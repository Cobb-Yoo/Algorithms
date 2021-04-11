#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 101;

int n,m,k;
string word;
bool noWord;
int cache[MAX][MAX];

int possibleNumOfWord(int A, int Z){
	if(A == 0 || Z == 0) return 1;
	
	int& result = cache[A][Z];
	if(result != -1) return result;
	
	result = min(possibleNumOfWord(A-1, Z)+possibleNumOfWord(A,Z-1), 1000000001);
	return result;
}

void getWord(int A, int Z, int skip){
	if(A == 0) {
		for(int i=0;i<Z;i++) word+='z';
		return;
	}
	
	if(Z == 0){
		for(int i=0;i<A;i++) word+='a';
		return;
	}
	
	int idx = possibleNumOfWord(A-1,Z);
	
	if(skip < idx){
		word += 'a';
		getWord(A-1,Z,skip);
	}
	else if(skip <= 1000000000){
		word += 'z';
		getWord(A,Z-1,skip-idx);
	}
	else noWord = 1;
}

int main(){
	cin >> n >> m >> k;
	
	noWord = 0;
	memset(cache,-1,sizeof(cache));
	
	if(k > possibleNumOfWord(n,m)) noWord = 1;
	else getWord(n,m,k-1);
	
	if(noWord) cout << -1;
	else cout << word;
}
