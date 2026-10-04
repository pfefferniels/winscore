// FUN_0050d78e @ 0050d78e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050d78e(void)

{
  DAT_00940e0c = NPT;
  push_words(&DAT_00767320,&ITEM_I);
  if (IP22 == 0x53) {
    if (IP11 != 0) {
      P2 = P5;
    }
    DAT_01fbb860 = (int)ROUND(P1);
    DAT_01fbb864 = (int)ROUND(P2) + DAT_01fbb860 + -1;
    DAT_01fbb868 = f_m1000;
    DAT_01fbb86c = f_220;
    DAT_01fbb870 = f_0;
  }
  if (DAT_02052748 == DAT_02052740) {
    if (IP22 != 0x53) goto LAB_0050d8c6;
    thunk_FUN_0054956b(&DAT_007672f4,0x28,&DAT_007672c8);
  }
LAB_0050d8b9:
  do {
    IP11 = 0;
    thunk_FUN_00518448();
LAB_0050d8c6:
    if (P1 == f_0) {
      FUN_0050d706();
      return;
    }
    if (DAT_0078b4e4 == -1) {
LAB_0050d95a:
      DAT_01fbb7f8 = 0x46;
      goto LAB_0050db16;
    }
    if (DAT_02052748 == DAT_02052740) {
      if (P1 == f_0) {
        return;
      }
      if (0x42 < DAT_01fbb7f8) goto LAB_0050d95a;
      if ((DAT_01fbb7f8 == 0x42) && (DAT_0078dc68 == 0x113)) {
        P1 = f_99;
      }
      if (P1 != f_0) {
        DAT_0078b4e4 = 0;
        if (((P3 == f_0) && (P2 == f_0)) && (P1 <= DAT_0078d894)) {
          P2 = DAT_01fbb868;
          P3 = DAT_01fbb86c;
          DAT_01fbb88c = (int)ROUND(P1);
        }
        goto LAB_0050da7e;
      }
      if ((0x3c < DAT_01fbb7f8) && (DAT_01fbb7f8 < 0x40)) goto LAB_0050da7e;
      goto LAB_0050d8b9;
    }
    if (P1 != f_0) {
LAB_0050da7e:
      DAT_01fbb890 = (int)ROUND(P1);
      if (DAT_01fbb890 < 1) {
        DAT_01fbb890 = 1;
      }
      if (IP22 == 0x53) {
        P2 = f_0;
        P3 = f_0;
        P4 = f_0;
      }
      DAT_01fbb880 = P2;
      _DAT_01fbb884 = P3;
      _DAT_01fbb888 = P4;
LAB_0050db16:
      pop_words(&DAT_00767320,&ITEM_I);
      NPT = DAT_00940e0c;
      return;
    }
  } while( true );
}


