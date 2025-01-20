#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
# define int long long
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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  int q; cin >> q;
  SegmentTree lengths(q + 1), listens(q + 1);
  int list_top = -1;
  unordered_map<string, int> songs_current; // store index
  unordered_map<string, int> songs_archive; // store listens

  for (int i = 0; i < q; i++) {
    char c; cin >> c;
    if (c == 'L') {
      // O(log q)
      string s; int length; cin >> s >> length;
      if (songs_current.count(s) > 0) {
        int idx = songs_current[s];
        songs_archive[s] = listens.query(idx, idx);
        lengths.update(idx, idx, -lengths.query(idx, idx));
        songs_current.erase(s);
      } else {
        list_top++;
        songs_current[s] = list_top;
        if (songs_archive.count(s) > 0) {
          listens.update(list_top, list_top, songs_archive[s]);
        }

        lengths.update(list_top, list_top, length);
      }
    } else if (c == 'P') {
      // O(log^2 q)
      ll x; cin >> x;
      ll total = lengths.query(0, list_top);
      listens.update(0, list_top, x / total);
      ll remainder = x % total;
      ll low = 0, high = list_top;
      while (low < high) {
        ll mid = (low + high) / 2;
        if (lengths.query(mid, list_top) <= remainder) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }

      if (lengths.query(low, list_top) <= remainder) {
        listens.update(low, list_top, 1);
      }
    } else {
      // O(log q)
      string s; cin >> s;
      if (songs_current.count(s) > 0) {
        cout << listens.query(songs_current[s], songs_current[s]) << "\n";
      } else if (songs_archive.count(s) > 0) {
        cout << songs_archive[s] << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
  }

  return 0;
}