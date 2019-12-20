#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <klee/klee.h>
uint8_t flags[8] = {0};
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    if (Size < sizeof(uint32_t) * 16)
        return 0;
    uint32_t *num = (uint32_t *)Data;
    //num[0] = 0x00621a27; num[1] = 0x00c01752;
    if (num[0] > 0x003e9ef4 && num[0] < 0x00649689) {
        if (num[1] > 0x00b10797 && num[1] < 0x00f2deeb) {
            if ((num[0] * num[1]) == 0x00621a27 * 0x00c01752) {
                flags[0] = 0;
            }
        }
    }
    //num[2] = 0x013520fa; num[3] = 0x018d6191;
    if (num[2] > 0x0112bc98 && num[2] < 0x01c16abd) {
        if (num[3] > 0x01596565 && num[3] < 0x01be1786) {
            if ((num[2] * num[3]) == 0x013520fa * 0x018d6191) {
                flags[1] = 1;
            }
        }
    }
    //num[4] = 0x025c6ef7; num[5] = 0x02145f29;
    if (num[4] > 0x024bde68 && num[4] < 0x0266302e) {
        if (num[5] > 0x0201deb3 && num[5] < 0x026191e9) {
            if ((num[4] * num[5]) == 0x025c6ef7 * 0x02145f29) {
                flags[2] = 2;
            }
        }
    }
    //num[6] = 0x03dbe07c; num[7] = 0x03b938b2;
    if (num[6] > 0x034b1b4b && num[6] < 0x03f4b1bf) {
        if (num[7] > 0x03ade8ae && num[7] < 0x03dd23c1) {
            if ((num[6] * num[7]) == 0x03dbe07c * 0x03b938b2) {
                flags[3] = 3;
            }
        }
    }
    //num[8] = 0x04d64617; num[9] = 0x046fb871;
    if (num[8] > 0x041dd6d8 && num[8] < 0x04f0640f) {
        if (num[9] > 0x0468cd60 && num[9] < 0x04a8c833) {
            if ((num[8] * num[9]) == 0x04d64617 * 0x046fb871) {
                flags[4] = 4;
            }
        }
    }
    //num[10] = 0x058e0874; num[11] = 0x0582d4bd;
    if (num[10] > 0x050d5ebc && num[10] < 0x05914006) {
        if (num[11] > 0x0581050a && num[11] < 0x05be6653) {
            if ((num[10] * num[11]) == 0x058e0874 * 0x0582d4bd) {
                flags[5] = 5;
            }
        }
    }
    //num[12] = 0x0681b201; num[13] = 0x0629a9d9;
    if (num[12] > 0x067fd111 && num[12] < 0x0691d629) {
        if (num[13] > 0x06209857 && num[13] < 0x06d93676) {
            if ((num[12] * num[13]) == 0x0681b201 * 0x0629a9d9) {
                flags[6] = 6;
            }
        }
    }
    //num[14] = 0x074fd355; num[15] = 0x075e1841;
    if (num[14] > 0x073f66a5 && num[14] < 0x07f04124) {
        if (num[15] > 0x07414558 && num[15] < 0x078e3e98) {
            if ((num[14] * num[15]) == 0x074fd355 * 0x075e1841) {
                flags[7] = 7;
            }
        }
    }
#if 0
#endif
    if (flags[0] == 0 
            && flags[1] == 1 
            && flags[2] == 2 
            && flags[3] == 3 
            && flags[4] == 4 
            && flags[5] == 5 
            && flags[6] == 6
            && flags[7] == 7
            /*
            */
            ) {
        *((volatile uint8_t *)0) = 0;
    }
    return 0;
}
int main(int argc, char **argv) {
    uint8_t data[sizeof(uint32_t) * 16];
    klee_make_symbolic(data, sizeof(data), "Data");
    LLVMFuzzerTestOneInput(data, sizeof(data));
    return 0;
}

