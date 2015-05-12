/*!
 *********************************************************************
 *  @file   : modComm.c
 *  Project : Simulink Connectivity
 *  Package : Inter-Module-Communication
 *  Company : ETAS GmbH, Stuttgart
 *  Author  : Stefan Hagel, PTS                  Date: Sept 2004
 *  Purpose : Hash-Table for Communication lcrt-main with LC-port-blocks
 *
 *********************************************************************
 * Version History:
 * V 1.0  Sept 2004  Hl : Creation
 *********************************************************************
 */

#include "modcomm.h"
#include <string.h>

#define MAXNUMBER 50
static char names[MAXNUMBER][256];
static int noModuleInputs[MAXNUMBER];
static double *localInputArrays[MAXNUMBER];
static int noModuleOutputs[MAXNUMBER];
static double *localOutputArrays[MAXNUMBER];
static int noRegisteredModules;


/*
 * Register module
 *
 * 1. Check if module name is already in the names list, return if yes
 * 2. Check if new entry exceeds max number of modules, return 0 if yes
 * 3. Put name of new module to names-array and the other inputs to the
 *    same index in the corresponding array lists.
 * Return value is 0 in case of error, i. e. on exceeding the maximum
 * number of modules, otherwise 1
 *
 * @history Sept 2004 [Hl] : creation
 */
int LC_registerModule(char* name, int noOfInputs, double *inputArrayPtr,
                                   int noOfOutputs, double *outputArrayPtr)
{
    int i;

    for ( i=0 ; i<noRegisteredModules ; i++ )
    {
        if (strcmp(name, names[i]) == 0)
        {
            // Module name already in list. To get sure, overwrite pointers:
            noModuleInputs[i] = noOfInputs;
            localInputArrays[i] = inputArrayPtr;
            noModuleOutputs[i] = noOfOutputs;
            localOutputArrays[i] = outputArrayPtr;
            return 1;
        }
    }
    // Add new entry to lists:
    if (noRegisteredModules == MAXNUMBER)
    {
        // No space left to add entry
        return 0;
    }
    strcpy(names[noRegisteredModules], name);
    localInputArrays[noRegisteredModules] = inputArrayPtr;
    localOutputArrays[noRegisteredModules] = outputArrayPtr;
    noModuleInputs[noRegisteredModules] = noOfInputs;
    noModuleOutputs[noRegisteredModules] = noOfOutputs;
    
    noRegisteredModules++;
    return 1;
}



/*
 * Get number of inputs for the corresponding module
 *
 * 1. Look for entered name in the names list
 * 2. If not found, return -1, otherwise return entry from the
 *    noModuleInputs array at the same index
 *
 * @history Sept 2004 [Hl] : creation
 */
int LC_getNoInputs(char* name)
{
    int i;

    for ( i=0 ; i<noRegisteredModules ; i++ )
    {
        if (strcmp(name, names[i]) == 0)
        {
            // Module name found in list.
            return noModuleInputs[i];
        }
    }
    return -1;
}


/*
 * Get address of input array for the corresponding module
 *
 * 1. Look for entered name in the names list
 * 2. If not found, return NULL, otherwise return entry from the array
 *    localInputArrays at the same index
 *
 * @history Sept 2004 [Hl] : creation
 */
double *LC_getInputArrayPtr(char* name)
{
    int i;

    for ( i=0 ; i<noRegisteredModules ; i++ )
    {
        if (strcmp(name, names[i]) == 0)
        {
            // Module name found in list.
            return localInputArrays[i];
        }
    }
    return NULL;
}


/*
 * Get number of outputs for the corresponding module
 *
 * 1. Look for entered name in the names list
 * 2. If not found, return -1, otherwise return entry from the
 *    noModuleOutputs array at the same index
 *
 * @history Sept 2004 [Hl] : creation
 */
int LC_getNoOutputs(char* name)
{
    int i;

    for ( i=0 ; i<noRegisteredModules ; i++ )
    {
        if (strcmp(name, names[i]) == 0)
        {
            // Module name found in list.
            return noModuleOutputs[i];
        }
    }
    return -1;
}


/*
 * Get address of output array for the corresponding module
 *
 * 1. Look for entered name in the names list
 * 2. If not found, return NULL, otherwise return entry from the array
 *    localOutputArrays at the same index
 *
 * @history Sept 2004 [Hl] : creation
 */
double *LC_getOutputArrayPtr(char* name)
{
    int i;

    for ( i=0 ; i<noRegisteredModules ; i++ )
    {
        if (strcmp(name, names[i]) == 0)
        {
            // Module name found in list.
            return localOutputArrays[i];
        }
    }
    return NULL;
}
