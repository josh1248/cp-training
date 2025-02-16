#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <bitset>
using namespace std;

// Credit: CS3233 AY24/25 Sem 2 Team 4 - Adriel, Abigail, Josh
struct bit_permutations {
    typedef unsigned long long ull;
    int numchoices, numitems;
    ull curr;
    bit_permutations(int choices, int items):
        numchoices(choices), numitems(items),
        curr(((1ull << items) - 1) - ((1ull << (items - choices)) - 1)) {}

    bool next_permutation() {
        ull succ = curr + 1ull;
        
        ull il1 = curr&succ; // ignore leading 1s
        if (!il1) return false; // no more 1s to shift out, all in LSB
        ull il1prev = il1 - 1ull;

        ull fd1 = il1&(~il1prev); // first disconnected 1
        ull f0 = (~curr)&succ; // first zero
        ull target_0s_prefix = (fd1/f0) >> 1;
        curr = il1 - target_0s_prefix;
        return (curr + 1ull) >= (1ull << numchoices);
    }
};

int main() {
    int choices = 7, items = 60;
    bit_permutations perms(choices, items);
    long long permutes = 0;
    do {
        // something
        ++permutes;
        // cout << perms.curr << "\n";
    } while (perms.next_permutation());

    cout << "Permutes: " << permutes << "\n";

    // Testing:
    // perms = bit_permutations(3, 6);
    // do {
    //     cout << perms.curr <<  " | " << bitset<6>(perms.curr) << "\n";
    // } while (perms.next_permutation());
}