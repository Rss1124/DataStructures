/*题目:中缀表达式转后缀表达式(只能转换0-9的中缀表达式)__by栈实现
注意:要想进行十位数及其以上的中缀表达式转后缀表达式，需要开辟新的栈来同时存放操作数和运算符*/ 
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
string str1,str2;

typedef struct{
	char c[MAXSIZE]; //运算符
	int top; //栈顶指针 
}SqStack;

bool init_SqStack(SqStack &S); //栈的初始化
bool empty(SqStack S); //栈的判空
bool push(SqStack &S,char ch); //入栈 
char pop(SqStack &S); //出栈 
void change(SqStack &S); //前缀转后缀 

bool init_SqStack(SqStack &S){
	S.top=-1;
}
bool empty(SqStack S){
	if(S.top==-1) return true;
	else return false;
}
bool push(SqStack &S,char ch){
	if(S.top==MAXSIZE-1) return false; //栈已满，无法入栈
	S.top=S.top+1;
	S.c[S.top]=ch;
	return true; 
}
char pop(SqStack &S){
	char ch;
	if(S.top==-1) return false; //栈已空，无法出栈
	ch=S.c[S.top];
	S.top=S.top-1;
	return ch; 
}
void change(SqStack &S){
	init_SqStack(S);
	cin>>str1;
	for(int i=0;i<str1.length();i++){
		if(str1[i]>=48&&str1[i]<=57) str2+=str1[i]; //如果发现是操作数0-9,直接输出 
//		else if(str1[i]=='(') push(S.c);//如果发现左括号，直接入栈 
		else if(str1[i]=='+'||str1[i]=='-'||str1[i]=='*'||str1[i]=='/'){ //如果发现是运算符 
			if(empty(S)==true) push(S,str1[i]); //如果此时栈是空的，则直接入栈
			else{ //如果栈不为空 
				if(str1[i]=='*'||str1[i]=='/'||S.c[S.top]=='(') push(S,str1[i]); //如果此时是最高级的操作符'*'或者'/'再或者操作符下面是一个'(',则直接入栈 
				else{ //否则将下面的元素出栈,出栈后再将新的操作符入栈 
					str2+=pop(S);
					push(S,str1[i]); 
				}
			} 
		}
		else if(str1[i]=='(') push(S,str1[i]); //如果发现是左括号，直接入栈 
		else if(str1[i]==')'){
			while(S.c[S.top]!='('){ //注意while循环的规则，当满足括号内的条件时，while循环就会停止 
				str2+=pop(S);
			}
			pop(S);
//			cout<<"test:"<<S.top<<" "<<S.c[S.top]<<endl; 
		} 
		
	}
	for(int i=S.top;i>=0;i--){
		str2+=pop(S);
	}		
	cout<<str2; 	
}


int main(){
	SqStack S;
	change(S);
}


