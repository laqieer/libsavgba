#ifndef GBA_EEPROM_H
#define GBA_EEPROM_H

/**
 * @brief EEPROM chip size.
 */
enum EepromSize {
    EEPROM_SIZE_512B = 6, ///< 512B (4Kbit)
    EEPROM_SIZE_8KB = 14, ///< 8KB (64K)
};

/**
 * @brief Init EEPROM chip.
 *
 * Set the size of EEPROM chip. **It should be called once at first.**
 *
 * @param size EEPROM chip size (\c EEPROM_SIZE_512B / \c EEPROM_SIZE_8KB).
 *
 * @return \c 0 for success, \c non-zero for error.
 */
int eeprom_init(u8 size);

/**
 * @brief Read data from EEPROM.
 *
 * @param addr address in EEPROM (unit: 8 bytes).
 * @param data buffer to hold data (size: a unit = 8 bytes).
 *
 * @return \c 0 for success, \c non-zero for error. 
 */
int eeprom_read(u32 addr, u16 *data);

/**
 * @brief Write data to EEPROM.
 *
 * @param addr address in EEPROM (unit: 8 bytes).
 * @param data buffer to hold data (size: a unit = 8 bytes).
 *
 * @return \c 0 for success, \c non-zero for error.
 */
int eeprom_write(u32 addr, u16 *data);

#endif /* GBA_EEPROM_H */
