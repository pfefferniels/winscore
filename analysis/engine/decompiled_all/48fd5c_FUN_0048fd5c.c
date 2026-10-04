// FUN_0048fd5c @ 0048fd5c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048fd5c(int *param_1)

{
  int iVar1;
  float fVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  float10 fVar5;
  
  puVar3 = &stack0xfffffffc;
  if (*param_1 == 0) {
    *param_1 = DAT_01a14950;
    return;
  }
  DAT_008298a8 = (int)ROUND(DAT_020b9440);
  if (*param_1 == -1) {
    DAT_01be6d60 = 0x32;
  }
  if (DAT_01be6d60 < 3) {
    _DAT_00829880 = (float)(&STAFF_STEP0)[(int)ROUND(DAT_020b9444)] * f_7;
    _DAT_0082987c = (&STAFF_Y0)[(int)ROUND(DAT_020b9444)];
    if ((3 < DAT_020527c8) && (DAT_00829878 != 8)) {
      amod(&ITEM_P4 + DAT_00829870,&f_100);
    }
    _DAT_0082987c = ((&STAFF_Y0)[(int)ROUND(DAT_020b9444)] - VIEW_DY) + 0x4000;
    DAT_0082986c = (float)DAT_01a14950 / f_150;
    DAT_00829874 = (float)(DAT_01a1494c - _DAT_0082987c) / _DAT_00829880 + f_2;
    _DAT_00829868 = DAT_0082986c - DAT_020b9448;
    _DAT_00829864 = DAT_00829874 - DAT_020b944c;
    P3 = DAT_020b9448;
    P6 = DAT_020b9454;
    if ((DAT_020b8e50 == 6) && (DAT_0078dc30 == 2)) {
      _DAT_00829868 = DAT_0082986c - DAT_020b9454;
    }
    iVar4 = 6;
    DAT_00829860 = 1;
    do {
      iVar1 = *(int *)(DAT_00829860 * 4 + 0x78d81c);
      if (iVar1 != 0) {
        if (iVar1 == 3) {
          DAT_020b9448 = DAT_0082986c;
        }
        else if (DAT_0078dc30 == 1) {
          *(float *)(&DAT_020b943c + iVar1 * 4) = DAT_0082986c;
        }
        else if (DAT_0078dc30 + -1 < 1) {
          *(float *)(&DAT_020b943c + iVar1 * 4) =
               _DAT_00829868 + *(float *)(&DAT_020b943c + iVar1 * 4);
        }
        else {
          *(float *)(&DAT_020b943c + iVar1 * 4) = DAT_0082986c;
        }
      }
      DAT_00829860 = DAT_00829860 + 1;
      iVar4 = iVar4 + -1;
    } while (0 < iVar4);
    DAT_00829860 = 1;
    do {
      DAT_0082985c = *(int *)(&DAT_0078d834 + DAT_00829860 * 4);
      if (DAT_0082985c == 0) {
        *(undefined4 *)(puVar3 + -0x14) = 0;
      }
      else if (DAT_0082985c == 5) {
        DAT_020b9450 = _DAT_00829864 + DAT_020b9450;
        if (DAT_0078dc30 == 2) {
          DAT_020b9450 = DAT_00829874;
        }
      }
      else {
        if (DAT_020b8e50 < 4) {
          fVar5 = (float10)FUN_005ff381(puVar3,0x490101);
          *(int *)(puVar3 + -0xe0) = (int)ROUND(fVar5);
          DAT_00829874 = (float)*(int *)(puVar3 + -0xe0);
        }
        DAT_020b944c = DAT_00829874;
      }
      *(undefined4 *)(puVar3 + -0x10) = 0;
      DAT_00829860 = DAT_00829860 + 1;
      *(int *)(puVar3 + -0x18) = *(int *)(puVar3 + -0x18) + -1;
    } while (0 < *(int *)(puVar3 + -0x18));
    goto LAB_004907ed;
  }
  _DAT_008298a4 = *(float *)(&DAT_020b943c + DAT_01be6d60 * 4);
  DAT_008298a0 = f_m9999;
  DAT_0082989c = f_m9999;
  DAT_00829898 = DAT_01a14950 - *param_1;
  iVar4 = DAT_00829898;
  if (DAT_00829898 < 0) {
    iVar4 = -DAT_00829898;
  }
  if (iVar4 < 3) {
    DAT_0082989c = f_m9999;
    DAT_008298a0 = f_m9999;
    return;
  }
  _DAT_00829894 = (float)DAT_00829898 / _DAT_01be6d64;
  DAT_00829890 = _DAT_00829894 + _DAT_008298a4;
  puVar3 = &stack0xfffffffc;
  fVar5 = (float10)FUN_005ff381(&stack0xfffffffc,0x490200);
  *(int *)(puVar3 + -0xe0) = (int)ROUND(fVar5);
  _DAT_0082988c = *(int *)(puVar3 + -0xe0);
  fVar2 = (float)_DAT_0082988c / f_10;
  DAT_00829890 = fVar2;
  if (DAT_01be6d68 + -1 < 0) goto LAB_00490670;
  if (DAT_01be6d68 + -1 < 1) {
    switch(DAT_008298a8) {
    default:
      if ((DAT_01be6d60 == 4) || (DAT_01be6d60 == 6)) {
        *(undefined4 *)(puVar3 + -0xac) = 0;
      }
      else {
        if ((DAT_008298a8 != 2) || (DAT_01be6d60 != 0xd && (DAT_01be6d60 != 8 && DAT_01be6d60 != 5))
           ) {
          *(undefined4 *)(puVar3 + -0xa4) = 0;
          goto LAB_00490643;
        }
        *(undefined4 *)(puVar3 + -0xa8) = 0;
      }
      break;
    case 3:
    case 9:
    case 0xb:
      if (((DAT_01be6d60 == 10) || (DAT_01be6d60 == 5)) || (DAT_01be6d60 == 9)) break;
      *(undefined4 *)(puVar3 + -0xa0) = 0;
LAB_00490643:
      if (_DAT_008298a4 == DAT_00829890) {
        *(undefined4 *)(puVar3 + -0x30) = 0;
        return;
      }
      goto LAB_004907bc;
    case 4:
      if (((DAT_01be6d60 != 0xd) && (DAT_020b9450 == f_999 || DAT_01be6d60 != 7)) &&
         (DAT_01be6d60 != 9 || DAT_020b9458 != f_0)) {
        *(undefined4 *)(puVar3 + -0x90) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x94) = 0;
      break;
    case 5:
      if (((DAT_01be6d60 != 0xc) && (DAT_01be6d60 != 0xb)) &&
         (DAT_020b945c < f_1 || DAT_01be6d60 != 9)) {
        *(undefined4 *)(puVar3 + -0x88) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x8c) = 0;
      break;
    case 6:
      if ((DAT_01be6d60 != 0xd) && (DAT_01be6d60 < 7 || 10 < DAT_01be6d60)) {
        *(undefined4 *)(puVar3 + -0x80) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x84) = 0;
      break;
    case 7:
    case 8:
      if ((DAT_01be6d60 != 7) && (DAT_008298a8 != 8 || DAT_01be6d60 != 9)) {
        *(undefined4 *)(puVar3 + -0x78) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x7c) = 0;
      break;
    case 10:
      if (((DAT_01be6d60 != 8) && (DAT_01be6d60 != 5)) && (DAT_01be6d60 != 7)) {
        *(undefined4 *)(puVar3 + -0x70) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x74) = 0;
      break;
    case 0xc:
      if (((DAT_01be6d60 != 0xc) && (DAT_01be6d60 != 5)) && (DAT_01be6d60 != 9)) {
        if (DAT_020b9450 < f_0) {
          if ((6 < DAT_01be6d60) && (DAT_01be6d60 < 0xf)) {
            *(undefined4 *)(puVar3 + -100) = 0;
            break;
          }
          *(undefined4 *)(puVar3 + -0x60) = 0;
        }
        else {
          *(undefined4 *)(puVar3 + -0x68) = 0;
        }
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x6c) = 0;
      break;
    case 0xe:
      if (((DAT_01be6d60 < 10) && (DAT_01be6d60 != 4)) && (DAT_01be6d60 != 5)) {
        *(undefined4 *)(puVar3 + -0x58) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x5c) = 0;
      break;
    case 0xf:
      if (DAT_01be6d60 != 0xc) {
        *(undefined4 *)(puVar3 + -0x50) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x54) = 0;
      break;
    case 0x10:
      if ((DAT_01be6d60 != 8) && (DAT_01be6d60 != 9)) {
        *(undefined4 *)(puVar3 + -0x48) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x4c) = 0;
      break;
    case 0x11:
      if (((DAT_01be6d60 == 7) || (DAT_01be6d60 < 5)) || (0xd < DAT_01be6d60)) {
        *(undefined4 *)(puVar3 + -0x40) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x44) = 0;
      break;
    case 0x12:
      if ((DAT_01be6d60 != 0xc) && (DAT_01be6d60 == 7 || (9 < DAT_01be6d60 || DAT_01be6d60 < 5))) {
        *(undefined4 *)(puVar3 + -0x38) = 0;
        goto LAB_00490643;
      }
      *(undefined4 *)(puVar3 + -0x3c) = 0;
    }
LAB_00490670:
    iVar4 = DAT_01be6d60 * 4;
    fVar5 = (float10)FUN_005ff381(puVar3,0x49068a);
    *(int *)(puVar3 + -0xe0) = (int)ROUND(fVar5);
    *(float *)(&DAT_020b943c + iVar4) = (float)*(int *)(puVar3 + -0xe0);
  }
  else {
    *(undefined2 *)(puVar3 + -0xe4) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0xe2) = (ushort)*(undefined4 *)(puVar3 + -0xe4) | 0xc00;
    *(int *)(puVar3 + -0xe0) = (int)ROUND(fVar2);
    _DAT_00829888 = *(int *)(puVar3 + -0xe0);
    _DAT_00829884 = f_0_5;
    fVar5 = (float10)amod(&DAT_00829890,&f_1);
    DAT_00829890 = (float)fVar5;
    if (DAT_00829890 < f_0_25) {
      _DAT_00829884 = f_0;
    }
    if (f_0_75 < DAT_00829890) {
      _DAT_00829884 = f_1;
    }
    *(float *)(&DAT_020b943c + DAT_01be6d60 * 4) = (float)_DAT_00829888 + _DAT_00829884;
    *(undefined4 *)(puVar3 + -0x34) = 0;
  }
  if (DAT_0082989c == *(float *)(&DAT_020b943c + DAT_01be6d60 * 4)) {
    *(undefined4 *)(puVar3 + -0x9c) = 0;
    return;
  }
  DAT_00829890 = *(float *)(&DAT_020b943c + DAT_01be6d60 * 4);
  *(undefined4 *)(puVar3 + -0x98) = 0;
  DAT_0082989c = DAT_00829890;
