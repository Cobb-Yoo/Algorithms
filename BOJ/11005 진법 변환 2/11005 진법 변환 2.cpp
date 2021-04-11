#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char option[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main(){
	int n, m;
	string answer = "";
	
	cin >> n >> m;
	
	while(n != 0){
		answer += option[n%m];
		n /= m;
	}
	
	reverse(answer.begin(),answer.end());
	
	cout << answer << endl;
}
