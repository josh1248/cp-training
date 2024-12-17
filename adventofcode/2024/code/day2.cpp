#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

bool safe(vi& v, bool can_remove) {
    if (v.size() <= 1) {
        return true;
    }

    int mod = (v[0] < v[1]) ? 1 : -1; // directionality
    int gap = 0; 
    for (int i = 1; i < v.size(); i++) {
        gap = mod * (v[i] - v[i - 1]);
        if (gap >= 1 && gap <= 3) {
            continue;
        }
        
        if (!can_remove) {
            return false;
        }

        // case 1: right of violating pair (1 2 7 4 5)
        int tmp = v[i];
        v.erase(v.begin() + i);
        bool remove_right = safe(v, false);
        v.insert(v.begin() + i, tmp);

        // case 2: left of violating pair (1 3 2 4 5)
        tmp = v[i - 1];
        v.erase(v.begin() + i - 1);
        bool remove_left = safe(v, false);
        v.insert(v.begin() + i - 1, tmp);

        // special case: violating pair arises due to wrong directionality (6 3 4 5)
        tmp = v[0];
        v.erase(v.begin());
        bool remove_front = safe(v, false);
        v.insert(v.begin(), tmp);

        return remove_front || remove_left || remove_right;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ins("../data/day2.txt");

    if (!ins) {
        return 1;
    }

    int safesp1 = 0, safesp2 = 0;
    string s; vi v; int i;
    while (getline(ins, s)) {
        stringstream ss(s);
        v.clear();
        while (ss >> i) {
            v.push_back(i);
        }

        if (safe(v, false)) {
            safesp1++;
            safesp2++;
            continue;
        } else if (safe(v, true)) {
            safesp2++;
        }
    }

    ins.close();

    cout << "part 1: " << safesp1 << "\n";
    cout << "part 2: " << safesp2 << "\n";
}