#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> height(n);
	for(int i=0;i<n;i++) cin >> height[i];
	
	height.push_back(0);
	stack<int> remaining;
	
	int result = 0;
	for(int i=0;i<height.size();i++){
		while(!remaining.empty() && height[remaining.top()] >= height[i]){
			int idx = remaining.top();
			remaining.pop();
			
			int width;
			if(remaining.empty()) width = i;
			else width = (i-remaining.top() - 1);
			
			result = max(result, height[idx]*width);
		}
		remaining.push(i);
	}
	
	cout << result << endl;
}
