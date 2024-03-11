#include<iostream>
#include<queue>
using namespace std;
#include<map>

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
    //cout<<endl;
    cin >> val;

    if(val == -1){
        return NULL;
    }

    //root node
    Node* node = new Node(val);
    //left tree
    //cout<<endl;
    cout << "left of "<<node->data<<" is: ";
    node->left = createTree();
   // cout<<endl;
    //right tree
    cout << "right of "<<node->data<<" is: ";
    node->right = createTree();
    cout<<endl;

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

void leftView(Node* root, int level, int &count){
    if(root == NULL){
        return;
    }
    if(level == count){
        cout<<root->data <<endl;
        count++;
    }

    leftView(root->left, level+1, count);
    leftView(root->right, level+1, count);
}    

void rightView(Node* root, int level, int &count){
    if(root == NULL){
        return;
    }
    if(level == count){
        cout<<root->data <<endl;
        count++;
    }

    rightView(root->right, level+1, count);
    rightView(root->left, level+1, count);
    
} 

void topView(Node* root){

    map<int, int> mp;       //vertical_level and element
    queue<pair<Node*, int>> q;    //node and vertical_level

    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> x = q.front();
        q.pop();

        if(!mp[x.second]){
            mp[x.second] = x.first->data;
        }

        if(x.first->left){
            q.push(make_pair(x.first->left, x.second-1));
        }
        if(x.first->right){
            q.push(make_pair(x.first->right, x.second+1));
        }
    }
    for(auto i : mp){
        cout << i.second << " ";
    }
}

void bottomView(Node* root){

    map<int, int> mp;       //vertical_level and element
    queue<pair<Node*, int>> q;    //node and vertical_level

    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> x = q.front();
        q.pop();

        
        mp[x.second] = x.first->data;
         

        if(x.first->left){
            q.push(make_pair(x.first->left, x.second-1));
        }
        if(x.first->right){
            q.push(make_pair(x.first->right, x.second+1));
        }
    }
    for(auto i : mp){
        cout << i.second << " ";
    }
}

void leftBoundaryPrint(Node* root){
    if(root == NULL){
        return;
    }

    //if leaf node then also return
    if(root->left == NULL && root->right == NULL){
        return;
    }

    cout<< root->data <<" ";
    if(root->left){
        leftBoundaryPrint(root->left);
    }
    else{
        leftBoundaryPrint(root->right);
    }
}

void leafBoundaryPrint(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout<< root->data <<" ";
    }
    leafBoundaryPrint(root->left);
    leafBoundaryPrint(root->right);
}

void rightBoundaryPrint(Node* root){
    if(root == NULL){
        return;
    }

    //if leaf node then also return
    if(root->left == NULL && root->right == NULL){
        return;
    }

    
    if(root->right){
        leftBoundaryPrint(root->right);
    }
    else{
        leftBoundaryPrint(root->left);
    }
    cout<< root->data <<" ";
}

void boundaryNodes(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data <<" ";
    leftBoundaryPrint(root->left);
    leafBoundaryPrint(root->left);
    leafBoundaryPrint(root->right);
    rightBoundaryPrint(root->right);
}

int main(){

    cout << "enter node value or -1 for NULL:";
    Node* root = createTree();

    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    levelOrderTraversal(qu);
    
    int level =0;
    int count = 0;


    // leftView(root, level, count);
   // rightView(root, level, count);
//    topView(root);
//    cout<<endl;
//    bottomView(root);

    boundaryNodes(root);


    return 0;
}