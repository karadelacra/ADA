@REM este script ejecutará los programas dentro de la carpeta pruebas a posteriori
@REM dando como referencia el archivo de texto nums.txt

@echo off
@REM set n = 1000 2000 3000  4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 600000 700000 800000 900000 1000000 1500000 2000000
@REM set s = 3000000 4000000 5000000 6000000 10000000

@REM 1burbuja1.exe 40 < nums.txt > out1.txt
@REM 2burbuja2.exe 40 < nums.txt > out2.txt
@REM 3burbuja3.exe 40 < nums.txt > out3.txt   
@REM 4insercion.exe 40 < nums.txt > out4.txt
@REM 5seleccion.exe 40 < nums.txt > out5.txt
@REM 6shell.exe 40 < nums.txt > out6.txt
@REM 7mergesort.exe 40 < nums.txt > out7.txt
8quicksort.exe 10000000 < nums.txt > numsord.txt

