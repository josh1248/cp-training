#include <iostream>
using namespace std;

int main() {
    int k; cin >> k;
    cout << "+";
    for (int i = 0; i < k; i++) {
        cout << "-";
    }
    cout << "+" << "\n";
    
    
    for (int i = 0; i < k; i++) {
        cout << "|";
        for (int j = 0; j < k; j++) {
            cout << " ";
        }
        cout << "|" << "\n";
    }
    
    cout << "+";
    for (int i = 0; i < k; i++) {
        cout << "-";
    }
    cout << "+" << "\n";
}