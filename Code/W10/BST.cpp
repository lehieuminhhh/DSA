#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left,*right;
} Node;

void Free(Node *root)
{
    if (root == NULL)
        return;
    Free(root->left);
    Free(root->right);
    free(root);
}

int leftOf(const Node *root, const int value)
{
    return value < root->data;
}
int rightOf(const Node *root, const int value)
{
    return value > root->data;
}

int leftMostVal(const Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
Node* Insert (Node* root, const int value)
{

    if (root == NULL)
    {
        Node *t = new Node;
        t->data = value;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if (leftOf (root, value))
    {
        root->left = Insert (root->left, value);
        return root;
    }
    root->right = Insert (root->right, value);
    return root;
}
void preOrder(const Node* root)
{
    if (root != NULL )
    {
        cout << root->data<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(const Node* root)
{
    if (root != NULL )
    {
        inOrder(root->left);
        cout << root->data<< " ";
        inOrder(root->right);
    }
}void postOrder(const Node* root)
{
    if (root != NULL )
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data<< " ";
    }
}
Node* Delete( Node* root, int value)
{
    if (root == NULL)
        return root;
    if (leftOf(root,value))
        root->left = Delete(root->left, value);
    else if (rightOf(root,value))
        root ->right = Delete(root->right,value);
    else
    {
        if (root->left == NULL)
        {
            Node *t = root->right;
            free (root);
            return t;
        }
        if (root->right == NULL)
        {
            Node *t = root->left;
            free(root);
            return t;
        }
        root->data = leftMostVal(root->right);
        root->right = Delete(root->right, root->data);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    int n, t;
    cin >> n;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> t;
        root = Insert (root, t);
    }
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout <<endl;
    return 0;
}
/*                    4
            2                   6
        1        3           5
*/

//9 13 4 3 5 6 7 9 24 35
