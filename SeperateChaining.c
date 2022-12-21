#include<stdio.h>
#include<stdlib.h>


struct KeyNode
{
	int key;
	struct KeyNode* link;
};
void Print(struct KeyNode* first)//first will store the address of the first node
{
	if(!first)
	{
		printf("Nil\n");
		return;
	}
	while(first)
	{
		printf("%d ",(*first).key);
		first = (*first).link;
	}
	printf("\n");
	return;
}
void InsertKey(int key,struct KeyNode** ptrToFirst)//(key,HashTable+i)
{
	struct KeyNode* newNode = malloc(sizeof(struct KeyNode));
	(*newNode).key = key;
	(*newNode).link = *ptrToFirst;
	*ptrToFirst = newNode;
	return;
}
int main()
{
	//Creation of Hash Table:
	struct KeyNode** HashTable = calloc(10,sizeof(struct KeyNode*));
	int i,n,key,index;
	printf("Enter the number of keys: ");
	scanf("%d",&n);
	//Creation of Key Table:
	int* KeyTable = malloc(sizeof(int)*n);
	printf("\nEnter all the keys: ");
	for(i=0;i<n;i++)	
		scanf("%d",KeyTable+i);
	//Hashing the keys:
	for(i=0;i<n;i++)
	{
		key = *(KeyTable+i);
		index = key%10;
		InsertKey(key,HashTable+index);
	}
	//Displaying the Hash Table
	printf("\nHASH TABLE:\n");
	for(i=0;i<10;i++)
	{
		printf("H[index=%d] -> ",i);
		Print(*(HashTable+i));
	}
	return 0;
}
