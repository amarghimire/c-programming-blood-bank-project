#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
FILE *fp;
struct blood{
   char name[30];
   char add[30];
   char bg[4];
   int con;
   int id;
}st;

void insert();
void display();
void search();
void update();
void delet();
void menu();
int main()
{
    menu();
    return 0;
}

void menu(){
   system("cls");
   int ch;
   printf("1] INSERT DONER\n2] DISPLAY INFO\n3] SEARCH INFO\n4] UPDATE INFO\n5] DELETE INFO\n6] EXIT\n");
   printf("   ");
   scanf("%d",&ch);

   switch(ch){
case 1:
   insert();
   break;
case 2:
   display();
   break;
case 3:
   search();
case 4:
   //update();
   break;
case 5:
   //delet();
   break;
case 6:
   exit(0);
   break;
default:
   printf("INVALID");
   getch();
   menu();

   }


}

void insert(){
   system("cls");
   fp=fopen("blood.txt","a");
   printf("ENTER NAME=");
   scanf("%s",st.name);
   printf("ENTER ADDRESS=");
   scanf("%s",st.add);
   printf("ENTER BLOOD GROUP=");
   scanf("%s",st.bg);
   printf("ENTER CONTACT NUMBER=");
   scanf("%d",&st.con);
   fwrite(&st,sizeof(st),1,fp);
   printf("DATA INSERTED SUCESSFULLY\n");
   fclose(fp);
   getch();
   menu();
}

void display(){
   system("cls");
   fp=fopen("blood.txt","r");
   if(fp==NULL){
      printf("THERE IS NO DATA");
      getch();
      menu();
   }else{
      printf("\tNAME\t\tADDRESS\t\tBLOOD GROUP\tCONTACT\n");
      while (fread(&st,sizeof(st),1,fp)){
      	// by default can be put >> [while (fread(&st,sizeof(st),1,fp)==1 
      printf("\t%s\t\t%s\t\t%s\t\t%d\n",st.name,st.add,st.bg,st.con);
      }
      fclose(fp);
      getch();
      menu();
   }
}

void search(){
   char temp[30];
   int ch;
   system("cls");
   fp=fopen("blood.txt","r");
   if(fp==NULL){
      printf("THERE IS NO DATA");
      getch();
      menu();
   }else{
      printf("1] SEARCH BY NAME=\n");
      printf("2] SEARCH BY ADDRESS=\n");
      printf("3] SEARCH BY BLOOD GROUP=\n");
      printf("4] GO BACK\n");
      printf("   ");
      scanf("%d",&ch);
      system("cls");
      if(ch==1){
      printf("ENTER NAME=");
      scanf("%s",temp);
      }else if(ch==2){
      printf("ENTER ADDRESS=");
      scanf("%s",temp);
      }else if(ch==3){
      printf("ENTER BLOOD GROUP=");
      scanf("%s",temp);
      }else if(ch==4){
         menu();
      }else{
         printf("INVALID INPUT\n");
         getch();
         search();
      }
      printf("\tNAME\t\tADDRESS\t\tBLOOD GROUP\tCONTACT\n");
      while(fread(&st,sizeof(st),1,fp)==1){
      if(strcmpi(temp,st.name)==0||strcmpi(temp,st.add)==0||strcmpi(temp,st.bg)==0){
      printf("\t%s\t\t%s\t\t%s\t\t%d\n",st.name,st.add,st.bg,st.con);
      }
      else{
      	printf("there is no such data");
	  }


      }
      fclose(fp);
      getch();
      menu();
   }
}
