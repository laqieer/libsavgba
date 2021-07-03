#include <tonc.h>

#include <gba_eeprom.h>

#define BUFFER_SIZE 8

int main(void) {
    int err;
	u16 buffer[BUFFER_SIZE];

	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;
	
	tte_init_chr4c_default(0, BG_CBB(0) | BG_SBB(31));

    tte_init_con();

    // Init EEPROM
    err = eeprom_init(EEPROM_SIZE_512B);
    if (err) {
        tte_printf("EEPROM(512B) Init Error: %d\n", err);
        goto end;
    }

    // Write Test
    err = eeprom_write(0, "EEPROM_Vnnn\n");
    if (err) {
        tte_printf("EEPROM(512B) Write Error: %d\n", err);
        goto end;
    }

    err = eeprom_write(1, "nnn\n");
    if (err) {
        tte_printf("EEPROM(512B) Write Error: %d\n", err);
        goto end;
    }

    // Read Test
    err = eeprom_read(0, buffer);
    if (err) {
        tte_printf("EEPROM(512B) Read Error: %d\n", err);
    }

    err = eeprom_read(1, &buffer[4]);
    if (err) {
        tte_printf("EEPROM(512B) Read Error: %d\n", err);
    }
    tte_write(buffer);

    // Final Result
    tte_write("EEPROM(512B) Test Passed!");

end:
	irq_init(NULL);
	irq_enable(II_VBLANK);

	while (1) {
		VBlankIntrWait();
	}
	
}
