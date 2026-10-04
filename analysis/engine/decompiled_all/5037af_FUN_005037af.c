// FUN_005037af @ 005037af (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005037af(float *param_1,float *param_2,int *param_3,int param_4,int param_5,int *param_6,
                 undefined4 param_7)

{
  int iVar1;
  
  DAT_020492a0 = 0;
  DAT_020492a4 = 0;
  _DAT_00903c8c = *param_1;
  _DAT_00903c88 = *param_2;
  _DAT_00903c84 = 0;
  iVar1 = *param_6;
  DAT_00903c80 = 1;
  do {
    if (iVar1 < 1) {
      return;
    }
    DAT_00903c7c = 0;
    DAT_00903c78 = *(int *)(DAT_00903c80 * 4 + param_5 + -4);
    DAT_00903c74 = (int)ROUND(*(float *)(param_4 + -4 + DAT_00903c78 * 4));
    DAT_00903c70 = (int)ROUND(*(float *)(param_4 + DAT_00903c78 * 4));
    _DAT_00903c6c = *(float *)(param_4 + 8 + DAT_00903c78 * 4);
    if (DAT_00903c74 < 3) {
      _DAT_00903c6c = f_0;
    }
    if ((_DAT_00903c6c < _DAT_00903c8c) || (_DAT_00903c88 < _DAT_00903c6c)) {
LAB_005039cc:
      if ((((DAT_00903c74 < 6) || (DAT_00903c70 < 4)) || (8 < DAT_00903c70)) ||
         (((*(float *)(param_4 + 0x18 + DAT_00903c78 * 4) == f_m1 && ((float)DAT_00903c70 == f_4))
          && (*(float *)(param_4 + 0x14 + DAT_00903c78 * 4) == f_0)))) {
LAB_00503d21:
        if (DAT_00903c7c != 0) goto LAB_00503d33;
      }
      else if ((DAT_00903c7c != 0) || (*param_3 < 1)) {
        if ((DAT_00903c70 == 8) && (*(float *)(param_4 + 0x14 + DAT_00903c78 * 4) == f_0)) {
          *(float *)(param_4 + 0x14 + DAT_00903c78 * 4) = f_200;
        }
        FUN_00503d77(&DAT_00903c80,&DAT_00903c78,&DAT_00766e50,&DAT_00903c8c,&DAT_00903c88,param_4);
        if ((5 < DAT_00903c70) && (7 < DAT_00903c74)) {
          if (DAT_00903c70 + -7 < 0) {
            if (10 < DAT_00903c74) {
              if (f_0 < *(float *)(param_4 + 0x28 + DAT_00903c78 * 4)) {
                FUN_00503d77(&DAT_00903c80,&DAT_00903c78,&DAT_00766e4c,&DAT_00903c8c,&DAT_00903c88,
                             param_4);
              }
              if ((f_0 <= *(float *)(param_4 + 0x18 + DAT_00903c78 * 4)) && (0xb < DAT_00903c74)) {
                if (f_0 < *(float *)(param_4 + 0x2c + DAT_00903c78 * 4)) {
                  FUN_00503d77(&DAT_00903c80,&DAT_00903c78,&DAT_00766e48,&DAT_00903c8c,&DAT_00903c88
                               ,param_4);
                }
                if ((0xd < DAT_00903c74) && (*(float *)(param_4 + 0x30 + DAT_00903c78 * 4) != f_0))
                {
                  if (f_0 < *(float *)(param_4 + 0x34 + DAT_00903c78 * 4)) {
                    FUN_00503d77(&DAT_00903c80,&DAT_00903c78,&DAT_00766e44,&DAT_00903c8c,
                                 &DAT_00903c88,param_4);
                  }
                  if (0xe < DAT_00903c74) {
                    DAT_00903c74 = 0xf;
                    goto LAB_00503ccf;
                  }
                }
              }
            }
          }
          else if ((DAT_00903c70 + -7 < 1) &&
                  (DAT_00903c70 = (int)ROUND(*(float *)(param_4 + 0x18 + DAT_00903c78 * 4)),
                  0x13 < DAT_00903c70)) {
            DAT_00903c74 = 8;
LAB_00503ccf:
            if (f_0 < *(float *)(param_4 + -4 + (DAT_00903c74 + DAT_00903c78) * 4)) {
              FUN_00503d77(&DAT_00903c80,&DAT_00903c78,&DAT_00903c74,&DAT_00903c8c,&DAT_00903c88,
                           param_4);
            }
          }
        }
        goto LAB_00503d21;
      }
    }
    else {
      DAT_00903c7c = 1;
      DAT_020492a4 = DAT_020492a4 + 1;
      _DAT_00903c84 = 0;
      *(int *)(&DAT_02049a74 + DAT_020492a4 * 4) = DAT_00903c78 + 3;
      if (DAT_00903c74 < 2) {
        thunk_FUN_00584a6f(&DAT_00903c80,&DAT_00903c78,&DAT_00766e58,&f_2,param_4,param_5,param_6,
                           param_7);
        *(float *)(param_4 + 4 + DAT_00903c78 * 4) = f_1;
        DAT_00903c74 = 2;
      }
      if (*param_3 != 1) {
        if (DAT_00903c74 < 3) {
          thunk_FUN_00584a6f(&DAT_00903c80,&DAT_00903c78,&DAT_00766e58,&f_3,param_4,param_5,param_6,
                             param_7);
          *(float *)(param_4 + 8 + DAT_00903c78 * 4) = f_0;
        }
        goto LAB_005039cc;
      }
LAB_00503d33:
      if (DAT_020492a0 == 0) {
        DAT_020492a0 = DAT_00903c80;
      }
    }
    DAT_00903c80 = DAT_00903c80 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


