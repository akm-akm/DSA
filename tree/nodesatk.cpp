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

void knode(Node *tree, int c = 0)
{
    if (tree == NULL)
        return;
    if (c == 3)
    {
        cout << tree->data << endl;
        return;
    }
    knode(tree->left, c + 1);
    knode(tree->right, c + 1);
}
int main()
{
    Node *head = new Node(10);
    head->right = new Node(20);
    head->left = new Node(20);
    head->left->left = new Node(20);
    head->left->left->left = new Node(20);
    head->left->left->left->left = new Node(20);
    head->left->left->left->left->right = new Node(20);

    head->right->right = new Node(30);
    head->right->right->right = new Node(40);
    knode(head);
    return 0;
}