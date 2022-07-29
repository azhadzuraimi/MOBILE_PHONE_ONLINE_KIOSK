#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;




struct admin //admin
{
    string name;
    int no;
    int id;
    int pass;
    admin *link;
};


struct food //food
{
    string name;
    int no;
    int item;
    float price;
    food *link;
};

struct drink //food
{
    string name;
    int no;
    int item;
    float price;
    drink *link;
};


int  mainMenu();
int  login1(admin *head);
int  mainMenu2();
int  exitprogram();
int  userselection(int ,food *head_1,drink *head_2,admin *head_3);
int  giveadmin_no(admin *head,int pass);
int  adminselect(int j,food *head_1,drink *head_2,admin *head_3);
int checkfood_no(food *head);
int checkdrink_no(drink *head);
int chooseaddnewitem(food *head_1,drink *head_2,admin *head_3);
int choosereplenishstock(food *head_1,drink *head_2,admin *head_3);
int choosedeletestock(food *head_1,drink *head_2,admin *head_3);
float customerselect(food *head_1,drink *head_2,float price); //customer selct
float buyfood(food *head,float price); //customerbuyfood
float buydrink(drink *head,float price);
float givefood_price(food *head,int no,int n);
float givedrink_price(drink *head,int no,int n);
void welcomescreen();
void initNode(food *head,string name,int no, int item, float price); //first node food
void addNode(food *head,string name,int no, int item, float price);  //add node food
void display(food *head);           //display node food
void initNode2(admin *head,string name,int n,int id, int pass);  // first node food
void addNode2(admin *head,string name,int n,int id, int pass);  //add node food
void display2(admin *head); //display node food
void displayadmin_info(admin *head,int no);
void displayadmin_name(admin *head,int no);
void displayadmin_id(admin *head,int no);
void displaycustomer_food(food *head);
void displaycustomer_drink(drink *head);
void displayfood_name(food *head,int no);
void displaydrink_name(drink *head,int no);
void receiptcustomer(float price);
void minusbuy_drink(drink *head,int no_item ,int total );
void minusbuy_food(food *head,int no_item ,int total );
void fileadd_food(food *head,int n);
void fileadd_foodno(int n);
void filebuy_food(food *head,int no_item ,int total );
void fileadd_drink(drink *head,int n);
void fileadd_drinkno(int n);
void filebuy_drink(drink *head,int no_item ,int total );
void addNode_drink(drink *head,string name,int no, int item, float price);
void initNode_drink(drink *head,string name,int no, int item, float price);
void display_drink(drink *head);
void replenishfood(food *head,int no, int item);
void replenishdrink(drink *head,int no, int item) ;
bool checkadmin_id(admin *head,int id);
bool checkadmin_pass(admin *head,int pass,int id);
void deletefoodlast(food *head,int no);
void deletefoodinit(food *head);
void deletefoodmiddle(food *head,int no);
void deletedrinkinit(drink *head) ;
void deletedrinklast(drink *head, int no);
void deletedrinkmiddle(drink *head,int no);
void reconstructdrink(drink *head,int  no);
void reconstructfood(food *head,int  no);

int main(){
string nameread[50]; //read file declare for food
int noread[50];
int itemread[50];
float priceread[50];
int nostockfood;

ifstream fileread_1;
fileread_1.open("no of stock food.txt");
cout<<"\nStock food no: ";
fileread_1>>nostockfood;
cout<<nostockfood<<"\n\n";
fileread_1.close();


food *head_1 = new food; //food node link

ifstream fileread_2;    //read data from stockfood.txt
fileread_2.open("stock food.txt");
cout<<"Stock left from food\n";
for(int i=0;i<nostockfood; i++)
{
    fileread_2>>nameread[i]>>noread[i]>>itemread[i]>>priceread[i];
}
for(int i=0;i<1;i++)
{
    initNode(head_1,nameread[i],noread[i],itemread[i],priceread[i]); //initialize food
}
for(int i=1;i<nostockfood;i++)
{
    addNode(head_1,nameread[i],noread[i],itemread[i],priceread[i]);
}
fileread_2.close(); /*
display(head_1);  */  //display all node for food

string nameread_2[50]; //read file declare for drink
int noread_2[50];
int itemread_2[50];
float priceread_2[50];
int nostockdrink;

ifstream fileread_3;
fileread_3.open("no of stock drink.txt");
cout<<"\nStock Drink no: ";
fileread_3>>nostockdrink;
cout<<nostockdrink<<"\n\n";
fileread_3.close();

drink *head_2 = new drink;

ifstream fileread_4;    //read data from stockdrink.txt
fileread_4.open("stock drink.txt");
cout<<"\n\nStock left from drink\n";
for(int i=0;i<nostockdrink; i++)
{
    fileread_4>>nameread_2[i]>>noread_2[i]>>itemread_2[i]>>priceread_2[i];
}
for(int i=0;i<1;i++)
{
    initNode_drink(head_2,nameread_2[i],noread_2[i],itemread_2[i],priceread_2[i]);  //initialize food
}

for(int i=1;i<nostockdrink;i++)
{
    addNode_drink(head_2,nameread_2[i],noread_2[i],itemread_2[i],priceread_2[i]);
}
fileread_4.close();/*
display_drink(head_2); */  //display all node for drink



admin *head_3 = new admin; //admin data read

initNode2(head_3,"Muhammad azhad bin zuraimi",1,101,111);  //initialize food


addNode2(head_3,"Muhammad Idin Harith",2,202,222);/*
display2(head_3);*/

/*
system("pause"); */

system("cls");
welcomescreen();

int choice, display, no;

display=mainMenu(); // 1=customer, 2=admin, 0=exit
userselection(display,head_1,head_2,head_3); //go to user selection menu


  return 0;
}


