#ifndef _JERRYSCRIPT_H_
#define _JERRYSCRIPT_H_

// #include "cmdconfig.h"

#ifdef _LANG_JERRYSCRIPT_
#include "Arduino_Portenta_JerryScript.h"
int cmd_JerryScript_Repl(int argc,char* argv[]);
int  cmd_JerryScript_RunFile(int argc,char* argv[]);
int cmd_JerryScript_Basic(int argc,char* argv[]);
#ifdef _JS_EXAMPLE_
int js_example2 (int argc,char *argv[]);
int js_example3 (int argc,char *argv[]);
int js_example4 (int argc,char *argv[]);
int js_example5 (int argc,char *argv[]);
int js_example6 (int argc,char *argv[]);
int js_example7 (int argc,char *argv[]);
int js_example8 (int argc,char *argv[]);
int js_example9 (int argc,char *argv[]);
int js_example10 (int argc,char *argv[]);
#endif
#endif //_LANG_JERRYSCRIPT_

#endif // _JERRYSCRIPT_H_
