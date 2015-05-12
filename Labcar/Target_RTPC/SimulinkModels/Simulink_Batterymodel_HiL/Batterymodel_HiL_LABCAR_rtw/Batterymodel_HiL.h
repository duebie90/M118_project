/*
 * Batterymodel_HiL.h
 *
 * Code generation for model "Batterymodel_HiL.mdl".
 *
 * Model version              : 1.809
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Tue May 12 19:08:03 2015
 *
 * Target selection: lcrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Batterymodel_HiL_h_
#define RTW_HEADER_Batterymodel_HiL_h_
#ifndef Batterymodel_HiL_COMMON_INCLUDES_
# define Batterymodel_HiL_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif                                 /* Batterymodel_HiL_COMMON_INCLUDES_ */

#include "Batterymodel_HiL_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Batterymodel_HiL_rtModel       RT_MODEL_Batterymodel_HiL

/* Block signals (auto storage) */
typedef struct {
  real_T FromWs;                       /* '<S11>/FromWs' */
  real_T ChargeCurrentA;               /* '<S10>/Multiport Switch' */
  real_T ChargeCurrentA_l[12];         /* '<S10>/Product' */
  real_T Gain1[12];                    /* '<S6>/Gain1' */
  real_T SumofElements;                /* '<S6>/Sum of Elements' */
  real_T Divide;                       /* '<S6>/Divide' */
  real_T Abs;                          /* '<S6>/Abs' */
  real_T Vektorize[12];                /* '<S16>/Vektorize' */
  real_T Vektorize_d[12];              /* '<S18>/Vektorize' */
  real_T UnitDelay[12];                /* '<S18>/Unit Delay' */
  real_T Divide_k[12];                 /* '<S18>/Divide' */
  real_T bala_01;                      /* '<S4>/bala_01' */
  real_T bala_02;                      /* '<S4>/bala_02' */
  real_T bala_03;                      /* '<S4>/bala_03' */
  real_T bala_04;                      /* '<S4>/bala_04' */
  real_T bala_05;                      /* '<S4>/bala_05' */
  real_T bala_06;                      /* '<S4>/bala_06' */
  real_T bala_07;                      /* '<S4>/bala_07' */
  real_T bala_08;                      /* '<S4>/bala_08' */
  real_T bala_09;                      /* '<S4>/bala_09' */
  real_T bala_10;                      /* '<S4>/bala_10' */
  real_T bala_11;                      /* '<S4>/bala_11' */
  real_T bala_12;                      /* '<S4>/bala_12' */
  real_T Product[12];                  /* '<S18>/Product' */
  real_T Add[12];                      /* '<S18>/Add' */
  real_T Product_d[12];                /* '<S20>/Product' */
  real_T Gain[12];                     /* '<S20>/Gain' */
  real_T UnitDelay1[12];               /* '<S20>/Unit Delay1' */
  real_T Product1[12];                 /* '<S20>/Product1' */
  real_T Gain1_g[12];                  /* '<S20>/Gain1' */
  real_T UnitDelay_l[12];              /* '<S20>/Unit Delay' */
  real_T Add_o[12];                    /* '<S20>/Add' */
  real_T Product2[12];                 /* '<S20>/Product2' */
  real_T UnitDelay_o[12];              /* '<S7>/Unit Delay' */
  real_T Gain_p[12];                   /* '<S18>/Gain' */
  real_T Add1[12];                     /* '<S20>/Add1' */
  real_T Gain_k[12];                   /* '<S6>/Gain' */
  real_T SumofElements1;               /* '<S6>/Sum of Elements1' */
  real_T Q_0[12];                      /* '<S17>/1//Q_0' */
  real_T DiscreteTimeIntegrator[12];   /* '<S17>/Discrete-Time Integrator' */
  real_T Add_d[12];                    /* '<S17>/Add' */
  real_T u11[12];                      /* '<S7>/0.01->1%' */
  real_T charge_currentA[12];          /* '<S22>/charge_current [A]' */
  real_T charge_currentmA[12];         /* '<S22>/charge_current [mA]' */
  real_T bat_mode_system;              /* '<S22>/bat_mode_system' */
  real_T current_system;               /* '<S22>/current_system' */
  real_T current_systemA;              /* '<S22>/current_system [A]' */
  real_T SumofElements_c;              /* '<S23>/Sum of Elements' */
  real_T SoCModel_;                    /* '<S23>/SoC Model_% ' */
  real_T SoC_Kalman;                   /* '<S23>/SoC_Kalman' */
  real_T deltaSoC;                     /* '<S23>/delta SoC' */
  real_T sum_bat_voltageV;             /* '<S21>/sum_bat_voltage [V]' */
  real_T bat_voltagemV;                /* '<S21>/bat_voltage [mV]' */
  real_T voltage_system;               /* '<S21>/voltage_system' */
  real_T voltage_systemmV;             /* '<S21>/voltage_system [mV]' */
  real_T voltage_systemV;              /* '<S21>/voltage_system [V]' */
  real_T CellT01;                      /* '<S1>/CellT01' */
  real_T CellT02;                      /* '<S1>/CellT02' */
  real_T CellT03;                      /* '<S1>/CellT03' */
  real_T CellT04;                      /* '<S1>/CellT04' */
  real_T CellT05;                      /* '<S1>/CellT05' */
  real_T CellT06;                      /* '<S1>/CellT06' */
  real_T CellT07;                      /* '<S1>/CellT07' */
  real_T CellT08;                      /* '<S1>/CellT08' */
  real_T CellT09;                      /* '<S1>/CellT09' */
  real_T CellT10;                      /* '<S1>/CellT10' */
  real_T CellT11;                      /* '<S1>/CellT11' */
  real_T CellT12;                      /* '<S1>/CellT12' */
  real_T CellV01;                      /* '<S2>/CellV01' */
  real_T CellV02;                      /* '<S2>/CellV02' */
  real_T CellV03;                      /* '<S2>/CellV03' */
  real_T CellV04;                      /* '<S2>/CellV04' */
  real_T CellV05;                      /* '<S2>/CellV05' */
  real_T CellV06;                      /* '<S2>/CellV06' */
  real_T CellV07;                      /* '<S2>/CellV07' */
  real_T CellV08;                      /* '<S2>/CellV08' */
  real_T CellV09;                      /* '<S2>/CellV09' */
  real_T CellV10;                      /* '<S2>/CellV10' */
  real_T CellV11;                      /* '<S2>/CellV11' */
  real_T CellV12;                      /* '<S2>/CellV12' */
  real_T Error_CellNo;                 /* '<S3>/Error_CellNo' */
  real_T Error_Event;                  /* '<S3>/Error_Event' */
  real_T Error_Indication;             /* '<S3>/Error_Indication' */
  real_T current_out;                  /* '<S22>/current_system [mA]' */
  real_T y[12];                        /* '<S18>/MATLAB Function' */
  real_T bat_modus;                    /* '<S6>/Embedded MATLAB Function' */
  real32_T DataTypeConversion;         /* '<S23>/Data Type Conversion' */
  real32_T SoC_Kalman_;                /* '<S23>/SoC_Kalman_%' */
  uint16_T DataTypeConversion_f;       /* '<S6>/Data Type Conversion' */
  uint16_T DataTypeConversion1;        /* '<S6>/Data Type Conversion1' */
} BlockIO_Batterymodel_HiL;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[12];         /* '<S18>/Unit Delay' */
  real_T UnitDelay1_DSTATE[12];        /* '<S20>/Unit Delay1' */
  real_T UnitDelay_DSTATE_n[12];       /* '<S20>/Unit Delay' */
  real_T UnitDelay_DSTATE_l[12];       /* '<S7>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE[12];/* '<S17>/Discrete-Time Integrator' */
  real_T deltaSoC_DWORK1;              /* '<S23>/delta SoC' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S11>/FromWs' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S18>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S18>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S18>/Scope4' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S20>/Scope1' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_o;                    /* '<S20>/Scope4' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_i;                    /* '<S18>/Scope1' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S11>/FromWs' */

  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S17>/Discrete-Time Integrator' */
} D_Work_Batterymodel_HiL;

