// FUN_004b9c10 @ 004b9c10 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9c10(int param_1,int *param_2,undefined4 *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  undefined1 *puVar4;
  int local_170;
  int local_144;
  int local_54;
  
  puVar4 = &stack0xfffffffc;
  if (DAT_01ba0d68 < 1) {
    DAT_01ba0d68 = 1;
  }
  DAT_0089f72c = DAT_01ba0d68;
  DAT_0089f728 = 0;
  DAT_0089f724 = DAT_01be0940;
  DAT_0089f720 = DAT_01be0940 / DAT_01ba0d68;
  DAT_0089f71c = -1;
  DAT_0089f718 = 10000;
  DAT_0089f714 = 0;
  DAT_0089f710 = 0;
  DAT_0089f70c = 0;
  DAT_0089f708 = -1;
  DAT_0089f704 = 10000;
  *param_3 = 1;
  DAT_0089f700 = 1;
  do {
    DAT_0089f6fc = 1;
    DAT_01ba0d6c = DAT_0089f724 / DAT_0089f72c;
    for (DAT_0089f6f8 = *(int *)(DAT_0089f700 * 4 + param_1 + -4);
        (DAT_0089f700 = DAT_0089f700 + 1, DAT_0089f700 <= *param_2 &&
        (DAT_0089f6f4 = *(int *)(DAT_0089f700 * 4 + param_1 + -4),
        DAT_0089f6f4 / 2 + DAT_0089f6f8 < DAT_01ba0d6c)); DAT_0089f6f8 = DAT_0089f6f4 + DAT_0089f6f8
        ) {
      DAT_0089f6fc = DAT_0089f6fc + 1;
    }
    DAT_0089f728 = DAT_0089f728 + 1;
    DAT_0089f724 = DAT_0089f724 - DAT_0089f6f8;
    DAT_0089f72c = DAT_0089f72c + -1;
    *(int *)(DAT_0089f728 * 4 + param_5 + -4) = DAT_0089f6f8;
    if (199 < DAT_0089f728) {
      FUN_00603150(" ****** nbar OVERFLOW >200 ******",0x21);
    }
    param_3[DAT_0089f728] = DAT_0089f700;
  } while (0 < DAT_0089f72c);
LAB_004b9e08:
  DAT_01ba0d64 = 0;
  DAT_01ba0d60 = 10000;
  DAT_0089f728 = 1;
  for (iVar3 = DAT_01ba0d68; 0 < iVar3; iVar3 = iVar3 + -1) {
    DAT_0089f6f8 = *(int *)(DAT_0089f728 * 4 + param_5 + -4);
    iVar1 = DAT_0089f728;
    iVar2 = DAT_0089f6f8;
    if (DAT_0089f6f8 <= DAT_01ba0d64) {
      iVar1 = DAT_0089f6f0;
      iVar2 = DAT_01ba0d64;
    }
    DAT_01ba0d64 = iVar2;
    DAT_0089f6f0 = iVar1;
    iVar1 = DAT_0089f728;
    iVar2 = DAT_0089f6f8;
    if (DAT_01ba0d60 <= DAT_0089f6f8) {
      iVar1 = DAT_0089f6ec;
      iVar2 = DAT_01ba0d60;
    }
    DAT_01ba0d60 = iVar2;
    DAT_0089f6ec = iVar1;
    DAT_0089f728 = DAT_0089f728 + 1;
  }
  DAT_0089f700 = DAT_01ba0d64 - DAT_01ba0d60;
  if ((DAT_01ba0d64 < DAT_0089f718) || (DAT_0089f700 < DAT_0089f704)) {
    if (DAT_0089f71c < DAT_01ba0d60) {
      DAT_0089f71c = DAT_01ba0d60;
    }
    if (DAT_01ba0d64 < DAT_0089f718) {
      DAT_0089f718 = DAT_01ba0d64;
    }
    if (DAT_0089f700 < DAT_0089f704) {
      DAT_0089f704 = DAT_0089f700;
    }
    thunk_FUN_0054c4c6(param_3 + 1,param_4 + 4,&DAT_01ba0d68);
    if (DAT_0089f6ec <= DAT_0089f6f0) goto LAB_004b9fc9;
    DAT_0089f6e8 = 1;
    _DAT_0089f6e4 = 1;
    DAT_0089f6e0 = 0;
    goto LAB_004b9fff;
  }
  FUN_004bc207(param_3,param_1,param_4,param_5);
  DAT_0089f6d4 = 10000;
  DAT_0089f6d0 = DAT_01ba0d68 + -1;
