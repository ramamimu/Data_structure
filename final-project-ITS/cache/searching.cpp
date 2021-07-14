// Ahmad Ferdiansyah Ramadhani
// 5025201218
// Pendataan Bebek

// MASIH UPPERBOUND (HARUS DILOWER BOUNDKAN)

#include <cstdio>
#include <iostream>
 
using namespace std;
 
int upperBound(int acuan, int arr[], int l, int r)
{
	int mid=l+(r-l)/2;;
	while(l<r)
	{
		if(arr[mid]<=acuan)
			l=mid+1;
		else
			r=mid;
		mid=l+(r-l)/2;
	}
	return mid;
}
 
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int q, start, finish;
	scanf("%d", &q);
	for (int i=0; i<q; i++)
	{
		scanf("%d %d", &start, &finish);
		start=upperBound(start, arr, 0, n);
		finish=upperBound(finish, arr, 0, n);
		printf("%d\n", finish-start);
	}
	return 0;
}