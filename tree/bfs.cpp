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

int height(Node *tree, int c = 1)
{
    if (tree == NULL)
        return 0;
    c += max(height(tree->left, 1), height(tree->right, 1));
    return c;
}

void knode(Node *tree, int k, int c = 0)
{
    if (tree == NULL)
        return;
    if (c == k - 1)
    {
        cout << tree->data << " ";
        return;
    }
    knode(tree->left, k, c + 1);
    knode(tree->right, k, c + 1);
}

void printBFS(Node *tree)
{
    int k = height(tree);
    for (int i = 1; i <= k; i++)
    {
        knode(tree, i);
        cout << endl;
    }
}

//                    10
//           3                 20
//      54       7        39        66
//    87 111                     22    12
//  9
//   5

void bfs(Node *tree)
{
    queue<Node *> q;
    q.push(tree);
    while (!q.empty())
    {
        Node *curr = q.front();
        cout << curr->data << " ";
        q.pop();
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
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
    bfs(head);
    return 0;
}