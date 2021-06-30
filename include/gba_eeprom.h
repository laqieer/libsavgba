#ifndef GBA_EEPROM_H
#define GBA_EEPROM_H

/**
 * @brief Read data from EEPROM (size: 512B).
 *
 * @param addr address in EEPROM (unit: 8 bytes).
 * @param data buffer to hold data (size: a unit = 8 bytes).
 *
 * @return \c 0 for success, \c non-zero for error. 
 */
int eeprom_512_read(u32 addr, u16 *data);

/**
 * @brief Write data to EEPROM (size: 512B).
 *
 * @param addr address in EEPROM (unit: 8 bytes).
 * @param data buffer to hold data (size: a unit = 8 bytes).
 *
 * @return \c 0 for success, \c non-zero for error.
 */
int eeprom_512_write(u32 addr, u16 *data);

/**
 * @brief Read data from EEPROM (size: 8KB).
 *
 * @param addr address in EEPROM (unit: 8 bytes).
 * @param data buffer to hold data (size: a unit = 8 bytes).
 *
 * @return \c 0 for success, \c non-zero for error. 
 */
int eeprom_8K_read(u32 addr, u16 *data);

/**
 * @brief Write data to EEPROM (size: 8KB).
 *
 * @param addr address in EEPROM (unit: 8 bytes).
 * @param data buffer to hold data (size: a unit = 8 bytes).
 *
 * @return \c 0 for success, \c non-zero for error.
 */
int eeprom_8K_write(u32 addr, u16 *data);

#endif /* GBA_EEPROM_H */
