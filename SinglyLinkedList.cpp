#include<iostream>
using namespace std;

//Singly Linked list
class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
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

void insertAtHead(Node* &head,int d){
    //new node create
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    //new node create
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    //insert at start
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //creating a node for d
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
    //insert at last
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }
}

void deleteNode(int position,Node* &head){
    //deleting first or start node
    if(position==1){
        Node* temp=head;
        head=head->next;
        //memory free start node
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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}


void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){
    //create a new node
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    //Singly linked list
    Node* head=node1;
    Node* tail=node1;
    print(head);

    insertAtHead(head,12);
    print(head);
    insertAtHead(head,15);
    print(head);

    insertAtTail(tail,5);
    print(head);

    insertAtPosition(tail,head,2,18);
    print(head);
    insertAtPosition(tail,head,1,1);
    print(head);
    insertAtPosition(tail,head,7,19);
    print(head);

    deleteNode(1,head);
    print(head);
    deleteNode(6,head);
    print(head);
    deleteNode(3,head);
    print(head);


}