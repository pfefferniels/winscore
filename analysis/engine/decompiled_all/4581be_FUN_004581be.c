// FUN_004581be @ 004581be (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004581be(int *param_1)

{
  int iVar1;
  int local_3c [10];
  undefined4 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_01c0c1a0 = 0;
  local_3c[0] = DAT_01c0c260 * 3;
  thunk_FUN_0054c4c6(&DAT_01c0c264,&DAT_01c00604,local_3c);
  DAT_01c00600 = DAT_01c0c260;
  DAT_007fecec = 0;
  _DAT_007fece8 = 1;
  DAT_007fece4 = 0;
  do {
    DAT_01c0c1a0 = DAT_01c0c1a0 + 1;
    DAT_007fece0 = DAT_007fecec + 1;
    DAT_007fecdc = 1;
    iVar1 = FUN_00458001(&DAT_007fece8,&DAT_007fecd8,&DAT_007fece4,&DAT_007fecdc,param_1);
    if (iVar1 == 0) {
      thunk_FUN_0054946a("*** Can\'t locate curve markers",0x1f);
      return;
    }
    local_14 = 0;
    _DAT_007fecd0 = (int)*(short *)((int)&DAT_01fbb8dc + DAT_007fecdc * 2 + 2);
    DAT_007fecd4 = DAT_007fecdc;
    DAT_007fecec = DAT_007fece0;
    for (iVar1 = (DAT_01c00600 - DAT_007fece0) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&PT_X0)[DAT_007fecdc] = *(undefined4 *)(DAT_007fecec * 0xc + 0x1c005f8);
      (&PT_Y0)[DAT_007fecdc] = *(undefined4 *)(DAT_007fecec * 0xc + 0x1c005fc);
      *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fecdc * 2 + 2) = 0;
      if ((&DAT_01c0060c)[DAT_007fecec * 3] != 0) {
        local_c = 0;
        break;
      }
      if (DAT_01c00600 != DAT_007fecec) {
        DAT_007fecdc = DAT_007fecdc + 1;
      }
      DAT_007fecec = DAT_007fecec + 1;
    }
    *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fecd4 * 2 + 2) = DAT_007fecd0;
    *(int *)(DAT_01c0c1a0 * 8 + 0x1c0c19c) = DAT_007fecd4;
    (&DAT_01c0c1a0)[DAT_01c0c1a0 * 2] = DAT_007fecdc;
    DAT_007feccc = *param_1 - DAT_007fecd8;
    if (DAT_007feccc != 0) {
      thunk_FUN_0054c4c6(&DAT_01fd3f80 + DAT_007fecd8,&DAT_01fd3f80 + DAT_007fecdc,&DAT_007feccc);
      thunk_FUN_0054c4c6(&DAT_02004cc0 + DAT_007fecd8,&DAT_02004cc0 + DAT_007fecdc,&DAT_007feccc);
      thunk_FUN_0054c4c6(&DAT_01fbb8e0 + DAT_007fecd8,&DAT_01fbb8e0 + DAT_007fecdc,&DAT_007feccc);
    }
    *param_1 = DAT_007fecdc + DAT_007feccc;
    if (DAT_01c00600 <= DAT_007fecec) {
      DAT_01c0c260 = DAT_007fece4;
      FUN_00457e7f(&DAT_0076139c);
      FUN_004584ba();
      return;
    }
    local_8 = 0;
  } while( true );
}