void welcomescreen() //welcome screen
{
    cout<<"!! Welcome To Kiosk  AZDIN !!\n";
    cout<<"Please Ensure That All Information Is Provided Correctly\n\n";                           // Prints welcome greetings to user.
}

int mainMenu()  //first main menu
{
    int choice;
    int i;
    cout<<"\n\nPlease select a user \n";														    // Prints to ask user to select a department.
    cout<<"\nEnter '1' for Customer \nEnter '2' for Admin \nEnter '0' = Exit\n";		            //  Prints out selection infos.
    cout<<"\nEnter your choice:\n";
    cin>>choice;
    for( i=0; i<1; i++) 																		    // detects users selection and return the value.
    {
        if (choice==0)
            return choice;
        if (choice==1)
            return choice;
        if (choice==2)
            return choice;
        else
        {
            cout<<"\nprogram cannot read please try again\n";
            mainMenu();
        }
    }
}


int userselection(int display,food *head_1,drink *head_2, admin *head_3) //userselection menu
{
int i;
float price=0;
for( i=0; i<1; i++){ // detects users selection and return the value.
    if (display==0)
        {  //exit
       return exitprogram();
    }

    else if (display==1)//customers
        {
            int k;
            price=customerselect(head_1,head_2,price);
            if(price==0)
                return exitprogram();
            receiptcustomer(price);

    }

    else if (display==2)//administrator
        {
            int j;
            j=login1(head_3);
            return adminselect(j,head_1,head_2,head_3);
    }
}
}


int adminselect(int j,food *head_1,drink *head_2,admin *head_3) //admin select
{
system("cls");
	int choice;
	int i;
	char k;

	cout<<"||Welcome admin||\n\n";
	cout<<"Name of admin :";
	displayadmin_name(head_3,j);
	cout<<endl;
	cout<<"id :";
	displayadmin_id(head_3,j);
	cout<<"\n\n\n";
	cout<<"\n\nselect choice \n";														        // Prints to ask user to select a department.
	cout<<"\nEnter '1' for add new item\nEnter '2' for replenish stock\nEnter '3' for delete stock\nEnter '0' = Exit\n";		//  Prints out selection infos.
	cout<<"\nEnter your choice:";
	cin>>choice;
	for( i=0;i<1;i++){																			// detects users selection and return the value.
	if (choice==0)
    {
	cout<<"\n\n||choice 0||";
	system("pause");
	return exitprogram();
	}
	else if (choice==1)
    {
	cout<<"\n\n||choice 1||";
	system("pause");
	chooseaddnewitem(head_1,head_2,head_3);
	cout<<"did u want to make any other decision? (y)";
	cin>>k;
	if (k=='y')
        adminselect(j,head_1,head_2,head_3);
	return exitprogram();
    }
	else if (choice==2)
    {
	cout<<"\n\n||choice 2||";
	system("pause");
	choosereplenishstock(head_1,head_2,head_3);
	cout<<"did u want to make any other decision? (y)";
	cin>>k;
	if (k=='y')
        adminselect(j,head_1,head_2,head_3);
	return exitprogram();
    }
    else if (choice==3)
    {
	cout<<"\n\n||choice 3||";
	system("pause");
	choosedeletestock(head_1,head_2,head_3);
	cout<<"did u want to make any other decision? (y)";
	cin>>k;
	if (k=='y')
        adminselect(j,head_1,head_2,head_3);
	return exitprogram();
    }
	else
    {
    cout<<"\nprogram cannot read please try again\n";
	adminselect(j,head_1,head_2,head_3);
	}
}
}


