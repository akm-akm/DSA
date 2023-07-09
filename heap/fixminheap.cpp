#include <iostream>

using namespace std;

void fix(int arr[], int cap, int i = 0)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int s = i;
    if (arr[i] > arr[l] && l > cap)
        s = l;
    if (arr[i] > arr[r] && arr[s] > arr[r])
        s = r;
    if (s != i)
    {
        swap(arr[s], arr[i]);
        fix(arr, cap, s);
    }
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "-------" << endl;
}
int main()
{
    int arr[] = {132,
                 2,
                 3,
                 4,
                 32,
                 12,
                 6,
                 8,
                 9,
                 35,
                 31};
    fix(arr, 11);
   
}