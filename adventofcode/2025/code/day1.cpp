#include <iostream>
#include <fstream>
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


    vi rots; string input_str;
    while (ins >> input_str) {
        int rot = stoi(input_str.substr(1));
        rots.push_back(input_str[0] == 'R' ? rot : -rot);
    }

    ins.close();

    int curr = 50;
    int part1 = 0, part2 = 0;
    for (int& rot: rots) {
        int nxt = ((curr + rot) % 100 + 100) % 100;

        if (nxt == 0) part1++;

        if (curr + rot >= 100) {
            part2 += (curr + rot) / 100;
        } else if (curr + rot <= 0) {
            part2 += abs(curr + rot - 100) / 100;
            if (curr == 0) part2--;
        }

        curr = nxt;
    }
    


    cout << "part 1: " << part1 << "\n";
    cout << "part 2: " << part2 << "\n";
}