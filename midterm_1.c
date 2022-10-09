#include <stdio.h>

 /*
 1번
 A와 B가 마라톤 시합을 한다.
 이때, 누가 얼마나 더 빠른지를 구하고,
 기록의 차이를 시, 분, 초로 변환하는 프로그램을 작성하시오.

 Input
 A와 B의 마라톤 기록(r)이 초 단위로 공백으로 구분되어 입력된다.
 먼저 입력된 기록이 A의 기록, 나중에 입력된 기록이 B의 기록이다.
 1 ≤ r ≤ 86400

 Output
 빠른 사람, 시, 분, 초를 공백으로 구분하여 출력한다.
 시, 분, 초가 0인 경우 0을 출력한다.
 기록이 같은 경우 -1을 출력한다.
 */

int main() {
    int r_a, r_b;
    scanf("%d %d", &r_a, &r_b);
    
    if(r_a != r_b) {
        char who_wins = (r_a < r_b) ? 'A' : 'B';
        int record = r_a - r_b;
        if(record < 0) {
            record *= -1;
        }
        
        int hour = record / 3600;
        int min = (record%3600) / 60;
        int sec = record - (hour*3600 + min*60);

        printf("%c %d %d %d", who_wins, hour, min, sec);
    } else {
        printf("-1");
    }
    
    return 0;
}
