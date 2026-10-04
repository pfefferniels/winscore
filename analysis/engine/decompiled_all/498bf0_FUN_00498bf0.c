// FUN_00498bf0 @ 00498bf0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00498bf0(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar6;
  unkbyte10 Var7;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  float10 extraout_ST1_01;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  if (f_0 <= _DAT_009c6ad4) {
    if (EDIT_ITEM == 0) {
      DAT_00838848 = 999999;
      DAT_0078dc78 = 1;
      DAT_01a14950 = DAT_01a14950 - VIEW_DX;
      DAT_01a1494c = VIEW_DY + DAT_01a1494c;
      LOAD_I = 1;
      iVar4 = ITEM_I;
      while (0 < iVar4) {
        ffree(in_ST0);
        Var7 = load_item_header();
        _DAT_00838844 = f_0;
        if ((3 < LOAD_LEN) &&
           ((_DAT_00838844 = (float)(&ITEM_P4)[LOAD_W], LOAD_CODE < 4 || (LOAD_CODE == 6)))) {
          ffree(Var7);
          fVar6 = (float10)amod(&ITEM_P4 + LOAD_W,&DAT_0076332c);
          _DAT_00838844 = (float)fVar6;
          Var7 = extraout_ST1_00;
        }
        DAT_0078dd70 = 0;
        if (LOAD_CODE == 2) {
          DAT_00838840 = 0;
          if (4 < LOAD_LEN) {
            *(undefined4 *)(puVar5 + -0x68) = (&ITEM_P5)[LOAD_W];
            ffree(Var7);
            fVar6 = (float10)FUN_005ff874(puVar5 + -0x68,&DAT_0076332c);
            *(undefined2 *)(puVar5 + -0x68) = in_FPUControlWord;
            *(ushort *)(puVar5 + -0x66) = (ushort)*(undefined4 *)(puVar5 + -0x68) | 0xc00;
            *(int *)(puVar5 + -100) = (int)ROUND(fVar6);
            in_FPUControlWord = *(undefined2 *)(puVar5 + -0x68);
            DAT_00838840 = *(int *)(puVar5 + -100);
          }
          DAT_0078dd74 = (&DAT_0078dd8c)[DAT_00838840];
LAB_00499289:
          _DAT_00838844 = (float)DAT_0078dd74 + _DAT_00838844;
        }
        else if (LOAD_CODE == 0xe) {
          _DAT_00838844 = f_3;
          *(undefined4 *)(puVar5 + -0x34) = 0;
        }
        else {
          if (LOAD_CODE != 8) {
            if (LOAD_CODE == 6) {
              DAT_0083883c = 0;
              if (6 < LOAD_LEN) {
                fVar1 = *(float *)(&ITEM_P7 + LOAD_W * 4);
                *(undefined2 *)(puVar5 + -0x68) = in_FPUControlWord;
                *(ushort *)(puVar5 + -0x66) = (ushort)*(undefined4 *)(puVar5 + -0x68) | 0xc00;
                *(int *)(puVar5 + -100) = (int)ROUND(ABS(fVar1));
                in_FPUControlWord = *(undefined2 *)(puVar5 + -0x68);
                DAT_0083883c = *(int *)(puVar5 + -100);
              }
              if (DAT_0083883c < 0x14) {
                DAT_0078dd74 = 6;
                DAT_0078dd70 = 2;
              }
              else {
                DAT_0078dd74 = -8;
              }
            }
            else {
              DAT_0078dd74 = *(int *)(&DAT_0078dda8 + LOAD_CODE * 4);
              if (LOAD_CODE == 5) {
                DAT_0083883c = 0;
                if (7 < LOAD_LEN) {
                  fVar1 = *(float *)(&ITEM_P8 + LOAD_W * 4);
                  *(undefined2 *)(puVar5 + -0x68) = in_FPUControlWord;
                  *(ushort *)(puVar5 + -0x66) = (ushort)*(undefined4 *)(puVar5 + -0x68) | 0xc00;
                  *(int *)(puVar5 + -100) = (int)ROUND(fVar1);
                  in_FPUControlWord = *(undefined2 *)(puVar5 + -0x68);
                  DAT_0083883c = *(int *)(puVar5 + -100);
                }
                if (DAT_0083883c == -1) {
                  DAT_0078dd70 = 1;
                }
                else if ((DAT_0083883c == -2) || (DAT_0083883c == -3)) {
                  DAT_0078dd70 = 3;
                }
              }
            }
            goto LAB_00499289;
          }
          _DAT_00838844 = f_3;
          *(undefined4 *)(puVar5 + -0x30) = 0;
        }
        if (200 < LOAD_STAFF) {
          LOAD_P3 = LOAD_P3 + f_227;
        }
        LOAD_P3 = (float)DAT_0078dd70 + LOAD_P3;
        in_ST0 = (float10)_DAT_00838844 * (float10)f_7 * (float10)(float)(&STAFF_STEP0)[LOAD_STAFF];
        iVar4 = (&STAFF_Y0)[LOAD_STAFF];
        *(undefined2 *)(puVar5 + -0x68) = in_FPUControlWord;
        *(ushort *)(puVar5 + -0x66) = (ushort)*(undefined4 *)(puVar5 + -0x68) | 0xc00;
        *(int *)(puVar5 + -100) = (int)ROUND((float10)iVar4 + in_ST0);
        DAT_00838834 = *(int *)(puVar5 + -100);
        *(undefined2 *)(puVar5 + -0x68) = *(undefined2 *)(puVar5 + -0x68);
        *(ushort *)(puVar5 + -0x66) = (ushort)*(undefined4 *)(puVar5 + -0x68) | 0xc00;
        *(int *)(puVar5 + -100) = (int)ROUND(LOAD_P3 * f_150);
        in_FPUControlWord = *(undefined2 *)(puVar5 + -0x68);
        DAT_00838830 = *(int *)(puVar5 + -100);
        DAT_0083882c = DAT_00838830 - DAT_01a14950;
        DAT_00838828 = DAT_00838834 - DAT_01a1494c;
        *(int *)(puVar5 + -100) = DAT_0083882c * DAT_0083882c + DAT_00838828 * DAT_00838828;
        _DAT_00838824 = (float)*(int *)(puVar5 + -100);
        DAT_00838838 = DAT_00838834;
        if (f_0 <= _DAT_00838824) {
          ffree(in_ST0);
          fVar6 = (float10)FUN_005ff146(puVar5,0x4993cd);
          _DAT_00838824 = (float)fVar6;
          *(undefined2 *)(puVar5 + -0x68) = in_FPUControlWord;
          *(ushort *)(puVar5 + -0x66) = (ushort)*(undefined4 *)(puVar5 + -0x68) | 0xc00;
          *(int *)(puVar5 + -100) = (int)ROUND(_DAT_00838824);
          in_FPUControlWord = *(undefined2 *)(puVar5 + -0x68);
          DAT_00838820 = *(int *)(puVar5 + -100);
          in_ST0 = extraout_ST1_01;
          if (((DAT_00790d70 != LOAD_I) && (DAT_00838820 < DAT_00838848)) && (EDIT_ITEM != LOAD_I))
          {
            DAT_0078dc78 = LOAD_I;
            DAT_00838848 = DAT_00838820;
          }
        }
        else {
          *(undefined4 *)(puVar5 + -0x2c) = 0;
        }
        *(undefined4 *)(puVar5 + -0x28) = 0;
        LOAD_I = LOAD_I + 1;
        *(int *)(puVar5 + -0x38) = *(int *)(puVar5 + -0x38) + -1;
        iVar4 = *(int *)(puVar5 + -0x38);
      }
      if (EDIT_ITEM == 0) {
        EDIT_ITEM = DAT_0078dc78;
      }
      DAT_0083881c = 2;
      DAT_0078dc45 = 0;
      DAT_00790d70 = DAT_0078dc78;
      DAT_01a14bb4 = DAT_0078dc78;
      if (DAT_0078de20 == 9) {
        ffree(in_ST0);
        DAT_020b8ea0._0_1_ = DAT_00763320;
        DAT_020b90a0 = DAT_00763320;
        Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0xa0,&DAT_00763314,&DAT_0076336c,"(1i4)",5,
                                  &DAT_0078dc78);
        ffree(Var7);
        in_ST0 = (float10)thunk_FUN_0058c2c9(&DAT_020b90a0,0xa0,&DAT_00763314,&DAT_0076336c,"(1i4)",
                                             5,&DAT_0078dc78);
        DAT_0078b4e0 = 0x58;
        P2 = (float)DAT_0078dc78;
        DAT_01fbb7e4 = 1;
      }
      else if (DAT_0078de20 == 8) {
        ffree(in_ST0);
        DAT_020b8ea0._0_1_ = DAT_00763310;
        Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0xa0,&DAT_00763314,&DAT_0076336c,"(1i4)",5,
                                  &DAT_0078dc78);
        ffree(Var7);
        in_ST0 = (float10)thunk_FUN_00518b3f(&DAT_0076336c);
      }
      else {
        DAT_0083881c = 1;
      }
      DAT_00838818 = 5;
      DAT_0078b388 = 5;
      DAT_01fbb7fc = 0xd;
      _DAT_01fbb7f4 = 1;
      *(undefined4 *)(puVar5 + -0x24) = 0;
    }
    else {
      DAT_0083881c = 99000;
      DAT_00838818 = 1;
      for (iVar4 = MAX_STAFF; 0 < iVar4; iVar4 = iVar4 + -1) {
        DAT_00838814 = DAT_01a1494c - (&STAFF_MID0)[DAT_00838818];
        if (DAT_00838814 < 0) {
          DAT_00838814 = -DAT_00838814;
        }
        iVar2 = DAT_00838818;
        iVar3 = DAT_00838814;
        if (DAT_0083881c <= DAT_00838814) {
          iVar2 = DAT_00838810;
          iVar3 = DAT_0083881c;
        }
        DAT_0083881c = iVar3;
        DAT_00838810 = iVar2;
        DAT_00838818 = DAT_00838818 + 1;
      }
      _DAT_0083880c = f_25 / (float)(&STAFF_STEP0)[DAT_00838810];
      FUN_005f34d1(&stack0xfffffffc,0x498cfc);
      FUN_005f33c9(puVar8,0x498d1e);
      FUN_005f34d1(puVar8,0x498d39);
      P3 = (float)DAT_01a14950 / f_150;
      *(int *)(puVar8 + -100) = (&STAFF_MID0)[DAT_00838810] - DAT_01a1494c;
      ffree((float10)*(int *)(puVar8 + -100));
      fVar6 = (float10)FUN_005ff381(puVar8,0x498d87);
      *(int *)(puVar8 + -100) = (int)ROUND(fVar6);
      P4 = f_7 - (float)*(int *)(puVar8 + -100);
      ffree(extraout_ST1);
      Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00763368,&DAT_0076336c,"(1i3)",5,
                                &DAT_00838810);
      ffree(Var7);
      in_ST0 = (float10)thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00763358,&DAT_0076335c,"(1f8.3)"
                                           ,7,&P3);
      if (DAT_020b8e50 == 0xe) {
        *(undefined4 *)(puVar8 + -0x14) = 0;
      }
      else {
        DAT_020b8eb0._1_1_ = 0x34;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00763348,&DAT_0076334c,
                                             "(1f7.3)",7,&P4);
        if (((DAT_0078dc30 == 1) || (DAT_020b8e50 < 4)) || (8 < DAT_020b8e50)) {
          *(undefined4 *)(puVar8 + -0x10) = 0;
        }
        else if (DAT_0078dc30 == 0) {
          *(undefined4 *)(puVar8 + -0xc) = 0;
          P6 = (P3 + DAT_020b9454) - DAT_020b9448;
          DAT_020b8ebc._0_1_ = DAT_00763344;
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_0076333c,&DAT_00763340,
                                               "(1f7.3)",7,&P6);
          if ((DAT_020b8e50 < 7) && (DAT_020b9450 != f_999)) {
            P5 = (P4 + DAT_020b9450) - DAT_020b944c;
            DAT_020b8ec7 = 0x35;
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00763330,&DAT_00763334,
                                                 "(1f7.3)",7,&P5);
          }
          else {
            *(undefined4 *)(puVar8 + -4) = 0;
          }
        }
        else {
          DAT_020b8ea6 = DAT_00763344;
          DAT_020b8eb0._1_1_ = 0x35;
          if ((DAT_020b9450 == f_999) || (6 < DAT_020b8e50)) {
            DAT_020b8eb0._1_1_ = 0x30;
          }
          *(undefined4 *)(puVar8 + -8) = 0;
        }
      }
    }
  }
  DAT_0171b230 = 0;
  ffree(in_ST0);
  return;
}


