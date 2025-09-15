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

void insertAtTail(Node* &head,Node* &tail,int d){
    Node* temp=new Node(d);
    if(head==NULL){
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

int deleteAllOccurences(Node* &head,Node* &tail,int key){
    if(head==NULL) return 0;
    int count=0;

    //if key at head
    while(head!=NULL && head->data==key){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        count++;
    }

    //if in middle or at end
    Node* curr=head;
    Node* prev=NULL;

    while(curr!=NULL){
        if(curr->data==key){
            count++;
            prev->next=curr->next;

            //if we are deleting tail
            if(curr->next==NULL){
                tail=prev;  //update tail
            }
            delete curr;
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    if (head==NULL){
        tail=NULL; //empty
    }
    return count;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    int key;
    

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 1);

    cout<<"Original List:   ";
    print(head);
    
    cout<<"Enter key to delete: ";cin>>key;
    
    int count=deleteAllOccurences(head,tail,key);
    cout<<"Count: "<<count<<endl;
    cout<<"Updated list: ";
    print(head);

    return 0;
}


