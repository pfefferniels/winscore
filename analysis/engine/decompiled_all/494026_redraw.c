// redraw @ 00494026 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void redraw(int *param_1)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  _DAT_0082a04c = (float)DAT_009c66cc;
  VIEW_DX = 0x960;
  if (*param_1 == 0) {
    DAT_009a9498 = 0x40;
    DAT_0082a048 = 100;
  }
  else {
    fit_view(&DAT_00762e40,&DAT_0082a044,&DAT_0082a040,&DAT_0082a03c,&DAT_0082a038);
    fit_view(&DAT_00762e40,&DAT_0082a044,&DAT_0082a040,&DAT_0082a03c,&DAT_0082a038);
    _DAT_0082a034 = (float)_DAT_01b12d48;
    _DAT_0082a030 = (float)(DAT_0082a038 + 500);
    _DAT_0082a02c = _DAT_0082a034 / _DAT_0082a030;
    _DAT_0082a050 = (_DAT_0082a02c - f_0_05) * (float)DAT_009c66cc;
    if (f_640 < _DAT_0082a050) {
      _DAT_0082a050 = f_640;
    }
    DAT_009a9498 = (int)ROUND(_DAT_0082a050);
    DAT_0082a048 = (int)ROUND((_DAT_0082a050 / f_64) * f_100 + f_0_5);
  }
  DAT_009c66cc = DAT_009a9498;
  _DAT_0082a028 = thunk_FUN_0059d240(DAT_0082a048);
  FUN_005f34d1(&stack0xfffffffc,0x4941f3);
  draw_items();
  if (**(int **)(puVar2 + 8) == 0) {
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  else {
    thunk_FUN_0055036f(&DAT_0082a024,&DAT_0082a020,&DAT_0082a01c,&DAT_0082a018);
    thunk_FUN_00579770(&DAT_00762e48,1,&IP1);
    IP4 = IP2;
    IP6 = 0;
    fVar1 = (_DAT_0082a024 - _DAT_0082a020) + f_5000;
    *(undefined2 *)(puVar2 + -0x34) = in_FPUControlWord;
    *(ushort *)(puVar2 + -0x32) = (ushort)*(undefined4 *)(puVar2 + -0x34) | 0xc00;
    *(int *)(puVar2 + -0x30) = (int)ROUND(fVar1);
    _DAT_0082a014 = (float)DAT_009c66cc / _DAT_0082a04c;
    fVar1 = (float)*(int *)(puVar2 + -0x30) * _DAT_0082a014;
    *(undefined2 *)(puVar2 + -0x34) = *(undefined2 *)(puVar2 + -0x34);
    *(ushort *)(puVar2 + -0x32) = (ushort)*(undefined4 *)(puVar2 + -0x34) | 0xc00;
    *(int *)(puVar2 + -0x30) = (int)ROUND(fVar1);
    IP2 = *(int *)(puVar2 + -0x30);
    thunk_FUN_00579770(&DAT_00762e2c,1,&IP1);
  }
  return;
}


