// FUN_005086df @ 005086df (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005086df(void)

{
  int iVar1;
  int iVar2;
  
  DAT_009403a8 = 1;
  for (iVar2 = DAT_01b34584; 0 < iVar2; iVar2 = iVar2 + -1) {
    if ((*(char *)((int)&DAT_01b34588 + DAT_009403a8 + 3) == '\x01') &&
       ('c' < (char)(&DAT_01b42feb)[DAT_009403a8])) {
      *(float *)(&DAT_01b456f8 + DAT_009403a8 * 4) =
           *(float *)(&DAT_01b456f8 + DAT_009403a8 * 4) / f_2;
      (&DAT_01b42feb)[DAT_009403a8] = (&DAT_01b42feb)[DAT_009403a8] + -100;
    }
    DAT_009403a8 = DAT_009403a8 + 1;
  }
  DAT_009403a4 = 1;
  do {
    DAT_009403a0 = DAT_009403a4;
    iVar2 = (DAT_01b34584 - DAT_009403a4) + 1;
    DAT_009403a8 = DAT_009403a4;
    while( true ) {
      if (iVar2 < 1) {
        return;
      }
      if ((*(char *)((int)&DAT_01b34588 + DAT_009403a8 + 3) == '\x0e') ||
         (*(char *)((int)&DAT_01b34588 + DAT_009403a8 + 3) == '\x11')) break;
      DAT_009403a8 = DAT_009403a8 + 1;
      iVar2 = iVar2 + -1;
    }
    DAT_0094039c = DAT_009403a4;
    for (iVar2 = DAT_009403a8 - DAT_009403a4; 0 < iVar2; iVar2 = iVar2 + -1) {
      if ((*(char *)((int)&DAT_01b34588 + DAT_0094039c + 3) == '\x01') &&
         (_DAT_00940398 = (int)(char)(&DAT_01b42feb)[DAT_0094039c], _DAT_00940398 != 0)) {
        DAT_00940394 = (int)*(char *)((int)&DAT_01b408d8 + DAT_0094039c + 3);
        DAT_00940390 = DAT_0094039c + 1;
        for (iVar1 = DAT_009403a8 - DAT_00940390; 0 < iVar1; iVar1 = iVar1 + -1) {
          if ((*(char *)((int)&DAT_01b34588 + DAT_00940390 + 3) == '\x01') &&
             (DAT_00940394 == *(char *)((int)&DAT_01b408d8 + DAT_00940390 + 3))) {
            if ((&DAT_01b42feb)[DAT_00940390] != '\0') {
              _DAT_00940398 = (int)(char)(&DAT_01b42feb)[DAT_00940390];
            }
            (&DAT_01b42feb)[DAT_00940390] = DAT_00940398;
          }
          DAT_00940390 = DAT_00940390 + 1;
        }
      }
      DAT_0094039c = DAT_0094039c + 1;
    }
    DAT_009403a4 = DAT_009403a8 + 1;
  } while( true );
}


