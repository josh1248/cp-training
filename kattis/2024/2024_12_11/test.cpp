#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    cout << a % 8 << "\n";
    int b = ((a >> 3) << 3);
    cout << (a ^ b) << "\n";
} 