int chooseaddnewitem(food *head_1,drink *head_2,admin *head_3) //admin choose new item to add
{
    string name;
    int stock,x,no;
    char j;
    float price;
    int i;

    system("cls");
    cout<<"choose what did u want to add\n";
    cout<<"1.food\n2.drink\n";
    cin>>x;
    switch (x){
        case 1: //add food
            cout<<"\nname of the food(MAX 13 characters and no space): \n";
            cin>> name;
            cout<<"\nstock:\n";
            cin>>stock;
            cout<<"\nprice of "<<name<<"\n";
            cin>>price;
            no=checkfood_no(head_1);
            no++;
            cout<<"\nitem is no: "<<no<<endl;
            system("pause");
            addNode(head_1,name,no,stock,price);
            fileadd_foodno(no);
            fileadd_food(head_1,no);
            display(head_1);
            cout<<"whant to add another? (Y)\n";
            cin>>j;
            if(j=='y'){
                chooseaddnewitem(head_1,head_2,head_3);
            }

            return 0;

        case 2: //add drink
            cout<<"\nname of the drink(MAX 13 characters AND no space): \n";
            cin>> name;
            cout<<"\nstock:\n";
            cin>>stock;
            cout<<"\nprice of "<<name<<"\n";
            cin>>price;
            no=checkdrink_no(head_2);
            no++;
            cout<<"\nitem is no: "<<no<<endl;
            system("pause");
            addNode_drink(head_2,name,no,stock,price);
            fileadd_drinkno(no);
            fileadd_drink(head_2,no);
            display_drink(head_2);
            cout<<"whant to add another? (Y)\n";
            cin>>j;
            if(j=='y'){
                chooseaddnewitem(head_1,head_2,head_3);
            }

            return 0;

        default:
            cout<<"\ncannot read, please try again";
            chooseaddnewitem(head_1,head_2,head_3);

    }
}


float customerselect(food *head_1,drink *head_2,float price) //customer selection
{
    system("cls");
	int choice;
	int i;

	cout<<"||Welcome customer||\n\n";
    cout<<"\n\ntotal :"<<price;
	cout<<endl;
	cout<<"\n\n\n";
	cout<<"\n\nselect choice \n";	 // Prints to ask user to select a department.
	cout<<"\nEnter '1' for buy FOOD\nEnter '2' for buy DRINK\nEnter '0' = Exit\n";		//  Prints out selection infos.
	cout<<"\nEnter your choice:";
	cin>>choice;
	for( i=0;i<1;i++){// detects users selection and return the value.
	if (choice==0)
    {
	cout<<"\n\n||choice 0||";
    return price;
	}
	if (choice==1)
    {
	cout<<"\n\n||choice 1||"; //buy food

	price = buyfood(head_1,price);

    }
	if (choice==2)
    {
	cout<<"\n\n||choice 2||"; //buy drink

	price = buydrink(head_2,price);

    }
}
    return  customerselect(head_1,head_2,price);
}


float buyfood(food *head,float price) //buyfood
{
    system("cls");
    int n,b;
    char another;
    cout<<left<<setw(15)<<"name";
    cout<<right<<setw(15)<<"no";
    cout<<right<<setw(15)<<"item";
    cout<<right<<setw(15)<<"price";
    cout<<"\n"<< endl;
    displaycustomer_food(head);
    cout<<"\ntotal price: ";
    cout<<price;
	cout<<"\n\nselect choices of food from no\n";
	cin>>n;
	cout<<"\nu choose ";
	displayfood_name(head,n);
	cout<<"\n\nhow many did u want?\n";
	cin>>b;
	price += givefood_price(head,n,b);
    filebuy_food(head,n,b);
    minusbuy_food(head,n,b);
	cout<<"\ntotal price: "<<price;
	cout<<"\ndid u want to buy another food?y/n\n";
	cin>>another;
	if(another=='y'){
        price=buyfood(head,price);
	};

	return price;
}

