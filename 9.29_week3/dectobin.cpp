#include<stdio.h>
#include<string.h>
#define MAX 10
struct MyBin
{
    int bin[MAX];
    int dec;

    MyBin();
    MyBin(int val);
    void DecToBin();
    void NotBin(int, int);
    void PrintOut();
    int FindFirstZero();
};


int main()
{
    MyBin a(-50);
    a.PrintOut();
    return 0;
}

MyBin::MyBin()
{
    memset(bin, 0, sizeof(bin) * MAX);
}

MyBin::MyBin(int val)
{
    memset(bin, 0, sizeof(bin) * MAX);
    dec = val;
    DecToBin();
}

void MyBin::DecToBin()
{
    int temp = dec, i = 0;
    if(temp > 0)
    {
        while(temp != 0)
        {
            bin[i] = temp % 2;
            temp /= 2;
            i++;
        }
    }
    else
    {
        while(temp != 0)
        {
            bin[i] = temp % 2;
            temp /= 2;
            i++;
        }
        NotBin(0, MAX - 1);
        int first = FindFirstZero();
        NotBin(0, first);
    }
    
}

void MyBin::NotBin(int a,int b)
{
    for(int i = b; i >= a; i--)
    {
        if(bin[i] == 0)
            bin[i] = 1;
        else
            bin[i] = 0;
    }
    
}

void MyBin::PrintOut()
{
    for (int i = MAX - 1; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }   
}

int MyBin::FindFirstZero()
{   
    int res;
    for(int i = MAX; i >= 0; i--)
    {
        if(bin[i] == 0)
            res = i;
    }
    return res;
}
        