#include <iostream>
#include <stdexcept>

using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() const {
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void addFront(int element) {
        if (isFull()) {
            throw overflow_error("Deque is full");
        }
        if (front == -1) { // Deque is empty
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = element;
        size++;
    }

    void addRear(int element) {
        if (isFull()) {
            throw overflow_error("Deque is full");
        }
        if (rear == -1) { // Deque is empty
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            throw underflow_error("Deque is empty");
        }
        if (front == rear) { // Only one element
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        size--;
    }

    void deleteRear() {
        if (isEmpty()) {
            throw underflow_error("Deque is empty");
        }
        if (front == rear) { // Only one element
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        size--;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;

    Deque deque(capacity);

    int choice, element;

    do {
        cout << "\nDeque Menu\n";
        cout << "1. Add element at front\n";
        cout << "2. Add element at rear\n";
        cout << "3. Delete element from front\n";
        cout << "4. Delete element from rear\n";
        cout << "5. Display elements\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to add at front: ";
                cin >> element;
                try {
                    deque.addFront(element);
                } catch (const overflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                cout << "Enter element to add at rear: ";
                cin >> element;
                try {
                    deque.addRear(element);
                } catch (const overflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try {
                    deque.deleteFront();
                } catch (const underflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                try {
                    deque.deleteRear();
                } catch (const underflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
