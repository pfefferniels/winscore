// FUN_0054b79d @ 0054b79d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054b79d(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 local_c4;
  char *local_c0;
  undefined4 local_bc;
  char *local_b8;
  int *local_b4;
  uint local_b0;
  int local_ac;
  undefined4 local_a8 [18];
  undefined4 local_60;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  if (DAT_020b8ea0._1_1_ == 'A') {
    thunk_FUN_004e5543(&DAT_020b90a0,0x200,&DAT_007692b8,&DAT_009a22b0);
    return;
  }
  if (DAT_020b8ea0._1_1_ == 'G') {
    thunk_FUN_00579770(&DAT_00769454,1,&IP1);
    DAT_009a22a8 = IP1;
  }
  else {
    if (DAT_020b8ea0._1_1_ == 'J') {
      local_a8[0] = 0;
      local_bc = 0x200;
      local_b8 = &DAT_020b90a0;
      local_b4 = &VIEW_DY;
      FUN_005f34f0(local_a8,0x784ff00,&DAT_0076915c,&local_bc,&DAT_007976a0);
      FUN_0054946a(&DAT_020b90a0,0x200);
      FUN_0054943a();
      return;
    }
    if (DAT_020b8ea0._1_1_ == 'M') {
      return;
    }
    if (DAT_020b8ea0._1_1_ != 'O') {
      if (DAT_020b8ea0._1_1_ == 'P') {
        local_b0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        DAT_009a22ac = (int)ROUND(P2);
        local_ac = DAT_009a22ac;
      }
      else {
        if (DAT_020b8ea0._1_1_ != 'S') {
          if (DAT_020b8ea0._1_1_ == 'U') {
            local_b0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
            VIEW_DY = (int)ROUND(P2);
            local_ac = VIEW_DY;
            draw_items();
            return;
          }
          if (DAT_020b8ea0._1_1_ == 'X') {
            DAT_009ae4bc = 1;
            FUN_005f33c9(&stack0xfffffffc,0x54bb60);
            FUN_005f34d1(puVar4,0x54bb7b);
            puVar2 = (undefined4 *)&DAT_020b8ea0;
            puVar3 = (undefined4 *)&DAT_020b90a0;
            for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            }
            do {
              FUN_0054943a();
              FUN_0054974f(&DAT_020b90a0,0x200,&DAT_00769440);
              *(undefined4 *)(puVar4 + -0x50) = 0x200;
              DAT_009a22a8 = 1;
              while ((&DAT_020b8e9f)[DAT_009a22a8] != '\0') {
                if ((&DAT_020b8e9f)[DAT_009a22a8] == '\r') {
                  *(undefined4 *)(puVar4 + -0x44) = 0;
                  goto LAB_0054bc41;
                }
                *(undefined4 *)(puVar4 + -0x48) = 0;
                *(undefined4 *)(puVar4 + -0x40) = 0;
                DAT_009a22a8 = DAT_009a22a8 + 1;
                *(int *)(puVar4 + -0x50) = *(int *)(puVar4 + -0x50) + -1;
                if (*(int *)(puVar4 + -0x50) < 1) {
LAB_0054bc41:
                  DAT_009ae4bc = 0;
                  puVar2 = (undefined4 *)&DAT_020b8ea0;
                  puVar3 = &DAT_009ae2bc;
                  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
                    *puVar3 = *puVar2;
                    puVar2 = puVar2 + 1;
                    puVar3 = puVar3 + 1;
                  }
                  *(undefined4 *)(puVar4 + -0x3c) = 0;
                  return;
                }
              }
              puVar2 = (undefined4 *)&DAT_020b8ea0;
              puVar3 = (undefined4 *)&DAT_020b90a0;
              for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
                *puVar3 = *puVar2;
                puVar2 = puVar2 + 1;
                puVar3 = puVar3 + 1;
              }
              *(undefined4 *)(puVar4 + -0x4c) = 0;
            } while( true );
          }
          goto LAB_0054bc68;
        }
        local_b0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_ac = (int)ROUND(P2);
        DAT_009a22ac = local_ac;
        if (P2 == f_0) {
          DAT_009a22ac = 0x4a8;
        }
        _DAT_009a22b4 = 0x2000;
        _DAT_009a22b8 = DAT_009a22ac;
        _DAT_009a22bc = 1000;
        _DAT_009a22c0 = 1000;
        _DAT_009a22c4 = 100;
        _DAT_009a22c8 = 0x96;
        thunk_FUN_00579770(&DAT_0076927c,1,&DAT_009a22b4);
        if (DAT_020b8ea2 != 'P') {
          return;
        }
        local_60 = 0;
      }
      _DAT_009a22b4 = 0;
      _DAT_009a22b8 = DAT_009a22ac;
      thunk_FUN_00579770(&DAT_00769278,1,&DAT_009a22b4);
      return;
    }
    P1 = f_0;
    P2 = f_0;
    IP1 = 0;
    IP2 = 0;
    thunk_FUN_00579770(&DAT_00769450,1,&IP1);
  }
