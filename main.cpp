#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

                                    /**    THIS IS FIRST CLASS
                                    *
                                    *      CONTAIN SOME SETTERS,GATTERS
                                    *      AND SOME VARIABLES
                                    **/
class Node
{
private:
    Node *next;
    int data;
public:
    void setNextNode(Node *n)
    {   next=n;
    }

    void setData(int d)
    {   data=d;
    }

    int getData()
    {
         return data;
    }

    Node *getNextNode()
    {   return next;
    }

    Node(int d)
    {   next=NULL;
        data=d;
    }

    Node()
    {
         next=NULL;
    }

};/// CLASS END PARENTHESIS

/**       **********    First Class End      *************
*         *******       Second Class            **********
*         ****          Linked_List Class          *******
*
**/

class Linked_List
{
private:
    Node *first;
    Node *NONE;
    Node *new_ptr;
public:

Linked_List()
{
    first=NULL;
    NONE =NULL;
    new_ptr=NULL;
}
    void add_at_start(int dat)       ///THIS IS ADD AT START FUNCTION
    {   Node *temp=new Node(dat);
        Node *temp2=first;
        if(first==NULL)
            first=temp;
        else
        {   first=temp;
            temp->setNextNode(temp2);
        }
    }//End

  void add_at_end(int dat)      ///THIS FUNCTION WILL ADD AT END OF THE LIST
  {
      Node *temp=new Node(dat);
      Node *temp2=first;
      if(first==NULL)
        add_at_start(dat);
      else
      {
      while(temp2->getNextNode()!=NULL)
      {
          temp2=temp2->getNextNode();
      }
      temp2->setNextNode(temp);
      }
  }//END


    void display_all()             ///This Will display list
    {   Node *temp=first;
    if(first==NULL)
        cout<<"Sorry, List is Empty :)  "<<endl;
    else{
        while(temp !=NULL)
        {   cout<<temp->getData()<<endl;
            temp=temp->getNextNode();
        }
    }
    }//End

    void remove_first()          ///THIS WILL REMOVE THE FIRST VALUE
    {
        if(first==NULL)
            cout<<"Sorry, List is Empty Nothing to Delete :) "<<endl;

    else if(first->getNextNode()==NULL)
        first=NULL;
    else
        first=first->getNextNode();
    }//END


    void remove_last()            ///THIS WILL REMOVE THE LAST VALUE
    {

        Node *temp=first;
        if(first==NULL)
            cout<<"Sorry, List is Empty :) "<<endl;
        else if(first->getNextNode()==NULL)
            first=NULL;
        else
        {
            while(temp->getNextNode()->getNextNode()!=NULL)
            {
                temp=temp->getNextNode();
            }
        temp->setNextNode(NONE);
        }
    }//End

    void remove_wanted(int dat)      ///THIS WILL REMOVE THE USER GIVEN VALUE FROM LIST
    {
        Node *temp=first;
        int co=0;
        if(first==NULL)
            cout<<"Sorry, Data List is Empty "<<endl;
            else if(first->getData()==dat)
                first=first->getNextNode();
        else
        {
            Node *t=first;
            while(t->getNextNode()!=NULL)
            {
                if(t->getData()==dat)
                    co++;
            t=t->getNextNode();
            }
            if(co==0)
                cout<<"Sorry, Given Data is not found "<<endl;
            else
            {
               temp=first;
                while(temp->getNextNode()->getData()!=dat)
            {
                temp=temp->getNextNode();
            }
            temp->setNextNode(temp->getNextNode()->getNextNode());
            }
 }
 }//END OF FUNCTION

int getSize()         ///THIS FUNCTION WILL GIVE THE SIZE
{
    int countr=0;
    Node *temp=first;
    if(temp==NULL)
        cout <<"Sorry, List is Empty >> "<<endl;
    else
    {
    while(temp!=NULL)
    {
        temp=temp->getNextNode();
        countr++;
    }
    }
    return countr;
}//END  OF FUNCTION

void remove_index(int ind)     ///THIS FUNCTION WILL REMOVE THE VALUE , WHICH INDEX IS GIVEN BY USER
{
    if(first == NULL)
        cout <<"Sorry, List is Empty "<<endl;
    else {
    Node *temp=first;
    int i=0;
    if(ind < 0)
        cout <<"Sorry, Wrong Index/Location is given : "<<endl;

    else
        if(ind > getSize())
        cout <<" Sorry, given Index Exceeds the Size of List "<<endl;

    else
        if(ind == 0)
        first = first->getNextNode();
    else
        if (ind==1)
        first ->setNextNode(first->getNextNode()->getNextNode());
    else
    {
    {
        for(i=1; i<ind ; i++)
            temp=temp->getNextNode();
    }
    temp->setNextNode(temp->getNextNode()->getNextNode());
    }
    }
}//END OF FUNCTION


void add_at_user_p(int dat, int indx)       ///THIS WILL ADD A NEW NODE AT USER GIVEN POSITION
{
    Node *temp2=new Node(dat);
    Node *temp=first;
    if(indx<0)
        add_at_start(dat);
    else if(indx>getSize())
        add_at_end(dat);
    else if(indx+1==getSize())
        add_at_end(dat);
    else
        {
        for (int i=1; i<indx; i++)
        {
            temp=temp->getNextNode();
        }
        temp2->setNextNode(temp->getNextNode());
        temp->setNextNode(temp2);
    }
}//END OF FUNCTION

void search_data(int dat)        ///THIS IS FOR SEARCHING DATA ON THE BASE OF
{                                ///      GIVEN DATA
    Node *temp=first;
    int co=0,x=0;
    while(temp!=NULL)
    {
        if(temp->getData()==dat)
            co++;
     temp=temp->getNextNode();
    }
    if(co==0)
        cout <<"Sorry, The Given Data is Not Found inThe List "<<endl;
    else
    {
        temp=first;
        while(temp->getData()!= dat)
        {
              temp=temp->getNextNode();
        x++;
         }
        cout <<"The Position Of Given Data is  "<<x<<endl;
    }
}//END OF FUNCTION

void show_data(int indxx)        ///THIS WILL SEARCH ON THE BASE OF INDEX
{
    Node *temp=first;
    if(indxx>getSize())
        cout <<"Sorry, the Given index Exceeds the Size of Linked List "<<endl;
    else if(indxx<0)
        cout <<"Sorry, Given Position is not correct "<<endl;
    else
    {
      for(int i=0; i<indxx; i++)
      {
          temp=temp->getNextNode();
      }
      cout <<"The Data At Given Location is "<<temp->getData()<<endl;
    }

}//END OF FUNCTION

void readFile()              ///THIS FUNCTION WILL READ INSTRUCTION FROM FILE
{
 ifstream file;
 string ch;
 file.open("read.txt");
 while(file.eof()==0)
 {
     file>>ch;
     if(ch=="A")
     {
         int x;
         file>>x;
         add_at_end(x);
     }
     if(ch=="AAS")
     {
         int y;
         file >>y;
         add_at_start(y);
     }
     if(ch=="AT")
     {
         int z,xx;
         file >>ch;
         file >>ch;
         add_at_user_p(xx,z);
     }
     if(ch=="D")
     {
         display_all();
     }
     if(ch=="RFS")
     {
         remove_first();
     }
     if(ch=="RA")
     {
         int nn;
         file>>nn;
         remove_index(nn);
     }
     if(ch=="R")
     {
         int bb;
         file >>bb;
         remove_wanted(bb);
     }
     if(ch=="RFE")
     {
         remove_last();
     }
 }//while end
file.close();
}//END OF FUNCTION


};//class End

                /**
                *
                *                      MAIN FUNCTION START FROM HERE
                *
                **/

