#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 100+1;
string s1,s2,s3;
int arr[MAX][MAX][MAX];

void solve(){
	int len1 = s1.size(); //i
	int len2 = s2.size(); //j
	int len3 = s3.size(); //k
	
	for(int k=1;k<=len3;k++){
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) arr[k][i][j] = arr[k-1][i-1][j-1]+1;
				else arr[k][i][j] = max({arr[k-1][i][j],arr[k][i-1][j],arr[k][i][j-1]});
			}
		}
	}
}

int main(){
	cin >> s1 >> s2 >> s3;
	
	solve();
	
	cout << arr[s3.size()][s1.size()][s2.size()] << endl;
}
