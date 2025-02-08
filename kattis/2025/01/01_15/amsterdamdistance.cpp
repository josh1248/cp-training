#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    int m, n; double r;
    scanf("%d %d %lf\n", &m, &n, &r);
    int m1, n1, m2, n2;
    scanf("%d %d %d %d\n", &m1, &n1, &m2, &n2);
    
    // travel into inner circle
    double vertical = abs(n1 - n2) * r / n;

    // decide if travelling across arc, or going to center and back is better
    double threshold = 3.1415926535 * abs(m1 - m2) / m;
    printf("%.10f\n", vertical + min(double(2), threshold) * r * min(n1, n2) / n);
}