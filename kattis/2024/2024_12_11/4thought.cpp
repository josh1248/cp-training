//time: 37 mins
//https://open.kattis.com/problems/4thought
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <numeric> // accumulate
#include <set>
#include <sstream>
using namespace std;
using vi = vector<int>;

string find(int curr, int target, int l) {
    if (l == 1) {
        if (curr == target) {
            return "4"; 
        } else {
            return "";
        }
    } else {
        string t;
        if ((t = find(curr * 4, target, l - 1)) != "") {
           return "4 * " + t;
        } else if ((t = find(4, target - curr, l - 1)) != "") {
           return "4 + " + t;
        } else if ((t = find(-4, target - curr, l - 1)) != "") {
           return "4 - " + t;
        } else if ((t = find(curr / 4, target, l - 1)) != "") {
           return "4 / " + t; 
        } else {
            return "";
        }
    }
}

int main() {
    int x, y;
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> y;
        string a = find(4, y, 4);
        cout << ((a == "") ? "no solution" : (a + " = " + to_string(y))) << "\n";
    }
}