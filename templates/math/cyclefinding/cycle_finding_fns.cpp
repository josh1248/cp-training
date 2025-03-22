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

// https://github.com/stevenhalim/cpbook-code/blob/master/ch5/UVa00350.cpp 
// either a math function or graph
int f(int x) { return -1; }

// lambda = cycle length, mu = start of cycle
pi floydCycleFinding(int x0) {                   // f(x) is defined above
  // 1st part: finding k*mu, hare h's speed is 2x tortoise t's
  int t = f(x0), h = f(f(x0));                   // f(x0) is after x0
  while (t != h) { t = f(t); h = f(f(h)); }
  // 2nd part: finding mu, hare h and tortoise t move at the same speed
  int mu = 0; h = x0;
  while (t != h) { t = f(t); h = f(h); ++mu; }
  // 3rd part: finding lambda, hare h moves, tortoise t stays
  int lambda = 1; h = f(t);
  while (t != h) { h = f(h); ++lambda; }
  return {mu, lambda};
}