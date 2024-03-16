#include<iostream>
using namespace std;


class TriNode{
    public:
        char data;
        TriNode* childrenArray[26];
        bool is_Terminal;

        TriNode(int val){
            this->data = val;
            this->is_Terminal = false;

            for(int i=0; i<26; i++){
                childrenArray[i] = NULL;
            }
        }
};

void insertNode(TriNode* node, string s){
    
    if(s.size() == 0){
        node->is_Terminal = true;
        return;
    }

    //solve 1 case
    TriNode* child;

    char c = s[0];
    int indx = c - 'a';

    if(node->childrenArray[indx] != NULL){
        //already present
        cout<<"found : "<<s[0]<<endl;
        child = node->childrenArray[indx];
    }
    else{
        //absent
        cout<<"insert : "<<s[0]<<endl;
        child = new TriNode(c);
        node->childrenArray[indx] = child;
    }
    //rest case will be handled by recursion
    insertNode(child, s.substr(1));
}

void deleteNode(TriNode* node, string s){
    
    if(s.size() == 0){
        node->is_Terminal = false;
        return;
    }

    //solve 1 case
    TriNode* child;

    char c = s[0];
    int indx = c - 'a';

    if(node->childrenArray[indx] != NULL){
        //already present
        cout<<"found : "<<s[0]<<endl;
        child = node->childrenArray[indx];
    }
    else{
        //absent
        return;
    }
    //rest case will be handled by recursion
    deleteNode(child, s.substr(1));
}

bool find(TriNode* node, string s){
    if(s.size() == 0 && node->is_Terminal == true){
        return true;
    }

    //solve 1 case
    TriNode* child;

    char c = s[0];
    int indx = c - 'a';

    if(node->childrenArray[indx] != NULL){
        //already present
        cout<<"found : "<<s[0]<<endl;
        child = node->childrenArray[indx];
    }
    else{
        //absent
        return false;
    }

    return find(child, s.substr(1));
}

int main(){

    TriNode* root = new TriNode('-'); 

    //INSERTIONS
    insertNode(root, "vikas");
    cout<<endl;

    insertNode(root, "viky");
    cout<<endl;

    insertNode(root, "vikyis");
    cout<<endl;

    //SEARCH
    if(find(root, "vikas")){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element NOT found"<<endl;
    }

    cout<<endl;
    deleteNode(root, "vikas");
    cout<<endl;
    
    //SEARCH
    if(find(root, "vikas")){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element NOT found"<<endl;
    }

    return 0;
}