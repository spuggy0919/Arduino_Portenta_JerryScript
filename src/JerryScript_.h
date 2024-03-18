#ifndef _JERRYSCRIPT_H_
#define _JERRYSCRIPT_H_

// #include "cmdconfig.h"

#ifdef JERRYSCRIPT
#include "Arduino_Portenta_JerryScript.h"
int cmd_JerryScript_Repl(int argc,char* argv[]);
int cmd_JerryScript_Basic(int argc,char* argv[]);
#endif

#endif // _JERRYSCRIPT_H_
