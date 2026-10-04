// FUN_005721e2 @ 005721e2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005721e2(void)

{
  int iVar1;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_44 [16];
  
  _DAT_009a853c = 0;
  if (((((DAT_0078b380 < 2) && (DAT_0078b378 != 1)) && (DAT_0078b378 != 2)) &&
      ((DAT_0078b378 < 3 || (7 < DAT_0078b378)))) &&
     ((DAT_0078b378 != 9 && ((DAT_0078b378 != 10 && (DAT_0078b378 != 0xb)))))) {
    iVar1 = DAT_0078b380;
    if (DAT_0078b380 < 0) {
      iVar1 = -DAT_0078b380;
    }
    if (iVar1 != 2) {
      if (DAT_0078b4f0 == 0) {
        local_44[0] = 0;
        local_4c = 8;
        local_48 = "(SAVED)";
        FUN_00606890(local_44,0xffffffff,0x784ff00,&DAT_0076a4d0,&local_4c);
      }
      else {
        local_44[0] = 0;
        local_4c = 8;
        local_48 = "       ";
        FUN_00606890(local_44,0xffffffff,0x784ff00,&DAT_0076a4d0,&local_4c);
      }
    }
  }
  return;
}


