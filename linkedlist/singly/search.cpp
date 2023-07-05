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

int search(Node *head, int x)
{
    Node *curr = head;
    int c = 1;
    while (curr != NULL)
    {
        if (curr->data == x)
            return c;
        c++;
        curr = curr->next;
    }

    return -1;
}
int searchRec(Node *head, int x, int c = 1)
{
    if (head == NULL)
        return -1;
    if (head->data == x)
        return c;

    return searchRec(head->next, x, c = c + 1);
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    cout << search(head, 40);
    cout << searchRec(head, 40);
}