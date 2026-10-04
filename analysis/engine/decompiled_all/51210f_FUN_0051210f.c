// FUN_0051210f @ 0051210f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x005122bb) */
/* WARNING: Removing unreachable block (ram,0x0051232f) */

void FUN_0051210f(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  undefined2 in_FPUControlWord;
  
  puVar4 = &stack0xfffffffc;
  IP2 = (int)ROUND(P2);
  IP3 = (int)ROUND(P3);
  FUN_005f33c9(&stack0xfffffffc,0x5121b7);
  FUN_005f34d1(puVar4,0x5121d2);
  if (DAT_020b8ea4 == ' ') {
    *(undefined4 *)(puVar4 + -0x8c) = 0;
  }
  else {
    FUN_005f33c9(puVar4,0x512212);
    DAT_01a9f304 = FUN_005ff950(puVar4 + -0x100,0x31);
    FUN_005f46bc(puVar4,0x512261);
    FUN_005f34d1(puVar4,0x512277);
    DAT_01a9f300 = DAT_01a9f304;
    iVar3 = (5 - DAT_01a9f304) / -1;
    *(int *)(puVar4 + -0x88) = iVar3;
    while (0 < iVar3) {
      iVar3 = FUN_005f4660(0x20);
      if (iVar3 != 0) {
        *(undefined4 *)(puVar4 + -0x84) = 0;
        goto LAB_0051236b;
      }
      DAT_01a9f300 = DAT_01a9f300 + -1;
      *(int *)(puVar4 + -0x88) = *(int *)(puVar4 + -0x88) + -1;
      iVar3 = *(int *)(puVar4 + -0x88);
    }
    FUN_005f46bc(puVar4,0x512351);
    FUN_005f34d1(puVar4,0x512367);
LAB_0051236b:
    *(undefined4 *)(puVar4 + -0xac) = 0;
    *(undefined4 *)(puVar4 + -0xc0) = 0x80;
    *(undefined **)(puVar4 + -0xbc) = &DAT_00941ff4;
    *(int **)(puVar4 + -0xb8) = &DAT_01a9f300;
    FUN_005f47c0(puVar4 + -0xac,0xffffffff,0x784ff00,&DAT_00767650,puVar4 + -0xc0);
    if (DAT_01a9f300 == 0) {
      *(undefined4 *)(puVar4 + -0x7c) = 0;
    }
    else {
      FUN_005f33c9(puVar4,0x5123f0);
      FUN_005f34d1(puVar4,0x51240b);
      (&DAT_020b90c6)[DAT_01a9f304] = 0;
      iVar3 = thunk_FUN_00579410(&DAT_0076764c);
      if (iVar3 == 0) {
        *(undefined4 *)(puVar4 + -0x78) = 0;
        return;
      }
    }
  }
  *(undefined4 *)(puVar4 + -0x74) = 0;
  *(undefined4 *)(puVar4 + -0xac) = 0;
  *(undefined4 *)(puVar4 + -0xc0) = 0x80;
  *(undefined **)(puVar4 + -0xbc) = &DAT_00941ff4;
  *(undefined4 *)(puVar4 + -0xb8) = 2;
  *(undefined4 *)(puVar4 + -0xb4) = 4;
  uVar2 = FUN_005f6540(puVar4 + -0xac,0x14,0x784ff01,&DAT_00767584,puVar4 + -0xc0);
  *(undefined4 *)(puVar4 + -0x70) = uVar2;
  if (*(int *)(puVar4 + -0x70) == 0) {
    if (DAT_020b8ea2 == 'Z') {
      *(undefined4 *)(puVar4 + -0xac) = 0;
      *(int **)(puVar4 + -0xb8) = &ITEM_WORDS;
      FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_00767648,puVar4 + -0xb8,&DAT_007965e0);
      iVar3 = ITEM_I;
      if (ITEM_I < 0) {
        iVar3 = 0;
      }
      DAT_01a9f300 = iVar3 + 1;
      *(undefined4 *)(puVar4 + -0xac) = 0;
      *(undefined4 *)(puVar4 + -200) = 1;
      *(undefined4 **)(puVar4 + -0xc4) = &DAT_02091d20;
      *(undefined4 *)(puVar4 + -0xc0) = 1;
      *(int *)(puVar4 + -0xbc) = iVar3;
      *(undefined4 *)(puVar4 + -0xb8) = 4;
      FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_00767644,puVar4 + -200,&DAT_007965f4);
    }
    else {
      *(undefined4 *)(puVar4 + -0x6c) = 0;
    }
    if (IP2 == 0) {
      IP2 = 1;
    }
    if (IP3 == 0) {
      IP3 = ITEM_I;
    }
    if (DAT_020b8ea2 == 'Z') {
      DAT_020b8ea2 = DAT_00767640;
    }
    iVar3 = (IP3 - IP2) + 1;
    *(int *)(puVar4 + -0x60) = iVar3;
    DAT_01a9f300 = IP2;
    while (0 < iVar3) {
      iVar3 = (&ITEM_PTR0)[DAT_01a9f300];
      DAT_01a9f304 = iVar3 + 1;
      fVar1 = (float)(&ITEM_LEN)[DAT_01a9f304];
      *(undefined2 *)(puVar4 + -0xb4) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0xb2) = (ushort)*(undefined4 *)(puVar4 + -0xb4) | 0xc00;
      *(int *)(puVar4 + -0xb0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb4);
      DAT_01a9f30c = *(int *)(puVar4 + -0xb0);
      DAT_01a9f308 = iVar3 + 0xc;
      if (((DAT_01a9f30c == 0xb) || (DAT_01a9f30c == 0xf)) || (DAT_01a9f30c == 0x10)) {
        DAT_01a9f310 = DAT_01a9f304 * 4 + 0x31;
        if ((DAT_01a9f30c == 0x10) && ((float)(&ITEM_P13)[DAT_01a9f304] == f_m1)) {
          DAT_01a9f310 = DAT_01a9f304 * 4 + 0x3d;
        }
        DAT_01a9f314 = 5;
        if ((DAT_01a9f30c == 0xf) || (DAT_01a9f30c == 0xb)) {
          DAT_01a9f314 = 0x40;
        }
        if (DAT_01a9f30c == 0x10) {
          fVar1 = (float)(&ITEM_LEN)[DAT_01a9f308];
          *(undefined2 *)(puVar4 + -0xb4) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0xb2) = (ushort)*(undefined4 *)(puVar4 + -0xb4) | 0xc00;
          *(int *)(puVar4 + -0xb0) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb4);
          DAT_01a9f314 = *(int *)(puVar4 + -0xb0);
        }
        DAT_01a9f314 = DAT_01a9f314 + DAT_01a9f310 + -1;
        DAT_01a9f304 = iVar3 + 2;
        iVar3 = -DAT_01a9f314 / -1;
        *(int *)(puVar4 + -0x58) = iVar3;
        while (0 < iVar3) {
          bVar8 = iVar3 == 0;
          bVar7 = false;
          iVar3 = 1;
          pbVar5 = (byte *)((int)&ITEM_LEN + DAT_01a9f314 + 3);
          pbVar6 = (byte *)&DAT_00767640;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pbVar5 < *pbVar6;
            bVar8 = *pbVar5 == *pbVar6;
            pbVar5 = pbVar5 + 1;
            pbVar6 = pbVar6 + 1;
          } while (bVar8);
          if (!bVar7 && !bVar8) {
            *(undefined4 *)(puVar4 + -0x54) = 0;
            break;
          }
          DAT_01a9f314 = DAT_01a9f314 + -1;
          *(int *)(puVar4 + -0x58) = *(int *)(puVar4 + -0x58) + -1;
          iVar3 = *(int *)(puVar4 + -0x58);
        }
        DAT_01a9f318 = DAT_01a9f314;
        if (DAT_01a9f30c == 0xf) {
          if (DAT_020b8ea2 == ' ') {
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(int **)(puVar4 + -0xb8) = &DAT_01a9f300;
            FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076763c,puVar4 + -0xb8,&DAT_007963e8);
            *(undefined4 *)(puVar4 + -0xc0) = 5;
            *(int *)(puVar4 + -0xbc) = *(int *)(puVar4 + 8) + 0x46;
            *(undefined4 *)(puVar4 + -0xb8) = 5;
            FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
            iVar3 = DAT_01a9f308 - DAT_01a9f304;
            if (iVar3 < 0) {
              iVar3 = 0;
            }
            DAT_01a9f318 = DAT_01a9f304 + iVar3;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar3;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            FUN_005fc980(puVar4 + -0xac,&DAT_0076762c,puVar4 + -200);
            FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
            DAT_01a9f318 = DAT_01a9f310;
            for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
              *(undefined4 *)(puVar4 + -0xb8) = 1;
              FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              DAT_01a9f318 = DAT_01a9f318 + 1;
            }
            FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
          }
          if (DAT_020b8ea2 != ' ') {
            iVar3 = DAT_01a9f308 - DAT_01a9f304;
            if (iVar3 < 0) {
              iVar3 = 0;
            }
            DAT_01a9f318 = DAT_01a9f304 + iVar3;
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar3;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076762c,puVar4 + -200,&DAT_0079610c);
            FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
            DAT_01a9f318 = DAT_01a9f310;
            for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
              *(undefined4 *)(puVar4 + -0xb8) = 1;
              FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              DAT_01a9f318 = DAT_01a9f318 + 1;
            }
            FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
          }
          *(undefined4 *)(puVar4 + -0x48) = 0;
        }
        else if (DAT_01a9f30c == 0xb) {
          if (DAT_020b8ea2 == ' ') {
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(int **)(puVar4 + -0xb8) = &DAT_01a9f300;
            FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076763c,puVar4 + -0xb8,&DAT_00796368);
            *(undefined4 *)(puVar4 + -0xc0) = 5;
            *(int *)(puVar4 + -0xbc) = *(int *)(puVar4 + 8) + 0x46;
            *(undefined4 *)(puVar4 + -0xb8) = 5;
            FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
            iVar3 = DAT_01a9f308 - DAT_01a9f304;
            if (iVar3 < 0) {
              iVar3 = 0;
            }
            DAT_01a9f318 = DAT_01a9f304 + iVar3;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar3;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            FUN_005fc980(puVar4 + -0xac,&DAT_0076762c,puVar4 + -200);
            FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
            DAT_01a9f318 = DAT_01a9f310;
            for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
              *(undefined4 *)(puVar4 + -0xb8) = 1;
              FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              DAT_01a9f318 = DAT_01a9f318 + 1;
            }
            FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
          }
          if (DAT_020b8ea2 != ' ') {
            iVar3 = DAT_01a9f308 - DAT_01a9f304;
            if (iVar3 < 0) {
              iVar3 = 0;
            }
            DAT_01a9f318 = DAT_01a9f304 + iVar3;
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar3;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076762c,puVar4 + -200,&DAT_007960c8);
            FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
            DAT_01a9f318 = DAT_01a9f310;
            for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
              *(undefined4 *)(puVar4 + -0xb8) = 1;
              FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              DAT_01a9f318 = DAT_01a9f318 + 1;
            }
            FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
          }
          *(undefined4 *)(puVar4 + -0x3c) = 0;
        }
        else {
          if ((DAT_01a9f30c == 0x10) && (*(float *)(&ITEM_P12 + DAT_01a9f304 * 4) == f_m1)) {
            (&ITEM_P13)[DAT_01a9f304] = f_0;
            if (DAT_020b8ea2 == ' ') {
              *(undefined4 *)(puVar4 + -0xac) = 0;
              *(int **)(puVar4 + -0xb8) = &DAT_01a9f300;
              FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076763c,puVar4 + -0xb8,&DAT_00796468)
              ;
              *(undefined4 *)(puVar4 + -0xc0) = 5;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f30c * 5 + *(int *)(puVar4 + 8) + -5;
              *(undefined4 *)(puVar4 + -0xb8) = 5;
              FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              iVar3 = (DAT_01a9f308 - DAT_01a9f304) + 5;
              if (iVar3 < 0) {
                iVar3 = 0;
              }
              DAT_01a9f318 = DAT_01a9f304 + iVar3;
              *(undefined4 *)(puVar4 + -200) = 1;
              *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = iVar3;
              *(undefined4 *)(puVar4 + -0xb8) = 4;
              FUN_005fc980(puVar4 + -0xac,&DAT_0076762c,puVar4 + -200);
              FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
              DAT_01a9f318 = DAT_01a9f310;
              for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
                *(undefined4 *)(puVar4 + -0xc0) = 1;
                *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
                *(undefined4 *)(puVar4 + -0xb8) = 1;
                FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
                DAT_01a9f318 = DAT_01a9f318 + 1;
              }
              FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
            }
            if (DAT_020b8ea2 != ' ') {
              iVar3 = (DAT_01a9f308 - DAT_01a9f304) + 5;
              if (iVar3 < 0) {
                iVar3 = 0;
              }
              DAT_01a9f318 = DAT_01a9f304 + iVar3;
              *(undefined4 *)(puVar4 + -0xac) = 0;
              *(undefined4 *)(puVar4 + -200) = 1;
              *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = iVar3;
              *(undefined4 *)(puVar4 + -0xb8) = 4;
              FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076762c,puVar4 + -200,&DAT_00796150);
              FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
              DAT_01a9f318 = DAT_01a9f310;
              for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
                *(undefined4 *)(puVar4 + -0xc0) = 1;
                *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
                *(undefined4 *)(puVar4 + -0xb8) = 1;
                FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
                DAT_01a9f318 = DAT_01a9f318 + 1;
              }
              FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
            }
          }
          else {
            if (DAT_020b8ea2 == ' ') {
              *(undefined4 *)(puVar4 + -0xac) = 0;
              *(int **)(puVar4 + -0xb8) = &DAT_01a9f300;
              FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076763c,puVar4 + -0xb8,&DAT_007964e8)
              ;
              *(undefined4 *)(puVar4 + -0xc0) = 5;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f30c * 5 + *(int *)(puVar4 + 8) + -5;
              *(undefined4 *)(puVar4 + -0xb8) = 5;
              FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              iVar3 = DAT_01a9f308 - DAT_01a9f304;
              if (iVar3 < 0) {
                iVar3 = 0;
              }
              DAT_01a9f318 = DAT_01a9f304 + iVar3;
              *(undefined4 *)(puVar4 + -200) = 1;
              *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = iVar3;
              *(undefined4 *)(puVar4 + -0xb8) = 4;
              FUN_005fc980(puVar4 + -0xac,&DAT_0076762c,puVar4 + -200);
              FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
              DAT_01a9f318 = DAT_01a9f310;
              for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
                *(undefined4 *)(puVar4 + -0xc0) = 1;
                *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
                *(undefined4 *)(puVar4 + -0xb8) = 1;
                FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
                DAT_01a9f318 = DAT_01a9f318 + 1;
              }
              FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
            }
            if (DAT_020b8ea2 != ' ') {
              iVar3 = DAT_01a9f308 - DAT_01a9f304;
              if (iVar3 < 0) {
                iVar3 = 0;
              }
              DAT_01a9f318 = DAT_01a9f304 + iVar3;
              *(undefined4 *)(puVar4 + -0xac) = 0;
              *(undefined4 *)(puVar4 + -200) = 1;
              *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
              *(undefined4 *)(puVar4 + -0xc0) = 1;
              *(int *)(puVar4 + -0xbc) = iVar3;
              *(undefined4 *)(puVar4 + -0xb8) = 4;
              FUN_005fc330(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076762c,puVar4 + -200,&DAT_007961a0);
              FUN_005fc980(puVar4 + -0xac,&DAT_00767628,0);
              DAT_01a9f318 = DAT_01a9f310;
              for (iVar3 = (DAT_01a9f314 - DAT_01a9f310) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
                *(undefined4 *)(puVar4 + -0xc0) = 1;
                *(int *)(puVar4 + -0xbc) = DAT_01a9f318 + 0x205343f;
                *(undefined4 *)(puVar4 + -0xb8) = 1;
                FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
                DAT_01a9f318 = DAT_01a9f318 + 1;
              }
              FUN_005fc980(puVar4 + -0xac,&DAT_00767624,0);
            }
          }
          *(undefined4 *)(puVar4 + -0x28) = 0;
        }
      }
      else {
        *(undefined4 *)(puVar4 + -0x5c) = 0;
        fVar1 = *(float *)(&DAT_02053438 + DAT_01a9f304 * 4);
        *(undefined2 *)(puVar4 + -0xb4) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0xb2) = (ushort)*(undefined4 *)(puVar4 + -0xb4) | 0xc00;
        *(int *)(puVar4 + -0xb0) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb4);
        DAT_00941ff0 = *(int *)(puVar4 + -0xb0);
        if (DAT_01a9f30c < 10) {
          if (DAT_020b8ea2 == ' ') {
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(int **)(puVar4 + -0xb8) = &DAT_01a9f300;
            iVar3 = FUN_005fc330(puVar4 + -0xac,0x14,0x784ff01,&DAT_0076763c,puVar4 + -0xb8,
                                 &DAT_007962d0);
            *(int *)(puVar4 + -0x24) = iVar3;
            if (iVar3 == 0) {
              *(undefined4 *)(puVar4 + -0xc0) = 5;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f30c * 5 + *(int *)(puVar4 + 8) + -5;
              *(undefined4 *)(puVar4 + -0xb8) = 5;
              iVar3 = FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              *(int *)(puVar4 + -0x24) = iVar3;
              if (iVar3 == 0) {
                iVar3 = DAT_00941ff0;
                if (DAT_00941ff0 < 0) {
                  iVar3 = 0;
                }
                DAT_01a9f318 = DAT_01a9f304 + iVar3;
                *(undefined4 *)(puVar4 + -200) = 1;
                *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
                *(undefined4 *)(puVar4 + -0xc0) = 1;
                *(int *)(puVar4 + -0xbc) = iVar3;
                *(undefined4 *)(puVar4 + -0xb8) = 4;
                uVar2 = FUN_005fc980(puVar4 + -0xac,&DAT_00767634,puVar4 + -200);
                *(undefined4 *)(puVar4 + -0x24) = uVar2;
              }
            }
            if (*(int *)(puVar4 + -0x24) != 0) goto LAB_00513b76;
          }
          if (DAT_020b8ea2 != ' ') {
            iVar3 = DAT_00941ff0;
            if (DAT_00941ff0 < 0) {
              iVar3 = 0;
            }
            DAT_01a9f318 = DAT_01a9f304 + iVar3;
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar3;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            uVar2 = FUN_005fc330(puVar4 + -0xac,0x14,0x784ff01,&DAT_00767634,puVar4 + -200,
                                 &DAT_00796060);
            *(undefined4 *)(puVar4 + -0x20) = uVar2;
            iVar3 = *(int *)(puVar4 + -0x20);
joined_r0x00512b2f:
            if (iVar3 != 0) goto LAB_00513b76;
          }
        }
        else {
          if (DAT_020b8ea2 == ' ') {
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(int **)(puVar4 + -0xb8) = &DAT_01a9f300;
            iVar3 = FUN_005fc330(puVar4 + -0xac,0x14,0x784ff01,&DAT_0076763c,puVar4 + -0xb8,
                                 &DAT_00796238);
            *(int *)(puVar4 + -0x1c) = iVar3;
            if (iVar3 == 0) {
              *(undefined4 *)(puVar4 + -0xc0) = 5;
              *(int *)(puVar4 + -0xbc) = DAT_01a9f30c * 5 + *(int *)(puVar4 + 8) + -5;
              *(undefined4 *)(puVar4 + -0xb8) = 5;
              iVar3 = FUN_005fc980(puVar4 + -0xac,&DAT_00767638,puVar4 + -0xc0);
              *(int *)(puVar4 + -0x1c) = iVar3;
              if (iVar3 == 0) {
                iVar3 = DAT_00941ff0;
                if (DAT_00941ff0 < 0) {
                  iVar3 = 0;
                }
                DAT_01a9f318 = DAT_01a9f304 + iVar3;
                *(undefined4 *)(puVar4 + -200) = 1;
                *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
                *(undefined4 *)(puVar4 + -0xc0) = 1;
                *(int *)(puVar4 + -0xbc) = iVar3;
                *(undefined4 *)(puVar4 + -0xb8) = 4;
                uVar2 = FUN_005fc980(puVar4 + -0xac,&DAT_00767634,puVar4 + -200);
                *(undefined4 *)(puVar4 + -0x1c) = uVar2;
              }
            }
            if (*(int *)(puVar4 + -0x1c) != 0) goto LAB_00513b76;
          }
          if (DAT_020b8ea2 != ' ') {
            iVar3 = DAT_00941ff0;
            if (DAT_00941ff0 < 0) {
              iVar3 = 0;
            }
            DAT_01a9f318 = DAT_01a9f304 + iVar3;
            *(undefined4 *)(puVar4 + -0xac) = 0;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &ITEM_LEN + DAT_01a9f304;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar3;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            uVar2 = FUN_005fc330(puVar4 + -0xac,0x14,0x784ff01,&DAT_00767634,puVar4 + -200,
                                 &DAT_00795ff8);
            *(undefined4 *)(puVar4 + -0x18) = uVar2;
            iVar3 = *(int *)(puVar4 + -0x18);
            goto joined_r0x00512b2f;
          }
        }
      }
      *(undefined4 *)(puVar4 + -0x14) = 0;
      DAT_01a9f300 = DAT_01a9f300 + 1;
      *(int *)(puVar4 + -0x60) = *(int *)(puVar4 + -0x60) + -1;
      iVar3 = *(int *)(puVar4 + -0x60);
    }
    *(undefined4 *)(puVar4 + -0xac) = 0;
    FUN_005f7950(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076757c,0);
    FUN_005f33c9(puVar4,0x513ab7);
    FUN_005f34d1(puVar4,0x513ad2);
    DAT_00942073 = 0;
    FUN_005f33c9(puVar4,0x513afc);
    if (DAT_020b8ea2 == 'X') {
      *(undefined4 *)(puVar4 + -0xc) = 0;
    }
    else {
      FUN_005f33c9(puVar4,0x513b39);
      FUN_005f34d1(puVar4,0x513b54);
      thunk_FUN_00567e5b();
      DAT_020b8ea0._0_1_ = DAT_007675b8;
      *(undefined4 *)(puVar4 + -8) = 0;
    }
  }
  else {
LAB_00513b76:
    *(undefined4 *)(puVar4 + -0xac) = 0;
    FUN_005f7950(puVar4 + -0xac,0x14,0x784ff00,&DAT_0076757c,0);
  }
  return;
}


