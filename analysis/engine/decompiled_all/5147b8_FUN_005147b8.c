// FUN_005147b8 @ 005147b8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005147b8(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_EDX;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined2 in_FPUControlWord;
  unkbyte10 extraout_ST0;
  unkbyte10 Var8;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  unkbyte10 extraout_ST0_02;
  float10 fVar9;
  unkbyte10 extraout_ST0_03;
  unkbyte10 extraout_ST0_04;
  float10 extraout_ST0_05;
  unkbyte10 extraout_ST0_06;
  unkbyte10 extraout_ST0_07;
  unkbyte10 extraout_ST0_08;
  unkbyte10 extraout_ST0_09;
  
  puVar4 = &stack0xfffffffc;
  iVar3 = 1;
  while (iVar3 < 0x12d) {
    FUN_005f34d1(puVar4,0x5147f4);
    iVar3 = extraout_EDX + 1;
  }
  DAT_01c4c78c = 0;
  _DAT_01ba0d90 = 0;
  DAT_00795464 = 0;
  ITEM_WORDS = 1;
  DAT_00942254 = 0;
  DAT_0078b4e0 = 0;
  iVar3 = FUN_005f4660(0x20);
  Var8 = extraout_ST0;
  if (iVar3 != 0) {
    FUN_005f33c9(puVar4,0x514879);
    Var8 = FUN_005f34d1(puVar4,0x514894);
  }
  if (**(int **)(puVar4 + 8) != 0) {
    ffree(Var8);
    thunk_FUN_00537db4(&DAT_00942a84,0x80,&DAT_00942250);
    DAT_0094224c = 1;
    goto LAB_005149c5;
  }
  *(undefined4 *)(puVar4 + -0x1a4) = 0;
  puVar5 = (undefined4 *)&DAT_020b8ea0;
  puVar7 = &DAT_01ba20a0;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)(puVar4 + -0x1c4) = 0;
  *(undefined4 *)(puVar4 + -0x1e0) = 0x80;
  *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01ba20a0;
  *(undefined4 *)(puVar4 + -0x1d8) = 3;
  *(undefined **)(puVar4 + -0x1d4) = &DAT_00767764;
  *(undefined4 *)(puVar4 + -0x1d0) = 2;
  ffree(Var8);
  uVar2 = FUN_005f6540(puVar4 + -0x1c4,8,0x784ff01,&DAT_00767754,puVar4 + -0x1e0);
  *(undefined4 *)(puVar4 + -0x194) = uVar2;
  if ((*(int *)(puVar4 + -0x194) != 0) || (DAT_0078b4e0 == 99)) {
    ffree(extraout_ST0_00);
    Var8 = thunk_FUN_0042ac4e(&DAT_01ba20a0,0x80);
    DAT_0078b4e0 = 0x2d;
    *(undefined4 *)(puVar4 + -0x18c) = 0;
LAB_00516bc6:
    ffree(Var8);
    return;
  }
  *(undefined4 *)(puVar4 + -400) = 0;
  puVar5 = &DAT_01ba20a0;
  pcVar6 = s_PARTS_00795090;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pcVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar6 = pcVar6 + 4;
  }
LAB_00514a91:
  FUN_005f33c9(puVar4,0x514aaf);
  FUN_005f33c9(puVar4,0x514acb);
  FUN_005f33c9(puVar4,0x514ae7);
  Var8 = FUN_005f34d1(puVar4,0x514b02);
  _DAT_00942244 = 0;
  DAT_01c4ef40 = 0;
  if (**(int **)(puVar4 + 8) == 0) goto LAB_00514b2d;
  *(undefined4 *)(puVar4 + -0x188) = 0;
  while( true ) {
    while( true ) {
      DAT_01c4ef40 = DAT_01c4ef40 + 1;
      ffree(Var8);
      Var8 = thunk_FUN_004fb0b8(&DAT_00942240,&DAT_0094223c);
      _DAT_0094223c = DAT_01c4ef40 + _DAT_0094223c + -1;
      ffree(Var8);
      Var8 = thunk_FUN_004fb38a(&DAT_00942240,&DAT_0094223c);
      if (**(int **)(puVar4 + 8) != 0) break;
      *(undefined4 *)(puVar4 + -0x17c) = 0;
LAB_00514b2d:
      while( true ) {
        *(undefined4 *)(puVar4 + -0x1c4) = 0;
        *(undefined4 *)(puVar4 + -0x1d8) = 0x200;
        *(undefined2 **)(puVar4 + -0x1d4) = &DAT_020b8ea0;
        *(undefined4 *)(puVar4 + -0x1d0) = 1;
        ffree(Var8);
        uVar2 = FUN_005fdbd0(puVar4 + -0x1c4,8,0x784ff02,&DAT_00767740,puVar4 + -0x1d8,&DAT_00796828
                            );
        *(undefined4 *)(puVar4 + -0x184) = uVar2;
        Var8 = extraout_ST0_01;
        if (*(int *)(puVar4 + -0x184) == -1) goto LAB_00514c86;
        if (DAT_00796868 != (char)DAT_020b8ea0) break;
        *(undefined4 *)(puVar4 + -0x180) = 0;
      }
    }
    DAT_0094224c = DAT_0094224c + 1;
    iVar3 = FUN_00601a30(0x20);
    if (iVar3 != 0) break;
    *(undefined4 *)(puVar4 + -0x174) = 0;
LAB_005149c5:
    FUN_005f33c9(puVar4,0x5149ed);
    Var8 = FUN_005f34d1(puVar4,0x514a08);
    *(undefined4 *)(puVar4 + -0x1a0) = 0x200;
    DAT_00942248 = 1;
    do {
      if ((char)(&DAT_020b8e9f)[DAT_00942248] < ' ') {
        (&DAT_020b8e9f)[DAT_00942248] = 0x20;
      }
      DAT_00942248 = DAT_00942248 + 1;
      *(int *)(puVar4 + -0x1a0) = *(int *)(puVar4 + -0x1a0) + -1;
    } while (0 < *(int *)(puVar4 + -0x1a0));
    if (**(int **)(puVar4 + 8) < 2) goto LAB_00514a7d;
    *(undefined4 *)(puVar4 + -0x19c) = 0;
  }
  *(undefined4 *)(puVar4 + -0x178) = 0;
  Var8 = extraout_ST0_02;
