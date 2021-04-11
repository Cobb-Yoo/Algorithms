#include <bits/stdc++.h>
using namespace std;

int main(){
	string str; cin >> str;
	
	double score = 0;
	
	if(str[0] == 'A') score += 4.0;
	else if(str[0] == 'B') score += 3.0;
	else if(str[0] == 'C') score += 2.0;
	else if(str[0] == 'D') score += 1.0;
	else{
		score += 0.0;
		printf("%.1f\n",score);
		return 0;
	}
	
	if(str[1] == '+') score += 0.3;
	else if(str[1] == '-') score -= 0.3;
	
	printf("%.1f\n", score);
}
