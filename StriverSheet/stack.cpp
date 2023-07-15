// Stack class.
class Stack
{
    int c, s, *arr;

public:
    Stack(int capacity)
    {
        arr = new int[capacity];
        c = capacity;
        s = 0;
    }

    void push(int num)
    {
        if (s < c)
        {
            arr[s] = num;
            s++;
        }
    }

    int pop()
    {
        if (s != 0)
        {

            s--;
            return arr[s];
        }
        return -1;
    }

    int top()
    {
        return s != 0 ? arr[s - 1] : -1;
    }

    int isEmpty()
    {
        return s == 0 ? 1 : 0;
    }

    int isFull()
    {
        return s == c ? 1 : 0;
    }
};
