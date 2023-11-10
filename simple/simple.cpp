#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<stdio.h>
#include<dos.h>
#define ll long long
using namespace std;
int choice;
//START OF CLASS
class hotel
{
private:

	int room_num;
	char fname[30];
	char lname[30];
	char id[20];
	char address[50];
	char phone[12];

public:
	int d;
	void main_menu();		//to dispay the main menu
	void add();			//to book a room
	int check(int r);			//to check room status
	void display(); 		//to display the customer record
	void rooms();			//to display alloted rooms
	void edit();			//to edit the customer record
	void modify(int);		//to modify the record
	void delete_record(int);		//to delete the record
	void bill(int);                 //for the bill of a record

};
//END OF CLASS

//FOR DISPLAYING MAIN MENU
void hotel::main_menu()
{
	while (choice != 5)
	{
		system("cls"); //Clearing the Screen The standard library header file <stdlib.h> is needed

		cout << "\n\t\t\t\t*************************";
		cout << "\n\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
		cout << "\n\t\t\t\t      * MAIN MENU *";
		cout << "\n\t\t\t\t*************************";
		cout << "\n\n\n\t\t\t1.Book A Room";
		cout << "\n\t\t\t2.Customer Records";
		cout << "\n\t\t\t3.Rooms Allotted";
		cout << "\n\t\t\t4.Edit Record";
		cout << "\n\t\t\t5.Exit";
		cout << "\n\n\t\t\tEnter Your Choice: ";
		cin >> choice;
		switch (choice)
		{

		case 1:	add();
			break;

		case 2: display();
			break;

		case 3: rooms();
			break;

		case 4:	edit();
			break;

		case 5: break;

		default:
		{
			cout << "\n\n\t\t\tWrong choice.....!!!";
			cout << "\n\t\t\tPress any key to  continue....!!";
			_getch();//fun is usually used to hold the output screen until the user  presses on the keyboard 
			//the header file <conio.h> 
		}

		}
	}
}

//END OF MENU FUNCTION

//FUNCTION FOR BOOKING OF ROOM

void hotel::add()
{
	system("cls");
	int r, flag;
	ofstream x1("Record.dat", ios::app);// ofstream writ file in pc
	cout << "\n Enter Customer Detalis";
	cout << "\n ----------------------";
	cout << "\n\n Room number: ";
	cout << "\n Total number. of Rooms - 50";
	cout << "\n Ordinary Rooms from 1 - 30";
	cout << "\n Luxuary Rooms from 31 - 45";
	cout << "\n Royal Rooms from 46 - 50";
	cout << "\n Enter The Room no. you want to stay in :- " << endl;
	cin >> r;
	flag = check(r);
	if (flag == 1)
		cout << "\n Sorry..!!!Room is already booked";
	else
	{
		room_num = r;
		cout << "  first Name: ";
		cin >> fname;
		cout << "  last Name: ";
		cin >> lname;
		cout << "  ID number: ";
		cin >> id;
		cout << " Address: ";
		cin >> address;
		cout << " Phone No: ";
		cin >> phone;
		cout << " Enter the Duration of stay: ";
		cin >> d;
		x1.write((char*)this, sizeof(hotel)); //write block of data  //The sizeof operator can be used to get the size of classes
		cout << "\n Room is booked...!!!";
	}

	cout << "\n Press any key to continue.....!!";

	_getch();//fun is usually used to hold the output screen until the user  presses on the keyboard 
			//the header file <conio.h> 
	x1.close();


}

//END OF BOOKING FUNCTION


int  hotel::check(int r)//to check room status
{
	int flag = 0;
	ifstream x("Record.dat", ios::in); // Opens file for reading
	while (!x.eof())// eof used to check if the stream is has raised any EOF (End Of File) error
	{
		x.read((char*)this, sizeof(hotel));//Read block of data  //The sizeof operator can be used to get the size of classes
		if (room_num == r)
		{

			flag = 1;
			break;

		}
	}
	x.close();
	return(flag);
}

//function to display the customer record  ```````````````````````````yes
void hotel::display()    
{
	system("cls");
	ifstream display("Record.dat", ios::in); //Opens file for reading
	int r;
	bool flag = 0;
	cout << "\n Enter room number. for a particular customer`s details :- " << endl;
	cin >> r;
	while (!display.eof())// eof used to check if the stream is has raised any EOF (End Of File) error
	{
		display.read((char*)this, sizeof(hotel));//Read block of data  //The sizeof operator can be used to get the size of classes
		if (room_num == r)
		{
			system("cls");
			cout << " Cusromer Details"<<endl;
			cout << "----------------" << endl;
			cout << endl;
			cout << " Room number:  " << room_num<<endl;
			cout << endl;
			cout << " Name:  " << fname << " "<<lname;
			cout << endl;
			cout << endl;
			cout << " ID number:  " << id << endl;
			cout << endl;
			cout << " Address:  " << address << endl;
			cout << endl;
			cout << " Phone no:  " << phone << endl;
			cout << endl;
			flag = 1;
			break;
		}

	}
	if (flag == 0)
		cout << "\n Sorry Room number. not found or vacant....!!";
	cout << "\n\n Press any key to continue....!!";

	_getch(); // fun is usually used to hold the output screen until the user  presses on the keyboard
		//the header file <conio.h> 
	display.close();

}
//end of display function 

