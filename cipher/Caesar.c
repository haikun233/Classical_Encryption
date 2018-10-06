//
//  Caesar.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include "Caesar.h"

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
