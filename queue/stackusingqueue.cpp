#include <iostream>
#include <queue>

using namespace std;

struct Stack
{
    queue<int> q, w;
    void push(int x)
    {
        while (!q.empty())
        {
            w.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!w.empty())
        {
            q.push(w.front());
            w.pop();
        }
    }
    bool empty() { return q.empty(); }
    int size() { return q.size(); }
    bool peek() { return q.back(); }
    void pop()
    {
        q.pop();
    }
    void print()
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(12);
    s.push(3);
    s.push(54);
    s.push(6);
    s.push(6);
    s.push(87);
    s.pop();
    s.push(54);

    cout << s.size() << endl;
    s.print();
    return 0;
}