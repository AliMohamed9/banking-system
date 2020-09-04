#include <iostream>
using namespace std ;
struct node
{
    string name;
    float money ;
    int num;
    node*next=NULL ;
}   ;
void add(node*&start);
void display(node*&start);
void edit(node*&start);
void Delete(node*&start);
void display_all (node*&start);


///////////////////////////////////////////////
int main()
{
    node*start;
    start=NULL;
    int ch;

    cout<<"welcome to Bank V1.1"<<endl;


    do
    {
        cout<<"enter the option \n";
        cout <<" (1)add customer...(2)display ...(3)edit ...(4)delete...(5)display all \n ";
        cin>>ch;

        switch(ch)
        {
        case (1):
            add(start);
            break;
        case (2) :
            display(start);
            break;
        case (3):
            edit(start);
            break;
        case(4):
            Delete(start);
            break;
        case(5) :
            display_all(start);
            break;
        }
    }
    while (ch<6);


    return 0;
}
//////////////////////////////////////////////////
void add(node *&start)
{
    static int number=0 ;


    cout <<"the customer number  "<<++number<<endl;

    node *temp;
    node *current;
    temp=new node;
    //insert box
    cout<<"enter the customer name "<<endl;
    cin>>temp->name;
    cout <<"enter the money \n ";
    cin>>temp->money ;
    temp->num = number;
    //position of box
    if(start==NULL)
        start=temp;
    else
    {
        current=start;
        while(current->next!=NULL)
        {
            current=current->next;
        }

        current->next=temp;
        temp->next=NULL;
    }


}


///////////////////////////////////////////////////////
void display(node *&start)
{
    int index;
    node *current;
    current =start;
    cout <<"enter the customer number to display.. \n";
    cin>>index;
    if(start==NULL)
    {
        cout<<"there is no client to  display"<<endl;
    }
    else
    {
        while(index != current->num)
        {
            current=current->next;
        }
        cout<<"the customer number is ....   "<<"("<<current->num<<")"<<endl;
        cout<<" the customer name is  ....   "<<current ->name<<endl;
        cout<<"the customer money is  ....   "<<current->money<<endl;
    }
}
//////////////////////////////////////////////////////////////
void edit(node*&start)
{
    int index;
    node*current=start;
    cout<<"enter the customer number to edit \n";
    cin>>index;
    cout<<"enter the new values \n";
     while(index != current->num)
        {
            current=current->next;
        }
    cout<<"enter the new value of money \n";
    cin>>current->money;
}
/////////////////////////////////////////////////////
void Delete(node*&start)
{
    node*temp=start;
    int index;
    int c=0;
    node * current1=start;
    node*current=start;
    cout <<"enter the customer,s number  to delete his information \n";
    cin>>index;
    if(index==1)
    {

        start=start->next;

        delete temp;
    }

    else
    {
        for(int i=1 ; i<index ; i++)
        {
            while( index!=current->num)
            {
                if(c>=1)
                    current1=current1->next;
                c++;
                current=current->next;

            }
        }
        if(current->next ==NULL)
        {
            current1->next=NULL;
            delete current;
        }
        else
        {
        temp=current1->next;
        current1->next=current1->next->next;
        delete temp;
        }
    }

}

void display_all(node*&start)
{
    node *current=start;

    do
    {
        cout<<"the customer number is  ....   "<<"("<<current->num<<")"<<endl;
        cout<<"the customer name   is  ....   "<<current ->name<<endl;
        cout<<"the customer money  is  ....   "<<current->money<<endl;
        current=current->next;
    }while(current != NULL);
}


