#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>


using namespace std;


class Lib
{
   public:
       char bookname[100],auname[50],bookId[20],publisher[50];
       int q,B,p;  //quantity, branch, price

       Lib()
       {
           strcpy(bookname,"NO Book Name");
           strcpy(auname,"No Author Name");
           strcpy(bookId,"No Book ID");
           strcpy(publisher,"No Book ID");
           q=0;
           B=0;
           p=0;
       }

          void main_menu();  //main page
          void student_menu(); //student menu
          void pass_verify(); //password verification
          void librarian(); //librarian menu
          void admin(); //admin menu
          void pass_verify1(); //admin password
          void change_password();  //change password
          void getdata();  //book information
          void show(int);  //display books
          void booklist(int); //list of books for branch returned as i by branch
          void modify();  //add, modify
          void book_search(int);  //search
          int branch(int);  //return integer as branch identifier
          void issue();  //issue book
          void book_verify(char[],int,int);  //verifying if such a book is present
          void fine(int,int,int,int,int,int);  //fine calculation
};

void Lib::getdata()   //enter data of class members
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details...\n";
                    cout<<"\n\t\tBook's Name : ";
                    cin.getline(bookname,100);
                    for(i=0;bookname[i]!='\0';i++)
                    {
                    if(bookname[i]>='a'&&bookname[i]<='z')
                       bookname[i]-=32;
                    }
                    cout<<"\n\t\tAuthor's Name : ";
                    cin.getline(auname,50);
                    cout<<"\n\t\tPublication name : ";
                    cin.getline(publisher,50);
                    cout<<"\n\t\tBook's ID : ";
                    cin.getline(bookId,20);
                    cout<<"\n\t\tBook's Price : ";
                    cin>>p;
                    cout<<"\n\t\tBook's Quantity : ";
                    cin>>q;
}

