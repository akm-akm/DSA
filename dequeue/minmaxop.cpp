#include <iostream>
#include <deque>

using namespace std;

struct Man
{
    deque<int> dq;

    void insertMax(int x)
    {
        if (!dq.empty() && x <= dq.back())
        {
            exit(1);
        }
        dq.push_back(x);
    }

    void insertMin(int x)
    {
        if (!dq.empty() && x >= dq.front())
        {
            exit(1);
        }
        dq.push_front(x);
    }

    int getMin()
    {
        if (dq.empty())
            exit(1);

        return dq.front();
    }

    int getMax()
    {
        if (dq.empty())
            exit(1);

        return dq.back();
    }
    void extractMin()
    {
        dq.pop_front();
    }
    void extractMax()
    {
        dq.pop_back();
    }
};

int main()
{
    Man m;
    m.insertMin(6);
    m.insertMin(5);
    m.insertMin(6);
    m.insertMin(4);
    cout << m.getMax();
}