#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 20
string str1,str2;

typedef struct{
	char c[MAXSIZE]; //运算符
	int top; //栈顶指针 
}SqStack;

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
				if(str1[i]=='*'||str1[i]=='/') push(S,str1[i]); //如果此时是最高级的操作符'*'或者'/',则直接入栈 
				else{ //否则将下面的元素出栈,出栈后再将新的操作符入栈 
					str2+=pop(S);
					push(S,str1[i]); 
				}
			} 
		}
		else if(str1[i]=='(') push(S,str1[i]); //如果发现是左括号，直接入栈 
		else if(str1[i]==')'){
			while(S.c[S.top+1]=='('){
				str2+=pop(S);
			}
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