LAB_004907bc:
  **(int **)(puVar3 + 8) = DAT_01a14950;
  *(float *)(&DAT_020b943c + DAT_01be6d60 * 4) = DAT_00829890;
  _DAT_008298a4 = DAT_00829890;
  *(undefined4 *)(puVar3 + -0x2c) = 0;
LAB_004907ed:
  VEC_N = DAT_01be6d74;
  *DAT_01fbb844 = DAT_01be6d70;
  NPT = 1;
  thunk_FUN_0054c590(&DAT_020b9440,&P1,&DAT_00762d28);
  draw_item();
  if (COLOR == 0) {
    COLOR = 0xff;
  }
  P1 = f_99;
  flush_points();
  *DAT_01fbb7c0 = VEC_N + -1;
  if (DAT_020527c8 < DAT_01be6d60) {
    DAT_020527c8 = DAT_01be6d60;
  }
  FUN_0048ecfb();
  if (DAT_01be6d60 < 3) {
    if ((((P6 == DAT_01c58934) && (P5 == DAT_01c58930)) && (P3 == DAT_01c58928)) &&
       (P4 == DAT_01c5892c)) {
      *(undefined4 *)(puVar3 + -8) = 0;
      return;
    }
  }
  else {
    *(undefined4 *)(puVar3 + -0xc) = 0;
  }
  *(undefined4 *)(puVar3 + -4) = 0;
  thunk_FUN_00549422();
  DAT_0205274c = 1;
  DAT_01c58934 = P6;
  DAT_01c58930 = P5;
  DAT_01c5892c = P4;
  DAT_01c58928 = P3;
  return;
}


