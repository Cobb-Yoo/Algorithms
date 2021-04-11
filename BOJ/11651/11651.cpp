#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector <pair<int, int>> arr(n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&arr[i].second, &arr[i].first);
	}
	
	sort(arr.begin(),arr.end());
	
	for(int i=0;i<n;i++){
		printf("%d %d\n",arr[i].second, arr[i].first);
	}
}
