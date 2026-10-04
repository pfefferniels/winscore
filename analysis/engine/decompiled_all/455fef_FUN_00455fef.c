// FUN_00455fef @ 00455fef (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455fef(int *param_1,int *param_2,float *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  float10 fVar3;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  
  puVar2 = &stack0xfffffffc;
  DAT_007fec00 = *param_1;
  ffree(in_ST0);
  DAT_007febfc = thunk_FUN_00450b9c(param_1);
  _DAT_007febf8 = *param_3 / f_57_295776;
  ffree(extraout_ST0);
  fVar3 = (float10)FUN_005ff110(&stack0xfffffffc,0x456042);
  _DAT_007febf4 = (float)fVar3;
  ffree(extraout_ST1);
  fVar3 = (float10)FUN_005ff0f5(puVar2,0x456064);
  _DAT_007febf0 = (float)fVar3;
  DAT_007febec = (&PT_X0)[**(int **)(puVar2 + 8)];
  DAT_007febe8 = (&PT_Y0)[**(int **)(puVar2 + 8)];
  do {
    DAT_007febe4 = (&PT_X0)[DAT_007fec00];
    *(int *)(puVar2 + -0x24) = DAT_007febe4 - DAT_007febec;
    iVar1 = *(int *)(puVar2 + -0x24);
    _DAT_007febe0 = (float)iVar1;
    *(int *)(puVar2 + -0x24) = (&PT_Y0)[DAT_007fec00] - DAT_007febe8;
    _DAT_007febdc = (float)*(int *)(puVar2 + -0x24);
    ffree((float10)_DAT_007febf0 * (float10)iVar1);
    fVar3 = (float10)anint(puVar2,0x45610a);
    *(int *)(puVar2 + -0x24) = (int)ROUND(fVar3);
    DAT_007febe4 = DAT_007febec + *(int *)(puVar2 + -0x24);
    (&PT_X0)[DAT_007fec00] = DAT_007febe4;
    ffree((float10)_DAT_007febf0 * (float10)_DAT_007febdc);
    fVar3 = (float10)anint(puVar2,0x456161);
    *(int *)(puVar2 + -0x24) = (int)ROUND(fVar3);
    DAT_007febe4 = DAT_007febe8 + *(int *)(puVar2 + -0x24);
    (&PT_Y0)[DAT_007fec00] = DAT_007febe4;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007febfc * VEC_STRIDE) =
         (&PT_X0)[DAT_007fec00] + DAT_0078df10;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007febfc + 1) * VEC_STRIDE) =
         (&PT_Y0)[DAT_007fec00] - DAT_0078df14;
    DAT_007febfc = DAT_007febfc + 3;
    DAT_007fec00 = DAT_007fec00 + 1;
  } while (DAT_007fec00 <= *param_2);
  ffree(extraout_ST1_00);
  return;
}


