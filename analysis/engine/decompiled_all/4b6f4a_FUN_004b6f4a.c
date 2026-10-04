// FUN_004b6f4a @ 004b6f4a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b6f4a(int *param_1,int *param_2,undefined4 *param_3,float *param_4,int *param_5)

{
  int iVar1;
  
  DAT_01fbb860 = *param_1;
  DAT_01fbb864 = *param_2;
  DAT_01fbb868 = *param_3;
  DAT_01fbb86c = *param_4;
  DAT_01fbb870 = f_0;
  DAT_01fbb874 = 0;
  DAT_01fbb878 = 1;
  DAT_01fbb87c = ITEM_I;
  thunk_FUN_0049b1d8();
  DAT_0089f4d0 = 1;
  _DAT_01e9b5a0 = *param_3;
  DAT_01e9bd70 = f_0;
  _DAT_0089f4cc = 1;
  _DAT_0089f4c8 = (float)*param_1;
  _DAT_0089f4c4 = *param_4 - f_0_2;
  thunk_FUN_0054c419(&DAT_01e9b280,&DAT_00764838);
  DAT_0089f4c0 = *param_1;
  iVar1 = (*param_2 - DAT_0089f4c0) + 1;
  do {
    if (iVar1 < 1) {
      DAT_0089f4b0 = 1;
      if (DAT_01e9a794 - _DAT_01e9a790 <= f_0_1) {
        DAT_0089f4b0 = 2;
        DAT_0089f4d0 = DAT_0089f4d0 + -1;
      }
      FUN_004b5db0(&DAT_0089f4d0,param_3,param_4,DAT_0089f4b0 * 4 + 0x1e9a78c,
                   DAT_0089f4b0 * 4 + 0x1e99c9c,&DAT_01e9a470);
      if (*param_5 != 999) {
        draw_items();
      }
      return;
    }
    DAT_0089f4bc = 0;
    thunk_FUN_004bcd68(&DAT_0089f4cc,&DAT_0089f4bc,&DAT_0089f4c8,&STAFF_STEP0 + DAT_0089f4c0,
                       &DAT_0089f4c0,param_3,param_4,&DAT_01e99980,&DAT_01e9af60,&DAT_01e9b280,
                       &DAT_01e9c540,&DAT_01e9a470);
    if (DAT_0089f4bc != 0) {
      if (f_0_1 < *param_4 - (float)(&DAT_01e9997c)[DAT_0089f4bc]) {
        DAT_0089f4bc = DAT_0089f4bc + 1;
        (&DAT_01e9997c)[DAT_0089f4bc] = *param_4;
      }
      if (DAT_0089f4d0 == 1) {
        thunk_FUN_0054c590(&DAT_01e99980,&DAT_01e9a790,&DAT_0089f4bc);
        thunk_FUN_0054c590(&DAT_01e9af60,&DAT_01e99ca0,&DAT_0089f4bc);
        DAT_0089f4d0 = DAT_0089f4bc;
      }
      else {
        DAT_0089f4b8 = 1;
        DAT_0089f4b4 = 1;
        DAT_0089f4b0 = 1;
        while( true ) {
          DAT_0089f4ac = (float)(&DAT_01e99980)[DAT_0089f4b0];
          while (DAT_0089f4a8 = *(float *)(&DAT_01e9a790 + DAT_0089f4b4 * 4),
                f_0_1 < ABS(DAT_0089f4ac - DAT_0089f4a8)) {
            if (DAT_0089f4ac < DAT_0089f4a8) {
              FUN_004b7468(&DAT_01e9b5a0,&DAT_0089f4ac,&DAT_0089f4a8,DAT_0089f4b4 * 4 + 0x1e99c9c,
                           DAT_0089f4b0 * 4 + 0x1e9af5c,&DAT_01e9bd70,&DAT_0089f4b8);
              goto LAB_004b72ec;
            }
            FUN_004b7468(&DAT_01e9b5a0,&DAT_0089f4a8,&DAT_0089f4ac,DAT_0089f4b0 * 4 + 0x1e9af5c,
                         DAT_0089f4b4 * 4 + 0x1e99c9c,&DAT_01e9bd70,&DAT_0089f4b8);
            DAT_0089f4b4 = DAT_0089f4b4 + 1;
          }
          if (DAT_0089f4a8 < DAT_0089f4ac) {
            DAT_0089f4ac = DAT_0089f4a8;
          }
          DAT_0089f4a4 = *(float *)(DAT_0089f4b4 * 4 + 0x1e99c9c);
          if (DAT_0089f4a4 < *(float *)(DAT_0089f4b0 * 4 + 0x1e9af5c)) {
            DAT_0089f4a4 = *(float *)(DAT_0089f4b0 * 4 + 0x1e9af5c);
          }
          *(float *)(DAT_0089f4b8 * 4 + 0x1e9bd6c) = DAT_0089f4a4;
          DAT_0089f4b8 = DAT_0089f4b8 + 1;
          *(float *)(DAT_0089f4b8 * 4 + 0x1e9b59c) = DAT_0089f4ac;
          if (_DAT_0089f4c4 <= DAT_0089f4ac) break;
          DAT_0089f4b4 = DAT_0089f4b4 + 1;
LAB_004b72ec:
          DAT_0089f4b0 = DAT_0089f4b0 + 1;
        }
        thunk_FUN_0054c590(&DAT_01e9b5a0,&DAT_01e9a790,&DAT_0089f4b8);
        thunk_FUN_0054c590(&DAT_01e9bd70,&DAT_01e99ca0,&DAT_0089f4b8);
        DAT_0089f4d0 = DAT_0089f4b8;
      }
    }
    DAT_0089f4c0 = DAT_0089f4c0 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


