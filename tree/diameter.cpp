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

int height(Node *tree, int c = 1)
{
    if (tree == NULL)
        return 0;
    c += max(height(tree->left, 1), height(tree->right, 1));
    return c;
}

int diameter(Node *tree)
{
    if (tree == NULL)
        return 0;
    int d1 = height(tree->left) + height(tree->right) + 1;
    int d2 = diameter(tree->left);
    int d3 = diameter(tree->right);
    return max(d1, max(d2, d3));
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
    cout << diameter(head);
    return 0;
}