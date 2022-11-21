#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef enum {op, val} mytype;

struct data
{
	mytype type;
	int value;
	char oper;
	int priority;
};

struct SplitData
{
	data item[MAX];
	data postitem[MAX];
	int count;
	void Split(char*);
	void ShowInfix();	
	void InfixToPost();
	void ShowPostfix(); 	
	data Calculate();
};

struct MyStack
{
	data a[MAX];
	int top;
	bool IsEmpty();
	bool IsFull();
	void Push(data da);
	data Pop();
	data Top();
	MyStack()
	{
		top=-1;
	}
};

int main()
{
	// char s[80]="4*2+10-9/3";   //1234*
	// SplitData DataInfix;
	// DataInfix.Split(s);
	// DataInfix.ShowInfix();
	// DataInfix.InfixToPost();
	// DataInfix.ShowPostfix();

	FILE *fptr = fopen("1103hw.txt", "r");
	char a[80];
	while(!feof(fptr)){
		fscanf(fptr, "%s", a);
		SplitData DataInfix;
		printf("---------------------------\n");
		//printf("%s\n",a);
		DataInfix.Split(a);
		DataInfix.ShowInfix();
		DataInfix.InfixToPost();
		DataInfix.ShowPostfix();
		data num = DataInfix.Calculate();
		printf("%d\n", num.value);
		a[0] = '\0';
	}
	return 0;
} 

bool MyStack::IsEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}

bool MyStack::IsFull()
{
	if(top == MAX - 1)
		return true;
	else
		return false;
}

void MyStack::Push(data da)
{
	if(IsFull())
		printf("The STACK is full");
	else
		a[++top] = da;
}
data MyStack::Pop()
{
	if(IsEmpty())
		printf("The STACK is empty");
	return a[top--];
}
data MyStack::Top()
{
	if(IsEmpty())
		printf("The STACK is empty");
	return a[top];
}
//======================================================
void SplitData::Split(char *str)
{
	count=0;
	int i=0, j=0;
	char temp[MAX];
	while(str[i]!='\0')
	{
		switch(str[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case ')':
				 if(j!=0)
				 {
				 	temp[j]='\0';
				 	item[count].type=val;
				 	item[count].value=atoi(temp);
				 	//printf("%d\n",item[count].value);
				 	j=0;
				 	count++;
				 }
				 item[count].type=op;
				 item[count].oper=str[i];
				 //printf("%c\n",item[count].oper);
				 count++;
				 break;
			default:
				temp[j]=str[i];
				j++;
		}
		i++;
	}
	if(j!=0)
	{
		temp[j]='\0';
	 	item[count].type=val;
	 	item[count].value=atoi(temp);
	 	//printf("%d\n",item[count].value);
	 	j=0;
	 	count++;
	}
	for(int i=0;i<count;i++)
	{
		if(item[i].oper=='+'||item[i].oper=='-')
			item[i].priority=1;
		else if(item[i].oper=='*'||item[i].oper=='/')
			item[i].priority=2;
	}
}
//==========================================
void SplitData::ShowInfix()
{
	for(int i=0;i<count;i++)
	{
		if(item[i].type==val)
			printf(" %d ", item[i].value);
		else
			printf("%c",item[i].oper);
	}
	printf("\n");
}
//==========================================
void SplitData::InfixToPost()
{
	MyStack s;
	int i=0,j=0;
	for(i=0;i<count;i++)
	{
		if(item[i].type==val)
		{
			postitem[j]=item[i];
			//printf("%d\n", item[i].value);
			j++;
		}
		else
		{
			if(s.IsEmpty())
			{
				//printf("%c",item[i].oper);
				s.Push(item[i]);
			}
			else
			{
				if(item[i].oper == '(')
				{
					item[i].priority = 0;
					//printf("%c",item[i].oper);
					s.Push(item[i]);
				}
				else if(item[i].oper == ')')
				{
					while(!s.IsEmpty())
					{
						if(s.a[s.top].oper == '(')
						{	
							s.Pop();
							break;
						}
						else
						{
							postitem[j] = s.Pop();
							j++;
						}
					}
				}
				else
				{
					while(s.a[s.top].priority>=item[i].priority&&!s.IsEmpty())
					{
						postitem[j]=s.Pop();
						//printf("%c\n",postitem[j].oper);
						j++;
					}
					//printf("%c",item[i].oper);
					s.Push(item[i]);
				}
			}
		}
	}
	while(!s.IsEmpty())
	{
		postitem[j]=s.Pop();
		//printf("%c\n",postitem[j].oper);
		j++;
	}
	count = j;
}
//=======================================================
void SplitData::ShowPostfix()
{
	for(int i=0;i<count;i++)
	{
		if(postitem[i].type==val)
			printf(" %d ", postitem[i].value);
		else
			printf("%c",postitem[i].oper);
	}
	printf("\n");
}

data SplitData::Calculate()
{
	MyStack s;
	for(int i = 0; i < count; i++)
	{
		if(postitem[i].type == val)
		{
			s.Push(postitem[i]);
		}
		else
		{
			data num1 = s.Pop();
			data num2 = s.Pop();

			data ans;
			switch (postitem[i].oper)
			{
			case '+':
				ans.value = num1.value + num2.value;
				break;
			case '-':
				ans.value = num2.value - num1.value;
				break;
			case '*':
				ans.value = num1.value * num2.value;
				break;
			case '/':
				ans.value = num2.value / num1.value;
				break;		
			default:
				break;
			}
			s.Push(ans);
		}
	}

	data res = s.Pop();
	return res;
}