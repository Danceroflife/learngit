#include<algorithm>
#include<vector>
using namespace std;
//冒泡
void bubble_sort(vector<int> &q)
{
	for(int i=q.size()-1;i>0;i--)
	{
		bool flag=false;//优化 若一遍过去并没有交换任何元素 表明数组本身有序，
		for(int j=0;j<i;j++)
		{
			if(q[j]>q[j+1])
			{
				swap(q[j],q[j+1]);
				flag=true;
			}
		}
		if(!flag)
			break;
	}
}

//选择排序
void select_sort(vector<int>& q)
{
	for(int i=0;i<q.size();i++)
	{
		for(int j=i+1;j<q.size();j++)
		{
			if(q[j]<q[i])
				swap(q[i],q[j]);
		}
	}
}

//插入排序==打扑克
void insertSort(vector<int>& q)
{
	for(int i=1;i<q.size();i++)//一个数字已有序 从第二个数字开始 j为已排序 i为将要排序的
	{
		int t=q[i],j;
		for(j=i-1;j>=0;j--)
		{
			if(q[j]>t)
				q[j+1]=q[j];//此处为循环后覆盖
			else
				break;
		}
		q[j+1]=t;//注意为j+1 不是j 一趟for循环排好一个i的位置
	}
}

//希尔排序
void shellSort(vector<int>& q)
{
}

//归并排序
void mergeSort(vector<int>& q,int l,int r)
{
	if(l>=r)
		return ;
	int mid=(l+r)/2;
	mergeSort(q,l,mid);
	mergeSort(q,mid+1,r);

	static vector<int> w;//类似于全局变量 所有的mergeSort()共用这个变量。
	w.clear();

	int i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(q[i]<=q[j])
			w.push_back (q[i++]);
		else
			w.push_back (q[j++]);
	}

	while(i<=mid)
		w.push_back (q[i++]);
	while(j<=r)
		w.push_back (q[j++]);

	for(i=0;i<w.size();i++)
	{
		q[i+l]=w[i];
	}
}

//利用归并排序求数组中的逆序对
int mergeSortReverse(vector<int>& q,int l,int r)
{
	if(l>=r)
		return 0;
	
	int res=0;
	int mid=(l+r)/2;
	res+=mergeSortReverse(q,l,mid);
	res+=mergeSortReverse(q,mid+1,r);

	static vector<int> w;//类似于全局变量 所有的mergeSort()共用这个变量。
	w.clear();

	int i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(q[i]<=q[j])
			w.push_back (q[i++]);
		else
			w.push_back (q[j++]);
			res+=mid-i+1;
	}

	while(i<=mid)
		w.push_back (q[i++]);
	while(j<=r)
		w.push_back (q[j++]);

	for(i=0;i<w.size();i++)
	{
		q[i+l]=w[i];
	}
	return res;
}


//快速排序
void quickSort(vector<int>&q,int l,int r)
{
	if(l>=r)
		return;

	int i=l-1,j=r+1,x=q[l+r>>1];
	while(i<j)
	{
		do j--;while(q[j]>x);
		do i++;while(q[i]<x);
		if(i<j)
			swap(q[i],q[j]);
		else
		{
			quickSort(q,l,j);
			quickSort(q,j+1,r);
		}		
	}
}

int main()
{
	int n;
	vector<int> q;
	cin>>n;
	for(int i=0,t;i<n;i++)
	{
		cin>>t;
		q.push_back(t);
	}

	//bubble_sort(q);
	//select_sort(q);
	//insertSort(q);
	//shellSort(q);
	//mergeSort(q,0,q.size()-1);
	
	//cout<<mergeSortReverse(q,0,q.size()-1)<<endl;

	quickSort(q,0,q.size()-1);

	for(auto x:q)
		cout<<x<<' ';
	cout<<endl;
	return 0;
}
	//insertSort(q);
	//shellSort(q);
	//mergeSort(q,0,q.size()-1);
	
	cout<<mergeSortReverse(q,0,q.size()-1)<<endl;

	for(auto x:q)
		cout<<x<<' ';
	cout<<endl;
	return 0;
}
