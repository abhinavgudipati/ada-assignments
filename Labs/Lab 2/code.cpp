
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int maxNum=1000;
	vector<int> deadPairs(maxNum+1,-1);
	vector<bool> taken(maxNum+1);
	int i=0;
	int dif=0;
	while(i+dif<=maxNum)
	{
		if(!taken[i])
		{
			taken[i]=true;
			int j=i+dif;
			taken[j]=true;
			deadPairs[i]=j;
			deadPairs[j]=i;
			++dif;
		}
		++i;
	}

	int t=1;
	cin>>t;
	++t;
	while(--t)
	{
		int a,b;
		cin>>a>>b;

		if(deadPairs[a]!=b)
			cout<<"YES";
		else
			cout<<"NO";

		cout<<"\n";
	}

	return 0;
}