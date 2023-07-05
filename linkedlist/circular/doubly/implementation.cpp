#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
void print(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << endl;
    for (Node *i = head->next; i != head; i = i->next)
    {
        cout << i->data << endl;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    head->next = a;
    head->prev = b;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = head;
    print(head);
}