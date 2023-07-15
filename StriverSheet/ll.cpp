#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(0);
    Node *curr = head;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        curr->next = newNode;
        curr = curr->next;
    }
    return head;
}