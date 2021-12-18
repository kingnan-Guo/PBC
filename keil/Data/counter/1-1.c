//#include "stdio.h"
#include "reg51.h"
//int TMOD, TH0, TL0, ET0, EA, TR0;
int count;
int num;
int segArr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void initCounter(){
    //printf("%d \n", 0x01);
    
    TMOD = 0x06; // 0000 0110   8λ �Զ����ö�ʱ������
    TH0 = (256 - 5); // ����Ϊ 3  
    TL0 = (256 - 5);
    ET0 = 1; //��ʱ��0 �������ж�
    EA = 1; // �������ж�
    TR0 = 1; //������ʱ�� 0

}

void seg() {
    P2 = segArr[count];
		if(count == 10) {
			count =0;
		}
}


int main() {
    initCounter();
    while (1){
			seg();
		}
    return 0;
}

// �ⲿ�ж�0: 0 ; ��ʱ���ж�1: 1; �ⲿ�ж�1: 2; ��ʱ����1:3; �����ж�: 4;
void countIser() interrupt 1{
    count++;
}

