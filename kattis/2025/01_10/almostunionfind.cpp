// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics

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
typedef long long ll;

class AlmostUF {
public:
  vector<ll> v, setSize, sumAt;
  int s;
  AlmostUF(int N) {
    s = N;
    // need to use labels which are not vertices because of the move operation
    v.assign(2 * N, 1);
    setSize.assign(N, 1);
    sumAt.assign(N, 0);

    for (int i = 0; i < N; i++) {
      v[i] = i + N;
      sumAt[i] = i;
    }

    for (int i = N; i < 2 * N; i++) {
      v[i] = i;
    }
  }

  int find(int p) {
    while (v[p] != p) {
      v[p] = find(v[p]);
      p = v[p];
    }
    return v[p];
  }

  void u(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    
    if (setSize[x - s] > setSize[y - s]) {
      swap(x, y);
    }
    v[x] = y;
    setSize[y - s] += setSize[x - s];
    sumAt[y - s] += sumAt[x - s];
  }

  void move(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) {
      return;
    }

    v[x] = py;
    setSize[px - s]--;
    sumAt[px - s] -= x;
    setSize[py - s]++;
    sumAt[py - s] += x;
  }

  void peek(int x) {
    x = find(x);
    cout << setSize[x - s] << " " << sumAt[x - s] + setSize[x - s] << "\n";
  }
};

int main() {
  int n, m;
  while (cin >> n) {
    cin >> m;
    AlmostUF uf(n);
    for (int i = 0; i < m; i++) {
      int t; cin >> t;
      if (t == 1) {
        int p, q; cin >> p >> q;
        uf.u(p - 1, q - 1);
      } else if (t == 2) {
        int p, q; cin >> p >> q;
        uf.move(p - 1, q - 1);
      } else {
        int p; cin >> p;
        uf.peek(p - 1);
      }
    }
  }
}
