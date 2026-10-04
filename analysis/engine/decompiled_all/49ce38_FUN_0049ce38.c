// FUN_0049ce38 @ 0049ce38 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049ce38(float *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  unkbyte10 in_ST0;
  float10 fVar4;
  unkbyte10 Var5;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  
  ffree(in_ST0);
  fVar4 = (float10)thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I,&ITEM_WORDS);
  DAT_008389ac = 0;
  DAT_020b8e44 = ITEM_WORDS;
  DAT_008389a8 = (float)ITEM_I;
  _DAT_008389a4 = *param_1;
  DAT_01b117b0 = 0.0;
  iVar2 = DAT_01c4c83c - (int)DAT_01c4c838;
  DAT_008389a0 = DAT_01c4c838;
  do {
    if (iVar2 < 1) {
      *param_1 = f_m1;
      fVar3 = DAT_00838994;
LAB_0049d782:
      DAT_00838994 = fVar3;
      ffree(fVar4);
      fVar4 = (float10)thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I,&ITEM_WORDS);
      DAT_01b117ac = DAT_008389a8;
      DAT_00838994 = DAT_008389a8;
      for (iVar2 = (ITEM_I - (int)DAT_008389a8) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
        DAT_01b117a4 = (float)(&ITEM_PTR0)[(int)DAT_00838994];
        DAT_0083898c = (int)ROUND((float)(&ITEM_P1)[(int)DAT_01b117a4]);
        if ((DAT_0083898c == 5) &&
           ((float)(&ITEM_P4)[(int)DAT_01b117a4] != (float)(&ITEM_P5)[(int)DAT_01b117a4])) {
          ffree(fVar4);
          Var5 = FUN_0049dbb2(&ITEM_P3 + (int)DAT_01b117a4,&ITEM_P4 + (int)DAT_01b117a4);
          ffree(Var5);
          fVar4 = (float10)FUN_0049dbb2(&ITEM_P6 + (int)DAT_01b117a4,&ITEM_P5 + (int)DAT_01b117a4);
        }
        else if (DAT_0083898c == 6) {
          ffree(fVar4);
          Var5 = FUN_0049daa6(&ITEM_P3 + (int)DAT_01b117a4,&ITEM_P4 + (int)DAT_01b117a4);
          ffree(Var5);
          Var5 = FUN_0049daa6(&ITEM_P6 + (int)DAT_01b117a4,&DAT_01b117a0);
          ffree(Var5);
          fVar4 = (float10)amod(&DAT_01b117a0,&f_100);
          DAT_01c4c850 = (float)fVar4;
          ffree(extraout_ST1);
          fVar4 = (float10)amod(&ITEM_P4 + (int)DAT_01b117a4,&f_100);
          DAT_01b117a0 = (float)fVar4;
          DAT_01c4c854 = ((float)(&ITEM_P6)[(int)DAT_01b117a4] -
                         (float)(&ITEM_P3)[(int)DAT_01b117a4]) / f_4;
          if ((DAT_01c4c854 < f_1) && (DAT_01c4c854 != f_0)) {
            DAT_01c4c854 = f_1;
          }
          if (DAT_01c4c854 <= ABS(DAT_01c4c850 - DAT_01b117a0)) {
            if (DAT_01c4c850 <= DAT_01b117a0) {
              DAT_01c4c850 = DAT_01b117a0 - DAT_01c4c854;
            }
            else {
              DAT_01b117a0 = DAT_01c4c850 - DAT_01c4c854;
            }
          }
          DAT_01c4c854 = f_100;
          fVar4 = extraout_ST1_00;
          if (DAT_01b117a0 < f_0) {
            fVar4 = (float10)f_100;
            DAT_01c4c854 = (float)-fVar4;
          }
          (&ITEM_P4)[(int)DAT_01b117a4] = DAT_01c4c854 + DAT_01b117a0;
          (&ITEM_P5)[(int)DAT_01b117a4] = DAT_01c4c850;
        }
        DAT_00838994 = (float)((int)DAT_00838994 + 1);
      }
LAB_0049da9b:
      ffree(fVar4);
      return;
    }
    DAT_0083899c = (&DAT_01c4637c)[(int)DAT_008389a0];
    if ((((float)(&DAT_01c6da60)[DAT_0083899c] == f_8) &&
        (f_9 <= *(float *)(&DAT_01c6da5c + DAT_0083899c * 4))) &&
       (_DAT_008389a4 == (float)(&DAT_01c6da80)[DAT_0083899c])) {
      _DAT_00838998 = (float)(&DAT_01c6da64)[DAT_0083899c];
      break;
    }
    DAT_008389a0 = (float)((int)DAT_008389a0 + 1);
    iVar2 = iVar2 + -1;
  } while( true );
