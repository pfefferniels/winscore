// FUN_0040cde4 @ 0040cde4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0040cebd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040cde4(int *param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (*param_1 == 0) {
    return;
  }
  if (DAT_020b8ea2 == 'X') {
    DAT_020b8ea3 = 'X';
  }
  IP2 = (int)ROUND(P2);
  if (IP2 == 0) {
    IP2 = 1;
  }
  IP5 = (int)ROUND(P5);
  if (IP5 == 0) {
    IP5 = IP2;
  }
  DAT_007abac4 = 1;
  DAT_007abac0 = 1;
  if ((EDIT_ITEM != 0) && (f_0 <= DAT_020b9458)) {
    DAT_020b8ea0._0_1_ = DAT_0075f044;
    thunk_FUN_0054c419(&DAT_020b95e0,&DAT_0075f050);
    thunk_FUN_0054c590(&DAT_020b9440,&DAT_020b95e0,&DAT_0075f050);
    DAT_007ababc = (int)ROUND(_DAT_020b95e4);
    IP6 = DAT_020527c8;
    do {
      if (f_0 <= _DAT_020b95f8) {
        LOAD_I = DAT_007abac4;
        for (iVar2 = (ITEM_I - DAT_007abac4) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
          load_item_header();
          if ((((4 < LOAD_LEN) && (LOAD_CODE == 1)) && (DAT_007ababc == LOAD_STAFF)) &&
             ((DAT_020b95e8 - f_0_1 <= LOAD_P3 && (LOAD_P3 <= DAT_020b95f4 + f_0_1)))) {
            thunk_FUN_0054c419(&DAT_020b964c,&DAT_0075f050);
            thunk_FUN_0054c590(&ITEM_P1 + LOAD_W,&DAT_020b964c,&LOAD_LEN);
            fVar3 = (float10)amod(&DAT_020b965c,&f_100);
            DAT_020b8e60 = (int)ROUND(fVar3 / (float10)f_10);
            if ((DAT_020b8e60 != 0) && (_DAT_020b9660 != f_1)) {
              _DAT_007abab8 = f_1;
              IP7 = (int)ROUND(_DAT_020b95f8);
              IP8 = IP7 / 10;
              DAT_007ababc = (int)ROUND(_DAT_020b95e4);
              if ((IP8 == DAT_020b8e60) || (DAT_020b8ea3 == 'X')) {
                IP4 = (int)ROUND(_DAT_020b95ec / f_100);
                if (IP4 < 0) {
                  IP4 = -IP4;
                }
                DAT_007abab4 = (int)ROUND(_DAT_020b9658 / f_100);
                iVar1 = DAT_007abab4;
                if (DAT_007abab4 < 0) {
                  iVar1 = -DAT_007abab4;
                }
                if (iVar1 == IP4) {
                  push_words(&DAT_0075f050,&DAT_020b95e0);
                  FUN_0040c1c0(&DAT_020b8e60);
                  pop_words(&DAT_0075f050,&DAT_020b95e0);
                  if (LOAD_LEN < 8) {
                    thunk_FUN_005239c9(&LOAD_I,&f_8);
                  }
                  if ((0xe < LOAD_LEN) && (*(float *)(&ITEM_P15 + LOAD_W * 4) != f_0)) {
                    P2 = P2 / *(float *)(&ITEM_P15 + LOAD_W * 4);
                  }
                  *(float *)(&ITEM_P8 + LOAD_W * 4) = P2;
                  if (_DAT_020b966c != f_0) {
                    fVar3 = (float10)amod(&DAT_020b966c,&f_10);
                    IP9 = (int)ROUND(fVar3);
                    DAT_020b964c = (float)IP9;
                    *(float *)(&ITEM_P9 + LOAD_W * 4) = _DAT_020b966c - DAT_020b964c;
                  }
                }
              }
            }
          }
          LOAD_I = LOAD_I + 1;
        }
      }
      do {
        DAT_007abac0 = DAT_007abac0 + 1;
        if ((EDIT_ITEM != 0) || (ITEM_I < DAT_007abac0)) {
          _DAT_007abab0 = ITEM_WORDS;
          ITEM_I = 1;
          DAT_007abac0 = EDIT_ITEM;
          EDIT_ITEM = 0;
          push_words(&DAT_0075f050,&DAT_020b9440);
          draw_items();
          pop_words(&DAT_0075f050,&DAT_020b9440);
          DAT_0078b4f0 = 1;
          EDIT_ITEM = DAT_007abac0;
          return;
        }
LAB_0040cfa0:
        LOAD_I = DAT_007abac0;
        load_item_header();
      } while (((((LOAD_CODE != 6) || (LOAD_LEN < 7)) ||
                (DAT_007ababc = LOAD_STAFF, LOAD_STAFF < IP2)) ||
               ((IP5 < LOAD_STAFF || (LOAD_P3 < P3)))) || (P4 < LOAD_P3));
      IP6 = LOAD_LEN;
      thunk_FUN_0054c419(&DAT_020b95e0,&DAT_0075f050);
      thunk_FUN_0054c590(&ITEM_P1 + LOAD_W,&DAT_020b95e0,&LOAD_LEN);
    } while( true );
  }
  thunk_FUN_005725fa();
  if (DAT_020527a0 == -3) goto LAB_0040cfa0;
  DAT_020527a0 = -2;
  goto LAB_0040cfa0;
}


