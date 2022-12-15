#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void tobit(int a[], int n, int bit){
    int i = bit - 1;
    while (n > 0)   
    {
        a[i] = n % 2;   
        i = i - 1;
        n = n / 2;
    }
    for(int i = 0; i < bit; i++)
        printf("%d",a[i]);
    printf("\n");
}

void perm(int a[],int e,int i, int bit)
{
    if(i == e) return;
    tobit(a, i, bit);
    return perm(a, e, i + 1, bit);
}

int main()
{
    int bit;
    scanf("%d", &bit);
    int *a =  (int *)malloc(sizeof(int) * bit);
    memset(a, 0, bit * sizeof(a[0]));
    perm(a, pow(2,bit),0 , bit);
}

