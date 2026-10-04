// FUN_004f3db0 @ 004f3db0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004f3ed9) */
/* WARNING: Removing unreachable block (ram,0x004f3f80) */

void FUN_004f3db0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 local_cc [36];
  undefined4 local_3c [14];
  
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  iVar1 = FUN_005f4660(0x20);
  if (iVar1 == 0) {
    if ((DAT_020b8ea0._1_1_ == ' ') || (DAT_020b8ea0._1_1_ == '*')) {
      thunk_FUN_0045ef21();
    }
    else {
      iVar1 = FUN_005f4660(0x20);
      if (iVar1 == 0) {
        if ((DAT_00794fd0 == 0) || (DAT_00794fd0 = DAT_00794fd0 + -1, 1 < DAT_00794fd0)) {
          iVar1 = FUN_005f4660(0x20);
          if (iVar1 == 0) {
            DAT_008d1a50 = (uint)(DAT_020b8ea0._1_1_ == 'B');
            FUN_004f5268(&DAT_008d1a50);
            if (DAT_008d1a50 != 0xffffff9d) {
              DAT_020b8ea0._0_1_ = DAT_007665e0;
            }
            if (DAT_0078b4e4 == 0) {
              DAT_0078b4e4 = (int)DAT_020b8ea0._1_1_;
            }
          }
          else if (DAT_0078dc68 == -1) {
            FUN_005f33c9(&stack0xfffffffc,0x4f40fb);
            FUN_005f34d1(puVar6,0x4f4116);
            DAT_0078dc68 = 2000;
            *(undefined4 *)(puVar6 + -4) = 0;
          }
          else {
            FUN_005f33c9(&stack0xfffffffc,0x4f40a7);
            FUN_005f34d1(puVar5,0x4f40c2);
            DAT_0078dc68 = -1;
            *(undefined4 *)(puVar5 + -8) = 0;
          }
        }
        else {
          DAT_00794fd0 = 0;
          local_3c[0] = 0;
          FUN_005f7950(local_3c,DAT_02052740,0x784ff00,&DAT_00766614,0);
          DAT_02052740 = 0;
          draw_items();
        }
      }
      else {
        puVar2 = &DAT_0078b510;
        puVar3 = local_cc;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        DAT_008d1a4c = FUN_005ff950(local_cc,0x80);
        FUN_005f33c9(&stack0xfffffffc,0x4f3ea4);
        FUN_005f34d1(puVar4,0x4f3ebf);
        FUN_005f46bc(puVar4,0x4f3efd);
        FUN_005f34d1(puVar4,0x4f3f13);
        iVar1 = DAT_008d1a4c + 7;
        *(int *)(puVar4 + -0x40) = DAT_008d1a4c + 3;
        *(int *)(puVar4 + -0x48) = iVar1;
        thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,puVar4 + -0x40,puVar4 + -0x48,"(1i4)",5,&ITEM_I);
        FUN_005f46bc(puVar4,0x4f3fa4);
        FUN_005f34d1(puVar4,0x4f3fba);
        thunk_FUN_0054da52(&DAT_020b8ea0,0x200);
        thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
      }
    }
  }
  else {
    FUN_004f5d49(&DAT_008d1a50);
  }
  return;
}


