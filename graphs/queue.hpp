#ifndef QUEUE
#define QUEUE 1
template <class Item>
class QNode
{
  public:
    Item val;
    QNode<Item> *next;

    QNode(Item x)
    {
      val=x;
      next=NULL;
    }
};
template <class Item>
class Queue
{ 
  public:
    QNode<Item> *head,*tail;
    int length;

    Queue()
    {
      head=NULL;
      tail=NULL;
      length=0;
    }

    int queue_length()
    {
      return length;
    }
    void enqueue(Item x)
    {
      if(head==NULL)
      {
        head= new QNode<Item>(x);
        tail=head;
      }
      else
      {
        QNode<Item> *temp=tail;
        temp->next=new QNode<Item>(x);
        tail=temp->next;
      }
      length++; 
    }
    Item dequeue()
    {
      if(head==NULL)
        return 0;
      else
      {
        QNode<Item> *temp=head;
        int x;
      
      
        head=head->next;
        x=(temp->val);
        delete temp;
        length--;
        return x;
      }
    }
};
#endif 