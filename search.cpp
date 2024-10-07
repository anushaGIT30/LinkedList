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

int lengthOFlinkedlist(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        // cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    return count;
}
int searchAnElement(Node *head, int val)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertArray2Linkedlist(v);
    int length = lengthOFlinkedlist(head);

    cout << searchAnElement(head, 77);
    return 0;
}
