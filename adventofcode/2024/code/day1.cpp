#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    ifstream ins("../data/day1.txt");

    if (!ins) {
        return 1;
    }


    vi v1, v2; int i1, i2;
    while (ins >> i1 >> i2) {
        v1.push_back(i1);
        v2.push_back(i2);
    }

    ins.close();

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll dist = 0;
    for (int i = 0; i < v1.size(); ++i) {
        dist += abs(v1[i] - v2[i]);
    }

    multiset<int> mv2(v2.begin(), v2.end());

    ll sim = 0;
    for (int i: v1) {
        sim += i * mv2.count(i);
    }

    cout << "part 1: " << dist << "\n";
    cout << "part 2: " << sim << "\n";
}