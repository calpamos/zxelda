@echo off
REM _________________________________________________________
REM Inicializamos las variables de sistema de Z88DK
REM _________________________________________________________
echo "ESTA ES LA VERSION 1.10"
set Z88DK_PATH=c:\z88dk10
set PATH=%Z88DK_PATH%\bin;%PATH%
set Z80_OZFILES=%Z88DK_PATH%\Lib\
set ZCCCFG=%Z88DK_PATH%\Lib\Config\
REM _________________________________________________________
REM Compilamos el juego
REM _________________________________________________________
echo ## COMPILANDO
zcc +zx -vn zxelda.c -o zxelda.bin -lndos -zorg=24200
echo ## CONSTRUYENDO CINTA
rem cambia JUEGO por el nombre que quieres que salga en Program:
rem Si quieres pantalla de carga renombra loaderzx_con_pantalla.bas por loaderzx.bas
utilszx\bas2tap -a10 -sZXELDA loaderzx_con_pantalla.bas loaderzx.tap
rem Si quieres pantalla de carga quita el siguiente "rem"
utilszx\bin2tap -o screenzx.tap -a 16384 loadingzx.bin
utilszx\bin2tap -o mainzx.tap -a 24200 zxelda.bin
copy /b loaderzx.tap + screenzx.tap + mainzx.tap zxelda.tap
REM _________________________________________________________
REM Borramos ficheros temporales generados
REM _________________________________________________________
echo ## BORRANDO TEMPORALES
del loaderzx.tap
del mainzx.tap
del zxelda.bin
del *.def
echo ## FIN
REM _________________________________________________________
REM Esperamos a que el usuario pulse una tecla para cerrar
REM _________________________________________________________
pause
