//
//  main.c
//  cipher
//
//  Created by 张海鲲 on 2018/9/30.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Caesar.h"
#include "Monoalphabetic.h"
#include "Playfair.h"

#define SLEN 100

int main(int argc, const char * argv[]) {
    
    int num=0, numkey = 0;
    char strkey[SLEN];
    char Ptext[SLEN];
    printf("******************************************\n");
    printf("1.Caesar cipher\n");
    printf("2.Monoalphabetic cipher\n");
    printf("3.Playfair cipher\n");
    printf("4.Vernam proposed the autokey system\n");
    printf("5.Row transposition\n");
    printf("6.Product cipher\n");
    printf("******************************************\n");
    printf("%d",'k');
    printf("%c",'k'+7);
    while (1) {
        printf("Please enter the corresponding number(1-6):\n");
        scanf("%d",&num);
        if(num >=1 && num <=6){
            printf("Enter your Plaintext:\n");
            scanf("%s",Ptext);
            switch (num) {
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
                    puts("CipherText in Monoalphabetic:");
                    MonoalphabeticEncryption(Ptext, strkey);
                    printf("\n");
                    break;
                case 3:
                    printf("Enter the string key:\n");
                    scanf("%s",strkey);
                    PlayfairEncryption(Ptext,strkey);
                    printf("\n");
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                default:
                    break;
            }
            break;
        }else{
            printf("Sorry,your input is incorrect,please re-enter!!!\n");
        }
    }
}