LAB_00514c86:
  *(undefined4 *)(puVar4 + -0x1c4) = 0;
  ffree(Var8);
  fVar9 = (float10)FUN_005f7950(puVar4 + -0x1c4,8,0x784ff00,&DAT_0076773c,0);
  _DAT_00942238 = 0;
  if (DAT_01c4c830 < 2) {
    DAT_01c4c830 = 1;
  }
  DAT_00942234 = (float)DAT_01c4c830;
  DAT_01ba2120 = 5;
  DAT_00942248 = 0;
  DAT_00942230 = 0;
  _DAT_0094222c = 0;
  DAT_00942250 = 0;
  DAT_00942228 = 0;
  _DAT_00942224 = 0;
  DAT_0094265c = 0;
  *(int *)(puVar4 + -0x16c) = DAT_01c4ef40;
  DAT_01c4c840 = 1;
  DAT_01ba2080 = DAT_01c4c830;
  iVar3 = DAT_01c4ef40;
  while (0 < iVar3) {
    puVar5 = (undefined4 *)(&DAT_01c4eec4 + DAT_01c4c840 * 0x80);
    puVar7 = (undefined4 *)(&DAT_00942a04 + DAT_01c4c840 * 0x80);
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    DAT_01c4c840 = DAT_01c4c840 + 1;
    *(int *)(puVar4 + -0x16c) = *(int *)(puVar4 + -0x16c) + -1;
    iVar3 = *(int *)(puVar4 + -0x16c);
  }
LAB_00514d9d:
  if (DAT_0094265c != 0) {
    ITEM_WORDS = 1;
    DAT_01ba2064 = DAT_00942220;
    DAT_01ba2068 = DAT_0094221c;
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    *(undefined4 *)(puVar4 + -0x1e0) = 7;
    *(char **)(puVar4 + -0x1dc) = "pts.tmp";
    *(undefined4 *)(puVar4 + -0x1d8) = 6;
    *(char **)(puVar4 + -0x1d4) = "binary";
    *(undefined4 *)(puVar4 + -0x1d0) = 2;
    *(undefined4 *)(puVar4 + -0x1cc) = 4;
    ffree(fVar9);
    uVar2 = FUN_005f6540(puVar4 + -0x1c4,0x1b,0x784ff01,&DAT_00767718,puVar4 + -0x1e0);
    *(undefined4 *)(puVar4 + -0x164) = uVar2;
    Var8 = extraout_ST0_03;
    if (*(int *)(puVar4 + -0x164) == 0) {
      iVar3 = DAT_0094221c;
      if (DAT_0094221c < 0) {
        iVar3 = 0;
      }
      DAT_01c4c828 = iVar3 + 1;
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      *(undefined4 *)(puVar4 + -0x1e0) = 1;
      *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01c6da60;
      *(undefined4 *)(puVar4 + -0x1d8) = 1;
      *(int *)(puVar4 + -0x1d4) = iVar3;
      *(undefined4 *)(puVar4 + -0x1d0) = 4;
      ffree(extraout_ST0_03);
      Var8 = FUN_005f8240(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_00767714,puVar4 + -0x1e0);
      iVar3 = DAT_01ba2064;
      if (DAT_01ba2064 < 0) {
        iVar3 = 0;
      }
      DAT_01c4c828 = iVar3 + 1;
      *(undefined4 *)(puVar4 + -0x1e0) = 1;
      *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01c46380;
      *(undefined4 *)(puVar4 + -0x1d8) = 1;
      *(int *)(puVar4 + -0x1d4) = iVar3;
      *(undefined4 *)(puVar4 + -0x1d0) = 4;
      ffree(Var8);
      Var8 = FUN_005f8730(puVar4 + -0x1c4,&DAT_00767710,puVar4 + -0x1e0);
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      ffree(Var8);
      fVar9 = (float10)FUN_005f7950(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_0076773c,0);
      DAT_00942218 = 0;
      *(undefined4 *)(puVar4 + -0x158) = 0;
      goto LAB_00515011;
    }
    goto FUN_00516bd1;
  }
  *(undefined4 *)(puVar4 + -0x168) = 0;
  if (DAT_01c4ef40 <= DAT_00942230) {
    *(undefined4 *)(puVar4 + -0x154) = 0;
LAB_00516a39:
    DAT_01c4ef40 = DAT_00942248;
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    *(undefined4 *)(puVar4 + -0x1e0) = 8;
    *(char **)(puVar4 + -0x1dc) = "pts2.tmpInstrument #     not found in some system. ";
    *(undefined4 *)(puVar4 + -0x1d8) = 6;
    *(char **)(puVar4 + -0x1d4) = "binary";
    *(undefined4 *)(puVar4 + -0x1d0) = 2;
    *(undefined4 *)(puVar4 + -0x1cc) = 4;
    ffree(fVar9);
    uVar2 = FUN_005f6540(puVar4 + -0x1c4,0x1b,0x784ff01,&DAT_00767718,puVar4 + -0x1e0);
    *(undefined4 *)(puVar4 + -0xc) = uVar2;
    Var8 = extraout_ST0_09;
    if (*(int *)(puVar4 + -0xc) != 0) goto FUN_00516bd1;
    iVar3 = DAT_01a1fee4;
    if (DAT_01a1fee4 < 0) {
      iVar3 = 0;
    }
    DAT_01c4c828 = iVar3 + 1;
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    *(undefined4 *)(puVar4 + -0x1e0) = 1;
    *(undefined4 **)(puVar4 + -0x1dc) = &ITEM_P1;
    *(undefined4 *)(puVar4 + -0x1d8) = 1;
    *(int *)(puVar4 + -0x1d4) = iVar3;
    *(undefined4 *)(puVar4 + -0x1d0) = 4;
    ffree(extraout_ST0_09);
    Var8 = FUN_005f8240(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_007676ac,puVar4 + -0x1e0);
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    ffree(Var8);
    Var8 = FUN_005f7950(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_0076773c,0);
    ITEM_WORDS = DAT_01a1fee4;
    ffree(Var8);
    Var8 = thunk_FUN_0049c760();
    goto LAB_00516bc6;
  }
  DAT_00942230 = DAT_00942230 + 1;
  DAT_00942214 = *(int *)(&DAT_01a74e9c + DAT_00942230 * 4);
  DAT_00942218 = 0;
  ITEM_WORDS = 1;
  _DAT_0094222c = DAT_00942214;
