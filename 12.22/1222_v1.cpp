#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 

#define MAX 80
struct node
{
	int data;
	int level;
	node *llink, *rlink;
	node()
	{
		llink=NULL;
		rlink=NULL;
	}
};

struct BS_tree
{
	node *head;
	int level;
	BS_tree();
	BS_tree(const char *filename);
	void Insert(int num);		//包含建立以及插入節點。
	void Delete(int num);		//從Binary Search Tree中刪除一個節點。
	void ShowTree();			//以樹狀圖形將此Binary Search Tree印出。
	node* Search(int num);		//當呼叫此函數時，傳入一個欲搜尋的數值進行搜尋，
								//若找到則傳回此節點的父親節點，
								//若沒有找到則回傳NULL。
	void LevelTraversal();
	void printSpace(int);
	//int pow(int, int);
}; 

struct Queue
{
	node* seq[MAX];
	int front, rear;
	Queue()
	{
		front=0;
		rear=0;
	}
	bool IsFull()
	{
		if((rear+1)%MAX == front)
		{			
			return true;
		}
		else
			return false;
	}
	bool IsEmpty()
	{
		if(rear == front)
			return true;
		else
			return false;
	}

	void Add(node* tmp)
	{
		if(IsFull()==false)		
		{
			seq[rear]=tmp;
			rear=(rear+1)%MAX;
		}
		else
		{
			printf("The Queue is Full\n");
		}		
	}
	
	node* Del()
	{
		node *tmp=NULL;
		if(IsEmpty()==false)
		{
			tmp=seq[front];
			front = (front+1)%MAX;
			
		}
		else
		{
			printf("The Queue is Empty\n");
		}
		return tmp;
	}
	
};

int main()
{
	BS_tree t1("1222.txt");
	
	t1.Insert(7);
	t1.Insert(1);
	t1.ShowTree();
	//t1.ShowTree();
	//t1.Search(19);
	//printf("%d",t1.Search(7) -> data);
	t1.Delete(4);
	t1.ShowTree();
	return 0;
} 

BS_tree::BS_tree(){

}
//======================================
BS_tree::BS_tree(const char *filename)
{
	FILE *fptr=fopen(filename, "r");
	int num;
	head=NULL;
	while(!feof(fptr))
	{
		fscanf(fptr, "%d", &num);
		Insert(num);
		//ShowTree();
		//system("pause"); 
	//	printf("%d\n",num);
	} 
	fclose(fptr);
}
//======================================
void BS_tree::Insert(int num)
{
	node *ptr=head;
	node *temp=NULL;
	node *parent=head;
	int currentLevel=1;
	
	temp=(node*)malloc(sizeof(node));
	
	temp->data=num;
	temp->llink=NULL;
	temp->rlink=NULL;
	
	//printf("insert num:%d\n",num);
	if(!ptr)
	{
		head=temp;
		//parent=temp;
	}
	else
	{		
		while(ptr)
		{
			//printf("ptr:%d\n",ptr->data);
			parent=ptr;
			if(num>ptr->data)
				ptr=ptr->rlink;				
			else
				ptr=ptr->llink;
			currentLevel++;
			//printf("parent:%d\n",parent->data);
		}
		
		if(num>parent->data)
			parent->rlink=temp;
		else
			parent->llink=temp;

		level = currentLevel;
		if(currentLevel>level)
			level=currentLevel;
	}
}
//======================================
node* BS_tree::Search(int num)
{
	node *temp = head;
	Queue q;
	q.Add(temp);
	while (!q.IsEmpty())
	{
		temp = q.Del();
		if(temp -> data == num){
			return temp;
		}
		if(temp -> llink)
			q.Add(temp -> llink);
		
		if(temp -> rlink)
			q.Add(temp -> rlink);
	}
	printf("Not found!\n");
	return 0;
}

void BS_tree::Delete(int num)
{
	BS_tree del;
	int store[100];
	int count = 0;
	node *temp = head;
	Queue q;
	q.Add(temp);
	while (!q.IsEmpty())
	{
		temp = q.Del();
		//printf("%d ",temp -> data);
		store[count] = temp -> data;
		count++;
		if(temp -> llink)
			q.Add(temp -> llink);
		
		if(temp -> rlink)
			q.Add(temp -> rlink);
	}
	
	for(int i = 0; i < count; i++){
		if(store[i] == num) 
			continue;
		del.Insert(store[i]);   
	}

	head = del.head;

}
//======================================
void BS_tree::LevelTraversal()
{

}
//======================================
//======================================
void BS_tree::ShowTree()
{
	Queue q;
	Queue myQ;
	node *ptr=head;
	node *temp = head;
	int currentLevel=0;
	int num=0;
	q.Add(ptr);
	printf("tree hight:%d\n",level);
	int count = 1;
	
	// while(!q.IsEmpty())
	// {
	// 	temp=q.Del();
	// 	if(temp -> llink)
	// 		q.Add(temp -> llink);
	// 	if(temp -> rlink)
	// 		q.Add(temp -> rlink);
		
	// 	//printSpace(pow(2,level-currentLevel));
	// 	//printf("\b\b%2d",temp->data);
	// 	//printSpace(pow(2,level-currentLevel));
	// 	printf("%2d",level);
	// }

	myQ.Add(ptr);
	while(currentLevel<=level)
	{
		ptr=myQ.Del();
		if(ptr)
		{
			printSpace(pow(2,level-currentLevel));
			printf("\b\b%2d",ptr->data);
			printSpace(pow(2,level-currentLevel));
			num++;
			myQ.Add(ptr->llink);
			myQ.Add(ptr->rlink);
		}
		else
		{
			printSpace(pow(2,level-currentLevel));
			printf("\b\b  ");
			printSpace(pow(2,level-currentLevel));
			num++;
			myQ.Add(NULL);
			myQ.Add(NULL);
		}
		if(num==pow(2,currentLevel))
		{
			num=0;
			printf("\n");
			currentLevel++;
		}		
	}
	//system("pause");
}
//==============================================
void BS_tree::printSpace(int num)
{
	for(int i=0;i<num;i++)
		printf(" ");
}

