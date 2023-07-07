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

void findMiddle(Node *head)
{
    Node *c = head;
    if (head == NULL)
        cout << "NULL";
    int i = 0, count = 0;
    while (c != NULL)
    {
        count++;
        c = c->next;
    }
    cout << count;
    while (i < count / 2)
    {
        c = c->next;
    }
    cout << c->data;
}

void findMiddleEfficient(Node *head)
{
    Node *curr = head;
    if (head == NULL)
        cout << "NULL";
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    findMiddleEfficient(head);
}