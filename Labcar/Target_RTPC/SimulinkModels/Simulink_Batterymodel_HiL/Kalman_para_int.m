%% Kalman-Parameter
%% Parameter entsprechend Batterie-ESB -> siehe Doku
C_dl =  single(20);                                        % Diffusionskapazität [Farad]
R_dl =  single(0.03);                                      % Diffusionswiderstand [Ohm]
R_i =   single(0.05);                                      % Innenwiderstand  [Ohm]
C_cell = single(1300);                                     % Zellkapazität [mAh]
C_cell = single(C_cell*3600/1000);                         % Zellkapazität [As]
%% Polynomapproximation : OCV(SoC) Parameter für Polynom 3. Grades

p = [2.2966 -3.6644 2.5182 2.9036]';
  
%% Varianzen für Rauschprozesse
% Var11         =   5e-13;                            % Varianz des Soc
% Var22         =   5e-13;                            % Varianz der Diffusionsspannung
Var11         =   single(5e-13);                            % Varianz des Soc
Var22         =   single(5e-13);                            % Varianz der Diffusionsspannung
Varmess       =   single(1e-2); 
                        
%% Matrizen
A   = diag([ 1  (1-T_s/(C_dl*R_dl))]);              % Systemmatrix
A_T = A';                                           % transponierte Systematrix A

B   = [(T_s/C_cell);  (T_s/C_dl) ];                 % Eingangsvektor

Q   = diag([Var11 Var22]);                          % Kovarianzmatrix des Prozessrauschen
F   = Varmess;                                      % Kovarianzmatrix des Messrauschen                                        
                          
%% Vektoren / Matrizen zur Initialisierung
% Initialisierung des SoC, durch Interpolation SoC(Vk)
SoC_init = [0 3.33 6.67 10 13.33 16.67 20 23.33 26.67 30 33.33 36.67 40 43.33 46.67 50 53.33 56.67 60 63.33 66.67 70 73.33 76.67 80 83.33 86.67 90 93.33 96.67 100]';
Vk_init =  [2.57 3 3.2 3.3 3.31 3.32 3.33 3.34 3.35 3.36 3.37 3.38 3.385 3.39 3.41 3.44 3.52 3.57 3.63 3.65 3.69 3.72 3.76 3.79 3.81 3.82 3.83 3.84 3.85 3.9 4.1]';

P_0=[1e-5 5e-8; 5e-8 1.4e-8];                       % Initiale Fehlerkovarianzmatrix
%% "Housekeeping"
clear C_cell C_dl R_dl Var11 Var22 Varmess;
