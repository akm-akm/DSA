#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *solve(vector<int> arr, int i, int n)
{
    Node *root = NULL;
    if (i < n)
    {
        root = new Node(arr[i]);
        return solve(arr, 2 * i + 1, n);
        return solve(arr, 2 * i + 2, n);
    }
    return root;
}

Node *createTree(vector<int> &arr)
{

    return solve(arr, 0, arr.size());
}