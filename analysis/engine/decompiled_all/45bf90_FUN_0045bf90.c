// FUN_0045bf90 @ 0045bf90 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045bf90(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined *puStack_168;
  int local_88;
  
  puVar11 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar12 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar13 = &stack0xfffffffc;
  puVar14 = &stack0xfffffffc;
  if (DAT_01fbb8a0 == 0) {
    puStack_168 = (undefined *)0x45ce70;
    FUN_005f33c9();
    puStack_168 = (undefined *)0x45ce8b;
    FUN_005f34d1();
    DAT_01fbb8a0 = 0x28;
    *(undefined4 *)(puVar14 + -0x8c) = 0;
  }
  else if (((DAT_009ae2bc & 0xff) == 0xd) || ((DAT_009ae2bc >> 8 & 0xff) == 0xd)) {
    puStack_168 = (undefined *)0x45ce1f;
    FUN_005f33c9();
    puStack_168 = (undefined *)0x45ce3a;
    FUN_005f34d1();
    DAT_01fbb8a0 = 0;
    *(undefined4 *)(puVar13 + -0x88) = 0;
  }
  else {
    if (DAT_01fbb8a0 == 0x28) {
      puVar5 = &DAT_009ae2bc;
      puVar7 = (undefined4 *)&DAT_007ff010;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      puStack_168 = &DAT_007615c0;
      thunk_FUN_0054cb15(s__scor4_lib__00790914,0x40,&DAT_007feffc);
      puStack_168 = &DAT_007615c0;
      thunk_FUN_0054cb15(&DAT_007ff010,0x40,&DAT_007feff8);
      DAT_007feff4 = 0;
      if ((DAT_007ff010 == '*') && (DAT_007feff4 = 2, DAT_007ff011 == ' ')) {
        DAT_007feff4 = 3;
      }
      if (DAT_007feff4 != 0) {
LAB_0045c147:
        bVar9 = false;
        bVar10 = DAT_007feff4 == 0;
        if (!bVar10) {
          *(int *)(puVar3 + -0xb4) = DAT_007feff4 + -1;
          iVar2 = DAT_007feff8 - *(int *)(puVar3 + -0xb4);
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          *(int *)(puVar3 + -0xb8) = iVar2;
          puStack_168 = (undefined *)0x45c1ad;
          FUN_005f46bc();
          puStack_168 = (undefined *)0x45c1d0;
          FUN_005f46bc();
          puStack_168 = (undefined *)0x45c1f6;
          FUN_005f46bc();
          puStack_168 = (undefined *)0x45c20c;
          FUN_005f34d1();
          bVar9 = (undefined1 *)0xfffffffb < &puStack_168;
          bVar10 = &stack0x00000000 == (undefined1 *)0x164;
        }
        *(undefined4 *)(puVar3 + -0x78) = 0x40;
        DAT_007feff4 = 0x40;
        do {
          iVar2 = 1;
          pbVar6 = (byte *)((int)&DAT_007ff00c + DAT_007feff4 + 3);
          pbVar8 = &DAT_007615bc;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar9 = *pbVar6 < *pbVar8;
            bVar10 = *pbVar6 == *pbVar8;
            pbVar6 = pbVar6 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar10);
          if (!bVar9 && !bVar10) {
            *(undefined4 *)(puVar3 + -0x74) = 0;
            goto LAB_0045c264;
          }
          DAT_007feff4 = DAT_007feff4 + -1;
          *(int *)(puVar3 + -0x78) = *(int *)(puVar3 + -0x78) + -1;
          bVar9 = false;
          bVar10 = *(int *)(puVar3 + -0x78) == 0;
          if (*(int *)(puVar3 + -0x78) < 1) {
LAB_0045c264:
            if (*(char *)((int)&DAT_007ff00c + DAT_007feff4) != '.') {
              puStack_168 = (undefined *)0x45c2bb;
              FUN_005f46bc();
              puStack_168 = (undefined *)0x45c2d1;
              FUN_005f34d1();
            }
            puStack_168 = (undefined *)0x45c2f3;
            FUN_005f33c9();
            puStack_168 = (undefined *)0x45c30e;
            FUN_005f34d1();
            *(undefined4 *)(puVar3 + -0x70) = 0;
            DAT_01fbb8a0 = 0x29;
            return;
          }
        } while( true );
      }
      local_88 = 0x40;
      DAT_007feffc = 0x40;
      do {
        if (*(char *)((int)&DAT_007ff00c + DAT_007feffc + 3) == '\\') {
          puStack_168 = (undefined *)0x45c11f;
          FUN_005f46bc();
          puStack_168 = (undefined *)0x45c135;
          puVar3 = puVar11;
          FUN_005f34d1();
          goto LAB_0045c147;
        }
        DAT_007feffc = DAT_007feffc + -1;
        local_88 = local_88 + -1;
      } while (0 < local_88);
    }
    else {
      puStack_168 = (undefined *)0x45c347;
      FUN_005f33c9();
      puStack_168 = (undefined *)0x45c362;
      FUN_005f34d1();
      DAT_0081de8a = DAT_009ae2bc;
      puStack_168 = (undefined *)0x45c3a7;
      FUN_005f46bc();
      puStack_168 = (undefined *)0x45c3c3;
      FUN_005f46bc();
      puStack_168 = (undefined *)0x45c3df;
      FUN_005f46bc();
      puStack_168 = (undefined *)0x45c401;
      FUN_005f33c9();
      *(undefined4 *)(puVar12 + -0xb0) = 0;
      *(undefined4 *)(puVar12 + -0xc0) = 0x80;
      *(undefined **)(puVar12 + -0xbc) = &DAT_0081de88;
      *(int **)(puVar12 + -0xb8) = &DAT_007ff00c;
      FUN_005f47c0(puVar12 + -0xb0,0xffffffff,0x784ff00,&DAT_00761564,puVar12 + -0xc0);
      puStack_168 = (undefined *)0x45c478;
      FUN_005f33c9();
      puStack_168 = (undefined *)0x45c493;
      puVar4 = puVar12;
      FUN_005f34d1();
      if (DAT_007ff00c == 0) {
        *(undefined4 *)(puVar4 + -0x68) = 0;
      }
      else {
        puStack_168 = (undefined *)0x45c4c7;
        FUN_005f33c9();
        puStack_168 = (undefined *)0x45c4e2;
        FUN_005f34d1();
        DAT_007ff004 = thunk_FUN_00579410(&DAT_00761560);
        if (DAT_007ff004 != -1) {
          puStack_168 = (undefined *)0x45cda6;
          FUN_005f33c9();
          puStack_168 = (undefined *)0x45cdc1;
          FUN_005f34d1();
          *(undefined4 *)(puVar4 + -0xb0) = 0;
          FUN_005f7950(puVar4 + -0xb0,3,0x784ff00,&DAT_00761530,0);
          *(undefined4 *)(puVar4 + -0x5c) = 0;
          return;
        }
        *(undefined4 *)(puVar4 + -100) = 0;
      }
      *(undefined4 *)(puVar4 + -0xb0) = 0;
      *(undefined4 *)(puVar4 + -0xd0) = 0x40;
      *(char **)(puVar4 + -0xcc) = &DAT_007ff010;
      *(undefined4 *)(puVar4 + -200) = 3;
      *(undefined **)(puVar4 + -0xc4) = &DAT_0076155c;
      *(undefined4 *)(puVar4 + -0xc0) = 6;
      *(char **)(puVar4 + -0xbc) = "binary";
      *(undefined4 *)(puVar4 + -0xb8) = 2;
      uVar1 = FUN_005f6540(puVar4 + -0xb0,3,0x784ff01,&DAT_00761540,puVar4 + -0xd0);
      *(undefined4 *)(puVar4 + -0x58) = uVar1;
      if (*(int *)(puVar4 + -0x58) == 0) {
        *(undefined4 *)(puVar4 + -0xb0) = 0;
        *(short **)(puVar4 + -0xb8) = &DAT_007ff004;
        FUN_005f8240(puVar4 + -0xb0,3,0x784ff00,&DAT_0076153c,puVar4 + -0xb8);
        *(undefined4 *)(puVar4 + -0xb0) = 0;
        *(undefined4 *)(puVar4 + -0xb8) = 0x16;
        *(undefined **)(puVar4 + -0xb4) = &DAT_007ff05c;
        FUN_005f8240(puVar4 + -0xb0,3,0x784ff00,&DAT_00761538,puVar4 + -0xb8);
        *(undefined4 *)(puVar4 + -0xb0) = 0;
        *(undefined4 *)(puVar4 + -0xc0) = 0x32;
        *(undefined **)(puVar4 + -0xbc) = &DAT_007ff074;
        *(undefined4 *)(puVar4 + -0xb8) = 5;
        FUN_005f8240(puVar4 + -0xb0,3,0x784ff00,&DAT_00761534,puVar4 + -0xc0);
        DAT_007feff0 = DAT_007ff070 + -1;
        DAT_007feffc = 1;
        do {
          DAT_007feff4 = 1;
          *(undefined4 *)(puVar4 + -0xb0) = 0;
          *(short **)(puVar4 + -0xb8) = &DAT_007ff004;
          FUN_005f8240(puVar4 + -0xb0,3,0x784ff00,&DAT_0076153c,puVar4 + -0xb8);
LAB_0045c6ea:
          *(undefined4 *)(puVar4 + -0xb0) = 0;
          *(undefined4 *)(puVar4 + -0xb8) = 2;
          *(int *)(puVar4 + -0xb4) = DAT_007feffc * 2 + 0x7ff166;
          FUN_005f8240(puVar4 + -0xb0,3,0x784ff00,&DAT_00761538,puVar4 + -0xb8);
          DAT_007feffc = DAT_007feffc + 1;
          if (DAT_007feff0 < DAT_007feffc) {
            *(undefined4 *)(puVar4 + -0x40) = 0;
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            FUN_005f7950(puVar4 + -0xb0,3,0x784ff00,&DAT_00761530,0);
            *(undefined4 *)(puVar4 + -0x30) = 10;
            DAT_007fefec = 2;
            do {
              *(short *)(DAT_007fefec * 2 + 0x7ff0ce) =
                   *(short *)(DAT_007fefec * 2 + 0x7ff05a) / 3 + 1;
              DAT_007fefec = DAT_007fefec + 1;
              *(int *)(puVar4 + -0x30) = *(int *)(puVar4 + -0x30) + -1;
            } while (0 < *(int *)(puVar4 + -0x30));
            _DAT_007ff0d0 = 0;
            *(undefined4 *)(puVar4 + -0x2c) = 10;
            DAT_007fefec = 1;
            do {
              *(int *)(DAT_007fefec * 4 + 0x7ff0a4) = DAT_007ff004 + DAT_007fefec + -1;
              puStack_168 = (undefined *)0x45c880;
              FUN_005f33c9();
              puStack_168 = (undefined *)0x45c89b;
              FUN_005f34d1();
              DAT_007fefec = DAT_007fefec + 1;
              *(int *)(puVar4 + -0x2c) = *(int *)(puVar4 + -0x2c) + -1;
            } while (0 < *(int *)(puVar4 + -0x2c));
            DAT_007feffc = 0;
            iVar2 = (DAT_007ff070 + 1) / 3;
            *(int *)(puVar4 + -0x28) = iVar2;
            DAT_007fefec = 1;
            while (0 < iVar2) {
              DAT_007feffc = DAT_007feffc + 1;
              *(int *)(puVar4 + -0xb4) = (int)*(short *)(DAT_007fefec * 2 + 0x7ff166);
              *(float *)(DAT_007feffc * 4 + 0x80f334) = (float)*(int *)(puVar4 + -0xb4);
              *(int *)(puVar4 + -0xb4) = (int)(short)(&DAT_007ff168)[DAT_007fefec];
              *(float *)(DAT_007feffc * 4 + 0x8056f4) = (float)*(int *)(puVar4 + -0xb4);
              *(undefined2 *)(DAT_007feffc * 2 + 0x818f76) = (&DAT_007ff16a)[DAT_007fefec];
              DAT_007fefec = DAT_007fefec + 3;
              *(int *)(puVar4 + -0x28) = *(int *)(puVar4 + -0x28) + -1;
              iVar2 = *(int *)(puVar4 + -0x28);
            }
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            *(undefined4 *)(puVar4 + -0xd0) = 0x80;
            *(undefined **)(puVar4 + -0xcc) = &DAT_0081de88;
            *(undefined4 *)(puVar4 + -200) = 7;
            *(char **)(puVar4 + -0xc4) = "unknown";
            *(undefined4 *)(puVar4 + -0xc0) = 6;
            *(char **)(puVar4 + -0xbc) = "binary";
            *(undefined4 *)(puVar4 + -0xb8) = 2;
            uVar1 = FUN_005f6540(puVar4 + -0xb0,8,0x784ff01,&DAT_00761540,puVar4 + -0xd0);
            *(undefined4 *)(puVar4 + -0x24) = uVar1;
            if (*(int *)(puVar4 + -0x24) != 0) break;
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            *(undefined4 *)(puVar4 + -0xb8) = 0x16;
            *(undefined **)(puVar4 + -0xb4) = &DAT_007ff0d0;
            uVar1 = FUN_005fa4d0(puVar4 + -0xb0,8,0x784ff01,&DAT_00761538,puVar4 + -0xb8);
            *(undefined4 *)(puVar4 + -0x20) = uVar1;
            if (*(int *)(puVar4 + -0x20) != 0) break;
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            *(undefined4 *)(puVar4 + -0xc0) = 0xf0;
            *(undefined **)(puVar4 + -0xbc) = &DAT_0081dd98;
            *(undefined4 *)(puVar4 + -0xb8) = 0x18;
            uVar1 = FUN_005fa4d0(puVar4 + -0xb0,8,0x784ff01,&DAT_00761534,puVar4 + -0xc0);
            *(undefined4 *)(puVar4 + -0x1c) = uVar1;
            if (*(int *)(puVar4 + -0x1c) != 0) break;
            DAT_007ff004 = DAT_007ff0e4 + -1;
            iVar2 = (int)DAT_007ff004;
            if (iVar2 < 0) {
              iVar2 = 0;
            }
            DAT_007feffc = iVar2 + 1;
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &DAT_0080f338;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar2;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            uVar1 = FUN_005fa4d0(puVar4 + -0xb0,8,0x784ff01,&DAT_00761524,puVar4 + -200);
            *(undefined4 *)(puVar4 + -0x18) = uVar1;
            if (*(int *)(puVar4 + -0x18) != 0) break;
            iVar2 = (int)DAT_007ff004;
            if (iVar2 < 0) {
              iVar2 = 0;
            }
            DAT_007feffc = iVar2 + 1;
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined4 **)(puVar4 + -0xc4) = &DAT_008056f8;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar2;
            *(undefined4 *)(puVar4 + -0xb8) = 4;
            uVar1 = FUN_005fa4d0(puVar4 + -0xb0,8,0x784ff01,&DAT_00761524,puVar4 + -200);
            *(undefined4 *)(puVar4 + -0x14) = uVar1;
            if (*(int *)(puVar4 + -0x14) != 0) break;
            iVar2 = (int)DAT_007ff004;
            if (iVar2 < 0) {
              iVar2 = 0;
            }
            DAT_007feffc = iVar2 + 1;
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            *(undefined4 *)(puVar4 + -200) = 1;
            *(undefined2 **)(puVar4 + -0xc4) = &DAT_00818f78;
            *(undefined4 *)(puVar4 + -0xc0) = 1;
            *(int *)(puVar4 + -0xbc) = iVar2;
            *(undefined4 *)(puVar4 + -0xb8) = 2;
            uVar1 = FUN_005fa4d0(puVar4 + -0xb0,8,0x784ff01,&DAT_00761520,puVar4 + -200);
            *(undefined4 *)(puVar4 + -0x10) = uVar1;
            if (*(int *)(puVar4 + -0x10) != 0) break;
            *(undefined4 *)(puVar4 + -0xb0) = 0;
            FUN_005f7950(puVar4 + -0xb0,8,0x784ff00,&DAT_00761530,0);
            *(undefined4 *)(puVar4 + -8) = 0;
            goto LAB_0045cd7b;
          }
          DAT_007feff4 = DAT_007feff4 + 1;
          if (DAT_007feff4 < 0x41) goto code_r0x0045c771;
          *(undefined4 *)(puVar4 + -0x3c) = 0;
        } while( true );
      }
    }
    puStack_168 = (undefined *)0x1a;
    thunk_FUN_0054d831(" Error or file not found. ");
    puStack_168 = (undefined *)0x45cd47;
    FUN_005f34d1();
    *(undefined4 *)(puVar4 + -0xb0) = 0;
    FUN_005f7950(puVar4 + -0xb0,3,0x784ff00,&DAT_00761530,0);
LAB_0045cd7b:
    DAT_01fbb8a0 = 0;
  }
  return;
code_r0x0045c771:
  *(undefined4 *)(puVar4 + -0x38) = 0;
  goto LAB_0045c6ea;
}


