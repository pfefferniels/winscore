// FUN_0049e4e0 @ 0049e4e0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049e4e0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  thunk_FUN_0054c419(&DAT_01e9ac60,&DAT_00763538);
  thunk_FUN_0054c419(&DAT_01e9af80,&DAT_00763538);
  DAT_01e9999c = 0;
  DAT_01e9998c = ITEM_I;
  do {
    LOAD_I = DAT_01e9998c;
    load_item_header();
    if (LOAD_STAFF <= *param_2) {
      if (LOAD_STAFF < *param_1) {
LAB_0049e804:
        if (DAT_01e9999c != 0) {
          DAT_00838a08 = 1;
          for (iVar2 = DAT_01e9999c; 0 < iVar2; iVar2 = iVar2 + -1) {
            LOAD_I = 1;
            for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
              load_item_header();
              if (((LOAD_CODE < 8) && (3 < LOAD_CODE)) &&
                 (LOAD_STAFF == (&DAT_01e9999c)[DAT_00838a08])) {
                if (ABS(LOAD_P3 - *(float *)(DAT_00838a08 * 4 + 0x1e9a2fc)) < f_0_005) {
                  (&ITEM_P3)[LOAD_W] = *(undefined4 *)(DAT_00838a08 * 4 + 0x1e99cbc);
                }
                if ((5 < LOAD_LEN) &&
                   (ABS((float)(&ITEM_P6)[LOAD_W] - *(float *)(DAT_00838a08 * 4 + 0x1e9a2fc)) <
                    f_0_005)) {
                  (&ITEM_P6)[LOAD_W] = *(undefined4 *)(DAT_00838a08 * 4 + 0x1e99cbc);
                }
              }
              LOAD_I = LOAD_I + 1;
            }
            DAT_00838a08 = DAT_00838a08 + 1;
          }
        }
        return;
      }
      if (((LOAD_CODE == 0xe) || (0x10 < LOAD_CODE)) ||
         ((LOAD_CODE < 3 && (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_64)))) {
        DAT_01e99990 = DAT_01e9998c + -1;
        DAT_01e99980 = LOAD_P3;
        DAT_01e99998 = LOAD_STAFF;
        DAT_01e99988 = LOAD_P3;
        DAT_01e99984 = f_m999;
        for (iVar2 = -DAT_01e99990 / -1; 0 < iVar2; iVar2 = iVar2 + -1) {
          LOAD_I = DAT_01e99990;
          load_item_header();
          if (DAT_01e99980 != LOAD_P3) {
            if (((LOAD_STAFF != DAT_01e99998) || (LOAD_CODE == 0xe)) || (0x10 < LOAD_CODE)) break;
            if (LOAD_CODE < 3) {
              if (DAT_01e99984 != LOAD_P3) {
                if (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_64) break;
                _DAT_00838a0c = LOAD_W;
                if (DAT_01e99984 != LOAD_P3) {
                  DAT_01e99988 = DAT_01e99988 - f_0_4;
                }
              }
              (&ITEM_P3)[LOAD_W] = DAT_01e99988;
              DAT_01e99984 = LOAD_P3;
              DAT_01e9999c = DAT_01e9999c + 1;
              *(int *)(DAT_01e9999c * 4 + 0x1e99fdc) = DAT_01e9998c;
              (&DAT_01e9999c)[DAT_01e9999c] = DAT_01e99998;
              *(float *)(DAT_01e9999c * 4 + 0x1e99cbc) = DAT_01e99988;
              *(float *)(DAT_01e9999c * 4 + 0x1e9a2fc) = LOAD_P3;
            }
          }
          DAT_01e99990 = DAT_01e99990 + -1;
        }
      }
    }
    if (DAT_01e9998c < 2) goto LAB_0049e804;
    DAT_01e9998c = DAT_01e9998c + -1;
  } while( true );
}


