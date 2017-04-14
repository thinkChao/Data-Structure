#include <iostream>
using namespace std;
#define ArraySize 8


void create_heap(int data[],int size)
{
	for(int i=(size/2);i>0;i--)	//从最后一个非终端节点开始遍历，直到根节点
	{
		int l_kid=2*i;	//节点的左孩子
		int r_kid=2*i+1;	//节点的右孩子
		int tmp;	//暂存左孩子还右孩子之间最大的那个节点的数组下标
		int k;	//临时变量
		int j=i;
		while(l_kid<=size)	//要遍历到以该节点为根节点的叶子节点
		{
			
			tmp=l_kid;
			if(l_kid<size)	//l_kid<size,说明存在右孩子
			{
				if(data[l_kid-1]<data[r_kid-1])
					tmp=r_kid;
			}
			if(data[j-1]>data[tmp-1])
				break;
			else
			{
				k=data[j-1];
				data[j-1]=data[tmp-1];
				data[tmp-1]=k;
				l_kid=tmp*2;
				j=tmp;
			}
		}
	}
}

void heap(int data[],int size)
{
	create_heap(data,size);//先建堆
	cout<<"建堆完成：";
	for(int i=0;i<ArraySize;i++)
		cout<<data[i]<<" ";
	cout<<endl;
	int data1[ArraySize];	//存放排序后的结果
	for(i=0;i<size;i++)
	{
		data1[i]=data[0];
		data[0]=0;
		create_heap(data,size);
	}
	for(i=0;i<ArraySize;i++)
		cout<<data1[i]<<" ";
	
}

int main()
{
	int data[ArraySize];
	/*输入数组数据*/
	cout<<"请输入8个数："<<endl;
	for(int i=0;i<ArraySize;i++)
		cin>>data[i];
	/*执行排序*/
	heap(data,8);
	/*输出排序结果*/
	cout<<""<<endl;
	
	return 0;
}