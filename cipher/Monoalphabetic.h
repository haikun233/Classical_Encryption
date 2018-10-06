//
//  Monoalphabetic.h
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#ifndef Monoalphabetic_h
#define Monoalphabetic_h

#include <stdio.h>

struct Mkey {
    char Mon_Plain;
    char Mon_Cipher;
};

void MonoalphabeticEncryption(char MPlaintext[], char Mstr[]);

#endif /* Monoalphabetic_h */
