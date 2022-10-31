#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > TriNum01()//f(n^3) complexity method
{
	int a=1;
	int b=2;
	int c=3;
	bool isTri=0;
	vector<int> value;
	vector< vector<int> > Set;

	while(c!=50)
	{
		for(a=1;a!=b;++a)
		{
			for(b=2;b!=c;++b)
			{
				if(c*c==a*a+b*b)
				{
					isTri=1;
//					cout<<c<<"^2 = "<<a<<"^2 + "<<b<<"^2"<<endl;
					break;
				}
			}
			if(isTri)
			{
				value.push_back(a);
				value.push_back(b);
				value.push_back(c);
				Set.push_back(value);
				value.clear();
				break;
			}
		}
		isTri=0;
		++c;
	}
	
	return Set;
}

void TriNum02()//print f(n^3) complexity method
{
	#define N	49 + 1
	int a=1;
	int b=2;
	int c=3;
	int loopcount=0;
	bool isTri=0;
	
	while( c < N )
	{
		for(a=1;a<N;++a)
		{
			for(b=a+1;b<N;++b)
			{
				++loopcount;
				if(c*c==a*a+b*b)
				{
//					isTri=1;
					cout<<a<<", "<<b<<", "<<c<<endl;
					break;
				}
			}
/*			if(isTri)
			{
				break;
			}*/
		}
//		isTri=0;
		++c;
	}
	cout<<loopcount<<endl;
}

void TriNum02A()//In vector, index is each length of side and value is each square of side
{
	#define N	49 + 1
	int a=1;
	int b=2;
	int c=0;
	int c_count=0;
	int loopcount=0;
	vector<int> cc;
	vector<int>::iterator c_itr;

	while(c<50)
	{
		cc.push_back(c*c);
		++c;
	}

	for(a=1;a<N;++a)
	{
		for(b=a+1;b<N;++b)
		{			
			if(*(cc.begin()+a)+*(cc.begin()+b)>2500)
			{
				break;
			}
			for(c_itr=cc.begin(),c_count=0;c_itr!=cc.end();++c_itr, ++c_count)
			{
				++loopcount;
				if((*c_itr)==*(cc.begin()+a)+*(cc.begin()+b))
				{
					cout<<a<<", "<<b<<", "<<c_count<<endl;
					break;
				}
			}			
		}
	}
	cout<<loopcount<<endl;
}

void TriNum02Aa()//Exit condition
{
	#define N	49 + 1
	int a=1;
	int b=2;
	int c=0;
	int c_count=0;
	int loopcount=0;
	int isOver=0;
	vector<int> cc;
	vector<int>::iterator c_itr;

	while(c<N)
	{
		cc.push_back(c*c);
		++c;
	}

	for(a=1;a<N;++a)
	{
		for(b=a+1;b<N;++b)
		{			
			if(*(cc.begin()+a)+*(cc.begin()+b)>2500)
			{
				++isOver;
				break;
			}
			for(c_itr=cc.begin()+b+1,c_count=b+1;c_itr!=cc.end();++c_itr, ++c_count)
			{
				++loopcount;
				if(*(cc.begin()+a)+*(cc.begin()+b)<(*c_itr))
				{
					break;
				}
				if((*c_itr)==*(cc.begin()+a)+*(cc.begin()+b))
				{
					cout<<a<<", "<<b<<", "<<c_count<<endl;
					break;
				}
			}			
		}
	}
	cout<<loopcount<<endl;
	cout<<isOver<<endl;
}

void TriNum03()//print as Formula
{
	int m=2;
	int n=1;
	int a=0;
	int b=0;
	int c=0;
	
	while(m*m+n*n<50)
	{
		for(n=1;n<m;++n)
		{
			a=m*m-n*n;
			b=2*m*n;
			c=m*m+n*n;
			cout<<a<<", "<<b<<", "<<c<<endl;
		}
		++m;
	}
}

vector< vector<int> > TriNum04()//Formula
{
	int m=2;
	int n=1;
	int a=0;
	int b=0;
	int c=0;
	vector<int> value;
	vector< vector<int> > Set;
	
	while(m*m+n*n<50)
	{
		for(n=1;n<m;++n)
		{
			a=m*m-n*n;
			b=2*m*n;
			c=m*m+n*n;
			value.push_back(a);
			value.push_back(b);
			value.push_back(c);
//			cout<<a<<", "<<b<<", "<<c<<endl;
		}
		Set.push_back(value);
		value.clear();
		++m;
	}
	return Set;
}

void ownSort(vector< vector<int> > MV)
{
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;
	vector< vector<int> >::iterator compare_row;
	vector<int>::iterator compare_col;
	vector<int> restore;
	
	for(row=MV.begin();row!=MV.end();++row)
	{
		col=row->begin();
		for(compare_row=row+1;compare_row!=MV.end();++compare_row)
		{
			compare_col=compare_row->begin();
			if((*col)>(*compare_col))
			{
				restore.push_back((*col));
				restore.push_back((*(col+1)));
				restore.push_back((*(col+2)));
				(*col)=(*compare_col);
				(*compare_col)=(*restore.begin());
				(*(compare_col+1))=(*(restore.begin()+1));
				(*(compare_col+2))=(*(restore.begin()+2));
				restore.clear();
			}
		}
	}
}

int main(void)
{
	vector< vector<int> > answer;
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;
	vector< vector<int> > answer_second;
	vector< vector<int> >::iterator com_row;
	vector<int>::iterator com_col;
/*	
	answer=TriNum01();
	ownSort(answer);
	for(row=answer.begin();row!=answer.end();++row)
	{
		col=row->begin();
		cout<<(*col)<<", "<<(*(col+1))<<", "<<(*(col+2))<<endl;
	}
*/	
	cout<<endl;
/*	
	answer_second=TriNum04();
	ownSort(answer_second);
	for(com_row=answer_second.begin();com_row!=answer_second.end();++com_row)
	{
		com_col=com_row->begin();
		cout<<(*com_col)<<", "<<(*(com_col+1))<<", "<<(*(com_col+2))<<endl;
	}
*/

	TriNum02();
	cout<<endl;
//	TriNum02A();
	cout<<endl;
	TriNum02Aa();
//	TriNum03();

	return 0;
}
