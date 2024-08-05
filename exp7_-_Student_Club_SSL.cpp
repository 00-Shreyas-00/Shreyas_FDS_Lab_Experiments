#include <iostream>
#include <string>

using namespace std;

struct Node {
    int PRN;
    string name;
    Node* next;

    Node(int p, string n) : PRN(p), name(n), next(nullptr) {}
};

class PinnacleClub {
private:
    Node* head;
    Node* tail;

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    ~PinnacleClub() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addMember(int PRN, string name, bool isPresident = false, bool isSecretary = false) {
        Node* newNode = new Node(PRN, name);
        if (isPresident) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        } else if (isSecretary) {
            if (tail != nullptr) {
                tail->next = newNode;
                tail = newNode;
            } else {
                head = tail = newNode;
            }
        } else {
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    void deleteMember(int PRN) {
        if (head == nullptr) return;

        if (head->PRN == PRN) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->PRN != PRN) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            if (current->next == nullptr) tail = current;
            delete temp;
        }
    }

    int totalMembers() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void displayMembers() const {
        Node* current = head;
        while (current != nullptr) {
            cout << "PRN: " << current->PRN << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    void concatenate(PinnacleClub& other) {
        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        } else if (other.head != nullptr) {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = nullptr;
        other.tail = nullptr;
    }
};

int main() {
    PinnacleClub divisionA;
    PinnacleClub divisionB;

    // Adding members to Division A
    divisionA.addMember(1, "President_A", true);
    divisionA.addMember(2, "Member_A1");
    divisionA.addMember(3, "Member_A2");
    divisionA.addMember(4, "Secretary_A", false, true);

    // Adding members to Division B
    divisionB.addMember(5, "President_B", true);
    divisionB.addMember(6, "Member_B1");
    divisionB.addMember(7, "Member_B2");
    divisionB.addMember(8, "Secretary_B", false, true);

    // Display members of Division A
    cout << "Members of Division A:" << endl;
    divisionA.displayMembers();
    cout << endl;

    // Display members of Division B
    cout << "Members of Division B:" << endl;
    divisionB.displayMembers();
    cout << endl;

    // Concatenate Division B to Division A
    divisionA.concatenate(divisionB);

    // Display members of Division A after concatenation
    cout << "Members of Division A after concatenation with Division B:" << endl;
    divisionA.displayMembers();
    cout << endl;

    // Total number of members in Division A
    cout << "Total number of members in Division A: " << divisionA.totalMembers() << endl;

    return 0;
}
