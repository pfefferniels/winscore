// FUN_004a5f84 @ 004a5f84 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004a5feb) */

void FUN_004a5f84(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int local_c;
  
  puVar2 = &stack0xfffffffc;
  thunk_FUN_0058c2c9(&DAT_00839198,8,&DAT_00763a64,&DAT_00763a68,"(1i8)",5,param_1);
  local_c = 8;
  DAT_00839194 = 1;
  do {
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 == 0) break;
    DAT_00839194 = DAT_00839194 + 1;
    local_c = local_c + -1;
  } while (0 < local_c);
  DAT_00839190 = (*param_4 - DAT_00839194) + 8;
  FUN_005f46bc(&stack0xfffffffc,0x4a60a5);
  FUN_005f34d1(puVar2,0x4a60bb);
  **(int **)(puVar2 + 0x14) = DAT_00839190 + 2;
  return;
}


