//
//  Playfair.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include <string.h>
#include "Playfair.h"

void PlayfairEncryption(char PPlaintext[], char Pstr[]){
    int i,j,k,flag =-1, lennumtext,lenstr,templen, size,numtext[100],numstr[100],cipherkey[5][5];
    for(i=0,j=0;i<strlen(PPlaintext);i++)
    {
        if(PPlaintext[i]!=' ')
        {
            PPlaintext[j]=toupper(PPlaintext[i]);
            j++;
        }
        
    }
    PPlaintext[j]='\0';
    printf("Entered String is %s\n",PPlaintext);
    size = j;
    for(i=0;i<size;i++)
    {
        if(PPlaintext[i]!=' ')
            numtext[i]=PPlaintext[i]-'A';
    }
    lennumtext = i;
    
    for(i=0,j=0;i<strlen(Pstr);i++)
    {
        if(Pstr[i]!=' ')
        {
            Pstr[j]=toupper(Pstr[i]);
            j++;
        }
    }
    Pstr[j]='\0';
    printf("%s\n",Pstr);
    
    k=0;
    for(i=0;i<strlen(Pstr)+26;i++)
    {
        if(i<strlen(Pstr))
        {
            if(Pstr[i]=='J')
            {
                flag=8;
                printf("%d",flag);
            }
            numstr[i]=Pstr[i]-'A';
        }
        else
        {
            if(k!=9 && k!=flag)//Considering I=J and taking I in place of J except when J is there in key ignoring I
            {
                numstr[i]=k;
            }
            k++;
            
        }
    }
    templen = i;
    lenstr = removerepeated(templen, numstr);
    for (i=0; i<lenstr; i++) {
        printf("%c",numstr[i]+'A');
    }
    printf("\n");
    k=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cipherkey[i][j]=numstr[k];
            k++;
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            
            printf("%c ",cipherkey[i][j]+'A');
            
        }
        printf("\n");
    }
    
    for (i=0; i<lennumtext; i+=2) {
        if(numtext[i]==numtext[i+1])
        {
            
        }
    }
}

int removerepeated(int size,int a[])
{
    int i,j,k;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;)
        {
            if(a[i]==a[j])
            {
                
                for(k=j;k<size;k++)
                {
                    a[k]=a[k+1];
                }
                size--;
            }
            else
            {
                j++;
            }
        }
    }
    return(size);
}

void insertelementat(int position,int a[],int size)
{
    int i,insitem=23,temp[size+1];
    for(i=0;i<=size;i++)
    {
        if(i<position)
        {
            temp[i]=a[i];
        }
        if(i>position)
        {
            temp[i]=a[i-1];
        }
        if(i==position)
        {
            temp[i]=insitem;
        }
        
    }
    
    for(i=0;i<=size;i++)
    {
        a[i]=temp[i];
    }
}
