//zxelda v0.1b
//07abr'26

void animacion_hero(void) {
    switch(vista) {
        case 0: // anim plyr up
            switch(anim) {
                case 0: //frame 0
                    put_sprite_x16(plyr_upA,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
                case 1: //frame 1
                    put_sprite_x16(plyr_upB,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
            }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;

        case 1: //anim plyr rgh
            switch(anim) {
                case 0:
                    put_sprite_x16(plyr_rghA,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
                case 1:
                    put_sprite_x16(plyr_rghB,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
            }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;
        
        case 2: //anim plyr dwn
            switch(anim) {
                case 0:
                    put_sprite_x16(plyr_dwnA,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
                case 1:
                    put_sprite_x16(plyr_dwnB,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
            }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;
        
        case 3: //anim plyr lft
            switch(anim) {
                case 0:
                    put_sprite_x16(plyr_lftA,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
                case 1:
                    put_sprite_x16(plyr_lftB,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
            }
            anim++;

            if (anim > 1) {
                anim = 0;
            }
            break;
    }
}

void calculo_frame(void) {
    hmap = hy*ancho_mapa+hx;
}

void check_warp(void) { //entrada a cueva en mapa 1
    if (mapa_actual == 1 && mapa_trabajo[hmap] == 9) {
        mapa_actual = 5;
        hx = 6;
        hy = 7;
        carga_datos_mapa();
        calculo_frame();
        render_hud_fondo();
        render_mapa();
        return;
    }
    if (mapa_actual == 4 && mapa_trabajo[hmap] == 9) { //entrada a mapa3 desde mapa4
        mapa_actual = 3;
        hx = 7;
        hy = 7;
        carga_datos_mapa();
        calculo_frame();
        render_hud_fondo();
        render_mapa();
        return;
    }
    if (mapa_actual == 3 && hy == alto_mapa-1 && mapa_trabajo[hmap] == 9) { //salida mapa3 a mapa4
        mapa_actual = 4;
        hx = 7;
        hy = 5;
        carga_datos_mapa();
        calculo_frame();
        render_hud_fondo();
        render_mapa();
        return;
    }
    if (mapa_actual == 5 && hy == alto_mapa-1 && (hx == 7 || hx == 8)) { //salida de cueva
        mapa_actual = 1;
        hx = 2;
        hy = 2;
        carga_datos_mapa();
        calculo_frame();
        render_hud_fondo();
        render_mapa();
        return;
    }
}

void sword_render(void) { //logica del ataque a espada
    switch(vista) {
        case 0: // arriba
            if (hy == 0) return;
            put_sprite_8x16(swrd_up, hx*2+MAPA_OX, hy*2-2+MAPA_OY);
            break;
        case 1: // derecha
            if (hx == ancho_mapa-1) return;
            put_sprite_16x8(swrd_rgh, hx*2+2+MAPA_OX, hy*2+MAPA_OY);
            break;
        case 2: // abajo
            if (hy == alto_mapa-1) return;
            put_sprite_8x16(swrd_dwn, hx*2+MAPA_OX, hy*2+2+MAPA_OY);
            break;
        case 3: // izquierda
            if (hx == 0) return;
            put_sprite_16x8(swrd_lft, hx*2-2+MAPA_OX, hy*2+MAPA_OY);
            break;
    }
}

void sword_erase(void) {
    switch(vista) {
        case 0:
            if (hy > 0) render_tile(mapa_trabajo[(hy-1)*ancho_mapa+hx], hx, hy-1);
            break;
        case 1:
            if (hx < ancho_mapa-1) render_tile(mapa_trabajo[hy*ancho_mapa+hx+1], hx+1, hy);
            break;
        case 2:
            if (hy < alto_mapa-1) render_tile(mapa_trabajo[(hy+1)*ancho_mapa+hx], hx, hy+1);
            break;
        case 3:
            if (hx > 0) render_tile(mapa_trabajo[hy*ancho_mapa+hx-1], hx-1, hy);
            break;
    }
}

void check_sword_hit(void) {
    unsigned char tx, ty;
    if (!eactive) return;
    switch(vista) {
        case 0: tx=hx;   ty=hy-1; break;
        case 1: tx=hx+1; ty=hy;   break;
        case 2: tx=hx;   ty=hy+1; break;
        case 3: tx=hx-1; ty=hy;   break;
    }
    if (ex == tx && ey == ty) {
        eactive = 0;
        render_tile(mapa_trabajo[ey*ancho_mapa+ex], ex, ey);
    }
}

void update_attack(void) {
    if (attack_timer == 0) return;
    sword_render();
    attack_timer--;
    if (attack_timer == 0) sword_erase();
}

void animacion_enemigo(void) {
    if (!eactive) return;
    if (eanim == 0)
        put_sprite_x16(enmy_octoD_a, ex*2+MAPA_OX, ey*2+MAPA_OY);
    else
        put_sprite_x16(enmy_octoD_b, ex*2+MAPA_OX, ey*2+MAPA_OY);
    eanim ^= 1;
}

void mueve_enemigo(void) {
    if (!eactive) return;
    emov++;
    if (emov < 16) return;
    emov = 0;
    render_tile(mapa_trabajo[ey*ancho_mapa+ex], ex, ey);
    if (ex < hx) ex++;
    else if (ex > hx) ex--;
    else if (ey < hy) ey++;
    else if (ey > hy) ey--;
    if (ex == hx && ey == hy) {
        cambiar_pantalla(PANTALLA_GAME_OVER);
    }
}
