/*
 * File rtpc_os_config.c generated from default.los
 * Date: Tue May 12 19:08:34 2015
 *
 */

#include "rtpc_task_config.h"
#include "rtos.h"
#include "rtos_hook.h"
#ifndef NULL
#define NULL 0
#endif


/* ----- OS configuration ----- */
const rtpc_osconfig_t rtpc_osconfig = {
	.version = RTPC_TASK_CONFIG_VERSION,
	.max_coop_levels = 40,
	.os_monitoring = 0,
};


/* -------- Task Init -------- */
static const rtpc_process_t rtpc_process_list_Init[];        
static const char * const rtpc_processname_list_Init[];        

static const rtpc_task_t rtpc_task_def_Init = {
	.name = "Init",
	.period = 0.1,
	.priority = 0,
	.type = en_type_Init,
	.autostart = 1,
	.delay = 0,
	.max_activations = 0,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.2,
	.trigger_event = "TaskTriggerInit",
	.process_list = rtpc_process_list_Init,
	.processname_list = rtpc_processname_list_Init,
};

extern void Es113x_InitCode_Init_HWCF(void);
extern void CAN_Init(void);
extern void lcrt_Start_Batterymodel_HiL(void);

static const rtpc_process_t rtpc_process_list_Init[] = 
{
	Es113x_InitCode_Init_HWCF,
	CAN_Init,
	lcrt_Start_Batterymodel_HiL,
	NULL
};

static const char * const rtpc_processname_list_Init[] = 
{
	"Es113x_InitCode_Init_HWCF",
	"CAN_Init",
	"lcrt_Start_Batterymodel_HiL",
	NULL
};

/* -------- Task Exit -------- */
static const rtpc_process_t rtpc_process_list_Exit[];        
static const char * const rtpc_processname_list_Exit[];        

static const rtpc_task_t rtpc_task_def_Exit = {
	.name = "Exit",
	.period = 0.1,
	.priority = 0,
	.type = en_type_Exit,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.2,
	.trigger_event = "TaskTriggerExit",
	.process_list = rtpc_process_list_Exit,
	.processname_list = rtpc_processname_list_Exit,
};

extern void Es113x_ExitCode_Exit_HWCL(void);
extern void CAN_Exit(void);
extern void lcrt_Terminate_Batterymodel_HiL(void);

static const rtpc_process_t rtpc_process_list_Exit[] = 
{
	Es113x_ExitCode_Exit_HWCL,
	CAN_Exit,
	lcrt_Terminate_Batterymodel_HiL,
	NULL
};

static const char * const rtpc_processname_list_Exit[] = 
{
	"Es113x_ExitCode_Exit_HWCL",
	"CAN_Exit",
	"lcrt_Terminate_Batterymodel_HiL",
	NULL
};

/* -------- Task Acquisition -------- */
static const rtpc_process_t rtpc_process_list_Acquisition[];        
static const char * const rtpc_processname_list_Acquisition[];        

static const rtpc_task_t rtpc_task_def_Acquisition = {
	.name = "Acquisition",
	.period = 0.1,
	.priority = 1,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.2,
	.trigger_event = "TaskTriggerAcquisition",
	.process_list = rtpc_process_list_Acquisition,
	.processname_list = rtpc_processname_list_Acquisition,
};


static const rtpc_process_t rtpc_process_list_Acquisition[] = 
{
	NULL
};

static const char * const rtpc_processname_list_Acquisition[] = 
{
	NULL
};

/* -------- Task Config -------- */
static const rtpc_process_t rtpc_process_list_Config[];        
static const char * const rtpc_processname_list_Config[];        

static const rtpc_task_t rtpc_task_def_Config = {
	.name = "Config",
	.period = 0.1,
	.priority = 1,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.2,
	.trigger_event = "TaskTriggerConfig",
	.process_list = rtpc_process_list_Config,
	.processname_list = rtpc_processname_list_Config,
};


static const rtpc_process_t rtpc_process_list_Config[] = 
{
	NULL
};

static const char * const rtpc_processname_list_Config[] = 
{
	NULL
};

/* -------- Task Manager -------- */
static const rtpc_process_t rtpc_process_list_Manager[];        
static const char * const rtpc_processname_list_Manager[];        

static const rtpc_task_t rtpc_task_def_Manager = {
	.name = "Manager",
	.period = 0.01,
	.priority = 2,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.02,
	.trigger_event = "TaskTriggerManager",
	.process_list = rtpc_process_list_Manager,
	.processname_list = rtpc_processname_list_Manager,
};


static const rtpc_process_t rtpc_process_list_Manager[] = 
{
	NULL
};

static const char * const rtpc_processname_list_Manager[] = 
{
	NULL
};

/* -------- Task Analyze -------- */
static const rtpc_process_t rtpc_process_list_Analyze[];        
static const char * const rtpc_processname_list_Analyze[];        

