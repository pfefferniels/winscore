// note_special_head @ 00558a40 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void note_special_head(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  
  push_words(&DAT_00769af0,&P1);
  push_words(&DAT_00769af0,&DAT_020b9440);
  if (IP8 < 0) {
    if (OUTPUT_MODE != 0) goto LAB_00559431;
    IP8 = 1;
    IP9 = 99;
    IP6 = 4;
    IP12 = 100;
    P4 = f_0;
  }
  else {
    DAT_0078cd54 = (int)ROUND(P4) % 100;
    IP4 = (int)ROUND(P4);
    DAT_0078cd4c = -IP6 / 10;
    IP6 = -IP6 % 10;
    if (((DAT_0078cd4c == 9) || (DAT_0078cd4c == 8)) || (DAT_0078cd4c == 0xf)) {
      DAT_0078cd64 = 7;
      if (DAT_0078cd4c == 0xf) {
        DAT_0078cd64 = 0xe;
      }
      if (DAT_0078cd4c == 9) {
        DAT_0078cd64 = -7;
      }
      DAT_0078cd54 = DAT_0078cd64 + DAT_0078cd54;
      DAT_0078cd4c = 0;
    }
    if (DAT_0078cd4c < 4) {
      DAT_0078cd64 = -IP6 + 6;
      if (DAT_0078cd4c == 1) {
        DAT_0078cd64 = (-IP6 + 7) / 2 + 1;
      }
      if (DAT_0078cd64 < 0) {
        DAT_0078cd64 = 0;
      }
      DAT_0078cd44 = (int)ROUND(P5) % 10;
      FUN_0055953d();
      if (P6 == f_m5) {
        FUN_005596af();
      }
      else {
        FUN_00559601();
      }
      if ((DAT_0078cd4c == 1) && (IP6 == 6)) {
        DAT_01a1ae00 = 0x48;
      }
      DAT_0078cd50 = 0;
      if (P19 < f_100) {
        DAT_0078cd50 = (int)ROUND(P19);
      }
      if ((DAT_0078cd4c == 0) && (IP6 == 4)) {
        DAT_01a1ae00 = 0x4c;
        DAT_01a1ae04 = 0x45;
        _DAT_01a1ae08 = 0x3e;
        _DAT_01a1ae0c = 0x37;
      }
      if (P16 != f_0) {
        FUN_0055945e(&DAT_01a1ae00,&DAT_01a1ae04,&P16);
      }
      if (P17 != f_0) {
        FUN_0055945e(&DAT_01a1ae08,&DAT_01a1ae0c,&P17);
      }
      if (P18 != f_0) {
        FUN_0055945e(&DAT_01a1ae10,&DAT_01a1ae14,&P18);
      }
      if (f_100 <= P19) {
        FUN_0055945e(&DAT_01a1ae18,&DAT_01a1ae1c,&P18);
      }
      if (DAT_0078cd4c == 1) {
        DAT_0078cd50 = DAT_0078cd50 + -0xc;
      }
      IP3 = 1;
      DAT_0078cd64 = IP8;
      for (iVar4 = IP6; 0 < iVar4; iVar4 = iVar4 + -1) {
        IP8 = DAT_0078cd64;
        *(int *)(&DAT_01a1adfc + IP3 * 4) = *(int *)(&DAT_01a1adfc + IP3 * 4) + DAT_0078cd50;
        IP3 = IP3 + 1;
        DAT_0078cd64 = IP8;
      }
      iVar4 = IP6;
      for (IP3 = 1; (IP8 = IP6, 0 < iVar4 &&
                    (IP8 = IP3, DAT_0078cd54 < *(int *)(&DAT_01a1adfc + IP3 * 4))); IP3 = IP3 + 1) {
        iVar4 = iVar4 + -1;
      }
      DAT_01cb1068 = IP8;
      if (IP8 < DAT_0078cd64 % 100) {
        DAT_01cb1068 = DAT_0078cd64 % 100;
      }
      if (-1 < IP9) {
        IP9 = DAT_0078cd54 - *(int *)(&DAT_01a1adfc + DAT_01cb1068 * 4);
      }
      if (IP10 == 999) goto LAB_00559431;
      IP8 = DAT_01cb1068;
      if (100 < DAT_0078cd64) {
        IP8 = (int)(DAT_01cb1068 * 6) % 7;
      }
    }
    else if (IP8 == 0) goto LAB_00559431;
    P4 = (float)((IP6 - IP8) * 2) + f_2_2 + P14;
  }
  thunk_FUN_0054c473(&DAT_020b8ea0,1);
  if (99 < IP12) {
    DAT_020b8ea0._0_1_ = 0x28;
  }
  DAT_01cb1068 = (uint)(99 < IP12);
  if (IP9 < 0x3e9) {
    if (IP9 / 10 != 0) {
      pcVar1 = (char *)((int)&DAT_020b8ea0 + DAT_01cb1068);
      DAT_01cb1068 = DAT_01cb1068 + 1;
      *pcVar1 = (char)(IP9 / 10) + '0';
    }
    IP8 = IP9 % 10;
    DAT_01cb1068 = DAT_01cb1068 + 1;
    if (IP8 == -1) {
      IP8 = 0x28;
    }
    if (OUTPUT_MODE == 0) goto LAB_0055916e;
  }
  else {
    cVar3 = (char)(IP9 % 1000);
    IP8._0_1_ = cVar3 + '\x10';
    if (1999 < IP9) {
      IP8._0_1_ = cVar3 + '0';
    }
    IP9 = 0;
    DAT_01cb1068 = DAT_01cb1068 + 1;
LAB_0055916e:
    P4 = P4 + f_0_2;
  }
  (&DAT_020b8e9f)[DAT_01cb1068] = (char)IP8 + '0';
  if (99 < IP12) {
    if (IP9 == 99) {
      (&DAT_020b8e9e)[DAT_01cb1068] = 0x54;
      (&DAT_020b8e9f)[DAT_01cb1068] = 0x69;
      puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
      DAT_01cb1068 = DAT_01cb1068 + 1;
      *puVar2 = 0x65;
    }
    puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
    DAT_01cb1068 = DAT_01cb1068 + 1;
    *puVar2 = 0x29;
  }
  IP8 = 0x3ed;
  fVar5 = (float10)amod(&P12,&f_100);
  P6 = (float)fVar5;
  if (P6 != f_0) {
    IP8 = (int)ROUND(P6 + f_1000);
  }
  P6 = P15;
  if (P15 == f_0) {
    P6 = f_1;
  }
  P6 = P6 * f_0_55;
  iVar4 = IP4;
  if (IP4 < 0) {
    iVar4 = -IP4;
  }
  if (99 < iVar4) {
    P6 = P6 * f_0_818;
  }
  P7 = f_0;
  P9 = P13;
  P11 = P10;
  fVar5 = (float10)staff_level_y(&P4);
  Y_POS = (float)fVar5;
  P5 = f_0;
  if (9 < IP9) {
    P5 = f_0 - f_4;
  }
  if (99 < IP12) {
    P5 = P5 - f_4;
  }
  X_POS = STEP * P5 + X_POS;
  P5 = f_0_95;
  if (P20 == f_1) {
    FUN_00559733();
  }
  fVar5 = (float10)staff_level_y(&P4);
  Y_POS = (float)fVar5;
  if ((P26 != f_0) || (P25 != f_0)) {
    P14 = f_m1;
    P15 = P25;
    P16 = P26;
  }
  draw_text();
  thunk_FUN_0054c473(&DAT_020b8ea0,1);
LAB_00559431:
  pop_words(&DAT_00769af0,&DAT_020b9440);
  pop_words(&DAT_00769af0,&P1);
  return;
}


