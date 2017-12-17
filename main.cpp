#include <iostream>
#include <stdlib.h>
using namespace std;

template <class A>
struct Node
{
    A value;
    int x;
    Node *Next, *Prev;
};


template <class A>
class List {

public:
    Node <A> *Head;
    Node <A> *Tail;
public:
    List(): Head(NULL), Tail(NULL){};
    ~List();

    void Add(A value);
    void AddTail (A value);
    void Show();
    void ShowTail();
    void Ins(A value, int x);
};


template <class A>
List<A>::~List<A> ()
{
    Node <A> *temp;
    while (Head)
    {
        Tail=Head -> Next;
        delete Head;
        Head=Tail;
    }
}

template <class A>
void List<A> :: Add(A value) {
    Node <A> *temp=new Node <A>;
    temp -> Prev=NULL;
    temp -> value=value;

    if (Head!=NULL) {
        Node <A>  *pwn = Head;
        while (pwn != NULL){
            (pwn -> x)+=1;
            pwn = pwn->Next;
        }
        temp -> x = ((Head->x)-1);
        temp -> Next = Head;
        temp -> Prev= temp;
        Head = temp;
    }
    else {
        temp -> x = 1;
        temp -> Next=NULL;
        Head=Tail=temp;
    }
}

template <class A>
void List<A> :: AddTail(A value) {
    Node <A> *temp=new Node <A>;
    temp -> Next=NULL;
    temp -> value=value;

    if (Head!=NULL) {
        temp -> x = ((Head->x)+1);
        Tail -> Prev = Head;
        Tail -> Next= temp;
        Tail = temp;
    }
    else {
        temp -> x = 1;
        temp -> Prev=NULL;
        Head=Tail=temp;
    }
}


template <class A>
void List <A>:: Ins (A value, int x) {
    if (x==1) {
        Add(value);
    } else if (x== ((Tail-> x)+1)) {
        AddTail(value);
    } else if (x> ((Tail-> x)+1)) {
        cout << "don't do this" << x << endl;
    } else {
        Node <A> *pwn = Head;
        while ((pwn->x)!=x){
            pwn = pwn-> Next;
        }
        Node <T> *pwnprev= pwn -> Prev;
        Node <T> *temp = new Node <T>;
        temp -> value = value;
        temp -> x=x;

        pwnprev->Next=temp;
        temp -> Prev = pwnprev;
        temp -> Next = pwn;
        pwn -> Prev = temp;
        while (pwn != NULL) {
            (pwn -> x) +=1;
            pwn = pwn -> Next;

        }
    }}
template <class A>
void List <A>::Show() {

    Node <A> *temp = Head;
    while (temp != NULL) {
        cout << temp->x << " " << temp->value << ";";
        temp = temp->Next;
    }
    cout << "\n";
}

template <class A>
void List <A>::ShowTail() {

    Node <A> *temp = Tail;
    while (temp != NULL) {
        cout << temp->x << " " << temp->value << ";";
        temp = temp->Prev;
    }
    cout << "\n";
}
int main() {

    List<int> list;


    list.AddTail(100);
    list.AddTail(200);
    list.AddTail(0);
    list.AddTail(1888);



    list.Add(1);
    list.Add(2);
    list.Add(6);
    list.Add(4338);

    list.Ins(454,1);
    list.Ins(4114,7);


    list.AddTail (423);

    list.Show();
    cout << endl;
    list.ShowTail();
    return 0;
}