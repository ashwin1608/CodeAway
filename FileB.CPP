#include<conio.h>
#include<fstream.h>

void main()
{
   int x[]={10,20,30,40,50};

    clrscr();

    fstream obj("int.txt",ios::in | ios::out | ios::binary);

       for(int i=0 ; i<5 ; i++)
       {
	  obj.write( (char *) &x[i] , sizeof(x[i]));
       }


	 for(i=0 ; i<5; i++)
	 {
	     x[i]  = 0;
	     cout<<"\n\n x = "<<x[i];
	 }

	     obj.seekg(0);

	 for(i=0 ;i<5 ; i++)
	 {
		int pos = obj.tellg();
		cout<<"\n\n pos => "<<pos;

	    obj.read( (char *) &x[i] , sizeof(x[i]) );
	      //	 cout<<"\n\n x =  "<<x[i];
	 }

	     obj.close();

	   getch();
}