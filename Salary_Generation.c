#include <stdio.h>      //set of header files
#include <conio.h>
#include <windows.h>
#include<time.h>
void mainmenu();        //set of functions
void printing();
void finishing();
void qulity();
void hrdivision();
void security();
void engineering();

void password();    //for password option
void update();      //you can input data to basic salary file using this function
void returnfunc();  //for return previous department from payslip
int t();            //function for out put time
void getdata();         //to get employee data

float basic(int);       //function to get basic salary from file basic_salary.txt
float ot1(float);       //calculate week days ot
float ot2(float);       //calculate weekend days ot
float epf1(float);      //calculate 8% of EPF
float epf2(float);      //calculate 12% 0f EPF
float etf1(float);      //caculate 3% of ETF
float shifI();      //shift allowances
float shifII();
float shifIII();

void pay(float t[]);  //payslip with additional ot,union fee etc (workers)
void pay1(float s[]); //payslip without additional ot,union fee etc (company mangers)

int dept;       //to store selected department no and use it in return function
int i;      //use in ot and ot1 functions for get ot value from files
char*des;       //to store job post that selected by user

COORD coord = {0, 0}; // sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
struct emp  //input employee data
{
    char id[5];
    char epf[5];
    char name[20];
    char nic[10];

};
struct emp a;

