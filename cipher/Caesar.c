//
//  Caesar.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include "Caesar.h"

//将密文的ascii码值+7，打印出对应的字符，如果超出122就将超出的部分加上96得到相应的字符
void CaesarEncryption(char CPlaintext[], int Ckey){
    char Cbuffer[100];
    for(int i = 0; i < strlen(CPlaintext); i++){
        Cbuffer[i] = CPlaintext[i] + Ckey;
        if((Cbuffer[i] >= 97)&&(Cbuffer[i] <= 122))
            printf("%c", Cbuffer[i]);
        else if(Cbuffer[i] > 122){
            Cbuffer[i] = 96 + Cbuffer[i] - 122;
            printf("%c", Cbuffer[i]);
        }
    }
}
