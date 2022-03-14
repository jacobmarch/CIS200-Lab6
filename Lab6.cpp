#include <iostream>
#include <cstdlib>

using namespace::std;

#define SIZE 1000

int movePos;

class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = SIZE);
    ~Queue();
    
    void enqueue(int item);
    void moveNthFront(int pos);
    void print();

};

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue(){
    delete[] arr;
}

void Queue::moveNthFront(int pos){
    int temp = arr[pos];
    for (int i = pos - 1; i > -1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
}

void Queue::enqueue(int item)
{
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

void Queue::print(){
    for (int i = 0; i < capacity; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    cout << "Current Queue: ";
    q.print();

    cout << "Enter Position to move to front of queue: ";
    cin >> movePos;

    if (movePos > 4){
        cout << "Queue does not contain that position" << endl;
    }
    else {
        q.moveNthFront(movePos);
        cout << "Updated Queue: ";
        q.print();
    }
    
    return 0;

    




    

}

