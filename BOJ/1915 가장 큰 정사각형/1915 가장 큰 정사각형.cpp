#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;

int arr[MAX+1][MAX+1]={0};

int main(){
	int n,m;
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		string tmp;
		cin >> tmp;
		for(int j=0;j<m;j++){
			arr[i][j+1] = tmp[j]-'0';
		}
	}
	
	int answer=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j] > 0){
				arr[i][j] = min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]})+1;
				answer = max(answer, arr[i][j]);
			}
		}
	}
	
	cout << answer * answer << endl;
	
	
}
