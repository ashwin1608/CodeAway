#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<ctype.h>

  class ticbooth

  {

       private :

	 static int people;
	 static float price ;
	 static int tno;
	 int key;
	 char c;

       public :

	   ticbooth()
	   {
	    people++;

	   }



	   void infodisp()


	   {

	     cout<<"\n\n\n\t\t> > > >   Welcome To Oriental Book Fair   < < < < ";
	     delay(500);
	     cout<<"\n\n\n   TIMINGS => 10:15 PM  to  8:15 PM  ";

	     delay(500);
	     cout<<"\n\n\n   DAYS => Friday  to  Sunday  ";

	     delay(500);
	     cout<<"\n\n\n   Ticket Price Per Head : @ Rs 2.5 /-   ";

	     delay(500);
	     cout<<"\n\n\n   Are You Interested in buying a ticket ? ? ?  :   ";

	     delay(500);
	     cout<<"\n\n\n\n   Please  press ' y ' (yes) or ' n ' (no)...kindly!!  ";

	      cin>>c;

	  }



	   void decide()

	   {

	      if( c == 'y' || c =='Y')

	      {

		   price += 2.5;

		   getch();
		   clrscr();


	      }


	      else

	     {

	      clrscr();

	     }



       }

	      void check()

	      {
	       cout<<"\n\nPress any [ numerical ] key !!!";
	       cin>>key;



	       if(key == 3125)
	       {
		cout<<"\n\nTotal People visited => "<<people;
		cout<<"\n\nTotal Amount colected  => Rs "<<price<<" /-";
		cout<<"\n\nTotal Tickets sold => "<<price/2.5;
		getch();
		clrscr();
	       }
		else
		{
		clrscr();
		}

	      }


  };


    float ticbooth ::price;
    int ticbooth ::people;
    int ticbooth :: tno;


void main()
{

	     int i;
	     clrscr();

	    for( i=1; i<=4; i++)
	   {
	     ticbooth ti;
	     ti.infodisp();
	     ti.decide();
	     ti.check();
	   }
	     getch();




}