#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
	int n; cin >> n;
	int answer = 0;
	vector<int> arr(n);
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	sort(arr.begin(), arr.end());
	
	do{
		int tmp = 0;
		for(int i=0;i<n-1;i++) tmp += abs(arr[i]-arr[i+1]);
		
		answer = max(answer, tmp);
	}while(next_permutation(arr.begin(),arr.end()));
	
	cout << answer << endl;
}
