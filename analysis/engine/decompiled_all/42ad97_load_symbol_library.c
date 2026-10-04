// load_symbol_library @ 0042ad97 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void load_symbol_library(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  short *psVar4;
  short *psVar5;
  bool bVar6;
  undefined4 local_7c;
  char *local_78;
  undefined4 local_74;
  undefined4 local_68 [25];
  
  puVar3 = &stack0xfffffffc;
  local_68[0] = 0;
  local_7c = 3;
  local_78 = s_0000_drw_0078ed6e;
  local_74 = param_1;
  FUN_005f34f0(local_68,0x784ff00,&DAT_0075fce0,&local_7c,&DAT_0078e9f4);
  FUN_005f46bc(&stack0xfffffffc,0x42ae16);
  FUN_005f46bc(puVar3,0x42ae32);
  FUN_005f46bc(puVar3,0x42ae4e);
  FUN_005f34d1(puVar3,0x42ae64);
  *(undefined4 *)(puVar3 + -100) = 0;
  FUN_005f7950(puVar3 + -100,9,0x784ff00,&DAT_0075fc3c,0);
  *(undefined4 *)(puVar3 + -100) = 0;
  *(undefined4 *)(puVar3 + -0x88) = 0x80;
  *(undefined4 **)(puVar3 + -0x84) = &DAT_01cf8f44;
  *(undefined4 *)(puVar3 + -0x80) = 3;
  *(undefined **)(puVar3 + -0x7c) = &DAT_0075fcdc;
  *(undefined4 *)(puVar3 + -0x78) = 6;
  *(char **)(puVar3 + -0x74) = "binary";
  *(undefined4 *)(puVar3 + -0x70) = 2;
  uVar1 = FUN_005f6540(puVar3 + -100,9,0x784ff01,&DAT_0075fcc0,puVar3 + -0x88);
  *(undefined4 *)(puVar3 + -0x3c) = uVar1;
  if (*(int *)(puVar3 + -0x3c) == 0) {
    *(undefined4 *)(puVar3 + -100) = 0;
    *(undefined4 *)(puVar3 + -0x70) = 0x16;
    *(undefined4 *)(puVar3 + -0x6c) = *(undefined4 *)(puVar3 + 0xc);
    uVar1 = FUN_005f8240(puVar3 + -100,9,0x784ff01,&DAT_0075fcbc,puVar3 + -0x70);
    *(undefined4 *)(puVar3 + -0x38) = uVar1;
    if (*(int *)(puVar3 + -0x38) == 0) {
      *(undefined4 *)(puVar3 + -100) = 0;
      *(undefined4 *)(puVar3 + -0x78) = 0xf0;
      *(undefined4 *)(puVar3 + -0x74) = *(undefined4 *)(puVar3 + 0x10);
      *(undefined4 *)(puVar3 + -0x70) = 0x18;
      FUN_005f8240(puVar3 + -100,9,0x784ff00,&DAT_0075fcb8,puVar3 + -0x78);
      DAT_007ec328 = *(short *)(*(int *)(puVar3 + 0xc) + 0x14) + -1;
      iVar2 = DAT_007ec328;
      if (DAT_007ec328 < 0) {
        iVar2 = 0;
      }
      DAT_007ec324 = iVar2 + 1;
      *(undefined4 *)(puVar3 + -100) = 0;
      *(undefined4 *)(puVar3 + -0x80) = 1;
      *(undefined4 **)(puVar3 + -0x7c) = &DAT_01dc4200;
      *(undefined4 *)(puVar3 + -0x78) = 1;
      *(int *)(puVar3 + -0x74) = iVar2;
      *(undefined4 *)(puVar3 + -0x70) = 4;
      uVar1 = FUN_005f8240(puVar3 + -100,9,0x784ff01,&DAT_0075fcb4,puVar3 + -0x80);
      *(undefined4 *)(puVar3 + -0x30) = uVar1;
      if (*(int *)(puVar3 + -0x30) == 0) {
        iVar2 = DAT_007ec328;
        if (DAT_007ec328 < 0) {
          iVar2 = 0;
        }
        DAT_007ec324 = iVar2 + 1;
        *(undefined4 *)(puVar3 + -100) = 0;
        *(undefined4 *)(puVar3 + -0x80) = 1;
        *(undefined4 **)(puVar3 + -0x7c) = &DAT_01e12400;
        *(undefined4 *)(puVar3 + -0x78) = 1;
        *(int *)(puVar3 + -0x74) = iVar2;
        *(undefined4 *)(puVar3 + -0x70) = 4;
        uVar1 = FUN_005f8240(puVar3 + -100,9,0x784ff01,&DAT_0075fcb4,puVar3 + -0x80);
        *(undefined4 *)(puVar3 + -0x2c) = uVar1;
        if (*(int *)(puVar3 + -0x2c) == 0) {
          iVar2 = DAT_007ec328;
          if (DAT_007ec328 < 0) {
            iVar2 = 0;
          }
          DAT_007ec324 = iVar2 + 1;
          *(undefined4 *)(puVar3 + -100) = 0;
          *(undefined4 *)(puVar3 + -0x80) = 1;
          *(undefined2 **)(puVar3 + -0x7c) = &DAT_01d9d100;
          *(undefined4 *)(puVar3 + -0x78) = 1;
          *(int *)(puVar3 + -0x74) = iVar2;
          *(undefined4 *)(puVar3 + -0x70) = 2;
          uVar1 = FUN_005f8240(puVar3 + -100,9,0x784ff01,&DAT_0075fcb0,puVar3 + -0x80);
          *(undefined4 *)(puVar3 + -0x28) = uVar1;
          if (*(int *)(puVar3 + -0x28) == 0) {
            *(undefined4 *)(puVar3 + -100) = 0;
            FUN_005f7950(puVar3 + -100,9,0x784ff00,&DAT_0075fc3c,0);
            **(undefined2 **)(puVar3 + 0xc) = 1;
            *(undefined4 *)(puVar3 + -0x20) = 0;
            return;
          }
        }
      }
    }
  }
  if ((IP1 == 1) || (IP1 == 9)) {
    *(undefined4 *)(puVar3 + -0x18) = 0;
    if (DAT_007ec320 != 0) {
      *(undefined4 *)(puVar3 + -8) = 0;
      return;
    }
    FUN_005f33c9(puVar3,0x42b1d9);
    FUN_005f33c9(puVar3,0x42b1f5);
    FUN_005f34d1(puVar3,0x42b210);
    bVar6 = &stack0x00000000 == (undefined1 *)0x9c;
    iVar2 = 5;
    psVar4 = &DAT_0078ed6c;
    psVar5 = (short *)0x75fc90;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *psVar4 == *psVar5;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      DAT_007ec31c = thunk_FUN_0059b090();
      if (DAT_007ec31c == 0) {
        return;
      }
      DAT_007ec320 = 1;
      return;
    }
    *(undefined4 *)(puVar3 + -4) = 0;
  }
  else {
    *(undefined4 *)(puVar3 + -0x1c) = 0;
  }
  FUN_005f33c9(puVar3,0x42b253);
  FUN_005f33c9(puVar3,0x42b26f);
  FUN_005f33c9(puVar3,0x42b28b);
  FUN_005f34d1(puVar3,0x42b2a6);
  FUN_0042ac4e(&DAT_009ae2bc,0x200);
  *(undefined4 *)(puVar3 + -0xc) = 0;
  return;
}