static const rtpc_task_t rtpc_task_def_Analyze = {
	.name = "Analyze",
	.period = 0.1,
	.priority = 1,
	.type = en_type_Software,
	.autostart = 1,
	.delay = 0,
	.max_activations = 4,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.2,
	.trigger_event = "TaskTriggerAnalyze",
	.process_list = rtpc_process_list_Analyze,
	.processname_list = rtpc_processname_list_Analyze,
};


static const rtpc_process_t rtpc_process_list_Analyze[] = 
{
	NULL
};

static const char * const rtpc_processname_list_Analyze[] = 
{
	NULL
};

/* -------- Task Acknowledge -------- */
static const rtpc_process_t rtpc_process_list_Acknowledge[];        
static const char * const rtpc_processname_list_Acknowledge[];        

static const rtpc_task_t rtpc_task_def_Acknowledge = {
	.name = "Acknowledge",
	.period = 0.1,
	.priority = 1,
	.type = en_type_Software,
	.autostart = 1,
	.delay = 0,
	.max_activations = 4,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.2,
	.trigger_event = "TaskTriggerAcknowledge",
	.process_list = rtpc_process_list_Acknowledge,
	.processname_list = rtpc_processname_list_Acknowledge,
};


static const rtpc_process_t rtpc_process_list_Acknowledge[] = 
{
	NULL
};

static const char * const rtpc_processname_list_Acknowledge[] = 
{
	NULL
};

/* -------- Task TaskDVEModel -------- */
static const rtpc_process_t rtpc_process_list_TaskDVEModel[];        
static const char * const rtpc_processname_list_TaskDVEModel[];        

static const rtpc_task_t rtpc_task_def_TaskDVEModel = {
	.name = "TaskDVEModel",
	.period = 0.01,
	.priority = 3,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.02,
	.trigger_event = "TaskTriggerTaskDVEModel",
	.process_list = rtpc_process_list_TaskDVEModel,
	.processname_list = rtpc_processname_list_TaskDVEModel,
};

extern void CAN_Receive_board0_controller0(void);
extern void CAN_Receive_board0_controller1(void);
extern void Es113x_SyncReceiveCode_TaskDVEModel_HWCF(void);
extern void lcrt_OneStep_Outputs_Batterymodel_HiL(void);
extern void Es113x_SyncSendCode_TaskDVEModel_HWCF(void);
extern void lcrt_OneStep_States_Batterymodel_HiL(void);

static const rtpc_process_t rtpc_process_list_TaskDVEModel[] = 
{
	CAN_Receive_board0_controller0,
	CAN_Receive_board0_controller1,
	Es113x_SyncReceiveCode_TaskDVEModel_HWCF,
	lcrt_OneStep_Outputs_Batterymodel_HiL,
	Es113x_SyncSendCode_TaskDVEModel_HWCF,
	lcrt_OneStep_States_Batterymodel_HiL,
	NULL
};

static const char * const rtpc_processname_list_TaskDVEModel[] = 
{
	"CAN_Receive_board0_controller0",
	"CAN_Receive_board0_controller1",
	"Es113x_SyncReceiveCode_TaskDVEModel_HWCF",
	"lcrt_OneStep_Outputs_Batterymodel_HiL",
	"Es113x_SyncSendCode_TaskDVEModel_HWCF",
	"lcrt_OneStep_States_Batterymodel_HiL",
	NULL
};

/* -------- Task Module_EDAG_Global_cmod_compute_EDAG_Global -------- */
static const rtpc_process_t rtpc_process_list_Module_EDAG_Global_cmod_compute_EDAG_Global[];        
static const char * const rtpc_processname_list_Module_EDAG_Global_cmod_compute_EDAG_Global[];        

static const rtpc_task_t rtpc_task_def_Module_EDAG_Global_cmod_compute_EDAG_Global = {
	.name = "Module_EDAG_Global_cmod_compute_EDAG_Global",
	.period = 0.01,
	.priority = 3,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 0.02,
	.trigger_event = "TaskTriggerModule_EDAG_Global_cmod_compute_EDAG_Global",
	.process_list = rtpc_process_list_Module_EDAG_Global_cmod_compute_EDAG_Global,
	.processname_list = rtpc_processname_list_Module_EDAG_Global_cmod_compute_EDAG_Global,
};


static const rtpc_process_t rtpc_process_list_Module_EDAG_Global_cmod_compute_EDAG_Global[] = 
{
	NULL
};

static const char * const rtpc_processname_list_Module_EDAG_Global_cmod_compute_EDAG_Global[] = 
{
	NULL
};

/* -------- Task Module_CANModule_CAN_Send_board0_controller1 -------- */
static const rtpc_process_t rtpc_process_list_Module_CANModule_CAN_Send_board0_controller1[];        
static const char * const rtpc_processname_list_Module_CANModule_CAN_Send_board0_controller1[];        

static const rtpc_task_t rtpc_task_def_Module_CANModule_CAN_Send_board0_controller1 = {
	.name = "Module_CANModule_CAN_Send_board0_controller1",
	.period = 0.5,
	.priority = 3,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 1,
	.trigger_event = "TaskTriggerModule_CANModule_CAN_Send_board0_controller1",
	.process_list = rtpc_process_list_Module_CANModule_CAN_Send_board0_controller1,
	.processname_list = rtpc_processname_list_Module_CANModule_CAN_Send_board0_controller1,
};

