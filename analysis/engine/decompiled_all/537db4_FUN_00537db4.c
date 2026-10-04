// FUN_00537db4 @ 00537db4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00537db4(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  *param_3 = 0;
  DAT_0099a994 = 1;
  iVar1 = 0x200;
  DAT_0099a990 = 1;
  do {
    if ((&DAT_020b8e9f)[DAT_0099a990] == '\0') {
      *(undefined4 *)(puVar2 + -0x10) = 0;
      break;
    }
    if ((&DAT_020b8e9f)[DAT_0099a990] == '\r') {
      **(int **)(puVar2 + 0x10) = **(int **)(puVar2 + 0x10) + 1;
      FUN_005f46bc(puVar2,0x537e64);
      FUN_005f34d1(puVar2,0x537e7a);
      DAT_0099a994 = DAT_0099a990 + 2;
    }
    else {
      *(undefined4 *)(puVar2 + -0xc) = 0;
    }
    *(undefined4 *)(puVar2 + -8) = 0;
    DAT_0099a990 = DAT_0099a990 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  if ((char)(&DAT_020b8e9e)[DAT_0099a990] < ' ') {
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  else {
    **(int **)(puVar2 + 0x10) = **(int **)(puVar2 + 0x10) + 1;
    FUN_005f46bc(puVar2,0x537f26);
    FUN_005f34d1(puVar2,0x537f3c);
  }
  return;
}


