
#include "reg51.h"
sbit ex = P3^2;
// int IT0, EX0, EA;
int segArr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int num;
// �ⲿ�ж�
void initex() {
    IT0 = 1;  // �ⲿ�жϵĳ�����ʽ1 ���س��� , ��λinit0 ��int1 ���ǵ͵�ƽ��Ч�����Գ�����ʽ1 �������˼���� �½��ش���
    EX0 = 1;  // �ⲿ�ж� INT0 ���ж� EX1 ΪINT0���ж�
    EA = 1;   // �ܿ��ж�
		ex  1;
}

void seg() {
    P2 = segArr[num];
    if(num==10) {
        num = 0;
    }
}

int main()
{
    initex();
    while(1){
			seg();
    }
    return 0;
}
 
// ��ʱ�� 0 ���ж�
void exIsr() interrupt 0 {
    // ÿ�ν����ж���  num++
    num++;
}
