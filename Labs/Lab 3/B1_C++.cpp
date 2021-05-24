
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,totalMoney;
	cin>>n>>totalMoney;
	vector<pair<int,int>> coefficients(n);
	for(int i=0;i<n;++i)
		cin>>coefficients[i].first>>coefficients[i].second;
	
	int maxProfit=0;
	for(int i=0;i<n;++i)
	{
		int a=coefficients[i].first;
		int b=coefficients[i].second;
		
		int tempProfit=a*totalMoney*totalMoney+b*totalMoney;
		maxProfit=max(maxProfit,tempProfit);
	}

	cout<<maxProfit;

	return 0;
}