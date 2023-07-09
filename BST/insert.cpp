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

//                  50
//           40            70
//        30    45      55    75
//

Node *insert(Node *tree, int k)
{
    if (tree == NULL)
        return new Node(k);

    else if (k > tree->data)
        tree->right = insert(tree->right, k);
    else if (k < tree->data)
        tree->left = insert(tree->left, k);
    return tree;
}

void bfs(Node *tree)
{
    queue<Node *> q;
    q.push(tree);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *curr = q.front();

        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    Node *tree = new Node(10);
    tree = insert(tree, 14);
    tree = insert(tree, 7);
    tree = insert(tree, 9);
    tree = insert(tree, 24);
    tree = insert(tree, 1);
    bfs(tree);
}