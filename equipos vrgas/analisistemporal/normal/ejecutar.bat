@echo off


set A=322486 14700764 3128036 6337399 61396 10393545 2147445644 1295390003 450057883 187645041 1980098116 152503 5000 1493283650 214826 1843349527 1360839354 2109248666 2147470852 0
echo BL > outNormal.txt
for %%a in (%A%) do (
    BL.exe 1 %%a >> outNormal.txt 
)
echo BusquedaBinaria >> outNormal.txt
for %%a in (%A%) do (
    BusquedaBinaria.exe 1 %%a >> outNormal.txt 
)
echo BusquedaExponencial >> outNormal.txt
for %%a in (%A%) do (
    BusquedaExponencial.exe 1 %%a >> outNormal.txt 
)
echo BusquedaFibonacci >> outNormal.txt
for %%a in (%A%) do (
    BusquedaFibonacci.exe 1 %%a >> outNormal.txt 
)
echo BusquedaPorArbol >> outNormal.txt
for %%a in (%A%) do (
    BusquedaPorArbol.exe 1 %%a >> outNormal.txt 
)