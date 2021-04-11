#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool visited[201];
int room[201];
vector<int> v[201];
int n,m;

bool solve(int idx){
	if(!visited[idx]){
		visited[idx] = 1;
		
		for(int i=0;i<v[idx].size();i++){
			if(!room[v[idx][i]] || solve(room[v[idx][i]])){
				room[v[idx][i]] = idx;
				return 1;
			}
		}
	}
	
	return 0;
}

int main(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		int len; cin >> len;
		
		for(int j=0;j<len;j++){
			int num; cin >> num;
			
			v[i].push_back(num);
		}
	}
	
	int answer = 0;
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited));
		
		if(solve(i)) answer+=1;
	}
	
	cout << answer << endl;
}
