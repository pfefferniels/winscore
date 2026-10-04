// FUN_00554a38 @ 00554a38 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00554a38(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined2 in_FPUControlWord;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  DAT_009a396c = -99;
  DAT_009a3964 = thunk_FUN_0059a110(&DAT_009a396c);
  P1 = (float)DAT_009a396c;
  DAT_009a3960 = DAT_009a396c;
  if ((DAT_009a3964 == 2) || (DAT_009a396c < 0)) {
    P1 = f_m1;
  }
  else {
    FUN_005f34d1(&stack0xfffffffc,0x554abf);
    FUN_005f46bc(puVar3,0x554af4);
    FUN_005f46bc(puVar3,0x554b10);
    FUN_005f34d1(puVar3,0x554b26);
    *(undefined4 *)(puVar3 + -0x40) = 0;
    *(undefined4 *)(puVar3 + -0x50) = 0x80;
    *(undefined2 **)(puVar3 + -0x4c) = &DAT_020b8ea0;
    *(undefined4 *)(puVar3 + -0x48) = 2;
    *(undefined4 *)(puVar3 + -0x44) = 4;
    uVar2 = FUN_005f6540(puVar3 + -0x40,0x11,0x784ff01,&DAT_007698ec,puVar3 + -0x50);
    *(undefined4 *)(puVar3 + -0x1c) = uVar2;
    fVar1 = P1;
    if (*(int *)(puVar3 + -0x1c) == 0) {
      DAT_009a3968 = 0;
      *(undefined2 *)(puVar3 + -0x48) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x46) = (ushort)*(undefined4 *)(puVar3 + -0x48) | 0xc00;
      *(int *)(puVar3 + -0x44) = (int)ROUND(fVar1);
      _DAT_009a395c = *(undefined4 *)(puVar3 + -0x44);
      while( true ) {
        *(undefined4 *)(puVar3 + -0x40) = 0;
        *(undefined4 *)(puVar3 + -0x48) = 0x200;
        *(undefined2 **)(puVar3 + -0x44) = &DAT_020b8ea0;
        uVar2 = FUN_005fdbd0(puVar3 + -0x40,0x11,0x784ff03,&DAT_007698e8,puVar3 + -0x48,
                             &DAT_0079ec48);
        *(undefined4 *)(puVar3 + -0x18) = uVar2;
        if (*(int *)(puVar3 + -0x18) == -1) break;
        if (*(int *)(puVar3 + -0x18) != 0) goto LAB_00554cc2;
        if (DAT_009a3960 == DAT_009a3968) {
          *(undefined4 *)(puVar3 + -0x14) = 0;
          break;
        }
        DAT_009a3968 = DAT_009a3968 + 1;
        *(undefined4 *)(puVar3 + -0x10) = 0;
      }
      *(undefined4 *)(puVar3 + -0x40) = 0;
      *(undefined4 *)(puVar3 + -0x50) = 4;
      *(undefined2 **)(puVar3 + -0x4c) = &DAT_020b8ea0;
      *(undefined **)(puVar3 + -0x48) = &DAT_009a3958;
      FUN_005f9240(puVar3 + -0x40,0x784ff00,&DAT_007698e0,puVar3 + -0x50,&DAT_0079ec5c);
      P1 = (float)_DAT_009a3958;
      *(undefined4 *)(puVar3 + -0x40) = 0;
      FUN_005f7950(puVar3 + -0x40,0x11,0x784ff00,&DAT_007698dc,0);
      *(undefined4 *)(puVar3 + -4) = 0;
    }
    else {
LAB_00554cc2:
      FUN_005f33c9(puVar3,0x554ce0);
      FUN_005f34d1(puVar3,0x554cfb);
      thunk_FUN_0042ac4e(&DAT_020b90a0,0x7f);
    }
  }
  return;
}


