/* This file was automatically generated from the LABCAR OPERATOR CAN-Code-Generation*/
// Generation of Code took: 15,625[ms];
#include <rtos.h>
#include <ixxat_can.h>
#include "cancode.h"
#include "connect.h"
#include "../a_basdef.h"

long int lround ( double x );
long long llround ( double x );
extern int rtos_log(const int priority, const char *format, ...);

enum { MODEL, MANIP_PHYS, MANIP_HEX, CONFIG_VALS };

bool partEnabled_NewDB = true; // Calibration variable: For enabling/disabling complete CAN part
bool partEnabled_NewDB_oldState = false;
const double canBaseRateInv_bo0_co0 = 1; // inverse of the base rate 1s
double internalCANTime_bo0_co0 = 0.0;
static int can_handle_board0_controller0 = -1;

// Declare CAN-Controller specific variables needed for Canalyse Tracing:
double timeArray_board0_controller0[ 10 ];
double cycleTimeArray_board0_controller0[ 10 ];
uint32_t idArray_board0_controller0[ 10 ];
int32_t noIDs_board0_controller0 = 0;
unsigned char dataArray0_board0_controller0[ 8 ];
unsigned char dataArray1_board0_controller0[ 8 ];
unsigned char dataArray2_board0_controller0[ 8 ];
unsigned char dataArray3_board0_controller0[ 8 ];
unsigned char dataArray4_board0_controller0[ 8 ];
unsigned char dataArray5_board0_controller0[ 8 ];
unsigned char dataArray6_board0_controller0[ 8 ];
unsigned char dataArray7_board0_controller0[ 8 ];
unsigned char dataArray8_board0_controller0[ 8 ];
unsigned char dataArray9_board0_controller0[ 8 ];
unsigned char* dataArrayAddresses_board0_controller0[] = {dataArray0_board0_controller0, dataArray1_board0_controller0, dataArray2_board0_controller0, dataArray3_board0_controller0, dataArray4_board0_controller0, dataArray5_board0_controller0, dataArray6_board0_controller0, dataArray7_board0_controller0, dataArray8_board0_controller0, dataArray9_board0_controller0};
uint32_t dlcArray_board0_controller0[ 10 ];
uint32_t noActivitiesArray_board0_controller0[ 10 ];
double minCycleTimeArray_board0_controller0[ 10 ];
double maxCycleTimeArray_board0_controller0[ 10 ];
double averageCycleTimeArray_board0_controller0[ 10 ];
static bool firstReceptionOfAnyFrame_board0_controller0;


