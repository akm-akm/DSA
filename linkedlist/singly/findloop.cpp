#include <iostream>
#include <unordered_set>
#include <utility>
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

void findLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        cout << false;
    unordered_set<Node *> s;

    Node *curr = head;
    while (curr != NULL)
    {
        if (s.find(curr) != s.end())
        {
            cout << true;
            return;
        }
        s.insert(curr);
        curr = curr->next;
    }
    cout << false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    findLoop(head);
}