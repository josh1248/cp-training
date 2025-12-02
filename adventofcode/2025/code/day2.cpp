#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

vector<string> split(string s, string delimiter) {
    vector<string> ans;
    size_t pos_start = 0;
    while (true) {
        size_t found = s.find(delimiter, pos_start);
        if (found == string::npos) {
            ans.push_back(s.substr(pos_start));
            return ans;
        } else {
            ans.push_back(s.substr(pos_start, found - pos_start));
            pos_start = found + 1;
            if (pos_start >= s.size()) return ans;
        }
    }
}

int main() {
    ifstream ins("../data/day2.txt");

    if (!ins) {
        return 1;
    }


    string input_str;
    ins >> input_str;
    vector<string> ranges_str = split(input_str, ",");
    vector<pair<ll, ll>> ranges;
    for (string& range: ranges_str) {
        vector<string> tmp = split(range, "-");
        ll left = stoll(tmp[0]), right = stoll(tmp[1]);
        ranges.emplace_back(left, right);
    }

    ins.close();

    ll part1 = 0;
    unordered_set<ll> part2_seen;
    for (ll i = 1; i < int(1e5); i++) {
        int i_size = int(to_string(i).size());
        ll check = i;
        int check_length = i_size;
        while (true) {
            check = check * int(pow(10ll, i_size)) + i;
            check_length += i_size;

            if (check_length >= 17) break;
            for (auto& [l, r]: ranges) {
                if (l <= check && check <= r) {
                    if (check_length == 2 * i_size) part1 += check;
                    part2_seen.insert(check);
                    break;
                }
            }
        }
    }

    ll part2 = 0;
    for (auto v: part2_seen) part2 += v;

    cout << "part 1: " << part1 << "\n";
    cout << "part 2: " << part2 << "\n";
}