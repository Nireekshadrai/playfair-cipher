#include<stdio.h> 
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "header.h" 
extern char str[100];
extern char key[5][5],key2[20],u[50];
char s[100];int p=0;  int q=0,c=0;
//decryption 
void decrypt() 
{  
    int i, j, k = 0, m = 0, n,count=0;  
    char ch;
    char keyminus[25],keystr[10], key3[20],str1[25] = {  
        0  
    };  
    char alpa[50] ="abcdefghijklmnopqrstuvwxyz" ;
    c++;
    if(c>3)
    {
        SetColor(4);
        printf("You have entered wrong key more than thrice \n ACCESS DENIED!!!!");
        SetColor(15);
        exit(0);
    }
    printf("Enter key:");  
    i=0;
    while((ch=getch())!='\r')
        {   key3[i]=ch;
            putchar('*');
            if(ch==key2[i])
            {
                count++;
            }
            i++;
        }
    //entry of wrong key
    if(count!=strlen(key2))
        {
          SetColor(4);
          printf("\nYou have entered wrong key\n\n"); 
          SetColor(15);
          decrypt();
          exit(0);

        }
    key3[i]='\0';
    LowerCase(key3,i);
    strcpy(keystr,key3);
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
    printf("\nEnter the cipher text:");  
    scanf("%s",str1);
    //conversion of cipher text to lower case
    LowerCase(str1,strlen(str1)); 
    if(strcmp(u,str1)!=0)
     {
         SetColor(4);
         printf("\nEntered cipher text doesn't match\n\n") ;
         SetColor(15);
         decrypt();
         exit(0);
     }
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
    plain_text(str1,key);
    int l=2*q;
    s[l]='\0';
    if(strcmp(str,s)!=0)
    {
        specialcase(l);
    }
    printf("%s",s); 
}

void plain_text(char str1[],char key[][5])
   { 
    // construct diagram and convert to cipher text  
    int i,j;
    printf("\n\nCipher text :%s\nPlain text :", str1);  
    for (i = 0; i < strlen(str1); i++) 
    {  
        if (str1[i] == 'j') str1[i] = 'i';    
        else 
        {  
            if (str1[i + 1] == 'j') str1[i + 1] = 'i';  
            else 
            {  
                play_fair_decrypt(str1[i], str1[i + 1], key);  
                i++;  
            }  
        } 
     }
   }
 //decryption of cipher text
void play_fair_decrypt(char ch1, char ch2, char key[5][5]) 
{
    q++;
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
    {  if(c1==0)
            c1=5;
        if(c2==0)
            c2=5;
        c1 = (c1 - 1) % 5;  
        c2 = (c2 - 1) % 5; 
        s[p]=key[r1][c1];       //storing cipher text
        s[++p]=key[r1][c2];
        
        p++;
        
        
    } 
    else if (c1 == c2) 
    {  
           if(r1==0)
                r1=5;
           if(r2==0)
                r2=5;
            r1 = (r1 - 1) % 5;  
            r2 = (r2 - 1) % 5;  
          
            s[p]=key[r1][c1];  
            s[++p]=key[r2][c1];
            
            p++;
            
    } 
    else 
    {  
    
        s[p]=key[r1][c2];
        s[++p]=key[r2][c1];  

        p++;   
    }   
}

//decryption for special cases
void specialcase(int l)
{
    int i,j;
    for(i=0;(i<strlen(str));i++)
    {
        if(str[i]==str[i+1] )
            break;
    }
        if(i!=strlen(str) && (i%2==0))//checking for consecutive letters at odd position
        { 
            for(j=i+1;j<l;j++)
                {
                    s[j]=s[j+1]; 
                }
            s[j]='\0';
            if(strlen(str)%2==0)
                s[j-2]='\0';
        }
    else
    {
        if(strlen(str)%2!=0)
              s[l-1]='\0';
    }
}
