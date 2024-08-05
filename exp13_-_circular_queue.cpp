#include <iostream>
#include <string>

using namespace std;

class CircularQueue {
private:
    string* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        queue = new string[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() const {
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void addOrder(const string& order) {
        if (isFull()) {
            cout << "Queue is full. Cannot accept more orders." << endl;
        } else {
            rear = (rear + 1) % capacity;
            queue[rear] = order;
            size++;
            cout << "Order added: " << order << endl;
        }
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to serve." << endl;
        } else {
            cout << "Order served: " << queue[front] << endl;
            front = (front + 1) % capacity;
            size--;
        }
    }

    void displayOrders() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Current orders in the queue: ";
            int i = front;
            for (int count = 0; count < size; count++) {
                cout << queue[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the maximum number of orders the pizza parlor can handle: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    int choice;
    string order;

    do {
        cout << "\nPizza Parlor Menu\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter order description: ";
                getline(cin, order);
                cq.addOrder(order);
                break;
            case 2:
                cq.serveOrder();
                break;
            case 3:
                cq.displayOrders();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
