#include <iostream>
#include <vector>
using namespace std;

const int MAX = 26;

vector<pair<int,bool>> arr[MAX+1];

void preOrder(int node){
	cout << (char)(node+'A');
	for(int i=0;i<arr[node].size();i++){
		preOrder(arr[node][i].first);
	}
}

void inOrder(int node){
	if(arr[node].size() && arr[node][0].second){
		inOrder(arr[node][0].first);
	}
	
	cout << (char)(node + 'A');
	
	if(arr[node].size() && !arr[node][0].second){
		inOrder(arr[node][0].first);
	}
	else if(arr[node].size() == 2){
		inOrder(arr[node][1].first);
	}
}

void postOrder(int node){
	for(int i=0;i<arr[node].size();i++){
		postOrder(arr[node][i].first);
	}
	cout << (char)(node + 'A');
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		char a,b,c;
		cin >> a >> b >> c;
		
		if(b != '.'){
			arr[a-'A'].push_back({b -'A',true});
		}
		if(c != '.'){
			arr[a-'A'].push_back({c -'A',false});
		}
	}
	
	preOrder(0);
	cout << endl;
	inOrder(0);
	cout << endl;
	postOrder(0);
}
