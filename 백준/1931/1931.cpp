#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct confer{
	int begin;
	int end;
};

bool cmp(confer a, confer b){ // 정렬조건 : 회의가 끝나는 시간을 기준으로 오름차순으로 정렬함. 
	if(a.end == b.end){
		return a.begin < b.begin;
	}
	else{
		return a.end < b.end;
	}
}

int main(){
	int n;
	cin >> n;
	
	vector<confer> x(n);
	for(int i=0;i<n;i++){
		cin >> x[i].begin >> x[i].end;
	}
	
	sort(x.begin(),x.end(),cmp);
	
	int count=0;
	int end_point=0;
	
	for(int i=0;i<n;i++){
		if(end_point <= x[i].begin){
			count++;
			end_point = x[i].end;
		}
	}
	
	cout << count << endl;
}