LAB_004ba153:
  FUN_004bc303(&DAT_0089f6d4,param_5);
  local_170 = DAT_0089f6d0;
  DAT_0089f700 = 1;
  if (0 < DAT_0089f6d0) {
    do {
      if (((DAT_0089f720 < *(int *)(DAT_0089f700 * 4 + param_5 + -4)) &&
          (DAT_0089f738 = param_3[DAT_0089f700] + -1, DAT_0089f738 != param_3[DAT_0089f700 + -1]))
         && (DAT_0089f6e8 = *(int *)(DAT_0089f700 * 4 + param_5 + -4) -
                            *(int *)(DAT_0089f738 * 4 + param_1 + -4), DAT_01ba0d60 <= DAT_0089f6e8)
         ) {
        DAT_0089f6cc = *(int *)(param_1 + -4 + DAT_0089f738 * 4) +
                       *(int *)(param_5 + DAT_0089f700 * 4);
        if (DAT_0089f6cc <= DAT_01ba0d64) goto LAB_004ba3a5;
        if (DAT_0089f6d0 != DAT_0089f700) {
          DAT_0089f6f8 = DAT_0089f700 + 1;
          DAT_0089f6c8 = DAT_0089f6cc;
          for (iVar3 = (DAT_0089f6d0 - DAT_0089f6f8) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
            DAT_0089f6c4 = param_3[DAT_0089f6f8] + -1;
            DAT_0089f6dc = DAT_0089f6c8 - *(int *)(DAT_0089f6c4 * 4 + param_1 + -4);
            if ((DAT_0089f6dc < DAT_01ba0d60) || (DAT_01ba0d64 < DAT_0089f6dc)) break;
            DAT_0089f6c8 = *(int *)(param_5 + DAT_0089f6f8 * 4) +
                           *(int *)(param_1 + -4 + DAT_0089f6c4 * 4);
            if (DAT_0089f6c8 <= DAT_01ba0d64) goto LAB_004ba3b3;
            DAT_0089f6f8 = DAT_0089f6f8 + 1;
          }
        }
      }
      DAT_0089f700 = DAT_0089f700 + 1;
      local_170 = local_170 + -1;
      if (local_170 < 1) break;
    } while( true );
  }
  goto LAB_004ba402;
LAB_004b9fc9:
  if (1 < DAT_0089f6f0) {
    DAT_0089f6e8 = 0;
    _DAT_0089f6e4 = -1;
    DAT_0089f6e0 = 1;
LAB_004b9fff:
    do {
      while( true ) {
        DAT_0089f6f8 = param_3[DAT_0089f6e8 + DAT_0089f6f0 + -1] - DAT_0089f6e8;
        DAT_0089f6dc = *(int *)(DAT_0089f6f8 * 4 + param_1 + -4);
        *(int *)(DAT_0089f6f0 * 4 + param_5 + -4) =
             *(int *)(DAT_0089f6f0 * 4 + param_5 + -4) - DAT_0089f6dc;
        DAT_0089f6d8 = DAT_0089f6f0 + _DAT_0089f6e4;
        *(int *)(DAT_0089f6d8 * 4 + param_5 + -4) =
             *(int *)(param_5 + -4 + DAT_0089f6d8 * 4) + DAT_0089f6dc;
        param_3[DAT_0089f6e8 + DAT_0089f6f0 + -1] = DAT_0089f6e0 + DAT_0089f6f8;
        DAT_0089f6f0 = DAT_0089f6d8;
        if (DAT_0089f6e8 == 0) break;
        if (DAT_0089f6ec <= DAT_0089f6d8) goto LAB_004b9e08;
      }
    } while (DAT_0089f6ec < DAT_0089f6d8);
  }
  goto LAB_004b9e08;
LAB_004ba3a5:
  thunk_FUN_0047a1c9(param_5);
LAB_004ba3b3:
  *(int *)(DAT_0089f700 * 4 + param_5 + -4) = DAT_0089f6e8;
  *(int *)(DAT_0089f700 * 4 + param_5) = DAT_0089f6cc;
  param_3[DAT_0089f700] = param_3[DAT_0089f700] + -1;
  goto LAB_004ba153;
