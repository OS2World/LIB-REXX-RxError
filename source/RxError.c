#define RETURN_INVALID                   40
#define RETURN_OK                        0
#define INCL_DOSMISC
#define INCL_DOSERRORS
#define INCL_REXXSAA
#include <os2.h>
#include <rexxsaa.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

RexxFunctionHandler RxError;

ULONG RxError(CHAR *name,
              ULONG numargs,
              RXSTRING args[],
              CHAR *qjunk,
              RXSTRING *rstring)
{
    CHAR argtemp[257];
    ULONG errarg;
    FILE *debug;

    if (numargs!=1)
        return RETURN_INVALID;

    strncpy(argtemp, args[0].strptr, args[0].strlength);
    argtemp[args[0].strlength]=0x00;

    if (!strcmpi(argtemp, "disableharderror") ||
        !strcmpi(argtemp, "disableharderr") ||
        !strcmpi(argtemp, "disablehard") ||
        !strcmpi(argtemp, "dhard") ||
        !strcmpi(argtemp, "dh") ||
        !strcmp(argtemp, "0"))
        {
        errarg=FERR_DISABLEHARDERR;
        }
    else if (!strcmpi(argtemp, "enableharderror") ||
             !strcmpi(argtemp, "enableharderr") ||
             !strcmpi(argtemp, "enablehard") ||
             !strcmpi(argtemp, "ehard") ||
             !strcmpi(argtemp, "eh") ||
             !strcmp(argtemp, "1"))
        {
        errarg=FERR_ENABLEHARDERR;
        }
    else
        return RETURN_INVALID;

    if (DosError(errarg)!=0)
        return RETURN_INVALID;

    strcpy(rstring->strptr, "0");
    rstring->strlength=1;

    return RETURN_OK;
}
