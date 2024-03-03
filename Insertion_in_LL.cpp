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
    if(arr.size()==0){
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

void print(Node* &head){
    Node* temp=head;
     while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
     }
}

Node* InsertAtHead(Node* head, int element){
    Node* temp=new Node(element,head);
    return temp;
}

Node* InsertAtTail(Node* head, int element){
    if(head==nullptr){
        return new Node(element);
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* newNode=new Node(element);
    temp->next=newNode;
    return  head;
}

Node* InsertAtK(Node* head, int element, int k){  // We can insert elements from position "1" to "N+1" (where: 'N' is size of linked list)
      if(head==nullptr){
         if(k==1){
            return new Node(element,head);
         }else{
            return nullptr;
         }
      }
      if(k==1){  // insertion at head when one or more than one elements in Linked List are present
         Node* newNode=new Node(element,head);
         head=newNode;
         return head;  // It even works if we directly return "newNode"
      }
      Node* temp=head;
      int count=0;
      while(temp!=nullptr){
        count++;
        if(k-1==count){
            Node* newNode=new Node(element);
            newNode->next=temp->next;
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
      }
      return head;
}

Node* InsertBeforeValue(Node* head, int element, int val){  // We can insert elements from position "1" to "N+1" (where: 'N' is size of linked list)
      if(head==nullptr)
      return nullptr;
      if(head->data==val)
      return new Node(element,head);
      Node* temp=head;
      while(temp!=nullptr){
        if(temp->next->data==val){
            Node* newNode=new Node(element,temp->next);
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
      }
      return head;
}

int main(){
    vector<int>arr={200,4,1,123,78,10};
    Node* head=convertArr2LL(arr);
    head=InsertBeforeValue(head,2300,10);
    print(head);
    return 0;
}
