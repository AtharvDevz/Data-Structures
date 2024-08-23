#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        this->data = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};

void setLeftChild(Node* left, Node* parent){
    if(parent == nullptr){
        return ;
    }
    parent->left = left;
}

void setRightChild(Node* right, Node* parent){
    if(parent == nullptr){
        return ;
    }
    parent->right = right;
}

void buildBinaryTree(Node* root){
    if(root == nullptr){
        return ;
    }
    
    int leftData, rightData;
    Node* left;
    Node* right; 
    cout<<"Left of "<<root->data<<" : ";
    cin>>leftData;
    if(leftData != -1){
        left = new Node(leftData);
        root->left = left;
        buildBinaryTree(root->left);
    }
    cout<<"Right of "<<root->data<<" : ";
    cin>>rightData;
    if(rightData != -1){
        right = new Node(rightData);
        root->right = right;
        buildBinaryTree(root->right);
    }
}

void breadthFirstTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);  // Use nullptr instead of nullptr
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == nullptr){
            cout << "\n";
            if(!q.empty()){
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " , ";
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
        }
    }
}

void preOrderTraversal(Node* root){
    if(root == nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == nullptr){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void PostOrderTraversal(Node* root){
    if(root == nullptr){
        return ;
    }
    stack<Node*> st;
    stack<int> result;
    st.push(root);
    Node* current = root;
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        result.push(node->data);
        if (node->left != nullptr){
            st.push(node->left); 
        }
        if (node->right != nullptr) {
            st.push(node->right);
        }
    }
    while (!result.empty()) {
        cout << result.top()<<endl;
        result.pop();
    }
}

void inOrderTraversal(Node* root){
    if(root == nullptr){
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}


void InOrderTraversal(Node* root){
    if(root == nullptr){
        return ;
    }
    stack<Node* > st;
    Node* current = root ;
    st.push(root);
    while (!st.empty() || current != nullptr){
        while (current != nullptr){
            st.push(current->left);
            current = current->left ;
        }
        Node* poppedNode = st.top() ;
        st.pop();
        cout<<poppedNode->data<<" ";
        current = poppedNode->right;
    }
    
}

int main()
{
    Node *root = new Node(36);
    buildBinaryTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "\nBreadth First Order Traversal : " << endl;
    breadthFirstTraversal(root);
    cout<<"\nPre Order Traversal : "<<endl;
    preOrderTraversal(root);
    cout<<"\nPost Order Traversal : "<<endl;
    postOrderTraversal(root);
    cout<<"\nIn Order Traversal : "<<endl;
    inOrderTraversal(root);
    InOrderTraversal(root);
    return 0;
}