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
int LengthOfLL(Node* &head){
    int count=0;
    Node* temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}

int main(){
    vector<int>arr={200,4,1,123,78,10};
    Node* head=convertArr2LL(arr);

    //traversing a Linked List
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Length of LL is:"<<LengthOfLL(head)<<endl;
}




// Time Complexity=> O(n)  "for converting an Array to Linked List"