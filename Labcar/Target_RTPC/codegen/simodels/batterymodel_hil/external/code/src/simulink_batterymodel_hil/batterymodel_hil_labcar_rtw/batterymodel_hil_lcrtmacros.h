/*
 * File    : Batterymodel_HiL_lcrtmacros.h
 *
 * Abstract:
 *      This file provide some defines to combine multiple models.
 *      This file is processed before all the other files using:
 *      gcc -include Batterymodel_HiL_lcrtmacros.h ... .
 */

/* The simulink assert is mapped to an debug output */
#define utAssert(_exp)                 if(!(_exp)){ asdWriteUserDebug("LCRT RTI: ** Simulink assertblock shows assertion failed. The expression was: '" #_exp "' **\n");}
#ifndef MdlStart
#define MdlStart                       MdlStart_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlOutputs
#define MdlOutputs                     MdlOutputs_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlUpdate
#define MdlUpdate                      MdlUpdate_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlTerminate
#define MdlTerminate                   MdlTerminate_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlInitializeSizes
#define MdlInitializeSizes             MdlInitializeSizes_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlInitializeSampleTimes
#define MdlInitializeSampleTimes       MdlInitializeSampleTimes_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlInitialize
#define MdlInitialize                  MdlInitialize_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlEnable
#define MdlEnable                      MdlEnable_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlDerivatives
#define MdlDerivatives                 MdlDerivatives_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef MdlProjection
#define MdlProjection                  MdlProjection_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_CallSys
#define rt_CallSys                     rt_CallSys_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_EnableSys
#define rt_EnableSys                   rt_EnableSys_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_DisableSys
#define rt_DisableSys                  rt_DisableSys_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_ODECreateIntegrationData
#define rt_ODECreateIntegrationData    rt_ODECreateIntegrationData_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_ODEUpdateContinuousStates
#define rt_ODEUpdateContinuousStates   rt_ODEUpdateContinuousStates_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_ODEDestroyIntegrationData
#define rt_ODEDestroyIntegrationData   rt_ODEDestroyIntegrationData_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_ODECacheDataIntoSolverInfo
#define rt_ODECacheDataIntoSolverInfo  rt_ODECacheDataIntoSolverInfo_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_ODERetrieveDataFromSolverInfo
#define rt_ODERetrieveDataFromSolverInfo rt_ODERetrieveDataFromSolverInfo_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_ODECreateSolverInfo
#define rt_ODECreateSolverInfo         rt_ODECreateSolverInfo_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_SimInitTimingEngine
#define rt_SimInitTimingEngine         rt_SimInitTimingEngine_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_SimGetNextSampleHit
#define rt_SimGetNextSampleHit         rt_SimGetNextSampleHit_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_SimUpdateDiscreteTaskSampleHits
#define rt_SimUpdateDiscreteTaskSampleHits rt_SimUpdateDiscreteTaskSampleHits_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_SimUpdateDiscreteEvents
#define rt_SimUpdateDiscreteEvents     rt_SimUpdateDiscreteEvents_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef rt_SimUpdateDiscreteTaskTime
#define rt_SimUpdateDiscreteTaskTime   rt_SimUpdateDiscreteTaskTime_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

#ifndef local_numjac
#define local_numjac                   local_numjac_Batterymodel_HiL
#else
#error "A multiple model macro is already defined, this isn't allowed!"
#endif

//#ifndef rtP
//#define rtP rtP_Batterymodel_HiL
//#else
//#error "A multiple model macro is already defined, this isn't allowed!"
//#endif

//#ifndef rtB
//#define rtB rtB_Batterymodel_HiL
//#else
//#error "A multiple model macro is already defined, this isn't allowed!"
//#endif

//#ifndef rtcP
//#define rtcP rtcP_Batterymodel_HiL
//#else
//#error "A multiple model macro is already defined, this isn't allowed!"
//#endif

// For subblocks with the S-Function target (lower-case rt"s" for R14):
#ifndef rts
#define rts                            Batterymodel_HiL_rtS
#elif (rts != Batterymodel_HiL_rtS)
#error "A multiple model macro 'rts' is already defined, this isn't allowed!"
#endif

/* EOF: Batterymodel_HiL_lcrtmacros.h */
