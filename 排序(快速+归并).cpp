#include <iostream>
using namespace std;
#define ArraySize 5

/*快速排序*/
void quick(int data[],int lf,int rg)
{
	int tmp;
	//int mid=data[lf_idx];
	int lf_idx=lf+1;
	int rg_idx=rg;
	if(lf<rg)
	{
		while(1)
		{
			for(int i=lf_idx;i<=rg;i++)          //一开始用的i<=rg_idx,这是不可以的
			{
				if(data[i]>=data[lf])
				{
					lf_idx=i;
					break;
				}
				lf_idx=i;
			}
			for(int j=rg_idx;j>=lf;j--)
			{
				if(data[j]<=data[lf])
				{
					rg_idx=j;
					break;
				}
				rg_idx=j;
			}
			if(lf_idx<rg_idx)
			{
				tmp=data[lf_idx];
				data[lf_idx]=data[rg_idx];
				data[rg_idx]=tmp;
			}
			else
				break;
		}
		tmp=data[lf];
		data[lf]=data[rg_idx];
		data[rg_idx]=tmp;
		quick(data,lf,rg_idx-1);
		quick(data,rg_idx+1,rg);
	}
}

/*归并排序*/
void merge(int data[],int left,int mid,int right)
{
	int *temp_data = new int[right-left+1];
	int i=left,j=mid+1;
	int k=0;
	while(i<=mid&&j<=right)
	{
		if(data[i]>data[j])
		{
			temp_data[k]=data[j];
			k++;
			j++;
		}
		else
		{
			temp_data[k]=data[i];
			k++;
			i++;
		}
	}
	while(i<=mid)
		temp_data[k++]=data[i++];
	while(j<=right)
		temp_data[k++]=data[j++];
	for(i=left,j=0;i<=right;i++)                  
        data[i]=temp_data[j++];
}


void merge_sort(int data[],int array_size)
{
	int left;
	int right;
	int mid;
	for(int i=1;i<array_size;i=i*2)
	{
		left=0;
		while(left<array_size)
		{
			mid=left+(i-1);
			right=left+2*(i-1)+1;
			if(mid>=array_size)
				mid=array_size-1;
			if(right>=array_size)
				right=array_size-1;
			merge(data,left,mid,right);
			left=right+1;
		}
	}
}


int main()
{
	int data[ArraySize];
	/*输入数组数据*/
	cout<<"请输入5个数："<<endl;
	for(int i=0;i<ArraySize;i++)
		cin>>data[i];
	/*执行排序程序*/
	quick(data,0,4);	//快速排序
	//merge_sort(data,5);	//归并排序
	/*输出排序结果*/
	cout<<""<<endl;
	for(i=0;i<ArraySize;i++)
		cout<<data[i]<<" ";
	return 0;
}