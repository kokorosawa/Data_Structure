#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 50

struct Node
{
	char data;
	Node* llink;
	Node* rlink;
	Node()	
	{
		llink=NULL;
		rlink=NULL;
	}
};
struct Tree
{
	Node* root;
	int Height;
	Tree(const char *filename);
	void LevelTraversal();			//掃描每一層node的內容並輸出
									//使用Queue來儲存掃瞄過的節點
};

struct Queue
{
	Node* seq[MAX];
	int front, rear;
	Queue()
	{
		front=0;
		rear=0;
	}
	bool IsFull();
	bool IsEmpty();
	void Add(Node*);
	Node* Del(); 
};

void PrnSpace(int);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);

int main()
{
	Tree MyTree("a.txt");
	Node *head=MyTree.root;
	// printf("%c\n", head->data);
	// printf("%c %c\n", head->llink->data, head->rlink->data);
	// printf("%c %c\n", head->llink->llink->data, head->llink->rlink->data);
	MyTree.LevelTraversal();
	printf("preorder:");
	preorder(head);
	printf("\n");
	
	printf("inorder:");
	inorder(head);
	printf("\n");

	printf("postorder:");
	postorder(head);
	printf("\n");
	
	return 0;
} 
//=============================================================================
Tree::Tree(const char *filename)
{
	char s[MAX]={0};
	int i=0;
	Node *temp=NULL;
	Node *LChild=NULL, *RChild=NULL;
	
	int LvlCount=1;
	int count=0;
	
	Queue MyQueue; 
	
	Height=0;
	
	FILE *fptr=fopen(filename, "r");
	fscanf(fptr,"%s",s);
	printf("%s\n",s);
	if(s[i]!='\0')
	{
		temp=(Node*)malloc(sizeof(Node));
		temp->data=s[i];
		temp->llink=NULL;
		temp->rlink=NULL;
		root=temp;
		MyQueue.Add(temp);
		i++;
		Height++;
		LvlCount = LvlCount*2;
	}
	while(!MyQueue.IsEmpty()) 
	{
		temp=MyQueue.Del();

		if(s[i]!='\0')
		{
			LChild=(Node*)malloc(sizeof(Node));
			LChild->data=s[i];
			LChild->llink=NULL;
			LChild->rlink=NULL;
			 
			temp->llink=LChild;
			i++;
			MyQueue.Add(LChild);
			count++;
		}
		if(s[i]!='\0')
		{
			RChild=(Node*)malloc(sizeof(Node));
			RChild->data=s[i];
			RChild->llink=NULL;
			RChild->rlink=NULL;
			temp->rlink = RChild;
			
			i++;
			MyQueue.Add(RChild);
			count++;
		} 
		if(count==LvlCount)
		{
			Height++;
			count=0;
			LvlCount=LvlCount*2;
		}
	}	
		
}
//=============================================================================
void Tree::LevelTraversal()
{
	Queue MyQueue;
	Node *ptr=NULL;
	int LvlCount=1;
	int count=0;
	MyQueue.Add(root);
	printf("Tree Height:%d\n",Height);
	int height=Height;
	while(!MyQueue.IsEmpty())
	{
		ptr=MyQueue.Del();
		//printf("\nptr:%p\n",ptr);
		if(ptr!=NULL)
		{
			PrnSpace(pow(2,height));
			printf("\b%c",ptr->data);
			PrnSpace(pow(2,height));
		}
		count++;
		if(ptr!=NULL)
		{
			MyQueue.Add(ptr->llink);
			MyQueue.Add(ptr->rlink);
		}
		if(LvlCount==count)
		{
			printf("\n");
			count=0;
			LvlCount = LvlCount*2;
			height--;
		}
	}
	
}
//=============================================================================
bool Queue::IsFull()
{
	if((rear+1)%MAX==front)
		return true;
	else
		return false;
	
}
//=============================================================================
bool Queue::IsEmpty()
{
	if(rear == front)
		return true;
	else
		return false;

} 
//=============================================================================
void Queue::Add(Node* tmp)
{
	if(IsFull()!=true)
	{
		rear=(rear+1)%MAX;
		seq[rear]=tmp; 
	} 
}
//=============================================================================
Node* Queue::Del()
{
	Node* tmp=NULL;
	if(IsEmpty()!=true)
	{
		front = (front +1)%MAX;
		tmp = seq[front];		
	}
	return tmp;
}
//=============================================================================
void PrnSpace(int count)
{
	for(int i=0;i<count;i++)
	{
		printf(" ");
	}
}


void preorder(Node* root)
{
	if(!root) return;

	printf("%c", root -> data);
	preorder(root -> llink);
	preorder(root -> rlink);
}

void inorder(Node* root)
{
	if(!root) return;
	
	inorder(root -> llink);
	printf("%c", root -> data);
	inorder(root -> rlink);
}

void postorder(Node* root)
{
	if(!root) return;
	
	postorder(root -> llink);
	postorder(root -> rlink);
	printf("%c", root -> data);
}