LAB_004ba402:
  FUN_004bc303(&DAT_0089f6d4,param_5);
  local_144 = (1 - DAT_01ba0d68) / -1;
  DAT_0089f700 = DAT_01ba0d68;
  if (0 < local_144) {
    do {
      if (((DAT_0089f720 < *(int *)(DAT_0089f700 * 4 + param_5 + -4)) &&
          (DAT_0089f738 = param_3[DAT_0089f700 + -1],
          DAT_0089f738 + -1 != param_3[DAT_0089f700 + -2])) &&
         (DAT_0089f6e8 = *(int *)(DAT_0089f700 * 4 + param_5 + -4) -
                         *(int *)(DAT_0089f738 * 4 + param_1 + -4), DAT_01ba0d60 <= DAT_0089f6e8)) {
        DAT_0089f6cc = *(int *)(param_1 + -4 + DAT_0089f738 * 4) +
                       *(int *)(param_5 + -8 + DAT_0089f700 * 4);
        if (DAT_0089f6cc <= DAT_01ba0d64) goto LAB_004ba666;
        if (DAT_0089f700 != 2) {
          DAT_0089f6f8 = DAT_0089f700 + -1;
          DAT_0089f6c8 = DAT_0089f6cc;
          for (iVar3 = (1 - DAT_0089f6f8) / -1; 0 < iVar3; iVar3 = iVar3 + -1) {
            DAT_0089f6c4 = param_3[DAT_0089f6f8 + -1];
            DAT_0089f6dc = DAT_0089f6c8 - *(int *)(DAT_0089f6c4 * 4 + param_1 + -4);
            if ((DAT_0089f6dc < DAT_01ba0d60) || (DAT_01ba0d64 < DAT_0089f6dc)) break;
            DAT_0089f6c8 = *(int *)(param_5 + -8 + DAT_0089f6f8 * 4) +
                           *(int *)(param_1 + -4 + DAT_0089f6c4 * 4);
            if (DAT_0089f6c8 <= DAT_01ba0d64) goto LAB_004ba674;
            DAT_0089f6f8 = DAT_0089f6f8 + -1;
          }
        }
      }
      DAT_0089f700 = DAT_0089f700 + -1;
      local_144 = local_144 + -1;
      if (local_144 < 1) break;
    } while( true );
  }
  thunk_FUN_0047a1c9(param_5);
  DAT_0089f6d4 = DAT_01ba0d64 - DAT_01ba0d60;
  thunk_FUN_0054c4c6(param_3 + 1,param_4 + 4,&DAT_01ba0d68);
LAB_004ba707:
  DAT_0089f6f0 = DAT_01ba0d64 + 5;
  _DAT_0089f6c0 = 1;
  DAT_0089f738 = DAT_01ba0d64 - DAT_01ba0d60;
  if (DAT_0089f738 <= DAT_0089f6d4) {
    thunk_FUN_0054c4c6(param_3 + 1,param_4 + 4,&DAT_01ba0d68);
    DAT_0089f6d4 = DAT_0089f738;
  }
  iVar3 = DAT_01ba0d68;
  for (DAT_0089f700 = 1;
      (iVar1 = DAT_0089f700, 0 < iVar3 &&
      (DAT_01ba0d60 != *(int *)(param_5 + -4 + DAT_0089f700 * 4))); DAT_0089f700 = DAT_0089f700 + 1)
  {
    iVar3 = iVar3 + -1;
  }
