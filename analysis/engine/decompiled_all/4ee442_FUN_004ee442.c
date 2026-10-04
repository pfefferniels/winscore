// FUN_004ee442 @ 004ee442 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004ee442(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  unkbyte10 Var5;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  unkbyte10 extraout_ST1_05;
  unkbyte10 extraout_ST1_06;
  unkbyte10 Var6;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  unkbyte10 in_ST4;
  unkbyte10 in_ST5;
  unkbyte10 Var7;
  unkbyte10 in_ST6;
  unkbyte10 Var8;
  unkbyte10 Var9;
  undefined2 local_10c;
  
  DAT_01be6c90 = *param_2;
  DAT_01be6c70 = (int)ROUND((float10)DAT_01be6c90 - ABS((float10)*param_1));
  DAT_01be6c6c = 10;
  ffree((float10)*param_1);
  ffree((float10)DAT_01be6c90);
  Var7 = in_ST6;
  fVar4 = (float10)amod(&DAT_01f95d54 + DAT_01be6c70 * 0xf,&f_100);
  if ((float10)f_20 <= fVar4) {
    DAT_01be6c6c = 0x14;
  }
  DAT_01be6c78 = DAT_01be6c70 + 1;
  Var5 = extraout_ST1;
  if (DAT_01fbb700 == 2) {
    DAT_01be6c74 = DAT_01be6c70;
    for (iVar1 = (DAT_01be6c90 - DAT_01be6c70) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&DAT_01f95d54)[DAT_01be6c74 * 0xf] =
           (float)(int)ROUND((float)(&DAT_01f95d54)[DAT_01be6c74 * 0xf]);
      *(float *)(&DAT_01f95d68 + DAT_01be6c74 * 0x3c) = f_0;
      DAT_01be6c74 = DAT_01be6c74 + 1;
    }
    DAT_01be6c64 = (int)ROUND((float)(&DAT_01f95d50)[DAT_01be6c70 * 0xf]) % 100;
    DAT_01be6c68 = DAT_01be6c64;