LAB_0054bc68:
  if (P3 == f_1) {
    FUN_005f33c9(&stack0xfffffffc,0x54bc9d);
    FUN_005f34d1(puVar5,0x54bcb8);
    FUN_005f33c9(puVar5,0x54bcda);
    FUN_005f34d1(puVar5,0x54bcf5);
    FUN_0054946a(&DAT_020b90a0,0x200);
    *(undefined4 *)(puVar5 + -0x38) = 0;
  }
  else if (P3 == f_2) {
    FUN_005f33c9(&stack0xfffffffc,0x54bd4b);
    FUN_005f34d1(puVar6,0x54bd66);
    FUN_005f33c9(puVar6,0x54bd88);
    FUN_005f34d1(puVar6,0x54bda3);
    FUN_005494b2(&DAT_020b90a0,0x200,&DAT_0076937c);
    *(undefined4 *)(puVar6 + -0x34) = 0;
  }
  else {
    local_a8[0] = 0;
    local_c4 = 7;
    local_c0 = "textpos";
    local_bc = 6;
    local_b8 = "binary";
    local_b4 = (int *)0x2;
    local_b0 = 4;
    FUN_005f6540(local_a8,0x15,0x784ff00,&DAT_007693e0,&local_c4);
    DAT_009a22a4 = 0;
    DAT_009a22ac = 1;
    for (local_30 = ITEM_I; 0 < local_30; local_30 = local_30 + -1) {
      if ((float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_009a22ac]] == f_8) {
        local_2c = 0;
      }
      else {
        DAT_009a22a0 = *(int *)(&DAT_020a559c + DAT_009a22ac * 4);
        DAT_009a229c = (&DAT_020a55a0)[DAT_009a22ac];
        iVar1 = DAT_009a22a0;
        if (DAT_009a229c == DAT_009a22a0) {
          local_28 = 0;
        }
        else {
          while (DAT_009a2298 = iVar1,
                *(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2298 * DAT_01fbb83c
                         ) != '\0') {
            local_24 = 0;
            DAT_009a2298 = DAT_009a2298 + 1;
            if (DAT_009a229c <= DAT_009a2298) goto LAB_0054c040;
            local_14 = 0;
            iVar1 = DAT_009a2298;
          }
          local_20 = 4;
          DAT_009a2294 = 1;
          do {
            DAT_009a2298 = DAT_009a2298 + 1;
            puVar4 = (undefined1 *)((int)&DAT_01e99980 + DAT_009a22a4);
            DAT_009a22a4 = DAT_009a22a4 + 1;
            *puVar4 = *(undefined1 *)
                       ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2298 * DAT_01fbb83c);
            DAT_009a2294 = DAT_009a2294 + 1;
            local_20 = local_20 + -1;
          } while (0 < local_20);
          DAT_009a2298 = DAT_009a2298 + 0x15;
          while( true ) {
            puVar4 = (undefined1 *)((int)&DAT_01e99980 + DAT_009a22a4);
            DAT_009a22a4 = DAT_009a22a4 + 1;
            *puVar4 = *(undefined1 *)
                       ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_009a2298 * DAT_01fbb83c);
            DAT_009a2298 = DAT_009a2298 + 1;
            if (DAT_009a229c <= DAT_009a2298) break;
            local_1c = 0;
          }
          local_18 = 0;
        }
      }
LAB_0054c040:
      local_10 = 0;
      DAT_009a22ac = DAT_009a22ac + 1;
    }
    local_a8[0] = 0;
    local_b4 = &DAT_009a22a4;
    FUN_005fa4d0(local_a8,0x15,0x784ff00,&DAT_007693dc,&local_b4);
    local_c0 = (char *)&DAT_01e99980;
    local_b8 = (char *)DAT_009a22a4;
    if (DAT_009a22a4 < 0) {
      local_b8 = (char *)0x0;
    }
    DAT_009a22a8 = (int)local_b8 + 1;
    local_c4 = 1;
    local_bc = 1;
    local_b4 = (int *)0x1;
    FUN_005fa9f0(local_a8,&DAT_007693d8,&local_c4);
    local_a8[0] = 0;
    FUN_005f7950(local_a8,0x15,0x784ff00,&DAT_0076939c,0);
  }
  return;
}


