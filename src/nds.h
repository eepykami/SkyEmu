#ifndef SE_NDS_H
#define SE_NDS_H 1

#include "sb_types.h"


typedef enum{
  kARM7,
  kARM9,
}nds_arm_mode_t;
//////////////////////////////////////////////////////////////////////////////////////////
// MMIO Register listing from GBATEK (https://problemkaputt.de/gbatek.htm#dsiomaps)     //
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////
// GBA I/O Map //
//////////////////

#define GBA_DISPCNT  0x4000000  /* R/W LCD Control */
#define GBA_GREENSWP 0x4000002  /* R/W Undocumented - Green Swap */
#define GBA_DISPSTAT 0x4000004  /* R/W General LCD Status (STAT,LYC) */
#define GBA_VCOUNT   0x4000006  /* R   Vertical Counter (LY) */
#define GBA_BG0CNT   0x4000008  /* R/W BG0 Control */
#define GBA_BG1CNT   0x400000A  /* R/W BG1 Control */
#define GBA_BG2CNT   0x400000C  /* R/W BG2 Control */
#define GBA_BG3CNT   0x400000E  /* R/W BG3 Control */
#define GBA_BG0HOFS  0x4000010  /* W   BG0 X-Offset */
#define GBA_BG0VOFS  0x4000012  /* W   BG0 Y-Offset */
#define GBA_BG1HOFS  0x4000014  /* W   BG1 X-Offset */
#define GBA_BG1VOFS  0x4000016  /* W   BG1 Y-Offset */
#define GBA_BG2HOFS  0x4000018  /* W   BG2 X-Offset */
#define GBA_BG2VOFS  0x400001A  /* W   BG2 Y-Offset */
#define GBA_BG3HOFS  0x400001C  /* W   BG3 X-Offset */
#define GBA_BG3VOFS  0x400001E  /* W   BG3 Y-Offset */
#define GBA_BG2PA    0x4000020  /* W   BG2 Rotation/Scaling Parameter A (dx) */
#define GBA_BG2PB    0x4000022  /* W   BG2 Rotation/Scaling Parameter B (dmx) */
#define GBA_BG2PC    0x4000024  /* W   BG2 Rotation/Scaling Parameter C (dy) */
#define GBA_BG2PD    0x4000026  /* W   BG2 Rotation/Scaling Parameter D (dmy) */
#define GBA_BG2X     0x4000028  /* W   BG2 Reference Point X-Coordinate */
#define GBA_BG2Y     0x400002C  /* W   BG2 Reference Point Y-Coordinate */
#define GBA_BG3PA    0x4000030  /* W   BG3 Rotation/Scaling Parameter A (dx) */
#define GBA_BG3PB    0x4000032  /* W   BG3 Rotation/Scaling Parameter B (dmx) */
#define GBA_BG3PC    0x4000034  /* W   BG3 Rotation/Scaling Parameter C (dy) */
#define GBA_BG3PD    0x4000036  /* W   BG3 Rotation/Scaling Parameter D (dmy) */
#define GBA_BG3X     0x4000038  /* W   BG3 Reference Point X-Coordinate */
#define GBA_BG3Y     0x400003C  /* W   BG3 Reference Point Y-Coordinate */
#define GBA_WIN0H    0x4000040  /* W   Window 0 Horizontal Dimensions */
#define GBA_WIN1H    0x4000042  /* W   Window 1 Horizontal Dimensions */
#define GBA_WIN0V    0x4000044  /* W   Window 0 Vertical Dimensions */
#define GBA_WIN1V    0x4000046  /* W   Window 1 Vertical Dimensions */
#define GBA_WININ    0x4000048  /* R/W Inside of Window 0 and 1 */
#define GBA_WINOUT   0x400004A  /* R/W Inside of OBJ Window & Outside of Windows */
#define GBA_MOSAIC   0x400004C  /* W   Mosaic Size */
#define GBA_BLDCNT   0x4000050  /* R/W Color Special Effects Selection */
#define GBA_BLDALPHA 0x4000052  /* R/W Alpha Blending Coefficients */
#define GBA_BLDY     0x4000054  /* W   Brightness (Fade-In/Out) Coefficient */
#define NDS_DISP3DCNT       0x04000060  /* 3D Display Control Register (R/W) */
#define NDS_DISPCAPCNT      0x04000064  /* Display Capture Control Register (R/W) */
#define NDS_DISP_MMEM_FIFO  0x04000068  /* Main Memory Display FIFO (R?/W) */
#define NDS_A_MASTER_BRIGHT 0x0400006C  /* Master Brightness Up/Down */

// DMA Transfer Channels
#define GBA_DMA0SAD    0x40000B0   /* W    DMA 0 Source Address */
#define GBA_DMA0DAD    0x40000B4   /* W    DMA 0 Destination Address */
#define GBA_DMA0CNT_L  0x40000B8   /* W    DMA 0 Word Count */
#define GBA_DMA0CNT_H  0x40000BA   /* R/W  DMA 0 Control */
#define GBA_DMA1SAD    0x40000BC   /* W    DMA 1 Source Address */
#define GBA_DMA1DAD    0x40000C0   /* W    DMA 1 Destination Address */
#define GBA_DMA1CNT_L  0x40000C4   /* W    DMA 1 Word Count */
#define GBA_DMA1CNT_H  0x40000C6   /* R/W  DMA 1 Control */
#define GBA_DMA2SAD    0x40000C8   /* W    DMA 2 Source Address */
#define GBA_DMA2DAD    0x40000CC   /* W    DMA 2 Destination Address */
#define GBA_DMA2CNT_L  0x40000D0   /* W    DMA 2 Word Count */
#define GBA_DMA2CNT_H  0x40000D2   /* R/W  DMA 2 Control */
#define GBA_DMA3SAD    0x40000D4   /* W    DMA 3 Source Address */
#define GBA_DMA3DAD    0x40000D8   /* W    DMA 3 Destination Address */
#define GBA_DMA3CNT_L  0x40000DC   /* W    DMA 3 Word Count */
#define GBA_DMA3CNT_H  0x40000DE   /* R/W  DMA 3 Control */

// Timer Registers
#define GBA_TM0CNT_L   0x4000100   /* R/W   Timer 0 Counter/Reload */
#define GBA_TM0CNT_H   0x4000102   /* R/W   Timer 0 Control */
#define GBA_TM1CNT_L   0x4000104   /* R/W   Timer 1 Counter/Reload */
#define GBA_TM1CNT_H   0x4000106   /* R/W   Timer 1 Control */
#define GBA_TM2CNT_L   0x4000108   /* R/W   Timer 2 Counter/Reload */
#define GBA_TM2CNT_H   0x400010A   /* R/W   Timer 2 Control */
#define GBA_TM3CNT_L   0x400010C   /* R/W   Timer 3 Counter/Reload */
#define GBA_TM3CNT_H   0x400010E   /* R/W   Timer 3 Control */

// Serial Communication (1)
#define GBA_SIODATA32    0x4000120 /*R/W   SIO Data (Normal-32bit Mode; shared with below) */
#define GBA_SIOMULTI0    0x4000120 /*R/W   SIO Data 0 (Parent)    (Multi-Player Mode) */
#define GBA_SIOMULTI1    0x4000122 /*R/W   SIO Data 1 (1st Child) (Multi-Player Mode) */
#define GBA_SIOMULTI2    0x4000124 /*R/W   SIO Data 2 (2nd Child) (Multi-Player Mode) */
#define GBA_SIOMULTI3    0x4000126 /*R/W   SIO Data 3 (3rd Child) (Multi-Player Mode) */
#define GBA_SIOCNT       0x4000128 /*R/W   SIO Control Register */
#define GBA_SIOMLT_SEND  0x400012A /*R/W   SIO Data (Local of MultiPlayer; shared below) */
#define GBA_SIODATA8     0x400012A /*R/W   SIO Data (Normal-8bit and UART Mode) */

// Keypad Input
#define GBA_KEYINPUT  0x4000130    /* R      Key Status */
#define GBA_KEYCNT    0x4000132    /* R/W    Key Interrupt Control */

// Serial Communication (2)
#define GBA_RCNT      0x4000134    /* R/W  SIO Mode Select/General Purpose Data */
#define GBA_IR        0x4000136    /* -    Ancient - Infrared Register (Prototypes only) */
#define GBA_JOYCNT    0x4000140    /* R/W  SIO JOY Bus Control */
#define GBA_JOY_RECV  0x4000150    /* R/W  SIO JOY Bus Receive Data */
#define GBA_JOY_TRANS 0x4000154    /* R/W  SIO JOY Bus Transmit Data */
#define GBA_JOYSTAT   0x4000158    /* R/?  SIO JOY Bus Receive Status */

//////////////////
// ARM9 I/O Map //
//////////////////

// ARM9 IPC/ROM

#define NDS9_IPCSYNC     0x04000180   /*IPC Synchronize Register (R/W)*/
#define NDS9_IPCFIFOCNT  0x04000184   /*IPC Fifo Control Register (R/W)*/
#define NDS9_IPCFIFOSEND 0x04000188   /*IPC Send Fifo (W)*/
#define NDS9_AUXSPICNT   0x040001A0   /*Gamecard ROM and SPI Control*/
#define NDS9_AUXSPIDATA  0x040001A2   /*Gamecard SPI Bus Data/Strobe*/
#define NDS9_GC_BUS_CTL  0x040001A4   /*Gamecard bus timing/control*/
#define NDS9_GC_BUS_DAT  0x040001A8   /*Gamecard bus 8-byte command out*/
#define NDS9_GC_ENC0_LO  0x040001B0   /*Gamecard Encryption Seed 0 Lower 32bit*/
#define NDS9_GC_ENC1_LO  0x040001B4   /*Gamecard Encryption Seed 1 Lower 32bit*/
#define NDS9_GC_ENC0_HI  0x040001B8   /*Gamecard Encryption Seed 0 Upper 7bit (bit7-15 unused)*/
#define NDS9_GC_ENC1_HI  0x040001BA   /*Gamecard Encryption Seed 1 Upper 7bit (bit7-15 unused)*/

// ARM9 Memory and IRQ Control

#define NDS9_EXMEMCNT  0x04000204 /* External Memory Control (R/W) */
#define NDS9_IME       0x04000208 /* Interrupt Master Enable (R/W) */
#define NDS9_IE        0x04000210 /* Interrupt Enable (R/W) */
#define NDS9_IF        0x04000214 /* Interrupt Request Flags (R/W) */
#define NDS9_VRAMCNT_A 0x04000240 /* VRAM-A (128K) Bank Control (W) */
#define NDS9_VRAMCNT_B 0x04000241 /* VRAM-B (128K) Bank Control (W) */
#define NDS9_VRAMCNT_C 0x04000242 /* VRAM-C (128K) Bank Control (W) */
#define NDS9_VRAMCNT_D 0x04000243 /* VRAM-D (128K) Bank Control (W) */
#define NDS9_VRAMCNT_E 0x04000244 /* VRAM-E (64K) Bank Control (W) */
#define NDS9_VRAMCNT_F 0x04000245 /* VRAM-F (16K) Bank Control (W) */
#define NDS9_VRAMCNT_G 0x04000246 /* VRAM-G (16K) Bank Control (W) */
#define NDS9_WRAMCNT   0x04000247 /* WRAM Bank Control (W) */
#define NDS9_VRAMCNT_H 0x04000248 /* VRAM-H (32K) Bank Control (W) */
#define NDS9_VRAMCNT_I 0x04000249 /* VRAM-I (16K) Bank Control (W) */

// ARM9 Maths

#define NDS9_DIVCNT        0x04000280 /* Division Control (R/W) */
#define NDS9_DIV_NUMER     0x04000290 /* Division Numerator (R/W) */
#define NDS9_DIV_DENOM     0x04000298 /* Division Denominator (R/W) */
#define NDS9_DIV_RESULT    0x040002A0 /* Division Quotient (=Numer/Denom) (R) */
#define NDS9_DIVREM_RESULT 0x040002A8 /* Division Remainder (=Numer MOD Denom) (R) */
#define NDS9_SQRTCNT       0x040002B0 /* Square Root Control (R/W) */
#define NDS9_SQRT_RESULT   0x040002B4 /* Square Root Result (R) */
#define NDS9_SQRT_PARAM    0x040002B8 /* Square Root Parameter Input (R/W) */
#define NDS9_POSTFLG       0x04000300 /* Undoc */
#define NDS9_POWCNT1       0x04000304 /* Graphics Power Control Register (R/W) */

// ARM9 3D Display Engine
#define NDS9_RDLINES_COUNT   0x04000320 /* Rendered Line Count Register (R) */
#define NDS9_EDGE_COLOR      0x04000330 /* Edge Colors 0..7 (W) */
#define NDS9_ALPHA_TEST_REF  0x04000340 /* Alpha-Test Comparision Value (W) */
#define NDS9_CLEAR_COLOR     0x04000350 /* Clear Color Attribute Register (W) */
#define NDS9_CLEAR_DEPTH     0x04000354 /* Clear Depth Register (W) */
#define NDS9_CLRIMAGE_OFFSET 0x04000356 /* Rear-plane Bitmap Scroll Offsets (W) */
#define NDS9_FOG_COLOR       0x04000358 /* Fog Color (W) */
#define NDS9_FOG_OFFSET      0x0400035C /* Fog Depth Offset (W) */
#define NDS9_FOG_TABLE       0x04000360 /* Fog Density Table, 32 entries (W) */
#define NDS9_TOON_TABLE      0x04000380 /* Toon Table, 32 colors (W) */

#define NDS9_GXFIFO          0x04000400 /* Geometry Command FIFO (W) */

#define NDS9_MTX_MODE        0x04000440 /* Set Matrix Mode (W) */ 
#define NDS9_MTX_PUSH        0x04000444 /* Push Current Matrix on Stack (W) */ 
#define NDS9_MTX_POP         0x04000448 /* Pop Current Matrix from Stack (W) */ 
#define NDS9_MTX_STORE       0x0400044C /* Store Current Matrix on Stack (W) */ 
#define NDS9_MTX_RESTORE     0x04000450 /* Restore Current Matrix from Stack (W) */ 
#define NDS9_MTX_IDENTITY    0x04000454 /* Load Unit Matrix to Current Matrix (W) */ 
#define NDS9_MTX_LOAD_4x4    0x04000458 /* Load 4x4 Matrix to Current Matrix (W) */ 
#define NDS9_MTX_LOAD_4x3    0x0400045C /* Load 4x3 Matrix to Current Matrix (W) */ 
#define NDS9_MTX_MULT_4x4    0x04000460 /* Multiply Current Matrix by 4x4 Matrix (W) */ 
#define NDS9_MTX_MULT_4x3    0x04000464 /* Multiply Current Matrix by 4x3 Matrix (W) */ 
#define NDS9_MTX_MULT_3x3    0x04000468 /* Multiply Current Matrix by 3x3 Matrix (W) */ 
#define NDS9_MTX_SCALE       0x0400046C /* Multiply Current Matrix by Scale Matrix (W) */ 
#define NDS9_MTX_TRANS       0x04000470 /* Mult. Curr. Matrix by Translation Matrix (W) */ 
#define NDS9_COLOR           0x04000480 /* Directly Set Vertex Color (W) */ 
#define NDS9_NORMAL          0x04000484 /* Set Normal Vector (W) */ 
#define NDS9_TEXCOORD        0x04000488 /* Set Texture Coordinates (W) */ 
#define NDS9_VTX_16          0x0400048C /* Set Vertex XYZ Coordinates (W) */ 
#define NDS9_VTX_10          0x04000490 /* Set Vertex XYZ Coordinates (W) */ 
#define NDS9_VTX_XY          0x04000494 /* Set Vertex XY Coordinates (W) */ 
#define NDS9_VTX_XZ          0x04000498 /* Set Vertex XZ Coordinates (W) */ 
#define NDS9_VTX_YZ          0x0400049C /* Set Vertex YZ Coordinates (W) */ 
#define NDS9_VTX_DIFF        0x040004A0 /* Set Relative Vertex Coordinates (W) */ 
#define NDS9_POLYGON_ATTR    0x040004A4 /* Set Polygon Attributes (W) */ 
#define NDS9_TEXIMAGE_PARAM  0x040004A8 /* Set Texture Parameters (W) */ 
#define NDS9_PLTT_BASE       0x040004AC /* Set Texture Palette Base Address (W) */ 
#define NDS9_DIF_AMB         0x040004C0 /* MaterialColor0 - Diffuse/Ambient Reflect. (W) */ 
#define NDS9_SPE_EMI         0x040004C4 /* MaterialColor1 - Specular Ref. & Emission (W) */ 
#define NDS9_LIGHT_VECTOR    0x040004C8 /* Set Light's Directional Vector (W) */ 
#define NDS9_LIGHT_COLOR     0x040004CC /* Set Light Color (W) */ 
#define NDS9_SHININESS       0x040004D0 /* Specular Reflection Shininess Table (W) */ 
#define NDS9_BEGIN_VTXS      0x04000500 /* Start of Vertex List (W) */ 
#define NDS9_END_VTXS        0x04000504 /* End of Vertex List (W) */ 
#define NDS9_SWAP_BUFFERS    0x04000540 /* Swap Rendering Engine Buffer (W) */ 
#define NDS9_VIEWPORT        0x04000580 /* Set Viewport (W) */ 
#define NDS9_BOX_TEST        0x040005C0 /* Test if Cuboid Sits inside View Volume (W) */ 
#define NDS9_POS_TEST        0x040005C4 /* Set Position Coordinates for Test (W) */ 
#define NDS9_VEC_TEST        0x040005C8 /* Set Directional Vector for Test (W) */ 

#define NDS9_GXSTAT          0x04000600 /* Geometry Engine Status Register (R and R/W) */
#define NDS9_RAM_COUNT       0x04000604 /* Polygon List & Vertex RAM Count Register (R) */
#define NDS9_DISP_1DOT_DEPTH 0x04000610 /* 1-Dot Polygon Display Boundary Depth (W) */
#define NDS9_POS_RESULT      0x04000620 /* Position Test Results (R) */
#define NDS9_VEC_RESULT      0x04000630 /* Vector Test Results (R) */
#define NDS9_CLIPMTX_RESULT  0x04000640 /* Read Current Clip Coordinates Matrix (R) */
#define NDS9_VECMTX_RESULT   0x04000680 /* Read Current Directional Vector Matrix (R) */

// DS 3D I/O Map
// ARM9 Display Engine B
#define NDS9_B_DISPCNT        0x04001000  /* R/W LCD Control */
#define NDS9_B_BG0CNT         0x04001008  /* R/W BG0 Control */
#define NDS9_B_BG1CNT         0x0400100A  /* R/W BG1 Control */
#define NDS9_B_BG2CNT         0x0400100C  /* R/W BG2 Control */
#define NDS9_B_BG3CNT         0x0400100E  /* R/W BG3 Control */
#define NDS9_B_BG0HOFS        0x04001010  /* W   BG0 X-Offset */
#define NDS9_B_BG0VOFS        0x04001012  /* W   BG0 Y-Offset */
#define NDS9_B_BG1HOFS        0x04001014  /* W   BG1 X-Offset */
#define NDS9_B_BG1VOFS        0x04001016  /* W   BG1 Y-Offset */
#define NDS9_B_BG2HOFS        0x04001018  /* W   BG2 X-Offset */
#define NDS9_B_BG2VOFS        0x0400101A  /* W   BG2 Y-Offset */
#define NDS9_B_BG3HOFS        0x0400101C  /* W   BG3 X-Offset */
#define NDS9_B_BG3VOFS        0x0400101E  /* W   BG3 Y-Offset */
#define NDS9_B_BG2PA          0x04001020  /* W   BG2 Rotation/Scaling Parameter A (dx) */
#define NDS9_B_BG2PB          0x04001022  /* W   BG2 Rotation/Scaling Parameter B (dmx) */
#define NDS9_B_BG2PC          0x04001024  /* W   BG2 Rotation/Scaling Parameter C (dy) */
#define NDS9_B_BG2PD          0x04001026  /* W   BG2 Rotation/Scaling Parameter D (dmy) */
#define NDS9_B_BG2X           0x04001028  /* W   BG2 Reference Point X-Coordinate */
#define NDS9_B_BG2Y           0x0400102C  /* W   BG2 Reference Point Y-Coordinate */
#define NDS9_B_BG3PA          0x04001030  /* W   BG3 Rotation/Scaling Parameter A (dx) */
#define NDS9_B_BG3PB          0x04001032  /* W   BG3 Rotation/Scaling Parameter B (dmx) */
#define NDS9_B_BG3PC          0x04001034  /* W   BG3 Rotation/Scaling Parameter C (dy) */
#define NDS9_B_BG3PD          0x04001036  /* W   BG3 Rotation/Scaling Parameter D (dmy) */
#define NDS9_B_BG3X           0x04001038  /* W   BG3 Reference Point X-Coordinate */
#define NDS9_B_BG3Y           0x0400103C  /* W   BG3 Reference Point Y-Coordinate */
#define NDS9_B_WIN0H          0x04001040  /* W   Window 0 Horizontal Dimensions */
#define NDS9_B_WIN1H          0x04001042  /* W   Window 1 Horizontal Dimensions */
#define NDS9_B_WIN0V          0x04001044  /* W   Window 0 Vertical Dimensions */
#define NDS9_B_WIN1V          0x04001046  /* W   Window 1 Vertical Dimensions */
#define NDS9_B_WININ          0x04001048  /* R/W Inside of Window 0 and 1 */
#define NDS9_B_WINOUT         0x0400104A  /* R/W Inside of OBJ Window & Outside of Windows */
#define NDS9_B_MOSAIC         0x0400104C  /* W   Mosaic Size */
#define NDS9_B_BLDCNT         0x04001050  /* R/W Color Special Effects Selection */
#define NDS9_B_BLDALPHA       0x04001052  /* R/W Alpha Blending Coefficients */
#define NDS9_B_BLDY           0x04001054  /* W   Brightness (Fade-In/Out) Coefficient */

#define NDS9_B_MASTER_BRIGHT  0x0400106C  /* Master Brightness Up/Down */

// ARM9 IPC/ROM

#define NDS_IPCFIFORECV  0x04100000 /* IPC Receive Fifo (R)*/
#define NDS_GC_BUS       0x04100010 /* Gamecard bus 4-byte data in, for manual or dma read (R) (or W) */

//Main Memory Control

#define NDS9_MEM_CTRL 0x027FFFFE /* Main Memory Control*/ 

//////////////////
// ARM7 I/O Map //
//////////////////

#define NDS7_DEBUG_RCNT     0x04000134 /* Debug RCNT */
#define NDS7_EXTKEYIN       0x04000136 /* EXTKEYIN */
#define NDS7_RTC_BUS        0x04000138 /* RTC Realtime Clock Bus */
#define NDS7_IPCSYNC        0x04000180 /* IPC Synchronize Register (R/W) */
#define NDS7_IPCFIFOCNT     0x04000184 /* IPC Fifo Control Register (R/W) */
#define NDS7_IPCFIFOSEND    0x04000188 /* IPC Send Fifo (W) */
#define NDS7_AUXSPICNT      0x040001A0 /* Gamecard ROM and SPI Control */
#define NDS7_AUXSPIDATA     0x040001A2 /* Gamecard SPI Bus Data/Strobe */
#define NDS7_GCBUS_CTL      0x040001A4 /* Gamecard bus timing/control */
#define NDS7_GCBUS_CMD      0x040001A8 /* Gamecard bus 8-byte command out */
#define NDS7_GCBUS_SEED0_LO 0x040001B0 /* Gamecard Encryption Seed 0 Lower 32bit */
#define NDS7_GCBUS_SEED1_LO 0x040001B4 /* Gamecard Encryption Seed 1 Lower 32bit */
#define NDS7_GCBUS_SEED0_HI 0x040001B8 /* Gamecard Encryption Seed 0 Upper 7bit (bit7-15 unused) */
#define NDS7_GCBUS_SEED1_HI 0x040001BA /* Gamecard Encryption Seed 1 Upper 7bit (bit7-15 unused) */
#define NDS7_SPI_BUS_CTL    0x040001C0 /* SPI bus Control (Firmware, Touchscreen, Powerman) */
#define NDS7_SPI_BUS_DATA   0x040001C2 /* SPI bus Data */

// ARM7 Memory and IRQ Control
#define NDS7_EXMEMSTAT   0x04000204 /* EXMEMSTAT - External Memory Status */
#define NDS7_WIFIWAITCNT 0x04000206 /* WIFIWAITCNT */
#define NDS7_IME         0x04000208 /* IME - Interrupt Master Enable (R/W) */
#define NDS7_IE          0x04000210 /* IE  - Interrupt Enable (R/W) */
#define NDS7_IF          0x04000214 /* IF  - Interrupt Request Flags (R/W) */
#define NDS7_VRAMSTAT    0x04000240 /* VRAMSTAT - VRAM-C,D Bank Status (R) */
#define NDS7_WRAMSTAT    0x04000241 /* WRAMSTAT - WRAM Bank Status (R) */
#define NDS7_POSTFLG     0x04000300 /* POSTFLG */
#define NDS7_HALTCNT     0x04000301 /* HALTCNT (different bits than on GBA) (plus NOP delay) */
#define NDS7_POWCNT2     0x04000304 /* POWCNT2  Sound/Wifi Power Control Register (R/W) */
#define NDS7_BIOSPROT    0x04000308 /* BIOSPROT - Bios-data-read-protection address */

