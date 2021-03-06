#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int n,i;                                   //Global Variables
int found=0;
void mainmenu();                           //Main Menu Function
void adminpage();                          //Admin Menu Function
void createrecord();                       //Create Record Function
void viewrecord();                         //Display Record Function
void updaterecord();                       //Update Record Function
void memberpage();                         //Member Menu Function
void search();                             //Book Search Function
struct library
	{                                   /*Structure"library" Declared Globally*/
		int bookno,copies;
		char name[10];
		float price;
	}l[25];


void main()
{
	clrscr();

	mainmenu();
	getch();
}

	void mainmenu()
{
	int ch;                             //Interger for entering choice
	cout<<"\n\t\tWELCOME TO UNIVERSITY LIBRARY MANAGEMENT SOFTWARE \n";
	cout<<"\n \n\n";
	cout<<"1. ADMINISTRATOR Login \n\n\n";
	cout<<"2. MEMBER Login \n\n\n";
	cout<<"3. EXIT";
	cout<<"\n \n \n";
	cout<<"ENTER your CHOICE....";
	cin>>ch;
	switch(ch)
	{
		case(1):clrscr();
			adminpage();
			break;
		case(2):clrscr();
			memberpage();
			break;
		default: exit(1);
	}
}
	void adminpage()
{
		cout<<"\n\t\t\t\tADMINISTRATOR LOGIN\n\n\n";
		cout<<"1. ENTER Records \n\n\n";
		cout<<"2. VIEW Records \n\n\n";
		cout<<"3. UPDATE Records \n\n\n";
		cout<<"4. RETURN to Main Menu\n\n";
		cout<<"Press any KEY to EXIT\n\n";
		int ch;
		cout<<"\nEnter your CHOICE....";
		cin>>ch;

		switch(ch)
		{
			case 1: clrscr();
				createrecord();
				break;
			case 2: clrscr();
				viewrecord();
				break;
			case 3: clrscr();
				updaterecord();
				break;

			case 4: clrscr();
				mainmenu();
				break;
			default:exit(1);               //to Exit from program


		}
	   getch();
}
void createrecord()
{
       if (found==0)
	  {
		cout<<"\n\t\t\t\tENTER RECORDS \n\n\n";
		ofstream fout;
		fout.open("library.dat",ios::trunc);
		fout<<"BOOK NO\t\t\tBOOK NAME\t\tPRICE\t\tCOPIES\n";
		fout<<"-------------------------------------------------------------------------------";
		fout<<"\n\n";
		cout<<"How many Records you want to enter ? ";
		cin>>n;
		cout<<"\n\n";
		for( i=0;i<n;i++)
		{
			cout<<"Enter Book no: ";
			cin>>l[i].bookno;
			fout<<l[i].bookno<<"\t\t\t";
			cout<<"Enter Book name: ";
			gets(l[i].name);
			fout<<l[i].name<<"\t\t\t";
			cout<<"Enter the price : ";
			cin>>l[i].price;
			fout<<l[i].price<<"\t\t";
			cout<<"Enter the no. of copies : ";
			cin>>l[i].copies;
			cout<<"\n";
			fout<<l[i].copies<<"\n";
		}
	   fout.close();
	   cout<<"\n\nPress any KEY to GO BACK\n";
	   getch();
	   clrscr();
	   adminpage();
}
	  else if (found==1)
{

		int bno;
		char f='n';
		cout<<"\n\t\t\t\tBOOK SEARCH \n\n\n";
		cout<<"Enter the Book no you want to search : \n";
		cin>>bno;
		ifstream fin;
		fin.open("library.dat",ios::in);
		for(int i=0;i<n;i++)
		{
			if(l[i].bookno==bno)
		  {
				f='y';
				cout<<"\n\n BOOK FOUND ! \n\n";
				cout<<"Book Name: "<<l[i].name<<"\n";
				cout<<"Book Price: "<<l[i].price<<"\n";
				cout<<"Copies: "<<l[i].copies<<"\n\n";
				cout<<"Student can issue the book for 15 days from the Universtiy Library. \n";
		   }
		}
		if (f=='n')
	{
		cout<<"Book not FOUND !";
	}
	fin.close();
	   cout<<"\n\nPress any KEY to go to MAIN MENU\n";
	   getch();
	   clrscr();
	   mainmenu();

	}
}

	void viewrecord()
{
	cout<<"\n\t\t\t\tVIEW RECORDS \n\n\n";
	ifstream fin;
	fin.open("library.dat",ios::in);
	char ch;
	while(!fin.eof())
	{
		fin.get(ch);
		cout<<ch;
	}
	cout<<"\n\n";
	fin.close();
	cout<<"Press any KEY to GO BACK \n";
	getch();
	clrscr();
	adminpage();
}
void updaterecord()
		{
		ofstream fout;
		int n;
		fout.open("library.dat",ios::app);
		cout<<"\n\t\t\t\tUPDATE RECORD\n\n";
		cout<<"How many Records you want to enter ? ";
		cin>>n;
		cout<<"\n\n";
		for(int i=0;i<n;i++)
		{
			cout<<"Enter Book no: ";
			cin>>l[i].bookno;
			fout<<l[i].bookno<<"\t\t\t";
			cout<<"Enter Book name: ";
			gets(l[i].name);
			fout<<l[i].name<<"\t\t\t";
			cout<<"Enter the price : ";
			cin>>l[i].price;
			fout<<l[i].price<<"\t\t";
			cout<<"Enter the no. of copies : ";
			cin>>l[i].copies;
			cout<<"\n";
			fout<<l[i].copies<<"\n";
		}
			fout.close();
			cout<<"\n\n Press any Key to GO BACK \n";
			getch();
			clrscr();
			adminpage();
}

void memberpage()
{
		cout<<"\n\t\t\t\tMEMBER LOGIN\n\n\n";
		cout<<"1. Search Books \n\n\n";
		cout<<"2. RETURN to Main Menu\n\n";
		cout<<"Press any KEY to EXIT\n\n";
		int ch;
		cout<<"\nEnter your CHOICE....";
		cin>>ch;

		switch(ch)
		{
			case 1: clrscr();
				search();
				break;
			case 2: memberpage();
				clrscr();
				break;
			default:exit(1);
			}

	 }

void search()
{
	found=1;
	createrecord();
}

   /*Thanks */