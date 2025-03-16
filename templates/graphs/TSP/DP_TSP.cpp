// Collecting Beepers
// https://github.com/stevenhalim/cpbook-code/blob/master/ch3/dp/beepers_UVa10496.cpp
// Held-Karp DP-TSP
#include <bits/stdc++.h>
using namespace std;

// https://github.com/stevenhalim/cpbook-code/blob/master/ch3/dp/beepers_UVa10496.cpp
// Held-Karp DP-TSP
#define LSOne(S) ((S) & -(S))

const int MAX_n = 11;

int dist[MAX_n][MAX_n], memo[MAX_n][1<<(MAX_n-1)]; // Karel + max 10 beepers

// dp(0, (1<<(n-1))-1)), where n is the number of non-source nodes
int dp(int u, int mask) {                        // mask = free coordinates
  if (mask == 0) return dist[u][0];              // close the loop
  int &ans = memo[u][mask];
  if (ans != -1) return ans;                     // computed before
  ans = 2000000000;
  int m = mask;
  while (m) {                                    
    int two_pow_v = LSOne(m);
    int v = __builtin_ctz(two_pow_v)+1;          // change to ctzll if long long needed
    ans = min(ans, dist[u][v] + dp(v, mask^two_pow_v));
    m -= two_pow_v;
  }
  return ans;
}

int main() {
  int TC; scanf("%d", &TC);
  while (TC--) {
    int xsize, ysize; scanf("%d %d", &xsize, &ysize); // these two values are not used
    int x[MAX_n], y[MAX_n];
    scanf("%d %d", &x[0], &y[0]);
    int n; scanf("%d", &n); ++n;                 // include Karel
    for (int i = 1; i < n; ++i)                  // Karel is at index 0
      scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < n; ++i)                  // build distance table
      for (int j = i; j < n; ++j)
        dist[i][j] = dist[j][i] = abs(x[i]-x[j]) + abs(y[i]-y[j]); // Manhattan distance
    memset(memo, -1, sizeof memo);
    printf("%d\n", dp(0, (1<<(n-1))-1));         // DP-TSP
    // printf("The shortest path has length %d\n", dp(0, (1<<(n-1))-1)); // DP-TSP
  }
  return 0;
}