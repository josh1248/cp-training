#include <algorithm>
#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ins("../data/day3.txt");

    if (!ins) {
        return 1;
    }


    regex r(R"(mul\((\d+),(\d+)\))");
    smatch m;

    // https://stackoverflow.com/questions/21667295/how-to-match-multiple-results-using-stdregex
    // https://www.cplusplus.com/reference/regex/regex_token_iterator/regex_token_iterator/
    // single matches: use 
    regex_token_iterator<string::iterator> iter_end;
    regex_token_iterator<string::iterator> it(s.begin(), s.end(), r);

    string s = "addwpihf2mul(5,3)2e12";

    ll res = 0;
    regex_search(s, m, r);
    for(auto v: m) std::cout << v << std::endl;
}