#include <bits/stdc++.h>
#include <Windows.h>
#define RARE 0
#define EPIC 1
#define UNIQUE 2
#define LENGENDARY 3
using namespace std;

bool randomArr[1000];
double MAX;

int legend;
vector<int> legendCompleteCount;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void randomArrInit(int status, int &cnt){
	memset(randomArr,0,sizeof(randomArr));
	
	if(status == RARE) for(int i=0;i<150;i++) randomArr[i] = 1;
	else if(status == EPIC) for(int i=0;i<35;i++) randomArr[i] = 1;
	else for(int i=0;i<10;i++) randomArr[i] = 1;
	
	for(int i=0;i<1000;i++){
		int x = rand() % (1000-i)+i;
		swap(randomArr[i], randomArr[x]);
	}
	
	cnt++;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){	
	srand((unsigned)time(NULL));
	
	printf("레전드 도달을 %ld번했을 때 개수를 구하는 프로그램입니다.\n",MAX);
	cout << "모든 경우는 블랙큐브만 계산했습니다.\n";
	cout << "몇번의 레전더리를 보고 싶은신가요? 값을 입력해주세요 : ";
	cin >> MAX;
	
	int now = 0;
	
	for(double i=1;i<=MAX;i++){
		int status = 0;
		int cnt = 0;
		while(1) {
			randomArrInit(status, cnt);
			if(randomArr[rand()%1000]) status++;
			
			if(status == LENGENDARY) {
				legendCompleteCount.push_back(cnt);
				break;
			}
		}
		
		int pre = (int)((i/MAX)*100);
		
		if(pre != now){
			now = pre;
			system("cls");
			cout << now << "% 만큼 진행되었습니다.\n";
		}
	}
	system("cls");
	
	sort(legendCompleteCount.begin(), legendCompleteCount.end(), cmp);
	
	double result = 0;
	for(int i=0;i<MAX;i++){
		result += legendCompleteCount[i];
	}
	
	printf("%ld의 아이템을 레어에서 레전더리로 올리기 위해서는\n",MAX);
	cout << result/MAX << "개 정도 걸립니다.\n";
	cout << "가장 많이 소모한 갯수는 ";
	printf("%ld개 입니다.\n", legendCompleteCount[0]);
	
	cout << "가장 적게 소모한 갯수는 ";
	printf("%ld개 입니다.\n", legendCompleteCount[MAX-1]);
}
