// FUN_00582d56 @ 00582d56 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00582d56(int param_1,undefined4 param_2,float *param_3,undefined4 *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  int local_48;
  int local_44;
  int local_8;
  
  local_48 = 8;
  DAT_009a9098 = 1;
  do {
    *(undefined1 *)((int)&DAT_009a9098 + DAT_009a9098 + 3) =
         *(undefined1 *)(DAT_009a9098 + param_1 + -1);
    DAT_009a9098 = DAT_009a9098 + 1;
    local_48 = local_48 + -1;
  } while (0 < local_48);
  *param_4 = 0;
  thunk_FUN_0054c419(&IP1,&DAT_0076abc8);
  local_44 = 4;
  DAT_009a9098 = 7;
  do {
    if (*(char *)(DAT_009a9098 + param_1 + -1) == '.') {
      DAT_009a9094 = 1;
      if (*(char *)(DAT_009a9098 + param_1 + -2) == '.') {
        DAT_009a9094 = 2;
        DAT_009a9098 = DAT_009a9098 + -1;
      }
      *(undefined1 *)(DAT_009a9098 + param_1 + -1) = 0x20;
      goto LAB_00582e79;
    }
    DAT_009a9098 = DAT_009a9098 + -1;
    local_44 = local_44 + -1;
  } while (0 < local_44);
  DAT_009a9094 = 0;
LAB_00582e79:
  DAT_009a9098 = 3;
  DAT_009a9090 = 0;
  if (*(char *)(param_1 + 2) == 'T') {
    DAT_009a9090 = 1;
    DAT_009a9098 = 4;
    if (*(char *)(param_1 + 3) == ' ') {
      *(undefined1 *)(param_1 + 3) = 0x45;
    }
  }
  DAT_009a90b4 = *(byte *)(DAT_009a9098 + param_1 + -1);
  bVar6 = DAT_009a90b4 < 0x20;
  if (DAT_009a90b4 == 0x20) {
    thunk_FUN_00468df8(&DAT_0076abc4);
    return;
  }
  P1 = f_0;
  iVar3 = 1;
  pbVar4 = &DAT_009a90b4;
  pbVar5 = &DAT_0076abc0;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar2 = *pbVar5;
    bVar1 = *pbVar4;
    bVar6 = bVar1 < bVar2;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 == bVar2);
  if ((bVar6) && (bVar6 = DAT_009a90b4 < 0x2a, DAT_009a90b4 != 0x2a)) {
    iVar3 = 1;
    bVar7 = false;
    pbVar4 = &DAT_009a90b4;
    pbVar5 = &DAT_0076ab9c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pbVar4 < *pbVar5;
      bVar7 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (!bVar6) {
      iVar3 = 1;
      bVar6 = false;
      pbVar4 = &DAT_009a90b4;
      pbVar5 = &DAT_0076ab98;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pbVar4 < *pbVar5;
        bVar7 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (bVar6 || bVar7) {
        P1 = P2;
        FUN_00582d05();
        goto LAB_005830be;
      }
    }
  }
  else {
    if (DAT_009a90b4 == 0x2a) {
      P1 = P2;
    }
    if (DAT_009a90b4 == 0x53) {
      P1 = f_16;
    }
    if (DAT_009a90b4 == 0x45) {
      P1 = f_8;
    }
    if (DAT_009a90b4 == 0x51) {
      P1 = f_4;
    }
    if (DAT_009a90b4 == 0x48) {
      P1 = f_2;
    }
    if (DAT_009a90b4 == 0x57) {
      P1 = f_1;
    }
    if (DAT_009a90b4 == 0x44) {
      P1 = f_0_5;
    }
    if (DAT_009a90b4 == 0x55) {
      P1 = f_20;
    }
    if (P1 != f_0) {
LAB_005830be:
      P7 = f_4 / P1;
      P9 = f_0;
      P6 = f_0;
      if (f_8 <= P1) {
        P9 = f_1;
      }
      if (f_16 <= P1) {
        P9 = f_2;
      }
      if (f_32 <= P1) {
        P9 = f_3;
      }
      if (f_64 <= P1) {
        P9 = f_4;
      }
      if (f_128 <= P1) {
        P9 = f_5;
      }
      if (P1 < f_4) {
        P6 = f_1;
      }
      if (P1 < f_2) {
        P6 = f_2;
      }
      if (P1 < f_1) {
        P6 = f_3;
      }
      if (DAT_009a9090 != 0) {
        P7 = (P7 * f_2) / f_3;
      }
      P47 = f_0;
      if (*param_3 == f_1) {
        if (DAT_009a9094 == 0) goto LAB_0058334a;
        P9 = (float)DAT_009a9094 * f_10 + P9;
      }
      else {
        P5 = P9;
        P9 = f_0;
        if (f_1 < P7) {
          P5 = f_m1;
        }
        if (f_2 < P7) {
          P5 = f_m2;
        }
        if (f_4 < P7) {
          P5 = f_m3;
        }
        P6 = f_0;
        if (DAT_009a9094 == 0) goto LAB_0058334a;
        P6 = (float)DAT_009a9094;
      }
      P47 = P7 / f_2;
      if (DAT_009a9094 == 2) {
        P47 = P47 / f_2 + P47;
      }
      P7 = P47 + P7;
      goto LAB_0058334a;
    }
  }
  *param_4 = 0xffffffff;
LAB_0058334a:
  local_8 = 8;
  DAT_009a9098 = 1;
  do {
    *(undefined1 *)(DAT_009a9098 + param_1 + -1) =
         *(undefined1 *)((int)&DAT_009a9098 + DAT_009a9098 + 3);
    DAT_009a9098 = DAT_009a9098 + 1;
    local_8 = local_8 + -1;
  } while (0 < local_8);
  return;
}


