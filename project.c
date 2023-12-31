 //========================== Including Header Files====================//
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
//#include<alloc.h>//

//============= Variable For Mouse x,y Coordinets, Buttons Value====//
int mx, my, mouse_button,mouse_button2, maxx, maxy ;

//----------------------- define structure for this project---------------//
struct main
{
   char regn[10],name[50],f_name[50],address[100],course[10],doa[10];
};
struct result
{
   int m1,m2,m3,m4,total;
   char regn[10],grade[2];
};
struct link_main
{
   char lmregn[10],lmname[50],lmf_name[50],lmaddress[100],lmcourse[10],lmdoa[10];
   struct link_main *next;
};
struct link_result // Define link list Structure for deleting or editing//
{
   int lrm1,lrm2,lrm3,lrm4,lrtotal; // members//
   char lrregn[10],lrgrade[2]; // ,, //
   struct link_result *next; //linking address for next node//
};
typedef struct main m; //Declear typedef of structure//
typedef struct result r;
typedef struct link_main lm;
typedef struct link_result lr;
long int size1=sizeof(m); //declear size of structure//
long int size2=sizeof(r);
FILE *f1,*f2; //declear file stream for opening files//

//============== Define function Prototype for this project=========//
void add(); // Function 1 for add a record//
void edit(); // Function 2 for edit a record//
void search(); // Function 3 for find a record from database//
void delete(); // Function 4 for delete a recor from datanase//
void update(); // Function 5 for adding marks of students//
void form1(void); // Function 6 For Display Front Page //
void help(void); // Function 7 For Display Help File //
void displayList (void); // Function 8 For Display All Student In List Format//
void displayResult(void); // Function 9 For Display All Result Of Student With Registration No. //

//================== Main Function Starts Here===================/
void main()
{
 char c;
 clrscr(); // Clearing The Screen //
 load_mousedriver(); // Loading Mouse Driver//
 reset_mouse(); // Reseting Mouse On Screen //
 window(0,0,600,400);
 textmode(C4350);
 f1=fopen("c:\\student/main.dat","r"); // Open Main File In Read Mode //
 if (f1==NULL) // Checking database if avalible of not//
 {
 printf("Your data base not exit are you must create it press any key to continue");
 getch();
 clrscr();
 mkdir("c:\\student");
 f2=fopen("c:\\student/main.dat","wb"); // Creating Main database for application//
 fclose(f2);
 f2=fopen("C:\\student//result.dat","wb"); // Creating Result Database For This Application //
 fclose(f2);
 fclose(f1);
 f1=fopen("c:\\student/help","wb");
 f2=fopen("help","rb");
 while(feof(f2)==0) //=== Writeing Help File==//
 {
 c=getc(f2);
 putc(c,f1);
 }
 printf("You must restart your application press any key to continue.....");
 getch();
 _exit(0); // Exit From Application //
 }
 form1(); // Calling Function 6 //
 }

 //========================= Program For Adding A New Record==========//
void add()
{
 m a,b;
 int flag;
 flag=0;
 f1=fopen("c:\\student/main.dat","ab");
 if(f1==NULL)
 {
 printf("File can not open an error occored press any key to continue...");
 getch();
 exit(0);
 }
 f2=fopen("C:\\student/main.dat","rb");
 if(f2==NULL)
 {
 printf("File can not open.Make sure your database is correpted press any key to continue...");
 getch();
 exit(0);
 }
 clrscr();
 gotoxy(30,3);printf("Form for new student");
 gotoxy(30,4);printf("--------------------") ;
 gotoxy(5,6); printf("Enter Student Registration no:-");scanf("%s",&b.regn);
 while(fread(&a,size1,1,f2)==1)
 {
 if(strcmp(a.regn,b.regn)==0)
 flag=1;
 }
 if(flag==0)
 {
 gotoxy(5,8); printf("Enter Student Name :-");fflush(stdin);gets(b.name);
 gotoxy(5,10);printf("Enter Ntudent Fathers Name :-");fflush(stdin);gets(b.f_name);
 gotoxy(5,12);printf("Enter Student Address :-");fflush(stdin);gets(b.address);
 gotoxy(5,14);printf("Enter Course name :-");fflush(stdin);gets(b.course);
 gotoxy(5,16);printf("Enter Date Of Admission :-");fflush(stdin);gets(b.doa);
 fwrite(&b,size1,1,f1);
 fclose(f1);
 fclose(f2);
 }
 else
 {
 gotoxy(5,16);printf("This Regestration Number Already Exist Press Any Key To Continue....");
 getch();
 }
 form1();
}

