#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	srand(0);
	int n = 0;
	int a[5][5];
	bool t[100];
	memset(t, false, 100*sizeof(t[0]));
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5;j++){
			while(1){
			int temp =  rand() % 100;
			if(!t[temp]){
				a[i][j] =  temp + 101;
				t[temp] = true;
				break;
			}else
				temp =  rand() % 100;
			}
			 printf("%4d", a[i][j]);
		}
		printf("\n");
	} 
} 
