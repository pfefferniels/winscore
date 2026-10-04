// FUN_0055036f @ 0055036f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055036f(float *param_1,float *param_2,float *param_3,float *param_4)

{
  int iVar1;
  float10 in_ST0;
  int local_24;
  int local_20;
  int local_1c;
  int local_10;
  
  *param_1 = f_m99999;
  *param_2 = f_99999;
  *param_3 = *param_2;
  *param_4 = *param_1;
  if (2 < VEC_N) {
    DAT_009a2c20 = 1;
    for (iVar1 = (VEC_N + 1) / 3; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_009a2c1c = (float)*(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                    DAT_009a2c20 * VEC_STRIDE);
      if (DAT_009a2c1c < *param_3) {
        *param_3 = DAT_009a2c1c;
      }
      if (*param_4 < DAT_009a2c1c) {
        *param_4 = DAT_009a2c1c;
      }
      DAT_009a2c1c = (float)*(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                    (DAT_009a2c20 + 1) * VEC_STRIDE);
      if (*param_1 < DAT_009a2c1c) {
        *param_1 = DAT_009a2c1c;
      }
      if (DAT_009a2c1c < *param_2) {
        *param_2 = DAT_009a2c1c;
      }
      DAT_009a2c20 = DAT_009a2c20 + 3;
    }
  }
  if (*(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_01fbb83c) != '\0') {
    DAT_009a2c20 = 1;
    do {
      while( true ) {
        for (; *(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2c20 * DAT_01fbb83c)
               != '\0'; DAT_009a2c20 = DAT_009a2c20 + 1) {
        }
        local_24 = 4;
        DAT_009a2c18 = 1;
        do {
          DAT_009a2c20 = DAT_009a2c20 + 1;
          *(undefined1 *)((int)&DAT_009a2bfc + DAT_009a2c18 + 3) =
               *(undefined1 *)
                ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2c20 * DAT_01fbb83c);
          DAT_009a2c18 = DAT_009a2c18 + 1;
          local_24 = local_24 + -1;
        } while (0 < local_24);
        _DAT_009a2c14 = _DAT_009a2c00;
        local_20 = 4;
        DAT_009a2c18 = 1;
        do {
          DAT_009a2c20 = DAT_009a2c20 + 1;
          *(undefined1 *)((int)&DAT_009a2bfc + DAT_009a2c18 + 3) =
               *(undefined1 *)
                ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2c20 * DAT_01fbb83c);
          DAT_009a2c18 = DAT_009a2c18 + 1;
          local_20 = local_20 + -1;
        } while (0 < local_20);
        _DAT_009a2c10 = _DAT_009a2c00;
        DAT_009a2c20 = DAT_009a2c20 + 0x14;
        local_1c = 4;
        DAT_009a2c18 = 1;
        do {
          DAT_009a2c20 = DAT_009a2c20 + 1;
          *(undefined1 *)((int)&DAT_009a2bfc + DAT_009a2c18 + 3) =
               *(undefined1 *)
                ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2c20 * DAT_01fbb83c);
          DAT_009a2c18 = DAT_009a2c18 + 1;
          local_1c = local_1c + -1;
        } while (0 < local_1c);
        DAT_009a2c0c = _DAT_009a2c00;
        iVar1 = DAT_009a2c20;
        if (_DAT_009a2c00 != 0.0) break;
        DAT_009a2c20 = DAT_009a2c20 + 1;
      }
      do {
        DAT_009a2c20 = iVar1;
        local_10 = 4;
        DAT_009a2c18 = 1;
        do {
          DAT_009a2c20 = DAT_009a2c20 + 1;
          *(undefined1 *)((int)&DAT_009a2bfc + DAT_009a2c18 + 3) =
               *(undefined1 *)
                ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2c20 * DAT_01fbb83c);
          DAT_009a2c18 = DAT_009a2c18 + 1;
          local_10 = local_10 + -1;
        } while (0 < local_10);
        iVar1 = (int)ROUND(_DAT_009a2c10 * f_38_34 + (float)(int)_DAT_009a2c00);
        if (*param_4 < (float)iVar1) {
          *param_4 = (float)iVar1;
        }
        if ((float)(int)_DAT_009a2c00 < *param_3) {
          *param_3 = (float)(int)_DAT_009a2c00;
        }
        iVar1 = 4;
        DAT_009a2c18 = 1;
        do {
          DAT_009a2c20 = DAT_009a2c20 + 1;
          *(undefined1 *)((int)&DAT_009a2bfc + DAT_009a2c18 + 3) =
               *(undefined1 *)
                ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2c20 * DAT_01fbb83c);
          DAT_009a2c18 = DAT_009a2c18 + 1;
          iVar1 = iVar1 + -1;
        } while (0 < iVar1);
        in_ST0 = (float10)(int)_DAT_009a2c00;
        DAT_009a2c18 = (int)ROUND((float10)_DAT_009a2c14 * (float10)f_55_555 + in_ST0);
        if (*param_1 < (float)DAT_009a2c18) {
          *param_1 = (float)DAT_009a2c18;
        }
        if ((float)(int)_DAT_009a2c00 < *param_2) {
          *param_2 = (float)(int)_DAT_009a2c00;
        }
        DAT_009a2c0c = (float)((int)DAT_009a2c0c + -1);
        iVar1 = DAT_009a2c20 + 2;
      } while (0 < (int)DAT_009a2c0c);
      DAT_009a2c20 = DAT_009a2c20 + 3;
    } while (DAT_009a2c20 < *DAT_01fbb844);
  }
  if (*param_3 == f_99999) {
    *param_3 = f_0;
  }
  if (*param_2 == f_99999) {
    *param_2 = f_0;
  }
  if (*param_1 == f_m99999) {
    *param_1 = f_0;
  }
  P1 = *param_3;
  P2 = DAT_009a2c08;
  P3 = *param_2;
  P4 = *param_1;
  *param_1 = (float)VIEW_DY + *param_1;
  *param_2 = (float)VIEW_DY + *param_2;
  ffree(in_ST0);
  return;
}


