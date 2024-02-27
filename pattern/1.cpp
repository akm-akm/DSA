#include <iostream>

using namespace std;

int main()
{
    int r = 8;
    for (int i = 0; i < r; i++)
    {
        for (int k = r; k > i + 1; k--)
        {
            cout << " ";
        }
        for (int j = 0; j <= i * 2; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}