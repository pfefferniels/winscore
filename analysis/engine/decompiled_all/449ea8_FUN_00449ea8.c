// FUN_00449ea8 @ 00449ea8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Heritage AFTER dead removal. Example location: r0x020b944c : 0x0044a703 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_00449ea8(int *param_1)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  float10 fVar3;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined1 *puVar4;
  int local_118;
  int local_60;
  int local_34;
  int local_8;
  
  puVar4 = &stack0xfffffffc;
  DAT_0078b4f0 = 1;
LAB_00449ebf:
  local_118 = 0xc;
  DAT_01f95c80 = 1;
LAB_00449ed4:
  DAT_007fdf70 = (int)ROUND(*(float *)(&P0 + DAT_01f95c80 * 4));
  if (DAT_007fdf70 == 0) goto LAB_0044ae71;
  if (DAT_007fdf70 < 0) {
    iVar1 = -DAT_007fdf70;
    if (3 < iVar1) {
      iVar2 = DAT_007fdf70 * -4;
      in_ST0 = (float10)*(float *)(&DAT_020b943c + DAT_007fdf70 * -4);
      DAT_007fdf70 = iVar1;
      *(float *)(&DAT_020b943c + iVar2) = (float)-in_ST0;
      iVar1 = DAT_007fdf70;
    }
    goto LAB_0044ab9a;
  }
  if ((&P1)[DAT_01f95c80] == f_m9999) {
    DAT_01f95c88 = (int)ROUND((&P2)[DAT_01f95c80]);
    (&P2)[DAT_01f95c80] = f_0;
    if ((DAT_01f95c88 == 0) || (0x2d < DAT_01f95c88)) {
      DAT_01f95c88 = 0x2d;
    }
    if ((((int)ROUND(DAT_020b9440) == 0xf) || ((int)ROUND(DAT_020b9440) == 0x10)) &&
       (0xb < DAT_01f95c88)) {
      DAT_01f95c88 = 0xb;
    }
    if (DAT_007fdf70 < 4) {
      DAT_007fdf70 = 4;
    }
    DAT_02091d04 = DAT_01f95c88;
    DAT_01f95c8c = DAT_007fdf70;
    for (iVar2 = (DAT_01f95c88 - DAT_007fdf70) + 1; iVar1 = DAT_007fdf70, 0 < iVar2;
        iVar2 = iVar2 + -1) {
      *(float *)(&DAT_020b943c + DAT_01f95c8c * 4) = f_0;
      DAT_01f95c8c = DAT_01f95c8c + 1;
    }
    goto LAB_0044ab9a;
  }
  DAT_01f95c88 = (int)ROUND(DAT_020b9440);
  iVar1 = DAT_007fdf70;
  if (DAT_01f95c88 == 0x10) {
    if (*(float *)(&P0 + DAT_01f95c80 * 4) == f_26) {
      if ((&P1)[DAT_01f95c80] == f_0) {
        DAT_020b9474 = f_0;
        DAT_01f95c8c = 0xc;
      }
      else {
        DAT_020b9474 = f_m1;
        DAT_020b947c = (&P1)[DAT_01f95c80];
        DAT_01f95c8c = 0x10;
      }
    }
    else {
      if ((*(float *)(&P0 + DAT_01f95c80 * 4) == f_14) && ((&P1)[DAT_01f95c80] == f_m1)) {
        DAT_020b9474 = f_m1;
      }
      DAT_01f95c8c = 0xc;
      if (DAT_020b9474 == f_m1) {
        DAT_01f95c8c = 0x10;
      }
      if (DAT_007fdf70 % 100 <= DAT_01f95c8c) {
        DAT_01f95c8c = DAT_007fdf70;
        if (99 < DAT_007fdf70) {
          DAT_01f95c8c = DAT_007fdf70 / 100;
        }
        if (9999 < DAT_007fdf70) {
          DAT_01f95c8c = DAT_007fdf70 / 10000;
        }
        goto LAB_0044a2d0;
      }
    }
    goto LAB_0044ab9a;
  }
