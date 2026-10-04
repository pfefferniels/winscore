// FUN_0054dc2b @ 0054dc2b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0054dc2b(void)

{
  undefined2 in_FPUControlWord;
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x54dc4f);
  FUN_005f34d1(puVar1,0x54dc6a);
  thunk_FUN_00518448();
  *(undefined2 *)(puVar1 + -100) = in_FPUControlWord;
  *(ushort *)(puVar1 + -0x62) = (ushort)*(undefined4 *)(puVar1 + -100) | 0xc00;
  *(int *)(puVar1 + -0x60) = (int)ROUND(P2);
  DAT_009a2ab8 = *(int *)(puVar1 + -0x60);
  *(int *)(puVar1 + -0x60) = DAT_01be6d60 * 100;
  P1 = (float)*(int *)(puVar1 + -0x60);
  P3 = f_0;
  DAT_020b8ea0._0_1_ = DAT_00769150;
  switch(DAT_009a2ab8) {
  default:
    P1 = (float)DAT_01be6d60;
    P2 = f_0;
    if (DAT_009a2ab8 == -9) {
      P2 = f_m9999;
    }
    *(undefined4 *)(puVar1 + -0x3c) = 0;
    break;
  case 1:
    P2 = f_m0_1;
    *(undefined4 *)(puVar1 + -0x38) = 0;
    break;
  case 2:
    P2 = f_m0_5;
    *(undefined4 *)(puVar1 + -0x34) = 0;
    break;
  case 3:
    P2 = f_m1;
    *(undefined4 *)(puVar1 + -0x30) = 0;
    break;
  case 4:
    P2 = f_m5;
    *(undefined4 *)(puVar1 + -0x2c) = 0;
    break;
  case 5:
    P2 = f_m10;
    *(undefined4 *)(puVar1 + -0x28) = 0;
    break;
  case 6:
    P2 = f_m20;
    *(undefined4 *)(puVar1 + -0x24) = 0;
    break;
  case 7:
    P2 = f_0_1;
    *(undefined4 *)(puVar1 + -0x20) = 0;
    break;
  case 8:
    P2 = f_0_5;
    *(undefined4 *)(puVar1 + -0x1c) = 0;
    break;
  case 9:
    P2 = f_1;
    *(undefined4 *)(puVar1 + -0x18) = 0;
    break;
  case 10:
    P2 = f_5;
    *(undefined4 *)(puVar1 + -0x14) = 0;
    break;
  case 0xb:
    P2 = f_10;
    *(undefined4 *)(puVar1 + -0x10) = 0;
    break;
  case 0xc:
    P2 = f_20;
    *(undefined4 *)(puVar1 + -0xc) = 0;
    break;
  case 0xd:
    P2 = f_0_05;
    *(undefined4 *)(puVar1 + -8) = 0;
    break;
  case 0xe:
    P2 = f_m0_05;
    *(undefined4 *)(puVar1 + -4) = 0;
  }
  return;
}


