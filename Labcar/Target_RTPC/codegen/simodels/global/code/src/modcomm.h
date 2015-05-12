/*!
 *********************************************************************
 *  @file   : modComm.h
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


int LC_registerModule(char* name, int noOfInputs, double *inputArrayPtr, int noOfOutputs, double *outputArrayPtr);
int LC_getNoInputs(char* name);
double *LC_getInputArrayPtr(char* name);
int LC_getNoOutputs(char* name);
double *LC_getOutputArrayPtr(char* name);

