#include<stdio.h>
#include<string.h>
#define MAX 8
struct MyBin
{
    int bin[MAX];
    int dec;
    char cbin[MAX];

    MyBin();
    MyBin(int val);
    void DecToBin();
    void NotBin(int, int);
    void PrintOut();
    void rePrintOut();
    void BinToDec();
    int FindFirstZero();
};

void read()
{
    FILE *fp, *frp;
    fp = fopen("hw2.txt","r");
    frp = fopen("file.txt", "w+");
    char c[10];
    int flag = 0;
    while(!feof(fp))
    {
        MyBin a, b, ans;
        int flag = 0;
        fscanf(fp,"%s", c);
        int count = 0;
        for(int i = 0; i < MAX; i++)
        {
            if(c[i] == '0' || c[i] == '1')
                count++;
        }
        
        for(int i = MAX - count,p = 0; i < MAX; i++)
        {
           a.bin[i] = c[p] - 48;
           p++;
        }
        
        fscanf(fp,"%s", c);
        if(c[0] == '+')
            flag = 1;
        else
            flag = 0;
        

        fscanf(fp,"%s", c);
        count = 0;
        for(int i = 0; i < MAX; i++)
        {
            if(c[i] == '0' || c[i] == '1')
                count++;
        }
        
        for(int i = MAX - count, p = 0; i < MAX; i++)
        {
           b.bin[i] = c[p] - 48;
           p++;
        }

        a.BinToDec();
        b.BinToDec();
        for (int i = 0; i < MAX; i++)
        {
            fprintf(frp, "%d", a.bin[i]);
        }

        int sum = 0;
        if(flag == 1)
        {
            sum = a.dec + b.dec;
            fprintf(frp, " + ");
        }
        
        if(flag == 0)
        {
            sum = a.dec - b.dec;
            fprintf(frp, " - ");
        }
        
        printf("%d %d %d",  a.dec , b.dec, sum);

        for (int i = 0; i < MAX; i++)
        {
            fprintf(frp, "%d", b.bin[i]);
        }

        
        fprintf(frp, " = ");
        ans.dec = sum;
        ans.DecToBin();
        for (int i = MAX - 1; i >= 0; i--)
        {
            fprintf(frp, "%d", ans.bin[i]);
        }
        if(flag == 1)
            fprintf(frp, "  (%d + %d = %d)", a.dec, b.dec, ans.dec);
        else
            fprintf(frp, "  (%d - %d = %d)", a.dec, b.dec, ans.dec);
        fprintf(frp,"\n");
    }
    fclose(fp);
    fclose(frp);
}

int main()
{   
    read();
    return 0;
}





















MyBin::MyBin()
{
    for(int i = 0; i < MAX; i++)
        bin[i] = 0;
}

MyBin::MyBin(int val)
{
    for(int i = 0; i < MAX; i++)
        bin[i] = 0;
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

void MyBin::rePrintOut()
{
    for (int i = 0; i < MAX; i++)
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

void MyBin::BinToDec()
{
    int sum = 0;
    int bit = 1;
    for(int i = MAX - 1; i >= 0; i--)
    {
        if(bin[i] == 1)
            sum += bit;
        bit *= 2;
    }
    dec = sum;
}