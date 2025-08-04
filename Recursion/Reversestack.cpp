// Method-1
 void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        
        int top = St.top();
        St.pop();
        Reverse(St); //I am hoping my Reverse function will reverse the remaining stack

        //Now I need to push top at the bottom of the stack
        stack<int> temp;
        while(!St.empty()) {
            temp.push(St.top());
            St.pop();
        }
      
        St.push(top); //push at bottom
        //Now push remaining elements
        while(!temp.empty()) {
            St.push(temp.top());
            temp.pop();
        }
    }
    // Time Complexity: O(N^2) and Space Complexity: O(N)
    // Method-2
    void insertAtBottom(stack<int>& St, int element) {
        if(St.empty()) {
            St.push(element);
            return;
        }
        
        int cur_top_el = St.top();
        St.pop();
        insertAtBottom(St, element);
        St.push(cur_top_el);
    }

    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        int top = St.top();
        St.pop();
        
        Reverse(St);
        insertAtBottom(St, top);
    }
    // Time Complexity: O(N2) and Space Complexity: O(1)
// Method-3
 public static void insertAtBottom(Stack<Integer> St, int element) {
        if (St.isEmpty()) {
            St.push(element);
            return;
        }

        int curTopElement = St.pop();
        insertAtBottom(St, element);
        St.push(curTopElement);
    }
    
    static void reverse(Stack<Integer> St) {
        if (St.isEmpty()) {
            return;
        }
        
        int top = St.pop();
        reverse(St);
        insertAtBottom(St, top);
    }
// Time Complexity: O(N^2) and Space Complexity: O(1)