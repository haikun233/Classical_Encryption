//
//  Playfair.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include "Playfair.h"

void PlayfairEncryption(char PPlaintext[], char Pstr[]){
    int i,j,k;          //循环控制语句的变量
    int size;           //明文字符数组的长度
    int lennumtext;     //明文字符数字表示数组的长度
    int numtext[100];   //明文字符的数字表示数组
    int flag =-1;       //用来判定密钥字符是否含有字符J
    int numstr[100];    //密钥的数字表示数组
    int templen;        //密钥数字表示数组的长度
    int lenstr;         //去掉重复数字的密钥数字数组的长度
    int cipherkey[5][5];//密钥5*5矩阵
    int numcipher[100]; //密文字符数字数组
    int row1=0,col1=0,row2=0,col2=0;//矩阵行，列坐标
    
    
    //将明文的字符转为大写
    for(i=0,j=0;i<strlen(PPlaintext);i++)
    {
        if(PPlaintext[i]!=' ')
        {
            PPlaintext[j]=toupper(PPlaintext[i]);
            j++;
        }
        
    }
    PPlaintext[j]='\0';
    size = j;
    
    //将明文字符用0-25表示
    for(i=0;i<size;i++)
    {
        if(PPlaintext[i]!=' ')
            numtext[i]=PPlaintext[i]-'A';
    }
    lennumtext = i;
    
    //将密钥字符转为大些
    for(i=0,j=0;i<strlen(Pstr);i++)
    {
        if(Pstr[i]!=' ')
        {
            Pstr[j]=toupper(Pstr[i]);
            j++;
        }
    }
    Pstr[j]='\0';
    
    
    //将密钥字符转为0-25表示，flag为-1时，表示密钥中没有字符J，在后面的密钥中用I代替J，flag为8是，表示密钥中出现J，则后面的密钥中忽略I
    k=0;
    for(i=0;i<strlen(Pstr)+26;i++)
    {
        if(i<strlen(Pstr))
        {
            if(Pstr[i]=='J')
            {
                flag=8;
            }
            numstr[i]=Pstr[i]-'A';
        }
        else
        {
            if(k!=9 && k!=flag)
            {
                numstr[i]=k;
            }
            k++;
            
        }
    }
    templen = i;
    lenstr = removerepeated(templen, numstr);
    
    //将密钥数字数组转为5*5的数列
    k=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cipherkey[i][j]=numstr[k];
            k++;
        }
    }
    
    //将明文两两一组，如果两个字符相同，在后面的字符中插入字符X
    for (i=0; i<lennumtext; i+=2) {
        if(numtext[i]==numtext[i+1])
        {
            insertelementat(i+1, numtext, lennumtext);
            lennumtext++;
        }
    }
    
    //如果有单个字符，就在后面插入字符X
    if (lennumtext%2!=0) {
        insertelementat(lennumtext, numtext, lennumtext);
        lennumtext++;
    }
    
    
    for (k=0; k<lennumtext; k+=2) {
        for(i=0;i<5;i++){
            for (j=0; j<5; j++) {
                if(numtext[k]==cipherkey[i][j])             //将明文中连续两个字符的前一个字符与，密钥数列中的位置相匹配
                {
                    row1=i;
                    col1=j;
                }
                if (numtext[k+1] == cipherkey[i][j]) {      //将明文中连续两个字符的后一个字符与，密钥数列中的位置相匹配
                    row2=i;
                    col2=j;
                }
            }
        }
        if(row1==row2)                                          //两个字符在同一行，找出两个字符右边的一个字符，如果字符在最右边，则返回行第一个
        {
            col1=(col1+1)%5;
            col2=(col1+1)%5;
            numcipher[k]=cipherkey[row1][col1];
            numcipher[k+1]=cipherkey[row2][col2];
        }
        if(col1==col2)                                          //两个字符在同一列，找出两个字符下边的一个字符，如果字符在最下边，则返回列第一个
        {
            row1=(row1+1)%5;
            row2=(row2+1)%5;
            numcipher[k]=cipherkey[row1][col1];
            numcipher[k+1]=cipherkey[row2][col2];
        }
        if(row1!=row2&&col1!=col2)                              //如果字符不在同一行，不在同一列，则返回，两个字符组成矩形的另外两个字符
        {
            numcipher[k]=cipherkey[row1][col2];
            numcipher[k+1]=cipherkey[row2][col1];
        }
    }
    for (i=0; i<lennumtext; i++) {                              //打印密文字符数字的对应字符
        printf("%c",numcipher[i]+'A');
    }
}


//移除数组中相等的数字，返回修改后的数组长度
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

//在数组特定的位置，插入字符X
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
