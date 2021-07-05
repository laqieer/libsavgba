# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

## [3.3.0](https://github.com/laqieer/libsavgba/compare/v3.2.0...v3.3.0) (2021-07-05)


### Features

* add support to show error codes and error messages ([9e21e59](https://github.com/laqieer/libsavgba/commit/9e21e59eaef13059e55fce8d11c9d55fce0b8396))
* add verify in eeprom_write ([3fbd992](https://github.com/laqieer/libsavgba/commit/3fbd99282c2e81549b0799ce06f054d6c90864e2))
* support cross-sector flash write ([0c7e19a](https://github.com/laqieer/libsavgba/commit/0c7e19a760c577e2975a0e9b75701f855c8480e8))

## [3.2.0](https://github.com/laqieer/libsavgba/compare/v3.1.2...v3.2.0) (2021-07-05)


### Features

* add an extra tool: detect-save-type ([da45a5a](https://github.com/laqieer/libsavgba/commit/da45a5ac5fd289291910426b7f5c9a70cf57ac7a))

### [3.1.2](https://github.com/laqieer/libsavgba/compare/v3.1.1...v3.1.2) (2021-07-03)


### Bug Fixes

* fix 512B EEPROM's compatibility with EverDrive-GBA X5 ([a2e9b30](https://github.com/laqieer/libsavgba/commit/a2e9b30ea6860bc5493453763aec923509671fed))

### [3.1.1](https://github.com/laqieer/libsavgba/compare/v3.1.0...v3.1.1) (2021-07-03)


### Bug Fixes

* fix Flash's compatibility with vba and vba-m ([8f9d5e9](https://github.com/laqieer/libsavgba/commit/8f9d5e9ab1abd23f3e346a4106e841d2288722f5))

## [3.1.0](https://github.com/laqieer/libsavgba/compare/v3.0.0...v3.1.0) (2021-07-03)


### Features

* add backup media support for Atmel's Flash ([e77831e](https://github.com/laqieer/libsavgba/commit/e77831e90c007776125acbb92fd0556ccfd99596))

## [3.0.0](https://github.com/laqieer/libsavgba/compare/v2.0.0...v3.0.0) (2021-07-02)


### ⚠ BREAKING CHANGES

* add eeprom_init(), rename eeprom_512_read() and eeprom_8K_read() to eeprom_read(),
rename eeprom_512_write() and eeprom_8K_write() to eeprom_write()

### Features

* add 10ms timeout for eeprom_write() ([8053a4d](https://github.com/laqieer/libsavgba/commit/8053a4dced8fc0b5c010f3be756ce10c1bd7916a))
* unify read and write function for backup media EEPROM ([66abae8](https://github.com/laqieer/libsavgba/commit/66abae8995703028ab3aac52dbeb02c6f43136be))


### Bug Fixes

* fix detection after write data to EEPROM ([4e32a74](https://github.com/laqieer/libsavgba/commit/4e32a746f7c1c3e6251dd8552cc808444dee218f))
* fix out of range detection ([2263825](https://github.com/laqieer/libsavgba/commit/2263825591d1e7edb0f2c7ef8c6227a7282871b8))

## [2.0.0](https://github.com/laqieer/libsavgba/compare/v1.2.0...v2.0.0) (2021-07-02)


### ⚠ BREAKING CHANGES

* add a parameter to specify the flash size to flash_init(), just pass `0` if you
don't want to specify it, then it will be detected automatically by flash chip identification
operation

### Features

* add backup media support for 128KB Flash ([faefc2b](https://github.com/laqieer/libsavgba/commit/faefc2bcdf0586a17affb70fb2ad4587faf6d432))

## [1.2.0](https://github.com/laqieer/libsavgba/compare/v1.1.0...v1.2.0) (2021-07-02)


### Features

* add backup media support for 64KB Flash ([e104422](https://github.com/laqieer/libsavgba/commit/e10442283b73391c42d1b8edf57650e5b23f8c83))

## [1.1.0](https://github.com/laqieer/libsavgba/compare/v1.0.0...v1.1.0) (2021-06-30)


### Features

* add backup media support for EEPROM ([dbe36a0](https://github.com/laqieer/libsavgba/commit/dbe36a016beed6340475e4e21bd332a1bd642a9a))


### Bug Fixes

* fix Cart Backup IDs ([2c94c88](https://github.com/laqieer/libsavgba/commit/2c94c88cc657d59ea1ee7e621569f4ea224b768f))
* fix infinite loop in eeprom_write ([40fb7fe](https://github.com/laqieer/libsavgba/commit/40fb7fe3aac921a0eab94fde70441e13d411e04b))

## 1.0.0 (2021-06-29)


### Features

* add backup media support for SRAM ([91a9e57](https://github.com/laqieer/libsavgba/commit/91a9e57b3d1fecd1d1af731d7764e2e739adab9c))