void Lib::show(int i)  //display books
{
    cout<<"\n\t\tBook's Name : "<<bookname<<endl;
    cout<<"\n\t\tBook's Author : "<<auname<<endl;
    cout<<"\n\t\tBook's ID : "<<bookId<<endl;
    cout<<"\n\t\tBook's Publication : "<<publisher<<endl;
    cout<<"\n\t\tBook's Quantity : "<<q<<endl;
    if(i==2)
    {
        cout<<"\n\t\tBook's Price : "<<p<<endl;

    }
}
  void Lib::booklist(int i)  //list of books for branch i
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t-----------------------------------------------\n";
                    cout<<"\n\t-----------------------------------------------\n";
                    cout<<"\n\t                 BOOK LIST                     \n";
                    cout<<"\n\t-----------------------------------------------\n";
                    cout<<"\n\t-----------------------------------------------\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }intf.close();
                }

                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student_menu();
                else if(i==2)
                    librarian();
                else
                    admin();
    }
  void Lib::modify()  // book add, delete, modify
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t            MODIFICATION MENU                  \n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t\t1.Modification In an Existing Book\n\n\t\t2.Add a New Book\n\n\t\t3.Go back\n";
    cout<<"\n\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(3);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        admin();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\t1.Search By Book Name\n\n\t\t2.Search By Book's ID\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book's Name : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);
                                        if(bookname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookId[i]!='\0'&&st1[i]!='\0'&&st1[i]==bookId[i];i++);
                                        if(bookId[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tUpdate Successful.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(3);
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tBook added Successfully!!!\n";
    }

    else if(i==3)
    {
    system("cls");
    admin();
    }
    else
    {
    cout<<"\n\t\tWrong Input.\n";
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    admin();

  }

  int Lib::branch(int x)  //get branch --- parameter is who is called by (student or librarian) in order to return there
  {
      int i;
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t             BRANCH SELECTION                  \n";
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t\t1.CSE\n\n\t\t2.EE\n\n\t\t3.EC\n\n\t\t4.CIVIL\n\n\t\t5.MECHANICAL\n\n\t\t6.CHEMICAL\n\n\t\t7.APPLIED STUDIES\n\n\t\t8.Go to menu\n";
      cout<<"\n\t\tEnter youur choice : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: return 7;
                  break;
          case 8: system("cls");
                  if(x==1)
                  student_menu();
                  else if(x==2)
                    librarian();
                  else
                    admin();
          default : cout<<"\n\t\tPlease enter correct option....";
                    getch();
                    system("cls");
                    branch(x);
        }
  }

  void Lib::book_search(int x)   //search book
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student_menu();
            else if(x==2)
            librarian();
            else
                admin();
        }

      system("cls");
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t                SEARCH MENU                    \n";
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t-----------------------------------------------\n";
      cout<<"\n\t\t1.Search By Book's Name\n\n\t\t2.Search By Book's ID\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&bookname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bookname[i]||ch[i]==bookname[i]+32);i++);
            if(bookname[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }

      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&bookId[i]!='\0'&&ch[i]!='\0'&&ch[i]==bookId[i];i++);
              if(bookId[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option...";
             getch();
             system("cls");
             book_search(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available... \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student_menu();
    else if (x==2)
    librarian();
    else
        admin();


  }

void Lib::issue()   //issue book
{
    char st[50],st1[20],st2[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t            BOOK ISSUE CORNER                  \n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who issued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(st,100);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    book_verify(st1,b,1);
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(auname,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(st2,20);
        ifstream intf("student.txt",ios::binary);  //to check if books issued>3 or not
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              if(strcmp(publisher,st2)==0)
              {
                  cont++;
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
       // strcpy(publisher,st1);
        if(cont>=3)
        {
             cout<<"\n\t\tBook Issue Limit Exceeded..\n";
             cout<<"\n\t\tStudent : "<<st2<<" : Can't Issue Any Books As Of Now";
             cout<<"\n\t\tPress Any Key to Continue";
             getch();
             system("cls");
             librarian();
        }
        strcpy(publisher,st2);


        cout<<"\n\t\tEnter date : day : ";
        cin>>q;
        cout<<"\n\t\tmonth : ";
        cin>>B;
        cout<<"\n\t\tyear : ";
        cin>>p;
        ofstream outf("student.txt",ios::binary|ios::app);
        outf.write((char*)this,sizeof(*this));
        outf.close();
        cout<<"\n\n\t\tIssue Successfully.\n";
    }


    else if(i==2)
    {
    ifstream intf("student.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->The Details are :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\t"<<"Student's ID : "<<publisher<<"\n\t\t"<<"Book Name : "<<bookname<<"\n\t\t"<<"Book's ID : "<<bookId<<"\n\t\t"<<"Date : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\n\t\tEnter Student Name : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tEnter Student's ID : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("student.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              if(strcmp(publisher,st1)==0)
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->The Details are :-\n";
                      cout<<"\n\t\tStudent Name : "<<auname;
                      cout<<"\n\t\tStudent's ID : "<<publisher;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
                  cout<<"\n\t\tBook Name : "<<bookname;
                  cout<<"\n\t\tBook's ID : "<<bookId;
                  cout<<"\n\t\tDate : "<<q<<"/"<<B<<"/"<<p<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tNo record found.";
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,50);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    fstream intf("student.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            if(strcmp(bookId,st1)==0&&strcmp(publisher,st)==0)
                {
                    d=q;
                    m=B;
                    y=p;
                    cout<<"\n\t\tEnter New Date : ";
                    cin>>q>>B>>p;
                    fine(d,m,y,q,B,p); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tReissue successfully."; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==5)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    book_verify(st1,b,2);
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,20);
    cout<<"\n\t\tEnter Present date : ";
    cout<<"\n\t\tEnter date : day : ";
    cin>>d;
    cout<<"\n\t\tmonth : ";
    cin>>m;
    cout<<"\n\t\tyear : ";
    cin>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("student.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {

            if(strcmp(bookId,st1)==0&&strcmp(publisher,st)==0&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    fine(q,B,p,d,m,y);
                    cout<<"\n\t\tReturned successfully.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("student.txt");
    rename("temp.txt","student.txt");
    }
    else if(i==6)
    {
    system("cls");
    librarian();
    }
    else
        cout<<"\n\t\tWrong Input.\n";

    cout<<"\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();
}

void Lib::fine(int d,int m,int y,int dd,int mm,int yy)   //calculation of fine
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tThe Total Fine is : "<<n2;

}

void Lib::book_verify(char st[],int b,int x) //verify if book exists
{
    int i,cont=0,flag=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        if(b==B && strcmp(bookId,st)==0)
        {
            if(q==0)
            {
                flag=1;
                break;
            }
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        if(flag==1)
            cout<<"\n\t\t NO BOOKS REMAINING OF THE GIVEN DETAILS!!\n";
        else
            cout<<"\n\t\tBook not found.\n";
        cout<<"\n\n\t\tPress any key to continue.....";
        intf.close();
        getch();
        system("cls");
        issue();
    }
    intf.close();
}

void Lib::main_menu()  //main page
{
   int i;
        cout<<"\n\t-------------------------------------------------\n";
        cout<<"\n\t-------------------------------------------------\n";
        cout<<"\n\t     WELCOME TO IIIT SURAT'S LIBRARY PORTAL      \n";
        cout<<"\n\t-------------------------------------------------\n";
        cout<<"\n\t-------------------------------------------------\n\n";
        cout<<"\n\t\t1.STUDENT'S CORNER\n\n\t\t2.LIBRARIAN DESK\n\n\t\t3.ADMINISTRATOR DESK\n\n\t\t4.ABOUT\n\n\t\t5.CLOSE APPLICATION\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student_menu();
        }
        else if(i==2)
            pass_verify();

        else if(i==3)
            pass_verify1();

        else if(i==4)
        {
            system("cls");
            cout<<"\n\n\t************ABOUT THE DEVELOPER***************\n\n";
            cout<<"\n\t-------------------------------------------------\n";
            cout<<"\n\n\t\t DEVELOPED BY SHRUTIK TALAWAT\n";
            cout<<"\n\n\t\t\t---- B.TECH-2, SEMESTER-4\n";
            cout<<"\n\n\t\t\t---- SHRUTIKTALAWAT@GMAIL.COM \n";
            cout<<"\n\n\t\t\t---- UI17CO02\n";
            cout<<"\n\t-------------------------------------------------\n";
            cout<<"\n\t-------------------------------------------------\n";
            cout<<"\n\n\t************ABOUT THE APPLICATION***************\n\n";
            cout<<"\n\t-------------------------------------------------\n";
            cout<<"\n\n\t\t NAME : IIIT SURAT'S LIBRARY PORTAL\n";
            cout<<"\n\n\t\t LANGUAGE : C++\n";
            cout<<"\n\n\t\t ENVIRONMENT : CODE::BLOCKS(17.12)\n";
            cout<<"\n\n\t\t COMPILER : MINGW-W64\n";
            cout<<"\n\n\t\t OPERATING SYSTEM : WINDOWS 10(64 BIT)\n";
            cout<<"\n\t-------------------------------------------------\n";
            cout<<"\n\n\t\t PRESS ANY KEY TO CONTINUE\n";
            getch();
            system("cls");
            main_menu();
        }

        else if(i==5)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option....";
            cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE";
            getch();
            system("CLS");
           main_menu();
        }
}

void Lib::student_menu()   //student menu
{
    int i,cont;
    char st[50],st1[50];
        cout<<"\n\t-----------------------------------------\n";
        cout<<"\n\t-----------------------------------------\n";
        cout<<"\n\t             WELCOME STUDENT             \n";
        cout<<"\n\t-----------------------------------------\n";
        cout<<"\n\t-----------------------------------------\n";
        cout<<"\n\t\t1.List of Books\n\n\t\t2.Search a Book\n\n\t\t3.Search Your Record\n\n\t\t4.Go to Main Menu\n\n\t\t5.Close Application\n";
        cout<<"\n\t\tPlease Enter a Choice : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                book_search(1);
            else if(i==3)
            {
                system("cls");
                fflush(stdin);
                cout<<"\n\t\t->Please Enter Details :-\n";
                cout<<"\n\n\t\tEnter Student Name : ";
                cin.getline(st,50);
                cout<<"\n\n\t\tEnter Student's ID : ";
                cin.getline(st1,20);
                system("cls");
                ifstream intf("student.txt",ios::binary);
                intf.read((char*)this,sizeof(*this));
                cont=0;
                while(!intf.eof())
                {
                    if(strcmp(publisher,st1)==0)
                {
                        cont++;
                        if(cont==1)
                        {
                            cout<<"\n\t\t->The Details are :-\n";
                            cout<<"\n\t\tStudent Name : "<<auname;
                            cout<<"\n\t\tStudent's ID : "<<publisher;
                        }
                        cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
                        cout<<"\n\t\tBook Name : "<<bookname;
                        cout<<"\n\t\tBook's ID : "<<bookId;
                        cout<<"\n\t\tDate : "<<q<<"/"<<B<<"/"<<p<<"\n";
                }
                    intf.read((char*)this,sizeof(*this));

                }
                intf.close();
                if(cont==0)
                cout<<"\n\t\tNo Book found.";
                cout<<"\n\t\tPress any key to continue";
                getch();
                system("cls");
                student_menu();
            }

            else if(i==4)
            {
                system("cls");
                main_menu();
            }
            else if(i==5)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option\n ";
                cout<<"\n\t\tPRESS ANY KEY TO CONTINUE";
                getch();
                system("cls");
                student_menu();
            }
}

void Lib::pass_verify1()  //admin password
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)//carrige return
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)//backspace
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password1.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        admin();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
        getch();
        system("cls");
        main_menu();
    }
}

