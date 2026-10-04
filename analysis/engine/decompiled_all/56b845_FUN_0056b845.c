// FUN_0056b845 @ 0056b845 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056b845(void)

{
  undefined1 *puVar1;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 *local_6c;
  undefined4 local_64 [9];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  puVar1 = &stack0xfffffffc;
  DAT_01a9f350 = DAT_0078b6a0;
  DAT_01a9f300 = DAT_0078b6a0 % 100;
  if (DAT_01a9f300 != 99) {
    if (99 < DAT_0078b6a0) {
      DAT_00791444 = -1;
    }
    if (DAT_0078b6a0 == DAT_00791444) {
      local_40 = 0;
    }
    else {
      _DAT_009a7fc8 = 0;
      if (DAT_0078d8a0 == -1) {
        DAT_009a7fd8 = 0;
        _DAT_009a7fd4 = 0;
        DAT_00791444 = -1;
      }
      else {
        local_3c = 0;
      }
      if (DAT_009a7fd8 == 0) {
        local_38 = 0;
      }
      else if (DAT_009a7fd8 == 10) {
        DAT_009a7fd8 = 0;
      }
      local_64[0] = 0;
      local_74 = 2;
      local_70 = 0x79f8d6;
      local_6c = &DAT_01a9f300;
      FUN_005f34f0(local_64,0x784ff00,&DAT_0076a164,&local_74,&DAT_0079f73c);
      thunk_FUN_004acee1(&DAT_019c682c,0x80,&DAT_009a7fd0);
      puVar1 = &stack0xfffffffc;
      while( true ) {
        FUN_005f46bc(puVar1,0x56b99f);
        FUN_005f46bc(puVar1,0x56b9bb);
        FUN_005f46bc(puVar1,0x56b9d7);
        FUN_005f34d1(puVar1,0x56b9ed);
        *(undefined4 *)(puVar1 + -0x60) = 0;
        *(undefined4 *)(puVar1 + -0x70) = 0x80;
        *(undefined **)(puVar1 + -0x6c) = &DAT_0078b3a0;
        *(uint **)(puVar1 + -0x68) = &DAT_009a7fe0;
        FUN_005f47c0(puVar1 + -0x60,0xffffffff,0x784ff00,&DAT_0076a23c,puVar1 + -0x70);
        if ((DAT_009a7fe0 & 1) != 0) break;
        if (DAT_0079f8d8 == DAT_00791450 && DAT_0079144c == DAT_0079f8d4) {
          *(undefined4 *)(puVar1 + -0x24) = 0;
        }
        else {
          FUN_005f33c9(puVar1,0x56baa5);
          FUN_005f33c9(puVar1,0x56bac1);
          FUN_005f33c9(puVar1,0x56badd);
          FUN_005f34d1(puVar1,0x56baf8);
          *(undefined4 *)(puVar1 + -0x60) = 0;
          *(undefined4 *)(puVar1 + -0x70) = 4;
          *(undefined4 *)(puVar1 + -0x6c) = 0x20b90a5;
          *(int **)(puVar1 + -0x68) = &ITEM_I;
          FUN_005f34f0(puVar1 + -0x60,0x784ff00,&DAT_0076a164,puVar1 + -0x70,&DAT_0079f750);
          thunk_FUN_0054d831(&DAT_020b90a0,0x200);
        }
        DAT_0079144c = DAT_0079f8d4;
        DAT_00791450 = DAT_0079f8d8;
        DAT_00791440 = DAT_009a7fd8;
        DAT_0079f8d4 = 0x30306d66;
        DAT_0079f8d8 = 0x746d662e;
        *(undefined4 *)(puVar1 + -0x1c) = 0;
      }
      *(undefined4 *)(puVar1 + -0x28) = 0;
      DAT_01a9f304 = 0x1f;
      thunk_FUN_00498826(&DAT_0078b3a0,0x80,&DAT_01a9f304,&DAT_0076a200,&DAT_0076a1e0);
      if (DAT_01a9f304 < 0) {
        *(undefined4 *)(puVar1 + -0x18) = 0;
      }
      else {
        DAT_009a7fd8 = 1;
        DAT_0078d8a0 = DAT_01a9f300;
        if (99 < DAT_01a9f350) {
          DAT_0078d8a0 = -1;
        }
        FUN_005f34d1(puVar1,0x56bc4e);
        *(undefined4 *)(puVar1 + -0x60) = 0;
        *(undefined4 *)(puVar1 + -0x70) = 0x1c;
        *(undefined **)(puVar1 + -0x6c) = &DAT_01cac242 + DAT_009a7fd8 * 0x1e;
        *(undefined4 *)(puVar1 + -0x68) = 0x1c;
        FUN_005f8240(puVar1 + -0x60,0x1f,0x784ff00,&DAT_0076a1f8,puVar1 + -0x70);
        *(undefined4 *)(puVar1 + -0x68) = 0x1c;
        *(undefined1 **)(puVar1 + -100) = &DAT_01a1ace0;
        FUN_005f8730(puVar1 + -0x60,&DAT_0076a1f4,puVar1 + -0x68);
        DAT_00791440 = 0xa3;
        *(undefined4 *)(puVar1 + -0x78) = 1;
        *(int *)(puVar1 + -0x74) = DAT_009a7fd8 * 0x144 + 0x1be5dfc;
        *(undefined4 *)(puVar1 + -0x70) = 1;
        *(undefined4 *)(puVar1 + -0x6c) = 0xa2;
        *(undefined4 *)(puVar1 + -0x68) = 2;
        FUN_005f8730(puVar1 + -0x60,&DAT_0076a1f0,puVar1 + -0x78);
        *(undefined **)(puVar1 + -0x68) = &DAT_009a7fdc;
        FUN_005f8730(puVar1 + -0x60,&DAT_0076a1ec,puVar1 + -0x68);
        *(undefined4 *)(puVar1 + -0x10) = 0xa2;
        DAT_00791440 = 1;
        do {
          *(int *)(puVar1 + -100) =
               (int)*(short *)(&DAT_01be5dfa + DAT_009a7fd8 * 0x144 + DAT_00791440 * 2);
          DAT_01a9f308 = (float)*(int *)(puVar1 + -100);
          *(float *)(&DAT_01cac100 + DAT_00791440 * 4 + DAT_009a7fd8 * 0x288) = DAT_01a9f308 / f_638
          ;
          DAT_00791440 = DAT_00791440 + 1;
          *(int *)(puVar1 + -0x10) = *(int *)(puVar1 + -0x10) + -1;
        } while (0 < *(int *)(puVar1 + -0x10));
        DAT_00791440 = 0xa3;
        *(undefined4 *)(puVar1 + -0x60) = 0;
        *(undefined4 *)(puVar1 + -0x78) = 1;
        *(int *)(puVar1 + -0x74) = DAT_009a7fd8 * 0x144 + 0x1be5dfc;
        *(undefined4 *)(puVar1 + -0x70) = 1;
        *(undefined4 *)(puVar1 + -0x6c) = 0xa2;
        *(undefined4 *)(puVar1 + -0x68) = 2;
        FUN_005f8240(puVar1 + -0x60,0x1f,0x784ff00,&DAT_0076a1f0,puVar1 + -0x78);
        *(undefined **)(puVar1 + -0x68) = &DAT_009a7fdc;
        FUN_005f8730(puVar1 + -0x60,&DAT_0076a1ec,puVar1 + -0x68);
        *(undefined4 *)(puVar1 + -0x60) = 0;
        FUN_005f7950(puVar1 + -0x60,0x1f,0x784ff00,&DAT_0076a1e4,0);
        DAT_00791440 = DAT_009a7fd8;
        DAT_00791444 = DAT_01a9f350;
      }
    }
    if ((OUTPUT_MODE != 0) && (P7 != f_0)) {
      thunk_FUN_0056f33e(&DAT_009a7fc8);
    }
    *(undefined4 *)(puVar1 + -4) = 0;
  }
  return;
}


