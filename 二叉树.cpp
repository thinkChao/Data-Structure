#include <iostream>
using namespace std;
#define ArraySize 6
//定义二叉树节点
struct Node
{
	int value;
	struct Node *left_node;
	struct Node *right_node;
};
typedef struct Node TNode;	//定义二叉树节点
typedef TNode *BTree;	//定义二叉树链表
BTree bTree;		//
//建树，按“左小右大”的原则建的
void Add_Node(int value)
{
	/*定义需要用到的变量*/
	TNode *newNode;		//待插入的新节点
	BTree currentNode;		//临时的指针
	int flag = 0;		//记录是否插入了新的节点

	newNode = (TNode *)malloc(sizeof(TNode));		//为新节点分配空间并输入内容
	newNode->value = value;
	newNode->left_node = NULL;
	newNode->right_node = NULL;
	/*将新节点插入二叉树*/
	if(bTree == NULL)
		bTree = newNode;
	else
	{
		currentNode = bTree;
		while(!flag)		//循环结束的时刻是：flag=1，即节点已被插入
		{
			if(value<currentNode->value)
			{
				if(currentNode->left_node==NULL)
				{
					currentNode->left_node=newNode;
					flag=1;
				}
				else
					currentNode=currentNode->left_node;
			}
			else
			{
				if(currentNode->right_node==NULL)
				{
					currentNode->right_node=newNode;
					flag=1;
				}
				else
					currentNode=currentNode->right_node;
			}
		}
	}
}

void Preorder(BTree bTree)		//递归前序遍历
{
	if(bTree!=NULL)
	{
		cout<<bTree->value<<" ";
		Preorder(bTree->left_node);
		Preorder(bTree->right_node);
	}
}

void Preorder2(BTree bTree)		//非递归前序遍历
{
	/*定义需要用到的变量*/
	BTree stack[ArraySize];		//用数组来充当栈
	int top=0;		//top变量来充当栈顶指针，top为0说明栈空
	BTree p=bTree;
	while(p||top!=0)
	{
		if(p)
		{
			cout<<p->value<<" ";
			stack[top++]=p;
			p=p->left_node;
		}
		else
		{
			p=stack[--top];		//注意这里是“--top”
			p=p->right_node;
		}
	}
}

void Inorder(BTree bTree)		//递归中序遍历
{
	if(bTree!=NULL)
	{
		Inorder(bTree->left_node);
		cout<<bTree->value<<" ";
		Inorder(bTree->right_node);
	}
}

void Inorder2(BTree bTree)		//非递归中序遍历
{
	/*定义需要用到的变量*/
	BTree stack[ArraySize];		//用数组来充当栈
	int top=0;		//top变量来充当栈顶指针，top为0说明栈空
	BTree p=bTree;
	while(p||top!=0)	//举例：建立一个只有三个节点的二叉树发现，当p的指向为空，且top=0的时候，所有的元素都已经遍历过了
	{
		if(p)
		{
			stack[top++]=p;
			p=p->left_node;
		}
		else	//举例发现，当p指向为空时，就要执行出战操作，然后输出元素
		{
			p=stack[--top];		//注意这里是“--top”
			cout<<p->value<<" ";
			p=p->right_node;
		}
	}
}

void Postorder(BTree bTree)		//递归后序遍历
{
	if(bTree!=NULL)
	{
		Postorder(bTree->left_node);
		Postorder(bTree->right_node);
		cout<<bTree->value<<" ";
	}

}

void Postorder2(BTree bTree)		//非递归后序遍历
{
	BTree stack1[ArraySize];
	int stack2[ArraySize];
	int top1=0,top2=0;
	int flag;
	BTree p=bTree;
	while(p||top1!=0)
	{
		if(p)
		{
			stack1[top1++]=p;
			stack2[top2++]=0;
			p=p->left_node;
		}
		else
		{
			p=stack1[top1-1];		
			flag=stack2[top2-1];
			if(flag==0)
			{
				stack2[top2-1]=1;
				p=p->right_node;
			}
			else
			{
				p=stack1[--top1];
				--top2;
				cout<<p->value<<" ";
				p=NULL;		//这一句很关键，调试了一上午，问题就是没有加上这一句。
			}
		}
	}
}

int main()
{
	int content[ArraySize];
	cout<<"请输入6个整数："<<endl;	//输入数据
	for(int i=0;i<ArraySize;i++)
		cin>>content[i];
	for(i=0;i<ArraySize;i++)	//建树
		Add_Node(content[i]);
	cout<<"建树完成!"<<endl;
	cout<<"递归前序遍历：";
	Preorder(bTree);
	cout<<"非递归前序遍历：";
	Preorder2(bTree);
	cout<<endl;

	cout<<"递归中序遍历：";
	Inorder(bTree);
	cout<<"非递归中序遍历：";
	Inorder2(bTree);
	cout<<endl;

	cout<<"递归后序遍历：";
	Postorder(bTree);
	cout<<"非递归后序遍历：";
	Postorder2(bTree);
	cout<<endl;
	return 0;
}