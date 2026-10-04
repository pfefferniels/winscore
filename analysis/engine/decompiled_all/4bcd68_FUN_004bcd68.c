// FUN_004bcd68 @ 004bcd68 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bcd68(int *param_1,int *param_2,float *param_3,float *param_4,int *param_5,
                 float *param_6,float *param_7,float *param_8,float *param_9,int param_10,
                 int param_11,int param_12)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  float10 in_ST0;
  float10 fVar4;
  float10 extraout_ST0;
  unkbyte10 Var5;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 extraout_ST1_03;
  int local_1d8;
  
  DAT_0089f998 = 0;
  DAT_0089f994 = 0;
  DAT_0089f990 = *param_6 - f_0_001;
  _DAT_0089f98c = *param_7 + f_0_001;
  DAT_0089f988 = (int)ROUND(*param_3);
  DAT_0089f984 = *param_5;
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    ffree(in_ST0);
    fVar4 = (float10)load_item_header();
    if (((LOAD_CODE < 5) || (LOAD_CODE == 0xe)) ||
       ((LOAD_CODE == 10 && ((0xf < LOAD_LEN && (*(float *)(&ITEM_P16 + LOAD_W * 4) != f_0)))))) {
LAB_004bcec2:
      ffree(fVar4);
      in_ST0 = (float10)thunk_FUN_004b6ced(&LOAD_W,&DAT_0089f980);
      if (DAT_0089f984 < DAT_01c58920) break;
      if ((DAT_0089f990 <= DAT_01c58924) && (DAT_01c58924 <= _DAT_0089f98c)) {
        if (LOAD_CODE == 0xe) {
          if (((DAT_0089f988 <= DAT_01c58920) && (f_0 <= DAT_01c58928)) && (DAT_01c5892c <= f_7)) {
            if (DAT_01c58928 == f_0) {
              DAT_01c58928 = f_1;
            }
            in_ST0 = (float10)DAT_0089f984;
            if (in_ST0 < (float10)DAT_01c58920 + (float10)DAT_01c58928) goto LAB_004bd1ac;
          }
        }
        else if ((*param_1 <= LOAD_I) && (DAT_0089f984 == DAT_01c58920)) {
          if (LOAD_CODE == 1) {
LAB_004bd18d:
            if (DAT_01c58934 < f_0) goto LAB_004bd1ee;
          }
          else {
            if (LOAD_CODE == 2) {
              if (DAT_01c58930 < f_0) goto LAB_004bd1ee;
              goto LAB_004bd18d;
            }
            if (LOAD_CODE == 3) {
              if (f_5 < DAT_01c5892c) goto LAB_004bd1ee;
            }
            else if (LOAD_CODE == 4) {
              if ((((float)(&ITEM_P6)[LOAD_W] != f_0) || (LOAD_LEN < 7)) ||
                 (f_m1 < *(float *)(&ITEM_P7 + LOAD_W * 4))) goto LAB_004bd1ee;
            }
            else if ((LOAD_CODE != 10) && (LOAD_CODE == 0x12)) {
              DAT_0089f97c = DAT_01c58934;
              if (DAT_01c58934 == f_0) {
                DAT_0089f97c = f_1;
              }
              if (f_2 < ABS(DAT_0089f97c * DAT_01c58928)) goto LAB_004bd1ee;
            }
          }
LAB_004bd1ac:
          DAT_0089f994 = DAT_0089f994 + 1;
          *(float *)(param_12 + -4 + DAT_0089f994 * 4) = DAT_01c58924;
          *(int *)(DAT_0089f994 * 4 + param_11 + -4) = LOAD_W;
        }
      }
    }
    else {
      bVar3 = 0x10 < LOAD_CODE;
      ffree(fVar4);
      iVar1 = thunk_FUN_005358e5(&LOAD_W);
      in_ST0 = extraout_ST0;
      fVar4 = extraout_ST0;
      if (bVar3 && iVar1 == 0) goto LAB_004bcec2;
    }
