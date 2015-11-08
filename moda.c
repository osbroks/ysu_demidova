#include<stdio.h>
 
#pragma warning(disable: 4996)
 
#define N 20
system();
 
int main(void){
    int A[N];
    int i = 0,
        j = 0,
        len = 0,
        curNum = 0, //chastota vstrechanii
        maxNum = 0, //chastota modi
        curModa = 0, //tekuschaya moda
        maxModa = 0,
        flag = 0;
 
        printf("Insert array A[], a number of elements max 20: ");
        scanf("%d", &len);
 
    while(1){
        if(!scanf("%d", &A[i])){
            printf("Wrong enter!\n");
            printf("Insert array A[], a number of elements = %d\n", len);
            fflush(stdin);
            i = 0;
        }
        i++;
        if(i == len){
            break;
        }
    }
 
    for (i = 0; i < len; i++){
        curNum = 0;
        for(j = 0; j < len; j++){
            if(A[i]==A[j]){
                curNum++;
            }
        }
        if(curNum > maxModa){
            flag = 1;
            maxModa = curNum;
            maxNum = A[i];
        }
        else if(curNum == maxModa && A[i] != maxNum){
            flag = 0;
        }
        
        curModa = maxNum;
    }
 
    if(flag){
        printf("chastota vstrechanii: %d\nmoda: %d\n", maxModa, curModa);
    }
    else{
        printf("No moda\n");
        system("PAUSE");
        return;
    }
 
    system("PAUSE");
    return 0;
}
