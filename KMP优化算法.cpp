/*KMP�Ż��㷨*/ 
#include<bits/stdc++.h>
using namespace std;
string str1,str2; 

string get_modelstr(int n){ //��ȡģ���ַ��� 
	string mstr;
	for(int i=0;i<n;i++){
		mstr+=str2[i];
	}
	return mstr;
}
int get_back(string mstr){ //��ȡ����ֵ,����Ĳ�����ģ���ַ���mstr 
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
bool check_string(string str1,string str2,int *arr){
	for(int i=0,j=0;i<str1.length();i++){		
		if(str1[i]==str2[j]){ //ĳ���ַ�ƥ��ɹ� 
			cout<<"�ɹ�"<<" "<<"i��"<<i<<" "<<"j��"<<j<<endl;//test		
			if(j==str2.length()-1) return true;
			else j++;		
		}
		else if(str1[i]!=str2[j]){
			cout<<"ʧ��"<<" "<<"i��"<<i<<" "<<"j��"<<j<<endl;//test	
			if(i==str1.length()-1) return false;			
			j=arr[j+1]-1;
		}
	}
}

int main(){
	cin>>str1; //str1�Ǵ��ַ��� 
	cin>>str2; //str2��С�ַ���
	int length=str2.length();
	int arr[length+1]={0};	
	get_backarr(str2,arr,length); //��ȡnext�ַ��� 
	cout<<check_string(str1,str2,arr);
//	for(int i=0;i<=length;i++){
//		cout<<arr[i]<<" ";
//	}
}
 