LAB_004ee62b:
    DAT_01be6c74 = DAT_01be6c70;
    do {
      DAT_008d1790 = (int)ROUND((float)(&DAT_01f95d50)[DAT_01be6c74 * 0xf]) % 100;
      DAT_008d178c = (int)ROUND((float)(&DAT_01f95d8c)[DAT_01be6c74 * 0xf]) % 100;
      if (DAT_01be6c68 < DAT_008d178c) {
        DAT_01be6c68 = DAT_008d178c;
      }
      if (DAT_008d178c < DAT_01be6c64) {
        DAT_01be6c64 = DAT_008d178c;
      }
      if (DAT_01be6c6c == 0x14) {
        if (DAT_008d1790 <= DAT_008d178c) goto LAB_004ee79e;
      }
      else if (DAT_008d178c <= DAT_008d1790) goto LAB_004ee79e;
      DAT_01be6c74 = DAT_01be6c74 + 1;
      if (DAT_01be6c90 <= DAT_01be6c74) {
        if (DAT_01be6c68 < 0) {
          DAT_01be6c68 = 0;
        }
        DAT_01be6c60 = (DAT_01be6c68 - DAT_01be6c64) + 0x3d;
        break;
      }
    } while( true );
  }
  do {
    DAT_01be6c68 = (int)ROUND((float)(&DAT_01f95d50)[DAT_01be6c78 * 0xf]) % 100;
    DAT_01be6c64 = (int)ROUND(*(float *)(&DAT_01f95d14 + DAT_01be6c78 * 0x3c)) % 100;
    iVar1 = DAT_01be6c68 - DAT_01be6c64;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar1 < 2) {
      *(float *)(&DAT_01f95d68 + DAT_01be6c78 * 0x3c) = (float)DAT_01be6c6c;
      DAT_01be6c78 = DAT_01be6c78 + 1;
    }
    DAT_01be6c78 = DAT_01be6c78 + 1;
  } while (DAT_01be6c78 <= DAT_01be6c90);
  if (DAT_01be6c6c == 0x14) {
    DAT_01be6c80 = DAT_01be6c90;
    DAT_01be6c78 = DAT_01be6c70;
    DAT_01be6c70 = 1;
  }
  else {
    DAT_01be6c80 = DAT_01be6c70;
    DAT_01be6c78 = DAT_01be6c90;
    DAT_01be6c70 = -1;
  }
  ffree(in_ST2);
  ffree(Var5);
  Var8 = Var7;
  Var5 = thunk_FUN_0054c419(&DAT_01e99980,&DAT_00766430);
  iVar2 = DAT_01be6c70;
  DAT_008d1788 = 0x11b;
  DAT_008d1784 = 0;
  DAT_01be6c7c = DAT_01be6c78;
  Var6 = extraout_ST1_02;
  for (iVar1 = ((DAT_01be6c80 - DAT_01be6c78) + DAT_01be6c70) / DAT_01be6c70; 0 < iVar1;
      iVar1 = iVar1 + -1) {
    DAT_008d1784 = DAT_008d1784 + 1;
    iVar3 = DAT_008d1784 * 2;
    ffree(Var6);
    ffree(Var5);
    fVar4 = (float10)amod(&DAT_01f95d50 + DAT_01be6c7c * 0xf,&f_100);
    local_10c = (undefined2)(int)ROUND(fVar4);
    *(undefined2 *)((int)&DAT_008d1790 + iVar3 + 2) = local_10c;
    if (*(float *)(&DAT_01f95d68 + DAT_01be6c7c * 0x3c) == f_20) {
      *(undefined4 *)(DAT_008d1784 * 4 + 0x1e99e7c) = DAT_008d1788;
      (&DAT_01e99abc)[DAT_008d1784] = DAT_008d1788;
    }
    *(undefined2 *)(DAT_008d1784 * 2 + 0x8d1832) = (undefined2)DAT_01be6c7c;
    ffree(in_ST3);
    ffree(extraout_ST1_03);
    Var9 = Var8;
    fVar4 = (float10)amod(&DAT_01f95d54 + DAT_01be6c7c * 0xf,&DAT_00766404);
    DAT_01fbb70c = (int)ROUND(fVar4);
    if (DAT_01fbb70c != 0) {
      (&DAT_01e9997c)[DAT_008d1784] = DAT_01fbb70c;
      *(int *)(DAT_008d1784 * 4 + 0x1e99bfc) =
           (int)(short)(*(short *)((int)&DAT_008d1790 + DAT_008d1784 * 2 + 2) -
                       (short)(char)(&DAT_00794cfb)[DAT_01fbb70c]);
      *(int *)(DAT_008d1784 * 4 + 0x1e99d3c) =
           (int)(short)((short)(char)(&DAT_00794cf3)[DAT_01fbb70c] +
                       *(short *)((int)&DAT_008d1790 + DAT_008d1784 * 2 + 2));
    }
    DAT_01be6c7c = iVar2 + DAT_01be6c7c;
    Var5 = extraout_ST1_04;
    Var6 = in_ST4;
    in_ST3 = in_ST5;
    in_ST4 = in_ST6;
    in_ST5 = Var7;
    in_ST6 = Var8;
    Var7 = Var9;
    Var8 = Var9;
  }
  DAT_01be6c6c = 1;
  iVar1 = DAT_008d1784;
  for (iVar2 = DAT_008d1784; DAT_008d1784 = iVar1, 0 < iVar2; iVar2 = iVar2 + -1) {
    if (((&DAT_01e9997c)[DAT_01be6c6c] != 0) && (*(int *)(DAT_01be6c6c * 4 + 0x1e99e7c) == 0)) {
      DAT_008d1780 = *(int *)(DAT_01be6c6c * 4 + 0x1e99bfc);
      DAT_008d177c = *(int *)(DAT_01be6c6c * 4 + 0x1e99d3c);
      *param_2 = 1;
      for (; 0 < iVar1; iVar1 = iVar1 + -1) {
        if ((((DAT_01be6c6c != *param_2) && (*(int *)(*param_2 * 4 + 0x1e99e7c) != 0)) &&
            (DAT_008d1778 = (int)*(short *)((int)&DAT_008d1790 + *param_2 * 2 + 2),
            DAT_008d1778 <= DAT_008d177c)) && (DAT_008d1780 <= DAT_008d1778)) {
          (&DAT_01e99abc)[DAT_01be6c6c] = DAT_008d1788;
        }
        *param_2 = *param_2 + 1;
      }
    }
    DAT_01be6c6c = DAT_01be6c6c + 1;
    iVar1 = DAT_008d1784;
  }
  *param_2 = 1;
  DAT_008d1774 = 1;
