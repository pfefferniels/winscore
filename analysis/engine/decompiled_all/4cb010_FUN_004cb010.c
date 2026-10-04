// FUN_004cb010 @ 004cb010 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004cb010(int *param_1,int *param_2)

{
  int iVar1;
  
  LOAD_I = 1;
  iVar1 = ITEM_I;
  while ((0 < iVar1 && (load_item_header(), LOAD_STAFF <= *param_2))) {
    if ((LOAD_CODE < 0x11) &&
       ((((LOAD_CODE != 0xe && (LOAD_CODE != 8)) && (3 < LOAD_CODE)) && (*param_1 <= LOAD_STAFF))))
    {
      DAT_01add2e8 = LOAD_W + 3;
      FUN_004cb2ea();
      if ((LOAD_CODE < 8) && (5 < LOAD_LEN)) {
        if ((LOAD_CODE != 6) || (f_0 <= *(float *)(&ITEM_P7 + LOAD_W * 4))) {
          DAT_01add2e8 = LOAD_W + 6;
          LOAD_P3 = (float)(&ITEM_LEN)[DAT_01add2e8];
          FUN_004cb2ea();
        }
        if ((LOAD_CODE == 6) && (10 < LOAD_LEN)) {
          DAT_01add2e8 = LOAD_W + 0xb;
          LOAD_P3 = (float)(&ITEM_LEN)[DAT_01add2e8];
          if (f_0 < LOAD_P3) {
            FUN_004cb2ea();
          }
          if ((0xb < LOAD_LEN) && (f_0 < *(float *)(&ITEM_P7 + LOAD_W * 4))) {
            DAT_01add2e8 = LOAD_W + 0xc;
            LOAD_P3 = (float)(&ITEM_LEN)[DAT_01add2e8];
            if (f_0 < LOAD_P3) {
              FUN_004cb2ea();
            }
            if ((0xd < LOAD_LEN) && ((float)(&ITEM_P13)[LOAD_W] != f_0)) {
              DAT_01add2e8 = LOAD_W + 0xe;
              LOAD_P3 = (float)(&ITEM_LEN)[DAT_01add2e8];
              if (f_0 < LOAD_P3) {
                FUN_004cb2ea();
              }
              if (0xe < LOAD_LEN) {
                DAT_01add2e8 = LOAD_W + 0xf;
                LOAD_P3 = (float)(&ITEM_LEN)[DAT_01add2e8];
                if (f_0 < LOAD_P3) {
                  FUN_004cb2ea();
                }
              }
            }
          }
        }
      }
    }
    LOAD_I = LOAD_I + 1;
    iVar1 = iVar1 + -1;
  }
  return;
}


