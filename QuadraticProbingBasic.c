#include<stdio.h>
#include<stdlib.h>


int main()
{
	int i,n,key,index;
	//Creating Hash Table
	int* HashTable = malloc(sizeof(int)*10);
	for(i=0;i<10;i++)
		*(HashTable+i) = -1;
	printf("Number of keys: ");
	scanf("%d",&n);
	int* KeyTable = malloc(sizeof(int)*n);
	printf("Enter the keys:");
	for(i=0;i<n;i++)
		scanf("%d",(KeyTable+i));
	//Hashing the keys
	for(i=0;i<n;i++)
	{
		key = *(KeyTable+i);
		index = key % 10;
		if(*(HashTable+index) == -1)
			*(HashTable+index) = key;
		else //Quadratic Probing
		{
			for(int j=1;j<5;j++)
			{
				if(*(HashTable+((index+j*j)%10)) == -1)
				{
					*(HashTable+((index+j*j)%10)) = key;
					break;
				}
			}
		}
	}
	printf("HASH TABLE:\n");
	for(i=0;i<10;i++)
		printf("H[index=%d] -> %d\n",i,*(HashTable+i));
	return 0;
}
