// FUN_0044695d @ 0044695d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044695d(void)

{
  int iVar1;
  unkbyte10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  
  ffree(in_ST0);
  fVar2 = (float10)thunk_FUN_005725fa();
  DAT_020527a0 = 0xfffffffe;
  _DAT_007fc200 = 0;
  DAT_007fc1fc = 1;
  iVar1 = ITEM_I;
  do {
    if (iVar1 < 1) {
      DAT_01fbb8a0 = 0;
      ffree(fVar2);
      Var3 = draw_items();
      ffree(Var3);
      Var3 = thunk_FUN_00549422();
      ffree(Var3);
      return;
    }
    ffree(fVar2);
    LOAD_I = DAT_007fc1fc;
    fVar2 = (float10)load_item_header();
    if ((((DAT_01fbb860 <= LOAD_STAFF) && (LOAD_STAFF <= DAT_01fbb864)) && (DAT_01fbb868 <= LOAD_P3)
        ) && (LOAD_P3 <= DAT_01fbb86c)) {
      if (LOAD_CODE < 3) {
        fVar2 = (float10)(float)(&ITEM_P4)[LOAD_W];
        if (ABS(fVar2) < (float10)f_100) {
          DAT_007fc1f8 = f_100;
          if ((float)(&ITEM_P4)[LOAD_W] < f_0) {
            fVar2 = (float10)f_100;
            DAT_007fc1f8 = (float)-fVar2;
          }
          (&ITEM_P4)[LOAD_W] = DAT_007fc1f8 + (float)(&ITEM_P4)[LOAD_W];
          if (LOAD_CODE == 1) {
            if ((7 < LOAD_LEN) && (f_0 < *(float *)(&ITEM_P8 + LOAD_W * 4))) {
              *(float *)(&ITEM_P8 + LOAD_W * 4) = *(float *)(&ITEM_P8 + LOAD_W * 4) / f_0_6;
            }
            if (10 < LOAD_LEN) {
              *(float *)(&ITEM_P11 + LOAD_W * 4) =
                   (float)(int)ROUND(*(float *)(&ITEM_P11 + LOAD_W * 4));
            }
            goto LAB_00446b3c;
          }
        }
      }
      else {
LAB_00446b3c:
        if (LOAD_CODE == 6) {
          fVar2 = (float10)(float)(&ITEM_P4)[LOAD_W];
          if (ABS(fVar2) < (float10)f_100) {
            _DAT_007fc1f4 = f_1;
            if (f_20 < *(float *)(&ITEM_P7 + LOAD_W * 4)) {
              _DAT_007fc1f4 = f_m1;
            }
            _DAT_007fc1f0 = _DAT_007fc1f4 + (float)(&ITEM_P4)[LOAD_W];
            DAT_007fc1f8 = _DAT_007fc1f0 + f_100;
            _DAT_007fc200 = 1;
            if (_DAT_007fc1f0 < f_0) {
              DAT_007fc1f8 = _DAT_007fc1f0 - f_100;
            }
            (&ITEM_P4)[LOAD_W] = DAT_007fc1f8;
            (&ITEM_P5)[LOAD_W] = _DAT_007fc1f4 + (float)(&ITEM_P5)[LOAD_W];
            IP2 = LOAD_STAFF;
            P2 = (float)LOAD_STAFF;
            IP5 = LOAD_STAFF;
            P5 = (float)LOAD_STAFF;
            P3 = LOAD_P3;
            P4 = (float)(&ITEM_P6)[LOAD_W];
            ffree(fVar2);
            fVar2 = (float10)thunk_FUN_0040cde4(&DAT_00760840);
          }
        }
        else if ((LOAD_CODE == 9) && (5 < LOAD_LEN)) {
          (&ITEM_P6)[LOAD_W] = f_0_75;
        }
      }
    }
    DAT_007fc1fc = DAT_007fc1fc + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


