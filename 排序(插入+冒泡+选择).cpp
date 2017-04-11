#include <iostream>
using namespace std;
#define ArraySize 8

void inser(int data[])		//插入排序
{
	/*定义需要用到的变量*/
	int contemp;	//临时存放待插入的元素
	int i;	//存放待插入元素的位置
	int j;	//用来指向已被排序好的部分的元素的位置
	for(i=1;i<ArraySize;i++)
	{
		j=i-1;	
		contemp = data[i];
		while(j>=0&&data[j]>contemp)
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=contemp;
	}
}

void maopao(int data[])		//冒泡排序
{
	int contemp;	//临时存放
	for(int i=ArraySize-1;i>0;i--)	//一共需要“ArraySize-1”次循环才能完成
		for(int j=0;j<i;j++)	//每一次循环需要比较的次数是递减的
		{
			if(data[j]>data[j+1])
			{
				contemp=data[j];
				data[j]=data[j+1];
				data[j+1]=contemp;
			}
		}
}

void select(int data[])		//选择排序
{
	int contemp;	//临时存放
	for(int i=0;i<ArraySize-1;i++)		//需要“ArraySize-1”次循环
		for(int j=i+1;j<ArraySize;j++)
		{
			if(data[i]>data[j])
			{
				contemp=data[j];
				data[j]=data[i];
				data[i]=contemp;
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
	/*执行排序,下面有三种排序方法，选择使用哪种就取消注释即可，默认是插入排序*/
	inser(data);	//插入排序
	//maopao(data);		//冒泡排序
	//select(data);		//选择排序
	/*输出排序结果*/
	cout<<""<<endl;
	for(i=0;i<ArraySize;i++)
		cout<<data[i]<<" ";
	return 0;
}