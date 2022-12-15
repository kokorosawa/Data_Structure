#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX	80

struct HeapTree
{
	int data[MAX];
	int count;
    HeapTree();
	HeapTree(const char* filename);
	void InsertData(int);
	void Show();
	void ShowSpace(int);
	int MyPower(int);
	int GetLevel();
	void ShowTree();
    void Pop();
};

int main()
{   
    HeapTree t1("a.txt");
	t1.ShowTree();
    printf("\n");
    int n = t1.count;
    t1.Pop();
    t1.Pop();
    t1.Pop();
    t1.Pop();
    // for(int i = 1; i <= 3; i++){
    //     t1.Pop();  
    //     system("pause");
    // }
    //printf("%d",n);
	return 0;
}

//======================================
HeapTree::HeapTree(const char* filename)
{
    FILE *fptr=fopen(filename, "r");
	count=0;
	while(!feof(fptr))
	{
		count++;
		fscanf(fptr,"%d",&data[count]);
		//printf("%4d", data[count]);
		InsertData(data[count]); 
		//ShowTree();
		printf("\n");
		//system("pause");
		
	}
	printf("\n");
}


HeapTree::HeapTree()
{
    
}

//======================================
void HeapTree::InsertData(int num)
{
    int index = count;
    int temp;
    while(index > 1){
        if(data[index] > data[index / 2]){
            temp = data[index];
            data[index] = data[index / 2];
            data[index / 2] = temp;
        }
        index /= 2;
    }
}

//======================================
void HeapTree::Show()
{

}

//======================================
void HeapTree::ShowSpace(int num)
{
    for(int i=0;i<num;i++)
	{
		printf(" ");
	}
}

//======================================
int HeapTree::MyPower(int num)
{

}

//======================================
int HeapTree::GetLevel()
{
    int level=0;
	int i=count;
	while(i)
	{
		level++;
		i=i/2;
	}
	return level;
}

//======================================
void HeapTree::ShowTree()
{
    int level=1;
	int height=GetLevel();
	//int height=3;
	printf("count:%d\n",count);
	printf("height:%d\n",height);
	for(int i=1;i<=count;i++)
	{

		ShowSpace(pow(2, height-level+1));
		printf("\b\b%2d",data[i]);
		ShowSpace(pow(2, height-level+1));
		
		if(i==pow(2, level)-1)
		{
			level++;
			printf("\n");
		}
		
	}
}

void HeapTree::Pop()
{
    HeapTree newtree;
    for(int i = 2; i <= count; i++){
        newtree.count++;
        newtree.data[i - 1] = data[i];
        newtree.InsertData(0);
    }

    data[count] = 0;
    count--;
    for(int i = 1;i <= count; i++){
        data[i] = newtree.data[i];
    }
    ShowTree();
}