LAB_0051598e:
  DAT_00942214 = DAT_00942214 + -1;
  if (DAT_00942250 < DAT_01c4ef40) {
    DAT_00942228 = DAT_00942228 + 1;
    ffree(fVar9);
    Var8 = thunk_FUN_00497f00(&DAT_00942a04 + DAT_00942228 * 0x80,0x80,&DAT_01c6da60,&DAT_01c46380,
                              &DAT_01ba2068,&DAT_01ba2064,&ITEM_WORDS);
    if (ITEM_WORDS != -1) {
      ffree(Var8);
      Var8 = thunk_FUN_004faa2c(&DAT_01c6da60,&DAT_01c46380,&DAT_01ba2068,&DAT_01ba2064);
      if (DAT_0078b4e0 == 0x2d) {
        *(undefined4 *)(puVar4 + -0x148) = 0;
        goto LAB_00516bc6;
      }
      DAT_00942658 = DAT_01ba2064 + 1;
      *(undefined4 *)(puVar4 + -0x144) = 0x100;
      DAT_01c4c828 = 1;
      do {
        (&DAT_00942658)[DAT_01c4c828] = 0;
        (&DAT_00942254)[DAT_01c4c828] = 0;
        DAT_01c4c828 = DAT_01c4c828 + 1;
        *(int *)(puVar4 + -0x144) = *(int *)(puVar4 + -0x144) + -1;
      } while (0 < *(int *)(puVar4 + -0x144));
      if (DAT_00942228 == 1) {
        DAT_01c4c844 = MAX_STAFF;
        ffree(Var8);
        Var8 = thunk_FUN_0054c590(&STAFF_STEP0,&DAT_01c41ce0,&MAX_STAFF);
        ffree(Var8);
        Var8 = thunk_FUN_0054c4c6(&STAFF_Y0,&DAT_01c420e4,&MAX_STAFF);
      }
      else {
        *(undefined4 *)(puVar4 + -0x140) = 0;
      }
      DAT_0078b4e4 = 0x53;
      ffree(Var8);
      Var8 = thunk_FUN_0049846f(&DAT_01c6da60,&DAT_01c46380,&DAT_01ba2068,&DAT_01ba2064);
      DAT_00942220 = DAT_01ba2064;
      DAT_0094221c = DAT_01ba2068;
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      *(undefined4 *)(puVar4 + -0x1e0) = 7;
      *(char **)(puVar4 + -0x1dc) = "pts.tmp";
      *(undefined4 *)(puVar4 + -0x1d8) = 6;
      *(char **)(puVar4 + -0x1d4) = "binary";
      *(undefined4 *)(puVar4 + -0x1d0) = 2;
      *(undefined4 *)(puVar4 + -0x1cc) = 4;
      ffree(Var8);
      uVar2 = FUN_005f6540(puVar4 + -0x1c4,0x1b,0x784ff01,&DAT_00767718,puVar4 + -0x1e0);
      *(undefined4 *)(puVar4 + -0x13c) = uVar2;
      Var8 = extraout_ST0_04;
      if (*(int *)(puVar4 + -0x13c) != 0) goto FUN_00516bd1;
      iVar3 = DAT_0094221c;
      if (DAT_0094221c < 0) {
        iVar3 = 0;
      }
      DAT_01c4c828 = iVar3 + 1;
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      *(undefined4 *)(puVar4 + -0x1e0) = 1;
      *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01c6da60;
      *(undefined4 *)(puVar4 + -0x1d8) = 1;
      *(int *)(puVar4 + -0x1d4) = iVar3;
      *(undefined4 *)(puVar4 + -0x1d0) = 4;
      ffree(extraout_ST0_04);
      Var8 = FUN_005fa4d0(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_00767714,puVar4 + -0x1e0);
      iVar3 = DAT_01ba2064;
      if (DAT_01ba2064 < 0) {
        iVar3 = 0;
      }
      DAT_01c4c828 = iVar3 + 1;
      *(undefined4 *)(puVar4 + -0x1e0) = 1;
      *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01c46380;
      *(undefined4 *)(puVar4 + -0x1d8) = 1;
      *(int *)(puVar4 + -0x1d4) = iVar3;
      *(undefined4 *)(puVar4 + -0x1d0) = 4;
      ffree(Var8);
      Var8 = FUN_005fa9f0(puVar4 + -0x1c4,&DAT_00767710,puVar4 + -0x1e0);
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      ffree(Var8);
      fVar9 = (float10)FUN_005f7950(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_0076773c,0);
      *(int *)(puVar4 + -0x130) = DAT_01ba2064;
      DAT_01c4c828 = 1;
      iVar3 = DAT_01ba2064;
      while (0 < iVar3) {
        fVar1 = (float)(&DAT_01c6da64)[(&DAT_01c4637c)[DAT_01c4c828]];
        *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
        *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
        DAT_01c4c820 = *(int *)(puVar4 + -0x1c8);
        if ((&DAT_00942254)[DAT_01c4c820] == 0) {
          (&DAT_00942254)[DAT_01c4c820] = DAT_01c4c828;
        }
        DAT_01c4c828 = DAT_01c4c828 + 1;
        *(int *)(puVar4 + -0x130) = *(int *)(puVar4 + -0x130) + -1;
        iVar3 = *(int *)(puVar4 + -0x130);
      }
      *(undefined4 *)(puVar4 + -300) = 0x100;
      DAT_01c4c828 = 0x100;
      do {
        if ((&DAT_00942254)[DAT_01c4c828] == 0) {
          (&DAT_00942254)[DAT_01c4c828] = (&DAT_00942258)[DAT_01c4c828];
        }
        DAT_01c4c828 = DAT_01c4c828 + -1;
        *(int *)(puVar4 + -300) = *(int *)(puVar4 + -300) + -1;
      } while (0 < *(int *)(puVar4 + -300));
      iVar3 = -DAT_01ba2064 / -1;
      *(int *)(puVar4 + -0x128) = iVar3;
      DAT_01c4c828 = DAT_01ba2064;
      while (0 < iVar3) {
        iVar3 = (&DAT_01c4637c)[DAT_01c4c828];
        fVar1 = (float)(&DAT_01c6da60)[iVar3];
        *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
        *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
        if (*(int *)(puVar4 + -0x1c8) == 0xe) {
          DAT_01c4c820 = 1;
          if (f_4 <= *(float *)(&DAT_01c6da5c + iVar3 * 4)) {
            fVar9 = (float10)(float)(&DAT_01c6da6c)[iVar3];
            *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
            *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
            *(int *)(puVar4 + -0x1c8) = (int)ROUND(ABS(fVar9));
            in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
            DAT_01c4c820 = *(int *)(puVar4 + -0x1c8);
          }
          if (DAT_01c4c820 == 0) {
            DAT_01c4c820 = 1;
          }
          fVar1 = (float)(&DAT_01c6da64)[iVar3];
          *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
          *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
          DAT_01c4c83c = *(int *)(puVar4 + -0x1c8);
          if ((&DAT_00942658)[DAT_01c4c83c] < DAT_01c4c820) {
            (&DAT_00942658)[DAT_01c4c83c] = DAT_01c4c820;
          }
        }
        else {
          *(undefined4 *)(puVar4 + -0x124) = 0;
        }
        *(undefined4 *)(puVar4 + -0x120) = 0;
        DAT_01c4c828 = DAT_01c4c828 + -1;
        *(int *)(puVar4 + -0x128) = *(int *)(puVar4 + -0x128) + -1;
        iVar3 = *(int *)(puVar4 + -0x128);
      }
      DAT_01c4c830 = 0;
      DAT_01c4c828 = 0;
      while( true ) {
        DAT_01c4c828 = DAT_01c4c828 + 1;
        if ((&DAT_00942658)[DAT_01c4c828] == 0) {
          *(undefined4 *)(puVar4 + -0x11c) = 0;
        }
        else {
          DAT_01c4c834 = (&DAT_00942658)[DAT_01c4c828] + DAT_01c4c828 + -1;
          iVar3 = (DAT_01c4c834 - DAT_01c4c828) + 1;
          *(int *)(puVar4 + -0x118) = iVar3;
          DAT_01c4c820 = DAT_01c4c828;
          while (0 < iVar3) {
            (&DAT_00942658)[DAT_01c4c820] = DAT_01c4c828;
            DAT_01c4c820 = DAT_01c4c820 + 1;
            *(int *)(puVar4 + -0x118) = *(int *)(puVar4 + -0x118) + -1;
            iVar3 = *(int *)(puVar4 + -0x118);
          }
          DAT_01c4c830 = DAT_01c4c830 + 1;
          DAT_01c4c828 = DAT_01c4c834;
        }
        if (0xff < DAT_01c4c828) break;
        *(undefined4 *)(puVar4 + -0x114) = 0;
      }
      *(undefined4 *)(puVar4 + -0x110) = 0;
      DAT_00942210 = 0;
      _DAT_0094220c = 0;
LAB_00515011:
      *(undefined4 *)(puVar4 + -0x10c) = 0x100;
      DAT_01c4c828 = 0x100;
      do {
        DAT_01c4c834 = (&DAT_00942658)[DAT_01c4c828];
        if (DAT_01c4c834 != 0) {
          DAT_01c4c838 = (&DAT_00942254)[DAT_01c4c834];
          DAT_01c4c83c = (&DAT_00942258)[DAT_01c4c828];
          iVar3 = -DAT_01c4c828 / -1;
          *(int *)(puVar4 + -0x104) = iVar3;
          DAT_01c4c820 = DAT_01c4c828;
          goto joined_r0x005150cd;
        }
        *(undefined4 *)(puVar4 + -0x108) = 0;
        *(undefined4 *)(puVar4 + -0xf8) = 0;
        DAT_01c4c828 = DAT_01c4c828 + -1;
        *(int *)(puVar4 + -0x10c) = *(int *)(puVar4 + -0x10c) + -1;
      } while (0 < *(int *)(puVar4 + -0x10c));
      goto LAB_00515134;
    }
    *(undefined4 *)(puVar4 + -0x14c) = 0;
    goto LAB_00516bc6;
  }
  *(undefined4 *)(puVar4 + -0x150) = 0;
  goto LAB_00516a39;