float buydrink(drink *head,float price) //buyfood
{
    system("cls");
    int n,b;
    char another;
    cout<<left<<setw(15)<<"name";
    cout<<right<<setw(15)<<"no";
    cout<<right<<setw(15)<<"item";
    cout<<right<<setw(15)<<"price";
    cout<<"\n"<< endl;
    displaycustomer_drink(head);
    cout<<"\ntotal price: ";
    cout<<price;
	cout<<"\n\nselect choices of drink from no\n";
	cin>>n;
	cout<<"\nu choose ";
	displaydrink_name(head,n);
	cout<<"\n\nhow many did u want?\n";
	cin>>b;
	price += givedrink_price(head,n,b);
	filebuy_drink(head,n,b);
    minusbuy_drink(head,n,b);
	cout<<"\ntotal price: "<<price;
	cout<<"\ndid u want to buy another drink?y/n\n";
	cin>>another;
	if(another=='y'){
        price=buydrink(head,price);
	};

	return price;
}


void initNode(food *head,string name,int no, int item, float price)//first node for food
{
    head->name = name;
    head->no = no;
	head->item = item;
	head->price = price;
	head->link =NULL;
}


void initNode_drink(drink *head,string name,int no, int item, float price)//first node for food
{
    head->name = name;
    head->no = no;
	head->item = item;
	head->price = price;
	head->link =NULL;
}


void initNode2(admin *head,string name,int n,int id, int pass)//first node for admin
{
	head->name = name;
	head->no = n;
	head->id = id;
	head->pass = pass;
	head->link =NULL;
}


void addNode(food *head,string name,int no, int item, float price) //add node for food
{
	food *newNode = new food;
	newNode->name = name;
    newNode->no = no;
	newNode->item = item;
	newNode->price = price;
	newNode->link = NULL;

	food *cur = head;
	while(cur) {
		if(cur->link == NULL) {
			cur->link = newNode;
			return;
		}
		cur = cur->link;
	}
}


void replenishfood(food *head,int no, int item) //add node for food
{
	float p;
	food *list = head;
	while(list) {
		if (list->no == no)
            {
                list->item=item;
                return;
		}
        else
            list = list->link;
	}
}


void replenishdrink(drink *head,int no, int item) //add node for food
{
	float p;
	drink *list = head;
	while(list) {
		if (list->no == no)
            {
                list->item=item;
                return;
		}
        else
            list = list->link;
	}
}


void addNode_drink(drink *head,string name,int no, int item, float price) //add node for drink
{
	drink *newNode = new drink;
	newNode->name = name;
    newNode->no = no;
	newNode->item = item;
	newNode->price = price;
	newNode->link = NULL;

	drink *cur = head;
	while(cur) {
		if(cur->link == NULL) {
			cur->link = newNode;
			return;
		}
		cur = cur->link;
	}
}


void addNode2(admin *head,string name,int n,int id, int pass) //add node for admin
{
	admin *newNode = new admin;
	newNode->name = name;
	newNode->no = n;
	newNode->id = id;
	newNode->pass = pass;
	newNode->link = NULL;

	admin *cur = head;
	while(cur) {
		if(cur->link == NULL) {
			cur->link = newNode;
			return;
		}
		cur = cur->link;
	}
}


void display(food *head) //display node for food
{
	food *list = head;
	while(list) {
		cout << list->name<<endl;
		cout << list->no <<endl;
		cout << list->item<<endl;
		cout << list->price<<endl;
		cout<<endl;
		list = list->link;
	}
	cout << endl;
	cout << endl;
}


void display_drink(drink *head) //display node for food
{
	drink *list = head;
	while(list) {
		cout << list->name<<endl;
		cout << list->no <<endl;
		cout << list->item<<endl;
		cout << list->price<<endl;
		cout<<endl;
		list = list->link;
	}
	cout << endl;
	cout << endl;
}


void display2(admin *head) //display node for admin id
{
	admin *list = head;
	while(list) {
		cout << list->name<<endl;
		cout << list->no <<endl;
		cout << list->id <<endl;
		cout << list->pass <<endl;
		cout<<endl;
		list = list->link;
	}
	cout << endl;
	cout << endl;
}


int login1(admin *head) //Login Program
{
	int id;
	int pass;
	char *name;
	int i;

	system("cls");

	cout<<"\nenter your id admin: \n";
	cin>>id;

	cout<<"\nenter your password: \n";
	cin>>pass;

	if (checkadmin_id(head,id)){        //check id and pass
        if(checkadmin_pass(head,pass,id)){
        int j;
        j=giveadmin_no(head,pass);
        cout<<"\nadmin id "<<j<<endl;
        cout<<"\nadmin is true\n";
        system("pause");
        return j;
        }};

    cout<<"\n//Wrong password or id.... please try again//\n\n";  // for loop is used to create a fake loading screen.
    for (int i = 0; i < 101; i+=10) {
    cout<<"\b\b\b\b\b. %3d%%"<< i;
    Sleep(150);
    };
    login1(head);
	};


