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
void printDoWhile(Node *head)
{
    if (head == NULL)
        return;
    Node *i = head;
    do
    {
        cout << i->data << endl;
        i = i->next;
    } while (i != head);
}

Node *insertHead(Node *head, int x)
{
    Node *temp = new Node(x);
    Node *curr = head;
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return temp;
}
Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    Node *curr = head;
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return head;
}
Node *insertEndEfficient(Node *head, int x)
{
    Node *temp = new Node(x);
    Node *curr = head;
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    swap(head->data, temp->data);
    return temp;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    //  printDoWhile(head);
    head = insertHead(head, 99);
    head = insertEnd(head, 89);
    head = insertEndEfficient(head, 890);
    printDoWhile(head);
}