#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 16;
const int INF = 987654321;

int n;
int data[MAX][MAX];
int check[MAX][1<<MAX];

int tsp(int here, int visited){
	if(visited == (1<<n)-1){
		if(data[here][0] != 0) return data[here][0];
		return INF;
	}
	
	int &result = check[here][visited];
	if(result != -1) return result;
	result = INF;
	
	for(int i=0;i<n;i++){
		if (visited & (1 << i) || data[here][i]==0) continue;
		int candidate = data[here][i] + tsp(i,visited+(1<<i));
		result = min(result, candidate);
	}
	return result;
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> data[i][j];
		}
	}
	
	memset(check,-1,sizeof(check));
	cout << tsp(0,1) << endl;
}
