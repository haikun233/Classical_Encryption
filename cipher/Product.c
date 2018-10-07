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
    for(i=0,j=0;i<strlen(ProPlaintext);i++)
    {
        if(ProPlaintext[i]!=' ')
        {
            ProPlaintext[j]=toupper(ProPlaintext[i]);
            j++;
        }
        
    }
    lentext = i;
    
    struct Pro pro[lentext];
    for (i=0; i<lentext; i++) {
        pro[i].Pro_Index= i+1;
        pro[i].Pro_Plaint=ProPlaintext[i];
    }
    
    for (i=0; i<strlen(Prokey); i++) {
        for (j=0; j<lentext;j++) {
            if(Prokey[i]==pro[j].Pro_Index)
                printf("%c",pro[j].Pro_Plaint);
        }
    }
}
