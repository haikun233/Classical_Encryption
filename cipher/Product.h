//
//  Product.h
//  cipher
//
//  Created by 张海鲲 on 2018/10/7.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#ifndef Product_h
#define Product_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Pro {
    int  Pro_Index;
    char Pro_Plaint;
};

void ProductEncryption(char ProPlaintext[], char Prokey[]);

#endif /* Product_h */
