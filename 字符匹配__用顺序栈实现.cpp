/*字符匹配__用顺序栈实现
核心算法：依次扫描所有字符，如果遇到左括号则把它入栈，如果是右括号则把它出栈，并进行匹配 
匹配成功返回1,匹配失败返回0
匹配失败的情况：左括号单身；右括号单身；左右括号不匹配 
*/ 
#include<bits/stdc++.h>
using namespace std; 
#define MAXSIZE 10

typedef struct{
	char data[MAXSIZE];
	int top; //栈顶指针 
}SqStack;

bool char_match(string str,int length); //超重点：字符匹配算法，务必细品 
void init_stack(SqStack &S); //顺序栈的初始化
bool empty(SqStack S); //顺序栈判空
bool push(SqStack &S,char c); //入栈
bool pop(SqStack &S,char &c); //出栈 

void init_stack(SqStack &S){
	S.top=-1;
}
bool empty(SqStack S){
	if(S.top==-1) return true; //空栈 
	else return false;
}
bool push(SqStack &S,char c){
	if(S.top==MAXSIZE-1) return false; //栈满了 
	S.top=S.top+1;
	S.data[S.top]=c;
	return true;
}
bool pop(SqStack &S,char &c){
	if(S.top==-1) return false; //栈空了 
	c=S.data[S.top];
	S.top=S.top-1;
	return true; 
}
bool char_match(string str,int length){
	SqStack S;
	init_stack(S);
	for(int i=0;i<length;i++){
		if(str[i]=='('||str[i]=='['||str[i]=='{'){ //遍历顺序栈 
			push(S,str[i]); //扫描到左括号，入栈 
		}
		else{
			if(empty(S)==true) return false; //如果此时扫描到右括号，且栈为空，直接返回 
			char topElem;
			pop(S,topElem); //扫描到右括号，出栈进行匹配 
			if(str[i]==')' && topElem!='(') return false;
			if(str[i]==']' && topElem!='[') return false;
			if(str[i]=='}' && topElem!='{') return false;
		}
	}
	return empty(S);
}

int main(){
	string str;
	cin>>str;
	int l=str.length();
	cout<<char_match(str,l);
}


