#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node* next;
    friend class SingleLL;
};

class SingleLL
{
private:
    Node* head;
    Node* tail;

public:
    SingleLL ()
    {
        head = new Node;
        tail = new Node;
        head->next = tail;
    }
    SingleLL (int val)
    {
        head = new Node;
        tail = new Node;
        Node* temp;
        temp -> data = val;
        temp -> next = tail;
        head -> next = temp;
    }

    Node* element(int pos)
    {
        Node* curr = head;
        for (int i = 1; i < pos ; i++)
        {
            curr = curr -> next;
        }
        return curr;
    }
    void addFirst(int val)
    {
        Node* temp = new Node;
        temp -> next = head -> next;
        temp -> data = val;
        head -> next = temp;
    }
    void addLast(int val)
    {
        Node* temp = new Node;
        temp->next = tail;
        temp->data = val;
        for (Node* curr = head; 1 ; curr = curr->next)
        {
            if (curr->next == tail)
            {
                curr->next = temp;
                break;
            }
        }
    }
    void add(int val, int pos)
    {
        Node* temp = new Node;
        Node* curr = head;
        temp -> data = val;
        for (int i = 1 ; i < pos ; i++)
        {
            curr = curr -> next;
        }
        temp -> next = curr -> next;
        curr -> next = temp;
    }
    void del(int pos)
    {
        Node* curr = head;
        for (int i = 1 ; i < pos ; i++)
        {
            curr = curr -> next;
        }
        curr -> next = curr->next->next;
    }
    void print()
    {
        if (head->next == tail)
        {
            return;
        }
        for (Node* curr = head->next; curr != tail ; curr = curr->next)
        {
            cout << curr->data <<" ";
        }
    }
};


int main()
{
    SingleLL llist;
    llist.addLast (4);
    llist.addLast (5);
    llist.addLast (6);
    llist.addLast (7);
    llist.addLast (8);
    llist.addLast (9);
    llist.print();
    return 0;
}
