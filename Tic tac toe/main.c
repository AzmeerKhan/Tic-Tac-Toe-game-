#include <stdio.h>
#include <stdlib.h>
void help();
void start();
int computer(char*);
int file(char*);
int main()
{
    char menu;

/*   Main Menu    */

    while(1)
    {
        system("color 07");

       printf("Made by AAK");

//   For printing a menu from file

       file("Main menu");
       menu=getch();
       printf("\a");
       system("cls");

// Main Menu choices
       switch(menu)
         {
            case 'H': case 'h':
              {
                 help();


                 system("cls");
                 break;
              }
            case 'Q': case 'q':
              {
                 exit(0);
                 break;
              }
            case 'P': case 'p':
              {
                 start();
                 getch();
                 printf("\a");
                 system("cls");
                 break;
              }
         }
     }
}
//  GAME
void start()
{
	int j=0,i,count=0,k,win;
	char name2[30]="Computer",name1[30];
	char string[9]={'7','8','9','4','5','6','1','2','3'};
	int choice;
	printf("\n\n\n            For SINGLEPLAYER   Press : S\n");
	printf("            For MULTIPLAYER    Press : M\n");
	char type='a';

	while(type!='S'&&type!='s'&&type!='M'&&type!='m')
    {
        type=getch();
        printf("\a");
        system("cls");
    }
	printf("Made by AAK\n\n   (6-8 characters only)\n   Player 1 Enter Your Name : ");
	gets(name1);
	printf("\a");


	if(type=='M'||type=='m')
    {
	   printf("   Player 2 Enter Your Name : ");
	   gets(name2);
	   printf("\a");
    }
	system("cls");
	system("color 03");

// main loop for all 9 turns
	for(k=1;k<=10;k++)
    {
        printf("Made by AAK\n\n%s : X\n%s : O\n\n\n",name1,name2);
        printf("                |     |\n");

// for printing a board
	  for(i=0;i<3;i++)
	   {
	      printf("           ");
		  for(j=0;j<3;j++)
		    {
		           printf("  %c  ",string[count]);
		           if(j!=2)
                       printf("|");
                count++;
		    }
		  if(i!=2)
           {
		      printf("\n        --------+-----+--------\n");
           }
	   }
	   printf("\n                |     |");

// Check board for win and draw conditions
// k>4 because game never ends before 5th turn
	   if(k>4)
       {
	   if((string[6]==string[7]) && (string[6]==string[8]) ||
               (string[3]==string[4]) && (string[3]==string[5]) ||
               (string[0]==string[1]) && (string[0]==string[2]) ||
               (string[0]==string[3]) && (string[0]==string[6]) ||
               (string[1]==string[4]) && (string[1]==string[7]) ||
               (string[2]==string[5]) && (string[2]==string[8]) ||
               (string[0]==string[4]) && (string[0]==string[8]) ||
               (string[2]==string[4]) && (string[2]==string[6]))
            {
                if(win==1)
                {
                    printf("\n\n\n              *************\n"
                                 "               %s WON\n"
                                 "              *************",name1);
                                 printf("\a\a\a");
                     break;
                }
                else
                {
                    printf("\n\n\n              *************\n"
                                 "               %s WON\n"
                                 "              *************",name2);
                                 printf("\a\a\a");
                     break;
                }
            }
            else
            {
                if(k>9)
                {
                printf("\n\n\n              ***********\n"
                             "               Game draw\n"
                             "              ***********");
                             printf("\a\a\a");
                     break;
                }
            }
       }

//  For player 1 turn
	      if(k%2!=0)
            {
	               printf("\n\n\n%s\nEnter your choice : ",name1);
                while(1)
                {
	                  choice=getch();
	                  printf("\a");

	           for(i=0;i<9;i++)
               {
                   if(string[i]==choice)
                   {
                       string[i]='X';
                       win=1;
                       break;
                   }
               }
               if(win==1)
               {
                   break;
               }
               else
               {
                   printf("\n             ****************\n"
                            "              Invalid choice\n"
                            "             ****************\nRe_Enter:");
                            printf("\a");
               }
                }
    }

//  For player 2 turn
          else
            {
                if(type=='M'||type=='m')
                {
                   printf("\n\n\n                         %s\n                         Enter your choice : ",name2);
                while(1)
                {
                   choice=getch();
                   printf("\a");
	           for(i=0;i<9;i++)
               {
                   if(string[i]==choice)
                   {
                       string[i]='O';
                       win=2;
                       break;
                   }
                }
                if(win==2)
                {
                    break;
                }
                else
                {
                    printf("\n             ****************\n"
                             "              Invalid choice\n"
                             "             ****************\nRE_Enter:");
                             printf("\a");
                }
                }
                }
// For computer's turn
                else
                {
                    choice=computer(string);
                    win=2;
                }
            }
            system("cls");
            count=0;
    }
    printf("\n\nPress any key for Main Menu:");
}

int computer(char string[])
{
    int random;
    while(2)
    {
      srand(time(NULL));
      random = rand() % 9;
      if((string[random]!='X')&&(string[random]!='O'))
      {
        string[random]='O';
        break;
      }
    }
    return 0;
}

void help()
{
    char a='p';
//   HELP MENU
    while(a!='b')
    {
        printf("Made by AAK");
//for print a help menu from file

        file("Help");
        a=getch();
        printf("\a");
        system("cls");

// Help menu choices
        switch(a)
         {
            case 'A': case 'a':
              {
                 printf("Made by AAK");
                 file("About");
                 getch();
                 printf("\a");
                 system("cls");
                 break;
              }
            case 'R': case 'r':
              {
                 printf("Made by AAK");
                 file("Rules");
                 getch();
                 printf("\a");
                 system("cls");
                 break;
              }
            case 'C': case 'c':
              {
                printf("Made by AAK\n\n\n            CONROLS:-\n            -------"
                                    "\n\n            Enter number to place your mark in the corresponding box."
                       "\n\n\nPress any key:");
                 getch();
                 printf("\a");
                 system("cls");
                 break;
              }
            case 'B': case 'b':
                {
                    a='b';
                    break;
                }
         }

    }
}

// File function for printing text from file

int file(char *start)
{
    char c;
    FILE *fp;
    char temp[512];
    fp=fopen("Tic tac toe.txt","r");
    if(fp==NULL)
    {
        return(-1);
    }
    while(fgets(temp,512,fp)!=NULL)
    {
        if(strstr(temp,start))
        {
           c=getc(fp);
           while(c!='^')
           {
           printf("%c",c);
           c=getc(fp);
           }

        }
    }
    fclose(fp);
    return 0;
}
