#include <iostream>
#include <queue>
#include <set>
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

bool check(Node *tree, int l = INT32_MIN, int u = INT32_MAX)
{
    if (tree == NULL) return true;
    return check(tree->left, l, tree->data) && l < tree->data && tree->data < u;
    return check(tree->right, tree->data, u) && l < tree->data && tree->data < u;
}
