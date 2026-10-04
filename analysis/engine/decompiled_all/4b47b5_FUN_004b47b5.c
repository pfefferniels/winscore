// FUN_004b47b5 @ 004b47b5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b47b5(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined2 in_FPUControlWord;
  
  puVar2 = &stack0xfffffffc;
  DAT_0089f3d8 = 1;
  iVar1 = ITEM_I;
  while (0 < iVar1) {
    LOAD_I = DAT_0089f3d8;
    load_item_header();
    if (LOAD_CODE == 0x10) {
      _DAT_0089f3d4 = *(float *)(&ITEM_P11 + LOAD_W * 4);
      if (_DAT_0089f3d4 <= f_m98) {
        thunk_FUN_0054c590(&ITEM_P1 + LOAD_W,&P1,&DAT_00764678);
        *(undefined2 *)(puVar2 + -0x3c) = in_FPUControlWord;
        *(ushort *)(puVar2 + -0x3a) = (ushort)*(undefined4 *)(puVar2 + -0x3c) | 0xc00;
        *(int *)(puVar2 + -0x38) = (int)ROUND(P12);
        in_FPUControlWord = *(undefined2 *)(puVar2 + -0x3c);
        IP12 = *(int *)(puVar2 + -0x38);
        for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
          *(undefined4 *)(&DAT_020b943c + iVar1 * 4) = *(undefined4 *)(&P0 + iVar1 * 4);
        }
        FUN_005f33c9(puVar2,0x4b48cb);
        FUN_005f34d1(puVar2,0x4b48e6);
        DAT_0078b4e4 = 0x4e;
        _DAT_0089f3d0 = ITEM_I;
        if (_DAT_0089f3d4 == f_m98) {
          DAT_020b8ea2 = DAT_00764670;
        }
        else {
          *(undefined4 *)(puVar2 + -8) = 0;
        }
        EDIT_ITEM = DAT_0089f3d8;
        DAT_0089f3cc = LOAD_W;
        edit_letters();
        DAT_020b9448 = P2;
        DAT_020b9468 = P4;
        EDIT_ITEM = 0;
        (&ITEM_P3)[DAT_0089f3cc] = P2;
        *(float *)(&ITEM_P11 + DAT_0089f3cc * 4) = P4;
        for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
          *(float *)(&P0 + iVar1 * 4) = f_0;
        }
        FUN_005f34d1(puVar2,0x4b49cf);
      }
      else {
        *(undefined4 *)(puVar2 + -0xc) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar2 + -0x10) = 0;
    }
    *(undefined4 *)(puVar2 + -4) = 0;
    DAT_0089f3d8 = DAT_0089f3d8 + 1;
    *(int *)(puVar2 + -0x14) = *(int *)(puVar2 + -0x14) + -1;
    iVar1 = *(int *)(puVar2 + -0x14);
  }
  return;
}