LAB_0044a2d0:
  DAT_007fdf6c = (&P1)[DAT_01f95c80];
  if ((DAT_01f95c88 == 1) && (0x31 < DAT_007fdf70)) {
    DAT_007fdf68 = (int)ROUND(DAT_020b944c);
    DAT_007fdf64 = DAT_007fdf68 % 100 + 0x1c;
    if (DAT_007fdf70 < 0x18) {
      if (DAT_007fdf70 == 0x15) {
        DAT_007fdf64 = DAT_007fdf68 % 100 + 0x1e;
      }
      if (DAT_007fdf70 == 0x16) {
        DAT_007fdf64 = DAT_007fdf64 + 1;
      }
      if (DAT_007fdf70 == 0x17) {
        DAT_007fdf64 = DAT_007fdf64 + -1;
      }
      DAT_007fdf64 = DAT_007fdf64 % 7;
      DAT_01f95c88 = (int)ROUND(DAT_020b9450);
      DAT_01f95c8c = DAT_01f95c88 % 10;
      P2 = f_1;
      if (DAT_007fdf6c < f_0) {
        P2 = f_m1;
      }
      switch(DAT_01f95c8c) {
      case 1:
        if (DAT_007fdf6c <= f_0) {
          DAT_01f95c88 = 1;
          if ((DAT_007fdf64 == 1) || (DAT_007fdf64 == 4)) {
            DAT_01f95c88 = 2;
          }
        }
        else {
          if ((DAT_007fdf64 != 0) && (DAT_007fdf64 != 3)) break;
          DAT_01f95c88 = 3;
        }
        goto LAB_0044ad7e;
      case 2:
        if (f_0 < DAT_007fdf6c) {
          DAT_01f95c88 = -1;
          if ((DAT_007fdf64 == 0) || (DAT_007fdf64 == 3)) {
            DAT_01f95c88 = 1;
          }
          goto LAB_0044ad7e;
        }
        if ((DAT_007fdf64 == 1) || (DAT_007fdf64 == 4)) {
          DAT_01f95c88 = 3;
          goto LAB_0044ad7e;
        }
        break;
      default:
        if (DAT_007fdf6c <= f_0) {
          DAT_01f95c88 = 5;
          if ((DAT_007fdf64 == 1) || (DAT_007fdf64 == 4)) {
            DAT_01f95c88 = 2;
          }
        }
        else {
          DAT_01f95c88 = 4;
          if ((DAT_007fdf64 == 0) || (DAT_007fdf64 == 3)) {
            DAT_01f95c88 = 1;
          }
        }
        if (DAT_01f95c8c == 3) {
          DAT_01f95c88 = DAT_01f95c88 + -3;
        }
        goto LAB_0044ad7e;
      case 4:
        if (DAT_007fdf6c <= f_0) {
          DAT_01f95c88 = -1;
          if ((DAT_007fdf64 == 1) || (DAT_007fdf64 == 4)) {
            DAT_01f95c88 = -3;
          }
          goto LAB_0044ad7e;
        }
        break;
      case 5:
        if (f_0 <= DAT_007fdf6c) goto code_r0x0044acb4;
      }
LAB_0044ab9a:
      DAT_007fdf70 = iVar1;
      DAT_01f95c80 = DAT_01f95c80 + 2;
      local_118 = local_118 + -1;
      if (local_118 < 1) {
LAB_0044ae71:
        local_34 = 0x2d;
        DAT_01f95c80 = 1;
        do {
          DAT_007fdf6c = *(float *)(&DAT_020b943c + DAT_01f95c80 * 4);
          if (DAT_007fdf6c != f_0) {
            *param_1 = DAT_01f95c80;
          }
          *(float *)(&P0 + DAT_01f95c80 * 4) = DAT_007fdf6c;
          DAT_01f95c80 = DAT_01f95c80 + 1;
          local_34 = local_34 + -1;
        } while (0 < local_34);
        DAT_007fdf60 = NPT;
        if ((DAT_020b9440 == f_1) && (P13 == f_99)) {
          DAT_007fdf6c = f_0;
          if ((P6 != f_2) &&
             (((P11 < f_0 && (f_10 <= P5)) && (DAT_01f95c80 = (int)ROUND(P11), DAT_01f95c80 == -7)))
             ) {
            DAT_01f95c94 = P15;
            if (P15 == f_0) {
              DAT_01f95c94 = f_1;
            }
            in_ST0 = (float10)P4;
            if ((float10)f_100 <= ABS(in_ST0)) {
              DAT_01f95c94 = f_0_6;
            }
            DAT_01f95c80 = (int)ROUND(P2);
            DAT_007fdf6c = (DAT_01f95c94 * f_1_35 * (float)(&STAFF_STEP0)[DAT_01f95c80]) / f_25;
            if (f_20 <= P5) {
              in_ST0 = (float10)DAT_007fdf6c;
              DAT_007fdf6c = (float)-in_ST0;
            }
          }
          P13 = DAT_007fdf6c;
          DAT_020b9470 = DAT_007fdf6c;
        }
        if ((_DAT_01fbb744 == f_0) && (_DAT_01fbb748 == f_0)) {
          if (DAT_020b8ea0 == 0x5854) {
            ffree(in_ST0);
            in_ST0 = (float10)draw_item();
          }
        }
        else {
          if (DAT_007fdf5c == 0) {
            DAT_01f95c80 = DAT_007fdf64 - DAT_007fdf68;
            DAT_007fdf5c = DAT_01f95c80 + NPT;
          }
          NPT = DAT_007fdf5c;
          DAT_007fdf70 = (int)ROUND(_DAT_01fbb744 * f_150);
          _DAT_01fbb744 = f_0;
          _DAT_01fbb748 = f_0;
        }
        if ((-1 < DAT_0078b374) && (DAT_01fbb720 != -2)) {
          DAT_0205274c = 1;
          DAT_007fdf58 = ITEM_WORDS;
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_00449b86();
          local_8 = 0x40;
          DAT_020b8e44 = 1;
          do {
            *(undefined4 *)(DAT_020b8e44 * 4 + 0x7fdf80) = 0;
            if (DAT_020b8e44 <= *param_1) {
              *(int *)(DAT_020b8e44 * 4 + 0x7fdf80) = (int)ROUND(*(float *)(&P0 + DAT_020b8e44 * 4))
              ;
            }
            DAT_020b8e44 = DAT_020b8e44 + 1;
            local_8 = local_8 + -1;
          } while (0 < local_8);
          _DAT_007fdf4c = EDIT_ITEM;
          DAT_020b8e44 = ITEM_WORDS;
          ITEM_WORDS = DAT_007fdf58;
        }
        DAT_01f95c84 = NPT;
        DAT_007fdf5c = NPT;
        NPT = DAT_007fdf60;
        DAT_0078b4ec = 0;
LAB_0044b2fa:
        ffree(in_ST0);
        return;
      }
      goto LAB_00449ed4;
    }
    if (0x59 < DAT_007fdf70) {
      ffree(in_ST0);
      fVar3 = (float10)amod(&DAT_020b9450,&f_10);
      DAT_01f95c88 = (int)ROUND(fVar3);
      in_ST0 = extraout_ST1;
    }
  }
  if (DAT_01f95c88 == 6) {
    if ((DAT_007fdf6c < f_0) && (DAT_007fdf70 == 8)) {
      FUN_005f33c9(&stack0xfffffffc,0x44adf4);
      FUN_005f34d1(puVar4,0x44ae0f);
      fVar3 = (float10)P2;
      P2 = (float)-fVar3;
      ffree(fVar3);
      in_ST0 = (float10)thunk_FUN_0045ef21();
      DAT_0078b4e0 = 0;
      DAT_020b945c = f_0;
      *(undefined4 *)(puVar4 + -0x88) = 0;
      goto LAB_0044b2fa;
    }
    if (DAT_007fdf6c == f_999) {
      iVar1 = DAT_007fdf70;
      if ((((DAT_007fdf70 == 0xb) || (DAT_007fdf70 == 0xe)) &&
          (DAT_01f95c88 = DAT_007fdf70 + 1, f_0 <= *(float *)(&DAT_020b943c + DAT_01f95c88 * 4))) &&
         ((f_0 <= *(float *)(&DAT_020b943c + DAT_007fdf70 * 4) &&
          (*(float *)(&DAT_020b943c + DAT_01f95c88 * 4) == f_0 ||
           *(float *)(&DAT_020b943c + DAT_007fdf70 * 4) == f_0)))) {
        if (*(float *)(&DAT_020b943c + DAT_01f95c88 * 4) == f_0) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0054c68f(&DAT_007fdf70,&DAT_01f95c88);
        }
        *(undefined4 *)(&DAT_020b943c + DAT_007fdf70 * 4) =
             *(undefined4 *)(&DAT_020b943c + DAT_01f95c88 * 4);
        *(float *)(&DAT_020b943c + DAT_01f95c88 * 4) = f_0;
        iVar1 = DAT_007fdf70;
      }
      goto LAB_0044ab9a;
    }
  }
  DAT_01f95c88 = 0;
  DAT_01f95c8c = (int)ROUND(DAT_020b9440);
  if (99 < DAT_007fdf70) {
    if (19999 < DAT_007fdf70) {
      DAT_007fdf70 = DAT_007fdf70 / 10000;
      if ((DAT_007fdf6c <= f_0) || (f_45 < DAT_007fdf6c)) goto LAB_0044ae71;
      DAT_01f95c88 = 1;
      goto LAB_0044a752;
    }
    DAT_007fdf70 = DAT_007fdf70 / 100;
    DAT_01f95c88 = -1;
    if (DAT_007fdf70 != 4) goto LAB_0044a752;
    DAT_01f95c94 = DAT_020b944c;
    in_ST0 = (float10)DAT_020b944c;
    if ((ABS(in_ST0) < (float10)f_100) || ((3 < DAT_01f95c8c && (DAT_01f95c8c != 6))))
    goto LAB_0044a752;
    in_ST0 = (float10)DAT_007fdf6c;
    if (ABS(in_ST0) < (float10)f_100) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0046f774(&DAT_007fdf6c);
    }
    else {
      DAT_007fdf6c = f_100;
      if (f_0 < DAT_020b944c) {
        in_ST0 = (float10)f_100;
        DAT_007fdf6c = (float)-in_ST0;
      }
    }
    DAT_007fdf6c = DAT_007fdf6c + DAT_01f95c94;
