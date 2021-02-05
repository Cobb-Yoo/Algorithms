#include <iostream>
#include <vector>
using namespace std;

int n,cnt;
char option[] = {'+','-','.',' '};
int a[16];
char b[16];
int c[16];
char d[16];

void solve(int num){
	if(num == n){
		int idx=0;
		int tmp=1;
		int sum=0;
		
		for(int i=2;i<=num;i++){
			if(b[i-1]==option[2]){
				if(i<10) tmp = tmp*10 + i;
				else tmp = tmp*100 + i;
				
				if(i==n){
					c[idx] = tmp;
					break;
				}
			}
			else{
				c[idx] = i;
				d[idx++] = b[i-1];
				tmp++;
			}
		}
		
		sum = c[0];
		for(int i=0;i<idx;i++){
			if(d[i]==option[0]) sum+=c[i+1];
			else sum-=c[i+1];
		}
		
		if(sum == 0){
			cnt++;
			if(cnt>20) return;
			
			cout << 1 << " ";
			for(int i=1;i<n;i++){
				cout << b[i] << " " << i+1 << " ";
			}
			cout << endl;
		}
		return;
	}
	
	for(int i=0;i<3;i++){
		b[num] = option[i];
		solve(num+1);
	}
}

int main(){
	cin >> n;
	
	solve(1);
	
	cout << cnt;
}
