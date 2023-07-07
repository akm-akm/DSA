#include <iostream>
#include <queue>

using namespace std;

void generate(int n)
{
    queue<int> q;
    q.push(4);
    q.push(5);
    for (int i = 0; i < n; i++)
    {
        int top = q.front();
        cout << top << " ";
        q.pop();
        q.push(top * 10 + 4);
        q.push(top * 10 + 5);
    }
}

int main()
{

    int n = 20;
    generate(n);
}