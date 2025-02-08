#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, studies, birth;
    int n, courses;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> studies >> birth >> courses;
        cout << name << " ";
        if (stoi(studies.substr(0, 4)) >= 2010 || stoi(birth.substr(0, 4)) >= 1991) {
            cout << "eligible\n";
        } else if (courses > 40) {
            cout << "ineligible\n";
        } else {
            cout << "coach petitions\n";
        }
    }
}