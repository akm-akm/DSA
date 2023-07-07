#include <iostream>
#include <deque>
using namespace std;

void maxarray(int ar[], int k, int n)
{
    deque<int> dq;
    dq.push_back(0);
    int i;
    for (i = 1; i < k; i++)
    {
        if (ar[dq.back()] < ar[i])
        {
            dq.pop_back();
            dq.push_back(i);
        }
    }
    cout << ar[dq.back()] << " ";
    for (; i < n; i++)
    {
        
    }
}
int main()
{
    int ar[] = {1, 2, 3, 4, 4, 5, 5, 6, 67, 7, 43, 6, 2, 1};
    maxarray(ar, 3, 14);
    return 0;
}