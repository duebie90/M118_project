T_cells=20*ones(1,12); %Cell temperatures: numbers in a row%
Tcells=T_cells;
Q_0=36000*ones(1,12); %As initial charge%
SoC_init_cells=0.8*ones(1,12); %%actual initial charge 80% %
SoCinitCells=SoC_init_cells;
R_balance=10*ones(1,12); %?? Ohm%
balance_vector=[1 1 0 0 0 0 0 0 0 0 0 0];
%balance_vector=0*ones(1,12);
Ts=10*10^-3; %%10ms
T_s=Ts;

%%Cell Parameter %%
R_diff=4*10^-3; %%4mOhm
C_diff=5000; %%5000 F
R_ct  =3.2*10^-3; %%3,2mOhm
R_i   =2*10^-3; %%2mOhm

%%%BMS Constants%%%%
ChargeCurrent=5;
DischargeCurrent=-5;
ChargeSwitch=1;
n_cells=12;
CellNo=12;
delta_max_v_cell=1;

V_min_cell = uint16(2800); % minimal cell voltage [mV]
V_max_cell = uint16(4090); % maximum cell voltage [mV]
V_delta_max_cell = uint16(100); % maximum cell voltage dif-
% ference [mV]
T_min_cell = uint16(273); % min. cell temperature [K]
T_max_cell = uint16(373); % max. cell temperature [K]
I_max_line = int32(10000); % max. charge current [mA]
I_min_line = int32(-10000); % max. dischar. current [mA]
V_min_bat = uint16(36000); % min. battery voltage [mV]
V_max_bat = uint16(49080); % max. battery voltage [mV]



load('SoC_table.mat');
load('OCV_table.mat');
poles_soc=polyfit(SoC_table, OCV_table,4);