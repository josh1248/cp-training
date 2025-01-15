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

// adapted from and courtesy of https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/segmenttree_ds.cpp
// Modifications:
// - Updating adds to leaves of v rather than overriding it
// Assumption:
// - f(a1 + n, a2 + n, ..., ak + n) = f(a, b, ...) + size_adjust(n, k)
// true for range min queries, range max queries, range sum queries, but not range mult queries
class SegmentTree {
private:
  int n;
  vi A, st, lazy;

  int l(int p) { return  p<<1; }                 // left child
  int r(int p) { return (p<<1)+1; }              // right child

  int conquer(int a, int b) {
    if (a == -1) return b;                       // left half is not in desired range at all
    if (b == -1) return a;
    return a + b;                            // Change as required.
  }

  // Represents extra value of subarray if all of its x elements has v added to it. Change as required.
  int size_adjust(int v, int s) {
    return v * s;
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
    if (lazy[p] != 0) {                           // modified 
      st[p] += size_adjust(lazy[p], R - L + 1);   // modified
      if (L != R) {
        lazy[l(p)] += lazy[p];                    // modified
        lazy[r(p)] += lazy[p];                    // modified
      } else {         
        A[L] += lazy[p];                          // modified
      }
      lazy[p] = 0;                                // modified
    }
  }

  int query(int p, int L, int R, int i, int j) {
    propagate(p, L, R);                          
    if (i > j) return -1;                        
    if ((L >= i) && (R <= j)) return st[p]; 
    int m = (L+R)/2;
    return conquer(query(l(p), L  , m, i          , min(m, j)),
                   query(r(p), m+1, R, max(i, m+1), j        ));
  }

  void update(int p, int L, int R, int i, int j, int val) {
    propagate(p, L, R);                          
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  
      lazy[p] += val;                             // modified
      propagate(p, L, R);                       
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
      int lsubtree = size_adjust(lazy[l(p)], m - L + 1) + st[l(p)]; // modified
      int rsubtree = size_adjust(lazy[l(p)], R - m) + st[r(p)]; // modified
      st[p] = conquer(lsubtree, rsubtree);
    }
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, 0) {} // modified

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }
  
  // adds val to leaves[i..j]
  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    vi v(n + q, 0); // holds position index for movie at pos i
    vi movie_pos(n); // maps movie label to current position in the ST
    for (int i = 0; i < n; i++) {
      movie_pos[i] = n - i - 1;
    }
    for (int i = 0; i < n; i++) {
      v[i] = n - i - 1;
    }

    SegmentTree st(v);
    for (int i = 0; i < q; i++) {
      int k; cin >> k; k--;
      int curr = movie_pos[k];
      cout << st.query(curr, curr) << " ";
      st.update(curr + 1, n + i - 1, 1);
      movie_pos[k] = n + i;
      // for (int i = 0; i < n + q; i++) {
      //   cout << st.query(i, i) << " ";
      // }
      // cout << "\n";
    } 
    cout << "\n";
  }
}