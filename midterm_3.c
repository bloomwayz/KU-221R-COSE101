#include <stdio.h>

 /*
 일직선 상에서 앞으로 한칸 또는 뒤로 한칸씩 이동하는 장난감 자동차가 있다.
 장난감 자동차는 한 번 전원을 켤 때마다 앞 또는 뒤로 랜덤하게 8칸을 이동한다.
 8칸을 이동하고, 앞 또는 뒤로만 이동한다는 점을 고려하여
 전원을 켰을 때 동작을 unsigned char 자료형에 비트 단위로 기록하기로 했다.
 1은 앞으로 1칸 이동을 의미한다.
 0은 뒤로 1칸 이동을 의미한다.
 자동차의 시작 위치는 0이다.

 Input
 A, B, C, D 장난감 자동차의 동작이 비트단위로 기록된 값이 공백을 사이에 두고 순서대로 입력된다.
 0 ≤ 기록 ≤ 255

 Output
 가장 앞에 있는 장난감 자동차를 출력한다.
 만약 가장 앞에 있는 차가 여러대라면 공백 없이 A, B, C, D 순서대로 출력한다.
 /*
 
int main() {
    unsigned char A, B, C, D;
    scanf("%hhu %hhu %hhu %hhu", &A, &B, &C, &D);
    
    int A_bits[8] = {0, };
    int B_bits[8] = {0, };
    int C_bits[8] = {0, };
    int D_bits[8] = {0, };
    
    for(int i=0; i<8; i++) {
        A_bits[7-i] = A % 2;
        B_bits[7-i] = B % 2;
        C_bits[7-i] = C % 2;
        D_bits[7-i] = D % 2;
        
        A /= 2;
        B /= 2;
        C /= 2;
        D /= 2;
    }
    
    int count[4] = {0, };
    for(int i=0; i<8; i++) {
        if(A_bits[i] == 1) {
            count[0] += 1;
        } else if(A_bits[i] == 0) {
            count[0] -= 1;
        }
        
        if(B_bits[i] == 1) {
            count[1] += 1;
        } else if(B_bits[i] == 0) {
            count[1] -= 1;
        }
        
        if(C_bits[i] == 1) {
            count[2] += 1;
        } else if(C_bits[i] == 0) {
            count[2] -= 1;
        }
        
        if(D_bits[i] == 1) {
            count[3] += 1;
        } else if(D_bits[i] == 0) {
            count[3] -= 1;
        }
    }
    
    int count_max = -10;
    for(int i=0; i<4; i++) {
        if(count[i] > count_max) {
            count_max = count[i];
        }
    }
    
    for(int i=0; i<4; i++) {
        if(count[i] == count_max) {
            printf("%c", 'A'+i);
        }
    }
    
    return 0;
}
