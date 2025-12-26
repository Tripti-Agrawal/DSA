#include<iostream>
using namespace std;
//Doubly linked list
class Node{
    public:
    int data;
    Node* next;
    Node*prev;

    //Constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

    //Destructor
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data:"<<value<<endl;
    }
};

//Length of linked list
int getLength(Node*head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(Node* &tail,Node* &head,int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertAtTail(Node* &tail,Node* &head,int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
    }else{
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    //insert at start
    if(position==1){
        insertAtHead(tail,head,d);
        return;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    //insert at last
    if(temp->next==NULL){
        insertAtTail(tail,head,d);
        return;
    }

    //creating a node for d
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}

void deleteNode(int position,Node* &head){
    //deleting first or start node
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

//Traversal of linked list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){
    
    //Doubly linked list
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);

    // cout<<getLength(head)<<endl;

    insertAtHead(tail,head,15);
    print(head);
    insertAtHead(tail,head,20);
    print(head);

    insertAtTail(tail,head,2);
    print(head);

    insertAtPosition(tail,head,3,12);
    print(head);
    insertAtPosition(tail,head,1,25);
    print(head);
    insertAtPosition(tail,head,7,1);
    print(head);

    deleteNode(1,head);
    print(head);
    deleteNode(4,head);
    print(head);
    deleteNode(5,head);
    print(head);

}