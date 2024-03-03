#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
    Node(int data, Node* &next){
        this->data=data;
        this->next=next;
    }
};

Node* convertArr2LL(vector<int>& arr){
    if(arr.size()==0){      // It checks whether array is empty or not
        return nullptr;
    }
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}


Node* deleteHead(Node* head){
    if(head==nullptr)
    return head;

    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* &head){
    if(head==nullptr || head->next==nullptr)  //If LL is empty or has one node, in both the cases we return "nullptr"
    return nullptr;

    Node* temp=head;
    Node* previous=nullptr;
    while(temp->next!=nullptr){
          previous=temp;
          temp=temp->next;
    }
    delete temp;
    previous->next=nullptr;

    return head; 
}

Node* deleteK(Node* &head,int k){
    if(head==nullptr){  // No element in the Linked List
        return head;
    }
  if(k==1){   // We are trying to remove the head of the Linked List
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  int count=0;
  Node* temp=head;  // points towards current node
  Node* previous=nullptr;  // points to a node previous to which "temp" is pointing
  while(temp!=nullptr){
    count++;
    if(count==k){
        previous->next=temp->next;
        free(temp);
        break;
    }
    previous=temp;
    temp=temp->next;
  }
  return head;
}

Node* deleteVal(Node* head,int val){
    if(head==nullptr){
        return nullptr;
    }
    Node* temp=head;
    Node* previous=nullptr;
    while(temp!=nullptr){
    if(head->data==val){
        head=head->next;
        free(temp);
        return head;
    }else{
        if(temp->data==val){
          previous->next=temp->next;
          free(temp);
          return head;
        }
    }
    previous=temp;
    temp=temp->next;
    }
    return head;
}

void print(Node* &head){
    Node* temp=head;
     while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
     }
}


int main(){
    vector<int>arr={200,4,1,123,78,10};
    Node* head=convertArr2LL(arr);
    Node* temp=deleteVal(head,200);
    print(temp);

}
