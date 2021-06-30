#include <stddef.h>

#include <tonc.h>

#include "err_def.h"

#define MEM_EEPROM 0x0D000000
#define eeprom_mem ((u8*)MEM_EEPROM)

#define EEPROM_512_ADDR_WIDTH 6
#define EEPROM_8K_ADDR_WIDTH 14

void eeprom_memcpy(void *dst, const void *src, size_t size)
{
    u16 REG_IME_old = REG_IME;
    REG_IME = 0;
    REG_WAITCNT = (REG_WAITCNT & (~0x700)) | WS_ROM2_N8;
    DMA_TRANSFER(dst, src, size, 3, DMA_ENABLE);
    while(REG_DMA3CNT_H & 0x8000);
    REG_IME = REG_IME_old;
}

int eeprom_read(u32 addr, u16 *data, int addr_width)
{
    u16 buffer[68];

    if (data == NULL)
    {
        return E_INVALID_PARAM;
    }

    if (addr >= 1 << addr_width)
    {
        return E_OUT_OF_RANGE;
    }

    buffer[0] = 1;
    buffer[1] = 1;
    buffer[2 + addr_width] = 0;
    for (int i = 1 + addr_width; i >= 2; i--)
    {
        buffer[i] = addr & 1;
        addr = addr >> 1;
    }
    eeprom_memcpy(eeprom_mem, buffer, 3 + addr_width);

    eeprom_memcpy(buffer, eeprom_mem, 68);

    for (int i = 3; i >= 0; i--)
    {
        data[i] = 0;
        for (int j = 0; j < 16; j++)
        {
            data[i] += buffer[4 + 16 * (3 - i) + j] << (15 - j);
        }
    }

    return 0;
}

int eeprom_write(u32 addr, u16 *data, int addr_width)
{
    u16 buffer[81];

    if (data == NULL)
    {
        return E_INVALID_PARAM;
    }

    if (addr >= 1 << addr_width)
    {
        return E_OUT_OF_RANGE;
    }

    buffer[0] = 1;
    buffer[1] = 0;
    buffer[66 + addr_width] = 0;
    for (int i = 1 + addr_width; i >= 2; i--)
    {
        buffer[i] = addr & 1;
        addr = addr >> 1;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            buffer[65 + addr_width - 16 * i - j] = (data[i] >> j) & 1;
        }
    }
    eeprom_memcpy(eeprom_mem, buffer, 67 + addr_width);

    while(!(*eeprom_mem & 1));

    return 0;
}

int eeprom_512_read(u32 addr, u16 *data)
{
    return eeprom_read(addr, data, EEPROM_512_ADDR_WIDTH);
}

int eeprom_512_write(u32 addr, u16 *data)
{
    return eeprom_write(addr, data, EEPROM_512_ADDR_WIDTH);
}

int eeprom_8K_read(u32 addr, u16 *data)
{
    return eeprom_read(addr, data, EEPROM_8K_ADDR_WIDTH);
}

int eeprom_8K_write(u32 addr, u16 *data)
{
    return eeprom_write(addr, data, EEPROM_8K_ADDR_WIDTH);
}
