#include <iostream>
#include <cstring>
using namespace std;

bool arr[101];

int main(){
	int answer = 0;
	
	int n;
	cin >> n;

	memset(arr,0,sizeof(arr));
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		
		if(arr[tmp] == 0) arr[tmp] = 1;
		else answer++;
	}
	
	cout << answer << endl;
}
