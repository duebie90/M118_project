function varargout = generateRTW(model, dir)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% generateRTW.m
% ETAS Simulink Integration
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Copyright (c) 2004 by ETAS GmbH, Stuttgart, Germany 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Generate RTW
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Prepare RTW Codegeneration
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% goto model directory
cd(dir);

% load preLoadFile.m to provide anything for opening the model:
if exist('preLoadFile.m') == 2
  preLoadFile;
end

% load parameterization m-files
%if exist('InitialParameterization.m') == 2
%    InitialParameterization
%end

% Evaluate M-script being created from LCO before to set necessary
% search paths etc.
preOpen;

% open Simulink model
open([model '.mdl']);

curtime = clock;

% load postLoadFile.m for actions after opening the model:
postOpen

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Update Model (Diagram) 
%% in order to detect errors before RTW code generation starts
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

try
    set_param( model, 'SimulationCommand', 'update')
catch
    fprintf('\n\n######   E r r o r   encountered before RTW Code Generation #####\nSolve the problem and start the code generation again.\n\n');
    err = lasterror;
    fprintf(err.message);
    if exist('Success.txt') == 2
        delete Success.txt
    end
    eh = errordlg(sprintf(['RTW code-generation for model terminated with errors.\nThe error messages are displayed in the Matlab window.\n\nAdvice:\nSolve the problem in your Simulink model and try again.']), 'Error in RTW code generation:');    
    uiwait(eh);
    exit
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Start RTW-Code Generation

%% Hl, LCSW2.0: Added an error catching expression since there was always
%% an error produced after the change of the make with the recursive make call.
%% With that, the "time elapsed" computed in "makeetas" is no longer displayed
%% and thus this computation is shifted to this place.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

try
    eval(get_param(model, 'RTWMakeCommand'));
catch
    fprintf('\n\n######   E r r o r   encountered during RTW Code Generation #####\nSolve the problem and start the code generation again.\n\n');
    disp(lasterr)
    if exist('Success.txt') == 2
        delete Success.txt
    end
    eh = errordlg(sprintf(['RTW code-generation for model terminated with errors.\nThe error messages are displayed in the Matlab window.\n\nAdvice:\nSolve the problem in your Simulink model and try again.']), 'Error in RTW code generation:');
    uiwait(eh);
    exit
end

if (findstr(version, '(R14)') > 0) == false
    test = 89
    if isempty(findstr('Error(s) encountered while building model', lasterr))
        fprintf('\n\n######   E r r o r   encountered after RTW Code Generation #####\nSolve the problem and start the code generation again.\n\n');
        fprintf(lasterr)
        if exist('Success.txt') == 2
            delete Success.txt
        end
        eh = errordlg(sprintf(['RTW code-generation for model terminated with errors.\nThe error messages are displayed in the Matlab window.\n\nAdvice:\nSolve the problem in your Simulink model and try again.']), 'Error in RTW code generation:');
        uiwait(eh);
        exit
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% save Simulink model
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% This is necessary for R14SP2 and later versions. Otherwise a query window comes up and asks what to do with unsaved changes
save_system;

fprintf('elapsed time: %fs\n', etime(clock, curtime));

if exist('Success.txt') == 2
%    eh = msgbox(['RTW code-generation for model '  model  ' successfully completed.'], 'Congratulations');
%    uiwait(eh);
else
    eh = errordlg(sprintf(['RTW code-generation for model terminated with errors.\nThe error messages are displayed in the Matlab window.\n\nAdvice:\nSolve the problem in your Simulink model and try again.\n\nHint:\nGenerating RTW code for Matlab''s standard realtime\ntarget "GRT" sometimes produces additional error\nmessages which may be helpful to localize the problem.']), 'Error in RTW code generation:');
    uiwait(eh);
end


exit
