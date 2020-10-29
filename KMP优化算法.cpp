/*KMP优化算法*/ 
#include<bits/stdc++.h>
using namespace std;
string str1,str2; 

string get_modelstr(int n){ //获取模型字符串 
	string mstr;
	for(int i=0;i<n;i++){
		mstr+=str2[i];
	}
	return mstr;
}
int get_back(string mstr){ //获取返回值,代入的参数是模型字符串mstr 
	int flag,max=0; //flag用来记录匹配到的最长的字符串长度 
	string str1,str2; //str1：串的前缀，str2：串的后缀 
	for(int i=0,j=mstr.length()-1;i<mstr.length()-1;i++,j--){
		str1+=mstr[i]; 
//		cout<<"前缀："<<str1<<endl; //test
		str2=mstr[j]+str2; //注意str1字符串是从最后一个位置插入的，而str2字符串是从第一个位置插入的
//		cout<<"后缀："<<str2<<endl; //test
		if(str1==str2){
			flag=str1.length();
			if(flag>=max) max=flag;
		}		 
	} 
	return max+1;
}
void get_backarr(string str,int *arr,int length){
	for(int i=0;i<str.length();i++){
		if(i==0||i==1) arr[i+1]=1; //如果字符串在第一或第二个位置匹配错误了，则直接让其从第一个位置重新开始匹配 
		else{
			string mstr=get_modelstr(i);
			arr[i+1]=get_back(mstr);
		} 
	}
//	for(int i=0;i<=length;i++){
//		cout<<arr[i]<<" ";
//	}	
}
bool check_string(string str1,string str2,int *arr){
	for(int i=0,j=0;i<str1.length();i++){		
		if(str1[i]==str2[j]){ //某个字符匹配成功 
			cout<<"成功"<<" "<<"i："<<i<<" "<<"j："<<j<<endl;//test		
			if(j==str2.length()-1) return true;
			else j++;		
		}
		else if(str1[i]!=str2[j]){
			cout<<"失败"<<" "<<"i："<<i<<" "<<"j："<<j<<endl;//test	
			if(i==str1.length()-1) return false;			
			j=arr[j+1]-1;
		}
	}
}

int main(){
	cin>>str1; //str1是大字符串 
	cin>>str2; //str2是小字符串
	int length=str2.length();
	int arr[length+1]={0};	
	get_backarr(str2,arr,length); //获取next字符串 
	cout<<check_string(str1,str2,arr);
//	for(int i=0;i<=length;i++){
//		cout<<arr[i]<<" ";
//	}
}
 
