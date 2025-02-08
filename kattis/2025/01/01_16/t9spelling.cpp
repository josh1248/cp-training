#include <iostream>
using namespace std;

char choice(char c) {
    if (c >= 'w') {
        return '9';
    } else {
        return '1' + (c - 'a') / 3;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Case #" << i << ": ";
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            char x = choice(s[j]);
            if (x == '9') {
                cout << string(s[j] - 'w' + 1, x);
            } else {
                cout << string((s[j] - 'a') % 3 + 1, x);
            }
            if (j < s.size() - 1 && (choice(s[j]) == choice(s[j + 1]))) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}