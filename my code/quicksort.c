#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//划分
int partition(vector<int>&arr,int s,int e)
{
	int k=arr[s];
	while(s<e)
	{
		while(s<e&&arr[e]>=k)
			e--;
		arr[s]=arr[e];
		while(s<e&&arr[s]<=k)
			s++;
		arr[e]=arr[s];
	}
	arr[s]=k;
	return s;

}
//递归
void quick1(vector<int> &arr,int s,int e)
{
	if(s<=e)
	{
		int bondindex=partition(arr,s,e);
		quick1(arr,s,bondindex-1);
		quick1(arr,bondindex+1,e);
	}
}
//非递归
void quick2(vector<int> &arr,int s,int e)
{
	if(s>=e)
		return;
	stack<int> sc;
	sc.push(s);
	sc.push(e);
	while(!sc.empty())
	{
		int e=sc.top();
		sc.pop();
		int s=sc.top();
		sc.pop();
		if(s<e)
		{
			int bondindex2=partition(arr,s,e);
			sc.push(s);
			sc.push(bondindex2-1);

			sc.push(bondindex2+1);
			sc.push(e);
		}
	}
}
int main()
{
	vector<int> vec;
	int tmp;
	while(cin>>tmp)
	{
		vec.push_back(tmp);
		if(cin.get()=='\n')
			break;
	}
	quick1(vec,0,vec.size()-1);
	quick1(vec,0,vec.size()-1);
	for(auto x:vec)
		cout<<x<<' ';
	return 0;
}