void edit()
{
 m a,b; // Declearing Structure Type Variable //
 r a1,b1; // ,, //
 lm *s,*p,*n; // Declearing Pointer Type Variable //
 lr *m,*w,*k;
 char reg[10],op;
 char newe[100];
 int flag;
 s=p=n=NULL;
 flag=0;
 clrscr();
 gotoxy(25,1);printf("-----------------------------------");
 gotoxy(24,2);printf("| Edit Profile Of A Student |");
 gotoxy(25,3);printf("-----------------------------------");
 f1=fopen("c:\\student/main.dat","rb");
 if (f1==NULL){printf("Databse not exist");getch();exit(0);}
 gotoxy(5,6);printf("| Enter Reg No Of Student :-");fflush(stdin);gets(reg);
 while(fread(&a,size1,1,f1)==1)
 {
 n=(lm*)malloc(sizeof(lm));
 strcpy(n->lmregn,a.regn);
 strcpy(n->lmname,a.name);
 strcpy(n->lmf_name,a.f_name);
 strcpy(n->lmaddress,a.address);
 strcpy(n->lmcourse,a.course);
 strcpy(n->lmdoa,a.doa);
 n->next=NULL;
 if (s==NULL)
 {
 s=n;
 }
 else
 {
 for(p=s;p->next!=NULL;p=p->next);p->next=n;
 }
 }
 fclose(f1);
 f1=fopen("c:\\student/main.dat","rb");
 while(fread(&a,size1,1,f1)==1)
 {
 if(strcmp(a.regn,reg)==0)
 {
 gotoxy(5,5);printf("| |");
 gotoxy(5,7);printf("| |");
 gotoxy(5,8);printf("| |");
 gotoxy(5,9);printf("| |");
 gotoxy(5,10);printf("| |");
 gotoxy(5,11);printf("| |");
 gotoxy(5,4);printf("|-----------------------------Details------------------------------");
 gotoxy(5,7);printf("| Student Name :- %s",a.name);
 gotoxy(5,8);printf("| Student Father`s Name :- %s",a.f_name);
 gotoxy(5,9);printf("| Student Address :- %s",a.address);
 gotoxy(5,10);printf("| Course :- %s",a.course);
 gotoxy(5,11);printf("| Date of Addmission :- %s",a.doa);
 gotoxy(5,12);printf("|-----------------------------------------------------------------");
 }
 else
 {
 // gotoxy(5,9);printf("Record Was Not Found");
 }
 }
 gotoxy(5,13);printf("|--------------------------Choose Any Option----------------------");
 gotoxy(5,15);printf("| Edit Name Press A |");
 gotoxy(5,16);printf("| Edit Father Name Press B |");
 gotoxy(5,17);printf("| Edit Address Press C |");
 gotoxy(5,18);printf("| Edit Course Press D |");
 gotoxy(5,19);printf("| Edit Date Of Add Press E |");
 gotoxy(5,20);printf("|-----------------------------------------------------------------|");
 gotoxy(40,19);printf(" | Type your option:- ");
 fflush(stdin);scanf("%c",&op);
 for(p=s;p!=NULL;p=p->next)
 {
 if(strcmp(p->lmregn,reg)==0)
 {
 if (op=='A'||op=='a')
 {
 gotoxy(5,22);printf("Enter New Name :-");fflush(stdin);gets(newe);
 strcpy(p->lmname,newe);
 flag=0;
 break;
 }
 else if(op=='b'||op=='B')
 {
 gotoxy(5,22);printf("Enter New Father Name :-");fflush(stdin);gets(newe);
 strcpy(p->lmf_name,newe);
 flag=0;
 break;
 }
 else if(op=='c'||op=='C')
 {
 gotoxy(5,22);printf("Enter New Address :-");fflush(stdin);gets(newe);
 strcpy(p->lmaddress,newe);
 flag=0;
 break;
 }
 else if(op=='d'||op=='D')
 {
 gotoxy(5,22);printf("Enter New Course :-");fflush(stdin);gets(newe);
 strcpy(p->lmcourse,newe);
 flag=0;
 break;
 }
 else if (op=='e'||op=='E')
 {
 gotoxy(5,22);printf("Enter New Date of Addmission :-");fflush(stdin);gets(newe);
 strcpy(p->lmdoa,newe);
 flag=0;
 break;
 }
 else
 {
 flag=2;
 break;
 }
 }
 else
 {
 flag=1;
 }
 }
 if(flag==1)
 { for(p=s;p!=NULL;p=p->next)
 {
 free(p);
 }
 gotoxy(20,25);printf("The Record was not found press any key to continue..");getch();
 }
 else if(flag==2)
 {
 for(p=s;p!=NULL;p=p->next)
 {
 free(p);
 }
 gotoxy(20,25);printf("You have enter wrong option press any key to continue ..");getch();
 }
 else
 {
 f2=fopen("c:\\student/main.dat","wb");
 for(p=s;p!=NULL;p=p->next)
 {
 strcpy(b.regn,p->lmregn);
 strcpy(b.name,p->lmname);
 strcpy(b.f_name,p->lmf_name);
 strcpy(b.address,p->lmaddress);
 strcpy(b.course,p->lmcourse);
 strcpy(b.doa,p->lmdoa);
 fwrite(&b,size1,1,f2);
 free(p);
 }
 fclose(f2);
 }
 getch();
 form1();
}

