// FUN_0041baa2 @ 0041baa2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined8 __fastcall FUN_0041baa2(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_007d159c = 0;
  DAT_01e66a08 = 0xf3e58;
  DAT_007d1598 = *param_3;
  DAT_007d1594 = 1;
  DAT_007d1590 = 200;
  if ((32000 < DAT_01a14948 - VIEW_DX) || (32000 < DAT_01a14950 - VIEW_DX)) {
    DAT_007d1594 = 0xc9;
    DAT_007d1590 = 0x100;
  }
  DAT_007d158c = 0;
  if ((((DAT_01fbb8a0 == 0x20) || (DAT_01fbb8a0 == 10)) || (DAT_01fbb8a0 == 3)) ||
     (DAT_01fbb8a0 == 600)) {
    DAT_007d158c = 1;
  }
  while( true ) {
    DAT_007d1588 = DAT_007d1594;
    iVar1 = 0;
    iVar2 = DAT_01e66a08;
    for (iVar4 = (DAT_007d1590 - DAT_007d1594) + 1; DAT_01e66a08 = iVar2, 0 < iVar4;
        iVar4 = iVar4 + -1) {
      if ((DAT_007d158c != 0) ||
         (iVar3 = iVar1, (*(uint *)(&DAT_01e67104 + DAT_007d1588 * 4) & 1) != 0)) {
        DAT_007d1584 = *param_3 - (&STAFF_MID0)[DAT_007d1588];
        if (DAT_007d1584 < 0) {
          DAT_007d1584 = -DAT_007d1584;
        }
        iVar3 = DAT_007d1588;
        DAT_01e66a08 = DAT_007d1584;
        if (iVar2 <= DAT_007d1584) {
          iVar3 = iVar1;
          DAT_01e66a08 = iVar2;
        }
      }
      param_2 = 0;
      DAT_007d1588 = DAT_007d1588 + 1;
      iVar1 = iVar3;
      iVar2 = DAT_01e66a08;
    }
    if ((iVar1 != 0) || (DAT_007d159c != 0)) break;
    DAT_007d1594 = 1;
    DAT_007d159c = 1;
  }
  return CONCAT44(param_2,iVar1);
}


