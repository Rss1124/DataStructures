/*����:�Բ������޸Ľ����Ҫ"������"*/ 

#include<bits/stdc++.h>
using namespace std;

void test(int x){
	x=1024;
	printf("test�����ڲ� x=%d\n",x);
} 

void test2(int & x){
	x=1024;
	printf("test2�����ڲ� x=%d\n",x);
} 

int main(){
	int x=1;
	printf("����test֮ǰ x=%d\n",x);
	test(x);
	printf("����test֮�� x=%d\n",x); 
	test2(x);
	printf("����test2֮�� x=%d\n",x); 	
}
