#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct Node {
    string name;
    Node* next;

    Node(string n) : name(n), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addStudent(const string& name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }

    unordered_set<string> toSet() const {
        unordered_set<string> resultSet;
        Node* current = head;
        while (current != nullptr) {
            resultSet.insert(current->name);
            current = current->next;
        }
        return resultSet;
    }

    Node* getHead() const {
        return head;
    }
};

void displaySet(const unordered_set<string>& set) {
    for (const auto& name : set) {
        cout << name << " ";
    }
    cout << endl;
}

unordered_set<string> computeUnion(const unordered_set<string>& setA, const unordered_set<string>& setB) {
    unordered_set<string> resultSet = setA;
    resultSet.insert(setB.begin(), setB.end());
    return resultSet;
}

unordered_set<string> computeIntersection(const unordered_set<string>& setA, const unordered_set<string>& setB) {
    unordered_set<string> resultSet;
    for (const auto& name : setA) {
        if (setB.find(name) != setB.end()) {
            resultSet.insert(name);
        }
    }
    return resultSet;
}

int main() {
    LinkedList vanillaLovers;
    LinkedList butterscotchLovers;

    // Adding students who like vanilla ice-cream
    vanillaLovers.addStudent("Alice");
    vanillaLovers.addStudent("Bob");
    vanillaLovers.addStudent("Charlie");

    // Adding students who like butterscotch ice-cream
    butterscotchLovers.addStudent("Dave");
    butterscotchLovers.addStudent("Eve");
    butterscotchLovers.addStudent("Charlie");

    // Converting linked lists to sets
    unordered_set<string> vanillaSet = vanillaLovers.toSet();
    unordered_set<string> butterscotchSet = butterscotchLovers.toSet();

    // a. Set of students who like either vanilla or butterscotch or both
    unordered_set<string> eitherOrBoth = computeUnion(vanillaSet, butterscotchSet);
    cout << "Students who like either vanilla or butterscotch or both:" << endl;
    displaySet(eitherOrBoth);

    // b. Set of students who like both vanilla and butterscotch
    unordered_set<string> both = computeIntersection(vanillaSet, butterscotchSet);
    cout << "Students who like both vanilla and butterscotch:" << endl;
    displaySet(both);

    // c. Number of students who like neither vanilla nor butterscotch
    int totalStudents = 5; // Assuming a total of 5 students for simplicity
    int neitherCount = totalStudents - eitherOrBoth.size();
    cout << "Number of students who like neither vanilla nor butterscotch: " << neitherCount << endl;

    return 0;
}
