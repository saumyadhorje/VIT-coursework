#include <iostream>
using namespace std;

#define size 50

struct queue {
    int rear, front;
    int arr[size];
};

// Initialize
void init(queue &q) {
    q.front = -1;
    q.rear = -1;
}

// Check empty
bool isempty(queue &q) {
    return (q.front == -1);
}

// Check full
bool isfull(queue &q) {
    return (q.front == 0 && q.rear == size - 1) ||
           ((q.rear + 1) % size == q.front);
}

// Insert (enqueue)
void enqueue(queue &q, int val) {

    if (isfull(q)) {
        cout << "Queue is FULL\n";
        return;
    }
    

    //single element
    if (q.front == -1) {
        q.front = q.rear = 0;
    }
    else {
        q.rear = (q.rear + 1) % size;
    }

    q.arr[q.rear] = val;
    cout << val << " inserted\n";
}

// Delete (dequeue)
int dequeue(queue &q) {

    if (isempty(q)) {
        cout << "Queue is EMPTY\n";
        return -1;
    }
   
//single element
    if (q.front == 0&&q.rear==0) {
        q.front = q.rear = -1;
    }
    else {
        q.front = (q.front + 1) % size;
    }
 int val = q.arr[q.front];
    return val;
}

// Display
void display(queue &q) {

    if (isempty(q)) {
        cout << "Queue is EMPTY\n";
        return;
    }

    cout << "Circular Queue: ";

    int i = q.front;

    while (i != q.rear) {
        cout << q.arr[i] << " ";
        i = (i + 1) % size;
    }

    cout << q.arr[q.rear] << endl;
}

// MAIN
int main() {

    queue q;
    init(q);

    int choice, val;

    while (1) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> val;
            enqueue(q, val);
            break;

        case 2:
            val = dequeue(q);
            if (val != -1)
                cout << "Deleted: " << val << endl;
            break;

        case 3:
            display(q);
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
