#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int Max = 200;
int A,B,C;
vector<int> v;
bool cache[Max+1][Max+1][Max+1];

void solve(){
	queue<pair<pair<int,int>, int>> q;
	q.push({{0,0},C});
	
	while(!q.empty()){
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();
	
		if(cache[a][b][c]) continue;
		
		if(!a) v.push_back(c);
		cache[a][b][c] = 1;
		//a->b
		if(a+b > B) q.push({{a+b-B, B}, c});
		else q.push({{0, a+b}, c});
		
		//a->c
		if(a+c > C) q.push({{a+c-C, b}, C});
		else q.push({{0, b}, a+c});
		
		//b->a
		if(b+a > A) q.push({{A, b+a-A}, c});
		else q.push({{b+a, 0}, c});
		
		//b->c
		if(b+c > C) q.push({{a, b+c-C}, C});
		else q.push({{a, 0}, b+c});
		
		//c->a
		if(c+a > A) q.push({{A, b}, a+c-A});
		else q.push({{a+c, b}, 0});
		
		//c->b
		if(c+b > B) q.push({{a, B}, c+b-B});
		else q.push({{a, c+b}, 0});
	}
}

int main(){
	cin >> A >> B >> C;
	
	solve();
	
	sort(v.begin(), v.end());
	int len = v.size();
	for(int i=0;i<len;i++){
		cout << v[i] << " ";
	}
}
