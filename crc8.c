#include <stdio.h>
#include <stdlib.h>

uint8_t Crc8(uint8_t *text, unsigned int len)
{
    uint8_t crc = 0x00;
    uint8_t i;

    while (len--)
    {
        crc ^= *text++;

        for (i = 0; i < 8; i++)
            crc = crc & 0x80 ? (crc << 1) ^ 0x07 : crc << 1;
    }

    return crc;
}

int main()
{
    printf("0x%x\n", Crc8((uint8_t *)"Hello World", 11));
    
    return 0;
}
