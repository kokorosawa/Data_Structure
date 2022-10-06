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
	MyPoly SingleMult(polynomial);           //將多項式乘上一項
	int Lead_Exp();                 //回傳多項式中最大指數的次方
	void Attach(int, int);          //新增 1 個項式到多項式中
	void Remove(int);               //刪除多項式中的某一指數

    // 作業2
	// MyPoly Mult(MyPoly);         //多項式相乘
};

int main(){
	MyPoly poly1("B1.txt");
	MyPoly poly2("B2.txt");
	MyPoly poly3;
	poly1.ShowPoly(); 
	poly2.ShowPoly();
	polynomial t;
	t.coef = 10;
	t.expon = 10;
	poly3 = poly1.Add(poly2);
	poly3.ShowPoly();
	return 0;
} 

MyPoly::MyPoly()
{
	size = 0;
}

MyPoly::MyPoly(const char* filename)
{	
	FILE *fptr = nullptr;
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

MyPoly MyPoly::SingleMult(polynomial p)
{
	MyPoly res;
	for(int i = 0; i < size; i++)
	{
		res.terms[i].coef = terms[i].coef * p.coef;
		res.terms[i].expon = terms[i].expon + p.expon;
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

void MyPoly::Attach(int coef, int expon)	
{
	
}
void MyPoly::Remove(int num)
{
	
}

// MyPoly MyPoly::Mult(MyPoly B)
// {
    
// }

