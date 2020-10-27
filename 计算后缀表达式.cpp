/*�����׺���ʽ(ֻ�ܼ���0-9�Ĳ�����)__byջʵ��*/ 
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

typedef struct{
	int top;
	int num[MAXSIZE]; //���ڴ�Ų����� 
}CSqStack;

void init_csqstack(CSqStack &S); //ջ�ĳ�ʼ�� 
bool empty(CSqStack &S); //ջ���п�
bool push(CSqStack &S,int num); //��ջ
int pop(CSqStack &S); //��ջ 
int calculate(CSqStack &S); //�����׺���ʽ 

void init_csqstack(CSqStack &S){
	S.top=-1;
}
bool empty(CSqStack &S){
	if(S.top==-1) return true;
	else return false;
}
bool push(CSqStack &S,int num){
	if(S.top==MAXSIZE-1) return false; //ջ���ˣ��޷�������ջ
	S.top=S.top+1;
	S.num[S.top]=num;
	return true; 
}
int pop(CSqStack &S){
	int num;
	if(empty(S)==true) return false; //ջ�ѿգ��޷�������ջ
	num=S.num[S.top];
	S.top=S.top-1;
	return num; 
}
int calculate(CSqStack &S){
	init_csqstack(S);
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>=48&&str[i]<=57){ //��������ַ���0-9�����֣�����ת����int������Ȼ����ѹջ��ȥ 
			int num=(int)str[i]-48;
			push(S,num);
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){ //��������˲�����'+','-','*','/',��ô��Ӧ���Ƚ����ϵ�����������pop�������ж�Ӧ�����㣬�ٰѻ�õ�ֵѹջ��ȥ
			int num1,num2; //num1�����������num2���Ҳ�����
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
