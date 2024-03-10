#include<iostream>
#include<queue>
using namespace std;
#include <algorithm>

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

Node* buildTree(int inOrder[],int postOrder[],int &postOrderIndx,int inOrderStart,int inOrderEnd, int size){
    if(postOrderIndx < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    auto itr = find(inOrder, inOrder + size, postOrder[postOrderIndx]);
    
    int position = distance(inOrder, itr);
   // cout << "index of "<<preOrder[preOrderIndx]<<" is : "<<position<<endl;
    Node* node = new Node(postOrder[postOrderIndx]);
    postOrderIndx--;

    node->right = buildTree(inOrder, postOrder, postOrderIndx, position+1, inOrderEnd, size);
    node->left = buildTree(inOrder, postOrder, postOrderIndx, inOrderStart, position-1, size);
    

    return node;

}


int main(){

    int inOrder[] = {8, 14, 6, 2, 10, 4};
    int postOrder[] ={8, 6, 14, 4, 10, 2};

    int size = 6;   
    int postOrderIndx = size-1;
    int inOrderStart = 0;
    int inOrderEnd = size-1;
    
    Node* root =  buildTree(inOrder, postOrder, postOrderIndx, inOrderStart, inOrderEnd, size);

    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    levelOrderTraversal(qu);


    return 0 ;
}