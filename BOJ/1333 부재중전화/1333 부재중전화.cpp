#include <iostream>
using namespace std;

int main(){
	int n,l,d;
	cin >> n >> l >> d;
	
	int time=0;
	int cnt=1;
	
	while(1){
		if((l+5)*cnt-5 <= d*time && d*time < (l+5)*cnt){
			cout << d*time << endl;
			break;
		}
		else if((l+5)*cnt > d*time){
			time++;
		}
		else{
			if(n > cnt) cnt++;
			else{
				cout << d*time << endl;
				break;
			}
		}
	}
}