LAB_0044aa60:
    *(float *)(&DAT_020b943c + DAT_007fdf70 * 4) = DAT_007fdf6c;
    iVar1 = DAT_007fdf70;
    goto LAB_0044ab9a;
  }
LAB_0044a752:
  iVar1 = DAT_007fdf70;
  if ((((f_0 < DAT_020b9458) && (DAT_020b9450 < f_0)) && (DAT_007fdf70 == 99)) &&
     (DAT_01f95c8c == 0xc)) {
    DAT_01f95c8c = (int)ROUND(DAT_020b9458);
    local_60 = 0x12;
    DAT_01f95c84 = 1;
    do {
      if (DAT_01f95c8c == *(int *)(DAT_01f95c84 * 4 + 0x78f8f8)) {
        DAT_020b9458 = (float)*(int *)(DAT_01f95c84 * 4 + 0x78f8b0);
        goto LAB_0044ab9a;
      }
      DAT_01f95c84 = DAT_01f95c84 + 1;
      local_60 = local_60 + -1;
    } while (0 < local_60);
  }
  if (DAT_007fdf70 < 0x2e) {
    if (DAT_01f95c88 != 0) {
      if (DAT_01f95c88 < 1) {
        DAT_007fdf6c = DAT_007fdf6c + *(float *)(&DAT_020b943c + DAT_007fdf70 * 4);
      }
      else {
        DAT_01f95c88 = (int)ROUND(DAT_007fdf6c);
        if ((DAT_01f95c88 < 3) || (0x2d < DAT_01f95c88)) goto LAB_0044ab9a;
        DAT_007fdf6c = *(float *)(&DAT_020b943c + DAT_01f95c88 * 4);
        if ((DAT_01f95c88 == 4) && (DAT_020b9440 == f_6)) {
          ffree(in_ST0);
          fVar3 = (float10)amod(&DAT_007fdf6c,&f_100);
          DAT_007fdf6c = (float)fVar3;
          in_ST0 = extraout_ST1_00;
        }
      }
    }
    if (DAT_007fdf70 == 2) {
      if (DAT_0078d894 < DAT_007fdf6c) goto LAB_0044ae71;
      if (DAT_007fdf6c <= f_0) {
        DAT_007fdf6c = f_1;
      }
    }
    if ((DAT_007fdf70 != 1) || (f_0 < DAT_007fdf6c && DAT_007fdf6c <= f_18)) goto LAB_0044aa60;
  }
  goto LAB_0044ae71;
code_r0x0044acb4:
  DAT_01f95c88 = -2;
  if ((DAT_007fdf64 == 0) || (DAT_007fdf64 == 3)) {
    DAT_01f95c88 = -3;
  }
LAB_0044ad7e:
  P1 = f_400;
  P3 = f_500;
  P4 = (float)DAT_01f95c88;
  P5 = f_0;
  goto LAB_00449ebf;
}


