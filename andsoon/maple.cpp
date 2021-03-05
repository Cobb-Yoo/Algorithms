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
	
	printf("������ ������ %ld������ �� ������ ���ϴ� ���α׷��Դϴ�.\n",MAX);
	cout << "��� ���� ��ť�길 ����߽��ϴ�.\n";
	cout << "����� ���������� ���� �����Ű���? ���� �Է����ּ��� : ";
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
			cout << now << "% ��ŭ ����Ǿ����ϴ�.\n";
		}
	}
	system("cls");
	
	sort(legendCompleteCount.begin(), legendCompleteCount.end(), cmp);
	
	double result = 0;
	for(int i=0;i<MAX;i++){
		result += legendCompleteCount[i];
	}
	
	printf("%ld�� �������� ����� ���������� �ø��� ���ؼ���\n",MAX);
	cout << result/MAX << "�� ���� �ɸ��ϴ�.\n";
	cout << "���� ���� �Ҹ��� ������ ";
	printf("%ld�� �Դϴ�.\n", legendCompleteCount[0]);
	
	cout << "���� ���� �Ҹ��� ������ ";
	printf("%ld�� �Դϴ�.\n", legendCompleteCount[MAX-1]);
}
