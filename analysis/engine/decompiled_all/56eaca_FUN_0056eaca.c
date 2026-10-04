// FUN_0056eaca @ 0056eaca (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0056eb18) */

void FUN_0056eaca(void)

{
  undefined4 local_3c;
  int local_38;
  undefined4 *local_34;
  undefined4 local_28 [9];
  
  thunk_FUN_0056ae1c();
  (&DAT_01caf69f)[DAT_01cadcfc] = 0x5c;
  DAT_01a27710 = DAT_01a2770c * 100 + DAT_01a27718 + -0x12c0;
  local_3c = 3;
  local_38 = (int)&DAT_01caf6a0 + DAT_01cadcfc;
  local_28[0] = 0;
  local_34 = &DAT_01a27710;
  FUN_005f34f0(local_28,0x784ff00,&DAT_0076a368,&local_3c,&DAT_0079fd04);
  DAT_01cadcfc = DAT_01cadcfc + 3;
  if ((DAT_01a27710 < 0x28) || (199 < DAT_01a27710 && DAT_01a27710 < 0xf1)) {
    FUN_0056edfd();
  }
  DAT_01a27710 = 0;
  return;
}


