#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    uint32_t *num = (uint32_t *)Data;
    if (Size < sizeof(uint32_t))
        return 0;
    if (*num == 0xa1b2c3d4u)
        *((volatile uint8_t *)0) = 0;
    return 0;
}

__attribute__((weak))
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("%s <test case path>\n", argv[0]);
        return -1;
    }
    FILE *fp = NULL;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("fopen %s failed\n", argv[1]);
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) != 0) {
        printf("fseek failed\n");
        fclose(fp);
        return -1;
    }
    long size = ftell(fp);
    if (size < 0) {
        printf("ftell failed\n");
        fclose(fp);
        return -1;
    }
    rewind(fp);
    uint8_t *data = (uint8_t *)malloc(size);
    if (data == NULL) {
        printf("oom\n");
        fclose(fp);
        return -1;
    }
    if (fread(data, size, 1, fp) != 1) {
        printf("fread failed\n");
        free(data);
        fclose(fp);
        return -1;
    }
    fclose(fp);
    LLVMFuzzerTestOneInput(data, size);
    free(data);
    return 0;
}
