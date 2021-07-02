#include <string.h>

#include <tonc.h>

#include <gba_flash.h>

#define BUFFER_SIZE 50

int main(void) {
    int err;
	u8 buffer[BUFFER_SIZE];

	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;
	
	tte_init_chr4c_default(0, BG_CBB(0) | BG_SBB(31));

    tte_init_con();

    // Init Flash
    err = flash_init(FLASH_SIZE_128KB);
    if (err) {
        tte_printf("Flash(128KB) Init Error: %d\n", err);
        goto end;
    }

    // Write Test
    err = flash_write(64 * 1024, "FLASH1M_Vnnn\n", BUFFER_SIZE);
    if (err) {
        tte_printf("Flash(128KB) Write Error: %d\n", err);
        goto end;
    }

    err = flash_write(0, "Error: 0x0E010000 is mirrored to 0x0E000000\n", BUFFER_SIZE);
    if (err) {
        tte_printf("Flash(128KB) Write Error: %d\n", err);
        goto end;
    }

    // Read Test
    err = flash_read(64 * 1024, buffer, BUFFER_SIZE);
    if (err) {
        tte_printf("Flash(128KB) Read Error: %d\n", err);
    }
    tte_write(buffer);

    // Final Result
    if (memcmp(buffer, "FLASH1M_Vnnn\n", 12) == 0)
        tte_write("Flash(128KB) Test Passed!");

end:
	irq_init(NULL);
	irq_enable(II_VBLANK);

	while (1) {
		VBlankIntrWait();
	}
	
}
