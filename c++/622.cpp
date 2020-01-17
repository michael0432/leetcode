#include <stdlib.h>
#include <iostream>
using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */

    int* array;
    int head;
    int tail;
    int size;

    MyCircularQueue(int k) {
        array = new int[k+1];
        head = 0;
        tail = 0;
        size = k+1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        else{
            tail = (tail + 1) % size;
            array[tail] = value;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else{
            head = (head + 1) % size;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return array[head+1];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return array[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(head == tail){
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((tail+1) % size == head){
            return true;
        }
        
        return false;
    }
};

int main(){
    MyCircularQueue* obj = new MyCircularQueue(3);
    cout << obj->enQueue(1) << endl;
    cout << obj->enQueue(2) << endl;
    cout << obj->enQueue(3) << endl;
    cout << obj->enQueue(4) << endl;
}