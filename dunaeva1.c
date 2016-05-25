#include<stdio.h>

#pragma warning(disable: 4996)

#define N 20
system();

int main(void){
	int A[N];
	int i = 0,
		j = 0,
		curNum = 0,
		maxNum = 0,
		curModa = 0,
		maxModa = 0,
		flagModa = 0;

	printf("Insert array A[], a number of elements = %d\n", N);

	while(1){	
		if(!scanf("%d", &A[i])){
			printf("Wrong enter!\n");
			printf("Insert array A[], a number of elements = %d\n", N);
			fflush(stdin);
			i = 0;
		}
		i++;
		if(i == N){
			break;
		}
	}

	for (i = 0; i < N; i++){
		curNum = 0;
		for(j = 0; j < N; j++){
			if(A[i]==A[j]){
				curNum++;
			}
		}
		if(curNum > maxModa){
			maxModa = curNum;
			maxNum = A[i];
		}
		if(curNum == maxModa){
			flagModa = 0;
		}
		if(maxModa > 1){
			flagModa = 1;
		}
		curModa = maxNum;
	}

	if(flagModa){
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
