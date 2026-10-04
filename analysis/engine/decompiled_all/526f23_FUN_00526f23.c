// FUN_00526f23 @ 00526f23 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00526fc1) */
/* WARNING: Removing unreachable block (ram,0x005271b2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00526f23(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  DAT_0094eac0 = 0;
  FUN_005f34d1(&stack0xfffffffc,0x526f51);
  *(undefined4 *)(puVar5 + -0x24) = 0x3c;
  DAT_0094eabc = 0x3c;
  do {
    if (*(char *)((int)&DAT_007cb2cc + DAT_0094eabc + 3) == ']') {
      *(undefined4 *)(puVar5 + -0x20) = 0;
      break;
    }
    DAT_0094eabc = DAT_0094eabc + -1;
    *(int *)(puVar5 + -0x24) = *(int *)(puVar5 + -0x24) + -1;
  } while (0 < *(int *)(puVar5 + -0x24));
  FUN_005f46bc(puVar5,0x526fe3);
  FUN_005f34d1(puVar5,0x526ff9);
  DAT_0094eab8 = DAT_0094eabc;
  iVar4 = -DAT_0094eabc / -1;
  *(int *)(puVar5 + -0x1c) = iVar4;
  do {
    if (iVar4 < 1) {
      FUN_005f46bc(puVar5,0x5271d4);
      FUN_005f34d1(puVar5,0x5271ea);
      thunk_FUN_0054c5f8(&DAT_020b90a0,1,&DAT_007cb2d2,1,&DAT_00767ecc);
      if (*(char *)((int)&DAT_020b8ea0 + **(int **)(puVar5 + 8) + 1) == '$') {
        FUN_00527276(*(undefined4 *)(puVar5 + 8));
      }
      return;
    }
    if ((*(char *)((int)&DAT_007cb2cc + DAT_0094eab8 + 3) == '/') ||
       (*(char *)((int)&DAT_007cb2cc + DAT_0094eab8 + 3) == '[')) {
      DAT_0094eab0 = DAT_0094eab8 + 1;
      iVar4 = 0x3d - DAT_0094eab0;
      DAT_0094eab4 = DAT_0094eab0;
      *(int *)(puVar5 + -0x14) = iVar4;
      iVar2 = DAT_0094eac0;
      while (DAT_0094eac0 = iVar2, 0 < iVar4) {
        DAT_0094eac0 = iVar2 + 1;
        cVar1 = *(char *)((int)&DAT_007cb2cc + DAT_0094eab0 + 3);
        uVar3 = _DAT_0094eac8 >> 8;
        if (cVar1 == '\'') {
          cVar1 = DAT_00767ed4;
        }
        if (cVar1 == ']') {
          cVar1 = DAT_00767ed0;
        }
        _DAT_0094eac8 = CONCAT31((int3)uVar3,cVar1);
        (&DAT_020b90a0)[iVar2] = cVar1;
        if (((_DAT_0094eac8 & 0xff) == 0x2f) || ((_DAT_0094eac8 & 0xff) == 0x3a)) {
          if ((_DAT_0094eac8 & 0xff) != 0x3a) {
            *(undefined4 *)(puVar5 + -0xc) = 0;
            break;
          }
        }
        else {
          *(undefined4 *)(puVar5 + -0x10) = 0;
        }
        *(undefined4 *)(puVar5 + -8) = 0;
        DAT_0094eab0 = DAT_0094eab0 + 1;
        *(int *)(puVar5 + -0x14) = *(int *)(puVar5 + -0x14) + -1;
        iVar2 = DAT_0094eac0;
        iVar4 = *(int *)(puVar5 + -0x14);
      }
    }
    else {
      *(undefined4 *)(puVar5 + -0x18) = 0;
    }
    *(undefined4 *)(puVar5 + -4) = 0;
    DAT_0094eab8 = DAT_0094eab8 + -1;
    *(int *)(puVar5 + -0x1c) = *(int *)(puVar5 + -0x1c) + -1;
    iVar4 = *(int *)(puVar5 + -0x1c);
  } while( true );
}


