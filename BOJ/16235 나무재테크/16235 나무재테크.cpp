#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k;
int A[10][10]; // �߰��� ��� 
vector<int> trees_map[10][10]; // ������ 
int map[10][10]; // ��л��� 
int option[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
int answer = 0;

// ���� ���� ���� ������ �;������� �� �ִ�. 
// �� �ڽ��� ���̸�ŭ ����� �Դ´�. ����� � �������� �Դ´�. ����� �����ߴ� ������ �״´�. 
// ���� : ���� ������ ���̸� 2�� ���� ���� ������� ���Ѵ�. 
// ���� : ������ ���̰� 5�� ����� �Ǹ� ������ 8���⿡ ���̰� 1�� ������ �����Ѵ�. 
// �ܿ� : ����� �߰��Ѵ�. 

void a_few_years_later(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(trees_map[i][j].size()){
				vector<int> tmp;
				int dead=0;
				
				sort(trees_map[i][j].begin(), trees_map[i][j].end());
				
				int len = trees_map[i][j].size();
				for(int k=0;k<len;k++){
					if(map[i][j] >= trees_map[i][j][k]){
						map[i][j] -= trees_map[i][j][k];
						tmp.push_back(trees_map[i][j][k]+1);
					}
					else dead += trees_map[i][j][k]/2;
				}
				
				trees_map[i][j].clear();
				for(int l=0;l<tmp.size();l++) trees_map[i][j].push_back(tmp[l]);
					
				map[i][j] += dead;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(trees_map[i][j].size()){
				int len = trees_map[i][j].size();
				
				for(int k=0;k<len;k++){
					if(trees_map[i][j][k]%5 == 0) {
						for(int t=0;t<8;t++){
							int y = i + option[t][0];
							int x = j + option[t][1];
							
							if(0<=y&&y<n && 0<=x&&x<n) trees_map[y][x].push_back(1);
						}
					}
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			map[i][j] += A[i][j];
		}
	}
}

void checkTree(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			answer += trees_map[i][j].size();
		}
	}
}
 
int main(){	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> A[i][j];
			map[i][j]=5;
		}
	}
	
	for(int i=0;i<m;i++){
		int y,x,z;
		cin >> y >> x >> z;
		
		trees_map[y-1][x-1].push_back(z);
	}
	
	while(k--) a_few_years_later();
	
	checkTree();
	
	cout << answer << endl;
}
