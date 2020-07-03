#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,x;
	cin >> n >> x;
	int arr[n];
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	vector<int> answer;
	for(int i=0;i<n;i++){
		if(arr[i] < x) answer.push_back(arr[i]);
	}
	
	for(int i=0;i<answer.size();i++){
		cout << answer[i] << " ";
	}
}


