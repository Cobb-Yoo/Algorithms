#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 2000;

int cache[MAX][MAX];
int n;
int left_arr[MAX];
int right_arr[MAX];

int getScore(int left_card, int right_card){
	if(left_card >= n || right_card >= n) return 0;
	
	int& result = cache[left_card][right_card];
	if(result != -1) return result;
	
	result = 0;
	if(left_arr[left_card] > right_arr[right_card]) result += right_arr[right_card] + getScore(left_card, right_card+1);
	else result += max(getScore(left_card+1,right_card+1), getScore(left_card+1, right_card));
	
	return result;
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> left_arr[i];
	for(int i=0;i<n;i++) cin >> right_arr[i];
	
	memset(cache,-1,sizeof(cache));
	cout << getScore(0,0) << endl;
}