LAB_004ba7e0:
  DAT_0089f700 = iVar1;
  if (DAT_01ba0d68 != DAT_0089f700) {
    DAT_0089f738 = param_3[DAT_0089f700];
    DAT_0089f6e8 = *(int *)(param_1 + -4 + DAT_0089f738 * 4) +
                   *(int *)(param_5 + -4 + DAT_0089f700 * 4);
    if (DAT_0089f6e8 <= DAT_0089f6f0) {
      DAT_0089f6c8 = *(int *)(DAT_0089f700 * 4 + param_5) -
                     *(int *)(DAT_0089f738 * 4 + param_1 + -4);
      if (DAT_01ba0d60 <= DAT_0089f6c8) {
        *(int *)(DAT_0089f700 * 4 + param_5 + -4) = DAT_0089f6e8;
        *(int *)(DAT_0089f700 * 4 + param_5) = DAT_0089f6c8;
        param_3[DAT_0089f700] = DAT_0089f738 + 1;
        goto LAB_004bb28d;
      }
      if (DAT_0089f6d0 != DAT_0089f700) {
        DAT_0089f6f4 = DAT_0089f700 + 1;
        for (iVar3 = (DAT_0089f6d0 - DAT_0089f6f4) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
          DAT_0089f6c4 = param_3[DAT_0089f6f4];
          DAT_0089f6dc = *(int *)(param_1 + -4 + DAT_0089f6c4 * 4) + DAT_0089f6c8;
          if (DAT_0089f6f0 < DAT_0089f6dc) break;
          if (DAT_01ba0d60 < DAT_0089f6dc) {
            DAT_0089f6c8 = *(int *)(DAT_0089f6f4 * 4 + param_5) -
                           *(int *)(DAT_0089f6c4 * 4 + param_1 + -4);
            if (DAT_01ba0d60 <= DAT_0089f6c8) {
LAB_004bade0:
              *(int *)(DAT_0089f700 * 4 + param_5 + -4) = DAT_0089f6e8;
              DAT_0089f6bc = DAT_0089f700 + 1;
              iVar3 = (DAT_0089f6f4 - DAT_0089f6bc) + 1;
              goto joined_r0x004bae16;
            }
          }
          else {
            DAT_0089f6ec = *(int *)(param_1 + DAT_0089f6c4 * 4) + DAT_0089f6dc;
            if (DAT_0089f6f0 < DAT_0089f6ec) break;
            DAT_0089f6c8 = (*(int *)(DAT_0089f6f4 * 4 + param_5) -
                           *(int *)(DAT_0089f6c4 * 4 + param_1 + -4)) -
                           *(int *)(DAT_0089f6c4 * 4 + param_1);
            if (DAT_01ba0d60 < DAT_0089f6c8) goto LAB_004bade0;
          }
          DAT_0089f6f4 = DAT_0089f6f4 + 1;
        }
      }
    }
  }
  if ((DAT_0089f700 == 1) ||
     ((DAT_0089f714 == DAT_0089f700 && (DAT_0089f708 == DAT_0089f6f0 - DAT_0089f6ec)))) {
LAB_004bacf9:
    if ((DAT_0089f70c == DAT_0089f700) && (DAT_0089f708 == DAT_0089f6f0 - DAT_0089f6ec))
    goto LAB_004bb2c6;
    DAT_0089f70c = DAT_0089f700;
    if (DAT_01ba0d68 == DAT_0089f700) goto LAB_004bb2c6;
    DAT_0089f6f8 = DAT_0089f700 + 1;
    iVar3 = (DAT_01ba0d68 - DAT_0089f6f8) + 1;
    while( true ) {
      if (iVar3 < 1) goto LAB_004bb2c6;
      iVar1 = DAT_0089f6f8;
      if (DAT_01ba0d60 == *(int *)(param_5 + -4 + DAT_0089f6f8 * 4)) break;
      DAT_0089f6f8 = DAT_0089f6f8 + 1;
      iVar3 = iVar3 + -1;
    }
    goto LAB_004ba7e0;
  }
  if (DAT_0089f6d4 == DAT_0089f6a8) {
    DAT_0089f710 = DAT_0089f710 + 1;
    if (DAT_0089f710 != 10) goto LAB_004baab2;
LAB_004bb2c6:
    FUN_004bc207(param_3,param_1,param_4,param_5);
    goto LAB_004bb2d7;
  }
  DAT_0089f710 = 0;
LAB_004baab2:
  DAT_0089f6a8 = DAT_0089f6d4;
  DAT_0089f714 = DAT_0089f700;
  DAT_0089f708 = DAT_0089f6f0 - DAT_0089f6ec;
  DAT_0089f738 = param_3[DAT_0089f700 + -1] + -1;
  DAT_0089f6e8 = *(int *)(param_1 + -4 + DAT_0089f738 * 4) +
                 *(int *)(param_5 + -4 + DAT_0089f700 * 4);
  if (DAT_0089f6f0 < DAT_0089f6e8) goto LAB_004bacf9;
  DAT_0089f6c8 = *(int *)(DAT_0089f700 * 4 + param_5 + -8) -
                 *(int *)(DAT_0089f738 * 4 + param_1 + -4);
  if (DAT_0089f6c8 < DAT_01ba0d60) {
    if (2 < DAT_0089f700) {
      DAT_0089f6f4 = DAT_0089f700 + -1;
      for (iVar3 = (1 - DAT_0089f6f4) / -1; 0 < iVar3; iVar3 = iVar3 + -1) {
        DAT_0089f6c4 = param_3[DAT_0089f6f4 + -1] + -1;
        DAT_0089f6dc = *(int *)(param_1 + -4 + DAT_0089f6c4 * 4) + DAT_0089f6c8;
        if (DAT_0089f6f0 < DAT_0089f6dc) break;
        if (DAT_01ba0d60 < DAT_0089f6dc) {
          DAT_0089f6c8 = *(int *)(DAT_0089f6f4 * 4 + param_5 + -8) -
                         *(int *)(DAT_0089f6c4 * 4 + param_1 + -4);
          if (DAT_01ba0d60 <= DAT_0089f6c8) {
LAB_004baff8:
            *(int *)(DAT_0089f700 * 4 + param_5 + -4) = DAT_0089f6e8;
            DAT_0089f6bc = DAT_0089f700 + -1;
            iVar3 = ((DAT_0089f6f4 - DAT_0089f6bc) + -1) / -1;
            goto joined_r0x004bb03e;
          }
        }
        else {
          DAT_0089f6ec = *(int *)(param_1 + -8 + DAT_0089f6c4 * 4) + DAT_0089f6dc;
          if (DAT_0089f6f0 < DAT_0089f6ec) break;
          DAT_0089f6c8 = (*(int *)(DAT_0089f6f4 * 4 + param_5 + -8) -
                         *(int *)(DAT_0089f6c4 * 4 + param_1 + -4)) -
                         *(int *)(DAT_0089f6c4 * 4 + param_1 + -8);
          if (DAT_01ba0d60 < DAT_0089f6c8) goto LAB_004baff8;
        }
        DAT_0089f6f4 = DAT_0089f6f4 + -1;
      }
    }
    goto LAB_004bacf9;
  }
  *(int *)(DAT_0089f700 * 4 + param_5 + -4) = DAT_0089f6e8;
  *(int *)(DAT_0089f700 * 4 + param_5 + -8) = DAT_0089f6c8;
  param_3[DAT_0089f700 + -1] = DAT_0089f738;
  goto LAB_004bb28d;
