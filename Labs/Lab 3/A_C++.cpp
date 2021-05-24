
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int& aa:arr)
		cin>>aa;

	int minDuration=-1;

	int low=1;
	int high=arr.back()-arr.front();
	while(low<=high)
	{
		int mid=low+(high-low)/2;

		int kk=k;
		int day=0;
		while(day<n && kk>0)
		{
			--kk;
			day=lower_bound(arr.begin(),arr.end(),arr[day]+mid)-arr.begin();
		}

		if(kk==0)
		{
			minDuration=max(minDuration,mid);
			low=mid+1;
		}
		else
			high=mid-1;
	}

	cout<<minDuration;

	return 0;
}
