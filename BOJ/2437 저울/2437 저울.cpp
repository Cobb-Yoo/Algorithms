#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	int answer = 0;
	sort(arr.begin(),arr.end());
	
	for(int i=0;i<n;i++){
		if(answer+1 < arr[i]) break;
		answer += arr[i];
	}
	
	cout << answer+1 << endl;
}