//function to display alloted rooms
void  hotel::rooms()
{
	system("cls");

	ifstream c("Record.dat", ios::in); // Opens file for reading
	cout << "\n\t\t\t    List Of Rooms Allotted";
	cout << "\n\t\t\t    ----------------------";
	cout << "\n\n Room Number.\tfirst Name \tlast Name \t id \t\t\tAddresst\t\t\tPhone Number.\n";
	while (!c.eof()) // eof used to check if the stream is has raised any EOF (End Of File) error
	{
		c.read((char*)this, sizeof(hotel));//Read block of data  //The sizeof operator can be used to get the size of classes
		cout << "\n\n "<< room_num << "\t\t" << fname << "\t\t" << lname 
		<<"\t\t" << id << "\t\t"<<address << "\t\t" << phone;

	}

	cout << "\n\n\n\t\t\tPress any key to continue.....!!";
	_getch();// fun is usually used to hold the output screen until the user  presses on the keyboard
			//the header file <conio.h> 
	c.close();
}     //```````````````````````````yes
//end of rooms function 

//Function for editing records and for billing
void hotel::edit()
{
	system("cls");
	int choice, room;
	cout << " \n EDIT MENU ";
	cout << "\n ---------";
	cout << "\n\n 1.Modify Customer Record";
	cout << "\n 2.Delete Customer Record";
	cout << "\n 3. Bill Of Customer";
	cout << "\n Enter your choice: ";
	cin >> choice;
	system("cls");
	cout << "Enter room number" << endl;
	cin >> room;
	switch (choice)
	{
	case 1:
		modify(room);
		break;
	case 2:
		delete_record(room);
		break;
	case 3:
		bill(room);
		break;

	default:
		cout << " Wrong Choice...!!" << endl;

		break;
	}
	cout << " Press any key to continue..!!" << endl;

	_getch();// fun is usually used to hold the output screen until the user  presses on the keyboard
			//the header file <conio.h> 

}
//end of edit function

//function to modify the record
void  hotel::modify(int room)
{
	ll  pos, flag = 0;
	fstream m("Record.dat", ios::in | ios::out | ios::binary); // fstream  has the capabilities of both ofstream and ifstream which 
	//means it can create files, write information to files, and read information from files
	while (!m.eof())
	{
		pos = m.tellg();// tellg() Get position in input sequence
	   //Returns the position of the current character in the input stream.
		m.read((char*)this, sizeof(hotel));////Read block of data  //The sizeof operator can be used to get the size of classes
		if (room_num == room)
		{

			cout << "Enter New Details" << endl;
			cout << "-----------------" << endl;
			cout << "first Name: " << endl;
			cin >> fname;
			cout << "last Name: " << endl;
			cin >> lname;
			cout << "ID number: " << endl;
			cin >> id;
			cout << " Address: " << endl;
			cin >> address;
			cout << " Phone no: " << endl;
			cin >> phone;
			cout << " Duration of stay: " << endl;
			cin >> d;
			m.seekg(pos);//Set position in input sequence
			//Sets the position of the next character to be extracted from the input stream.
			m.write((char*)this, sizeof(hotel));//write block of data  //The sizeof operator can be used to get the size of classes
			cout << "Record is modified....!!" << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << " Sorry Room number. not found or vacant...!!" << endl;
	}
	m.close();

}//```````````````````````````yes
//end of modify function 

//function to delete record
void hotel::delete_record(int room)
{
	int flag = 0;
	string s;
	ifstream input("Record.dat", ios::in); // Opens file for reading
	ofstream output("file.dat", ios::out);//Opens file for writing
	while (!input.eof())
	{
		input.read((char*)this, sizeof(hotel));//Read block of data  //The sizeof operator can be used to get the size of classes
		if (room_num == room)
		{
			cout << "first Name: " << endl << fname;
			//cout << "last Name: " << endl << lname;
			//cout << "ID number: " << endl << id;
			cout << "Address: " << endl << address;
			cout << " Pone Number: " << endl << phone;
			cout << endl;
			cout << "Do you want to delete this record(Yes/No): " << endl;
			cin >> s;

			if (s == "no" || "NO" || "No")
				output.write((char*)this, sizeof(hotel));
			flag = 1;


		}
		else if (s == "yes" || "Yes" || "YES")
		{
			output.write((char*)this, sizeof(hotel));
		}
	}
	input.close();
	output.close();

	if (flag == 0)
		cout << " Sorry room number. not found or vacant...!!" << endl;

	else
	{

		remove("Record.dat");//The remove function  used to delete a file
		rename("file.datt", "Record.dat");//The rename() function to renames a specified file
		//int rename( const char *oldname, const char *newname );

	}
}
//end of delete function

//funcction for customer,s bill
void hotel::bill(int r)
{
	hotel h1;
	ifstream f1;
	f1.open("record.dat", ios::in | ios::binary);

	if (!f1)
		cout << "cannot open";

	else
	{

		f1.read((char*)&h1, sizeof(hotel));
		while (f1)

		{

			f1.read((char*)&h1, sizeof(hotel));

		}

		if (h1.room_num == r)
		{

			if (h1.room_num >= 1 && h1.room_num <= 30)
				cout << "your bill = 2000";

			else if (h1.room_num >= 35 && h1.room_num <= 45)
				cout << "your bill = 5000";

			else
				cout << "your bill = 7000";

		}

		else
		{
			cout << "room no. not found";
		}

	}

	f1.close();
	_getch();
	


}
//end of bill function


//start of main programS
int main()
{
	hotel h;
	system("cls");
	cout << "\n\t\t\t****************************";
	cout << "\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
	cout << "\n\t\t\t****************************";
	cout << "\n\n\t\tDeveloped By Marwa Gamal:";
	cout << "\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
	_getch();

	h.main_menu();
	return 0;

}
//end of main program 
