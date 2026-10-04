// FUN_00536839 @ 00536839 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00536839(int *param_1)

{
  undefined4 local_18;
  
  _DAT_0099a868 = 0x42;
  fit_view(&DAT_0099a868,&DAT_0099a878,&DAT_0099a874,&DAT_0099a86c,&DAT_0099a870);
  _DAT_0099a864 = DAT_0099a878 - _DAT_0099a874;
  _DAT_0099a860 = DAT_0099a870 - _DAT_0099a86c;
  thunk_FUN_00579770(&DAT_00768974,1,&IP1);
  _DAT_0099a85c = (float)IP1;
  _DAT_0099a858 = (float)IP2;
  local_18 = 0;
  thunk_FUN_00579770(&DAT_00768970,1,&IP1);
  DAT_0099a854 = IP1;
  DAT_0099a850 = IP2;
  if (((*param_1 == 1) && ((float)_DAT_0099a864 < _DAT_0099a858 || IP2 == 0)) ||
     ((*param_1 == 3 && ((float)_DAT_0099a860 < _DAT_0099a85c || IP1 == 0)))) {
    local_18 = 1;
  }
  else {
    IP1 = 500000;
    IP2 = -500000;
    thunk_FUN_00579770(&DAT_00768990,1,&IP1);
    thunk_FUN_00579770(&DAT_00768970,1,&IP1);
    _DAT_0099a87c = IP2;
    _DAT_0099a880 = IP1;
    if (((*param_1 == 2) && ((float)_DAT_0099a864 < _DAT_0099a858 || DAT_0099a850 == IP2)) ||
       ((*param_1 == 4 && ((float)_DAT_0099a860 < _DAT_0099a85c || DAT_0099a854 == IP1)))) {
      local_18 = 1;
    }
    IP1 = DAT_0099a854;
    IP2 = DAT_0099a850;
    thunk_FUN_00579770(&DAT_00768990,1,&IP1);
  }
  return local_18;
}


