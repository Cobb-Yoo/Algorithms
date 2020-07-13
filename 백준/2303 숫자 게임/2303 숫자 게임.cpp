#include <iostream>
using namespace std;

int tmp[5];

pair<int,int> check(){
	int resultA = 0;
	int resultB = 0;
	
	for(int i=0;i<3;i++){
		for(int j=i+1;j<4;j++){
			for(int k=j+1;k<5;k++){
				if(resultA < (tmp[i]+tmp[j]+tmp[k])%10){
					resultA = (tmp[i]+tmp[j]+tmp[k])%10;
					resultB = tmp[i]+tmp[j]+tmp[k];
				}
			}
		}
	}
	
	return {resultA , resultB};
}

int main(){
	int n;
	cin >> n;
	
	pair<int,int> arr[n];
	pair<int,int> answer;
	int idx;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++) cin >> tmp[i];
		
		arr[i] = check();
		
		if(answer.first < arr[i].first){
			idx = i+1;
			answer = arr[i];
		}
		else if(answer.first == arr[i].first){
			if(answer.second < arr[i].second){
				idx = i+1;
			}
		}
	}
	
	cout << idx << endl;
}
