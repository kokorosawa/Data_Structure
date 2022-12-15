#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct polynomial{
	int coef;                       //多項式的係數
	int expon;                      //多項式的指數
};

struct MyPoly{
	polynomial terms[MAX];          //多項式陣列
	int size;                       //多項式大小
	MyPoly();                       //建構子 初始化 size = 0
	MyPoly(const char*);            //建構子 讀入檔案
	
	void ShowPoly();                //印出多項式內容
	MyPoly Add(MyPoly);             //多項式相加
	MyPoly SingleMult(int);           //將多項式乘上一項
	int Lead_Exp();                 //回傳多項式中最大指數的次方
	MyPoly Attach(int, int);          //新增 1 個項式到多項式中
	MyPoly Remove(int);               //刪除多項式中的某一指數
	void Read(const char*);
	MyPoly Mult(MyPoly);

    // 作業2
	// MyPoly Mult(MyPoly);         //多項式相乘
};

int main(){
	MyPoly poly1;
	MyPoly poly2;
	MyPoly poly3;
	MyPoly poly4;
	MyPoly poly6;
	MyPoly poly7;
	MyPoly poly8;
	int op;
	int ceof;
	int expon;
	while(1)
	{
		printf("1. 讀入多項式\n");
		printf("2. 印出多項式內容\n");
		printf("3. 多項式相加\n");
		printf("4. 多項式相乘一數值\n");
		printf("5. 印出多項式中最大指數的係數\n");
		printf("6. 新增項式\n");
		printf("7. 刪除多項式中的項式\n");
		printf("8. 多項式相乘\n");
		printf("9. 結束程式\n");
		printf("Option:");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			poly1.Read("B1.txt");
			poly2.Read("B2.txt");
			break;
		case 2:
			printf("poly1:");
			poly1.ShowPoly();
			printf("poly2:");
			poly2.ShowPoly();
			break;
		case 3:
			poly3 = poly1.Add(poly2);
			poly3.ShowPoly();
			break;
		case 4:		
			int b;
			scanf("%d", &b);
			poly4 = poly1.SingleMult(b);
			poly4.ShowPoly();
			break;
		case 5:
			int ans;
			ans = poly1.Lead_Exp();
			printf("%d\n", ans);
			break;
		case 6:
			printf("coef:");
			scanf("%d", &ceof);
			printf("expon:");
			scanf("%d", &expon);
			poly6 = poly1.Attach(ceof, expon);
			poly6.ShowPoly();
			break;
		case 7:
			printf("expon:");
			scanf("%d", &expon);
			poly7 = poly1.Remove(expon);
			poly7.ShowPoly();
			break;
		case 8:
			poly8 = poly1.Mult(poly2);
			poly8.ShowPoly();
			break;
		case 9:
			exit(0);
			break;		
		default:
			break;
		}
	}
	return 0;
} 

MyPoly::MyPoly()
{
	size = 0;
}

MyPoly::MyPoly(const char* filename)
{	
	FILE *fptr;
	fptr = fopen(filename, "r");
	size = 0;
	while(!feof(fptr))
	{
		fscanf(fptr, "%d %d", &terms[size].coef, &terms[size].expon);
		size++;
	}
}

void MyPoly::Read(const char* filename)
{
	FILE *fptr;
	fptr = fopen(filename, "r");
	size = 0;
	while(!feof(fptr))
	{
		fscanf(fptr, "%d %d", &terms[size].coef, &terms[size].expon);
		size++;
	}
}

void MyPoly::ShowPoly()
{
	for(int i = 0 ; i < size; i++)
	{
		printf("%dx^%d+", terms[i].coef, terms[i].expon);
	}
	printf("\b \n");
}

MyPoly MyPoly::SingleMult(int b)
{
	MyPoly res;
	for(int i = 0; i < size; i++)
	{
		res.terms[i].coef = terms[i].coef * b;
		res.terms[i].expon = terms[i].expon;
		res.size++;
	}
	return res;
}

MyPoly MyPoly::Add(MyPoly B)
{
	MyPoly res;
	int b1 = 0,b2 = 0;
	int resize = size + B.size;
	for(int i = 0; i < resize; i++)
	{
		if(terms[b1].expon == B.terms[b2].expon)
		{
			res.terms[i].coef = terms[b1].coef + B.terms[b2].coef;
			res.terms[i].expon = terms[b1].expon;
			b1++;
			b2++;
			resize--;
		}
		else if(terms[b1].expon > B.terms[b2].expon)
		{
			res.terms[i].coef = terms[b1].coef;
			res.terms[i].expon = terms[b1].expon;
			b1++;
		}
		else if(terms[b1].expon < B.terms[b2].expon)
		{
			res.terms[i].coef = B.terms[b2].coef;
			res.terms[i].expon = B.terms[b2].expon;
			b2++;
		}
			
		res.size++;
	}
	return res;
}

int MyPoly::Lead_Exp()
{	
	return terms[0].expon;
}

MyPoly MyPoly::Attach(int coef, int expon)	
{
	MyPoly res;
	res.terms[0].coef = coef;
	res.terms[0].expon = expon;
	for(int i = 1; i < size + 1; i++)
	{
		res.terms[i].coef = terms[i - 1].coef;
		res.terms[i].expon = terms[i - 1].expon;
	}
	res.size = size + 1;
	return res;
}
MyPoly MyPoly::Remove(int num)
{
	MyPoly res;
	int i;
	for(i = 0; i < size; i++)
	{	
		if(terms[i].expon == num)
			break;
		res.terms[i].coef = terms[i].coef;
		res.terms[i].expon = terms[i].expon;
		res.size++;
	}
	
	for(i = i; i < size - 1; i++)
	{	
		res.terms[i].coef = terms[i + 1].coef;
		res.terms[i].expon = terms[i + 1].expon;
		res.size++;
	}

	return res;
}

MyPoly MyPoly::Mult(MyPoly b) 
{
    MyPoly res;
	int tempsize = 0;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < b.size; j++)
		{
			res.terms[tempsize].coef = terms[i].coef * b.terms[j].coef;
			res.terms[tempsize].expon = terms[i].expon + b.terms[j].expon;
			tempsize++;
		}
	}
	res.size = tempsize;
	return res;
}

