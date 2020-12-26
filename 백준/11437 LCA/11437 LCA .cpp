#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

const int MAX = 50000+1;
int n;
vector<int> v[MAX];
int tree[17][MAX];
int depth[MAX];

void make_tree(){
	queue<int> q;
	q.push(1);
	tree[0][1] = 1;
	depth[1] = 1;
	
	while(!q.empty()){
		int parent = q.front();
		q.pop();
		
		int len = v[parent].size();
		for(int i=0;i<len;i++){
			int child = v[parent][i];
			
			if(depth[child] == 0){
				tree[0][child] = parent;
				depth[child] = depth[parent] + 1;
				q.push(child);
			}
		}
	}
}

void find_parent(){
	for(int i=1;i<17;i++){
		for(int j=1;j<=n;j++){
			tree[i][j] = tree[i-1][tree[i-1][j]];
		}
	}
}

int find(int child, int parent){
	int dif = depth[child] - depth[parent];
	for(int i = 16;i >= 0;i--){
		int tmp = pow(2,i);
		if(tmp <= dif){
			child = tree[i][child];
			dif -= tmp;
		}
	}
	if(parent == child) return child;
	
	int t = depth[child]-1;
	
	while(t>0){
		if(tree[0][parent] == tree[0][child]) break;
		
		parent = tree[0][parent];
		child = tree[0][child];
		t--;
	}
	
	return tree[0][child];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	int a,b;
	for(int i=0;i<n-1;i++){
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	make_tree();
	find_parent();
	
	int t;
	cin >> t;
	int result;
	for(int i=0;i<t;i++){
		cin >> a >> b;
		
		result = depth[a] > depth[b] ? find(a,b) : find(b,a);
		
		cout << result << "\n";
	}
}
