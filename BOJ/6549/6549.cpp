#include <iostream>
using namespace std;

int MAX = 0;
int maxCnt;
int n;
int arr[100001];
int value;

int right(int cnt){
	int result = 0;
	if(cnt < n && (value <= arr[cnt])){
		result = value + right(cnt+1);
		return result;
	}else{
		return 0;
	}
}
int left(int cnt){
	int result = 0;
	if(cnt >= 0 && (value <= arr[cnt])){
		result = value + left(cnt-1);
		return result;
	}else{
		return 0;
	}
}
void cal(int cnt){
	int result=0;
	
	result += right(cnt+1);
	result += left(cnt-1);
	result += arr[cnt];
	
	if(MAX < result){
		MAX = result;
		maxCnt = cnt;
	}
}

int main(){
	while(cin >> n && n){
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
	
		for(int i=0;i<n;i++) {
			value = arr[i];
			cal(i);
		}
		
		cout << MAX << endl;
	}
}
