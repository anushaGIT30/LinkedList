#include <bits/stdc++.h>
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
void printingTheLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *removeHead(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}
Node *removeKthElementposition(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *removeGivenElement(Node *head, int ele)
{
    if (head == nullptr)
    {
        return head;
    }
    if (head->data == ele)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {

        if (temp->data == ele)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> v = {4, 5, 88, 22, 44, 55, 66, 77, 88};
    Node *head = convertArray2Linkedlist(v);
    // cout << head->data;
    // head = removeKthElementposition(head, 1);
    head = removeGivenElement(head, 22);
    printingTheLL(head);
}