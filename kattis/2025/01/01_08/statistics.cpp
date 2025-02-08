#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s;
    int c = 0;
    while (getline(cin, s)) {
        c++;
        stringstream ss(s);
        int n;
        ss >> n;
        int high = -1e9, low = 1e9;
        int k;
        for (int i = 0; i < n; i++) {
            ss >> k;
            high = max(high, k);
            low = min(low, k);
        }
        cout << "Case " << c << ": ";
        cout << low << " " << high << " " << high - low << "\n";
    }
}