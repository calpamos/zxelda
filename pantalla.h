//zxelda v0.1b
//07abr'26

void init_pantalla (void) {
    port_out (254,6); //border color. 0_black, 1_blue, 2_red, 3_magenta, 4_green, 5_teal, 6_yellow, 7_white
    cls(0);
}

void render_intro (void) {
    cls(0);
}

void render_game_over (void) {
    cls(0);
    //TODO: dibujar pantalla de game over
}

void render_mapa (void) {
    int contador=0;
    for (y=0;y<alto_mapa;y++) {
        for (x=0;x<ancho_mapa;x++) {
            render_tile (mapa_trabajo[contador],x,y);
            contador++;
        }
    }
    
}

void render_hud_fondo(void) {
    unsigned char *borde = (mapa_actual == 3) ? sprite_negro : sprite_amaD;
    for (x=0; x<3; x++) {
        put_sprite_x16(borde, 0,  x*2);
        put_sprite_x16(borde, 30, x*2);
    }
}

void render_menu (void) {
    //put_partial1v_sprite_x16(menu8x8,0,0); //tile misterioso 1PLYR
}

void restaura_fondo_tile (void) {
    unsigned char tile=mapa_trabajo[hmap];
    render_tile(tile,hx,hy);
}

int render_tile(int grafico, int x, int y) {
    switch (grafico) {
        case 0:
            put_sprite_x16 (sprite_amaD, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 1:
            put_sprite_x16 (wrld_frst, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 2:
            put_sprite_x16 (wrld_bush, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 3:
            put_sprite_x16 (dngn_blck, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 4:
            put_sprite_x16 (dngn_tile, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 5:
            put_sprite_x16 (dngn_wall,x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 6:
            put_sprite_x16 (wrld_door_left, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 7:
            put_sprite_x16 (wrld_door_rght, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 8:
            put_sprite_8x16 (wrld_door_up, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
        case 9:
            put_sprite_x16 (sprite_negro, x*2+MAPA_OX, y*2+MAPA_OY);
        break;
    }
}

int render_hero(int x, int y) {
    int rx = x + MAPA_OX;
    int ry = y + MAPA_OY;
    switch (vista) {
        case 0: //up
            switch (anim) {
                case 0:
                    put_sprite_x16 (plyr_upA,rx,ry);
                    break;
                case 1:
                    put_sprite_x16 (plyr_upB,rx,ry);
                    break;
                }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;

        case 1: //der
            switch (anim) {
                case 0:
                    put_sprite_x16 (plyr_rghA,rx,ry);
                    break;
                case 1:
                    put_sprite_x16 (plyr_rghB,rx,ry);
                    break;
                }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;
        
        case 2: //abaj
            switch (anim) {
                case 0:
                    put_sprite_x16 (plyr_dwnA,rx,ry);
                    break;
                case 1:
                    put_sprite_x16 (plyr_dwnB,rx,ry);
                    break;
                }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;
        
        case 3: //izq
            switch (anim) {
                case 0:
                    put_sprite_x16 (plyr_lftA,rx,ry);
                    break;
                case 1:
                    put_sprite_x16 (plyr_lftB,rx,ry);
                    break;
                }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;
    }
}

void cambiar_pantalla (unsigned char nueva) {
    modo_app = nueva;
    cls(0);
    switch (modo_app) {
        case PANTALLA_INTRO:
            render_intro();
        break;
        case PANTALLA_MENU:
            render_menu();
        break;
        case PANTALLA_JUEGO:
            inicia_variables_juego();
            render_hud_fondo();
            render_mapa();
            render_hero(hx*2, hy*2);
        break;
        case PANTALLA_GAME_OVER:
            render_game_over();
        break;
    }
}
