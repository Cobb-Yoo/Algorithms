#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair <int, int>> arr;
int min=100000000;

void cal(int cnt){
		
}

int main(){	
	cin >> n;
	
	for(int i=0;i<n;i++){
		int tmpA, tmpB;
		cin >> tmpA >> tmpB >> endl;
		
		arr.push_back(tmpA, tmpB);
	}
	
	sort(arr.begin(),arr.end());
	
	cal(arr.size());
	
	cout << min << endl;
}
