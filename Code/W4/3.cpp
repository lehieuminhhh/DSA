#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node* next;
    Node* prev;
    friend class RoundLL;
};

class RoundLL
{
private:
    Node* head;
    Node* prev;

public:
    RoundLL ()
    {
        head = new Node;

        head->next = head;
        head->prev = head;
    }
    RoundLL (int val)
    {
        head = new Node;
        Node* temp;
        temp -> data = val;
        temp -> next = head;
        temp -> prev = head;
        head -> next = temp;
        head -> prev = temp;
    }

    void addFirst(int val)
    {
        Node* temp = new Node;
        temp -> next = head -> next;
        temp -> next -> prev = temp;
        temp -> prev = head;
        temp -> data = val;
        head -> next = temp;
    }
    void del(int n, int j)
    {
        Node* curr = head;
        Node* temp;
        for (int a = 0; a < n; a++)
        {
            for (int i = 0 ; i < j ; i++)
            {
                curr = curr -> next;
                if (curr == head)
                {
                    curr = curr -> next;
                }
                //cout <<curr->data<<" ";
            }
            cout <<curr->data<<" ";
            temp = curr->prev;
            curr->next ->prev = temp;
            temp->next = curr->next;

            curr = temp;
        }
    }
};


int main()
{
    RoundLL llist;
    int n ,j;
    cin>> n>>j;
    for (int i = n ; i>0 ;i--)
    {
        llist.addFirst(i);
    }
    llist.del(n,j);
    return 0;
}

