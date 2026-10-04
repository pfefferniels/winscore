// FUN_00432998 @ 00432998 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432998(void)

{
  uint uVar1;
  int iVar2;
  undefined4 local_4c;
  undefined *local_48;
  undefined *local_44;
  undefined *local_40;
  undefined4 local_3c [9];
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  _DAT_01cb0e90 = 1;
  local_3c[0] = 0;
  local_44 = &DAT_007f167c;
  FUN_005f8240(local_3c,3,0x784ff00,&DAT_007600e0,&local_44);
  local_44 = (undefined *)0x16;
  local_40 = &DAT_01cb0e90;
  FUN_005f8730(local_3c,&DAT_007600dc,&local_44);
  local_4c = 0x32;
  local_48 = &DAT_007f1680;
  local_44 = (undefined *)0x5;
  FUN_005f8730(local_3c,&DAT_007600d8,&local_4c);
  DAT_007f1678 = DAT_01cb0ea4 + -1;
  local_18 = 10000;
  DAT_007f1674 = 1;
  do {
    uVar1 = DAT_007f1674 + 0x40U & 0x3f;
    if ((uVar1 != 0) && ((int)(DAT_007f1674 + 0x40U) < 0)) {
      uVar1 = uVar1 - 0x40;
    }
    if (uVar1 == 1) {
      local_3c[0] = 0;
      local_44 = &DAT_007f167c;
      local_14 = FUN_005f8240(local_3c,3,0x784ff02,&DAT_007600d4,&local_44);
      if (local_14 == -1) break;
    }
    local_40 = (undefined *)(DAT_007f1674 * 2 + 0x7f16b2);
    local_3c[0] = 0;
    local_44 = (undefined *)0x2;
    local_10 = FUN_005f8240(local_3c,3,0x784ff02,&DAT_007600d0,&local_44);
    if (local_10 == -1) break;
    DAT_007f1674 = DAT_007f1674 + 1;
    local_18 = local_18 + -1;
  } while (0 < local_18);
  DAT_007f1670 = 1;
  DAT_007f1674 = 1;
  for (iVar2 = (DAT_007f1678 + 2) / 3; 0 < iVar2; iVar2 = iVar2 + -1) {
    *(float *)(&DAT_01dc41fc + DAT_007f1670 * 4) =
         (float)(int)*(short *)(DAT_007f1674 * 2 + 0x7f16b2);
    local_40 = (undefined *)(int)(short)(&DAT_007f16b4)[DAT_007f1674];
    *(float *)(&DAT_01e123fc + DAT_007f1670 * 4) = (float)(int)local_40;
    *(undefined2 *)(&DAT_01d9d0fe + DAT_007f1670 * 2) = (&DAT_007f16b6)[DAT_007f1674];
    DAT_007f1670 = DAT_007f1670 + 1;
    DAT_007f1674 = DAT_007f1674 + 3;
  }
  local_3c[0] = 0;
  FUN_005f7950(local_3c,3,0x784ff00,&DAT_007600cc,0);
  local_8 = 10;
  DAT_007f1674 = 2;
  do {
    if (1 < *(short *)(DAT_007f1674 * 2 + 0x1cb0e8e)) {
      *(short *)(DAT_007f1674 * 2 + 0x1cb0e8e) = *(short *)(DAT_007f1674 * 2 + 0x1cb0e8e) / 3 + 1;
    }
    DAT_007f1674 = DAT_007f1674 + 1;
    local_8 = local_8 + -1;
  } while (0 < local_8);
  return;
}


