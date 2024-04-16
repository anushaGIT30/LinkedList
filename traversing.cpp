#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    // Constructor
    Node(int val){
        data=val;
        next=nullptr;
    }
};

int main() {
    vector<int> arr = {2, 5, 6, 9};

    Node* head = new Node(arr[0]); // Creating the head node
    Node* temp = head; // temp is set to the head node

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]); // Creating new nodes and linking them
        temp = temp->next; // Moving temp to the next node
    }

    temp = head; // Resetting temp to the head node for traversal
    while (temp) {
        cout << temp->data << " "; // Printing the data of each node
        temp = temp->next; // Moving to the next node
    }

    
    temp = head;
    while (temp) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
