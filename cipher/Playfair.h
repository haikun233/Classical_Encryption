//
//  Playfair.h
//  cipher
//
//  Created by 张海鲲 on 2018/10/2.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#ifndef Playfair_h
#define Playfair_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int removerepeated(int size,int a[]);

void insertelementat(int position,int a[],int size);

void PlayfairEncryption(char PPlaintext[], char Pstr[]);

#endif /* Playfair_h */
