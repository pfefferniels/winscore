// FUN_0041ef66 @ 0041ef66 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ef66(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  DAT_007d1ddc = (int)ROUND(DAT_01fb8c60);
  LOAD_I = 1;
  _DAT_007d1dd8 = f_m9999;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((LOAD_CODE == 3) && (DAT_007d1ddc == LOAD_STAFF)) && (_DAT_007d1dd8 < LOAD_P3)) {
      _DAT_007d1dd8 = LOAD_P3;
      DAT_0079484c = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
      if (LOAD_LEN < 5) {
        DAT_0079484c = 0;
      }
      _DAT_00794854 = (&DAT_0078e8ac)[DAT_0079484c];
    }
    LOAD_I = LOAD_I + 1;
  }
  if (_DAT_007d1dd8 != f_m9999) {
    *param_1 = *param_1 + 1;
    if ((DAT_0079484c == 0) || (DAT_0079484c == 4)) {
      FUN_005f46bc(&stack0xfffffffc,0x41f114);
      puVar2 = puVar3;
      FUN_005f34d1(puVar3,0x41f12a);
    }
    if (DAT_0079484c == 1) {
      FUN_005f46bc(puVar2,0x41f172);
      FUN_005f34d1(puVar2,0x41f188);
    }
    if (DAT_0079484c == 2) {
      FUN_005f46bc(puVar2,0x41f1d0);
      FUN_005f34d1(puVar2,0x41f1e6);
    }
    if (DAT_0079484c == 3) {
      FUN_005f46bc(puVar2,0x41f22e);
      FUN_005f34d1(puVar2,0x41f244);
    }
    **(int **)(puVar2 + 8) = **(int **)(puVar2 + 8) + 3;
    _DAT_00794854 = (&DAT_0078e8ac)[DAT_0079484c];
  }
  return;
}


