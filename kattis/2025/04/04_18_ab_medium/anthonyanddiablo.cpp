#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // largest area for perimeter is a circle.
    // https://math.stackexchange.com/questions/4808/why-does-a-circle-enclose-the-largest-area
    // can always make arbitrarily small area with a very thin rectangle
    double wantedarea, perimeter; cin >> wantedarea >> perimeter;

    // perimeter = 2 pi r
    // r = perimeter / 2 pi
    // area = pi r^2 = perimeter^2 / 4 pi 
    double maxarea = perimeter * perimeter / 4.0 / M_PI;
    cout << (maxarea > wantedarea ? "Diablo is happy!" : "Need more materials!") << "\n";
    return 0;
}