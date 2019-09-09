找出两个数组中相同的元素，并输出其映射关系 如("a", "a", "b", "c") ("b", "a", "b", "d") 输出 {("a", "a"):"a", "b":("b", "b")}，语言不限
#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

void MapString(map<string,int>& mp1,map<string,int>& mp2)
{
	map<string,int>::iterator it1=mp1.begin();
	map<string,int>::iterator it2=mp2.begin();
	while(it1!=mp1.end())
	{
		it2=mp2.find(it1->first);
		if(it2!=mp2.end())
		{
			if(it1->second>1)
			{
				cout<<"(";
			}
			for(int i=0;i<it1->second;i++)
			{
				cout<<"\""<<it1->first<<"\"";
				if(i!=it1->second-1)
				{
					cout<<",";
				}
			}
			if(it1->second>1)
			{
				cout<<")";
			}
			cout<<":";
			if(it2->second>1)
			{
				cout<<"(";
			}
			for(int i=0;i<it2->second;i++)
			{
				cout<<"\""<<it2->first<<"\"";
				if(i!=it2->second-1)
				{
					cout<<",";
				}
			}
			if(it2->second>1)
			{
				cout<<")";
			}
			cout<<endl;
		}
		it1++;
	}
}
int main()
{
	map<string,int> mp1;
	map<string,int> mp2;
	string s;
	while(1)
	{
		cin>>s;
		mp1[s]+=1;
		if(cin.get()=='\n')
		{
			break;
		}
	}
	while(1)
	{
		cin>>s;
		mp2[s]+=1;
		if(cin.get()=='\n')
		{
			break;
		}
	}
		MapString(mp1,mp2);
	return 0;
}
