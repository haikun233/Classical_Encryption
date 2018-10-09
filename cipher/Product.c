//
//  Product.c
//  cipher
//
//  Created by 张海鲲 on 2018/10/7.
//  Copyright © 2018年 张海鲲. All rights reserved.
//

#include "Product.h"


void ProductEncryption(char ProPlaintext[], char Prokey[]){
    
    int i , j, lentext;
    
    //将明文的字符转为大写
    for(i=0,j=0;i<strlen(ProPlaintext);i++)
    {
        if(ProPlaintext[i]!=' ')
        {
            ProPlaintext[j]=toupper(ProPlaintext[i]);
            j++;
        }
        
    }
    lentext = i;
    
    //创建序号与明文字符对应的结构体数组
    struct Pro pro[lentext];
    
    //对结构体的变量进行赋值
    for (i=0; i<lentext; i++) {
        pro[i].Pro_Index= i+1;
        pro[i].Pro_Plaint=ProPlaintext[i];
    }
    
    //按照密钥的顺序输出成密文
    for (i=0; i<strlen(Prokey); i++) {
        for (j=0; j<lentext;j++) {
            if(Prokey[i]==pro[j].Pro_Index)
                printf("%c",pro[j].Pro_Plaint);
        }
    }
}
