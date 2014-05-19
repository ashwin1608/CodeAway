
    #include<iostream.h>
    #include<conio.h>
    #include<stdlib.h>


	struct node
	{
	    int num;
	    node *next;
	};


    class Q
    {
	node *front , *rear;

	  public:
	  Q()
	  {
	      front = rear = NULL;
	  }

	      void PUSH();
	      void DISP();
	      void POP();
    };


	    void Q::PUSH()
	    {
		  node *newnode = new node;

		  cout<<"\n\n Enter any num : ";
		     cin>>newnode->num;

		     newnode->next = NULL;

		  if(front == NULL)
		  {
			front = rear = newnode;
		  }
		  else
		  {
		     rear->next = newnode;
		     rear = newnode;
		  }
	    }

	    void Q::DISP()
	    {
		if(front == NULL)
		{
		     cout<<"\n\n EMPTY QUEUE..";
		}
		else
		{
		    node *temp = front;

		    while(temp != NULL)
		    {
			 cout<<"\n\n  "<<temp->num;
			   temp = temp->next;
		    }
		}
	    }


	    void Q::POP()
	    {
		if(front == NULL)
		{
		     cout<<"\n\n EMPTY QUEUE..";
		}
		else
		{
		   node *temp;
		   temp = front->next;
		      delete front;
		     front = temp;
		}

		if(front == NULL)
		{
		     rear = NULL;
		}
	    }

   int menu();

void main()
{
       int ch;
       Q obj;
	 clrscr();

       do
       {
	   ch = menu();

	   switch(ch)
	   {
	     case 1:
		     obj.PUSH();
		     obj.DISP();
		       break;
	     case 2:
		     obj.DISP();
		       break;
	     case 3:
		     obj.POP();
		     obj.DISP();
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

