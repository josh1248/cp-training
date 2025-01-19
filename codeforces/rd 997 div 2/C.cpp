#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
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

int precomp6[6] = {1, 1, 2, 3, 1, 2};
int precomp7[7] = {1, 1, 2, 3, 1, 2, 3};
int precomp9[9] = {7, 3, 3, 7, 5, 3, 7, 7, 3};
int precomp15[15] = {15, 8, 8, 8, 15, 5, 8, 1, 15, 5, 8, 15, 15, 15, 8};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);  

    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        if (x == 6) {
            for (int i = 0; i < 6; i++) {
                cout << precomp6[i] << " ";
            }
            cout << "\n";
        } else if (x == 7) {
            for (int i = 0; i < 7; i++) {
                cout << precomp7[i] << " ";
            }
            cout << "\n";
        } else if (x == 8) {
            for (int i = 0; i < 7; i++) {
                cout << precomp7[i] << " ";
            }
            cout << "4\n";
        } else if (x <= 14) {
            for (int i = 0; i < 9; i++) {
                cout << precomp9[i] << " ";
            }
            for (int i = 9; i < x; i++) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            for (int i = 0; i < 15; i++) {
                cout << precomp15[i] << " ";
            }
            for (int i = 15; i < x; i++) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        }
    } 
}