/* This file was automatically generated from the LABCAR OPERATOR CAN-Code-Generation*/
#ifndef _CANCODE_H_
#define _CANCODE_H_

#include <stdint.h>

typedef unsigned char dlcType;

/* global signal analysis structure */
typedef struct
{
	uint32_t NumberOfActivations;
	double TimeOfLastActivation;
	double CurrentCycleTime;
	double MinimumCycleTime;
	double MaximumCycleTime;
	double AverageCycleTime;
	uint16_t DLC;
}
frameAnalysisSignals_struct;
// Declaration of the structures to carry the physical values of the frames:

// Structure with physical values for frame 'rtpc_bms_volt_1_4'  ID 101:
typedef struct
{
	double Signal_Cell_V1;
	double Signal_Cell_V2;
	double Signal_Cell_V3;
	double Signal_Cell_V4;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_101std_rtpc_bms_volt_1_4_struct;

// Structure with physical values for frame 'rtpc_bms_volt_5_8'  ID 102:
typedef struct
{
	double Signal_Cell_V5;
	double Signal_Cell_V6;
	double Signal_Cell_V7;
	double Signal_Cell_V8;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_102std_rtpc_bms_volt_5_8_struct;

// Structure with physical values for frame 'rtpc_bms_volt_9_12'  ID 103:
typedef struct
{
	double Signal_Cell_V10;
	double Signal_Cell_V11;
	double Signal_Cell_V12;
	double Signal_Cell_V9;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_103std_rtpc_bms_volt_9_12_struct;

// Structure with physical values for frame 'rtpc_bms_temp_1_4'  ID 111:
typedef struct
{
	double Signal_Cell_T1;
	double Signal_Cell_T2;
	double Signal_Cell_T3;
	double Signal_Cell_T4;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_111std_rtpc_bms_temp_1_4_struct;

// Structure with physical values for frame 'rtpc_bms_temp_5_8'  ID 112:
typedef struct
{
	double Signal_Cell_T5;
	double Signal_Cell_T6;
	double Signal_Cell_T7;
	double Signal_Cell_V8;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_112std_rtpc_bms_temp_5_8_struct;

// Structure with physical values for frame 'rtpc_bms_temp_9_12'  ID 113:
typedef struct
{
	double Signal_Cell_T10;
	double Signal_Cell_T11;
	double Signal_Cell_T12;
	double Signal_Cell_T9;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_113std_rtpc_bms_temp_9_12_struct;

// Structure with physical values for frame 'rtpc_bms_sammeln'  ID 131:
typedef struct
{
	double Signal_Absolute_Amp;
	double Signal_Laden;
	double Signal_Mode;
	double Signal_Total_volt;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_131std_rtpc_bms_sammeln_struct;

// Structure with physical values for frame 'bms_rtcp_volt_1_4'  ID 201:
typedef struct
{
	double Signal_Cell_V1;
	double Signal_Cell_V2;
	double Signal_Cell_V3;
	double Signal_Cell_V4;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_201std_bms_rtcp_volt_1_4_struct;

// Structure with physical values for frame 'bms_rctp_volt_5_8'  ID 202:
typedef struct
{
	double Signal_Cell_V5;
	double Signal_Cell_V6;
	double Signal_Cell_V7;
	double Signal_Cell_V8;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_202std_bms_rctp_volt_5_8_struct;

// Structure with physical values for frame 'bms_rctp_volt_9_12'  ID 203:
typedef struct
{
	double Signal_Cell_V10;
	double Signal_Cell_V11;
	double Signal_Cell_V12;
	double Signal_Cell_V9;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_203std_bms_rctp_volt_9_12_struct;

// Structure with physical values for frame 'bms_rctp_temp_1_4'  ID 211:
typedef struct
{
	double Signal_Cell_T1;
	double Signal_Cell_T2;
	double Signal_Cell_T3;
	double Signal_Cell_T4;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_211std_bms_rctp_temp_1_4_struct;

// Structure with physical values for frame 'bms_rctp_temp_5_8'  ID 212:
typedef struct
{
	double Signal_Cell_T5;
	double Signal_Cell_T6;
	double Signal_Cell_T7;
	double Signal_Cell_T8;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_212std_bms_rctp_temp_5_8_struct;

// Structure with physical values for frame 'bms_rctp_temp_9_12'  ID 213:
typedef struct
{
	double Signal_Cell_T10;
	double Signal_Cell_T11;
	double Signal_Cell_T12;
	double Signal_Cell_T9;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_213std_bms_rctp_temp_9_12_struct;

// Structure with physical values for frame 'bms_rtcp_bal'  ID 221:
typedef struct
{
	double Signal_Cell_1;
	double Signal_Cell_10;
	double Signal_Cell_11;
	double Signal_Cell_12;
	double Signal_Cell_2;
	double Signal_Cell_3;
	double Signal_Cell_4;
	double Signal_Cell_5;
	double Signal_Cell_6;
	double Signal_Cell_7;
	double Signal_Cell_8;
	double Signal_Cell_9;
	double Signal_Reserviert_1;
	double Signal_Reserviert_2;
	double Signal_Reserviert_3;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_221std_bms_rtcp_bal_struct;

// Structure with physical values for frame 'bms_rtcp_sammeln'  ID 231:
typedef struct
{
	double Signal_Absolut_Amp;
	double Signal_Laden;
	double Signal_SoC;
	double Signal_Total_Volt;
	frameAnalysisSignals_struct Analysis_struct;
}
signals_bo0_co0_231std_bms_rtcp_sammeln_struct;



// Declaration of the prototypes for the user manipulations:


#endif // _CANCODE_H_
