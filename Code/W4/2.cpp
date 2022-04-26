#include <iostream>

using namespace std;


class DNode {
private:
	int data;
	DNode* prev;
	DNode* next;

	friend class DLinkedList;
};

class DLinkedList {
private:
	DNode* header;
	DNode* trailer;
public:

	DLinkedList() {
		header = new DNode;
		trailer = new DNode;
		header->next = trailer;
		trailer->prev = header;
	}

	void addFront(const int e)
	{
		DNode *temp = new DNode;
		temp->data = e;
		temp->next = header->next;
		header->next->prev = temp;
		temp->prev = header;
		header->next = temp;
	}
    void sum ()
    {
        int s = 0;
        for (DNode *temp = header-> next; temp != trailer ; temp = temp->next)
        {
            s+= temp->data;
        }
        cout << s << endl;
    }
    void findMax()
    {
        int max = header->next->data;
        DNode *temp = new DNode;
        temp = header->next;
        while ( temp->next != trailer)
        {
            temp = temp-> next;
            if (temp->data > max)
            {
                max = temp->data;
            }
        }
        cout << max << endl;
    }
	void reverseDisplay()
	{
    	DNode *trace = trailer;
    	do
    	{
    	    trace = trace->prev;
    	    cout << trace->data << " ";
    	} while (trace->prev != header);
	}
	void deleteDup()
	{

	    DNode* curr = header->next;
        DNode* temp, *temp2 ;
        while ( curr -> next != trailer)
        {
            temp = curr;

            while (temp->next != trailer)
            {
                temp2 = temp;
                temp = temp->next;
                if (temp->data == curr->data)
                {
                    temp2->next = temp->next;
                    temp->next->prev = temp2;
                    temp =temp2;
                }
            }
            curr = curr->next;
        }
	}
};





/*Node* deleteDuplicates(Node* head)
{
    Node* curr = head;
    Node* temp, *temp2 ;
    while ( curr -> next != NULL)
    {
        temp = curr;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
            if (temp->value == curr->value)
            {
                temp2->next = temp->next;
                temp = temp2;
            }
        }
    }
    return head;
}
*/
int main()
{
	int n;
	cin >> n;

	DLinkedList llist;

	for(int i = 0; i < n; i++) {
	    int num;
	    cin >> num;
	    llist.addFront(num);
	}
	llist.deleteDup();
	llist.reverseDisplay();
	//llist.findMax();
	//llist.sum();

	return 0;
}



/* bai nop

Node* deleteDuplicates(Node* head)
	{
	    Node* curr = head;
        Node* temp, *temp2 ;
        while ( curr -> next != NULL)
        {
            temp = curr;

            while (temp->next != NULL)
            {
                temp2 = temp;
                temp = temp->next;
                if (temp->value == curr->value)
                {
                    temp2->next = temp->next;
                    temp =temp2;
                }
            }
            curr = curr->next;
        }
        return head;
	}
	*/
