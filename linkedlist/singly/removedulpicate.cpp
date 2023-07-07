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

Node *removeDup(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *t = curr->next;
            curr->next = curr->next->next;
            delete t;
        }
        else
            curr = curr->next;
    }
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
    Node *head = new Node(10);
    head->next = new Node(10);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    print(head);
    head = removeDup(head);
    print(head);
}