LAB_00514a7d:
  **(undefined4 **)(puVar4 + 8) = 2;
  *(undefined4 *)(puVar4 + -0x198) = 0;
  goto LAB_00514a91;
joined_r0x005150cd:
  if (iVar3 < 1) goto LAB_0051512a;
  if (DAT_01c4c834 != (&DAT_00942658)[DAT_01c4c820]) {
    *(undefined4 *)(puVar4 + -0x100) = 0;
    goto LAB_00515134;
  }
  (&DAT_00942658)[DAT_01c4c820] = 0;
  DAT_01c4c820 = DAT_01c4c820 + -1;
  *(int *)(puVar4 + -0x104) = *(int *)(puVar4 + -0x104) + -1;
  iVar3 = *(int *)(puVar4 + -0x104);
  goto joined_r0x005150cd;
LAB_0051512a:
  *(undefined4 *)(puVar4 + -0xfc) = 0;
LAB_00515134:
  DAT_01c4c840 = DAT_01c4c838;
  do {
    DAT_01c4c84c = (&DAT_01c4637c)[DAT_01c4c840];
    fVar1 = (float)(&DAT_01c6da60)[DAT_01c4c84c];
    *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
    *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
    *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
    in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
    DAT_01c4c834 = *(int *)(puVar4 + -0x1c8);
    if (DAT_01c4c834 < 3) {
      if (0 < DAT_01c4c834) goto LAB_005151c6;
      *(undefined4 *)(puVar4 + -0xf0) = 0;
    }
    else {
      *(undefined4 *)(puVar4 + -0xf4) = 0;
LAB_005151c6:
      fVar1 = (float)(&DAT_01c6da64)[DAT_01c4c84c];
      *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
      *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
      DAT_00942208 = *(int *)(puVar4 + -0x1c8);
      fVar1 = *(float *)(&DAT_01c6da5c + DAT_01c4c84c * 4);
      *(undefined2 *)(puVar4 + -0x1cc) = *(undefined2 *)(puVar4 + -0x1cc);
      *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
      *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
      DAT_01c4c844 = *(int *)(puVar4 + -0x1c8);
      if (DAT_00942218 == 0) {
        if (DAT_01c4c834 == 8) {
          if (DAT_01c4c844 < 9) {
            *(undefined4 *)(puVar4 + -0xe4) = 0;
          }
          else {
            P9 = (float)(&DAT_01c6da80)[DAT_01c4c84c];
            DAT_01c4c828 = 0;
            while( true ) {
              DAT_01c4c828 = DAT_01c4c828 + 1;
              DAT_01c4c850 = *(float *)(DAT_01c4c828 * 4 + 0x1b117fc);
              if (DAT_01c4c850 == f_0) break;
              DAT_01c4c854 = DAT_01c4c850;
              if (P9 == DAT_01c4c850) {
                fVar1 = (float)(&DAT_01c6da64)[DAT_01c4c84c];
                *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
                *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
                *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
                in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
                DAT_00942204 = *(int *)(puVar4 + -0x1c8);
                DAT_01c4c848 = DAT_01c4c840 + 1;
                iVar3 = DAT_01c4c83c - DAT_01c4c848;
                *(int *)(puVar4 + -0xd8) = iVar3;
                while (0 < iVar3) {
                  DAT_01c4c834 = (&DAT_01c4637c)[DAT_01c4c848];
                  fVar1 = (float)(&DAT_01c6da64)[DAT_01c4c834];
                  *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
                  *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
                  *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
                  in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
                  _DAT_00942200 = *(int *)(puVar4 + -0x1c8);
                  if ((DAT_00942204 == _DAT_00942200) &&
                     ((float)(&DAT_01c6da60)[DAT_01c4c834] <= f_2)) {
                    *(undefined4 *)(puVar4 + -0xd4) = 0;
                    DAT_00942218 = 1;
                    ffree(fVar9);
                    fVar9 = (float10)thunk_FUN_0049bf20(&DAT_00942208);
                    DAT_00942210 = DAT_00942208;
                    *(undefined4 *)(puVar4 + -0xcc) = 0;
                    goto LAB_00515951;
                  }
                  DAT_01c4c848 = DAT_01c4c848 + 1;
                  *(int *)(puVar4 + -0xd8) = *(int *)(puVar4 + -0xd8) + -1;
                  iVar3 = *(int *)(puVar4 + -0xd8);
                }
                *(undefined4 *)(puVar4 + -0xd0) = 0;
              }
              else {
                *(undefined4 *)(puVar4 + -0xdc) = 0;
              }
            }
            *(undefined4 *)(puVar4 + -0xe0) = 0;
          }
          goto LAB_00515951;
        }
        *(undefined4 *)(puVar4 + -0xe8) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -0xec) = 0;
      }
      if (DAT_00942210 == DAT_00942208) {
        *(undefined4 *)(puVar4 + -200) = 0;
      }
      else if ((DAT_01c4c834 == 0xe) || (DAT_01c4c834 == 0x12)) {
        _DAT_0094220c = 1;
        DAT_009421fc = f_1;
        if (DAT_01c4c834 == 0x12) {
          *(undefined4 *)(puVar4 + -0xc0) = 0;
        }
        else {
          _DAT_009421f8 = (float)(&DAT_01c6da68)[DAT_01c4c84c];
          DAT_01c4c828 = DAT_01c4c840;
          LOAD_I = DAT_01c4c840 + 1;
          iVar3 = DAT_01c4c83c - LOAD_I;
          *(int *)(puVar4 + -0xbc) = iVar3;
          while (0 < iVar3) {
            DAT_01c4c848 = (&DAT_01c4637c)[LOAD_I];
            fVar1 = (float)(&DAT_01c6da60)[DAT_01c4c848];
            *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
            *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
            *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
            LOAD_CODE = *(int *)(puVar4 + -0x1c8);
            if (LOAD_CODE < 3) {
              *(undefined4 *)(puVar4 + -0xb8) = 0;
              break;
            }
            if (LOAD_CODE == 0xe) {
              if (f_0_5 < (float)(&DAT_01c6da68)[DAT_01c4c848] - _DAT_009421f8) {
                *(undefined4 *)(puVar4 + -0xb0) = 0;
                goto LAB_00515951;
              }
            }
            else {
              *(undefined4 *)(puVar4 + -0xb4) = 0;
            }
            *(undefined4 *)(puVar4 + -0xac) = 0;
            LOAD_I = LOAD_I + 1;
            *(int *)(puVar4 + -0xbc) = *(int *)(puVar4 + -0xbc) + -1;
            iVar3 = *(int *)(puVar4 + -0xbc);
          }
          if (DAT_01c4c844 < 6) {
            *(undefined4 *)(puVar4 + -0xa8) = 0;
          }
          else {
            DAT_01c4c828 = DAT_01c4c844;
            if (0xb < DAT_01c4c844) {
              DAT_01c4c828 = 0xb;
            }
            iVar3 = DAT_01c4c828 + -5;
            *(int *)(puVar4 + -0xa4) = iVar3;
            DAT_01c4c848 = 6;
            while (0 < iVar3) {
              *(float *)(&DAT_01c6da5c + (DAT_01c4c848 + DAT_01c4c84c) * 4) = f_0;
              DAT_01c4c848 = DAT_01c4c848 + 1;
              *(int *)(puVar4 + -0xa4) = *(int *)(puVar4 + -0xa4) + -1;
              iVar3 = *(int *)(puVar4 + -0xa4);
            }
            *(undefined4 *)(puVar4 + -0xa0) = 0;
          }
        }
LAB_005156c9:
        DAT_01c4c844 = DAT_01c4c844 + 1;
        DAT_01c4c828 = DAT_01c4c84c + 2;
        *(float *)(&DAT_01c6da5c + DAT_01c4c828 * 4) = DAT_009421fc;
        ffree(fVar9);
        fVar9 = (float10)thunk_FUN_0054c590(&DAT_01c6da5c + DAT_01c4c84c * 4,&ITEM_LEN + ITEM_WORDS,
                                            &DAT_01c4c844);
        ITEM_WORDS = DAT_01c4c844 + ITEM_WORDS;
      }
      else {
        *(undefined4 *)(puVar4 + -0xc4) = 0;
        if (DAT_01c4c834 == 0x10) {
          *(undefined4 *)(puVar4 + -0x9c) = 0;
LAB_00515321:
          fVar1 = (float)(&DAT_01c6da74)[DAT_01c4c84c];
          *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
          *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1 / f_100);
          in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
          DAT_01c4c828 = *(int *)(puVar4 + -0x1c8);
          if (DAT_01c4c828 < 0) {
            DAT_01c4c828 = -DAT_01c4c828;
          }
          if ((DAT_01c4c828 != 0) && (DAT_01c4c828 != 2)) {
            if (DAT_01c4c828 == 3) {
              (&DAT_01c6da74)[DAT_01c4c84c] = f_0;
            }
LAB_005154a7:
            DAT_009421fc = DAT_00942234;
            goto LAB_005156c9;
          }
          *(undefined4 *)(puVar4 + -0x7c) = 0;
        }
        else if (DAT_01c4c834 == 5) {
          if (DAT_01c4c844 < 8) {
            *(undefined4 *)(puVar4 + -0x94) = 0;
          }
          else {
            fVar1 = (float)(&DAT_01c6da7c)[DAT_01c4c84c];
            *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
            *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
            *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
            DAT_01c4c828 = *(int *)(puVar4 + -0x1c8);
            if ((DAT_01c4c828 == 1) || (DAT_01c4c828 == 2)) {
              fVar1 = (float)(&DAT_01c6da70)[DAT_01c4c84c];
              *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
              *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
              *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
              in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
              DAT_01c4c828 = *(int *)(puVar4 + -0x1c8);
              if ((0x59 < DAT_01c4c828) && (DAT_01c4c828 < 0xbe)) {
                *(undefined4 *)(puVar4 + -0x88) = 0;
                goto LAB_005154a7;
              }
              *(undefined4 *)(puVar4 + -0x8c) = 0;
            }
            else {
              *(undefined4 *)(puVar4 + -0x90) = 0;
            }
          }
        }
        else {
          *(undefined4 *)(puVar4 + -0x98) = 0;
          if ((DAT_01c4c834 == 10) || (DAT_01c4c834 == 9)) {
            if (5 < DAT_01c4c844) goto LAB_00515321;
            *(undefined4 *)(puVar4 + -0x80) = 0;
          }
          else {
            *(undefined4 *)(puVar4 + -0x84) = 0;
          }
        }
      }
    }
