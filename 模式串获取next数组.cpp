/*��Ŀ��ģʽ����ȡnext����*/ 
#include<bits/stdc++.h>
using namespace std;
string str; 

string get_modelstr(int n); //��ȡģ���ַ��� 
int get_back(string mstr); //��ȡ����ֵ,����Ĳ�����ģ���ַ���mstr 
void get_backarr(string str,int *arr,int length); //��ȡnext���� 

string get_modelstr(int n){
	string mstr;
	for(int i=0;i<n;i++){
		mstr+=str[i];
	}
	return mstr;
}
int get_back(string mstr){ 
	int flag,max=0; //flag������¼ƥ�䵽������ַ������� 
	string str1,str2; //str1������ǰ׺��str2�����ĺ�׺ 
	for(int i=0,j=mstr.length()-1;i<mstr.length()-1;i++,j--){
		str1+=mstr[i]; 
//		cout<<"ǰ׺��"<<str1<<endl; //test
		str2=mstr[j]+str2; //ע��str1�ַ����Ǵ����һ��λ�ò���ģ���str2�ַ����Ǵӵ�һ��λ�ò����
//		cout<<"��׺��"<<str2<<endl; //test
		if(str1==str2){
			flag=str1.length();
			if(flag>=max) max=flag;
		}		 
	} 
	return max+1;
}
void get_backarr(string str,int *arr,int length){
	for(int i=0;i<str.length();i++){
		if(i==0||i==1) arr[i+1]=1; //����ַ����ڵ�һ��ڶ���λ��ƥ������ˣ���ֱ������ӵ�һ��λ�����¿�ʼƥ�� 
		else{
			string mstr=get_modelstr(i);
			arr[i+1]=get_back(mstr);
		} 
	}
//	for(int i=0;i<=length;i++){
//		cout<<arr[i]<<" ";
//	}	
}


int main(){
	cin>>str;
	int length=str.length();
	int arr[length+1]={0};	
	get_backarr(str,arr,length);
	for(int i=0;i<=length;i++){
		cout<<arr[i]<<" ";
	}
}
