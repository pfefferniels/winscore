// FUN_004abc64 @ 004abc64 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004abc64(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 local_94;
  char *local_90;
  undefined4 *local_8c;
  undefined2 *local_88;
  undefined4 local_84 [9];
  undefined4 local_60;
  
  puVar2 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  DAT_0088d7dc = 8;
  local_84[0] = 0;
  FUN_005f7950(local_84,8,0x784ff00,&DAT_00763c88,0);
  thunk_FUN_00498826(s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0,0x80,&DAT_0088d7dc,&DAT_00763d50,
                     &DAT_00763d50);
  if (DAT_0088d7dc < 0) {
    local_60 = 0;
  }
  else {
    DAT_02052740 = 8;
    local_84[0] = 0;
    local_8c = &DAT_0078b474;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f18,&local_8c,&DAT_00791ce8);
    local_8c = (undefined4 *)(DAT_0078b470 * f_100);
    local_84[0] = 0;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f54,&local_8c,&DAT_00791d04);
    local_84[0] = 0;
    local_8c = &DAT_0078b478;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f18,&local_8c,&DAT_00791d20);
    local_84[0] = 0;
    local_8c = &DAT_0078b4a4;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f18,&local_8c,&DAT_00791d3c);
    local_84[0] = 0;
    local_8c = &DAT_0078b48c;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f1c,&local_8c,&DAT_00791d58);
    DAT_0088d7d8 = DAT_0078b4a8 / 0xc + -1;
    DAT_0088d7e6 = DAT_00763f52;
    DAT_0088d7e4 = CONCAT11((char)DAT_0088d7d8 + '0',(char)DAT_00763f50);
    local_84[0] = 0;
    local_8c = (undefined4 *)0x3;
    local_88 = &DAT_0088d7e4;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763d88,&local_8c,&DAT_00791d74);
    local_90 = s_INCHESMETRIC_0079218e + DAT_0078b4e8 * 6;
    local_84[0] = 0;
    local_94 = 6;
    local_8c = (undefined4 *)0x6;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763c8c,&local_94,&DAT_00791d94);
    local_84[0] = 0;
    local_8c = &DAT_0078b488;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f1c,&local_8c,&DAT_00791da8);
    local_8c = (undefined4 *)(_DAT_0078ded4 * _DAT_0078ded8);
    local_84[0] = 0;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f54,&local_8c,&DAT_00791dc8);
    local_84[0] = 0;
    local_8c = &DAT_0078b4a0;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f18,&local_8c,&DAT_00791de4);
    local_84[0] = 0;
    local_8c = &DAT_0078b490;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f1c,&local_8c,&DAT_00791e04);
    local_84[0] = 0;
    local_8c = &DAT_0078b494;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f1c,&local_8c,&DAT_00791e20);
    local_84[0] = 0;
    local_8c = &DAT_0078b498;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f1c,&local_8c,&DAT_00791e3c);
    local_84[0] = 0;
    local_8c = &DAT_0078b49c;
    FUN_005fc330(local_84,8,0x784ff00,&DAT_00763f1c,&local_8c,&DAT_00791e58);
    DAT_0088d7d4 = DAT_0078b4c0 + 1;
    FUN_005f46bc(&stack0xfffffffc,0x4ac109);
    FUN_005f34d1(puVar2,0x4ac11f);
    FUN_004abb46(&DAT_019c68ac,0x80,&DAT_0078b4c0,&DAT_00763d50);
    DAT_0088d7d4 = DAT_0078b4c4 + 1;
    FUN_005f46bc(puVar2,0x4ac18d);
    FUN_005f34d1(puVar2,0x4ac1a3);
    FUN_004abb46(&DAT_019c682c,0x80,&DAT_0078b4c4,&DAT_00763c94);
    iVar1 = FUN_00601a30(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar2,0x4ac20b);
      FUN_005f34d1(puVar2,0x4ac226);
    }
    puVar3 = puVar2;
    FUN_005f33c9(puVar2,0x4ac248);
    DAT_0088d7d0 = FUN_005ff950(puVar3 + -0x110,0x80);
    FUN_004abb46(&DAT_009af53c,0x80,&DAT_0088d7d0,&DAT_00763f20);
    *(undefined4 *)(puVar3 + -0x80) = 0;
    *(undefined4 **)(puVar3 + -0x88) = &DAT_0078df00;
    FUN_005fc330(puVar3 + -0x80,8,0x784ff00,&DAT_00763f18,puVar3 + -0x88,&DAT_00791e74);
    *(undefined4 *)(puVar3 + -0x80) = 0;
    *(undefined4 **)(puVar3 + -0x88) = &DAT_0078df04;
    FUN_005fc330(puVar3 + -0x80,8,0x784ff00,&DAT_00763f18,puVar3 + -0x88,&DAT_00791e94);
    DAT_0088d7cc = DAT_01fbb6f8;
    if (DAT_01fbb6f8 < 0) {
      DAT_0088d7cc = 0;
    }
    *(undefined4 *)(puVar3 + -0x80) = 0;
    *(int **)(puVar3 + -0x88) = &DAT_0088d7cc;
    FUN_005fc330(puVar3 + -0x80,8,0x784ff00,&DAT_00763f18,puVar3 + -0x88,&DAT_00791eb4);
    if (_DAT_0078dc80 < f_5) {
      _DAT_0078dc80 = f_5_01;
    }
    *(undefined4 *)(puVar3 + -0x80) = 0;
    *(undefined **)(puVar3 + -0x88) = &DAT_0078dc80;
    FUN_005fc330(puVar3 + -0x80,8,0x784ff00,&DAT_00763f1c,puVar3 + -0x88,&DAT_00791ed4);
    *(undefined4 *)(puVar3 + -0x80) = 0;
    *(int **)(puVar3 + -0x88) = &PAPER;
    FUN_005fc330(puVar3 + -0x80,8,0x784ff00,&DAT_00763f18,puVar3 + -0x88,&DAT_00791ef4);
    *(undefined4 *)(puVar3 + -0x80) = 0;
    *(undefined4 *)(puVar3 + -0x88) = 1;
    *(undefined1 **)(puVar3 + -0x84) = &DAT_0078b390;
    FUN_005fc330(puVar3 + -0x80,8,0x784ff00,&DAT_00763d88,puVar3 + -0x88,&DAT_00791f14);
    DAT_0088d7d0 = DAT_0078dc84 / 1000;
    DAT_0088d7c8 = (DAT_0078dc84 % 1000) / 100;
    DAT_0088d7c4 = (DAT_0078dc84 % 100) / 10;
    DAT_0088d7d8 = DAT_0078dc84 % 10;
    DAT_0088d7cc = DAT_0088d7c8 * 30000 + DAT_0088d7d0 * 2000000 + DAT_0088d7c4 * 500 +
                   DAT_0088d7d8 * 8;
    DAT_0078dc84 = DAT_0078dc84 + 5000000;
    *(undefined4 *)(puVar3 + -0x80) = 0;
    *(int **)(puVar3 + -0x88) = &DAT_0088d7cc;
    FUN_005fc330(puVar3 + -0x80,8,0x784ff00,&DAT_00763f18,puVar3 + -0x88,&DAT_00791f34);
  }
  *(undefined4 *)(puVar3 + -0x80) = 0;
  FUN_005f7950(puVar3 + -0x80,DAT_02052740,0x784ff00,&DAT_00763c88,0);
  DAT_02052740 = 0;
  return;
}


