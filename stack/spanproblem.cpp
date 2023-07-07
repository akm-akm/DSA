#include <iostream>
#include <stack>

using namespace std;

void spanProblem(int ar[], int n)
{
    stack<int> s;
    s.push(0);
    int span;
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && ar[s.top()] <= ar[i])
        {
            s.pop();
        }
        span = s.empty() ? i + 1 : i - s.top();
        cout << span << " ";
        s.push(i);
    }
}
int main()
{
    int ar[] = {1, 3, 4, 2, 5, 8, 6, 5, 7, 8, 9, 1, 23, 20, 34, 5};
    int n = 16;
    spanProblem(ar, n);
    return 0;
}