#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int d;
    while (cin >> d) {
        long long acc = -d;
        float cutoff = pow(d, 0.5);
        for (int i = 1; i < cutoff + 0.1; i++) {
            if (d % i == 0) {
                acc += i;
                if (d / i != i) {
                    acc += d / i;
                }
            }    
        }
    
        cout << d << " ";
        
        if (acc == d) {
            cout << "perfect\n";
        } else if (acc - d <= 2 && acc - d >= -2) {
            cout << "almost perfect\n";
        } else {
            cout << "not perfect\n";
        }
    }
}