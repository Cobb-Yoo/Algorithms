#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> w;
	vector<int> k;
	int tmp;
	
	for(int i=0;i<10;i++){
		cin >> tmp;
		w.push_back(tmp);
	}
	
	for(int i=0;i<10;i++){
		cin >> tmp;
		k.push_back(tmp);
	}
	
	sort(w.begin(), w.end());
	sort(k.begin(), k.end());
	
	int answer_w = w[9] + w[8] + w[7];
	int answer_k = k[9] + k[8] + k[7];
	
	cout << answer_w << " " << answer_k << endl;
}
