#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int n;
vector<ll> arr(6);

ll answer = 0;

ll surface_2(){
	ll result = arr[0]+arr[1];
	
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			if(i+j == 5) continue;
			
			result = min(result, arr[i]+arr[j]);
		}
	}
	
	return result;
}

ll surface_3(){
	ll result = arr[0]+arr[1]+arr[2];
	
	for(int i=2;i<=3;i++){
		result = min({result, arr[0]+arr[1]+arr[i], arr[0]+arr[4]+arr[i]});
		result = min({result, arr[5]+arr[1]+arr[i], arr[5]+arr[4]+arr[i]});
	}
	
	return result;
}

int main(){
	cin >> n;
	for(int i=0;i<6;i++) cin >> arr[i];
		
	ll sur3 = surface_3();
	ll sur2 = surface_2();
	sort(arr.begin(), arr.end());
	
	if(n == 1) for(int i=0;i<5;i++) answer += arr[i];
	else{
		ll m = arr[0];
		
		answer += sur3*4;
		
		answer += sur2*(n-1)*4;
		answer += sur2*(n-2)*4;
		
		answer += m*(n-2)*(n-2);
		answer += m*(n-2)*(n-1)*4;
	} 
	
	
	cout << answer << endl;
}
