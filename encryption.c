#include<stdio.h>
#include<conio.h>
#include<string.h>
//to use time library
#include<time.h>
#include<windows.h>
#include "header.h"
char u[50];
int g=0;
void cipher_text(char str2[],char key[][5])
   { 
       // construct diagram and convert to cipher text  
        int i,j;
        printf("\nEntered text :%s\nCipher Text :", str2);  
        for (i = 0; i < strlen(str2); i++) 
        {  
            if (str2[i] == 'j') str2[i] = 'i';  
            if (str2[i + 1] == '\0') play_fair(str2[i], 'x', key);  
            else 
            {  
                if (str2[i + 1] == 'j') 
                    str2[i + 1] = 'i';  
                if (str2[i] == str2[i + 1]) 
                    play_fair(str2[i], 'x', key);  
                else 
                {  
                    play_fair(str2[i], str2[i + 1], key);  
                    i++;  
                }  
            }  
        } 
        u[g]='\0';
        printf("\n");  
   }

//encryption of plain text
void play_fair(char ch1, char ch2, char key[5][5]) 
{  
    int i,j,r1,c1,r2,c2;  
    for (i = 0; i < 5; i++) 
    {  
        for (j = 0; j < 5; j++) 
        {  
            if (ch1 == key[i][j]) 
            {  
                r1 = i;  
                c1 = j; 
            } 
            else if (ch2 == key[i][j]) 
            {  
                r2 = i;  
                c2 = j;
            }  
        }  
    }  
    if (r1 == r2) 
    {  
        c1 = (c1 + 1) % 5;  
        c2 = (c2 + 1) % 5;  
        printf("%c%c", key[r1][c1], key[r2][c2]); 
        u[g]=key[r1][c1];
        u[++g]=key[r1][c2];
        g++;
    } 
    else if (c1 == c2) 
    {  
        r1 = (r1 + 1) % 5;  
        r2 = (r2 + 1) % 5;  
        printf("%c%c", key[r1][c1], key[r2][c2]);  
        u[g]=key[r1][c1];  
        u[++g]=key[r2][c1];
        g++;
    } 
    else 
    {  
        printf("%c%c", key[r1][c2], key[r2][c1]); 
        u[g]=key[r1][c2];
        u[++g]=key[r2][c1]; 
        g++;   
    }   
}
//for time delay
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time 
    clock_t start_time = clock(); 
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) ;

} 

//to set colour
void SetColor(int ForgC)
 {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
         //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }
 void LowerCase(char plain[],int pl)
 {
     int i;
     for(i=0;i<pl;i++)
     {
         if(plain[i]>64 && plain[i]<91)
         plain[i]+=32;
     }
 }