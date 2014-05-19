#include<conio.h>
#include<iostream.h>
#include<process.h>

   int menu();
   void push(int[] ,int &);
   void pop(int[] ,int &);
   void disp(int[] ,int);

void main()
{
    int x[50] , size=0 ,ch;

	 clrscr();

       do
       {
	   ch = menu();

	   switch(ch)
	   {
	     case 1:
		       push(x,size);
		       disp(x,size);
		       break;
	     case 2:
		       disp(x,size);
		       break;
	     case 3:
		       pop(x,size);
		       disp(x,size);
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


     void push(int x[] ,int &size)
     {
	   cout<<"\n\n Enter any num : ";
		cin>>x[size];                 // PUSH
		size++;
     }

     void disp(int x[] , int size)
     {
	 if(size == 0)
	 {
	      cout<<"\n\n STACK EMPTY...";
	 }
	 else
	 {
	    for(int i=size-1; i>=0 ; i--)
	    {
		cout<<"\n\n "<<x[i];
	    }
	 }
     }

     void pop(int x[] , int &size)
     {
	  if(size == 0)
	  {
	       cout<<"\n\n STACK IS EMPTY...";
	  }
	  else
	  {
	       x[size-1] = 0;        // POP...
	       size--;
	  }
     }