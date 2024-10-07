#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
Node *convertArraytoDDL(vector<int> &arr)
{
    // creating a head
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        // creating a temp
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node *DeleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete (prev);
    return head;
}
Node *DeleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *newTail = tail->prev;
    newTail->next = nullptr;
    newTail->prev = nullptr;
    delete (tail);
    return head;
}
Node *DeleteKthElement(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    int count = 0;
    Node *kthnode = head;
    while (kthnode != nullptr)
    {
        count++;
        if (count == k)
        {
            break;
        }
        kthnode = kthnode->next;
    }
    Node *prev = kthnode->prev;
    Node *front = kthnode->next;
    if (prev == nullptr && front == nullptr)
    {
        return nullptr;
    }
    else if (prev == nullptr)
    {
        return DeleteHead(head);
    }
    else if (front == nullptr)
    {
        return DeleteTail(head);
    }
    prev->next = front;
    front->prev = prev;
    kthnode->next = nullptr;
    kthnode->prev = nullptr;
    delete kthnode;
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    vector<int> arr = {99, 6, 8, 9};
    Node *head = convertArraytoDDL(arr);
    head = DeleteKthElement(head, 1);
    print(head);
    return 0;
}