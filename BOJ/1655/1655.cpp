#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		
		if(max.empty()){
			max.push(num);
		}
		else{
			if(max.size() > min.size()){
				min.push(num);
			}
			else{
				max.push(num);
			}
				
			if(max.top() > min.top()){
				int tmp_max = max.top();
				int tmp_min = min.top();
				max.pop();
				min.pop();
			
				max.push(tmp_min);
				min.push(tmp_max);
			}
		}
		
		cout << max.top() << "\n";
		
	}
}
