#include<bits/stdc++.h>
using namespace std;

int dfs(int num){
	if(num==1) return num;
	else return num*dfs(num-1);
} 

int main(){
	cout<<dfs(10);
}
