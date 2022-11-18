#include <vector>
#include <iostream>
using namespace std;

vector<int> pytagoras(int a, int b)
{
	vector<int> aRealm;
	vector<int> bRealm;
	vector<int> cRealm;
	vector<int> answer;
	vector<int>::iterator a_itr;
	vector<int>::iterator b_itr;
	vector<int>::iterator c_itr;
	int idx=0;
	int restore=0;
	int i=0;
	int j=0;
	int compare=0;
	int range=0;
	int loopnum=0;
	bool isExist=0;

	if(a>b)
	{
		restore=a;
		a=b;
		b=restore;
	}

	for(idx=0;idx<a;idx++)
	{
		aRealm.push_back(idx*idx);
	}
	for(idx=0;idx<b;idx++)
	{
		bRealm.push_back(idx*idx);
	}
	for(idx=0;idx<b+2;idx++)
	{
		cRealm.push_back(idx*idx);
	}
	for(a_itr=aRealm.begin();a_itr!=aRealm.end();++a_itr)
	{
		for(b_itr=bRealm.begin();b_itr!=bRealm.end();++b_itr)
		{
			compare=(a+b+1)/2;
			c_itr=cRealm.begin();
			isExist=0;
			range=compare-a+1;
			while(range!=0&&isExist==0)
			{
				loopnum++;
				range/=2;
				if((*a_itr)+(*b_itr)>*(c_itr+compare))
				{
					compare+=range;
				}
				else if((*a_itr)+(*b_itr)<*(c_itr+compare))
				{
					compare-=range;
				}
				else
				{
					answer.push_back(*(c_itr+compare));
					isExist=1;
				}
			}
		}
	}
	cout<<"repeat for : "<<loopnum<<endl;
	return answer;
}

int main(void)
{
	vector<int> myvec;
	vector<int>::iterator itr;
	myvec=pytagoras(50,50);
	for(itr=myvec.begin();itr!=myvec.end();++itr)
	{
		cout<<*itr<<endl;
	}
	
	return 0;
}
