#include <iostream>
#include <vector>
using namespace std;

void algo(int r)
{
    for (int i = 0; i < r; i++)
    {
        cout << i + 1 << " Abracadabra\n";
    }
}

int main()
{
    int reps;
    string s = "Abracadabra";
    cin >> reps;
    algo(reps);
}