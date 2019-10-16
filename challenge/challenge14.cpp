#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char nameA[MAX][100];
int nameCount=0;
int graph[MAX][MAX] = { 0 };
int paperCount=0;

void initE(int n) {//�׷��� �ʱ�ȭ
	for (int i = 1; i < MAX; i++) {//�������� �� �ʱ�ȭ 
		graph[i][0] = 2000;
	}
	graph[0][0] = 0;

	strcpy(nameA[0], "E, e");
}

void insert(char *name) { //�ߺ� �ܾ� �ִ��� Ȯ�� �� �������� Ȯ�� �� �߰�
	int i;
	
	printf("inserting name is ::: %s\n",name);

	for (i = 0; i <= nameCount; i++) { //�ߺ� �ܾ� Ȯ��
		if (!strcmp(nameA[i], name)) {
			graph[i][paperCount] = 1;//
			return;
		}
	}

	graph[++nameCount][paperCount] = 1;// �׷��� ����
	strcpy(nameA[nameCount], name); //�ܾ� �߰�
}

void check() { // ����� �����͵�� ���� ��� �����ǽ� ���� ����.
	int CalArray[100] = { 0 };
	int CalNum;
	int min;

	for (int i = 0; i < paperCount; i++) {
		CalNum=0;
		for (int j = 1; j <= nameCount; j++) {//���� ���� �� ģ���鸸 ���´�. 
			if (graph[i][j] == 1) {
				CalArray[CalNum++] = graph[i][0];
			}
		}
		
		min = 2000;
		printf("CalNum is :");
		for (int j = 0; j < CalNum; j++) { // �����ǽ� �� �߿� �������� ���� ã�´�. 
			printf("%d ", CalArray[j]);	
			
			if (min >= CalArray[j]){
				min = CalArray[j];
			}
		}
		printf("\n");
		
		printf("THE MIN IS : %d\n",min);

		for (int j = 1; j <= nameCount; j++) {// ���� ���� �� ģ������ ã�Ƽ� �����ǽ� ����  ���� ���� ģ������ �ϳ� �÷��� �����Ѵ�. 
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
	initE(m); //�������� ���� �ʱ�ȭ
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

			if (line[j] == ',') { // <<<<<<<<<<<<<<<<< ���⸸ �����ϸ� ��. 
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
