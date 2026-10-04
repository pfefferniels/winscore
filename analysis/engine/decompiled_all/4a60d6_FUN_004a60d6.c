// FUN_004a60d6 @ 004a60d6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004a613d) */

void FUN_004a60d6(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int local_c;
  
  puVar2 = &stack0xfffffffc;
  thunk_FUN_0058c248(&DAT_008391a8,0xb,&DAT_00763a64,&DAT_00763a74,"(1f11.4)",8,param_1);
  local_c = 0xb;
  DAT_008391a4 = 1;
  do {
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 == 0) break;
    DAT_008391a4 = DAT_008391a4 + 1;
    local_c = local_c + -1;
  } while (0 < local_c);
  DAT_008391a0 = (*param_4 - DAT_008391a4) + 0xb;
  FUN_005f46bc(&stack0xfffffffc,0x4a61f7);
  FUN_005f34d1(puVar2,0x4a620d);
  **(int **)(puVar2 + 0x14) = DAT_008391a0 + 2;
  return;
}