LAB_0049cf8d:
  DAT_00838994 = DAT_008389a0;
  do {
    fVar3 = (float)((int)DAT_00838994 + 1);
    DAT_0083899c = (&DAT_01c4637c)[(int)fVar3];
    if ((_DAT_00838998 == (float)(&DAT_01c6da64)[DAT_0083899c]) &&
       (_DAT_00838990 = (float)(&DAT_01c6da68)[DAT_0083899c], _DAT_01c4c858 <= _DAT_00838990)) {
      if (_DAT_01c4c85c < _DAT_00838990) goto LAB_0049d782;
      if (DAT_01b117b0 == 0.0) {
        DAT_01b117a0 = DAT_00838994;
        fVar1 = DAT_01b117b0;
        for (iVar2 = (((int)DAT_008389a0 - (int)DAT_00838994) + -1) / -1; 0 < iVar2;
            iVar2 = iVar2 + -1) {
          DAT_01b117a4 = (float)(&DAT_01c4637c)[(int)DAT_01b117a0];
          DAT_0083898c = (int)ROUND((float)(&DAT_01c6da60)[(int)DAT_01b117a4]);
          if ((float)(&DAT_01c6da60)[(int)DAT_01b117a4] == f_1) {
            if ((*(float *)(&DAT_01c6da78 + (int)DAT_01b117a4 * 4) != f_65) ||
               (fVar4 = (float10)(float)(&DAT_01c6da6c)[(int)DAT_01b117a4],
               DAT_01b117b0 = DAT_01b117a0, ABS(fVar4) < (float10)f_100)) break;
          }
          else if ((0x10 < DAT_0083898c) ||
                  ((DAT_0083898c == 0xe || (DAT_01b117b0 = fVar1, DAT_0083898c == 2)))) break;
          DAT_01b117a0 = (float)((int)DAT_01b117a0 + -1);
          fVar1 = DAT_01b117b0;
        }
        if (fVar1 != 0.0) break;
      }
      DAT_01b117b0 = 1.4013e-45;
      DAT_01b117ac = (float)(int)ROUND(*(float *)(&DAT_01c6da5c + DAT_0083899c * 4));
      DAT_00838994 = fVar3;
      (&DAT_01c6da64)[DAT_0083899c] = DAT_01ba2084;
      DAT_0083898c = (int)ROUND((float)(&DAT_01c6da60)[DAT_0083899c]);
      if ((DAT_0083898c < 3) || (DAT_0083898c == 6)) {
        if ((DAT_0083898c == 2) &&
           ((f_13 <= *(float *)(&DAT_01c6da5c + DAT_0083899c * 4) &&
            (fVar3 = DAT_00838994, _DAT_008389a4 == *(float *)(&DAT_01c6da90 + DAT_0083899c * 4)))))
        goto LAB_0049d708;
        DAT_01b117a4 = (float)(&DAT_01c6da6c)[DAT_0083899c];
        fVar4 = (float10)DAT_01b117a4;
        if (ABS(fVar4) < (float10)f_100) {
          DAT_01b117a0 = f_100;
          if (DAT_01b117a4 < f_0) {
            fVar4 = (float10)f_100;
            DAT_01b117a0 = (float)-fVar4;
          }
          (&DAT_01c6da6c)[DAT_0083899c] = DAT_01b117a0 + DAT_01b117a4;
        }
        if (DAT_0083898c != 1) {
          if (DAT_0083898c == 6) {
            DAT_008389ac = 1;
            DAT_01b117a0 = *(float *)(&DAT_01c6da78 + DAT_0083899c * 4);
            fVar4 = (float10)DAT_01b117a0;
            if ((float10)f_20 <= ABS(fVar4)) {
              DAT_01b117a4 = f_10;
              if (DAT_01b117a0 < f_0) {
                fVar4 = (float10)f_10;
                DAT_01b117a4 = (float)-fVar4;
              }
              *(float *)(&DAT_01c6da78 + DAT_0083899c * 4) = DAT_01b117a0 - DAT_01b117a4;
            }
          }
          goto LAB_0049d3f3;
        }
        DAT_01b117a0 = (float)(&DAT_01c6da70)[DAT_0083899c];
        DAT_01b117a4 = f_0;
        if (f_20 <= DAT_01b117a0) {
          DAT_01b117a4 = f_m10;
        }
        if (DAT_01b117a0 < f_10) {
          DAT_01b117a4 = f_10;
        }
        (&DAT_01c6da70)[DAT_0083899c] = DAT_01b117a4 + DAT_01b117a0;
        if ((7 < (int)DAT_01b117ac) && ((float)(&DAT_01c6da7c)[DAT_0083899c] < f_20)) {
          (&DAT_01c6da7c)[DAT_0083899c] = f_0;
        }
        if ((10 < (int)DAT_01b117ac) && ((float)(&DAT_01c6da88)[DAT_0083899c] != f_0)) {
          fVar4 = (float10)(float)(&DAT_01c6da88)[DAT_0083899c];
          DAT_01b117a0 = (float)(int)ROUND(ABS(fVar4));
          (&DAT_01c6da88)[DAT_0083899c] = (float)-(int)DAT_01b117a0;
        }
      }
      else {
LAB_0049d3f3:
        if (DAT_0083898c == 5) {
          DAT_008389ac = 1;
          DAT_01b117a4 = *(float *)(&DAT_01c6da78 + DAT_0083899c * 4);
          if (f_0 <= DAT_01b117a4) {
            fVar4 = (float10)DAT_01b117a4;
            *(float *)(&DAT_01c6da78 + DAT_0083899c * 4) = (float)-fVar4;
            DAT_01b117a0 = (float)(&DAT_01c6da7c)[DAT_0083899c];
            if ((DAT_01b117a0 == f_m2) || (DAT_01b117a0 == f_m3)) {
              DAT_01b117a4 = f_1_8;
            }
            else {
              if (DAT_01b117a0 == f_m4) {
                (&DAT_01c6da7c)[DAT_0083899c] = f_m1;
              }
              DAT_01b117a4 = f_3_8;
            }
            (&DAT_01c6da6c)[DAT_0083899c] = (float)(&DAT_01c6da6c)[DAT_0083899c] - DAT_01b117a4;
            (&DAT_01c6da70)[DAT_0083899c] = (float)(&DAT_01c6da70)[DAT_0083899c] - DAT_01b117a4;
          }
        }
      }
      DAT_01b117ac = (float)(int)ROUND(*(float *)(&DAT_01c6da5c + DAT_0083899c * 4) + f_1);
      ffree(fVar4);
      fVar4 = (float10)thunk_FUN_0054c590(&DAT_01c6da5c + DAT_0083899c * 4,&ITEM_LEN + ITEM_WORDS,
                                          &DAT_01b117ac);
      ITEM_WORDS = (int)DAT_01b117ac + ITEM_WORDS;
      fVar3 = DAT_00838994;
    }
LAB_0049d708:
    DAT_00838994 = fVar3;
    if (DAT_01c4c83c + -1 <= (int)DAT_00838994) {
      fVar3 = DAT_00838994;
      if (DAT_008389ac != 0) goto LAB_0049d782;
      goto LAB_0049da9b;
    }
  } while( true );
  _DAT_01c4c858 = (float)(&DAT_01c6da68)[(&DAT_01c4637c)[(int)fVar1]];
  DAT_01b117b0 = fVar1;
  goto LAB_0049cf8d;
}


