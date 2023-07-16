#include <iostream>

using namespace std;

struct Heap
{
    int *arr;
    int size, capacity;
    Heap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }
    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }
    int parent(int index) { return (index - 1) / 2; }

    void insert(int value)
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = value;
        int pos = size - 1;
        while (arr[pos] < arr[(pos - 1) / 2] && pos != 0)
        {
            if (arr[pos] < arr[(pos - 1) / 2])
            {
                swap(arr[pos], arr[(pos - 1) / 2]);
                pos = (pos - 1) / 2;
            }
        }
        // for (int index = size - 1; index != 0 && arr[index] < arr[(index - 1) / 2];)
        // {
        //     if (arr[index] < arr[(index - 1) / 2])
        //     {
        //         swap(arr[index], arr[(index - 1) / 2]);
        //         index = (index - 1) / 2;
        //     }
        // }
    }
    void print()
    {
        for (int index = 0; index < size; index++)
        {
            cout << arr[index] << endl;
        }
        cout << "------" << endl;
    }

    void decreasekey(int value, int index)
    {
        arr[index] = value;
        while (index != 0 && arr[(index - 1) / 2] > arr[index])
        {
            if (arr[(index - 1) / 2] > arr[index])
            {
                swap(arr[(index - 1) / 2], arr[index]);
                index = (index - 1) / 2;
            }
        }
    }

    void minHeapify(int index = 0)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < size && arr[index] > arr[left])
            smallest = left;
        if (right < size && arr[smallest] > arr[right])
            smallest = right;
        if (smallest != index)
        {
            swap(arr[smallest], arr[index]);
            minHeapify(smallest);
        }
    }

    int extractMin()
    {
        int temp = arr[0];
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify();
        return temp;
    }

    void deleteKey(int index)
    {
        decreasekey(INT16_MIN, index);
        extractMin();
    }
};

void maxHeapify(int arr[], int index, int size)
{
    int left, largest, right;
    left = 2 * index + 1;
    right = 2 * index + 2;
    largest = index;
    if (largest < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[largest] < arr[right])
        largest = right;
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        maxHeapify(arr, largest, size);
    }
}

void buildHeap(int arr[], int size)
{
    for (int index = (size - 2) / 2; index >= 0; index++)
    {
        maxHeapify(arr, index, size);
    }
}

void heapSort(int arr[], int size)
{
    buildHeap(arr, size);
    for (int index = size - 1; index >= 1; index--)
    {
        swap(arr[0], arr[index]);
        maxHeapify(arr, 0, index);
    }
    for (int index = 0; index < 15; index++)
    {
        cout << arr[index] << " ";
    }
}

int main()
{
    Heap h(20);
    h.insert(321);
    h.insert(143);
    h.insert(17);
    h.insert(16);
    h.insert(19);
    h.insert(241);
    h.insert(13);
    h.insert(21);
    h.print();
    h.decreasekey(4, 4);
    cout << h.extractMin() << endl;
    h.print();
    h.deleteKey(3);
    int arr[] = {51, 20, 53, 46, 4, 23, 54, 33, 234, 65, 11, 21, 35, 87, 9};

    heapSort(arr, 15);

    return 0;
}