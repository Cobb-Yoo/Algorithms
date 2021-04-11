#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool sel[100];
vector<int> v;

void print(){
	for(int i=0;i<v.size();i++){
		printf("%d ",v[i]);
	}
	printf("\n");
}

void dfs(int a){
	if(a == m) print();
	
	for(int i=0;i<n;i++){
		
		if(!sel[i]){
			sel[i] = true;
			v.push_back(i+1);
			dfs(a+1);
			sel[i] = false;
			v.pop_back();
		}
	}
}

int main(){
	cin >> n >> m;// m이 수열의 수
	
	dfs(0);
}
