// FUN_004a6f47 @ 004a6f47 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a6f47(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  
  puVar5 = &stack0xfffffffc;
  FUN_005f46bc(&stack0xfffffffc,0x4a6f81);
  FUN_005f46bc(puVar5,0x4a6f9d);
  FUN_005f34d1(puVar5,0x4a6fb3);
  DAT_008396f4 = DAT_00763c7c;
  DAT_008396f5 = 0x20;
  DAT_008396e0 = -1;
  DAT_008396e4 = 0;
  *(undefined4 *)(puVar5 + -0x1c) = 1000;
  DAT_008396dc = 1;
  while ((_DAT_008396d8 = FUN_005f7bb0(&DAT_00839840,0x80,&DAT_00839728,&DAT_008396e0),
         DAT_008396e0 != -2 && (DAT_008396e0 != -3))) {
    DAT_008396e4 = DAT_008396e4 + 1;
    iVar7 = DAT_008396e4 * 10;
    *(undefined4 *)(iVar7 + 0x1ae0116) = DAT_0083973a;
    *(undefined4 *)(iVar7 + 0x1ae011a) = DAT_0083973e;
    *(undefined2 *)(iVar7 + 0x1ae011e) = DAT_00839742;
    thunk_FUN_0054c83c(DAT_008396e4 * 10 + 0x1ae0116,10,&DAT_00763c78);
    DAT_008396dc = DAT_008396dc + 1;
    *(int *)(puVar5 + -0x1c) = *(int *)(puVar5 + -0x1c) + -1;
    if (*(int *)(puVar5 + -0x1c) < 1) {
LAB_004a70ba:
      *(undefined4 **)(puVar5 + -0x48) = &DAT_01ae0120;
      FUN_006027f0(puVar5 + -0x48,&DAT_008396e4,&DAT_00763c78);
      iVar7 = DAT_008396e4;
      *(int *)(puVar5 + -0x14) = DAT_008396e4;
      DAT_008396dc = 1;
      iVar4 = DAT_008396e4;
      while (DAT_008396e4 = iVar4, 0 < iVar7) {
        iVar7 = DAT_008396dc * 10;
        uVar1 = *(undefined4 *)(iVar7 + 0x1ae0116);
        DAT_00839718._0_2_ = (undefined2)uVar1;
        DAT_00839718._2_1_ = (undefined1)((uint)uVar1 >> 0x10);
        DAT_00839718._3_1_ = (byte)((uint)uVar1 >> 0x18);
        uVar2 = *(uint *)(iVar7 + 0x1ae011a);
        DAT_0083971c = (undefined1)uVar2;
        uRam0083971d = (undefined1)(uVar2 >> 8);
        uRam0083971e = (undefined2)(uVar2 >> 0x10);
        DAT_00839720 = *(undefined2 *)(iVar7 + 0x1ae011e);
        *(uint *)(DAT_008396dc * 4 + 0x8398bc) =
             ((uVar2 & 0xff) + (uint)DAT_00839718._3_1_ * 0x1a) * 10 + -0x55d2;
        DAT_008396dc = DAT_008396dc + 1;
        *(int *)(puVar5 + -0x14) = *(int *)(puVar5 + -0x14) + -1;
        iVar4 = DAT_008396e4;
        iVar7 = *(int *)(puVar5 + -0x14);
      }
      DAT_008396d4 = 0;
      *(int *)(puVar5 + -0x10) = iVar4;
      DAT_008396dc = 1;
      while (0 < iVar4) {
        FUN_004a72c7(DAT_008396dc * 10 + 0x1ae0116,10);
        iVar7 = DAT_008396dc * 10;
        uVar1 = *(undefined4 *)(iVar7 + 0x1ae0116);
        DAT_00839718._0_2_ = (undefined2)uVar1;
        DAT_00839718._2_1_ = (undefined1)((uint)uVar1 >> 0x10);
        DAT_00839718._3_1_ = (byte)((uint)uVar1 >> 0x18);
        uVar3 = *(undefined4 *)(iVar7 + 0x1ae011a);
        DAT_0083971c = (undefined1)uVar3;
        uRam0083971d = (undefined1)((uint)uVar3 >> 8);
        uRam0083971e = (undefined2)((uint)uVar3 >> 0x10);
        DAT_00839720 = *(undefined2 *)(iVar7 + 0x1ae011e);
        DAT_008396f0 = CONCAT13(uRam0083971d,CONCAT12(DAT_0083971c,(short)((uint)uVar1 >> 0x10)));
        *(undefined4 *)(puVar5 + -0xc) = 10;
        DAT_008396d0 = 1;
        do {
          puVar6 = (undefined4 *)(&DAT_01c2cc08 + DAT_008396d0 * 0x18);
          puVar8 = &DAT_008396f6;
          for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar8 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar8 = puVar8 + 1;
          }
          DAT_008396d4 = DAT_008396d4 + 1;
          FUN_005f33c9(puVar5,0x4a723d);
          DAT_008396f0 = CONCAT13(DAT_008396f0._3_1_ + '\x01',(undefined3)DAT_008396f0);
          DAT_008396d0 = DAT_008396d0 + 1;
          *(int *)(puVar5 + -0xc) = *(int *)(puVar5 + -0xc) + -1;
        } while (0 < *(int *)(puVar5 + -0xc));
        *(undefined4 *)(puVar5 + -8) = 0;
        DAT_008396dc = DAT_008396dc + 1;
        *(int *)(puVar5 + -0x10) = *(int *)(puVar5 + -0x10) + -1;
        iVar4 = *(int *)(puVar5 + -0x10);
      }
      DAT_008396e4 = DAT_008396e4 * 10;
      _DAT_008396cc = DAT_008396e4;
      *(undefined4 *)(puVar5 + -4) = 0;
      return;
    }
  }
  *(undefined4 *)(puVar5 + -0x18) = 0;
  goto LAB_004a70ba;
}


