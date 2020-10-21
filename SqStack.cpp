/*顺序栈的实现
缺点：栈的大小不可变 
*/ 
#include<bits/stdc++.h>
using namespace std; 
#define MAXSIZE 10
typedef struct{
	int data[MAXSIZE];
	int top; //表示栈顶指针，一般表示数组的下标 
}SqStack;

void init_sqstack(SqStack &S); //初始化栈 
bool empty_sqstack(SqStack S); //判断栈是否为空
bool push(SqStack &S,int e); //将元素e入栈 
bool pop(SqStack &S,int &e); //将栈顶元素出栈,并通过变量e返回 
bool get_top(SqStack &S,int &e); //读取栈顶元素,并通过变量e返回 

void init_sqstack(SqStack &S){
	S.top=-1;
} 
bool empty_sqstack(SqStack S){
	if(S.top==-1) return true;
	else return false;
}
bool push(SqStack &S,int e){
	if(S.top==MAXSIZE-1) return false; //此时栈已满，无法插入
	S.top=S.top+1;
	S.data[S.top]=e; //S.top的值就是数组的下标 
	return true; 
}
bool pop(SqStack &S,int &e){
	if(S.top==-1) return false; //此时已经是空栈，没有元素可以出栈了
	e=S.data[S.top]; //S.top的值就是数组的下标 
	S.top=S.top-1;
	return true; 
} 
bool get_top(SqStack &S,int &e){
	if(S.top==-1) return false; ////此时已经是空栈，没有栈顶元素了
	e=S.data[S.top];
	return true; 
} 

int main(){
	SqStack S;
	init_sqstack(S);
}
