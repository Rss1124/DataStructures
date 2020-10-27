/*计算后缀表达式(只能计算0-9的操作数)__by栈实现*/ 
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

typedef struct{
	int top;
	int num[MAXSIZE]; //用于存放操作数 
}CSqStack;

void init_csqstack(CSqStack &S); //栈的初始化 
bool empty(CSqStack &S); //栈的判空
bool push(CSqStack &S,int num); //入栈
int pop(CSqStack &S); //出栈 
int calculate(CSqStack &S); //计算后缀表达式 

void init_csqstack(CSqStack &S){
	S.top=-1;
}
bool empty(CSqStack &S){
	if(S.top==-1) return true;
	else return false;
}
bool push(CSqStack &S,int num){
	if(S.top==MAXSIZE-1) return false; //栈满了，无法继续入栈
	S.top=S.top+1;
	S.num[S.top]=num;
	return true; 
}
int pop(CSqStack &S){
	int num;
	if(empty(S)==true) return false; //栈已空，无法继续出栈
	num=S.num[S.top];
	S.top=S.top-1;
	return num; 
}
int calculate(CSqStack &S){
	init_csqstack(S);
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>=48&&str[i]<=57){ //如果发现字符是0-9的数字，将其转换成int型数据然后再压栈进去 
			int num=(int)str[i]-48;
			push(S,num);
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){ //如果遇到了操作符'+','-','*','/',那么就应该先将顶上的两个操作数pop出来进行对应的运算，再把获得的值压栈进去
			int num1,num2; //num1是左操作数，num2是右操作数
			num2=pop(S);
//			cout<<"num2="<<num2<<endl; //test
			num1=pop(S); 
//			cout<<"num1="<<num1<<endl; //test
			if(str[i]=='+') push(S,num1+num2);
			else if(str[i]=='-') push(S,num1-num2);
			else if(str[i]=='*') push(S,num1*num2);
			else if(str[i]=='/') push(S,num1/num2);
		}
	}
	return pop(S);
} 
int main(){
	CSqStack S;
	cout<<calculate(S);

} 
