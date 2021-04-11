#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;
ll b;
int arr[6][6];

vector<vector<int>> cal(ll cnt){
	vector<vector<int>> tmp(n, vector<int>(n));
	vector<vector<int>> result(n, vector<int>(n));
			
	if(cnt == 1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				tmp[i][j] = arr[i][j] % 1000;
			}
		}
		return tmp;
	}
	else if(cnt % 2){
		tmp = cal(cnt-1);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					result[i][j] += tmp[i][k] * arr[k][j];
				}
				result[i][j] %= 1000;
			}
		}
	}else{
		tmp = cal(cnt/2);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					result[i][j] += tmp[i][k] * tmp[k][j];
				}
				result[i][j] %= 1000;
			}
		}
	}
	
	return result;
}

int main(){
	cin >> n >> b;
	
	vector<vector<int>> result(n, vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	
	result = cal(b);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
