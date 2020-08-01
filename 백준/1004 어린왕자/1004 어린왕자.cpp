#include <iostream>
using namespace std;

int start_x, start_y;
int end_x, end_y;
int n;

bool inRange(int a, int b, int r){
	if(r*r > (start_x-a)*(start_x-a)+(start_y-b)*(start_y-b)
		&& r*r > (end_x-a)*(end_x-a)+(end_y-b)*(end_y-b)) return 0;
	else if(r*r > (start_x-a)*(start_x-a)+(start_y-b)*(start_y-b)
		|| r*r > (end_x-a)*(end_x-a)+(end_y-b)*(end_y-b)) return 1;
		
	return 0; 
}

int main(){
	int t; cin >> t;
	
	while(t--){
		
		cin >> start_x >> start_y >> end_x >> end_y;
		cin >> n;
		
		int cnt = 0;
		for(int i=0;i<n;i++) {
			int a, b, r;
			cin >> a >> b >> r;
			
			if(inRange(a,b,r)) cnt++;
		}
		cout << cnt << endl;
	}
}
