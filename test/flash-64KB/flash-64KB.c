#include <tonc.h>

#include <err_def.h>
#include <gba_flash.h>

#define BUFFER_SIZE 50

int main(void) {
    int err;
	u8 buffer[BUFFER_SIZE];

	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;

	tte_init_chr4c_default(0, BG_CBB(0) | BG_SBB(31));

    tte_init_con();

    // Init Flash
    err = flash_init(FLASH_SIZE_64KB);
    if (err) {
        tte_printf("Flash(64KB) Init Error: %s\n", SavErrMsgs[err]);
        goto end;
    }

    // Write Test
    err = flash_write(0, (u8 *)"FLASH512_Vnnn\n", BUFFER_SIZE);
    if (err) {
        tte_printf("Flash(64KB) Write Error: %s\n", SavErrMsgs[err]);
        goto end;
    }

    // Read Test
    err = flash_read(0, buffer, BUFFER_SIZE);
    if (err) {
        tte_printf("Flash(64KB) Read Error: %s\n", SavErrMsgs[err]);
    }
    tte_write((char *)buffer);

    // Final Result
    tte_write("Flash(64KB) Test Passed!");

end:
	irq_init(NULL);
	irq_enable(II_VBLANK);

	while (1) {
		VBlankIntrWait();
	}

}
