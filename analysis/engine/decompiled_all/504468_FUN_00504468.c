// FUN_00504468 @ 00504468 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00504468(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  *param_1 = 0;
  DAT_00904084 = '\x02';
  puVar1 = &DAT_01b3458c + DAT_01b34584;
  DAT_01b34584 = DAT_01b34584 + 1;
  *puVar1 = 0xe;
  *(float *)(&DAT_01b456f0 + DAT_01b34584 * 4) = f_1;
  *(undefined1 *)((int)&DAT_01b34588 + DAT_01b34584 + 1) = 2;
  DAT_00904080 = 1;
  for (iVar2 = DAT_01b34584; 0 < iVar2; iVar2 = iVar2 + -1) {
    if (*(char *)((int)&DAT_01b34588 + DAT_00904080 + 3) <= DAT_00904084) {
      *param_1 = *param_1 + 1;
      *(undefined4 *)(&DAT_01b2a930 + *param_1 * 4) =
           *(undefined4 *)(&DAT_01b456f8 + DAT_00904080 * 4);
      *(undefined4 *)(&DAT_01b4f338 + *param_1 * 4) =
           *(undefined4 *)(&DAT_01b36c98 + DAT_00904080 * 4);
    }
    DAT_00904080 = DAT_00904080 + 1;
  }
  DAT_01b9d5cc = *param_1;
  DAT_01b8278c = DAT_01b34588;
  *param_1 = 0;
  DAT_0090407c = 1;
  DAT_00904078 = 1;
  (&DAT_01b4f33c)[DAT_01b9d5cc] = 9999;
  DAT_00904074 = *(int *)(&DAT_01b4f338 + DAT_0090407c * 4);
  iVar2 = DAT_00904078;
  iVar3 = DAT_0090407c;
  while (DAT_0090407c = iVar3, DAT_00904078 = iVar2, DAT_0090407c <= DAT_01b9d5cc) {
    iVar3 = DAT_0090407c + 1;
    iVar2 = DAT_00904078;
    if (DAT_00904074 < *(int *)(&DAT_01b4f338 + iVar3 * 4)) {
      DAT_00904070 = *(int *)(&DAT_01b4f338 + iVar3 * 4);
      _DAT_0090406c = f_9999;
      iVar3 = DAT_00904078;
      for (iVar2 = (DAT_0090407c - DAT_00904078) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
        DAT_00904068 = *(float *)(&DAT_01b2a930 + iVar3 * 4);
        if ((f_0 < DAT_00904068) && (DAT_00904068 < _DAT_0090406c)) {
          _DAT_0090406c = DAT_00904068;
        }
        iVar3 = iVar3 + 1;
      }
      if (DAT_00904068 < f_64) {
        DAT_01b34588 = _DAT_0090406c + DAT_01b34588;
      }
      *param_1 = *param_1 + 1;
      (&DAT_01b8278c)[*param_1] = DAT_01b34588;
      *(int *)(&DAT_01b78b48 + *param_1 * 4) = DAT_00904074;
      DAT_00904064 = 0;
      DAT_00904074 = DAT_00904070;
      DAT_00904080 = DAT_00904078;
      for (iVar2 = (DAT_0090407c - DAT_00904078) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
        DAT_00904068 = *(float *)(&DAT_01b2a930 + DAT_00904080 * 4) - _DAT_0090406c;
        if (DAT_00904068 < f_0_01) {
          DAT_00904068 = f_0;
        }
        *(float *)(&DAT_01b2a930 + DAT_00904080 * 4) = DAT_00904068;
        *(undefined4 *)(&DAT_01b4f338 + DAT_00904080 * 4) = 0;
        if ((f_0 < *(float *)(&DAT_01b2a930 + DAT_00904080 * 4)) &&
           (*(int *)(&DAT_01b4f338 + DAT_00904080 * 4) = DAT_00904074, DAT_00904064 == 0)) {
          DAT_00904064 = DAT_00904080;
        }
        DAT_00904080 = DAT_00904080 + 1;
      }
      iVar2 = DAT_00904064;
      iVar3 = DAT_00904064;
      if (DAT_00904064 == 0) {
        iVar2 = DAT_00904078;
        iVar3 = DAT_0090407c;
      }
    }
  }
  return;
}


