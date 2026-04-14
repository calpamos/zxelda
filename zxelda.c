//zxelda v0.1b
//07abr'26

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
    cambiar_pantalla(PANTALLA_JUEGO);

    while(!zx_break()) { //infinte loop
        switch(modo_app) {
            case PANTALLA_INTRO:
            break;

            case PANTALLA_MENU:
            break;

            case PANTALLA_JUEGO:
                calculo_frame();
                check_warp();
                mueve_enemigo();
                animacion_enemigo();
                update_attack();
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
