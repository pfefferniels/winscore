// cmd_input @ 004afb68 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cmd_input(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 extraout_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  puVar6 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  iVar1 = FUN_005f4660(0x20);
  fVar5 = extraout_ST0;
  if (iVar1 != 0) {
LAB_004aff8e:
    if (0 < ITEM_I) {
      if (DAT_0078b4e4 != 0x46) {
        ffree(fVar5);
        fVar5 = (float10)thunk_FUN_0045ef21();
        goto LAB_004b0232;
      }
      if (DAT_020b8ea2 == 'X') {
        iVar1 = FUN_005f4660(0x20);
        if (iVar1 == 0) {
          puVar2 = (undefined4 *)&DAT_020b90a0;
          puVar3 = &DAT_0089f164;
          for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar3 = puVar3 + 1;
          }
        }
        FUN_005f33c9(&stack0xfffffffc,0x4b003e);
        Var4 = FUN_005f34d1(puVar7,0x4b0059);
        if (DAT_02052740 != 0) {
          *(undefined4 *)(puVar7 + -0x7c) = 0;
          ffree(Var4);
          Var4 = FUN_005f7950(puVar7 + -0x7c,DAT_02052740,0x784ff00,&DAT_007643ac,0);
          DAT_02052740 = 0;
        }
        puVar2 = (undefined4 *)&DAT_020b90a0;
        puVar3 = &DAT_01fb8cc4;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        DAT_01fbb8a0 = 0x1f;
        ffree(Var4);
        fVar5 = (float10)thunk_FUN_00445fff();
        *(undefined4 *)(puVar7 + -0x40) = 0;
        goto LAB_004b0232;
      }
      ffree(fVar5);
      Var4 = thunk_FUN_00579770(&DAT_007643a8,1,&DAT_0089f14c);
      DAT_0089f144 = VIEW_DY;
      ffree(Var4);
      Var4 = FUN_004b041d();
      VIEW_DY = DAT_0089f144;
      ffree(Var4);
      Var4 = thunk_FUN_00579770(&DAT_007643a4,1,&DAT_0089f14c);
      ffree(Var4);
      draw_items();
    }
    goto LAB_004b0139;
  }
  if (((((_DAT_020b90a0 & 0xffff) != 0x5843) && ((float)ITEM_I == P2)) &&
      (DAT_020b8ea0._1_1_ != 'F')) && ((EDIT_ITEM == 0 && (DAT_020b8ea0._1_1_ != 'N')))) {
    ffree(extraout_ST0);
    Var4 = push_words(&DAT_007643f4,&DAT_020b8ea0);
    ffree(Var4);
    Var4 = push_words(&DAT_007643f0,&P1);
    _DAT_0089f148 = 1;
    ffree(Var4);
    Var4 = thunk_FUN_00535d00(&DAT_0089f148);
    ffree(Var4);
    Var4 = pop_words(&DAT_007643f0,&P1);
    ffree(Var4);
    fVar5 = (float10)pop_words(&DAT_007643f4,&DAT_020b8ea0);
  }
  if ((_DAT_020b90a0 == 0x49564e49) || (_DAT_020b90a0 == 0x69766e69)) {
    DAT_007924c0 = -DAT_007924c0;
    FUN_005f34d1(&stack0xfffffffc,0x4b019d);
    FUN_005f33c9(puVar8,0x4b01bf);
    Var4 = FUN_005f34d1(puVar8,0x4b01da);
    if (DAT_007924c0 < 0) {
      FUN_005f33c9(puVar8,0x4b0205);
      Var4 = FUN_005f34d1(puVar8,0x4b0220);
    }
    ffree(Var4);
    fVar5 = (float10)draw_items();
    *(undefined4 *)(puVar8 + -0x58) = 0;
    goto LAB_004b0232;
  }
  if (DAT_0078b4e4 != 0x4e) goto LAB_004aff8e;
  if (DAT_0078b4e0 != 0x49) {
    DAT_0078b4e0 = 0;
    goto LAB_004b0232;
  }
  if (DAT_020b8ea2 == 'C') {
    if (DAT_020b8ea3 == 'H') {
      DAT_0078b4e8 = 0;
      ffree(fVar5);
      thunk_FUN_0054e9f2();
      goto LAB_004b0139;
    }
    if (P2 != f_0) {
      DAT_0078dc3d = P2;
    }
    DAT_0078d840 = DAT_0078dc3d;
    ffree(fVar5);
    thunk_FUN_00572367();
  }
  else {
    if (DAT_020b8ea2 == 'V') {
      _DAT_0078dd58 = (int)ROUND(P2);
    }
    else {
      if (DAT_020b8ea2 == 'Z') {
        ffree(fVar5);
        fVar5 = (float10)thunk_FUN_0052f485();
        if (P2 != f_1) {
          DAT_01fbb8a8 = 1;
          DAT_01fbb8a0 = 8;
          DAT_01fbb8a4 = 0x59;
          FUN_005f33c9(&stack0xfffffffc,0x4afe94);
          Var4 = FUN_005f34d1(puVar6,0x4afeaf);
          ffree(Var4);
          fVar5 = (float10)thunk_FUN_0041b68a();
          *(undefined4 *)(puVar6 + -0xc) = 0;
          goto LAB_004b0232;
        }
      }
      DAT_01be12e4 = 0;
      DAT_0089f140 = ITEM_WORDS;
      if (0 < DAT_00791480) {
        ffree(fVar5);
        fVar5 = (float10)thunk_FUN_00473cdd(&DAT_007643e8);
      }
      if ((P2 != f_0) && ((_DAT_020b90a0 & 0xffffff) == 0x5a4e4c)) {
        _DAT_0089f13c = (float)DAT_01e66a08;
        fVar5 = (float10)DAT_01e66a08 * (float10)f_25;
        if ((float10)f_750 < fVar5 / (float10)(float)(&STAFF_STEP0)[(int)ROUND(P2)]) {
          P2 = f_0;
        }
      }
      ffree(fVar5);
      input_main();
      if (ITEM_WORDS == DAT_0089f140) goto LAB_004b0144;
    }
LAB_004b0139:
    DAT_0078b4f0 = 1;
  }
LAB_004b0144:
  DAT_0078b4e0 = 0;
  fVar5 = (float10)FUN_005f34d1(&stack0xfffffffc,0x4b0169);
LAB_004b0232:
  ffree(fVar5);
  return;
}


