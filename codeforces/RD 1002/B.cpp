#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

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

int rmaxq(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return max(a, b); 
}

int rminq(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return min(a, b); 
}

int rmq_size_adjust(int v, int repeats) {
  return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        SegmentTree stmax(v, rmaxq, rmq_size_adjust);
        SegmentTree stmin(v, rminq, rmq_size_adjust);
        int small = 1, large = n - k + 1;
        int cost = 1;
        if (stmax.query(small, large) != cost || stmin.query(small, large) != cost) {
            cout << cost << "\n";
            goto done;
        } else if (large - small > 0) {
            cout << cost + 1 << "\n";
            goto done;
        } else {
            while (cost <= k / 2) {
                if (v[large] != cost) {
                    cout << cost << "\n";
                    goto done;
                }
                large += 2;
                small = large;
                cost++;
            }
        }


        cout << k / 2 + 1 << "\n";

        done:
    }
}