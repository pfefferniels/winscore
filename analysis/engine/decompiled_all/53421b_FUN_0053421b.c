// FUN_0053421b @ 0053421b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053421b(void)

{
  int iVar1;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_44 [10];
  undefined4 local_1c;
  undefined4 local_14;
  
  DAT_0078cd44 = DAT_01eae1b0;
  if (DAT_01eae1b0 < 100) {
    DAT_01a1c800 = 1;
    for (iVar1 = DAT_01eae1b0; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (DAT_01a1c80c == *(int *)(&DAT_01eae00c + DAT_01a1c800 * 4)) {
        return;
      }
      DAT_01a1c800 = DAT_01a1c800 + 1;
    }
    DAT_01a1c800 = 1;
    for (iVar1 = DAT_01a1c814; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (DAT_01a1c80c == (&DAT_01caea3c)[DAT_01a1c800]) {
        local_1c = 0;
        IP1 = 9;
        IP10 = 0;
        IP11 = 0;
        NPT = 1;
        _DAT_01a1c824 = f_6_25;
        if (0x31 < DAT_01a1c80c) {
          _DAT_01a1c824 = f_7_5;
        }
        draw_symbol(&i_0,&i_0,&DAT_01a1c80c,&DAT_01a1c824,&DAT_01a1c824,&DAT_00768860,&i_0,
                    &DAT_00768860);
        DAT_0078b6bc = 0xffffffff;
        P1 = (float)i_0;
        DAT_0078dc64 = NPT + DAT_0078dc64;
        if (DAT_0078dc64 < DAT_0078dc68) {
          local_14 = 0;
          DAT_0078cd44 = DAT_0078cd44 + 1;
          *(int *)(&DAT_01eae00c + DAT_0078cd44 * 4) = DAT_01a1c80c;
          DAT_01eae1b0 = DAT_0078cd44;
          FUN_00534859();
          local_44[0] = 0;
          local_4c = 3;
          local_48 = &DAT_0078cd50;
          FUN_005fc330(local_44,0x18,0x784ff00,&DAT_0076885c,&local_4c,&DAT_007971d0);
          IP2 = 0;
          thunk_FUN_004d3ff3();
          local_44[0] = 0;
          FUN_005fc330(local_44,0x18,0x784ff00,&DAT_00768858,0,&DAT_00797244);
          return;
        }
        DAT_0078b6bc = 0xffffffff;
        DAT_0078dc64 = DAT_0078dc64 - NPT;
        P1 = (float)i_0;
        return;
      }
      DAT_01a1c800 = DAT_01a1c800 + 1;
    }
    DAT_01a1c814 = DAT_01a1c814 + 1;
    (&DAT_01caea3c)[DAT_01a1c814] = DAT_01a1c80c;
  }
  return;
}


