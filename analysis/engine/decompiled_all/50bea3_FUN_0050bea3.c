// FUN_0050bea3 @ 0050bea3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050bea3(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int *piVar9;
  char *pcVar10;
  bool bVar11;
  float10 fVar12;
  undefined4 local_bc;
  float *local_b8;
  undefined4 local_b4;
  float *local_b0;
  undefined4 *local_ac;
  undefined4 local_a8;
  undefined4 local_a4 [11];
  int local_78;
  undefined4 local_74;
  
  puVar4 = &stack0xfffffffc;
  local_a4[0] = 0;
  local_b4 = 0x80;
  local_b0 = &P14;
  local_ac = &DAT_00940c80;
  FUN_005f47c0(local_a4,0xffffffff,0x784ff00,&DAT_0076706c,&local_b4);
  if ((DAT_00940c80 & 1) == 0) {
    FUN_005f33c9(&stack0xfffffffc,0x50bf3a);
    FUN_005f34d1(puVar4,0x50bf55);
    *(undefined4 *)(puVar4 + -0xa0) = 0;
    *(undefined4 *)(puVar4 + -0xb0) = 0x25;
    *(undefined **)(puVar4 + -0xac) = &DAT_020b90b0;
    *(undefined4 *)(puVar4 + -0xa8) = 0x24;
    *(float **)(puVar4 + -0xa4) = &P14;
    FUN_005f34f0(puVar4 + -0xa0,0x784ff00,&DAT_00767134,puVar4 + -0xb0,&DAT_00795b3c);
    thunk_FUN_0054d831(&DAT_020b90a0,0x200);
    *(undefined4 *)(puVar4 + -0x78) = 0;
    return;
  }
  _DAT_00940c7c = 0;
  DAT_00940c78 = 0;
  DAT_00940c74 = 0x1f;
  local_a4[0] = 0;
  local_bc = 0x80;
  local_b8 = &P14;
  local_b4 = 3;
  local_b0 = (float *)&DAT_00767130;
  local_ac = (undefined4 *)0x200;
  local_a8 = 2;
  local_78 = FUN_005f6540(local_a4,0x1f,0x784ff01,&DAT_0076711c,&local_bc);
  puVar4 = &stack0xfffffffc;
  if (local_78 == 0) {
    puVar4 = &stack0xfffffffc;
    if (DAT_00940c74 == -1) {
      local_74 = 0;
      puVar4 = &stack0xfffffffc;
    }
    else {
LAB_0050c091:
      FUN_005f34d1(puVar4,0x50c0ae);
      *(undefined4 *)(puVar4 + -0xa0) = 0;
      iVar1 = FUN_005fdbd0(puVar4 + -0xa0,0x1f,0x784ff03,&DAT_00767118,0,&DAT_00795b28);
      *(int *)(puVar4 + -0x6c) = iVar1;
      if (iVar1 == 0) {
        iVar1 = 0x100;
        DAT_00940c70 = 1;
        do {
          *(undefined4 *)(puVar4 + -0xb0) = 1;
          *(undefined1 **)(puVar4 + -0xac) = &DAT_020b8e9f + DAT_00940c70;
          *(undefined4 *)(puVar4 + -0xa8) = 1;
          iVar2 = FUN_005fe110(puVar4 + -0xa0,&DAT_00767114,puVar4 + -0xb0);
          *(int *)(puVar4 + -0x6c) = iVar2;
          if (iVar2 != 0) goto LAB_0050c197;
          DAT_00940c70 = DAT_00940c70 + 1;
          iVar1 = iVar1 + -1;
        } while (0 < iVar1);
        uVar3 = FUN_005fe110(puVar4 + -0xa0,&DAT_007670f0,0);
        *(undefined4 *)(puVar4 + -0x6c) = uVar3;
      }
LAB_0050c197:
      if (*(int *)(puVar4 + -0x6c) == -1) goto LAB_0050c7d0;
      if (*(int *)(puVar4 + -0x6c) == 0) {
        puVar5 = (undefined4 *)&DAT_020b8ea0;
        puVar8 = (undefined4 *)(puVar4 + -0x2b8);
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar8 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar8 = puVar8 + 1;
        }
        DAT_00940c6c = FUN_005ff950(puVar4 + -0x2b8,0x200);
        if ((char)DAT_020b8ea0 != '%') {
          *(undefined4 *)(puVar4 + -0x68) = 0;
LAB_0050c2f3:
          if (OUTPUT_MODE < 0) {
            *(undefined4 *)(puVar4 + -0xa0) = 0;
            iVar1 = FUN_005fc330(puVar4 + -0xa0,0x18,0x784ff01,&DAT_00767118,0,&DAT_00795b0c);
            *(int *)(puVar4 + -0xc) = iVar1;
            if (iVar1 == 0) {
              DAT_00940c68 = 1;
              for (iVar1 = DAT_00940c6c; 0 < iVar1; iVar1 = iVar1 + -1) {
                *(undefined4 *)(puVar4 + -0xb0) = 1;
                *(undefined1 **)(puVar4 + -0xac) = &DAT_020b8e9f + DAT_00940c68;
                *(undefined4 *)(puVar4 + -0xa8) = 1;
                iVar2 = FUN_005fc980(puVar4 + -0xa0,&DAT_00767114,puVar4 + -0xb0);
                *(int *)(puVar4 + -0xc) = iVar2;
                if (iVar2 != 0) goto LAB_0050c3f5;
                DAT_00940c68 = DAT_00940c68 + 1;
              }
              uVar3 = FUN_005fc980(puVar4 + -0xa0,&DAT_007670f0,0);
              *(undefined4 *)(puVar4 + -0xc) = uVar3;
            }
LAB_0050c3f5:
            if (*(int *)(puVar4 + -0xc) != 0) goto LAB_0050c7cb;
            *(undefined4 *)(puVar4 + -8) = 0;
          }
          else {
            *(undefined4 *)(puVar4 + -0x10) = 0;
          }
          goto LAB_0050c091;
        }
        bVar11 = OUTPUT_MODE == 0;
        if (-1 < OUTPUT_MODE) {
          iVar1 = 3;
          piVar6 = (int *)s__BoundingBox_00795b80;
          piVar9 = (int *)((int)&DAT_020b8ea0 + 1);
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar11 = *piVar6 == *piVar9;
            piVar6 = piVar6 + 1;
            piVar9 = piVar9 + 1;
          } while (bVar11);
          if (bVar11) {
            DAT_00940c68 = 1;
            DAT_00940c64 = 0xf;
            while( true ) {
              while (((char)(&DAT_020b8e9f)[DAT_00940c64] < '+' ||
                     ('9' < (char)(&DAT_020b8e9f)[DAT_00940c64]))) {
                DAT_00940c64 = DAT_00940c64 + 1;
                if (DAT_00940c6c <= DAT_00940c64) goto LAB_0050c78a;
                *(undefined4 *)(puVar4 + -0x58) = 0;
              }
              iVar1 = DAT_00940c68 * 4;
              fVar12 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_00940c64,1,&DAT_00940c64);
              *(float *)(iVar1 + 0x1a2776c) = (float)fVar12;
              DAT_00940c68 = DAT_00940c68 + 1;
              if ((9 < DAT_00940c68) || (DAT_00940c6c <= DAT_00940c64)) break;
              *(undefined4 *)(puVar4 + -0x5c) = 0;
            }
LAB_0050c78a:
            if (DAT_00940c68 != 1) {
              DAT_020b9468 = f_m9999;
              P11 = f_m9999;
              IP11 = -9999;
              *(undefined4 *)(puVar4 + -0x50) = 0;
              goto LAB_0050c7d0;
            }
            *(undefined4 *)(puVar4 + -0x54) = 0;
          }
          else {
            *(undefined4 *)(puVar4 + -0x60) = 0;
          }
          goto LAB_0050c091;
        }
        *(undefined4 *)(puVar4 + -100) = 0;
        if (DAT_020b8ea0._1_1_ == '*') {
          _DAT_00940c7c = 1;
        }
        else {
          *(undefined4 *)(puVar4 + -0x4c) = 0;
        }
        if (DAT_01aae360 == 0) {
          *(undefined4 *)(puVar4 + -0x48) = 0;
        }
        else {
          iVar1 = 2;
          bVar11 = false;
          piVar6 = (int *)((int)&DAT_020b8ea0 + 1);
          piVar9 = &DAT_0076710c;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar11 = *piVar6 == *piVar9;
            piVar6 = piVar6 + 1;
            piVar9 = piVar9 + 1;
          } while (bVar11);
          if (bVar11) {
            *(undefined4 *)(puVar4 + -0x44) = 0;
            goto LAB_0050c091;
          }
          iVar1 = 3;
          bVar11 = false;
          piVar6 = (int *)s__BoundingBox_00795b80;
          piVar9 = (int *)((int)&DAT_020b8ea0 + 1);
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar11 = *piVar6 == *piVar9;
            piVar6 = piVar6 + 1;
            piVar9 = piVar9 + 1;
          } while (bVar11);
          if (!bVar11) {
            iVar1 = 3;
            bVar11 = false;
            piVar6 = (int *)((int)&DAT_020b8ea0 + 1);
            piVar9 = &DAT_00767100;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar11 = *piVar6 == *piVar9;
              piVar6 = piVar6 + 1;
              piVar9 = piVar9 + 1;
            } while (bVar11);
            if (bVar11) {
              iVar1 = 7;
              bVar11 = true;
              pcVar7 = (char *)((int)&DAT_020b8eb0 + 1);
              pcVar10 = "(atend)";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar11 = *pcVar7 == *pcVar10;
                pcVar7 = pcVar7 + 1;
                pcVar10 = pcVar10 + 1;
              } while (bVar11);
              if (bVar11) {
                *(undefined4 *)(puVar4 + -0x38) = 0;
                goto LAB_0050c091;
              }
              DAT_00940c78 = 1;
              DAT_00940c60 = 0x11;
            }
            else {
              *(undefined4 *)(puVar4 + -0x3c) = 0;
              if ((DAT_00940c78 == 0) || (ram0x020b8ea1 != 0x2b25)) {
                DAT_00940c78 = 0;
                if (DAT_020b8ea0._1_1_ != '!') goto LAB_0050c2f3;
                *(undefined4 *)(puVar4 + -0x14) = 0;
                goto LAB_0050c091;
              }
              DAT_00940c60 = 4;
              *(undefined4 *)(puVar4 + -0x18) = 0;
            }
            DAT_00940c68 = 1;
            iVar1 = (DAT_00940c6c - DAT_00940c60) + 1;
            *(int *)(puVar4 + -0x34) = iVar1;
            DAT_00940c64 = DAT_00940c60;
            while (0 < iVar1) {
              if ((&DAT_020b8e9f)[DAT_00940c64] == ' ') {
                if (1 < DAT_00940c68) {
                  iVar1 = 0x1d - DAT_00940c68;
                  *(int *)(puVar4 + -0x30) = iVar1;
                  while (0 < iVar1) {
                    *(undefined1 *)(DAT_00940c68 + 0x1aae427) = 0x20;
                    DAT_00940c68 = DAT_00940c68 + 1;
                    *(int *)(puVar4 + -0x30) = *(int *)(puVar4 + -0x30) + -1;
                    iVar1 = *(int *)(puVar4 + -0x30);
                  }
                  *(undefined4 *)(puVar4 + -0xa0) = 0;
                  *(undefined4 *)(puVar4 + -0xa8) = 0x1c;
                  *(undefined1 **)(puVar4 + -0xa4) = &DAT_01aae428;
                  uVar3 = FUN_005fc330(puVar4 + -0xa0,0x1a,0x784ff01,&DAT_007670ac,puVar4 + -0xa8,
                                       &DAT_00795b50);
                  *(undefined4 *)(puVar4 + -0x2c) = uVar3;
                  if (*(int *)(puVar4 + -0x2c) == 0) {
                    DAT_01aae444 = DAT_01aae444 + 1;
                    DAT_00940c68 = 1;
                  }
                }
              }
              else {
                *(undefined1 *)(DAT_00940c68 + 0x1aae427) = (&DAT_020b8e9f)[DAT_00940c64];
                DAT_00940c68 = DAT_00940c68 + 1;
                if (0x1c < DAT_00940c68) {
                  DAT_00940c68 = 0x1c;
                }
              }
              *(undefined4 *)(puVar4 + -0x28) = 0;
              DAT_00940c64 = DAT_00940c64 + 1;
              *(int *)(puVar4 + -0x34) = *(int *)(puVar4 + -0x34) + -1;
              iVar1 = *(int *)(puVar4 + -0x34);
            }
            if (1 < DAT_00940c68) {
              iVar1 = 0x1d - DAT_00940c68;
              *(int *)(puVar4 + -0x24) = iVar1;
              while (0 < iVar1) {
                *(undefined1 *)(DAT_00940c68 + 0x1aae427) = 0x20;
                DAT_00940c68 = DAT_00940c68 + 1;
                *(int *)(puVar4 + -0x24) = *(int *)(puVar4 + -0x24) + -1;
                iVar1 = *(int *)(puVar4 + -0x24);
              }
              *(undefined4 *)(puVar4 + -0xa0) = 0;
              *(undefined4 *)(puVar4 + -0xa8) = 0x1c;
              *(undefined1 **)(puVar4 + -0xa4) = &DAT_01aae428;
              uVar3 = FUN_005fc330(puVar4 + -0xa0,0x1a,0x784ff01,&DAT_007670ac,puVar4 + -0xa8,
                                   &DAT_00795b64);
              *(undefined4 *)(puVar4 + -0x20) = uVar3;
              if (*(int *)(puVar4 + -0x20) != 0) goto LAB_0050c091;
              DAT_01aae444 = DAT_01aae444 + 1;
            }
            *(undefined4 *)(puVar4 + -0x1c) = 0;
            goto LAB_0050c091;
          }
          *(undefined4 *)(puVar4 + -0x40) = 0;
        }
        goto LAB_0050c091;
      }
    }
  }
LAB_0050c7cb:
  thunk_FUN_004cf1c2();
LAB_0050c7d0:
  *(undefined4 *)(puVar4 + -0xa0) = 0;
  FUN_005f7950(puVar4 + -0xa0,0x1f,0x784ff00,&DAT_007670f4,0);
  return;
}


