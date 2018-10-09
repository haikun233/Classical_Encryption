//
//  main.c
//  cipher
//
//  Created by 张海鲲 on 2018/9/30.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Caesar.h"
#include "Monoalphabetic.h"
#include "Playfair.h"
#include "Vernam.h"
#include "Rowtransposition.h"
#include "Product.h"

#define SLEN 100

int chk_data( char *num )
{
    int i;
    for( i=0;num[i];i++ )
    {
        if ( num[i] >'6'|| num[i] <'1' ) //只要有非数字，就返回错误
            return 0;
    }
    if ( i>4 ) //都是数字，但长度超过4位，返回错误
        return 0;
    return 1;
}

int main(int argc, const char * argv[]) {
    
    int numkey = 0, numkeys[100], n=0;
    char num[SLEN];
    char Ptext[SLEN];                               //声明明文变量
    char strkey[SLEN];                              //声明密钥变量
    printf("******************************************\n");
    printf("1.Caesar cipher\n");
    printf("2.Monoalphabetic cipher\n");
    printf("3.Playfair cipher\n");
    printf("4.Vernam proposed the autokey system\n");
    printf("5.Row transposition\n");
    printf("6.Product cipher\n");
    printf("******************************************\n");
    
    /*
     输入数字1-6，对应六种不同的加密方法，按照输入的明文和密钥，打印出相应的密文
     */
    while ( 1 )
    {
        printf("Please enter the corresponding number(1-6):\n");
        scanf("%s", num );
        if ( chk_data( num )==0 )
        {
            printf("Sorry,your input is incorrect,please re-enter!!!\n");
        }
        else{
            printf("Enter your Plaintext:\n");
            scanf("%s",Ptext);
            switch (atoi(num)) {
                case 1:
                    printf("Enter the number key:\n");
                    scanf("%d",&numkey);
                    puts("CipherText in Caesar:");
                    CaesarEncryption(Ptext, numkey);
                    printf("\n");
                    break;
                case 2:
                    printf("Enter the string key(in order of a-z):\n");
                    scanf("%s",strkey);
                    printf("CipherText in Monoalphabetic:");
                    MonoalphabeticEncryption(Ptext, strkey);
                    printf("\n");
                    break;
                case 3:
                    printf("Enter the string key:\n");
                    scanf("%s",strkey);
                    printf("CipherText in Playfair:\n");
                    PlayfairEncryption(Ptext,strkey);
                    printf("\n");
                    break;
                case 4:
                    printf("Enter the string key:\n");
                    scanf("%s",strkey);
                    printf("CipherText in Vernam proposed the autokey system:\n");
                    VernamEncryption(Ptext, strkey);
                    printf("\n");
                    break;
                case 5:
                    printf("Enter the string key:\n");
                    scanf("%s",strkey);
                    printf("CipherText in Rowtransposition:\n");
                    RowtranspositionEncryption(Ptext, strkey);
                    printf("\n");
                    break;
                case 6:
                    printf("Enter the key:\n");
                    for(int i=0;;i++){
                        scanf("%d",&numkeys[i]);
                        n++;
                        if(getchar()=='\n')
                            break;
                    }
                    for (int i=0; i<n; i++) {
                        strkey[i]=numkeys[i];
                    }
                    printf("CipherText in Product Ciphers:\n");
                    ProductEncryption(Ptext, strkey);
                    printf("\n");
                    break;
                default:
                    break;
            }
            break;
        }
    }
}

