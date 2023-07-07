#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseIt(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

void reverseRec(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    reverseRec(q);
    q.push(x);
}

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{

    queue<int> q;
    q.push(41);
    q.push(47);
    q.push(54);
    q.push(9);
    q.push(7);
    q.push(5);
    print(q);

    reverseIt(q);
    print(q);
    reverseRec(q);
    print(q);
}