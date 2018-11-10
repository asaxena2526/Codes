#ifndef QUEUE
#define QUEUE 1

class QNode
{
  public:
    int val;
    QNode *next;

    QNode(int x)
    {
      val=x;
      next=NULL;
    }
};
class Queue
{ 
  public:
    QNode *head,*tail;
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
    void enqueue(int x)
    {
      if(head==NULL)
      {
        head= new QNode(x);
        tail=head;
      }
      else
      {
        QNode *temp=tail;
        temp->next=new QNode(x);
        tail=temp->next;
      }
      length++; 
    }
    int dequeue()
    {
      if(head==NULL)
        return 0;
      else
      {
        QNode *temp=head;
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