#include <iostream>
#include <vector> 
using namespace std;

int arr[51];

int Find(int n){
	if(arr[n] == -1) return n;
	return n = Find(arr[n]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	arr[x] = y;
}

int main(){
	int n,m;
	int conan;
	cin >> n >> m;
	cin >> conan;
	
	vector<int> know;
	vector<vector<int>> v(50);
	
	for(int i=0;i<conan;i++){
		int t;
		cin >> t;
		know.push_back(t);
	}
	
	for(int i=1;i<=n;i++) arr[i] = -1;
	
	for(int i=0;i<m;i++){
		int len;
		cin >> len;
		
		int num;
		cin >> num;
		for(int j=1;j<len;j++){
			int pre = num;
			cin >> num;
			Union(pre, num);
			
			v[i].push_back(num);
		}
	}
	
	for(auto& list : v){
		bool flag = 0;
		
		for(auto& person : list){
			if(flag) break;
			for(auto& t : know){
				if(Find(person) == Find(t)){
					flag = 1;
					break;
				}
			}
		}
		
		if(flag)m--;
	}
	
	cout << m << endl;
	
	
}
