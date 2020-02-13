#include <iostream>

#include <deque>

using namespace std;

 

const int MAX = 1000;

 

typedef struct

{

        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

 

int N, M;

int tomato[MAX][MAX];

deque<pair<int, int>> dq;

int noTomato;

 

//�丶�䰡 ���� �;����� Ȯ��

bool allRipe(void)

{

        int possible = M * N - noTomato;

        int tomatoCnt = 0;

 

        for (int i = 0; i < M; i++)

                 for (int j = 0; j < N; j++)

                         if (tomato[i][j] == 1)

                                 tomatoCnt++;

 

        return possible == tomatoCnt;

}

 

int BFS(void)

{

        int day = 0;

 

        //ó������ ���� �� �ִ� �丶�䰡 ���� ���

        if (dq.empty())

                 return -1;

 

        while (!dq.empty())

        {

                 int currentSize = dq.size();

 

                 for (int i = 0; i < currentSize; i++)

                 {

                         int y = dq.front().first;

                         int x = dq.front().second;

 

                         for (int i = 0; i < 4; i++)

                         {

                                 int nextY = y + moveDir[i].y;

                                 int nextX = x + moveDir[i].x;

 

                                 //���� �丶�䰡 ���� �ȿ� �ְ� �� �;��� ��쿡��

                                 if (0 <= nextY && nextY < M && 0 <= nextX && nextX < N && tomato[nextY][nextX] == 0)

                                 {

                                          tomato[nextY][nextX] = 1;

                                          dq.push_back(make_pair(nextY, nextX));

                                 }

                         }

 

                         dq.pop_front();

 

                         //���� �� �ִ� �丶�並 ���� ������ ���� �;��� ���

                         if (dq.size() == 0 && allRipe())

                                 return day;

                         //���� �� �ִ� �丶��� ���� �������� �� ���� �丶�� ����

                         else if (dq.size() == 0 && !allRipe())

                                 return -1;

                 }

                 day++;

        }

}

 

int main(void)

{

        cin >> N >> M;

 

        for (int i = 0; i < M; i++)

                 for (int j = 0; j < N; j++)

                 {

                         cin >> tomato[i][j];

 

                         if (tomato[i][j] == 1)

                                 dq.push_back(make_pair(i, j)); //���� �丶��� ���� �ִ´�

                         else if (tomato[i][j] == -1)

                                 noTomato++; //�丶�並 ���� �� ���� ĭ

                 }

 

        if (dq.size() == M * N - noTomato)

        {

                 cout << 0 << endl; //��� �丶�� �� �;��� ���

        }

        else

        {

                 int result = BFS();

                 cout << result << endl;

        }

 

        return 0;

}
