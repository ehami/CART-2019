/**
 * @file libLCD
 * a modified version of libLCD
 */
#include <API.h>

// ARRAYS OF SCRIPTS AND TITLES, NEED TO BE DEFINED ELSEWHERE //
#define NUM_SCRIPTS 8
extern const char* titles[];
extern void (*scripts[])();

#define LCD_TASK_DELTA 20

static FILE *lcdPort;

void lcdPrintCentered(unsigned char line, const char *string);

void lcdScriptInit(FILE *port);

// called in a looping task in lcdScriptSelect
void _lcdScriptSelect(void *parameters);

void lcdScriptSelect();

void lcdScriptExecute();
