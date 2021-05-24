
#include <iostream>
#include <queue>

using namespace std;

struct Stock
{
	int a;
	int b;
	int u;

	Stock()
	{
		this->a = 0;
		this->b = 0;
		this->u = 0;
	}
	Stock(int aa,int bb)
	{
		this->a = aa;
		this->b = bb;
		this->u = 0;
	}
};

bool operator<(const Stock& s1, const Stock& s2)
{
	int p1 = 2*s1.a*(s1.u+1) + s1.b - s1.a;
	int p2 = 2*s2.a*(s2.u+1) + s2.b - s2.a;

	return p1 <= p2;
}
ostream& operator<<(ostream &out, const Stock& stock)
{
	out<<"[ "<<stock.a<<" | "<<stock.b<<" | "<<stock.u<<"]";

	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin>>n>>m;
	priority_queue<Stock> stocksHeap;
	for(int i=0;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		Stock stock(a,b);
		stocksHeap.push(stock);
	}

	int64_t totalProfit=0;
	for(int i=0;i<m;++i)
	{
		Stock stock = stocksHeap.top();
		stocksHeap.pop();
		int profit = 2*stock.a*(stock.u+1) + stock.b - stock.a;
		if(profit < 0)
			break;
		totalProfit += profit;
		++stock.u;
		stocksHeap.push(stock);
	}

	cout<<totalProfit;

	return 0;
}
