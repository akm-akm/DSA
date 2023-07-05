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
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }
    Node *curr = head;
    head = head->next;
    head->prev = NULL;
    delete curr;
    return head;
}

Node *deleteEnd(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;
    delete (curr->next);
    curr->next = NULL;
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    head = deleteEnd(head);
    print(head);
}