/* Backward compatible GRT Identifiers */
#define rtB                            Batterymodel_HiL_B
#define BlockIO                        BlockIO_Batterymodel_HiL
#define rtXdot                         Batterymodel_HiL_Xdot
#define StateDerivatives               StateDerivatives_Batterymodel_HiL
#define tXdis                          Batterymodel_HiL_Xdis
#define StateDisabled                  StateDisabled_Batterymodel_HiL
#define rtP                            Batterymodel_HiL_P
#define Parameters                     Parameters_Batterymodel_HiL
#define rtDWork                        Batterymodel_HiL_DWork
#define D_Work                         D_Work_Batterymodel_HiL

/* Parameters (auto storage) */
struct Parameters_Batterymodel_HiL_ {
  real_T ChargeSwitch_Value;           /* Expression: ChargeSwitch
                                        * Referenced by: '<S10>/ChargeSwitch'
                                        */
  real_T ChargeCurrentA1_Value;        /* Expression: DischargeCurrent
                                        * Referenced by: '<S10>/ChargeCurrent[A]1'
                                        */
  real_T ChargeCurrentA_Value;         /* Expression: ChargeCurrent
                                        * Referenced by: '<S10>/ChargeCurrent[A]'
                                        */
  real_T Constant1_Value[12];          /* Expression: ones(CellNo,1)
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Temp_01_P1_Size[2];           /* Computed Parameter: Temp_01_P1_Size
                                        * Referenced by: '<S15>/Temp_01'
                                        */
  real_T Temp_01_P1[16];               /* Computed Parameter: Temp_01_P1
                                        * Referenced by: '<S15>/Temp_01'
                                        */
  real_T Temp_01_P2_Size[2];           /* Computed Parameter: Temp_01_P2_Size
                                        * Referenced by: '<S15>/Temp_01'
                                        */
  real_T Temp_01_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_01'
                                        */
  real_T Temp_02_P1_Size[2];           /* Computed Parameter: Temp_02_P1_Size
                                        * Referenced by: '<S15>/Temp_02'
                                        */
  real_T Temp_02_P1[16];               /* Computed Parameter: Temp_02_P1
                                        * Referenced by: '<S15>/Temp_02'
                                        */
  real_T Temp_02_P2_Size[2];           /* Computed Parameter: Temp_02_P2_Size
                                        * Referenced by: '<S15>/Temp_02'
                                        */
  real_T Temp_02_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_02'
                                        */
  real_T Temp_03_P1_Size[2];           /* Computed Parameter: Temp_03_P1_Size
                                        * Referenced by: '<S15>/Temp_03'
                                        */
  real_T Temp_03_P1[16];               /* Computed Parameter: Temp_03_P1
                                        * Referenced by: '<S15>/Temp_03'
                                        */
  real_T Temp_03_P2_Size[2];           /* Computed Parameter: Temp_03_P2_Size
                                        * Referenced by: '<S15>/Temp_03'
                                        */
  real_T Temp_03_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_03'
                                        */
  real_T Temp_04_P1_Size[2];           /* Computed Parameter: Temp_04_P1_Size
                                        * Referenced by: '<S15>/Temp_04'
                                        */
  real_T Temp_04_P1[16];               /* Computed Parameter: Temp_04_P1
                                        * Referenced by: '<S15>/Temp_04'
                                        */
  real_T Temp_04_P2_Size[2];           /* Computed Parameter: Temp_04_P2_Size
                                        * Referenced by: '<S15>/Temp_04'
                                        */
  real_T Temp_04_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_04'
                                        */
  real_T Temp_05_P1_Size[2];           /* Computed Parameter: Temp_05_P1_Size
                                        * Referenced by: '<S15>/Temp_05'
                                        */
  real_T Temp_05_P1[16];               /* Computed Parameter: Temp_05_P1
                                        * Referenced by: '<S15>/Temp_05'
                                        */
  real_T Temp_05_P2_Size[2];           /* Computed Parameter: Temp_05_P2_Size
                                        * Referenced by: '<S15>/Temp_05'
                                        */
  real_T Temp_05_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_05'
                                        */
  real_T Temp_06_P1_Size[2];           /* Computed Parameter: Temp_06_P1_Size
                                        * Referenced by: '<S15>/Temp_06'
                                        */
  real_T Temp_06_P1[16];               /* Computed Parameter: Temp_06_P1
                                        * Referenced by: '<S15>/Temp_06'
                                        */
  real_T Temp_06_P2_Size[2];           /* Computed Parameter: Temp_06_P2_Size
                                        * Referenced by: '<S15>/Temp_06'
                                        */
  real_T Temp_06_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_06'
                                        */
  real_T Temp_07_P1_Size[2];           /* Computed Parameter: Temp_07_P1_Size
                                        * Referenced by: '<S15>/Temp_07'
                                        */
  real_T Temp_07_P1[16];               /* Computed Parameter: Temp_07_P1
                                        * Referenced by: '<S15>/Temp_07'
                                        */
  real_T Temp_07_P2_Size[2];           /* Computed Parameter: Temp_07_P2_Size
                                        * Referenced by: '<S15>/Temp_07'
                                        */
  real_T Temp_07_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_07'
                                        */
  real_T Temp_08_P1_Size[2];           /* Computed Parameter: Temp_08_P1_Size
                                        * Referenced by: '<S15>/Temp_08'
                                        */
  real_T Temp_08_P1[16];               /* Computed Parameter: Temp_08_P1
                                        * Referenced by: '<S15>/Temp_08'
                                        */
  real_T Temp_08_P2_Size[2];           /* Computed Parameter: Temp_08_P2_Size
                                        * Referenced by: '<S15>/Temp_08'
                                        */
  real_T Temp_08_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_08'
                                        */
  real_T Temp_09_P1_Size[2];           /* Computed Parameter: Temp_09_P1_Size
                                        * Referenced by: '<S15>/Temp_09'
                                        */
  real_T Temp_09_P1[16];               /* Computed Parameter: Temp_09_P1
                                        * Referenced by: '<S15>/Temp_09'
                                        */
  real_T Temp_09_P2_Size[2];           /* Computed Parameter: Temp_09_P2_Size
                                        * Referenced by: '<S15>/Temp_09'
                                        */
  real_T Temp_09_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_09'
                                        */
  real_T Temp_10_P1_Size[2];           /* Computed Parameter: Temp_10_P1_Size
                                        * Referenced by: '<S15>/Temp_10'
                                        */
  real_T Temp_10_P1[16];               /* Computed Parameter: Temp_10_P1
                                        * Referenced by: '<S15>/Temp_10'
                                        */
  real_T Temp_10_P2_Size[2];           /* Computed Parameter: Temp_10_P2_Size
                                        * Referenced by: '<S15>/Temp_10'
                                        */
  real_T Temp_10_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_10'
                                        */
  real_T Temp_11_P1_Size[2];           /* Computed Parameter: Temp_11_P1_Size
                                        * Referenced by: '<S15>/Temp_11'
                                        */
  real_T Temp_11_P1[16];               /* Computed Parameter: Temp_11_P1
                                        * Referenced by: '<S15>/Temp_11'
                                        */
  real_T Temp_11_P2_Size[2];           /* Computed Parameter: Temp_11_P2_Size
                                        * Referenced by: '<S15>/Temp_11'
                                        */
  real_T Temp_11_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_11'
                                        */
  real_T Temp_12_P1_Size[2];           /* Computed Parameter: Temp_12_P1_Size
                                        * Referenced by: '<S15>/Temp_12'
                                        */
  real_T Temp_12_P1[16];               /* Computed Parameter: Temp_12_P1
                                        * Referenced by: '<S15>/Temp_12'
                                        */
  real_T Temp_12_P2_Size[2];           /* Computed Parameter: Temp_12_P2_Size
                                        * Referenced by: '<S15>/Temp_12'
                                        */
  real_T Temp_12_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S15>/Temp_12'
                                        */
  real_T Curr_01_P1_Size[2];           /* Computed Parameter: Curr_01_P1_Size
                                        * Referenced by: '<S14>/Curr_01'
                                        */
  real_T Curr_01_P1[16];               /* Computed Parameter: Curr_01_P1
                                        * Referenced by: '<S14>/Curr_01'
                                        */
  real_T Curr_01_P2_Size[2];           /* Computed Parameter: Curr_01_P2_Size
                                        * Referenced by: '<S14>/Curr_01'
                                        */
  real_T Curr_01_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_01'
                                        */
  real_T Curr_02_P1_Size[2];           /* Computed Parameter: Curr_02_P1_Size
                                        * Referenced by: '<S14>/Curr_02'
                                        */
  real_T Curr_02_P1[16];               /* Computed Parameter: Curr_02_P1
                                        * Referenced by: '<S14>/Curr_02'
                                        */
  real_T Curr_02_P2_Size[2];           /* Computed Parameter: Curr_02_P2_Size
                                        * Referenced by: '<S14>/Curr_02'
                                        */
  real_T Curr_02_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_02'
                                        */
  real_T Curr_03_P1_Size[2];           /* Computed Parameter: Curr_03_P1_Size
                                        * Referenced by: '<S14>/Curr_03'
                                        */
  real_T Curr_03_P1[16];               /* Computed Parameter: Curr_03_P1
                                        * Referenced by: '<S14>/Curr_03'
                                        */
  real_T Curr_03_P2_Size[2];           /* Computed Parameter: Curr_03_P2_Size
                                        * Referenced by: '<S14>/Curr_03'
                                        */
  real_T Curr_03_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_03'
                                        */
  real_T Curr_04_P1_Size[2];           /* Computed Parameter: Curr_04_P1_Size
                                        * Referenced by: '<S14>/Curr_04'
                                        */
  real_T Curr_04_P1[16];               /* Computed Parameter: Curr_04_P1
                                        * Referenced by: '<S14>/Curr_04'
                                        */
  real_T Curr_04_P2_Size[2];           /* Computed Parameter: Curr_04_P2_Size
                                        * Referenced by: '<S14>/Curr_04'
                                        */
  real_T Curr_04_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_04'
                                        */
  real_T Curr_05_P1_Size[2];           /* Computed Parameter: Curr_05_P1_Size
                                        * Referenced by: '<S14>/Curr_05'
                                        */
  real_T Curr_05_P1[16];               /* Computed Parameter: Curr_05_P1
                                        * Referenced by: '<S14>/Curr_05'
                                        */
  real_T Curr_05_P2_Size[2];           /* Computed Parameter: Curr_05_P2_Size
                                        * Referenced by: '<S14>/Curr_05'
                                        */
  real_T Curr_05_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_05'
                                        */
  real_T Curr_06_P1_Size[2];           /* Computed Parameter: Curr_06_P1_Size
                                        * Referenced by: '<S14>/Curr_06'
                                        */
  real_T Curr_06_P1[16];               /* Computed Parameter: Curr_06_P1
                                        * Referenced by: '<S14>/Curr_06'
                                        */
  real_T Curr_06_P2_Size[2];           /* Computed Parameter: Curr_06_P2_Size
                                        * Referenced by: '<S14>/Curr_06'
                                        */
  real_T Curr_06_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_06'
                                        */
  real_T Curr_07_P1_Size[2];           /* Computed Parameter: Curr_07_P1_Size
                                        * Referenced by: '<S14>/Curr_07'
                                        */
  real_T Curr_07_P1[16];               /* Computed Parameter: Curr_07_P1
                                        * Referenced by: '<S14>/Curr_07'
                                        */
  real_T Curr_07_P2_Size[2];           /* Computed Parameter: Curr_07_P2_Size
                                        * Referenced by: '<S14>/Curr_07'
                                        */
  real_T Curr_07_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_07'
                                        */
  real_T Curr_08_P1_Size[2];           /* Computed Parameter: Curr_08_P1_Size
                                        * Referenced by: '<S14>/Curr_08'
                                        */
  real_T Curr_08_P1[16];               /* Computed Parameter: Curr_08_P1
                                        * Referenced by: '<S14>/Curr_08'
                                        */
  real_T Curr_08_P2_Size[2];           /* Computed Parameter: Curr_08_P2_Size
                                        * Referenced by: '<S14>/Curr_08'
                                        */
  real_T Curr_08_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_08'
                                        */
  real_T Curr_09_P1_Size[2];           /* Computed Parameter: Curr_09_P1_Size
                                        * Referenced by: '<S14>/Curr_09'
                                        */
  real_T Curr_09_P1[16];               /* Computed Parameter: Curr_09_P1
                                        * Referenced by: '<S14>/Curr_09'
                                        */
  real_T Curr_09_P2_Size[2];           /* Computed Parameter: Curr_09_P2_Size
                                        * Referenced by: '<S14>/Curr_09'
                                        */
  real_T Curr_09_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_09'
                                        */
  real_T Curr_10_P1_Size[2];           /* Computed Parameter: Curr_10_P1_Size
                                        * Referenced by: '<S14>/Curr_10'
                                        */
  real_T Curr_10_P1[16];               /* Computed Parameter: Curr_10_P1
                                        * Referenced by: '<S14>/Curr_10'
                                        */
  real_T Curr_10_P2_Size[2];           /* Computed Parameter: Curr_10_P2_Size
                                        * Referenced by: '<S14>/Curr_10'
                                        */
  real_T Curr_10_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_10'
                                        */
  real_T Curr_11_P1_Size[2];           /* Computed Parameter: Curr_11_P1_Size
                                        * Referenced by: '<S14>/Curr_11'
                                        */
  real_T Curr_11_P1[16];               /* Computed Parameter: Curr_11_P1
                                        * Referenced by: '<S14>/Curr_11'
                                        */
  real_T Curr_11_P2_Size[2];           /* Computed Parameter: Curr_11_P2_Size
                                        * Referenced by: '<S14>/Curr_11'
                                        */
  real_T Curr_11_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_11'
                                        */
  real_T Curr_12_P1_Size[2];           /* Computed Parameter: Curr_12_P1_Size
                                        * Referenced by: '<S14>/Curr_12'
                                        */
  real_T Curr_12_P1[16];               /* Computed Parameter: Curr_12_P1
                                        * Referenced by: '<S14>/Curr_12'
                                        */
  real_T Curr_12_P2_Size[2];           /* Computed Parameter: Curr_12_P2_Size
                                        * Referenced by: '<S14>/Curr_12'
                                        */
  real_T Curr_12_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S14>/Curr_12'
                                        */
  real_T bat_modus_P1_Size[2];         /* Computed Parameter: bat_modus_P1_Size
                                        * Referenced by: '<S6>/bat_modus'
                                        */
  real_T bat_modus_P1[16];             /* Computed Parameter: bat_modus_P1
                                        * Referenced by: '<S6>/bat_modus'
                                        */
  real_T bat_modus_P2_Size[2];         /* Computed Parameter: bat_modus_P2_Size
                                        * Referenced by: '<S6>/bat_modus'
                                        */
  real_T bat_modus_P2;                 /* Expression: OutportID
                                        * Referenced by: '<S6>/bat_modus'
                                        */
  real_T currentmA_P1_Size[2];         /* Computed Parameter: currentmA_P1_Size
                                        * Referenced by: '<S6>/current [mA]'
                                        */
  real_T currentmA_P1[16];             /* Computed Parameter: currentmA_P1
                                        * Referenced by: '<S6>/current [mA]'
                                        */
  real_T currentmA_P2_Size[2];         /* Computed Parameter: currentmA_P2_Size
                                        * Referenced by: '<S6>/current [mA]'
                                        */
  real_T currentmA_P2;                 /* Expression: OutportID
                                        * Referenced by: '<S6>/current [mA]'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: CellNo
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Volt_01_P1_Size[2];           /* Computed Parameter: Volt_01_P1_Size
                                        * Referenced by: '<S13>/Volt_01'
                                        */
  real_T Volt_01_P1[16];               /* Computed Parameter: Volt_01_P1
                                        * Referenced by: '<S13>/Volt_01'
                                        */
  real_T Volt_01_P2_Size[2];           /* Computed Parameter: Volt_01_P2_Size
                                        * Referenced by: '<S13>/Volt_01'
                                        */
  real_T Volt_01_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_01'
                                        */
  real_T Volt_02_P1_Size[2];           /* Computed Parameter: Volt_02_P1_Size
                                        * Referenced by: '<S13>/Volt_02'
                                        */
  real_T Volt_02_P1[16];               /* Computed Parameter: Volt_02_P1
                                        * Referenced by: '<S13>/Volt_02'
                                        */
  real_T Volt_02_P2_Size[2];           /* Computed Parameter: Volt_02_P2_Size
                                        * Referenced by: '<S13>/Volt_02'
                                        */
  real_T Volt_02_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_02'
                                        */
  real_T Volt_03_P1_Size[2];           /* Computed Parameter: Volt_03_P1_Size
                                        * Referenced by: '<S13>/Volt_03'
                                        */
  real_T Volt_03_P1[16];               /* Computed Parameter: Volt_03_P1
                                        * Referenced by: '<S13>/Volt_03'
                                        */
  real_T Volt_03_P2_Size[2];           /* Computed Parameter: Volt_03_P2_Size
                                        * Referenced by: '<S13>/Volt_03'
                                        */
  real_T Volt_03_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_03'
                                        */
  real_T Volt_04_P1_Size[2];           /* Computed Parameter: Volt_04_P1_Size
                                        * Referenced by: '<S13>/Volt_04'
                                        */
  real_T Volt_04_P1[16];               /* Computed Parameter: Volt_04_P1
                                        * Referenced by: '<S13>/Volt_04'
                                        */
  real_T Volt_04_P2_Size[2];           /* Computed Parameter: Volt_04_P2_Size
                                        * Referenced by: '<S13>/Volt_04'
                                        */
  real_T Volt_04_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_04'
                                        */
  real_T Volt_05_P1_Size[2];           /* Computed Parameter: Volt_05_P1_Size
                                        * Referenced by: '<S13>/Volt_05'
                                        */
  real_T Volt_05_P1[16];               /* Computed Parameter: Volt_05_P1
                                        * Referenced by: '<S13>/Volt_05'
                                        */
  real_T Volt_05_P2_Size[2];           /* Computed Parameter: Volt_05_P2_Size
                                        * Referenced by: '<S13>/Volt_05'
                                        */
  real_T Volt_05_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_05'
                                        */
  real_T Volt_06_P1_Size[2];           /* Computed Parameter: Volt_06_P1_Size
                                        * Referenced by: '<S13>/Volt_06'
                                        */
  real_T Volt_06_P1[16];               /* Computed Parameter: Volt_06_P1
                                        * Referenced by: '<S13>/Volt_06'
                                        */
  real_T Volt_06_P2_Size[2];           /* Computed Parameter: Volt_06_P2_Size
                                        * Referenced by: '<S13>/Volt_06'
                                        */
  real_T Volt_06_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_06'
                                        */
  real_T Volt_07_P1_Size[2];           /* Computed Parameter: Volt_07_P1_Size
                                        * Referenced by: '<S13>/Volt_07'
                                        */
  real_T Volt_07_P1[16];               /* Computed Parameter: Volt_07_P1
                                        * Referenced by: '<S13>/Volt_07'
                                        */
  real_T Volt_07_P2_Size[2];           /* Computed Parameter: Volt_07_P2_Size
                                        * Referenced by: '<S13>/Volt_07'
                                        */
  real_T Volt_07_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_07'
                                        */
  real_T Volt_08_P1_Size[2];           /* Computed Parameter: Volt_08_P1_Size
                                        * Referenced by: '<S13>/Volt_08'
                                        */
  real_T Volt_08_P1[16];               /* Computed Parameter: Volt_08_P1
                                        * Referenced by: '<S13>/Volt_08'
                                        */
  real_T Volt_08_P2_Size[2];           /* Computed Parameter: Volt_08_P2_Size
                                        * Referenced by: '<S13>/Volt_08'
                                        */
  real_T Volt_08_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_08'
                                        */
  real_T Volt_09_P1_Size[2];           /* Computed Parameter: Volt_09_P1_Size
                                        * Referenced by: '<S13>/Volt_09'
                                        */
  real_T Volt_09_P1[16];               /* Computed Parameter: Volt_09_P1
                                        * Referenced by: '<S13>/Volt_09'
                                        */
  real_T Volt_09_P2_Size[2];           /* Computed Parameter: Volt_09_P2_Size
                                        * Referenced by: '<S13>/Volt_09'
                                        */
  real_T Volt_09_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_09'
                                        */
  real_T Volt_10_P1_Size[2];           /* Computed Parameter: Volt_10_P1_Size
                                        * Referenced by: '<S13>/Volt_10'
                                        */
  real_T Volt_10_P1[16];               /* Computed Parameter: Volt_10_P1
                                        * Referenced by: '<S13>/Volt_10'
                                        */
  real_T Volt_10_P2_Size[2];           /* Computed Parameter: Volt_10_P2_Size
                                        * Referenced by: '<S13>/Volt_10'
                                        */
  real_T Volt_10_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_10'
                                        */
  real_T Volt_11_P1_Size[2];           /* Computed Parameter: Volt_11_P1_Size
                                        * Referenced by: '<S13>/Volt_11'
                                        */
  real_T Volt_11_P1[16];               /* Computed Parameter: Volt_11_P1
                                        * Referenced by: '<S13>/Volt_11'
                                        */
  real_T Volt_11_P2_Size[2];           /* Computed Parameter: Volt_11_P2_Size
                                        * Referenced by: '<S13>/Volt_11'
                                        */
  real_T Volt_11_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_11'
                                        */
  real_T Volt_12_P1_Size[2];           /* Computed Parameter: Volt_12_P1_Size
                                        * Referenced by: '<S13>/Volt_12'
                                        */
  real_T Volt_12_P1[16];               /* Computed Parameter: Volt_12_P1
                                        * Referenced by: '<S13>/Volt_12'
                                        */
  real_T Volt_12_P2_Size[2];           /* Computed Parameter: Volt_12_P2_Size
                                        * Referenced by: '<S13>/Volt_12'
                                        */
  real_T Volt_12_P2;                   /* Expression: OutportID
                                        * Referenced by: '<S13>/Volt_12'
                                        */
  real_T voltagemV_P1_Size[2];         /* Computed Parameter: voltagemV_P1_Size
                                        * Referenced by: '<S6>/voltage [mV]'
                                        */
  real_T voltagemV_P1[16];             /* Computed Parameter: voltagemV_P1
                                        * Referenced by: '<S6>/voltage [mV]'
                                        */
  real_T voltagemV_P2_Size[2];         /* Computed Parameter: voltagemV_P2_Size
                                        * Referenced by: '<S6>/voltage [mV]'
                                        */
  real_T voltagemV_P2;                 /* Expression: OutportID
                                        * Referenced by: '<S6>/voltage [mV]'
                                        */
  real_T C_diff_Value;                 /* Expression: 1./C_diff
                                        * Referenced by: '<S20>/1.//C_diff'
                                        */
  real_T Vektorize_Gain[12];           /* Expression: ones(1,n_cells)
                                        * Referenced by: '<S16>/Vektorize'
                                        */
  real_T Vektorize_Gain_o[12];         /* Expression: ones(1,12)
                                        * Referenced by: '<S18>/Vektorize'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S18>/Unit Delay'
                                        */
  real_T R_balance_Value[12];          /* Expression: 10*ones(1,12)
                                        * Referenced by: '<S16>/R_balance'
                                        */
  real_T bala_01_P1_Size[2];           /* Computed Parameter: bala_01_P1_Size
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_01_P1[16];               /* Computed Parameter: bala_01_P1
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_01_P2_Size[2];           /* Computed Parameter: bala_01_P2_Size
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_01_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_01_P3_Size[2];           /* Computed Parameter: bala_01_P3_Size
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_01_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_01_P4_Size[2];           /* Computed Parameter: bala_01_P4_Size
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_01_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_01'
                                        */
  real_T bala_02_P1_Size[2];           /* Computed Parameter: bala_02_P1_Size
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_02_P1[16];               /* Computed Parameter: bala_02_P1
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_02_P2_Size[2];           /* Computed Parameter: bala_02_P2_Size
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_02_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_02_P3_Size[2];           /* Computed Parameter: bala_02_P3_Size
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_02_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_02_P4_Size[2];           /* Computed Parameter: bala_02_P4_Size
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_02_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_02'
                                        */
  real_T bala_03_P1_Size[2];           /* Computed Parameter: bala_03_P1_Size
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_03_P1[16];               /* Computed Parameter: bala_03_P1
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_03_P2_Size[2];           /* Computed Parameter: bala_03_P2_Size
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_03_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_03_P3_Size[2];           /* Computed Parameter: bala_03_P3_Size
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_03_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_03_P4_Size[2];           /* Computed Parameter: bala_03_P4_Size
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_03_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_03'
                                        */
  real_T bala_04_P1_Size[2];           /* Computed Parameter: bala_04_P1_Size
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_04_P1[16];               /* Computed Parameter: bala_04_P1
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_04_P2_Size[2];           /* Computed Parameter: bala_04_P2_Size
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_04_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_04_P3_Size[2];           /* Computed Parameter: bala_04_P3_Size
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_04_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_04_P4_Size[2];           /* Computed Parameter: bala_04_P4_Size
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_04_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_04'
                                        */
  real_T bala_05_P1_Size[2];           /* Computed Parameter: bala_05_P1_Size
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_05_P1[16];               /* Computed Parameter: bala_05_P1
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_05_P2_Size[2];           /* Computed Parameter: bala_05_P2_Size
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_05_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_05_P3_Size[2];           /* Computed Parameter: bala_05_P3_Size
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_05_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_05_P4_Size[2];           /* Computed Parameter: bala_05_P4_Size
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_05_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_05'
                                        */
  real_T bala_06_P1_Size[2];           /* Computed Parameter: bala_06_P1_Size
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_06_P1[16];               /* Computed Parameter: bala_06_P1
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_06_P2_Size[2];           /* Computed Parameter: bala_06_P2_Size
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_06_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_06_P3_Size[2];           /* Computed Parameter: bala_06_P3_Size
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_06_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_06_P4_Size[2];           /* Computed Parameter: bala_06_P4_Size
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_06_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_06'
                                        */
  real_T bala_07_P1_Size[2];           /* Computed Parameter: bala_07_P1_Size
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_07_P1[16];               /* Computed Parameter: bala_07_P1
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_07_P2_Size[2];           /* Computed Parameter: bala_07_P2_Size
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_07_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_07_P3_Size[2];           /* Computed Parameter: bala_07_P3_Size
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_07_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_07_P4_Size[2];           /* Computed Parameter: bala_07_P4_Size
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_07_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_07'
                                        */
  real_T bala_08_P1_Size[2];           /* Computed Parameter: bala_08_P1_Size
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_08_P1[16];               /* Computed Parameter: bala_08_P1
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_08_P2_Size[2];           /* Computed Parameter: bala_08_P2_Size
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_08_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_08_P3_Size[2];           /* Computed Parameter: bala_08_P3_Size
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_08_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_08_P4_Size[2];           /* Computed Parameter: bala_08_P4_Size
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_08_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_08'
                                        */
  real_T bala_09_P1_Size[2];           /* Computed Parameter: bala_09_P1_Size
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_09_P1[16];               /* Computed Parameter: bala_09_P1
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_09_P2_Size[2];           /* Computed Parameter: bala_09_P2_Size
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_09_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_09_P3_Size[2];           /* Computed Parameter: bala_09_P3_Size
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_09_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_09_P4_Size[2];           /* Computed Parameter: bala_09_P4_Size
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_09_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_09'
                                        */
  real_T bala_10_P1_Size[2];           /* Computed Parameter: bala_10_P1_Size
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_10_P1[16];               /* Computed Parameter: bala_10_P1
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_10_P2_Size[2];           /* Computed Parameter: bala_10_P2_Size
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_10_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_10_P3_Size[2];           /* Computed Parameter: bala_10_P3_Size
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_10_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_10_P4_Size[2];           /* Computed Parameter: bala_10_P4_Size
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_10_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_10'
                                        */
  real_T bala_11_P1_Size[2];           /* Computed Parameter: bala_11_P1_Size
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_11_P1[16];               /* Computed Parameter: bala_11_P1
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_11_P2_Size[2];           /* Computed Parameter: bala_11_P2_Size
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_11_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_11_P3_Size[2];           /* Computed Parameter: bala_11_P3_Size
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_11_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_11_P4_Size[2];           /* Computed Parameter: bala_11_P4_Size
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_11_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_11'
                                        */
  real_T bala_12_P1_Size[2];           /* Computed Parameter: bala_12_P1_Size
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T bala_12_P1[16];               /* Computed Parameter: bala_12_P1
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T bala_12_P2_Size[2];           /* Computed Parameter: bala_12_P2_Size
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T bala_12_P2;                   /* Expression: InportID
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T bala_12_P3_Size[2];           /* Computed Parameter: bala_12_P3_Size
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T bala_12_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T bala_12_P4_Size[2];           /* Computed Parameter: bala_12_P4_Size
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T bala_12_P4;                   /* Expression: constValue
                                        * Referenced by: '<S4>/bala_12'
                                        */
  real_T Gain_Gain;                    /* Expression: Ts
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T C_diffR_diff_Value;           /* Expression: 1./(C_diff.*R_diff)
                                        * Referenced by: '<S20>/1//C_diff*R_diff)'
                                        */
  real_T UnitDelay1_X0;                /* Expression: 0
                                        * Referenced by: '<S20>/Unit Delay1'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: Ts
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real_T UnitDelay_X0_n;               /* Expression: 0
                                        * Referenced by: '<S20>/Unit Delay'
                                        */
  real_T R_ctR_i_Value;                /* Expression: R_ct + R_i
                                        * Referenced by: '<S20>/R_ct+R_i'
                                        */
  real_T UnitDelay_X0_k;               /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 100
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T poles_soc_Value[5];           /* Expression: poles_soc
                                        * Referenced by: '<S18>/ poles_soc'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1000
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Q_0_Gain[12];                 /* Expression: 1./Q_0
                                        * Referenced by: '<S17>/1//Q_0'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S17>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real_T InitSoC_Value[12];            /* Expression: SoCinitCells
                                        * Referenced by: '<S5>/Init SoC [%]'
                                        */
  real_T u11_Gain;                     /* Expression: 100
                                        * Referenced by: '<S7>/0.01->1%'
                                        */
  real_T charge_currentA_Gain;         /* Expression: 1
                                        * Referenced by: '<S22>/charge_current [A]'
                                        */
  real_T charge_currentmA_Gain;        /* Expression: 1000
                                        * Referenced by: '<S22>/charge_current [mA]'
                                        */
  real_T bat_mode_system_P1_Size[2];   /* Computed Parameter: bat_mode_system_P1_Size
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T bat_mode_system_P1[16];       /* Computed Parameter: bat_mode_system_P1
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T bat_mode_system_P2_Size[2];   /* Computed Parameter: bat_mode_system_P2_Size
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T bat_mode_system_P2;           /* Expression: InportID
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T bat_mode_system_P3_Size[2];   /* Computed Parameter: bat_mode_system_P3_Size
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T bat_mode_system_P3;           /* Expression: b_useConstant
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T bat_mode_system_P4_Size[2];   /* Computed Parameter: bat_mode_system_P4_Size
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T bat_mode_system_P4;           /* Expression: constValue
                                        * Referenced by: '<S22>/bat_mode_system'
                                        */
  real_T current_system_P1_Size[2];    /* Computed Parameter: current_system_P1_Size
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_system_P1[16];        /* Computed Parameter: current_system_P1
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_system_P2_Size[2];    /* Computed Parameter: current_system_P2_Size
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_system_P2;            /* Expression: InportID
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_system_P3_Size[2];    /* Computed Parameter: current_system_P3_Size
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_system_P3;            /* Expression: b_useConstant
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_system_P4_Size[2];    /* Computed Parameter: current_system_P4_Size
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_system_P4;            /* Expression: constValue
                                        * Referenced by: '<S22>/current_system'
                                        */
  real_T current_systemA_Gain;         /* Expression: 1/1000
                                        * Referenced by: '<S22>/current_system [A]'
                                        */
  real_T Cellno_Value;                 /* Expression: CellNo
                                        * Referenced by: '<S23>/Cellno'
                                        */
  real_T SoC_Kalman_P1_Size[2];        /* Computed Parameter: SoC_Kalman_P1_Size
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T SoC_Kalman_P1[16];            /* Computed Parameter: SoC_Kalman_P1
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T SoC_Kalman_P2_Size[2];        /* Computed Parameter: SoC_Kalman_P2_Size
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T SoC_Kalman_P2;                /* Expression: InportID
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T SoC_Kalman_P3_Size[2];        /* Computed Parameter: SoC_Kalman_P3_Size
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T SoC_Kalman_P3;                /* Expression: b_useConstant
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T SoC_Kalman_P4_Size[2];        /* Computed Parameter: SoC_Kalman_P4_Size
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T SoC_Kalman_P4;                /* Expression: constValue
                                        * Referenced by: '<S23>/SoC_Kalman'
                                        */
  real_T bat_voltagemV_Gain;           /* Expression: 1000
                                        * Referenced by: '<S21>/bat_voltage [mV]'
                                        */
  real_T voltage_system_P1_Size[2];    /* Computed Parameter: voltage_system_P1_Size
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_system_P1[16];        /* Computed Parameter: voltage_system_P1
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_system_P2_Size[2];    /* Computed Parameter: voltage_system_P2_Size
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_system_P2;            /* Expression: InportID
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_system_P3_Size[2];    /* Computed Parameter: voltage_system_P3_Size
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_system_P3;            /* Expression: b_useConstant
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_system_P4_Size[2];    /* Computed Parameter: voltage_system_P4_Size
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_system_P4;            /* Expression: constValue
                                        * Referenced by: '<S21>/voltage_system'
                                        */
  real_T voltage_systemmV_Gain;        /* Expression: 1
                                        * Referenced by: '<S21>/voltage_system [mV]'
                                        */
  real_T voltage_systemV_Gain;         /* Expression: 1/1000
                                        * Referenced by: '<S21>/voltage_system [V]'
                                        */
  real_T InitAmbientTemperatureK_Value[12];/* Expression: Tcells
                                            * Referenced by: '<S5>/Init Ambient Temperature [K]'
                                            */
  real_T Mod_CAN_RS232_Com_P1_Size[2]; /* Computed Parameter: Mod_CAN_RS232_Com_P1_Size
                                        * Referenced by: '<S9>/Mod_CAN_RS232_Com'
                                        */
  real_T Mod_CAN_RS232_Com_P1[16];     /* Computed Parameter: Mod_CAN_RS232_Com_P1
                                        * Referenced by: '<S9>/Mod_CAN_RS232_Com'
                                        */
  real_T Mod_CAN_RS232_Com_P2_Size[2]; /* Computed Parameter: Mod_CAN_RS232_Com_P2_Size
                                        * Referenced by: '<S9>/Mod_CAN_RS232_Com'
                                        */
  real_T Mod_CAN_RS232_Com_P2;         /* Expression: OutportID
                                        * Referenced by: '<S9>/Mod_CAN_RS232_Com'
                                        */
  real_T Mod_CAN_RS232_Value;          /* Expression: 0
                                        * Referenced by: '<S9>/Mod_CAN_RS232'
                                        */
  real_T CellT01_P1_Size[2];           /* Computed Parameter: CellT01_P1_Size
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT01_P1[16];               /* Computed Parameter: CellT01_P1
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT01_P2_Size[2];           /* Computed Parameter: CellT01_P2_Size
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT01_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT01_P3_Size[2];           /* Computed Parameter: CellT01_P3_Size
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT01_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT01_P4_Size[2];           /* Computed Parameter: CellT01_P4_Size
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT01_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT01'
                                        */
  real_T CellT02_P1_Size[2];           /* Computed Parameter: CellT02_P1_Size
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT02_P1[16];               /* Computed Parameter: CellT02_P1
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT02_P2_Size[2];           /* Computed Parameter: CellT02_P2_Size
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT02_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT02_P3_Size[2];           /* Computed Parameter: CellT02_P3_Size
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT02_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT02_P4_Size[2];           /* Computed Parameter: CellT02_P4_Size
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT02_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT02'
                                        */
  real_T CellT03_P1_Size[2];           /* Computed Parameter: CellT03_P1_Size
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT03_P1[16];               /* Computed Parameter: CellT03_P1
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT03_P2_Size[2];           /* Computed Parameter: CellT03_P2_Size
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT03_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT03_P3_Size[2];           /* Computed Parameter: CellT03_P3_Size
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT03_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT03_P4_Size[2];           /* Computed Parameter: CellT03_P4_Size
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT03_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT03'
                                        */
  real_T CellT04_P1_Size[2];           /* Computed Parameter: CellT04_P1_Size
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT04_P1[16];               /* Computed Parameter: CellT04_P1
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT04_P2_Size[2];           /* Computed Parameter: CellT04_P2_Size
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT04_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT04_P3_Size[2];           /* Computed Parameter: CellT04_P3_Size
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT04_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT04_P4_Size[2];           /* Computed Parameter: CellT04_P4_Size
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT04_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT04'
                                        */
  real_T CellT05_P1_Size[2];           /* Computed Parameter: CellT05_P1_Size
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT05_P1[16];               /* Computed Parameter: CellT05_P1
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT05_P2_Size[2];           /* Computed Parameter: CellT05_P2_Size
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT05_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT05_P3_Size[2];           /* Computed Parameter: CellT05_P3_Size
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT05_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT05_P4_Size[2];           /* Computed Parameter: CellT05_P4_Size
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT05_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT05'
                                        */
  real_T CellT06_P1_Size[2];           /* Computed Parameter: CellT06_P1_Size
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT06_P1[16];               /* Computed Parameter: CellT06_P1
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT06_P2_Size[2];           /* Computed Parameter: CellT06_P2_Size
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT06_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT06_P3_Size[2];           /* Computed Parameter: CellT06_P3_Size
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT06_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT06_P4_Size[2];           /* Computed Parameter: CellT06_P4_Size
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT06_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT06'
                                        */
  real_T CellT07_P1_Size[2];           /* Computed Parameter: CellT07_P1_Size
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT07_P1[16];               /* Computed Parameter: CellT07_P1
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT07_P2_Size[2];           /* Computed Parameter: CellT07_P2_Size
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT07_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT07_P3_Size[2];           /* Computed Parameter: CellT07_P3_Size
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT07_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT07_P4_Size[2];           /* Computed Parameter: CellT07_P4_Size
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT07_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT07'
                                        */
  real_T CellT08_P1_Size[2];           /* Computed Parameter: CellT08_P1_Size
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT08_P1[16];               /* Computed Parameter: CellT08_P1
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT08_P2_Size[2];           /* Computed Parameter: CellT08_P2_Size
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT08_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT08_P3_Size[2];           /* Computed Parameter: CellT08_P3_Size
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT08_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT08_P4_Size[2];           /* Computed Parameter: CellT08_P4_Size
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT08_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT08'
                                        */
  real_T CellT09_P1_Size[2];           /* Computed Parameter: CellT09_P1_Size
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT09_P1[16];               /* Computed Parameter: CellT09_P1
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT09_P2_Size[2];           /* Computed Parameter: CellT09_P2_Size
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT09_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT09_P3_Size[2];           /* Computed Parameter: CellT09_P3_Size
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT09_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT09_P4_Size[2];           /* Computed Parameter: CellT09_P4_Size
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT09_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT09'
                                        */
  real_T CellT10_P1_Size[2];           /* Computed Parameter: CellT10_P1_Size
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT10_P1[16];               /* Computed Parameter: CellT10_P1
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT10_P2_Size[2];           /* Computed Parameter: CellT10_P2_Size
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT10_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT10_P3_Size[2];           /* Computed Parameter: CellT10_P3_Size
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT10_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT10_P4_Size[2];           /* Computed Parameter: CellT10_P4_Size
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT10_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT10'
                                        */
  real_T CellT11_P1_Size[2];           /* Computed Parameter: CellT11_P1_Size
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT11_P1[16];               /* Computed Parameter: CellT11_P1
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT11_P2_Size[2];           /* Computed Parameter: CellT11_P2_Size
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT11_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT11_P3_Size[2];           /* Computed Parameter: CellT11_P3_Size
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT11_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT11_P4_Size[2];           /* Computed Parameter: CellT11_P4_Size
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT11_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT11'
                                        */
  real_T CellT12_P1_Size[2];           /* Computed Parameter: CellT12_P1_Size
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellT12_P1[16];               /* Computed Parameter: CellT12_P1
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellT12_P2_Size[2];           /* Computed Parameter: CellT12_P2_Size
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellT12_P2;                   /* Expression: InportID
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellT12_P3_Size[2];           /* Computed Parameter: CellT12_P3_Size
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellT12_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellT12_P4_Size[2];           /* Computed Parameter: CellT12_P4_Size
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellT12_P4;                   /* Expression: constValue
                                        * Referenced by: '<S1>/CellT12'
                                        */
  real_T CellV01_P1_Size[2];           /* Computed Parameter: CellV01_P1_Size
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV01_P1[16];               /* Computed Parameter: CellV01_P1
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV01_P2_Size[2];           /* Computed Parameter: CellV01_P2_Size
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV01_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV01_P3_Size[2];           /* Computed Parameter: CellV01_P3_Size
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV01_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV01_P4_Size[2];           /* Computed Parameter: CellV01_P4_Size
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV01_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV01'
                                        */
  real_T CellV02_P1_Size[2];           /* Computed Parameter: CellV02_P1_Size
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV02_P1[16];               /* Computed Parameter: CellV02_P1
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV02_P2_Size[2];           /* Computed Parameter: CellV02_P2_Size
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV02_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV02_P3_Size[2];           /* Computed Parameter: CellV02_P3_Size
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV02_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV02_P4_Size[2];           /* Computed Parameter: CellV02_P4_Size
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV02_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV02'
                                        */
  real_T CellV03_P1_Size[2];           /* Computed Parameter: CellV03_P1_Size
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV03_P1[16];               /* Computed Parameter: CellV03_P1
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV03_P2_Size[2];           /* Computed Parameter: CellV03_P2_Size
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV03_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV03_P3_Size[2];           /* Computed Parameter: CellV03_P3_Size
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV03_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV03_P4_Size[2];           /* Computed Parameter: CellV03_P4_Size
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV03_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV03'
                                        */
  real_T CellV04_P1_Size[2];           /* Computed Parameter: CellV04_P1_Size
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV04_P1[16];               /* Computed Parameter: CellV04_P1
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV04_P2_Size[2];           /* Computed Parameter: CellV04_P2_Size
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV04_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV04_P3_Size[2];           /* Computed Parameter: CellV04_P3_Size
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV04_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV04_P4_Size[2];           /* Computed Parameter: CellV04_P4_Size
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV04_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV04'
                                        */
  real_T CellV05_P1_Size[2];           /* Computed Parameter: CellV05_P1_Size
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV05_P1[16];               /* Computed Parameter: CellV05_P1
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV05_P2_Size[2];           /* Computed Parameter: CellV05_P2_Size
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV05_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV05_P3_Size[2];           /* Computed Parameter: CellV05_P3_Size
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV05_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV05_P4_Size[2];           /* Computed Parameter: CellV05_P4_Size
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV05_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV05'
                                        */
  real_T CellV06_P1_Size[2];           /* Computed Parameter: CellV06_P1_Size
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV06_P1[16];               /* Computed Parameter: CellV06_P1
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV06_P2_Size[2];           /* Computed Parameter: CellV06_P2_Size
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV06_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV06_P3_Size[2];           /* Computed Parameter: CellV06_P3_Size
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV06_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV06_P4_Size[2];           /* Computed Parameter: CellV06_P4_Size
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV06_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV06'
                                        */
  real_T CellV07_P1_Size[2];           /* Computed Parameter: CellV07_P1_Size
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV07_P1[16];               /* Computed Parameter: CellV07_P1
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV07_P2_Size[2];           /* Computed Parameter: CellV07_P2_Size
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV07_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV07_P3_Size[2];           /* Computed Parameter: CellV07_P3_Size
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV07_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV07_P4_Size[2];           /* Computed Parameter: CellV07_P4_Size
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV07_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV07'
                                        */
  real_T CellV08_P1_Size[2];           /* Computed Parameter: CellV08_P1_Size
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV08_P1[16];               /* Computed Parameter: CellV08_P1
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV08_P2_Size[2];           /* Computed Parameter: CellV08_P2_Size
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV08_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV08_P3_Size[2];           /* Computed Parameter: CellV08_P3_Size
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV08_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV08_P4_Size[2];           /* Computed Parameter: CellV08_P4_Size
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV08_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV08'
                                        */
  real_T CellV09_P1_Size[2];           /* Computed Parameter: CellV09_P1_Size
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV09_P1[16];               /* Computed Parameter: CellV09_P1
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV09_P2_Size[2];           /* Computed Parameter: CellV09_P2_Size
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV09_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV09_P3_Size[2];           /* Computed Parameter: CellV09_P3_Size
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV09_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV09_P4_Size[2];           /* Computed Parameter: CellV09_P4_Size
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV09_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV09'
                                        */
  real_T CellV10_P1_Size[2];           /* Computed Parameter: CellV10_P1_Size
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV10_P1[16];               /* Computed Parameter: CellV10_P1
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV10_P2_Size[2];           /* Computed Parameter: CellV10_P2_Size
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV10_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV10_P3_Size[2];           /* Computed Parameter: CellV10_P3_Size
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV10_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV10_P4_Size[2];           /* Computed Parameter: CellV10_P4_Size
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV10_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV10'
                                        */
  real_T CellV11_P1_Size[2];           /* Computed Parameter: CellV11_P1_Size
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV11_P1[16];               /* Computed Parameter: CellV11_P1
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV11_P2_Size[2];           /* Computed Parameter: CellV11_P2_Size
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV11_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV11_P3_Size[2];           /* Computed Parameter: CellV11_P3_Size
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV11_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV11_P4_Size[2];           /* Computed Parameter: CellV11_P4_Size
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV11_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV11'
                                        */
  real_T CellV12_P1_Size[2];           /* Computed Parameter: CellV12_P1_Size
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T CellV12_P1[16];               /* Computed Parameter: CellV12_P1
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T CellV12_P2_Size[2];           /* Computed Parameter: CellV12_P2_Size
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T CellV12_P2;                   /* Expression: InportID
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T CellV12_P3_Size[2];           /* Computed Parameter: CellV12_P3_Size
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T CellV12_P3;                   /* Expression: b_useConstant
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T CellV12_P4_Size[2];           /* Computed Parameter: CellV12_P4_Size
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T CellV12_P4;                   /* Expression: constValue
                                        * Referenced by: '<S2>/CellV12'
                                        */
  real_T Error_CellNo_P1_Size[2];      /* Computed Parameter: Error_CellNo_P1_Size
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_CellNo_P1[16];          /* Computed Parameter: Error_CellNo_P1
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_CellNo_P2_Size[2];      /* Computed Parameter: Error_CellNo_P2_Size
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_CellNo_P2;              /* Expression: InportID
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_CellNo_P3_Size[2];      /* Computed Parameter: Error_CellNo_P3_Size
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_CellNo_P3;              /* Expression: b_useConstant
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_CellNo_P4_Size[2];      /* Computed Parameter: Error_CellNo_P4_Size
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_CellNo_P4;              /* Expression: constValue
                                        * Referenced by: '<S3>/Error_CellNo'
                                        */
  real_T Error_Event_P1_Size[2];       /* Computed Parameter: Error_Event_P1_Size
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Event_P1[16];           /* Computed Parameter: Error_Event_P1
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Event_P2_Size[2];       /* Computed Parameter: Error_Event_P2_Size
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Event_P2;               /* Expression: InportID
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Event_P3_Size[2];       /* Computed Parameter: Error_Event_P3_Size
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Event_P3;               /* Expression: b_useConstant
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Event_P4_Size[2];       /* Computed Parameter: Error_Event_P4_Size
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Event_P4;               /* Expression: constValue
                                        * Referenced by: '<S3>/Error_Event'
                                        */
  real_T Error_Indication_P1_Size[2];  /* Computed Parameter: Error_Indication_P1_Size
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real_T Error_Indication_P1[16];      /* Computed Parameter: Error_Indication_P1
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real_T Error_Indication_P2_Size[2];  /* Computed Parameter: Error_Indication_P2_Size
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real_T Error_Indication_P2;          /* Expression: InportID
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real_T Error_Indication_P3_Size[2];  /* Computed Parameter: Error_Indication_P3_Size
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real_T Error_Indication_P3;          /* Expression: b_useConstant
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real_T Error_Indication_P4_Size[2];  /* Computed Parameter: Error_Indication_P4_Size
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real_T Error_Indication_P4;          /* Expression: constValue
                                        * Referenced by: '<S3>/Error_Indication'
                                        */
  real32_T SoC_Kalman__Gain;           /* Computed Parameter: SoC_Kalman__Gain
                                        * Referenced by: '<S23>/SoC_Kalman_%'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_Batterymodel_HiL {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[83];
    SimStruct *childSFunctionPtrs[83];
    struct _ssBlkInfo2 blkInfo2[83];
    struct _ssSFcnModelMethods2 methods2[83];
    struct _ssSFcnModelMethods3 methods3[83];
    struct _ssStatesInfo2 statesInfo2[83];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn23;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn24;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn26;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn27;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn28;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn29;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn30;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn31;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn32;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn33;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn34;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn35;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn36;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn37;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn38;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn39;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn40;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn41;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn42;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn43;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn44;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn45;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn46;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn47;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn48;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn49;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn50;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn51;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn52;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn53;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn54;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn55;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn56;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn57;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn58;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn59;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn60;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn61;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn62;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn63;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn64;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn65;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn66;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn67;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn68;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn69;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn70;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn71;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn72;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn73;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn74;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn75;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn76;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn77;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn78;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn79;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn80;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn81;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn82;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_Batterymodel_HiL Batterymodel_HiL_P;

/* Block signals (auto storage) */
extern BlockIO_Batterymodel_HiL Batterymodel_HiL_B;

/* Block states (auto storage) */
extern D_Work_Batterymodel_HiL Batterymodel_HiL_DWork;

/* Real-time Model object */
extern struct RT_MODEL_Batterymodel_HiL *const Batterymodel_HiL_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Batterymodel_HiL'
 * '<S1>'   : 'Batterymodel_HiL/Inports Cel_Temperatures'
 * '<S2>'   : 'Batterymodel_HiL/Inports Cell_Voltage'
 * '<S3>'   : 'Batterymodel_HiL/Inports Error'
 * '<S4>'   : 'Batterymodel_HiL/Inports_Balance '
 * '<S5>'   : 'Batterymodel_HiL/Inputs'
 * '<S6>'   : 'Batterymodel_HiL/Outports'
 * '<S7>'   : 'Batterymodel_HiL/battery'
 * '<S8>'   : 'Batterymodel_HiL/displays'
 * '<S9>'   : 'Batterymodel_HiL/Inputs/Betriebsmodus'
 * '<S10>'  : 'Batterymodel_HiL/Inputs/Charge Profile'
 * '<S11>'  : 'Batterymodel_HiL/Inputs/Charge Profile/virtuel drive cycle'
 * '<S12>'  : 'Batterymodel_HiL/Outports/Embedded MATLAB Function'
 * '<S13>'  : 'Batterymodel_HiL/Outports/Outports Zellspannungen'
 * '<S14>'  : 'Batterymodel_HiL/Outports/Outports Zellströme'
 * '<S15>'  : 'Batterymodel_HiL/Outports/Outports Zelltemperaturen'
 * '<S16>'  : 'Batterymodel_HiL/battery/Batteriemodell'
 * '<S17>'  : 'Batterymodel_HiL/battery/SoC_Cells_Modell'
 * '<S18>'  : 'Batterymodel_HiL/battery/Batteriemodell/battery_electrical_values'
 * '<S19>'  : 'Batterymodel_HiL/battery/Batteriemodell/battery_electrical_values/MATLAB Function'
 * '<S20>'  : 'Batterymodel_HiL/battery/Batteriemodell/battery_electrical_values/Subsystem_diskret'
 * '<S21>'  : 'Batterymodel_HiL/displays/Batteirespannung'
 * '<S22>'  : 'Batterymodel_HiL/displays/Batteriestrom'
 * '<S23>'  : 'Batterymodel_HiL/displays/Vergleich SoC'
 * '<S24>'  : 'Batterymodel_HiL/displays/Batteriestrom/current_system [mA]'
 */
#endif                                 /* RTW_HEADER_Batterymodel_HiL_h_ */
