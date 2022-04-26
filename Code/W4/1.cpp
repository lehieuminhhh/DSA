    Node* sort(Node* head)
    {
        Node* curr = head;
        Node* a,*tmp;
        while (curr->next != NULL)
        {
            if (curr->next->getValue() < curr->getValue())
            {
                a = curr;
                curr = curr->next;
                while (a->prev != NULL && a->prev->getValue() > curr->getValue())
                {
                    a = a->prev;
                }
                tmp = curr->prev;
                if(curr->next != NULL)
                {
                    curr->next->prev = tmp;
                }
                tmp->next = curr->next;

                curr->prev = a->prev;
                curr->next = a;
                a->prev = curr;
                if (curr->prev != NULL)
                {
                    curr->prev->next = curr;
                } else
                {
                    head = curr;
                }
                curr = tmp;
            } else
            {
                curr = curr->next;
            }
        }
        return head;
    }

