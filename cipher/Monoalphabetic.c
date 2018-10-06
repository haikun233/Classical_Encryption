//
//  Monoalphabetic.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include "Monoalphabetic.h"

void MonoalphabeticEncryption(char MPlaintext[], char Mstr[]){
    struct Mkey mkeys [26];
    for(int i = 0;i < 26; i++){
        mkeys[i].Mon_Plain=i+'a';
        mkeys[i].Mon_Cipher=Mstr[i];
    }
//    struct Mkey mkeys [26] = {{'a','Q'},{'b','W'},{'c','E'},{'d','R'},
//        {'e','T'},{'f','Y'},{'g','U'},{'h','I'},
//        {'i','O'},{'j','P'},{'k','A'},{'l','S'},
//        {'m','D'},{'n','F'},{'o','G'},{'p','H'},
//        {'q','J'},{'r','K'},{'s','L'},{'t','Z'},
//        {'u','X'},{'v','C'},{'w','V'},{'x','B'},
//        {'y','N'},{'z','M'}};
//    for(int i = 0; i < strlen(MPlaintext); i++){
//        for(int j = 0; j < 26; j++){
//            if(MPlaintext[i] == mkeys[j].Mon_Plain)
//                printf("%c",mkeys[j].Mon_Cipher);
//        }
//    }
    int k =0;
    while (MPlaintext[k]!='\0'){
        for(int j = 0; j < 26; j++){
            if(MPlaintext[k] == mkeys[j].Mon_Plain)
                printf("%c",mkeys[j].Mon_Cipher);
        }
        k++;
    }
}

