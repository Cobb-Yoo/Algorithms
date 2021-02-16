#include <bits/stdc++.h>
using namespace std;

const int DAY = 14;
int jun, js_m;
int sung, ss_m;
int arr[DAY+1];
int flag;

void JUN(int n){
	if(js_m >= n){
		jun+= js_m/n;
		js_m %= n;
	}
}

void SUNG(int n, int cost){
	if(n < 0){
		if(flag > 0) flag = -1;
		else flag--;
		
		if(flag == -3){
			sung += ss_m/cost;
			ss_m %= cost;
		}
	}
	else if(n > 0){
		if(flag < 0) flag = 1;
		else flag++;
		
		if(flag == 3 && sung > 0){
			ss_m = cost*sung;
			sung = 0;
		}
	}
	else flag = 0;
}

void PRINT(int n){
	cout << "========" << n << "========= " << flag << endl;
	cout << "jun`s cnt : " << jun << endl;
	cout << "jun`s money : " << js_m << endl;
	cout << "sung`s cnt : " << sung << endl;
	cout << "sung`s money : " << ss_m << endl;
}

int main(){
	int n; cin >> n;
	js_m = ss_m = n;
	
	for(int i=0;i<DAY;i++) cin >> arr[i];
	
	
	JUN(arr[0]);
	for(int i=1;i<DAY;i++){
		JUN(arr[i]);
		SUNG(arr[i]-arr[i-1], arr[i]);
		
		//PRINT(i);
	}
	
	js_m = js_m + jun*arr[DAY-1];
	ss_m = ss_m + sung*arr[DAY-1];
	
	if(js_m < ss_m) cout << "TIMING";
	else if(js_m > ss_m)cout << "BNP";
	else cout << "SAMESAME\n";
}
