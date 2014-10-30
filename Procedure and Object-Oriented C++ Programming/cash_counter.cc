# include <iostream.h>
# include <conio.h>
# include <fstream.h>
# include <iomanip.h>
# include <stdio.h>
# include <process.h>
# include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Stockdata
{
 int qty,rate,code;
 public:
 char name [20];
  void input()
  {
    SetConsoleTextAttribute(hConsole, 14);
    cout<< "\n Enter code : ";
    cin>>code;
    cout<<"\n Enter name : ";
    cin>> name ;
    cout<< "\n Enter quantity : " ;
    cin>>qty ;
    cout<< "\n Enter rate : " ;
    cin>>rate ;cout<<endl<<endl;
  }

  void output()
  {
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"\n "<<setw(5)<< code ;
    cout<<setw(28)<< name ;
    cout<<setw(13)<< qty ;
    cout<<setw(12)<< rate ;
  }

  void qtymod(int t)
  {
    qty=qty-t;
  }

  int retcode()
  {
  return code;
  }

  int retrate()
  {
   return rate;
  }

  int retqty()
  {
   return qty;
  }

}Stock;

class Billdata:public Stockdata
{
 int code,qty,price;
 public:
 char name[20];
 void output(int x)
 {
  cout<<endl<<"   "<<x<<setw(11)<<code;
  cout<<setw(25)<<name<<setw(14);
  cout<<qty<<setw(11)<<price;
  cout<<endl;
  }

 void input(int a,int c)
 {
   SetConsoleTextAttribute(hConsole, 10);
   code=c ;
   cout<< "\n Enter quantity : " ;
   cin>> qty ;
   price=qty*a;
}
}Bill;

void bildisplay()
{
 int x=0;
 ifstream bil("bill.dat",ios::binary);
 SetConsoleTextAttribute(hConsole, 12);
 cout<<"\n                  <<__________CUSTOMER BILL___________>>";
 cout<<"\n                                   << ************* >> "<<endl;
 SetConsoleTextAttribute(hConsole, 1);
 cout<<"\n __________________________________________________________________";
 cout<<"\n SL.NO.   ITEM_CODE\t\tITEM_NAME \t QUANTITY    PRICE";
 cout<<"\n
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~";

 SetConsoleTextAttribute(hConsole, 7);

 while(bil.read((char*)&Bill,sizeof(Bill)))
 {
 x+=1;
 Bill.output(x);}
 cout<<"\n\n Press any key to continue....";
 getch();bil.close();
 clrscr();
}

void createbill()
{
 int tempcode,ans=1;
 ofstream bil("bill.dat",ios::binary);
 while(ans==1)
 {
  cout<<"\n Enter the itemcode :";
  cin>>tempcode;
  int flag=0;
  fstream stck("stock.dat",ios::binary|ios::in|ios::
out);
while(stck.read((char*)&Stock,sizeof(Stock)))
   if(Stock.retcode()==tempcode)
   {
    flag++;
    Bill.input(Stock.retrate(),Stock.retcode());
    strcpy(Bill.name,Stock.name);
    bil.write((char*)&Bill,sizeof(Bill));
   }

  if(flag==0)
  cout<<"\n Itemcode invalid!";
  stck.close();
  cout<<"\n Enter 1 to add new item or 0 to
finalise bill....";
  cin>>ans;
}

 bil.close();
 cout<<"\n Press any key to generate bill...";
 getch();clrscr();
 bildisplay();
}

void display()
{
 ifstream fob("stock.dat",ios::binary);
 cout<<endl<<endl;
 cout<<"\n ITEM_CODE \t\t ITEM_NAME \t QUANTITY \tRATE";
 cout<<"\n
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~";

while(fob.read((char*)&Stock,sizeof(Stock)))
 {
  Stock.output();
  cout<<endl;
 }

 getch();
 fob.close();
}

void del()
{
 int tempcode;
 cout<<"Enter the code of the item to be deleted
:";
 cin>>tempcode;
 ifstream fob("stock.dat",ios::binary);
 ofstream tob("temp.dat",ios::binary);
 while(fob.read((char*)&Stock,sizeof(Stock)))
 {
 if(Stock.retcode()!=tempcode)
 tob.write((char*)&Stock,sizeof(Stock));
 }
 fob.close();
 tob.close();
 remove("stock.dat");
 rename("temp.dat","stock.dat");
}

void modify()
{
 int tempcode;
 cout<<"\n Enter the code of item to be modified
:";
 cin>>tempcode;
 fstream fob("stock.dat",ios::binary|ios::in|ios::
out);
 while(fob.read((char*)&Stock,sizeof(Stock)))
 {
  if(Stock.retcode()==tempcode)
  Stock.input();
  fob.write((char*)&Stock,sizeof(Stock));
void add(int n)
}

{ofstream fob("stock.dat",ios::binary|ios::
app);

}

for(int i=0;i<n;i++)
 {
  Stock.input();
  fob.write((char*)&Stock,sizeof(Stock));
 }
 fob.close();
}

void main()
{
 remove("bill.dat");
 int reply=1,option;
 do
 {
  SetConsoleTextAttribute(hConsole, 76);
  cout<<endl<<"           |_______Supermarket Billing
Database________| ";
 cout<<endl<<"                            ****************************** ";
 cout<<endl<<endl<<endl;
 SetConsoleTextAttribute(hConsole, 10);
 cout << "MAIN MENU"<<endl;
 cout << "~~~~~~~~~"<<endl<<endl;
 cout << "1. ITEM DIRECTORY" ;
 cout<<endl<<endl;
 cout << "2. CREATE BILL";
 cout<<endl<<endl;
 cout << "3. EXIT" <<endl;
 cout<<"ENTER OPTION SL.NO.===>";
 cin>>option;
switch (option)
 {
   case 2 :{clrscr();
   cout<<endl<<"         |_______Supermarket Billing
Database________|";

  case 1 :{clrscr();

          <<endl;

     (hConsole, 2);
    cout<<"\n                  ________SUPERMARKET
STOCKDATABASE________";

13);

STOCKDATABASE________";

>";

   cout<<"\n           ________SUPERMARKET
STOCKDATABASE________";

RECORDS--->";

    cout<<"\n\n Enter the number of records to be added :";
    case 1 :{clrscr();
    <<endl;

(hConsole, 2);

                    cout<<"\n                  ________SUPERMARKET
STOCKDATABASE________";

13);

STOCKDATABASE________";

>";

                    cout<<"\n           ________SUPERMARKET
STOCKDATABASE________";

RECORDS--->";

                    cout<<"\n\n Enter the number of records to be added :";

        case 4: {cout<<"\n          ________SUPERMARKET
STOCKDATABASE________";

~~~~~~~~~~~~~~~~~~~~~~~~~";

       }

      break;

    }

    case 3 :{getch();exit(0);}

  }

 cout<<"\n\n Press 1 to return to main menu....";

 cin>>reply;

 }while(reply==1);

 clrscr();

 cout<<"\n\n Press any key to exit....";

 getch();

}
