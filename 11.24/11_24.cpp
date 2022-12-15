#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 12
struct node {
	int data;
	node* link;
};

struct equivalence {
	node* seq[MAX_SIZE];
	void eqRead(char* );			//從檔案讀取資料，並且儲存至seq陣列中。
	void add(int, int);				//新增一筆等價關係之資料。
	void ShowList();				//顯示目前陣列中等價關係之鏈結串列。
	void ShowClass(); 				//顯示目前等價類。
	equivalence()
	{
		for(int i=0;i<MAX_SIZE;i++)
		{
			seq[i] = NULL;
		}
	}
};

int main() {
	equivalence MyEq;
	MyEq.eqRead("1.txt"); 
	MyEq.ShowList();
	MyEq.ShowClass();
	return 0;
}
//=============================================================================
void equivalence::eqRead(char* filename)
{
	int a, b;
	FILE *fptr=fopen(filename,"r");
	while(!feof(fptr))
	{
		fscanf(fptr, "%d %d", &a, &b);
		add(a, b);
		//ShowList();
		//system("pause"); 
	}	
}
//=============================================================================
void equivalence::add(int a, int b)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->link=seq[a];
	temp->data=b;
	seq[a]=temp;
	
	temp = (node*)malloc(sizeof(node));
	temp->link=seq[b];
	temp->data=a;
	seq[b]=temp;
}
//=============================================================================
void equivalence::ShowList()
{
	node *ptr=NULL;
	for(int i=0;i<MAX_SIZE;i++)
	{
		printf("seq[%d]->",i);
		ptr=seq[i];
		while(ptr!=NULL)
		{
			printf("%d->",ptr->data);
			ptr=ptr->link;
		}
		printf("\b\b  \n");
	}

}
//=============================================================================
void equivalence::ShowClass()
{
	node *next=NULL;
	node *ptr=NULL;
	node *top=NULL;
	int out[MAX_SIZE]={0};
	for(int i=0;i<MAX_SIZE;i++)
	{		
		if(!out[i])
		{
			printf("New Class:");
			out[i]=1;
			
			ptr=seq[i];
			printf("%2d,",i);
			while(1)
			{
				while(ptr!=NULL)
				{
					//輸出 seq[i]那個 linked list 中沒有輸出過，即out[ptr->data]為0的節點 
					if(!out[ptr->data])
					{
						out[ptr->data]=1;
						printf("%2d,",ptr->data);
						
						//將節點加入stack 
						next=ptr->link;
						ptr->link=top;
						top=ptr;
						ptr=next; 					
					}
					else
						ptr=ptr->link;								
				}
				//如果 stack 為空，表示一個 class 結束 
				if(top==NULL) break;
				
				//從 stack 取出節點 
				ptr=seq[top->data];
				top=top->link;
			}
			printf("\b \n");				
		}
		
	}
	
}