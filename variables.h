//zxelda v0.1a
//16mar'26

unsigned char modo_app=0; //0 menu, 1 juego
unsigned char x,y; //render mapa

unsigned char hx; //hero
unsigned char hy;
unsigned char hmap;
int anim;
unsigned char vista;

unsigned char ancho_mapa;
unsigned char alto_mapa;
unsigned char mapa_actual;
unsigned char mapa_trabajo[140];
extern unsigned char mapa1[];
extern unsigned char mapa2[];
extern unsigned char mapa3[];

#asm
    ._mapa1
    defb 1,1,1,1,1,1,0,0,1,1,1,1,1,1
    defb 1,1,9,1,1,0,0,0,1,1,1,1,1,1
    defb 1,1,0,0,0,0,0,0,1,1,1,1,1,1
    defb 1,0,0,0,0,0,0,0,0,1,1,1,1,1
    defb 1,0,0,0,0,0,0,0,0,0,0,0,0,1
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,0,0,0,0,0,0,0,0,0,1,1,1
    defb 1,1,0,0,0,0,0,0,0,0,1,1,1,1
    defb 1,1,1,1,1,1,1,1,1,1,1,1,1,1
    ._mapa2
    defb 1,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,0,0,0,0,0,0,0,0,0,0,0,0
    defb 1,1,2,2,2,2,2,2,2,2,2,2,2,2
    ._mapa3
    defb 3,3,3,3,3,3,3,3,3,3,3,3,3,3
    defb 3,4,4,4,4,4,4,4,3,3,3,3,3,3
    defb 3,4,4,4,4,4,4,4,4,4,3,3,3,3
    defb 3,4,4,4,4,4,4,4,4,4,4,3,3,3
    defb 3,4,4,4,4,4,4,4,4,4,4,4,4,3
    defb 3,4,4,4,4,4,4,4,4,4,4,3,3,3
    defb 3,4,4,4,4,4,4,4,4,4,3,3,3,3
    defb 3,4,4,4,4,4,4,4,3,3,3,3,3,3
    defb 3,0,0,3,3,3,3,3,3,3,3,3,3,3
#endasm

unsigned char Fx_anim;

void carga_datos_mapa (void) {
    if (mapa_actual == 1) {
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa1[x];
        }
    }
    if (mapa_actual == 2) {
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa2[x];
        }
    }
    if (mapa_actual == 3) {
        for (x = 0; x < ancho_mapa * alto_mapa; x++) {
            mapa_trabajo[x] = mapa3[x];
        }
    }
}

// devuelve el mapa conectado en la direccion dada, 0 si no hay conexion
// mapa1: derecha→mapa2
// mapa2: izquierda→mapa1, arriba→mapa3
// mapa3: abajo→mapa2
unsigned char get_mapa_conexion(unsigned char mapa, unsigned char dir) {
    switch(mapa) {
        case 1:
            if (dir == DIR_DER) return 2;
        break;
        case 2:
            if (dir == DIR_IZQ) return 1;
            if (dir == DIR_ARR) return 3;
        break;
        case 3:
            if (dir == DIR_ABA) return 2;
        break;
    }
    return 0;
}

void inicia_variables_juego(void) {
    //heroe
    hx = 7;
    hy = 2;
    hmap = 0;
    anim = 0;
    vista = 0;

    //mapa actual
    ancho_mapa = 14;
    alto_mapa = 9;
    mapa_actual = 1;
    carga_datos_mapa();
}
