#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename LT>
class List
{
private:
    template<typename NT>
    class Node
    {
    public:
        NT Data;
        Node* next;
        Node(NT _Data=NT(), Node* _next=NULL) : Data(_Data), next(_next) {}        
        ~Node(){}
    };
    Node<LT>* head;
    Node<LT>* end;
    int SIZE;

public:
    List() : head(NULL), end(NULL), SIZE(0) {}
    ~List();

    LT& operator[](const int index);

    int size() { return SIZE; }
    void push_back(const LT& data);
    void pop_back();
    void push_front(const LT& data);
    void pop_front();
    bool empty() { return (SIZE == 0)? true : false; }
    void clear();
};

template<typename LT>
List<LT>::~List()
{
    Node<LT>* tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<typename LT>
LT& List<LT>::operator[] (const int index)
{
    if (index < 0 && index >= SIZE) throw 1;
    Node<LT>* tmp = head;

    for (int i = 0; i < index; i++)
        tmp = tmp->next;

    return tmp->Data;
}

template<typename LT>
void List<LT>::push_back(const LT& data)
{
    if (SIZE == 0)
    {
        head = new Node<LT>();
        head->Data = data;
        end = head;
    }
    else
    {
        Node<LT>* tmp = new Node<LT>();
        tmp->Data = data;
        end->next = tmp;
        end = tmp;
    }
    
    SIZE++;
}

template<typename LT>
void List<LT>::pop_back()
{
    Node<LT>* tmp = head;
    for (int i = 0; i < SIZE-1; i++)
        tmp = tmp->next;
    delete end;
    end = tmp;
    SIZE--;
}

template<typename LT>
void List<LT>::push_front(const LT& data)
{
    Node<LT>* tmp = new Node<LT>();
    tmp->Data = data;
    tmp->next = head;
    head = tmp;
    
    SIZE++;
}

template<typename LT>
void List<LT>::pop_front()
{
    Node<LT>* tmp = head;
    head = head->next;
    delete tmp;

    SIZE--;
}

template<typename LT>
void List<LT>::clear()
{
    Node<LT>* tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{

    List<int> lst;
    
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);

    cout << "size:" << lst.size() << endl;
    

    return 0;
}