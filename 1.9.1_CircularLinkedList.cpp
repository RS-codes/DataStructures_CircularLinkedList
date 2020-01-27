/* 1.9.1 Circular Linked List */

#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* Insert(int x,Node *head){
	Node* temp=new Node;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		temp->next=head;
	}else{
		Node* temp1=head;
		do{
			temp1=temp1->next;
		}while(temp1->next!=head);
		temp->next=head;
		temp1->next=temp;
	}
	return head;
}

void Print(Node* head){
	if(head!=NULL){
		Node* temp=head;
		do{		
			cout<<temp->data<<" ";
			temp=temp->next;
		}while(temp!=head);
	}cout<<endl;
}

void Check(Node* head){
	if(head!=NULL){
		Node* temp=head;
		do{
			temp=temp->next;
		}while(temp!=head);
		if(temp==head) cout<<"Circular..\n";
		else cout<<"Linear..\n";
	}	
}

int main(){
	Node* head=NULL; //empty
	int n,x;
	cout<<"Enter Size: ";
	cin>>n;
	cout<<"enter elements:\n";
	for(int i=0;i<n;i++){
		cin>>x;
		head=Insert(x,head);
	}
	Print(head);
	Check(head);
	return 0;
}