static ixxat_can_data_t frame_bo0_co0_101std_rtpc_bms_volt_1_4;
static ixxat_can_data_t frame_bo0_co0_102std_rtpc_bms_volt_5_8;
static ixxat_can_data_t frame_bo0_co0_103std_rtpc_bms_volt_9_12;
static ixxat_can_data_t frame_bo0_co0_111std_rtpc_bms_temp_1_4;
static ixxat_can_data_t frame_bo0_co0_112std_rtpc_bms_temp_5_8;
static ixxat_can_data_t frame_bo0_co0_113std_rtpc_bms_temp_9_12;
static ixxat_can_data_t frame_bo0_co0_131std_rtpc_bms_sammeln;
// Declare variables needed for the handling of frame (controller-specific) 'rtpc_bms_volt_1_4' ID 101:
// Structure with physical values for frame ID bo0_co0_101std_rtpc_bms_volt_1_4:
signals_bo0_co0_101std_rtpc_bms_volt_1_4_struct signals_bo0_co0_101std_rtpc_bms_volt_1_4;
signals_bo0_co0_101std_rtpc_bms_volt_1_4_struct signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip;
static signals_bo0_co0_101std_rtpc_bms_volt_1_4_struct signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited;
static int32_t counter_bo0_co0_101std_rtpc_bms_volt_1_4 = 0;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4 = 8;
bool dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4_manip = false;
unsigned char byteArray_bo0_co0_101std_rtpc_bms_volt_1_4[ 8 ];
int32_t inTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 = 1;  // Measure variable: Input trigger value
bool remoteTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 = false; // Calibration variable: For remote sending of frame
bool manualEnabled_bo0_co0_101std_rtpc_bms_volt_1_4 = true; // Calibration variable: For manual enabling/disabling of the sending
bool singleShot_bo0_co0_101std_rtpc_bms_volt_1_4 = false;  // Calibration variable: To trigger off a single sending
double cycleTime_bo0_co0_101std_rtpc_bms_volt_1_4 = 1;  // Calibration variable: Sending cycle time
bool inportCycleTime_bo0_co0_101std_rtpc_bms_volt_1_4 = false;  // Calibration variable: Use cycleTime inport or cycleTime parameter
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1;
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V1;
static uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V1;
int32_t mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 = MODEL;
int32_t sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 = 0;
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2;
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V2;
static uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V2;
int32_t mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 = MODEL;
int32_t sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 = 0;
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3;
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V3;
static uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V3;
int32_t mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 = MODEL;
int32_t sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 = 0;
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4;
uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V4;
static uint32_t intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V4;
int32_t mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 = MODEL;
int32_t sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 = 0;
// Declare variables needed for the handling of frame (controller-specific) 'rtpc_bms_volt_5_8' ID 102:
// Structure with physical values for frame ID bo0_co0_102std_rtpc_bms_volt_5_8:
signals_bo0_co0_102std_rtpc_bms_volt_5_8_struct signals_bo0_co0_102std_rtpc_bms_volt_5_8;
signals_bo0_co0_102std_rtpc_bms_volt_5_8_struct signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip;
static signals_bo0_co0_102std_rtpc_bms_volt_5_8_struct signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited;
static int32_t counter_bo0_co0_102std_rtpc_bms_volt_5_8 = 0;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8 = 8;
bool dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8_manip = false;
unsigned char byteArray_bo0_co0_102std_rtpc_bms_volt_5_8[ 8 ];
int32_t inTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 = 1;  // Measure variable: Input trigger value
bool remoteTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 = false; // Calibration variable: For remote sending of frame
bool manualEnabled_bo0_co0_102std_rtpc_bms_volt_5_8 = true; // Calibration variable: For manual enabling/disabling of the sending
bool singleShot_bo0_co0_102std_rtpc_bms_volt_5_8 = false;  // Calibration variable: To trigger off a single sending
double cycleTime_bo0_co0_102std_rtpc_bms_volt_5_8 = 1;  // Calibration variable: Sending cycle time
bool inportCycleTime_bo0_co0_102std_rtpc_bms_volt_5_8 = false;  // Calibration variable: Use cycleTime inport or cycleTime parameter
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5;
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V5;
static uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V5;
int32_t mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 = MODEL;
int32_t sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 = 0;
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6;
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V6;
static uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V6;
int32_t mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 = MODEL;
int32_t sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 = 0;
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7;
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V7;
static uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V7;
int32_t mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 = MODEL;
int32_t sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 = 0;
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8;
uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V8;
static uint32_t intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V8;
int32_t mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 = MODEL;
int32_t sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 = 0;
// Declare variables needed for the handling of frame (controller-specific) 'rtpc_bms_volt_9_12' ID 103:
// Structure with physical values for frame ID bo0_co0_103std_rtpc_bms_volt_9_12:
signals_bo0_co0_103std_rtpc_bms_volt_9_12_struct signals_bo0_co0_103std_rtpc_bms_volt_9_12;
signals_bo0_co0_103std_rtpc_bms_volt_9_12_struct signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip;
static signals_bo0_co0_103std_rtpc_bms_volt_9_12_struct signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited;
static int32_t counter_bo0_co0_103std_rtpc_bms_volt_9_12 = 0;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12 = 8;
bool dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12_manip = false;
unsigned char byteArray_bo0_co0_103std_rtpc_bms_volt_9_12[ 8 ];
int32_t inTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 = 1;  // Measure variable: Input trigger value
bool remoteTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 = false; // Calibration variable: For remote sending of frame
bool manualEnabled_bo0_co0_103std_rtpc_bms_volt_9_12 = true; // Calibration variable: For manual enabling/disabling of the sending
bool singleShot_bo0_co0_103std_rtpc_bms_volt_9_12 = false;  // Calibration variable: To trigger off a single sending
double cycleTime_bo0_co0_103std_rtpc_bms_volt_9_12 = 1;  // Calibration variable: Sending cycle time
bool inportCycleTime_bo0_co0_103std_rtpc_bms_volt_9_12 = false;  // Calibration variable: Use cycleTime inport or cycleTime parameter
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10;
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V10;
static uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V10;
int32_t mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 = MODEL;
int32_t sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 = 0;
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11;
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V11;
static uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V11;
int32_t mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 = MODEL;
int32_t sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 = 0;
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12;
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V12;
static uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V12;
int32_t mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 = MODEL;
int32_t sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 = 0;
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9;
uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V9;
static uint32_t intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V9;
int32_t mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 = MODEL;
int32_t sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 = 0;
// Declare variables needed for the handling of frame (controller-specific) 'rtpc_bms_temp_1_4' ID 111:
// Structure with physical values for frame ID bo0_co0_111std_rtpc_bms_temp_1_4:
signals_bo0_co0_111std_rtpc_bms_temp_1_4_struct signals_bo0_co0_111std_rtpc_bms_temp_1_4;
signals_bo0_co0_111std_rtpc_bms_temp_1_4_struct signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip;
static signals_bo0_co0_111std_rtpc_bms_temp_1_4_struct signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited;
static int32_t counter_bo0_co0_111std_rtpc_bms_temp_1_4 = 0;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4 = 8;
bool dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4_manip = false;
unsigned char byteArray_bo0_co0_111std_rtpc_bms_temp_1_4[ 8 ];
int32_t inTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 = 1;  // Measure variable: Input trigger value
bool remoteTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 = false; // Calibration variable: For remote sending of frame
bool manualEnabled_bo0_co0_111std_rtpc_bms_temp_1_4 = true; // Calibration variable: For manual enabling/disabling of the sending
bool singleShot_bo0_co0_111std_rtpc_bms_temp_1_4 = false;  // Calibration variable: To trigger off a single sending
double cycleTime_bo0_co0_111std_rtpc_bms_temp_1_4 = 1;  // Calibration variable: Sending cycle time
bool inportCycleTime_bo0_co0_111std_rtpc_bms_temp_1_4 = false;  // Calibration variable: Use cycleTime inport or cycleTime parameter
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1;
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T1;
static uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T1;
int32_t mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 = MODEL;
int32_t sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 = 0;
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2;
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T2;
static uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T2;
int32_t mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 = MODEL;
int32_t sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 = 0;
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3;
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T3;
static uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T3;
int32_t mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 = MODEL;
int32_t sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 = 0;
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4;
uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T4;
static uint32_t intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T4;
int32_t mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 = MODEL;
int32_t sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 = 0;
// Declare variables needed for the handling of frame (controller-specific) 'rtpc_bms_temp_5_8' ID 112:
// Structure with physical values for frame ID bo0_co0_112std_rtpc_bms_temp_5_8:
signals_bo0_co0_112std_rtpc_bms_temp_5_8_struct signals_bo0_co0_112std_rtpc_bms_temp_5_8;
signals_bo0_co0_112std_rtpc_bms_temp_5_8_struct signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip;
static signals_bo0_co0_112std_rtpc_bms_temp_5_8_struct signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited;
static int32_t counter_bo0_co0_112std_rtpc_bms_temp_5_8 = 0;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8 = 8;
bool dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8_manip = false;
unsigned char byteArray_bo0_co0_112std_rtpc_bms_temp_5_8[ 8 ];
int32_t inTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 = 1;  // Measure variable: Input trigger value
bool remoteTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 = false; // Calibration variable: For remote sending of frame
bool manualEnabled_bo0_co0_112std_rtpc_bms_temp_5_8 = true; // Calibration variable: For manual enabling/disabling of the sending
bool singleShot_bo0_co0_112std_rtpc_bms_temp_5_8 = false;  // Calibration variable: To trigger off a single sending
double cycleTime_bo0_co0_112std_rtpc_bms_temp_5_8 = 1;  // Calibration variable: Sending cycle time
bool inportCycleTime_bo0_co0_112std_rtpc_bms_temp_5_8 = false;  // Calibration variable: Use cycleTime inport or cycleTime parameter
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5;
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_T5;
static uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T5;
int32_t mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 = MODEL;
int32_t sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 = 0;
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6;
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_T6;
static uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T6;
int32_t mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 = MODEL;
int32_t sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 = 0;
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7;
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_T7;
static uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T7;
int32_t mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 = MODEL;
int32_t sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 = 0;
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8;
uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_V8;
static uint32_t intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_V8;
int32_t mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 = MODEL;
int32_t sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 = 0;
// Declare variables needed for the handling of frame (controller-specific) 'rtpc_bms_temp_9_12' ID 113:
// Structure with physical values for frame ID bo0_co0_113std_rtpc_bms_temp_9_12:
signals_bo0_co0_113std_rtpc_bms_temp_9_12_struct signals_bo0_co0_113std_rtpc_bms_temp_9_12;
signals_bo0_co0_113std_rtpc_bms_temp_9_12_struct signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip;
static signals_bo0_co0_113std_rtpc_bms_temp_9_12_struct signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited;
static int32_t counter_bo0_co0_113std_rtpc_bms_temp_9_12 = 0;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12 = 8;
bool dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12_manip = false;
unsigned char byteArray_bo0_co0_113std_rtpc_bms_temp_9_12[ 8 ];
int32_t inTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 = 1;  // Measure variable: Input trigger value
bool remoteTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 = false; // Calibration variable: For remote sending of frame
bool manualEnabled_bo0_co0_113std_rtpc_bms_temp_9_12 = true; // Calibration variable: For manual enabling/disabling of the sending
bool singleShot_bo0_co0_113std_rtpc_bms_temp_9_12 = false;  // Calibration variable: To trigger off a single sending
double cycleTime_bo0_co0_113std_rtpc_bms_temp_9_12 = 1;  // Calibration variable: Sending cycle time
bool inportCycleTime_bo0_co0_113std_rtpc_bms_temp_9_12 = false;  // Calibration variable: Use cycleTime inport or cycleTime parameter
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10;
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T10;
static uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T10;
int32_t mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 = MODEL;
int32_t sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 = 0;
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11;
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T11;
static uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T11;
int32_t mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 = MODEL;
int32_t sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 = 0;
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12;
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T12;
static uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T12;
int32_t mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 = MODEL;
int32_t sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 = 0;
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9;
uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T9;
static uint32_t intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T9;
int32_t mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 = MODEL;
int32_t sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 = 0;
// Declare variables needed for the handling of frame (controller-specific) 'rtpc_bms_sammeln' ID 131:
// Structure with physical values for frame ID bo0_co0_131std_rtpc_bms_sammeln:
signals_bo0_co0_131std_rtpc_bms_sammeln_struct signals_bo0_co0_131std_rtpc_bms_sammeln;
signals_bo0_co0_131std_rtpc_bms_sammeln_struct signals_bo0_co0_131std_rtpc_bms_sammeln_manip;
static signals_bo0_co0_131std_rtpc_bms_sammeln_struct signals_bo0_co0_131std_rtpc_bms_sammeln_limited;
static int32_t counter_bo0_co0_131std_rtpc_bms_sammeln = 0;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_131std_rtpc_bms_sammeln = 8;
bool dlcParam_bo0_co0_131std_rtpc_bms_sammeln_manip = false;
unsigned char byteArray_bo0_co0_131std_rtpc_bms_sammeln[ 8 ];
int32_t inTrigger_bo0_co0_131std_rtpc_bms_sammeln = 1;  // Measure variable: Input trigger value
bool remoteTrigger_bo0_co0_131std_rtpc_bms_sammeln = false; // Calibration variable: For remote sending of frame
bool manualEnabled_bo0_co0_131std_rtpc_bms_sammeln = true; // Calibration variable: For manual enabling/disabling of the sending
bool singleShot_bo0_co0_131std_rtpc_bms_sammeln = false;  // Calibration variable: To trigger off a single sending
double cycleTime_bo0_co0_131std_rtpc_bms_sammeln = 1;  // Calibration variable: Sending cycle time
bool inportCycleTime_bo0_co0_131std_rtpc_bms_sammeln = false;  // Calibration variable: Use cycleTime inport or cycleTime parameter
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp;
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Absolute_Amp;
static uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Absolute_Amp;
int32_t mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp = MODEL;
int32_t sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp = 0;
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden;
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Laden;
static uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Laden;
int32_t mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden = MODEL;
int32_t sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden = 0;
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode;
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Mode;
static uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Mode;
int32_t mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode = MODEL;
int32_t sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode = 0;
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt;
uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Total_volt;
static uint32_t intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Total_volt;
int32_t mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt = MODEL;
int32_t sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt = 0;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rtcp_volt_1_4' ID 201:
// Structure with physical values for frame ID bo0_co0_201std_bms_rtcp_volt_1_4:
signals_bo0_co0_201std_bms_rtcp_volt_1_4_struct signals_bo0_co0_201std_bms_rtcp_volt_1_4;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_201std_bms_rtcp_volt_1_4 = 8;
bool dlcParam_bo0_co0_201std_bms_rtcp_volt_1_4_manip = false;
unsigned char byteArray_bo0_co0_201std_bms_rtcp_volt_1_4[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V1;
uint32_t intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V2;
uint32_t intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V3;
uint32_t intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V4;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rctp_volt_5_8' ID 202:
// Structure with physical values for frame ID bo0_co0_202std_bms_rctp_volt_5_8:
signals_bo0_co0_202std_bms_rctp_volt_5_8_struct signals_bo0_co0_202std_bms_rctp_volt_5_8;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_202std_bms_rctp_volt_5_8 = 8;
bool dlcParam_bo0_co0_202std_bms_rctp_volt_5_8_manip = false;
unsigned char byteArray_bo0_co0_202std_bms_rctp_volt_5_8[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V5;
uint32_t intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V6;
uint32_t intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V7;
uint32_t intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V8;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rctp_volt_9_12' ID 203:
// Structure with physical values for frame ID bo0_co0_203std_bms_rctp_volt_9_12:
signals_bo0_co0_203std_bms_rctp_volt_9_12_struct signals_bo0_co0_203std_bms_rctp_volt_9_12;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_203std_bms_rctp_volt_9_12 = 8;
bool dlcParam_bo0_co0_203std_bms_rctp_volt_9_12_manip = false;
unsigned char byteArray_bo0_co0_203std_bms_rctp_volt_9_12[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V10;
uint32_t intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V11;
uint32_t intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V12;
uint32_t intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V9;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rctp_temp_1_4' ID 211:
// Structure with physical values for frame ID bo0_co0_211std_bms_rctp_temp_1_4:
signals_bo0_co0_211std_bms_rctp_temp_1_4_struct signals_bo0_co0_211std_bms_rctp_temp_1_4;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_211std_bms_rctp_temp_1_4 = 8;
bool dlcParam_bo0_co0_211std_bms_rctp_temp_1_4_manip = false;
unsigned char byteArray_bo0_co0_211std_bms_rctp_temp_1_4[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T1;
uint32_t intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T2;
uint32_t intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T3;
uint32_t intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T4;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rctp_temp_5_8' ID 212:
// Structure with physical values for frame ID bo0_co0_212std_bms_rctp_temp_5_8:
signals_bo0_co0_212std_bms_rctp_temp_5_8_struct signals_bo0_co0_212std_bms_rctp_temp_5_8;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_212std_bms_rctp_temp_5_8 = 8;
bool dlcParam_bo0_co0_212std_bms_rctp_temp_5_8_manip = false;
unsigned char byteArray_bo0_co0_212std_bms_rctp_temp_5_8[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T5;
uint32_t intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T6;
uint32_t intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T7;
uint32_t intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T8;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rctp_temp_9_12' ID 213:
// Structure with physical values for frame ID bo0_co0_213std_bms_rctp_temp_9_12:
signals_bo0_co0_213std_bms_rctp_temp_9_12_struct signals_bo0_co0_213std_bms_rctp_temp_9_12;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_213std_bms_rctp_temp_9_12 = 8;
bool dlcParam_bo0_co0_213std_bms_rctp_temp_9_12_manip = false;
unsigned char byteArray_bo0_co0_213std_bms_rctp_temp_9_12[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T10;
uint32_t intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T11;
uint32_t intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T12;
uint32_t intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T9;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rtcp_bal' ID 221:
// Structure with physical values for frame ID bo0_co0_221std_bms_rtcp_bal:
signals_bo0_co0_221std_bms_rtcp_bal_struct signals_bo0_co0_221std_bms_rtcp_bal;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_221std_bms_rtcp_bal = 8;
bool dlcParam_bo0_co0_221std_bms_rtcp_bal_manip = false;
unsigned char byteArray_bo0_co0_221std_bms_rtcp_bal[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_1;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_10;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_11;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_12;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_2;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_3;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_4;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_5;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_6;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_7;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_8;
int32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_9;
uint32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_1;
uint32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_2;
uint32_t intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_3;
// Declare variables needed for the handling of frame (controller-specific) 'bms_rtcp_sammeln' ID 231:
// Structure with physical values for frame ID bo0_co0_231std_bms_rtcp_sammeln:
signals_bo0_co0_231std_bms_rtcp_sammeln_struct signals_bo0_co0_231std_bms_rtcp_sammeln;
// DLC param initialization and byte array as measure variable for receive frames:
uint32_t dlcParam_bo0_co0_231std_bms_rtcp_sammeln = 8;
bool dlcParam_bo0_co0_231std_bms_rtcp_sammeln_manip = false;
unsigned char byteArray_bo0_co0_231std_bms_rtcp_sammeln[ 8 ];
// Declare the 'Intern' variables for the bit-representation of the signals:
uint32_t intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Absolut_Amp;
uint32_t intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Laden;
uint32_t intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_SoC;
uint32_t intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Total_Volt;
const double canBaseRateInv_bo0_co1 = 2; // inverse of the base rate 0.5s
double internalCANTime_bo0_co1 = 0.0;
static int can_handle_board0_controller1 = -1;

// Declare CAN-Controller specific variables needed for Canalyse Tracing:
double timeArray_board0_controller1[ 10 ];
double cycleTimeArray_board0_controller1[ 10 ];
uint32_t idArray_board0_controller1[ 10 ];
int32_t noIDs_board0_controller1 = 0;
unsigned char dataArray0_board0_controller1[ 8 ];
unsigned char dataArray1_board0_controller1[ 8 ];
unsigned char dataArray2_board0_controller1[ 8 ];
unsigned char dataArray3_board0_controller1[ 8 ];
unsigned char dataArray4_board0_controller1[ 8 ];
unsigned char dataArray5_board0_controller1[ 8 ];
unsigned char dataArray6_board0_controller1[ 8 ];
unsigned char dataArray7_board0_controller1[ 8 ];
unsigned char dataArray8_board0_controller1[ 8 ];
unsigned char dataArray9_board0_controller1[ 8 ];
unsigned char* dataArrayAddresses_board0_controller1[] = {dataArray0_board0_controller1, dataArray1_board0_controller1, dataArray2_board0_controller1, dataArray3_board0_controller1, dataArray4_board0_controller1, dataArray5_board0_controller1, dataArray6_board0_controller1, dataArray7_board0_controller1, dataArray8_board0_controller1, dataArray9_board0_controller1};
uint32_t dlcArray_board0_controller1[ 10 ];
uint32_t noActivitiesArray_board0_controller1[ 10 ];
double minCycleTimeArray_board0_controller1[ 10 ];
double maxCycleTimeArray_board0_controller1[ 10 ];
double averageCycleTimeArray_board0_controller1[ 10 ];
static bool firstReceptionOfAnyFrame_board0_controller1;




static void InitFrameIxxatDataStruct ( ixxat_can_data_t* frame_struct, uint32_t id, unsigned char dlc, unsigned char mff, bool initData, byte initialDataBytePattern )
{
	frame_struct->id = id;
	frame_struct->dlc = dlc;
	frame_struct->mff = mff;

	if ( initData == true )
	{
		uint32_t i;
		uint32_t bytes = (uint32_t)dlc;
		for ( i = 0; i < bytes; ++i )
		{
			frame_struct->data[ i ] = initialDataBytePattern;  // Use initial data byte pattern
		}
	}
}

static void InitFrameSignalsStruct ( frameAnalysisSignals_struct* Analysis_struct, unsigned short dlc )
{
	Analysis_struct->NumberOfActivations = 0;
	Analysis_struct->TimeOfLastActivation = 0.0;
	Analysis_struct->CurrentCycleTime = 0.0;
	Analysis_struct->MinimumCycleTime = 1e100; // should be big enough
	Analysis_struct->MaximumCycleTime = 0.0;
	Analysis_struct->AverageCycleTime = 0.0;
	Analysis_struct->DLC = dlc;
}

void FrameAnalysis ( frameAnalysisSignals_struct* Analysis_struct, double time )
{
	// Assign values to arrays for Canalyse-Tracing
	Analysis_struct->NumberOfActivations++;

	if ( Analysis_struct->NumberOfActivations > 1 )
	{
		Analysis_struct->CurrentCycleTime = time - Analysis_struct->TimeOfLastActivation;

		if ( Analysis_struct->MinimumCycleTime > Analysis_struct->CurrentCycleTime )
		{
			Analysis_struct->MinimumCycleTime = Analysis_struct->CurrentCycleTime;
		}
		if ( Analysis_struct->MaximumCycleTime < Analysis_struct->CurrentCycleTime )
		{
			Analysis_struct->MaximumCycleTime = Analysis_struct->CurrentCycleTime;
		}

		Analysis_struct->AverageCycleTime = ( Analysis_struct->CurrentCycleTime + ( Analysis_struct->NumberOfActivations - 2 ) * Analysis_struct->AverageCycleTime ) / ( Analysis_struct->NumberOfActivations - 1 );
	}

	Analysis_struct->TimeOfLastActivation = time;
}

void CAN_Init()
{
	int32_t i;

	// Initialization for controller 0 of board 0:
	internalCANTime_bo0_co0 = 0.0;
	for ( i = 0; i < 10; ++i )
	{
		timeArray_board0_controller0[ i ] = 0;
		cycleTimeArray_board0_controller0[ i ] = 0;
		idArray_board0_controller0[ i ] = 0;
		dlcArray_board0_controller0[ i ] = 0;
		noActivitiesArray_board0_controller0[ i ] = 0;
		minCycleTimeArray_board0_controller0[ i ] = 1e100;
		maxCycleTimeArray_board0_controller0[ i ] = 0;
		averageCycleTimeArray_board0_controller0[ i ] = 0;

		unsigned char* ptr = dataArrayAddresses_board0_controller0[ i ];
		int size;
		for ( size = 0; size < 8; ++size )
		{
			*(ptr + size) = 0;
		}
	}
	noIDs_board0_controller0 = 0;
	firstReceptionOfAnyFrame_board0_controller0 = true;

	// For frame 'rtpc_bms_volt_1_4' ID 101
	InitFrameSignalsStruct ( &( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Analysis_struct ), dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4 );
	// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
	InitFrameIxxatDataStruct ( &frame_bo0_co0_101std_rtpc_bms_volt_1_4, 0x101, dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

	// For frame 'rtpc_bms_volt_5_8' ID 102
	InitFrameSignalsStruct ( &( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Analysis_struct ), dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8 );
	// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
	InitFrameIxxatDataStruct ( &frame_bo0_co0_102std_rtpc_bms_volt_5_8, 0x102, dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

	// For frame 'rtpc_bms_volt_9_12' ID 103
	InitFrameSignalsStruct ( &( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Analysis_struct ), dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12 );
	// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
	InitFrameIxxatDataStruct ( &frame_bo0_co0_103std_rtpc_bms_volt_9_12, 0x103, dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

	// For frame 'rtpc_bms_temp_1_4' ID 111
	InitFrameSignalsStruct ( &( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Analysis_struct ), dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4 );
	// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
	InitFrameIxxatDataStruct ( &frame_bo0_co0_111std_rtpc_bms_temp_1_4, 0x111, dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

	// For frame 'rtpc_bms_temp_5_8' ID 112
	InitFrameSignalsStruct ( &( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Analysis_struct ), dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8 );
	// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
	InitFrameIxxatDataStruct ( &frame_bo0_co0_112std_rtpc_bms_temp_5_8, 0x112, dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

	// For frame 'rtpc_bms_temp_9_12' ID 113
	InitFrameSignalsStruct ( &( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Analysis_struct ), dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12 );
	// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
	InitFrameIxxatDataStruct ( &frame_bo0_co0_113std_rtpc_bms_temp_9_12, 0x113, dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

	// For frame 'rtpc_bms_sammeln' ID 131
	InitFrameSignalsStruct ( &( signals_bo0_co0_131std_rtpc_bms_sammeln.Analysis_struct ), dlcParam_bo0_co0_131std_rtpc_bms_sammeln );
	// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
	InitFrameIxxatDataStruct ( &frame_bo0_co0_131std_rtpc_bms_sammeln, 0x131, dlcParam_bo0_co0_131std_rtpc_bms_sammeln, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

	// For frame 'bms_rtcp_volt_1_4' ID 201
	InitFrameSignalsStruct ( &( signals_bo0_co0_201std_bms_rtcp_volt_1_4.Analysis_struct ), dlcParam_bo0_co0_201std_bms_rtcp_volt_1_4 );

	// For frame 'bms_rctp_volt_5_8' ID 202
	InitFrameSignalsStruct ( &( signals_bo0_co0_202std_bms_rctp_volt_5_8.Analysis_struct ), dlcParam_bo0_co0_202std_bms_rctp_volt_5_8 );

	// For frame 'bms_rctp_volt_9_12' ID 203
	InitFrameSignalsStruct ( &( signals_bo0_co0_203std_bms_rctp_volt_9_12.Analysis_struct ), dlcParam_bo0_co0_203std_bms_rctp_volt_9_12 );

	// For frame 'bms_rctp_temp_1_4' ID 211
	InitFrameSignalsStruct ( &( signals_bo0_co0_211std_bms_rctp_temp_1_4.Analysis_struct ), dlcParam_bo0_co0_211std_bms_rctp_temp_1_4 );

	// For frame 'bms_rctp_temp_5_8' ID 212
	InitFrameSignalsStruct ( &( signals_bo0_co0_212std_bms_rctp_temp_5_8.Analysis_struct ), dlcParam_bo0_co0_212std_bms_rctp_temp_5_8 );

	// For frame 'bms_rctp_temp_9_12' ID 213
	InitFrameSignalsStruct ( &( signals_bo0_co0_213std_bms_rctp_temp_9_12.Analysis_struct ), dlcParam_bo0_co0_213std_bms_rctp_temp_9_12 );

	// For frame 'bms_rtcp_bal' ID 221
	InitFrameSignalsStruct ( &( signals_bo0_co0_221std_bms_rtcp_bal.Analysis_struct ), dlcParam_bo0_co0_221std_bms_rtcp_bal );

	// For frame 'bms_rtcp_sammeln' ID 231
	InitFrameSignalsStruct ( &( signals_bo0_co0_231std_bms_rtcp_sammeln.Analysis_struct ), dlcParam_bo0_co0_231std_bms_rtcp_sammeln );

	can_handle_board0_controller0 = rtos_comm_open ( "ixxat_can:0/controller=0 btr0=0 btr1=28 stt=1 checkinterval=0.50 initchk=4", 0, 0, 0 );
	if ( can_handle_board0_controller0 < 0 )
	{
		rtos_log( LOG_ERR, "Error in initializing CAN-controller 0 of CAN-board 0\n" );
	}

	// Initialization for controller 1 of board 0:
	internalCANTime_bo0_co1 = 0.0;
	for ( i = 0; i < 10; ++i )
	{
		timeArray_board0_controller1[ i ] = 0;
		cycleTimeArray_board0_controller1[ i ] = 0;
		idArray_board0_controller1[ i ] = 0;
		dlcArray_board0_controller1[ i ] = 0;
		noActivitiesArray_board0_controller1[ i ] = 0;
		minCycleTimeArray_board0_controller1[ i ] = 1e100;
		maxCycleTimeArray_board0_controller1[ i ] = 0;
		averageCycleTimeArray_board0_controller1[ i ] = 0;

		unsigned char* ptr = dataArrayAddresses_board0_controller1[ i ];
		int size;
		for ( size = 0; size < 8; ++size )
		{
			*(ptr + size) = 0;
		}
	}
	noIDs_board0_controller1 = 0;
	firstReceptionOfAnyFrame_board0_controller1 = true;

	can_handle_board0_controller1 = rtos_comm_open ( "ixxat_can:0/controller=1 btr0=0 btr1=28 stt=1 checkinterval=0.50 initchk=4", 0, 0, 0 );
	if ( can_handle_board0_controller1 < 0 )
	{
		rtos_log( LOG_ERR, "Error in initializing CAN-controller 1 of CAN-board 0\n" );
	}

}

void CAN_Send_board0_controller0( void )
{
	// Variable declarations:
	int32_t i;
	bool singleShotByInport;

	bool sendFrame;
	bool cyclicSendConditionFulfilled;
	bool spontanousSendConditionFulfilled;


	// 'Send'-Code for all Frames of Controller 0 and Board 0:

	static double oldSingleShotSignalInport_bo0_co0_101std_rtpc_bms_volt_1_4 = 1;
	// ==========================================================================
	// 'Send'-Code for Frame 'rtpc_bms_volt_1_4' with  ID '101'.
	inTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 = (int32_t) getInPortValue ( &inport_inTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 );
	singleShotByInport = ( ( oldSingleShotSignalInport_bo0_co0_101std_rtpc_bms_volt_1_4 < 0.5 ) && ( getInPortValue ( &inport_singleShot_bo0_co0_101std_rtpc_bms_volt_1_4 ) > 0.5 ) ); // check single shot trigger transition, (check with 0.5 because of conversion from double to bool)
	oldSingleShotSignalInport_bo0_co0_101std_rtpc_bms_volt_1_4 =  getInPortValue ( &inport_singleShot_bo0_co0_101std_rtpc_bms_volt_1_4 );
	sendFrame = false; // if this bool turns to true the frame is sent
	cyclicSendConditionFulfilled = false; // if this bool turns to true one of the frame cyclic send conditions are fulfilled.
	spontanousSendConditionFulfilled = false; // if this bool turns to true one of the frame spontanous send conditions are fulfilled.

	// check manual send condition
	if (
	       (
	           ( inTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 == 0 )
	        || ( manualEnabled_bo0_co0_101std_rtpc_bms_volt_1_4 == false )
	       )
	    && 
	       (
	           ( singleShot_bo0_co0_101std_rtpc_bms_volt_1_4 == true )
	        || ( singleShotByInport == true )
	       )
	   )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
		singleShot_bo0_co0_101std_rtpc_bms_volt_1_4 = false;
	}

	// check remote trigger send condition
	if ( remoteTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 == true )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
	}

	if ( ( partEnabled_NewDB == true ) || ( partEnabled_NewDB_oldState == true ) )
	{
		//Reinitialize frame byte array if part was disabled in last cycle
		if ( ( partEnabled_NewDB != partEnabled_NewDB_oldState ) && ( partEnabled_NewDB_oldState == false ) )
		{
			// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
			InitFrameIxxatDataStruct ( &frame_bo0_co0_101std_rtpc_bms_volt_1_4, 0x101, dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

			// Overwrite sending cycle time
			cycleTime_bo0_co0_101std_rtpc_bms_volt_1_4 = 1;
		}

		//Reinitialize currently valid signal send modes
		sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 = 0;
		sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 = 0;
		sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 = 0;
		sendMode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 = 0;

		if ( partEnabled_NewDB == true )
		{
			bool counterIsZero = false;
			if ( counter_bo0_co0_101std_rtpc_bms_volt_1_4 == 0 )
			{
				counterIsZero = true;
				if ( inportCycleTime_bo0_co0_101std_rtpc_bms_volt_1_4 == true )
				{
					counter_bo0_co0_101std_rtpc_bms_volt_1_4 = (int32_t)( ( getInPortValue ( &inport_cycleTime_bo0_co0_101std_rtpc_bms_volt_1_4 ) * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}
				else
				{
					counter_bo0_co0_101std_rtpc_bms_volt_1_4 = (int32_t)( ( cycleTime_bo0_co0_101std_rtpc_bms_volt_1_4 * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}

				if ( manualEnabled_bo0_co0_101std_rtpc_bms_volt_1_4 == true )
				{
					// check cyclic condition
					if ( counterIsZero && ( inTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 != 0 ) )
					{
						cyclicSendConditionFulfilled = true;
						sendFrame = true;
					}
				}
			}
			// no spontanous send condition

			if ( cyclicSendConditionFulfilled == true )
			{
				// Initialize DLC of frame

				// use model DLC if manipulation is deactivated
				if ( dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4_manip == false )
				{
					// overwrite DLC of frame with specified byte count
					dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4 = 8;
				}
				// Check if DLC is in range of protocol specification
				if ( dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4 > 8 )
				{
					// overwrite DLC of frame with max supported byte count of protocol
					dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4 = 8;
				}

				signals_bo0_co0_101std_rtpc_bms_volt_1_4.Analysis_struct.DLC = dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4;
				frame_bo0_co0_101std_rtpc_bms_volt_1_4.dlc = dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4;

				// increment remote trigger if necessary
				if ( remoteTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 == true )
				{
					remoteTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 = false;
					double remoteCounter = 0.0;
					OUTPORT_REAL64_GETVALUE ( &outport_bo0_co0_101std_rtpc_bms_volt_1_4_remoteTrigger, remoteCounter );
					if ( remoteCounter > 2147483647 )
					{
						remoteCounter = 0;
					}

					setOutPortValue ( &outport_bo0_co0_101std_rtpc_bms_volt_1_4_remoteTrigger, remoteCounter + 1.0 );
				}

				// Copy (physical) signals from Inports to structure:
				if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 == CONFIG_VALS )
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V1 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V1 = getInPortValue ( &inport_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 );
				}
				if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 == CONFIG_VALS )
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V2 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V2 = getInPortValue ( &inport_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 );
				}
				if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 == CONFIG_VALS )
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V3 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V3 = getInPortValue ( &inport_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 );
				}
				if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 == CONFIG_VALS )
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V4 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V4 = getInPortValue ( &inport_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 );
				}

				// Compute bit-representation for all signals of the frame:
				//MONITORED Signals

				//UNMONITORED & COUNTER Signals only if it is clear that we have to send a frame
				if ( sendFrame == true )
				{
					// Signal 'Signal_Cell_V1'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V1 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V1 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V1 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V1 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V1 = signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V1;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V1 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V1 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V1 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V1 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V1 = signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V1;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 == MANIP_HEX )
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V1 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V1;
					}
					else
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V1 = lround ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V1 );
					}

					// Copy to internal variable
					intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V1;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V1 frame bo0_co0_101std_rtpc_bms_volt_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 0 ] = ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 );
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 1 ] = ( ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V1 >> 8 ) );
					// Signal 'Signal_Cell_V2'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V2 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V2 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V2 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V2 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V2 = signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V2;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V2 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V2 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V2 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V2 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V2 = signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V2;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 == MANIP_HEX )
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V2 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V2;
					}
					else
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V2 = lround ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V2 );
					}

					// Copy to internal variable
					intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V2;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V2 frame bo0_co0_101std_rtpc_bms_volt_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 2 ] = ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 );
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 3 ] = ( ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V2 >> 8 ) );
					// Signal 'Signal_Cell_V3'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V3 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V3 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V3 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V3 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V3 = signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V3;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V3 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V3 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V3 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V3 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V3 = signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V3;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 == MANIP_HEX )
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V3 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V3;
					}
					else
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V3 = lround ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V3 );
					}

					// Copy to internal variable
					intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V3;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V3 frame bo0_co0_101std_rtpc_bms_volt_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 4 ] = ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 );
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 5 ] = ( ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V3 >> 8 ) );
					// Signal 'Signal_Cell_V4'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V4 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V4 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V4 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V4 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V4 = signals_bo0_co0_101std_rtpc_bms_volt_1_4_manip.Signal_Cell_V4;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V4 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V4 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V4 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V4 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V4 = signals_bo0_co0_101std_rtpc_bms_volt_1_4.Signal_Cell_V4;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 == MANIP_HEX )
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V4 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_manip_Signal_Cell_V4;
					}
					else
					{
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V4 = lround ( signals_bo0_co0_101std_rtpc_bms_volt_1_4_limited.Signal_Cell_V4 );
					}

					// Copy to internal variable
					intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 = intern_bo0_co0_101std_rtpc_bms_volt_1_4_unlimited_Signal_Cell_V4;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V4 frame bo0_co0_101std_rtpc_bms_volt_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 6 ] = ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 );
					frame_bo0_co0_101std_rtpc_bms_volt_1_4.data[ 7 ] = ( ( intern_bo0_co0_101std_rtpc_bms_volt_1_4_Signal_Cell_V4 >> 8 ) );

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_101std_rtpc_bms_volt_1_4, frame_bo0_co0_101std_rtpc_bms_volt_1_4.data, dlcParam_bo0_co0_101std_rtpc_bms_volt_1_4 );

					i = rtos_comm_write ( can_handle_board0_controller0, &frame_bo0_co0_101std_rtpc_bms_volt_1_4, sizeof ( frame_bo0_co0_101std_rtpc_bms_volt_1_4 ) );
					if ( i < 0 )
					{
						rtos_log ( LOG_ERR, "Error in sending CAN-frame 'rtpc_bms_volt_1_4'\n" );
					}
					else
					{
						FrameAnalysis ( &( signals_bo0_co0_101std_rtpc_bms_volt_1_4.Analysis_struct ), internalCANTime_bo0_co0 );

						setOutPortValue ( &outport_bo0_co0_101std_rtpc_bms_volt_1_4_timeStamp, internalCANTime_bo0_co0 );
					}
				}
			}

			counter_bo0_co0_101std_rtpc_bms_volt_1_4--;
			if ( counter_bo0_co0_101std_rtpc_bms_volt_1_4 < 0 )
			{
				counter_bo0_co0_101std_rtpc_bms_volt_1_4 = 0;
			}
		}
	}

	static double oldSingleShotSignalInport_bo0_co0_102std_rtpc_bms_volt_5_8 = 1;
	// ==========================================================================
	// 'Send'-Code for Frame 'rtpc_bms_volt_5_8' with  ID '102'.
	inTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 = (int32_t) getInPortValue ( &inport_inTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 );
	singleShotByInport = ( ( oldSingleShotSignalInport_bo0_co0_102std_rtpc_bms_volt_5_8 < 0.5 ) && ( getInPortValue ( &inport_singleShot_bo0_co0_102std_rtpc_bms_volt_5_8 ) > 0.5 ) ); // check single shot trigger transition, (check with 0.5 because of conversion from double to bool)
	oldSingleShotSignalInport_bo0_co0_102std_rtpc_bms_volt_5_8 =  getInPortValue ( &inport_singleShot_bo0_co0_102std_rtpc_bms_volt_5_8 );
	sendFrame = false; // if this bool turns to true the frame is sent
	cyclicSendConditionFulfilled = false; // if this bool turns to true one of the frame cyclic send conditions are fulfilled.
	spontanousSendConditionFulfilled = false; // if this bool turns to true one of the frame spontanous send conditions are fulfilled.

	// check manual send condition
	if (
	       (
	           ( inTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 == 0 )
	        || ( manualEnabled_bo0_co0_102std_rtpc_bms_volt_5_8 == false )
	       )
	    && 
	       (
	           ( singleShot_bo0_co0_102std_rtpc_bms_volt_5_8 == true )
	        || ( singleShotByInport == true )
	       )
	   )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
		singleShot_bo0_co0_102std_rtpc_bms_volt_5_8 = false;
	}

	// check remote trigger send condition
	if ( remoteTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 == true )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
	}

	if ( ( partEnabled_NewDB == true ) || ( partEnabled_NewDB_oldState == true ) )
	{
		//Reinitialize frame byte array if part was disabled in last cycle
		if ( ( partEnabled_NewDB != partEnabled_NewDB_oldState ) && ( partEnabled_NewDB_oldState == false ) )
		{
			// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
			InitFrameIxxatDataStruct ( &frame_bo0_co0_102std_rtpc_bms_volt_5_8, 0x102, dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

			// Overwrite sending cycle time
			cycleTime_bo0_co0_102std_rtpc_bms_volt_5_8 = 1;
		}

		//Reinitialize currently valid signal send modes
		sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 = 0;
		sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 = 0;
		sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 = 0;
		sendMode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 = 0;

		if ( partEnabled_NewDB == true )
		{
			bool counterIsZero = false;
			if ( counter_bo0_co0_102std_rtpc_bms_volt_5_8 == 0 )
			{
				counterIsZero = true;
				if ( inportCycleTime_bo0_co0_102std_rtpc_bms_volt_5_8 == true )
				{
					counter_bo0_co0_102std_rtpc_bms_volt_5_8 = (int32_t)( ( getInPortValue ( &inport_cycleTime_bo0_co0_102std_rtpc_bms_volt_5_8 ) * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}
				else
				{
					counter_bo0_co0_102std_rtpc_bms_volt_5_8 = (int32_t)( ( cycleTime_bo0_co0_102std_rtpc_bms_volt_5_8 * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}

				if ( manualEnabled_bo0_co0_102std_rtpc_bms_volt_5_8 == true )
				{
					// check cyclic condition
					if ( counterIsZero && ( inTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 != 0 ) )
					{
						cyclicSendConditionFulfilled = true;
						sendFrame = true;
					}
				}
			}
			// no spontanous send condition

			if ( cyclicSendConditionFulfilled == true )
			{
				// Initialize DLC of frame

				// use model DLC if manipulation is deactivated
				if ( dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8_manip == false )
				{
					// overwrite DLC of frame with specified byte count
					dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8 = 8;
				}
				// Check if DLC is in range of protocol specification
				if ( dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8 > 8 )
				{
					// overwrite DLC of frame with max supported byte count of protocol
					dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8 = 8;
				}

				signals_bo0_co0_102std_rtpc_bms_volt_5_8.Analysis_struct.DLC = dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8;
				frame_bo0_co0_102std_rtpc_bms_volt_5_8.dlc = dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8;

				// increment remote trigger if necessary
				if ( remoteTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 == true )
				{
					remoteTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 = false;
					double remoteCounter = 0.0;
					OUTPORT_REAL64_GETVALUE ( &outport_bo0_co0_102std_rtpc_bms_volt_5_8_remoteTrigger, remoteCounter );
					if ( remoteCounter > 2147483647 )
					{
						remoteCounter = 0;
					}

					setOutPortValue ( &outport_bo0_co0_102std_rtpc_bms_volt_5_8_remoteTrigger, remoteCounter + 1.0 );
				}

				// Copy (physical) signals from Inports to structure:
				if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 == CONFIG_VALS )
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V5 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V5 = getInPortValue ( &inport_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 );
				}
				if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 == CONFIG_VALS )
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V6 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V6 = getInPortValue ( &inport_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 );
				}
				if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 == CONFIG_VALS )
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V7 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V7 = getInPortValue ( &inport_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 );
				}
				if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 == CONFIG_VALS )
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V8 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V8 = getInPortValue ( &inport_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 );
				}

				// Compute bit-representation for all signals of the frame:
				//MONITORED Signals

				//UNMONITORED & COUNTER Signals only if it is clear that we have to send a frame
				if ( sendFrame == true )
				{
					// Signal 'Signal_Cell_V5'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V5 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V5 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V5 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V5 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V5 = signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V5;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V5 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V5 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V5 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V5 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V5 = signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V5;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 == MANIP_HEX )
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V5 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V5;
					}
					else
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V5 = lround ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V5 );
					}

					// Copy to internal variable
					intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V5;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V5 frame bo0_co0_102std_rtpc_bms_volt_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 0 ] = ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 );
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 1 ] = ( ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V5 >> 8 ) );
					// Signal 'Signal_Cell_V6'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V6 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V6 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V6 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V6 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V6 = signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V6;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V6 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V6 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V6 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V6 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V6 = signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V6;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 == MANIP_HEX )
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V6 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V6;
					}
					else
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V6 = lround ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V6 );
					}

					// Copy to internal variable
					intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V6;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V6 frame bo0_co0_102std_rtpc_bms_volt_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 2 ] = ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 );
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 3 ] = ( ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V6 >> 8 ) );
					// Signal 'Signal_Cell_V7'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V7 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V7 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V7 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V7 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V7 = signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V7;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V7 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V7 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V7 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V7 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V7 = signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V7;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 == MANIP_HEX )
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V7 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V7;
					}
					else
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V7 = lround ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V7 );
					}

					// Copy to internal variable
					intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V7;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V7 frame bo0_co0_102std_rtpc_bms_volt_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 4 ] = ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 );
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 5 ] = ( ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V7 >> 8 ) );
					// Signal 'Signal_Cell_V8'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V8 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V8 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V8 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V8 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V8 = signals_bo0_co0_102std_rtpc_bms_volt_5_8_manip.Signal_Cell_V8;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V8 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V8 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V8 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V8 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V8 = signals_bo0_co0_102std_rtpc_bms_volt_5_8.Signal_Cell_V8;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 == MANIP_HEX )
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V8 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_manip_Signal_Cell_V8;
					}
					else
					{
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V8 = lround ( signals_bo0_co0_102std_rtpc_bms_volt_5_8_limited.Signal_Cell_V8 );
					}

					// Copy to internal variable
					intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 = intern_bo0_co0_102std_rtpc_bms_volt_5_8_unlimited_Signal_Cell_V8;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V8 frame bo0_co0_102std_rtpc_bms_volt_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 6 ] = ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 );
					frame_bo0_co0_102std_rtpc_bms_volt_5_8.data[ 7 ] = ( ( intern_bo0_co0_102std_rtpc_bms_volt_5_8_Signal_Cell_V8 >> 8 ) );

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_102std_rtpc_bms_volt_5_8, frame_bo0_co0_102std_rtpc_bms_volt_5_8.data, dlcParam_bo0_co0_102std_rtpc_bms_volt_5_8 );

					i = rtos_comm_write ( can_handle_board0_controller0, &frame_bo0_co0_102std_rtpc_bms_volt_5_8, sizeof ( frame_bo0_co0_102std_rtpc_bms_volt_5_8 ) );
					if ( i < 0 )
					{
						rtos_log ( LOG_ERR, "Error in sending CAN-frame 'rtpc_bms_volt_5_8'\n" );
					}
					else
					{
						FrameAnalysis ( &( signals_bo0_co0_102std_rtpc_bms_volt_5_8.Analysis_struct ), internalCANTime_bo0_co0 );

						setOutPortValue ( &outport_bo0_co0_102std_rtpc_bms_volt_5_8_timeStamp, internalCANTime_bo0_co0 );
					}
				}
			}

			counter_bo0_co0_102std_rtpc_bms_volt_5_8--;
			if ( counter_bo0_co0_102std_rtpc_bms_volt_5_8 < 0 )
			{
				counter_bo0_co0_102std_rtpc_bms_volt_5_8 = 0;
			}
		}
	}

	static double oldSingleShotSignalInport_bo0_co0_103std_rtpc_bms_volt_9_12 = 1;
	// ==========================================================================
	// 'Send'-Code for Frame 'rtpc_bms_volt_9_12' with  ID '103'.
	inTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 = (int32_t) getInPortValue ( &inport_inTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 );
	singleShotByInport = ( ( oldSingleShotSignalInport_bo0_co0_103std_rtpc_bms_volt_9_12 < 0.5 ) && ( getInPortValue ( &inport_singleShot_bo0_co0_103std_rtpc_bms_volt_9_12 ) > 0.5 ) ); // check single shot trigger transition, (check with 0.5 because of conversion from double to bool)
	oldSingleShotSignalInport_bo0_co0_103std_rtpc_bms_volt_9_12 =  getInPortValue ( &inport_singleShot_bo0_co0_103std_rtpc_bms_volt_9_12 );
	sendFrame = false; // if this bool turns to true the frame is sent
	cyclicSendConditionFulfilled = false; // if this bool turns to true one of the frame cyclic send conditions are fulfilled.
	spontanousSendConditionFulfilled = false; // if this bool turns to true one of the frame spontanous send conditions are fulfilled.

	// check manual send condition
	if (
	       (
	           ( inTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 == 0 )
	        || ( manualEnabled_bo0_co0_103std_rtpc_bms_volt_9_12 == false )
	       )
	    && 
	       (
	           ( singleShot_bo0_co0_103std_rtpc_bms_volt_9_12 == true )
	        || ( singleShotByInport == true )
	       )
	   )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
		singleShot_bo0_co0_103std_rtpc_bms_volt_9_12 = false;
	}

	// check remote trigger send condition
	if ( remoteTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 == true )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
	}

	if ( ( partEnabled_NewDB == true ) || ( partEnabled_NewDB_oldState == true ) )
	{
		//Reinitialize frame byte array if part was disabled in last cycle
		if ( ( partEnabled_NewDB != partEnabled_NewDB_oldState ) && ( partEnabled_NewDB_oldState == false ) )
		{
			// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
			InitFrameIxxatDataStruct ( &frame_bo0_co0_103std_rtpc_bms_volt_9_12, 0x103, dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

			// Overwrite sending cycle time
			cycleTime_bo0_co0_103std_rtpc_bms_volt_9_12 = 1;
		}

		//Reinitialize currently valid signal send modes
		sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 = 0;
		sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 = 0;
		sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 = 0;
		sendMode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 = 0;

		if ( partEnabled_NewDB == true )
		{
			bool counterIsZero = false;
			if ( counter_bo0_co0_103std_rtpc_bms_volt_9_12 == 0 )
			{
				counterIsZero = true;
				if ( inportCycleTime_bo0_co0_103std_rtpc_bms_volt_9_12 == true )
				{
					counter_bo0_co0_103std_rtpc_bms_volt_9_12 = (int32_t)( ( getInPortValue ( &inport_cycleTime_bo0_co0_103std_rtpc_bms_volt_9_12 ) * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}
				else
				{
					counter_bo0_co0_103std_rtpc_bms_volt_9_12 = (int32_t)( ( cycleTime_bo0_co0_103std_rtpc_bms_volt_9_12 * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}

				if ( manualEnabled_bo0_co0_103std_rtpc_bms_volt_9_12 == true )
				{
					// check cyclic condition
					if ( counterIsZero && ( inTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 != 0 ) )
					{
						cyclicSendConditionFulfilled = true;
						sendFrame = true;
					}
				}
			}
			// no spontanous send condition

			if ( cyclicSendConditionFulfilled == true )
			{
				// Initialize DLC of frame

				// use model DLC if manipulation is deactivated
				if ( dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12_manip == false )
				{
					// overwrite DLC of frame with specified byte count
					dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12 = 8;
				}
				// Check if DLC is in range of protocol specification
				if ( dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12 > 8 )
				{
					// overwrite DLC of frame with max supported byte count of protocol
					dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12 = 8;
				}

				signals_bo0_co0_103std_rtpc_bms_volt_9_12.Analysis_struct.DLC = dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12;
				frame_bo0_co0_103std_rtpc_bms_volt_9_12.dlc = dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12;

				// increment remote trigger if necessary
				if ( remoteTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 == true )
				{
					remoteTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 = false;
					double remoteCounter = 0.0;
					OUTPORT_REAL64_GETVALUE ( &outport_bo0_co0_103std_rtpc_bms_volt_9_12_remoteTrigger, remoteCounter );
					if ( remoteCounter > 2147483647 )
					{
						remoteCounter = 0;
					}

					setOutPortValue ( &outport_bo0_co0_103std_rtpc_bms_volt_9_12_remoteTrigger, remoteCounter + 1.0 );
				}

				// Copy (physical) signals from Inports to structure:
				if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 == CONFIG_VALS )
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V10 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V10 = getInPortValue ( &inport_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 );
				}
				if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 == CONFIG_VALS )
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V11 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V11 = getInPortValue ( &inport_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 );
				}
				if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 == CONFIG_VALS )
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V12 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V12 = getInPortValue ( &inport_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 );
				}
				if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 == CONFIG_VALS )
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V9 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V9 = getInPortValue ( &inport_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 );
				}

				// Compute bit-representation for all signals of the frame:
				//MONITORED Signals

				//UNMONITORED & COUNTER Signals only if it is clear that we have to send a frame
				if ( sendFrame == true )
				{
					// Signal 'Signal_Cell_V10'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V10 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V10 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V10 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V10 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V10 = signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V10;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V10 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V10 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V10 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V10 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V10 = signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V10;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 == MANIP_HEX )
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V10 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V10;
					}
					else
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V10 = lround ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V10 );
					}

					// Copy to internal variable
					intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V10;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V10 frame bo0_co0_103std_rtpc_bms_volt_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 2 ] = ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 );
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 3 ] = ( ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V10 >> 8 ) );
					// Signal 'Signal_Cell_V11'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V11 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V11 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V11 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V11 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V11 = signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V11;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V11 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V11 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V11 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V11 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V11 = signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V11;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 == MANIP_HEX )
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V11 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V11;
					}
					else
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V11 = lround ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V11 );
					}

					// Copy to internal variable
					intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V11;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V11 frame bo0_co0_103std_rtpc_bms_volt_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 4 ] = ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 );
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 5 ] = ( ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V11 >> 8 ) );
					// Signal 'Signal_Cell_V12'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V12 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V12 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V12 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V12 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V12 = signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V12;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V12 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V12 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V12 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V12 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V12 = signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V12;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 == MANIP_HEX )
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V12 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V12;
					}
					else
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V12 = lround ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V12 );
					}

					// Copy to internal variable
					intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V12;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V12 frame bo0_co0_103std_rtpc_bms_volt_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 6 ] = ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 );
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 7 ] = ( ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V12 >> 8 ) );
					// Signal 'Signal_Cell_V9'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V9 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V9 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V9 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V9 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V9 = signals_bo0_co0_103std_rtpc_bms_volt_9_12_manip.Signal_Cell_V9;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V9 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V9 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V9 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V9 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V9 = signals_bo0_co0_103std_rtpc_bms_volt_9_12.Signal_Cell_V9;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 == MANIP_HEX )
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V9 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_manip_Signal_Cell_V9;
					}
					else
					{
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V9 = lround ( signals_bo0_co0_103std_rtpc_bms_volt_9_12_limited.Signal_Cell_V9 );
					}

					// Copy to internal variable
					intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 = intern_bo0_co0_103std_rtpc_bms_volt_9_12_unlimited_Signal_Cell_V9;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V9 frame bo0_co0_103std_rtpc_bms_volt_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 0 ] = ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 );
					frame_bo0_co0_103std_rtpc_bms_volt_9_12.data[ 1 ] = ( ( intern_bo0_co0_103std_rtpc_bms_volt_9_12_Signal_Cell_V9 >> 8 ) );

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_103std_rtpc_bms_volt_9_12, frame_bo0_co0_103std_rtpc_bms_volt_9_12.data, dlcParam_bo0_co0_103std_rtpc_bms_volt_9_12 );

					i = rtos_comm_write ( can_handle_board0_controller0, &frame_bo0_co0_103std_rtpc_bms_volt_9_12, sizeof ( frame_bo0_co0_103std_rtpc_bms_volt_9_12 ) );
					if ( i < 0 )
					{
						rtos_log ( LOG_ERR, "Error in sending CAN-frame 'rtpc_bms_volt_9_12'\n" );
					}
					else
					{
						FrameAnalysis ( &( signals_bo0_co0_103std_rtpc_bms_volt_9_12.Analysis_struct ), internalCANTime_bo0_co0 );

						setOutPortValue ( &outport_bo0_co0_103std_rtpc_bms_volt_9_12_timeStamp, internalCANTime_bo0_co0 );
					}
				}
			}

			counter_bo0_co0_103std_rtpc_bms_volt_9_12--;
			if ( counter_bo0_co0_103std_rtpc_bms_volt_9_12 < 0 )
			{
				counter_bo0_co0_103std_rtpc_bms_volt_9_12 = 0;
			}
		}
	}

	static double oldSingleShotSignalInport_bo0_co0_111std_rtpc_bms_temp_1_4 = 1;
	// ==========================================================================
	// 'Send'-Code for Frame 'rtpc_bms_temp_1_4' with  ID '111'.
	inTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 = (int32_t) getInPortValue ( &inport_inTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 );
	singleShotByInport = ( ( oldSingleShotSignalInport_bo0_co0_111std_rtpc_bms_temp_1_4 < 0.5 ) && ( getInPortValue ( &inport_singleShot_bo0_co0_111std_rtpc_bms_temp_1_4 ) > 0.5 ) ); // check single shot trigger transition, (check with 0.5 because of conversion from double to bool)
	oldSingleShotSignalInport_bo0_co0_111std_rtpc_bms_temp_1_4 =  getInPortValue ( &inport_singleShot_bo0_co0_111std_rtpc_bms_temp_1_4 );
	sendFrame = false; // if this bool turns to true the frame is sent
	cyclicSendConditionFulfilled = false; // if this bool turns to true one of the frame cyclic send conditions are fulfilled.
	spontanousSendConditionFulfilled = false; // if this bool turns to true one of the frame spontanous send conditions are fulfilled.

	// check manual send condition
	if (
	       (
	           ( inTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 == 0 )
	        || ( manualEnabled_bo0_co0_111std_rtpc_bms_temp_1_4 == false )
	       )
	    && 
	       (
	           ( singleShot_bo0_co0_111std_rtpc_bms_temp_1_4 == true )
	        || ( singleShotByInport == true )
	       )
	   )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
		singleShot_bo0_co0_111std_rtpc_bms_temp_1_4 = false;
	}

	// check remote trigger send condition
	if ( remoteTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 == true )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
	}

	if ( ( partEnabled_NewDB == true ) || ( partEnabled_NewDB_oldState == true ) )
	{
		//Reinitialize frame byte array if part was disabled in last cycle
		if ( ( partEnabled_NewDB != partEnabled_NewDB_oldState ) && ( partEnabled_NewDB_oldState == false ) )
		{
			// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
			InitFrameIxxatDataStruct ( &frame_bo0_co0_111std_rtpc_bms_temp_1_4, 0x111, dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

			// Overwrite sending cycle time
			cycleTime_bo0_co0_111std_rtpc_bms_temp_1_4 = 1;
		}

		//Reinitialize currently valid signal send modes
		sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 = 0;
		sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 = 0;
		sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 = 0;
		sendMode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 = 0;

		if ( partEnabled_NewDB == true )
		{
			bool counterIsZero = false;
			if ( counter_bo0_co0_111std_rtpc_bms_temp_1_4 == 0 )
			{
				counterIsZero = true;
				if ( inportCycleTime_bo0_co0_111std_rtpc_bms_temp_1_4 == true )
				{
					counter_bo0_co0_111std_rtpc_bms_temp_1_4 = (int32_t)( ( getInPortValue ( &inport_cycleTime_bo0_co0_111std_rtpc_bms_temp_1_4 ) * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}
				else
				{
					counter_bo0_co0_111std_rtpc_bms_temp_1_4 = (int32_t)( ( cycleTime_bo0_co0_111std_rtpc_bms_temp_1_4 * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}

				if ( manualEnabled_bo0_co0_111std_rtpc_bms_temp_1_4 == true )
				{
					// check cyclic condition
					if ( counterIsZero && ( inTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 != 0 ) )
					{
						cyclicSendConditionFulfilled = true;
						sendFrame = true;
					}
				}
			}
			// no spontanous send condition

			if ( cyclicSendConditionFulfilled == true )
			{
				// Initialize DLC of frame

				// use model DLC if manipulation is deactivated
				if ( dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4_manip == false )
				{
					// overwrite DLC of frame with specified byte count
					dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4 = 8;
				}
				// Check if DLC is in range of protocol specification
				if ( dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4 > 8 )
				{
					// overwrite DLC of frame with max supported byte count of protocol
					dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4 = 8;
				}

				signals_bo0_co0_111std_rtpc_bms_temp_1_4.Analysis_struct.DLC = dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4;
				frame_bo0_co0_111std_rtpc_bms_temp_1_4.dlc = dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4;

				// increment remote trigger if necessary
				if ( remoteTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 == true )
				{
					remoteTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 = false;
					double remoteCounter = 0.0;
					OUTPORT_REAL64_GETVALUE ( &outport_bo0_co0_111std_rtpc_bms_temp_1_4_remoteTrigger, remoteCounter );
					if ( remoteCounter > 2147483647 )
					{
						remoteCounter = 0;
					}

					setOutPortValue ( &outport_bo0_co0_111std_rtpc_bms_temp_1_4_remoteTrigger, remoteCounter + 1.0 );
				}

				// Copy (physical) signals from Inports to structure:
				if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 == CONFIG_VALS )
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T1 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T1 = getInPortValue ( &inport_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 );
				}
				if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 == CONFIG_VALS )
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T2 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T2 = getInPortValue ( &inport_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 );
				}
				if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 == CONFIG_VALS )
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T3 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T3 = getInPortValue ( &inport_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 );
				}
				if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 == CONFIG_VALS )
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T4 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T4 = getInPortValue ( &inport_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 );
				}

				// Compute bit-representation for all signals of the frame:
				//MONITORED Signals

				//UNMONITORED & COUNTER Signals only if it is clear that we have to send a frame
				if ( sendFrame == true )
				{
					// Signal 'Signal_Cell_T1'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T1 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T1 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T1 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T1 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T1 = signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T1;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T1 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T1 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T1 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T1 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T1 = signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T1;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 == MANIP_HEX )
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T1 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T1;
					}
					else
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T1 = lround ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T1 );
					}

					// Copy to internal variable
					intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T1;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T1 frame bo0_co0_111std_rtpc_bms_temp_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 0 ] = ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 );
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 1 ] = ( ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T1 >> 8 ) );
					// Signal 'Signal_Cell_T2'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T2 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T2 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T2 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T2 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T2 = signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T2;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T2 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T2 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T2 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T2 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T2 = signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T2;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 == MANIP_HEX )
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T2 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T2;
					}
					else
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T2 = lround ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T2 );
					}

					// Copy to internal variable
					intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T2;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T2 frame bo0_co0_111std_rtpc_bms_temp_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 2 ] = ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 );
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 3 ] = ( ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T2 >> 8 ) );
					// Signal 'Signal_Cell_T3'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T3 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T3 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T3 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T3 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T3 = signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T3;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T3 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T3 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T3 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T3 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T3 = signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T3;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 == MANIP_HEX )
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T3 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T3;
					}
					else
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T3 = lround ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T3 );
					}

					// Copy to internal variable
					intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T3;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T3 frame bo0_co0_111std_rtpc_bms_temp_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 4 ] = ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 );
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 5 ] = ( ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T3 >> 8 ) );
					// Signal 'Signal_Cell_T4'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T4 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T4 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T4 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T4 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T4 = signals_bo0_co0_111std_rtpc_bms_temp_1_4_manip.Signal_Cell_T4;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T4 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T4 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T4 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T4 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T4 = signals_bo0_co0_111std_rtpc_bms_temp_1_4.Signal_Cell_T4;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 == MANIP_HEX )
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T4 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_manip_Signal_Cell_T4;
					}
					else
					{
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T4 = lround ( signals_bo0_co0_111std_rtpc_bms_temp_1_4_limited.Signal_Cell_T4 );
					}

					// Copy to internal variable
					intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 = intern_bo0_co0_111std_rtpc_bms_temp_1_4_unlimited_Signal_Cell_T4;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T4 frame bo0_co0_111std_rtpc_bms_temp_1_4: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 6 ] = ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 );
					frame_bo0_co0_111std_rtpc_bms_temp_1_4.data[ 7 ] = ( ( intern_bo0_co0_111std_rtpc_bms_temp_1_4_Signal_Cell_T4 >> 8 ) );

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_111std_rtpc_bms_temp_1_4, frame_bo0_co0_111std_rtpc_bms_temp_1_4.data, dlcParam_bo0_co0_111std_rtpc_bms_temp_1_4 );

					i = rtos_comm_write ( can_handle_board0_controller0, &frame_bo0_co0_111std_rtpc_bms_temp_1_4, sizeof ( frame_bo0_co0_111std_rtpc_bms_temp_1_4 ) );
					if ( i < 0 )
					{
						rtos_log ( LOG_ERR, "Error in sending CAN-frame 'rtpc_bms_temp_1_4'\n" );
					}
					else
					{
						FrameAnalysis ( &( signals_bo0_co0_111std_rtpc_bms_temp_1_4.Analysis_struct ), internalCANTime_bo0_co0 );

						setOutPortValue ( &outport_bo0_co0_111std_rtpc_bms_temp_1_4_timeStamp, internalCANTime_bo0_co0 );
					}
				}
			}

			counter_bo0_co0_111std_rtpc_bms_temp_1_4--;
			if ( counter_bo0_co0_111std_rtpc_bms_temp_1_4 < 0 )
			{
				counter_bo0_co0_111std_rtpc_bms_temp_1_4 = 0;
			}
		}
	}

	static double oldSingleShotSignalInport_bo0_co0_112std_rtpc_bms_temp_5_8 = 1;
	// ==========================================================================
	// 'Send'-Code for Frame 'rtpc_bms_temp_5_8' with  ID '112'.
	inTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 = (int32_t) getInPortValue ( &inport_inTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 );
	singleShotByInport = ( ( oldSingleShotSignalInport_bo0_co0_112std_rtpc_bms_temp_5_8 < 0.5 ) && ( getInPortValue ( &inport_singleShot_bo0_co0_112std_rtpc_bms_temp_5_8 ) > 0.5 ) ); // check single shot trigger transition, (check with 0.5 because of conversion from double to bool)
	oldSingleShotSignalInport_bo0_co0_112std_rtpc_bms_temp_5_8 =  getInPortValue ( &inport_singleShot_bo0_co0_112std_rtpc_bms_temp_5_8 );
	sendFrame = false; // if this bool turns to true the frame is sent
	cyclicSendConditionFulfilled = false; // if this bool turns to true one of the frame cyclic send conditions are fulfilled.
	spontanousSendConditionFulfilled = false; // if this bool turns to true one of the frame spontanous send conditions are fulfilled.

	// check manual send condition
	if (
	       (
	           ( inTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 == 0 )
	        || ( manualEnabled_bo0_co0_112std_rtpc_bms_temp_5_8 == false )
	       )
	    && 
	       (
	           ( singleShot_bo0_co0_112std_rtpc_bms_temp_5_8 == true )
	        || ( singleShotByInport == true )
	       )
	   )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
		singleShot_bo0_co0_112std_rtpc_bms_temp_5_8 = false;
	}

	// check remote trigger send condition
	if ( remoteTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 == true )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
	}

	if ( ( partEnabled_NewDB == true ) || ( partEnabled_NewDB_oldState == true ) )
	{
		//Reinitialize frame byte array if part was disabled in last cycle
		if ( ( partEnabled_NewDB != partEnabled_NewDB_oldState ) && ( partEnabled_NewDB_oldState == false ) )
		{
			// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
			InitFrameIxxatDataStruct ( &frame_bo0_co0_112std_rtpc_bms_temp_5_8, 0x112, dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

			// Overwrite sending cycle time
			cycleTime_bo0_co0_112std_rtpc_bms_temp_5_8 = 1;
		}

		//Reinitialize currently valid signal send modes
		sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 = 0;
		sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 = 0;
		sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 = 0;
		sendMode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 = 0;

		if ( partEnabled_NewDB == true )
		{
			bool counterIsZero = false;
			if ( counter_bo0_co0_112std_rtpc_bms_temp_5_8 == 0 )
			{
				counterIsZero = true;
				if ( inportCycleTime_bo0_co0_112std_rtpc_bms_temp_5_8 == true )
				{
					counter_bo0_co0_112std_rtpc_bms_temp_5_8 = (int32_t)( ( getInPortValue ( &inport_cycleTime_bo0_co0_112std_rtpc_bms_temp_5_8 ) * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}
				else
				{
					counter_bo0_co0_112std_rtpc_bms_temp_5_8 = (int32_t)( ( cycleTime_bo0_co0_112std_rtpc_bms_temp_5_8 * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}

				if ( manualEnabled_bo0_co0_112std_rtpc_bms_temp_5_8 == true )
				{
					// check cyclic condition
					if ( counterIsZero && ( inTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 != 0 ) )
					{
						cyclicSendConditionFulfilled = true;
						sendFrame = true;
					}
				}
			}
			// no spontanous send condition

			if ( cyclicSendConditionFulfilled == true )
			{
				// Initialize DLC of frame

				// use model DLC if manipulation is deactivated
				if ( dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8_manip == false )
				{
					// overwrite DLC of frame with specified byte count
					dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8 = 8;
				}
				// Check if DLC is in range of protocol specification
				if ( dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8 > 8 )
				{
					// overwrite DLC of frame with max supported byte count of protocol
					dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8 = 8;
				}

				signals_bo0_co0_112std_rtpc_bms_temp_5_8.Analysis_struct.DLC = dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8;
				frame_bo0_co0_112std_rtpc_bms_temp_5_8.dlc = dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8;

				// increment remote trigger if necessary
				if ( remoteTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 == true )
				{
					remoteTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 = false;
					double remoteCounter = 0.0;
					OUTPORT_REAL64_GETVALUE ( &outport_bo0_co0_112std_rtpc_bms_temp_5_8_remoteTrigger, remoteCounter );
					if ( remoteCounter > 2147483647 )
					{
						remoteCounter = 0;
					}

					setOutPortValue ( &outport_bo0_co0_112std_rtpc_bms_temp_5_8_remoteTrigger, remoteCounter + 1.0 );
				}

				// Copy (physical) signals from Inports to structure:
				if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 == CONFIG_VALS )
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T5 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T5 = getInPortValue ( &inport_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 );
				}
				if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 == CONFIG_VALS )
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T6 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T6 = getInPortValue ( &inport_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 );
				}
				if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 == CONFIG_VALS )
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T7 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T7 = getInPortValue ( &inport_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 );
				}
				if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 == CONFIG_VALS )
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_V8 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_V8 = getInPortValue ( &inport_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 );
				}

				// Compute bit-representation for all signals of the frame:
				//MONITORED Signals

				//UNMONITORED & COUNTER Signals only if it is clear that we have to send a frame
				if ( sendFrame == true )
				{
					// Signal 'Signal_Cell_T5'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T5 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T5 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T5 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T5 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T5 = signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T5;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T5 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T5 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T5 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T5 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T5 = signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T5;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 == MANIP_HEX )
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T5 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_T5;
					}
					else
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T5 = lround ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T5 );
					}

					// Copy to internal variable
					intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T5;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T5 frame bo0_co0_112std_rtpc_bms_temp_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 0 ] = ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 );
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 1 ] = ( ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T5 >> 8 ) );
					// Signal 'Signal_Cell_T6'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T6 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T6 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T6 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T6 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T6 = signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T6;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T6 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T6 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T6 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T6 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T6 = signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T6;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 == MANIP_HEX )
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T6 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_T6;
					}
					else
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T6 = lround ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T6 );
					}

					// Copy to internal variable
					intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T6;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T6 frame bo0_co0_112std_rtpc_bms_temp_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 2 ] = ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 );
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 3 ] = ( ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T6 >> 8 ) );
					// Signal 'Signal_Cell_T7'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T7 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T7 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T7 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T7 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T7 = signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_T7;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T7 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T7 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T7 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T7 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T7 = signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_T7;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 == MANIP_HEX )
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T7 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_T7;
					}
					else
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T7 = lround ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_T7 );
					}

					// Copy to internal variable
					intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_T7;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T7 frame bo0_co0_112std_rtpc_bms_temp_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 4 ] = ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 );
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 5 ] = ( ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_T7 >> 8 ) );
					// Signal 'Signal_Cell_V8'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_V8 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_V8 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_V8 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_V8 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_V8 = signals_bo0_co0_112std_rtpc_bms_temp_5_8_manip.Signal_Cell_V8;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_V8 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_V8 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_V8 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_V8 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_V8 = signals_bo0_co0_112std_rtpc_bms_temp_5_8.Signal_Cell_V8;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 == MANIP_HEX )
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_V8 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_manip_Signal_Cell_V8;
					}
					else
					{
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_V8 = lround ( signals_bo0_co0_112std_rtpc_bms_temp_5_8_limited.Signal_Cell_V8 );
					}

					// Copy to internal variable
					intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 = intern_bo0_co0_112std_rtpc_bms_temp_5_8_unlimited_Signal_Cell_V8;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_V8 frame bo0_co0_112std_rtpc_bms_temp_5_8: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 6 ] = ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 );
					frame_bo0_co0_112std_rtpc_bms_temp_5_8.data[ 7 ] = ( ( intern_bo0_co0_112std_rtpc_bms_temp_5_8_Signal_Cell_V8 >> 8 ) );

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_112std_rtpc_bms_temp_5_8, frame_bo0_co0_112std_rtpc_bms_temp_5_8.data, dlcParam_bo0_co0_112std_rtpc_bms_temp_5_8 );

					i = rtos_comm_write ( can_handle_board0_controller0, &frame_bo0_co0_112std_rtpc_bms_temp_5_8, sizeof ( frame_bo0_co0_112std_rtpc_bms_temp_5_8 ) );
					if ( i < 0 )
					{
						rtos_log ( LOG_ERR, "Error in sending CAN-frame 'rtpc_bms_temp_5_8'\n" );
					}
					else
					{
						FrameAnalysis ( &( signals_bo0_co0_112std_rtpc_bms_temp_5_8.Analysis_struct ), internalCANTime_bo0_co0 );

						setOutPortValue ( &outport_bo0_co0_112std_rtpc_bms_temp_5_8_timeStamp, internalCANTime_bo0_co0 );
					}
				}
			}

			counter_bo0_co0_112std_rtpc_bms_temp_5_8--;
			if ( counter_bo0_co0_112std_rtpc_bms_temp_5_8 < 0 )
			{
				counter_bo0_co0_112std_rtpc_bms_temp_5_8 = 0;
			}
		}
	}

	static double oldSingleShotSignalInport_bo0_co0_113std_rtpc_bms_temp_9_12 = 1;
	// ==========================================================================
	// 'Send'-Code for Frame 'rtpc_bms_temp_9_12' with  ID '113'.
	inTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 = (int32_t) getInPortValue ( &inport_inTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 );
	singleShotByInport = ( ( oldSingleShotSignalInport_bo0_co0_113std_rtpc_bms_temp_9_12 < 0.5 ) && ( getInPortValue ( &inport_singleShot_bo0_co0_113std_rtpc_bms_temp_9_12 ) > 0.5 ) ); // check single shot trigger transition, (check with 0.5 because of conversion from double to bool)
	oldSingleShotSignalInport_bo0_co0_113std_rtpc_bms_temp_9_12 =  getInPortValue ( &inport_singleShot_bo0_co0_113std_rtpc_bms_temp_9_12 );
	sendFrame = false; // if this bool turns to true the frame is sent
	cyclicSendConditionFulfilled = false; // if this bool turns to true one of the frame cyclic send conditions are fulfilled.
	spontanousSendConditionFulfilled = false; // if this bool turns to true one of the frame spontanous send conditions are fulfilled.

	// check manual send condition
	if (
	       (
	           ( inTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 == 0 )
	        || ( manualEnabled_bo0_co0_113std_rtpc_bms_temp_9_12 == false )
	       )
	    && 
	       (
	           ( singleShot_bo0_co0_113std_rtpc_bms_temp_9_12 == true )
	        || ( singleShotByInport == true )
	       )
	   )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
		singleShot_bo0_co0_113std_rtpc_bms_temp_9_12 = false;
	}

	// check remote trigger send condition
	if ( remoteTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 == true )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
	}

	if ( ( partEnabled_NewDB == true ) || ( partEnabled_NewDB_oldState == true ) )
	{
		//Reinitialize frame byte array if part was disabled in last cycle
		if ( ( partEnabled_NewDB != partEnabled_NewDB_oldState ) && ( partEnabled_NewDB_oldState == false ) )
		{
			// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
			InitFrameIxxatDataStruct ( &frame_bo0_co0_113std_rtpc_bms_temp_9_12, 0x113, dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

			// Overwrite sending cycle time
			cycleTime_bo0_co0_113std_rtpc_bms_temp_9_12 = 1;
		}

		//Reinitialize currently valid signal send modes
		sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 = 0;
		sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 = 0;
		sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 = 0;
		sendMode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 = 0;

		if ( partEnabled_NewDB == true )
		{
			bool counterIsZero = false;
			if ( counter_bo0_co0_113std_rtpc_bms_temp_9_12 == 0 )
			{
				counterIsZero = true;
				if ( inportCycleTime_bo0_co0_113std_rtpc_bms_temp_9_12 == true )
				{
					counter_bo0_co0_113std_rtpc_bms_temp_9_12 = (int32_t)( ( getInPortValue ( &inport_cycleTime_bo0_co0_113std_rtpc_bms_temp_9_12 ) * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}
				else
				{
					counter_bo0_co0_113std_rtpc_bms_temp_9_12 = (int32_t)( ( cycleTime_bo0_co0_113std_rtpc_bms_temp_9_12 * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}

				if ( manualEnabled_bo0_co0_113std_rtpc_bms_temp_9_12 == true )
				{
					// check cyclic condition
					if ( counterIsZero && ( inTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 != 0 ) )
					{
						cyclicSendConditionFulfilled = true;
						sendFrame = true;
					}
				}
			}
			// no spontanous send condition

			if ( cyclicSendConditionFulfilled == true )
			{
				// Initialize DLC of frame

				// use model DLC if manipulation is deactivated
				if ( dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12_manip == false )
				{
					// overwrite DLC of frame with specified byte count
					dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12 = 8;
				}
				// Check if DLC is in range of protocol specification
				if ( dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12 > 8 )
				{
					// overwrite DLC of frame with max supported byte count of protocol
					dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12 = 8;
				}

				signals_bo0_co0_113std_rtpc_bms_temp_9_12.Analysis_struct.DLC = dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12;
				frame_bo0_co0_113std_rtpc_bms_temp_9_12.dlc = dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12;

				// increment remote trigger if necessary
				if ( remoteTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 == true )
				{
					remoteTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 = false;
					double remoteCounter = 0.0;
					OUTPORT_REAL64_GETVALUE ( &outport_bo0_co0_113std_rtpc_bms_temp_9_12_remoteTrigger, remoteCounter );
					if ( remoteCounter > 2147483647 )
					{
						remoteCounter = 0;
					}

					setOutPortValue ( &outport_bo0_co0_113std_rtpc_bms_temp_9_12_remoteTrigger, remoteCounter + 1.0 );
				}

				// Copy (physical) signals from Inports to structure:
				if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 == CONFIG_VALS )
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T10 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T10 = getInPortValue ( &inport_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 );
				}
				if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 == CONFIG_VALS )
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T11 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T11 = getInPortValue ( &inport_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 );
				}
				if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 == CONFIG_VALS )
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T12 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T12 = getInPortValue ( &inport_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 );
				}
				if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 == CONFIG_VALS )
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T9 = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T9 = getInPortValue ( &inport_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 );
				}

				// Compute bit-representation for all signals of the frame:
				//MONITORED Signals

				//UNMONITORED & COUNTER Signals only if it is clear that we have to send a frame
				if ( sendFrame == true )
				{
					// Signal 'Signal_Cell_T10'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T10 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T10 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T10 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T10 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T10 = signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T10;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T10 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T10 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T10 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T10 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T10 = signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T10;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 == MANIP_HEX )
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T10 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T10;
					}
					else
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T10 = lround ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T10 );
					}

					// Copy to internal variable
					intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T10;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T10 frame bo0_co0_113std_rtpc_bms_temp_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 2 ] = ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 );
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 3 ] = ( ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T10 >> 8 ) );
					// Signal 'Signal_Cell_T11'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T11 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T11 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T11 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T11 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T11 = signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T11;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T11 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T11 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T11 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T11 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T11 = signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T11;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 == MANIP_HEX )
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T11 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T11;
					}
					else
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T11 = lround ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T11 );
					}

					// Copy to internal variable
					intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T11;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T11 frame bo0_co0_113std_rtpc_bms_temp_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 4 ] = ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 );
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 5 ] = ( ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T11 >> 8 ) );
					// Signal 'Signal_Cell_T12'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T12 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T12 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T12 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T12 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T12 = signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T12;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T12 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T12 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T12 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T12 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T12 = signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T12;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 == MANIP_HEX )
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T12 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T12;
					}
					else
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T12 = lround ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T12 );
					}

					// Copy to internal variable
					intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T12;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T12 frame bo0_co0_113std_rtpc_bms_temp_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 6 ] = ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 );
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 7 ] = ( ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T12 >> 8 ) );
					// Signal 'Signal_Cell_T9'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 == MANIP_PHYS )
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T9 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T9 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T9 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T9 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T9 = signals_bo0_co0_113std_rtpc_bms_temp_9_12_manip.Signal_Cell_T9;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T9 > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T9 = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T9 < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T9 = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T9 = signals_bo0_co0_113std_rtpc_bms_temp_9_12.Signal_Cell_T9;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 == MANIP_HEX )
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T9 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_manip_Signal_Cell_T9;
					}
					else
					{
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T9 = lround ( signals_bo0_co0_113std_rtpc_bms_temp_9_12_limited.Signal_Cell_T9 );
					}

					// Copy to internal variable
					intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 = intern_bo0_co0_113std_rtpc_bms_temp_9_12_unlimited_Signal_Cell_T9;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Cell_T9 frame bo0_co0_113std_rtpc_bms_temp_9_12: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 0 ] = ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 );
					frame_bo0_co0_113std_rtpc_bms_temp_9_12.data[ 1 ] = ( ( intern_bo0_co0_113std_rtpc_bms_temp_9_12_Signal_Cell_T9 >> 8 ) );

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_113std_rtpc_bms_temp_9_12, frame_bo0_co0_113std_rtpc_bms_temp_9_12.data, dlcParam_bo0_co0_113std_rtpc_bms_temp_9_12 );

					i = rtos_comm_write ( can_handle_board0_controller0, &frame_bo0_co0_113std_rtpc_bms_temp_9_12, sizeof ( frame_bo0_co0_113std_rtpc_bms_temp_9_12 ) );
					if ( i < 0 )
					{
						rtos_log ( LOG_ERR, "Error in sending CAN-frame 'rtpc_bms_temp_9_12'\n" );
					}
					else
					{
						FrameAnalysis ( &( signals_bo0_co0_113std_rtpc_bms_temp_9_12.Analysis_struct ), internalCANTime_bo0_co0 );

						setOutPortValue ( &outport_bo0_co0_113std_rtpc_bms_temp_9_12_timeStamp, internalCANTime_bo0_co0 );
					}
				}
			}

			counter_bo0_co0_113std_rtpc_bms_temp_9_12--;
			if ( counter_bo0_co0_113std_rtpc_bms_temp_9_12 < 0 )
			{
				counter_bo0_co0_113std_rtpc_bms_temp_9_12 = 0;
			}
		}
	}

	static double oldSingleShotSignalInport_bo0_co0_131std_rtpc_bms_sammeln = 1;
	// ==========================================================================
	// 'Send'-Code for Frame 'rtpc_bms_sammeln' with  ID '131'.
	inTrigger_bo0_co0_131std_rtpc_bms_sammeln = (int32_t) getInPortValue ( &inport_inTrigger_bo0_co0_131std_rtpc_bms_sammeln );
	singleShotByInport = ( ( oldSingleShotSignalInport_bo0_co0_131std_rtpc_bms_sammeln < 0.5 ) && ( getInPortValue ( &inport_singleShot_bo0_co0_131std_rtpc_bms_sammeln ) > 0.5 ) ); // check single shot trigger transition, (check with 0.5 because of conversion from double to bool)
	oldSingleShotSignalInport_bo0_co0_131std_rtpc_bms_sammeln =  getInPortValue ( &inport_singleShot_bo0_co0_131std_rtpc_bms_sammeln );
	sendFrame = false; // if this bool turns to true the frame is sent
	cyclicSendConditionFulfilled = false; // if this bool turns to true one of the frame cyclic send conditions are fulfilled.
	spontanousSendConditionFulfilled = false; // if this bool turns to true one of the frame spontanous send conditions are fulfilled.

	// check manual send condition
	if (
	       (
	           ( inTrigger_bo0_co0_131std_rtpc_bms_sammeln == 0 )
	        || ( manualEnabled_bo0_co0_131std_rtpc_bms_sammeln == false )
	       )
	    && 
	       (
	           ( singleShot_bo0_co0_131std_rtpc_bms_sammeln == true )
	        || ( singleShotByInport == true )
	       )
	   )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
		singleShot_bo0_co0_131std_rtpc_bms_sammeln = false;
	}

	// check remote trigger send condition
	if ( remoteTrigger_bo0_co0_131std_rtpc_bms_sammeln == true )
	{
		cyclicSendConditionFulfilled = true;
		spontanousSendConditionFulfilled = true;
		sendFrame = true;
	}

	if ( ( partEnabled_NewDB == true ) || ( partEnabled_NewDB_oldState == true ) )
	{
		//Reinitialize frame byte array if part was disabled in last cycle
		if ( ( partEnabled_NewDB != partEnabled_NewDB_oldState ) && ( partEnabled_NewDB_oldState == false ) )
		{
			// Call InitFrameIxxatDataStruct for frame with parameters ( struct, id, dlc, mff, initDataArray, initialDataBytePattern ) 
			InitFrameIxxatDataStruct ( &frame_bo0_co0_131std_rtpc_bms_sammeln, 0x131, dlcParam_bo0_co0_131std_rtpc_bms_sammeln, IXXAT_CAN_MFF_11_DAT, true, 0x0 );

			// Overwrite sending cycle time
			cycleTime_bo0_co0_131std_rtpc_bms_sammeln = 1;
		}

		//Reinitialize currently valid signal send modes
		sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp = 0;
		sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden = 0;
		sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode = 0;
		sendMode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt = 0;

		if ( partEnabled_NewDB == true )
		{
			bool counterIsZero = false;
			if ( counter_bo0_co0_131std_rtpc_bms_sammeln == 0 )
			{
				counterIsZero = true;
				if ( inportCycleTime_bo0_co0_131std_rtpc_bms_sammeln == true )
				{
					counter_bo0_co0_131std_rtpc_bms_sammeln = (int32_t)( ( getInPortValue ( &inport_cycleTime_bo0_co0_131std_rtpc_bms_sammeln ) * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}
				else
				{
					counter_bo0_co0_131std_rtpc_bms_sammeln = (int32_t)( ( cycleTime_bo0_co0_131std_rtpc_bms_sammeln * canBaseRateInv_bo0_co0 ) + 0.000001 );
				}

				if ( manualEnabled_bo0_co0_131std_rtpc_bms_sammeln == true )
				{
					// check cyclic condition
					if ( counterIsZero && ( inTrigger_bo0_co0_131std_rtpc_bms_sammeln != 0 ) )
					{
						cyclicSendConditionFulfilled = true;
						sendFrame = true;
					}
				}
			}
			// no spontanous send condition

			if ( cyclicSendConditionFulfilled == true )
			{
				// Initialize DLC of frame

				// use model DLC if manipulation is deactivated
				if ( dlcParam_bo0_co0_131std_rtpc_bms_sammeln_manip == false )
				{
					// overwrite DLC of frame with specified byte count
					dlcParam_bo0_co0_131std_rtpc_bms_sammeln = 8;
				}
				// Check if DLC is in range of protocol specification
				if ( dlcParam_bo0_co0_131std_rtpc_bms_sammeln > 8 )
				{
					// overwrite DLC of frame with max supported byte count of protocol
					dlcParam_bo0_co0_131std_rtpc_bms_sammeln = 8;
				}

				signals_bo0_co0_131std_rtpc_bms_sammeln.Analysis_struct.DLC = dlcParam_bo0_co0_131std_rtpc_bms_sammeln;
				frame_bo0_co0_131std_rtpc_bms_sammeln.dlc = dlcParam_bo0_co0_131std_rtpc_bms_sammeln;

				// increment remote trigger if necessary
				if ( remoteTrigger_bo0_co0_131std_rtpc_bms_sammeln == true )
				{
					remoteTrigger_bo0_co0_131std_rtpc_bms_sammeln = false;
					double remoteCounter = 0.0;
					OUTPORT_REAL64_GETVALUE ( &outport_bo0_co0_131std_rtpc_bms_sammeln_remoteTrigger, remoteCounter );
					if ( remoteCounter > 2147483647 )
					{
						remoteCounter = 0;
					}

					setOutPortValue ( &outport_bo0_co0_131std_rtpc_bms_sammeln_remoteTrigger, remoteCounter + 1.0 );
				}

				// Copy (physical) signals from Inports to structure:
				if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp == CONFIG_VALS )
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Absolute_Amp = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Absolute_Amp = getInPortValue ( &inport_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp );
				}
				if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden == CONFIG_VALS )
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Laden = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Laden = getInPortValue ( &inport_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden );
				}
				if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode == CONFIG_VALS )
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Mode = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Mode = getInPortValue ( &inport_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode );
				}
				if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt == CONFIG_VALS )
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Total_volt = 0.0000000000000000e+000;
				}
				else
				{
					signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Total_volt = getInPortValue ( &inport_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt );
				}

				// Compute bit-representation for all signals of the frame:
				//MONITORED Signals

				//UNMONITORED & COUNTER Signals only if it is clear that we have to send a frame
				if ( sendFrame == true )
				{
					// Signal 'Signal_Absolute_Amp'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp == MANIP_PHYS )
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Absolute_Amp > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Absolute_Amp = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Absolute_Amp < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Absolute_Amp = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Absolute_Amp = signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Absolute_Amp;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Absolute_Amp > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Absolute_Amp = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Absolute_Amp < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Absolute_Amp = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Absolute_Amp = signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Absolute_Amp;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp == MANIP_HEX )
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Absolute_Amp = intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Absolute_Amp;
					}
					else
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Absolute_Amp = lround ( signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Absolute_Amp );
					}

					// Copy to internal variable
					intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp = intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Absolute_Amp;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Absolute_Amp frame bo0_co0_131std_rtpc_bms_sammeln: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 4 ] = ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp );
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 5 ] = ( ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Absolute_Amp >> 8 ) );
					// Signal 'Signal_Laden'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden == MANIP_PHYS )
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Laden > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Laden = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Laden < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Laden = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Laden = signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Laden;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Laden > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Laden = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Laden < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Laden = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Laden = signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Laden;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden == MANIP_HEX )
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Laden = intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Laden;
					}
					else
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Laden = lround ( signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Laden );
					}

					// Copy to internal variable
					intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden = intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Laden;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Laden frame bo0_co0_131std_rtpc_bms_sammeln: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 6 ] = ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden );
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 7 ] = ( ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Laden >> 8 ) );
					// Signal 'Signal_Mode'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode == MANIP_PHYS )
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Mode > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Mode = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Mode < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Mode = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Mode = signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Mode;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Mode > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Mode = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Mode < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Mode = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Mode = signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Mode;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode == MANIP_HEX )
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Mode = intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Mode;
					}
					else
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Mode = lround ( signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Mode );
					}

					// Copy to internal variable
					intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode = intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Mode;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Mode frame bo0_co0_131std_rtpc_bms_sammeln: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 0 ] = ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode );
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 1 ] = ( ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Mode >> 8 ) );
					// Signal 'Signal_Total_volt'
					// Check if model value or if manipulation of physical value
					// Limit to minimum/maximum
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt == MANIP_PHYS )
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Total_volt > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Total_volt = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Total_volt < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Total_volt = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Total_volt = signals_bo0_co0_131std_rtpc_bms_sammeln_manip.Signal_Total_volt;
						}
					}
					else  // Thus MODEL
					{
						if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Total_volt > 6.5535000000000000e+004 )
						{
							// maximum exceeded
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Total_volt = 6.5535000000000000e+004;
						}
						else if ( signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Total_volt < 0.0000000000000000e+000 )
						{
							// less than minimum
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Total_volt = 0.0000000000000000e+000;
						}
						else
						{
							// signal is within the limits
							signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Total_volt = signals_bo0_co0_131std_rtpc_bms_sammeln.Signal_Total_volt;
						}
					}

					// Check if model or if manipulation of hexadecimal value
					// Apply transformation formula if available
					if ( mode_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt == MANIP_HEX )
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Total_volt = intern_bo0_co0_131std_rtpc_bms_sammeln_manip_Signal_Total_volt;
					}
					else
					{
						intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Total_volt = lround ( signals_bo0_co0_131std_rtpc_bms_sammeln_limited.Signal_Total_volt );
					}

					// Copy to internal variable
					intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt = intern_bo0_co0_131std_rtpc_bms_sammeln_unlimited_Signal_Total_volt;

					// Check for limits due to bit length if necessary (i. e. bit length != 32, 64)
					if ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt > 65535 ) // 2^(bitcount) - 1
					{
						// Overflow
						intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt = 65535;
						rtos_log ( LOG_DEBUG, "Warning: Overflow for CAN signal Signal_Total_volt frame bo0_co0_131std_rtpc_bms_sammeln: Value is greater than the largest number representable as hex number!\n" );
					}

					// Enter signal into byte array
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 2 ] = ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt );
					frame_bo0_co0_131std_rtpc_bms_sammeln.data[ 3 ] = ( ( intern_bo0_co0_131std_rtpc_bms_sammeln_Signal_Total_volt >> 8 ) );

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_131std_rtpc_bms_sammeln, frame_bo0_co0_131std_rtpc_bms_sammeln.data, dlcParam_bo0_co0_131std_rtpc_bms_sammeln );

					i = rtos_comm_write ( can_handle_board0_controller0, &frame_bo0_co0_131std_rtpc_bms_sammeln, sizeof ( frame_bo0_co0_131std_rtpc_bms_sammeln ) );
					if ( i < 0 )
					{
						rtos_log ( LOG_ERR, "Error in sending CAN-frame 'rtpc_bms_sammeln'\n" );
					}
					else
					{
						FrameAnalysis ( &( signals_bo0_co0_131std_rtpc_bms_sammeln.Analysis_struct ), internalCANTime_bo0_co0 );

						setOutPortValue ( &outport_bo0_co0_131std_rtpc_bms_sammeln_timeStamp, internalCANTime_bo0_co0 );
					}
				}
			}

			counter_bo0_co0_131std_rtpc_bms_sammeln--;
			if ( counter_bo0_co0_131std_rtpc_bms_sammeln < 0 )
			{
				counter_bo0_co0_131std_rtpc_bms_sammeln = 0;
			}
		}
	}

	partEnabled_NewDB_oldState = partEnabled_NewDB;
	internalCANTime_bo0_co0 = internalCANTime_bo0_co0 + 1;

}


