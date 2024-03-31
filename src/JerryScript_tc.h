#ifndef _JERRYSCRIPT_H_
#define _JERRYSCRIPT_H_

// #include "cmdconfig.h"

#ifdef _LANG_JERRYSCRIPT_
#include "Arduino_Portenta_JerryScript.h"
int cmd_JerryScript_Repl(int argc,char* argv[]);
int  cmd_JerryScript_RunFile(int argc,char* argv[]);
int cmd_JerryScript_Basic(int argc,char* argv[]);
int js_example9 (int argc,char *argv[]);
int js_example10 (int argc,char *argv[]);

#endif //_LANG_JERRYSCRIPT_

#endif // _JERRYSCRIPT_H_
