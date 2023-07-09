#include <iostream>

using namespace std;

struct Heap
{
    int *arr;
    int s, c;
    Heap(int cap)
    {
        c = cap;
        s = 0;
        arr = new int[c];
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    void insert(int x)
    {
        if (s == c)
            return;
        s++;
        arr[s-1] = x;
        int pos = s-1;
        while (x < arr[(pos - 1) / 2] || pos != 0)
        {
            swap(arr[pos], arr[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }
    void print()
    {
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Heap h(20);
    h.insert(19);
    h.insert(321);
    h.insert(143);
    h.insert(17);
    h.insert(16);
    h.insert(241);
    h.insert(13);
    h.insert(21);
   h.print();
    return 0;
}