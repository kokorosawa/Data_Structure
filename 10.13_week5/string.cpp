#include <stdio.h>
#include <stdlib.h>
#define MAX 201

struct MyString 
{
	char s[MAX];
	
	MyString();
	MyString(const char*);
	 
	void Show(void);
    int Length(void);
    int IndexOf(const char *);
    MyString SubString(int, int);
	void Assign(const char *);
	void InsertOf(const char *, int);  
	     
    MyString operator+(const char*);
    MyString operator+(MyString);
    MyString operator+(int);
	void operator=(const char*);
};

int main()
{
	MyString str1="Hello";
	MyString str2;
	MyString str3; 

	str1.Show();
	printf("length:%d\n", str1.Length());
	
	printf("ll in %s at %d\n", str1.s, str1.IndexOf("ll"));
	
	
	str2="Hello World";
	str2.Show();
	str2="My favorite class is DS";
	str2.Show();

    str3=str1 + " My Friends";
	str3.Show(); 
	str3=str1 + " " + str2 + " "+"Absolutely!!" + 12556683;
	str3.Show(); 
	return 0;
}

MyString::MyString()
{
	s[0]='\0';
}
MyString::MyString(const char *temp)
{
	int i=0;
	while(temp[i]!='\0')
	{
		s[i]=temp[i];
		i++;
	}
	s[i]='\0';
}
void MyString::Show()
{
	printf("%s\n",s);
}

int MyString::Length()
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;	
	}	
	return i;
}

int MyString::IndexOf(const char *temp)
{
	int i=0;
	int j=0;
	int temp_len=0;
	
	MyString MyTemp(temp);
	temp_len=MyTemp.Length();
	temp_len=0;
	
	while(temp[temp_len]!='\0') temp_len++;
	 
	while(s[i]!='\0')
	{
		while(s[i+j]==temp[j] && s[i+j]!='\0')
		{
			j++;
		}
		//printf("j=%d\n",j);
		
		
		if(j==temp_len)
			return i;
		else
		{
			j=0;
			i++;
		}
	}
	return -1;
}

// MyString MyString::SubString(int begin, int count)
// {
	
// }

void MyString::Assign(const char *temp)
{
	
}

void MyString::operator=(const char* temp)
{
	int i=0;
	while(temp[i]!='\0')
	{
		s[i]=temp[i];
		i++;
	}
    s[i] ='\0';
}


MyString MyString::operator+(const char* temp)
{

	MyString ReStr;
	
	int i=0;
	while(s[i]!='\0')
	{
        ReStr.s[i] = s[i];
        i++;
	}

    int j = 0;
    while(temp[j]!='\0')
	{
        ReStr.s[i + j] = temp[j];
        j++;
	}
    ReStr.s[i + j] = '\0';

	return ReStr;
}

MyString MyString::operator+(MyString temp)
{
    MyString ReStr;
    int i=0;
	while(s[i]!='\0')
	{
        ReStr.s[i] = s[i];
        i++;
	}

    int j = 0;
    while(temp.s[j]!='\0')
	{
        ReStr.s[i + j] = temp.s[j];
        j++;
	}
    ReStr.s[i + j] = '\0';
	return ReStr;
}

MyString MyString::operator+(int num)
{
	MyString ReStr;
    int i=0;
	while(s[i]!='\0')
	{
        ReStr.s[i] = s[i];
        i++;
	}

    int a[MAX] = {0};
    int j = 0;
    while(num!=0)
    {
        a[j] = num % 10;
        num /= 10;
        j++;
    }

    // for(auto n : a)
    //     printf("%d",n);
    // printf("\n");

    for(int k = i; k < i + j; k++)
    {
        ReStr.s[k] = a[i + j - k - 1] + '0';
    }
	return ReStr;
}

void MyString::InsertOf(const char *input, int index)
{
	
}