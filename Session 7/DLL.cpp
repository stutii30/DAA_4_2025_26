#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *prev;
    Node *next;
    Node(int d)
    {
        val = d;
        next = NULL;
    }
};
Node *head = NULL;
void insertion(int d)
{

    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    temp->next->prev = temp;
}
void deletion(int d)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    if (head->val == d)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        return;
    }
    while (temp->next != NULL && temp->next->val != d)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return;
    }
    temp->next = temp->next->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp;
        return;
    }
}
void traverse()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main()
{
    insertion(10);
    insertion(20);
    insertion(30);
    insertion(40);
    insertion(50);
    traverse();
    deletion(40);
    cout << endl;
    traverse();
    return 0;
}