// FUN_00504fcb @ 00504fcb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00504fcb(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_00909ec4 = 1;
  for (iVar2 = DAT_01b34584; 0 < iVar2; iVar2 = iVar2 + -1) {
    if (*(char *)((int)&DAT_01b34588 + DAT_00909ec4 + 3) == '\x01') {
      if (f_0 < *(float *)(&DAT_01b456f8 + DAT_00909ec4 * 4)) {
        iVar4 = (int)*(char *)((int)&DAT_01b408d8 + DAT_00909ec4 + 3);
        LOAD_P3 = (float)(iVar4 / 7);
        LOAD_LEN = (iVar4 % 7) * 2;
        if (4 < LOAD_LEN) {
          LOAD_LEN = LOAD_LEN + -1;
        }
        *(char *)((int)&DAT_01b408d8 + DAT_00909ec4 + 3) =
             SUB41(LOAD_P3,0) * '\f' + (char)LOAD_LEN +
             (char)*(undefined4 *)(&DAT_007956a4 + (char)(&DAT_01b42feb)[DAT_00909ec4] * 4) + '\x18'
        ;
      }
      else {
        *(undefined1 *)((int)&DAT_01b34588 + DAT_00909ec4 + 3) = 0;
      }
    }
    DAT_00909ec4 = DAT_00909ec4 + 1;
  }
  DAT_00909ec4 = 1;
  for (iVar2 = DAT_01b34584; 0 < iVar2; iVar2 = iVar2 + -1) {
    if (*(char *)((int)&DAT_01b34588 + DAT_00909ec4 + 3) == '\a') {
      LOAD_LEN = (int)(char)(&DAT_01b42feb)[DAT_00909ec4];
      DAT_00909ec0 = *(int *)(&DAT_01b36c98 + DAT_00909ec4 * 4);
      DAT_00909ebc = (int)ROUND(*(float *)(&DAT_01b456f8 + DAT_00909ec4 * 4));
      FUN_00504dfc(&DAT_00909ec0,&DAT_00909ec0,&DAT_00909ebc,&DAT_00766ec0);
      DAT_00909eb8 = 0xc;
      if (LOAD_LEN < 0) {
        DAT_00909eb8 = 0xfffffff4;
      }
      if (LOAD_LEN == 0xf) {
        DAT_00909eb8 = 0x18;
      }
      DAT_00909eb4 = 1;
      for (iVar4 = DAT_01b34584; 0 < iVar4; iVar4 = iVar4 + -1) {
        if (((*(char *)((int)&DAT_01b34588 + DAT_00909eb4 + 3) == '\x01') &&
            (DAT_00909eb0 = *(int *)(&DAT_01b36c98 + DAT_00909eb4 * 4), DAT_00909ec0 <= DAT_00909eb0
            )) && (DAT_00909eb0 <= DAT_00909ebc)) {
          if (LOAD_LEN == 0) {
            if ((DAT_0078d9f4 == 0) && (DAT_00909ebc != DAT_00909eb0)) {
              *(float *)(&DAT_01b456f8 + DAT_00909eb4 * 4) =
                   *(float *)(&DAT_01b456f8 + DAT_00909eb4 * 4) + f_0_05;
            }
          }
          else {
            *(char *)((int)&DAT_01b408d8 + DAT_00909eb4 + 3) =
                 *(char *)((int)&DAT_01b408d8 + DAT_00909eb4 + 3) + (char)DAT_00909eb8;
          }
        }
        DAT_00909eb4 = DAT_00909eb4 + 1;
      }
    }
    DAT_00909ec4 = DAT_00909ec4 + 1;
  }
  thunk_FUN_0054c419(&DAT_01b4f33c,&DAT_00766ec4);
  DAT_00909eac = 400;
  DAT_00909eb4 = 1;
  LOAD_P3 = 0.0;
  DAT_00909eb8 = 1;
  DAT_00909ec4 = 1;
  for (iVar2 = DAT_01b34584; 0 < iVar2; iVar2 = iVar2 + -1) {
    if (*(char *)((int)&DAT_01b34588 + DAT_00909ec4 + 3) == '\x01') {
      puVar1 = (undefined1 *)((int)&DAT_01b58f7c + DAT_01b34574);
      DAT_01b34574 = DAT_01b34574 + 1;
      *puVar1 = *(undefined1 *)((int)&DAT_01b408d8 + DAT_00909ec4 + 3);
      LOAD_LEN = *(int *)(&DAT_01b36c98 + DAT_00909ec4 * 4);
      DAT_00909ea8 = DAT_00909eb8;
      for (iVar4 = (DAT_01b9d5c0 - DAT_00909eb8) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
        iVar3 = LOAD_LEN - *(int *)(&DAT_01b78b48 + DAT_00909ea8 * 4);
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < 1) {
          DAT_00909eb8 = DAT_00909ea8;
          if (f_64 <= *(float *)(&DAT_01b456f8 + DAT_00909ec4 * 4)) {
            *(int *)(&DAT_01b4f338 + DAT_01b34574 * 4) = LOAD_LEN;
            LOAD_P3 = 1.4013e-45;
          }
          *(undefined4 *)(&DAT_01b5b688 + DAT_01b34574 * 4) =
               *(undefined4 *)(DAT_00909ea8 * 4 + 0x1b82788);
          *(float *)(&DAT_01b652c8 + DAT_01b34574 * 4) =
               *(float *)(DAT_00909ea8 * 4 + 0x1b82788) +
               *(float *)(&DAT_01b456f8 + DAT_00909ec4 * 4);
          *(float *)(&DAT_01b6ef08 + DAT_01b34574 * 4) = (float)(((LOAD_LEN + 1) % 400) / 2);
          if (DAT_00909eac <= *(int *)(&DAT_01b36c98 + DAT_00909ec4 * 4)) {
            DAT_00909eac = DAT_00909eac + 400;
            *(int *)(&DAT_01aad490 + DAT_00909eb4 * 0x10 + DAT_01b34580 * 4) = DAT_01b34574 + -1;
            DAT_00909eb4 = DAT_00909eb4 + 1;
          }
          break;
        }
        DAT_00909ea8 = DAT_00909ea8 + 1;
      }
    }
    DAT_00909ec4 = DAT_00909ec4 + 1;
  }
  *(int *)(&DAT_01aad490 + DAT_00909eb4 * 0x10 + DAT_01b34580 * 4) = DAT_01b34574;
  if (LOAD_P3 == 0.0) {
    return;
  }
  DAT_00909ec4 = DAT_01b34574;
