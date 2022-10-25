#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 40
#define Len 20

struct LongInt
{
	int MyInt[MAX];
	bool IsPositive;
	
	LongInt();
	LongInt(int);
	LongInt(const char*);
	void Init();   					//�Q�ζüƲ��ͤ@�Ӫ��פp��19����
	void Init(int num);  			//���w�@�Ӫ��פp��19����
	LongInt operator=(int); 			//�B��l�h��
	void Zero();  					//�N�������}�C��l��0
	void Show();
	void Showlong(); 					//��ܰ}�C
	
	int Compare(LongInt b); 		//�������������b������̸��j�A�Y�j��b�h�^��1�A�Ϥ��A�h�^��-1
	bool operator>(LongInt b);
	bool operator<(LongInt b);
	bool operator==(LongInt b);
	
	LongInt Add(LongInt);
	LongInt operator+(LongInt); 	//�B��l�h��
	LongInt Sub(LongInt);
	LongInt operator-(LongInt); 	//�B��l�h��     123456
	
//	HW
	LongInt Multi(LongInt);
	LongInt operator*(LongInt); 
	LongInt Div(LongInt);
	LongInt operator/(LongInt); 
};

int main(){
	LongInt a = "99999999999999999999";
	LongInt b = "99999999999999999999";  // '1' - '0'  char s[]="12345.....", s[i]-'0'
	LongInt c;
	LongInt t = "18468284177722972105";
	LongInt s = "57485431294651594451"; 
	printf("a=");
	a.Show();
	printf("b=");
	b.Show();

	c = b * a;
	printf("b*c=\n");
	c.Showlong();

	printf("a=");
	t.Show();
	printf("b=");
	s.Show();

	c = t * s;
	printf("b*c=\n");
	c.Showlong();
	return 0;
}

//==================================================== 
LongInt::LongInt()
{
	Zero();
	IsPositive=true;
	srand(time(NULL));
	for(int i=0;i<Len;i++)
	{
		MyInt[i]=rand()%10;
	}
	
}
//====================================================
LongInt::LongInt(int num)
{
	Zero();
	IsPositive=true;
	srand(time(NULL));
	if(num>=0)
		IsPositive=true;
	else
	{
		IsPositive=false;
		num = num *-1;
	}
	for(int i=0;i<Len;i++)
	{
		MyInt[i]=num%10;
		num=num/10;
	}
	
}
//====================================================
LongInt::LongInt(const char *str)
{
	int i=0; 
	int len=strlen(str); 
	Zero();
	IsPositive = true;
	while(str[i]!='\0')
	{
		MyInt[i]=str[len-1-i]-'0';
		i++;
	}
}
//====================================================
//====================================================
void LongInt::Zero()
{
	for(int i=0;i<MAX;i++)
	{
		MyInt[i]=0;
	}
}
//====================================================
void LongInt::Show()
{
	if(IsPositive) printf(" ");
	else printf("-");
	for(int i=Len-1;i>=0;i--)
	{
		printf("%d", MyInt[i]);
	}
	printf("\n");
}

void LongInt::Showlong()
{
	if(IsPositive) printf(" ");
	else printf("-");
	for(int i = MAX-1;i >=0;i--)
	{
		printf("%d", MyInt[i]);
	}
	printf("\n");
}
//====================================================
LongInt LongInt::Add(LongInt b)
{
	LongInt result=0;
	for(int i=0;i<Len;i++)
	{
		result.MyInt[i] = MyInt[i] + b.MyInt[i];
	}
	
	for(int i=0;i<Len;i++)
	{
		if(result.MyInt[i]>=10)
		{
			result.MyInt[i+1]+=result.MyInt[i]/10;
			result.MyInt[i]=result.MyInt[i]%10;
		}
	}

	return result;
}
//====================================================
LongInt LongInt::operator+(LongInt b)
{
	return Add(b);
}
//====================================================
int LongInt::Compare(LongInt b)
{
	for(int i=Len-1;i>=0;i--)
	{
		if(MyInt[i]>b.MyInt[i])
			return 1;
		else if(MyInt[i]<b.MyInt[i])
			return -1;
	}
	return 0;
}
//====================================================
bool LongInt::operator>(LongInt b)
{
	if(Compare(b)==1)
		return true;
	else
		return false;
}
//====================================================
bool LongInt::operator<(LongInt b)
{
	if(Compare(b)==-1)
		return true;
	else
		return false;
}
//====================================================
bool LongInt::operator==(LongInt b)
{
	if(Compare(b)==0)
		return true;
	else
		return false;
}
//====================================================
LongInt LongInt::Sub(LongInt b)
{
	LongInt result;
	if(Compare(b)==1||Compare(b)==0)
	{
		result.IsPositive=true;
		for(int i=0;i<Len;i++)
		{
			result.MyInt[i]=MyInt[i]-b.MyInt[i];
		}
	}
	else
	{
		result.IsPositive=false;
		for(int i=0;i<Len;i++)
		{
			result.MyInt[i]=b.MyInt[i]-MyInt[i];
		}
	}
	for(int i=0;i<Len;i++)
	{
		if(result.MyInt[i]<0)
		{
			result.MyInt[i] +=10;
			result.MyInt[i+1]--;
		} 
	}
	return result;
}
//====================================================
LongInt LongInt::operator-(LongInt b)
{
	return Sub(b);
}
//====================================================

LongInt LongInt::operator=(int b)
{
	return LongInt(b); 
	 
}

LongInt LongInt::Multi(LongInt b){
	LongInt res;
	res.Zero();
	int size = 0;
	for(int i = 0; i < Len; i++)
	{
		size = i;
		for(int j = 0; j < Len; j++)
		{
			res.MyInt[size] += MyInt[i] * b.MyInt[j];
			size++;
		}
	}

	res.MyInt[1]+=res.MyInt[0]/10;
	res.MyInt[0]=res.MyInt[0]%10;

	for(int i = 1; i < MAX; i++)
	{
		if(res.MyInt[i - 1]>=10)
		{
			res.MyInt[i]+=res.MyInt[i - 1]/10;
			res.MyInt[i - 1]=res.MyInt[i - 1]%10;
		}
	}
	return res;
}

LongInt LongInt::operator *(LongInt b)
{
	return Multi(b); 
}

LongInt LongInt::Div(LongInt b){
	LongInt res;
	res.Zero();
	int size = 0;
	return res;
}
