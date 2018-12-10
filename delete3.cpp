#include<iostream>
using namespace std;

struct node
{
int data;
node*link;
};

node*head=0;

void insert(int x)
{
  if(!head)
  {
    head=new node();
    head->data=x;
    head->link=0;
    return;
  }
  node*temp=new node();
  temp->data=x;
  temp->link=head;
  head=temp;
}

void delet(int n)
{
    if(n==1)
    {
      node*p=head;
      head=p->link;
      delete p;
      return;
    }
  node*temp1=head;

  for(int i=0;i<n-2;i++)
  temp1=temp1->link;

  node*temp2=temp1->link;
  temp1->link=temp2->link;
  delete temp2;
}

void print()
{
node*p=head;
while(p)
{
cout<<p->data<<" ";
  p=p->link;
}
cout<<endl;
}



int main()
{
cout<<"1->> for insert"<<endl;
cout<<"2->> for delete"<<endl;
cout<<"3-->> for showing"<<endl;
cout<<"4-->>  for exit"<<endl;

cout<<endl<<endl<<endl;

while(1)
{
  int x;
  cin>>x;
if(x==1)
{
cout<<"insert data"<<endl;
int val;
cin>>val;
insert(val);

}
else if(x==2)
{
cout<<"delete data from link"<<endl;
cout<<"pick the position"<<endl;
int pos;
cin>>pos;
delet(pos);

}
else if(x==3)
{
  cout<<"too see the state"<<endl;
  print();
  cout<<endl<<endl;
}
else
{
  return 1;
}

}
  return 0;
}
