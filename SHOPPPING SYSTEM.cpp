#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <windows.h>
#include "queue1.h"
#include "animation.h"
#include "stackme.h"
#include <fstream>
using namespace std;

int search(int);
int display();
string check(int);
class node
{
	public:
	int ID;
	string proName;
	double prePrice;
	int quantity;
	struct node *next;
};

 node *head = NULL;

////////////////////////////////////////////////////////////////////
void beg()
{
	system("cls");
	ofstream obj;
	int id, quant; //  quant    for quantity
	string name;
	double pre; //  pre for price
	 node *t = new node;
	 node *p = head;
	 obj.open("Product_Info.txt");
    
	cout << "\t\t\tEnter product ID:-";
	cin >> id;
	obj<<"Product ID = "<<id<<endl;
	t->ID = id;
	cout << "\t\t\tEnter product Name:-";
	cin >> name;
	obj<<"Product Name = "<<name<<endl;
	t->proName = name;
	cout << "\t\t\tEnter product price:-";
	cin >> pre;
	obj<<"Product Price = "<<pre<<endl;
	t->prePrice = pre;
	cout << "\t\t\tEnter product quantity:-";
	cin >> quant;
	obj<<"Product Quantity = "<<quant<<endl;
	t->quantity = quant;
	obj.close("Product_Info.txt")
	if (head == NULL)
	{
		t->next = head;
		head = t;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = t;
		t->next = NULL;
	}
	system("cls");
	cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
int search(int id) //    for search item in list
{
	int count = 1;
	struct node *p = head;
	while (p != NULL)
	{
		if (p->ID == id)
			break;
		else
			count++;
		p = p->next;
	}
	return count;
}
/////////////////////////////////////////////////////////////////////////////////////////////
int hash(int x, int mod)
{
	return x % mod;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void delPro()
{
	system("cls");
	display();
	int id;
	 node *cur = head;
	 node *pre = head;
	cout << "\n\nEnter ID to delete that product:\n\n";
	cin >> id;
	if (head == NULL)
	{
		system("cls");
		cout << "List is empty" << endl;
	}
	int pos = 0;
	int count = display(); //   for load no of nodes
	pos = search(id);	   //   for check weather desire node is exist or not
	if (pos <= count)
	{

		while (cur->ID != id)
		{ //  for delete middle area products
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		system("cls");
		cout << "\n<<item is deleted>>\n";
	}
	else
	{
		cout << "\n<<<Not found>>\n\n";
	}
}

//////////////////////////////////////////////////////////////////////////////////
void modify()
{
	int id;
	double pre; //    pre for price
	string pName;
	int nid;
	int nq; //   pName for new name
	if (head == NULL)
	{
		system("cls");
		cout << "List is empty" << endl;
	}
	else
	{
		display();
		ifstream obj ; 
		cout << "\n\nEnter ID to modify product Name and its price:\n";
		cin >> id;
		struct node *cur = head;
		int pos = 0;
		int count = display(); //   for load no of nodes
		pos = search(id);
       obj.open("Product_Info.txt");
        while (!obj.eof() && line!=id)
            {

                getline(obj,line);
            }
		//   for check weather desire node is exist or not
		if (pos <= count)
		{

			while (cur->ID != id)
			{
				cur = cur->next;
			}
			cout << "\nOld ID : " << cur->ID << endl;
			cout << "\nOld Name : " << cur->proName << endl;
			cout << "\nOld Price : " << cur->prePrice << endl;
			cout << "\nOld Quantity : " << cur->quantity << endl;

			cout << endl
				 << endl;
			cout << "Enter new ID:";
			cin >> nid;
			cur->ID = nid;
			cout << "Enter new Name:";
			cin >> pName;
			cur->proName = pName;
			cout << "Enter new Price:";
			cin >> pre;
			cur->prePrice = pre;
			cout << "Enter new Quantity:";
			cin >> nq;
			cur->quantity = nq;
		}

		else
		{
			cout << id << " is <<<Not found>>\n\n";
		}
	}
}

////////////////////////////////////////////////////////////////////////
int display()
{
	system("cls");
	int c = 0; //   c for count products
     node *p = head;
	cout << "Existing products are:\n";
	cout << "ID\t\tProduct Name\t\t\Price\t\tQuantity\n";
	cout << "=================================================================|\n";
	while (p != NULL)
	{
		cout << p->ID << "\t\t" << p->proName << "\t\t\t" << p->prePrice << "\t\t\t" << check(p->quantity) << "\n"; //    call   check func and pass quantity
		p = p->next;
		c = c + 1;
	}
	cout << "\nTotal products in our store is : " << c << "\n\n\n";
	return c;
}
//////////////////////////////////////////////////////////////////
string check(int quant)

{ //        check function
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();

	if (quant <= 0)
		return "out of stock!";
	else
		return quantity;
}

///////////////////////////////////////////////////////////////////////
void buy()
{
	system("cls");
	display();
	string product[28];
	// for display sold item
	int pay = 0, no, c = 0, price, id, i = 1;

	if (head == NULL)
	{
		cout << "\n<<<<<There is no items to buy>>>>>\n\n";
	}
	else
	{
		cout << "How many items you want to buy ?";
		cin >> no;
		int count = display(); // for sotring no of nodes in c
		while (i <= no)
		{
			struct node *cur = head;
			int quant, cho;
		a:
			cout << "Enter id of item that you want to buy: ";
			int id, pos = 0;
			cin >> id;
			if (id == -1)
			{
				system("cls");
				return;
			}
			pos = search(id);
			if (pos <= count)
			{
				// item availible in store
				while (cur->ID != id)
				{
					cur = cur->next;
				}
				cout << "How many quantity you want:";
				cin >> quant;
				if (cur->quantity < quant)
				{
					cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
					cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
					goto a;
				}
				product[c] = cur->proName; // this will conatin the items buy names in array;
				c++;
				pay = pay + (cur->prePrice * quant);   //     calculate Bill
				cur->quantity = cur->quantity - quant; //    change quantity
				i++;
			}
			else
			{
				cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
			}
		}
		string customer;
		cout << "\n\t\t Enter Your Name : ";
		cin >> customer;
		enqueue(customer);
		system("cls");
		cout << "\n\n\n\n\t\t\tYou have bought : ";
		for (int i = 0; i < no; i++)
		{
			cout << product[i] << ",";
		}

		price = pay * (0.90); //    with 5% discount
		cout << "\n\nOriginal price : " << pay;
		cout << "\n with 10% discount: " << price << "\nThank you! for the shopping\n\n";
	}
}
///////////////////////////////////////////////////////////////////////
void administrator()
{
	system("cls");
	int ch;
	do
	{
		cout << "\t\t============================================" << endl;
		cout << "\t\t|             ADMINISTRATOR PORTAL         |" << endl;
		cout << "\t\t============================================" << endl;

		cout << "\t\t    Enter 1 to add a new product       " << endl;
		cout << "\t\t    Enter 2 to display all products       " << endl;
		cout << "\t\t    Enter 3 to Modify existing products       " << endl;
		cout << "\t\t    Enter 4 to delete a particular product       " << endl;
		cout << "\t\t    Enter 5 for Customers list       " << endl;
		cout << "\t\t    Enter 6 to Dequeue Costumer       " << endl;
		cout << "\t\t    Enter 7 to Generate Hash      " << endl;
		cout << "\t\t    Enter 0 for Main Menu       " << endl;

		cout << "\nEnter Your Choice : ";
		cin >> ch;
		switch (ch)
		{

		case 1:
			beg();
			break;

		case 2:
			modify();
			system("cls");
			break;

		case 3:
			modify();
			system("cls");
			break;

		case 4:
			delPro();
			cout << "\n-------Product is Deleted--------\n";
			break;

		case 5:
			system("cls");
			cout << "|==============CUSTOMERS NAMES LIST=================|" << endl;
			displayQueue();
			break;

		case 6:
			system("cls");
			cout << "|==============CUSTOMERS NAMES LIST=================|" << endl;
			dequeue();
			displayQueue();
			break;

		case 7:
			int x, n;
			cout << "Enter element to generate Hash = ";
			cin >> x;
			cout << " total list number : ";
			cin >> n;
			cout << "Hash of " << x << " is = " << hash(x, n);
			break;
		default:
			system("cls");
		}
	} while (ch != 0);
}
int main()
{
	for (int i = 0; i < 51; i++)
	{
		push(i);
	}

	system("color F1"); // for console colour
	gotoxy(17, 5);
	cout<<"-------------------------------------------------------------------"<< endl;
	gotoxy(17, 7);
	cout<<"||                      Shopping Club System                          ||"<< endl;
	gotoxy(17, 9);
	cout<<"-------------------------------------------------------------------"<< endl;
	gotoxy(17, 11);
	cout<<"                 |Subject Teacher ->> Miss Anum <<-|             \n"<< endl; 
	gotoxy(17, 13);
	cout << "               >>>-----Project Implemented By-----<<<             " << endl;
	gotoxy(22, 15);
	cout << "                       Sameel Ashar (4659)                       "<< endl;
	gotoxy(22, 16);
	cout << "                       Yousha Haider (4672)                       " << endl;
	gotoxy(22, 17);
	cout <<"                        Muhammad Arif (3496)                       " << endl<< endl ;
	system("pause");
	system("cls");
	system("color Fc");

	int ch;
	while (ch != 3)
	{

		//     Choice for below message

		cout << "\n\t\t|----------<Main Menu>-----------|";
		cout << "\n\n";
		cout << "\t\t 1) Administrator Of Market \n";
		cout << "\t\t 2) Customer                \n";
		cout << "\t\t 3) Exit                    \n";

		cout << "\nEnter Your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:

			administrator();
			break;

		case 2:
			cout << endl
				 << endl;
			bpop;
			system("pause");
			buy();
			break;

		case 3:
			cout << "\n\n\t\t\t\t\tThank You\t\t\t\t";
			break;
		}
	}

	return 0;
}
