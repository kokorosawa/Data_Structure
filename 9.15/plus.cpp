#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	srand(0);
	int n = 0;
	int *a;
	bool t[100];
	scanf("%d", &n);
	a = (int *)malloc(n * n * sizeof(int));
	memset(t, false, 100*sizeof(t[0]));
	for(int i = 0; i < n * n; i++){
		if(i % n == 0)
			printf("\n");
		while(1){
			int temp =  rand() % 100;
			if(!t[temp]){
				a[i] =  temp + 101;
				t[temp] = true;
				break;
			}else
				temp =  rand() % 100;
		}
		printf("%4d", a[i]);
	} 
} 
