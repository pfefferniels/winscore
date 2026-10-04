// FUN_0042d9f9 @ 0042d9f9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_0042d9f9(float *param_1)

{
  undefined4 local_18;
  
  local_18 = 0;
  if (((*(float *)(&DAT_020b9358 + DAT_01caf6b0 * 4) == *(float *)(&DAT_020b9350 + DAT_01caf6b0 * 4)
       ) && (DAT_01caf6c8 = (int)ROUND(*(float *)(&DAT_020b934c + DAT_01caf6b0 * 4)),
            DAT_01caf6c8 != 6)) && (DAT_01caf6c8 != 0xc)) {
    DAT_01caf6c4 = *param_1 + f_2;
    if (DAT_01fbb8b8 - f_0_5 <= DAT_01caf6c4) {
      *(float *)(&DAT_020b9358 + DAT_01caf6b0 * 4) = DAT_01fbb8b8;
    }
    else {
      *param_1 = DAT_01caf6c4;
      DAT_01caf6b0 = DAT_01caf6b0 + -2;
      local_18 = 1;
    }
  }
  return local_18;
}


