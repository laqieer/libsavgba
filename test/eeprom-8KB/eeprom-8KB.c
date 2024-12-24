#include <tonc.h>

#include <err_def.h>
#include <gba_eeprom.h>

#define BUFFER_SIZE 8

int main(void) {
    int err;
	u16 buffer[BUFFER_SIZE];

	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;

	tte_init_chr4c_default(0, BG_CBB(0) | BG_SBB(31));

    tte_init_con();

    // Init EEPROM
    err = eeprom_init(EEPROM_SIZE_8KB);
    if (err) {
        tte_printf("EEPROM(8KB) Init Error: %s\n", SavErrMsgs[err]);
        goto end;
    }

    // Write Test
    err = eeprom_write(0, (u16 *)"EEPROM_Vnnn\n");
    if (err) {
        tte_printf("EEPROM(8KB) Write Error: %s\n", SavErrMsgs[err]);
        goto end;
    }

    err = eeprom_write(1, (u16 *)"nnn\n");
    if (err) {
        tte_printf("EEPROM(8KB) Write Error: %s\n", SavErrMsgs[err]);
        goto end;
    }

    // Read Test
    err = eeprom_read(0, buffer);
    if (err) {
        tte_printf("EEPROM(8KB) Read Error: %s\n", SavErrMsgs[err]);
    }

    err = eeprom_read(1, &buffer[4]);
    if (err) {
        tte_printf("EEPROM(8KB) Read Error: %s\n", SavErrMsgs[err]);
    }
    tte_write((char *)buffer);

    // Final Result
    tte_write("EEPROM(8KB) Test Passed!");

end:
	irq_init(NULL);
	irq_enable(II_VBLANK);

	while (1) {
		VBlankIntrWait();
	}

}
