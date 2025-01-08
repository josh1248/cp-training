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
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

int v(char c) {
    if (c == ' ') {
        return 0;
    } else {
        return 1 + c - 'a';
    }
}

char v_inv(int val) {
    return (val == 0) ? ' ' : (val - 1 + 'a');
}

void encrypt(string& s) {
    int hold = 0;
    for (int i = 0; i < s.size(); i++) {
        hold = (hold + v(s[i])) % 27;
        cout << v_inv(hold);
    }
    cout << "\n";
}

void decrypt(string& s) {
    int prev = 0;
    for (int i = 0; i < s.size(); i++) {
        // v(s[i]) = u_i - u_{i-1} (taking positive mod 27), with u_{-1} = 0
        int org = (v(s[i]) - prev) % 27;
        if (org < 0) {
            org += 27;
        }
        cout << v_inv(org);
        prev = v(s[i]);
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    char c; string s;

    getline(cin, s); 
    
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        
        if (s[0] == 'd') {
            s.erase(s.begin(), s.begin() + 2);
            decrypt(s);
        } else {
            s.erase(s.begin(), s.begin() + 2);
            encrypt(s);
        }
    }
}