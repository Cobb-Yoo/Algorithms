#include <iostream>
#include <vector>
using namespace std;

int n;

void init(vector<int> &v){
	for(int i=1;i<4;i++) v[i] = i;
}

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	cin >> n;
	
	vector<int> v(4);
	init(v);
	
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		
		swap(v[a], v[b]);
	}
	
	for(int i=1;i<=3;i++){
		if(v[i] == 1) cout << i << endl;
	}
}
