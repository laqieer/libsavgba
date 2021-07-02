# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

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
