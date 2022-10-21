#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct polynomial{
	int coef;                       //�h�������Y��
	int expon;                      //�h����������
};

struct MyPoly{
	polynomial terms[MAX];          //�h�����}�C
	int size;                       //�h�����j�p
	MyPoly();                       //�غc�l ��l�� size = 0
	MyPoly(const char*);            //�غc�l Ū�J�ɮ�
	
	void ShowPoly();                //�L�X�h�������e
	MyPoly Add(MyPoly);             //�h�����ۥ[
	MyPoly SingleMult(int);           //�N�h�������W�@��
	int Lead_Exp();                 //�^�Ǧh�������̤j���ƪ�����
	MyPoly Attach(int, int);          //�s�W 1 �Ӷ�����h������
	MyPoly Remove(int);               //�R���h���������Y�@����
	void Read(const char*);
	MyPoly Mult(MyPoly);

    // �@�~2
	// MyPoly Mult(MyPoly);         //�h�����ۭ�
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
		printf("1. Ū�J�h����\n");
		printf("2. �L�X�h�������e\n");
		printf("3. �h�����ۥ[\n");
		printf("4. �h�����ۭ��@�ƭ�\n");
		printf("5. �L�X�h�������̤j���ƪ��Y��\n");
		printf("6. �s�W����\n");
		printf("7. �R���h������������\n");
		printf("8. �h�����ۭ�\n");
		printf("9. �����{��\n");
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