LAB_00515951:
    DAT_01c4c840 = DAT_01c4c840 + 1;
    if (DAT_01c4c83c <= DAT_01c4c840) break;
    *(undefined4 *)(puVar4 + -0x78) = 0;
  } while( true );
  if (DAT_00942214 < 1) goto LAB_0051612b;
  *(undefined4 *)(puVar4 + -0x74) = 0;
  goto LAB_0051598e;
LAB_0051612b:
  if (DAT_00942218 == 0) {
    if (DAT_00942254 == 0) {
      FUN_005f33c9(puVar4,0x516285);
      Var8 = FUN_005f34d1(puVar4,0x5162a0);
      *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
      *(int *)(puVar4 + -0x1c8) = (int)ROUND(DAT_01c4c854);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
      DAT_009421f4 = *(int *)(puVar4 + -0x1c8);
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      *(undefined4 *)(puVar4 + -0x1d8) = 4;
      *(undefined4 **)(puVar4 + -0x1d4) = &DAT_009ae2c8;
      *(int **)(puVar4 + -0x1d0) = &DAT_009421f4;
      ffree(Var8);
      FUN_005f34f0(puVar4 + -0x1c4,0x784ff00,&DAT_007676e4,puVar4 + -0x1d8,&DAT_0079683c);
      Var8 = FUN_005f33c9(puVar4,0x516364);
      ffree(Var8);
      DAT_009421f4 = thunk_FUN_0059b090();
      fVar9 = extraout_ST0_05;
      if (DAT_009421f4 != 0) {
        DAT_00942254 = 1;
      }
    }
    else {
      *(undefined4 *)(puVar4 + -0x6c) = 0;
    }
    _DAT_00942238 = 1;
    ffree(fVar9);
    Var8 = thunk_FUN_00501148();
    if (DAT_00942248 == 0) {
      ffree(Var8);
      Var8 = thunk_FUN_0050169d();
    }
    if (DAT_0078b4e0 == 0x2d) {
      *(undefined4 *)(puVar4 + -100) = 0;
      goto LAB_00516bc6;
    }
    DAT_0078b4e0 = 0;
    *(undefined4 *)(puVar4 + -0x60) = 0;
  }
  else {
    *(undefined4 *)(puVar4 + -0x70) = 0;
    FUN_005f33c9(puVar4,0x516167);
    FUN_005f33c9(puVar4,0x516183);
    Var8 = FUN_005f34d1(puVar4,0x51619e);
    *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
    *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
    *(int *)(puVar4 + -0x1c8) = (int)ROUND(DAT_01c4c850);
    in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
    DAT_009421f4 = *(int *)(puVar4 + -0x1c8);
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    *(undefined4 *)(puVar4 + -0x1d8) = 4;
    *(undefined1 **)(puVar4 + -0x1d4) = &DAT_020b8ea6;
    *(int **)(puVar4 + -0x1d0) = &DAT_009421f4;
    ffree(Var8);
    Var8 = FUN_005f34f0(puVar4 + -0x1c4,0x784ff00,&DAT_007676e4,puVar4 + -0x1d8,&DAT_00796850);
    ffree(Var8);
    Var8 = thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
  }
  ffree(Var8);
  Var8 = thunk_FUN_00477d48();
  DAT_01c4c834 = 0;
  if (DAT_00942248 == 0) {
    *(undefined4 *)(puVar4 + -0x58) = 0;
  }
  else {
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    *(undefined4 *)(puVar4 + -0x1e0) = 8;
    *(char **)(puVar4 + -0x1dc) = "pts2.tmpInstrument #     not found in some system. ";
    *(undefined4 *)(puVar4 + -0x1d8) = 6;
    *(char **)(puVar4 + -0x1d4) = "binary";
    *(undefined4 *)(puVar4 + -0x1d0) = 2;
    *(undefined4 *)(puVar4 + -0x1cc) = 4;
    ffree(Var8);
    uVar2 = FUN_005f6540(puVar4 + -0x1c4,0x1b,0x784ff01,&DAT_00767718,puVar4 + -0x1e0);
    *(undefined4 *)(puVar4 + -0x54) = uVar2;
    Var8 = extraout_ST0_06;
    if (*(int *)(puVar4 + -0x54) != 0) {
FUN_00516bd1:
      ffree(Var8);
                    /* WARNING: Subroutine does not return */
      FUN_006013a0(&DAT_007676a8,0,0x784ff00,0,0);
    }
    iVar3 = DAT_01a1fee4;
    if (DAT_01a1fee4 < 0) {
      iVar3 = 0;
    }
    DAT_01c4c828 = iVar3 + 1;
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    *(undefined4 *)(puVar4 + -0x1e0) = 1;
    *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01ba2140;
    *(undefined4 *)(puVar4 + -0x1d8) = 1;
    *(int *)(puVar4 + -0x1d4) = iVar3;
    *(undefined4 *)(puVar4 + -0x1d0) = 4;
    ffree(extraout_ST0_06);
    Var8 = FUN_005f8240(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_007676ac,puVar4 + -0x1e0);
    *(undefined4 *)(puVar4 + -0x1c4) = 0;
    ffree(Var8);
    Var8 = FUN_005f7950(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_0076773c,0);
    ffree(Var8);
    Var8 = FUN_00516bf9(&DAT_01c4c834);
    if (DAT_01c4c834 != 0) {
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      *(undefined4 *)(puVar4 + -0x1e0) = 8;
      *(char **)(puVar4 + -0x1dc) = "pts2.tmpInstrument #     not found in some system. ";
      *(undefined4 *)(puVar4 + -0x1d8) = 6;
      *(char **)(puVar4 + -0x1d4) = "binary";
      *(undefined4 *)(puVar4 + -0x1d0) = 2;
      *(undefined4 *)(puVar4 + -0x1cc) = 4;
      ffree(Var8);
      uVar2 = FUN_005f6540(puVar4 + -0x1c4,0x1b,0x784ff01,&DAT_00767718,puVar4 + -0x1e0);
      *(undefined4 *)(puVar4 + -0x48) = uVar2;
      Var8 = extraout_ST0_07;
      if (*(int *)(puVar4 + -0x48) != 0) goto FUN_00516bd1;
      iVar3 = DAT_01a1fee4;
      if (DAT_01a1fee4 < 0) {
        iVar3 = 0;
      }
      DAT_01c4c828 = iVar3 + 1;
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      *(undefined4 *)(puVar4 + -0x1e0) = 1;
      *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01ba2140;
      *(undefined4 *)(puVar4 + -0x1d8) = 1;
      *(int *)(puVar4 + -0x1d4) = iVar3;
      *(undefined4 *)(puVar4 + -0x1d0) = 4;
      ffree(extraout_ST0_07);
      Var8 = FUN_005fa4d0(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_007676ac,puVar4 + -0x1e0);
      *(undefined4 *)(puVar4 + -0x1c4) = 0;
      ffree(Var8);
      fVar9 = (float10)FUN_005f7950(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_0076773c,0);
      *(undefined4 *)(puVar4 + -0x3c) = 0;
      goto LAB_005169a6;
    }
    *(int *)(puVar4 + -0x38) = DAT_01a1fee0;
    LOAD_I = 1;
    if (0 < DAT_01a1fee0) {
LAB_005166cf:
      if (f_2 < (float)(&DAT_01ba2140)[(&DAT_01a1fee4)[LOAD_I]]) goto code_r0x005166f0;
      *(undefined4 *)(puVar4 + -0x34) = 0;
      ffree(Var8);
      Var8 = thunk_FUN_0054c590(&DAT_01ba2140,&ITEM_P1,&DAT_01a1fee4);
      DAT_01c4c820 = 1;
      while( true ) {
        fVar1 = (float)(&ITEM_LEN)[DAT_01c4c820];
        *(undefined2 *)(puVar4 + -0x1cc) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0x1ca) = (ushort)*(undefined4 *)(puVar4 + -0x1cc) | 0xc00;
        *(int *)(puVar4 + -0x1c8) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1cc);
        DAT_01c4c828 = *(int *)(puVar4 + -0x1c8);
        if ((DAT_01c4c828 < 0x11) || ((float)(&ITEM_P1)[DAT_01c4c820] != f_2)) {
          *(undefined4 *)(puVar4 + -0x2c) = 0;
        }
        else {
          *(float *)(&ITEM_P17 + DAT_01c4c820 * 4) = f_0;
        }
        DAT_01c4c820 = DAT_01c4c828 + DAT_01c4c820 + 1;
        if (DAT_01a1fee4 <= DAT_01c4c820) break;
        *(undefined4 *)(puVar4 + -0x28) = 0;
      }
      ITEM_WORDS = DAT_01a1fee4;
      ffree(Var8);
      Var8 = thunk_FUN_0049c760();
      goto LAB_0051681f;
    }