void Lib::pass_verify()  //librarian password
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)//carrige return
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)//backspace
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
        getch();
        system("cls");
        main_menu();
    }
}

void Lib::librarian()  //librarian menu
{
    int i;
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t            WELCOME LIBRARIAN                  \n";
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t\t1.List of Books\n\n\t\t2.Search a Book\n\n\t\t3.Book Issue Corner\n\n\t\t4.Logout\n\n\t\t5.Change My Password\n\n\t\t6.Logout And Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:book_search(2);
                     break;
            case 3:issue();
                     break;
            case 4:system("cls");
                     main_menu();
                     break;
            case 5:change_password();
                    break;
            case 6:exit(0);
            default:cout<<"\n\t\t***Please enter correct option ***";
                    cout<<"\n\t\tPRESS ANY KEY TO CONTINUE";
            getch();
            system("cls");
            librarian();
        }
}

void Lib::admin()  //adminn menu
{
    int i;
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t           WELCOME ADMININISTRATOR             \n";
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t-----------------------------------------------\n";
        cout<<"\n\t\t1.List of Books\n\n\t\t2.Search a Book\n\n\t\t3.Modification Corner\n\n\t\t4.Logout\n\n\t\t5.Logout And Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(3);
                     break;
            case 2:book_search(3);
                     break;
            case 3:modify();
                     break;
            case 4:system("cls");
                     main_menu();
                     break;
            case 5:exit(0);
            default:cout<<"\n\t\t***Please enter correct option ***";
                    cout<<"\n\t\tPRESS ANY KEY TO CONTINUE";
            getch();
            system("cls");
            admin();
        }
}

void Lib::change_password()  //change password
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t            EDIT LOG IN DETAILS                \n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\n\n\t\tEnter Old Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
        cout<<"\n\t\tEnter New Password : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tYou didn't follow the instruction \n\n\t\tPress any key to try again.....";
                getch();
                system("cls");
                change_password();
                librarian();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        getch();
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n";
        cout<<"\n\t\tEnter 1 for retry or 2 for menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        change_password();
        }
        else
        {
            system("cls");
            librarian();
        }
    }
}

int main()  //main function
{
    system("color f0");
    Lib obj;
    obj.main_menu(); //go to main menu
    getch();
    return 0;
}
