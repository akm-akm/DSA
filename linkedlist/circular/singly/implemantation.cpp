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
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    printDoWhile(head);
}