// FUN_004a1240 @ 004a1240 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004a15ec) */
/* WARNING: Removing unreachable block (ram,0x004a1d72) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a1240(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 in_ST0;
  unkbyte10 Var8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int local_b8;
  
  puVar9 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  puVar11 = &stack0xfffffffc;
  puVar12 = &stack0xfffffffc;
  puVar13 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  DAT_00838aa0 = 0;
  if (DAT_02052740 != 0) {
    ffree(in_ST0);
    in_ST0 = (float10)FUN_004a2c81(param_1,s_M_C_DELJLIJ_TREDCTCPSTJTMUMD_0079182c,2);
    if (*param_1 == -1) {
LAB_004a20da:
      ffree(in_ST0);
      Var8 = thunk_FUN_0054d7d4(&DAT_020b8ea0,2);
      ffree(Var8);
      in_ST0 = (float10)thunk_FUN_0054d831(&DAT_0076365c,3);
      goto LAB_004a2140;
    }
    goto LAB_004a2116;
  }
  if ((_DAT_020b90a0 == 0x5443) || (_DAT_020b90a0 == 0x5350)) {
    DAT_01fbb8a4 = 0;
  }
  _DAT_00838a9c = 0;
  switch(*param_1) {
  default:
    local_b8 = 0xe;
    DAT_00838aa0 = 1;
    do {
      if (*(short *)(DAT_00838aa0 * 2 + 0x79182a) == DAT_020b8ea0) {
        DAT_01fbb8a4 = DAT_00838aa0;
        if ((DAT_00838aa0 < 4) || (6 < DAT_00838aa0)) {
          DAT_02052760 = 0;
          DAT_01fbb8a0 = 2;
          goto LAB_004a1f15;
        }
        if (DAT_00838aa0 != 6) goto LAB_004a201b;
        FUN_005f33c9(&stack0xfffffffc,0x4a1ea9);
        in_ST0 = (float10)FUN_005f34d1(puVar12,0x4a1ec4);
        DAT_01fbb8a0 = 8;
        *(undefined4 *)(puVar12 + -0x98) = 0;
        puVar5 = puVar12;
        goto LAB_004a2062;
      }
      DAT_00838aa0 = DAT_00838aa0 + 1;
      local_b8 = local_b8 + -1;
    } while (0 < local_b8);
    if (DAT_020b8ea0 != 0x2020) goto LAB_004a20da;
    goto LAB_004a2140;
  case 2:
  case 0x10:
    if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
      DAT_01fbb7e0 = VEC_N;
      ffree(in_ST0);
      Var8 = thunk_FUN_0041b011();
    }
    else {
      ffree(in_ST0);
      Var8 = thunk_FUN_00518448();
      if (P5 != f_0) {
        iVar1 = 5;
        for (iVar2 = 1; iVar2 < 0x13; iVar2 = iVar2 + 1) {
          *(undefined4 *)(iVar2 * 4 + 0x1c5855c) = *(undefined4 *)(&P0 + iVar1 * 4);
          iVar1 = iVar1 + 1;
        }
      }
      DAT_01fbb7e0 = VEC_N;
      ffree(Var8);
      Var8 = thunk_FUN_0041aa88();
    }
    ffree(Var8);
    in_ST0 = (float10)FUN_004a30bb(&DAT_00838a98,&DAT_0076382c);
    if (DAT_00838a98 == -2) goto LAB_004a1d31;
    if (DAT_00838a98 == 0) {
      puVar6 = (undefined4 *)&DAT_020b90a0;
      puVar7 = &DAT_009ae2bc;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      VEC_N = DAT_01fbb7e0;
      ffree(in_ST0);
      thunk_FUN_00549422();
      goto LAB_004a1f15;
    }
    DAT_01fbb860 = (int)ROUND(P1);
    DAT_01fbb868 = P2;
    DAT_01fbb86c = P3;
    DAT_01fbb864 = (int)ROUND(P4);
    if (DAT_01fbb8a4 == 9) goto LAB_004a2172;
LAB_004a191d:
    FUN_005f33c9(&stack0xfffffffc,&LAB_004a193b);
    in_ST0 = (float10)FUN_005f34d1(puVar11,&LAB_004a1956);
    if (DAT_01fbb8a4 == 0xd) {
      FUN_005f33c9(puVar11,&LAB_004a1981);
      in_ST0 = (float10)FUN_005f34d1(puVar11,&LAB_004a199c);
    }
    if (DAT_01fbb8a0 == 0x10) {
      DAT_0078b4e0 = 0xffffffff;
    }
    DAT_01fbb8a0 = 3;
    *(undefined4 *)(puVar11 + -0x7c) = 0;
    puVar5 = puVar11;
    break;
  case 3:
  case 4:
  case 0x12:
    if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
LAB_004a18a6:
      DAT_01fbb7e4 = VEC_N;
      ffree(in_ST0);
      Var8 = thunk_FUN_0041b011();
      ffree(Var8);
      in_ST0 = (float10)FUN_004a30bb(&DAT_00838a98,&DAT_007637b4);
      puVar3 = &stack0xfffffffc;
      if (DAT_00838a98 != -2) {
        if (DAT_00838a98 == 0) {
          VEC_N = DAT_01fbb7e4;
          puVar6 = (undefined4 *)&DAT_020b90a0;
          puVar7 = &DAT_009ae2bc;
          for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          ffree(in_ST0);
          thunk_FUN_00549422();
          goto LAB_004a191d;
        }
LAB_004a19cb:
        DAT_01fbb890 = (int)ROUND(P1);
        DAT_01fbb880 = P2;
        _DAT_01fbb884 = P3;
        _DAT_01fbb888 = P5;
LAB_004a1a2e:
        DAT_00838aa0 = 0;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_00442800(&DAT_00838aa0);
        if (((DAT_02052760 == 0) && (2 < DAT_01fbb8a4)) && (DAT_01fbb8a4 < 3)) {
          DAT_00838a94 = DAT_01fbb8a4;
          DAT_01fbb8a0 = 0x11;
          ffree(in_ST0);
          in_ST0 = (float10)FUN_004a217d();
          DAT_01fbb8a4 = DAT_00838a94;
          goto LAB_004a2172;
        }
        goto LAB_004a2116;
      }
    }
    else {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00518448();
      if ((DAT_01fbb8a4 == 0xd) || (DAT_01fbb8a4 == 0xe)) {
        _DAT_01fbb888 = P1;
        DAT_01fbb890 = DAT_01fbb860;
        DAT_01fbb880 = f_0;
        _DAT_01fbb884 = f_0;
        if (DAT_01fbb8a4 == 0xe) {
          in_ST0 = (float10)P1;
          _DAT_01fbb888 = (float)-in_ST0;
        }
        DAT_01fbb8a4 = 1;
        goto LAB_004a1a2e;
      }
      DAT_01fbb7e0 = VEC_N;
      ffree(in_ST0);
      Var8 = thunk_FUN_0041aa88();
      ffree(Var8);
      in_ST0 = (float10)FUN_004a30bb(&DAT_00838a98,&DAT_007637b4);
      puVar3 = &stack0xfffffffc;
      if (DAT_00838a98 != -2) {
        if (DAT_00838a98 == 0) {
          VEC_N = DAT_01fbb7e0;
          goto LAB_004a18a6;
        }
        goto LAB_004a19cb;
      }
    }
    goto LAB_004a1d31;
  case 5:
    DAT_01fbb8a4 = 5;
    DAT_01fbb8a0 = 6;
    FUN_005f33c9(&stack0xfffffffc,&LAB_004a16f0);
    puVar5 = puVar10;
    in_ST0 = (float10)FUN_005f34d1(puVar10,&LAB_004a170b);
    *(undefined4 *)(puVar5 + -0x5c) = 0;
    break;
  case 6:
    if ((char)DAT_020b8ea0 == '|') {
      DAT_01fbb7e4 = VEC_N;
      ffree(in_ST0);
      Var8 = thunk_FUN_0041b011();
      ffree(Var8);
      in_ST0 = (float10)FUN_004a30bb(&DAT_00838a98,&DAT_0076382c);
      puVar3 = &stack0xfffffffc;
      if (DAT_00838a98 != -2) {
        if (DAT_00838a98 == 0) goto LAB_004a14e0;
        goto LAB_004a1542;
      }
      goto LAB_004a1d31;
    }
LAB_004a14e0:
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00518448();
    if (((char)DAT_020b8ea0 != 'B') && (P1 != f_0 || P3 != f_0)) {
LAB_004a1542:
      DAT_01fbb8a0 = 7;
      DAT_01fbb860 = (int)ROUND(P1);
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      DAT_01fbb864 = (int)ROUND(P4);
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0054946a("Enter up to 5 Code numbers. (0 = all Codes)",0x2c);
      goto LAB_004a2172;
    }
    goto LAB_004a2140;
  case 7:
    ffree(in_ST0);
    Var8 = thunk_FUN_00518448();
    DAT_01c58560 = P1;
    if ((float)DAT_02052760 != f_0) {
      DAT_02052760 = (int)ROUND(P1);
    }
    ffree(Var8);
    FUN_004a217d();
    in_ST0 = (float10)FUN_005f34d1(&stack0xfffffffc,&LAB_004a16ac);
    *(undefined4 *)(puVar9 + -0x60) = 0;
    puVar3 = puVar9;
    goto LAB_004a1d31;
  case 8:
  case 0xb:
    DAT_01fbb7e0 = VEC_N;
    if ((char)DAT_020b8ea0 == '|') {
      ffree(in_ST0);
      Var8 = thunk_FUN_0041b011();
    }
    else {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00518448();
      if (((char)DAT_020b8ea0 == 'B') || (P1 == f_0 && P3 == f_0)) goto LAB_004a2140;
      ffree(in_ST0);
      Var8 = thunk_FUN_0041aa88();
    }
    ffree(Var8);
    in_ST0 = (float10)FUN_004a30bb(&DAT_00838a98,&DAT_0076382c);
    puVar3 = &stack0xfffffffc;
    if (DAT_00838a98 != -2) {
      if (DAT_00838a98 == 0) {
        puVar6 = (undefined4 *)&DAT_020b90a0;
        puVar7 = &DAT_009ae2bc;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        VEC_N = DAT_01fbb7e0;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_00549422();
        break;
      }
      if (DAT_00838aa0 == 8) {
        if (P2 < f_0) {
          P2 = f_0;
        }
        if ((P3 == f_0) || (DAT_01fbb8b8 < P3)) {
          P3 = DAT_01fbb8b8;
        }
      }
      DAT_01fbb860 = (int)ROUND(P1);
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      DAT_01fbb864 = (int)ROUND(P4);
      if (DAT_01fbb8a0 == 0xb) {
        _DAT_01c4cbe0 = P2;
        _DAT_01c4cbe8 = P2;
        DAT_01c4cbe4 = P3;
        if (P3 <= P2) {
          DAT_01c4cbe4 = DAT_01fbb8b8;
        }
        _DAT_01c4cbec = DAT_01c4cbe4;
        _DAT_01c4cbf0 = P1;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0055b1f8();
        puVar3 = &stack0xfffffffc;
      }
      else {
        ffree(in_ST0);
        Var8 = thunk_FUN_0054946a(&DAT_00763748,1);
        ffree(Var8);
        in_ST0 = (float10)thunk_FUN_004b7ad8();
        VEC_N = DAT_01fbb7e0;
        puVar3 = &stack0xfffffffc;
      }
    }
LAB_004a1d31:
    *DAT_01fbb7c0 = DAT_01fbb7e0 + -1;
    *(int *)(puVar3 + -0xe4) = VEC_BASE;
    *(int *)(puVar3 + -0xe8) = VEC_STRIDE;
    *(undefined4 *)(puVar3 + -0xec) = 0x10;
    *(int *)(puVar3 + -0xf0) = VEC_STRIDE * VEC_LBOUND;
    iVar1 = DAT_01fbb7e0;
    for (iVar2 = 1; iVar2 <= *(int *)(puVar3 + -0xec); iVar2 = iVar2 + 1) {
      *(undefined4 *)
       ((*(int *)(puVar3 + -0xe4) - *(int *)(puVar3 + -0xf0)) + *(int *)(puVar3 + -0xe8) * iVar1) =
           0;
      iVar1 = iVar1 + 1;
    }
LAB_004a2116:
    ffree(in_ST0);
    Var8 = draw_items();
    ffree(Var8);
    Var8 = thunk_FUN_00549422();
    DAT_01fbb8a4 = 0;
    ffree(Var8);
    in_ST0 = (float10)thunk_FUN_00468df8(&DAT_00763658);
LAB_004a2140:
    DAT_01fbb8a0 = 0;
    if (DAT_00838a98 == -2) {
      ffree(in_ST0);
      in_ST0 = (float10)draw_items();
    }
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00597b60(0xffffffff);
    _DAT_00838a9c = 0;
    goto LAB_004a2172;
  case 0xc:
    DAT_01fbb8a4 = 5;
    DAT_01fbb8a0 = 0xd;
    puVar5 = &stack0xfffffffc;
    break;
  case 0xd:
    DAT_01fbb8a0 = -1;
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00494302();
    goto LAB_004a2172;
  case 0xe:
    DAT_01fbb8a4 = 5;
    DAT_01fbb8a0 = 0xf;
LAB_004a1f15:
    FUN_005f33c9(&stack0xfffffffc,0x4a1f33);
    in_ST0 = (float10)FUN_005f34d1(puVar13,0x4a1f4e);
    puVar4 = puVar13;
    if (DAT_00838aa0 == 8) {
      DAT_01fbb8a0 = 0x10;
      ffree(in_ST0);
      thunk_FUN_005725fa();
      FUN_005f33c9(puVar13,0x4a1f8b);
      in_ST0 = (float10)FUN_005f34d1(puVar13,0x4a1fa6);
      puVar4 = puVar13;
    }
    if (DAT_00838aa0 == 6) {
      DAT_01fbb8a0 = 8;
    }
    if (DAT_00838aa0 == 7) {
      DAT_01fbb8a0 = 0xb;
    }
    if (DAT_00838aa0 == 10) {
      DAT_02052760 = 1;
    }
    if (DAT_00838aa0 == 0xc) {
      DAT_01fbb8a4 = 1;
      *(undefined4 *)(puVar4 + -0xa0) = 0;
LAB_004a201b:
      DAT_01fbb8a0 = 8;
      FUN_005f33c9(puVar4,0x4a2039);
      in_ST0 = (float10)FUN_005f34d1(puVar4,0x4a2054);
      *(undefined4 *)(puVar4 + -0x94) = 0;
      puVar5 = puVar4;
    }
    else {
      *(undefined4 *)(puVar4 + -0xa4) = 0;
      puVar5 = puVar4;
    }
    break;
  case 0xf:
    DAT_01fbb8a0 = -1;
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_005770d8();
    goto LAB_004a2172;
  }
LAB_004a2062:
  puVar6 = &DAT_009ae2bc;
  puVar7 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_0041b68a();
  *(undefined4 *)(puVar5 + -0x9c) = 0;
LAB_004a2172:
  ffree(in_ST0);
  return;
}


