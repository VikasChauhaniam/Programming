#include<iostream>
using namespace std;
#include<queue>

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node*  addNode(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = addNode(root->right, data);
    }
    else{
        root->left = addNode(root->left, data);
    }

    return root;
}

Node* createBST(Node* &root){
    cout << "enter data :";
    int data;
    cin >> data;

    

    while(data != -1){
        root = addNode(root, data);
        cout << "enter data :";
        cin >> data;
    }
    return root;
}

void printLevelOrder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<< " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            
        }
    }
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    
    inOrder(root->left);
    cout << root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data<<" ";
}

void minValue(Node* root){
    if(root == NULL){
        return;
    }

    while(root->left != NULL){
        root = root->left;
    }
    cout<<"min value is :"<<root->data;
}

void maxValue(Node* root){
    if(root == NULL){
        return;
    }

    while(root->right != NULL){
        root = root->right;
    }
    cout<<"max value is :"<<root->data;
}

bool searchInBST(Node* root, int find){
    if(root == NULL){
        return false;
    }

    bool leftAns;
    bool rightAns;

    if(root->data == find){
        return true;
    }
    else{
        leftAns = searchInBST(root->left, find);
        rightAns = searchInBST(root->right, find);
    }
    return leftAns || rightAns;
}

Node* deleteNode(Node* root,int &target){
    if(root == NULL){
        return NULL;
    }

    if(target == root->data){
        
        if(root->left == NULL && root->right == NULL){
            //leaf node
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            //leftchild but not right
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        else if(root->left == NULL && root->right != NULL){
            //rightchild but not left
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        else{
            //both child exist
            Node* temp = root;
            while(temp->left){
                temp = temp->left;
            }
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
            return root;
        }
        
        
    }
    else if(target > root->data){
        root->right = deleteNode(root->right, target);
    }
    else{
        root->left = deleteNode(root->left, target);
    }
    return root;
}
int main(){

    Node* root = NULL;
    createBST(root);
    printLevelOrder(root);

    // cout<<endl;
    // preOrder(root);

    // cout<<endl;
    // inOrder(root);

    // cout<<endl;
    // postOrder(root);

    // cout<<endl;
    // minValue(root);

    // cout<<endl;
    // maxValue(root);
    // cout<< endl;

    // bool x = searchInBST(root, 41);
    // if(x){
    //     cout << "element found"<<endl;
    // }else{
    //     cout << "not found"<<endl;
    // }

    cout << "enter taget to delete : ";
    int target;
    cin >> target;
    while(target != -1){
        root = deleteNode(root, target);
        printLevelOrder(root);
        cout << "enter taget to delete : ";
        cin >> target;
    }
}