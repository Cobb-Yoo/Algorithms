#include <iostream>
#include <deque>
using namespace std;

deque<int> d;
int n,m;

void init(){
	for(int i=1;i<=n;i++){
		d.push_back(i);
	}
}

int main(){
	
	cin >> n >> m;
	
	init();
	
	int cnt = 0;
	
	for(int i=0;i<m;i++){
		int num;
		int len = d.size();
		int idx;
		
		cin >> num;
		
		for(int i=0;i<len;i++){
			if(num == d[i])	{
				idx = i;
				break;
			}
		}
		
		if(idx < len-idx){
			for(;d.front() != num;){
				cnt++;
				d.push_back(d.front());
				d.pop_front();
			}
			d.pop_front();
		}
		else{
			for(;d.front() != num;){
				cnt++;
				d.push_front(d.back());
				d.pop_back();
			}
			d.pop_front();
		}
	}
	
	cout << cnt << endl;
}