bool checkadmin_id(admin *head,int id) //check searching same admin.id
{
	admin *list = head;
	while(list) {
        if (list->id == id)
            return true;
        else
            list = list->link;
	}
	return false;
}


bool checkadmin_pass(admin *head,int pass,int id) //check searching same admin.pass
{
	admin *list = head;
	while(list) {
        if (list->id==id){
		if (list->pass == pass)
            return true;
        else
            return false;
        }
        else
            list = list->link;
	}
	return false;
}


int giveadmin_no(admin *head,int pass)  //give admin no
{
int i;
	admin *list = head;
	while(list) {
		if (list->pass == pass)
            {
            return list->no;
		}
        else
            list = list->link;
	}
	return false;

}


int exitprogram()   //to exit program
{
    system("cls");
    cout<<"Thank you for visiting us. Please come again \(^.^)/\n\n\n";
    return 0;
}


void displayadmin_info(admin *head,int no) //display  admin info
{
	admin *list = head;
	while(list) {
            if (no==list->no)
                {
                    cout << list->name<<endl;
                    cout << list->no<<endl;
                    cout << list->id<<endl;
                    cout << list->pass<<endl;
                }
		list = list->link;
	}
	cout << endl;
	cout << endl;
}


void displayadmin_name(admin *head,int no) //display  admin info
{
	admin *list = head;
	while(list) {
            if (no==list->no)
                {
                    cout << list->name;
                }
		list = list->link;
	}
}


void displayadmin_id(admin *head,int no)  //display  admin info
{
	admin *list = head;
	while(list) {
            if (no==list->no)
                {
                    cout << list->id;
                }
		list = list->link;
	}
}


void displaycustomer_food(food *head) //display node for food
{
	food *list = head;
	while(list) {
		cout << left << setw(15) << list->name;
		cout << right << setw(15) << list->no;
		cout << right << setw(15)<< list->item;
		cout << right << setw(15)<< list->price;
		cout<<endl;
		list = list->link;
	}
}

void displaycustomer_drink(drink *head) //display node for food
{
	drink *list = head;
	while(list) {
		cout << left << setw(15) << list->name;
		cout << right << setw(15) << list->no;
		cout << right << setw(15)<< list->item;
		cout << right << setw(15)<< list->price;
		cout<<endl;
		list = list->link;
	}
}


void displayfood_name(food *head,int no)  //display  admin info
{
	food *list = head;
	while(list) {
            if (no==list->no)
                {
                    cout << list->name;
                }
		list = list->link;
	}
}


void displaydrink_name(drink *head,int no)  //display  admin info
{
	drink *list = head;
	while(list) {
            if (no==list->no)
                {
                    cout << list->name;
                }
		list = list->link;
	}
}

float givefood_price(food *head,int no,int n)  //give food price
{
float p;
	food *list = head;
	while(list) {
		if (list->no == no)
            {
                p=list->price;
                p=p*n;
                return p;
		}
        else
            list = list->link;
	}
}


float givedrink_price(drink *head,int no,int n)  //give food price
{
float p;
	drink *list = head;
	while(list) {
		if (list->no == no)
            {
                p=list->price;
                p=p*n;
                return p;
		}
        else
            list = list->link;
	}
}


int givefood_item(food *head,int no)  //give food price
{
int p;
	food *list = head;
	while(list) {
		if (list->no == no)
            {
                p=list->item;
                return p;
		}
        else
            list = list->link;
	}
}


int givedrink_item(drink *head,int no)  //give food price
{
int p;
	drink *list = head;
	while(list) {
		if (list->no == no)
            {
                p=list->item;
                return p;
		}
        else
            list = list->link;
	}
}

void receiptcustomer(float price)
{   system("cls");
    string address;
    string name;
    cout<<"your name: \n";
    cin.ignore();
    getline(cin,name);
    cout<<"\nyour delivery address: ";
    cin.ignore();
    getline(cin,address);
    system("cls");
    cout<<"Welcome "<<name<<".\n\nwe will delivery to the address:\n"<<address<<"\n\n";
    cout<<"thanks for buying at Azdin ^.^\n\n";
    cout<<"total price: RM"<<price;
    cout<<"\nThank You. Please come again";
    cout<<"\nkeep the invoice for appliance returns\n\n\n";
}


int checkfood_no(food *head) //display node for food
{
    int n;
	food *list = head;
	while(list) {
		list = list->link;
		n=list->no;
		if (list->link==NULL)
            return n;
        }
}


