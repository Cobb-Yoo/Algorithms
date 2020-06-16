#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;	
	
	int buyPackageNum=6;
	int minPackage = 1000;
	int minSingle = 1000;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		minPackage = min(minPackage, a);
		minSingle = min(minSingle, b);
	}
	
	buyPackageNum = min(buyPackageNum, minPackage/minSingle);
	
	if(n <= 6) cout << min(minPackage, minSingle*n) << endl;
	else {
		int answer = 987654321;
		
		for(int i=0;i<=n/6+1;i++) answer = min(answer, minPackage*i+minSingle*max(n-6*i,0));
		cout << answer << endl;	
	}
	
}
