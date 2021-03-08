#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,n,t, *arr, *arr2;
	scanf("%d %d",&n,&t);
	arr = (int *)malloc(sizeof(int)*n);
	arr2 = (int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}

	i--;
	while(i>=0)
	{
		arr2[i]=t/arr[i];
		t %= arr[i];
		i--;
	}

	for(i=0;i<n;i++)
	{
		t+=arr2[i];
	}

	printf("%d",t);

}