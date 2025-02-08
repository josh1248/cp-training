#include <iostream>
#include <algorithm>
#include <cstdio>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

// Credit: https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unordered_map<ll, ll, custom_hash> safe_map;

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

int rmaxq_s(int v, int repeats) {
  return v;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    while (true) {
        int n;
        scanf("%d\n", &n);
        if (n == 0) {
            scanf("%d\n", &n);
            return 0;
        }
        vi rain(n), years(n); safe_map years_map;
        for (int i = 0; i < n; i++) {
            int y, r;
            scanf("%d %d\n", &y, &r);
            years_map[y] = i;
            years[i] = y;
            rain[i] = r;
        }

        SegmentTree st(rain, rmaxq, rmaxq_s);
        int q; scanf("%d\n", &q);
        for (int i = 0; i < q; i++) {
            int y, x; scanf("%d %d\n", &y, &x);
            if (years_map.count(x) == 1 && years_map.count(y) == 1) {
                int y_idx = years_map[y], x_idx = years_map[x];
                if (rain[y_idx] < rain[x_idx] || rain[x_idx] <= st.query(y_idx + 1, x_idx - 1)) {
                    printf("false\n");
                } else {
                    printf("%s\n", ((x - y) == (x_idx - y_idx)) ? "true" : "maybe");
                }
            } else if (years_map.count(x) == 0 && years_map.count(y) == 1) {
                int x_replace_idx = distance(years.begin(), lower_bound(years.begin(), years.end(), x)) - 1;
                int y_idx = years_map[y];
                if (x_replace_idx == y_idx) {
                    printf("maybe\n");
                } else {
                    printf("%s\n", ((rain[y_idx] > st.query(y_idx + 1, x_replace_idx)) ? "maybe" : "false"));
                }
            } else if (years_map.count(x) == 1 && years_map.count(y) == 0) {
                int y_replace_idx = distance(years.begin(), lower_bound(years.begin(), years.end(), y));
                if (y_replace_idx == years_map[x]) {
                    printf("maybe\n");
                } else {
                    printf("%s\n", ((rain[years_map[x]] > st.query(y_replace_idx, years_map[x] - 1)) ? "maybe" : "false"));
                }
            } else {
                printf("maybe\n");
            }
        }
        printf("\n");
    }
}