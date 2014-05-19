#include<conio.h>
#include<iostream.h>
#include<process.h>

   struct node
   {
      int num;
      node *next;
   };

       int menu();
   void create(node *);
   void disp(node *);
   node* insert(node*);
   node* del(node*);
   node* search(node* , int);

void main()
{
     int ch;
     node *start=NULL;

     clrscr();

     do
     {
	 ch = menu();

	 switch(ch)
	 {
	    case 1:
		   start = new node;
		   create(start);
		   disp(start);
		   break;
	    case 2:
		   disp(start);
		   break;
	    case 3:
		    start = insert(start);
		       disp(start);
		     break;
	    case 4:
		     start = del(start);
		       disp(start);
			break;
	    case 5:
		  cout<<"\n\n Thanks.. ..";
		     getch();
		     exit(0);
	    default:
		  cout<<"\n\n Please enter proper choice...";
	 }
	    getch();

     }while(ch != 5);

}

      int menu()
      {
	  int choice;

	  clrscr();

	   cout<<"\n\n 1] Create a link list ";
	   cout<<"\n\n 2] Display link list ";
	   cout<<"\n\n 3] Insert into link list ";
	   cout<<"\n\n 4] Delete from link list ";
	   cout<<"\n\n 5] Exit ";

	   cout<<"\n\n\n Enter ur choice :  ";
		cin>>choice;

		return choice;
      }




	void create(node *first)
	{
	    cout<<"\n\n Enter any num or type 0 to finish : ";
		     cin>>first->num;

		 if(first->num == 0)
		 {
		    first->next = NULL;
		 }
		 else
		 {
		      first->next = new node;
		       create(first->next);
		 }
	}

	    void disp(node *first)
	    {
		if(first==NULL)
		{
		   cout<<"\n\n EMPTY LIST...";
		}
		else
		{
			while(first->next != NULL)
			{
			 cout<<"\n\n "<<first->num;
			       first = first->next;
			}
		}
	    }


	   node* insert(node *first)
	   {
		 int nnum , tnum;
		 node *newnode ,*tag;

		 cout<<"\n\n Enter new num : ";
		      cin>>nnum;
		 cout<<"\n\n Enter target num : ";
		      cin>>tnum;

		   if(first->num == tnum)
		   {
		      newnode = new node;
		      newnode->num = nnum;
		      newnode->next = first;
		      first = newnode;
		   }

		   else
		   {
		       tag = search(first , tnum);

			if(tag == NULL)
			{
			   cout<<"\n\n Target num not found...";
			}
			else
			{
			    newnode = new node;
			    newnode->num = nnum;
			    newnode->next = tag->next;
			    tag->next = newnode;
			}
		   }

		   return first;
	   }


	     node* search(node *first , int tnum)
	     {
		 if(first->next == NULL)
		 {
		    return NULL;
		 }
		 else if(first->next->num == tnum)
		 {
		    return first;
		 }
		 else
		 {
		    return search(first->next , tnum);
		 }
	     }

	     node* del(node *first)
	     {
		  int dnum;
		  node *tag , *temp;

		  cout<<"\n\n Enter num to be deleted : ";
		       cin>>dnum;

		     if(first->num == dnum)
		     {
			 temp = first->next;
			 delete first;
			 first = temp;
		     }
		     else
		     {
			  tag = search(first , dnum);

			   if(tag == NULL)
			   {
				cout<<"\n\n num not found...";
			   }
			   else
			   {
			      temp = tag->next->next;
			      delete tag->next ;
			       tag->next = temp;
			   }
		     }

		     return first;
	     }
