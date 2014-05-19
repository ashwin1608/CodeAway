#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

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

    void getdata()
    {
       cout<<"\n Enter rollno :";
       cin>>rollno;
       cout<<"\n\n Enter name : ";
	   gets(name);
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
    stud s[5];
    int i,r,flag = 1;
    char nname[20];
    stud  s1;

      clrscr();

      s[0] = stud("A" , 1);
      s[1] = stud("B" , 2);
      s[2] = stud("D" , 4);

      fstream obj1("stud1.txt",ios::in |  ios::out | ios::binary);
      fstream obj2("stud2.txt",ios::in |  ios::out | ios::binary);

	 for(i=0 ;i<3 ; i++)
	 {
	     obj1.write((char *) &s[i] , sizeof(s[i]));
		 s[i].show();
	 }

	    cout<<"\n\n Enter data to be inserted in file :";
		  s1.getdata();

		  obj1.seekg(0 , ios::beg);

	      for(i=0 ; i<3 ; i++)
	      {
		   obj1.read((char *) &s[i] , sizeof(stud));

		      if(s1.get() < s[i].get())
		      {
			  obj2.write((char *) &s1 , sizeof(stud));
			  obj2.write((char *) &s[i] , sizeof(stud));
				 flag = 2;
				 break;
		      }

		   obj2.write((char *) &s[i] , sizeof(stud));
	      }


	      if(flag == 1)
	      {
		  obj2.write((char *) &s1 , sizeof(stud));
	      }


	      while(!obj1.eof())
	      {
		   obj1.read((char *) &s[i] , sizeof(stud));
		   obj2.write((char *) &s[i] , sizeof(stud));
	      }

	      obj1.close();

	      obj2.seekg(0 , ios::beg);

	      for(i=0 ;i<4 ; i++)
	      {
		   obj2.read((char *) &s[i] , sizeof(s[i]));
		       s[i].show();
	      }

	      obj2.close();

	      remove("stud1.txt");
	      rename("stud2.txt", "stud1.txt");

	 getch();
}