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
};



int main() {
	int n;
	cin >> n;

	DLinkedList llist;

	for(int i = 0; i < n; i++) {
	    int num;
	    cin >> num;
	    llist.addFront(num);
	}
	llist.findMax();
	llist.sum();

	return 0;
}
