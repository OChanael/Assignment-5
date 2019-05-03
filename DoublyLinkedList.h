#include <iostream>

using namespace std;

template <class T> //ListNode Class
class ListNode
{
private:

public:
  T data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode(); //constructor
  ListNode(T d);
  ~ListNode(); //destructor
};

template <class T>
ListNode<T>::ListNode()
{
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}



template <class T> //DoublyLinkedList Class
class DoublyLinkedList
{
private:

public:
  unsigned int size;
  ListNode<T> *front;
  ListNode<T> *back;

  DoublyLinkedList(); //constructor
  ~DoublyLinkedList(); //destructor

  void insertBack(T d);

  T removeFront();
  T peekFront();
  T peekBack();

  void printList();
  void deletePos(int pos);
  bool isEmpty();
  unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  delete front;
  delete back;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);

  if(size == 0) //empty list
  {
    front = node;
  }
  else //not empty
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront()
{
  if(!isEmpty())
  {
    ListNode<T> *node = front;
    if(front->next == NULL) //only node in list
    {
      front = NULL;
      back = NULL;
    }
    else //more than one node
    {
      front->next->prev = NULL;
      front = front->next;
    }
    T temp = node->data;

    delete node;
    --size;
    return temp;
  }
  else
  {
    return T();
  }
}

template <class T>
void DoublyLinkedList<T>::deletePos(int pos)
{
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(idx != pos)
  {
    prev = curr;
    curr = curr->next;
    ++idx;
  }
  prev->next = curr->next; //stuff to be deleted
  curr->next->prev = prev;
  curr->next = NULL;
  curr->prev = NULL;
  curr->data = NULL;

  --size;
  delete curr;
}

template<class T>
T DoublyLinkedList<T>::peekFront()
{
  return front->data;
}

template <class T>
T DoublyLinkedList<T>::peekBack()
{
  return back->data;
}

template <class T>
void DoublyLinkedList<T>::printList()
{
  if(front == NULL)
  {
    cout << "No Data To Print" << endl;
  }
  ListNode<T> *curr = front;

  while(true)
  {
    if(curr == NULL)
    {
      break;
    }
    cout << curr->data << ", ";
    curr = curr->next;
  }
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return(size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}
