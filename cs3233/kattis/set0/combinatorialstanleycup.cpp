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

/*
need to count how many n choose k are odd , where k can range from 0 to n. let this be f(n)

can use a bijection - the parity of n choose k equals the parity of (n + 2^i)choose(k), if n < 2^i
this is because the number of factors of 2 remain the same in the numerator, while denominator is the same.

additionally, n choose k = n choose n - k as well. then (n + 2^i)choose(k) = (n + 2^i)choose(n + 2^i - k),
with the same parity. denominators do not overlap. therefore, can form a 1 to 2 mapping of parities.

therefore, f(n) = 2 * f(n + 2^i) if n < 2^i

base case: f(0) = 1

so if n = 2^i1 + 2^i2 + ... + 2^in with i1 < i2 < ... < ik,
then f(n) = 2^k (where k is the number of 1's in the binary representation of k)
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    cout << (1 << __builtin_popcount(x)) << "\n";
}