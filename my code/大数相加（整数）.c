#include <iostream>
#include <string>

using namespace std;

string add(string &a1, string &a2)
{
    // please write your code here.
    string max=a1,min=a2;
    int i,j;
    if(a1.size()<a2.size())
    {
        max=a2;
        min=a1;
    }
    for(i=min.size()-1,j=max.size()-1;i>=0;i--,j--)      
    {
        max[j]+=min[i]-'0';//先将Min的所有位加到max的对应位上
    }
    for(i=max.size()-1;i>0;i--)
    {
        if(max[i]>'9')//max每一位是字符型
        {
            max[i]-=10;
            max[i-1]++;
        }
        /*
        if(max[i]>'.')
        {
            max[i]='.';
        }*/
    }
    if(max[0]>'9')//如果max的第一位>9的话，需要往前进一位，但是由于以及是第一位了，所以加一个字符1
    {
        max[0]=max[0]-10;
        max='1'+max;
    }
    return max;
    
}

int main(void){
    string a1, a2, a3;
    cin >> a1 >> a2;
    a3 = add(a1, a2);
    cout<< a3<< endl;
    return 0;
}