int main()
{   Linked_List myList;
    char ch;
    int choice,dat;

    do           //do while loop start
    {
        system("CLS");

        cout<<"********************************************"<<endl;
        cout<<"1 For Add data at start                  ***"<<endl;
        cout<<"2 For Add data at end                    ***"<<endl;
        cout<<"3 For Remove Data From start             ***"<<endl;
        cout<<"4 For Remove data From Last              ***"<<endl;
        cout<<"5 For Remove Specific Data From list     *** "<<endl;
        cout<<"6 For Remove Data from Specific index    ***"<<endl;
        cout<<"7 For Add Data at Specific Location      ***"<<endl;
        cout<<"8 To SEARCH for Data                     ***"<<endl;
        cout<<"9 To Search data on Desired location     ***"<<endl;
        cout<<"10 For Get the Size of the List          ***"<<endl;
        cout<<"11 For Display whole List                ***"<<endl;
        cout<<"12 To  read instruction from File        ***"<<endl;
        cout<<"********************************************"<<endl;
        cout<<endl<<"Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {   case 1:
                cout<<"Enter Value to be add at start : ";
                cin>>dat;
                myList.add_at_start(dat);
                break;

            case 2:
                cout<<"Enter Data to Add at end : ";
                cin>>dat;
                myList.add_at_end(dat);
                break;
            case 3:
                myList.remove_first();
                break;
            case 4:
                myList.remove_last();
                break;
            case 5:
                cout<<endl<<"Enter the Data you want to delete from List : ";
                cin>>dat;
                myList.remove_wanted(dat);
                break;
            case 6:
                cout<<endl<<"Enter the index you want Delete it's Data : ";
                cin>>dat;
                myList.remove_index(dat);
                break;
            case 7:
                cout <<"Enter the Location of New Data : ";
                cin >>choice;
                cout <<"Enter the Data : ";
                cin >>dat;
                myList.add_at_user_p(dat, choice);
                break;
            case 8:
                cout <<"Enter the Data : ";
                cin >>dat;
                myList.search_data(dat);
                break;
            case 9:
                cout <<"Enter the Location To Show It's Data : ";
                cin>>dat;
                myList.show_data(dat);
                break;
            case 10 :
                dat= myList.getSize();
                if(dat!=0)
                cout <<endl<<"The Size of the List is  >> "<<dat<<endl;
                break;
            case 11:
                cout <<endl<<"Displaying List .......   "<<endl;
                myList.display_all();
                break;
            case 12:
                myList.readFile();
                break;

            default :
                cout <<endl<<"Invalid Choice Entered "<<endl;

        }  //switch End
        cout<<endl<<"Do You Want To Continue : (y/n) : ";
        cin>>ch;
        cout <<endl<<endl;
    }
    while(ch!='n');

    return 0;
}
