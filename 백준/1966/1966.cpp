#include <iostream>
#include <queue>
using namespace std;

int main(){	
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		int count=0;
		
		int a,b;
		cin >> a >> b;
		int tmp;
		
		priority_queue<int> arr;
		queue<pair<int,int>> q;
		
		for(int j=0;j<a;j++){
			cin >> tmp;
			arr.push(tmp);
			q.push({j,tmp});
		}
		
		while(!arr.empty()){	
			if(arr.top()==q.front().second){
				count++;
				if(q.front().first == b){
					cout << count << endl;
					break;
				}
				else{
					arr.pop();
					q.pop();
				}
			}
			else{
				q.push({q.front().first, q.front().second});
				q.pop();
			}
		}
	}
}
