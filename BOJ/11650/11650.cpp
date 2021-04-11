#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std; 

int main()
{
    int n;
    cin >> n;
    
    vector <pair<int,int>> arr(n);
    
    for(int i=0;i<n;i++){
    	scanf("%d %d",&arr[i].first, &arr[i].second);
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i=0;i<n;i++){
		printf("%d %d\n",arr[i].first,arr[i].second);
	}
}
