#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }

    ~Node(){
        int value=this->data;
        if (this->next !=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data: "<<value<<endl;
    }
    
};

void insertAtHead(Node* &head, int d){
    //first create new node
    Node* temp=new Node(d);
    //point the next of temp to head
    temp->next=head;
    //make temp the new head
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    //insert at start
    if (position==1){
        insertAtHead(head,d);
        return;
    }
    //node temp is potraying head
    Node* temp=head;
    int cnt=1;

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    //if position is tail, we need to update temp to tail 
    if (temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    //creating a node for d
    Node* nodeToInsert=new Node(d);

    nodeToInsert->next=temp->next;

    temp->next=nodeToInsert;
}

void print(Node* &head){
    //making head as temp
    Node* temp=head;
    
    //now moving temp till last(till it reaches NULL)
    while(temp!=NULL){
        cout<<temp-> data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(int position,Node* &head,Node* &tail){
    //deletingfirst
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while (cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;

        if (curr->next == NULL) {
            tail = prev;  
        }

        curr->next=NULL;
        delete curr;
    }
}

void deleteByValue(Node* &head, Node* &tail, int value){
    //if empty
    if(head==NULL){
        cout<<"List is empty\n";
        return;
    }

    //if value at head
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        if (head==NULL) tail=NULL; //empty
        temp->next=NULL;
        delete temp;
        return;
    }

    //if value at middle or end
    Node* curr=head;
    Node* prev=NULL;

    while(curr!=NULL && curr->data!=value){
        prev=curr;
        curr=curr->next;
    }

    //not found
    if (curr==NULL){
        cout<<"value not found\n";
        return;
    }

    prev->next=curr->next;
    if (curr->next==NULL) tail=prev; //deleted last node
    curr->next=NULL;
    delete curr;

}

int getLenth(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

int search(Node* head,int key){
    int pos=1;
    while (head!=NULL){
        if (head->data==key) {
            return pos;
        }
        head=head->next;
        pos++;
    }
    return -1;
}

int main(){
    //creating a new node
    Node* node1=new Node(10);

    Node* head=node1;
    Node* tail=node1;

    while (true){
        int n,num,pos;
        cout<<"1. insertion at beginning\n";
        cout<<"2. insertion at end\n";
        cout<<"3. insertion at particular position\n";
        cout<<"4. deletion from begining\n";
        cout<<"5. deletion from end\n";
        cout<<"6. deletion of specific node \n";
        cout<<"7. search for a node and display its position\n";
        cout<<"8. display all node values\n";
        cout<<"9. EXIT\n";

        cout<<"Enter your choice: ";cin>>n;

        if(n==1) {
            cout<<"Enter number to add at beginning: ";cin>>num;
            insertAtHead(head,num);
        }
        else if(n==2){
            cout<<"Enter number to add at end: ";cin>>num;
            insertAtTail(tail,num);
        }
        else if(n==3){
            cout<<"Enter the position to add num: ";cin>>pos;
            cout<<"Enter number to add at "<<pos<<": ";cin>>num;
            insertAtPosition(tail,head,pos,num);
        }
        else if(n==4){
            deleteNode(1,head,tail);
        }
        else if(n==5){
            int len=getLenth(head);
            deleteNode(len,head,tail);
        }
        else if(n==6){
            cout<<"Enter value to delete: ";cin>>num;
            deleteByValue(head,tail,num);
        }
        else if(n==7){
            cout << "Enter value to search: "; cin >> num;
            int pos = search(head, num);
            if (pos == -1) cout << "Value not found\n";
            else cout << "Value found at position: " << pos << endl;

        }
        else if(n==8){
            print(head);
        }
        else if(n==9){
            break;
        }
        else cout<<"Invalid option.";
        
    }
    return 0;
}