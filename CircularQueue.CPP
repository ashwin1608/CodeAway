#include<conio.h>
#include<iostream.h>
#include<process.h>

  class CQ
  {
      int x[6] , front , rear , size;

      public:
      CQ()
      {
	      size = 6;
	  front = rear = -1;
      }
	 void PUSH();
	 void DISP();
	 void POP();
  };

	void CQ::PUSH()
	{
	     if(front ==-1)
	     {
		  front = rear = 0;
		  for(int i=0 ; i<size ; i++)
		      x[i] = 0;
	     }
	     else if( (front == 0  && rear == size) || ( front == rear+1))
	     {
		 cout<<"\n\n OVERFLOW..!!";
		     return;
	     }
	     else if(front != 0 && rear == size)
	     {
		 rear = 0;
	     }

		  cout<<"\n\n Enter any num : ";
		       cin>>x[rear];
		       rear++;
	}

	void CQ::DISP()
	{
	     if(front == -1)
	     {
		  cout<<"\n\n EMPTY..";
	     }
	     else
	     {
		 for(int i=0 ; i<size ;i++)
		 {
		       if(i== front)
		       {
			   cout<<" >>> "<<x[i];
		       }
		       else if(i== rear)
		       {
			   cout<<" "<<x[i]<<" <<< ";
		       }
		       else
		       {
			    cout<<"  "<<x[i];
		       }
		 }
	     }
	}

	void CQ::POP()
	{
	     if(front == -1)
	     {
		  cout<<"\n\n EMPTY..";
	     }
	     else
	     {
		  x[front] = 0;
		    front ++;

		    if(front==size)
		    {
			front = 0;
		    }
	     }
	}












 int menu()
 {
    int choice;

    clrscr();

    cout<<"\n\n 1] PUSH ";
    cout<<"\n\n 2] DISP ";
    cout<<"\n\n 3] POP ";
    cout<<"\n\n 4] EXIT ";

    cout<<"\n\n\n Enter choice : ";
	 cin>>choice;

	 return choice;
 }

void main()
{
    int ch;
    CQ obj;

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
		   cout<<"\n\n EXIT ";
		     getch();
		     exit(100);
	     default:
		    cout<<"\n\n PEPC ";
	 }

    getch();

    }while(ch != 4);
}