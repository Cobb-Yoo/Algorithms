#include <iostream>
#include <vector>
using namespace std;

int n,deletNode;
pair<int, bool> parent[50];
vector<int> ancestor[50];

int countLeaf(){
	for(int i=0;i<n;i++){
		for(int j=0;j<ancestor[i].size();j++){
			if(ancestor[i][j] == deletNode){
				parent[i].second = 1;
				break;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(i!=deletNode){
			parent[parent[i].first].second = 1;
		}
	}
	
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(parent[i].second == 0) cnt++;
	}
	
	return cnt;
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> parent[i].first;
		
		parent[parent[i].first].second = 1;
	}
	
	for(int i=0;i<n;i++){
		int curParent = parent[i].first;
		while(curParent != -1){
			ancestor[i].push_back(curParent);
			curParent = parent[curParent].first;
		}
	}
	
	cin >> deletNode;
	parent[deletNode].second = 1;
	parent[parent[deletNode].first].second = 0;
	
	cout << countLeaf() << endl;
}
