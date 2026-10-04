// FUN_0046885a @ 0046885a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0046885a(void)

{
  int iVar1;
  float10 fVar2;
  
  IP2 = (int)ROUND(DAT_020b9444);
  if (P2 == f_0) {
    fVar2 = (float10)amod(&DAT_020b9450,&f_10);
    P2 = f_m1;
    if (((int)ROUND(fVar2) == 2) || ((int)ROUND(fVar2) == 5)) {
      P2 = f_1;
    }
  }
  IP5 = 0;
  LOAD_I = 1;
  P6 = f_999;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if ((((LOAD_P3 <= DAT_020b9448) && (LOAD_CODE == 3)) && (IP2 == LOAD_STAFF)) &&
       ((P8 = DAT_020b9448 - LOAD_P3, f_0 <= P8 && (P8 < P6)))) {
      IP5 = LOAD_I;
      P6 = P8;
    }
    LOAD_I = LOAD_I + 1;
  }
  IP1 = 0x14;
  if (IP5 != 0) {
    LOAD_I = IP5;
    load_item_header();
    if (4 < LOAD_LEN) {
      IP1 = (int)ROUND((float)(&ITEM_P5)[LOAD_W] + f_20);
    }
    if (IP1 == 0x18) {
      IP1 = 0x14;
    }
  }
  DAT_00824658 = (int)ROUND(DAT_020b944c);
  DAT_00824654 = DAT_00824658 % 100 + 0x1c;
  if (IP1 < 0x18) {
    if (IP1 == 0x15) {
      DAT_00824654 = DAT_00824658 % 100 + 0x1e;
    }
    if (IP1 == 0x16) {
      DAT_00824654 = DAT_00824654 + 1;
    }
    if (IP1 == 0x17) {
      DAT_00824654 = DAT_00824654 + -1;
    }
    DAT_00824654 = DAT_00824654 % 7;
    DAT_00824650 = (int)ROUND(DAT_020b9450);
    DAT_0082464c = DAT_00824650 % 10;
    switch(DAT_0082464c) {
    case 1:
      if (P2 <= f_0) {
        DAT_00824650 = 1;
        if ((DAT_00824654 == 1) || (DAT_00824654 == 4)) {
          DAT_00824650 = 2;
        }
      }
      else {
        if ((DAT_00824654 != 0) && (DAT_00824654 != 3)) {
          DAT_01c58920 = f_999;
          return;
        }
        DAT_00824650 = 3;
      }
      break;
    case 2:
      if (P2 <= f_0) {
        if ((DAT_00824654 != 1) && (DAT_00824654 != 4)) {
          DAT_01c58920 = f_999;
          return;
        }
        DAT_00824650 = 3;
      }
      else {
        DAT_00824650 = -1;
        if ((DAT_00824654 == 0) || (DAT_00824654 == 3)) {
          DAT_00824650 = 1;
        }
      }
      break;
    default:
      if (P2 <= f_0) {
        DAT_00824650 = 5;
        if ((DAT_00824654 == 1) || (DAT_00824654 == 4)) {
          DAT_00824650 = 2;
        }
      }
      else {
        DAT_00824650 = 4;
        if ((DAT_00824654 == 0) || (DAT_00824654 == 3)) {
          DAT_00824650 = 1;
        }
      }
      if (DAT_0082464c == 3) {
        DAT_00824650 = DAT_00824650 + -3;
      }
      break;
    case 4:
      if (f_0 < P2) {
        DAT_01c58920 = f_999;
        return;
      }
      DAT_00824650 = -1;
      if ((DAT_00824654 == 1) || (DAT_00824654 == 4)) {
        DAT_00824650 = -3;
      }
      break;
    case 5:
      if (P2 < f_0) {
        DAT_01c58920 = f_999;
        return;
      }
      DAT_00824650 = -2;
      if ((DAT_00824654 == 0) || (DAT_00824654 == 3)) {
        DAT_00824650 = -3;
      }
    }
    DAT_01c58930 = (float)DAT_00824650 + DAT_020b9450;
    DAT_01c5892c = P2 + DAT_020b944c;
    return;
  }
  return;
}


