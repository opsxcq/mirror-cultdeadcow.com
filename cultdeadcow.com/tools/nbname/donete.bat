@echo off
nbtstat -R
net use \\%2 /user: "" > nul
if ErrorLevel 1 goto end
nete /E /U /M /D  \\%2 >> c:\logs\%1-%3-%2
net use \\%2 /d /y  > nul
:end
