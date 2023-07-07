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

int maxi(Node *tree)
{
    if (tree == NULL)
        return INT32_MIN;
    return max(tree->data, max(maxi(tree->left), maxi(tree->right)));
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
    cout << maxi(head);
    return 0;
}