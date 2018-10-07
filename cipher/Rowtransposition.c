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
    
    for(i=0,j=0;i<strlen(RPlaintext);i++)
    {
        if(RPlaintext[i]!=' ')
        {
            RPlaintext[j]=toupper(RPlaintext[i]);
            j++;
        }
        
    }
    
    for(i=0;i<strlen(RPlaintext);i++)
    {
        numtext[i]=RPlaintext[i]-'A';
    }
    lennumtext = i;
    
    for (i=0; i<strlen(Rstr); i++) {
        numstr[i] = Rstr[i] - '0';
    }
    lennumstr = i;
    for (i=0; i<lennumstr; i++) {
        if(numstr[i]>max)
            max=numstr[i];
    }
    
    row =lennumtext/max +1;
    col = max;
    
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
    
    struct Vkey{
        int key;
        int col;
    } vkeys[max];
    int temp1,temp2;
    
    for (i=0; i<max; i++) {
        vkeys[i].key=numstr[i];
        vkeys[i].col=i;
    }
    
    for (i=0; i<max; i++) {
        printf("%d ",vkeys[i].key);
    }
    printf("\n");
    for (i=0; i<max; i++) {
        printf("%d ",vkeys[i].col);
    }
    printf("\n");
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
    for (i=0; i<max; i++) {
        printf("%d ",vkeys[i].key);
    }
    printf("\n");
    for (i=0; i<max; i++) {
        printf("%d ",vkeys[i].col);
    }
    printf("\n");
    
//    for (i=1; i<=max; i++) {
//        if()
//    }
    for(i =0;i<row;i++){
        for(j=0;j<col;j++){
            if(i==row-1 && j >=lennumtext % max){
                printf(" ");
            }else
                printf("%c",ciphernum[i][j]+'A');
        }
    }
    printf("\n");
    
    for (int k=0; k<lennumstr; k++) {
        for (i=0; i<row; i++) {
            if(i==row-1&&vkeys[k].col >= lennumtext%max)
                printf("");
            else
                printf("%c",ciphernum[i][vkeys[k].col] + 'A');
        }
    }

//    for(int k= 0;k<lennumstr;k++){
//        //printf("%d",numstr[k]);
//        for (j=0; j<col; j++) {
//            if(j==numstr[k]-1){
//                for (i=0; i<row; i++) {
//                    if(i==row-1 && j >=lennumtext % max)
//                        printf("");
//                    else
//                        printf("%c",ciphernum[i][j]+'A');
//                }
//            }
//        }
//    }
    
//    for (j=0; j<col; j++) {
//        for (i=0; i<row; i++) {
//            for (int k=0; k<lennumstr; k++) {
//                if(j==numstr[k]-1)
//                {
//                    printf("%c\n",ciphernum[i][j] + 'A');
//                }
//            }
//        }
//    }
}
