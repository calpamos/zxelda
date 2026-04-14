//zxelda v0.1b
//07abr'26

unsigned char modo_app=0; //0 menu, 1 juego
unsigned char x,y; //render mapa

unsigned char hx; //hero x
unsigned char hy; //hero y
unsigned char hmap;
int anim;
unsigned char vista;

unsigned char ancho_mapa;
unsigned char alto_mapa;
unsigned char mapa_actual;
unsigned char mapa_trabajo[144];
extern unsigned char mapa1[];
extern unsigned char mapa2[];
extern unsigned char mapa3[];
extern unsigned char mapa4[];
extern unsigned char mapa5[];

#asm
    ._mapa1 //start 000
    defb 0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0
    defb 0,1,1,9,1,1,0,0,0,1,1,1,1,1,1,0
    defb 0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0
    defb 0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0
    defb 0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0
    defb 0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0
    defb 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
    ._mapa2 //start_lft 001
    defb 0,1,1,0,0,2,0,0,0,0,2,0,2,0,2,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,1,1,0,0,2,0,0,0,0,2,0,2,0,2,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,1,1,0,0,0,0,0,0,0,2,0,2,0,2,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,1,1,0,0,2,0,0,0,0,2,0,2,0,2,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,0
    ._mapa3 //dngn_001
    defb 9,5,5,5,5,5,5,3,3,5,5,5,5,5,5,9
    defb 9,5,9,9,9,9,9,4,4,9,9,9,9,9,5,9
    defb 9,5,9,4,4,4,9,3,4,4,4,9,4,9,5,9
    defb 9,5,9,4,9,4,9,4,9,9,4,9,4,9,5,9
    defb 9,5,4,4,9,4,9,4,4,9,4,9,4,4,5,9
    defb 9,5,9,4,9,4,9,9,4,9,4,9,4,9,5,9
    defb 9,5,9,4,9,4,4,4,3,9,4,9,4,9,5,9
    defb 9,5,9,9,9,9,9,4,4,9,4,4,4,9,5,9
    defb 9,5,5,5,5,5,5,9,9,5,5,5,5,5,5,9
    ._mapa4 //start -1 dungeon enter
    defb 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
    defb 0,1,0,0,0,0,0,8,0,0,0,0,0,0,1,0
    defb 0,1,0,0,0,0,6,9,7,0,0,0,0,0,1,0
    defb 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
    defb 0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
    defb 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
    ._mapa5 //from_start_room_door
    defb 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
    defb 0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
    defb 0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
    defb 0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
    defb 0,1,0,11,0,0,0,10,0,0,0,0,11,0,1,0
    defb 0,1,0,0,0,0,0,12,0,0,0,0,0,0,1,0
    defb 0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
    defb 0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
    defb 0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0
#endasm

unsigned char Fx_anim;
unsigned char attack_timer;

unsigned char ex;      // enemigo pos x (tile)
unsigned char ey;      // enemigo pos y (tile)
unsigned char eanim;   // frame animacion enemigo
unsigned char emov;    // contador movimiento enemigo
unsigned char eactive; // enemigo activo en este mapa

//border color. 0_black, 1_blue, 2_red, 3_magenta, 4_green, 5_teal, 6_yellow, 7_white
void carga_datos_mapa (void) {
    eactive = (mapa_actual == 1) ? 1 : 0;
    if (mapa_actual == 1) {
        port_out (254,6); 
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa1[x];
        }
    }
    if (mapa_actual == 2) {
        port_out (254,6);
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa2[x];
        }
    }
    if (mapa_actual == 3) {
        port_out (254,0);
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa3[x];
        }
    }
    if (mapa_actual == 4) {
        port_out (254,6);
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa4[x];
        }
    }
    if (mapa_actual == 5) {
        port_out (254,0);
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa5[x];
        }
    }
}

// devuelve el mapa conectado en la direccion dada, 0 si no hay conexion
// mapa1: derecha→mapa2, izquierda→mapa4
// mapa2: izquierda→mapa1
// mapa4: derecha→mapa1
unsigned char get_mapa_conexion(unsigned char mapa, unsigned char dir) {
    switch(mapa) {
        case 1:
            if (dir == DIR_DER) return 2;
            if (dir == DIR_IZQ) return 4;
        break;
        case 2:
            if (dir == DIR_IZQ) return 1;
        break;
        case 4:
            if (dir == DIR_DER) return 1;
        break;
    }
    return 0;
}

void inicia_variables_juego(void) {
    //heroe
    hx = 7; //hero pos x start
    hy = 2; //hero pos y start
    hmap = 0;
    anim = 0;
    vista = 0;

    //ataque
    attack_timer = 0;

    //enemigo
    ex = 7;
    ey = 7;
    eanim = 0;
    emov = 0;
    eactive = 1;

    //mapa actual
    ancho_mapa = 16;
    alto_mapa = 9;
    mapa_actual = 1;
    carga_datos_mapa();
}
