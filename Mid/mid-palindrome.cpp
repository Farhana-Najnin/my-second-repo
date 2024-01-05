#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};


void print_linked_list(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
void insert_tail(Node *&head,Node *&tail,int val )//o(1)
{
     Node *newNode=new Node(val);
     if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
     }
     tail->next=newNode;
     tail=newNode;

}
void Reverse(Node *&head ,Node *cur){
if(cur->next==NULL){
head=cur;
return;
}
Reverse(head,cur->next);
cur->next->next=cur;
cur->next=NULL;
}
bool Palindrome(Node *head){
Node *newHead=NULL;
    Node *newTail=NULL;
    Node *tmp=head;
    while(tmp!=NULL){
        insert_tail(newHead,newTail,tmp->val);
        tmp=tmp->next;
    }
    Reverse(newHead,newHead);
        tmp=head;
        Node *tmp2=newHead;
        while(tmp!=NULL){
            if(tmp->val!=tmp2->val){
                return false;
            }
            tmp=tmp->next;
            tmp2=tmp2->next;
        }
        return true;

    }


int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int val;

    while(true)
    {
        cin>>val;
        if(val==-1)
        {
            break;
        }
        insert_tail(head,tail,val);
    }
bool t=Palindrome(head);
if(t==true){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}


  //  print_linked_list(head);
    return 0;
}


