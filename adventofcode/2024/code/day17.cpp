#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    ifstream ins("../data/day9.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!ins) {
        return 1;
    }

    vi files, empties; char n; bool flag = true;
    while (ins >> n) {
        if (flag) {
            files.push_back(n - '0');
        } else {
            empties.push_back(n - '0');
        }
        flag = !flag;
    }
}