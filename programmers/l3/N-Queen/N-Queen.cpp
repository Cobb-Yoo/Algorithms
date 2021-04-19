#include <vector>
#include <cmath>

using namespace std;

int num;
int answer=0;
int arr[12];

bool check(int x){
	for(int i=0;i<x;i++){
		if(arr[i]==arr[x] || abs(arr[i]-arr[x]) == x-i) return 0;
	}
	return 1;
}

void nqueen(int cnt){
	if(cnt == num){
		answer++;
	}
	else{
		for(int i=0;i<num;i++){
			arr[cnt] = i;
			if(check(cnt)) nqueen(cnt+1);
		}
	}
}

int solution(int n) {
    num = n;
    nqueen(0);
    return answer;
}