void CAN_Send_board0_controller1( void )
{
	// Variable declarations:
	int32_t i;
	bool singleShotByInport;

	bool sendFrame;
	bool cyclicSendConditionFulfilled;
	bool spontanousSendConditionFulfilled;


	// 'Send'-Code for all Frames of Controller 1 and Board 0:
	internalCANTime_bo0_co1 = internalCANTime_bo0_co1 + 0.5;

}



void CAN_Receive_board0_controller0()
{
	int32_t i;
	int32_t index;
	unsigned char* ptr;

	static double zeroTimeSystem;
	static uint64_t zeroTimeCANBoard;
	double currentTime;
	int32_t indID = -1;
	bool firstReceptionOfThisFrame = true;
	ixxat_can_data_t can_frame;

	// Process the 'Receive'-Frames:

	while ( 0 < rtos_comm_read ( can_handle_board0_controller0, &can_frame, sizeof ( can_frame ), 50000 ) )
	{
		indID = -1; // init for loop

		// A Frame has been received. Its ID is located in can_frame.id,
		// its data bytes are in the byte array can_frame.data.

		// 'Canalyzer'-specific analysis of received frame.
		if ( firstReceptionOfAnyFrame_board0_controller0 )
		{
			zeroTimeSystem = internalCANTime_bo0_co0;
			zeroTimeCANBoard = can_frame.time_stamp;
			firstReceptionOfAnyFrame_board0_controller0 = false;
		}

		currentTime = zeroTimeSystem + 0.000125 * ( can_frame.time_stamp - zeroTimeCANBoard );
		switch ( can_frame.mff )
		{
			case IXXAT_CAN_MFF_11_RMT:
			{
				// Trigger for send frames with standard identifier can_frame.id
				switch ( can_frame.id )
				{
					// set remote trigger or gateway enabled flag to true if frame match
					case 0x101:
					{
						remoteTrigger_bo0_co0_101std_rtpc_bms_volt_1_4 = true;
						break;
					}
					// set remote trigger or gateway enabled flag to true if frame match
					case 0x102:
					{
						remoteTrigger_bo0_co0_102std_rtpc_bms_volt_5_8 = true;
						break;
					}
					// set remote trigger or gateway enabled flag to true if frame match
					case 0x103:
					{
						remoteTrigger_bo0_co0_103std_rtpc_bms_volt_9_12 = true;
						break;
					}
					// set remote trigger or gateway enabled flag to true if frame match
					case 0x111:
					{
						remoteTrigger_bo0_co0_111std_rtpc_bms_temp_1_4 = true;
						break;
					}
					// set remote trigger or gateway enabled flag to true if frame match
					case 0x112:
					{
						remoteTrigger_bo0_co0_112std_rtpc_bms_temp_5_8 = true;
						break;
					}
					// set remote trigger or gateway enabled flag to true if frame match
					case 0x113:
					{
						remoteTrigger_bo0_co0_113std_rtpc_bms_temp_9_12 = true;
						break;
					}
					// set remote trigger or gateway enabled flag to true if frame match
					case 0x131:
					{
						remoteTrigger_bo0_co0_131std_rtpc_bms_sammeln = true;
						break;
					}
				}
				break;
			}
			case IXXAT_CAN_MFF_29_RMT:
			{
				// Trigger for send frames with extended identifier can_frame.id
				switch ( can_frame.id )
				{
				}
				break;
			}
		}

		// Check if the received frame is of interest; process it if necessary
		switch ( can_frame.id )
		{
			case 0x201: // frames with ID 201
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rtcp_volt_1_4'  ID 201
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_201std_bms_rtcp_volt_1_4, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Cell_V1':
					intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V1 = ( ( can_frame.data[ 0 ] & 0xFF ) ) | 
					( ( can_frame.data[ 1 ] & 0xFF )  << 8);
					signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V1 = intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V1;
					// Extract signal 'Signal_Cell_V2':
					intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V2 = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V2 = intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V2;
					// Extract signal 'Signal_Cell_V3':
					intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V3 = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V3 = intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V3;
					// Extract signal 'Signal_Cell_V4':
					intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V4 = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V4 = intern_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V4;
					FrameAnalysis ( &( signals_bo0_co0_201std_bms_rtcp_volt_1_4.Analysis_struct ), currentTime );
					signals_bo0_co0_201std_bms_rtcp_volt_1_4.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V1, signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V1 );
					setOutPortValue ( &outport_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V2, signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V2 );
					setOutPortValue ( &outport_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V3, signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V3 );
					setOutPortValue ( &outport_bo0_co0_201std_bms_rtcp_volt_1_4_Signal_Cell_V4, signals_bo0_co0_201std_bms_rtcp_volt_1_4.Signal_Cell_V4 );
					setOutPortValue ( &outport_bo0_co0_201std_bms_rtcp_volt_1_4_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			case 0x202: // frames with ID 202
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rctp_volt_5_8'  ID 202
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_202std_bms_rctp_volt_5_8, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Cell_V5':
					intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V5 = ( ( can_frame.data[ 0 ] & 0xFF ) ) | 
					( ( can_frame.data[ 1 ] & 0xFF )  << 8);
					signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V5 = intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V5;
					// Extract signal 'Signal_Cell_V6':
					intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V6 = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V6 = intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V6;
					// Extract signal 'Signal_Cell_V7':
					intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V7 = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V7 = intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V7;
					// Extract signal 'Signal_Cell_V8':
					intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V8 = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V8 = intern_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V8;
					FrameAnalysis ( &( signals_bo0_co0_202std_bms_rctp_volt_5_8.Analysis_struct ), currentTime );
					signals_bo0_co0_202std_bms_rctp_volt_5_8.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V5, signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V5 );
					setOutPortValue ( &outport_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V6, signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V6 );
					setOutPortValue ( &outport_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V7, signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V7 );
					setOutPortValue ( &outport_bo0_co0_202std_bms_rctp_volt_5_8_Signal_Cell_V8, signals_bo0_co0_202std_bms_rctp_volt_5_8.Signal_Cell_V8 );
					setOutPortValue ( &outport_bo0_co0_202std_bms_rctp_volt_5_8_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			case 0x203: // frames with ID 203
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rctp_volt_9_12'  ID 203
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_203std_bms_rctp_volt_9_12, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Cell_V10':
					intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V10 = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V10 = intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V10;
					// Extract signal 'Signal_Cell_V11':
					intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V11 = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V11 = intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V11;
					// Extract signal 'Signal_Cell_V12':
					intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V12 = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V12 = intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V12;
					// Extract signal 'Signal_Cell_V9':
					intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V9 = ( ( can_frame.data[ 0 ] & 0xFF ) ) | 
					( ( can_frame.data[ 1 ] & 0xFF )  << 8);
					signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V9 = intern_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V9;
					FrameAnalysis ( &( signals_bo0_co0_203std_bms_rctp_volt_9_12.Analysis_struct ), currentTime );
					signals_bo0_co0_203std_bms_rctp_volt_9_12.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V10, signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V10 );
					setOutPortValue ( &outport_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V11, signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V11 );
					setOutPortValue ( &outport_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V12, signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V12 );
					setOutPortValue ( &outport_bo0_co0_203std_bms_rctp_volt_9_12_Signal_Cell_V9, signals_bo0_co0_203std_bms_rctp_volt_9_12.Signal_Cell_V9 );
					setOutPortValue ( &outport_bo0_co0_203std_bms_rctp_volt_9_12_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			case 0x211: // frames with ID 211
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rctp_temp_1_4'  ID 211
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_211std_bms_rctp_temp_1_4, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Cell_T1':
					intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T1 = ( ( can_frame.data[ 0 ] & 0xFF ) ) | 
					( ( can_frame.data[ 1 ] & 0xFF )  << 8);
					signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T1 = intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T1;
					// Extract signal 'Signal_Cell_T2':
					intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T2 = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T2 = intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T2;
					// Extract signal 'Signal_Cell_T3':
					intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T3 = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T3 = intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T3;
					// Extract signal 'Signal_Cell_T4':
					intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T4 = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T4 = intern_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T4;
					FrameAnalysis ( &( signals_bo0_co0_211std_bms_rctp_temp_1_4.Analysis_struct ), currentTime );
					signals_bo0_co0_211std_bms_rctp_temp_1_4.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T1, signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T1 );
					setOutPortValue ( &outport_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T2, signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T2 );
					setOutPortValue ( &outport_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T3, signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T3 );
					setOutPortValue ( &outport_bo0_co0_211std_bms_rctp_temp_1_4_Signal_Cell_T4, signals_bo0_co0_211std_bms_rctp_temp_1_4.Signal_Cell_T4 );
					setOutPortValue ( &outport_bo0_co0_211std_bms_rctp_temp_1_4_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			case 0x212: // frames with ID 212
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rctp_temp_5_8'  ID 212
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_212std_bms_rctp_temp_5_8, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Cell_T5':
					intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T5 = ( ( can_frame.data[ 0 ] & 0xFF ) ) | 
					( ( can_frame.data[ 1 ] & 0xFF )  << 8);
					signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T5 = intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T5;
					// Extract signal 'Signal_Cell_T6':
					intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T6 = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T6 = intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T6;
					// Extract signal 'Signal_Cell_T7':
					intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T7 = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T7 = intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T7;
					// Extract signal 'Signal_Cell_T8':
					intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T8 = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T8 = intern_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T8;
					FrameAnalysis ( &( signals_bo0_co0_212std_bms_rctp_temp_5_8.Analysis_struct ), currentTime );
					signals_bo0_co0_212std_bms_rctp_temp_5_8.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T5, signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T5 );
					setOutPortValue ( &outport_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T6, signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T6 );
					setOutPortValue ( &outport_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T7, signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T7 );
					setOutPortValue ( &outport_bo0_co0_212std_bms_rctp_temp_5_8_Signal_Cell_T8, signals_bo0_co0_212std_bms_rctp_temp_5_8.Signal_Cell_T8 );
					setOutPortValue ( &outport_bo0_co0_212std_bms_rctp_temp_5_8_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			case 0x213: // frames with ID 213
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rctp_temp_9_12'  ID 213
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_213std_bms_rctp_temp_9_12, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Cell_T10':
					intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T10 = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T10 = intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T10;
					// Extract signal 'Signal_Cell_T11':
					intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T11 = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T11 = intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T11;
					// Extract signal 'Signal_Cell_T12':
					intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T12 = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T12 = intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T12;
					// Extract signal 'Signal_Cell_T9':
					intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T9 = ( ( can_frame.data[ 0 ] & 0xFF ) ) | 
					( ( can_frame.data[ 1 ] & 0xFF )  << 8);
					signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T9 = intern_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T9;
					FrameAnalysis ( &( signals_bo0_co0_213std_bms_rctp_temp_9_12.Analysis_struct ), currentTime );
					signals_bo0_co0_213std_bms_rctp_temp_9_12.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T10, signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T10 );
					setOutPortValue ( &outport_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T11, signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T11 );
					setOutPortValue ( &outport_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T12, signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T12 );
					setOutPortValue ( &outport_bo0_co0_213std_bms_rctp_temp_9_12_Signal_Cell_T9, signals_bo0_co0_213std_bms_rctp_temp_9_12.Signal_Cell_T9 );
					setOutPortValue ( &outport_bo0_co0_213std_bms_rctp_temp_9_12_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			case 0x221: // frames with ID 221
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rtcp_bal'  ID 221
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_221std_bms_rtcp_bal, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Cell_1':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_1 = ( can_frame.data[ 0 ] & 0x1 ) == 0x1;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_1 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_1;
					// Extract signal 'Signal_Cell_10':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_10 = ( can_frame.data[ 1 ] & 0x2 ) == 0x2;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_10 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_10;
					// Extract signal 'Signal_Cell_11':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_11 = ( can_frame.data[ 1 ] & 0x4 ) == 0x4;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_11 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_11;
					// Extract signal 'Signal_Cell_12':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_12 = ( can_frame.data[ 1 ] & 0x8 ) == 0x8;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_12 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_12;
					// Extract signal 'Signal_Cell_2':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_2 = ( can_frame.data[ 0 ] & 0x2 ) == 0x2;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_2 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_2;
					// Extract signal 'Signal_Cell_3':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_3 = ( can_frame.data[ 0 ] & 0x4 ) == 0x4;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_3 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_3;
					// Extract signal 'Signal_Cell_4':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_4 = ( can_frame.data[ 0 ] & 0x8 ) == 0x8;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_4 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_4;
					// Extract signal 'Signal_Cell_5':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_5 = ( can_frame.data[ 0 ] & 0x10 ) == 0x10;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_5 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_5;
					// Extract signal 'Signal_Cell_6':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_6 = ( can_frame.data[ 0 ] & 0x20 ) == 0x20;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_6 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_6;
					// Extract signal 'Signal_Cell_7':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_7 = ( can_frame.data[ 0 ] & 0x40 ) == 0x40;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_7 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_7;
					// Extract signal 'Signal_Cell_8':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_8 = ( can_frame.data[ 0 ] & 0x80 ) == 0x80;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_8 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_8;
					// Extract signal 'Signal_Cell_9':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_9 = ( can_frame.data[ 1 ] & 0x1 ) == 0x1;
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_9 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_9;
					// Extract signal 'Signal_Reserviert_1':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_1 = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Reserviert_1 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_1;
					// Extract signal 'Signal_Reserviert_2':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_2 = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Reserviert_2 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_2;
					// Extract signal 'Signal_Reserviert_3':
					intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_3 = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_221std_bms_rtcp_bal.Signal_Reserviert_3 = intern_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_3;
					FrameAnalysis ( &( signals_bo0_co0_221std_bms_rtcp_bal.Analysis_struct ), currentTime );
					signals_bo0_co0_221std_bms_rtcp_bal.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_1, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_1 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_10, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_10 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_11, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_11 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_12, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_12 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_2, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_2 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_3, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_3 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_4, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_4 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_5, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_5 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_6, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_6 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_7, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_7 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_8, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_8 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Cell_9, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Cell_9 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_1, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Reserviert_1 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_2, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Reserviert_2 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_Signal_Reserviert_3, signals_bo0_co0_221std_bms_rtcp_bal.Signal_Reserviert_3 );
					setOutPortValue ( &outport_bo0_co0_221std_bms_rtcp_bal_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			case 0x231: // frames with ID 231
			{
				if ( partEnabled_NewDB == true )
				{
					// frame 'bms_rtcp_sammeln'  ID 231
					indID = -2; // incidates a known message is processed

					// Copy byte array to frame-specific measure variable:
					memcpy ( byteArray_bo0_co0_231std_bms_rtcp_sammeln, can_frame.data, 8 );

					// Extract the signals from the frame data byte array:
					// Extract signal 'Signal_Absolut_Amp':
					intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Absolut_Amp = ( ( can_frame.data[ 4 ] & 0xFF ) ) | 
					( ( can_frame.data[ 5 ] & 0xFF )  << 8);
					signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_Absolut_Amp = intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Absolut_Amp;
					// Extract signal 'Signal_Laden':
					intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Laden = ( ( can_frame.data[ 6 ] & 0xFF ) ) | 
					( ( can_frame.data[ 7 ] & 0xFF )  << 8);
					signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_Laden = intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Laden;
					// Extract signal 'Signal_SoC':
					intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_SoC = ( ( can_frame.data[ 0 ] & 0xFF ) ) | 
					( ( can_frame.data[ 1 ] & 0xFF )  << 8);
					signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_SoC = intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_SoC;
					// Extract signal 'Signal_Total_Volt':
					intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Total_Volt = ( ( can_frame.data[ 2 ] & 0xFF ) ) | 
					( ( can_frame.data[ 3 ] & 0xFF )  << 8);
					signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_Total_Volt = intern_bo0_co0_231std_bms_rtcp_sammeln_Signal_Total_Volt;
					FrameAnalysis ( &( signals_bo0_co0_231std_bms_rtcp_sammeln.Analysis_struct ), currentTime );
					signals_bo0_co0_231std_bms_rtcp_sammeln.Analysis_struct.DLC = can_frame.dlc;

					// Copy (physical) signals from structure to Outports:
					setOutPortValue ( &outport_bo0_co0_231std_bms_rtcp_sammeln_Signal_Absolut_Amp, signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_Absolut_Amp );
					setOutPortValue ( &outport_bo0_co0_231std_bms_rtcp_sammeln_Signal_Laden, signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_Laden );
					setOutPortValue ( &outport_bo0_co0_231std_bms_rtcp_sammeln_Signal_SoC, signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_SoC );
					setOutPortValue ( &outport_bo0_co0_231std_bms_rtcp_sammeln_Signal_Total_Volt, signals_bo0_co0_231std_bms_rtcp_sammeln.Signal_Total_Volt );
					setOutPortValue ( &outport_bo0_co0_231std_bms_rtcp_sammeln_timeStamp, currentTime );
				}

				break; // a known receive frame has been processed - thats all we have to do -> continue while-loop
			}
			default:
			{
				// frame is not of interest -> continue
				break;
			}
		}

		for ( i = 0; i < noIDs_board0_controller0; ++i )
		{
			if ( can_frame.id == idArray_board0_controller0[i] )
			{
				indID = i;
				break;
			}
		}

		if ( indID == -1 )
		{
			if ( noIDs_board0_controller0 >= 10 )
			{
				continue; //continue loop -> frame unknown but arrays are full
			}

			// The index 'indID' was not yet in the list 'idArray', but there is space left to add it to it
			indID = noIDs_board0_controller0;
			idArray_board0_controller0[ indID ] = can_frame.id;
			noIDs_board0_controller0++;
			firstReceptionOfThisFrame = true;
		}
		else
		{
			firstReceptionOfThisFrame = false;
		}

		if ( indID >= 0 )
		{
			// The index 'indID' is in the list 'idArray' -> fill other arrays
			if ( firstReceptionOfThisFrame == false )
			{
				cycleTimeArray_board0_controller0[ indID ] = currentTime - timeArray_board0_controller0[ indID ];
				if ( minCycleTimeArray_board0_controller0[ indID ] > cycleTimeArray_board0_controller0[ indID ] )
				{
					minCycleTimeArray_board0_controller0[ indID ] = cycleTimeArray_board0_controller0[ indID ];
				}

				if ( maxCycleTimeArray_board0_controller0[ indID ] < cycleTimeArray_board0_controller0[ indID ] )
				{
					maxCycleTimeArray_board0_controller0[ indID ] = cycleTimeArray_board0_controller0[ indID ];
				}
			}

			timeArray_board0_controller0[ indID ] = currentTime;
			noActivitiesArray_board0_controller0[ indID ] = noActivitiesArray_board0_controller0[ indID ] + 1;

			if ( noActivitiesArray_board0_controller0[ indID ] > 1 )
			{
				averageCycleTimeArray_board0_controller0[ indID ] = ( cycleTimeArray_board0_controller0[ indID ] + ( noActivitiesArray_board0_controller0[ indID ] - 2 ) * averageCycleTimeArray_board0_controller0[ indID ] ) / ( noActivitiesArray_board0_controller0[ indID ] - 1 );
			}

			dlcArray_board0_controller0[ indID ] = can_frame.dlc;
			ptr = dataArrayAddresses_board0_controller0[ indID ];
			for ( index = 0; index < 8; ++index )
			{
				ptr[ index ] = can_frame.data[ index ];
			}
		}
	}
}


