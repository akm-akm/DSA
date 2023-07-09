#include <iostream>

using namespace std;

void fix(int *arr[], int cap, int i = 0)
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
    else
    {
        fix(arr, cap, i++);
    }
}

void extractMin(int *arr, int s, int cap)
{
    swap(arr[0], arr[s - 1]);
    s--;
    fix(&arr, cap, s);
}

int main()
{
}