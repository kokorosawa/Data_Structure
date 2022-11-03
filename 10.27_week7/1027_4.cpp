#include <stdio.h>
#include <stdlib.h>
#define MAX 200
struct MyStack{
	int top;           //堆疊頂端
	char a[MAX];       //堆疊主體
	
	bool IsEmpty();    //判斷堆疊是否為空，是則回傳1，否則0
	bool IsFull();     //判斷堆疊是否為滿，是則回傳1，否則0
	void Push(char);   //將一個字元傳進堆疊中
	void Show();
	char Pop();        //將一個字元從堆疊中拿出並回傳
	MyStack()		   //建構子
	{
		top = -1;
	}
}; 

bool CheckQuote(char*);

//==========================================
int main(){
	// MyStack S1;
	// S1.Pop();
	
	// S1.Push('a');
	// S1.Push('b');
	// S1.Push('c');
	
	// printf("Pop: %c\n", S1.Pop());
	// printf("Pop: %c\n", S1.Pop());
	// printf("Pop: %c\n", S1.Pop());
	
	// FILE *fptr=fopen("20221027.txt", "r");
	// char s[80];
	// while(!feof(fptr))
	// {
	// 	fscanf(fptr, "%s",s);
	// 	printf("%s: ", s);
		
	// 	if(CheckQuote(s))
	// 		printf("Correct!\n");
	// 	else
	// 		printf("Error!\n");
	// 	s[0]='\0';
	// }
	
	FILE *fptr=fopen("input.txt", "r");
	char a[MAX];
	while(!feof(fptr))
	{
		int i = 0;
		fgets(a, 200, fptr);
		printf("%s", a);
		int count = 0;
		MyStack s;
		while (a[i] != '\0')
		{
			s.Push(a[i]);
			if(count > 0)
				count++;
			else if(a[i] == 'e')
				count = 1;
			
			if(a[i] == 's')
			{
				for(int j = 0; j < count; j++)
				{
					s.Pop();
				}
				count = 0;
			}
			i++;
		}
		
		s.Show();
		a[0]='\0';
	}
	return 0;	
}
//=========================================
void MyStack::Show()
{
	for(int i = 0; i <= top; i++)
	{
		printf("%c", a[i]);
	}
	
}
//=========================================
bool MyStack::IsEmpty()
{
	if(top==-1)
		return true;
		
	else
		return false;
	
}
//=========================================
bool MyStack::IsFull()
{
	if(top==MAX-1)		
		return true;
	else
		return false;
}
//=========================================
void MyStack::Push(char ch)
{
	if(IsFull())
	{
		printf("The stack is Full! Cannot push!\n");
	}
	else
	{
		top++;
		a[top]=ch;
	}
}
//=========================================
char MyStack::Pop()
{
	char ch;
	if(IsEmpty())
	{
		printf("The stack is Empty! Cannot pop!\n");
		return 0;
	}
	else
	{
		ch=a[top];
		top--;
		return ch;	
	}	
}
//=========================================

//               [(])  [()]

/* a.遇到左括號一律丟堆疊
   b.遇到右括號看堆疊頂端元素是否與目前得右括號配對
    	如果無法配對，就錯誤
    	或是堆疊已經空了也錯誤
   c.如果輸入字串已經結束，並且堆疊還有東西，錯誤
   d.如果輸入字串已經結束，並且堆疊也空了，正確。
*/ 
//=========================================
bool CheckQuote(char *s)
{
	MyStack S;
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
		{
			S.Push(s[i]);
		}
		else
		{
			if(S.IsEmpty())
			{
				return false;
			}
			else
			{		
				if(s[i]==')')
				{
					if(S.Pop()!='(')
						return false; 
				}
				else if(s[i]==']')
				{
					if(S.Pop()!='[')
						return false; 
				}
				else
				{
					if(S.Pop()!='{')
						return false; 
				}
			}
		}
		i++;
	}
	if(!S.IsEmpty())
		return false;
	else
		return true;
}
    

