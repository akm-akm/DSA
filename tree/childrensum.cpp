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

//                    10
//           3                 20
//      54       7        39        66
//    87 111                     22    12
//  9
//   5

bool sum(Node *tree)
{
    if (tree == NULL)
        return true;
        
}

int main()
{
    Node *head = new Node(10);
    head->right = new Node(20);
    head->left = new Node(3);
    head->left->left = new Node(54);
    head->left->right = new Node(7);
    head->left->left->left = new Node(87);
    head->left->left->right = new Node(111);
    head->left->left->left->left = new Node(9);
    head->left->left->left->left->right = new Node(5);

    head->right->right = new Node(66);
    head->right->left = new Node(39);
    head->right->right->right = new Node(12);
    head->right->right->left = new Node(22);
    cout << sum(head);
    return 0;
}