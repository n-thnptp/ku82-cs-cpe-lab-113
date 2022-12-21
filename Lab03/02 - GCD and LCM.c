// ให้เขียนโปรแกรมเพื่อรับค่าจำนวนเต็มบวก 2 จำนวน M, N จากผู้ใช้ บรรทัดละจำนวน
// จากนั้นแสดงจำนวนเต็มบวกที่มากที่สุดที่หาร M และ N ลงตัว (ห.ร.ม. - GCD) และจำนวนเต็มบวกที่น้อยที่สุดที่ M และ N หารลงตัว (ค.ร.น. - LCM)
// input < 1,000,000,000 | LCM < 4,000,000,000

// Hint:
// ใช้ atoll() ในการเปลี่ยน input เป็น long long
// GCD จะไม่เกินจำนวนเต็มบวก M หรือ N แต่ LCM จะไม่ต่ำกว่าจำนวนเต็มบวก M หรือ N ดังนั้น ไม่ควรให้โปรแกรมหา LCM ก่อน
// วิธีหา GCD ที่มีประสิทธิภาพ คือ Euclidean algorithm
// จาก Hint แรก ควรหา LCM จากความสัมพันธ์ M * N = GCD * LCM

// 1585           | 138583
// 3261           | 262211
// GCD: 1         | GCD: 997
// LCM: 5168685   | LCM: 36447329

#include <stdio.h>
#include <stdlib.h>

int main() {
    char M_str[12], N_str[12];
    int M, N, i, MN_swap, result;
    long long int M_res, N_res;
    double GCD, LCM;
    
    fgets(M_str, 12, stdin);
    fgets(N_str, 12, stdin);

    M = atoll(M_str);
    N = atoll(N_str);
    M_res = M;
    N_res = N;

    for (i = 0 ;; ++i) {
        if (N > M) {
            MN_swap = M;
            M = N;
            N = MN_swap;
        }
        result = M % N;
        // printf("M[%d] N[%d] = %d\n", M, N, result); // # GCD equation
        if (result == 0) {
            GCD = N;
            break;
        } else {
            M = N;
            N = result;
        }
    }
    // LCM = 284079715 * 624975373 / 56815943;
    LCM = M_res * N_res / GCD;
    printf("GCD: %.0f\n", GCD);
    printf("LCM: %.0f", LCM);
}