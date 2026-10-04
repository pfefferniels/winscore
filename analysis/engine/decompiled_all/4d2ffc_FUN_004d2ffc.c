// FUN_004d2ffc @ 004d2ffc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004d2ffc(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x4d3022);
  *(undefined4 *)(puVar2 + -0x14) = 0x30;
  DAT_008a01f4 = 1;
  do {
    if ((&DAT_020b8e9f)[DAT_008a01f4] == ' ') {
      *(undefined4 *)(puVar2 + -0x10) = 0;
      break;
    }
    DAT_008a01f4 = DAT_008a01f4 + 1;
    *(int *)(puVar2 + -0x14) = *(int *)(puVar2 + -0x14) + -1;
  } while (0 < *(int *)(puVar2 + -0x14));
  DAT_008a01f0 = DAT_008a01f4 + 1;
  iVar1 = 0x31 - DAT_008a01f0;
  *(int *)(puVar2 + -0xc) = iVar1;
  while( true ) {
    if (iVar1 < 1) {
      FUN_005f34d1(puVar2,0x4d31a9);
      *(undefined4 *)(puVar2 + -4) = 0;
      return;
    }
    if ((&DAT_020b8e9f)[DAT_008a01f0] != ' ') break;
    DAT_008a01f0 = DAT_008a01f0 + 1;
    *(int *)(puVar2 + -0xc) = *(int *)(puVar2 + -0xc) + -1;
    iVar1 = *(int *)(puVar2 + -0xc);
  }
  *(undefined4 *)(puVar2 + -8) = 0;
  FUN_005f46bc(puVar2,0x4d3112);
  FUN_005f34d1(puVar2,0x4d3128);
  FUN_005f34d1(puVar2,0x4d3149);
  FUN_005f33c9(puVar2,0x4d316b);
  FUN_005f34d1(puVar2,0x4d3186);
  return;
}


