#include <iostream>
using namespace std;
#define ArraySize 8


void radix(int data[],int size)
{	
	int n;	
	for(int i=1;i<=100;i=i*10)
	{
		int tmp[20][10]={0};//建立一个20行，10列的数组，每一列分别代表0~9位数，20行代表能存放的总个数
		for(int j=0;j<size;j++)
		{
			n=(data[j]/i)%10;
			tmp[j][n]=data[j];
		}
		int k=0;
		for(int p=0;p<10;p++)
			for(int q=0;q<size;q++)
			{
				if(tmp[q][p]!=0)
					data[k++]=tmp[q][p];
			}
	}

	
}


int main()
{
	int data[ArraySize];
	/*输入数组数据*/
	cout<<"请输入8个数："<<endl;
	for(int i=0;i<ArraySize;i++)
		cin>>data[i];
	/*执行排序*/
	radix(data,8);
	/*输出排序结果*/
	cout<<""<<endl;
	for(i=0;i<ArraySize;i++)
		cout<<data[i]<<" ";
	return 0;
}