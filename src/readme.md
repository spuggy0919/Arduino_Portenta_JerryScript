#### Portting driver layer of tinyConsole
tinybasic port bases on tinyconsole driver layer 

1.  **wsSerial.cpp** serial driver communicate between basic and websocket client, wsSerial also respones for client **Keyboard** input and **console out**.
2. **Itouch.cpp** **touch** event queuing driver , streams come from websocket client the console cmd app or basic filter the event queuq, to get coordinate.
3. display **graphics** functions are in one include **#include "audiovideo.h"**
4. **File system** is littlefs, the tinybasic uses old littlefsfun.h library, my new interface is **fileio.h** class object, global name is **g_fsio**.
   	
#### TinyConsole Library functions
1. **ESPMCU** defines ESP reset and wdt clear.
2. **GPIO** for button and Led pwm setting.
3. **LITTLEFSFUN** a LITTLEFS library, defined in littlefsfun.h.In future, fileio.cpp will maintain the file system api. 
4. **timer**, esp32 rtc
5. **Tinybasic** ver 1.4a
6. **Wifi**, config.json is checked at power on, then decides AP, STA auto , or STA mode
7. **Webserver** , HTTPD Webserver and Websocket functions.
   
#### JerryScript v3 port porting:
Arduino_Portenta_JerryScript_tc.cpp is modifed 
and 
two examples port as cmd file for my tinyConsole
one is REPL, another is BASIC to be shell cmd run script file.

Serial change to wsSerial
file io is changed to gfsio class object
other extsion command is disable now.
mbed is deleted.
heap size change from 128k to 64k, otherwise draw0_seg overflow
this folder will be used in ini lib_dep