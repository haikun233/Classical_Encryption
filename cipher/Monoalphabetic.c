//
//  Monoalphabetic.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include "Monoalphabetic.h"


//将密文和明文对应的形式用结构体数组表现出来，一一对应查询并打印
void MonoalphabeticEncryption(char MPlaintext[], char Mstr[]){
    struct Mkey mkeys [26];
    for(int i = 0;i < 26; i++){
        mkeys[i].Mon_Plain=i+'a';
        mkeys[i].Mon_Cipher=Mstr[i];
    }
    int k =0;
    while (MPlaintext[k]!='\0'){
        for(int j = 0; j < 26; j++){
            if(MPlaintext[k] == mkeys[j].Mon_Plain)
                printf("%c",mkeys[j].Mon_Cipher);
        }
        k++;
    }
}

