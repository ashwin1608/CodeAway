#include<conio.h>
#include<iostream.h>
#include<process.h>

   struct node
   {
       int num;
       node *prev;
   };

   class stack
   {
	node *top;

	public:
	stack()
	{
	   top = NULL;
	}

	void push();
	void disp();
	void pop();
   };

       void stack::push()
       {
	   node *newnode = new node;

	   cout<<"\n\n Enter any num : ";
	       cin>>newnode->num;

	     newnode->prev = top;
	      top = newnode;
       }


       void stack::disp()
       {
	    if(top == NULL)
	    {
	       cout<<"\n\n STACK IS EMPTY...";
	    }
	    else
	    {
		  node *temp = top;

		  while(temp != NULL)
		  {
		       cout<<"\n\n  "<<temp->num;
			 temp = temp->prev;
		  }
	    }

       };

       void stack::pop()
       {
	    if(top == NULL)
	    {
	       cout<<"\n\n STACK IS EMPTY...";
	    }
	    else
	    {
		  node *temp;
		  temp = top->prev;
		    delete top;
		    top = temp;
	    }
       }

   int menu();

void main()
{
       int ch;
       stack obj;
	 clrscr();

       do
       {
	   ch = menu();

	   switch(ch)
	   {
	     case 1:
		     obj.push();
		     obj.disp();
		       break;
	     case 2:
		     obj.disp();
		       break;
	     case 3:
		     obj.pop();
		     obj.disp();
		       break;
	     case 4:
		       cout<<"\n\n THANKS...!!!";
		       getch();
		       exit(0);
	     default:
		       cout<<"\n\n Please enter proper choice...";
	   }
	     getch();

       }while(ch!=4);
}


     int menu()
     {
	  int choice;

	  clrscr();

	  cout<<"\n\n 1] PUSH ";
	  cout<<"\n\n 2] DISP ";
	  cout<<"\n\n 3] POP ";
	  cout<<"\n\n 4] EXIT ";

	  cout<<"\n\n Enter ur choice : ";
	       cin>>choice;

	       return choice;
     }

