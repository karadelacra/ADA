@echo off

set A=BusquedaBinaria, BL, BusquedaExponencial, BusquedaFibonacci, BusquedaPorArbol

for %%a in (%A%) do (
    gcc %%a.c -o %%a.exe -lm -w
)