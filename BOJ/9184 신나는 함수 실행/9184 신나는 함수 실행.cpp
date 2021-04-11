#include <iostream>
using namespace std;

const int MAX = 21;
int arr[MAX][MAX][MAX];

int w(int a, int b, int c){
	if(a <=0 || b <= 0 || c <= 0){
		return 1;
	}
	else if(a >= MAX || b >= MAX || c >= MAX){
		return w(20,20,20);
	}
	
	if(arr[a][b][c] != 0) return arr[a][b][c];
	
	if(a < b && b < c){
		return arr[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	else {
		return arr[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	}
}

int main(){
	int a,b,c;
	
	while(cin >> a >> b >> c){
		if(a == -1 && b == -1 && c == -1) break;
		
		printf("w(%d, %d, %d) = ", a,b,c);
		cout << w(a,b,c) << "\n";
	}
}
