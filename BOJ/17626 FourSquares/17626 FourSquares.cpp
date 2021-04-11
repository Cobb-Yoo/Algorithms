#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50000+1;
int arr[MAX];
vector<int> v;
int n;

void init(){
	arr[0] = 0;
	arr[1] = 1;
	
	for(int i=1;i*i<MAX;i++){
		v.push_back(i*i);
	}

	
	for(int i=2;i<MAX;i++){
		int Min = 987654321;
		
		for(int j=0;v[j] <= i;j++){
			int tmp = i - v[j];
			Min = min(arr[tmp], Min);
		}
		
		arr[i] = Min + 1;
	}
}

int main(){
	cin >> n;
	init();
	
	cout << arr[n] << endl;
}