void search()
{
 int flag=0;
 char rn[10];
 m b;
 r c;
 clrscr();
 gotoxy(5,6);printf("Enter Registration No ");fflush(stdin);scanf("%s",&rn);fflush(stdin);
 f1=fopen("c:\\student/main.dat","rb");
 while(fread(&b,size1,1,f1)==1)
 {
 if(strcmp(b.regn,rn)==0)
 {
 flag=0;
 clrscr();
 gotoxy(30,2);printf("|-------------------|");
 gotoxy(30,3);printf("| Student Details |");
 gotoxy(30,4);printf("|-------------------|") ;
 gotoxy(5,6); printf("Student Registration no :-%s",b.regn);
 gotoxy(5,8); printf("Student Name :-%s",b.name);
 gotoxy(5,10);printf("Student Fathers Name :-%s",b.f_name);
 gotoxy(5,12);printf("Student Address :-%s",b.address);
 gotoxy(5,14);printf("Course name :-%s",b.course);
 gotoxy(5,16);printf("Date Of Admission :-%s",b.doa);
 break;
 }
 else
 {
 flag=1;
 }
 }
 fclose(f1);
 f2=fopen("c:\\student/result.dat","rb");
 while (fread(&c,size2,1,f2)==1)
 {
 if(strcmp(c.regn,rn)==0)
 { gotoxy(1,17);printf("|----------------------------------------------------------|");
 gotoxy(1,16);printf(" M1 Marks M2 Marks M3 Marks M4 Marks ");
 gotoxy(1,18);printf("| %d",c.m1);
 gotoxy(16,18);printf("| %d",c.m2);
 gotoxy(32,18);printf("| %d",c.m3);
 gotoxy(48,18);printf("| %d",c.m4);
 gotoxy(1,19);printf("|----------------------------------------------------------|");
 gotoxy(5,21);printf("TOTAL MARKS:-%d",c.total);
 fflush(stdin);
 gotoxy(25,21);printf("GRADE:-%s",c.grade);
 fclose(f2);
 getch();
 break;
 }
 else
 {
 flag=2;
 }
 }
 fclose(f1);
 if(flag==1)
 {
 gotoxy(5,16);printf("This Record Is Not Fond Press Any Key To Continue..");
 getch();
 }
 else if(flag==2)
 {
 gotoxy(5,16);printf("Marks Of This Student Not Found Any Key To Continue..");
 getch();
 }
}

 void delete()
{
 m a,b;
 r c,d;
 lm *s,*p,*n;
 lr *m,*t,*k;
 char reg[10],op;
 char newe[100];
 int flag,flag1;
 s=p=n=NULL;
 m=t=k=NULL;
 flag=flag1=0;
 clrscr();
 gotoxy(25,1);printf("-----------------------------------");
 gotoxy(24,2);printf("| Deleting Of A Student Profile |");
 gotoxy(25,3);printf("-----------------------------------");
 f1=fopen("c:\\student/main.dat","rb");
 if (f1==NULL){printf("Databse not exist");getch();exit(0);}
 gotoxy(5,6);printf("| Enter Reg No Of Student :-");fflush(stdin);scanf("%s",&reg);
 while(fread(&a,size1,1,f1)==1)
 {
 n=(lm*)malloc(sizeof(lm));
 strcpy(n->lmregn,a.regn);
 strcpy(n->lmname,a.name);
 strcpy(n->lmf_name,a.f_name);
 strcpy(n->lmaddress,a.address);
 strcpy(n->lmcourse,a.course);
 strcpy(n->lmdoa,a.doa);
 n->next=NULL;
 if (s==NULL)
 {
 s=n;
 }
 else
 {
 for(p=s;p->next!=NULL;p=p->next);p->next=n;
 }
 }
 fclose(f1);
 f2=fopen("c:\\student/result.dat","rb");
 while(fread(&c,size2,1,f2)==1)
 {
 k=(lr*)malloc(sizeof(lr));
 strcpy(k->lrregn,c.regn);
 k->lrm1=c.m1;
 k->lrm2=c.m2;
 k->lrm3=c.m3;
 k->lrm4=c.m4;
 k->lrtotal=c.total;
 strcpy(k->lrgrade,c.grade);
 k->next=NULL;
 if (m==NULL)
 {
 m=k;
 }
 else
 {
 for(t=m;t->next!=NULL;t=t->next);t->next=k;
 }
 }
 fclose(f2);
 f1=fopen("c:\\student/main.dat","rb");
 while(fread(&a,size1,1,f1)==1)
 {
 if(strcmp(a.regn,reg)==0)
 { flag=0;
 gotoxy(5,5);printf("| |");
 gotoxy(5,7);printf("| |");
 gotoxy(5,8);printf("| |");
 gotoxy(5,9);printf("| |");
 gotoxy(5,10);printf("| |");
 gotoxy(5,11);printf("| |");
 gotoxy(5,4);printf("|-----------------------------Details-----------------------------|");
 gotoxy(5,7);printf("| Student Name :- %s",a.name);
 gotoxy(5,8);printf("| Student Father`s Name :- %s",a.f_name);
 gotoxy(5,9);printf("| Student Address :- %s",a.address);
 gotoxy(5,10);printf("| Course :- %s",a.course);
 gotoxy(5,11);printf("| Date of Addmission :- %s",a.doa);
 gotoxy(5,12);printf("|-----------------------------------------------------------------|");
 break;
 }
 else
 {
 flag=2;
 }
 }
 fclose(f1);
 f2=fopen("c:\\student/result.dat","rb");
 while (fread(&c,size2,1,f2)==1)
 {
 if(strcmp(c.regn,reg)==0)
 {
 flag1=0;
 gotoxy(5,17);printf("|----------------------------------------------------------|");
 gotoxy(5,16);printf(" M1 Marks M2 Marks M3 Marks M4 Marks ");
 gotoxy(5,18);printf("| %d",c.m1);
 gotoxy(21,18);printf("| %d",c.m2);
 gotoxy(37,18);printf("| %d",c.m3);
 gotoxy(53,18);printf("| %d |",c.m4);
 gotoxy(5,19);printf("|----------------------------------------------------------|");
 gotoxy(5,21);printf("TOTAL MARKS:-%d",c.total);
 fflush(stdin);
 gotoxy(25,21);printf("GRADE:-%s",c.grade);
 fclose(f2);
 break;
 }
 else
 {
 flag1=2;
 }
 }
 fclose(f2);
 if (flag==2){gotoxy(10,30);printf("This Ren No Not Found Press Any Key To Continue");getch();goto end;}
 if (flag1==1){gotoxy(5,21);printf("The Marks Of This Student Not Exist");}
 gotoxy(5,23);printf("Are You Sure Delete This Record?(Y/N)");fflush(stdin);op=getch();
 if (op=='Y'||op=='y')
 {
 if(strcmp(s->lmregn,reg)==0)
 {
 flag=1;
 n=s->next;
 free(s);
 s=n;
 }
 else
 {
 for (p=s;p->next!=NULL;p=p->next)
 {
 if(strcmp(p->lmregn,reg)==0)
 {
 flag=1;
 n=p->next->next;
 free(p->next);
 p->next=n;
 }
 }
 }
 if(strcmp(m->lrregn,reg)==0)
 {
 flag1=1;
 k=m->next;
 free(m);
 m=k;
 }
 else
 {
 for (t=m;t->next!=NULL;t=t->next)
 {
 if(strcmp(t->lrregn,reg)==0)
 {
 flag1=1;
 k=t->next->next;
 free(t->next);
 t->next=k;
 }
 }
 }
 }
 else
 {
 gotoxy(10,30);printf("Record Was Not Deleted");getch();
 }
 if (flag==1)
 {
 f2=fopen("c:\\student/main.dat","wb");
 for(p=s;p!=NULL;p=p->next)
 {
 strcpy(b.regn,p->lmregn);
 strcpy(b.name,p->lmname);
 strcpy(b.f_name,p->lmf_name);
 strcpy(b.address,p->lmaddress);
 strcpy(b.course,p->lmcourse);
 strcpy(b.doa,p->lmdoa);
 fwrite(&b,size1,1,f2);
 free(p);
 }
 fclose(f2);
 }
 else
 {
 for(p=s;p!=NULL;p=p->next)
 {
 free(p);
 }
 }
 if (flag1==1)
 { fclose(f2);
 f2=fopen("c:\\student/result.dat","wb");
 for(t=m;t!=NULL;t=t->next)
 {
 strcpy(d.regn,t->lrregn);
 d.m1=t->lrm1;
 d.m2=t->lrm2;
 d.m3=t->lrm3;
 d.m4=t->lrm4;
 d.total=t->lrtotal;
 strcpy(d.grade,t->lrgrade);
 fwrite(&d,size2,1,f2);
 free(t);
 }
 fclose(f2);
 }
 else
 {
 for(t=m;t!=NULL;t=t->next)
 {
 free(t);
 }
 }
 end:
 form1();
}

 void update()
{
 m a,b;
 r c,d;
 int flag,tot,s1,s2,s3,s4,t1;
 char reg[10],g[2];
 flag=0;
 tot=s1=s2=s3=s4=t1=0;
 f1=fopen("c:\\student/result.dat","rb");
 if(f1==NULL)
 {
 printf("File can not open an error occored press any key to continue...");
 getch();
 fclose(f1);
 exit(0);
 }
 f2=fopen("C:\\student/main.dat","rb");
 if(f2==NULL)
 {
 printf("File can not open.Make sure your database is correpted press any key to continue...");
 getch();
 fclose(f1);
 exit(0);
 }
 clrscr();
 gotoxy(20,3);printf("Form for Marks Entry Of A Student");
 gotoxy(20,4);printf("---------------------------------") ;
 gotoxy(5,6); printf("Enter Student Registration no:-");fflush(stdin);gets(reg);
 while(fread(&a,size1,1,f2)==1)
 {
 if(strcmp(a.regn,reg)==0)
 { flag=1;
 break;
 }
 }
 while(fread(&c,size2,1,f1)==1)
 {
 if(strcmp(c.regn,reg)==0)
 {
 flag=2;
 break;
 }
 }
 if(flag==0)
 {
 gotoxy(10,40);printf("This Registration No Not Found....Press Any Key");
 getch();
 fclose(f1);
 fclose(f2);
 }
 else if(flag==2)
 {
 gotoxy(5,16);printf("The Marks Of This Candidate Already Exist....");
 getch();
 }
 else if(flag==1)
 {
 fclose(f1);
 f1=fopen("c:\\student/result.dat","ab");
 strcpy(d.regn,reg);
 gotoxy(5,8); printf("Enter Module 1 Marks :-");fflush(stdin);scanf("%d",&s1);
 gotoxy(5,10);printf("Enter Module 2 Marks :-");fflush(stdin);scanf("%d",&s2);
 gotoxy(5,12);printf("Enter Module 3 Marks :-");fflush(stdin);scanf("%d",&s3);
 gotoxy(5,14);printf("Enter Module 4 Marks :-");fflush(stdin);scanf("%d",&s4);
 t1=s1+s2+s3+s4;
 tot=t1/4;
 fflush(stdin);
 if(tot<50){g[0]='F';}else if(tot<55){g[0]='D';}else if(tot<64){g[0]='C';}else if(tot<75){g[0]='B';}else if(tot<85){g[0]='A';}else{g[0]='S';}
 gotoxy(5,16);printf("Total Marks Of Student :- %d",t1);
 gotoxy(5,17);printf("Grade Of The Student :- %s",g);
 d.m1 =s1;d.m2=s2;d.m3=s3;d.m4=s4;
 d.total=t1;
 fflush(stdin);
 strcpy(d.grade,g);
 fwrite(&d,size2,1,f1);
 fclose(f1);
 getch();
 }
 form1();
}

 void help(void)
{
 char c;
 clrscr();
 f1=fopen("c:\\student/help","rb");
 if(f1==NULL)
 {
 printf("The Help Can Not Avilable Press Any Key To Continue..");
 getch();
 fclose(f1);
 form1();
 }
 while ((c=getc(f1))!=EOF)
 {
 printf("%c",c);
 delay(4);
 if(c=='*')
 {
 gotoxy(30,40);printf("Press 0 to Exit Or Press Any Key To Continue..");
 while(!kbhit())
 {
 get_position();
 if(mouse_button==1){clrscr();goto out;}else if(mouse_button2==2){ clrscr();goto point;}
 }
 if(getch()=='0'){break;}else{clrscr();}
 point:
 }
 }
 out:
 fclose(f1);
 form1();
}

 void displayList(void)
{
 m a;
 int i,j;
 i=4,j=0;
 clrscr();
 f1=fopen("c:\\student/main.dat","rb");
 gotoxy(1,2);printf(" Reg No. Student Name F_name Courese Date Of Add");
 gotoxy(1,3);printf("|------------------------------------------------------------------------------|");
 while(fread(&a,size1,1,f1)==1)
 {
 if(j%2==0){textbackground(4);}else{textbackground(1);;}
 gotoxy(2,i);cprintf(" ");
 gotoxy(1,i);cprintf("| %s",a.regn);
 gotoxy(10,i);cprintf("| %s",a.name);
 gotoxy(30,i);cprintf("| %s",a.f_name);
 gotoxy(53,i);cprintf("| %s",a.course);
 gotoxy(67,i);cprintf("| %s",a.doa);
 gotoxy(80,i);cprintf("|");
 fflush(stdin);
 j++;
 i++;
 textbackground(0);
 gotoxy(1,i);cprintf("|--------|-------------------|----------------------|-------------|------------|");
 i++;
 if(i==50)
 { i=4;
 gotoxy(10,52);printf("Press any Key To Continue Or Press 0 zero to Exit");
 while (!kbhit())
 {
 get_position();
 if (mouse_button==1)
 {
 clrscr();
 gotoxy(1,2);printf(" Reg No. Student Name F_name Courese Date Of Add");
 gotoxy(1,3);printf("|------------------------------------------------------------------------------|");
 }
 else if(mouse_button2==2)
 {
 break;
 }
 }
 if(getch()=='0')
 {
 break;
 }
 else
 {
 clrscr();
 gotoxy(1,2);printf(" Reg No. Student Name F_name Courese Date Of Add");
 gotoxy(1,3);printf("|------------------------------------------------------------------------------|");
 }
 }
 }
 getch();
 fclose(f1);
 form1();
}

 void displayResult(void)
{
 r a;
 int i,j;
 i=4,j=0;
 clrscr();
 f1=fopen("c:\\student/result.dat","rb");
 gotoxy(1,1);printf("|---------------------------------------------------------------------------|");
 gotoxy(1,2);printf("| Reg No. Module 1 Module 2 Module 3 Module 4 Total Grade |");
 gotoxy(1,3);printf("|---------------------------------------------------------------------------|");
 while(fread(&a,size2,1,f1)==1)
 {
 if(j%2==0){textbackground(4);}else{textbackground(1);;}
 gotoxy(2,i);cprintf(" ");
 gotoxy(1,i);printf("| %s",a.regn);
 gotoxy(10,i);printf("| %d",a.m1);
 gotoxy(20,i);printf("| %d",a.m2);
 gotoxy(33,i);printf("| %d",a.m3);
 gotoxy(45,i);printf("| %d",a.m4);
 gotoxy(56,i);printf("| %d",a.total);
 gotoxy(65,i);printf("| %s",a.grade);
 gotoxy(77,i);printf("|");
 i++;
 j++;
 textbackground(0);
 gotoxy(1,i);printf("|--------|---------|------------|-----------|----------|--------|-----------|");
 i++;
 if(i==50)
 { i=4;
 gotoxy(10,52);printf("Press any Key To Continue Or Press 0 zero to Exit");
 if(getch()=='0')
 {
 break;
 }
 else
 {
 clrscr();
 gotoxy(1,2);printf(" Reg No. Student Name F_name Courese Date Of Add");
 gotoxy(1,3);printf("|------------------------------------------------------------------------------|");
 }
 }
 }
 fclose(f1);
 getch();
 form1();
}

 /* loads mouse driver in memory, if not already loaded */