LAB_005055f0:
  DAT_00909eb0 = 0;
  if (*(int *)(&DAT_01b4f338 + DAT_00909ec4 * 4) != 0) goto LAB_0050560c;
  goto LAB_005056ec;
LAB_0050560c:
  LOAD_LEN = *(int *)(&DAT_01b4f338 + DAT_00909ec4 * 4);
  DAT_00909ea4 = *(float *)(&DAT_01b5b688 + DAT_00909ec4 * 4);
  do {
    *(float *)(&DAT_01b652c8 + DAT_00909ec4 * 4) = DAT_00909ea4;
    *(float *)(&DAT_01b5b688 + DAT_00909ec4 * 4) = DAT_00909ea4 - f_0_05;
    DAT_00909ec4 = DAT_00909ec4 + -1;
    if (DAT_00909ec4 == 0) break;
    if ((DAT_00909eb0 == 0) && (LOAD_LEN != *(int *)(&DAT_01b4f338 + DAT_00909ec4 * 4))) {
      DAT_00909eb0 = DAT_00909ec4;
    }
  } while (*(int *)(&DAT_01b4f338 + DAT_00909ec4 * 4) != 0);
  DAT_00909ec4 = DAT_00909eb0;
  if (DAT_00909eb0 == 0) {
LAB_005056ec:
    if (DAT_00909ec4 < 2) {
      DAT_00909eb0 = 0;
      return;
    }
    DAT_00909ec4 = DAT_00909ec4 + -1;
  }
  goto LAB_005055f0;
}


