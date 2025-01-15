#include <iostream>
using namespace std;

int main() {
    int factors = 1;
    int x; cin >> x;
    int y = 2;
    while (y * y <= x) {
        if (x % y == 0) {
            x /= y;
            factors++;
        } else {
            y++;
        }
    }
    cout << factors << "\n";
}