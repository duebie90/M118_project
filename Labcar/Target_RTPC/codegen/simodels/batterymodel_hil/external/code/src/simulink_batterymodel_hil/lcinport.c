
#define S_FUNCTION_NAME  LCInport
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include <math.h>

#ifndef MATLAB_MEX_FILE
    #include "modcomm.h"
#endif


#define  output 	(*(real_T *) ssGetOutputPortRealSignal(S,0)) 	 // Output [s] Velocity
#define moduleName ((char_T *) mxGetData(ssGetSFcnParam(S,0)))  // Parameter: model name 
#define portIndex (int32_T) mxGetPr(ssGetSFcnParam(S,1))[0]  // Parameter: port number
#define b_useConstant (*(real_T *) mxGetPr(ssGetSFcnParam(S,2)))  // Parameter: port number
#define constValue (*(real_T *) mxGetPr(ssGetSFcnParam(S,3)))   // Parameter: port number


/*====================*
 * S-function methods *
 *====================*/

static void mdlInitializeSizes(SimStruct *S) {
	// Specify Number of Parameters, States, Inputs, Outputs, Work-Variables
	ssSetNumSFcnParams(S,4);  /* Number of expected parameters */
	if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
		/* Return if number of expected != number of actual parameters */
		return;
	}

	ssSetNumContStates(S,0);  /* Number of Continuous States Array */
	ssSetNumDiscStates(S,0);  /* Number of Discrete States Array */
	if (!ssSetNumInputPorts(S,0)) return;  /* Number of Inputs */
	if (!ssSetNumOutputPorts(S,1)) return;  /* Number of Outputs */
	ssSetNumRWork(S,0);  /* Length of RWork Array */
	ssSetNumIWork(S,0);  /* Length of IWork Array */

	ssSetSFcnParamTunable(S, 0, 1);

//	ssSetOutputPortWidth(S, 0, DYNAMICALLY_SIZED);
	ssSetOutputPortWidth(S, 0, 1);
	ssSetOutputPortDataType(S, 0, DYNAMICALLY_TYPED);
//	ssSetOutputPortDimensionInfo(S,  0, DYNAMIC_DIMENSION);
//	ssSetOptions(S, SS_OPTION_ALLOW_PARTIAL_DIMENSIONS_CALL);

    ssSetNumSampleTimes(S, 1);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    ssSetOptions(S, 0);
}

# define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int_T port, DTypeId id)
{
	#ifdef MATLAB_MEX_FILE
/*		char buffer[200];
		mxGetString( ssGetSFcnParam(S,0), buffer, 99 );
		ssPrintf("Testprint Inport: %s \n", buffer);
		switch(id) {
			case SS_DOUBLE:
				ssPrintf("LC INPUT mdlSetOutputPortDataType: double\n");
				break;
			case SS_INT32:
				ssPrintf("LC INPUT mdlSetOutputPortDataType: int32\n");
				break;
			case SS_UINT32:
				ssPrintf("LC INPUT mdlSetOutputPortDataType: uint32\n");
				break;
			case SS_BOOLEAN:
				ssPrintf("LC INPUT mdlSetOutputPortDataType: boolean\n");
				break;
			default:
				ssSetErrorStatus(S, "Block connected to an unsupported data type\n");
				break;
		}*/
	#endif

	ssSetOutputPortDataType(S, 0, id);
}


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S) {
    ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
}



#define MDL_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */
static void mdlInitializeConditions(SimStruct *S) {
}



#define MDL_START  /* Change to #undef to remove function */
static void mdlStart(SimStruct *S) {
	#ifndef MATLAB_MEX_FILE
		char buffer[200];
		mxGetString( ssGetSFcnParam(S,0), buffer, 99 );
		ssSetUserData(S, LC_getInputArrayPtr(buffer));
	#endif
}



static void mdlOutputs(SimStruct *S, int_T tid) {
	// Note: The index parameter is "double" since the RTW does not support parameters of other types in S-functions

	#ifdef MATLAB_MEX_FILE

		switch(ssGetOutputPortDataType(S, 0)) {
			case SS_DOUBLE:
				*(real_T *) ssGetOutputPortRealSignal(S,0) = constValue;
				break;
			case SS_SINGLE:
				*(real32_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			case SS_INT8:
				*(int8_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			case SS_INT16:
				*(int16_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			case SS_INT32:
				*(int32_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			case SS_UINT8:
				*(uint8_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			case SS_UINT16:
				*(uint16_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			case SS_UINT32:
				*(uint32_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			case SS_BOOLEAN:
				*(boolean_T *) ssGetOutputPortSignal(S,0) = constValue;
				break;
			default:
				ssSetErrorStatus(S, "Block connected to an unsupported data type\n");
				break;
		}

	#else

		double *localInputArray;

		localInputArray = ssGetUserData(S);

		switch(ssGetOutputPortDataType(S, 0)) {
			case SS_DOUBLE:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(real_T *) ssGetOutputPortRealSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(real_T *) ssGetOutputPortRealSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_SINGLE:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(real32_T *) ssGetOutputPortSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(real32_T *) ssGetOutputPortSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_INT8:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(int8_T *) ssGetOutputPortSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(int8_T *) ssGetOutputPortSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_INT16:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(int16_T *) ssGetOutputPortSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(int16_T *) ssGetOutputPortSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_INT32:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(int32_T *) ssGetOutputPortSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(int32_T *) ssGetOutputPortSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_UINT8:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(uint8_T *) ssGetOutputPortSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(uint8_T *) ssGetOutputPortSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_UINT16:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(uint16_T *) ssGetOutputPortSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(uint16_T *) ssGetOutputPortSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_UINT32:
				if (b_useConstant > 0.00001) {
					// Constant value:
					*(uint32_T *) ssGetOutputPortSignal(S,0) = constValue;
				} else {
					// Get value from external:
					*(uint32_T *) ssGetOutputPortSignal(S,0) = localInputArray[portIndex];
				}
				break;
			case SS_BOOLEAN:
				if (b_useConstant > 0.00001) {
					// Constant value:
					if (fabs(constValue) > 0.00001)
						*(boolean_T *) ssGetOutputPortSignal(S,0) = 1;  // true
					else
						*(boolean_T *) ssGetOutputPortSignal(S,0) = 0;  // false
				} else {
					// Get value from external:
					if (fabs(localInputArray[portIndex]) > 0.00001)
						*(boolean_T *) ssGetOutputPortSignal(S,0) = 1;  // true
					else
						*(boolean_T *) ssGetOutputPortSignal(S,0) = 0;  // false
				}
				break;
			default:
				ssSetErrorStatus(S, "Block connected to an unsupported data type\n");
				break;
		}

	#endif

}



#define MDL_UPDATE  /* Change to #undef to remove function */
static void mdlUpdate(SimStruct *S, int_T tid) {
#ifndef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#endif
}



#define MDL_DERIVATIVES  /* Change to #undef to remove function */
static void mdlDerivatives(SimStruct *S) {
}



static void mdlTerminate(SimStruct *S) {
}

#undef output
#undef moduleName
#undef portIndex
#undef b_useConstant
#undef constValue

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* mex-file interface mechanism */
#else
#include "cg_sfun.h"       /* code generation registration function */
#endif

