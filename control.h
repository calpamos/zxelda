//zxelda v0.1b
//07abr'26

int x8,y8;

void cambiar_mapa(unsigned char dir) {
    unsigned char destino = get_mapa_conexion(mapa_actual, dir);
    if (destino == 0) return;
    mapa_actual = destino;
    carga_datos_mapa();
    switch(dir) {
        case DIR_DER: hx = 1;             break;
        case DIR_IZQ: hx = ancho_mapa-2;  break;
        case DIR_ABA: hy = 0;             break;
        case DIR_ARR: hy = alto_mapa-1;   break;
    }
    calculo_frame();
    render_hud_fondo();
    render_mapa();
    render_hero(hx*2, hy*2);
}

void control_teclas_juego (void) {
    if ((port_in(64510)&1) == 0) { //tecla arrb
        if (hy == 0) { //borde superior - cambio mapa
            cambiar_mapa(DIR_ARR);
            return;
        }

        if (vista != 0) { //anim plyr mov up
            vista = 0;
            render_hero(hx*2,hy*2);
            wait_int();
            wait_int();
            wait_int();
            return;
        }

        if (mapa_trabajo[hmap-ancho_mapa] == 1) {
            return;
        }
        x8=hx*2;
        y8=(hy*2)-1;
        restaura_fondo_tile();
        render_hero(x8,y8);
        y8=y8-1;
        wait_int();
        wait_int();
        render_tile(mapa_trabajo[hmap],hx,hy);
        render_hero(x8,y8);
        hy--;
        calculo_frame();
        wait_int();
        return;
    }

    if ((port_in(57342)&1) == 0) { //tecla der
        if (hx==ancho_mapa-2) { //borde derecho - cambio mapa (col 15 es relleno)
            cambiar_mapa(DIR_DER);
            return;
        }

        if (vista !=1) { //animacion plyr der
            vista = 1;
            render_hero(hx*2,hy*2);
            wait_int();
            wait_int();
            wait_int();
            return;
        }

        if (mapa_trabajo[hmap+1]==1) {
            return;
        }
        x8=(hx*2)+1;
        y8=hy*2;
        restaura_fondo_tile();
        render_hero(x8,y8);
        x8=x8+1;
        wait_int();
        wait_int();
        render_tile(mapa_trabajo[hmap],hx,hy);
        render_hero(x8,y8);
        hx++;
        calculo_frame();
        wait_int();
        return;
    }

    if ((port_in(65022)&1) == 0) { //tecla abj
        if (hy == alto_mapa-1) { //borde inferior - cambio mapa
            cambiar_mapa(DIR_ABA);
            return;
        }

        if (vista != 2) { //anim plyr mov izq
            vista = 2;
            render_hero(hx*2,hy*2);
            wait_int();
            wait_int();
            wait_int();
            return;
        }

        if (mapa_trabajo[hmap+ancho_mapa] == 1) {
            return;
        }
        x8=hx*2;
        y8=(hy*2)+1;
        restaura_fondo_tile();
        render_hero(x8,y8);
        y8=y8+1;
        wait_int();
        wait_int();
        render_tile(mapa_trabajo[hmap],hx,hy);
        render_hero(x8,y8);
        hy++;
        calculo_frame();
        wait_int();
        return;
    }

    if ((port_in(57342)&2) == 0) { //tecla izq
        if (hx == 1) { //borde izquierdo - cambio mapa (col 0 es relleno)
            cambiar_mapa(DIR_IZQ);
            return;
        }

        if (vista != 3) { //anim plyr mov izq
            vista = 3;
            render_hero(hx*2,hy*2);
            wait_int();
            wait_int();
            wait_int();
            return;
        }

        if (mapa_trabajo[hmap - 1] == 1) {
            return;
        }

        //restaura_fondo_tile();
        //hx--;
        //calculo_frame();
        x8=(hx*2)-1;
        y8=hy*2;
        restaura_fondo_tile();
        render_hero(x8,y8);
        x8=x8-1;
        wait_int();
        wait_int();
        render_tile(mapa_trabajo[hmap],hx,hy);
        render_hero(x8,y8);
        hx--;
        calculo_frame();
        wait_int();
        return;
    }

    if ((port_in(32766)&1)==0) { //SPACE - ataque
        if (attack_timer == 0) {
            attack_timer = 8;
            check_sword_hit();
        }
    }

    if ((port_in(61438)&1)==0) { //tecla 0 -> menu
        cambiar_pantalla(PANTALLA_MENU);
    }
}

void control_teclas_intro(void) {
    if ((port_in(63486)&1)==0) { //tecla 1 -> menu
        cambiar_pantalla(PANTALLA_MENU);
    }
}

void control_teclas_menu(void) {
    if ((port_in(63486)&1)==0) { //tecla 1 -> jugar
        cambiar_pantalla(PANTALLA_JUEGO);
    }
}

void control_teclas_game_over(void) {
    if ((port_in(63486)&1)==0) { //tecla 1 -> menu
        cambiar_pantalla(PANTALLA_MENU);
    }
}

void teclado(void) {
    switch(modo_app) {
        case PANTALLA_INTRO:
            control_teclas_intro();
        break;
        case PANTALLA_MENU:
            control_teclas_menu();
        break;
        case PANTALLA_JUEGO:
            control_teclas_juego();
        break;
        case PANTALLA_GAME_OVER:
            control_teclas_game_over();
        break;
    }
}
