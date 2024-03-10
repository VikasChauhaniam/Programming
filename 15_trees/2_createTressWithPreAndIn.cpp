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

Node* buildTree(int inOrder[],int preOrder[],int &preOrderIndx,int inOrderStart,int inOrderEnd, int size){
    if(preOrderIndx >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    auto itr = find(inOrder, inOrder + size, preOrder[preOrderIndx]);
    
    int position = distance(inOrder, itr);
   // cout << "index of "<<preOrder[preOrderIndx]<<" is : "<<position<<endl;
    Node* node = new Node(preOrder[preOrderIndx]);
    preOrderIndx++;

    node->left = buildTree(inOrder, preOrder, preOrderIndx, inOrderStart, position-1, size);
    node->right = buildTree(inOrder, preOrder, preOrderIndx, position+1, inOrderEnd, size);

    return node;

}


int main(){

    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int preOrder[] ={2, 8, 10, 6, 4, 12};

    int size = 6;   
    int preOrderIndx = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    
    Node* root =  buildTree(inOrder, preOrder, preOrderIndx, inOrderStart, inOrderEnd, size);

    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    levelOrderTraversal(qu);


    return 0 ;
}