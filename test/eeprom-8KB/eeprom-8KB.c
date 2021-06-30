#include <tonc.h>

#include <gba_eeprom.h>

#define BUFFER_SIZE 4

int main(void) {
    int err;
	u16 buffer[BUFFER_SIZE];

	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;
	
	tte_init_chr4c_default(0, BG_CBB(0) | BG_SBB(31));

    // Write Test
    err = eeprom_8K_write(0, "EEPROM_Vnnn\n");
    if (err) {
        tte_write("EEPROM(8KB) Write Failed!");
        goto end;
    }

    err = eeprom_8K_write(1, "nnn\n");
    if (err) {
        tte_write("EEPROM(8KB) Write Failed!");
        goto end;
    }

    // Read Test
    err = eeprom_8K_read(0, buffer);
    if (err) {
        tte_write("EEPROM(8KB) Read Failed!");
    }
    tte_write(buffer);

    err = eeprom_8K_read(1, buffer);
    if (err) {
        tte_write("EEPROM(8KB) Read Failed!");
    }
    tte_write(buffer);

    // Final Result
    tte_write("EEPROM(8KB) Test Passed!");

end:
	irq_init(NULL);
	irq_enable(II_VBLANK);

	while (1) {
		VBlankIntrWait();
	}
	
}