int checkdrink_no(drink *head) //display node for food
{
    int n;
	drink *list = head;
	while(list) {
		list = list->link;
		n=list->no;
		if (list->link==NULL)
            return n;
        }
}


void fileadd_food(food *head,int n) //add node for food
{
string namewrite[n];
int nowrite[n];
int itemwrite[n];
float pricewrite[n];

int i;


food *cur = head;
	for(i=0;cur,i<n;i++) {
			namewrite[i]=cur->name;
			nowrite[i]=cur->no;
			itemwrite[i]=cur->item;
			pricewrite[i]=cur->price;
            cur = cur->link;
	}

ofstream addfile;      //create coef.txt file to save data
addfile.open("stock food.txt");
for(int i=0;i<n;i++)
        {
        addfile<<namewrite[i]<<"\t"<<nowrite[i]<<"\t"<<itemwrite[i]<<"\t"<<pricewrite[i]<<"\n";
    }
addfile.close();

}


void fileadd_foodno(int n) //add food no
{
ofstream addfile;      //create coef.txt file to save data
addfile.open("no of stock food.txt");
addfile<<n;
addfile.close();

}


void filebuy_food(food *head,int no_item ,int total ) //add node for food
{
int nostockfood;
ifstream fileread_5;
fileread_5.open("no of stock food.txt");
fileread_5>>nostockfood;
fileread_5.close();

int n=nostockfood;

string namewrite[n];
int nowrite[n];
int itemwrite[n];
float pricewrite[n];

food *cur = head;
	for(int i=0;cur,i<n;i++) {
			namewrite[i]=cur->name;
			nowrite[i]=cur->no;
			itemwrite[i]=cur->item;
			pricewrite[i]=cur->price;
            cur = cur->link;
	}

ofstream addfile;      //create coef.txt file to save data
addfile.open("stock food.txt");
for(int i=0;i<n;i++)
        {
            if(nowrite[i]==no_item)
                itemwrite[i]=itemwrite[i] - total;
        addfile<<namewrite[i]<<"\t"<<nowrite[i]<<"\t"<<itemwrite[i]<<"\t"<<pricewrite[i]<<"\n";
    }
addfile.close();

}


void minusbuy_food(food *head,int no_item ,int total )
{
int p;
	food *list = head;
	while(list) {
		if (list->no == no_item)
            {
                p=list->item;
                p=p-total;
                list->item=p;
                return;
		}
        else
            list = list->link;
	}

}


void fileadd_drinkno(int n) //add food no
{
ofstream addfile;      //create coef.txt file to save data
addfile.open("no of stock drink.txt");
addfile<<n;
addfile.close();

}

void fileadd_drink(drink *head,int n) //add node for food
{
string namewrite[n];
int nowrite[n];
int itemwrite[n];
float pricewrite[n];
int i;


drink *cur = head;
	for(i=0;cur,i<n;i++) {
			namewrite[i]=cur->name;
			nowrite[i]=cur->no;
			itemwrite[i]=cur->item;
			pricewrite[i]=cur->price;
            cur = cur->link;
	}

ofstream addfile;      //create coef.txt file to save data
addfile.open("stock drink.txt");
for(int i=0;i<n;i++)
        {
        addfile<<namewrite[i]<<"\t"<<nowrite[i]<<"\t"<<itemwrite[i]<<"\t"<<pricewrite[i]<<"\n";
    }
addfile.close();

}


void filebuy_drink(drink *head,int no_item ,int total ) //add node for food
{
int nostockdrink;

ifstream fileread_5;
fileread_5.open("no of stock drink.txt");
fileread_5>>nostockdrink;
fileread_5.close();

int n=nostockdrink;

string namewrite[n];
int nowrite[n];
int itemwrite[n];
float pricewrite[n];

drink *cur = head;
	for(int i=0;cur,i<n;i++) {
			namewrite[i]=cur->name;
			nowrite[i]=cur->no;
			itemwrite[i]=cur->item;
			pricewrite[i]=cur->price;
            cur = cur->link;
	}

ofstream addfile;      //create coef.txt file to save data
addfile.open("stock drink.txt");
for(int i=0;i<n;i++)
        {
            if(nowrite[i]==no_item)
                itemwrite[i]=itemwrite[i] - total;
        addfile<<namewrite[i]<<"\t"<<nowrite[i]<<"\t"<<itemwrite[i]<<"\t"<<pricewrite[i]<<"\n";
    }
addfile.close();

}


void minusbuy_drink(drink *head,int no_item ,int total )
{
int p;
	drink *list = head;
	while(list) {
		if (list->no == no_item)
            {
                p=list->item;
                p=p-total;
                list->item=p;
                return;
		}
        else
            list = list->link;
	}

}