LAB_00516810:
    LOAD_I = 0;
    *(undefined4 *)(puVar4 + -0x30) = 0;
  }
LAB_0051681f:
  ffree(Var8);
  Var8 = thunk_FUN_0054c4c6(&DAT_01c46380,&DAT_01a1fee8,&DAT_01ba2064);
  *(undefined4 *)(puVar4 + -0x1c4) = 0;
  *(undefined4 *)(puVar4 + -0x1e0) = 8;
  *(char **)(puVar4 + -0x1dc) = "pts2.tmpInstrument #     not found in some system. ";
  *(undefined4 *)(puVar4 + -0x1d8) = 6;
  *(char **)(puVar4 + -0x1d4) = "binary";
  *(undefined4 *)(puVar4 + -0x1d0) = 2;
  *(undefined4 *)(puVar4 + -0x1cc) = 4;
  ffree(Var8);
  uVar2 = FUN_005f6540(puVar4 + -0x1c4,0x1b,0x784ff01,&DAT_00767718,puVar4 + -0x1e0);
  *(undefined4 *)(puVar4 + -0x24) = uVar2;
  Var8 = extraout_ST0_08;
  if (*(int *)(puVar4 + -0x24) != 0) goto FUN_00516bd1;
  iVar3 = DAT_01ba2068;
  if (DAT_01ba2068 < 0) {
    iVar3 = 0;
  }
  DAT_01c4c828 = iVar3 + 1;
  *(undefined4 *)(puVar4 + -0x1c4) = 0;
  *(undefined4 *)(puVar4 + -0x1e0) = 1;
  *(undefined4 **)(puVar4 + -0x1dc) = &DAT_01c6da60;
  *(undefined4 *)(puVar4 + -0x1d8) = 1;
  *(int *)(puVar4 + -0x1d4) = iVar3;
  *(undefined4 *)(puVar4 + -0x1d0) = 4;
  ffree(extraout_ST0_08);
  Var8 = FUN_005fa4d0(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_007676ac,puVar4 + -0x1e0);
  *(undefined4 *)(puVar4 + -0x1c4) = 0;
  ffree(Var8);
  fVar9 = (float10)FUN_005f7950(puVar4 + -0x1c4,0x1b,0x784ff00,&DAT_0076773c,0);
  DAT_01a1fee4 = DAT_01ba2068;
  DAT_01a1fee0 = DAT_01ba2064;
LAB_005169a6:
  if (DAT_0094265c == 0) {
    DAT_00942250 = DAT_00942214 + DAT_00942250;
  }
  if (DAT_01c4c834 == 0) {
    if (LOAD_I == 0) {
      *(undefined4 *)(puVar4 + -0x14) = 0;
    }
    else {
      DAT_00942248 = DAT_00942248 + 1;
      puVar5 = &DAT_01ba20a0;
      puVar7 = (undefined4 *)(&DAT_01c4eec4 + DAT_00942248 * 0x80);
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      *(undefined4 *)(puVar4 + -0x10) = 0;
    }
  }
  else {
    *(undefined4 *)(puVar4 + -0x18) = 0;
  }
  goto LAB_00514d9d;
code_r0x005166f0:
  LOAD_I = LOAD_I + 1;
  *(int *)(puVar4 + -0x38) = *(int *)(puVar4 + -0x38) + -1;
  if (*(int *)(puVar4 + -0x38) < 1) goto LAB_00516810;
  goto LAB_005166cf;
}


