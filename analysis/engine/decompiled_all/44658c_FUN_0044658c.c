// FUN_0044658c @ 0044658c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00446872) */
/* WARNING: Removing unreachable block (ram,0x00446908) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044658c(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_38;
  
  puVar2 = &stack0xfffffffc;
  local_38 = 0x1fd;
  DAT_007fc0e8 = 4;
  while ((&DAT_020b909f)[DAT_007fc0e8] == ' ') {
    DAT_007fc0e8 = DAT_007fc0e8 + 1;
    local_38 = local_38 + -1;
    if (local_38 < 1) {
      return;
    }
  }
  iVar1 = 0x201 - DAT_007fc0e8;
  for (DAT_007fc0e4 = DAT_007fc0e8; (0 < iVar1 && ((&DAT_020b909f)[DAT_007fc0e4] != ' '));
      DAT_007fc0e4 = DAT_007fc0e4 + 1) {
    iVar1 = iVar1 + -1;
  }
  FUN_005f34d1(&stack0xfffffffc,0x44665e);
  FUN_005f46bc(puVar2,0x44669f);
  FUN_005f34d1(puVar2,0x4466b5);
  DAT_007fc0dc = DAT_007fc0e4;
  DAT_007fc0e0 = DAT_007fc0e4 - DAT_007fc0e8;
  iVar1 = 0x201 - DAT_007fc0e4;
  *(int *)(puVar2 + -0x20) = iVar1;
  while (0 < iVar1) {
    if ((&DAT_020b909f)[DAT_007fc0dc] != ' ') {
      *(undefined4 *)(puVar2 + -0x1c) = 0;
      iVar1 = 0x201 - DAT_007fc0dc;
      DAT_007fc0d8 = DAT_007fc0dc;
      goto joined_r0x0044674a;
    }
    DAT_007fc0dc = DAT_007fc0dc + 1;
    *(int *)(puVar2 + -0x20) = *(int *)(puVar2 + -0x20) + -1;
    iVar1 = *(int *)(puVar2 + -0x20);
  }
  puVar3 = &DAT_007fc170;
  puVar4 = &DAT_007fc0f0;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(puVar2 + -0x18) = 0;
LAB_0044680b:
  _DAT_007fc0ec = 0x73756d2e;
  thunk_FUN_00497193(&DAT_007fc170,0x80,&DAT_0078b690,4);
  if (DAT_0078b690 == 0x20202020) {
    FUN_005f46bc(puVar2,0x446896);
    FUN_005f34d1(puVar2,0x4468ac);
    *(undefined4 *)(puVar2 + -0xc) = 0;
  }
  else {
    *(undefined4 *)(puVar2 + -0x10) = 0;
    _DAT_007fc0ec = DAT_0078b690;
  }
  thunk_FUN_00497193(&DAT_007fc0f0,0x80,&DAT_0078b690,4);
  if (DAT_0078b690 == 0x20202020) {
    FUN_005f46bc(puVar2,0x44692c);
    FUN_005f34d1(puVar2,0x446942);
  }
  else {
    *(undefined4 *)(puVar2 + -8) = 0;
  }
  *(undefined4 *)(puVar2 + -4) = 0;
  return;
joined_r0x0044674a:
  if (iVar1 < 1) goto LAB_00446782;
  if ((&DAT_020b909f)[DAT_007fc0d8] == ' ') {
    *(undefined4 *)(puVar2 + -0x14) = 0;
    goto LAB_00446782;
  }
  DAT_007fc0d8 = DAT_007fc0d8 + 1;
  iVar1 = iVar1 + -1;
  goto joined_r0x0044674a;
LAB_00446782:
  FUN_005f46bc(puVar2,0x4467c3);
  FUN_005f34d1(puVar2,0x4467d9);
  DAT_007fc0d4 = DAT_007fc0d8 - DAT_007fc0dc;
  goto LAB_0044680b;
}


