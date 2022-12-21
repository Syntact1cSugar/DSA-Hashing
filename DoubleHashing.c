#include<stdio.h>
#include<stdlib.h>

int H1(int key)//Hash function h1(k) = k%11;
{
	return key%11;
}
int H2(int key)//Hash function h2(k) = 8-(k%8)
{
	return (8-(key%8));
}
int H(int key,int j)//Combination of two hash function (h1(k)+j*h2(key)
{
	return (H1(key)+j*H2(key))%11;
}
int main()
{
	int i,j,n,key;
	//Creation of Hash Table
	int* HashTable = (int*)malloc(sizeof(int)*11);
	//Initialize Hash Table
	for(i=0;i<11;i++)
		*(HashTable+i) = -1;
	printf("Number of keys : ");
	scanf("%d",&n);
	int* KeyTable = (int*)malloc(sizeof(int)*n);
	printf("\nEnter all the keys : ");
	for(i=0;i<n;i++)
		scanf("%d",KeyTable+i);
	//Hashing the keys:
	for(i=0;i<n;i++)
	{
		j = 0;//Intial probe number
		key = *(KeyTable+i);
		while(j<11 && *(HashTable+H(key,j)) != -1)
			j++;
		if(*(HashTable+H(key,j)) == -1)
			*(HashTable+H(key,j)) = key;
	}
	printf("HASH TABLE :\n");
	for(i=0;i<11;i++)
	{
		if(*(HashTable+i) == -1)continue;
		printf("HashTable[%d]->%d\n",i,*(HashTable+i));
	}
	return 0;
}
