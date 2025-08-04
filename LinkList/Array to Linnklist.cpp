class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//Main code ye hai
class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
              Node*temp=new Node();
        Node*head=temp;
        for(int i=0;i<arr.size();i++)
        {
        temp->data=arr[i];
         if(i<arr.size()-1)// ye isliye likh kyuki extra link ban jata last mai 
         {
             temp->next=new Node();// temp next  ko link karne keliye node to baneynge
             temp=temp->next;// temp ko shift bhi karna hai
         }
        }
        return head;
        
    }
};