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
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

Node *sortedInsert(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }

    if (head->data > x)
    {
        temp->next = head;
        return temp;
    }

    Node *c = head;

    while (c->next != NULL && c->next->data < x)
    {
        c = c->next;
    }
    temp->next = c->next;
    c->next = temp;
    return head;
}
int main()
{
    Node *head = new Node(30);
    head->next = new Node(20);
    head->next->next = new Node(10);
    head->next->next->next = new Node(4);
    print(head);
    head = sortedInsert(head, 22);
    print(head);
}