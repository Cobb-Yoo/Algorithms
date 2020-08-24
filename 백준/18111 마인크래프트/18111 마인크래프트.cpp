#include <iostream>
using namespace std;

int main(){
	int n,m,b;
	cin >> n >> m >> b;
	
	int map[n][m];
	int Max=0, Min=987654321;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			
			Max = max(Max, map[i][j]);
			Min = min(Min, map[i][j]);
		}
	}
	
	int time=987654321;
	int h=0;
	
	for(int k=Min;k<=Max;k++){
		int cnt_p=0;
		int cnt_m=0;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int tmp = k - map[i][j];
				
				if(tmp < 0) cnt_m += tmp*-1;
				else cnt_p += tmp;
			}
		}
		
		if(cnt_p <= cnt_m + b){
			int tmp = cnt_p + cnt_m*2;
			
			if(time > tmp){
				time = tmp;
				h = k;
			}
			else if(time == tmp) h = k;
		}
	}
	
	cout << time << " " << h << endl;
}
