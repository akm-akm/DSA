#include <iostream>

using namespace std;
// Use this class to implement  the following operation

class priQueue
{
    int *arr;
    int size;

public:
    priQueue()
    {
        arr = new int[1000];
        size = -1;
    }

    void push(int data)
    {

        if (size + 1 == 1000)
            return;
        arr[size + 1] = data;
        size++;
        int pos = size;
        while (pos > 0 && arr[(pos - 1) / 2] < arr[pos])
        {
            swap(arr[(pos - 1) / 2], arr[pos]);
            pos = (pos - 1) / 2;
        }
        // Write the code here.
    }
    void pop()
    {
        if (size == 0)
            size--;
        if (size == -1)
            return;
        arr[0] = INT32_MIN;
        swap(arr[0], arr[size]);
        size--;
        for (int i = 0; i < size; i++)
        {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            int max = i;
            if (left < size && arr[left] > arr[max])
                max = left;
            if (right < size && arr[right] > arr[max])
                max = right;
            if (max != i)
            {
                swap(arr[max], arr[i]);
                i = max;
            }
            else
            {
                break;
            }
        }

        // Write the code here.
    }
    int getMaxElement()
    {
        return size != -1 ? arr[0] : -1;
        // Write the code here.
    }
    bool isempty()
    {
        return size == -1;
    }
};

int main()
{
    priQueue pq;
    cout << pq.getMaxElement() << endl;
    cout << pq.getMaxElement() << endl;
    pq.pop();
    pq.pop();
    pq.push(2);
    pq.push(3);

    cout << pq.getMaxElement() << endl;
    cout << pq.getMaxElement() << endl;
}
