//zxelda v0.1a
//16mar'26

void animacion_hero(void) {
    switch(vista) {
        case 0:
            switch(anim) {
                case 0:
                    put_sprite_x16(sprite_linkDownA,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
                case 1:
                    put_sprite_x16(sprite_linkDownB,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
            }
            anim++;

            if (anim >= 2) {
                anim = 0;
            }
            break;

        case 1:
            switch(anim) {
                case 0:
                    put_sprite_x16(sprite_linkUpA,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
                case 1:
                    put_sprite_x16(sprite_linkUpB,hx*2+MAPA_OX,hy*2+MAPA_OY);
                    break;
            }
            anim--;

            if (anim <= -1) {
                anim = 1;
            }
            break;
    }
}

void calculo_frame(void) {
    hmap = hy*ancho_mapa+hx;
}

