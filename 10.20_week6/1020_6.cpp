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
	void Init();   					//利用亂數產生一個長度小於19的值
	void Init(int num);  			//指定一個長度小於19的值
	LongInt operator=(int); 			//運算子多載
	void Zero();  					//將本身的陣列初始為0
	void Show(); 					//顯示陣列
	
	int Compare(LongInt b); 		//比較本身跟長整數b之間何者較大，若大於b則回傳1，反之，則回傳-1
	bool operator>(LongInt b);
	bool operator<(LongInt b);
	bool operator==(LongInt b);
	
	LongInt Add(LongInt);
	LongInt operator+(LongInt); 	//運算子多載
	LongInt Sub(LongInt);
	LongInt operator-(LongInt); 	//運算子多載     123456
	
//	HW
	LongInt Multi(LongInt);
	LongInt operator*(LongInt); 
	LongInt Div(LongInt);
	LongInt operator/(LongInt); 
};

int main(){
	LongInt a(11);
	LongInt b(1111);  // '1' - '0'  char s[]="12345.....", s[i]-'0'
	LongInt c(1111);
	LongInt d;
	LongInt e="1234567891234567891"; 
	
	LongInt h; 
	printf("a=");
	a.Show();
	printf("b=");
	b.Show();
	c=a.Add(b);
	printf("c=");
	c.Show();
	
	c=a+b;
	printf("c=");
	c.Show();
	if(a>b)
		printf("a>b\n");
	else if(a<b)
		printf("a<b\n");
	else
		printf("a==b\n");
	
	d=a.Sub(b);
	printf("d=");
	d.Show();
	
	d=a-b;
	printf("d=");
	d.Show();
	printf("e=");
	e.Show();
	
	h=b.Multi(c);
	printf("b.Multi(c)=\n");
	h.Show();
	
	h=b*c;
	printf("b*c=\n");
	h.Show();
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
	for(int i=0;i<Len;i++)
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
			if(res.MyInt[i]>=10)
			{
				res.MyInt[i+1]+=res.MyInt[i]/10;
				res.MyInt[i]=res.MyInt[i]%10;
			}
			size++;
		}
	}
	return res;
}

LongInt LongInt::operator *(LongInt b)
{
	return Multi(b); 
}

// LongInt LongInt::Multi(LongInt b){
// 	LongInt res;
// 	res.Zero();
// 	int size = 0;
// 	for(int i = 0; i < Len; i++)
// 	{
// 		size = i;
// 		for(int j = 0; j < Len; j++)
// 		{
// 			res.MyInt[size] += MyInt[i] * b.MyInt[j];
// 			if(res.MyInt[i]>=10)
// 			{
// 				res.MyInt[i+1]+=res.MyInt[i]/10;
// 				res.MyInt[i]=res.MyInt[i]%10;
// 			}
// 			size++;
// 		}
// 	}
// 	return res;
// }
