#include <iostream>
using namespace std;

int n, m;
int dock[100001];

int find(int num){
	if(num == dock[num]) return num;
	return dock[num] = find(dock[num]);
}

void unioon(int a, int b){
	dock[a] = find(b);
}

int main(){
	int ans=0;
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) dock[i] = i;
	
	for(int tmp,i=0;i<m;i++){
		cin >> tmp;
		
		tmp = find(tmp);
		
		if(tmp) {
			unioon(tmp, tmp-1);
			ans++;
		}
		else break;
	}
	
	cout << ans;
}
