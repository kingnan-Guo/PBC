//#include "stdio.h"
#include "reg51.h"
//int TMOD, TH0, TL0, ET0, EA, TR0;
int count;
int num;
int segArr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void initTime(){
    //printf("%d \n", 0x01);
    
    TMOD = 0x01; // 0000 0001 ��ʱ��0 16λ��ʱ��
    TH0 = (65536 - 50000)/256; // 20ms = 50000us;  256 = 2 ^ 8;  ��ֵ>> 8  
    TL0 = (65536 - 50000)%256;
    // printf("TH0: %d TH0: %d \n", TH0, TL0);
    ET0 = 1; //��ʱ��0 �������ж�
    EA = 1; // �������ж�
    TR0 = 1; //������ʱ�� 0

}

void seg() {
    P2 = segArr[num];
    if(num==10) {
        num = 0;
    }
}


int main() {
    initTime();
    while (1){
			seg();
		};
    return 0;
}

// �ⲿ�ж�0: 0 ; ��ʱ���ж�1: 1; �ⲿ�ж�1: 2; ��ʱ����1:3; �����ж�: 4;
void timeIser() interrupt 1{
    TH0 = (65536 - 50000)/256;  
    TL0 = (65536 - 50000)%256;
    count++;
		if(count == 20) {
			num++;
			count =0;
		}
			
}

