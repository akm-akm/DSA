#include <iostream>

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

void left(Node *tree)
{
    if (tree == NULL)
        return;
    left(tree->left);
    cout << tree->data << " ";
    if (tree->left == NULL)
    {
        left(tree->right);
        
    }
}

int main()
{
    Node *head = new Node(10);
    head->left = new Node(50);
    head->right = new Node(60);
    head->right->left = new Node(70);
    head->right->right = new Node(20);
    head->right->left->left = new Node(8);

    left(head);
    return 0;
}