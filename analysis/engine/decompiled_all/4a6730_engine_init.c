// engine_init @ 004a6730 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 engine_init(void)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = &stack0xfffffffc;
  DAT_0171b230 = 0xffffffff;
  FUN_005f34d1(&stack0xfffffffc,0x4a6761);
  FUN_005f34d1(puVar2,0x4a6782);
  FUN_005f34d1(puVar2,0x4a67a3);
  FUN_005f34d1(puVar2,0x4a67c4);
  FUN_005f34d1(puVar2,0x4a67e5);
  FUN_005f34d1(puVar2,0x4a6806);
  FUN_005f34d1(puVar2,0x4a6827);
  FUN_005f34d1(puVar2,0x4a6848);
  FUN_005f34d1(puVar2,0x4a6869);
  FUN_005f34d1(puVar2,0x4a688a);
  DAT_0078b460 = 0xb;
  FUN_005f33c9(puVar2,0x4a68b7);
  FUN_005f34d1(puVar2,0x4a68d2);
  while( true ) {
    while( true ) {
      while( true ) {
        *(undefined4 *)(puVar2 + -0x38) = 0;
        *(undefined4 *)(puVar2 + -0x48) = 0x40;
        *(undefined4 **)(puVar2 + -0x44) = &DAT_0078b420;
        *(uint **)(puVar2 + -0x40) = &DAT_008391e0;
        FUN_005f47c0(puVar2 + -0x38,0xffffffff,0x784ff00,&DAT_00763bf8,puVar2 + -0x48);
        if ((DAT_008391e0 & 1) != 0) {
          *(undefined4 *)(puVar2 + -0x10) = 0;
          if (DAT_0078b460 != 0xb) {
            FUN_004aca90();
          }
          puVar4 = &DAT_0078b420;
          puVar5 = &DAT_019c692c;
          for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          FUN_004a6adc();
          thunk_FUN_004f5d49(&DAT_008391dc);
          FUN_004a6f47();
          FUN_005f46bc(puVar2,0x4a6a61);
          FUN_005f46bc(puVar2,0x4a6a7d);
          FUN_005f34d1(puVar2,0x4a6a93);
          return *(undefined4 *)(puVar2 + -0x18);
        }
        DAT_0078b420._0_1_ = (char)DAT_0078b420 + '\x01';
        if ('Y' < (char)DAT_0078b420) break;
        *(undefined4 *)(puVar2 + -0xc) = 0;
      }
      if (DAT_0078b460 != 0xb) break;
      DAT_0078b460 = 0x19;
      FUN_005f33c9(puVar2,0x4a698a);
      FUN_005f34d1(puVar2,0x4a69a5);
      *(undefined4 *)(puVar2 + -8) = 0;
    }
    if (DAT_0078b460 != 0x19) break;
    DAT_0078b460 = 0x1f;
    pcVar3 = "C:\\Program Files (x86)\\winscore\\scorlib\\PREF.DAT";
    puVar4 = &DAT_0078b420;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  thunk_FUN_0042ac4e(&DAT_0078b420,0x40);
                    /* WARNING: Subroutine does not return */
  FUN_006013a0(&DAT_00763b78,0,0x784ff00,0,0);
}


