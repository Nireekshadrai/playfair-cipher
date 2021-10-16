#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include<stdlib.h>
#include<windows.h>
#include "header.h" 
char str[25] = {  
        0  
    };
char key[5][5],key2[20];
void main() 
{  
    int i, j, k = 0, l, m = 0,n;  
    char ch,a;
    char keyminus[25],keystr[10];  
    char alpa[50] ="abcdefghijklmnopqrstuvwxyz" ;
    FILE *fp=fopen("playfair.txt","w");
    FILE *fk=fopen("key.txt","a");
    SetColor(3);
    printf("\n********************************ENCRYTION***************************************\n\n");
    SetColor(15);
    printf("Enter key:");  
    i=0;
    while((ch=getch())!='\r')
        {   
            key2[i]=ch;
            putchar('*');
            i++;
        }
    key2[i]='\0';
    //storing key in a file
    fprintf(fk,"%s\n",key2);
    //conversion of key to lower case
    LowerCase(key2,i);
    strcpy(keystr,key2);
    //revomal of repeated letters
    for(i=0;i<strlen(keystr);i++)
    {
        for(j=i+1;keystr[j]!='\0';j++)
        {
            if(keystr[j]==keystr[i])
            {
                for(k=j;keystr[k]!='\0';k++)
                    keystr[k]=keystr[k+1];
            }
        }
          
    } 
    printf("\nEnter the plain text:");  
    scanf("%s",str);
    //conversion of plain text to lower case
    LowerCase(str,strlen(str)); 
    printf("\n");
     //storing alpahbets other than those in key
    n = strlen(keystr);  
    j = 0;  
    for (i = 0; i < 26; i++) {  
        for (k = 0; k < n; k++) {  
            if (keystr[k] == alpa[i]) break;  
            else if (alpa[i] == 'j') break;  
        }  
        if (k == n) {  
            keyminus[j] = alpa[i];  
            j++;  
        }  
    } 
    //construct key keymatrix  
    k = 0;  
    for (i = 0; i < 5; i++) {  
        for (j = 0; j < 5; j++) {  
            if (k < n) {  
                key[i][j] = keystr[k];  
                k++;  
            } else {  
                key[i][j] = keyminus[m];  
                m++;  
            }  
            fprintf(fp,"%c ", key[i][j]);  
        }  
        fprintf(fp,"\n");  
    } 
    cipher_text(str,key); 
    delay(1);
    SetColor(3);
    printf("\n\nDO YOU WANT TO DECRYPT THE ABOVE CIPHER TEXT?? \nIf YES press y/Y\nElse press ANY-KEY to EXIT\n\n");
    SetColor(15);
    SetColor(4);
    fflush(stdin);
    scanf("%c",&a);
    printf("\n");
    SetColor(15);
    if(a=='y' || a=='Y')
    {
        decrypt();
        
    }
    else
    exit(0);
    fclose(fp);
    fclose(fk);
}


