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
}