// ARM7 Sound Registers (Sound Channel 0..15 (10h bytes each)) 
#define NDS7_SOUND0_CNT 0x04000400 /* Sound Channel 0 Control Register (R/W) */
#define NDS7_SOUND0_SAD 0x04000404 /* Sound Channel 0 Data Source Register (W) */
#define NDS7_SOUND0_TMR 0x04000408 /* Sound Channel 0 Timer Register (W) */
#define NDS7_SOUND0_PNT 0x0400040A /* Sound Channel 0 Loopstart Register (W) */
#define NDS7_SOUND0_LEN 0x0400040C /* Sound Channel 0 Length Register (W) */
#define NDS7_SOUND1_CNT 0x04001400 /* Sound Channel 1 Control Register (R/W) */
#define NDS7_SOUND1_SAD 0x04001404 /* Sound Channel 1 Data Source Register (W) */
#define NDS7_SOUND1_TMR 0x04001408 /* Sound Channel 1 Timer Register (W) */
#define NDS7_SOUND1_PNT 0x0400140A /* Sound Channel 1 Loopstart Register (W) */
#define NDS7_SOUND1_LEN 0x0400140C /* Sound Channel 1 Length Register (W) */
#define NDS7_SOUND2_CNT 0x04002400 /* Sound Channel 2 Control Register (R/W) */
#define NDS7_SOUND2_SAD 0x04002404 /* Sound Channel 2 Data Source Register (W) */
#define NDS7_SOUND2_TMR 0x04002408 /* Sound Channel 2 Timer Register (W) */
#define NDS7_SOUND2_PNT 0x0400240A /* Sound Channel 2 Loopstart Register (W) */
#define NDS7_SOUND2_LEN 0x0400240C /* Sound Channel 2 Length Register (W) */
#define NDS7_SOUND3_CNT 0x04003400 /* Sound Channel 3 Control Register (R/W) */
#define NDS7_SOUND3_SAD 0x04003404 /* Sound Channel 3 Data Source Register (W) */
#define NDS7_SOUND3_TMR 0x04003408 /* Sound Channel 3 Timer Register (W) */
#define NDS7_SOUND3_PNT 0x0400340A /* Sound Channel 3 Loopstart Register (W) */
#define NDS7_SOUND3_LEN 0x0400340C /* Sound Channel 3 Length Register (W) */
#define NDS7_SOUND4_CNT 0x04004400 /* Sound Channel 4 Control Register (R/W) */
#define NDS7_SOUND4_SAD 0x04004404 /* Sound Channel 4 Data Source Register (W) */
#define NDS7_SOUND4_TMR 0x04004408 /* Sound Channel 4 Timer Register (W) */
#define NDS7_SOUND4_PNT 0x0400440A /* Sound Channel 4 Loopstart Register (W) */
#define NDS7_SOUND4_LEN 0x0400440C /* Sound Channel 4 Length Register (W) */
#define NDS7_SOUND5_CNT 0x04005400 /* Sound Channel 5 Control Register (R/W) */
#define NDS7_SOUND5_SAD 0x04005404 /* Sound Channel 5 Data Source Register (W) */
#define NDS7_SOUND5_TMR 0x04005408 /* Sound Channel 5 Timer Register (W) */
#define NDS7_SOUND5_PNT 0x0400540A /* Sound Channel 5 Loopstart Register (W) */
#define NDS7_SOUND5_LEN 0x0400540C /* Sound Channel 5 Length Register (W) */
#define NDS7_SOUND6_CNT 0x04006400 /* Sound Channel 6 Control Register (R/W) */
#define NDS7_SOUND6_SAD 0x04006404 /* Sound Channel 6 Data Source Register (W) */
#define NDS7_SOUND6_TMR 0x04006408 /* Sound Channel 6 Timer Register (W) */
#define NDS7_SOUND6_PNT 0x0400640A /* Sound Channel 6 Loopstart Register (W) */
#define NDS7_SOUND6_LEN 0x0400640C /* Sound Channel 6 Length Register (W) */
#define NDS7_SOUND7_CNT 0x04007400 /* Sound Channel 7 Control Register (R/W) */
#define NDS7_SOUND7_SAD 0x04007404 /* Sound Channel 7 Data Source Register (W) */
#define NDS7_SOUND7_TMR 0x04007408 /* Sound Channel 7 Timer Register (W) */
#define NDS7_SOUND7_PNT 0x0400740A /* Sound Channel 7 Loopstart Register (W) */
#define NDS7_SOUND7_LEN 0x0400740C /* Sound Channel 7 Length Register (W) */
#define NDS7_SOUND8_CNT 0x04008400 /* Sound Channel 8 Control Register (R/W) */
#define NDS7_SOUND8_SAD 0x04008404 /* Sound Channel 8 Data Source Register (W) */
#define NDS7_SOUND8_TMR 0x04008408 /* Sound Channel 8 Timer Register (W) */
#define NDS7_SOUND8_PNT 0x0400840A /* Sound Channel 8 Loopstart Register (W) */
#define NDS7_SOUND8_LEN 0x0400840C /* Sound Channel 8 Length Register (W) */
#define NDS7_SOUND9_CNT 0x04009400 /* Sound Channel 9 Control Register (R/W) */
#define NDS7_SOUND9_SAD 0x04009404 /* Sound Channel 9 Data Source Register (W) */
#define NDS7_SOUND9_TMR 0x04009408 /* Sound Channel 9 Timer Register (W) */
#define NDS7_SOUND9_PNT 0x0400940A /* Sound Channel 9 Loopstart Register (W) */
#define NDS7_SOUND9_LEN 0x0400940C /* Sound Channel 9 Length Register (W) */
#define NDS7_SOUNDA_CNT 0x0400A400 /* Sound Channel 10 Control Register (R/W) */
#define NDS7_SOUNDA_SAD 0x0400A404 /* Sound Channel 10 Data Source Register (W) */
#define NDS7_SOUNDA_TMR 0x0400A408 /* Sound Channel 10 Timer Register (W) */
#define NDS7_SOUNDA_PNT 0x0400A40A /* Sound Channel 10 Loopstart Register (W) */
#define NDS7_SOUNDA_LEN 0x0400A40C /* Sound Channel 10 Length Register (W) */
#define NDS7_SOUNDB_CNT 0x0400B400 /* Sound Channel 11 Control Register (R/W) */
#define NDS7_SOUNDB_SAD 0x0400B404 /* Sound Channel 11 Data Source Register (W) */
#define NDS7_SOUNDB_TMR 0x0400B408 /* Sound Channel 11 Timer Register (W) */
#define NDS7_SOUNDB_PNT 0x0400B40A /* Sound Channel 11 Loopstart Register (W) */
#define NDS7_SOUNDB_LEN 0x0400B40C /* Sound Channel 11 Length Register (W) */
#define NDS7_SOUNDC_CNT 0x0400C400 /* Sound Channel 12 Control Register (R/W) */
#define NDS7_SOUNDC_SAD 0x0400C404 /* Sound Channel 12 Data Source Register (W) */
#define NDS7_SOUNDC_TMR 0x0400C408 /* Sound Channel 12 Timer Register (W) */
#define NDS7_SOUNDC_PNT 0x0400C40A /* Sound Channel 12 Loopstart Register (W) */
#define NDS7_SOUNDC_LEN 0x0400C40C /* Sound Channel 12 Length Register (W) */
#define NDS7_SOUNDD_CNT 0x0400D400 /* Sound Channel 13 Control Register (R/W) */
#define NDS7_SOUNDD_SAD 0x0400D404 /* Sound Channel 13 Data Source Register (W) */
#define NDS7_SOUNDD_TMR 0x0400D408 /* Sound Channel 13 Timer Register (W) */
#define NDS7_SOUNDD_PNT 0x0400D40A /* Sound Channel 13 Loopstart Register (W) */
#define NDS7_SOUNDD_LEN 0x0400D40C /* Sound Channel 13 Length Register (W) */
#define NDS7_SOUNDE_CNT 0x0400E400 /* Sound Channel 14 Control Register (R/W) */
#define NDS7_SOUNDE_SAD 0x0400E404 /* Sound Channel 14 Data Source Register (W) */
#define NDS7_SOUNDE_TMR 0x0400E408 /* Sound Channel 14 Timer Register (W) */
#define NDS7_SOUNDE_PNT 0x0400E40A /* Sound Channel 14 Loopstart Register (W) */
#define NDS7_SOUNDE_LEN 0x0400E40C /* Sound Channel 14 Length Register (W) */
#define NDS7_SOUNDF_CNT 0x0400F400 /* Sound Channel 15 Control Register (R/W) */
#define NDS7_SOUNDF_SAD 0x0400F404 /* Sound Channel 15 Data Source Register (W) */
#define NDS7_SOUNDF_TMR 0x0400F408 /* Sound Channel 15 Timer Register (W) */
#define NDS7_SOUNDF_PNT 0x0400F40A /* Sound Channel 15 Loopstart Register (W) */
#define NDS7_SOUNDF_LEN 0x0400F40C /* Sound Channel 15 Length Register (W) */

#define NDS7_SOUNDCNT   0x04000500 /* Sound Control Register (R/W) */
#define NDS7_SOUNDBIAS  0x04000504 /* Sound Bias Register (R/W) */
#define NDS7_SNDCAP0CNT 0x04000508 /* Sound Capture 0 Control Register (R/W) */
#define NDS7_SNDCAP1CNT 0x04000509 /* Sound Capture 1 Control Register (R/W) */
#define NDS7_SNDCAP0DAD 0x04000510 /* Sound Capture 0 Destination Address (R/W) */
#define NDS7_SNDCAP0LEN 0x04000514 /* Sound Capture 0 Length (W) */
#define NDS7_SNDCAP1DAD 0x04000518 /* Sound Capture 1 Destination Address (R/W) */
#define NDS7_SNDCAP1LEN 0x0400051C /* Sound Capture 1 Length (W) */


