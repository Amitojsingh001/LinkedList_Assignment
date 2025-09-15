#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtTail(Node* &head,Node* & tail,int d){
    Node* temp=new Node(d);

    if (head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* findMiddle(Node* head){
    if(head==NULL) return NULL;
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next; 
        fast=fast->next->next;
    }
    return slow; //it is at middle
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    // creating a list 1->2->3->4->5
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    cout<<"Linked List: ";
    print(head);

    Node* middle = findMiddle(head);
    if(middle != NULL)
        cout<<"Middle node: "<<middle->data<<endl;

    return 0;
}