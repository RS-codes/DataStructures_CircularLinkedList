/* 1.9.5 Checking Linked List is a Circular Linked List */

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

/*utility function*/
Node* newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

bool isCircular(Node* head){
    if(head==NULL) return true;

    Node* node=head->next;
    while(node!=NULL && node!= head)
        node=node->next;
        return (node==head);
}


/*driver code to test the implementation*/
int main()
{
    Node* head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);

    isCircular(head)? cout<<"yes\n": cout<<"no\n";

    /*making ll circular*/
   head->next->next->next->next=head;
    isCircular(head)? cout<<"yes\n": cout<<"no\n";
    return 0;
}





--variation
/*ftn to check circular
bool IsCircular(Node* head)
{
      bool circleFound = false;
      bool tailFound = false;

      if (head && head->next)
     {
          Node* slower = head;
          Node* faster = head;

          do 
          {
               slower = slower->next;
               faster =  faster->next->next;
               tailFound = ! (faster && faster->next);
               if ( ! tailFound )
               {
                   circleFound = (slower == faster || slower == faster->next);                                         
               }
          }
          while ( ! tailFound && ! circleFound)
     }

     return ( circleFound );
}

*/

/*
Case 2 of the above algorithm/code can be optimized. 
To implement the suggested change we need to modify the case 2 to following.

// Case 2 of the above algo
else if (current->data >= new_node->data)
{
  // swap the data part of head node and new node
  // assuming that we have a function swap(int *, int *)
  swap(&(current->data), &(new_node->data)); 
 
  new_node->next = (*head_ref)->next;
  (*head_ref)->next = new_node;
}*/