int choosereplenishstock(food *head_1,drink *head_2,admin *head_3)
{
    int stock=0,x,z,no,n;
    char j;


    system("cls");
    cout<<"choose what did u want to replenish\n";
    cout<<"1.food\n2.drink\n";
    cin>>x;
    switch (x){
        case 1:
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_food(head_1);
            cout<<"\nselect no(choices) of food want to replenish\n";
            cin>>no;
            cout<<"\nhow much u want to replenish the stock ";
            displayfood_name(head_1,no);
            cout<<"\n";
            cout<<"\n1:'50'\n2: custom no\n";
            cin>>z;
            if(z==1)
            stock=50;
            else if(z==2)
            {
                cout<<"\nwrite no u want to add to stock ";
                displayfood_name(head_1,no);
                cout<<"\n";
                cin>>stock;
                stock=stock+givefood_item(head_1,no);
            }
           else
            {
                cout<<" cannot read please try again";
                goto loop;
            }
            system("cls");
            cout<<"aftereffect\n\n";
            replenishfood(head_1,no,stock);
            n=checkfood_no(head_1);
            fileadd_food(head_1,n);
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_food(head_1);
            cout<<"\nwant to replenish another stock?(y)";
            cin>>j;
            if(j=='y')
            choosereplenishstock(head_1,head_2,head_3);
            break;



        case 2:
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_drink(head_2);
            cout<<"\nselect no(choices) of drink want to replenish\n";
            cin>>no;
            cout<<"\nhow much u want to replenish the stock ";
            displaydrink_name(head_2,no);
            cout<<"\n";
            cout<<"\n1:'50'\n2: custom no\n";
            cin>>z;
            if(z==1)
            stock=50;
            else if(z==2)
            {
                cout<<"\nwrite no u want to add to stock ";
                displaydrink_name(head_2,no);
                cout<<"\n";
                cin>>stock;
                stock=stock+givedrink_item(head_2,no);
            }
           else
            {
                cout<<" cannot read please try again";
                goto loop;
            };
            system("cls");
            cout<<"aftereffect\n\n";
            replenishdrink(head_2,no,stock);
            n=checkdrink_no(head_2);
            fileadd_drink(head_2,n);
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_drink(head_2);
            cout<<"\nwant to replenish another stock?(y)";
            cin>>j;
            if(j=='y')
            choosereplenishstock(head_1,head_2,head_3);
            break;


        default:
        loop: cout<<"\ncannot read, please try again";
            choosereplenishstock(head_1,head_2,head_3);

    }
    return 0;
}

choosedeletestock(food *head_1,drink *head_2,admin *head_3)
{

    int stock=0,x,no,n;
    char j,z;


    system("cls");
    cout<<"choose what did u want to delete\n";
    cout<<"1.food\n2.drink\n";
    cin>>x;
    switch (x){
        case 1:
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_food(head_1);
            cout<<"\nselect no(choices) of food want to delete\n";
            cin>>no;
            cout<<"\nu sure want to delete stock ";
            displayfood_name(head_1,no);
            cout<<"\n";
            cout<<"\n1:if yes press 'y'\n2:if no press anything\n";
            cin>>z;
            if(z=='y'||z=='Y')
            {
                 n=checkfood_no(head_1);
                 if(no==1)
                 {
                    deletefoodinit(head_1);
                    no=checkfood_no(head_1);
                    fileadd_foodno(no);
                    fileadd_food(head_1,no);
                    cout << " deleted!\n";
                    system("cls");
                 }
                 else if(no==n)
                 {
                    deletefoodlast(head_1,n);
                    no=checkfood_no(head_1);
                    fileadd_foodno(no);
                    fileadd_food(head_1,no);
                    cout << " deleted!\n";
                 }
                 else if (no!=1 && no<n)
                 {
                    deletefoodmiddle(head_1,no);
                    reconstructfood(head_1, no);
                    no=checkfood_no(head_1);
                    fileadd_foodno(no);
                    fileadd_food(head_1,no);
                    cout << " deleted!\n";
                 }
            }
            else
            {
                goto loop;
            }
            system("cls");
            cout<<"aftereffect\n\n";
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_food(head_1);
            cout<<"\nwant to delete another stock?(y)";
            cin>>j;
            if(j=='y')
            choosedeletestock(head_1,head_2,head_3);
            break;



        case 2:
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_drink(head_2);
            cout<<"\nselect no(choices) of food want to delete\n";
            cin>>no;
            cout<<"\nu sure want to delete stock ";
            displaydrink_name(head_2,no);
            cout<<"\n";
            cout<<"\n1:if yes press 'y'\n2:if no press anything\n";
            cin>>z;
            if(z=='y'||z=='Y')
            {
                 n=checkdrink_no(head_2);
                 if(no==1)
                 {
                    deletedrinkinit(head_2);
                    no=checkdrink_no(head_2);
                    fileadd_drinkno(no);
                    fileadd_drink(head_2,no);
                    cout << " deleted!\n";
                    system("cls");
                 }
                 else if(no==n)
                 {
                    deletedrinklast(head_2,n);
                    no=checkdrink_no(head_2);
                    fileadd_drinkno(no);
                    fileadd_drink(head_2,no);
                    cout << " deleted!\n";
                 }
                 else if (no!=1 && no<n)
                 {

                    deletedrinkmiddle(head_2,no);
                    reconstructdrink(head_2, no);
                    no=checkdrink_no(head_2);
                    fileadd_drinkno(no);
                    fileadd_drink(head_2,no);
                    cout << " deleted!\n";
                 }
            }
            else
            {
                goto loop;
            }
            system("cls");
            cout<<"aftereffect\n\n";
            cout<<left<<setw(15)<<"name";
            cout<<right<<setw(15)<<"no";
            cout<<right<<setw(15)<<"item";
            cout<<right<<setw(15)<<"price";
            cout<<"\n"<< endl;
            displaycustomer_drink(head_2);
            cout<<"\nwant to delete another stock?(y)";
            cin>>j;
            if(j=='y')
            choosedeletestock(head_1,head_2,head_3);
            break;

        default:
        loop: cout<<"\ncannot read, please try again";
            choosereplenishstock(head_1,head_2,head_3);

    }
    return 0;
}





