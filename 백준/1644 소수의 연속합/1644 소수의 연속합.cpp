#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v;
bool visited[4000001];

void init(){
	memset(visited,0,sizeof(visited));
	
	for(int i=2;i*i<=4000000;i++){
		if(!visited[i]){
			for(int j=i+i;j<=4000000;j+=i){
				visited[j] = 1;
			}
		}
	}
	
	for(int i=2;i<=4000000;i++){
		if(!visited[i]) v.push_back(i);
	}
}

int main(){
	int n; cin >> n;
	
	init();
	
	int cnt=0;
	int sum=0;
	int left=0, right=0;
	
	while(left<=right && right < v.size() && v[left] <= n){
		if(sum < n) sum += v[right++];
		else if(sum == n){
			cnt++;
			sum += v[right++];
		}
		else if(sum > n){
			sum -= v[left++];
			if(left > right && left < v.size()){
				right = left;
				sum = v[left];
			}
		}
	}
	
	cout << cnt << endl;
} 
