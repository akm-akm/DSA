#include <iostream>

using namespace std;

struct DequeueAr
{
    int *arr;
    int s, cap, front;
    DequeueAr(int c)
    {
        cap = c;
        arr = new int[cap];
        s = front = 0;
    }
    int size() { return s; }
    bool isFull() { return s == cap; }
    bool isEmpty() { return s == 0; }
    int getFront() { return s == 0 ? INT32_MAX : arr[0]; }
    int getRear() { return s == 0 ? INT32_MAX : arr[s]; }
    void deleteFront()
    {
        if (s)
            exit(0);
        for (int i = 1; i < s; i++)
        {
            arr[i - 1] = arr[i];
        }
        s--;
    }
    void deleteRear()
    {
        if (s)
            exit(0);
        s--;
    }
    void insertFront(int x)
    {
        for (int i = s; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        s++;
        arr[0] = x;
    }
    void insertRear(int x)
    {
        arr[s] = x;
        s++;
    }
    void print()
    {
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    DequeueAr dq(20);
    dq.insertFront(1);
    dq.insertRear(9);
    dq.insertFront(5);
    dq.insertRear(8);
    dq.insertFront(11);
    dq.insertFront(187);
    dq.insertRear(41);
    dq.insertFront(881);
    dq.print();
    return 0;
}