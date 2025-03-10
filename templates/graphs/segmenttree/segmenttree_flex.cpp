#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

// adapted and courtesy of https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/segmenttree_ds.cpp
// Modification:
// Allows for the conquer and size adjust function to be passed in as a parameter,
// in case several types of segment trees are required
class SegmentTree {
private:
  int n;
  function<int(int, int)> conquer;
  function<int(int, int)> size_adjust;
  vi A, st, lazy;

  int l(int p) { return  p<<1; }                 // left child
  int r(int p) { return (p<<1)+1; }              // right child

  void build(int p, int L, int R) {              // O(n)
    if (L == R)
      st[p] = A[L];
    else {
      int m = (L+R)/2;
      build(l(p), L  , m);
      build(r(p), m+1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {                         // has a lazy flag
      st[p] = size_adjust(lazy[p], R - L + 1);   // [L..R] has same value
      if (L != R)                                // not a leaf
        lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
      else                                       // L == R, a single index
        A[L] = lazy[p];                          // time to update this
      lazy[p] = -1;                              // erase lazy flag
    }
  }

  int query(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return -1;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    return conquer(query(l(p), L  , m, i          , min(m, j)),
                   query(r(p), m+1, R, max(i, m+1), j        ));
  }

  void update(int p, int L, int R, int i, int j, int val) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] = val;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
      int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = conquer(lsubtree, rsubtree);
    }
  }

public:
  SegmentTree(int sz, function<int(int, int)> f, function<int(int, int)> f_s)
    : n(sz), A(n), st(4*n), lazy(4*n, -1), conquer(f), size_adjust(f_s) { }

  SegmentTree(const vi &initialA, function<int(int, int)> f, function<int(int, int)> f_s)
    : SegmentTree((int)initialA.size(), f, f_s) {
    A = initialA;
    build(1, 0, n-1);
  }
  
  // replaces leaves[i..j] with val
  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }
};

int rmq(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return max(a, b); 
}

int rmq_size_adjust(int v, int repeats) {
  return v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  vi A = {18, 17, 13, 19, 15, 11, 20, 99};       // make n a power of 2
  SegmentTree st(A, rmq, rmq_size_adjust);

  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("              A is {18,17,13,19,15,11,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // 13
  printf("query(4, 7) = %d\n", st.query(4, 7));      // 11
  printf("query(3, 4) = %d\n", st.query(3, 4));      // 15

  st.update(5, 5, 77);                           // update A[5] to 77
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {18,17,13,19,15,77,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // remains 13
  printf("query(4, 7) = %d\n", st.query(4, 7));      // now 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // remains 15

  st.update(0, 3, 30);                           // update A[0..3] to 30
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30,30,15,77,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // now 30
  printf("query(4, 7) = %d\n", st.query(4, 7));      // remains 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // remains 15

  st.update(3, 3, 7);                            // update A[3] to 7
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30, 7,15,77,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // now 7
  printf("query(4, 7) = %d\n", st.query(4, 7));      // remains 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // now 7

  return 0;
}