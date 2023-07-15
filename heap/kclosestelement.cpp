#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>> pq;
    int arr[] = {11, 22, 33, 21, 34, 54, 37, 39, 41, 14, 42, 41};
    int k = -30, c = 3;
    if (k < 0)
    {
        for (int i = 0; i < c; i++)
        {
            pq.push(abs(arr[i] - k));
        }
        for (int i = c; i < 12; i++)
        {
            if (pq.top() >= abs(arr[i] - k))
            {
                pq.pop();
                pq.push(abs(arr[i] - k));
            }
        }
        while (!pq.empty())
        {
            cout << pq.top() + k << " ";
            pq.pop();
        }
    }
    else
    {
        for (int i = 0; i < c; i++)
        {
            pq.push(abs(arr[i] + k));
        }
        for (int i = c; i < 12; i++)
        {
            if (pq.top() >= abs(arr[i] + k))
            {
                pq.pop();
                pq.push(abs(arr[i] + k));
            }
        }
        while (!pq.empty())
        {
            cout << pq.top() - k << " ";
            pq.pop();
        }
    }
}
