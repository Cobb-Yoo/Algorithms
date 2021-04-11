#include <iostream>
#include <cstring>
using namespace std;

char arr[50][50];
bool ver[50];
bool col[50];
int n,m;

void init(){
	cin >> n >> m;
    
	memset(ver,0,sizeof(ver));
	memset(col,0,sizeof(col));
    
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
			
			if(arr[i][j] == 'X'){
				ver[i] = 1;
				col[j] = 1;
			}
		}
	}
}

int main(){
	init();
	
	int v=0,c=0;
	
	for(int i=0;i<n;i++) if(!ver[i]) v++;
	for(int i=0;i<m;i++) if(!col[i]) c++;
	
	cout << max(v,c) << endl;
}
