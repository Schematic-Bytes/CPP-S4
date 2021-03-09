#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 10
template <class T>
class stack
{
	T stk[MAX];
	int top;
	T ele;
	public:
		stack()
		{
		top=-1;
		}
		int stackfull()
		{
		if(top==MAX-1)
		{
		cout<<"stack is full";
		return 0;
		}
		else
		return 1;
		}
		int stackempty()
		{
		if(top<0)
		{
		cout<<"stack empty";
		return 0;
		}
		else
		return 1;
		}
		void push()
		{
		if(stackfull()==1)
		{
		cout<<"enter the element";
		cin>>ele;
		stk[++top]=ele;
		cout<<"inserted "<<ele;
		}
		}
		void pop()
		{
		if(stackempty()==1)
		{
		cout<<"deleted "<<stk[top--];
		}
		}
		void display()
		{
		if(stackempty()==1)
		{
		for(int i=top;i>=0;i--)
		cout<<stk[i]<<" ";
		}
		}
};
int main()
{
	int ch;
	stack<float> st;
		while(1)
		{
		cout<<"\n1.Push 2.Pop 3.Display 4.Exit\n Enter your choice";
		cin>>ch;
		switch(ch)
			{
			case 1: st.push(); 
				break;
			case 2: st.pop(); 
				break;
			case 3: st.display(); 
				break;
			case 4: exit(0);
			}
		}
return 0;
}
