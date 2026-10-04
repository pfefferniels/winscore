// FUN_00508997 @ 00508997 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00508997(void)

{
  int iVar1;
  int iVar2;
  
  DAT_009403b8 = 0;
  do {
    do {
      do {
        iVar2 = DAT_009403b8;
        DAT_009403b8 = DAT_009403b8 + 1;
        if (DAT_01b34584 <= DAT_009403b8) {
          return;
        }
      } while (((&DAT_01b3458c)[iVar2] != '\x11') || ((&DAT_01b3458d)[iVar2] == '\x11'));
      DAT_009403b4 = (int)(char)(&DAT_01b42fec)[iVar2];
      iVar1 = DAT_009403b4;
      if (DAT_009403b4 < 0) {
        iVar1 = -DAT_009403b4;
      }
    } while (99 < iVar1);
    DAT_009403b8 = iVar2 + 2;
    DAT_009403b0 = DAT_009403b8;
    for (iVar2 = (DAT_01b34584 - DAT_009403b8) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
      if (*(char *)((int)&DAT_01b34588 + DAT_009403b0 + 3) == '\x11') goto LAB_00508aa0;
      DAT_009403b0 = DAT_009403b0 + 1;
    }
    DAT_009403b0 = DAT_01b34584;
LAB_00508aa0:
    FUN_00508ad8(&DAT_009403b4,&DAT_009403b8,&DAT_009403b0);
  } while( true );
}


