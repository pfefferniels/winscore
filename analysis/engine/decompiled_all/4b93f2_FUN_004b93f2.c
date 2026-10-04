// FUN_004b93f2 @ 004b93f2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b93f2(void)

{
  int iVar1;
  
  DAT_0089f63c = 999;
  DAT_0089f638 = -999;
  LOAD_I = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((LOAD_CODE < 3) && (6 < LOAD_LEN)) && (f_0 < *(float *)(&ITEM_P7 + LOAD_W * 4))) {
      if (LOAD_STAFF < DAT_0089f63c) {
        DAT_0089f63c = LOAD_STAFF;
      }
      if (DAT_0089f638 < LOAD_STAFF) {
        DAT_0089f638 = LOAD_STAFF;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  FUN_005f34d1(&stack0xfffffffc,0x4b94ed);
  thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00764980,&DAT_00764984,"(1i3)",5,&DAT_0089f63c);
  thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00764978,&DAT_0076497c,"(1i3)",5,&DAT_0089f638);
  return;
}


