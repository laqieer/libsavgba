#include <stddef.h>

#include <tonc.h>

#include "err_def.h"
#include "gba_eeprom.h"

#define MEM_EEPROM 0x0D000000
#define eeprom_mem ((vu16*)MEM_EEPROM)

#define EEPROM_512_gEepromSize 6
#define EEPROM_8K_gEepromSize 14

#define LOOP_CNT_PER_MILLI_SECOND 1000
#define EEPROM_WRITE_TIMEOUT_BY_MILLI_SECOND 10

u8 gEepromSize;

void eeprom_memcpy(volatile void *dst, volatile const void *src, size_t size)
{
    u16 REG_IME_old = REG_IME;
    REG_IME = 0;
    REG_WAITCNT = (REG_WAITCNT & (~0x700)) | WS_ROM2_N8;
    DMA_TRANSFER(dst, src, size, 3, DMA_ENABLE);
    while(REG_DMA3CNT_H & 0x8000);
    REG_IME = REG_IME_old;
}

int eeprom_init(u8 size)
{
    if (size == EEPROM_SIZE_512B || size == EEPROM_SIZE_8KB)
        gEepromSize = size;
    else
        return E_UNSUPPORTED_DEVICE;

    return 0;
}

int eeprom_read(u32 addr, u16 *data)
{
    u16 buffer[68];

    if (data == NULL)
    {
        return E_INVALID_PARAM;
    }

    if (addr >= 1 << gEepromSize)
    {
        return E_OUT_OF_RANGE;
    }

    buffer[0] = 1;
    buffer[1] = 1;
    buffer[2 + gEepromSize] = 0;
    for (int i = 1 + gEepromSize; i >= 2; i--)
    {
        buffer[i] = addr & 1;
        addr = addr >> 1;
    }
    eeprom_memcpy(eeprom_mem, buffer, 3 + gEepromSize);

    eeprom_memcpy(buffer, eeprom_mem, 68);

    for (int i = 3; i >= 0; i--)
    {
        data[i] = 0;
        for (int j = 0; j < 16; j++)
        {
            data[i] |= (buffer[4 + 16 * (3 - i) + j] & 1) << (15 - j);
        }
    }

    return 0;
}

int eeprom_write_only(u32 addr, u16 *data)
{
    u16 buffer[81];

    if (data == NULL)
    {
        return E_INVALID_PARAM;
    }

    if (addr >= 1 << gEepromSize)
    {
        return E_OUT_OF_RANGE;
    }

    buffer[0] = 1;
    buffer[1] = 0;
    buffer[66 + gEepromSize] = 0;
    for (int i = 1 + gEepromSize; i >= 2; i--)
    {
        buffer[i] = addr & 1;
        addr = addr >> 1;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            buffer[65 + gEepromSize - 16 * i - j] = (data[i] >> j) & 1;
        }
    }
    eeprom_memcpy(eeprom_mem, buffer, 67 + gEepromSize);

    // After the DMA, keep reading from the chip, by normal LDRH [D000000h], until Bit 0 of the returned data becomes “1” (Ready).
    // To prevent your program from locking up in case of malfunction, generate a timeout if the chip does not reply after 10ms or longer. 
    for (vu32 i = 0; i < LOOP_CNT_PER_MILLI_SECOND * EEPROM_WRITE_TIMEOUT_BY_MILLI_SECOND; i++)
        if (*eeprom_mem & 1)
            return 0;

    return E_TIMEOUT;
}

int eeprom_write(u32 addr, u16 *data)
{
    int err;
    u16 buffer[4];

    err = eeprom_write_only(addr, data);
    if (err)
        return err;

    err = eeprom_read(addr, buffer);
    if (err)
        return err;

    if (data[0] != buffer[0] || data[1] != buffer[1] ||data[2] != buffer[2] ||data[3] != buffer[3])
        return E_VERIFY_FAIL;

    return 0;
}