LAB_004ba666:
  thunk_FUN_0047a1c9(param_5);
LAB_004ba674:
  *(int *)(DAT_0089f700 * 4 + param_5 + -4) = DAT_0089f6e8;
  *(int *)(DAT_0089f700 * 4 + param_5 + -8) = DAT_0089f6cc;
  param_3[DAT_0089f700 + -1] = param_3[DAT_0089f700 + -1] + 1;
  goto LAB_004ba402;
joined_r0x004bae16:
  if (iVar3 < 1) goto LAB_004baf9c;
  DAT_0089f6b8 = param_3[DAT_0089f6bc + -1];
  DAT_0089f6b4 = *(int *)(DAT_0089f6bc * 4 + param_5 + -4) -
                 *(int *)(DAT_0089f6b8 * 4 + param_1 + -4);
  param_3[DAT_0089f6bc + -1] = DAT_0089f6b8 + 1;
  if (DAT_01ba0d60 <= DAT_0089f6b4) {
    *(int *)(DAT_0089f6bc * 4 + param_5 + -4) = DAT_0089f6b4;
    goto LAB_004bb28d;
  }
  DAT_0089f6b0 = DAT_0089f6bc + 1;
  DAT_0089f6ac = param_3[DAT_0089f6bc];
  DAT_0089f6b4 = *(int *)(param_1 + -4 + DAT_0089f6ac * 4) + DAT_0089f6b4;
  if (DAT_0089f6b4 <= DAT_01ba0d60) {
    *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) =
         *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) - *(int *)(DAT_0089f6ac * 4 + param_1 + -4);
    DAT_0089f6ac = DAT_0089f6ac + 1;
    DAT_0089f6b4 = *(int *)(param_1 + -4 + DAT_0089f6ac * 4) + DAT_0089f6b4;
    param_3[DAT_0089f6b0 + -1] = DAT_0089f6ac;
  }
  *(int *)(DAT_0089f6bc * 4 + param_5 + -4) = DAT_0089f6b4;
  DAT_0089f6bc = DAT_0089f6bc + 1;
  iVar3 = iVar3 + -1;
  goto joined_r0x004bae16;
LAB_004baf9c:
  param_3[DAT_0089f6b0 + -1] = DAT_0089f6ac + 1;
  *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) =
       *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) - *(int *)(DAT_0089f6ac * 4 + param_1 + -4);
  goto LAB_004bb28d;
joined_r0x004bb03e:
  if (iVar3 < 1) goto LAB_004bb1c5;
  DAT_0089f6b8 = param_3[DAT_0089f6bc] + -1;
  DAT_0089f6b4 = *(int *)(DAT_0089f6bc * 4 + param_5 + -4) -
                 *(int *)(DAT_0089f6b8 * 4 + param_1 + -4);
  param_3[DAT_0089f6bc] = DAT_0089f6b8;
  if (DAT_01ba0d60 <= DAT_0089f6b4) {
    *(int *)(DAT_0089f6bc * 4 + param_5 + -4) = DAT_0089f6b4;
    goto LAB_004bb28d;
  }
  DAT_0089f6b0 = DAT_0089f6bc + -1;
  DAT_0089f6ac = param_3[DAT_0089f6bc + -1] + -1;
  DAT_0089f6b4 = *(int *)(param_1 + -4 + DAT_0089f6ac * 4) + DAT_0089f6b4;
  if (DAT_0089f6b4 <= DAT_01ba0d60) {
    DAT_0089f6b4 = *(int *)(param_1 + -8 + DAT_0089f6ac * 4) + DAT_0089f6b4;
    param_3[DAT_0089f6bc + -1] = DAT_0089f6ac;
    *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) =
         *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) - *(int *)(DAT_0089f6ac * 4 + param_1 + -4);
    DAT_0089f6ac = DAT_0089f6ac + -1;
  }
  *(int *)(DAT_0089f6bc * 4 + param_5 + -4) = DAT_0089f6b4;
  DAT_0089f6bc = DAT_0089f6bc + -1;
  iVar3 = iVar3 + -1;
  goto joined_r0x004bb03e;