extern void CAN_Send_board0_controller1(void);

static const rtpc_process_t rtpc_process_list_Module_CANModule_CAN_Send_board0_controller1[] = 
{
	CAN_Send_board0_controller1,
	NULL
};

static const char * const rtpc_processname_list_Module_CANModule_CAN_Send_board0_controller1[] = 
{
	"CAN_Send_board0_controller1",
	NULL
};

/* -------- Task TaskDVEModel_Bat_Modell -------- */
static const rtpc_process_t rtpc_process_list_TaskDVEModel_Bat_Modell[];        
static const char * const rtpc_processname_list_TaskDVEModel_Bat_Modell[];        

static const rtpc_task_t rtpc_task_def_TaskDVEModel_Bat_Modell = {
	.name = "TaskDVEModel_Bat_Modell",
	.period = 12,
	.priority = 3,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 24,
	.trigger_event = "TaskTriggerTaskDVEModel_Bat_Modell",
	.process_list = rtpc_process_list_TaskDVEModel_Bat_Modell,
	.processname_list = rtpc_processname_list_TaskDVEModel_Bat_Modell,
};


static const rtpc_process_t rtpc_process_list_TaskDVEModel_Bat_Modell[] = 
{
	NULL
};

static const char * const rtpc_processname_list_TaskDVEModel_Bat_Modell[] = 
{
	NULL
};

/* -------- Task Module_CANModule_CAN_Send_board0_controller0 -------- */
static const rtpc_process_t rtpc_process_list_Module_CANModule_CAN_Send_board0_controller0[];        
static const char * const rtpc_processname_list_Module_CANModule_CAN_Send_board0_controller0[];        

static const rtpc_task_t rtpc_task_def_Module_CANModule_CAN_Send_board0_controller0 = {
	.name = "Module_CANModule_CAN_Send_board0_controller0",
	.period = 1,
	.priority = 3,
	.type = en_type_Timer,
	.autostart = 1,
	.delay = 0,
	.max_activations = 1,
	.floating_point_exception = 0,
	.cpucore = 1,
	.core_exclusive = 0,
	.auto_trigger_mode = 0,
	.auto_trigger_timeout = 2,
	.trigger_event = "TaskTriggerModule_CANModule_CAN_Send_board0_controller0",
	.process_list = rtpc_process_list_Module_CANModule_CAN_Send_board0_controller0,
	.processname_list = rtpc_processname_list_Module_CANModule_CAN_Send_board0_controller0,
};

extern void CAN_Send_board0_controller0(void);

static const rtpc_process_t rtpc_process_list_Module_CANModule_CAN_Send_board0_controller0[] = 
{
	CAN_Send_board0_controller0,
	NULL
};

static const char * const rtpc_processname_list_Module_CANModule_CAN_Send_board0_controller0[] = 
{
	"CAN_Send_board0_controller0",
	NULL
};

/* ----- Global Task List ----- */
const rtpc_task_t * const rtpc_task_list[] = {
	&rtpc_task_def_Init,
	&rtpc_task_def_Exit,
	&rtpc_task_def_Acquisition,
	&rtpc_task_def_Config,
	&rtpc_task_def_Manager,
	&rtpc_task_def_Analyze,
	&rtpc_task_def_Acknowledge,
	&rtpc_task_def_TaskDVEModel,
	&rtpc_task_def_Module_EDAG_Global_cmod_compute_EDAG_Global,
	&rtpc_task_def_Module_CANModule_CAN_Send_board0_controller1,
	&rtpc_task_def_TaskDVEModel_Bat_Modell,
	&rtpc_task_def_Module_CANModule_CAN_Send_board0_controller0,
	NULL
};

/* ----- Task IDs ----- */
const unsigned short rtpc_task_id_Init = 1;
const unsigned short rtpc_task_id_Exit = 2;
const unsigned short rtpc_task_id_Acquisition = 3;
const unsigned short rtpc_task_id_Config = 4;
const unsigned short rtpc_task_id_Manager = 5;
const unsigned short rtpc_task_id_Analyze = 6;
const unsigned short rtpc_task_id_Acknowledge = 7;
const unsigned short rtpc_task_id_TaskDVEModel = 8;
const unsigned short rtpc_task_id_Module_EDAG_Global_cmod_compute_EDAG_Global = 9;
const unsigned short rtpc_task_id_Module_CANModule_CAN_Send_board0_controller1 = 10;
const unsigned short rtpc_task_id_TaskDVEModel_Bat_Modell = 11;
const unsigned short rtpc_task_id_Module_CANModule_CAN_Send_board0_controller0 = 12;

/* ----- Hook Callers ----- */

/* ----- rtpc_task_internal_init/exit ----- */

void rtpc_task_internal_init(void)
{
}


void rtpc_task_internal_exit(void)
{
}

