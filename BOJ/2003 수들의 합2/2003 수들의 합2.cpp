#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	
	int answer = 0;
	for(int i=0;i<n;i++){
		int sum = 0;
		
		for(int j=i;j<n;j++){
			sum+= arr[j];
			if(sum > m) break;
			else if (sum == m) {
				answer++;
				break;
			}
		}
	}
	
	cout << answer << endl;
}
