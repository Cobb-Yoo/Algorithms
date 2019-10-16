#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char nameA[MAX][100];
int nameCount=0;
int graph[MAX][MAX] = { 0 };
int paperCount=0;

void initE(int n) {//그래프 초기화
	for (int i = 1; i < MAX; i++) {//에르데시 수 초기화 
		graph[i][0] = 2000;
	}
	graph[0][0] = 0;

	strcpy(nameA[0], "E, e");
}

void insert(char *name) { //중복 단어 있는지 확인 및 연관관계 확인 및 추가
	int i;
	
	printf("inserting name is ::: %s\n",name);

	for (i = 0; i <= nameCount; i++) { //중복 단어 확인
		if (!strcmp(nameA[i], name)) {
			graph[i][paperCount] = 1;//
			return;
		}
	}

	graph[++nameCount][paperCount] = 1;// 그래프 연결
	strcpy(nameA[nameCount], name); //단어 추가
}

void check() { // 저장된 데이터들로 부터 모든 에르되시 수를 연산.
	int CalArray[100] = { 0 };
	int CalNum;
	int min;

	for (int i = 0; i < paperCount; i++) {
		CalNum=0;
		for (int j = 1; j <= nameCount; j++) {//같은 논문이 들어간 친구들만 묶는다. 
			if (graph[i][j] == 1) {
				CalArray[CalNum++] = graph[i][0];
			}
		}
		
		min = 2000;
		printf("CalNum is :");
		for (int j = 0; j < CalNum; j++) { // 에르되시 수 중에 가장작은 수를 찾는다. 
			printf("%d ", CalArray[j]);	
			
			if (min >= CalArray[j]){
				min = CalArray[j];
			}
		}
		printf("\n");
		
		printf("THE MIN IS : %d\n",min);

		for (int j = 1; j <= nameCount; j++) {// 같은 논문에 들어간 친구들을 찾아서 에르되시 수를  가장 낮은 친구보다 하나 올려서 저장한다. 
			if (graph[i][j] == 1) {
				if (graph[j][0] != min) {
					graph[j][0] = min + 1;
				}
			}
		}
	}
}

main() {
	int m;
	char tmp[10] = {0};
	char line[100];
	int l;
	int nn=0;

	scanf("%d", &m);
	initE(m); //에르데시 수를 초기화
	gets(line);

	for (int i = 0; i < m; i++) {
		paperCount++;

		gets(line);
	
		l = 0;
		nn=0;

		for (int j = 0; j < strlen(line); j++) {
			if (line[j] == ':') {
				insert(tmp);
				for (int k = 0; k < 10; k++) tmp[k] = '\0';
				break;
			}

			if (line[j] == ',') { // <<<<<<<<<<<<<<<<< 여기만 수정하면 됨. 
				l++;
				if (l == 2) {
					insert(tmp);
					for (int k = 0; k < 10; k++) tmp[k] = '\0';
					nn = 0;
				}
				else {
					tmp[nn++] = line[j];
					continue;
				}
			}
			else {
				tmp[nn++] = line[j];
			}
		}
	}

	check();

	for (int i = 0; i <= nameCount; i++) {
		printf("%s : ", nameA[i]);
		printf("%d\n", graph[i][0]);
	}
	
	printf("++++++++++\n");
	
	for(int k=0;k<7;k++){
		for(int z=0;z<7;z++){
			printf("%d\t",graph[k][z]);
		}
		printf("\n");
	}
	printf("++++++++++\n");
}
