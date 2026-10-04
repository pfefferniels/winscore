// FUN_00497f00 @ 00497f00 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497f00(undefined4 param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *pcVar9;
  bool bVar10;
  undefined2 in_FPUControlWord;
  undefined2 uVar11;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 Var12;
  float10 fVar13;
  float10 fVar14;
  int *in_stack_0000001c;
  
  puVar5 = &stack0xfffffffc;
  ffree(in_ST0);
  uVar2 = thunk_FUN_0054ec49(param_1,0x80);
  if ((uVar2 & 1) == 0) {
    ffree(extraout_ST0);
    Var12 = thunk_FUN_0042ac4e(param_1,0x80);
    ITEM_WORDS = -1;
  }
  else {
    MAX_STAFF = 0x100;
    ITEM_WORDS = *in_stack_0000001c;
    FUN_005f33c9(&stack0xfffffffc,0x497f63);
    Var12 = FUN_005f34d1(puVar5,0x497f7e);
    *(undefined1 *)(*(int *)(puVar5 + 8) + 0x7f) = 0;
    puVar6 = *(undefined4 **)(puVar5 + 8);
    puVar8 = (undefined4 *)&DAT_020b90aa;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    DAT_0082a694 = DAT_01c5860c;
    ffree(Var12);
    Var12 = thunk_FUN_00529628(&DAT_007632b0,&DAT_0082a690,*(undefined4 *)(puVar5 + 0x10),
                               &DAT_01c5860c,*(undefined4 *)(puVar5 + 8),0x80);
    puVar4 = DAT_0078b4e0;
    if ((int)DAT_0078b4e0 < 0) {
      FUN_005f33c9(puVar5,0x497ff4);
      Var12 = FUN_005f34d1(puVar5,0x49800f);
      puVar4 = &stack0xffffff9c;
    }
    bVar10 = puVar4 == (undefined1 *)0x0;
    iVar3 = 5;
    pcVar7 = (char *)&DAT_020b8ea0;
    pcVar9 = "Error";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar10 = *pcVar7 == *pcVar9;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (bVar10) {
      ffree(Var12);
      Var12 = thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
      ITEM_WORDS = -1;
      *(undefined4 *)(puVar5 + -0x24) = 0;
    }
    else {
      if (DAT_0082a694 != 0) {
        DAT_01c5860c = DAT_0082a694;
      }
      ffree(Var12);
      fVar13 = (float10)FUN_0049836a(*(undefined4 *)(puVar5 + 0x10),*(undefined4 *)(puVar5 + 0x14),
                                     *(undefined4 *)(puVar5 + 0x18),*(undefined4 *)(puVar5 + 0x1c),
                                     &DAT_0082a690);
      DAT_0082a68c = 0;
      iVar3 = **(int **)(puVar5 + 0x1c);
      *(int *)(puVar5 + -0x20) = iVar3;
      DAT_0082a694 = 1;
      while (0 < iVar3) {
        DAT_0082a688 = *(int *)(DAT_0082a694 * 4 + *(int *)(puVar5 + 0x14) + -4);
        fVar1 = *(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0082a688 * 4);
        *(undefined2 *)(puVar5 + -0x54) = in_FPUControlWord;
        *(ushort *)(puVar5 + -0x52) = (ushort)*(undefined4 *)(puVar5 + -0x54) | 0xc00;
        *(int *)(puVar5 + -0x50) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar5 + -0x54);
        DAT_0082a684 = *(int *)(puVar5 + -0x50);
        if (DAT_01c5860c < 3) {
          if (*(float *)(*(int *)(puVar5 + 0x10) + DAT_0082a688 * 4) != f_16) {
            *(undefined4 *)(puVar5 + -0x18) = 0;
            goto LAB_00498127;
          }
          if (*(float *)(*(int *)(puVar5 + 0x10) + 0x2c + DAT_0082a688 * 4) == f_0) {
            *(undefined4 *)(puVar5 + -0x14) = 0;
          }
          else {
            if (DAT_0082a68c == 0) {
              DAT_0082a68c = DAT_0082a688;
            }
            *(undefined4 *)(*(int *)(puVar5 + 0x10) + 8 + DAT_0082a688 * 4) =
                 *(undefined4 *)(*(int *)(puVar5 + 0x10) + 8 + DAT_0082a68c * 4);
          }
          DAT_0082a68c = DAT_0082a688;
          *(undefined4 *)(puVar5 + -0x10) = 0;
        }
        else {
          *(undefined4 *)(puVar5 + -0x1c) = 0;
LAB_00498127:
          if (*(float *)(*(int *)(puVar5 + 0x10) + DAT_0082a688 * 4) == f_8) {
            DAT_0082a680 = f_25;
            if (DAT_0082a684 < 5) {
              *(undefined4 *)(puVar5 + -8) = 0;
            }
            else {
              DAT_0082a680 = *(float *)(*(int *)(puVar5 + 0x10) + 0x10 + DAT_0082a688 * 4) * f_25;
              if (DAT_0082a680 == f_0) {
                DAT_0082a680 = f_25;
              }
            }
            fVar1 = *(float *)(*(int *)(puVar5 + 0x10) + 4 + DAT_0082a688 * 4);
            *(undefined2 *)(puVar5 + -0x54) = in_FPUControlWord;
            *(ushort *)(puVar5 + -0x52) = (ushort)*(undefined4 *)(puVar5 + -0x54) | 0xc00;
            *(int *)(puVar5 + -0x50) = (int)ROUND(fVar1);
            uVar11 = *(undefined2 *)(puVar5 + -0x54);
            CUR_STAFF = *(int *)(puVar5 + -0x50);
            (&STAFF_STEP0)[CUR_STAFF] = DAT_0082a680;
            _DAT_0082a67c = f_0;
            if (3 < DAT_0082a684) {
              ffree(fVar13);
              fVar13 = (float10)amod(DAT_0082a688 * 4 + *(int *)(puVar5 + 0x10) + 0xc,&DAT_00763280)
              ;
              _DAT_0082a67c = (float)fVar13;
            }
            iVar3 = CUR_STAFF;
            DAT_0082a698 = CUR_STAFF;
            _DAT_0082a69c = CUR_STAFF * 0xc4e + -0x6a0e;
            fVar13 = ((float10)_DAT_0082a67c * (float10)f_7 - (float10)f_21) * (float10)DAT_0082a680
            ;
            fVar14 = (float10)_DAT_0082a69c;
            *(undefined2 *)(puVar5 + -0x54) = uVar11;
            *(ushort *)(puVar5 + -0x52) = (ushort)*(undefined4 *)(puVar5 + -0x54) | 0xc00;
            *(int *)(puVar5 + -0x50) = (int)ROUND(fVar14 + fVar13);
            in_FPUControlWord = *(undefined2 *)(puVar5 + -0x54);
            (&STAFF_Y0)[iVar3] = *(undefined4 *)(puVar5 + -0x50);
          }
          else {
            *(undefined4 *)(puVar5 + -0xc) = 0;
          }
        }
        *(undefined4 *)(puVar5 + -4) = 0;
        DAT_0082a694 = DAT_0082a694 + 1;
        *(int *)(puVar5 + -0x20) = *(int *)(puVar5 + -0x20) + -1;
        iVar3 = *(int *)(puVar5 + -0x20);
      }
      DAT_0078b4e4 = 0;
      ffree(fVar13);
      Var12 = FUN_0049846f(*(undefined4 *)(puVar5 + 0x10),*(undefined4 *)(puVar5 + 0x14),
                           *(undefined4 *)(puVar5 + 0x18),*(undefined4 *)(puVar5 + 0x1c));
    }
  }
  ffree(Var12);
  return;
}


