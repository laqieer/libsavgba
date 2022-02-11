# libsavgba
A library to access various backup media in GBA cartridges

[![CI](https://github.com/laqieer/libsavgba/actions/workflows/main.yml/badge.svg)](https://github.com/laqieer/libsavgba/actions/workflows/main.yml)
[![CodeFactor](https://www.codefactor.io/repository/github/laqieer/libsavgba/badge)](https://www.codefactor.io/repository/github/laqieer/libsavgba)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Conventional Commits](https://img.shields.io/badge/Conventional%20Commits-1.0.0-yellow.svg)](https://conventionalcommits.org)
[![Commitizen friendly](https://img.shields.io/badge/commitizen-friendly-brightgreen.svg)](http://commitizen.github.io/cz-cli/)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Flaqieer%2Flibsavgba.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Flaqieer%2Flibsavgba?ref=badge_shield)

## Compatibility

### Emulator

|Save Type|SRAM|EEPROM(512B)|EEPROM(8KB)|Flash(64KB)|Flash(128KB)|
|---|---|---|---|---|---|
|[mGBA](https://mgba.io/)|✔|✔|✔|✔|✔|
|[VisualBoyAdvance-M](https://vba-m.com/)|✔|✔|✔|✔|✔|
|[NanoBoyAdvance](https://github.com/fleroviux/NanoBoyAdvance)|✔|✔|✔|✔|✔|
|[No$GBA](https://www.nogba.com/)|✔|✔|✔|✔|✔|
|[VisualBoyAdvance](http://www.emulator-zone.com/doc.php/gba/vboyadvance.html)|✔|✔|✔|✔|✔|

### Flashcart

|Save Type|SRAM|EEPROM(512B)|EEPROM(8KB)|Flash(64KB)|Flash(128KB)|
|---|---|---|---|---|---|
|[EZ-FLASH OMEGA](https://www.ezflash.cn/product/omega/)|✔|✔|✔|✔|✔|
|[EverDrive-GBA X5](https://krikzz.com/store/home/42-everdrive-gba-x5.html)|✔|✔|✘|✔|✔|
|[SuperCard MINI SD](http://chn.supercard.sc/manual/mini_sd.htm)|✔|✘|✘|✘|✘|

*EverDrive-GBA X5 doesn't support 8KB EEPROM.*

*SuperCard MINI SD only supports SRAM.*

## [Documentation](https://laqieer.github.io/libsavgba/)

## [Source](https://github.com/laqieer/libsavgba)

## Build

`make`

## Extra

[detect-save-type](https://github.com/laqieer/libsavgba/tree/main/test/detect-save-type)

## License
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Flaqieer%2Flibsavgba.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2Flaqieer%2Flibsavgba?ref=badge_large)
