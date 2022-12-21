#include<stdio.h>
#include<stdlib.h>

int main()
{
	//h(k,j) = (k % 10 + j) % 10;
	int i,n,key,index;
	int j;//Probe Number
	//Creating Hash Table
	int* HashTable = malloc(sizeof(int)*10);
	for(i=0;i<10;i++)
		*(HashTable+i) = -1;
	printf("Number of keys: ");
	scanf("%d",&n);
	//Creation of key table
	int* KeyTable = malloc(sizeof(int)*n);
	printf("\nEnter all the keys:");
	for(i=0;i<n;i++)
		scanf("%d",KeyTable+i);
	//Hashing the keys 
	for(i=0;i<n;i++)
	{
		key = *(KeyTable+i);
		index = key%10;
		if(*(HashTable+index) == -1)
			*(HashTable+index) = key;
		else //linear probing
		{
			for(j=index+1;j!=index;j=(j+1)%10)
				if(*(HashTable+i) == -1)
				{
					*(HashTable+j) = key;
					break;
				}
		}
	}
	printf("HASH TABLE:\n");
	for(i=0;i<10;i++)
	{
		printf("H[index=%d] -> %d\n",i,*(HashTable+i));
	}
	return 0;
}

