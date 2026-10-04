// FUN_004f7808 @ 004f7808 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f7808(void)

{
  undefined2 uVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar5;
  unkbyte10 Var6;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  
  puVar4 = &stack0xfffffffc;
  if ((_DAT_020b8ea0 & 0xffffff) == 0x54554f) {
    DAT_01f9a6f4 = 0;
  }
  else {
    _DAT_008d207c = 1;
    if (1 < ITEM_I) {
      DAT_0078b4f0 = 1;
      if ((_DAT_020b8ea0 & 0xff) == 0x4f) {
        ffree(in_ST0);
        in_ST0 = thunk_FUN_005725fa();
      }
      if ((_DAT_020b8ea0 & 0xffffff) != 0x4e524f) {
        if (DAT_0078b4e4 == 0x50) {
          DAT_01c585d4 = 1;
          for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
            DAT_01c585d8 = (&ITEM_PTR0)[DAT_01c585d4] + 2;
            if ((float)(&ITEM_LEN)[DAT_01c585d8] < f_200) {
              (&ITEM_LEN)[DAT_01c585d8] = (float)(&ITEM_LEN)[DAT_01c585d8] + f_300;
            }
            DAT_01c585d4 = DAT_01c585d4 + 1;
          }
        }
        DAT_01c585d4 = 1;
        puVar4 = &stack0xfffffffc;
        iVar3 = ITEM_I;
        while (0 < iVar3) {
          DAT_01c585dc = (&ITEM_PTR0)[DAT_01c585d4];
          ffree(in_ST0);
          fVar5 = (float10)anint(puVar4,0x4f799b);
          *(int *)(puVar4 + -0xd0) = (int)ROUND(fVar5);
          DAT_01c585d8 = *(int *)(puVar4 + -0xd0);
          DAT_008d2078 = (float)DAT_01c585d8;
          (&ITEM_P3)[DAT_01c585dc] = DAT_008d2078 / f_100;
          DAT_01c585d4 = DAT_01c585d4 + 1;
          *(int *)(puVar4 + -0x78) = *(int *)(puVar4 + -0x78) + -1;
          in_ST0 = extraout_ST1;
          iVar3 = *(int *)(puVar4 + -0x78);
        }
        ffree(in_ST0);
        fVar5 = (float10)thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&ITEM_WORDS);
        if (DAT_0078b4e4 == 0x48) {
          *(undefined4 *)(puVar4 + -0x74) = 0;
          FUN_005f33c9(puVar4,0x4f7a4f);
          fVar5 = (float10)FUN_005f34d1(puVar4,0x4f7a6a);
          *(int *)(puVar4 + -0x40) = ITEM_I;
          DAT_01c585d4 = 1;
          iVar3 = ITEM_I;
          while (0 < iVar3) {
            DAT_01c585dc = (&ITEM_PTR0)[DAT_01c585d4];
            ffree(fVar5);
            fVar5 = (float10)anint(puVar4,0x4f7ac0);
            *(int *)(puVar4 + -0xd0) = (int)ROUND(fVar5);
            DAT_008d2064 = *(int *)(puVar4 + -0xd0);
            *(int *)(puVar4 + -0xd0) = DAT_008d2064 * 1000;
            fVar2 = (float)(&ITEM_P2)[DAT_01c585dc];
            *(undefined2 *)(puVar4 + -0xd4) = in_FPUControlWord;
            *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
            *(int *)(puVar4 + -0xd0) = (int)ROUND((float)*(int *)(puVar4 + -0xd0) + fVar2);
            uVar1 = *(undefined2 *)(puVar4 + -0xd4);
            (&DAT_008e58fc)[DAT_01c585d4] = *(undefined4 *)(puVar4 + -0xd0);
            DAT_008d2078 = (float)(&ITEM_P4)[DAT_01c585dc];
            fVar2 = (float)(&ITEM_P1)[DAT_01c585dc];
            *(undefined2 *)(puVar4 + -0xd4) = uVar1;
            *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
            *(int *)(puVar4 + -0xd0) = (int)ROUND(fVar2);
            in_FPUControlWord = *(undefined2 *)(puVar4 + -0xd4);
            DAT_01c585d8 = *(int *)(puVar4 + -0xd0);
            if ((DAT_01c585d8 < 4) || (fVar5 = extraout_ST1_00, DAT_01c585d8 == 6)) {
              ffree(extraout_ST1_00);
              fVar5 = (float10)amod(&DAT_008d2078,&f_100);
              DAT_008d2078 = (float)fVar5;
              fVar5 = extraout_ST1_01;
            }
            if (DAT_01c585d8 == 0xe) {
              DAT_008d2078 = f_0;
            }
            *(float *)(&DAT_008d207c + DAT_01c585d4 * 4) = DAT_008d2078;
            if ((float)(&ITEM_LEN)[DAT_01c585dc] < f_4) {
              *(float *)(&DAT_008d207c + DAT_01c585d4 * 4) = f_0;
            }
            DAT_01c585d4 = DAT_01c585d4 + 1;
            *(int *)(puVar4 + -0x40) = *(int *)(puVar4 + -0x40) + -1;
            iVar3 = *(int *)(puVar4 + -0x40);
          }
          *(undefined4 *)(puVar4 + -0x3c) = 0;
        }
        else {
          if (DAT_0078b4e4 != 0x54) {
            FUN_005f33c9(puVar4,0x4f7c6c);
            fVar5 = (float10)FUN_005f34d1(puVar4,0x4f7c87);
          }
          *(int *)(puVar4 + -0x70) = ITEM_I;
          DAT_01c585d4 = 1;
          iVar3 = ITEM_I;
          while (0 < iVar3) {
            DAT_01c585dc = (&ITEM_PTR0)[DAT_01c585d4];
            fVar2 = (float)(&ITEM_P2)[DAT_01c585dc];
            *(undefined2 *)(puVar4 + -0xd4) = in_FPUControlWord;
            *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
            *(int *)(puVar4 + -0xd0) = (int)ROUND(fVar2);
            DAT_008d2064 = *(int *)(puVar4 + -0xd0);
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x52) {
              DAT_008d2064 = 0xc9 - DAT_008d2064;
            }
            *(int *)(puVar4 + -0xd0) = DAT_008d2064 * 1000000;
            fVar5 = (float10)*(int *)(puVar4 + -0xd0);
            fVar2 = (float)(&ITEM_P3)[DAT_01c585dc];
            *(undefined2 *)(puVar4 + -0xd4) = *(undefined2 *)(puVar4 + -0xd4);
            *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
            *(int *)(puVar4 + -0xd0) = (int)ROUND((float10)fVar2 * (float10)f_1000 + fVar5);
            in_FPUControlWord = *(undefined2 *)(puVar4 + -0xd4);
            (&DAT_008e58fc)[DAT_01c585d4] = *(undefined4 *)(puVar4 + -0xd0);
            if (f_2 < (float)(&ITEM_P1)[DAT_01c585dc]) {
              (&DAT_008e58fc)[DAT_01c585d4] = (&DAT_008e58fc)[DAT_01c585d4] + 1;
            }
            *(undefined4 *)(&DAT_008d207c + DAT_01c585d4 * 4) = (&ITEM_P4)[DAT_01c585dc];
            if ((float)(&ITEM_P1)[DAT_01c585dc] == f_2) {
              *(float *)(&DAT_008d207c + DAT_01c585d4 * 4) =
                   *(float *)(&DAT_008d207c + DAT_01c585d4 * 4) + f_5;
            }
            if ((float)(&ITEM_LEN)[DAT_01c585dc] < f_4) {
              *(float *)(&DAT_008d207c + DAT_01c585d4 * 4) = f_0;
            }
            DAT_01c585d4 = DAT_01c585d4 + 1;
            *(int *)(puVar4 + -0x70) = *(int *)(puVar4 + -0x70) + -1;
            iVar3 = *(int *)(puVar4 + -0x70);
          }
        }
        while( true ) {
          DAT_01c585dc = 500000000;
          DAT_008d2064 = 0;
          *(int *)(puVar4 + -0x6c) = ITEM_I;
          DAT_01c585d4 = 1;
          iVar3 = ITEM_I;
          while (0 < iVar3) {
            if ((int)(&DAT_008e58fc)[DAT_01c585d4] < DAT_01c585dc) {
              DAT_01c585dc = (&DAT_008e58fc)[DAT_01c585d4];
              DAT_008d2064 = DAT_01c585d4;
            }
            else {
              *(undefined4 *)(puVar4 + -0x68) = 0;
            }
            *(undefined4 *)(puVar4 + -100) = 0;
            DAT_01c585d4 = DAT_01c585d4 + 1;
            *(int *)(puVar4 + -0x6c) = *(int *)(puVar4 + -0x6c) + -1;
            iVar3 = *(int *)(puVar4 + -0x6c);
          }
          if (DAT_008d2064 == 0) break;
          DAT_01c585d0 = 0;
          *(int *)(puVar4 + -0x5c) = ITEM_I;
          DAT_01c585d4 = 1;
          _DAT_008d2060 = f_900;
          iVar3 = ITEM_I;
          while (0 < iVar3) {
            if ((DAT_01c585dc != (&DAT_008e58fc)[DAT_01c585d4]) ||
               (_DAT_008d2060 <= *(float *)(&DAT_008d207c + DAT_01c585d4 * 4))) {
              *(undefined4 *)(puVar4 + -0x58) = 0;
            }
            else {
              _DAT_008d2060 = *(float *)(&DAT_008d207c + DAT_01c585d4 * 4);
              DAT_01c585d0 = DAT_01c585d4;
            }
            *(undefined4 *)(puVar4 + -0x54) = 0;
            DAT_01c585d4 = DAT_01c585d4 + 1;
            *(int *)(puVar4 + -0x5c) = *(int *)(puVar4 + -0x5c) + -1;
            iVar3 = *(int *)(puVar4 + -0x5c);
          }
          if (DAT_01c585d0 == 0) {
            DAT_01c585d0 = ITEM_I;
          }
          (&DAT_008e58fc)[DAT_01c585d0] = 0x1dcd6501;
          *(float *)(&DAT_008d207c + DAT_01c585d0 * 4) = f_1000;
          ffree(fVar5);
          fVar5 = (float10)FUN_004f889e(&DAT_01c585d0,&DAT_008d207c);
          *(undefined4 *)(puVar4 + -0x50) = 0;
        }
        *(undefined4 *)(puVar4 + -0x60) = 0;
        *(undefined4 *)(puVar4 + -0x4c) = 0;
        if (DAT_0078b4e4 == 0x54) {
          *(undefined4 *)(puVar4 + -0x48) = 0;
          FUN_005f33c9(puVar4,0x4f804c);
          Var6 = FUN_005f34d1(puVar4,0x4f8067);
          ffree(Var6);
          fVar5 = (float10)FUN_004f8794();
          _DAT_008d207c = 1;
          DAT_008d205c = 0;
          *(int *)(puVar4 + -0x38) = ITEM_I;
          DAT_01c585d4 = 1;
          iVar3 = ITEM_I;
          while (0 < iVar3) {
            if ((float)(&DAT_01e99980)[(&ITEM_PTR0)[DAT_01c585d4]] == f_16) {
              DAT_008d205c = DAT_008d205c + 1;
              DAT_01c585dc = (&ITEM_PTR0)[DAT_01c585d4];
              (&DAT_020492a4)[DAT_008d205c] = DAT_01c585d4;
              fVar2 = (float)(&DAT_01e99984)[DAT_01c585dc];
              *(undefined2 *)(puVar4 + -0xd4) = in_FPUControlWord;
              *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
              *(int *)(puVar4 + -0xd0) = (int)ROUND(fVar2);
              *(int *)(puVar4 + -0xd0) = *(int *)(puVar4 + -0xd0) * 100000;
              fVar5 = (float10)*(int *)(puVar4 + -0xd0);
              fVar2 = (float)(&DAT_01e9998c)[DAT_01c585dc];
              *(undefined2 *)(puVar4 + -0xd4) = *(undefined2 *)(puVar4 + -0xd4);
              *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
              *(int *)(puVar4 + -0xd0) = (int)ROUND((float10)fVar2 * (float10)f_100 + fVar5);
              in_FPUControlWord = *(undefined2 *)(puVar4 + -0xd4);
              (&DAT_008e58fc)[DAT_008d205c] = *(undefined4 *)(puVar4 + -0xd0);
            }
            else {
              *(undefined4 *)(puVar4 + -0x34) = 0;
            }
            *(undefined4 *)(puVar4 + -0x30) = 0;
            DAT_01c585d4 = DAT_01c585d4 + 1;
            *(int *)(puVar4 + -0x38) = *(int *)(puVar4 + -0x38) + -1;
            iVar3 = *(int *)(puVar4 + -0x38);
          }
          while( true ) {
            DAT_01c585d8 = -9999;
            DAT_008d2064 = 0;
            *(int *)(puVar4 + -0x2c) = DAT_008d205c;
            DAT_01c585d4 = 1;
            iVar3 = DAT_008d205c;
            while (0 < iVar3) {
              if (DAT_01c585d8 < (int)(&DAT_008e58fc)[DAT_01c585d4]) {
                DAT_01c585d8 = (&DAT_008e58fc)[DAT_01c585d4];
                DAT_008d2064 = DAT_01c585d4;
              }
              else {
                *(undefined4 *)(puVar4 + -0x28) = 0;
              }
              *(undefined4 *)(puVar4 + -0x24) = 0;
              DAT_01c585d4 = DAT_01c585d4 + 1;
              *(int *)(puVar4 + -0x2c) = *(int *)(puVar4 + -0x2c) + -1;
              iVar3 = *(int *)(puVar4 + -0x2c);
            }
            if (DAT_008d2064 == 0) break;
            ffree(fVar5);
            fVar5 = (float10)FUN_004f889e(&DAT_020492a4 + DAT_008d2064,&DAT_008d207c);
            (&DAT_008e58fc)[DAT_008d2064] = 0xffffd8f1;
            *(undefined4 *)(puVar4 + -0x1c) = 0;
          }
          *(undefined4 *)(puVar4 + -0x20) = 0;
          *(int *)(puVar4 + -0x18) = ITEM_I;
          DAT_01c585d4 = 1;
          DAT_008d2064 = 0;
          iVar3 = ITEM_I;
          while (0 < iVar3) {
            DAT_01c585dc = (&ITEM_PTR0)[DAT_01c585d4];
            if ((float)(&DAT_01e99980)[DAT_01c585dc] != f_16) {
              ffree(fVar5);
              fVar5 = (float10)FUN_004f889e(&DAT_01c585d4,&DAT_008d207c);
            }
            DAT_01c585d4 = DAT_01c585d4 + 1;
            *(int *)(puVar4 + -0x18) = *(int *)(puVar4 + -0x18) + -1;
            iVar3 = *(int *)(puVar4 + -0x18);
          }
        }
        else {
          *(undefined4 *)(puVar4 + -0x44) = 0;
          DAT_008d2064 = 0;
        }
        if (DAT_0078b4e4 < 0x55) {
          if (DAT_0078b4e4 == 0x50) {
            ffree(fVar5);
            fVar5 = (float10)FUN_004f8794();
            *(int *)(puVar4 + -8) = ITEM_I;
            DAT_01c585d4 = 1;
            iVar3 = ITEM_I;
            while (0 < iVar3) {
              DAT_01c585d8 = (&ITEM_PTR0)[DAT_01c585d4] + 2;
              if (f_300 <= (float)(&ITEM_LEN)[DAT_01c585d8]) {
                (&ITEM_LEN)[DAT_01c585d8] = (float)(&ITEM_LEN)[DAT_01c585d8] - f_300;
              }
              DAT_01c585d4 = DAT_01c585d4 + 1;
              *(int *)(puVar4 + -8) = *(int *)(puVar4 + -8) + -1;
              iVar3 = *(int *)(puVar4 + -8);
            }
          }
          else {
            *(undefined4 *)(puVar4 + -0xc) = 0;
          }
          ffree(fVar5);
          in_ST0 = draw_items();
          if (((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x52) &&
             (DAT_0078b4e4 == 0x53 || DAT_0078b4e4 == 0x58)) {
            DAT_0078b4ec = 1;
          }
          *(undefined2 *)(puVar4 + -0xd4) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
          *(int *)(puVar4 + -0xd0) = (int)ROUND(_DAT_009c6ad4);
          DAT_01c585d8 = *(int *)(puVar4 + -0xd0);
          if (DAT_01c585d8 == 0) {
            *(undefined4 *)(puVar4 + -4) = 0;
          }
          else {
            _DAT_009c6ad4 = f_0;
            ffree(in_ST0);
            in_ST0 = thunk_FUN_00468df8(&DAT_007667b0);
          }
          goto LAB_004f878b;
        }
        ffree(fVar5);
        in_ST0 = FUN_004f8794();
        if (DAT_0078b4e4 != 99) {
          *(undefined4 *)(puVar4 + -0x10) = 0;
          goto LAB_004f878b;
        }
        *(undefined4 *)(puVar4 + -0x14) = 0;
      }
      DAT_008d2078 = f_1;
      _DAT_008d2074 = f_1;
      _DAT_008d2070 = f_m1;
      DAT_008d206c = (float)ITEM_I;
      DAT_008d2068 = ITEM_I;
LAB_004f8516:
      *(int *)(puVar4 + -0xa0) = DAT_008d2068;
      DAT_01c585d4 = 1;
      iVar3 = DAT_008d2068;
      while (0 < iVar3) {
        DAT_01c585dc = (&ITEM_PTR0)[DAT_01c585d4];
        if (((float)(&ITEM_P1)[DAT_01c585dc] == f_16) || ((float)(&ITEM_P1)[DAT_01c585dc] == f_15))
        {
          if ((*(float *)(&ITEM_P14 + DAT_01c585dc * 4) == f_m1) &&
             (*(float *)(&ITEM_P15 + DAT_01c585dc * 4) != f_0)) {
            DAT_01c585d8 = 0xf;
            goto LAB_004f8609;
          }
          *(undefined4 *)(puVar4 + -0x9c) = 0;
        }
        else if (((float)(&ITEM_LEN)[DAT_01c585dc] < f_25) ||
                (*(float *)(&ITEM_P25 + DAT_01c585dc * 4) == f_0)) {
          *(undefined4 *)(puVar4 + -0x98) = 0;
        }
        else {
          DAT_01c585d8 = 0x19;
LAB_004f8609:
          if (DAT_008d2078 == (float)(&ITEM_LEN)[DAT_01c585d8 + DAT_01c585dc]) {
            P3 = DAT_008d206c;
            DAT_008d206c = DAT_008d206c - f_1;
            P2 = (float)DAT_01c585d4;
            ffree(in_ST0);
            in_ST0 = thunk_FUN_0058adc1(&DAT_0076679c);
            *(undefined2 *)(puVar4 + -0xd4) = in_FPUControlWord;
            *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
            *(int *)(puVar4 + -0xd0) = (int)ROUND(DAT_008d206c);
            in_FPUControlWord = *(undefined2 *)(puVar4 + -0xd4);
            DAT_008d2068 = *(int *)(puVar4 + -0xd0);
            *(undefined4 *)(puVar4 + -0x94) = 0;
            goto LAB_004f8516;
          }
        }
        *(undefined4 *)(puVar4 + -0x90) = 0;
        DAT_01c585d4 = DAT_01c585d4 + 1;
        *(int *)(puVar4 + -0xa0) = *(int *)(puVar4 + -0xa0) + -1;
        iVar3 = *(int *)(puVar4 + -0xa0);
      }
      *(undefined2 *)(puVar4 + -0xd4) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
      *(int *)(puVar4 + -0xd0) = (int)ROUND(DAT_008d206c);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0xd4);
      DAT_008d2068 = *(int *)(puVar4 + -0xd0);
      DAT_008d2078 = DAT_008d2078 + f_1;
      if (DAT_008d2078 < f_11) {
        *(undefined4 *)(puVar4 + -0x8c) = 0;
        goto LAB_004f8516;
      }
      *(undefined4 *)(puVar4 + -0x88) = 0;
      ffree(in_ST0);
      in_ST0 = draw_items();
      *(undefined4 *)(puVar4 + -0x84) = 0;
    }
  }
LAB_004f878b:
  ffree(in_ST0);
  return;
}


