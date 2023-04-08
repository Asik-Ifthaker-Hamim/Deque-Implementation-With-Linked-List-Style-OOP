#include<bits/stdc++.h>
using namespace std;

template<typename t>
class Deque
{
    struct Node
    {
        t val;
        Node *link;
    };
    Node *head, *tail;
    int sz;
public:
    Deque()
    {
        sz = 0;
        head = tail = NULL;
    }
    void Push_Back(t data)
    {
        Node *a = new Node();
        a -> val = data;
        a -> link = 0;
        if(head == NULL)
        {
            head = tail = a;
        }
        else
        {
            tail -> link = a;
            tail = a;
        }
        sz++;
    }
    void Push_Front(t data)
    {
        Node *a = new Node();
        a -> val = data;
        if(head == NULL)
        {
            a->link=NULL;
            head = tail = a;
        }
        else
        {
            Node *temp=head;
            head=a;
            a->link=temp;
        }
        sz++;
    }
    void Pop_Front()
    {
        if(tail == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        if(head == tail)
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head -> link;
            delete temp;
        }
        sz--;
    }
    void Pop_Back()
    {
        if(tail == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        if(head == tail)
        {
            delete tail;
            head = tail =  NULL;
        }
        else
        {
            Node *x=head;
            for(int i=1; i<sz-1; i++)
            {
                x=x->link;
            }
            Node *temp=new Node();
            temp=tail;
            //cout<<temp->val<<endl;
            delete temp;
            tail=x;
            tail->link=NULL;
        }
        sz--;
    }
    int Size()
    {
        return sz;
    }
    t Front()
    {
        return head -> val;
    }
    t Back()
    {
        return tail->val;
    }

};


int main()
{
    Deque<string>q;
    q.Push_Back("Asik");
    q.Push_Back("Ifthaker");
    q.Push_Back("Hamim");
    q.Push_Front("3AM");

    cout << q.Front() << endl;
    q.Pop_Front();
    q.Pop_Back();
    cout << q.Back() << endl;
    cout << q.Size() << endl;
    q.Push_Back("Done");
    cout << q.Back() << endl;
    cout << q.Size() << endl;
    cout << q.Front() << endl;


    return 0;
}


