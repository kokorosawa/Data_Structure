#include <stdio.h>
#include <stdlib.h>
#define MAX 200
struct MyStack{
	int top;           //���|����
	char a[MAX];       //���|�D��
	
	bool IsEmpty();    //�P�_���|�O�_���šA�O�h�^��1�A�_�h0
	bool IsFull();     //�P�_���|�O�_�����A�O�h�^��1�A�_�h0
	void Push(char);   //�N�@�Ӧr���Ƕi���|��
	void Show();
	char Pop();        //�N�@�Ӧr���q���|�����X�æ^��
	MyStack()		   //�غc�l
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

/* a.�J�쥪�A���@�ߥ���|
   b.�J��k�A���ݰ��|���ݤ����O�_�P�ثe�o�k�A���t��
    	�p�G�L�k�t��A�N���~
    	�άO���|�w�g�ŤF�]���~
   c.�p�G��J�r��w�g�����A�åB���|�٦��F��A���~
   d.�p�G��J�r��w�g�����A�åB���|�]�ŤF�A���T�C
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
    

