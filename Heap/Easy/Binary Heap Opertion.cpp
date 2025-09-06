Extract Min () - In this method, from the Min heap we have to remove root node and then return .
To perform this activity first copy the root element is some variable, then copy the last element from the heat at root
Now decrease the size then apply the Minheapify method to re-arrange the tree.

the logic of Minheapify method - it will compare the  node with it's left and right children and swaps till gets their correct position.


 int extractMin()
    {
        // Your code here.
        if(heap_size <=0) return -1;
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        if(heap_size > 0) MinHeapify(0);
        return root;
        
    }
        
InsertKey() method -:

in this method we have to add a new node in the existing heap.

to do this first increse the size and call decreseKey method

the task of decreasekey method is - it will add the node at the end of the tree then re-arrange the tree after comparision with parent

void insertKey(int k) 
    {
        // Your code here.
        if(heap_size == capacity){
            return;
        }
        heap_size++;
        decreaseKey(heap_size-1, k);
    }
deleteKey() method :-

we want to delete ith node 
to do this first will replace this node value with Integer Min value
then will decrease key method to get this node at root.

then will call the extract min method to remove root node.


 void deleteKey(int i) 
    {
        // Your code here.
        if(i>= heap_size) return;
        decreaseKey(i,Integer.MIN_VALUE);
        extractMin();
        
    }
        void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}