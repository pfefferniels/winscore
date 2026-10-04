// FUN_004385a7 @ 004385a7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004385a7(void)

{
  int iVar1;
  float10 fVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  DAT_007f7674 = (int)ROUND((float)(&ITEM_LEN)[(&ITEM_PTR0)[EDIT_ITEM]]);
  DAT_007f7670 = 0;
  DAT_007f766c = (int)ROUND(DAT_020b9444);
  _DAT_007f7668 = DAT_020b9448;
  DAT_007f7664 = P2;
  if (P2 == f_0) {
    if ((DAT_007f7674 < 7) || (DAT_020b9458 < f_0)) goto LAB_00438989;
    DAT_007f7664 = DAT_020b9458;
  }
  _DAT_007f7660 = DAT_020b944c;
  _DAT_007f765c = DAT_020b9454;
  fVar2 = (float10)amod(&DAT_020b9450,&f_100);
  DAT_007f7658 = (int)ROUND(fVar2) / 10;
  if ((4 < DAT_007f7674) && (DAT_020b9454 == f_2 || DAT_007f7658 != 0)) {
    if (DAT_020b9454 == f_2) {
      DAT_007f7658 = 0;
    }
    LOAD_I = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      load_item_header();
      if ((((_DAT_007f7668 != LOAD_P3) || (LOAD_CODE != 1)) || (LOAD_STAFF != DAT_007f766c)) ||
         (5 < LOAD_LEN && _DAT_007f765c != (float)(&ITEM_P6)[LOAD_W])) goto LAB_00438893;
      if (DAT_007f7658 == 0) {
LAB_00438847:
        if (LOAD_LEN < 7) {
          thunk_FUN_005239c9(&LOAD_I,&f_7);
        }
        *(float *)(&ITEM_P7 + LOAD_W * 4) = DAT_007f7664;
        DAT_007f7670 = 1;
      }
      else if ((DAT_007f7658 == 1) || (DAT_007f7658 != 2)) {
        if (_DAT_007f7660 <= (float)(&ITEM_P4)[LOAD_W]) goto LAB_00438847;
      }
      else if ((float)(&ITEM_P4)[LOAD_W] <= _DAT_007f7660) goto LAB_00438847;
LAB_00438893:
      LOAD_I = LOAD_I + 1;
    }
    if (DAT_007f7670 != 0) {
      DAT_020b9458 = DAT_007f7664;
      FUN_005f33c9(&stack0xfffffffc,0x4388fb);
      FUN_005f34d1(puVar3,0x438916);
      *(undefined4 *)(puVar3 + -0x54) = 0;
      *(undefined4 *)(puVar3 + -0x68) = 7;
      *(undefined4 *)(puVar3 + -100) = 0x20b8ec3;
      *(float **)(puVar3 + -0x60) = &DAT_007f7664;
      FUN_005f34f0(puVar3 + -0x54,0x784ff00,&DAT_007603e8,puVar3 + -0x68,&DAT_0078f398);
      thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
      *(undefined4 *)(puVar3 + -4) = 0;
      return;
    }
  }
LAB_00438989:
  thunk_FUN_0054d831("*** no rhythm changes made ***",0x1f);
  return;
}


