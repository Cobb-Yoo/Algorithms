#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 1000000+1;

int n;
int arr[MAX];
int check[MAX];
pair<int,int> answer[MAX];
stack<int> s;

int lis(){
	int idx=0;
	check[idx] = arr[0];
	answer[0] = {0,arr[0]};
	
	for(int i=1;i<n;i++){
		if(check[idx] < arr[i]){
			check[++idx] = arr[i];
			answer[i] = {idx,arr[i]};
		}else{
			int idx2 = lower_bound(check,check+idx,arr[i]) - check;
			check[idx2] = arr[i];
			answer[i] = {idx2,arr[i]};
		}
	}
	return idx+1;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	int result = lis();
	cout << result << endl;
	
	int num = result - 1;
	for(int i=n-1;i >= 0;i--){
		if(answer[i].first == num){
			s.push(answer[i].second);
			num--;
		}
	}
	
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}
