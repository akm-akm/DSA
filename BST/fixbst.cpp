#include <iostream>
#include <queue>
#include <set>
#include <vector>
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
    if (tree == NULL)
        return true;
    return check(tree->left, l, tree->data) && l < tree->data && tree->data < u;
    return check(tree->right, tree->data, u) && l < tree->data && tree->data < u;
}

void fix(Node *tree, vector<int> ar)
{
    if (tree == NULL)
        return;
    fix(tree->left, ar);
    ar.push_back(tree->data);
    fix(tree->right, ar);
    
}