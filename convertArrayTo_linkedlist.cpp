#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* convertArray_to_Linkedlist(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main() {
    vector<int> arr = {99, 6, 8, 9};
    Node* head = convertArray_to_Linkedlist(arr);
    cout << head->data;
    return 0;
}


