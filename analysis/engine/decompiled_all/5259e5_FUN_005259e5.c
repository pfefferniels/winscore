// FUN_005259e5 @ 005259e5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005259e5(int *param_1)

{
  undefined1 *puVar1;
  int local_c;
  
  puVar1 = &stack0xfffffffc;
  _DAT_02052754 = *param_1 + 1;
  DAT_01fb8cc0 = DAT_01fb8c90;
  *param_1 = 0;
  if (DAT_01fbb700 == 2) {
    DAT_01fb8c88 = DAT_01fb8c94;
  }
  if ((DAT_01fbb7f8 < 0x3b) || (0x44 < DAT_01fbb7f8)) {
    local_c = 0x8c;
    DAT_0094ea34 = 0x8c;
    do {
      *(undefined1 *)((int)&DAT_020b8eb4 + DAT_0094ea34 + 1) = (&DAT_020b8e9f)[DAT_0094ea34];
      DAT_0094ea34 = DAT_0094ea34 + -1;
      local_c = local_c + -1;
    } while (0 < local_c);
    FUN_005f33c9(&stack0xfffffffc,0x525aad);
    thunk_FUN_0054d831(&DAT_020b8ea0,0xa2);
    thunk_FUN_00468df8(&DAT_00767d98);
    *(undefined4 *)(puVar1 + -4) = 0;
  }
  return;
}


