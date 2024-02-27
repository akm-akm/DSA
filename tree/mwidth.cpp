#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int maxWidth(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> a;
    a.push(root);
    a.push(NULL);
    int m = 1;
    int c = 0;
    while (a.empty() == false)
    {
        Node *front = a.front();
        if (front != NULL)
        {
            a.pop();
            c++;
            a.push(front->left);
            a.push(front->right);
        }
        else
        {
            a.pop();
            m = max(m, c);
            a.push(NULL);
            c = 0;
        }
    }
    return m;
}

int main()
{
    Node *a = new Node(10);
    a->left = new Node(20);
    a->right = new Node(30);
    a->left->left = new Node(20);
    a->left->right = new Node(20);
    a->right->right = new Node(20);
    a->right->right = new Node(20);
    cout << maxWidth(a);
}