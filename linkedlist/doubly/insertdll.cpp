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

Node *insertHead(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    if (head == NULL)
        return temp;
    head->prev = temp;
    return temp;
}

Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}
void print(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}
int main()
{
    Node *head = NULL;
    head = insertHead(head, 1);
    head = insertHead(head, 2);
    head = insertHead(head, 3);
    head = insertHead(head, 4);
    head = insertHead(head, 5);
    head = insertEnd(head, 6);
    head = insertEnd(head, 7);
    head = insertEnd(head, 8);
    head = insertEnd(head, 9);
    print(head);
    return 0;
}