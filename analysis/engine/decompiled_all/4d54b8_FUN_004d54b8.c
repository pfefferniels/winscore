// FUN_004d54b8 @ 004d54b8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d54b8(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  undefined1 *puVar5;
  undefined4 local_e4;
  undefined4 *local_e0;
  undefined4 local_dc;
  char *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 *local_cc;
  undefined *local_c8;
  undefined4 local_c4 [8];
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  int local_5c;
  int local_58;
  int local_4c;
  int local_2c;
  
  puVar5 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  _DAT_008a0380 = 0;
  DAT_008a037c = 0;
  if (DAT_01b11768 == 999) {
    DAT_01b11768 = 0;
    local_a0 = 0;
    local_c4[0] = 0;
    local_70 = FUN_005fc330(local_c4,0x18,0x784ff01,&DAT_00765604,0,&DAT_00793dc8);
    if (local_70 == 0) goto LAB_004d5670;
  }
  else {
    local_a4 = 0;
    if (DAT_01aae360 == 1) {
      local_9c = 0;
    }
    else {
      local_98 = 0;
    }
    if (DAT_0078b6b0 == 1) {
      local_cc = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      local_c8 = (undefined *)(int)ROUND(f_34000 / _DAT_01c60cb2 - DAT_01aae2f8);
      DAT_01aae2f8 = (float)(int)DAT_01aae2f4;
      DAT_008a0378 = DAT_01be6cb0;
      iVar4 = DAT_01be6cac + -0x10a;
      DAT_01be6cac = -DAT_01be6ca8;
      DAT_01be6ca8 = DAT_01be6ca4 + -0x10a;
      DAT_01be6ca4 = -DAT_01be6cb0;
      DAT_01aae2f4 = local_c8;
      DAT_01be6cb0 = iVar4;
    }
    local_c4[0] = 0;
    local_78 = FUN_005fc330(local_c4,0x18,0x784ff01,&DAT_00765604,0,&DAT_00793d94);
    puVar3 = &stack0xfffffffc;
    if (local_78 == 0) {
      local_74 = 0;
LAB_004d5670:
      DAT_008a0374 = 1;
      if ((DAT_0078cbb2 == 0) && (-2 < DAT_008a037c)) {
        local_c4[0] = 0;
        local_cc = &DAT_008a0374;
        local_68 = FUN_005fc330(local_c4,0x18,0x784ff01,&DAT_00765600,&local_cc,&DAT_00793cd0);
        puVar3 = &stack0xfffffffc;
        if (local_68 == 0) {
          local_c4[0] = 0;
          local_cc = (undefined4 *)0x1;
          local_c8 = &DAT_007655fc;
          local_64 = FUN_005fc330(local_c4,0x18,0x784ff01,&DAT_007655f8,&local_cc,&DAT_00793de0);
          puVar3 = &stack0xfffffffc;
          if (local_64 == 0) {
            local_c4[0] = 0;
            FUN_005f7950(local_c4,0x18,0x784ff00,&DAT_007655f4,0);
            local_c4[0] = 0;
            local_e4 = 4;
            local_e0 = &DAT_0078dcc8;
            local_dc = 6;
            local_d8 = "binary";
            local_d4 = 0x200;
            local_d0 = 2;
            local_cc = (undefined4 *)0x4;
            local_5c = FUN_005f6540(local_c4,0x18,0x784ff01,&DAT_007655d4,&local_e4);
            puVar3 = &stack0xfffffffc;
            if (local_5c == 0) {
              local_c4[0] = 0;
              local_cc = (undefined4 *)0x1;
              local_c8 = &DAT_007655fc;
              local_58 = FUN_005fa4d0(local_c4,0x18,0x784ff01,&DAT_007655f8,&local_cc);
              puVar3 = &stack0xfffffffc;
              if (local_58 == 0) {
                local_c4[0] = 0;
                FUN_005f7950(local_c4,0x18,0x784ff00,&DAT_007655f4,0);
                goto LAB_004d589f;
              }
            }
          }
        }
      }
      else {
        local_6c = 0;
LAB_004d589f:
        puVar3 = &stack0xfffffffc;
        if (DAT_01aae360 != 1) {
LAB_004d5f4c:
          if (DAT_01aae300 == 0) {
            *(undefined4 *)(puVar3 + -0xc0) = 0;
            FUN_005f7950(puVar3 + -0xc0,0x18,0x784ff00,&DAT_007655f4,0);
          }
          goto LAB_004d5f93;
        }
        local_c4[0] = 0;
        FUN_005f7950(local_c4,0x1a,0x784ff00,&DAT_007655f4,0);
        local_c4[0] = 0;
        local_4c = FUN_005fc330(local_c4,0x18,0x784ff01,&DAT_00765604,0,&DAT_00793e00);
        puVar3 = &stack0xfffffffc;
        if (local_4c == 0) {
          if (DAT_01aae444 < 1) {
            local_c4[0] = 0;
            local_2c = FUN_005fc330(local_c4,0x18,0x784ff01,&DAT_00765604,0,&DAT_00793e94);
            puVar3 = &stack0xfffffffc;
            if (local_2c != 0) goto LAB_004d5f87;
          }
          else {
            local_cc = DAT_0078b464;
            local_c8 = DAT_0078b468;
            local_c4[0] = 0;
            FUN_005f33c9(&stack0xfffffffc,0x4d5971);
            puVar3 = puVar5;
            FUN_005f33c9(puVar5,0x4d598d);
            *(undefined1 **)(puVar3 + -0xdc) = puVar3 + -0xf8;
            *(undefined4 *)(puVar3 + -0xe0) = 0x14;
            *(undefined4 *)(puVar3 + -0xd8) = 3;
            *(undefined4 *)(puVar3 + -0xd4) = extraout_EDX;
            *(undefined4 *)(puVar3 + -0xd0) = 0x200;
            *(undefined4 *)(puVar3 + -0xcc) = 2;
            uVar1 = FUN_005f6540(puVar3 + -0xc0,0x1a,0x784ff01,&DAT_007655b0,puVar3 + -0xe0);
            *(undefined4 *)(puVar3 + -0x44) = uVar1;
            if (*(int *)(puVar3 + -0x44) != 0) goto LAB_004d5f4c;
            *(undefined4 *)(puVar3 + -0xc0) = 0;
            *(undefined4 *)(puVar3 + -200) = 0x1c;
            *(undefined1 **)(puVar3 + -0xc4) = &DAT_01aae428;
            uVar1 = FUN_005fdbd0(puVar3 + -0xc0,0x1a,0x784ff03,&DAT_007655f8,puVar3 + -200,
                                 &DAT_00793e24);
            *(undefined4 *)(puVar3 + -0x40) = uVar1;
            if ((*(int *)(puVar3 + -0x40) != -1) && (*(int *)(puVar3 + -0x40) == 0)) {
              *(undefined4 *)(puVar3 + -0xc0) = 0;
              *(undefined4 *)(puVar3 + -200) = 0x1c;
              *(undefined1 **)(puVar3 + -0xc4) = &DAT_01aae428;
              uVar1 = FUN_005fc330(puVar3 + -0xc0,0x18,0x784ff01,&DAT_007655f8,puVar3 + -200,
                                   &DAT_00793e38);
              *(undefined4 *)(puVar3 + -0x3c) = uVar1;
              if (*(int *)(puVar3 + -0x3c) != 0) goto LAB_004d5f87;
              if (1 < DAT_01aae444) {
                iVar4 = DAT_01aae444 + -1;
                *(int *)(puVar3 + -0x38) = iVar4;
                DAT_008a0374 = 2;
                while (0 < iVar4) {
                  *(undefined4 *)(puVar3 + -0xc0) = 0;
                  *(undefined4 *)(puVar3 + -200) = 0x1c;
                  *(undefined1 **)(puVar3 + -0xc4) = &DAT_01aae428;
                  uVar1 = FUN_005fdbd0(puVar3 + -0xc0,0x1a,0x784ff03,&DAT_007655f8,puVar3 + -200,
                                       &DAT_00793e64);
                  *(undefined4 *)(puVar3 + -0x34) = uVar1;
                  if ((*(int *)(puVar3 + -0x34) == -1) || (*(int *)(puVar3 + -0x34) != 0)) break;
                  *(undefined4 *)(puVar3 + -0xc0) = 0;
                  *(undefined4 *)(puVar3 + -200) = 0x1c;
                  *(undefined1 **)(puVar3 + -0xc4) = &DAT_01aae428;
                  uVar1 = FUN_005fc330(puVar3 + -0xc0,0x18,0x784ff01,&DAT_007655f8,puVar3 + -200,
                                       &DAT_00793e78);
                  *(undefined4 *)(puVar3 + -0x30) = uVar1;
                  if (*(int *)(puVar3 + -0x30) != 0) goto LAB_004d5f87;
                  DAT_008a0374 = DAT_008a0374 + 1;
                  *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
                  iVar4 = *(int *)(puVar3 + -0x38);
                }
              }
            }
            *(undefined4 *)(puVar3 + -0xc0) = 0;
            *(undefined4 *)(puVar3 + -200) = 6;
            *(char **)(puVar3 + -0xc4) = "delete";
            FUN_005f7950(puVar3 + -0xc0,0x1a,0x784ff00,&DAT_007655a0,puVar3 + -200);
            puVar2 = puVar3;
          }
          *(undefined4 *)(puVar2 + -0xc0) = 0;
          FUN_005f7950(puVar2 + -0xc0,0x18,0x784ff00,&DAT_007655f4,0);
          puVar3 = puVar2;
          FUN_005f34d1(puVar2,0x4d5cc8);
          DAT_008a0374 = 1;
          DAT_0078b4e4 = 0xffffffff;
          uVar1 = FUN_004d5fe1(&DAT_01be6ca4,&DAT_01aae2f4);
          *(undefined4 *)(puVar3 + -200) = uVar1;
          thunk_FUN_004a5f84(puVar3 + -200,&DAT_01aae428,0x1c,&DAT_008a0374);
          uVar1 = FUN_004d5fe1(&DAT_01be6ca8,&DAT_01aae2f8);
          *(undefined4 *)(puVar3 + -200) = uVar1;
          thunk_FUN_004a5f84(puVar3 + -200,&DAT_01aae428,0x1c,&DAT_008a0374);
          DAT_0078b4e4 = 1;
          uVar1 = FUN_004d5fe1(&DAT_01be6cac,&DAT_01aae2f4);
          *(undefined4 *)(puVar3 + -200) = uVar1;
          thunk_FUN_004a5f84(puVar3 + -200,&DAT_01aae428,0x1c,&DAT_008a0374);
          uVar1 = FUN_004d5fe1(&DAT_01be6cb0,&DAT_01aae2f8);
          *(undefined4 *)(puVar3 + -200) = uVar1;
          thunk_FUN_004a5f84(puVar3 + -200,&DAT_01aae428,0x1c,&DAT_008a0374);
          if (DAT_008a0374 < 0x14) {
            iVar4 = 0x14 - DAT_008a0374;
            *(int *)(puVar3 + -0x20) = iVar4;
            while (0 < iVar4) {
              *(undefined1 *)(DAT_008a0374 + 0x1aae427) = 0x20;
              DAT_008a0374 = DAT_008a0374 + 1;
              *(int *)(puVar3 + -0x20) = *(int *)(puVar3 + -0x20) + -1;
              iVar4 = *(int *)(puVar3 + -0x20);
            }
          }
          *(undefined4 *)(puVar3 + -0xc0) = 0;
          *(undefined4 *)(puVar3 + -0x120) = 0x80;
          *(undefined4 **)(puVar3 + -0x11c) = &DAT_0078cb22;
          *(undefined4 *)(puVar3 + -0x118) = 6;
          *(char **)(puVar3 + -0x114) = "DIRECT";
          *(undefined4 *)(puVar3 + -0x110) = 1;
          *(undefined4 *)(puVar3 + -0x10c) = 6;
          *(char **)(puVar3 + -0x108) = "BINARY";
          *(undefined4 *)(puVar3 + -0x104) = 0x200;
          *(undefined4 *)(puVar3 + -0x100) = 2;
          *(undefined4 *)(puVar3 + -0xfc) = 4;
          uVar1 = FUN_005f6540(puVar3 + -0xc0,0x18,0x784ff01,&DAT_0076556c,puVar3 + -0x120);
          *(undefined4 *)(puVar3 + -0x1c) = uVar1;
          if (*(int *)(puVar3 + -0x1c) != 0) {
            thunk_FUN_0054d831("Error opening temp. font name file.",0x23);
            *(undefined4 *)(puVar3 + -4) = 0;
            goto LAB_004d5f93;
          }
          *(undefined4 *)(puVar3 + -0xc0) = 0;
          *(undefined4 *)(puVar3 + -200) = 0x13;
          *(undefined1 **)(puVar3 + -0xc4) = &DAT_01aae428;
          uVar1 = FUN_00603f70(puVar3 + -0xc0,0x18,0x784ff01,&DAT_007655f8,puVar3 + -200,0x81);
          *(undefined4 *)(puVar3 + -0x18) = uVar1;
          if (*(int *)(puVar3 + -0x18) == 0) goto LAB_004d5f4c;
        }
      }
    }
  }
LAB_004d5f87:
  thunk_FUN_004cf1c2();
  *(undefined4 *)(puVar3 + -8) = 0;
LAB_004d5f93:
  OUTPUT_MODE = 1;
  DAT_0078b4e4 = 0;
  if (DAT_008a037c == -1) {
    *(undefined4 *)(puVar3 + -0x10) = 0;
  }
  else {
    _DAT_020b8e40 = 0;
    _DAT_008a0380 = 0;
    *(undefined4 *)(puVar3 + -0xc) = 0;
  }
  return;
}


