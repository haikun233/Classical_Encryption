//
//  Rowtransposition.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/6.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include "Rowtransposition.h"


void RowtranspositionEncryption(char RPlaintext[], char Rstr[]){
    int i,j,numtext[100],numstr[100],lennumtext,lennumstr,max=0,row=0,col=0;
    
    //将明文的字符转为大写
    for(i=0,j=0;i<strlen(RPlaintext);i++)
    {
        if(RPlaintext[i]!=' ')
        {
            RPlaintext[j]=toupper(RPlaintext[i]);
            j++;
        }
        
    }
    
    //将明文字符用0-25表示
    for(i=0;i<strlen(RPlaintext);i++)
    {
        numtext[i]=RPlaintext[i]-'A';
    }
    lennumtext = i;
    
    //将密钥字符用0-9的数字表示
    for (i=0; i<strlen(Rstr); i++) {
        numstr[i] = Rstr[i] - '0';
    }
    lennumstr = i;
    
    //找出当中最大的数值
    for (i=0; i<lennumstr; i++) {
        if(numstr[i]>max)
            max=numstr[i];
    }
    
    row =lennumtext/max +1;         //矩阵行数
    col = max;                      //矩阵列数
    
    //将铭文转为row*col的字符数字矩阵
    int ciphernum[row][col];
    for(i =0;i<row;i++){
        for(j=0;j<col;j++){
            for (int k =0; k<lennumtext; k++) {
                if(i==k/8 && j==k%8){
                    ciphernum[i][j]=numtext[k];
                }
            }
        }
    }
    
    //将密钥与列的索引组成结构体数组
    struct Vkey{
        int key;
        int col;
    } vkeys[max];
    int temp1,temp2;
    
    //将密钥与列数绑定
    for (i=0; i<max; i++) {
        vkeys[i].key=numstr[i];
        vkeys[i].col=i;
    }
    
    //按照密钥从小到大对结构体数组成员进行排序
    for (i=0;i<max;i++){
        for (j=i+1; j<max; j++) {
            if(vkeys[i].key>vkeys[j].key){
                temp1 = vkeys[i].key;
                temp2 = vkeys[i].col;
                vkeys[i].key=vkeys[j].key;
                vkeys[i].col=vkeys[j].col;
                vkeys[j].key=temp1;
                vkeys[j].col=temp2;
            }
        }
    }
    
    //将对应列的字符打印下来
    for (int k=0; k<lennumstr; k++) {
        for (i=0; i<row; i++) {
            if(i==row-1&&vkeys[k].col >= lennumtext%max)
                printf("");
            else
                printf("%c",ciphernum[i][vkeys[k].col] + 'A');
        }
    }
}
