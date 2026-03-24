//zxelda v0.1a
//16mar'26

extern unsigned char sprite_negro [];

//extern unsigned char sprite_azulB [];
//extern unsigned char sprite_rojoB [];
//extern unsigned char sprite_magB [];
//extern unsigned char sprite_verB [];
//extern unsigned char sprite_tealB [];
//extern unsigned char sprite_amaB [];
//extern unsigned char sprite_blaB [];

//extern unsigned char sprite_azulD [];
//extern unsigned char sprite_rojoD [];
//extern unsigned char sprite_magD [];
//extern unsigned char sprite_verD [];
//extern unsigned char sprite_tealD [];
extern unsigned char sprite_amaD [];
//extern unsigned char sprite_blaD [];

extern unsigned char worldA_forest [];
extern unsigned char worldA_bush [];

extern unsigned char worldB_tile [];
extern unsigned char worldB_block [];

extern unsigned char sprite_linkUpA [];
extern unsigned char sprite_linkUpB [];
extern unsigned char sprite_linkDownA [];
extern unsigned char sprite_linkDownB [];
extern unsigned char sprite_linkRight [];
extern unsigned char sprite_linkLeftt [];

//extern unsigned char anim1 [];
//extern unsigned char anim2 [];
//extern unsigned char anim3 [];
//extern unsigned char anim4 [];
//extern unsigned char anim1b [];
//extern unsigned char anim2b [];
//extern unsigned char anim3b [];
//extern unsigned char anim4b [];

#asm
    ._worldA_forest
	defb	224,192,241,240,241,242,113,250
	defb	115,250,243,254,243,224,243,220
	defb	227,222,227,222, 65,220, 64,156
	defb	159, 28,158, 28,191, 24, 44,  0
	defb	  4,  4,  4,  4

    ._worldA_bush
	DEFB	 10, 64, 47,168, 55,212,127,234
	DEFB	125,213,255,250,223,244,127,106
	DEFB	247,228,255,160,223,208,126, 32
	DEFB	 26,  0,  5,192, 14,170, 21, 85
	DEFB	  4,  4,  4,  4

    ._worldB_tile
	DEFB	  0,  0,112,  1, 96,  1, 96,  1
	DEFB	 64,  1, 64,  1, 64,  1,  0,  1
	DEFB	  0,  1,  0,  1,  0,  1,  0,  1
	DEFB	  0,  1,  0,  1,  0,  1,127,254
	DEFB	 56, 56, 56, 56

    ._worldB_block
    DEFB	127,254,191,253,223,251,239,247
	DEFB	247,239,251,223,252, 63,252, 63
	DEFB	252, 63,252, 63,251,223,247,239
	DEFB	239,247,223,251,191,253,127,254
	DEFB	 56, 56, 56, 56


    ._sprite_linkUpA
    DEFB	  7,224, 15,240, 47,244, 47,244
	DEFB	 63,252, 63,252, 23,232, 25,144
	DEFB	 28, 60, 55,238,127,254,119,238
	DEFB	124, 62, 63,254, 14, 96,  0,112
	DEFB	 60, 60, 60, 60

    ._sprite_linkUpB
    DEFB	  7,224, 15,240, 47,244, 47,244
	DEFB	 63,252, 63,252, 23,232,  9,152
	DEFB	 60, 56,119,236,127,254,119,238
	DEFB	124, 62,127,252,  6,112, 14,  0
	DEFB	 60, 60, 60, 60

    ._sprite_linkDownA
	DEFB	  7,224, 15,240, 40, 20, 47,244
	DEFB	 56, 28, 34, 68, 16,  8,  9,152
	DEFB	 60, 56,111,236, 68,214,110, 42
	DEFB	108,246,127,252,  6,112, 14,  0
	DEFB	 60, 60, 60, 60
	
	._sprite_linkDownB
	DEFB	  7,224, 15,240, 40, 20, 47,244
	DEFB	 56, 28, 34, 68, 16,  8,  9,144
	DEFB	 60, 32,119,248, 98,120,119, 28
	DEFB	118,116,127,236, 14, 96,  0,112
	DEFB	 60, 60, 60, 60

    ._sprite_linkRight
	DEFB	 15,224, 63,248,123,208,251, 42
	DEFB	153, 46, 28,  2, 15, 14,  7,250
	DEFB	 28, 42, 51,238, 62, 62, 51,242
	DEFB	 60, 48, 31,240,  7,128,  7,192
	DEFB	  0,  0, 15,224, 63,248,123,208
	DEFB	251, 42,153, 46, 28,  2, 15, 14
	DEFB	  7,250, 28, 42, 51,238, 62, 62
	DEFB	115,242,252, 56,255,252,120, 56
	DEFB	 60, 60, 60, 60, 60, 60, 60, 60

    ._sprite_linkLeft
    DEFB	  7,240, 31,252, 11,222, 84,223
	DEFB	116,153, 64, 56,112,240, 95,224
	DEFB	 84, 56,119,204,124,124, 79,204
	DEFB	 12, 60, 15,248,  1,224,  3,224
	DEFB	  0,  0,  7,240, 31,252, 11,222
	DEFB	 84,223,116,153, 64, 56,112,240
	DEFB	 95,224, 84, 56,119,204,124,124
	DEFB	 79,206, 28, 63, 63,255, 28, 30
	DEFB	 60, 60, 60, 60, 60, 60, 60, 60
	

    
    ._sprite_negro
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0
    ._sprite_azulB
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 9,9,9,9
    ._sprite_rojoB
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 80,80,80,80
    ._sprite_magB
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 88,88,88,88
    ._sprite_verB
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 96,96,96,96
    ._sprite_tealB
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 104,104,104,104
    ._sprite_amaB
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 112,112,112,112
    ._sprite_blaB
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 120,120,120,120
    ._sprite_azulD
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 8,8,8,8
    ._sprite_rojoD
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 16,16,16,16
    ._sprite_magD
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 24,24,24,24
    ._sprite_verD
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 32,32,32,32
    ._sprite_tealD
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 40,40,40,40
    ._sprite_amaD
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 48,48,48,48
    ._sprite_blaD
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    defb 56,56,56,56
#endasm
