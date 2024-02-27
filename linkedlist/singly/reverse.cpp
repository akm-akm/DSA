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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *a = NULL;
    Node *b = head;
    Node *n;
    while (b != NULL)
    {
        n = b->next;
        b->next = a;
        a = b;
        b = n;
    }
    return a;
}

Node *reverseRecursive(Node *curr, Node *prev = NULL)
{
    if (curr == NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return reverseRecursive(next, curr);
}


int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    print(head);
    head = reverseRecursive(head);
    print(head);
}
