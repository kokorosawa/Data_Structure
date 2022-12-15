#include<stdio.h>
#include<stdlib.h>

struct listNode {
	int data;
	listNode *link;
};


listNode *Add(listNode *head, int num);
listNode *Delete(listNode *head, int deletePosition);
listNode *Insert(listNode *head, int insertNumber, int insertPosition);
void *Edit(listNode *head, int editNumber, int editPosition);
listNode *Inverse(listNode *head);
int Length(listNode *head);
listNode *Combine(listNode *head, listNode *head2);
void Show(listNode *head);

int main(){

	listNode *head=NULL;
	head=Add(head,0);
	printf("%p\n",head);
	
	head=Add(head,1);
	head=Add(head,2);
	head=Add(head,3);
	head=Add(head,4);
	head=Add(head,5);
	Show(head);
	head=Delete(head,2);
	Show(head);
	
	Edit(head, 10, 2); 
	Show(head);
	printf(" List length:%d\n", Length(head));
	head=Inverse(head);
	Show(head);
	
	
	listNode *head2=NULL;
	listNode *head3=NULL;
	head2=Add(head2,2);
	head2=Add(head2,3);
	head2=Add(head2,4);
	head2=Add(head2,5);
	head2=Add(head2,6);
	Show(head2);
	head3=Combine(head, head2);
	Show(head3);
	head3=Insert(head3, 88, 0);
	Show(head3); 
	
	return 0;
} 

//============================================================================= 
//新增，在鏈結串列的後面新增一筆資料x。
//傳入值為head以及欲新增的資料；回傳值為head。
listNode *Add(listNode *head, int num)
{
	listNode *ptr=head;
	listNode *tmp=(listNode*)malloc(sizeof(listNode));
	tmp->data=num;
	tmp->link=NULL;
	
	if(head==NULL)
	{
		head=tmp;
		//printf("subroutine head:%p\n",head);
	}
	else
	{
		//找到最後一個節點
		
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=tmp;
	}
	
	return head;
	
} 
//============================================================================= 
//將一筆特定位置的資料刪除。
//傳入值為head以及欲刪除的位置；回傳值為head。
listNode *Delete(listNode *head, int deletePosition)
{
	listNode *pre=head;
	listNode *current=head;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		for(int i=0;i<deletePosition;i++)
		{
			pre=current;
			current=current->link;
		} 
		if(current==head)
		{
			head=head->link;
		}
		else
			pre->link=current->link;
	}
	free(current);
	return head;
} 
//============================================================================= 
//將一筆資料插入於特定的位置
//傳入值為1. head 2. 插入的數字 3. 欲插入的位置；回傳值為head。
listNode *Insert(listNode *head, int insertNumber, int insertPosition)
{
	listNode *ptr=head;
	int len=Length(head);
	if(insertPosition>len)
	{
		printf("Position > list Length\n");
		return head;
	}
	else
	{
		listNode *tmp=(listNode*)malloc(sizeof(listNode));
		tmp->data=insertNumber;
		tmp->link=NULL; 
		for(int i=0;i<insertPosition-1; i++)
		{
			ptr=ptr->link;
		}
		if(insertPosition==0)
		{
			tmp->link=head;
			head=tmp;
		}
		else
		{
			tmp->link=ptr->link;
			ptr->link=tmp;
		}
		
	}
	return head;

}
//============================================================================= 
//修改資料，傳入值為1. head 2. 修改的數字 3. 欲修改的位置。   
void *Edit(listNode *head, int editNumber, int editPosition)
{
	listNode *ptr=head;
	for(int i=0;i<editPosition;i++)
	{
		ptr=ptr->link;
	}
	ptr->data=editNumber;

}
//=============================================================================  
//將目前的鏈結串列反轉，傳入值為目前鏈結串列的head，回傳值則為反轉後鏈結串列的head。
listNode *Inverse(listNode *head)
{
	listNode *pre, *current, *next;
	pre=NULL;
	current=head;
	next=head->link;
	
	while(current!=NULL)
	{
		current->link=pre;
		pre=current;
		current=next;
		if(next!=NULL)
			next=next->link;
	}
	return pre;
//             p  c  n	 
//       1->2->3->Null	

/*	pre=NULL;
	current=NULL;
	next=head;
	while(next!=NULL)
	{
		pre=current;
		current=next;
		next=next->link;
		current->link=pre;
	}
	return current;
*/
//    p  c  n	 
//       1->2->3->Null
} 
//=============================================================================
//計算此鏈結串列的長度，傳入值為head，回傳值為串列長度。  
int Length(listNode *head)
{
	listNode *ptr=head;
	int count=0;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	return count;
} 
//============================================================================= 
//將目前的鏈結串列 (head) 與鏈結串列 (head2) 合併，並且將結果存到目前串列，回傳值為head。
listNode *Combine(listNode *head, listNode *head2)
{
	listNode *ptr=head;
	if(ptr==NULL)
		return head2;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=head2;
	return head;

} 
//=============================================================================  
//顯示串列內容： 1->2->3->Null
void Show(listNode *head)
{
	while(head!=NULL)
	{
		printf("%2d->", head->data);
		head=head->link;		
	}
	printf("\b\b  \n");

}