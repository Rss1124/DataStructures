/*结论:对参数的修改结果需要"带回来"*/ 

#include<bits/stdc++.h>
using namespace std;

void test(int x){
	x=1024;
	printf("test函数内部 x=%d\n",x);
} 

void test2(int & x){
	x=1024;
	printf("test2函数内部 x=%d\n",x);
} 

int main(){
	int x=1;
	printf("调用test之前 x=%d\n",x);
	test(x);
	printf("调用test之后 x=%d\n",x); 
	test2(x);
	printf("调用test2之后 x=%d\n",x); 	
}
