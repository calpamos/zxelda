//zxelda v0.1a
//16mar'26

#include <stdio.h>

#include <lib\motorzx.h>
#include <lib\sonidoszx.h>

#include <config.h>
#include <variables.h>
#include <graficos.h>
#include <pantalla.h>
#include <logica.h>
#include <control.h>

#pragma output STACKPTR = 65000

void main (void) {
    init_pantalla();
    cambiar_pantalla(PANTALLA_MENU);

    while(!zx_break()) { //hasta pulsar break
        switch(modo_app) {
            case PANTALLA_INTRO:
            break;

            case PANTALLA_MENU:
            break;

            case PANTALLA_JUEGO:
                calculo_frame();
                animacion_hero();
            break;

            case PANTALLA_GAME_OVER:
            break;
        }
        teclado();

        wait_int();
        wait_int();
        wait_int();
    }
}
