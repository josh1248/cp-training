#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

vector<ll> pows;

ll solve(string s, int num_digits) {
    vector<ll> bests(num_digits, -1e15);
    for (int i = s.size() - 1; i >= 0; i--) {
        int curr_digit = s[i] - '0';
        for (int j = num_digits - 1; j >= 0; j--) {
            bests[j] = max(bests[j], pows[j] * curr_digit + (j > 0 ? bests[j - 1] : 0));
        }
    }
    return bests[num_digits - 1];
}

int main() {
    ifstream ins("../data/day3.txt");
    if (!ins) return 1;
    
    string s; vector<string> banks;
    while (ins >> s) {
        banks.push_back(s);
    }

    ins.close();

    for (int i = 0; i < 13; i++) {
        pows.push_back(ll(pow(10ll, i)));
    }

    ll part1 = 0, part2 = 0;
    for (string& s: banks) {
        part1 += solve(s, 2);
        part2 += solve(s, 12);
    }

    cout << "part 1: " << part1 << "\n";
    cout << "part 2: " << part2 << "\n";
}