void deletefoodinit(food *head) {
    int n;
    food *cur = head;
    head->name=head->link->name;
    head->no=head->link->no;
    head->item=head->link->item;
    head->price=head->link->price;
    head->link=head->link->link;
	while(cur) {
        n=cur->no;
		n--;
		cur->no=n;
		if(cur->link == NULL) {
			return;
		}
		cur = cur->link;
	}
}


void deletefoodlast(food *head, int no)
{
    food *deletelastnode;
    food *cur = head;
	while(cur) {

		if(cur->link->link == NULL) {
                 deletelastnode=cur;
                 deletelastnode=deletelastnode->link;
                cur->link=NULL;
                delete deletelastnode;
		}
		cur = cur->link;
	}
}

 void deletefoodmiddle(food *head,int no)
 {
    food *middle = head;
    food *temp = head;
    temp=temp->link;
	while(middle) {
		if(temp->no == no)
            {
               middle->link=temp->link;
               temp->link=NULL;
               delete temp;
                return;
            }
                middle = middle->link;
                if(temp!=NULL)
                temp = temp->link;
            }
 }

void reconstructfood(food *head,int no)

 {
     int p;
     food *middle = head;
     while(middle){
        if (middle->no > no)
        {
                    p=middle->no;
                    p=p-1;
                    middle->no=p;
        }
        middle = middle->link;
     }

 }



 void deletedrinkinit(drink *head) {
    int n;
    drink *cur = head;
    head->name=head->link->name;
    head->no=head->link->no;
    head->item=head->link->item;
    head->price=head->link->price;
    head->link=head->link->link;
	while(cur) {
        n=cur->no;
		n--;
		cur->no=n;
		if(cur->link == NULL) {
			return;
		}
		cur = cur->link;
	}
}


void deletedrinklast(drink *head, int no)
{
    drink *deletelastnode;
    drink *cur = head;
	while(cur) {

		if(cur->link->link == NULL) {
                 deletelastnode=cur;
                 deletelastnode=deletelastnode->link;
                cur->link=NULL;
                delete deletelastnode;
		}
		cur = cur->link;
	}
}

 void deletedrinkmiddle(drink *head,int no)
 {
    drink *middle = head;
    drink *temp = head;
    temp=temp->link;
	while(middle) {
		if(temp->no == no)
            {
               middle->link=temp->link;
               temp->link=NULL;
               delete temp;
                return;
            }
                middle = middle->link;
                if(temp!=NULL)
                temp = temp->link;
            }
 }

void reconstructdrink(drink *head,int no)

 {
     int p;
     drink *middle = head;
     while(middle){
        if (middle->no > no)
        {
                    p=middle->no;
                    p=p-1;
                    middle->no=p;
        }
        middle = middle->link;
     }

 }
