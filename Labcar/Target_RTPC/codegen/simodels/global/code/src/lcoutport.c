
#define S_FUNCTION_NAME  LCOutport
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

#ifndef MATLAB_MEX_FILE
    #include "modcomm.h"
#endif

// Purpose: Write the input of the block to RTIO. The ID of this input in RTIO
// is passed to the function as parameter.


/*====================*
 * S-function methods *
 *====================*/

#define moduleName ((char_T *) mxGetData(ssGetSFcnParam(S,0)))  // Parameter: model name 
#define portIndex (int32_T) mxGetPr(ssGetSFcnParam(S,1))[0]  // Parameter: port number
//#define  buffer ((char_T *) &(ssGetIWork(S)[0]))  // Model name (copy of parameter)

static void mdlInitializeSizes(SimStruct *S) {

	// Specify Number of Parameters, States, Inputs, Outputs, Work-Variables
	ssSetNumSFcnParams(S,2);  /* Number of expected parameters */
	if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
		/* Return if number of expected != number of actual parameters */
		return;
	}

	ssSetNumContStates(S,0);  /* Number of Continuous States Array */
	ssSetNumDiscStates(S,0);  /* Number of Discrete States Array */
	if (!ssSetNumInputPorts(S,1)) return;  /* Number of Inputs */
	if (!ssSetNumOutputPorts(S,0)) return;  /* Number of Outputs */
	ssSetNumRWork(S,0);  /* Length of RWork Array */
	ssSetNumIWork(S,0);  /* Length of IWork Array */

	// Specify Properties of single Parameters, Inputs, Outputs
	ssSetInputPortWidth(S, 0, 1);
//	ssSetInputPortDimensionInfo(S, 0, DYNAMIC_DIMENSION);
	ssSetInputPortDataType(S, 0, DYNAMICALLY_TYPED);
	ssSetInputPortRequiredContiguous(S, 0, true);
	ssSetInputPortDirectFeedThrough(S, 0, 0);

	ssSetSFcnParamTunable(S, 0, 1);
	ssSetSFcnParamTunable(S, 1, 1);

	ssSetNumSampleTimes(S, 1);
	ssSetNumPWork(S, 0);
	ssSetNumModes(S, 0);
	ssSetNumNonsampledZCs(S, 0);
	
	ssSetOptions(S, 0);
}



# define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, int_T port, DTypeId id)
{
	#ifdef MATLAB_MEX_FILE
/*	char buffer[200];
	mxGetString( ssGetSFcnParam(S,0), buffer, 199 );
	ssPrintf("Testprint: %s \n", buffer);
	switch(id) {
		case SS_DOUBLE:
			ssPrintf("LC OUTPUT mdlSetInputPortDataType: double\n");
			break;
		case SS_INT32:
			ssPrintf("LC OUTPUT mdlSetInputPortDataType: int32\n");
			break;
		case SS_UINT32:
			ssPrintf("LC OUTPUT mdlSetInputPortDataType: uint32\n");
			break;
		case SS_BOOLEAN:
			ssPrintf("LC OUTPUT mdlSetInputPortDataType: boolean\n");
			break;
		default:
			ssSetErrorStatus(S, "Block connected to an unsupported data type\n");
			break;
	}*/
	#endif
	
	ssSetInputPortDataType(S, 0, id);
}


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S) {
	ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);
	ssSetOffsetTime(S, 0, 0.0);
}



#define MDL_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */
static void mdlInitializeConditions(SimStruct *S) {
}



#define MDL_START  /* Change to #undef to remove function */
static void mdlStart(SimStruct *S) {
	#ifndef MATLAB_MEX_FILE
		char buffer[200];
		mxGetString( ssGetSFcnParam(S,0), buffer, 99 );
		ssSetUserData(S, LC_getOutputArrayPtr(buffer));
	#endif
}


static void mdlOutputs(SimStruct *S, int_T tid) {

	// Note: The index parameter is "double" since the RTW does not support parameters of other types in S-functions

	#ifndef MATLAB_MEX_FILE

		double *localOutputArray;
		localOutputArray = ssGetUserData(S);

		switch(ssGetInputPortDataType(S, 0)) {
			case SS_DOUBLE:
				localOutputArray[portIndex] = *(real_T *) ssGetInputPortRealSignal(S,0);
				break;
			case SS_SINGLE:
				localOutputArray[portIndex] = *(real32_T *) ssGetInputPortSignal(S,0);
				break;
			case SS_INT8:
				localOutputArray[portIndex] = *(int8_T *) ssGetInputPortSignal(S,0);
				break;
			case SS_INT16:
				localOutputArray[portIndex] = *(int16_T *) ssGetInputPortSignal(S,0);
				break;
			case SS_INT32:
				localOutputArray[portIndex] = *(int32_T *) ssGetInputPortSignal(S,0);
				break;
			case SS_UINT8:
				localOutputArray[portIndex] = *(uint8_T *) ssGetInputPortSignal(S,0);
				break;
			case SS_UINT16:
				localOutputArray[portIndex] = *(uint16_T *) ssGetInputPortSignal(S,0);
				break;
			case SS_UINT32:
				localOutputArray[portIndex] = *(uint32_T *) ssGetInputPortSignal(S,0);
				break;
			case SS_BOOLEAN:
				localOutputArray[portIndex] = *(boolean_T *) ssGetInputPortSignal(S,0);
				break;
			default:
				ssSetErrorStatus(S, "Block connected to an unsupported data type\n");
				break;
		}

	#endif
}


#define MDL_UPDATE  /* Change to #undef to remove function */
static void mdlUpdate(SimStruct *S, int_T tid) {
}



#define MDL_DERIVATIVES  /* Change to #undef to remove function */
static void mdlDerivatives(SimStruct *S) {
}



static void mdlTerminate(SimStruct *S) {
}


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* mex-file interface mechanism */
#else
#include "cg_sfun.h"       /* code generation registration function */
#endif

