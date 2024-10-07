#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node *nextNode)
    {
        data = data1;
        next = nextNode;
    }
};

Node *convertArray2Linkedlist(vector<int> &v)
{
    if (v.empty())
        return nullptr; // Handle empty vector

    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *insertingAnElementInHead(Node *head, int ele)
{
    return new Node(ele, head);
}

Node *insertAtTail(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val); // Create a new node if the list is empty
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next; // Traverse to the end of the list
    }
    temp->next = new Node(val); // Create and attach the new node at the end
    return head;                // Return the head of the list
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertArray2Linkedlist(v);
    // head = insertingAnElementInHead(head, 9);
    head = insertAtTail(head, 96);
    printLinkedList(head);
    return 0;
}
