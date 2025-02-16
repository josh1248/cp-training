#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <bitset>
using namespace std;

void combinations(vector<int>& nums, int k) {
    string select(k, '1');
    select.resize(nums.size(), '0');
    int e = 1;
    do {
        cout << e << ": ";
        for (int i = 0; i < int(nums.size()); ++i) {
            if (select[i]) {
                cout << nums[i] << " ";
            }
        }
        cout << "\n";
        e++;
    } while (prev_permutation(select.begin(), select.end()));
    cout << "(Total combinations: " << e - 1 << ")\n";
}

void permutations(vector<int>& nums) {
    vector<int>gen(nums.size());
    iota(gen.begin(), gen.end(), 0);
    int e = 1;
    do {
        cout << e << ": ";
        for (int i: gen) {
            cout << i << " ";
        }
        cout << "\n";
        e++;
    } while (next_permutation(gen.begin(), gen.end()));
}

void permutations_combinations(vector<int>& nums, int k) {
    vector<int> gen(nums.size());
    iota(gen.begin(), gen.end(), 0);
    int e = 1;
    do {
        cout << e << ": ";
        for (int i = 0; i < k; i++) {
            cout << nums[gen[i]] << " ";
        }
        cout << "\n";
        e++;
        sort(gen.begin()+k, gen.end(), greater<int>());
    } while (next_permutation(gen.begin(), gen.end()));
    cout << "(Total permutation-combinations: " << e - 1 << ")\n";
}

int main() {
    cout << "Input n and k:\n";
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // cout << "Combinations:\n";
    // combinations(v, k);

    // cout << "Permutations:\n";
    // permutations(v);

    cout << "Permutation-combinations:\n";
    permutations_combinations(v, k);
    bitset<10> test;
}