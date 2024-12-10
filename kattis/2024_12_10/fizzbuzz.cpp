#include <iostream>
#include <vector>
using namespace std;

void algo(int x, int y, int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        string o;
        if (i % x == 0){
            o += "Fizz";
        }
        if (i % y == 0)
        {
            o += "Buzz";
        }

        if (o == "")
        {
            cout << i;
        }
        else
        {
            cout << o;
        }
        cout << "\n";
    }
}

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    algo(x, y, n);
}