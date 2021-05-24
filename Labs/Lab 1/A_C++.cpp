/*
CSE222: ADA (W21):	Lab1
A1
Abhimanyu Gupta:	2019226
Abhinav Gudipati:	2019227
*/

#include <bits/stdc++.h>

using namespace std;

long long countSpiltInversionAndMerge(int arr[],int n,int l1,int r1,int l2,int r2)
{
	int s1=r1-l1+1;
	int s2=r2-l2+1;
	int arr1[s1];
	int arr2[s2];
	int g1=l1;
	int g2=l2;
	for(int i=0;i<s1;++i)
		arr1[i]=arr[g1+i];
	for(int i=0;i<s2;++i)
		arr2[i]=arr[g2+i];
	/*
		0 1 2 3 4 5 6
		  l       r
		  s=5
		  s1=2	s2=3
		     l+s1
		a1[2]={l+0,l+1}
		a2[2]={l+s1+0,l+s1+1,l+s1+2};
		
				  l                 r
		a[] -> ...l1.....r1,l2......r2...
		a1[]-> l1......r1    -> size=s1, indexing=i
		a2[]-> l2......r2
						  s1
				3 4 5 6 7 | 2........
				s1=5	i=0;
	*/
	int i=0;
	int j=0;
	int g=l1;
	long long inversionCount=0;
	while(i<s1 && j<s2)
	{
		if(arr1[i]<=arr2[j])	//arr1[i] -> arr[g+i+j]
		{
			arr[g+i+j]=arr1[i];
			++i;
		}
		else
		{
			inversionCount+=s1-i;
			arr[g+i+j]=arr2[j];
			++j;
		}
	}
	/*	2 3 4
		1 2 2
		1 2 2 2 i=1 j=s2
	*/
	while(i<s1)
	{
		arr[g+i+j]=arr1[i];
		++i;
	}
	while(j<s2)
	{
		inversionCount+=s1-i;
		arr[g+i+j]=arr2[j];
		++j;
	}

	return inversionCount;
}

long long countInversionRoutine(int arr[],int n,int l,int r)
{
	int s=r-l+1;
	if(s<=1)
		return 0;

	int m=l+(r-l)/2;
	long long leftInversionCount=countInversionRoutine(arr,n,l,m);
	long long rightInversionCount=countInversionRoutine(arr,n,m+1,r);
	long long splitInversionCount=countSpiltInversionAndMerge(arr,n,l,m,m+1,r);

	long long totalInversionsCount=leftInversionCount+rightInversionCount+splitInversionCount;

	return totalInversionsCount;
}

long long countInversion(int arr[],int n)
{
	return countInversionRoutine(arr,n,0,n-1);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		int n;
		cin>>n;
		int arr[n];
		int arr2[n];
		for(int j=0;j<n;++j)
		{
			int temp;
			cin>>temp;
			--temp;
			arr[temp]=j;
		}
		for(int j=0;j<n;++j)
		{
			int temp;
			cin>>temp;
			--temp;
			arr2[j]=arr[temp];
		}

		long long inversionCount=countInversion(arr2,n);

		cout<<inversionCount<<"\n";

	}

	return 0;
}