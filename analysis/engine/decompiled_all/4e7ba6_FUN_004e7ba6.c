// FUN_004e7ba6 @ 004e7ba6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7ba6(void)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  puVar2 = &stack0xfffffffc;
  if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x4e) {
    FUN_004e9018();
    return;
  }
  _DAT_008d12ec = 1;
  if ((_DAT_020b8ea0 & 0xffff) == 0x544d) {
    FUN_004e79d2();
    return;
  }
  DAT_008d12e8 = DAT_0078b4e4;
  if (((DAT_0078b4e0 < 0x46) || (DAT_0078b4e4 == 0x53)) || (DAT_0078b4e4 == 0x20)) {
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x45) {
      thunk_FUN_004e5988();
      return;
    }
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58) {
      FUN_004e7820();
      return;
    }
    FUN_004e7f79();
    return;
  }
  if (DAT_0078b4e4 - 0x41U < 9) {
    bVar5 = DAT_0078b4e4 + -0x41 == 0;
    switch(DAT_0078b4e4 + -0x41) {
    case 0:
      iVar1 = 7;
      pcVar3 = (char *)&DAT_020b8ea0;
      pcVar4 = "MAKEDIR";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        thunk_FUN_00510b90();
      }
      else {
        FUN_004e8642();
      }
      break;
    default:
      goto LAB_004e7e0f;
    case 2:
      break;
    case 4:
      if (_DAT_020b8ea0 == 0x5341454d) {
        FUN_005f33c9(&stack0xfffffffc,&LAB_004e7cf1);
        FUN_005f34d1(puVar2,&LAB_004e7d0c);
        if (DAT_0078b4e8 == 1) {
          FUN_005f33c9(puVar2,&LAB_004e7d37);
          FUN_005f34d1(puVar2,&LAB_004e7d52);
        }
        *(undefined4 *)(puVar2 + -8) = 0;
      }
      else if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x54) {
        DAT_0078b4e8 = 1;
        thunk_FUN_0054e9f2();
        DAT_0078b4f0 = 1;
      }
      break;
    case 5:
    case 6:
      break;
    case 7:
      break;
    case 8:
    }
  }
  else {
    if (DAT_0078b4e4 == 0x4d) {
      DAT_0078b378 = 0;
      DAT_008d12e8 = DAT_0078b4e4;
      _DAT_008d12ec = 1;
      return;
    }
    if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x4b) {
      FUN_004ea5ef();
      return;
    }
    if (((_DAT_020b8ea0 >> 8 & 0xff) != 0x55) && ((_DAT_020b8ea0 >> 8 & 0xff) != 0x58)) {
      DAT_008d12e8 = DAT_0078b4e4;
      _DAT_008d12ec = 1;
      return;
    }
LAB_004e7e0f:
    _DAT_008d12f0 = (int)ROUND(P2);
    if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x42) {
      _DAT_008d12f0 = -99;
    }
    if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x58) {
      _DAT_008d12f0 = -0x62;
    }
    FUN_004e8adf(&DAT_008d12f0);
  }
  return;
}


