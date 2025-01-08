#include <iostream>
using namespace std;
int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << x << " is ";
        cout << (x % 2 == 0 ? "even" : "odd") << "\n";
    }
}