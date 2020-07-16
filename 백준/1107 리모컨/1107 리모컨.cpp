#include <iostream>
#include <cstring>
#include <string>
#define MIN(a,b) (a<b?a:b)
using namespace std;

int n,m;
bool breaknum[10];
int answer = 0x3f3f3f3f; //infinity 

void check(string s){
	for(int i=0;i<10;i++){
		if(!breaknum[i]){
			string tmp = s + to_string(i);
			
			answer = MIN(answer, abs(n - stoi(tmp)) + tmp.length());
			
			if(tmp.size() < 6) check(tmp);
		}
	}
}

int main(){
	memset(breaknum,0,sizeof(breaknum));
	
	cin >> n >> m;
	
	answer = MIN(answer, abs(100 - n));
	
	for(int i=0;i<m;i++){
		int tmp;
		cin >> tmp;
		
		breaknum[tmp] = 1;
	}
	
	if(m < 10) check("");
	
	cout << answer << endl;
}
