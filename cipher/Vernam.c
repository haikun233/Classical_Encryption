//
//  Vernam.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/6.
//  Copyright © 2018年 张海鲲. All rights reserved.
//
#include <string.h>
#include "Vernam.h"

void VernamEncryption(char VPlaintext[], char Vstr[]){
    int i,j,numtext[100],numstr[100],ciphernum[100];
    
    //将明文的字符转为大写
    for(i=0,j=0;i<strlen(VPlaintext);i++)
    {
        if(VPlaintext[i]!=' ')
        {
            VPlaintext[j]=toupper(VPlaintext[i]);
            j++;
        }
    }
    VPlaintext[j]='\0';
    
    //将明文字符用0-25表示
    for(i=0;i<strlen(VPlaintext);i++)
    {
        numtext[i]=VPlaintext[i]-'A';
    }
    
    //将密钥字符转为大些
    for(i=0,j=0;i<strlen(Vstr);i++)
    {
        if(Vstr[i]!=' ')
        {
            Vstr[j]=toupper(Vstr[i]);
            j++;
        }
    }
    Vstr[j]='\0';
    
    //将密钥字符转为0-25表示
    for(i=0;i<strlen(Vstr);i++)
    {
        numstr[i]=Vstr[i]-'A';
    }
    
    //将密钥后面接上明文形成新的密钥
    int temp[100];
    for(i=0;i<strlen(VPlaintext);i++){
        if(i<strlen(Vstr))
            temp[i]=numstr[i];
        else
            temp[i]=numtext[i-strlen(Vstr)];
    }
    
    //将明文与密钥进行XOR形成密文
    for (i=0; i<strlen(VPlaintext); i++) {
        ciphernum[i]= (numtext[i] ^ temp[i])%26;
    }
    
    //打印密文
    for(i=0;i<strlen(VPlaintext);i++)
    {
        printf("%c",ciphernum[i]+'A');
    }
}
