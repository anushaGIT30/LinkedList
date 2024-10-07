#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertArray2Linkedlist(vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
        // mover=mover.next;
    }
    return head;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertArray2Linkedlist(v);
    cout << head->data;
}