mmio_reg_t nds9_io_reg_desc[]={
  { GBA_DISPCNT , "DISPCNT ", { 
    { 0, 3, "BG Mode (0-5=Video Mode 0-5, 6-7=Prohibited)"},
    { 3 ,1, "Reserved / CGB Mode (0=GBA, 1=CGB)"},
    { 4 ,1, "Display Frame Select (0-1=Frame 0-1)"},
    { 5 ,1, "H-Blank Interval Free (1=Allow access to OAM during H-Blank)"},
    { 6 ,1, "OBJ Character VRAM Mapping (0=2D, 1=1D"},
    { 7 ,1, "Forced Blank (1=Allow FAST VRAM,Palette,OAM)"},
    { 8 ,1, "Screen Display BG0 (0=Off, 1=On)"},
    { 9 ,1, "Screen Display BG1 (0=Off, 1=On)"},
    { 10,1, "Screen Display BG2 (0=Off, 1=On)"},
    { 11,1, "Screen Display BG3 (0=Off, 1=On)"},
    { 12,1, "Screen Display OBJ (0=Off, 1=On)"},
    { 13,1, "Window 0 Display Flag (0=Off, 1=On)"},
    { 14,1, "Window 1 Display Flag (0=Off, 1=On)"},
    { 15,1, "OBJ Window Display Flag (0=Off, 1=On)"},
  } },
  { GBA_GREENSWP, "GREENSWP", { {0, 1, "Green Swap  (0=Normal, 1=Swap)" }} }, /* R/W Undocumented - Green Swap */
  { GBA_DISPSTAT, "DISPSTAT", { 
    { 0,1, "V-Blank flag (1=VBlank) (set in line 160..226; not 227",},
    { 1,1, "H-Blank flag (1=HBlank) (toggled in all lines, 0..227",},
    { 2,1, "V-Counter flag (1=Match) (set in selected line)",},
    { 3,1, "V-Blank IRQ Enable (1=Enable)",},
    { 4,1, "H-Blank IRQ Enable (1=Enable)",},
    { 5,1, "V-Counter IRQ Enable (1=Enable)",},
    { 6,1, "DSi: LCD Initialization Ready (0=Busy, 1=Ready",},
    { 7,1, "NDS: MSB of V-Vcount Setting (LYC.Bit8) (0..262",},
    { 8,8, "V-Count Setting (LYC) (0..227)",},

  } }, /* R/W General LCD Status (STAT,LYC) */
  { GBA_VCOUNT  , "VCOUNT  ", { 0 } }, /* R   Vertical Counter (LY) */
  { GBA_BG0CNT  , "BG0CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG0 Control */
  { GBA_BG1CNT  , "BG1CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG1 Control */
  { GBA_BG2CNT  , "BG2CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG2 Control */
  { GBA_BG3CNT  , "BG3CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG3 Control */
  { GBA_BG0HOFS , "BG0HOFS", { 0 } }, /* W   BG0 X-Offset */
  { GBA_BG0VOFS , "BG0VOFS", { 0 } }, /* W   BG0 Y-Offset */
  { GBA_BG1HOFS , "BG1HOFS", { 0 } }, /* W   BG1 X-Offset */
  { GBA_BG1VOFS , "BG1VOFS", { 0 } }, /* W   BG1 Y-Offset */
  { GBA_BG2HOFS , "BG2HOFS", { 0 } }, /* W   BG2 X-Offset */
  { GBA_BG2VOFS , "BG2VOFS", { 0 } }, /* W   BG2 Y-Offset */
  { GBA_BG3HOFS , "BG3HOFS", { 0 } }, /* W   BG3 X-Offset */
  { GBA_BG3VOFS , "BG3VOFS", { 0 } }, /* W   BG3 Y-Offset */
  { GBA_BG2PA   , "BG2PA", { 0 } }, /* W   BG2 Rotation/Scaling Parameter A (dx) */
  { GBA_BG2PB   , "BG2PB", { 0 } }, /* W   BG2 Rotation/Scaling Parameter B (dmx) */
  { GBA_BG2PC   , "BG2PC", { 0 } }, /* W   BG2 Rotation/Scaling Parameter C (dy) */
  { GBA_BG2PD   , "BG2PD", { 0 } }, /* W   BG2 Rotation/Scaling Parameter D (dmy) */
  { GBA_BG2X    , "BG2X", { 0 } }, /* W   BG2 Reference Point X-Coordinate */
  { GBA_BG2Y    , "BG2Y", { 0 } }, /* W   BG2 Reference Point Y-Coordinate */
  { GBA_BG3PA   , "BG3PA", { 0 } }, /* W   BG3 Rotation/Scaling Parameter A (dx) */
  { GBA_BG3PB   , "BG3PB", { 0 } }, /* W   BG3 Rotation/Scaling Parameter B (dmx) */
  { GBA_BG3PC   , "BG3PC", { 0 } }, /* W   BG3 Rotation/Scaling Parameter C (dy) */
  { GBA_BG3PD   , "BG3PD", { 0 } }, /* W   BG3 Rotation/Scaling Parameter D (dmy) */
  { GBA_BG3X    , "BG3X", { 0 } }, /* W   BG3 Reference Point X-Coordinate */
  { GBA_BG3Y    , "BG3Y", { 0 } }, /* W   BG3 Reference Point Y-Coordinate */
  { GBA_WIN0H   , "WIN0H", {  
    { 0, 8, "X2, Rightmost coordinate of window, plus 1 " },
    { 8, 8,  "X1, Leftmost coordinate of window"}, 
  } }, /* W   Window 0 Horizontal Dimensions */
  { GBA_WIN1H   , "WIN1H", { 
    { 0, 8, "X2, Rightmost coordinate of window, plus 1 " },
    { 8, 8, "X1, Leftmost coordinate of window"}, 
  } }, /* W   Window 1 Horizontal Dimensions */
  { GBA_WIN0V   , "WIN0V", { 
    {0, 8,  "Y2, Bottom-most coordinate of window, plus 1" },
    {8, 8,  "Y1, Top-most coordinate of window" },
  } }, /* W   Window 0 Vertical Dimensions */
  { GBA_WIN1V   , "WIN1V", { 
    {0, 8,  "Y2, Bottom-most coordinate of window, plus 1" },
    {8, 8,  "Y1, Top-most coordinate of window" },
  } }, /* W   Window 1 Vertical Dimensions */
  { GBA_WININ   , "WININ", {
    { 0 , 1,  "Window 0 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 1 , 1,  "Window 0 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 2 , 1,  "Window 0 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 3 , 1,  "Window 0 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 4 , 1,  "Window 0 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 5 , 1,  "Window 0 Color Special Effect (0=Disable, 1=Enable)"},
    { 8 , 1,  "Window 1 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 9 , 1,  "Window 1 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 10, 1,  "Window 1 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 11, 1,  "Window 1 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 12, 1,  "Window 1 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 13, 1,  "Window 1 Color Special Effect (0=Disable, 1=Enable)"},
  } }, /* R/W Inside of Window 0 and 1 */
  { GBA_WINOUT  , "WINOUT", { 
    { 0 , 1,  "Window 0 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 1 , 1,  "Window 0 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 2 , 1,  "Window 0 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 3 , 1,  "Window 0 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 4 , 1,  "Window 0 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 5 , 1,  "Window 0 Color Special Effect (0=Disable, 1=Enable)"},
    { 8 , 1,  "Window 1 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 9 , 1,  "Window 1 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 10, 1,  "Window 1 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 11, 1,  "Window 1 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 12, 1,  "Window 1 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 13, 1,  "Window 1 Color Special Effect (0=Disable, 1=Enable)"},
  } }, /* R/W Inside of OBJ Window & Outside of Windows */
  { GBA_MOSAIC  , "MOSAIC", { 
    { 0, 4, "BG Mosaic H-Size (minus 1)" },
    { 4, 4, "BG Mosaic V-Size (minus 1)" },
    { 8, 4, "OBJ Mosaic H-Size (minus 1)" },
    { 12,4, "OBJ Mosaic V-Size (minus 1)" },
  } }, /* W   Mosaic Size */
  { GBA_BLDCNT  , "BLDCNT", { 
    { 0 , 1, "BG0 1st Target Pixel (Background 0)" },
    { 1 , 1, "BG1 1st Target Pixel (Background 1)" },
    { 2 , 1, "BG2 1st Target Pixel (Background 2)" },
    { 3 , 1, "BG3 1st Target Pixel (Background 3)" },
    { 4 , 1, "OBJ 1st Target Pixel (Top-most OBJ pixel)" },
    { 5 , 1, "BD  1st Target Pixel (Backdrop)" },
    { 6 , 2, "Color Effect (0: None 1: Alpha 2: Lighten 3: Darken)" },
    { 8 , 1, "BG0 2nd Target Pixel (Background 0)" },
    { 9 , 1, "BG1 2nd Target Pixel (Background 1)" },
    { 10, 1, "BG2 2nd Target Pixel (Background 2)" },
    { 11, 1, "BG3 2nd Target Pixel (Background 3)" },
    { 12, 1, "OBJ 2nd Target Pixel (Top-most OBJ pixel)" },
    { 13, 1, "BD  2nd Target Pixel (Backdrop)" },
  } }, /* R/W Color Special Effects Selection */
  { GBA_BLDALPHA, "BLDALPHA", { 
    {0, 4, "EVA Coef. (1st Target) (0..16 = 0/16..16/16, 17..31=16/16)"},
    {8, 4, "EVB Coef. (2nd Target) (0..16 = 0/16..16/16, 17..31=16/16)"},
  } }, /* R/W Alpha Blending Coefficients */
  { GBA_BLDY    , "BLDY", { 0 } }, /* W   Brightness (Fade-In/Out) Coefficient */  
  { NDS_DISP3DCNT,       "DISP3DCNT",       {}}, /* 3D Display Control Register (R/W) */
  { NDS_DISPCAPCNT,      "DISPCAPCNT",      {}}, /* Display Capture Control Register (R/W) */
  { NDS_DISP_MMEM_FIFO,  "DISP_MMEM_FIFO",  {}}, /* Main Memory Display FIFO (R?/W) */
  { NDS_A_MASTER_BRIGHT, "A_MASTER_BRIGHT", {}}, /* Master Brightness Up/Down */

  // DMA Transfer Channels
  { GBA_DMA0SAD  , "DMA0SAD", { 0 } },   /* W    DMA 0 Source Address */
  { GBA_DMA0DAD  , "DMA0DAD", { 0 } },   /* W    DMA 0 Destination Address */
  { GBA_DMA0CNT_L, "DMA0CNT_L", { 0 } },   /* W    DMA 0 Word Count */
  { GBA_DMA0CNT_H, "DMA0CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Prohibited)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 0 Control */
  { GBA_DMA1SAD  , "DMA1SAD", { 0 } },   /* W    DMA 1 Source Address */
  { GBA_DMA1DAD  , "DMA1DAD", { 0 } },   /* W    DMA 1 Destination Address */
  { GBA_DMA1CNT_L, "DMA1CNT_L", { 0 } },   /* W    DMA 1 Word Count */
  { GBA_DMA1CNT_H, "DMA1CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Sound)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 1 Control */
  { GBA_DMA2SAD  , "DMA2SAD", { 0 } },   /* W    DMA 2 Source Address */
  { GBA_DMA2DAD  , "DMA2DAD", { 0 } },   /* W    DMA 2 Destination Address */
  { GBA_DMA2CNT_L, "DMA2CNT_L", { 0 } },   /* W    DMA 2 Word Count */
  { GBA_DMA2CNT_H, "DMA2CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Sound)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 2 Control */
  { GBA_DMA3SAD  , "DMA3SAD", { 0 } },   /* W    DMA 3 Source Address */
  { GBA_DMA3DAD  , "DMA3DAD", { 0 } },   /* W    DMA 3 Destination Address */
  { GBA_DMA3CNT_L, "DMA3CNT_L", { 0 } },   /* W    DMA 3 Word Count */
  { GBA_DMA3CNT_H, "DMA3CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 11, 1,  "Game Pak DRQ (0=Normal, 1=DRQ <from> Game Pak, DMA3)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Video Capture)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 3 Control */  

  // Timer Registers
  { GBA_TM0CNT_L, "TM0CNT_L", {0} },   /* R/W   Timer 0 Counter/Reload */
  { GBA_TM0CNT_H, "TM0CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 0 Control */
  { GBA_TM1CNT_L, "TM1CNT_L", {0} },   /* R/W   Timer 1 Counter/Reload */
  { GBA_TM1CNT_H, "TM1CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 1 Control */
  { GBA_TM2CNT_L, "TM2CNT_L", {0} },   /* R/W   Timer 2 Counter/Reload */
  { GBA_TM2CNT_H, "TM2CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 2 Control */
  { GBA_TM3CNT_L, "TM3CNT_L", {0} },   /* R/W   Timer 3 Counter/Reload */
  { GBA_TM3CNT_H, "TM3CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 3 Control */  

  // Serial Communication (1)
  { GBA_SIODATA32  , "SIODATA32", {0} }, /*R/W   SIO Data (Normal-32bit Mode; shared with below) */
  { GBA_SIOMULTI0  , "SIOMULTI0", {0} }, /*R/W   SIO Data 0 (Parent)    (Multi-Player Mode) */
  { GBA_SIOMULTI1  , "SIOMULTI1", {0} }, /*R/W   SIO Data 1 (1st Child) (Multi-Player Mode) */
  { GBA_SIOMULTI2  , "SIOMULTI2", {0} }, /*R/W   SIO Data 2 (2nd Child) (Multi-Player Mode) */
  { GBA_SIOMULTI3  , "SIOMULTI3", {0} }, /*R/W   SIO Data 3 (3rd Child) (Multi-Player Mode) */
  { GBA_SIOCNT     , "SIOCNT", {0} }, /*R/W   SIO Control Register */
  { GBA_SIOMLT_SEND, "SIOMLT_SEND", {0} }, /*R/W   SIO Data (Local of MultiPlayer; shared below) */
  { GBA_SIODATA8   , "SIODATA8", {0} }, /*R/W   SIO Data (Normal-8bit and UART Mode) */  

  // Keypad Input
  { GBA_KEYINPUT, "GBA_KEYINPUT", {
    { 0, 1, "Button A" },
    { 1, 1, "Button B" },
    { 2, 1, "Select" },
    { 3, 1, "Start" },
    { 4, 1, "Right" },
    { 5, 1, "Left" },
    { 6, 1, "Up" },
    { 7, 1, "Down" },
    { 8, 1, "Button R" },
    { 9, 1, "Button L" },
  } },    /* R      Key Status */
  { GBA_KEYCNT  , "GBA_KEYCNT", {
    { 0, 1, "Button A" },
    { 1, 1, "Button B" },
    { 2, 1, "Select" },
    { 3, 1, "Start" },
    { 4, 1, "Right" },
    { 5, 1, "Left" },
    { 6, 1, "Up" },
    { 7, 1, "Down" },
    { 8, 1, "Button R" },
    { 9, 1, "Button L" },
    { 14,1, "Button IRQ Enable (0=Disable, 1=Enable)" },
    { 15,1, "Button IRQ Condition (0=OR, 1=AND)"},
  } },    /* R/W    Key Interrupt Control */  

  // Serial Communication (2)
  { GBA_RCNT     , "RCNT", {0} },     /* R/W  SIO Mode Select/General Purpose Data */
  { GBA_IR       , "IR", {0} },     /* -    Ancient - Infrared Register (Prototypes only) */
  { GBA_JOYCNT   , "JOYCNT", {0} },     /* R/W  SIO JOY Bus Control */
  { GBA_JOY_RECV , "JOY_RECV", {0} },     /* R/W  SIO JOY Bus Receive Data */
  { GBA_JOY_TRANS, "JOY_TRANS", {0} },     /* R/W  SIO JOY Bus Transmit Data */
  { GBA_JOYSTAT  , "JOYSTAT", {0} },     /* R/?  SIO JOY Bus Receive Status */  

  { NDS9_IPCSYNC     , "IPCSYNC",     {}}, /*IPC Synchronize Register (R/W)*/
  { NDS9_IPCFIFOCNT  , "IPCFIFOCNT",  {}}, /*IPC Fifo Control Register (R/W)*/
  { NDS9_IPCFIFOSEND , "IPCFIFOSEND", {}}, /*IPC Send Fifo (W)*/
  { NDS9_AUXSPICNT   , "AUXSPICNT",   {}}, /*Gamecard ROM and SPI Control*/
  { NDS9_AUXSPIDATA  , "AUXSPIDATA",  {}}, /*Gamecard SPI Bus Data/Strobe*/
  { NDS9_GC_BUS_CTL  , "GC_BUS_CTL",  {}}, /*Gamecard bus timing/control*/
  { NDS9_GC_BUS_DAT  , "GC_BUS_DAT",  {}}, /*Gamecard bus 8-byte command out*/
  { NDS9_GC_ENC0_LO  , "GC_ENC0_LO",  {}}, /*Gamecard Encryption Seed 0 Lower 32bit*/
  { NDS9_GC_ENC1_LO  , "GC_ENC1_LO",  {}}, /*Gamecard Encryption Seed 1 Lower 32bit*/
  { NDS9_GC_ENC0_HI  , "GC_ENC0_HI",  {}}, /*Gamecard Encryption Seed 0 Upper 7bit (bit7-15 unused)*/
  { NDS9_GC_ENC1_HI  , "GC_ENC1_HI",  {}}, /*Gamecard Encryption Seed 1 Upper 7bit (bit7-15 unused)*/
  
  // ARM9 Memory and IRQ Control
  { NDS9_EXMEMCNT , "EXMEMCNT",  {}}, /* External Memory Control (R/W) */
  { NDS9_IME      , "IME",       {}}, /* Interrupt Master Enable (R/W) */
  { NDS9_IE       , "IE",        {}}, /* Interrupt Enable (R/W) */
  { NDS9_IF       , "IF",        {}}, /* Interrupt Request Flags (R/W) */
  { NDS9_VRAMCNT_A, "VRAMCNT_A", {}}, /* VRAM-A (128K) Bank Control (W) */
  { NDS9_VRAMCNT_B, "VRAMCNT_B", {}}, /* VRAM-B (128K) Bank Control (W) */
  { NDS9_VRAMCNT_C, "VRAMCNT_C", {}}, /* VRAM-C (128K) Bank Control (W) */
  { NDS9_VRAMCNT_D, "VRAMCNT_D", {}}, /* VRAM-D (128K) Bank Control (W) */
  { NDS9_VRAMCNT_E, "VRAMCNT_E", {}}, /* VRAM-E (64K) Bank Control (W) */
  { NDS9_VRAMCNT_F, "VRAMCNT_F", {}}, /* VRAM-F (16K) Bank Control (W) */
  { NDS9_VRAMCNT_G, "VRAMCNT_G", {}}, /* VRAM-G (16K) Bank Control (W) */
  { NDS9_WRAMCNT  , "WRAMCNT",   {}}, /* WRAM Bank Control (W) */
  { NDS9_VRAMCNT_H, "VRAMCNT_H", {}}, /* VRAM-H (32K) Bank Control (W) */
  { NDS9_VRAMCNT_I, "VRAMCNT_I", {}}, /* VRAM-I (16K) Bank Control (W) */
  
  // ARM9 Maths
  { NDS9_DIVCNT,        "DIVCNT",        {}}, /* Division Control (R/W) */
  { NDS9_DIV_NUMER,     "DIV_NUMER",     {}}, /* Division Numerator (R/W) */
  { NDS9_DIV_DENOM,     "DIV_DENOM",     {}}, /* Division Denominator (R/W) */
  { NDS9_DIV_RESULT,    "DIV_RESULT",    {}}, /* Division Quotient (=Numer/Denom) (R) */
  { NDS9_DIVREM_RESULT, "DIVREM_RESULT", {}}, /* Division Remainder (=Numer MOD Denom) (R) */
  { NDS9_SQRTCNT,       "SQRTCNT",       {}}, /* Square Root Control (R/W) */
  { NDS9_SQRT_RESULT,   "SQRT_RESULT",   {}}, /* Square Root Result (R) */
  { NDS9_SQRT_PARAM,    "SQRT_PARAM",    {}}, /* Square Root Parameter Input (R/W) */
  { NDS9_POSTFLG,       "POSTFLG",       {}}, /* Undoc */
  { NDS9_POWCNT1,       "POWCNT1",       {}}, /* Graphics Power Control Register (R/W) */

  // ARM9 3D Display Engine
  { NDS9_RDLINES_COUNT,   "RDLINES_COUNT",   {}}, /* Rendered Line Count Register (R) */
  { NDS9_EDGE_COLOR,      "EDGE_COLOR",      {}}, /* Edge Colors 0..7 (W) */
  { NDS9_ALPHA_TEST_REF,  "ALPHA_TEST_REF",  {}}, /* Alpha-Test Comparision Value (W) */
  { NDS9_CLEAR_COLOR,     "CLEAR_COLOR",     {}}, /* Clear Color Attribute Register (W) */
  { NDS9_CLEAR_DEPTH,     "CLEAR_DEPTH",     {}}, /* Clear Depth Register (W) */
  { NDS9_CLRIMAGE_OFFSET, "CLRIMAGE_OFFSET", {}}, /* Rear-plane Bitmap Scroll Offsets (W) */
  { NDS9_FOG_COLOR,       "FOG_COLOR",       {}}, /* Fog Color (W) */
  { NDS9_FOG_OFFSET,      "FOG_OFFSET",      {}}, /* Fog Depth Offset (W) */
  { NDS9_FOG_TABLE,       "FOG_TABLE",       {}}, /* Fog Density Table, 32 entries (W) */
  { NDS9_TOON_TABLE,      "TOON_TABLE",      {}}, /* Toon Table, 32 colors (W) */
  { NDS9_GXFIFO,          "GXFIFO",          {}}, /* Geometry Command FIFO (W) */
  { NDS9_MTX_MODE,        "MTX_MODE",        {}}, /* Set Matrix Mode (W) */ 
  { NDS9_MTX_PUSH,        "MTX_PUSH",        {}}, /* Push Current Matrix on Stack (W) */ 
  { NDS9_MTX_POP,         "MTX_POP",         {}}, /* Pop Current Matrix from Stack (W) */ 
  { NDS9_MTX_STORE,       "MTX_STORE",       {}}, /* Store Current Matrix on Stack (W) */ 
  { NDS9_MTX_RESTORE,     "MTX_RESTORE",     {}}, /* Restore Current Matrix from Stack (W) */ 
  { NDS9_MTX_IDENTITY,    "MTX_IDENTITY",    {}}, /* Load Unit Matrix to Current Matrix (W) */ 
  { NDS9_MTX_LOAD_4x4,    "MTX_LOAD_4x4",    {}}, /* Load 4x4 Matrix to Current Matrix (W) */ 
  { NDS9_MTX_LOAD_4x3,    "MTX_LOAD_4x3",    {}}, /* Load 4x3 Matrix to Current Matrix (W) */ 
  { NDS9_MTX_MULT_4x4,    "MTX_MULT_4x4",    {}}, /* Multiply Current Matrix by 4x4 Matrix (W) */ 
  { NDS9_MTX_MULT_4x3,    "MTX_MULT_4x3",    {}}, /* Multiply Current Matrix by 4x3 Matrix (W) */ 
  { NDS9_MTX_MULT_3x3,    "MTX_MULT_3x3",    {}}, /* Multiply Current Matrix by 3x3 Matrix (W) */ 
  { NDS9_MTX_SCALE,       "MTX_SCALE",       {}}, /* Multiply Current Matrix by Scale Matrix (W) */ 
  { NDS9_MTX_TRANS,       "MTX_TRANS",       {}}, /* Mult. Curr. Matrix by Translation Matrix (W) */ 
  { NDS9_COLOR,           "COLOR",           {}}, /* Directly Set Vertex Color (W) */ 
  { NDS9_NORMAL,          "NORMAL",          {}}, /* Set Normal Vector (W) */ 
  { NDS9_TEXCOORD,        "TEXCOORD",        {}}, /* Set Texture Coordinates (W) */ 
  { NDS9_VTX_16,          "VTX_16",          {}}, /* Set Vertex XYZ Coordinates (W) */ 
  { NDS9_VTX_10,          "VTX_10",          {}}, /* Set Vertex XYZ Coordinates (W) */ 
  { NDS9_VTX_XY,          "VTX_XY",          {}}, /* Set Vertex XY Coordinates (W) */ 
  { NDS9_VTX_XZ,          "VTX_XZ",          {}}, /* Set Vertex XZ Coordinates (W) */ 
  { NDS9_VTX_YZ,          "VTX_YZ",          {}}, /* Set Vertex YZ Coordinates (W) */ 
  { NDS9_VTX_DIFF,        "VTX_DIFF",        {}}, /* Set Relative Vertex Coordinates (W) */ 
  { NDS9_POLYGON_ATTR,    "POLYGON_ATTR",    {}}, /* Set Polygon Attributes (W) */ 
  { NDS9_TEXIMAGE_PARAM,  "TEXIMAGE_PARAM",  {}}, /* Set Texture Parameters (W) */ 
  { NDS9_PLTT_BASE,       "PLTT_BASE",       {}}, /* Set Texture Palette Base Address (W) */ 
  { NDS9_DIF_AMB,         "DIF_AMB",         {}}, /* MaterialColor0 - Diffuse/Ambient Reflect. (W) */ 
  { NDS9_SPE_EMI,         "SPE_EMI",         {}}, /* MaterialColor1 - Specular Ref. & Emission (W) */ 
  { NDS9_LIGHT_VECTOR,    "LIGHT_VECTOR",    {}}, /* Set Light's Directional Vector (W) */ 
  { NDS9_LIGHT_COLOR,     "LIGHT_COLOR",     {}}, /* Set Light Color (W) */ 
  { NDS9_SHININESS,       "SHININESS",       {}}, /* Specular Reflection Shininess Table (W) */ 
  { NDS9_BEGIN_VTXS,      "BEGIN_VTXS",      {}}, /* Start of Vertex List (W) */ 
  { NDS9_END_VTXS,        "END_VTXS",        {}}, /* End of Vertex List (W) */ 
  { NDS9_SWAP_BUFFERS,    "SWAP_BUFFERS",    {}}, /* Swap Rendering Engine Buffer (W) */ 
  { NDS9_VIEWPORT,        "VIEWPORT",        {}}, /* Set Viewport (W) */ 
  { NDS9_BOX_TEST,        "BOX_TEST",        {}}, /* Test if Cuboid Sits inside View Volume (W) */ 
  { NDS9_POS_TEST,        "POS_TEST",        {}}, /* Set Position Coordinates for Test (W) */ 
  { NDS9_VEC_TEST,        "VEC_TEST",        {}}, /* Set Directional Vector for Test (W) */ 
  { NDS9_GXSTAT,          "GXSTAT",          {}}, /* Geometry Engine Status Register (R and R/W) */
  { NDS9_RAM_COUNT,       "RAM_COUNT",       {}}, /* Polygon List & Vertex RAM Count Register (R) */
  { NDS9_DISP_1DOT_DEPTH, "DISP_1DOT_DEPTH", {}}, /* 1-Dot Polygon Display Boundary Depth (W) */
  { NDS9_POS_RESULT,      "POS_RESULT",      {}}, /* Position Test Results (R) */
  { NDS9_VEC_RESULT,      "VEC_RESULT",      {}}, /* Vector Test Results (R) */
  { NDS9_CLIPMTX_RESULT,  "CLIPMTX_RESULT",  {}}, /* Read Current Clip Coordinates Matrix (R) */
  { NDS9_VECMTX_RESULT,   "VECMTX_RESULT",   {}}, /* Read Current Directional Vector Matrix (R) */

  // ARM9 Display Engine B
  { NDS9_B_BG0CNT  , "(2D-B) BG0CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG0 Control */
  { NDS9_B_BG1CNT  , "(2D-B) BG1CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG1 Control */
  { NDS9_B_BG2CNT  , "(2D-B) BG2CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG2 Control */
  { NDS9_B_BG3CNT  , "(2D-B) BG3CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG3 Control */
  { NDS9_B_BG0HOFS , "(2D-B) BG0HOFS", { 0 } }, /* W   BG0 X-Offset */
  { NDS9_B_BG0VOFS , "(2D-B) BG0VOFS", { 0 } }, /* W   BG0 Y-Offset */
  { NDS9_B_BG1HOFS , "(2D-B) BG1HOFS", { 0 } }, /* W   BG1 X-Offset */
  { NDS9_B_BG1VOFS , "(2D-B) BG1VOFS", { 0 } }, /* W   BG1 Y-Offset */
  { NDS9_B_BG2HOFS , "(2D-B) BG2HOFS", { 0 } }, /* W   BG2 X-Offset */
  { NDS9_B_BG2VOFS , "(2D-B) BG2VOFS", { 0 } }, /* W   BG2 Y-Offset */
  { NDS9_B_BG3HOFS , "(2D-B) BG3HOFS", { 0 } }, /* W   BG3 X-Offset */
  { NDS9_B_BG3VOFS , "(2D-B) BG3VOFS", { 0 } }, /* W   BG3 Y-Offset */
  { NDS9_B_BG2PA   , "(2D-B) BG2PA", { 0 } }, /* W   BG2 Rotation/Scaling Parameter A (dx) */
  { NDS9_B_BG2PB   , "(2D-B) BG2PB", { 0 } }, /* W   BG2 Rotation/Scaling Parameter B (dmx) */
  { NDS9_B_BG2PC   , "(2D-B) BG2PC", { 0 } }, /* W   BG2 Rotation/Scaling Parameter C (dy) */
  { NDS9_B_BG2PD   , "(2D-B) BG2PD", { 0 } }, /* W   BG2 Rotation/Scaling Parameter D (dmy) */
  { NDS9_B_BG2X    , "(2D-B) BG2X", { 0 } }, /* W   BG2 Reference Point X-Coordinate */
  { NDS9_B_BG2Y    , "(2D-B) BG2Y", { 0 } }, /* W   BG2 Reference Point Y-Coordinate */
  { NDS9_B_BG3PA   , "(2D-B) BG3PA", { 0 } }, /* W   BG3 Rotation/Scaling Parameter A (dx) */
  { NDS9_B_BG3PB   , "(2D-B) BG3PB", { 0 } }, /* W   BG3 Rotation/Scaling Parameter B (dmx) */
  { NDS9_B_BG3PC   , "(2D-B) BG3PC", { 0 } }, /* W   BG3 Rotation/Scaling Parameter C (dy) */
  { NDS9_B_BG3PD   , "(2D-B) BG3PD", { 0 } }, /* W   BG3 Rotation/Scaling Parameter D (dmy) */
  { NDS9_B_BG3X    , "(2D-B) BG3X", { 0 } }, /* W   BG3 Reference Point X-Coordinate */
  { NDS9_B_BG3Y    , "(2D-B) BG3Y", { 0 } }, /* W   BG3 Reference Point Y-Coordinate */
  { NDS9_B_WIN0H   , "(2D-B) WIN0H", {  
    { 0, 8, "X2, Rightmost coordinate of window, plus 1 " },
    { 8, 8,  "X1, Leftmost coordinate of window"}, 
  } }, /* W   Window 0 Horizontal Dimensions */
  { NDS9_B_WIN1H   , "(2D-B) WIN1H", { 
    { 0, 8, "X2, Rightmost coordinate of window, plus 1 " },
    { 8, 8, "X1, Leftmost coordinate of window"}, 
  } }, /* W   Window 1 Horizontal Dimensions */
  { NDS9_B_WIN0V   , "(2D-B) WIN0V", { 
    {0, 8,  "Y2, Bottom-most coordinate of window, plus 1" },
    {8, 8,  "Y1, Top-most coordinate of window" },
  } }, /* W   Window 0 Vertical Dimensions */
  { NDS9_B_WIN1V   , "(2D-B) WIN1V", { 
    {0, 8,  "Y2, Bottom-most coordinate of window, plus 1" },
    {8, 8,  "Y1, Top-most coordinate of window" },
  } }, /* W   Window 1 Vertical Dimensions */
  { NDS9_B_WININ   , "(2D-B) WININ", {
    { 0 , 1,  "Window 0 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 1 , 1,  "Window 0 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 2 , 1,  "Window 0 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 3 , 1,  "Window 0 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 4 , 1,  "Window 0 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 5 , 1,  "Window 0 Color Special Effect (0=Disable, 1=Enable)"},
    { 8 , 1,  "Window 1 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 9 , 1,  "Window 1 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 10, 1,  "Window 1 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 11, 1,  "Window 1 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 12, 1,  "Window 1 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 13, 1,  "Window 1 Color Special Effect (0=Disable, 1=Enable)"},
  } }, /* R/W Inside of Window 0 and 1 */
  { NDS9_B_WINOUT  , "(2D-B) WINOUT", { 
    { 0 , 1,  "Window 0 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 1 , 1,  "Window 0 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 2 , 1,  "Window 0 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 3 , 1,  "Window 0 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 4 , 1,  "Window 0 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 5 , 1,  "Window 0 Color Special Effect (0=Disable, 1=Enable)"},
    { 8 , 1,  "Window 1 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 9 , 1,  "Window 1 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 10, 1,  "Window 1 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 11, 1,  "Window 1 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 12, 1,  "Window 1 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 13, 1,  "Window 1 Color Special Effect (0=Disable, 1=Enable)"},
  } }, /* R/W Inside of OBJ Window & Outside of Windows */
  { NDS9_B_MOSAIC  , "(2D-B) MOSAIC", { 
    { 0, 4, "BG Mosaic H-Size (minus 1)" },
    { 4, 4, "BG Mosaic V-Size (minus 1)" },
    { 8, 4, "OBJ Mosaic H-Size (minus 1)" },
    { 12,4, "OBJ Mosaic V-Size (minus 1)" },
  } }, /* W   Mosaic Size */
  { NDS9_B_BLDCNT  , "(2D-B) BLDCNT", { 
    { 0 , 1, "BG0 1st Target Pixel (Background 0)" },
    { 1 , 1, "BG1 1st Target Pixel (Background 1)" },
    { 2 , 1, "BG2 1st Target Pixel (Background 2)" },
    { 3 , 1, "BG3 1st Target Pixel (Background 3)" },
    { 4 , 1, "OBJ 1st Target Pixel (Top-most OBJ pixel)" },
    { 5 , 1, "BD  1st Target Pixel (Backdrop)" },
    { 6 , 2, "Color Effect (0: None 1: Alpha 2: Lighten 3: Darken)" },
    { 8 , 1, "BG0 2nd Target Pixel (Background 0)" },
    { 9 , 1, "BG1 2nd Target Pixel (Background 1)" },
    { 10, 1, "BG2 2nd Target Pixel (Background 2)" },
    { 11, 1, "BG3 2nd Target Pixel (Background 3)" },
    { 12, 1, "OBJ 2nd Target Pixel (Top-most OBJ pixel)" },
    { 13, 1, "BD  2nd Target Pixel (Backdrop)" },
  } }, /* R/W Color Special Effects Selection */
  { NDS9_B_BLDALPHA, "(2D-B) BLDALPHA", { 
    {0, 4, "EVA Coef. (1st Target) (0..16 = 0/16..16/16, 17..31=16/16)"},
    {8, 4, "EVB Coef. (2nd Target) (0..16 = 0/16..16/16, 17..31=16/16)"},
  } }, /* R/W Alpha Blending Coefficients */
  { NDS9_B_BLDY    , "(2D-B) BLDY", { 0 } }, /* W   Brightness (Fade-In/Out) Coefficient */  

  { NDS9_B_MASTER_BRIGHT  ,"(2D-B) MASTER_BRIGHT",  {}}, /* Master Brightness Up/Down */
};

mmio_reg_t nds7_io_reg_desc[]={
    { GBA_DISPCNT , "DISPCNT ", { 
    { 0, 3, "BG Mode (0-5=Video Mode 0-5, 6-7=Prohibited)"},
    { 3 ,1, "Reserved / CGB Mode (0=GBA, 1=CGB)"},
    { 4 ,1, "Display Frame Select (0-1=Frame 0-1)"},
    { 5 ,1, "H-Blank Interval Free (1=Allow access to OAM during H-Blank)"},
    { 6 ,1, "OBJ Character VRAM Mapping (0=2D, 1=1D"},
    { 7 ,1, "Forced Blank (1=Allow FAST VRAM,Palette,OAM)"},
    { 8 ,1, "Screen Display BG0 (0=Off, 1=On)"},
    { 9 ,1, "Screen Display BG1 (0=Off, 1=On)"},
    { 10,1, "Screen Display BG2 (0=Off, 1=On)"},
    { 11,1, "Screen Display BG3 (0=Off, 1=On)"},
    { 12,1, "Screen Display OBJ (0=Off, 1=On)"},
    { 13,1, "Window 0 Display Flag (0=Off, 1=On)"},
    { 14,1, "Window 1 Display Flag (0=Off, 1=On)"},
    { 15,1, "OBJ Window Display Flag (0=Off, 1=On)"},
  } },
  { GBA_GREENSWP, "GREENSWP", { {0, 1, "Green Swap  (0=Normal, 1=Swap)" }} }, /* R/W Undocumented - Green Swap */
  { GBA_DISPSTAT, "DISPSTAT", { 
    { 0,1, "V-Blank flag (1=VBlank) (set in line 160..226; not 227",},
    { 1,1, "H-Blank flag (1=HBlank) (toggled in all lines, 0..227",},
    { 2,1, "V-Counter flag (1=Match) (set in selected line)",},
    { 3,1, "V-Blank IRQ Enable (1=Enable)",},
    { 4,1, "H-Blank IRQ Enable (1=Enable)",},
    { 5,1, "V-Counter IRQ Enable (1=Enable)",},
    { 6,1, "DSi: LCD Initialization Ready (0=Busy, 1=Ready",},
    { 7,1, "NDS: MSB of V-Vcount Setting (LYC.Bit8) (0..262",},
    { 8,8, "V-Count Setting (LYC) (0..227)",},

  } }, /* R/W General LCD Status (STAT,LYC) */
  { GBA_VCOUNT  , "VCOUNT  ", { 0 } }, /* R   Vertical Counter (LY) */
  { GBA_BG0CNT  , "BG0CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG0 Control */
  { GBA_BG1CNT  , "BG1CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG1 Control */
  { GBA_BG2CNT  , "BG2CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG2 Control */
  { GBA_BG3CNT  , "BG3CNT  ", { 
    { 0,2 , "BG Priority (0-3, 0=Highest)"},
    { 2,2 , "Character Base Block (0-3, in units of 16 KBytes) (=BG Tile Data)"},
    { 4,2 , "NDS: MSBs of char base"},
    { 6,1 , "Mosaic (0=Disable, 1=Enable)"},
    { 7,1 , "Colors/Palettes (0=16/16, 1=256/1)"},
    { 8,5 , "Screen Base Block (0-31, in units of 2 KBytes) (=BG Map Data)"},
    { 13,1, "BG0/BG1: (NDS: Ext Palette ) BG2/BG3: Overflow (0=Transp, 1=Wrap)"},
    { 14,1, "Screen Size (0-3)"},
  } }, /* R/W BG3 Control */
  { GBA_BG0HOFS , "BG0HOFS", { 0 } }, /* W   BG0 X-Offset */
  { GBA_BG0VOFS , "BG0VOFS", { 0 } }, /* W   BG0 Y-Offset */
  { GBA_BG1HOFS , "BG1HOFS", { 0 } }, /* W   BG1 X-Offset */
  { GBA_BG1VOFS , "BG1VOFS", { 0 } }, /* W   BG1 Y-Offset */
  { GBA_BG2HOFS , "BG2HOFS", { 0 } }, /* W   BG2 X-Offset */
  { GBA_BG2VOFS , "BG2VOFS", { 0 } }, /* W   BG2 Y-Offset */
  { GBA_BG3HOFS , "BG3HOFS", { 0 } }, /* W   BG3 X-Offset */
  { GBA_BG3VOFS , "BG3VOFS", { 0 } }, /* W   BG3 Y-Offset */
  { GBA_BG2PA   , "BG2PA", { 0 } }, /* W   BG2 Rotation/Scaling Parameter A (dx) */
  { GBA_BG2PB   , "BG2PB", { 0 } }, /* W   BG2 Rotation/Scaling Parameter B (dmx) */
  { GBA_BG2PC   , "BG2PC", { 0 } }, /* W   BG2 Rotation/Scaling Parameter C (dy) */
  { GBA_BG2PD   , "BG2PD", { 0 } }, /* W   BG2 Rotation/Scaling Parameter D (dmy) */
  { GBA_BG2X    , "BG2X", { 0 } }, /* W   BG2 Reference Point X-Coordinate */
  { GBA_BG2Y    , "BG2Y", { 0 } }, /* W   BG2 Reference Point Y-Coordinate */
  { GBA_BG3PA   , "BG3PA", { 0 } }, /* W   BG3 Rotation/Scaling Parameter A (dx) */
  { GBA_BG3PB   , "BG3PB", { 0 } }, /* W   BG3 Rotation/Scaling Parameter B (dmx) */
  { GBA_BG3PC   , "BG3PC", { 0 } }, /* W   BG3 Rotation/Scaling Parameter C (dy) */
  { GBA_BG3PD   , "BG3PD", { 0 } }, /* W   BG3 Rotation/Scaling Parameter D (dmy) */
  { GBA_BG3X    , "BG3X", { 0 } }, /* W   BG3 Reference Point X-Coordinate */
  { GBA_BG3Y    , "BG3Y", { 0 } }, /* W   BG3 Reference Point Y-Coordinate */
  { GBA_WIN0H   , "WIN0H", {  
    { 0, 8, "X2, Rightmost coordinate of window, plus 1 " },
    { 8, 8,  "X1, Leftmost coordinate of window"}, 
  } }, /* W   Window 0 Horizontal Dimensions */
  { GBA_WIN1H   , "WIN1H", { 
    { 0, 8, "X2, Rightmost coordinate of window, plus 1 " },
    { 8, 8, "X1, Leftmost coordinate of window"}, 
  } }, /* W   Window 1 Horizontal Dimensions */
  { GBA_WIN0V   , "WIN0V", { 
    {0, 8,  "Y2, Bottom-most coordinate of window, plus 1" },
    {8, 8,  "Y1, Top-most coordinate of window" },
  } }, /* W   Window 0 Vertical Dimensions */
  { GBA_WIN1V   , "WIN1V", { 
    {0, 8,  "Y2, Bottom-most coordinate of window, plus 1" },
    {8, 8,  "Y1, Top-most coordinate of window" },
  } }, /* W   Window 1 Vertical Dimensions */
  { GBA_WININ   , "WININ", {
    { 0 , 1,  "Window 0 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 1 , 1,  "Window 0 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 2 , 1,  "Window 0 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 3 , 1,  "Window 0 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 4 , 1,  "Window 0 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 5 , 1,  "Window 0 Color Special Effect (0=Disable, 1=Enable)"},
    { 8 , 1,  "Window 1 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 9 , 1,  "Window 1 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 10, 1,  "Window 1 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 11, 1,  "Window 1 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 12, 1,  "Window 1 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 13, 1,  "Window 1 Color Special Effect (0=Disable, 1=Enable)"},
  } }, /* R/W Inside of Window 0 and 1 */
  { GBA_WINOUT  , "WINOUT", { 
    { 0 , 1,  "Window 0 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 1 , 1,  "Window 0 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 2 , 1,  "Window 0 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 3 , 1,  "Window 0 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 4 , 1,  "Window 0 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 5 , 1,  "Window 0 Color Special Effect (0=Disable, 1=Enable)"},
    { 8 , 1,  "Window 1 BG0 Enable Bits (0=No Display, 1=Display)"},
    { 9 , 1,  "Window 1 BG1 Enable Bits (0=No Display, 1=Display)"},
    { 10, 1,  "Window 1 BG2 Enable Bits (0=No Display, 1=Display)"},
    { 11, 1,  "Window 1 BG3 Enable Bits (0=No Display, 1=Display)"},
    { 12, 1,  "Window 1 OBJ Enable Bit (0=No Display, 1=Display)"},
    { 13, 1,  "Window 1 Color Special Effect (0=Disable, 1=Enable)"},
  } }, /* R/W Inside of OBJ Window & Outside of Windows */
  { GBA_MOSAIC  , "MOSAIC", { 
    { 0, 4, "BG Mosaic H-Size (minus 1)" },
    { 4, 4, "BG Mosaic V-Size (minus 1)" },
    { 8, 4, "OBJ Mosaic H-Size (minus 1)" },
    { 12,4, "OBJ Mosaic V-Size (minus 1)" },
  } }, /* W   Mosaic Size */
  { GBA_BLDCNT  , "BLDCNT", { 
    { 0 , 1, "BG0 1st Target Pixel (Background 0)" },
    { 1 , 1, "BG1 1st Target Pixel (Background 1)" },
    { 2 , 1, "BG2 1st Target Pixel (Background 2)" },
    { 3 , 1, "BG3 1st Target Pixel (Background 3)" },
    { 4 , 1, "OBJ 1st Target Pixel (Top-most OBJ pixel)" },
    { 5 , 1, "BD  1st Target Pixel (Backdrop)" },
    { 6 , 2, "Color Effect (0: None 1: Alpha 2: Lighten 3: Darken)" },
    { 8 , 1, "BG0 2nd Target Pixel (Background 0)" },
    { 9 , 1, "BG1 2nd Target Pixel (Background 1)" },
    { 10, 1, "BG2 2nd Target Pixel (Background 2)" },
    { 11, 1, "BG3 2nd Target Pixel (Background 3)" },
    { 12, 1, "OBJ 2nd Target Pixel (Top-most OBJ pixel)" },
    { 13, 1, "BD  2nd Target Pixel (Backdrop)" },
  } }, /* R/W Color Special Effects Selection */
  { GBA_BLDALPHA, "BLDALPHA", { 
    {0, 4, "EVA Coef. (1st Target) (0..16 = 0/16..16/16, 17..31=16/16)"},
    {8, 4, "EVB Coef. (2nd Target) (0..16 = 0/16..16/16, 17..31=16/16)"},
  } }, /* R/W Alpha Blending Coefficients */
  { GBA_BLDY    , "BLDY", { 0 } }, /* W   Brightness (Fade-In/Out) Coefficient */  
  { NDS_DISP3DCNT,       "DISP3DCNT",       {}}, /* 3D Display Control Register (R/W) */
  { NDS_DISPCAPCNT,      "DISPCAPCNT",      {}}, /* Display Capture Control Register (R/W) */
  { NDS_DISP_MMEM_FIFO,  "DISP_MMEM_FIFO",  {}}, /* Main Memory Display FIFO (R?/W) */
  { NDS_A_MASTER_BRIGHT, "A_MASTER_BRIGHT", {}}, /* Master Brightness Up/Down */

  // DMA Transfer Channels
  { GBA_DMA0SAD  , "DMA0SAD", { 0 } },   /* W    DMA 0 Source Address */
  { GBA_DMA0DAD  , "DMA0DAD", { 0 } },   /* W    DMA 0 Destination Address */
  { GBA_DMA0CNT_L, "DMA0CNT_L", { 0 } },   /* W    DMA 0 Word Count */
  { GBA_DMA0CNT_H, "DMA0CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Prohibited)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 0 Control */
  { GBA_DMA1SAD  , "DMA1SAD", { 0 } },   /* W    DMA 1 Source Address */
  { GBA_DMA1DAD  , "DMA1DAD", { 0 } },   /* W    DMA 1 Destination Address */
  { GBA_DMA1CNT_L, "DMA1CNT_L", { 0 } },   /* W    DMA 1 Word Count */
  { GBA_DMA1CNT_H, "DMA1CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Sound)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 1 Control */
  { GBA_DMA2SAD  , "DMA2SAD", { 0 } },   /* W    DMA 2 Source Address */
  { GBA_DMA2DAD  , "DMA2DAD", { 0 } },   /* W    DMA 2 Destination Address */
  { GBA_DMA2CNT_L, "DMA2CNT_L", { 0 } },   /* W    DMA 2 Word Count */
  { GBA_DMA2CNT_H, "DMA2CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Sound)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 2 Control */
  { GBA_DMA3SAD  , "DMA3SAD", { 0 } },   /* W    DMA 3 Source Address */
  { GBA_DMA3DAD  , "DMA3DAD", { 0 } },   /* W    DMA 3 Destination Address */
  { GBA_DMA3CNT_L, "DMA3CNT_L", { 0 } },   /* W    DMA 3 Word Count */
  { GBA_DMA3CNT_H, "DMA3CNT_H", {
    { 5,  2,  "Dest Addr Control (0=Incr,1=Decr,2=Fixed,3=Incr/Reload)" },
    { 7,  2,  "Source Adr Control (0=Incr,1=Decr,2=Fixed,3=Prohibited)" },
    { 9,  1,  "DMA Repeat (0=Off, 1=On) (Must be zero if Bit 11 set)" },
    { 10, 1,  "DMA Transfer Type (0=16bit, 1=32bit)" },
    { 11, 1,  "Game Pak DRQ (0=Normal, 1=DRQ <from> Game Pak, DMA3)" },
    { 12, 2,  "DMA Start Timing (0=Immediately, 1=VBlank, 2=HBlank, 3=Video Capture)" },
    { 14, 1,  "IRQ upon end of Word Count (0=Disable, 1=Enable)" },
    { 15, 1,  "DMA Enable (0=Off, 1=On)" },
  } },   /* R/W  DMA 3 Control */  

  // Timer Registers
  { GBA_TM0CNT_L, "TM0CNT_L", {0} },   /* R/W   Timer 0 Counter/Reload */
  { GBA_TM0CNT_H, "TM0CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 0 Control */
  { GBA_TM1CNT_L, "TM1CNT_L", {0} },   /* R/W   Timer 1 Counter/Reload */
  { GBA_TM1CNT_H, "TM1CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 1 Control */
  { GBA_TM2CNT_L, "TM2CNT_L", {0} },   /* R/W   Timer 2 Counter/Reload */
  { GBA_TM2CNT_H, "TM2CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 2 Control */
  { GBA_TM3CNT_L, "TM3CNT_L", {0} },   /* R/W   Timer 3 Counter/Reload */
  { GBA_TM3CNT_H, "TM3CNT_H", {
    { 0 ,2, "Prescaler Selection (0=F/1, 1=F/64, 2=F/256, 3=F/1024)" },
    { 2 ,1, "Count-up (0=Normal, 1=Incr. on prev. Timer overflow)" },
    { 6 ,1, "Timer IRQ Enable (0=Disable, 1=IRQ on Timer overflow)" },
    { 7 ,1, "Timer Start/Stop (0=Stop, 1=Operate)" },
  } },   /* R/W   Timer 3 Control */  

  // Serial Communication (1)
  { GBA_SIODATA32  , "SIODATA32", {0} }, /*R/W   SIO Data (Normal-32bit Mode; shared with below) */
  { GBA_SIOMULTI0  , "SIOMULTI0", {0} }, /*R/W   SIO Data 0 (Parent)    (Multi-Player Mode) */
  { GBA_SIOMULTI1  , "SIOMULTI1", {0} }, /*R/W   SIO Data 1 (1st Child) (Multi-Player Mode) */
  { GBA_SIOMULTI2  , "SIOMULTI2", {0} }, /*R/W   SIO Data 2 (2nd Child) (Multi-Player Mode) */
  { GBA_SIOMULTI3  , "SIOMULTI3", {0} }, /*R/W   SIO Data 3 (3rd Child) (Multi-Player Mode) */
  { GBA_SIOCNT     , "SIOCNT", {0} }, /*R/W   SIO Control Register */
  { GBA_SIOMLT_SEND, "SIOMLT_SEND", {0} }, /*R/W   SIO Data (Local of MultiPlayer; shared below) */
  { GBA_SIODATA8   , "SIODATA8", {0} }, /*R/W   SIO Data (Normal-8bit and UART Mode) */  

  // Keypad Input
  { GBA_KEYINPUT, "GBA_KEYINPUT", {
    { 0, 1, "Button A" },
    { 1, 1, "Button B" },
    { 2, 1, "Select" },
    { 3, 1, "Start" },
    { 4, 1, "Right" },
    { 5, 1, "Left" },
    { 6, 1, "Up" },
    { 7, 1, "Down" },
    { 8, 1, "Button R" },
    { 9, 1, "Button L" },
  } },    /* R      Key Status */
  { GBA_KEYCNT  , "GBA_KEYCNT", {
    { 0, 1, "Button A" },
    { 1, 1, "Button B" },
    { 2, 1, "Select" },
    { 3, 1, "Start" },
    { 4, 1, "Right" },
    { 5, 1, "Left" },
    { 6, 1, "Up" },
    { 7, 1, "Down" },
    { 8, 1, "Button R" },
    { 9, 1, "Button L" },
    { 14,1, "Button IRQ Enable (0=Disable, 1=Enable)" },
    { 15,1, "Button IRQ Condition (0=OR, 1=AND)"},
  } },    /* R/W    Key Interrupt Control */  

  // Serial Communication (2)
  { GBA_RCNT     , "RCNT", {0} },     /* R/W  SIO Mode Select/General Purpose Data */
  { GBA_IR       , "IR", {0} },     /* -    Ancient - Infrared Register (Prototypes only) */
  { GBA_JOYCNT   , "JOYCNT", {0} },     /* R/W  SIO JOY Bus Control */
  { GBA_JOY_RECV , "JOY_RECV", {0} },     /* R/W  SIO JOY Bus Receive Data */
  { GBA_JOY_TRANS, "JOY_TRANS", {0} },     /* R/W  SIO JOY Bus Transmit Data */
  { GBA_JOYSTAT  , "JOYSTAT", {0} },     /* R/?  SIO JOY Bus Receive Status */  

  { NDS7_DEBUG_RCNT,      "DEBUG_RCNT",     {}}, /* Debug RCNT */
  { NDS7_EXTKEYIN,        "EXTKEYIN",       {}}, /* EXTKEYIN */
  { NDS7_RTC_BUS,         "RTC_BUS",        {}}, /* RTC Realtime Clock Bus */
  { NDS7_IPCSYNC,         "IPCSYNC",        {}}, /* IPC Synchronize Register (R/W) */
  { NDS7_IPCFIFOCNT,      "IPCFIFOCNT",     {}}, /* IPC Fifo Control Register (R/W) */
  { NDS7_IPCFIFOSEND,     "IPCFIFOSEND",    {}}, /* IPC Send Fifo (W) */
  { NDS7_AUXSPICNT,       "AUXSPICNT",      {}}, /* Gamecard ROM and SPI Control */
  { NDS7_AUXSPIDATA,      "AUXSPIDATA",     {}}, /* Gamecard SPI Bus Data/Strobe */
  { NDS7_GCBUS_CTL,       "GCBUS_CTL",      {}}, /* Gamecard bus timing/control */
  { NDS7_GCBUS_CMD,       "GCBUS_CMD",      {}}, /* Gamecard bus 8-byte command out */
  { NDS7_GCBUS_SEED0_LO,  "GCBUS_SEED0_LO", {}}, /* Gamecard Encryption Seed 0 Lower 32bit */
  { NDS7_GCBUS_SEED1_LO,  "GCBUS_SEED1_LO", {}}, /* Gamecard Encryption Seed 1 Lower 32bit */
  { NDS7_GCBUS_SEED0_HI,  "GCBUS_SEED0_HI", {}}, /* Gamecard Encryption Seed 0 Upper 7bit (bit7-15 unused) */
  { NDS7_GCBUS_SEED1_HI,  "GCBUS_SEED1_HI", {}}, /* Gamecard Encryption Seed 1 Upper 7bit (bit7-15 unused) */
  { NDS7_SPI_BUS_CTL,     "SPI_BUS_CTL",    {}}, /* SPI bus Control (Firmware, Touchscreen, Powerman) */
  { NDS7_SPI_BUS_DATA,    "SPI_BUS_DATA",   {}}, /* SPI bus Data */
  // ARM7 Memory and IRQ Control
  { NDS7_EXMEMSTAT,   "EXMEMSTAT",   {}}, /* EXMEMSTAT - External Memory Status */
  { NDS7_WIFIWAITCNT, "WIFIWAITCNT", {}}, /* WIFIWAITCNT */
  { NDS7_IME,         "IME",         {}}, /* IME - Interrupt Master Enable (R/W) */
  { NDS7_IE,          "IE",          {}}, /* IE  - Interrupt Enable (R/W) */
  { NDS7_IF,          "IF",          {}}, /* IF  - Interrupt Request Flags (R/W) */
  { NDS7_VRAMSTAT,    "VRAMSTAT",    {}}, /* VRAMSTAT - VRAM-C,D Bank Status (R) */
  { NDS7_WRAMSTAT,    "WRAMSTAT",    {}}, /* WRAMSTAT - WRAM Bank Status (R) */
  { NDS7_POSTFLG,     "POSTFLG",     {}}, /* POSTFLG */
  { NDS7_HALTCNT,     "HALTCNT",     {}}, /* HALTCNT (different bits than on GBA) (plus NOP delay) */
  { NDS7_POWCNT2,     "POWCNT2",     {}}, /* POWCNT2  Sound/Wifi Power Control Register (R/W) */
  { NDS7_BIOSPROT,    "BIOSPROT",    {}}, /* BIOSPROT - Bios-data-read-protection address */

  // ARM7 Sound Registers (Sound Channel 0..15 (10h bytes each)) 
  { NDS7_SOUND0_CNT, "SOUND0_CNT", {}}, /* Sound Channel 0 Control Register (R/W) */
  { NDS7_SOUND0_SAD, "SOUND0_SAD", {}}, /* Sound Channel 0 Data Source Register (W) */
  { NDS7_SOUND0_TMR, "SOUND0_TMR", {}}, /* Sound Channel 0 Timer Register (W) */
  { NDS7_SOUND0_PNT, "SOUND0_PNT", {}}, /* Sound Channel 0 Loopstart Register (W) */
  { NDS7_SOUND0_LEN, "SOUND0_LEN", {}}, /* Sound Channel 0 Length Register (W) */
  { NDS7_SOUND1_CNT, "SOUND1_CNT", {}}, /* Sound Channel 1 Control Register (R/W) */
  { NDS7_SOUND1_SAD, "SOUND1_SAD", {}}, /* Sound Channel 1 Data Source Register (W) */
  { NDS7_SOUND1_TMR, "SOUND1_TMR", {}}, /* Sound Channel 1 Timer Register (W) */
  { NDS7_SOUND1_PNT, "SOUND1_PNT", {}}, /* Sound Channel 1 Loopstart Register (W) */
  { NDS7_SOUND1_LEN, "SOUND1_LEN", {}}, /* Sound Channel 1 Length Register (W) */
  { NDS7_SOUND2_CNT, "SOUND2_CNT", {}}, /* Sound Channel 2 Control Register (R/W) */
  { NDS7_SOUND2_SAD, "SOUND2_SAD", {}}, /* Sound Channel 2 Data Source Register (W) */
  { NDS7_SOUND2_TMR, "SOUND2_TMR", {}}, /* Sound Channel 2 Timer Register (W) */
  { NDS7_SOUND2_PNT, "SOUND2_PNT", {}}, /* Sound Channel 2 Loopstart Register (W) */
  { NDS7_SOUND2_LEN, "SOUND2_LEN", {}}, /* Sound Channel 2 Length Register (W) */
  { NDS7_SOUND3_CNT, "SOUND3_CNT", {}}, /* Sound Channel 3 Control Register (R/W) */
  { NDS7_SOUND3_SAD, "SOUND3_SAD", {}}, /* Sound Channel 3 Data Source Register (W) */
  { NDS7_SOUND3_TMR, "SOUND3_TMR", {}}, /* Sound Channel 3 Timer Register (W) */
  { NDS7_SOUND3_PNT, "SOUND3_PNT", {}}, /* Sound Channel 3 Loopstart Register (W) */
  { NDS7_SOUND3_LEN, "SOUND3_LEN", {}}, /* Sound Channel 3 Length Register (W) */
  { NDS7_SOUND4_CNT, "SOUND4_CNT", {}}, /* Sound Channel 4 Control Register (R/W) */
  { NDS7_SOUND4_SAD, "SOUND4_SAD", {}}, /* Sound Channel 4 Data Source Register (W) */
  { NDS7_SOUND4_TMR, "SOUND4_TMR", {}}, /* Sound Channel 4 Timer Register (W) */
  { NDS7_SOUND4_PNT, "SOUND4_PNT", {}}, /* Sound Channel 4 Loopstart Register (W) */
  { NDS7_SOUND4_LEN, "SOUND4_LEN", {}}, /* Sound Channel 4 Length Register (W) */
  { NDS7_SOUND5_CNT, "SOUND5_CNT", {}}, /* Sound Channel 5 Control Register (R/W) */
  { NDS7_SOUND5_SAD, "SOUND5_SAD", {}}, /* Sound Channel 5 Data Source Register (W) */
  { NDS7_SOUND5_TMR, "SOUND5_TMR", {}}, /* Sound Channel 5 Timer Register (W) */
  { NDS7_SOUND5_PNT, "SOUND5_PNT", {}}, /* Sound Channel 5 Loopstart Register (W) */
  { NDS7_SOUND5_LEN, "SOUND5_LEN", {}}, /* Sound Channel 5 Length Register (W) */
  { NDS7_SOUND6_CNT, "SOUND6_CNT", {}}, /* Sound Channel 6 Control Register (R/W) */
  { NDS7_SOUND6_SAD, "SOUND6_SAD", {}}, /* Sound Channel 6 Data Source Register (W) */
  { NDS7_SOUND6_TMR, "SOUND6_TMR", {}}, /* Sound Channel 6 Timer Register (W) */
  { NDS7_SOUND6_PNT, "SOUND6_PNT", {}}, /* Sound Channel 6 Loopstart Register (W) */
  { NDS7_SOUND6_LEN, "SOUND6_LEN", {}}, /* Sound Channel 6 Length Register (W) */
  { NDS7_SOUND7_CNT, "SOUND7_CNT", {}}, /* Sound Channel 7 Control Register (R/W) */
  { NDS7_SOUND7_SAD, "SOUND7_SAD", {}}, /* Sound Channel 7 Data Source Register (W) */
  { NDS7_SOUND7_TMR, "SOUND7_TMR", {}}, /* Sound Channel 7 Timer Register (W) */
  { NDS7_SOUND7_PNT, "SOUND7_PNT", {}}, /* Sound Channel 7 Loopstart Register (W) */
  { NDS7_SOUND7_LEN, "SOUND7_LEN", {}}, /* Sound Channel 7 Length Register (W) */
  { NDS7_SOUND8_CNT, "SOUND8_CNT", {}}, /* Sound Channel 8 Control Register (R/W) */
  { NDS7_SOUND8_SAD, "SOUND8_SAD", {}}, /* Sound Channel 8 Data Source Register (W) */
  { NDS7_SOUND8_TMR, "SOUND8_TMR", {}}, /* Sound Channel 8 Timer Register (W) */
  { NDS7_SOUND8_PNT, "SOUND8_PNT", {}}, /* Sound Channel 8 Loopstart Register (W) */
  { NDS7_SOUND8_LEN, "SOUND8_LEN", {}}, /* Sound Channel 8 Length Register (W) */
  { NDS7_SOUND9_CNT, "SOUND9_CNT", {}}, /* Sound Channel 9 Control Register (R/W) */
  { NDS7_SOUND9_SAD, "SOUND9_SAD", {}}, /* Sound Channel 9 Data Source Register (W) */
  { NDS7_SOUND9_TMR, "SOUND9_TMR", {}}, /* Sound Channel 9 Timer Register (W) */
  { NDS7_SOUND9_PNT, "SOUND9_PNT", {}}, /* Sound Channel 9 Loopstart Register (W) */
  { NDS7_SOUND9_LEN, "SOUND9_LEN", {}}, /* Sound Channel 9 Length Register (W) */
  { NDS7_SOUNDA_CNT, "SOUNDA_CNT", {}}, /* Sound Channel 10 Control Register (R/W) */
  { NDS7_SOUNDA_SAD, "SOUNDA_SAD", {}}, /* Sound Channel 10 Data Source Register (W) */
  { NDS7_SOUNDA_TMR, "SOUNDA_TMR", {}}, /* Sound Channel 10 Timer Register (W) */
  { NDS7_SOUNDA_PNT, "SOUNDA_PNT", {}}, /* Sound Channel 10 Loopstart Register (W) */
  { NDS7_SOUNDA_LEN, "SOUNDA_LEN", {}}, /* Sound Channel 10 Length Register (W) */
  { NDS7_SOUNDB_CNT, "SOUNDB_CNT", {}}, /* Sound Channel 11 Control Register (R/W) */
  { NDS7_SOUNDB_SAD, "SOUNDB_SAD", {}}, /* Sound Channel 11 Data Source Register (W) */
  { NDS7_SOUNDB_TMR, "SOUNDB_TMR", {}}, /* Sound Channel 11 Timer Register (W) */
  { NDS7_SOUNDB_PNT, "SOUNDB_PNT", {}}, /* Sound Channel 11 Loopstart Register (W) */
  { NDS7_SOUNDB_LEN, "SOUNDB_LEN", {}}, /* Sound Channel 11 Length Register (W) */
  { NDS7_SOUNDC_CNT, "SOUNDC_CNT", {}}, /* Sound Channel 12 Control Register (R/W) */
  { NDS7_SOUNDC_SAD, "SOUNDC_SAD", {}}, /* Sound Channel 12 Data Source Register (W) */
  { NDS7_SOUNDC_TMR, "SOUNDC_TMR", {}}, /* Sound Channel 12 Timer Register (W) */
  { NDS7_SOUNDC_PNT, "SOUNDC_PNT", {}}, /* Sound Channel 12 Loopstart Register (W) */
  { NDS7_SOUNDC_LEN, "SOUNDC_LEN", {}}, /* Sound Channel 12 Length Register (W) */
  { NDS7_SOUNDD_CNT, "SOUNDD_CNT", {}}, /* Sound Channel 13 Control Register (R/W) */
  { NDS7_SOUNDD_SAD, "SOUNDD_SAD", {}}, /* Sound Channel 13 Data Source Register (W) */
  { NDS7_SOUNDD_TMR, "SOUNDD_TMR", {}}, /* Sound Channel 13 Timer Register (W) */
  { NDS7_SOUNDD_PNT, "SOUNDD_PNT", {}}, /* Sound Channel 13 Loopstart Register (W) */
  { NDS7_SOUNDD_LEN, "SOUNDD_LEN", {}}, /* Sound Channel 13 Length Register (W) */
  { NDS7_SOUNDE_CNT, "SOUNDE_CNT", {}}, /* Sound Channel 14 Control Register (R/W) */
  { NDS7_SOUNDE_SAD, "SOUNDE_SAD", {}}, /* Sound Channel 14 Data Source Register (W) */
  { NDS7_SOUNDE_TMR, "SOUNDE_TMR", {}}, /* Sound Channel 14 Timer Register (W) */
  { NDS7_SOUNDE_PNT, "SOUNDE_PNT", {}}, /* Sound Channel 14 Loopstart Register (W) */
  { NDS7_SOUNDE_LEN, "SOUNDE_LEN", {}}, /* Sound Channel 14 Length Register (W) */
  { NDS7_SOUNDF_CNT, "SOUNDF_CNT", {}}, /* Sound Channel 15 Control Register (R/W) */
  { NDS7_SOUNDF_SAD, "SOUNDF_SAD", {}}, /* Sound Channel 15 Data Source Register (W) */
  { NDS7_SOUNDF_TMR, "SOUNDF_TMR", {}}, /* Sound Channel 15 Timer Register (W) */
  { NDS7_SOUNDF_PNT, "SOUNDF_PNT", {}}, /* Sound Channel 15 Loopstart Register (W) */
  { NDS7_SOUNDF_LEN, "SOUNDF_LEN", {}}, /* Sound Channel 15 Length Register (W) */

  { NDS7_SOUNDCNT,   "SOUNDCNT",   {}}, /* Sound Control Register (R/W) */
  { NDS7_SOUNDBIAS,  "SOUNDBIAS",  {}}, /* Sound Bias Register (R/W) */
  { NDS7_SNDCAP0CNT, "SNDCAP0CNT", {}}, /* Sound Capture 0 Control Register (R/W) */
  { NDS7_SNDCAP1CNT, "SNDCAP1CNT", {}}, /* Sound Capture 1 Control Register (R/W) */
  { NDS7_SNDCAP0DAD, "SNDCAP0DAD", {}}, /* Sound Capture 0 Destination Address (R/W) */
  { NDS7_SNDCAP0LEN, "SNDCAP0LEN", {}}, /* Sound Capture 0 Length (W) */
  { NDS7_SNDCAP1DAD, "SNDCAP1DAD", {}}, /* Sound Capture 1 Destination Address (R/W) */
  { NDS7_SNDCAP1LEN, "SNDCAP1LEN", {}}, /* Sound Capture 1 Length (W) */

};

// Interrupt sources
#define GBA_INT_LCD_VBLANK 0   
#define GBA_INT_LCD_HBLANK 1     
#define GBA_INT_LCD_VCOUNT 2     
#define GBA_INT_TIMER0     3     
#define GBA_INT_TIMER1     4     
#define GBA_INT_TIMER2     5     
#define GBA_INT_TIMER3     6     
#define GBA_INT_SERIAL     7     
#define GBA_INT_DMA0       8     
#define GBA_INT_DMA1       9     
#define GBA_INT_DMA2       10    
#define GBA_INT_DMA3       11    
#define GBA_INT_KEYPAD     12    
#define GBA_INT_GAMEPAK    13   

#define NDS_INT_IPC_SYNC         16  /* IPC Sync */
#define NDS_INT_IPC_FIFO_SEND    17  /* IPC Send FIFO Empty */
#define NDS_INT_IPC_FIFO_RECV    18  /* IPC Recv FIFO Not Empty */
#define NDS_INT_GC_TRANSFER_DONE 19  /* NDS-Slot Game Card Data Transfer Completion */
#define NDS_INT_GC_IREQ_MC       20  /* NDS-Slot Game Card IREQ_MC */
#define NDS9_INT_GX_FIFO         21  /* NDS9 only: Geometry Command FIFO */
#define NDS7_INT_SCREEN_FOLD     22  /* NDS7 only: Screens unfolding */
#define NDS7_INT_SPI             23  /* NDS7 only: SPI bus */
#define NDS7_WIFI                24  /* NDS7 only: Wifi    / DSi9: XpertTeak DSP */
#define NDSi9_DSP                24  /* NDS7 only: Wifi    / DSi9: XpertTeak DSP */

#define NDSi9_CAMERA             25  /* Not used           / DSi9: Camera */
#define NDSi9_UNDOC              26  /* Not used           / DSi9: Undoc, IF.26 set on FFh-filling 40021Axh */
#define NDSi_IREQ_MC             27  /* Not used           / DSi:  Maybe IREQ_MC for 2nd gamecard? */
#define NDSi_DMA0                28  /* Not used           / DSi: NewDMA0 */
#define NDSi_DMA1                29  /* Not used           / DSi: NewDMA1 */
#define NDSi_DMA2                30  /* Not used           / DSi: NewDMA2 */
#define NDSi_DMA3                31  /* Not used           / DSi: NewDMA3 */

#define GBA_BG_PALETTE  0x00000000                    
#define GBA_OBJ_PALETTE 0x00000200                    
#define GBA_OBJ_TILES0_2   0x00010000
#define GBA_OBJ_TILES3_5   0x00014000
#define GBA_OAM         0x07000000

#define GBA_BACKUP_NONE        0
#define GBA_BACKUP_EEPROM      1
#define GBA_BACKUP_EEPROM_512B 2
#define GBA_BACKUP_EEPROM_8KB  3
#define GBA_BACKUP_SRAM        4
#define GBA_BACKUP_FLASH_64K   5 
#define GBA_BACKUP_FLASH_128K  6  

#define GBA_REQ_1B    0x01
#define GBA_REQ_2B    0x02
#define GBA_REQ_4B    0x04
#define GBA_REQ_READ  0x40
#define GBA_REQ_WRITE 0x80

#define NDS_LCD_W 256
#define NDS_LCD_H 192


typedef struct {     
  uint8_t ram[4*1024*1024]; /*4096KB Main RAM (8192KB in debug version)*/
  uint8_t wram[96*1024];    /*96KB   WRAM (64K mapped to NDS7, plus 32K mappable to NDS7 or NDS9)*/
  /* TCM/Cache (TCM: 16K Data, 32K Code) (Cache: 4K Data, 8K Code) */
  uint8_t code_tcm[32*1024];
  uint8_t data_tcm[16*1024];
  uint8_t code_cache[8*1024];
  uint8_t data_cache[4*1024];
  uint8_t vram[656*1024];    /* VRAM (allocateable as BG/OBJ/2D/3D/Palette/Texture/WRAM memory) */
  uint8_t palette[2*1024];   

  uint8_t oam[4*1024];       /* OAM/PAL (2K OBJ Attribute Memory, 2K Standard Palette RAM) */
  /* BIOS ROM (4K NDS9, 16K NDS7, 16K GBA) */
  uint8_t nds7_bios[16*1024];
  uint8_t nds9_bios[4*1024];
  /* Firmware FLASH (512KB in iQue variant, with chinese charset) */
  uint8_t firmware[256*1024];
  uint8_t io[1024];

  uint8_t *card_data;
  size_t card_size;

  uint8_t wait_state_table[16*4];
  bool prefetch_en;
  int prefetch_size;
  uint32_t requests;
  uint32_t openbus_word;
  uint32_t arm7_bios_word;
} nds_mem_t;

typedef struct {
  //Bytes 0..31
  uint8_t title[12];   /* Game Title  (Uppercase ASCII, padded with 00h) */
  uint8_t gamecode[4];  /* Gamecode    (Uppercase ASCII, NTR-<code>)        (0=homebrew) */
  uint8_t makercode[2]; /* Makercode   (Uppercase ASCII, eg. "01"=Nintendo) (0=homebrew) */
  uint8_t unitcode;     /* Unitcode    (00h=NDS, 02h=NDS+DSi, 03h=DSi) (bit1=DSi) */
  uint8_t seed_sel;        /* Encryption Seed Select (00..07h, usually 00h) */
  uint8_t device_capacity; /* Devicecapacity         (Chipsize = 128KB SHL nn) (eg. 7 = 16MB) */
  uint8_t reserved[8];
  uint8_t region;          /* NDS Region  (00h=Normal, 80h=China, 40h=Korea) (other on DSi) */
  uint8_t rom_version;     /* ROM Version (usually 00h) */
  uint8_t autostart;       /* Autostart (Bit2: Skip "Press Button" after Health and Safety) */
  //Byte 32..63
  uint32_t arm9_rom_offset; /* ARM9 rom_offset    (4000h and up, align 1000h) */
  uint32_t arm9_entrypoint; /* ARM9 entry_address (2000000h..23BFE00h) */
  uint32_t arm9_ram_address;/* ARM9 ram_address   (2000000h..23BFE00h) */
  uint32_t arm9_size;       /* ARM9 size          (max 3BFE00h) (3839.5KB) */

  uint32_t arm7_rom_offset;  /* ARM7 rom_offset    (8000h and up) */
  uint32_t arm7_entrypoint;  /* ARM7 entry_address (2000000h..23BFE00h, or 37F8000h..3807E00h) */
  uint32_t arm7_ram_address; /* ARM7 ram_address   (2000000h..23BFE00h, or 37F8000h..3807E00h) */
  uint32_t arm7_size;        /* ARM7 size          (max 3BFE00h, or FE00h) (3839.5KB, 63.5KB) */
  
  //Byte 64..95
  uint32_t fnt_offset; /* File Name Table (FNT) offset */
  uint32_t fnt_size;   /* File Name Table (FNT) size */
  uint32_t fat_offset; /* File Allocation Table (FAT) offset */
  uint32_t fat_size;   /* File Allocation Table (FAT) size */
  uint32_t arm9_overlay_offset; /* File ARM9 overlay_offset */
  uint32_t arm9_overlay_size;   /* File ARM9 overlay_size */
  uint32_t arm7_overlay_offset; /* File ARM7 overlay_offset */
  uint32_t arm7_overlay_size;   /* File ARM7 overlay_size */
  //Byte 96..127
  uint32_t port0; /* Port 40001A4h setting for normal commands (usually 00586000h) */
  uint32_t port1; /* Port 40001A4h setting for KEY1 commands   (usually 001808F8h) */
  uint32_t icon_title_offset; /* Icon/Title offset (0=None) (8000h and up) */
  uint16_t sec_checksum;  /* Secure Area Checksum, CRC-16 of [[020h]..00007FFFh] */
  uint16_t sec_delay; /* Secure Area Delay (in 131kHz units) (051Eh=10ms or 0D7Eh=26ms) */
  uint32_t arm9_autoload; /* ARM9 Auto Load List Hook RAM Address (?) ;\endaddr of auto-load */
  uint32_t arm7_autoload; /* ARM7 Auto Load List Hook RAM Address (?) ;/functions */
  uint8_t sec_disable[8]; /* Secure Area Disable (by encrypted "NmMdOnly") (usually zero) */
  //Byte 128..159
  uint32_t rom_size_used; /* Total Used ROM size (remaining/unused bytes usually FFh-padded) */
  uint32_t rom_header_size;  /* ROM Header Size (4000h) */
  uint8_t reserved2[24];
} nds_card_t;
typedef struct{
  bool up,down,left,right;
  bool a, b, start, select;
  bool l,r;
  bool x,y;
  float touch_x;
  float touch_y;
} nds_input_t;
typedef struct{
  int source_addr;
  int dest_addr;
  int length;
  int current_transaction;
  bool last_enable;
  bool last_vblank;
  bool last_hblank;
  uint32_t latched_transfer;
  int startup_delay; 
  bool activate_audio_dma;
} nds_dma_t; 
typedef struct{
  int scan_clock; 
  bool last_vblank;
  bool last_hblank;
  int last_lcd_y; 
  struct {
    int32_t internal_bgx;
    int32_t internal_bgy;
  }aff[2];
  uint16_t dispcnt_pipeline[3];
}nds_ppu_t;
typedef struct{
  bool last_enable; 
  uint16_t reload_value; 
  uint16_t pending_reload_value; 
  uint16_t prescaler_timer;
  uint16_t elapsed_audio_samples;
  int startup_delay;
}nds_timer_t;
typedef struct{
  uint32_t serial_state;
  uint32_t serial_bits_clocked;
  uint64_t input_register;
  uint64_t output_register;
  uint32_t state;
  uint8_t status_register;
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t day_of_week;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
}nds_rtc_t;
typedef struct nds_t{
  nds_mem_t mem;
  arm7_t arm7;
  arm7_t arm9;

  nds_card_t card;
  nds_input_t joy;       
  nds_ppu_t ppu[2];
  nds_rtc_t rtc;
  nds_dma_t dma[4]; 
  //There is a 2 cycle penalty when the CPU takes over from the DMA
  bool last_transaction_dma; 
  bool activate_dmas; 
  nds_timer_t timers[4];
  uint32_t timer_ticks_before_event;
  uint32_t deferred_timer_ticks;
  bool halt; 
  bool prev_key_interrupt;
  uint32_t first_target_buffer[GBA_LCD_W];
  uint32_t second_target_buffer[GBA_LCD_W];
  uint8_t window[GBA_LCD_W];
  uint8_t framebuffer_top[NDS_LCD_W*NDS_LCD_H*3];
  uint8_t framebuffer_bottom[NDS_LCD_W*NDS_LCD_H*3];
  // Some HW has up to a 4 cycle delay before its IF propagates. 
  // This array acts as a FIFO to keep track of that. 
  uint16_t pipelined_if[5];
  int active_if_pipe_stages; 
  char save_file_path[SB_FILE_PATH_SIZE];
} nds_t; 

static void nds_tick_keypad(sb_joy_t*joy, nds_t* nds); 
static FORCE_INLINE void nds_tick_timers(nds_t* nds);
static void nds_compute_timers(nds_t* nds); 
static void FORCE_INLINE nds_send_interrupt(nds_t*nds,int delay,int if_bit);
// Returns a pointer to the data backing the baddr (when not DWORD aligned, it
// ignores the lowest 2 bits. 
static FORCE_INLINE uint32_t * nds_dword_lookup(nds_t* nds,unsigned baddr, int req_type);
static FORCE_INLINE uint32_t nds_read32(nds_t*nds, unsigned baddr){return *nds_dword_lookup(nds,baddr,GBA_REQ_READ|GBA_REQ_4B);}
static FORCE_INLINE uint16_t nds_read16(nds_t*nds, unsigned baddr){
  uint32_t* val = nds_dword_lookup(nds,baddr,GBA_REQ_READ|GBA_REQ_2B);
  int offset = SB_BFE(baddr,1,1);
  return ((uint16_t*)val)[offset];
}
static FORCE_INLINE uint8_t nds_read8(nds_t*nds, unsigned baddr){
  uint32_t* val = nds_dword_lookup(nds,baddr,GBA_REQ_READ|GBA_REQ_1B);
  int offset = SB_BFE(baddr,0,2);
  return ((uint8_t*)val)[offset];
}            
static uint64_t nds_rev_bits(uint64_t data, int bits){
  uint64_t out = 0;
  for(int i=0;i<bits;++i){
    out<<=1;
    out|=data&1;
    data>>=1;
  }
  return out;
}
#define NDS_MEM_1B 0x0
#define NDS_MEM_2B 0x1
#define NDS_MEM_4B 0x2

#define NDS_MEM_WRITE 0x10
#define NDS_MEM_SEQ   0x20
#define NDS_MEM_ARM7  0x40
#define NDS_MEM_ARM9  0x80
static uint32_t nds_apply_mem_op(uint8_t * memory,uint32_t address, uint32_t data, int transaction_type){
  if(transaction_type&NDS_MEM_4B){
    address&=~3;
    if(transaction_type&NDS_MEM_WRITE)*(uint32_t*)(memory+address)=data;
    else data = *(uint32_t*)(memory+address);
  }else if(transaction_type&NDS_MEM_2B){
    address&=~1;
    if(transaction_type&NDS_MEM_WRITE)*(uint16_t*)(memory+address)=data;
    else data = *(uint16_t*)(memory+address);
  }else{
    if(transaction_type&NDS_MEM_WRITE)memory[address]=data;
    else data = memory[address];
  }
  return data; 
}
static uint32_t nds_process_memory_transaction(nds_t * nds, uint32_t addr, uint32_t data, int transaction_type){
  uint32_t *ret = &nds->mem.openbus_word;
  /*
  NDS9 Memory Map

  00000000h  Instruction TCM (32KB) (not moveable) (mirror-able to 1000000h)
  0xxxx000h  Data TCM        (16KB) (moveable)
  02000000h  Main Memory     (4MB)
  03000000h  Shared WRAM     (0KB, 16KB, or 32KB can be allocated to ARM9)
  04000000h  ARM9-I/O Ports
  05000000h  Standard Palettes (2KB) (Engine A BG/OBJ, Engine B BG/OBJ)
  06000000h  VRAM - Engine A, BG VRAM  (max 512KB)
  06200000h  VRAM - Engine B, BG VRAM  (max 128KB)
  06400000h  VRAM - Engine A, OBJ VRAM (max 256KB)
  06600000h  VRAM - Engine B, OBJ VRAM (max 128KB)
  06800000h  VRAM - "LCDC"-allocated (max 656KB)
  07000000h  OAM (2KB) (Engine A, Engine B)
  08000000h  GBA Slot ROM (max 32MB)
  0A000000h  GBA Slot RAM (max 64KB)
  FFFF0000h  ARM9-BIOS (32KB) (only 3K used)

The ARM9 Exception Vectors are located at FFFF0000h. The IRQ handler redirects to [DTCM+3FFCh].

NDS7 Memory Map

  00000000h  ARM7-BIOS (16KB)
  02000000h  Main Memory (4MB)
  03000000h  Shared WRAM (0KB, 16KB, or 32KB can be allocated to ARM7)
  03800000h  ARM7-WRAM (64KB)
  04000000h  ARM7-I/O Ports
  04800000h  Wireless Communications Wait State 0 (8KB RAM at 4804000h)
  04808000h  Wireless Communications Wait State 1 (I/O Ports at 4808000h)
  06000000h  VRAM allocated as Work RAM to ARM7 (max 256K)
  08000000h  GBA Slot ROM (max 32MB)
  0A000000h  GBA Slot RAM (max 64KB)
*/

  switch(addr>>24){
    case 0x0: //BIOS(NDS7), TCM(NDS9)
      if(transaction_type&NDS_MEM_ARM7){
        if(addr<0x4000){
          if(nds->arm7.registers[PC]<0x4000)
            nds->mem.arm7_bios_word = nds_apply_mem_op(nds->mem.nds7_bios,addr,data,transaction_type&~NDS_MEM_WRITE);
          //else nds->mem.bios_word=0;
          nds->mem.openbus_word=nds->mem.arm7_bios_word;
        } 
       }else{
        if(addr<32*1024) nds->mem.openbus_word = nds_apply_mem_op(nds->mem.code_tcm,addr&(32*1024-1),data,transaction_type);
        else nds->mem.openbus_word = nds_apply_mem_op(nds->mem.data_tcm,addr&(16*1024-1),data,transaction_type);
       }
       break;
    case 0x1: // TCM(NDS9)
      if(transaction_type&NDS_MEM_ARM9){
        addr&=0x00ffffff;
        if(addr<32*1024) nds->mem.openbus_word = nds_apply_mem_op(nds->mem.code_tcm,addr&(32*1024-1),data,transaction_type);
        else nds->mem.openbus_word = nds_apply_mem_op(nds->mem.data_tcm,addr&(16*1024-1),data,transaction_type);
       }
       break;
    case 0x2: //Main RAM
      addr&=4*1024*1024-1;
      *ret = nds_apply_mem_op(nds->mem.ram, addr, data, transaction_type); 
      nds->mem.openbus_word=*ret;
      break;
    case 0x3: //Shared WRAM 
      addr&=64*1024-1;
      *ret = nds_apply_mem_op(nds->mem.ram, addr, data, transaction_type); 
      nds->mem.openbus_word=*ret;
      break;
    case 0x4: 
      if(addr<=0x40003FF ){
        addr&=64*1024-1;
        *ret = nds_apply_mem_op(nds->mem.io, addr, data, transaction_type); 
        nds->mem.openbus_word=*ret;
      }
      break;
    case 0x5: //Palette 
      addr&=2*1024-1;
      *ret = nds_apply_mem_op(nds->mem.palette, addr, data, transaction_type); 
      nds->mem.openbus_word=*ret;
      break;
    case 0x6: //VRAM(NDS9) WRAM(NDS7)
      addr&=512*1024-1;
      *ret = nds_apply_mem_op(nds->mem.vram, addr, data, transaction_type); 
      nds->mem.openbus_word=*ret;
      break;
    case 0x7: 
      addr&=2*1024-1;
      *ret = nds_apply_mem_op(nds->mem.oam, addr, data, transaction_type); 
      nds->mem.openbus_word=*ret;
      break;
    case 0x8:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE: 
    case 0xF: break;
    case 0xFF: 
      if(addr>0xFFFF0000&& transaction_type& NDS_MEM_ARM9){
        addr&=32*1024-1;
        *ret = nds_apply_mem_op(nds->mem.nds9_bios, addr, data, transaction_type&~NDS_MEM_WRITE); 
        nds->mem.openbus_word=*ret;
      }
      break;
  }
  return *ret; 
}
/* Only simulates a small subset of the RTC needed to make time events work in the pokemon games. */
//static FORCE_INLINE void nds_process_rtc_state_machine(nds_t* nds){
//  uint32_t data = nds->cart.gpio_data;
//  bool clk  = SB_BFE(data,0,1);
//  bool io_dat = SB_BFE(data,1,1);
//  bool cs   = SB_BFE(data,2,1);
//  #define SERIAL_INIT 0 
//  #define SERIAL_CLK_LOW 1
//  #define SERIAL_CLK_HIGH 2  //

//  #define RTC_RECV_CMD -1
//  #define RTC_RESET     0
//  #define RTC_STATUS    1
//  #define RTC_DATE_TIME 2    
//  #define RTC_TIME      3//

//  nds->rtc.status_register &= ~((1<<7));
//  nds->rtc.status_register |= 0x40;//

//  if(cs==0){
//    nds->rtc.serial_state=SERIAL_INIT;
//    nds->rtc.serial_bits_clocked=0;
//    nds->rtc.state = RTC_RECV_CMD;
//  }//

//  if(cs!=0){
//    bool new_bit = false; 
//    
//    if(nds->rtc.serial_state==SERIAL_CLK_LOW&&clk){
//      nds->rtc.input_register<<=1;
//      nds->rtc.input_register|=((uint64_t)io_dat);
//      new_bit = true;
//    
//      bool out_bit = (nds->rtc.output_register&1);
//      nds->mem.cart_rom[0x0000C4] = (nds->cart.gpio_data&~2)|(out_bit<<1);
//      nds->rtc.output_register>>=1;
//    }
//    
//    nds->rtc.serial_state= clk? SERIAL_CLK_HIGH: SERIAL_CLK_LOW;//

//    if(new_bit){
//      nds->rtc.serial_bits_clocked++;
//      if(nds->rtc.serial_bits_clocked==8) nds->rtc.state= SB_BFE(nds->rtc.input_register,0,4);
//      int  cmd = SB_BFE(nds->rtc.state,1,3);
//      bool read = SB_BFE(nds->rtc.state,0,1);
//      switch(cmd){
//        case RTC_RECV_CMD:break;
//        case RTC_STATUS:{
//          if(nds->rtc.serial_bits_clocked==8) nds->rtc.output_register = nds->rtc.status_register;
//          if(nds->rtc.serial_bits_clocked==16){
//            if(!read)nds->rtc.status_register=SB_BFE(nds->rtc.input_register,0,8);
//            nds->rtc.state= RTC_RECV_CMD;
//            nds->rtc.serial_bits_clocked=0;
//          }
//          break;
//        }
//        case RTC_DATE_TIME:{
//          if(nds->rtc.serial_bits_clocked==8) nds->rtc.output_register =
//            ((uint64_t)(nds->rtc.year&0xff)       <<(0*8))|
//            ((uint64_t)(nds->rtc.month&0xff)      <<(1*8))|
//            ((uint64_t)(nds->rtc.day&0xff)        <<(2*8))|
//            ((uint64_t)(nds->rtc.day_of_week&0xff)<<(3*8))|
//            ((uint64_t)(nds->rtc.hour&0xff)       <<(4*8))|
//            ((uint64_t)(nds->rtc.minute&0xff)     <<(5*8))|
//            ((uint64_t)(nds->rtc.second&0xff)     <<(6*8));
//          if(nds->rtc.serial_bits_clocked==8*8){
//            if(!read){
//              nds->rtc.year  = SB_BFE(nds->rtc.input_register,6*8,8);
//              nds->rtc.month = SB_BFE(nds->rtc.input_register,5*8,8);
//              nds->rtc.day   = SB_BFE(nds->rtc.input_register,4*8,8);
//              nds->rtc.day_of_week = SB_BFE(nds->rtc.input_register,3*8,8);
//              nds->rtc.hour   = SB_BFE(nds->rtc.input_register,2*8,8);
//              nds->rtc.minute = SB_BFE(nds->rtc.input_register,1*8,8);
//              nds->rtc.second = SB_BFE(nds->rtc.input_register,0*8,8);
//            }
//            nds->rtc.state= RTC_RECV_CMD;
//            nds->rtc.serial_bits_clocked=0;
//          }
//          break;
//        }
//        case RTC_TIME:{
//          if(nds->rtc.serial_bits_clocked==8) nds->rtc.output_register = 
//            ((uint64_t)(nds->rtc.hour&0xff)<<(0*8))|
//            ((uint64_t)(nds->rtc.minute&0xff)<<(1*8))|
//            ((uint64_t)(nds->rtc.second&0xff)<<(2*8));
//          if(nds->rtc.serial_bits_clocked==4*8){
//            if(!read){
//              nds->rtc.hour   = SB_BFE(nds->rtc.input_register,0*8,8);
//              nds->rtc.minute = SB_BFE(nds->rtc.input_register,1*8,8);
//              nds->rtc.second = SB_BFE(nds->rtc.input_register,2*8,8);
//            }
//            nds->rtc.state= RTC_RECV_CMD;
//            nds->rtc.serial_bits_clocked=0;
//          }
//          break;
//        }
//      }
//    }
//  }
//}
//static FORCE_INLINE void nds_process_backup_write(nds_t*nds, unsigned baddr, uint32_t data){
//  if(nds->cart.backup_type==GBA_BACKUP_FLASH_64K||nds->cart.backup_type==GBA_BACKUP_FLASH_128K){
//    nds_process_flash_state_machine(nds,baddr,data);
//  }else if(nds->cart.backup_type==GBA_BACKUP_SRAM){
//    if(nds->mem.cart_backup[baddr&0x7fff]!=(data&0xff)){
//      nds->mem.cart_backup[baddr&0x7fff]=data&0xff; 
//      nds->cart.backup_is_dirty=true;
//    }
//  }
//}
static FORCE_INLINE void nds9_store32(nds_t*nds, unsigned baddr, uint32_t data){
  nds_process_memory_transaction(nds,baddr,data,NDS_MEM_WRITE|NDS_MEM_4B|NDS_MEM_ARM9);
}
static FORCE_INLINE void nds7_store32(nds_t*nds, unsigned baddr, uint32_t data){
  nds_process_memory_transaction(nds,baddr,data,NDS_MEM_WRITE|NDS_MEM_4B|NDS_MEM_ARM7);
}
static FORCE_INLINE void nds9_store16(nds_t*nds, unsigned baddr, uint16_t data){
  nds_process_memory_transaction(nds,baddr,data,NDS_MEM_WRITE|NDS_MEM_2B|NDS_MEM_ARM9);
}
static FORCE_INLINE void nds7_store16(nds_t*nds, unsigned baddr, uint16_t data){
  nds_process_memory_transaction(nds,baddr,data,NDS_MEM_WRITE|NDS_MEM_2B|NDS_MEM_ARM7);
}
static FORCE_INLINE void nds9_store8(nds_t*nds, unsigned baddr, uint8_t data){
  nds_process_memory_transaction(nds,baddr,data,NDS_MEM_WRITE|NDS_MEM_1B|NDS_MEM_ARM9);
}
static FORCE_INLINE void nds7_store8(nds_t*nds, unsigned baddr, uint8_t data){
  nds_process_memory_transaction(nds,baddr,data,NDS_MEM_WRITE|NDS_MEM_1B|NDS_MEM_ARM7);
}


static FORCE_INLINE uint32_t nds9_read32(nds_t*nds, unsigned baddr){
  return nds_process_memory_transaction(nds,baddr,0,NDS_MEM_4B|NDS_MEM_ARM9);
}
static FORCE_INLINE uint32_t nds7_read32(nds_t*nds, unsigned baddr){
  return nds_process_memory_transaction(nds,baddr,0,NDS_MEM_4B|NDS_MEM_ARM7);
}
static FORCE_INLINE uint16_t nds9_read16(nds_t*nds, unsigned baddr){
  return nds_process_memory_transaction(nds,baddr,0,NDS_MEM_2B|NDS_MEM_ARM9);
}
static FORCE_INLINE uint16_t nds7_read16(nds_t*nds, unsigned baddr){
  return nds_process_memory_transaction(nds,baddr,0,NDS_MEM_2B|NDS_MEM_ARM7);
}
static FORCE_INLINE uint8_t nds9_read8(nds_t*nds, unsigned baddr){
  return nds_process_memory_transaction(nds,baddr,0,NDS_MEM_1B|NDS_MEM_ARM9);
}
static FORCE_INLINE uint8_t nds7_read8(nds_t*nds, unsigned baddr){
  return nds_process_memory_transaction(nds,baddr,0,NDS_MEM_1B|NDS_MEM_ARM7);
}

static FORCE_INLINE void nds_io_store8(nds_t*nds, unsigned baddr, uint8_t data){nds->mem.io[baddr&0xffff]=data;}
static FORCE_INLINE void nds_io_store16(nds_t*nds, unsigned baddr, uint16_t data){*(uint16_t*)(nds->mem.io+(baddr&0xffff))=data;}
static FORCE_INLINE void nds_io_store32(nds_t*nds, unsigned baddr, uint32_t data){*(uint32_t*)(nds->mem.io+(baddr&0xffff))=data;}

static FORCE_INLINE uint8_t  nds_io_read8(nds_t*nds, unsigned baddr) {return nds->mem.io[baddr&0xffff];}
static FORCE_INLINE uint16_t nds_io_read16(nds_t*nds, unsigned baddr){return *(uint16_t*)(nds->mem.io+(baddr&0xffff));}
static FORCE_INLINE uint32_t nds_io_read32(nds_t*nds, unsigned baddr){return *(uint32_t*)(nds->mem.io+(baddr&0xffff));}
static FORCE_INLINE void nds_recompute_waitstate_table(nds_t* nds,uint16_t waitcnt){
  // TODO: Make the waitstate for the ROM configureable 
  const int wait_state_table[16*4]={
    1,1,1,1, //0x00 (bios)
    1,1,1,1, //0x01 (bios)
    3,3,6,6, //0x02 (256k WRAM)
    1,1,1,1, //0x03 (32k WRAM)
    1,1,1,1, //0x04 (IO)
    1,1,2,2, //0x05 (BG/OBJ Palette)
    1,1,2,2, //0x06 (VRAM)
    1,1,1,1, //0x07 (OAM)
    4,4,8,8, //0x08 (GAMEPAK ROM 0)
    4,4,8,8, //0x09 (GAMEPAK ROM 0)
    4,4,8,8, //0x0A (GAMEPAK ROM 1)
    4,4,8,8, //0x0B (GAMEPAK ROM 1)
    4,4,8,8, //0x0C (GAMEPAK ROM 2)
    4,4,8,8, //0x0D (GAMEPAK ROM 2)
    4,4,4,4, //0x0E (GAMEPAK SRAM)
    1,1,1,1, //0x0F (unused)
  };
  for(int i=0;i<16*4;++i){
    nds->mem.wait_state_table[i]=wait_state_table[i];
  }
  uint8_t sram_wait = SB_BFE(waitcnt,0,2);
  uint8_t wait_first[3];
  uint8_t wait_second[3];

  wait_first[0]  = SB_BFE(waitcnt,2,2);
  wait_second[0] = SB_BFE(waitcnt,4,1);
  wait_first[1]  = SB_BFE(waitcnt,5,2);
  wait_second[1] = SB_BFE(waitcnt,7,1);
  wait_first[2]  = SB_BFE(waitcnt,8,2);
  wait_second[2] = SB_BFE(waitcnt,10,1);
  uint8_t prefetch_en = SB_BFE(waitcnt,14,1);

  int primary_table[4]={4,3,2,8};

  //Each waitstate is two entries in table
  for(int ws=0;ws<3;++ws){
    for(int i=0;i<2;++i){
      uint8_t w_first = primary_table[wait_first[ws]];
      uint8_t w_second = wait_second[ws]?1:2;
      if(ws==1)w_second = wait_second[ws]?1:4;
      if(ws==2)w_second = wait_second[ws]?1:8;
      w_first+=1;w_second+=1;
      //Wait 0
      int wait16b = w_second; 
      int wait32b = w_second*2; 

      int wait16b_nonseq = w_first; 
      int wait32b_nonseq = w_first+w_second;

      nds->mem.wait_state_table[(0x08+i+ws*2)*4+0] = wait16b;
      nds->mem.wait_state_table[(0x08+i+ws*2)*4+1] = wait16b_nonseq;
      nds->mem.wait_state_table[(0x08+i+ws*2)*4+2] = wait32b;
      nds->mem.wait_state_table[(0x08+i+ws*2)*4+3] = wait32b_nonseq;
    }
  }
  nds->mem.prefetch_en = prefetch_en;
  nds->mem.prefetch_size = 0;

  //SRAM
  nds->mem.wait_state_table[(0x0E*4)+0]= 1+primary_table[sram_wait];
  nds->mem.wait_state_table[(0x0E*4)+1]= 1+primary_table[sram_wait];
  nds->mem.wait_state_table[(0x0E*4)+2]= 1+primary_table[sram_wait];
  nds->mem.wait_state_table[(0x0E*4)+3]= 1+primary_table[sram_wait];
  waitcnt&=(1<<15); // Force cartridge to report as GBA cart
  nds_io_store16(nds,GBA_WAITCNT,waitcnt);
}
static FORCE_INLINE void nds_compute_access_cycles(nds_t *nds, uint32_t address,int request_size/*0: 1B,1: 2B,3: 4B*/){
//  int bank = SB_BFE(address,24,4);
//  bool prefetch_en= nds->mem.prefetch_en;
//  if(!prefetch_en){
//    if(nds->cpu.i_cycles)request_size|=1;
//    if(request_size&1)nds->cpu.next_fetch_sequential =false;
//    nds->mem.prefetch_size = 0;
//  }
//  uint32_t wait = nds->mem.wait_state_table[bank*4+request_size];
//  if(prefetch_en){        
//    nds->mem.prefetch_size+=nds->cpu.i_cycles;
//    if(bank>=0x08&&bank<=0x0D){
//      if((request_size&1)){
//        //Non sequential->reset prefetch buffer
//        nds->mem.prefetch_size = 0;
//        // Check if the bubble made it to the execute stage before being squashed, 
//        // and apply the bubble cycle if it was not squashed. 
//        // Note, only a single pipeline bubble is tracked using this infrastructure. 
//        if(nds->mem.pipeline_bubble_shift_register){
//          wait+=1;
//          nds->mem.pipeline_bubble_shift_register=0;
//        }
//        nds->cpu.next_fetch_sequential =false;
//      }else{
//        nds->mem.pipeline_bubble_shift_register>>=wait;
//        //Sequential fetch from prefetch buffer based on available wait states
//        if(nds->mem.prefetch_size>=wait){
//          nds->mem.prefetch_size-=wait-1; 
//          wait = 1; 
//        }else{
//          wait -= nds->mem.prefetch_size;
//          nds->mem.prefetch_size=0;
//        }
//      }
//    }else {
//      nds->mem.pipeline_bubble_shift_register=((bank==0x03||bank==0x07||bank<=0x01)&& (request_size&1))*4; 
//      nds->mem.prefetch_size+=wait; 
//    }
//  }
  uint32_t wait = 1; 
  //wait+=nds->cpu.i_cycles;
  //nds->cpu.i_cycles=0;
  nds->mem.requests+=wait;
}
static FORCE_INLINE uint32_t nds_compute_access_cycles_dma(nds_t *nds, uint32_t address,int request_size/*0: 1B,1: 2B,3: 4B*/){
  int bank = SB_BFE(address,24,4);
  uint32_t wait = nds->mem.wait_state_table[bank*4+request_size];
  return wait;
}
static FORCE_INLINE void nds_process_mmio_read(nds_t *nds, uint32_t address);


// Try to load a GBA rom, return false on invalid rom
bool nds_load_rom(nds_t* nds, const char * filename, const char* save_file);
void nds_reset(nds_t*nds);
 
static FORCE_INLINE uint32_t * nds_dword_lookup(nds_t* nds,unsigned addr, int req_type){
  uint32_t *ret = &nds->mem.openbus_word;
//  switch(addr>>24){
//    case 0x0: if(addr<0x4000){
//      if(nds->cpu.registers[15]<0x4000)nds->mem.bios_word = *(uint32_t*)(nds->mem.bios+(addr&~3));
//      //else nds->mem.bios_word=0;
//      nds->mem.openbus_word=nds->mem.bios_word;
//     } break;
//    case 0x1: break;
//    case 0x2: 
//      ret = (uint32_t*)(nds->mem.wram0+(addr&0x3fffc)); 
//      nds->mem.openbus_word=*ret;
//      break;
//    case 0x3: 
//      ret = (uint32_t*)(nds->mem.wram1+(addr&0x7ffc)); 
//      nds->mem.openbus_word=*ret;
//      break;
//    case 0x4: 
//      if(addr<=0x40003FF ){
//        if(req_type&GBA_REQ_READ){
//          int io_reg = (addr>>2)&0xff;
//          if(nds->mem.mmio_reg_valid_lookup[io_reg]){
//            nds_process_mmio_read(nds,addr);
//            nds->mem.mmio_word = (*(uint32_t*)(nds->mem.io+(addr&0x3fc)))&nds->mem.mmio_data_mask_lookup[io_reg];
//            ret = &nds->mem.mmio_word;
//          }
//        }else ret = (uint32_t*)(nds->mem.io+(addr&0x3fc));
//      }
//      break;
//    case 0x5: 
//      ret = (uint32_t*)(nds->mem.palette+(addr&0x3fc)); 
//      nds->mem.openbus_word=*ret;
//      break;
//    case 0x6: 
//      if(addr&0x10000)ret = (uint32_t*)(nds->mem.vram+(addr&0x07ffc)+0x10000);
//      else ret = (uint32_t*)(nds->mem.vram+(addr&0x1fffc));
//      nds->mem.openbus_word=*ret;
//      break;
//    case 0x7: 
//      ret = (uint32_t*)(nds->mem.oam+(addr&0x3fc));
//      nds->mem.openbus_word=*ret;
//      break;
//    case 0x8:
//    case 0x9:
//    case 0xA:
//    case 0xB:
//    case 0xC:
//    case 0xD:{
//        int maddr = addr&0x1fffffc;
//        if(maddr>=nds->cart.rom_size){
//          nds->mem.openbus_word = ((maddr/2)&0xffff)|(((maddr/2+1)&0xffff)<<16);
//          // Return ready when done writting EEPROM (required by Minish Cap)
//          if(nds->cart.backup_type==GBA_BACKUP_EEPROM) nds->mem.openbus_word = 1; 
//        }else{
//          nds->mem.openbus_word = *(uint32_t*)(nds->mem.cart_rom+maddr);
//          if(req_type&0x3){
//            uint16_t res16 = nds->mem.openbus_word >> (addr&2)*8;
//            nds->mem.openbus_word = res16*0x10001;
//          }
//        }
//      }
//      break;
//    case 0xE:
//    case 0xF:
//      if(nds->cart.backup_type==GBA_BACKUP_SRAM){
//        nds->mem.sram_word= nds->mem.cart_backup[(addr&0x7fff)]*0x01010101;
//        ret = &nds->mem.sram_word;
//     }else if(nds->cart.backup_type==GBA_BACKUP_EEPROM) ret = (uint32_t*)&nds->mem.eeprom_word;
//      else{
//        //Flash
//        if(nds->cart.in_chip_id_mode&&addr<=0xE000001) ret = (uint32_t*)(nds->mem.flash_chip_id);
//        else ret = (uint32_t*)(nds->mem.cart_backup+(addr&0xfffc)+nds->cart.flash_bank*64*1024);
//      }
//      nds->mem.openbus_word=(*ret&0xffff)*0x10001;
//      break;
//  }
  return ret;
}

static void nds_recompute_mmio_mask_table(nds_t* nds){
//  for(int io_reg = 0; io_reg<256;io_reg++){
//    uint32_t dword_address = 0x04000000+io_reg*4;
//    uint32_t data_mask =0xffffffff;
//    bool valid = true;
//    if(dword_address==0x4000008)data_mask&=0xdfffdfff;
//    else if(dword_address==0x4000048)data_mask &= 0x3f3f3f3f;
//    else if(dword_address==0x4000050)data_mask &= 0x1F1F3FFF;
//    else if(dword_address==0x4000060)data_mask &= 0xFFC0007F;
//    else if(dword_address==0x4000064||dword_address==0x400006C||dword_address==0x4000074)data_mask &= 0x4000;
//    else if(dword_address==0x4000068)data_mask &= 0xFFC0;
//    else if(dword_address==0x4000070)data_mask &= 0xE00000E0;
//    else if(dword_address==0x4000078)data_mask &= 0xff00;
//    else if(dword_address==0x400007C)data_mask &= 0x40FF;
//    else if(dword_address==0x4000080)data_mask &= 0x770FFF77;
//    else if(dword_address==0x4000084)data_mask &= 0x0080;
//    else if(dword_address==0x4000088)data_mask = 0x0000ffff;
//    else if(dword_address==0x40000B8||dword_address==0x40000C4||dword_address==0x40000D0)data_mask&=0xf7e00000;
//    else if(dword_address==0x40000DC)data_mask&=0xFFE00000; 
//    else if((dword_address>=0x4000010&& dword_address<=0x4000046) ||
//            (dword_address==0x400004C) ||
//            (dword_address>=0x4000054&& dword_address<=0x400005E)||
//            (dword_address==0x400008C)||
//            (dword_address>=0x40000A0&&dword_address<=0x40000B6)||
//            (dword_address>=0x40000BC&&dword_address<=0x40000C2)||
//            (dword_address>=0x40000C8&&dword_address<=0x40000CE)||
//            (dword_address>=0x40000D4&&dword_address<=0x40000DA)||
//            (dword_address>=0x40000E0&&dword_address<=0x40000FE)||
//            (dword_address==0x400100C))valid = false;
//    nds->mem.mmio_data_mask_lookup[io_reg]=data_mask;
//    nds->mem.mmio_reg_valid_lookup[io_reg]=valid;
//  }
}

static FORCE_INLINE void nds_process_mmio_read(nds_t *nds, uint32_t address){
  // Force recomputing timers on timer read
  if(address>= GBA_TM0CNT_L&&address<=GBA_TM3CNT_H)nds_compute_timers(nds);
}
static bool nds_process_mmio_write(nds_t *nds, uint32_t address, uint32_t data, int req_size_bytes){
//  uint32_t address_u32 = address&~3; 
//  uint32_t word_mask = 0xffffffff;
//  uint32_t word_data = data; 
//  if(req_size_bytes==2){
//    word_data<<= (address&2)*8;
//    word_mask =0x0000ffff<< ((address&2)*8);
//  }else if(req_size_bytes==1){
//    word_data<<= (address&3)*8;
//    word_mask =0x000000ff<< ((address&3)*8);
//  }
//  word_data&=word_mask;
//
//  if(address_u32== GBA_IE){
//    uint16_t IE = nds_io_read16(nds,GBA_IE);
//    uint16_t IF = nds_io_read16(nds,GBA_IF);
  //
//    IE = ((IE&~word_mask)|(word_data&word_mask))>>0;
//    IF &= ~((word_data)>>16);
//    nds_io_store16(nds,GBA_IE,IE);
//    nds_io_store16(nds,GBA_IF,IF);
//
//    return true; 
//  }else if(address_u32 == GBA_TM0CNT_L||address_u32==GBA_TM1CNT_L||address_u32==GBA_TM2CNT_L||address_u32==GBA_TM3CNT_L){
//    nds_compute_timers(nds);
//    int timer_off = (address_u32-GBA_TM0CNT_L)/4;
//    if(word_mask&0xffff){
//      nds->timers[timer_off+0].pending_reload_value = word_data&(word_mask&0xffff);
//    }
//    if(word_mask&0xffff0000){
//      nds_store16(nds,address_u32+2,(word_data>>16)&0xffff);
//      nds->timers[timer_off+0].reload_value =nds->timers[timer_off+0].pending_reload_value;
//    }
//    nds->timer_ticks_before_event=0;
//    return true;
//  }else if(address_u32==GBA_POSTFLG){
//    //Only BIOS can update Post Flag and haltcnt
//    if(nds->cpu.registers[15]<0x4000){
//      //Writes to haltcnt halt the CPU
//      if(word_mask&0xff00)nds->halt = true;
//      uint32_t data = nds_io_read32(nds,address_u32);
//      //POST can only be initialized once, then other writes are dropped. 
//      if((word_mask&0xff)&&(data&0xff))word_mask&=~0xff;
//      data&=~word_mask;
//      data|=word_data&word_mask;
//      nds_io_store32(nds,address_u32,data);
//    }
//    return true; 
//  }else if(address_u32==GBA_BG2X||address_u32==GBA_BG3X){
//    int aff_bg = (address_u32-GBA_BG2X)/32;
//    nds->ppu.aff[aff_bg].internal_bgx&= ~word_mask;
//    nds->ppu.aff[aff_bg].internal_bgx|= word_data;
//  }else if(address_u32==GBA_BG2Y||address_u32==GBA_BG3Y){
//    int aff_bg = (address_u32-GBA_BG2X)/32;
//    nds->ppu.aff[aff_bg].internal_bgy&= ~word_mask;
//    nds->ppu.aff[aff_bg].internal_bgy|= word_data;
//  }else if(address_u32==GBA_DMA0CNT_L||address_u32==GBA_DMA1CNT_L||
//           address_u32==GBA_DMA2CNT_L||address_u32==GBA_DMA3CNT_L){
//    nds->activate_dmas=true;
//  }else if (address_u32==GBA_WAITCNT){
//     uint16_t waitcnt = nds_io_read16(nds,GBA_WAITCNT);
//     waitcnt = ((waitcnt&~word_mask)|(word_data&word_mask));
//     nds_recompute_waitstate_table(nds,waitcnt);
//  }else if(address_u32==GBA_KEYINPUT){
//    if(word_mask&0xffff0000){
//      nds_store16(nds,GBA_KEYINPUT,(word_data>>16)&0xffff);
//    }
//    nds_tick_keypad(NULL,nds);
//  }
  return false;
}
int nds_search_rom_for_backup_string(nds_t* nds){
//  for(int b = 0; b< nds->cart.rom_size;++b){
//    const char* strings[]={"EEPROM_", "SRAM_", "FLASH_","FLASH512_","FLASH1M_"};
//    int backup_type[]= {GBA_BACKUP_EEPROM,GBA_BACKUP_SRAM,GBA_BACKUP_FLASH_64K, GBA_BACKUP_FLASH_64K, GBA_BACKUP_FLASH_128K};
//    for(int type = 0; type<sizeof(strings)/sizeof(strings[0]);++type){
//      int str_off = 0; 
//      bool matches = true; 
//      const char* str = strings[type];
//      while(str[str_off] && matches){
//        if(str[str_off]!=nds->mem.cart_rom[b+str_off])matches = false;
//        if(b+str_off>=nds->cart.rom_size)matches=false; 
//        ++str_off;
//      }
//      if(matches)return backup_type[type];
//    }
//  }
  return GBA_BACKUP_NONE; 
}
bool nds_load_rom(nds_t* nds, const char* filename, const char* save_file){

  if(!sb_path_has_file_ext(filename, ".nds")){
    return false; 
  }
  size_t bytes = 0;                                                       
  uint8_t *data = sb_load_file_data(filename, &bytes);
  if(bytes>512*1024*1024){
    printf("ROMs with sizes >512MB (%zu bytes) are too big for the NDS\n",bytes); 
    return false;
  }  
  if(bytes<1024){
    printf("ROMs with sizes <1024B (%zu bytes) are too small for the NDS\n",bytes); 
    return false;
  }

  strncpy(nds->save_file_path,save_file,SB_FILE_PATH_SIZE);
  nds->save_file_path[SB_FILE_PATH_SIZE-1]=0;

  nds_reset(nds);
  memcpy(&nds->card,data,sizeof(nds_card_t));
  nds->card.title[11]=0;
  nds->mem.card_data=data;
  nds->mem.card_size = bytes;
  
//  nds->cart.backup_type = nds_search_rom_for_backup_string(nds);
//
//  data = sb_load_file_data(save_file,&bytes);
//  if(data){
//    printf("Loaded save file: %s, bytes: %zu\n",save_file,bytes);
//    if(bytes>=128*1024)bytes=128*1024;
//    memcpy(nds->mem.cart_backup, data, bytes);
//    sb_free_file_data(data);
//  }else{
//    printf("Could not find save file: %s\n",save_file);
//    for(int i=0;i<sizeof(nds->mem.cart_backup);++i) nds->mem.cart_backup[i]=0;
//  }
//
//  // Setup flash chip id (this is not used if the cartridge does not have flash backup storage)
//  nds->mem.flash_chip_id[1]=0x13;
//  nds->mem.flash_chip_id[0]=0x62;
  return true; 
}  
static void nds_unload(nds_t* nds){
  printf("Unloading DS data\n");
  sb_free_file_data(nds->mem.card_data);
}
    
static FORCE_INLINE void nds_tick_ppu(nds_t* nds, bool render){
//  nds->ppu.scan_clock+=1;
//  if(nds->ppu.scan_clock%4)return;
//  if(nds->ppu.scan_clock>=280896)nds->ppu.scan_clock-=280896;
//
//  int lcd_y = (nds->ppu.scan_clock+44)/1232;
//  int lcd_x = ((nds->ppu.scan_clock)%1232)/4;
//  if(lcd_x==0||lcd_x==240||lcd_x==296){
//    uint16_t disp_stat = nds_io_read16(nds, GBA_DISPSTAT)&~0x7;
//    uint16_t vcount_cmp = SB_BFE(disp_stat,8,8);
//    bool vblank = lcd_y>=160&&lcd_y<227;
//    bool hblank = lcd_x>=240&&lcd_x< 296;
//    disp_stat |= vblank ? 0x1: 0; 
//    disp_stat |= hblank ? 0x2: 0;      
//    disp_stat |= lcd_y==vcount_cmp ? 0x4: 0;   
//    nds_io_store16(nds,GBA_VCOUNT,lcd_y);   
//    nds_io_store16(nds,GBA_DISPSTAT,disp_stat);
//    uint32_t new_if = 0;
//    if(hblank!=nds->ppu.last_hblank){
//      nds->ppu.last_hblank = hblank;
//      bool hblank_irq_en = SB_BFE(disp_stat,4,1);
//      if(hblank&&hblank_irq_en) new_if|= (1<< GBA_INT_LCD_HBLANK); 
//      nds->activate_dmas=true;
//      if(!hblank){
//        nds->ppu.dispcnt_pipeline[0]=nds->ppu.dispcnt_pipeline[1];
//        nds->ppu.dispcnt_pipeline[1]=nds->ppu.dispcnt_pipeline[2];
//        nds->ppu.dispcnt_pipeline[2]=nds_io_read16(nds, GBA_DISPCNT);
//      }else{
//        uint16_t dispcnt = nds->ppu.dispcnt_pipeline[0];
//
//        int bg_mode = SB_BFE(dispcnt,0,3);
//
//        // From Mirei: Affine registers are only incremented when bg_mode is not 0
//        // and the bg is enabled.
//        if(bg_mode!=0){
//          for(int aff=0;aff<2;++aff){
//            bool bg_en = SB_BFE(dispcnt,8+aff+2,1);
//            if(!bg_en)continue;
//            int32_t b = (int16_t)nds_io_read16(nds,GBA_BG2PB+(aff)*0x10);
//            int32_t d = (int16_t)nds_io_read16(nds,GBA_BG2PD+(aff)*0x10);
//            uint16_t bgcnt = nds_io_read16(nds, GBA_BG2CNT+aff*2);
//            bool mosaic = SB_BFE(bgcnt,6,1);
//            if(mosaic){
//              uint16_t mos_reg = nds_io_read16(nds,GBA_MOSAIC);
//              int mos_y = SB_BFE(mos_reg,4,4)+1;
//              if((lcd_y%mos_y)==0){
//                nds->ppu.aff[aff].internal_bgx+=b*mos_y;
//                nds->ppu.aff[aff].internal_bgy+=d*mos_y;
//              }
//            }else{
//              nds->ppu.aff[aff].internal_bgx+=b;
//              nds->ppu.aff[aff].internal_bgy+=d;
//            }
//          }
//        }
//      }
//    }
//    if(lcd_y != nds->ppu.last_lcd_y){
//      if(vblank!=nds->ppu.last_vblank){
//        nds->ppu.last_vblank = vblank;
//        bool vblank_irq_en = SB_BFE(disp_stat,3,1);
//        if(vblank&&vblank_irq_en) new_if|= (1<< GBA_INT_LCD_VBLANK); 
//        nds->activate_dmas=true;
//      }
//      nds->ppu.last_lcd_y  = lcd_y;
//      if(lcd_y==vcount_cmp) {
//        bool vcnt_irq_en = SB_BFE(disp_stat,5,1);
//        if(vcnt_irq_en)new_if |= (1<<GBA_INT_LCD_VCOUNT);
//      }
//      //Latch BGX and BGY registers
//      if(lcd_y==0){
//        for(int aff=0;aff<2;++aff){
//          nds->ppu.aff[aff].internal_bgx=nds_io_read32(nds,GBA_BG2X+(aff)*0x10);
//          nds->ppu.aff[aff].internal_bgy=nds_io_read32(nds,GBA_BG2Y+(aff)*0x10);
//
//          nds->ppu.aff[aff].internal_bgx = SB_BFE(nds->ppu.aff[aff].internal_bgx,0,28);
//          nds->ppu.aff[aff].internal_bgy = SB_BFE(nds->ppu.aff[aff].internal_bgy,0,28);
//
//          nds->ppu.aff[aff].internal_bgx = (nds->ppu.aff[aff].internal_bgx<<4)>>4;
//          nds->ppu.aff[aff].internal_bgy = (nds->ppu.aff[aff].internal_bgy<<4)>>4;
//        }
//      }
//    }
//    nds_send_interrupt(nds,3,new_if);
//  }
//
//  if(!render)return; 
//
//  uint16_t dispcnt = nds_io_read16(nds, GBA_DISPCNT);
//  int bg_mode = SB_BFE(dispcnt,0,3);
//  int obj_vram_map_2d = !SB_BFE(dispcnt,6,1);
//  int forced_blank = SB_BFE(dispcnt,7,1);
//  if(forced_blank)return;
//  bool visible = lcd_x<240 && lcd_y<160;
//  //Render sprites over scanline when it completes
//  if(lcd_y<160 && lcd_x == 0){
    //
//    //Render sprites over scanline when it completes
//    uint8_t default_window_control =0x3f;//bitfield [0-3:bg0-bg3 enable 4:obj enable, 5: special effect enable]
//    bool winout_enable = SB_BFE(dispcnt,13,3)!=0;
//    uint16_t WINOUT = nds_io_read16(nds, GBA_WINOUT);
//    if(winout_enable)default_window_control = SB_BFE(WINOUT,0,8);
  //
//    for(int x=0;x<240;++x){nds->window[x] = default_window_control;}
//    uint8_t obj_window_control = default_window_control;
//    bool obj_window_enable = SB_BFE(dispcnt,15,1);
//    if(obj_window_enable)obj_window_control = SB_BFE(WINOUT,8,6);
//    bool display_obj = SB_BFE(dispcnt,12,1);
//    if(display_obj){
//      for(int o=0;o<128;++o){
//        uint16_t attr0 = *(uint16_t*)(nds->mem.oam+o*8+0);
//        //Attr0
//        uint8_t y_coord = SB_BFE(attr0,0,8);
//        bool rot_scale =  SB_BFE(attr0,8,1);
//        bool double_size = SB_BFE(attr0,9,1)&&rot_scale;
//        bool obj_disable = SB_BFE(attr0,9,1)&&!rot_scale;
//        if(obj_disable) continue; 
//
//        int obj_mode = SB_BFE(attr0,10,2); //(0=Normal, 1=Semi-Transparent, 2=OBJ Window, 3=Prohibited)
//        bool mosaic  = SB_BFE(attr0,12,1);
//        bool colors_or_palettes = SB_BFE(attr0,13,1);
//        int obj_shape = SB_BFE(attr0,14,2);//(0=Square,1=Horizontal,2=Vertical,3=Prohibited)
//        uint16_t attr1 = *(uint16_t*)(nds->mem.oam+o*8+2);
//
//        int rotscale_param = SB_BFE(attr1,9,5);
//        bool h_flip = SB_BFE(attr1,12,1)&&!rot_scale;
//        bool v_flip = SB_BFE(attr1,13,1)&&!rot_scale;
//        int obj_size = SB_BFE(attr1,14,2);
//        // Size  Square   Horizontal  Vertical
//        // 0     8x8      16x8        8x16
//        // 1     16x16    32x8        8x32
//        // 2     32x32    32x16       16x32
//        // 3     64x64    64x32       32x64
//        const int xsize_lookup[16]={
//          8,16,8,0,
//          16,32,8,0,
//          32,32,16,0,
//          64,64,32,0
//        };
//        const int ysize_lookup[16]={
//          8,8,16,0,
//          16,8,32,0,
//          32,16,32,0,
//          64,32,64,0
//        }; 
//
//        int y_size = ysize_lookup[obj_size*4+obj_shape];
//
//        if(((lcd_y-y_coord)&0xff) <y_size*(double_size?2:1)){
//          int16_t x_coord = SB_BFE(attr1,0,9);
//          if (SB_BFE(x_coord,8,1))x_coord|=0xfe00;
//
//          int x_size = xsize_lookup[obj_size*4+obj_shape];
//          int x_start = x_coord>=0?x_coord:0;
//          int x_end   = x_coord+x_size*(double_size?2:1);
//          if(x_end>=240)x_end=240;
//          //Attr2
//          //Skip objects disabled by window
//          uint16_t attr2 = *(uint16_t*)(nds->mem.oam+o*8+4);
//          int tile_base = SB_BFE(attr2,0,10);
//          // Always place sprites as the highest priority
//          int priority = SB_BFE(attr2,10,2);
//          int palette = SB_BFE(attr2,12,4);
//          for(int x = x_start; x< x_end;++x){
//            int sx = (x-x_coord);
//            int sy = (lcd_y-y_coord)&0xff;
//            if(mosaic){
//              uint16_t mos_reg = nds_io_read16(nds,GBA_MOSAIC);
//              int mos_x = SB_BFE(mos_reg,8,4)+1;
//              int mos_y = SB_BFE(mos_reg,12,4)+1;
//              sx = ((x/mos_x)*mos_x-x_coord);
//              sy = (((lcd_y/mos_y)*mos_y-y_coord)&0xff);
//            }
//            if(rot_scale){
//              uint32_t param_base = rotscale_param*0x20; 
//              int32_t a = *(int16_t*)(nds->mem.oam+param_base+0x6);
//              int32_t b = *(int16_t*)(nds->mem.oam+param_base+0xe);
//              int32_t c = *(int16_t*)(nds->mem.oam+param_base+0x16);
//              int32_t d = *(int16_t*)(nds->mem.oam+param_base+0x1e);
   //
//              int64_t x1 = sx<<8;
//              int64_t y1 = sy<<8;
//              int64_t objref_x = (x_size<<(double_size?8:7));
//              int64_t objref_y = (y_size<<(double_size?8:7));
              //
//              int64_t x2 = a*(x1-objref_x) + b*(y1-objref_y)+(x_size<<15);
//              int64_t y2 = c*(x1-objref_x) + d*(y1-objref_y)+(y_size<<15);
//
//              sx = (x2>>16);
//              sy = (y2>>16);
//              if(sx>=x_size||sy>=y_size||sx<0||sy<0)continue;
//            }else{
//              if(h_flip)sx=x_size-sx-1;
//              if(v_flip)sy=y_size-sy-1;
//            }
//            int tx = sx%8;
//            int ty = sy%8;
                      //
//            int y_tile_stride = obj_vram_map_2d? 32 : x_size/8*(colors_or_palettes? 2:1);
//            int tile = tile_base + ((sx/8))*(colors_or_palettes? 2:1)+(sy/8)*y_tile_stride;
//            //Tiles >511 are not rendered in bg_mode3-5 since that memory is used to store the bitmap graphics. 
//            if(tile<512&&bg_mode>=3&&bg_mode<=5)continue;
//            uint8_t palette_id;
//            int obj_tile_base = GBA_OBJ_TILES0_2;
//            if(colors_or_palettes==false){
//              palette_id= nds->mem.vram[obj_tile_base+tile*8*4+tx/2+ty*4];
//              palette_id= (palette_id>>((tx&1)*4))&0xf;
//              if(palette_id==0)continue;
//              palette_id+=palette*16;
//            }else{
//              palette_id=nds->mem.vram[obj_tile_base+tile*8*4+tx+ty*8];
//              if(palette_id==0)continue;
//            }
//
//            uint32_t col = *(uint16_t*)(nds->mem.palette+GBA_OBJ_PALETTE+palette_id*2);
//            //Handle window objects(not displayed but control the windowing of other things)
//            if(obj_mode==2){nds->window[x]=obj_window_control; 
//            }else if(obj_mode!=3){
//              int type =4;
//              col=col|(type<<17)|((5-priority)<<28)|((0x7)<<25);
//              if(obj_mode==1)col|=1<<16;
//              if((col>>17)>(nds->first_target_buffer[x]>>17))nds->first_target_buffer[x]=col;
//            }  
//          }
//        }
//      }
//    }
//    int enabled_windows = SB_BFE(dispcnt,13,3); // [0: win0, 1:win1, 2: objwin]
//    if(enabled_windows){
//      for(int win=1;win>=0;--win){
//        bool win_enable = SB_BFE(dispcnt,13+win,1);
//        if(!win_enable)continue;
//        uint16_t WINH = nds_io_read16(nds, GBA_WIN0H+2*win);
//        uint16_t WINV = nds_io_read16(nds, GBA_WIN0V+2*win);
//        int win_xmin = SB_BFE(WINH,8,8);
//        int win_xmax = SB_BFE(WINH,0,8);
//        int win_ymin = SB_BFE(WINV,8,8);
//        int win_ymax = SB_BFE(WINV,0,8);
//        // Garbage values of X2>240 or X1>X2 are interpreted as X2=240.
//        // Garbage values of Y2>160 or Y1>Y2 are interpreted as Y2=160. 
//        if(win_xmin>win_xmax)win_xmax=240;
//        if(win_ymin>win_ymax)win_ymax=161;
//        if(win_xmax>240)win_xmax=240;
//        if(lcd_y<win_ymin||lcd_y>=win_ymax)continue;
//        uint16_t winin = nds_io_read16(nds,GBA_WININ);
//        uint8_t win_value = SB_BFE(winin,win*8,6);
//        for(int x=win_xmin;x<win_xmax;++x)nds->window[x] = win_value;
//      }
//      int backdrop_type = 5;
//      uint32_t backdrop_col = (*(uint16_t*)(nds->mem.palette + GBA_BG_PALETTE+0*2))|(backdrop_type<<17);
//      for(int x=0;x<240;++x){
//        uint8_t window_control = nds->window[x];
//        if(SB_BFE(window_control,4,1)==0)nds->first_target_buffer[x]=backdrop_col;
//      }
//    }
//  }
//
//  if(visible){
//    uint8_t window_control =nds->window[lcd_x];
//    if(bg_mode==6 ||bg_mode==7){
//      //Palette 0 is taken as the background
//    }else if (bg_mode<=5){     
//      for(int bg = 3; bg>=0;--bg){
//        uint32_t col =0;         
//        if((bg<2&&bg_mode==2)||(bg==3&&bg_mode==1)||(bg!=2&&bg_mode>=3))continue;
//        bool bg_en = SB_BFE(dispcnt,8+bg,1)&&SB_BFE(nds->ppu.dispcnt_pipeline[0],8+bg,1);
//        if(!bg_en || SB_BFE(window_control,bg,1)==0)continue;
//
//        bool rot_scale = bg_mode>=1&&bg>=2;
//        uint16_t bgcnt = nds_io_read16(nds, GBA_BG0CNT+bg*2);
//        int priority = SB_BFE(bgcnt,0,2);
//        int character_base = SB_BFE(bgcnt,2,2);
//        bool mosaic = SB_BFE(bgcnt,6,1);
//        bool colors = SB_BFE(bgcnt,7,1);
//        int screen_base = SB_BFE(bgcnt,8,5);
//        bool display_overflow =SB_BFE(bgcnt,13,1);
//        int screen_size = SB_BFE(bgcnt,14,2);
//
//        int screen_size_x = (screen_size&1)?512:256;
//        int screen_size_y = (screen_size>=2)?512:256;
        //
//        int bg_x = 0;
//        int bg_y = 0;
        //
//        if(rot_scale){
//          screen_size_x = screen_size_y = (16*8)<<screen_size;
//          if(bg_mode==3||bg_mode==4){
//            screen_size_x=240;
//            screen_size_y=160;
//          }else if(bg_mode==5){
//            screen_size_x=160;
//            screen_size_y=128;
//          }
//          colors = true;
//
//          int32_t bgx = nds->ppu.aff[bg-2].internal_bgx;
//          int32_t bgy = nds->ppu.aff[bg-2].internal_bgy;
//
//          int32_t a = (int16_t)nds_io_read16(nds,GBA_BG2PA+(bg-2)*0x10);
//          int32_t c = (int16_t)nds_io_read16(nds,GBA_BG2PC+(bg-2)*0x10);
//
//          // Shift lcd_coords into fixed point
//          int64_t x2 = a*lcd_x + (((int64_t)bgx));
//          int64_t y2 = c*lcd_x + (((int64_t)bgy));
//          if(mosaic){
//            int16_t mos_reg = nds_io_read16(nds,GBA_MOSAIC);
//            int mos_x = SB_BFE(mos_reg,0,4)+1;
//            x2 = a*((lcd_x/mos_x)*mos_x) + (((int64_t)bgx));
//            y2 = c*((lcd_x/mos_x)*mos_x) + (((int64_t)bgy));
//          }
//
//
//          bg_x = (x2>>8);
//          bg_y = (y2>>8);
//
//          if(display_overflow==0){
//            if(bg_x<0||bg_x>=screen_size_x||bg_y<0||bg_y>=screen_size_y)continue; 
//          }else{
//            bg_x%=screen_size_x;
//            bg_y%=screen_size_y;
//          }
                              //
//        }else{
//          int16_t hoff = nds_io_read16(nds,GBA_BG0HOFS+bg*4);
//          int16_t voff = nds_io_read16(nds,GBA_BG0VOFS+bg*4);
//          hoff=(hoff<<7)>>7;
//          voff=(voff<<7)>>7;
//          bg_x = (hoff+lcd_x);
//          bg_y = (voff+lcd_y);
//          if(mosaic){
//            uint16_t mos_reg = nds_io_read16(nds,GBA_MOSAIC);
//            int mos_x = SB_BFE(mos_reg,0,4)+1;
//            int mos_y = SB_BFE(mos_reg,4,4)+1;
//            bg_x = hoff+(lcd_x/mos_x)*mos_x;
//            bg_y = voff+(lcd_y/mos_y)*mos_y;
//          }
//        }
//        if(bg_mode==3){
//          int p = bg_x+bg_y*240;
//          int addr = p*2; 
//          col  = *(uint16_t*)(nds->mem.vram+addr);
//        }else if(bg_mode==4){
//          int p = bg_x+bg_y*240;
//          int frame_sel = SB_BFE(dispcnt,4,1);
//          int addr = p*1+0xA000*frame_sel; 
//          uint8_t pallete_id = nds->mem.vram[addr];
//          if(pallete_id==0)continue;
//          col = *(uint16_t*)(nds->mem.palette+GBA_BG_PALETTE+pallete_id*2);
//        }else if(bg_mode==5){
//          int p = bg_x+bg_y*160;
//          int frame_sel = SB_BFE(dispcnt,4,1);
//          int addr = p*2+0xA000*frame_sel; 
//          col  = *(uint16_t*)(nds->mem.vram+addr);
//        }else{
//          bg_x = bg_x&(screen_size_x-1);
//          bg_y = bg_y&(screen_size_y-1);
//          int bg_tile_x = bg_x/8;
//          int bg_tile_y = bg_y/8;
//
//          int tile_off = bg_tile_y*(screen_size_x/8)+bg_tile_x;
//
//          int screen_base_addr =    screen_base*2048;
//          int character_base_addr = character_base*16*1024;
//
//          uint16_t tile_data =0;
//
//          int px = bg_x%8;
//          int py = bg_y%8;
//
//          if(rot_scale)tile_data=nds->mem.vram[screen_base_addr+tile_off];
//          else{
//            int tile_off = (bg_tile_y%32)*32+(bg_tile_x%32);
//            if(bg_tile_x>=32)tile_off+=32*32;
//            if(bg_tile_y>=32)tile_off+=32*32*(screen_size==3?2:1);
//            tile_data=*(uint16_t*)(nds->mem.vram+screen_base_addr+tile_off*2);
//
//            int h_flip = SB_BFE(tile_data,10,1);
//            int v_flip = SB_BFE(tile_data,11,1);
//            if(h_flip)px=7-px;
//            if(v_flip)py=7-py;
//          }
//          int tile_id = SB_BFE(tile_data,0,10);
//          int palette = SB_BFE(tile_data,12,4);
//
//          uint8_t tile_d=tile_id;
//          if(colors==false){
//            tile_d=nds->mem.vram[character_base_addr+tile_id*8*4+px/2+py*4];
//            tile_d= (tile_d>>((px&1)*4))&0xf;
//            if(tile_d==0)continue;
//            tile_d+=palette*16;
//          }else{
//            tile_d=nds->mem.vram[character_base_addr+tile_id*8*8+px+py*8];
//            if(tile_d==0)continue;
//          }
//          uint8_t pallete_id = tile_d;
//          col = *(uint16_t*)(nds->mem.palette+GBA_BG_PALETTE+pallete_id*2);
//        }
//        col |= (bg<<17) | ((5-priority)<<28)|((4-bg)<<25);
//        if(col>nds->first_target_buffer[lcd_x]){
//          uint32_t t = nds->first_target_buffer[lcd_x];
//          nds->first_target_buffer[lcd_x]=col;
//          col = t;
//        }
//        if(col>nds->second_target_buffer[lcd_x])nds->second_target_buffer[lcd_x]=col;          
//      }
//    }
//    uint32_t col = nds->first_target_buffer[lcd_x];
//    int r = SB_BFE(col,0,5);
//    int g = SB_BFE(col,5,5);
//    int b = SB_BFE(col,10,5);
//    uint32_t type = SB_BFE(col,17,3);
//
//    bool effect_enable = SB_BFE(window_control,5,1);
//    uint16_t bldcnt = nds_io_read16(nds,GBA_BLDCNT);
//    int mode = SB_BFE(bldcnt,6,2);
//
//    //Semitransparent objects are always selected for blending
//    if(SB_BFE(col,16,1)){
//      uint32_t col2 = nds->second_target_buffer[lcd_x];
//      uint32_t type2 = SB_BFE(col2,17,3);
//      bool blend = SB_BFE(bldcnt,8+type2,1);
//      if(blend){mode=1;effect_enable=true;}
//      else effect_enable &= SB_BFE(bldcnt,type,1);
//    }else effect_enable &= SB_BFE(bldcnt,type,1);
//    if(effect_enable){
//      uint16_t bldy = nds_io_read16(nds,GBA_BLDY);
//      float evy = SB_BFE(bldy,0,5)/16.;
//      if(evy>1.0)evy=1;
//      switch(mode){
//        case 0: break; //None
//        case 1: {
//          uint32_t col2 = nds->second_target_buffer[lcd_x];
//          uint32_t type2 = SB_BFE(col2,17,3);
//          bool blend = SB_BFE(bldcnt,8+type2,1);
//          if(blend){
//            uint16_t bldalpha= nds_io_read16(nds,GBA_BLDALPHA);
//            int r2 = SB_BFE(col2,0,5);
//            int g2 = SB_BFE(col2,5,5);
//            int b2 = SB_BFE(col2,10,5);
//            int eva = SB_BFE(bldalpha,0,5);
//            int evb = SB_BFE(bldalpha,8,5);
//            if(eva>16)eva=16;
//            if(evb>16)evb=16;
//            r = (r*eva+r2*evb)/16;
//            g = (g*eva+g2*evb)/16;
//            b = (b*eva+b2*evb)/16;
//            if(r>31)r = 31;
//            if(g>31)g = 31;
//            if(b>31)b = 31;
//          }
//        }break; //Alpha Blend
//        case 2: //Lighten
//          r = r+(31-r)*evy;
//          g = g+(31-g)*evy;
//          b = b+(31-b)*evy;  
//          break; 
//        case 3: //Darken
//          r = r-(r)*evy;
//          g = g-(g)*evy;
//          b = b-(b)*evy;         
//          break; 
//      }
//    }
//    int p = (lcd_x+lcd_y*240)*3;
//    float screen_blend_factor = 0.7;
//    nds->framebuffer[p+0] = r*7*screen_blend_factor+nds->framebuffer[p+0]*(1.0-screen_blend_factor);
//    nds->framebuffer[p+1] = g*7*screen_blend_factor+nds->framebuffer[p+1]*(1.0-screen_blend_factor);
//    nds->framebuffer[p+2] = b*7*screen_blend_factor+nds->framebuffer[p+2]*(1.0-screen_blend_factor);  
//    int backdrop_type = 5;
//    uint32_t backdrop_col = (*(uint16_t*)(nds->mem.palette + GBA_BG_PALETTE+0*2))|(backdrop_type<<17);
//    nds->first_target_buffer[lcd_x] = backdrop_col;
//    nds->second_target_buffer[lcd_x] = backdrop_col;
//  }
}
static void nds_tick_keypad(sb_joy_t*joy, nds_t* nds){
//  uint16_t reg_value = 0;
//  //Null joy updates are used to tick the joypad when mmios are set
//  if(joy){
//    reg_value|= !(joy->a)     <<0;
//    reg_value|= !(joy->b)     <<1;
//    reg_value|= !(joy->select)<<2;
//    reg_value|= !(joy->start) <<3;
//    reg_value|= !(joy->right) <<4;
//    reg_value|= !(joy->left)  <<5;
//    reg_value|= !(joy->up)    <<6;
//    reg_value|= !(joy->down)  <<7;
//    reg_value|= !(joy->r)     <<8;
//    reg_value|= !(joy->l)     <<9;
//    nds_io_store16(nds, GBA_KEYINPUT, reg_value);
//  }else reg_value = nds_io_read16(nds, GBA_KEYINPUT);
//
//  uint16_t keycnt = nds_io_read16(nds,GBA_KEYCNT);
//  bool irq_enable = SB_BFE(keycnt,14,1);
//  bool irq_condition = SB_BFE(keycnt,15,1);//[0: any key, 1: all keys]
//  int if_bit = 0;
//  if(irq_enable){
//    uint16_t pressed = SB_BFE(reg_value,0,10)^0x3ff;
//    uint16_t mask = SB_BFE(keycnt,0,10);
//
//    if(irq_condition&&((pressed&mask)==mask))if_bit|= 1<<GBA_INT_KEYPAD;
//    if(!irq_condition&&((pressed&mask)!=0))if_bit|= 1<<GBA_INT_KEYPAD;
//
//    if(if_bit&&!nds->prev_key_interrupt){
//      nds_send_interrupt(nds,4,if_bit);
//      nds->prev_key_interrupt = true;
//    }else nds->prev_key_interrupt = false;
//
//  }

}
/*uint64_t nds_read_eeprom_bitstream(nds_t *nds, uint32_t source_address, int offset, int size, int elem_size, int dir){
  uint64_t data = 0; 
  for(int i=0;i<size;++i){
    data|= ((uint64_t)(nds_read16(nds,source_address+(i+offset)*elem_size*dir)&1))<<(size-i-1);
  }
  return data; 
}
void nds_store_eeprom_bitstream(nds_t *nds, uint32_t source_address, int offset, int size, int elem_size, int dir,uint64_t data){
  for(int i=0;i<size;++i){
    nds_store16(nds,source_address+(i+offset)*elem_size*dir,data>>(size-i-1)&1);
  }
}*/
static FORCE_INLINE int nds_tick_dma(nds_t*nds, int last_tick){
  return 0; 
//  int ticks =0;
//  nds->activate_dmas=false;
//  for(int i=0;i<4;++i){
//    uint16_t cnt_h=nds_io_read16(nds, GBA_DMA0CNT_H+12*i);
//    bool enable = SB_BFE(cnt_h,15,1);
//    if(enable){
//      bool type = SB_BFE(cnt_h,10,1); // 0: 16b 1:32b
//
//      if(!nds->dma[i].last_enable){
//        nds->dma[i].last_enable = enable;
//        nds->dma[i].source_addr=nds_io_read32(nds,GBA_DMA0SAD+12*i);
//        nds->dma[i].dest_addr=nds_io_read32(nds,GBA_DMA0DAD+12*i);
//        //GBA Suite says that these need to be force aligned
//        if(type){
//          nds->dma[i].dest_addr&=~3;
//          nds->dma[i].source_addr&=~3;
//        }else{
//          nds->dma[i].dest_addr&=~1;
//          nds->dma[i].source_addr&=~1;
//        }
//        nds->dma[i].current_transaction=0;
//        nds->dma[i].startup_delay=2;
//      }
  //
//      int  dst_addr_ctl = SB_BFE(cnt_h,5,2); // 0: incr 1: decr 2: fixed 3: incr reload
//      int  src_addr_ctl = SB_BFE(cnt_h,7,2); // 0: incr 1: decr 2: fixed 3: not allowed
//      bool dma_repeat = SB_BFE(cnt_h,9,1); 
//      int  mode = SB_BFE(cnt_h,12,2);
//      bool irq_enable = SB_BFE(cnt_h,14,1);
//      bool force_first_write_sequential = false;
//      int transfer_bytes = type? 4:2; 
//      bool skip_dma = false;
//      if(nds->dma[i].current_transaction==0){
//        if(mode==3 && i ==0)continue;
//        if(nds->dma[i].startup_delay>=0){
//          nds->dma[i].startup_delay-=last_tick; 
//          if(nds->dma[i].startup_delay>=0){
//            nds->activate_dmas=true;
//            continue;
//          }
//          nds->dma[i].startup_delay=-1;
//        }
//        if(dst_addr_ctl==3){        
//          nds->dma[i].dest_addr=nds_io_read32(nds,GBA_DMA0DAD+12*i);
//        }
//        bool last_vblank = nds->dma[i].last_vblank;
//        bool last_hblank = nds->dma[i].last_hblank;
//        nds->dma[i].last_vblank = nds->ppu.last_vblank;
//        nds->dma[i].last_hblank = nds->ppu.last_hblank;
//        if(mode ==1 && (!nds->ppu.last_vblank||last_vblank)) continue; 
//        if(mode==2){
//          uint16_t vcount = nds_io_read16(nds,GBA_VCOUNT);
//          if(vcount>=160||!nds->ppu.last_hblank||last_hblank)continue;
//        }
//        //Video dma
//        if(mode==3 && i ==3){
//          uint16_t vcount = nds_io_read16(nds,GBA_VCOUNT);
//          if(!nds->ppu.last_hblank||last_hblank)continue;
//          //Video dma starts at scanline 2
//          if(vcount<2)continue;
//          if(vcount==161)dma_repeat=false;
//        }
//        if(dst_addr_ctl==3){
//          nds->dma[i].dest_addr=nds_io_read32(nds,GBA_DMA0DAD+12*i);
//          //GBA Suite says that these need to be force aligned
//          if(type) nds->dma[i].dest_addr&=~3;
//          else nds->dma[i].dest_addr&=~1;
//        }
//        if(nds->dma[i].source_addr>=0x08000000&&nds->dma[i].dest_addr>=0x08000000){
//          force_first_write_sequential=true;
//        }else{
//          if(nds->dma[i].dest_addr>=0x08000000){
//            // Allow the in process prefetech to finish before starting DMA
//            if(!nds->mem.prefetch_size&&nds->mem.prefetch_en)ticks+=nds_compute_access_cycles_dma(nds,nds->dma[i].dest_addr,2)>4;
//          }
//        }
//        if(nds->dma[i].source_addr>=0x08000000){
//            if(nds->mem.prefetch_en)ticks+=nds_compute_access_cycles_dma(nds,nds->dma[i].source_addr,2)<=4;
//        }
//        nds->last_transaction_dma=true;
//        uint32_t cnt = nds_io_read16(nds,GBA_DMA0CNT_L+12*i);
//
//        if(i!=3)cnt&=0x3fff;
//        if(cnt==0)cnt = i==3? 0x10000: 0x4000;
//
//        static const uint32_t src_mask[] = { 0x07FFFFFF, 0x0FFFFFFF, 0x0FFFFFFF, 0x0FFFFFFF};
//        static const uint32_t dst_mask[] = { 0x07FFFFFF, 0x07FFFFFF, 0x07FFFFFF, 0x0FFFFFFF};
//        nds->dma[i].source_addr&=src_mask[i];
//        nds->dma[i].dest_addr  &=dst_mask[i];
//        nds_io_store16(nds,GBA_DMA0CNT_L+12*i,cnt);
        //
//        if(src_addr_ctl==0&&(dst_addr_ctl==0||dst_addr_ctl==3)&&cnt>2){
//          int fast_dma_count = cnt-2;
//          int bytes = fast_dma_count*transfer_bytes;
//          int src_addr = nds->dma[i].source_addr; 
//          int dst_addr = nds->dma[i].dest_addr; 
//
//          uint8_t *source_start = (uint8_t*)nds_dword_lookup(nds,src_addr,transfer_bytes|GBA_REQ_READ)+(src_addr&3);
//          uint8_t *dest_start   = (uint8_t*)nds_dword_lookup(nds,dst_addr,transfer_bytes|GBA_REQ_WRITE)+(dst_addr&3);
//          uint8_t *source_end = (uint8_t*)nds_dword_lookup(nds,src_addr+bytes,transfer_bytes|GBA_REQ_READ)+(src_addr&3);
//          uint8_t *dest_end   = (uint8_t*)nds_dword_lookup(nds,dst_addr+bytes,transfer_bytes|GBA_REQ_WRITE)+(dst_addr&3);
//          if(source_end-source_start==bytes&&dest_end-dest_start==bytes&&mode!=3){
//            if((i!=0||src_addr<0x08000000)&&(src_addr>=0x02000000)){
//              bytes = fast_dma_count*transfer_bytes;
//              memcpy(dest_start,source_start, bytes);
//              nds->dma[i].current_transaction=fast_dma_count;
//              int trans_type = type?2:0;
//              // First non-sequential fetch
//              ticks+=nds_compute_access_cycles_dma(nds, nds->dma[i].dest_addr,trans_type+(force_first_write_sequential?0:1));
//              ticks+=nds_compute_access_cycles_dma(nds, src_addr, trans_type+1);
//              // Remaining sequential fetches
//              ticks+=nds_compute_access_cycles_dma(nds, nds->dma[i].dest_addr, trans_type)*(fast_dma_count-1);
//              ticks+=nds_compute_access_cycles_dma(nds, src_addr, trans_type)*(fast_dma_count-1);
//            }
//          }
//        }
        //
//      }
//      const static int dir_lookup[4]={1,-1,0,1};
//      int src_dir = dir_lookup[src_addr_ctl];
//      int dst_dir = dir_lookup[dst_addr_ctl];
//
//      uint32_t src = nds->dma[i].source_addr;
//      uint32_t dst = nds->dma[i].dest_addr;
//      uint32_t cnt = nds_io_read16(nds,GBA_DMA0CNT_L+12*i);
//
//      // ROM ignores direction and always increments
//      if(src>=0x08000000&&src<0x0e000000) src_dir=1;
//      if(dst>=0x08000000&&dst<0x0e000000) dst_dir=1;
//
//      // EEPROM DMA transfers
//      if(i==3 && nds->cart.backup_type==GBA_BACKUP_EEPROM){
//        int src_in_eeprom = (src&0x1ffffff)>=nds->cart.rom_size||(src&0x1ffffff)>=0x01ffff00;
//        int dst_in_eeprom = (dst&0x1ffffff)>=nds->cart.rom_size||(dst&0x1ffffff)>=0x01ffff00;
//        src_in_eeprom &= src>=0x8000000 && src<=0xDFFFFFF;
//        dst_in_eeprom &= dst>=0x8000000 && dst<=0xDFFFFFF;
//        skip_dma = src_in_eeprom || dst_in_eeprom;
//        if(dst_in_eeprom){
//          if(cnt==73){
//            // Write data 6 bit address
//            uint32_t addr = nds_read_eeprom_bitstream(nds, src, 2, 6, type?4:2, src_dir);
//            uint64_t data = nds_read_eeprom_bitstream(nds, src, 2+6, 64, type?4:2, src_dir); 
//            ((uint64_t*)nds->mem.cart_backup)[addr]=data;
//            nds->cart.backup_is_dirty=true;
//          }else if(cnt==81){
//            // Write data 14 bit address
//            uint32_t addr = nds_read_eeprom_bitstream(nds, src, 2, 14, type?4:2, src_dir)&0x3ff;
//            uint64_t data = nds_read_eeprom_bitstream(nds, src, 2+14, 64, type?4:2, src_dir); 
//            ((uint64_t*)nds->mem.cart_backup)[addr]=data;
//            nds->cart.backup_is_dirty=true;
//          }else if(cnt==9){
//            // 2 bits "11" (Read Request)
//            // 6 bits eeprom address (MSB first)
//            // 1 bit "0"
//            // Write data 6 bit address
//            nds->mem.eeprom_addr = nds_read_eeprom_bitstream(nds, src, 2, 6, type?4:2, src_dir);
//          }else if(cnt==17){
//            // 2 bits "11" (Read Request)
//            // 14 bits eeprom address (MSB first)
//            // 1 bit "0"
//            // Write data 6 bit address
//            nds->mem.eeprom_addr = nds_read_eeprom_bitstream(nds, src, 2, 14, type?4:2, src_dir)&0x3ff;
//          }else{
//            printf("Bad cnt: %d for eeprom write\n",cnt);
//          }
//          nds->dma[i].current_transaction=cnt;
//        }
//        if(src_in_eeprom){
//          if(cnt==68){
//            uint64_t data = ((uint64_t*)nds->mem.cart_backup)[nds->mem.eeprom_addr];
//            nds_store_eeprom_bitstream(nds, dst, 4, 64, type?4:2, dst_dir,data);
//          }else{
//            printf("Bad cnt: %d for eeprom read\n",cnt);
//          }
//          nds->dma[i].current_transaction=cnt;
//        }
//      }
//      bool audio_dma = (mode==3) && (i==1||i==2);
//      if(!skip_dma){
//        // This code is complicated to handle the per channel DMA latches that are present
//        // Correct implementation is needed to pass latch.gba, Pokemon Pinball (intro explosion),
//        // and the text in Lufia
//        // TODO: There in theory should be separate latches per DMA, but that breaks Hello Kitty
//        // and Tomb Raider
//        if(nds->dma[i].current_transaction<cnt){
//          int x = nds->dma[i].current_transaction++;
//          int dst_addr = dst+x*transfer_bytes*dst_dir;
//          int src_addr = src+x*transfer_bytes*src_dir;
//          if(type){
//            if(src_addr>=0x02000000){
//              nds->dma[i].latched_transfer = nds_read32(nds,src_addr);
//              ticks+=nds_compute_access_cycles_dma(nds, src_addr, x!=0? 2:3);
//            }
//            nds_dma_write32(nds,dst_addr,nds->dma[i].latched_transfer);
//            ticks+=nds_compute_access_cycles_dma(nds, dst_addr, x!=0||force_first_write_sequential? 2:3);
//          }else{
//            int v = 0;
//            if(src_addr>=0x02000000){
//              v= nds->dma[i].latched_transfer = (nds_read16(nds,src_addr))&0xffff;
//              nds->dma[i].latched_transfer |= nds->dma[i].latched_transfer<<16;
//              ticks+=nds_compute_access_cycles_dma(nds, src_addr, x!=0? 0:1);
//            }else v = nds->dma[i].latched_transfer>>(((dst_addr)&0x3)*8);
//            nds_dma_write16(nds,dst_addr,v&0xffff);
//            ticks+=nds_compute_access_cycles_dma(nds, dst_addr, x!=0||force_first_write_sequential? 0:1);
//          }
//        }
//      }
      //
//      if(nds->dma[i].current_transaction>=cnt){
//        if(dst_addr_ctl==0||dst_addr_ctl==3)     dst+=cnt*transfer_bytes;
//        else if(dst_addr_ctl==1)dst-=cnt*transfer_bytes;
//        if(src_addr_ctl==0)     src+=cnt*transfer_bytes;
//        else if(src_addr_ctl==1)src-=cnt*transfer_bytes;
        //
//        nds->dma[i].source_addr=src;
//        nds->dma[i].dest_addr=dst;
//
//        if(irq_enable){
//          uint16_t if_bit = 1<<(GBA_INT_DMA0+i);
//          nds_send_interrupt(nds,4,if_bit);
//        }
//        if(!dma_repeat||mode==0){
//          cnt_h&=0x7fff;
//          //Reload on incr reload     
//          enable =false;
//          nds_io_store16(nds, GBA_DMA0CNT_H+12*i,cnt_h);
//        }else{
//          nds->dma[i].current_transaction=0;
//        }
//      }
//    }
//    nds->dma[i].last_enable = enable;
//    if(ticks)break;
//  }
//  nds->activate_dmas|=ticks!=0;
 //
//  if(nds->last_transaction_dma&&ticks==0){
//    ticks+=2; 
//    nds->last_transaction_dma=false;
//  }
//
//  return ticks; 
}                                              
static FORCE_INLINE void nds_tick_sio(nds_t* nds){
  //Just a stub for now;
  uint16_t siocnt = nds_io_read16(nds,GBA_SIOCNT);
  bool active = SB_BFE(siocnt,7,1);
  bool irq_enabled = SB_BFE(siocnt,14,1);
  if(active){
   
    if(irq_enabled){
      uint16_t if_bit = 1<<(GBA_INT_SERIAL);
      nds_send_interrupt(nds,4,if_bit);
    }
    siocnt&= ~(1<<7);
    nds_io_store16(nds,GBA_SIOCNT,siocnt);
  }
}
static FORCE_INLINE void nds_tick_timers(nds_t* nds){
  nds->deferred_timer_ticks+=1;
  if(nds->deferred_timer_ticks>=nds->timer_ticks_before_event)nds_compute_timers(nds); 
}
static void nds_compute_timers(nds_t* nds){

//  int ticks = nds->deferred_timer_ticks; 
//  nds->deferred_timer_ticks=0;
//  int last_timer_overflow = 0; 
//  int timer_ticks_before_event = 32768; 
//  for(int t=0;t<4;++t){ 
//    uint16_t tm_cnt_h = nds_io_read16(nds,GBA_TM0CNT_H+t*4);
//    bool enable = SB_BFE(tm_cnt_h,7,1);
//    if(enable){
//      int compensated_ticks = ticks;
//      uint16_t prescale = SB_BFE(tm_cnt_h,0,2);
//      bool count_up     = SB_BFE(tm_cnt_h,2,1)&&t!=0;
//      bool irq_en       = SB_BFE(tm_cnt_h,6,1);
//      uint16_t value = nds_io_read16(nds,GBA_TM0CNT_L+t*4);
//      if(enable!=nds->timers[t].last_enable&&enable){
//        nds->timers[t].startup_delay=2;
//        value = nds->timers[t].reload_value;
//        nds_io_store16(nds,GBA_TM0CNT_L+t*4,value);
//      }
//      if(nds->timers[t].startup_delay>=0){
//        nds->timers[t].startup_delay-=ticks; 
//        nds->timers[t].last_enable = enable;
//        if(nds->timers[t].startup_delay>=0){
//          if(nds->timers[t].startup_delay<timer_ticks_before_event)timer_ticks_before_event=nds->timers[t].startup_delay;
//          continue;
//        }
//        compensated_ticks=-nds->timers[t].startup_delay;
//        nds->timers[t].startup_delay=-1;
//        nds->timers[t].prescaler_timer=0;
//      }
//
//      if(count_up){
//        if(last_timer_overflow){
//          uint32_t v= value;
//          v+=last_timer_overflow;
//          last_timer_overflow=0;
//          while(v>0xffff){
//            v=(v+nds->timers[t].reload_value)-0x10000;
//            last_timer_overflow++;
//            nds->timers[t].elapsed_audio_samples++;
//          }
//          value=v;
//        }
//      }else{
//        last_timer_overflow=0;
//        int prescale_time = nds->timers[t].prescaler_timer;
//        prescale_time+=compensated_ticks;
//        const int prescaler_lookup[]={0,6,8,10};
//        int prescale_duty = prescaler_lookup[prescale];
//
//        int increment = prescale_time>>prescale_duty;
//        prescale_time = prescale_time&((1<<prescale_duty)-1);
//        int v = value+increment;
//        while(v>0xffff){
//          v=(v+nds->timers[t].reload_value)-0x10000;
//          last_timer_overflow++;
//          nds->timers[t].elapsed_audio_samples++;
//        }
//        value = v; 
//        nds->timers[t].prescaler_timer=prescale_time;
//        int ticks_before_overflow = (int)(0xffff-value)<<(prescale_duty);
//        if(ticks_before_overflow<timer_ticks_before_event)timer_ticks_before_event=ticks_before_overflow;
//      }
//      nds->timers[t].reload_value=nds->timers[t].pending_reload_value;
//      if(last_timer_overflow && irq_en){
//        uint16_t if_bit = 1<<(GBA_INT_TIMER0+t);
//        nds_send_interrupt(nds,4,if_bit);        
//      }
//      nds_io_store16(nds,GBA_TM0CNT_L+t*4,value);
//    }else last_timer_overflow=0;
//    nds->timers[t].last_enable = enable;
//  }
//  nds->timer_ticks_before_event=timer_ticks_before_event;
}
static FORCE_INLINE float nds_compute_vol_env_slope(int length_of_step,int dir){
  float step_time = length_of_step/64.0;
  float slope = 1./step_time;
  if(dir==0)slope*=-1;
  if(length_of_step==0)slope=0;
  return slope/16.;
} 
static FORCE_INLINE float nds_polyblep(float t,float dt){
  if(t<=dt){    
    t = t/dt;
    return t+t-t*t-1.0;;
  }else if (t >= 1-dt){
    t=(t-1.0)/dt;
    return t*t+t+t+1.0;
  }else return 0; 
}
static FORCE_INLINE float nds_bandlimited_square(float t, float duty_cycle,float dt){
  float t2 = t - duty_cycle;
  if(t2< 0.0)t2 +=1.0;
  float y = t < duty_cycle ? -1 : 1;
  y -= nds_polyblep(t,dt);
  y += nds_polyblep(t2,dt);
  return y;
}
static FORCE_INLINE void nds_send_interrupt(nds_t*nds,int delay,int if_bit){
  if(if_bit){
    nds->active_if_pipe_stages|=1<<delay;
    nds->pipelined_if[delay]|= if_bit;
  }
}
static FORCE_INLINE void nds_tick_interrupts(nds_t*nds){
  if(nds->active_if_pipe_stages){
    uint16_t if_bit = nds->pipelined_if[0];
    if(if_bit){
      uint16_t if_val = nds_io_read16(nds,GBA_IF);
      if_val |= if_bit;
      nds_io_store16(nds,GBA_IF,if_val);
    }
    nds->pipelined_if[0]=nds->pipelined_if[1];
    nds->pipelined_if[1]=nds->pipelined_if[2];
    nds->pipelined_if[2]=nds->pipelined_if[3];
    nds->pipelined_if[3]=nds->pipelined_if[4];
    nds->pipelined_if[4]=0;
    nds->active_if_pipe_stages>>=1;
  }
}
static uint8_t nds_bin_to_bcd(uint8_t bin){
  bin%=100;
  return (bin%10)|((bin/10)<<4);
}
void nds_tick_rtc(nds_t*nds){
  time_t time_secs= time(NULL);
  struct tm * tm = localtime(&time_secs);
  nds->rtc.second = nds_bin_to_bcd(tm->tm_sec);
  nds->rtc.minute = nds_bin_to_bcd(tm->tm_min);
  nds->rtc.hour  = nds_bin_to_bcd(tm->tm_hour);
  nds->rtc.day   = nds_bin_to_bcd(tm->tm_mday);
  nds->rtc.month = nds_bin_to_bcd(tm->tm_mon+1);
  nds->rtc.year  = nds_bin_to_bcd(tm->tm_year%100);
  nds->rtc.day_of_week=nds_bin_to_bcd(tm->tm_wday);
}
void nds_tick(sb_emu_state_t* emu, nds_t* nds){
  if(emu->run_mode == SB_MODE_RESET){
    nds_reset(nds);
    emu->run_mode = SB_MODE_RUN;
  }
  if(emu->run_mode == SB_MODE_STEP||emu->run_mode == SB_MODE_RUN){
    nds_tick_rtc(nds);
    nds_tick_keypad(&emu->joy,nds);
    //bool prev_vblank = nds->ppu.last_vblank; 
    //Skip emulation of a frame if we get too far ahead the audio playback
//    static int last_tick =0;
//    while(true){
//      int ticks = nds->activate_dmas? nds_tick_dma(nds,last_tick) :0;
//      if(!ticks){
//        uint16_t int_if = nds_io_read16(nds,GBA_IF);
//        if(nds->halt){
//          ticks=2;
//          if(int_if){nds->halt = false;}
//        }else{
//          nds->mem.requests=0;
//          if(int_if){
//            int_if &= nds_io_read16(nds,GBA_IE);
//            uint32_t ime = nds_io_read32(nds,GBA_IME);
//            if(SB_BFE(ime,0,1)==1){
//              nds->cpu.i_cycles=0;
//              arm7_process_interrupts(&nds->cpu, int_if);
//              ticks=nds->cpu.i_cycles;
//            }
//          }
//          if(nds->cpu.registers[PC]== emu->pc_breakpoint)nds->cpu.trigger_breakpoint=true;
//          else if(!ticks){
//            arm7_exec_instruction(&nds->cpu);
//            ticks = nds->mem.requests; 
//          }
//        }
//        if(nds->cpu.trigger_breakpoint){emu->run_mode = SB_MODE_PAUSE; nds->cpu.trigger_breakpoint=false; break;}
//      }
//      last_tick=ticks;
//      nds_tick_sio(nds);
//
//      double delta_t = ((double)ticks)/(16*1024*1024);
//
//      for(int t = 0;t<ticks;++t){
//        nds_tick_interrupts(nds);
//        nds_tick_timers(nds);
//        nds_tick_ppu(nds,emu->render_frame);
//      }
//
//      if(nds->ppu.last_vblank && !prev_vblank){
//        prev_vblank = nds->ppu.last_vblank;
//        break;
//      }
//      prev_vblank = nds->ppu.last_vblank;
//    }
  }                  
  
  if(emu->run_mode == SB_MODE_STEP) emu->run_mode = SB_MODE_PAUSE; 
}
void nds9_copy_card_region_to_ram(nds_t* nds, const char* region_name, uint32_t rom_offset, uint32_t ram_offset, uint32_t size){
  printf("Copy %s: Card[%d]-> RAM[%d] Size: %d\n",region_name,rom_offset,ram_offset,size);
  for(int i=0;i<size;++i){
    if(rom_offset+i<nds->mem.card_size) nds9_store8(nds,ram_offset+i,nds->mem.card_data[rom_offset+i]);
  }
}
void nds7_copy_card_region_to_ram(nds_t* nds, const char* region_name, uint32_t rom_offset, uint32_t ram_offset, uint32_t size){
  printf("Copy %s: Card[%d]-> RAM[%d] Size: %d\n",region_name,rom_offset,ram_offset,size);
  for(int i=0;i<size;++i){
    if(rom_offset+i<nds->mem.card_size) nds7_store8(nds,ram_offset+i,nds->mem.card_data[rom_offset+i]);
  }
}
void nds_reset(nds_t*nds){
  memset(&nds->mem,0,sizeof(nds->mem));
  for(int i=0;i<NDS_LCD_H*NDS_LCD_W;++i){
    nds->framebuffer_top[i*3]= 0;
    nds->framebuffer_top[i*3+1]= 255;
    nds->framebuffer_top[i*3+2]= 0;

    nds->framebuffer_bottom[i*3]= 0;
    nds->framebuffer_bottom[i*3+1]= 0;
    nds->framebuffer_bottom[i*3+2]= 255;
  }
  nds->arm7 = arm7_init(nds);
  nds->arm9 = arm7_init(nds);
  
  for(int bg = 2;bg<4;++bg){
    nds_io_store16(nds,GBA_BG2PA+(bg-2)*0x10,1<<8);
    nds_io_store16(nds,GBA_BG2PB+(bg-2)*0x10,0<<8);
    nds_io_store16(nds,GBA_BG2PC+(bg-2)*0x10,0<<8);
    nds_io_store16(nds,GBA_BG2PD+(bg-2)*0x10,1<<8);
  }
  //nds_store32(nds,GBA_DISPCNT,0xe92d0000);
  nds9_store16(nds,0x04000088,512);
  nds9_store32(nds,0x040000DC,0x84000000);
  nds_recompute_waitstate_table(nds,0);
  nds_recompute_mmio_mask_table(nds);
  nds->halt =false;
  nds->activate_dmas=false;
  nds->deferred_timer_ticks=0;
  bool loaded_bios= true;
  loaded_bios&= se_load_bios_file("NDS7 BIOS", nds->save_file_path, "nds7.bin", nds->mem.nds7_bios,sizeof(nds->mem.nds7_bios));
  loaded_bios&= se_load_bios_file("NDS9 BIOS", nds->save_file_path, "nds9.bin", nds->mem.nds9_bios,sizeof(nds->mem.nds9_bios));
  loaded_bios&= se_load_bios_file("NDS Firmware", nds->save_file_path, "firmware.bin", nds->mem.firmware,sizeof(nds->mem.firmware));

  if(!loaded_bios){
    printf("FATAL: Failed to load required bios\n");
  }

  //memcpy(nds->mem.bios,gba_bios_bin,sizeof(gba_bios_bin));
  const uint32_t initial_regs[37]={
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x3007f00,0x0000000,0x8000000,
    0xdf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x3007fa0,0x0,0x3007fe0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,
  };
  for(int i=0;i<37;++i)nds->arm7.registers[i]=initial_regs[i];
  for(int i=0;i<37;++i)nds->arm9.registers[i]=initial_regs[i];
  const uint32_t initial_mmio_writes[]={
    0x4000000,0x80,
    0x4000004,0x7e0000,
    0x4000020,0x100,
    0x4000024,0x1000000,
    0x4000030,0x100,
    0x4000034,0x1000000,
    0x4000080,0xe0000,
    0x4000084,0xf,
    0x4000088,0x200,
    0x4000100,0xff8a,
    0x4000130,0x3ff,
    0x4000134,0x8000,
    0x4000300,0x1,
  };
  for(int i=0;i<sizeof(initial_mmio_writes)/sizeof(uint32_t);i+=2){
    uint32_t addr=initial_mmio_writes[i+0];
    uint32_t data=initial_mmio_writes[i+1];
    arm7_write32(nds, addr,data);
  }
  nds9_store32(nds,GBA_IE,0x1);
  nds9_store16(nds,GBA_DISPCNT,0x9140);

  printf("Game Name: %s\n",nds->card.title);
  nds9_copy_card_region_to_ram(nds,"ARM9 Executable",nds->card.arm9_rom_offset,nds->card.arm9_ram_address,nds->card.arm9_size);
  nds7_copy_card_region_to_ram(nds,"ARM7 Executable",nds->card.arm7_rom_offset,nds->card.arm7_ram_address,nds->card.arm7_size);
  nds->arm9.registers[PC] = nds->card.arm9_entrypoint;
  nds->arm7.registers[PC] = nds->card.arm7_entrypoint;

}

#endif