// ù��° ���� ��� : ���������� ��
using namespace std;


long long solution(int price, int money, int count)
{    
    long long a = price, b = money, c = count;
    // long long result = count * (price + price*count)/2-money;    �ȵ�
    //long long result = count * price * (1+count)/2-money;         �ȵʤ� 
    long long result = c * a * (1+c)/2-b;
    
    if(result > 0) return result;
    return 0;
}

// ����ȯ�� �� ������ �ؾ��Ѵ�.  