int main()
{system("cls");
   int j;char code[35]={" G&D Currency & Security (Pvt) Ltd "};
    gotoxy(7,4);
    for(j=0;j<15;j++)
    {
    delay(50);
    printf("\xB2");
    }
    for(j=0;j<35;j++)
    {
        delay(50);
        printf("%c",code[j]);
    }
   for(j=0;j<15;j++)
   {
   delay(50);
   printf("\xB2");
   }
    gotoxy(17,10);
	printf("Press any key to countinue.....");
	getch();
    mainmenu();     //main function start to execute by calling mainmenu,sub function
    getch();
    return 0;
}
void mainmenu() //function for mainmenu(you should access other department using this function)
{
    system("cls");
    int opt;     //variable to get user opttion
    gotoxy(10,2);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 G&D Currency & Security (Pvt) Ltd. \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(22,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30,7);
    printf("\xDB\xDB\xDB\xB2 (1)Printing Department");
    gotoxy(30,9);
    printf("\xDB\xDB\xDB\xB2 (2)Finishing Department");
    gotoxy(30,11);
    printf("\xDB\xDB\xDB\xB2 (3)Qulity Department");
    gotoxy(30,13);
    printf("\xDB\xDB\xDB\xB2 (4)H.R. Division");
    gotoxy(30,15);
    printf("\xDB\xDB\xDB\xB2 (5)Security Department");
    gotoxy(30,17);
    printf("\xDB\xDB\xDB\xB2 (6)Enginnering Department");
    gotoxy(30,19);
    printf("\xDB\xDB\xDB\xB2 (7)System Update");
    gotoxy(30,21);
    printf("\xDB\xDB\xDB\xB2 (8)Exit");
     gotoxy(5,23);
     t();
gotoxy(55,23);
printf("Enter your option");
scanf("%d",&opt);
dept=opt;
if(opt!=8)
{
    switch(opt)
{
    case 1:printing();break;        //function calls for all sub department functions
    case 2:finishing();break;
    case 3:qulity();break;
    case 4:hrdivision();break;
    case 5:security();break;
    case 6:engineering();break;
    case 7:password();break;
    default:printf(" INVALID OPTION");
            getch();
            system("cls");
            mainmenu();
}
}
system("cls");
gotoxy(25,2);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 programmers \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(5,4);
printf("1.Sashane Mihiranga Hevavitharana (GROUP LEADER)");gotoxy(55,4);
printf("DCSD\tDO153");
gotoxy(5,6);
printf("2.Malindu Dilshan");gotoxy(55,6);
printf("DCSD\tDO153");
gotoxy(5,8);
printf("3.Isuru Devinda");gotoxy(55,8);
printf("DCSD\tDO153");
gotoxy(5,10);
printf("4.Ishara prasanna");gotoxy(55,10);
printf("DCN\tDO153");
gotoxy(5,12);
printf("5.Indika");gotoxy(55,12);
printf("DCN\tDO153");
gotoxy(20,14);
printf("THANK YOU!!");
}
void printing() //printing department display all job posts
{
system("cls");
gotoxy(20,2);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Printing Department \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(27,4);
printf("\xB2\xB2\xB2\xB2 1.Print Manager");
gotoxy(27,6);
printf("\xB2\xB2\xB2\xB2 2.Print Supervisor");
gotoxy(27,8);
printf("\xB2\xB2\xB2\xB2 3.Printer 1");
gotoxy(27,10);
printf("\xB2\xB2\xB2\xB2 4.Printer 2");
gotoxy(27,12);
printf("\xB2\xB2\xB2\xB2 5.Print Assisten");
gotoxy(27,14);
printf("\xB2\xB2\xB2\xB2 6.Print Poarter");
gotoxy(27,16);
printf("\xB2\xB2\xB2\xB2 7.Back to main menu");
int opt;float s[4],t[9];
printf("\n\tEnter the job post");
scanf("%d",&opt);
s[0]=basic(opt-1);
t[0]=basic(opt-1);
if(opt!=7)
{
switch(opt)
{
case 1:     //you can genarate paysheet for puticular job post when you execte each cases
    des="PRINT MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 2:
    des="PRINT SUPERVISOR";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 3:
    i=0;
    des="PRINTER 1";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 4:
    i=1;
    des="PRINTER 2";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 5:
    i=2;
    des="PRINT ASSISTEN";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 6:
    i=3;
    des="PRINT POARTER";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
default:
    printf(" INVALID OPTION");
    getch();
    printing();
}
}
else
{
    mainmenu();
}
}
void finishing()       //finishing department display all job posts
{
system("cls");
gotoxy(20,2);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Finishing Department \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(27,4);
printf("\xB2\xB2\xB2\xB2 1.Finishing Manager");
gotoxy(27,6);
printf("\xB2\xB2\xB2\xB2 2.Finishing Supervisor");
gotoxy(27,8);
printf("\xB2\xB2\xB2\xB2 3.Leadhand ");
gotoxy(27,10);
printf("\xB2\xB2\xB2\xB2 4.Finishing Operator");
gotoxy(27,12);
printf("\xB2\xB2\xB2\xB2 5.back to main menu");
int opt;float s[4],t[9];
printf("\n\tEnter the job post");
scanf("%d",&opt);
s[0]=basic(opt+5);
t[0]=basic(opt+5);
if(opt!=5)
{
switch(opt)
{
case 1:     //you can genarate paysheet for puticular job post when you exeecte each cases
    des="FINISHING MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 2:
    des="FINISHING SUPERVISOR";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 3:
    i=4;
    des="LEADHAND";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 4:
    i=5;
    des="FINISHING OPERATOR";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
default:
    printf(" INVALID OPTION");
    getch();
    finishing();

}
}
else
{
    mainmenu();
}
}
void qulity()       //qulity department display all job posts
{
system("cls");
gotoxy(20,2);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Qulity Department \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(27,4);
printf("\xB2\xB2\xB2\xB2 1.Qulity Manager");
gotoxy(27,6);
printf("\xB2\xB2\xB2\xB2 2.Qulity Supervisor");
gotoxy(27,8);
printf("\xB2\xB2\xB2\xB2 3.Seniar Qulity");
gotoxy(27,10);
printf("\xB2\xB2\xB2\xB2 4.QI");
gotoxy(27,12);
printf("\xB2\xB2\xB2\xB2 5.back to main menu");
int opt;float s[4],t[9];
printf("\n\tEnter the job post");
scanf("%d",&opt);
s[0]=basic(opt+9);
t[0]=basic(opt+9);
if(opt!=5)
{
switch(opt)
{
case 1:     //you can genarate paysheet for puticular job post when you exeecte each cases
    des="QULITY MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 2:
    des="QULITY SUPERVISOR";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 3:
    i=6;
    des="SENIAR QULITY";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 4:
    i=7;
    des="QI";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
default:
    printf(" INVALID OPTION");
    getch();
    qulity();
}
}
else
{
    mainmenu();
}
}
void hrdivision()          //H.R. division display all job posts
{

system("cls");
gotoxy(20,2);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 H.R.Division \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(27,4);
printf("\xB2\xB2\xB2\xB2 1.Genaral Manager");
gotoxy(27,6);
printf("\xB2\xB2\xB2\xB2 2.Factory Manager");
gotoxy(27,8);
printf("\xB2\xB2\xB2\xB2 3.H.R.Manger");
gotoxy(27,10);
printf("\xB2\xB2\xB2\xB2 4.Finans Manager");
gotoxy(27,12);
printf("\xB2\xB2\xB2\xB2 5.Accountan");
gotoxy(27,14);
printf("\xB2\xB2\xB2\xB2 6.IT technisian");
gotoxy(27,16);
printf("\xB2\xB2\xB2\xB2 7.Cleark");
gotoxy(27,18);
printf("\xB2\xB2\xB2\xB2 8.back to main menu");
int opt;float s[4],t[9];
printf("\n\tEnter the job post");
scanf("%d",&opt);
s[0]=basic(opt+13);
t[0]=basic(opt+13);
if(opt!=8)
{
switch(opt)
{
case 1:     //you can genarate paysheet for puticular job post when you exeecte each cases
    des="GENARAL MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 2:
    des="FACTORY MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 3:
    des="H.R.MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 4:
    des="FINANS MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 5:
    i=8;
    des="ACCOUNTAN";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 6:
    i=9;
    des="IT TECHNICIAN";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 7:
    i=10;
    des="CLEARK";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
default:
    printf(" INVALID OPTION");
    getch();
    hrdivision();
}
}
else
{
    mainmenu();
}
}
void security()     //security department display all job posts
{

system("cls");
gotoxy(20,2);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Security Department \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(27,4);
printf("\xB2\xB2\xB2\xB2 1.Security Manager");
gotoxy(27,6);
printf("\xB2\xB2\xB2\xB2 2.Security Supervisor");
gotoxy(27,8);
printf("\xB2\xB2\xB2\xB2 3.Shift Controller");
gotoxy(27,10);
printf("\xB2\xB2\xB2\xB2 4.Seniar Security");
gotoxy(27,12);
printf("\xB2\xB2\xB2\xB2 5.Juniar Security");
gotoxy(27,14);
printf("\xB2\xB2\xB2\xB2 6.back to main menu");
int opt;float s[4],t[9];
printf("\n\tEnter the job post");
scanf("%d",&opt);
s[0]=basic(opt+20);
t[0]=basic(opt+20);
if(opt!=6)
{
switch(opt)
{
case 1:     //you can genarate paysheet for puticular job post when you exeecte each cases
    des="SECURITY MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 2:
    des="SECURITY SUPERVISOR";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 3:
    i=11;
    des="SHIFT CONTROLLER";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 4:
    i=12;
    des="SENIAR SECURITY";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 5:
    i=13;
    des="JUNIAR SECURITY";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
default:
    printf(" INVALID OPTION");
    getch();
    security();
}
}
else
{
    mainmenu();
}
}
void engineering()      //engineering department display all job posts
{

system("cls");
gotoxy(20,2);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Engineering Department \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(27,4);
printf("\xB2\xB2\xB2\xB2 1.Enginnering Manager");
gotoxy(27,6);
printf("\xB2\xB2\xB2\xB2 2.Enginnering Supervisor");
gotoxy(27,8);
printf("\xB2\xB2\xB2\xB2 3.Enginner");
gotoxy(27,10);
printf("\xB2\xB2\xB2\xB2 4.Labour");
gotoxy(27,12);
printf("\xB2\xB2\xB2\xB2 5.back to main menu");
int opt;float s[4],t[9];
printf("\n\tEnter the job post");
scanf("%d",&opt);
s[0]=basic(opt+25);
t[0]=basic(opt+25);
if(opt!=5)
{
switch(opt)
{
case 1:     //you can genarate paysheet for puticular job post when you exeecte each cases
    des="ENGINNERING MANAGER";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 2:
    des="ENGINNERING SUPERVISOR";
    s[1]=epf1(s[0]);
    s[2]=epf2(s[0]);
    s[3]=etf1(s[0]);
    pay1(s);break;
case 3:
    i=14;
    des="ENGINNER";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
case 4:
    i=15;
    des="LABOUR";
    t[1]=ot1(t[0]);
    t[2]=ot2(t[0]);
    t[3]=epf1(t[0]);
    t[4]=epf2(t[0]);
    t[5]=etf1(t[0]);
    t[6]=shifI();
    t[7]=shifII();
    t[8]=shifIII();
    pay(t);break;
default:
    printf(" INVALID OPTION");
    getch();
    engineering();
}
}
else
{
    mainmenu();
}
}
void getdata()      //to input employee data
{
    system("cls");
    gotoxy(10,2);printf("Enter the Employee Information Below,job post [%s]",des);
    gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(46,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(46,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(46,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(46,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(46,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(46,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(46,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,6);
	printf(" EMP ID:");
	gotoxy(30,6);
	scanf("%s",a.id);
	gotoxy(21,7);
	printf(" EPF NO:");gotoxy(30,7);
	scanf("%s",a.epf);
	gotoxy(21,8);
	printf(" Name:");gotoxy(30,8);
	scanf("%s",a.name);
	gotoxy(21,9);
	printf(" NIC:");gotoxy(30,9);
	scanf("%s",a.nic);
}
float basic(int j)      //basic salary will get by basic_salary.txt while execution
{
FILE *fp;
int x;float bs[30];
fp =fopen("c:\\basic_salary.txt", "r");
for (x=0; x<30; x++)
{
    fscanf(fp,"%f,",&bs[x]);
}
fclose(fp);
return bs[j];
}
float ot1(float bs) //function for calculate the week days ot
{
int x;float ot,hou[15];
FILE*fp;        //ot hours input by ot hour.txt file during the execution
 fp=fopen("c:\\ot_hours.txt","r");
 for (x=0; x<30; x++)
 {
    fscanf(fp,"%f",&hou[x]);
 }
fclose(fp);
ot=(bs/200)*1.5*hou[i];
return ot;
}
float ot2(float bs)     //function for calculate the weekend days ot
{
 int x;float otSunday,hou[15];
FILE*fp;        //ot hours input by ot hour_weekend.txt file during the execution
 fp=fopen("c:\\weekend_ot.txt","r");
 for (x=0; x<30; x++)
{
    fscanf(fp,"%f",&hou[x]);
}
 fclose(fp);
otSunday=(bs/200)*2*hou[i];
return otSunday;
}
float epf1(float bs)    //function for calculate the 8% of EPF
{
float epf;
epf=(bs/100)*8;
return epf;
}
float epf2(float bs)        //function for calculate the 12% of EPF
{
float epfCom;
epfCom=(bs/100)*12;
return epfCom;
}
float etf1(float bs)        //function for calculate the 3% of ETF
{
float etf;
etf=(bs/100)*3;
return etf;
}
float shifI()
{
int x,shf,sf[15];
FILE*fp;        //shif time input by shift01.txt file during the execution
 fp=fopen("c:\\shift01.txt","r");
 for (x=0; x<30; x++)
{
    fscanf(fp,"%d",&sf[x]);
}
 fclose(fp);
 shf=100*sf[i];
return shf;
}
float shifII()
{
    int x,shf,sf[15];
FILE*fp;        //shif time input by shift02.txt file during the execution
 fp=fopen("c:\\shift02.txt","r");
 for (x=0; x<30; x++)
{
    fscanf(fp,"%d",&sf[x]);
}
 fclose(fp);
 shf=110*sf[i];
return shf;
}
float shifIII()
{
    int x,shf,sf[15];
FILE*fp;        //shif time input by shift03.txt file during the execution
 fp=fopen("c:\\shift03.txt","r");
 for (x=0; x<30; x++)
{
    fscanf(fp,"%d",&sf[x]);
}
 fclose(fp);
 shf=800*sf[i];
return shf;
}
void pay(float t[9])     //paysheet with additional ot values
{
    float totEa,totDe,net,ufee=100,stDut=25; /*totEa variable for calculate total earnings,
                                totDe variable for calculate total deductions,net for save net salary
                                ufee for union fee and stDut for stamp dut*/

getdata();
system("cls");
gotoxy(1,1);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(23,1);
printf("G&D Currency & Security (Pvt) Ltd.");
gotoxy(58,1);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(30,3);
printf("\xB2\xB2\xB2\xB2\xB2 PAYSLIP \xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(3,5);
printf("EMP NO.");gotoxy(17,5);
printf("%s",a.id);gotoxy(30,5);
printf("NIC NO.");gotoxy(40,5);
printf("%s",a.nic);gotoxy(55,5);
printf("EPF NO.");gotoxy(65,5);
printf("%s",a.epf);
gotoxy(3,6);
printf("NAME");gotoxy(17,6);
printf("%s",a.name);
gotoxy(3,7);
printf("DESIGNATION");gotoxy(17,7);
printf("%s",des);

gotoxy(3,9);
printf("EARNINGS");     //earnings(left column on payslip)
gotoxy(2,11);
printf("BASIC SAL\t%.2f",t[0]);        //basic salary
gotoxy(2,12);
printf("O.T. 1.50\t%.2f",t[1]);       //week days ot
gotoxy(2,13);
printf("OT 1.5 PR\t%.2f",t[2]);      //weekend days ot
gotoxy(2,14);
printf("SHIFT I\t%2.f",t[6]);      //shift 6:00 a.m to 2:00 p.m
gotoxy(2,15);
printf("SHIFT II\t%.2f",t[7]);     //shift 2:00 p.m to 10:00 p.m
gotoxy(2,16);
printf("SHIFT III\t%.2f",t[8]);        //shift 10:00 p.m to 6:00 a.m
gotoxy(15,17);
printf("----------");
gotoxy(2,18);
totEa=t[0]+t[1]+t[2]+t[6]+t[7]+t[8];     //calclate total earnings
printf("TOT EARNINGS\t%.2f",totEa);
gotoxy(15,19);
printf("----------");
gotoxy(2,20);
printf("EPF YER 12.00\t %.2f",t[4]);        //12% of EPF
gotoxy(2,21);
printf("ETF YER  3.00\t %.2f",t[5]);        //3% of ETF
gotoxy(2,22);
printf("EPF YEE  8.00\t %.2f",t[3]);     //8% of EPF

gotoxy(44,9);
printf("DEDUCTIONS");     //deductions(right column on payslip)
gotoxy(43,11);
printf("UNION FEE\t%.2f",ufee);
gotoxy(43,12);
printf("STAMP DUT\t%.2f",stDut);       //stamp dut
gotoxy(43,13);
printf("EPF YEE\t%.2f",t[3]);      //8% 0f EPF
gotoxy(43,14);
printf("ETF YEE\t%.2f",t[5]);      //3% of ETF

gotoxy(56,17);
printf("----------");
gotoxy(39,18);
totDe=stDut+ufee+t[3]+t[5];     //calclate total deductions
printf("TOT DEDUCTIONS\t%.2f",totDe);
gotoxy(56,19);
printf("----------");
net=totEa-totDe;
gotoxy(39,20);
printf("NET PAY\t\t%.2f",net);
gotoxy(29,23);
printf("Do you want to back to main menu(Y/N)");
if(getch()=='y')
mainmenu();
else
returnfunc();
}
void pay1(float s[4])     //paysheet without additional ot values
{
    float totEa,totDe,net,stDut=25; /*totEa variable for calculate total earnings,
                                totDe variable for calculate total deductions,net for save net salary
                                and stDut for stamp dut*/
getdata();
system("cls");
gotoxy(1,1);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(23,1);
printf("G&D Currency & Security (Pvt) Ltd.");
gotoxy(58,1);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(30,3);
printf("\xB2\xB2\xB2\xB2\xB2 PAYSLIP \xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(3,5);
printf("EMP NO.");gotoxy(17,5);
printf("%s",a.id);gotoxy(30,5);
printf("NIC NO.");gotoxy(40,5);
printf("%s",a.nic);gotoxy(55,5);
printf("EPF NO.");gotoxy(65,5);
printf("%s",a.epf);
gotoxy(3,6);
printf("NAME");gotoxy(17,6);
printf("%s",a.name);
gotoxy(3,7);
printf("DESIGNATION");gotoxy(17,7);
printf("%s",des);

gotoxy(3,9);
printf("EARNINGS");     //earnings(left column on payslip)
gotoxy(2,11);
printf("BASIC SAL\t%.2f",s[0]);        //basic salary
gotoxy(15,16);
printf("----------");
gotoxy(2,17);
totEa=s[0];     //calclate total earnings
printf("TOT EARNINGS\t%.2f",totEa);
gotoxy(15,18);
printf("----------");
gotoxy(2,20);
printf("EPF YER 12.00\t %.2f",s[2]);        //12% of EPF
gotoxy(2,21);
printf("ETF YER  3.00\t %.2f",s[3]);        //3% of ETF
gotoxy(2,22);
printf("EPF YEE  8.00\t %.2f",s[1]);     //8% of EPF

gotoxy(44,9);
printf("DEDUCTIONS");     //deductions(right column on payslip)
gotoxy(43,11);
printf("STAMP DUT\t%.2f",stDut);       //stamp dut
gotoxy(43,12);
printf("EPF YEE\t%.2f",s[1]);      //8% 0f EPF
gotoxy(43,13);
printf("ETF YEE\t%.2f",s[3]);   //3% of ETF
gotoxy(56,16);
printf("----------");
gotoxy(39,17);
totDe=stDut+s[1]+s[3];     //calclate total deductions
printf("TOT DEDUCTIONS\t%.2f",totDe);
gotoxy(56,18);
printf("----------");
net=totEa-totDe;
gotoxy(39,19);
printf("NET PAY\t\t%.2f",net);
gotoxy(29,22);
printf("Do you want to back to main menu(Y/N)");
if(getch()=='y')
mainmenu();
else
returnfunc();
}
void password()     //password function for limit to accesses to the sytem update function
{
    system("cls");
    char pass[10],password[10]={"deadpool"};
    gotoxy(23,7);
    printf("G&D Currency & Security (Pvt) Ltd.");
    gotoxy(25,9);
    printf("*****PASSWORD PROTECTED*****");
    gotoxy(15,16);
    printf("Enter Password ");
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
   {
    system("cls");
    gotoxy(15,9);
	printf("Password match");
	gotoxy(17,10);
	printf("Press any key to countinue.....");
	getch();
	update();
   }
   else
   {
	 gotoxy(15,16);
	 printf("Incorrect Password");
	 getch();
	 mainmenu();
   }
}
void update()       //function to input basic salary into files,only access by genaral manager
{
    system("cls");
    int c;float basic;
    FILE *fp;
fp =fopen("c:\\basic_salary.txt", "w");
for (c=0; c<30; c++)
{
    system("cls");
    gotoxy(25,2);
    printf("G&D Currency & Security (Pvt) Ltd.");
    gotoxy(16,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UPDATE MENU FOR BASIC SALARY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(2,7);
    switch(c)
    {
    case 0:printf("\xDB\xDB Printing Department (Print Manager)");break;
    case 1:printf("\xDB\xDB Printing Department (Print Supervisior)");break;
    case 2:printf("\xDB\xDB Printing Department (Printer 1)");break;
    case 3:printf("\xDB\xDB Printing Department (Printer 2)");break;
    case 4:printf("\xDB\xDB Printing Department (Print Assisten)");break;
    case 5:printf("\xDB\xDB Printing Department (Print Poarter)");break;
    case 6:printf("\xDB\xDB Finishing Department (Finishing Manager)");break;
    case 7:printf("\xDB\xDB Finishing Department (Finishing Supervisor)");break;
    case 8:printf("\xDB\xDB Finishing Department (Leadhand)");break;
    case 9:printf("\xDB\xDB Finishing Department (Finishing Operator)");break;
    case 10:printf("\xDB\xDB Qulity Department (Qulity Manager)");break;
    case 11:printf("\xDB\xDB Qulity Department (Qulity Supervisor)");break;
    case 12:printf("\xDB\xDB Qulity Department (Seniar Qulity)");break;
    case 13:printf("\xDB\xDB Qulity Department (QI)");break;
    case 14:printf("\xDB\xDB H.R.Division (Genaral Manager)");break;
    case 15:printf("\xDB\xDB H.R.Division (Factory Manager)");break;
    case 16:printf("\xDB\xDB H.R.Division (H.R.Manger)");break;
    case 17:printf("\xDB\xDB H.R.Division (Finans Manager)");break;
    case 18:printf("\xDB\xDB H.R.Division (Accountan)");break;
    case 19:printf("\xDB\xDB H.R.Division (IT technisian)");break;
    case 20:printf("\xDB\xDB H.R.Division (Cleark)");break;
    case 21:printf("\xDB\xDB Security Department (Security Manager)");break;
    case 22:printf("\xDB\xDB Security Department (Security Supervisor)");break;
    case 23:printf("\xDB\xDB Security Department (Shift Controller)");break;
    case 24:printf("\xDB\xDB Security Department (Seniar Security)");break;
    case 25:printf("\xDB\xDB Security Department (Juniar Security)");break;
    case 26:printf("\xDB\xDB Engineering Department (Enginnering Manager)");break;
    case 27:printf("\xDB\xDB Engineering Department (Enginnering Supervisor)");break;
    case 28:printf("\xDB\xDB Engineering Department (Enginner)");break;
    case 29:printf("\xDB\xDB Engineering Department (Labour)");break;
    }
    gotoxy(5,8);
    printf("\tEnter basic salary[Rs] = ");
    scanf("%f",&basic);
    fprintf(fp,"%f\n",basic);
}
fclose(fp);
printf("\nDo you want to save again(Y/N)");
if(getch()=='y')
update();
else
mainmenu();
}
void returnfunc()
{
    switch(dept)
{
    case 1:printing();break;        //function for get previous department,using dept global variable
    case 2:finishing();break;
    case 3:qulity();break;
    case 4:hrdivision();break;
    case 5:security();break;
    case 6:engineering();break;
}
}
int t(void)     //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}
