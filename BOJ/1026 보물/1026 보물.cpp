#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> brr;

bool cmpa(int a, int b){
	return a < b;
}
bool cmpb(int a, int b){
	return a > b;
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		brr.push_back(tmp);
	}
	
	sort(arr.begin(),arr.end(), cmpa);
	sort(brr.begin(),brr.end(), cmpb);
	
	int answer = 0;
	for(int i=0;i<n;i++) answer += (arr[i] * brr[i]);
	
	cout << answer << endl;
}
