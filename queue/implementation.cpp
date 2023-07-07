#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct QueueLL
{
    Node *head;
    Node *rear;
    int siz;
    QueueLL()
    {
        head = NULL;
        rear = NULL;

        siz = 0;
    }
    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (rear == NULL)
        {
            rear = temp;
            head = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        siz++;
    }
    void dequeue()
    {
        if (head == NULL)
        {
            exit(0);
        }
        else
        {
            Node *c = head;
            head = head->next;
            delete c;
            siz--;
        }
    }
    int peek()
    {
        if (head == NULL)
        {
            exit(0);
        }
        return head->data;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    int size()
    {
        return siz;
    }
    void print()
    {
        Node *c = head;
        while (c != NULL)
        {
            cout << c->data << " ";
            c = c->next;
        }
        cout << endl;
    }
};

struct QueueAr
{
    int *arr;
    int s;
    QueueAr(int cap)
    {
        s = 0;
        arr = new int[cap];
    }

    void enqueue(int x)
    {
        arr[s] = x;
        s++;
    }
    void dequeue()
    {
        if (s == 0)
        {
            exit(0);
        }
        else
        {
            for (int i = 1; i < s; i++)
            {
                arr[i - 1] = arr[i];
            }
            s--;
        }
    }
    int peek()
    {
        if (s)
        {
            exit(0);
        }
        return arr[0];
    }
    bool isEmpty()
    {
        return s == 0;
    }
    int size()
    {
        return s;
    };
};

// |4| | | |7|9|1|8|5| cap=9 s=6 front=4
// |4| | | | |9|1|8|5| cap=9 s=5 front=5
// |5|4|9|2| | |1|8|5| cap=9 s=7 front=6
// |4|7|9|1|8|5| | | | cap=9 s=6 front=0

struct QueueArEff
{
    int *arr;
    int s, front, c, rear;
    QueueArEff(int cap)
    {
        c = cap;
        arr = new int[c];
        s = 0;
    }
    bool isEmpty() { return s == 0; }
    bool isFull() { return s == c; }
    int getRear() { return ((front + s - 1) % c); }
    int getFront() { return s == 0 ? -1 : front; }
    void enqueue(int x)
    {
        if (s == c)
            exit(0);
        int rear = getRear();
        rear = (rear + 1) % c;
        arr[rear] = x;
        s++;
    }
    void dequeue()
    {
        if (s == 0)
            exit(0);
        front = (front + 1) % c;
        s--;
    }
};

main()
{

    QueueLL q;
    q.enqueue(4);
    q.enqueue(9);
    q.enqueue(7);
    q.enqueue(5);
    cout << q.size();

    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    cout << q.isEmpty();
    cout << q.size();
}