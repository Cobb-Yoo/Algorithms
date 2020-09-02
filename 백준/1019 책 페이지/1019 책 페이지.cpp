#include <iostream>
#include <cstring>
using namespace std;

long long arr[10];

void calculate(int n, int idx){
	while(n){
		arr[n%10] += idx;
		n /= 10;
	}
}

void solve(int start, int end, int idx){
	while(start%10 && start <= end){
		calculate(start, idx);
		start++;
	}
	
	if(start > end) return;
	
	while(end%10 != 9 && start <= end){
		calculate(end, idx);
		end--;
	}
	
	long long cnt = (end/10 - start/10+1);
	
	for(int i=0;i<10;i++) arr[i] += cnt * idx;
	
	solve(start/10, end/10, idx*10);
}

int main(){
	memset(arr,0,sizeof(arr));
	int n;
	cin >> n;
	
	solve(1,n,1);
	
	for(int i=0;i<10;i++) cout << arr[i] << " ";
}
