// FUN_0041f35d @ 0041f35d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f35d(int *param_1)

{
  int iVar1;
  
  DAT_007abac8 = 0;
  DAT_007d1df0 = DAT_00794850;
  if (DAT_007cc600 == 0) {
    DAT_007cc600 = 1;
  }
  if (((&DAT_020b8e9f)[DAT_007cc600] == '/') || ((&DAT_020b8e9f)[DAT_007cc600] == ':')) {
    DAT_007d1dec = DAT_007cc600;
    DAT_007cc600 = DAT_007cc600 + -1;
    for (iVar1 = -DAT_007cc600 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (((&DAT_020b8e9f)[DAT_007cc600] == '/') || ((&DAT_020b8e9f)[DAT_007cc600] == ':')) {
        DAT_007cdda0 = DAT_007cdda0 + -1;
        DAT_01fb9634 = *(undefined4 *)(&DAT_007ce0c0 + DAT_007cdda0 * 4);
        DAT_00794850 = *(undefined4 *)(&DAT_007ce700 + DAT_007cdda0 * 4);
        ITEM_I = *(int *)(&DAT_007ce3e0 + DAT_007cdda0 * 4);
        DAT_00794830 = *(undefined4 *)(&DAT_007ced40 + DAT_007cdda0 * 4);
        _DAT_007d1de8 = *(undefined4 *)(&DAT_007cea20 + DAT_007cdda0 * 4);
        DAT_0079484c = *(undefined4 *)(&DAT_007cf060 + DAT_007cdda0 * 4);
        DAT_00794840 = *(undefined4 *)(&DAT_007cf380 + DAT_007cdda0 * 4);
        DAT_007abacc = *(undefined4 *)(&DAT_007cf6a0 + DAT_007cdda0 * 4);
        DAT_007cbfa0 = (&DAT_007cbfa0)[DAT_007cdda0];
        DAT_0078cae4 = *(undefined4 *)(&DAT_007cf9c0 + DAT_007cdda0 * 4);
        goto LAB_0041f587;
      }
      DAT_007cc600 = DAT_007cc600 + -1;
    }
    DAT_007cc600 = 0;
    ITEM_I = *param_1;
    DAT_007cdda0 = 0;
    DAT_00794830 = 0;
LAB_0041f587:
    ITEM_WORDS = (&DAT_02091d20)[ITEM_I];
    VEC_N = (&DAT_02035a00)[ITEM_I];
    DAT_007cc604 = DAT_007cc600 + 1;
    *DAT_01fbb7c0 = VEC_N + -1;
    DAT_007d1de4 = DAT_007cc600;
    if (DAT_007cc600 == 0) {
      DAT_007d1de4 = 1;
      FUN_005f34d1(&stack0xfffffffc,0x41f613);
      DAT_00794850 = DAT_007d1df0;
    }
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007d1de4);
    thunk_FUN_00549422();
  }
  else {
    (&DAT_020b8e9f)[DAT_007cc600] = 0x20;
    DAT_007cc600 = DAT_007cc600 + -1;
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
  }
  return;
}