LAB_004bd1ee:
    LOAD_I = LOAD_I + 1;
  }
  if (1 < DAT_0089f994) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_004b6e38(&DAT_0089f994,param_12,param_11);
    DAT_0089f97c = *param_4 * f_0_04;
    *param_8 = DAT_0089f990;
    *param_9 = f_0;
    *param_2 = 1;
    _DAT_0089f978 = f_0;
    DAT_0089f974 = 0;
    DAT_0089f970 = 0;
    do {
      DAT_0089f970 = DAT_0089f970 + 1;
      DAT_0089f96c = *(int *)(DAT_0089f970 * 4 + param_11 + -4);
      DAT_0089f968 = (int)ROUND((float)(&ITEM_P1)[DAT_0089f96c]);
      ffree(in_ST0);
      Var5 = thunk_FUN_004b6ced(&DAT_0089f96c,&DAT_0089f980);
      DAT_0089f964 = f_0;
      DAT_0089f960 = f_0;
      _DAT_0089f95c = f_1;
      ffree(Var5);
      fVar4 = (float10)amod(&DAT_01c58928,&f_100);
      DAT_0089f958 = (float)fVar4;
      in_ST0 = extraout_ST1;
      if (DAT_0089f968 < 2) {
        DAT_0089f954 = (int)ROUND(DAT_01c58930);
        _DAT_0089f950 = DAT_00792554;
        if ((DAT_0089f954 < 0x14) && (DAT_0089f954 % 10 == 3 || DAT_0089f954 % 10 == 2)) {
          _DAT_0089f950 = DAT_00792550;
        }
        DAT_0089f94c = DAT_0089f970;
        DAT_0089f948 = (int)ROUND(DAT_01c5892c);
        if (100 < DAT_0089f948) {
          ffree(extraout_ST1);
          fVar4 = (float10)amod(&DAT_01c5892c,&f_100);
          DAT_01c5892c = (float)fVar4;
          in_ST0 = extraout_ST1_00;
        }
        DAT_0089f944 = (int)ROUND(DAT_01c5892c / f_10);
        while (DAT_0089f944 != 1) {
          if ((DAT_0089f944 != 0) || (DAT_0089f994 <= DAT_0089f94c)) goto LAB_004bdeb1;
          DAT_0089f94c = DAT_0089f94c + 1;
          DAT_0089f940 = *(int *)(DAT_0089f94c * 4 + param_11 + -4);
          if (((float)(&ITEM_P1)[DAT_0089f940] != f_1) ||
             (DAT_01c58924 != (float)(&ITEM_P3)[DAT_0089f940])) goto LAB_004bdeb1;
          DAT_0089f944 = ((int)ROUND((float)(&ITEM_P5)[DAT_0089f940]) % 100) / 10;
        }
        if (DAT_0089f94c < DAT_0089f994) {
          DAT_0089f940 = *(int *)(DAT_0089f94c * 4 + param_11);
          local_1d8 = (int)ROUND((float)(&ITEM_P1)[DAT_0089f940]);
          if (local_1d8 == 0xe) {
LAB_004bdce7:
            do {
              DAT_0089f94c = DAT_0089f94c + 1;
              if (((DAT_0089f994 <= DAT_0089f94c) ||
                  (DAT_0089f940 = *(int *)(DAT_0089f94c * 4 + param_11),
                  (int)ROUND((float)(&ITEM_P1)[DAT_0089f940]) != 1)) ||
                 (_DAT_0089f938 != (float)(&ITEM_P3)[DAT_0089f940])) goto LAB_004bde38;
            } while ((int)ROUND((float)(&ITEM_P5)[DAT_0089f940]) % 100 < 10);
            if (0x13 < (int)ROUND((float)(&ITEM_P5)[DAT_0089f940]) % 100) {
LAB_004bde38:
              _DAT_0089f938 = f_1_5;
              if (DAT_01c5893c != f_0) {
                _DAT_0089f938 = f_0_5;
              }
              _DAT_0089f950 = _DAT_0089f938 + _DAT_0089f950;
            }
          }
          else {
            _DAT_0089f938 = (float)(&ITEM_P3)[DAT_0089f940];
            while (local_1d8 == 1) {
              if (0x13 < (int)ROUND((float)(&ITEM_P5)[DAT_0089f940]) % 100) goto LAB_004bdce7;
              if (((9 < (int)ROUND((float)(&ITEM_P5)[DAT_0089f940]) % 100) ||
                  (_DAT_0089f938 != (float)(&ITEM_P3)[DAT_0089f940])) ||
                 (DAT_0089f994 <= DAT_0089f94c)) break;
              DAT_0089f94c = DAT_0089f94c + 1;
              DAT_0089f940 = *(int *)(DAT_0089f94c * 4 + param_11 + -4);
              local_1d8 = (int)ROUND((float)(&ITEM_P1)[DAT_0089f940]);
            }
          }
LAB_004bdeb1:
          if (DAT_0089f974 != DAT_0089f930) {
            DAT_0089f974 = 0;
          }
          DAT_0089f930 = 0;
          DAT_0089f934 = DAT_0089f970 + 1;
          iVar2 = (DAT_0089f994 - DAT_0089f934) + 2;
          DAT_0089f944 = DAT_0089f970;
          DAT_0089f92c = DAT_01c5892c;
          while (((0 < iVar2 && (DAT_0089f970 = DAT_0089f934, DAT_0089f934 <= DAT_0089f994)) &&
                 (((float)(&ITEM_P1)[*(int *)(param_11 + -4 + DAT_0089f934 * 4)] == f_1 &&
                  (DAT_0089f8e8 = *(float *)(param_12 + -4 + DAT_0089f934 * 4) -
                                  *(float *)(param_12 + -8 + DAT_0089f934 * 4), DAT_0089f8e8 < f_0_1
                  ))))) {
            *(undefined4 *)(param_12 + -4 + DAT_0089f934 * 4) =
                 *(undefined4 *)(param_12 + -8 + DAT_0089f934 * 4);
            DAT_0089f934 = DAT_0089f934 + 1;
            iVar2 = iVar2 + -1;
          }
          DAT_0089f970 = DAT_0089f970 + -1;
          in_ST0 = (float10)DAT_01c58928;
          if ((float10)f_100 <= ABS(in_ST0)) {
            _DAT_0089f95c = f_0_7;
          }
          _DAT_0089f924 = f_0;
          _DAT_0089f928 = f_0;
          DAT_0089f934 = DAT_0089f944;
          _DAT_0089f938 = f_0;
          if ((0xe < DAT_0089f980) && (*(float *)(&ITEM_P15 + DAT_0089f96c * 4) != f_0)) {
            _DAT_0089f95c = _DAT_0089f95c * *(float *)(&ITEM_P15 + DAT_0089f96c * 4);
          }
          do {
            DAT_0089f93c = *(int *)(DAT_0089f934 * 4 + param_11 + -4);
            if ((float)(&ITEM_P1)[DAT_0089f93c] == f_1) {
              DAT_0089f920 = 0;
              DAT_0089f91c = f_0;
              DAT_0089f918 = f_0;
              _DAT_0089f914 = f_0;
              _DAT_0089f928 = f_0;
              DAT_0089f910 = f_0;
              ffree(in_ST0);
              fVar4 = (float10)thunk_FUN_004b6ced(&DAT_0089f93c,&DAT_0089f94c);
              if (_DAT_0089f928 <= f_3) {
                if ((8 < DAT_0089f94c) && (DAT_0089f910 = DAT_01c5893c, DAT_01c5893c != f_0)) {
                  DAT_0089f8e8 = (float)((int)ROUND(DAT_01c5893c) % 10);
                  DAT_0089f90c = ((int)ROUND(DAT_01c5893c) % 100) / 10;
                  bVar3 = DAT_0089f8e8 != 0.0;
                  ffree(fVar4);
                  fVar4 = (float10)amod(&DAT_01c5892c,&f_100);
                  if (bVar3 && fVar4 < (float10)f_20) {
                    _DAT_0089f928 = _DAT_0089f95c * f_2_3;
                  }
                  ffree(extraout_ST1_01);
                  fVar4 = (float10)amod(&DAT_0089f910,&f_1);
                  DAT_0089f910 = (float)fVar4;
                  if (f_0_9 < DAT_0089f910) {
                    DAT_0089f910 = f_0_9 - DAT_0089f910;
                  }
                  fVar4 = (float10)DAT_0089f90c * (float10)f_1_7;
                  DAT_0089f910 = (float)((float10)DAT_0089f910 * (float10)f_10 + fVar4);
                  if (_DAT_0089f928 < DAT_0089f910) {
                    _DAT_0089f928 = DAT_0089f910;
                  }
                  DAT_0089f920 = 0;
                }
                DAT_0089f908 = f_0;
                if ((9 < DAT_0089f94c) &&
                   (DAT_0089f908 = *(float *)(&ITEM_P10 + DAT_0089f93c * 4), DAT_0089f908 != f_0)) {
                  if (DAT_0089f908 == f_110) {
                    DAT_0089f908 = f_10;
                  }
                  DAT_0089f8e8 = DAT_0089f908;
                  if ((DAT_0089f908 == f_10) || (DAT_0089f908 == f_20)) {
                    DAT_0089f8e8 = DAT_0079254c;
                    if (DAT_00792550 == _DAT_0089f950) {
                      DAT_0089f8e8 = DAT_00792554;
                    }
                    if (DAT_0089f908 < f_20) goto LAB_004be46a;
                    fVar4 = (float10)DAT_0089f918;
                    DAT_0089f918 = (float)-fVar4;
                    DAT_0089f974 = 0;
                    DAT_0089f91c = DAT_0089f8e8;
                  }
                  else if (f_0 <= DAT_0089f908) {
                    DAT_0089f94c = -1;
LAB_004be46a:
                    DAT_0089f918 = DAT_0089f8e8;
                  }
                  else {
                    fVar4 = (float10)DAT_0089f908;
                    DAT_0089f91c = (float)-fVar4;
                  }
                }
              }
              DAT_0089f918 = _DAT_0089f928 + DAT_0089f918;
              DAT_0089f948 = (int)ROUND(DAT_01c5892c);
              DAT_0089f904 = DAT_0089f948 % 10;
              if (DAT_0089f904 != 0) {
                DAT_0089f974 = 0;
                if (100 < DAT_0089f948) {
                  DAT_0089f904 = DAT_0089f904 + 9;
                }
                DAT_0089f8e8 = (&DAT_00792554)[DAT_0089f904];
                if ((DAT_0089f998 == 1) && (DAT_0089f940 == DAT_0089f900)) {
                  if (_DAT_0089f978 != DAT_01c58948) {
                    if ((_DAT_0089f8fc < f_20) && (DAT_0089f92c < f_20)) {
                      _DAT_0089f8e0 = DAT_01c58948;
                      if (DAT_01c58948 == f_1) {
                        fVar4 = (float10)DAT_01c58948;
                        _DAT_0089f8e0 = (float)-fVar4;
                      }
                      if (_DAT_0089f978 == f_1) {
                        fVar4 = (float10)_DAT_0089f978;
                        _DAT_0089f978 = (float)-fVar4;
                      }
                      if (_DAT_0089f8e0 < _DAT_0089f978) goto LAB_004be6f8;
                    }
                    goto LAB_004be78d;
                  }
                  if (f_4 <= ABS(_DAT_0089f8f8 - DAT_0089f958)) {
                    if (_DAT_0089f8fc < f_20) {
                      if (DAT_0089f958 < _DAT_0089f8f8) goto LAB_004be62d;
                    }
                    else if ((_DAT_0089f8f8 < DAT_0089f958) || (_DAT_0089f8f4 == f_0)) {
LAB_004be62d:
                      DAT_0089f8e8 = DAT_0089f8e8 - f_1_5;
                    }
                  }
                }
LAB_004be6f8:
                ffree(fVar4);
                fVar4 = (float10)amod(&DAT_01c5892c,&f_1);
                _DAT_0089f8e0 = (float)fVar4;
                if (f_0_9 < _DAT_0089f8e0) {
                  _DAT_0089f8e0 = f_0_9 - _DAT_0089f8e0;
                }
                fVar4 = (float10)DAT_0089f8e8 + (float10)DAT_0089f91c;
                DAT_0089f91c = (float)((float10)_DAT_0089f8e0 * (float10)f_10 + fVar4);
                if (DAT_0089f94c < 0) {
                  DAT_0089f91c = DAT_0089f91c - DAT_0089f908;
                }
              }
LAB_004be78d:
              ffree(fVar4);
              fVar4 = (float10)amod(&DAT_01c58928,&f_100);
              DAT_01c58928 = (float)fVar4;
              DAT_0089f930 = (uint)(f_12 < DAT_01c58928);
              if (DAT_01c58928 < f_2) {
                DAT_0089f930 = 0xffffffff;
              }
              if ((DAT_0089f930 == 0) || (DAT_0089f930 != DAT_0089f974)) {
                DAT_0089f974 = DAT_0089f930;
              }
              else {
                if (DAT_0089f91c < f_1_3) {
                  DAT_0089f91c = f_1_3;
                }
                if (DAT_0089f920 != 0) {
                  DAT_0089f974 = 0;
                }
              }
              if ((9 < DAT_0089f954) && (DAT_0089f954 < 0x14)) {
                DAT_0089f91c = DAT_0089f91c + f_1_7;
                DAT_0089f918 = DAT_0089f918 + f_1_8;
              }
              if (_DAT_0089f924 < DAT_0089f91c) {
                _DAT_0089f924 = DAT_0089f91c;
              }
              in_ST0 = extraout_ST1_02;
              if (_DAT_0089f938 < DAT_0089f918) {
                _DAT_0089f938 = DAT_0089f918;
              }
            }
            DAT_0089f934 = DAT_0089f934 + 1;
          } while (DAT_0089f934 <= DAT_0089f970);
          DAT_0089f960 = _DAT_0089f95c * _DAT_0089f924;
          DAT_0089f964 = (_DAT_0089f950 + _DAT_0089f938) * _DAT_0089f95c;
          DAT_0089f900 = DAT_0089f944;
          DAT_0089f940 = DAT_0089f970;
          _DAT_0089f8f8 = DAT_0089f958;
          _DAT_0089f8fc = DAT_0089f92c;
          _DAT_0089f8f4 = f_0;
          if (8 < DAT_0089f980) {
            ffree(in_ST0);
            fVar4 = (float10)amod(&ITEM_P9 + DAT_0089f96c * 4,&f_10);
            _DAT_0089f8f4 = (float)fVar4;
            in_ST0 = extraout_ST1_03;
          }
          _DAT_0089f978 = DAT_01c58948;
          goto LAB_004be9b2;
        }
      }
      else {
        DAT_0089f974 = 0;
        if (DAT_0089f968 == 0xe) {
          _DAT_01c58938 = f_1;
          if (0x10 < DAT_0089f980) {
            _DAT_01c58938 = *(float *)(&ITEM_P17 + DAT_0089f96c * 4) / DAT_0089f97c;
          }
          ffree(extraout_ST1);
          in_ST0 = (float10)thunk_FUN_004b6818(&DAT_0089f960,&DAT_0089f964,&DAT_0089f980,
                                               &DAT_0089f998);
        }
        else if (DAT_0089f968 == 2) {
          ffree(extraout_ST1);
          in_ST0 = (float10)thunk_FUN_004b6657(&DAT_0089f980,&DAT_0089f96c,&DAT_0089f960,
                                               &DAT_0089f964,&DAT_01c58928,&DAT_01c5892c,
                                               &DAT_01c58930,&DAT_0089f95c);
        }
        else if (DAT_0089f968 == 3) {
          DAT_0089f964 = f_7_5;
          if (f_100 <= DAT_01c58928) {
            DAT_0089f964 = f_6_5;
          }
          DAT_0089f8f0 = (uint)(f_100 <= DAT_01c58928);
          if (DAT_0089f998 == 0xe) {
LAB_004bd78e:
            DAT_0089f8e8 = param_9[*param_2 + -1];
            if (f_3 <= DAT_0089f8e8) {
              DAT_0089f8e8 = DAT_0089f8e8 - f_1;
            }
            if (DAT_0089f8e8 < f_3) {
              DAT_0089f8e8 = f_2;
            }
            param_9[*param_2 + -1] = DAT_0089f8e8;
          }
          else {
            if (DAT_0089f998 == 1) {
              DAT_0089f960 = f_1;
            }
            if (DAT_0089f994 != DAT_0089f970) {
              if (*param_2 == 1) goto LAB_004bd78e;
              in_ST0 = (float10)*(float *)(param_12 + DAT_0089f970 * 4) - (float10)DAT_01c58924;
              if ((((float10)DAT_0089f97c * (float10)DAT_0089f964 <= in_ST0) &&
                  (DAT_0089f8e8 = param_9[*param_2 + -1],
                  DAT_01c58924 - *(float *)(param_12 + -8 + DAT_0089f970 * 4) < DAT_0089f8e8)) &&
                 (DAT_0089f8e8 = DAT_0089f8e8 + *(float *)(param_12 + -8 + DAT_0089f970 * 4),
                 DAT_0089f8e8 < *(float *)(param_12 + DAT_0089f970 * 4) - f_0_2)) {
                DAT_01c58924 = DAT_0089f8e8;
                (&ITEM_P3)[*(int *)(param_11 + -4 + DAT_0089f970 * 4)] = DAT_0089f8e8;
              }
            }
          }
        }
        else if (DAT_0089f968 == 4) {
          DAT_0089f960 = f_1_3;
          if (DAT_0089f998 == 0xe) {
            DAT_0089f960 = f_0_2;
          }
          if ((DAT_0089f998 == 3) || (0x10 < DAT_0089f998)) {
            DAT_0089f960 = f_0;
          }
          DAT_0089f964 = f_1_8;
          if (f_15 <= (float)(&ITEM_LEN)[DAT_0089f96c]) goto LAB_004bd5be;
        }
        else if (DAT_0089f968 == 10) {
          DAT_0089f960 = f_0_2;
          DAT_0089f964 = f_4;
          if (DAT_01c58930 != f_0) {
            DAT_0089f964 = DAT_01c58930 * f_4;
          }
LAB_004bd5be:
          DAT_0089f8e8 = *(float *)(&ITEM_P15 + DAT_0089f96c * 4) / DAT_0089f97c;
          DAT_0089f960 = DAT_0089f960 - DAT_0089f8e8;
          DAT_0089f964 = DAT_0089f8e8 + DAT_0089f964;
        }
        else if (DAT_0089f968 == 0x11) {
          ffree(extraout_ST1);
          in_ST0 = (float10)thunk_FUN_004b6c51(&DAT_0089f960,&DAT_0089f964,&DAT_01c5892c,
                                               &DAT_01c58934,&DAT_0089f998);
        }
        else {
          ffree(extraout_ST1);
          in_ST0 = (float10)thunk_FUN_004b6a52(&DAT_0089f980,&DAT_0089f960,&DAT_0089f964,
                                               &ITEM_P1 + DAT_0089f96c,&DAT_0089f998,
                                               param_9 + *param_2 + -1);
          if (DAT_0089f994 == DAT_0089f970) {
            DAT_0089f964 = DAT_0089f964 - f_2_5;
          }
          else {
            DAT_0089f8e8 = DAT_0089f97c;
            if (DAT_0089f97c < f_1) {
              DAT_0089f8e8 = (f_1 - DAT_0089f97c) / f_2 + DAT_0089f97c;
            }
            if (DAT_0089f8e8 < f_1) {
              DAT_0089f964 = DAT_0089f8e8 * DAT_0089f964;
            }
          }
        }
LAB_004be9b2:
        if (f_0_03 <= ABS(DAT_01c58924 - param_8[*param_2 + -1])) {
          *param_2 = *param_2 + 1;
          param_8[*param_2 + -1] = DAT_01c58924;
          param_9[*param_2 + -1] = f_0;
          *(float *)(param_10 + -4 + *param_2 * 4) = f_0;
        }
        if ((DAT_0089f968 == 0x12) || (*(float *)(param_10 + -4 + *param_2 * 4) < DAT_0089f960)) {
          *(float *)(param_10 + -4 + *param_2 * 4) = DAT_0089f960;
        }
        if (param_9[*param_2 + -1] < DAT_0089f964) {
          param_9[*param_2 + -1] = DAT_0089f964;
        }
        if ((DAT_0089f968 < 3) || (DAT_0089f968 == 4)) {
          _DAT_0089f8e0 = f_0;
          if (DAT_0089f998 == 0xe) {
            _DAT_0089f8e0 = DAT_0078b494 / DAT_0089f97c - f_2_5;
          }
          if (DAT_0089f998 == 0x11) {
            _DAT_0089f8e0 = DAT_0078b498 / DAT_0089f97c - f_2_8;
          }
          if (DAT_0089f998 == 0x12) {
            _DAT_0089f8e0 = DAT_0078b49c / DAT_0089f97c - f_3_7;
          }
          if ((DAT_0089f998 == 3) && (DAT_0089f8f0 == 0)) {
            _DAT_0089f8e0 = DAT_0078b490 / DAT_0089f97c - f_1_8;
          }
          if (f_0 < _DAT_0089f8e0) {
            *(float *)(param_10 + -4 + *param_2 * 4) =
                 _DAT_0089f8e0 + *(float *)(param_10 + -4 + *param_2 * 4);
          }
        }
        DAT_0089f998 = DAT_0089f968;
      }
    } while (DAT_0089f970 < DAT_0089f994);
    *param_1 = DAT_0089f970;
    if (*param_2 != 1) {
      *(float *)(param_10 + *param_2 * 4) = f_0;
      iVar2 = *param_2;
      DAT_0089f970 = 1;
      for (; 0 < iVar2; iVar2 = iVar2 + -1) {
        param_9[DAT_0089f970 + -1] =
             (param_9[DAT_0089f970 + -1] + *(float *)(param_10 + DAT_0089f970 * 4)) * DAT_0089f97c;
        DAT_0089f970 = DAT_0089f970 + 1;
      }
    }
  }
  ffree(in_ST0);
  return;
}


