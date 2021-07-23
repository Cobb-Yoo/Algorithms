#include <bits/stdc++.h>
using namespace std;

bool arr[1001];
int user[1001];
int predic = 0;
int predicMax = 0;
int Max = 0;

int main(){
	int len, n;
	cin >> len >> n;
	
	for(int i=1;i<=n;i++){
		int p,k;
		cin >> p >> k;
		
		if(predicMax < k - p) {
			predicMax = k-p;
			predic = i;
		}
		
		for(int j=p;j<=k;j++){
			if(!arr[j]) {
				user[i]++;
				arr[j] = 1;
			}
		}
	}
	
	for(int i=1;i<=len;i++){
		if(user[Max] < user[i]) Max = i;
	}
	
	cout << predic << endl << Max << endl;
}
