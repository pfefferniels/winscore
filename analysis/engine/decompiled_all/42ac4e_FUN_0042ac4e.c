// FUN_0042ac4e @ 0042ac4e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042ac4e(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  undefined1 *puVar5;
  int local_ac [42];
  
  puVar5 = &stack0xfffffffc;
  bVar4 = &stack0x00000000 == (undefined1 *)0xb0;
  iVar1 = 0x20;
  piVar2 = &DAT_0078ecec;
  piVar3 = param_1;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    piVar2 = param_1;
    piVar3 = &DAT_0078ecec;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    piVar2 = local_ac;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *param_1;
      param_1 = param_1 + 1;
      piVar2 = piVar2 + 1;
    }
    iVar1 = FUN_005ff950(local_ac,0x80);
    DAT_007ec318 = iVar1 + 1;
    FUN_005f46bc(&stack0xfffffffc,0x42aceb);
    FUN_005f34d1(puVar5,0x42ad01);
    FUN_005f33c9(puVar5,0x42ad23);
    FUN_005f34d1(puVar5,0x42ad3e);
    FUN_005f33c9(puVar5,0x42ad5d);
    FUN_005f34d1(puVar5,0x42ad78);
    thunk_FUN_005960f0(&DAT_020b8ea0);
  }
  return;
}