LAB_004bb1c5:
  *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) =
       *(int *)(DAT_0089f6b0 * 4 + param_5 + -4) - *(int *)(DAT_0089f6ac * 4 + param_1 + -4);
  param_3[DAT_0089f6f4 + -1] = DAT_0089f6ac;
LAB_004bb28d:
  thunk_FUN_0047a1c9(param_5);
  goto LAB_004ba707;
LAB_004bb2d7:
  local_54 = DAT_01ba0d68 + -1;
  DAT_0089f728 = 2;
  if (0 < local_54) {
    do {
      DAT_0089f6f8 = param_3[DAT_0089f728 + -1];
      DAT_0089f6dc = *(int *)(DAT_0089f728 * 4 + param_5 + -4);
      DAT_0089f6cc = *(int *)(DAT_0089f728 * 4 + param_5 + -8);
      if (DAT_0089f6dc < DAT_0089f6cc) {
        DAT_0089f6f4 = *(int *)(DAT_0089f6f8 * 4 + param_1 + -8);
        if (DAT_0089f6f4 <= DAT_0089f6cc - DAT_0089f6dc) goto LAB_004bb429;
      }
      else {
        DAT_0089f6f4 = *(int *)(DAT_0089f6f8 * 4 + param_1 + -4);
        if (DAT_0089f6f4 < DAT_0089f6dc - DAT_0089f6cc) {
          *(int *)(DAT_0089f728 * 4 + param_5 + -8) = DAT_0089f6f4 + DAT_0089f6cc;
          *(int *)(DAT_0089f728 * 4 + param_5 + -4) = DAT_0089f6dc - DAT_0089f6f4;
          param_3[DAT_0089f728 + -1] = DAT_0089f6f8 + 1;
          goto LAB_004bb2d7;
        }
      }
      DAT_0089f728 = DAT_0089f728 + 1;
      local_54 = local_54 + -1;
      if (local_54 < 1) break;
    } while( true );
  }
  goto LAB_004bb47d;
LAB_004bb429:
  *(int *)(DAT_0089f728 * 4 + param_5 + -8) = DAT_0089f6cc - DAT_0089f6f4;
  *(int *)(DAT_0089f728 * 4 + param_5 + -4) = DAT_0089f6f4 + DAT_0089f6dc;
  param_3[DAT_0089f728 + -1] = DAT_0089f6f8 + -1;
  goto LAB_004bb2d7;
