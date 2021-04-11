#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<string> data;
string answer;
int n,m;

char get_char(int arr[]){
	int max = 0;
	int idx;
	for(int i=0;i<4;i++){
		if(max < arr[i]){
			max = arr[i];
			idx = i;
		}
	}
	
	if(idx == 0) return 'A';
	else if(idx == 1) return 'C';
	else if(idx == 2) return 'G';
	else return 'T';
}

int get_hammingDistance(){
	int len = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(answer[i] != data[j][i]) len++;
		}
	}
	
	return len;
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		string tmp;
		cin >> tmp;
		
		data.push_back(tmp);
	}
	
	for(int i=0;i<m;i++){
		int arr[4] = {0,};
		
		for(int j=0;j<n;j++){
			if(data[j][i] == 'A') arr[0]++;
			else if(data[j][i] == 'C') arr[1]++;
			else if(data[j][i] == 'G') arr[2]++;
			else arr[3]++;
		}
		answer += get_char(arr);
	}
	
	int len = get_hammingDistance();
	
	cout << answer << endl;
	cout << len << endl;
}
