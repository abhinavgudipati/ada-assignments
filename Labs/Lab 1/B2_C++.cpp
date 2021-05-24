/*
Abhimanyu Gupta:	2019226
Abhinav Gudipati:	2019227

Course:
https://sites.google.com/iiitd.ac.in/ada2021/
CSE222: ADA (W21):	Lab1
http://foobar.iiitd.edu.in/ B2	
*/

#include <bits/stdc++.h>

using namespace std;

bool compareY(const pair<int,int> &p1,const pair<int,int> &p2)
{
	if(p1.second<p2.second)
		return true;
	else if(p1.second==p2.second)
		return p1.first<=p2.first;
	else
		return false;
}

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

double minPerimeterTriangleStrip(double extremeDistance,const pair<int,int> &partitionPoint,const vector<pair<int,int>> &pointsY)
{
	vector<pair<int,int>> stripPoints;
	stripPoints.reserve(pointsY.size());
	for(int i=0;i<pointsY.size();++i)
	{
		if(abs(pointsY[i].first-partitionPoint.first)<=extremeDistance)
			stripPoints.push_back(pointsY[i]);
	}

	double minPerimeter=DBL_MAX;
	int n=stripPoints.size();
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(stripPoints[j].second-stripPoints[i].second>extremeDistance)
				break;
			for(int k=j+1;k<n;++k)
			{		
				if(stripPoints[k].second-stripPoints[j].second>extremeDistance)
					break;
				double perimeter=getPerimeter(stripPoints[i],stripPoints[j],stripPoints[k]);
				minPerimeter=min(minPerimeter,perimeter);
			}
		}
	}

	return minPerimeter;
}

double minPerimeterTriangle(const vector<pair<int,int>> &pointsX,const vector<pair<int,int>> &pointsY)
{
	if(pointsX.size()<3)
		return DBL_MAX;
	else if(pointsX.size()==3)
		return getPerimeter(pointsX[0],pointsX[1],pointsX[2]);

	int n=pointsX.size();
	vector<pair<int,int>> leftPointsX(pointsX.begin(),pointsX.begin()+n/2);
	vector<pair<int,int>> rightPointsX(pointsX.begin()+n/2,pointsX.end());

	vector<pair<int,int>> leftPointsY;
	vector<pair<int,int>> rightPointsY;
	leftPointsX.reserve(n/2);
	rightPointsY.reserve(n/2);

	pair<int,int> middlePoint=rightPointsX[0];
	for(int i=0;i<n;++i)
	{
		if(pointsY[i].first<middlePoint.first)
			leftPointsY.push_back(pointsY[i]);
		else if(pointsY[i].first==middlePoint.first && pointsY[i].second<middlePoint.second)
			leftPointsY.push_back(pointsY[i]);
		else
			rightPointsY.push_back(pointsY[i]);
	}

	double minPerimeterLeft=minPerimeterTriangle(leftPointsX,leftPointsY);
	double minPerimeterRight=minPerimeterTriangle(rightPointsX,rightPointsY);

	double minPerimeter=min(minPerimeterLeft,minPerimeterRight);
	double minPerimeterStrip=minPerimeterTriangleStrip(minPerimeter/2,middlePoint,pointsY);

	minPerimeter=min(minPerimeter,minPerimeterStrip);
	return minPerimeter;
}

double minPerimeterTriangle(const vector<pair<int,int>> &points)
{
	vector<pair<int,int>> pointsX=points;
	vector<pair<int,int>> pointsY=points;

	sort(pointsX.begin(),pointsX.end());
	sort(pointsY.begin(),pointsY.end(),compareY);

	return minPerimeterTriangle(pointsX,pointsY);
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

	double minPerimeter=minPerimeterTriangle(points);

	cout<<fixed<<setprecision(9)<<minPerimeter<<"\n";

	return 0;
}