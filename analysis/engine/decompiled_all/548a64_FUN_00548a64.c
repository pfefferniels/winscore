// FUN_00548a64 @ 00548a64 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548a64(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar2 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x548a8e);
  FUN_005f34d1(puVar2,0x548aa9);
  FUN_005f33c9(puVar2,0x548acb);
  FUN_005f34d1(puVar2,0x548ae6);
  FUN_005f33c9(puVar2,0x548b08);
  FUN_005f34d1(puVar2,0x548b23);
  FUN_005f33c9(puVar2,0x548b45);
  FUN_005f34d1(puVar2,0x548b60);
  FUN_005f33c9(puVar2,0x548b82);
  FUN_005f34d1(puVar2,0x548b9d);
  FUN_005f33c9(puVar2,0x548bbf);
  FUN_005f34d1(puVar2,0x548bda);
  _DAT_0099f978 = f_30;
  IP8 = 0;
  P10 = f_0;
  P5 = f_1;
  P6 = f_1;
  P48 = f_1;
  STEP = f_25;
  DAT_0099f974 = 1;
  DAT_0099f970 = 1;
  DAT_009a0380 = 1;
  *(undefined4 *)(puVar2 + -0x1c) = 6;
  DAT_0099f96c = 1;
  iVar1 = DAT_0099f970;
  do {
    DAT_0099f970 = iVar1;
    puVar3 = (undefined4 *)(DAT_0099f96c * 0xa0 + 0x9a0ab0);
    puVar4 = &DAT_0099f980;
    for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = &DAT_0099f980;
    puVar4 = (undefined4 *)(puVar2 + -0xe0);
    for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    DAT_0099f968 = FUN_005ff950(puVar2 + -0xe0,0xa0);
    FUN_005f46bc(puVar2,0x548ce9);
    FUN_005f34d1(puVar2,0x548cff);
    *(undefined1 *)((int)&DAT_009a9498 + DAT_0099f968 + DAT_0099f970 + 3) = 0x20;
    DAT_0099f970 = DAT_0099f968 + DAT_0099f970;
    DAT_0099f96c = DAT_0099f96c + 1;
    *(int *)(puVar2 + -0x1c) = *(int *)(puVar2 + -0x1c) + -1;
    iVar1 = DAT_0099f970 + 1;
  } while (0 < *(int *)(puVar2 + -0x1c));
  DAT_0099f964 = 1;
  DAT_0099f96c = 1;
  while( true ) {
    if (*(char *)((int)&DAT_009a9498 + DAT_0099f96c + 3) == ' ') {
      if (DAT_0099f970 == DAT_0099f96c) {
        *(undefined4 *)(puVar2 + -0x14) = 0;
        goto LAB_00548f00;
      }
      DAT_0099f96c = DAT_0099f96c + 1;
      while (*(char *)((int)&DAT_009a9498 + DAT_0099f96c + 3) == ' ') {
        DAT_0099f960 = DAT_0099f96c;
        for (iVar1 = (DAT_0099f970 - DAT_0099f96c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          *(undefined1 *)((int)&DAT_009a9498 + DAT_0099f960 + 3) =
               *(undefined1 *)((int)&DAT_009a9498 + DAT_0099f960 + 2);
          DAT_0099f960 = DAT_0099f960 + 1;
        }
        DAT_0099f970 = DAT_0099f970 + -1;
        *(undefined4 *)(puVar2 + -0xc) = 0;
      }
      *(undefined4 *)(puVar2 + -0x10) = 0;
      DAT_0099f974 = DAT_0099f974 + 1;
      *(int *)(DAT_0099f974 * 4 + 0x9a037c) = DAT_0099f96c;
      _DAT_0099f95c = DAT_0099f96c - *(int *)(DAT_0099f974 * 4 + 0x9a0378);
      text_parse(*(int *)(DAT_0099f974 * 4 + 0x9a0378) + 0x9a949b,1,&DAT_0099f95c);
      *(float *)(DAT_0099f974 * 4 + 0x99fba8) = P13;
    }
    else {
      *(undefined4 *)(puVar2 + -0x18) = 0;
    }
    if (DAT_0099f970 <= DAT_0099f96c) break;
    DAT_0099f96c = DAT_0099f96c + 1;
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  *(undefined4 *)(puVar2 + -8) = 0;
LAB_00548f00:
  (&DAT_009a0380)[DAT_0099f974] = DAT_0099f96c + 1;
  _DAT_0099f95c = DAT_0099f96c - *(int *)(DAT_0099f974 * 4 + 0x9a037c);
  text_parse(*(int *)(DAT_0099f974 * 4 + 0x9a037c) + 0x9a949b,1,&DAT_0099f95c);
  *(float *)(DAT_0099f974 * 4 + 0x99fbac) = P13;
  return;
}


