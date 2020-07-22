#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	
	bool visited[n+1];
	for(int i=0;i<=n;i++) visited[i] = 0;
	int cnt = 0;
	 
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if(!visited[j]){
				visited[j] = 1;
				k--;
			}
			
			if(!k){
				cout << j << endl;
				return 0;
			}
		}
	}
}
