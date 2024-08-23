#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Node *buildTree(Node *root)
// {
//     int data;
//     cout << "Enter the Data : ";
//     cin >> data;
//     root = new Node(data);

//     if (data == -1)
//     {
//         return NULL;
//     }
//     cout << "left Part of " << root->data << ": ";
//     root->left = buildTree(root->left);
//     cout << "Right Part of " << root->data << ": ";
//     root->right = buildTree(root->right);

//     return root;
// }

void buildBinaryTree(Node* root){
    if(root == NULL){
        return ;
    }
    
    int leftData, rightData;
    Node* left;
    Node* right;
    cout<<"Left of"<<root->data<<" : ";
    cin>>leftData;
    if(leftData != -1){
        left = new Node(leftData);
        root->left = left;
        buildBinaryTree(root->left);
    }
    cout<<"Right of"<<root->data<<" : ";
    cin>>rightData;
    if(rightData != -1){
        right = new Node(rightData);
        root->right = right;
        buildBinaryTree(root->right);
    }
}

void breadthFirstTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data;
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}


void inOrderTraversal(Node* root){
    
}

int main()
{
    Node *root = new Node(36);
    buildBinaryTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "\nBreadth First Order Traversal : " << endl;
    breadthFirstTraversal(root);
    return 0;
}