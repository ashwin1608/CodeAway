#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

class student
{
    char name[20];
    int rollno;

    public:
    student(){}

    student(char *s , int r)
    {
	strcpy(name , s);
	   rollno = r;
    }

    void show()
    {
	 cout<<"\n\n rollno => "<<rollno;
	 cout<<"\n\n Name => "<<name;
    }

    void getdata()
    {
	 cout<<"\n\n Enter rollno : ";
	      cin>>rollno;
	 cout<<"\n\n Enter name :";
	      gets(name);
    }

    get()
    {
      return rollno;
    }

};


void main()
{
     student s[5] , s1;
     int i,r;
     char nname[20];

      clrscr();

      s[0] = student("A" , 1);
      s[1] = student("B" , 2);
      s[2] = student("C" , 3);

	  fstream obj1("student1.txt",ios::in | ios::out | ios::binary);
	  fstream obj2("student2.txt",ios::in | ios::out | ios::binary);

	     for(i=0 ; i<3 ; i++)
	     {
		  obj1.write((char *) &s[i] , sizeof(s[i]));
			   s[i].show();
	     }

	       s1.getdata();

		   obj1.seekg(0);
		   int f=1;

		for(i=0 ; i<3 ; i++)
		{
		    obj1.read( (char *) &s[i] , sizeof(s[i]));

			if(s1.get()  < s[i].get())
			{
			     f = 2;
			   obj2.write((char *) &s1 , sizeof(s1));
			   obj2.write((char *) &s[i] , sizeof(s[i]));
			   break;
			}

			 obj2.write((char *) &s[i] , sizeof(s[i]));
		}

		 if(f == 1)
		 {
		      obj2.write((char *) &s1 , sizeof(s1));
		 }


		 while(! obj1.eof())
		 {
		    obj1.read( (char *) &s[i] , sizeof(s[i]));
		    obj2.write((char *) &s[i] , sizeof(s[i]));
		 }

		 obj1.close();
		 obj2.seekp(0 , ios::beg);

	     for(i=0 ; i<4 ; i++)
	     {
		  obj2.read((char *) &s[i] , sizeof(s[i]));
			   s[i].show();
	     }


	     getch();
}