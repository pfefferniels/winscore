// FUN_00541619 @ 00541619 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00541619(int *param_1,uint *param_2)

{
  int iVar1;
  
  if (DAT_020b8ea3 == 'X') {
    push_words(&DAT_00768e04,&P1);
    DAT_0078b4e4 = 0x53;
    thunk_FUN_004f7808();
    pop_words(&DAT_00768e04,&P1);
    thunk_FUN_0054e546(&DAT_0099de1c,&DAT_0099de18);
    if (((int)*param_2 < 1) || (2 < (int)*param_2)) {
      *param_2 = 1;
    }
    DAT_0099e968 = (uint)(*param_2 == 1);
    _DAT_0099e96c = (uint)(*param_2 == 2);
    DAT_0099e970 = (int)ROUND(_DAT_0099de1c);
    DAT_0099e974 = (int)ROUND(_DAT_0099de1c + f_1);
    DAT_0099e980 = DAT_007974fc;
    iVar1 = thunk_FUN_0059bae0(&DAT_0099e968);
    *param_1 = iVar1;
    P2 = (float)(int)DAT_0099e968;
    if (P2 == f_0) {
      P2 = f_2;
    }
    P3 = (float)DAT_0099e970;
    P4 = (float)DAT_0099e974;
  }
  else {
    push_words(&DAT_00768e04,&P1);
    thunk_FUN_005725fa();
    DAT_020527a0 = 0xfffffffe;
    DAT_0078b4e4 = 0x53;
    thunk_FUN_004f7808();
    pop_words(&DAT_00768e04,&P1);
    thunk_FUN_0054e546(&DAT_0099de1c,&DAT_0099de18);
    if (((int)*param_2 < 1) || (2 < (int)*param_2)) {
      *param_2 = 1;
    }
    DAT_0099e968 = (uint)(*param_2 == 1);
    _DAT_0099e96c = (uint)(*param_2 == 2);
    DAT_0099e970 = (int)ROUND(_DAT_0099de18);
    DAT_0099e974 = (int)ROUND(_DAT_0099de1c);
    _DAT_0099e978 = (int)ROUND(DAT_01e67910);
    if (DAT_01e67914 == f_0) {
      DAT_01e67914 = DAT_01fbb8b8;
    }
    _DAT_0099e97c = (int)ROUND(DAT_01e67914);
    DAT_0099e980 = DAT_007974fc;
    iVar1 = thunk_FUN_0059b960(&DAT_0099e968);
    *param_1 = iVar1;
    *param_2 = DAT_0099e968;
    if (*param_2 == 0) {
      *param_2 = 2;
    }
  }
  if (*param_1 == 2) {
    DAT_01fbb8a0 = 0;
    draw_items();
    thunk_FUN_00549422();
  }
  else {
    DAT_01fbb860 = DAT_0099e970;
    DAT_01fbb864 = DAT_0099e974;
    if (DAT_0099e970 == 0) {
      DAT_01fbb860 = (int)ROUND(_DAT_0099de18);
    }
    if (DAT_0099e974 == 0) {
      DAT_01fbb864 = DAT_01fbb860;
    }
    DAT_01e67910 = (float)_DAT_0099e978;
    DAT_01e67914 = (float)_DAT_0099e97c;
    DAT_007974fc = DAT_0099e980;
  }
  return;
}


