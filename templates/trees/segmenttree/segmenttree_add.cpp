#include <iostream>
#include <algorithm>
#include <cstdio>
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
// Modification: Updating adds to leaves of v rather than overriding it
class SegmentTree {
private:
  int n;
  vi A, st, lazy;

  int l(int p) { return  p<<1; }                 // left child
  int r(int p) { return (p<<1)+1; }              // right child

  int conquer(int a, int b) {
    if (a == -1) return b;                       // left half is not in desired range at all
    if (b == -1) return a;
    return min(a, b);                            // Change as required.
  }

  // Represents value of subarray if all of its x elements equal v. Change as required.
  int size_adjust(int v, int s) {
    return v;
  }

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
      st[p] += size_adjust(lazy[p], R - L + 1);   // [L..R] has same value
      if (L != R)                                // not a leaf
        lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
      else                                       // L == R, a single index
        A[L] += lazy[p];                          // time to update this
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
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }
  
  // adds val to leaves[i..j]
  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }
};

int main() {
  vi A = {18, 17, 13, 19, 15, 11, 20, 99};       // make n a power of 2
  SegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("              A is {18,17,13,19,15,11,20,99}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // 13
  printf("query(4, 7) = %d\n", st.query(4, 7));      // 11
  printf("query(3, 4) = %d\n", st.query(3, 4));      // 15

  st.update(5, 5, 77);                           
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {18,17,13,19,15,88,20,99}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // remains 13
  printf("query(4, 7) = %d\n", st.query(4, 7));      // now 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // remains 15

  st.update(0, 3, 30);                           
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {48,47,43,49,15,88,20,99}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // now 30
  printf("query(4, 7) = %d\n", st.query(4, 7));      // remains 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // remains 15

  st.update(4, 4, 20);                           
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {48,47,43,49,35,77,20,99}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // now 7
  printf("query(4, 7) = %d\n", st.query(4, 7));      // remains 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // now 7

  return 0;
}