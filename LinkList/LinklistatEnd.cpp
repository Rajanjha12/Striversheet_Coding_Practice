/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node *temp=head;
        Node *prev= new Node(x);
        if(head==NULL)
        return prev;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=prev;
        return head;
    }
};
//