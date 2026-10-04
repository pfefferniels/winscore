// FUN_0041f64f @ 0041f64f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0041f64f(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  DAT_007d2088 = 5;
LAB_0041f663:
  do {
    if ((*(char *)((int)&DAT_007cb2cc + DAT_007d2088 + 3) == '/') ||
       (*(char *)((int)&DAT_007cb2cc + DAT_007d2088 + 3) == ']')) {
      if (*(char *)((int)&DAT_007cb2cc + DAT_007d2088 + 2) == '/') {
        *(undefined4 *)(puVar3 + -0x18) = 0;
        DAT_007d2084 = DAT_007d2088 + -2;
        while ((iVar1 = DAT_007d2084 + -1, *(char *)((int)&DAT_007cb2cc + DAT_007d2084 + 2) != '/'
               && (*(char *)((int)&DAT_007cb2cc + DAT_007d2084 + 2) != '['))) {
          *(undefined4 *)(puVar3 + -0xc) = 0;
          DAT_007d2084 = iVar1;
        }
        DAT_007d2080 = (DAT_007d2088 - iVar1) + -2;
        iVar2 = (DAT_007d2088 + -0x101) / -1;
        *(int *)(puVar3 + -8) = iVar2;
        DAT_007d207c = 0x100;
        DAT_007d2084 = iVar1;
        while (0 < iVar2) {
          *(undefined1 *)((int)&DAT_007cb2cc + DAT_007d207c + 3) =
               *(undefined1 *)((int)&DAT_007cb2cc + (DAT_007d207c - DAT_007d2080) + 3);
          DAT_007d207c = DAT_007d207c + -1;
          *(int *)(puVar3 + -8) = *(int *)(puVar3 + -8) + -1;
          iVar2 = *(int *)(puVar3 + -8);
        }
        FUN_005f46bc(puVar3,0x41f7de);
        FUN_005f34d1(puVar3,0x41f7f4);
        *(undefined4 *)(puVar3 + -4) = 0;
        goto LAB_0041f663;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x1c) = 0;
    }
    DAT_007d2088 = DAT_007d2088 + 1;
    if (0x100 < DAT_007d2088) {
      *(undefined4 *)(puVar3 + -0x10) = 0;
      return;
    }
    *(undefined4 *)(puVar3 + -0x14) = 0;
  } while( true );
}


