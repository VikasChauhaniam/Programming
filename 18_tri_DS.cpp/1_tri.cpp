#include<iostream>
using namespace std;
#include<vector>

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

void otherStrings(TriNode* node, vector<string> &ans, string v){
    if(node->is_Terminal == true){
        ans.push_back(v);
    }

    for(char ch = 'a'; ch <= 'z'; ch++){
        int i = ch- 'a';

        if(node->childrenArray[i] != NULL){
            
            v.push_back(ch);
            
            TriNode* newnode = node->childrenArray[i];
            otherStrings(newnode, ans, v);
            v.pop_back();
            
        }
        
    }
}

void printPrefix(TriNode* root, string s, vector<string> &ans){
    if(s.length() == 0){
        TriNode*  lastChar = root;
        otherStrings(lastChar, ans, s);
    }
    
    char ch = s[0];
    int indx = ch - 'a';
    TriNode*  child;
    if(root->childrenArray[indx] != NULL){
        child = root->childrenArray[indx];
    }else{
        return;
    }

    
    printPrefix(child, s.substr(1), ans);
    
}

int main(){

    TriNode* root = new TriNode('-'); 

    //INSERTIONS
    insertNode(root, "vikas");
    cout<<endl;

    insertNode(root, "viky");
    cout<<endl;

    insertNode(root, "vikram");
    cout<<endl;

    //SEARCH
    // if(find(root, "vikas")){
    //     cout<<"element found"<<endl;
    // }
    // else{
    //     cout<<"element NOT found"<<endl;
    // }

    // cout<<endl;
    // deleteNode(root, "vikas");
    // cout<<endl;

    // //SEARCH
    // if(find(root, "vikas")){
    //     cout<<"element found"<<endl;
    // }
    // else{
    //     cout<<"element NOT found"<<endl;
    //}

    vector<string> ans;
    string input = "vik";
    printPrefix(root, input, ans);

    for(auto i : ans){
        cout<<input+i<<endl;
    }

    return 0;
}