load_mousedriver()
{
 unsigned char far *ms ;
 /* convert the segment:offset address from IVT into a far pointer */
 ms = MK_FP ( peek ( 0, 0x33 * 4 + 2 ), peek ( 0, 0x33 * 4 ) ) ;
 /* check if mouse driver isn't already loaded */
 if ( ms == NULL || *ms == 0xcf )
 system ( "wittyms -p2" ) ;
 return 0;
}
/* initialises the mouse driver */
reset_mouse()
{
 union REGS i, o ;
 /* issue interrupt */
 i.x.ax = 0 ;
 int86 ( 0x33, &i, &o ) ;
 /* if unable to reset mouse */
 if ( o.x.ax == 0 )
 {
 gotoxy ( 20, 15 ) ;
 printf ( "Mouse not available! Press any key..." ) ;
 fflush ( stdin ) ;
 getch() ;
 exit ( 2 ) ;
 }
 return 0;
}
/* displays the mouse pointer */
show_ptr()
{
 union REGS i, o ;
 i.x.ax = 1 ; /* service number */
 int86 ( 0x33, &i, &o ) ; /* issue interrupt */
 return 0;
}
/* hides the mouse pointer */
hide_ptr()
{
 union REGS i, o ;
 i.x.ax = 2 ; /* service number */
 int86 ( 0x33, &i, &o ) ; /* issue interrupt */
 return 0;
}
/* checks which icon is selected */
getresponse()
{
 /* display the mouse pointer */
 show_ptr() ;
 get_position();
 return 0;
 }
/* gets current coordinates of mouse pointer and status of mouse buttons */
get_position()
{
 union REGS i, o ;
 i.x.ax = 3 ; /* service number */
 int86 ( 0x33, &i, &o ) ; /* issue interrupt */
 mx = o.x.cx ; /* x coordinate */
 my = o.x.dx ; /* y coordinate */
 mouse_button = o.x.bx & 1 ; /* store status of mouse buttons */
 mouse_button2=o.x.bx & 2;
 return 0;
}