#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

class stud
{
    char name[20];
    int rollno;

    public:

    stud(){}
    stud(char *s , int r)
    {
	   strcpy(name ,s);
	   rollno = r;
    }

    void show()
    {
	cout<<"\n\n rollno = "<<rollno;
	cout<<"\n\n name = "<<name;
    }

    int get()
    {
	return rollno;
    }
};


void main()
{
    stud s[3];
    int i,r,flag = 1;

      clrscr();

      s[0] = stud("A" , 1);
      s[1] = stud("B" , 2);
      s[2] = stud("D" , 3);

      fstream obj1("stud1.txt",ios::in |  ios::out | ios::binary);
      fstream obj2("stud2.txt",ios::in |  ios::out | ios::binary);

	  for(i=0 ; i<3; i++)
	  {
	      obj1.write((char *) &s[i] , sizeof(s[i]));
		s[i].show();
	  }

	    cout<<"\n\n Enter rollno : ";
		 cin>>r;

		 obj1.seekg(0);

		 for(i=0 ; i<3 ; i++)
		 {
		    obj1.read((char *) &s[i] , sizeof(s[i]));

		       if(r != s[i].get())
		       {
		       obj2.write((char *) &s[i] , sizeof(s[i]));
		       }
		       else
		       {
			   flag = 2;
		       }
		 }


		 if(flag ==1)
		 {
		     cout<<"\n\n num not present..";
			     getch();
			     exit(0);
		 }

		     obj1.close();
		     obj2.seekg(0);


	  for(i=0 ; i<2; i++)
	  {
	      obj2.read((char *) &s[i] , sizeof(s[i]));
		s[i].show();
	  }

	  obj2.close();

      getch();
}
