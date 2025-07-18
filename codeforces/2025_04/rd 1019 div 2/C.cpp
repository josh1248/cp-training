#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

// adapted and courtesy of https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/segmenttree_ds.cpp
class SegmentTree {
    private:
      int n;
      vi A, st, lazy;
    
      int l(int p) { return  p<<1; }                 // left child
      int r(int p) { return (p<<1)+1; }              // right child
    
      int conquer(int a, int b) {
        if (a == -1) return b;                       // left half is not in desired range at all
        if (b == -1) return a;
        return max(a, b);                            // Change as required.
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
      SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}
    
      SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
      }
      
      // replaces leaves[i..j] with val
      void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
    
      int query(int i, int j) { return query(1, 0, n-1, i, j); }
    };

void solve() {
    int n, k; cin >> n >> k;
    vi nums(n); rep(i, 0, n) cin >> nums[i];
    rep(i, 0, n) {
        nums[i] = (nums[i] <= k ? 1 : -1);
    }
    // subarray median <= k means subarray sum >= 0
    vi prefixsum(n - 1, 0);
    int curr = 0;
    rep(i, 0, n - 1) {
        curr += nums[i];
        prefixsum[i] = curr;
    }
    vi suffixsum(n - 1, 0);
    curr = 0;
    rep(i, 0, n - 1) {
        curr += nums[n - i - 1];
        suffixsum[i] = curr;
    }

    // our task is to find 2 non-overlapping subarrays with sum >= 0
    // Case 1: (0) (anything) (0)
    // Case 2: (0) (0) (anything)
    // Case 3: (anything) (0) (0)


    int left = -1, right = -1;
    curr = 0;
    rep(i, 0, n) {
        curr += nums[i];
        if (curr >= 0) {
            left = i + 1;
            break;
        }
    }
    curr = 0;
    rep(j, 0, n) {
        curr += nums[n - 1 - j];
        if (curr >= 0) {
            right = j + 1;
            break;
        }
    }
    if (left != -1 && right != -1 && left + right < n) {
        cout << "YES\n";
        return;
    }
    
    SegmentTree prefixst(prefixsum);
    rep(i, 0, n - 2) {
        if (prefixsum[i] >= 0 && prefixst.query(i + 1, n - 1) >= prefixsum[i]) {
            cout << "YES\n";
            return;
        }
    }
 
    SegmentTree suffixst(suffixsum);
    rep(i, 0, n - 2) {
        if (suffixsum[i] >= 0 && suffixst.query(i + 1, n - 1) >= suffixsum[i]) {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}