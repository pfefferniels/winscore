// FUN_00410362 @ 00410362 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00410362(void)

{
  undefined4 *local_34 [2];
  undefined4 local_2c [10];
  
  if (DAT_01fbb798 != 2) {
    DAT_0078b4e0 = DAT_02052740;
    DAT_02052740 = DAT_02052748;
    local_2c[0] = 0;
    local_34[0] = &DAT_01fbb860;
    FUN_005fc330(local_2c,0xffffffff,0x784ff00,&DAT_0075f304,local_34,&DAT_0078b0e0);
    local_34[0] = &DAT_01fbb870;
    FUN_005fc980(local_2c,&DAT_0075f300,local_34);
    DAT_02052740 = DAT_0078b4e0;
  }
  return;
}


