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

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *t = head;
    while (t->next != head)
    {
        t = t->next;
    }
    t->next = head->next;
    delete (head);
    return t->next;
}

Node *deleteKth(Node *head, int k)
{ // k less than cll size;
    int c = 2;
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    if (k == 1)
    {
        return deleteHead(head);
    }
    Node *t = head;
    while (c < k)
    {
        t = t->next;
    }
    Node *temp = t->next;
    t->next = t->next->next;
    delete (temp);
    return head;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    head = deleteKth(head, 2);
    print(head);
}