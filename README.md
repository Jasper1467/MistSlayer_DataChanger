# MistSlayer_DataChanger

# Usage
msdc.exe operation file

**operation**: 
- **enc**: encrypt/save the edited data.
- **dec**: decrypt/make the data easy to edit

**file**: the target file

# Installation
Download one of the releases and place the binary in the directory:
```
%APPDATA%\..\LocalLow\MojuGames\MistSlayer
```

# Build
Simply run **build.bat**.

Alternatively, run this code in your terminal:
```
gcc main.c des.h des.c -o msdc
```