#include <iostream>
#include <stack>
#include <deque>
using namespace std;

void greatestLeft(int ar[], int n)
{
    stack<int> s;
    int max;
    s.push(0);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && (ar[s.top()] <= ar[i]))
        {
            s.pop();
        }
        max = s.empty() ? -1 : ar[s.top()];
        s.push(i);
        cout << max << " ";
    }
}

void greatestRight(int ar[], int n)
{
    stack<int> s, z;
    int max;
    s.push(n - 1);
    z.push(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && (ar[i] >= ar[s.top()]))
        {
            s.pop();
        }
        if (s.empty())
            z.push(-1);
        else
            z.push(ar[s.top()]);
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << z.top() << " ";
        z.pop();
    }
}
int main()
{
    int ar[] = {1, 3, 4, 2, 5, 8, 6, 5, 7, 8, 9, 1, 23, 20, 34, 5};
    int n = 16;
    greatestLeft(ar, n);
    cout << endl;
    greatestRight(ar, n);
    return 0;
}