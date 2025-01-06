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
typedef pair<int, int> pi;
typedef long long ll;

// number of factors of 2 in n!
int f(int n) {
    // divide every even number by 2
    return n == 1 ? 0 : n == 2 ? 1 : (n / 2 + f(n / 2));
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;

    int res = 0;
    for (int i = 0; i < )
}