#include<iostream>
#define MAX 10
using namespace std;
class stack{
	int stk[MAX];
	int top;
	public:
	stack(){
		top=-1;
	}
	void push(int r){
		if(top==MAX-1)
		cout<<"Overflow";
		else{
		top=top+1;
		stk[top]=r;
		}
	}
	void convert(){
		int n,i;
		cout<<"Enter the number";
		cin>>n;
		i=0;
		while(n>0){
			int r;
			r=n%2;
			n=n/2;
			push(r);
		}
	}
	void display(){
		cout<<"Binary value";
		for(int i=top;i>=0;i--)
		cout<<stk[i]<<" ";
	}
};
int main(){
	stack s;
	s.convert();
	s.display();
	return 0;
}