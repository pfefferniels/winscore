// FUN_0044f333 @ 0044f333 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0044f537) */
/* WARNING: Removing unreachable block (ram,0x0044f499) */
/* WARNING: Removing unreachable block (ram,0x0044f553) */

void FUN_0044f333(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  thunk_FUN_0054c83c(&DAT_007fe36c,1,&DAT_00760f64);
  FUN_005f34d1(&stack0xfffffffc,0x44f377);
  FUN_005f34d1(puVar2,0x44f398);
  *(undefined4 *)(puVar2 + -0x28) = 0x80;
  DAT_007fe360 = 1;
  do {
    if (*(char *)(DAT_007fe360 + 0x7fe36b) == ' ') {
      *(undefined4 *)(puVar2 + -0x24) = 0;
      DAT_007fe35c = DAT_007fe360 + 1;
      iVar1 = 0x81 - DAT_007fe35c;
      *(int *)(puVar2 + -0x1c) = iVar1;
      while( true ) {
        if (iVar1 < 1) {
          *(undefined4 *)(puVar2 + -0x14) = 0;
          return;
        }
        if (*(char *)(DAT_007fe35c + 0x7fe36b) != ' ') break;
        DAT_007fe35c = DAT_007fe35c + 1;
        *(int *)(puVar2 + -0x1c) = *(int *)(puVar2 + -0x1c) + -1;
        iVar1 = *(int *)(puVar2 + -0x1c);
      }
      *(undefined4 *)(puVar2 + -0x18) = 0;
      FUN_0044f5df(&DAT_007fe56c,0x80,DAT_007fe35c + 0x7fe36b,1);
      *(undefined4 *)(puVar2 + -0x10) = 0x80;
      DAT_007fe35c = 1;
      do {
        iVar1 = FUN_005f4660(0x20);
        if (iVar1 != 0) {
          *(undefined4 *)(puVar2 + -0xc) = 0;
          DAT_007fe358 = 1;
          DAT_007fe360 = DAT_007fe35c + 1;
          iVar1 = (DAT_007fe35c - DAT_007fe360) + 4;
          *(int *)(puVar2 + -4) = iVar1;
          while (0 < iVar1) {
            FUN_005f46bc(puVar2,0x44f572);
            FUN_005f34d1(puVar2,0x44f588);
            DAT_007fe358 = DAT_007fe358 + 1;
            DAT_007fe360 = DAT_007fe360 + 1;
            *(int *)(puVar2 + -4) = *(int *)(puVar2 + -4) + -1;
            iVar1 = *(int *)(puVar2 + -4);
          }
          return;
        }
        DAT_007fe35c = DAT_007fe35c + 1;
        *(int *)(puVar2 + -0x10) = *(int *)(puVar2 + -0x10) + -1;
      } while (0 < *(int *)(puVar2 + -0x10));
      *(undefined4 *)(puVar2 + -8) = 0;
      return;
    }
    DAT_007fe360 = DAT_007fe360 + 1;
    *(int *)(puVar2 + -0x28) = *(int *)(puVar2 + -0x28) + -1;
  } while (0 < *(int *)(puVar2 + -0x28));
  *(undefined4 *)(puVar2 + -0x20) = 0;
  return;
}


