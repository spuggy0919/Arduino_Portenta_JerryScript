#### This port library should be combined with tinyconsole project.
https://github.com/spuggy0919/ESP32_tinyConsole.git

select platform.ini JerryScript section

### JerryScript is modifed from the  fork below
https://github.com/dmazzella/Arduino_Portenta_JerryScript

[libarary license MIT](https://github.com/spuggy0919/Arduino_Portenta_JerryScript/blob/main/LICENSE)

[JerryScript LICENSE Apache License 2.0](https://github.com/jerryscript-project/jerryscript/blob/master/LICENSE)


### Important How to let tinyConsole work with JerryScript 
study the examples from [Jerryscript Document](https://github.com/jerryscript-project/jerryscript/blob/master/docs/03.API-EXAMPLE.md) convert these examples into cmd of tinyConsole.

#### Portting driver layer of tinyConsole
JerryScript port bases on tinyconsole driver layer (below will be modified for unification in future)

1.  **wsSerial.cpp** serial driver communicate between basic and websocket client, wsSerial also respones for client **Keyboard** input and **console out**.
2. **Itouch.cpp** **touch** event queuing driver , streams come from websocket client the console cmd app or basic filter the event queuq, to get coordinate.
3. display **graphics** functions are in one include **#include "audiovideo.h"**
4. **File system** is littlefs, the jerryscript  uses new interface is **fileio.h** class object, global name is **g_fsio**.
   
   	
#### TinyConsole Library functions
1. **ESPMCU** defines ESP reset and wdt clear.
2. **GPIO** for button and Led pwm setting.
3. **LITTLEFSFUN** a LITTLEFS library, defined in littlefsfun.h.In future, fileio.cpp will maintain the file system api. 
4. **timer**, esp32 rtc
5. Language package, **JerryScript** is v3.0
6. **Wifi**, config.json is checked at power on, then decides AP, STA auto , or STA mode
7. **Webserver** , HTTPD Webserver and Websocket functions.
   
#### JerryScript v3 port porting:
Arduino_Portenta_JerryScript_tc.cpp is modifed 
and 
Three examples port as cmd file for my tinyConsole
one is REPL, another is BASIC  which runs script line.
Last one is run File Script, call JerryScript-ext.c function, **jerryx_source_exec_script**

Serial change to wsSerial
file io is changed to gfsio class object
other extsion command is disable now.
mbed is deleted.
heap size change from 128k to 64k, otherwise draw0_seg overflow
this folder will be used in ini lib_dep

Examples
Use Jerryscript-ext.c library to execute script
check cmd/cmd_JerryScript_File.cpp