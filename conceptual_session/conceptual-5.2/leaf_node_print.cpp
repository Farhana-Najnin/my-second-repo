#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node *left;
    Node*right;
    Node(int val){
    this->val=val;
    this->left=NULL;
        this->right=NULL;
    }
};
Node *input_tree(){
int val;
cin>>val;
Node *root;
if(val==-1){
    root=NULL;
}
else{
    root=new Node(val);
}
queue<Node*>q;
if(root){
    q.push(root);
}
while(!q.empty()){
    //1.ber kore ana
    Node *p=q.front();
    q.pop();
    //jabotiyo ja kaj ache kora
    int l,r;
    cin>> l>> r;
    Node *myLeft;
    Node *myRight;
    if(l == -1)
        myLeft=NULL;
    else
        myLeft=new Node(l);
    if(r == -1)
        myRight=NULL;
    else
        myRight=new Node(r);
    //connection
    p->left=myLeft;
    p->right=myRight;
    //children gulo rakha
    if(p->left)
       q.push(p->left);
    if(p->right)
        q.push(p->right);

}
return root;
}
void printLeafNodes(Node *root,vector<int>&v){
if(root==NULL) return;
if(root->left==NULL&&root->right==NULL){
v.push_back(root->val);
}
printLeafNodes(root->right,v);
printLeafNodes(root->left,v);
}
vector<int>printLeafs(Node*root){
vector<int>v;
printLeafNodes(root,v);
return v;
}
int main(){
Node *root=input_tree();
vector<int>v;
v=printLeafs(root);
cout<<v.size()<<endl;
for(int i:v){
    cout<<i<<endl;
}
return 0;
}