LAB_004eed64:
  do {
    DAT_01be6c74 = (&DAT_01e9997c)[*param_2];
    if (DAT_01be6c74 != 0) {
      DAT_01be6c6c = (int)*(short *)((int)&DAT_008d1790 + *param_2 * 2 + 2);
      DAT_01fbb70c = (&DAT_01e99abc)[*param_2];
      DAT_01be6c68 = 0;
      DAT_01fbb710 = 999;
      DAT_008d1770 = 0;
      DAT_008d176c = *param_2 + 1;
      for (iVar1 = (DAT_008d1784 - DAT_008d176c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_01be6c84 = (&DAT_01e9997c)[DAT_008d176c];
        DAT_008d177c = (int)*(short *)((int)&DAT_008d1790 + DAT_008d176c * 2 + 2);
        if (0 < DAT_01be6c84) {
          DAT_01be6c64 = DAT_01be6c6c - *(short *)((int)&DAT_008d1790 + DAT_008d176c * 2 + 2);
          if (DAT_01be6c64 < 7) {
            ffree(Var6);
            ffree(Var5);
            Var5 = FUN_004ef47d();
            Var6 = extraout_ST1_05;
          }
          else {
            DAT_01be6c7c = 0;
          }
          if (DAT_01be6c7c < DAT_01fbb710) {
            DAT_01fbb710 = DAT_01be6c7c;
            DAT_01be6c68 = DAT_01be6c7c;
            DAT_008d1770 = DAT_008d176c;
          }
        }
        DAT_008d176c = DAT_008d176c + 1;
      }
      if (DAT_008d1770 != 0) {
        DAT_01fbb70c = DAT_01be6c68 + DAT_01fbb70c;
        if ((int)(&DAT_01e99abc)[DAT_008d1770] < DAT_01fbb70c) {
          (&DAT_01e99abc)[DAT_008d1770] = DAT_01fbb70c;
        }
        DAT_008d176c = *param_2 + 1;
        if (DAT_008d1770 != DAT_008d176c) {
          DAT_01fbb710 = DAT_008d176c;
          for (iVar1 = DAT_008d1770 - DAT_008d176c; 0 < iVar1; iVar1 = iVar1 + -1) {
            DAT_01be6c84 = (&DAT_01e9997c)[DAT_01fbb710];
            if (DAT_01be6c84 != 0) {
              DAT_008d1780 = (int)*(short *)((int)&DAT_008d1790 + DAT_01fbb710 * 2 + 2);
              iVar2 = DAT_01fbb70c + 0xf0;
              if (DAT_01be6c84 == 4) {
                iVar2 = DAT_01fbb70c + 0x1b8;
              }
              DAT_01fbb70c = iVar2;
              if ((int)(&DAT_01e99abc)[DAT_01fbb710] < DAT_01fbb70c) {
                (&DAT_01e99abc)[DAT_01fbb710] = DAT_01fbb70c;
              }
              DAT_01be6c6c = DAT_008d1780;
            }
            DAT_01fbb710 = DAT_01fbb710 + 1;
          }
        }
        *param_2 = DAT_008d1770;
        goto LAB_004eed64;
      }
    }
    *param_2 = *param_2 + 1;
    if (DAT_008d1784 <= *param_2) {
      *param_2 = 1;
      do {
        DAT_01be6c74 = (&DAT_01e9997c)[*param_2];
        if ((DAT_01be6c74 != 0) && ((&DAT_01e99abc)[*param_2] != 0)) {
          DAT_008d1780 = *(int *)(*param_2 * 4 + 0x1e99bfc);
          DAT_008d1774 = (&DAT_01e99abc)[*param_2];
          DAT_008d176c = *param_2 + 1;
          for (iVar1 = (DAT_008d1784 - DAT_008d176c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
            DAT_01be6c84 = (&DAT_01e9997c)[DAT_008d176c];
            if (DAT_01be6c84 != 0) {
              if (*(int *)(DAT_008d176c * 4 + 0x1e99d3c) <= DAT_008d1780) break;
              DAT_01fbb710 = (&DAT_01e99abc)[DAT_008d176c];
              DAT_008d177c = DAT_008d1774 - DAT_01fbb710;
              if (DAT_01be6c84 == 4) {
                DAT_008d177c = DAT_008d177c + -200;
              }
              iVar2 = DAT_008d177c;
              if (DAT_008d177c < 0) {
                iVar2 = -DAT_008d177c;
              }
              if (iVar2 < 0xf0) {
                DAT_01be6c64 = (int)(short)(*(short *)((int)&DAT_008d1790 + *param_2 * 2 + 2) -
                                           *(short *)((int)&DAT_008d1790 + DAT_008d176c * 2 + 2));
                ffree(Var6);
                ffree(Var5);
                Var5 = FUN_004ef47d();
                Var6 = extraout_ST1_06;
                if (0 < DAT_008d177c) {
                  DAT_008d1780 = 200;
                  if ((&DAT_01e9997c)[DAT_008d176c] == 4) {
                    DAT_008d1780 = 0;
                  }
                  if ((((&DAT_01e99abc)[DAT_008d176c] == 0) ||
                      (DAT_008d1780 < DAT_008d1774 - (&DAT_01e99abc)[DAT_008d176c])) ||
                     (200 < DAT_01be6c7c)) {
                    iVar1 = DAT_008d1774 - DAT_01fbb710;
                    DAT_008d1774 = -iVar1 + 0xf0;
                    if ((&DAT_01e9997c)[DAT_008d176c] == 4) {
                      DAT_008d1774 = -iVar1 + 0x1b8;
                    }
                    if (0 < DAT_008d1774) {
                      DAT_008d1770 = *param_2;
                      for (iVar1 = DAT_008d176c - DAT_008d1770; 0 < iVar1; iVar1 = iVar1 + -1) {
                        if (((&DAT_01e9997c)[DAT_008d1770] != 0) &&
                           ((&DAT_01e99abc)[DAT_008d1770] != 0)) {
                          (&DAT_01e99abc)[DAT_008d1770] =
                               (&DAT_01e99abc)[DAT_008d1770] + DAT_008d1774;
                        }
                        DAT_008d1770 = DAT_008d1770 + 1;
                      }
                    }
                  }
                  else {
                    (&DAT_01e99abc)[DAT_008d176c] = DAT_01be6c7c + DAT_008d1774;
                  }
                  break;
                }
                (&DAT_01e99abc)[DAT_008d176c] = DAT_01be6c7c + DAT_008d1774;
              }
            }
            DAT_008d176c = DAT_008d176c + 1;
          }
        }
        *param_2 = *param_2 + 1;
        iVar1 = DAT_008d1784;
        if (DAT_008d1784 <= *param_2) {
          *param_2 = 1;
          for (; 0 < iVar1; iVar1 = iVar1 + -1) {
            DAT_01be6c7c = (&DAT_01e99abc)[*param_2] - *(int *)(*param_2 * 4 + 0x1e99e7c);
            DAT_01be6c6c = (int)*(short *)(*param_2 * 2 + 0x8d1832);
            if (DAT_01be6c7c < 0) {
              DAT_01be6c7c = 0;
            }
            if (899 < DAT_01be6c7c) {
              DAT_01be6c7c = 899;
            }
            (&DAT_01f95d54)[DAT_01be6c6c * 0xf] =
                 (float)DAT_01be6c7c / f_1000 + (float)(&DAT_01f95d54)[DAT_01be6c6c * 0xf];
            *param_2 = *param_2 + 1;
          }
          ffree(Var6);
          ffree(Var5);
          return;
        }
      } while( true );
    }
  } while( true );
LAB_004ee79e:
  ffree(in_ST2);
  ffree(Var5);
  Var5 = thunk_FUN_0054c669(&DAT_01f95d50 + DAT_01be6c74 * 0xf,&DAT_01f95d8c + DAT_01be6c74 * 0xf);
  ffree(extraout_ST1_00);
  ffree(Var5);
  Var5 = thunk_FUN_0054c669(&DAT_01f95d54 + DAT_01be6c74 * 0xf,&DAT_01f95d90 + DAT_01be6c74 * 0xf);
  in_ST2 = extraout_ST1_01;
  goto LAB_004ee62b;
}


