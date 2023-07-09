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

//                  50
//           40            70
//        30    45      55    75
//

bool search(Node *tree, int k)
{
    if (tree == NULL)
        return false;
    else if (tree->data == k)
        return true;
    else if (tree->data > k)
        return search(tree->left, k);
    return search(tree->right, k);
}

int main()
{
    Node *tree = new Node(10);
    cout << search(tree, 10);
}