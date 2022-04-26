#include <bits/stdc++.h>
using namespace std;
int maxx = 0;
typedef struct Node
{
    int data;
    Node *left,*right;
} Node;

int leftOf(const Node *root, const int value)
{
    return value < root->data;
}
int rightOf(const Node *root, const int value)
{
    return value > root->data;
}

Node* Insert (Node* root, const int value,int depth)
{

    if (root == NULL)
    {
        Node *t = new Node;
        t->data = value;
        t->left = NULL;
        t->right = NULL;
        if (depth>maxx)
        {
            maxx = depth;
        }
        return t;
    }
    if (leftOf (root, value))
    {
        root->left = Insert (root->left, value,depth+1);
        return root;
    }
    root->right = Insert (root->right, value,depth+1);
    return root;
}

int main()
{
    Node *root = NULL;
    int n,t;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> t;
        root = Insert(root,t,1);
    }
    cout << maxx;
    return 0;
}
