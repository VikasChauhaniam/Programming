#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree(){

    
    int val;
    cin >> val;

    if(val == -1){
        return NULL;
    }

    //root node
    Node* node = new Node(val);
    //left tree
    cout << "left of "<<node->data<<" is: ";
    node->left = createTree();
    //right tree
    cout << "right of "<<node->data<<" is: ";
    node->right = createTree();

    return node;

}

void printPreOrder(Node* node){

    if(node == NULL){
        return;
    }

    cout<< node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);

    
}

void printInOrder(Node* node){

    if(node == NULL){
        return;
    }

    
    printInOrder(node->left);
    cout<< node->data << " ";
    printInOrder(node->right);

    
}

void printPostOrder(Node* node){

    if(node == NULL){
        return;
    }

    
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout<< node->data << " ";

    
}

void levelOrderTraversal(queue<Node*> &qu){

    

    if(qu.empty()){
        return;
    }

    Node* node = qu.front();
    
    qu.pop();

    if(node == NULL){
        cout<<endl;
        if(!qu.empty()){
            qu.push(NULL);
        }
        
    }
    else{
        cout << node->data <<" ";
        

        if(node->left){
            qu.push(node->left);
        }

        if(node->right){
            qu.push(node->right);
        }
    }
    
    
    levelOrderTraversal(qu);
}

int findHeight(Node* &root){

    if(root == NULL){
        return 0;
    }

    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);

    return max(leftH, rightH) +1;
}

int findDiameter(Node* &root){

    if(root == NULL){
        return 0;
    }

    int leftD = findDiameter(root->left);
    int rightD = findDiameter(root->right);
    int bothsideD = findHeight(root->left) + findHeight(root->right);

    return max(leftD, max(rightD, bothsideD));

}

int main(){

    cout << "enter node value or -1 for NULL:";
    Node* root = createTree();
    
    // cout<<"preOrder"<<endl;
    // printPreOrder(root);
    // cout<<endl;

    // cout<<"InOrder"<<endl;
    // printInOrder(root);
    // cout<<endl;

    // cout<<"postOrder"<<endl;
    // printPostOrder(root);
    // cout<<endl;

    // cout<<"Level Order"<<endl;
    // queue<Node*> qu;
    // qu.push(root);
    // qu.push(NULL);
    // levelOrderTraversal(qu);

    // int x = findHeight(root);
    // cout<<"height is:"<<x<<endl;

    int d = findDiameter(root);
    cout<<"d is:"<<d<<endl;


    return 0;
}