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
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    return temp->prev;
}

Node *insertHead(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    if (head == NULL)
        return temp;
    head->prev = temp;
    return temp;
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
    print(head);

    head = reverse(head);
    print(head);
    return 0;
}