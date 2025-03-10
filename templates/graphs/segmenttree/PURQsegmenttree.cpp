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

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

// simplified version of Segment Tree if range updates are not required
// adapted and courtesy of https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/segmenttree_ds.cpp
class PURQSegmentTree {
private:
  int n;
  vi A, st;

  int l(int p) { return  p<<1; }                 // left child
  int r(int p) { return (p<<1)+1; }              // right child

  int conquer(int a, int b) {
    if (a == -1) return b;                       // left half is not in desired range at all
    if (b == -1) return a;
    return min(a, b);                            // Change as required.
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

  int query(int p, int L, int R, int i, int j) {   // O(log n)
    if (i > j) return -1;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    return conquer(query(l(p), L  , m, i          , min(m, j)),
                   query(r(p), m+1, R, max(i, m+1), j        ));
  }

  void update(int p, int L, int R, int i, int val) { // O(log n)
    if (L > R || !(L <= i && i <= R)) return;
    if (L == R) { st[p] = A[i] = val; return; } 
    int m = (L+R)/2;
    update(l(p), L  , m, i, val);
    update(r(p), m+1, R, i, val);
    st[p] = conquer(st[l(p)], st[r(p)]);
  }

public:
  PURQSegmentTree(int sz) : n(sz), A(n), st(4*n) {}

  PURQSegmentTree(const vi &initialA) : PURQSegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }
  
  // replaces leaves[i..j] with val
  void update(int i, int val) { update(1, 0, n-1, i, val); }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  vi A = {18, 17, 13, 19, 15, 11, 20, 99};       // make n a power of 2
  PURQSegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("              A is {18,17,13,19,15,11,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // 13
  printf("query(4, 7) = %d\n", st.query(4, 7));      // 11
  printf("query(3, 4) = %d\n", st.query(3, 4));      // 15

  st.update(5, 77);                           // update A[5] to 77
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {18,17,13,19,15,77,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // remains 13
  printf("query(4, 7) = %d\n", st.query(4, 7));      // now 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // remains 15

  st.update(0, 30);                           // update A[0..3] to 30
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,17,13,19,15,77,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // now 30
  printf("query(4, 7) = %d\n", st.query(4, 7));      // remains 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // remains 15

  st.update(3, 7);                            // update A[3] to 7
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,17,13, 7,15,77,20,oo}\n");
  printf("query(1, 3) = %d\n", st.query(1, 3));      // now 7
  printf("query(4, 7) = %d\n", st.query(4, 7));      // remains 15
  printf("query(3, 4) = %d\n", st.query(3, 4));      // now 7

  return 0;
}