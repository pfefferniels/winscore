// FUN_004d3e78 @ 004d3e78 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004d3e78(void)

{
  undefined4 local_3c [10];
  int local_14;
  
  thunk_FUN_0054c590(&P1,&DAT_020b9440,&DAT_007654fc);
  if (1 < NPT) {
    FUN_004d3f5f();
    FUN_004d3ff3();
    if (DAT_0078b4e0 == 0x42) {
      return;
    }
  }
  NPT = 1;
  if (0 < DAT_0078d850) {
    local_3c[0] = 0;
    local_14 = FUN_005fc330(local_3c,0x18,0x784ff01,&DAT_007654f8,0,&DAT_00793b98);
    if (local_14 == 0) {
      DAT_0078d854 = 1;
      DAT_0078d850 = 0;
    }
    else {
      thunk_FUN_004cf1c2();
    }
  }
  return;
}


