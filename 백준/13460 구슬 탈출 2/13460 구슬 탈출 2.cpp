#include <iostream>
using namespace std;

int n,m;
char map[10][10];
pair<int,int> red;
pair<int,int> blue;
pair<int,int> hole;


int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			
			if(map[i][j] == 'R') red = {i,j};
			else if(map[i][j] == 'B') blue = {i,j};
			else if(map[i][j] == 'O') hole = {i,j};
		}
	}
	
	//4���� �����ӿ� ���� red�� blue�� ��ǥ���� Ȯ���ؼ� �������� �켱������ �Ǵ��Ѵ�.
	//�켱������ ������ ���� ������ �����δ�.
	//�� ���� �켱������ ���� �����δ�.
	//queue�� ������ ���� ���� �����Ͽ� bfs�� �غ��Ѵ�. 
}
