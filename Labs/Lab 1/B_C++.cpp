/*
CSE222: ADA (W21):	Lab1
B1
Abhimanyu Gupta:	2019226
Abhinav Gudipati:	2019227
*/

#include <bits/stdc++.h>

using namespace std;

long long getSquare(long long num)
{
	return num*num;
}

double getDistance(pair<int,int> p1,pair<int,int> p2)
{
	double dist=sqrt(getSquare((long long)p1.first-(long long)p2.first)+getSquare((long long)p1.second-(long long)p2.second));

	return dist;
}

double getPerimeter(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3)
{
	double side1=getDistance(p1,p2);
	double side2=getDistance(p1,p3);
	double side3=getDistance(p2,p3);

	double perimeter=side1+side2+side3;

	return perimeter;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	vector<pair<int,int>> points(n);
	for(int i=0;i<n;++i)
		cin>>points[i].first>>points[i].second;

	double minPerimeter=DBL_MAX;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			for(int k=j+1;k<n;++k)
			{
				double perimeter=getPerimeter(points[i],points[j],points[k]);
				minPerimeter=min(minPerimeter,perimeter);
			}

	cout<<setprecision(9)<<minPerimeter<<"\n";

	return 0;
}