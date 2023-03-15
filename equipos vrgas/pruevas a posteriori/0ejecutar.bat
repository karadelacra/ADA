@REM este script ejecutará los programas dentro de la carpeta pruebas a posteriori
@REM dando como referencia el archivo de texto nums.txt

@echo off
set n = 1000 2000 3000  4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 600000 700000 800000 900000 1000000 1500000 2000000
set s = 3000000 4000000 5000000 6000000 10000000

1burbuja1.exe 40 < nums.txt > out1.txt
2burbuja2.exe 40 < nums.txt > out2.txt
3burbuja3.exe 40 < nums.txt > out3.txt   
4insercion.exe 40 < nums.txt > out4.txt
5seleccion.exe 40 < nums.txt > out5.txt
6shell.exe 40 < nums.txt > out6.txt
7mergesort.exe 40 < nums.txt > out7.txt
8quicksort.exe 40 < nums.txt > out8.txt