void CAN_Receive_board0_controller1()
{
	int32_t i;
	int32_t index;
	unsigned char* ptr;

	static double zeroTimeSystem;
	static uint64_t zeroTimeCANBoard;
	double currentTime;
	int32_t indID = -1;
	bool firstReceptionOfThisFrame = true;
	ixxat_can_data_t can_frame;

	// Process the 'Receive'-Frames:

	while ( 0 < rtos_comm_read ( can_handle_board0_controller1, &can_frame, sizeof ( can_frame ), 50000 ) )
	{
		indID = -1; // init for loop

		// A Frame has been received. Its ID is located in can_frame.id,
		// its data bytes are in the byte array can_frame.data.

		// 'Canalyzer'-specific analysis of received frame.
		if ( firstReceptionOfAnyFrame_board0_controller1 )
		{
			zeroTimeSystem = internalCANTime_bo0_co1;
			zeroTimeCANBoard = can_frame.time_stamp;
			firstReceptionOfAnyFrame_board0_controller1 = false;
		}

		currentTime = zeroTimeSystem + 0.000125 * ( can_frame.time_stamp - zeroTimeCANBoard );
		switch ( can_frame.mff )
		{
			case IXXAT_CAN_MFF_11_RMT:
			{
				// Trigger for send frames with standard identifier can_frame.id
				switch ( can_frame.id )
				{
				}
				break;
			}
			case IXXAT_CAN_MFF_29_RMT:
			{
				// Trigger for send frames with extended identifier can_frame.id
				switch ( can_frame.id )
				{
				}
				break;
			}
		}

		// Check if the received frame is of interest; process it if necessary
		switch ( can_frame.id )
		{
			default:
			{
				// frame is not of interest -> continue
				break;
			}
		}

		for ( i = 0; i < noIDs_board0_controller1; ++i )
		{
			if ( can_frame.id == idArray_board0_controller1[i] )
			{
				indID = i;
				break;
			}
		}

		if ( indID == -1 )
		{
			if ( noIDs_board0_controller1 >= 10 )
			{
				continue; //continue loop -> frame unknown but arrays are full
			}

			// The index 'indID' was not yet in the list 'idArray', but there is space left to add it to it
			indID = noIDs_board0_controller1;
			idArray_board0_controller1[ indID ] = can_frame.id;
			noIDs_board0_controller1++;
			firstReceptionOfThisFrame = true;
		}
		else
		{
			firstReceptionOfThisFrame = false;
		}

		if ( indID >= 0 )
		{
			// The index 'indID' is in the list 'idArray' -> fill other arrays
			if ( firstReceptionOfThisFrame == false )
			{
				cycleTimeArray_board0_controller1[ indID ] = currentTime - timeArray_board0_controller1[ indID ];
				if ( minCycleTimeArray_board0_controller1[ indID ] > cycleTimeArray_board0_controller1[ indID ] )
				{
					minCycleTimeArray_board0_controller1[ indID ] = cycleTimeArray_board0_controller1[ indID ];
				}

				if ( maxCycleTimeArray_board0_controller1[ indID ] < cycleTimeArray_board0_controller1[ indID ] )
				{
					maxCycleTimeArray_board0_controller1[ indID ] = cycleTimeArray_board0_controller1[ indID ];
				}
			}

			timeArray_board0_controller1[ indID ] = currentTime;
			noActivitiesArray_board0_controller1[ indID ] = noActivitiesArray_board0_controller1[ indID ] + 1;

			if ( noActivitiesArray_board0_controller1[ indID ] > 1 )
			{
				averageCycleTimeArray_board0_controller1[ indID ] = ( cycleTimeArray_board0_controller1[ indID ] + ( noActivitiesArray_board0_controller1[ indID ] - 2 ) * averageCycleTimeArray_board0_controller1[ indID ] ) / ( noActivitiesArray_board0_controller1[ indID ] - 1 );
			}

			dlcArray_board0_controller1[ indID ] = can_frame.dlc;
			ptr = dataArrayAddresses_board0_controller1[ indID ];
			for ( index = 0; index < 8; ++index )
			{
				ptr[ index ] = can_frame.data[ index ];
			}
		}
	}
}


void CAN_Exit()
{
	rtos_comm_close ( can_handle_board0_controller0 );
	can_handle_board0_controller0 = -1;   // Mark channel as not longer in use
	rtos_comm_close ( can_handle_board0_controller1 );
	can_handle_board0_controller1 = -1;   // Mark channel as not longer in use
}


int32_t getCANDeviceHandle ( uint32_t boardID, uint32_t controllerID )
{
	if ( ( boardID == 0 ) && ( controllerID == 0 ) )
	{
		return can_handle_board0_controller0;
	}
	if ( ( boardID == 0 ) && ( controllerID == 1 ) )
	{
		return can_handle_board0_controller1;
	}
	return -99;
}


