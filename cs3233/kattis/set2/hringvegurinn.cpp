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
#define int long long

// adapted from and courtesy of https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/segmenttree_ds.cpp
// Modifications:
// - Updating adds to leaves of v rather than overriding it
// Assumption:
// - f(a1 + n, a2 + n, ..., ak + n) = f(a, b, ...) + size_adjust(n, k)
// true for range min queries, range max queries, range sum queries, but not range mult queries
class SegmentTree {
private:
  int n;
  vector<ll> A, st, lazy;

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

  SegmentTree(const vector<ll> &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }
  
  // adds val to leaves[i..j]
  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int query(int i, int j) { return query(1, 0, n-1, i, j); }
};

void type2(SegmentTree& st, int n, int l, int r, int x) {
  if (l > r) {
    type2(st, n, l, n - 1, x);
    type2(st, n, 0, r, x);
  } else {
    st.update(l, r, x);
  }
}

int type3(SegmentTree& st, int n, int l, int r) {
  if (l > r) {
    return type3(st, n, l, n - 1) + type3(st, n, 0, r);
  } else {
    return st.query(l, r);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q; cin >> n >> q;
  SegmentTree st(n);

  int offset = 0;
  for (int i = 0; i < q; i++) {
    int type; cin >> type;
    if (type == 1) {
      int r; cin >> r;
      offset += r;
      offset %= n;
    } else if (type == 2) {
      int l, r, x; cin >> l >> r >> x;
      l--; r--;
      type2(st, n, (l + offset) % n, (r + offset) % n, x);
    } else {
      int l, r; cin >> l >> r;
      l--; r--;
      cout << type3(st, n, (l + offset) % n, (r + offset) % n) << "\n";
    }
  }
}