LAB_004bb47d:
  DAT_0089f6a4 = 0;
  DAT_0089f700 = 1;
  param_3[DAT_01ba0d68] = *param_2 + 1;
  DAT_01ba0d6c = DAT_01be0940 / DAT_01ba0d68;
  thunk_FUN_0047a1c9(param_5);
  FUN_005f33c9(&stack0xfffffffc,0x4bb4e3);
  FUN_005f34d1(puVar4,0x4bb4fe);
  thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_00764a64,&DAT_00764a68,"(1i3)",5,&DAT_01ba0d6c);
  thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_00764a5c,&DAT_00764a60,"(1i3)",5,&DAT_01ba0d60);
  thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_00764a54,&DAT_00764a58,"(1i3)",5,&DAT_01ba0d64);
  iVar3 = **(int **)(puVar4 + 0xc);
  *(int *)(puVar4 + -0x34) = iVar3;
  DAT_0089f6f8 = 1;
  while (0 < iVar3) {
    DAT_0089f728 = *(int *)(DAT_0089f6f8 * 4 + *(int *)(puVar4 + 8) + -4);
    if (DAT_01be0944 <= *(int *)(DAT_0089f6f8 * 4 + *(int *)(puVar4 + 0x1c) + -4)) {
      DAT_0089f728 = -DAT_0089f728;
    }
    *(int *)(DAT_0089f6f8 * 4 + *(int *)(puVar4 + 0x20) + -4) = DAT_0089f728;
    DAT_0089f6f8 = DAT_0089f6f8 + 1;
    *(int *)(puVar4 + -0x34) = *(int *)(puVar4 + -0x34) + -1;
    iVar3 = *(int *)(puVar4 + -0x34);
  }
  DAT_0089f6a4 = 0;
  DAT_0089f714 = 0;
  if (DAT_01be0960 == 0) {
    *(undefined4 *)(puVar4 + -0x30) = 0;
  }
  else {
    DAT_01be0960 = 1;
    DAT_00795464 = DAT_01be0964;
  }
  iVar3 = DAT_01ba0d68;
  *(int *)(puVar4 + -0x2c) = DAT_01ba0d68;
  DAT_0089f6f8 = 1;
  do {
    if (iVar3 < 1) {
      *(undefined4 *)(DAT_01ba0d68 * 4 + *(int *)(puVar4 + 0x10)) = 0;
      *(undefined4 *)(DAT_01ba0d68 * 4 + *(int *)(puVar4 + 0x10) + 4) = 0;
      _DAT_0089f68c = 0;
      return;
    }
    DAT_0089f714 = DAT_0089f714 + 1;
    DAT_0089f728 = *(int *)(DAT_0089f6f8 * 4 + *(int *)(puVar4 + 0x10)) -
                   *(int *)(DAT_0089f6f8 * 4 + *(int *)(puVar4 + 0x10) + -4);
    *(int *)(DAT_0089f6f8 * 4 + *(int *)(puVar4 + 0x10) + -4) = DAT_0089f728;
    (&DAT_01b11800)[DAT_01b11800] = DAT_0089f728;
    DAT_01b11800 = DAT_01b11800 + 1;
    DAT_0089f728 = DAT_0089f700 + DAT_0089f728 + -1;
    DAT_0089f6dc = DAT_0089f700 + DAT_01be0948 + -1;
    DAT_0089f6a4 = DAT_0089f6a4 + 1;
    _DAT_0089f6a0 = (float)DAT_01ba0d64 / f_69;
    *(undefined4 *)(puVar4 + -0x28) = 0x44;
    DAT_0089f69c = 2;
    do {
      *(undefined1 *)((int)&DAT_0089f738 + DAT_0089f69c + 3) = 0xc4;
      DAT_0089f69c = DAT_0089f69c + 1;
      *(int *)(puVar4 + -0x28) = *(int *)(puVar4 + -0x28) + -1;
    } while (0 < *(int *)(puVar4 + -0x28));
    DAT_0089f698 = 1;
    DAT_0089f6e0 = 1;
    iVar3 = (DAT_0089f728 - DAT_0089f700) + 1;
    *(int *)(puVar4 + -0x24) = iVar3;
    DAT_0089f69c = DAT_0089f700;
    DAT_0089f73c = DAT_00764a4c;
    while (0 < iVar3) {
      DAT_0089f6e8 = *(int *)(*(int *)(puVar4 + 0x20) + -4 + DAT_0089f69c * 4);
      if (DAT_0089f6e8 < 0) {
        DAT_0089f6e8 = -DAT_0089f6e8;
      }
      _DAT_0089f694 = (float)DAT_0089f6e8;
      *(undefined2 *)(puVar4 + -0x1d8) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x1d6) = (ushort)*(undefined4 *)(puVar4 + -0x1d8) | 0xc00;
      *(int *)(puVar4 + -0x1d4) = (int)ROUND(_DAT_0089f694 / _DAT_0089f6a0 + f_0_3);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1d8);
      DAT_0089f690 = *(int *)(puVar4 + -0x1d4);
      DAT_0089f6e0 = (DAT_0089f690 + -1) / 2 + DAT_0089f698;
      DAT_0089f698 = DAT_0089f690 + DAT_0089f698;
      if (0x45 < DAT_0089f698) {
        DAT_0089f698 = 0x45;
      }
      if (DAT_0089f6e8 < 100) {
        *(undefined4 *)(puVar4 + -0x20) = 0;
LAB_004bb8fd:
        puVar4[-0x1d1] = (char)(DAT_0089f6e8 / 10) + '0';
        *(undefined1 *)((int)&DAT_0089f738 + DAT_0089f6e0 + 3) = puVar4[-0x1d1];
        DAT_0089f6e0 = DAT_0089f6e0 + 1;
        DAT_0089f690 = DAT_0089f6e8 % 10;
      }
      else {
        if (9 < DAT_0089f6e8) {
          puVar4[-0x1d1] = (char)(DAT_0089f6e8 / 100) + '0';
          *(undefined1 *)((int)&DAT_0089f738 + DAT_0089f6e0 + 3) = puVar4[-0x1d1];
          DAT_0089f6e0 = DAT_0089f6e0 + 1;
          DAT_0089f6e8 = DAT_0089f6e8 % 100;
          goto LAB_004bb8fd;
        }
        *(undefined4 *)(puVar4 + -0x1c) = 0;
      }
      puVar4[-0x1d1] = (char)DAT_0089f690 + '0';
      *(undefined1 *)((int)&DAT_0089f738 + DAT_0089f6e0 + 3) = puVar4[-0x1d1];
      DAT_0089f6e0 = 0xc5;
      if (DAT_0089f728 == DAT_0089f69c) {
        DAT_0089f6e0 = 0xb4;
      }
      puVar4[-0x1d1] = (undefined1)DAT_0089f6e0;
      *(undefined1 *)((int)&DAT_0089f738 + DAT_0089f698 + 3) = puVar4[-0x1d1];
      if (*(int *)(*(int *)(puVar4 + 0x20) + -4 + DAT_0089f69c * 4) < 0) {
        *(undefined1 *)((int)&DAT_0089f738 + DAT_0089f698 + 3) = 0xdb;
      }
      DAT_0089f69c = DAT_0089f69c + 1;
      *(int *)(puVar4 + -0x24) = *(int *)(puVar4 + -0x24) + -1;
      iVar3 = *(int *)(puVar4 + -0x24);
    }
    if (DAT_0089f698 < 0x45) {
      DAT_0089f6e0 = DAT_0089f698 + 1;
      iVar3 = 0x46 - DAT_0089f6e0;
      *(int *)(puVar4 + -0x14) = iVar3;
      while (0 < iVar3) {
        *(undefined1 *)((int)&DAT_0089f738 + DAT_0089f6e0 + 3) = 0x20;
        DAT_0089f6e0 = DAT_0089f6e0 + 1;
        *(int *)(puVar4 + -0x14) = *(int *)(puVar4 + -0x14) + -1;
        iVar3 = *(int *)(puVar4 + -0x14);
      }
    }
    else {
      *(undefined4 *)(puVar4 + -0x18) = 0;
    }
    s_4_0x69a1_1i3__00792533[0] = (undefined1)i_2016554034;
    s_4_0x69a1_1i3__00792533[1] = i_2016554034._1_1_;
    s_4_0x69a1_1i3__00792533[2] = i_2016554034._2_1_;
    s_4_0x69a1_1i3__00792533[3] = i_2016554034._3_1_;
    if (9 < DAT_0089f6dc) {
      s_4_0x69a1_1i3__00792533[0] = (undefined1)i_2016488499;
      s_4_0x69a1_1i3__00792533[1] = i_2016488499._1_1_;
      s_4_0x69a1_1i3__00792533[2] = i_2016488499._2_1_;
      s_4_0x69a1_1i3__00792533[3] = i_2016488499._3_1_;
    }
    if (99 < DAT_0089f6dc) {
      s_4_0x69a1_1i3__00792533[0] = (undefined1)i_538979380;
      s_4_0x69a1_1i3__00792533[1] = i_538979380._1_1_;
      s_4_0x69a1_1i3__00792533[2] = i_538979380._2_1_;
      s_4_0x69a1_1i3__00792533[3] = i_538979380._3_1_;
    }
    FUN_005f33c9(puVar4,0x4bbad1);
    FUN_005f34d1(puVar4,0x4bbaec);
    thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00764a30,&DAT_00764a34,"(1i3)",5,&DAT_0089f6dc);
    DAT_020b8ea6 = 0;
    FUN_005f33c9(puVar4,0x4bbb4d);
    if (DAT_0089f714 < DAT_00795464) {
      *(undefined4 *)(puVar4 + -0x10) = 0;
LAB_004bbc1a:
      if (10 < DAT_0089f6a4) goto LAB_004bbc2c;
      *(undefined4 *)(puVar4 + -4) = 0;
    }
    else {
      DAT_0089f698 = DAT_00795464;
      if (DAT_01be0960 == 0) {
        *(undefined4 *)(puVar4 + -0xc) = 0;
      }
      else {
        DAT_01be0960 = DAT_01be0960 + 1;
        DAT_00795464 = (&DAT_01be0960)[DAT_01be0960];
      }
      DAT_0089f714 = 0;
      DAT_0089f6a4 = DAT_0089f6a4 + 1;
      (&DAT_01b11800)[DAT_01b11800] = 0;
      DAT_01b11800 = DAT_01b11800 + 1;
      (&DAT_01b11800)[DAT_01b11800] = 0;
      DAT_00795468 = DAT_00795468 + 1;
      if (DAT_0089f6a4 + DAT_00795464 < 0xc) goto LAB_004bbc1a;
      *(undefined4 *)(puVar4 + -8) = 0;
LAB_004bbc2c:
      DAT_0089f6a4 = 0;
    }
    DAT_0089f700 = DAT_0089f728 + 1;
    DAT_0089f6f8 = DAT_0089f6f8 + 1;
    *(int *)(puVar4 + -0x2c) = *(int *)(puVar4 + -0x2c) + -1;
    iVar3 = *(int *)(puVar4 + -0x2c);
  } while( true );
}


