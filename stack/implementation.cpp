#include <iostream>
using namespace std;

struct StackArray
{
    int *arr;
    int cap, top;
    StackArray(int c)
    {
        cap = c;
        arr = new int[c];
        top = -1;
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int res = arr[top];
        top--;
        return res;
    }
    int peek()
    {
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

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
struct StackLL
{
    int s;
    Node *head;
    StackLL()
    {
        head = NULL;
        s = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        s++;
    }
    int pop()
    {
        if (head == NULL)
            return INT16_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        s--;
        return res;
    }
    int peek()
    {
        if (head == NULL)
        {
            return INT16_MAX;
        }
        return head->data;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    int size()
    {
        return s;
    }
};

int main()
{
    StackLL s;
    s.push(12);
    s.push(3);
    s.push(54);
    s.push(6);
    s.push(6);
    s.push(87);
    cout << s.size() << endl;

    return 0;
}