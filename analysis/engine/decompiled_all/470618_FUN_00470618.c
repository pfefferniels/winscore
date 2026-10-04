// FUN_00470618 @ 00470618 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00470bbc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00470618(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  unkbyte10 Var3;
  
  puVar1 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (DAT_0078b4e0 != 0) {
    DAT_0078d870 = EDIT_ITEM;
    DAT_0078b4f0 = 1;
    if ((DAT_0078b4e0 == 0x4c) && (DAT_0078b4e4 == 0x53)) {
      if (DAT_0205274c != 0) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0054d831(&DAT_00761ffc,0x39);
        goto LAB_00470e9c;
      }
      if (P2 == f_0) goto LAB_00470e9c;
      DAT_0078d858 = P2;
      if (DAT_020b8ea2 == 'P') {
        DAT_0078d858 = f_0_126;
LAB_00470736:
        DAT_0078d858 = P2 / (DAT_0078d858 * STEP);
      }
      else {
        if (DAT_020b8ea2 == 'I') {
          DAT_0078d858 = f_0_00175;
          goto LAB_00470736;
        }
        if (DAT_020b8ea2 == 'C') {
          DAT_0078d858 = f_0_004445;
          goto LAB_00470736;
        }
      }
      DAT_01caea40 = (int)ROUND(P3);
      if (DAT_01caea40 == 0) {
        DAT_01caea40 = 999;
      }
      DAT_01caea44 = 1;
      if (DAT_01caea40 < 1) {
        in_ST0 = (float10)DAT_0078d858;
        DAT_0078d858 = (float)-in_ST0;
        DAT_01caea44 = -1;
        DAT_01caea40 = DAT_01caea40 + 2;
      }
      DAT_01caea40 = DAT_01caea40 + EDIT_ITEM + -1;
      if (DAT_01caea40 < 1) {
        DAT_01caea40 = 1;
      }
      DAT_01c585dc = DAT_01caea44 + EDIT_ITEM;
      DAT_01c585e0 = (int)ROUND(P4);
      DAT_0078d864 = DAT_020b944c - DAT_0078d858;
      _DAT_0078d86c = DAT_020b9444;
      DAT_0078d868 = DAT_020b9448;
      DAT_01c585d8 = DAT_020b9454;
      DAT_01c585d0 = DAT_020b9458;
      while( true ) {
        DAT_01c585c4 = (&ITEM_PTR0)[DAT_01c585dc];
        ffree(in_ST0);
        DAT_01c585c8 = thunk_FUN_00441157(&DAT_01c585c4);
        if ((1 < DAT_01c585c8) || ((DAT_01c585e0 == 0 && (DAT_01c585c8 == 1)))) break;
        (&ITEM_P3)[DAT_01c585c4] = DAT_0078d868;
        (&ITEM_P4)[DAT_01c585c4] = DAT_0078d864;
        (&ITEM_P6)[DAT_01c585c4] = DAT_01c585d8;
        *(undefined4 *)(&ITEM_P7 + DAT_01c585c4 * 4) = DAT_01c585d0;
        DAT_0078d864 = DAT_0078d864 - DAT_0078d858;
        if ((DAT_01caea40 == DAT_01c585dc) || (ITEM_I <= DAT_01c585dc)) break;
        DAT_01c585dc = DAT_01caea44 + DAT_01c585dc;
        in_ST0 = extraout_ST0;
      }
      EDIT_ITEM = 0;
      ffree(extraout_ST0);
      in_ST0 = (float10)draw_items();
      EDIT_ITEM = DAT_0078d870;
      goto LAB_00470e9c;
    }
    DAT_01c585cc = (int)ROUND(DAT_020b946c);
    if (DAT_020b8ea2 == 'P') {
      ffree(in_ST0);
      in_ST0 = (float10)FUN_004716d8();
      goto LAB_00470e9c;
    }
    if (DAT_0078b4e4 == 0x4d) {
      if (DAT_0205274c == 0) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_004401d8();
      }
      else {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0054d831("*** Can\'t do RM if any parameters have just been changed."
                                             ,0x39);
      }
      goto LAB_00470e9c;
    }
    puVar2 = &stack0xfffffffc;
    if (DAT_0078b4e0 == 0x54) {
      DAT_009ae4bc = 1;
      DAT_01c585c8 = (int)ROUND(DAT_020b946c + f_1);
      (&DAT_01fb8cf7)[DAT_01c585c8] = 0;
      FUN_005f33c9(&stack0xfffffffc,0x470af7);
      Var3 = FUN_005f34d1(puVar1,0x470b12);
      DAT_00824ecc = 0;
      *(undefined4 *)(puVar1 + -0x50) = 0x200;
      DAT_01c585cc = 1;
      do {
        if ((&DAT_020b8e9f)[DAT_01c585cc] == '_') {
          DAT_00824ecc = DAT_01c585cc;
        }
        DAT_01c585cc = DAT_01c585cc + 1;
        *(int *)(puVar1 + -0x50) = *(int *)(puVar1 + -0x50) + -1;
      } while (0 < *(int *)(puVar1 + -0x50));
      if ((1 < DAT_00824ecc) && ((&DAT_020b8e9e)[DAT_00824ecc] == '_')) {
        DAT_00824ecc = DAT_00824ecc + -1;
      }
      if (DAT_00824ecc != 0) {
        FUN_005f46bc(puVar1,0x470be0);
        Var3 = FUN_005f34d1(puVar1,0x470bf6);
      }
      _DAT_00824ec8 = 1;
      ffree(Var3);
      Var3 = FUN_00470ea5(&DAT_00824ec8);
      DAT_00824ecc = 0;
      if ((char)DAT_020b8ea0 == '_') {
        *(undefined4 *)(puVar1 + -0x4c) = 0;
      }
      else {
        DAT_01fb8cf8 = DAT_00790ca4;
        DAT_00824ecc = 4;
        if (DAT_020b8ea0._1_1_ == '_') {
          DAT_00824ecc = 5;
        }
      }
      *(undefined4 *)(puVar1 + -0x48) = 0x200;
      DAT_01c585cc = 1;
      do {
        if ((&DAT_020b8e9f)[DAT_01c585cc] == '\0') {
          DAT_009ae4bc = 0;
          DAT_0078b4e0 = 0;
          *(undefined4 *)(puVar1 + -0x44) = 0;
          break;
        }
        if (DAT_00824ecc == 0) {
          DAT_00824ecc = DAT_01c585cc;
        }
        (&DAT_01fb8cf7)[DAT_00824ecc] = (&DAT_020b8e9f)[DAT_01c585cc];
        DAT_00824ecc = DAT_00824ecc + 1;
        DAT_01c585cc = DAT_01c585cc + 1;
        *(int *)(puVar1 + -0x48) = *(int *)(puVar1 + -0x48) + -1;
      } while (0 < *(int *)(puVar1 + -0x48));
      DAT_00790ca4 = DAT_01fb8cf8;
      if (DAT_00824ecc == 0) {
        DAT_00824ecc = DAT_01c585cc;
      }
      DAT_01c585cc = DAT_00824ecc + -1;
      *(undefined4 *)(puVar1 + -0x40) = 0;
      DAT_020b946c = (float)DAT_01c585cc;
      ffree(Var3);
      in_ST0 = (float10)thunk_FUN_0054c590(&DAT_020b9440,&P1,&DAT_00761ff4);
      puVar2 = puVar1;
    }
  }
  *(undefined2 *)(puVar2 + -0x9c) = in_FPUControlWord;
  *(ushort *)(puVar2 + -0x9a) = (ushort)*(undefined4 *)(puVar2 + -0x9c) | 0xc00;
  *(int *)(puVar2 + -0x98) = (int)ROUND(P12);
  _DAT_01cadcf8 = *(undefined4 *)(puVar2 + -0x98);
  if (P5 == f_0) {
    P5 = f_1;
  }
  ffree(in_ST0);
  in_ST0 = (float10)text_parse(&DAT_01fb8cf8,1,&DAT_01cadcf8);
  DAT_020b9470 = P13;
  if (DAT_0078b4e0 == 0x4a) {
    P11 = f_0;
    ffree(in_ST0);
    Var3 = FUN_00471190();
    ffree(Var3);
    in_ST0 = (float10)text_parse(&DAT_01fb8cf8,1,&DAT_01cadcf8);
  }
  else {
    *(undefined4 *)(puVar2 + -0x3c) = 0;
  }
  DAT_01cb1064 = f_0;
  *(undefined4 *)(puVar2 + -0x38) = 0;
  DAT_020b9470 = P13;
LAB_00470e9c:
  ffree(in_ST0);
  return;
}


