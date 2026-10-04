// draw_clef @ 00431ae0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_clef(undefined4 param_1,float *param_2,int *param_3,float *param_4,float *param_5)

{
  undefined1 *puVar1;
  int iVar2;
  unkbyte10 in_ST0;
  unkbyte10 Var3;
  float10 fVar4;
  float10 fVar5;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  unkbyte10 extraout_ST1_05;
  unkbyte10 extraout_ST1_06;
  unkbyte10 extraout_ST1_07;
  unkbyte10 extraout_ST1_08;
  unkbyte10 extraout_ST1_09;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  
  puVar1 = &stack0xfffffffc;
  if (P7 == f_99) {
    ffree(in_ST1);
    ffree(in_ST0);
    Var3 = push_words(&DAT_00760048,&P1);
    P1 = f_9;
    P3 = f_m4;
    P4 = f_21;
    P5 = f_269;
    P6 = f_1_4;
    P7 = f_0;
    ffree(extraout_ST1);
    ffree(Var3);
    Var3 = draw_item();
    ffree(extraout_ST1_00);
    ffree(Var3);
    in_ST0 = pop_words(&DAT_00760048,&P1);
    P5 = f_m5;
    P3 = f_m4;
    P7 = f_0;
    P6 = f_0_1;
    P1 = f_4;
    DAT_007f1520 = -5;
    iVar2 = 0xe;
    DAT_007f151c = 1;
    Var3 = extraout_ST1_01;
    do {
      ffree(Var3);
      ffree(in_ST0);
      P4 = P5;
      in_ST0 = draw_item();
      DAT_007f1520 = DAT_007f1520 + 2;
      P4 = (float)DAT_007f1520;
      DAT_007f151c = DAT_007f151c + 1;
      iVar2 = iVar2 + -1;
      Var3 = extraout_ST1_02;
      P5 = P4;
    } while (0 < iVar2);
    P26 = f_990000;
    in_ST1 = extraout_ST1_02;
    goto LAB_004322ff;
  }
  _DAT_007f1518 = *param_2;
  DAT_007f1514 = *param_4;
  _DAT_007f1510 = *param_5;
  if (DAT_007f1514 == f_0) {
    DAT_007f1514 = f_1;
  }
  if (_DAT_007f1510 == f_0) {
    _DAT_007f1510 = DAT_007f1514;
  }
  DAT_007f150c = *param_3 + 1;
  if (DAT_007f150c < 7) {
    if (DAT_007f150c < 1) {
      DAT_007f150c = 1;
    }
    _DAT_007f1508 = f_21;
    iVar2 = IP4;
    if (IP4 < 0) {
      iVar2 = -IP4;
    }
    if (99 < iVar2) {
      _DAT_007f1510 = DAT_007f1514 * f_0_8;
      _DAT_007f1508 = f_21 + *(float *)(DAT_007f150c * 4 + 0x78f308);
      DAT_007f1514 = _DAT_007f1510;
    }
    if (DAT_007f150c == 4) {
      _DAT_007f1508 = _DAT_007f1508 + f_14;
      DAT_007f150c = 3;
      *param_3 = 2;
    }
    _DAT_007f1518 = STEP * _DAT_007f1508 + _DAT_007f1518;
  }
  if (IP1 == 3) {
    ffree(in_ST1);
    ffree(in_ST0);
    puVar1 = &stack0xfffffffc;
    fVar4 = (float10)FUN_005ff381(&stack0xfffffffc,0x431dd3);
    *(int *)(puVar1 + -100) = (int)ROUND(fVar4);
    DAT_007f151c = *(int *)(puVar1 + -100);
    if (DAT_007f151c < 0) {
      DAT_007f151c = -DAT_007f151c;
    }
    if (DAT_007f151c == 0xb4) {
      *(undefined4 *)(puVar1 + -0x28) = 0;
    }
    else if ((DAT_007f151c == 0) || (99 < DAT_007f151c)) {
      *(undefined4 *)(puVar1 + -0x24) = 0;
      in_ST0 = extraout_ST1_03;
      goto LAB_00432030;
    }
    DAT_007f1504 = **(undefined4 **)(puVar1 + 8);
    DAT_007f1500 = 0;
    DAT_007f14fc = P3;
    DAT_007f14f8 = P4;
    DAT_007f14f4 = P6;
    P6 = f_m5_25;
    _DAT_007f14f0 = f_0_08;
    if ((DAT_007f151c == 0x58) || (DAT_007f151c == 0xf)) {
      P6 = f_10_95;
      _DAT_007f14f0 = f_0_085;
      if (DAT_007f151c == 0x58) {
        _DAT_007f14f0 = f_0_12;
      }
      *(undefined4 *)(puVar1 + -0x1c) = 0;
    }
    else {
      *(undefined4 *)(puVar1 + -0x20) = 0;
      if (DAT_007f151c == 0xb4) {
        DAT_007f151c = 0x50;
        P6 = f_0;
        DAT_007f1500 = 1;
        _DAT_007f14f0 = f_0_06;
      }
      else {
        *(undefined4 *)(puVar1 + -0x18) = 0;
      }
    }
    ffree(in_ST1);
    ffree(extraout_ST1_03);
    fVar4 = (float10)amod(&P4,&f_100);
    P4 = (float)((float10)DAT_007f1514 * (float10)P6 + fVar4 + (float10)f_3);
    fVar4 = (float10)P3;
    P3 = (float)((float10)STEP * (float10)_DAT_007f14f0 * (float10)DAT_007f1514 +
                (float10)P15 + fVar4);
    ffree(in_ST2);
    ffree((float10)P15 + fVar4);
    Var3 = item_position();
    P6 = DAT_007f1514 * f_0_7;
    IP7 = 0xb;
    DAT_007f151c = DAT_007f151c / 10;
    if (DAT_007f151c == 1) {
      DAT_007f151c = 0xf;
    }
    DAT_007f14ec = P5;
    P5 = (float)DAT_007f151c;
    ffree(extraout_ST1_04);
    ffree(Var3);
    in_ST0 = draw_number(&DAT_007f151c);
    P5 = DAT_007f14ec;
    **(undefined4 **)(puVar1 + 8) = DAT_007f1504;
    IP1 = 3;
    **(int **)(puVar1 + 0x10) = DAT_007f1500;
    P3 = DAT_007f14fc;
    P4 = DAT_007f14f8;
    P6 = DAT_007f14f4;
    in_ST1 = extraout_ST1_05;
    in_ST2 = in_ST3;
  }
LAB_00432030:
  if ((IP1 == 3) && ((DAT_007f150c == 0x43 || DAT_007f150c == 0x2d) || DAT_007f150c == 0x38)) {
    DAT_007f1514 = DAT_007f1514 * f_0_1;
    _DAT_007f1510 = _DAT_007f1510 * f_0_1;
    **(undefined4 **)(puVar1 + 0x10) = 3;
    if (DAT_007f150c == 0x2d) {
      DAT_007f1514 = DAT_007f1514 * f_0_6;
      _DAT_007f1510 = _DAT_007f1510 * f_0_6;
      *(float *)(puVar1 + -0x68) = P4 + f_1_2;
      ffree(in_ST1);
      ffree(in_ST0);
      in_ST1 = in_ST2;
      fVar4 = (float10)staff_level_y(puVar1 + -0x68);
      _DAT_007f1518 = (float)fVar4;
      in_ST0 = extraout_ST1_06;
    }
    else if (DAT_007f150c == 0x38) {
      DAT_007f1514 = DAT_007f1514 * f_0_83;
      _DAT_007f1510 = _DAT_007f1510 * f_0_83;
      *(float *)(puVar1 + -0x68) = P4 + f_0_35;
      ffree(in_ST1);
      ffree(in_ST0);
      in_ST1 = in_ST2;
      fVar4 = (float10)staff_level_y(puVar1 + -0x68);
      _DAT_007f1518 = (float)fVar4;
      in_ST0 = extraout_ST1_07;
    }
    *(undefined4 *)(puVar1 + -0x10) = 0;
  }
  else {
    *(undefined4 *)(puVar1 + -0x14) = 0;
    if (DAT_007f150c < 0x2e) {
      if (OUTPUT_MODE == 0) {
        *(undefined4 *)(puVar1 + -8) = 0;
        DAT_007f1500 = *(int *)(&DAT_01c5a518 + DAT_007f150c * 4) + -1;
        DAT_007f1514 = STEP * DAT_007f1514;
        _DAT_007f1510 = STEP * _DAT_007f1510;
        DAT_007f151c = *(int *)(&DAT_01c5a514 + DAT_007f150c * 4);
        for (iVar2 = (DAT_007f1500 - DAT_007f151c) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
          fVar4 = (float10)DAT_007f1514 * (float10)*(float *)(&DAT_01c5963c + DAT_007f151c * 4) +
                  (float10)**(float **)(puVar1 + 8);
          fVar5 = (float10)_DAT_007f1510 * (float10)*(float *)(&DAT_01c59da8 + DAT_007f151c * 4) +
                  (float10)_DAT_007f1518;
          *(float *)(puVar1 + -0x68) = (float)fVar4;
          *(float *)(puVar1 + -0x70) = (float)fVar5;
          ffree(fVar5);
          ffree(fVar4);
          in_ST0 = add_point(puVar1 + -0x68,puVar1 + -0x70,&DAT_01c5a5cc + DAT_007f151c * 4);
          DAT_007f151c = DAT_007f151c + 1;
          in_ST1 = extraout_ST1_08;
        }
        goto LAB_004322ff;
      }
      DAT_007f1514 = DAT_007f1514 * f_0_25;
      if (DAT_007f1514 == f_0) {
        DAT_007f1514 = f_0_25;
      }
      _DAT_007f1510 = _DAT_007f1510 * f_0_25;
    }
    else {
      *(undefined4 *)(puVar1 + -0xc) = 0;
    }
  }
  ffree(in_ST1);
  ffree(in_ST0);
  in_ST0 = draw_symbol(*(undefined4 *)(puVar1 + 8),&DAT_007f1518,*(undefined4 *)(puVar1 + 0x10),
                       &DAT_007f1514,&DAT_007f1510,&DAT_0075ffd8,&DAT_0075ffd8,&DAT_0075ffd8);
  *(undefined4 *)(puVar1 + -4) = 0;
  in_ST1 = extraout_ST1_09;
LAB_004322ff:
  ffree(in_ST1);
  ffree(in_ST0);
  return;
}


