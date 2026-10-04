// FUN_004b041d @ 004b041d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004b1b03) */
/* WARNING: Removing unreachable block (ram,0x004b1884) */
/* WARNING: Removing unreachable block (ram,0x004b1842) */
/* WARNING: Removing unreachable block (ram,0x004b17b6) */
/* WARNING: Removing unreachable block (ram,0x004b13d8) */
/* WARNING: Removing unreachable block (ram,0x004b11a1) */
/* WARNING: Removing unreachable block (ram,0x004b09b8) */
/* WARNING: Removing unreachable block (ram,0x004b0577) */
/* WARNING: Removing unreachable block (ram,0x004b0fee) */
/* WARNING: Removing unreachable block (ram,0x004b1460) */
/* WARNING: Removing unreachable block (ram,0x004b160d) */
/* WARNING: Removing unreachable block (ram,0x004b17fc) */
/* WARNING: Removing unreachable block (ram,0x004b1a08) */
/* WARNING: Removing unreachable block (ram,0x004b1932) */
/* WARNING: Removing unreachable block (ram,0x004b1998) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b041d(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  undefined2 in_FPUControlWord;
  undefined2 uVar12;
  unkbyte10 Var13;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  undefined1 *puVar14;
  int local_218;
  
  puVar14 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  DAT_0089f21c = 0;
  if (DAT_01fbb8a0 != 0x12) {
    local_218 = 0x200;
    IP1 = 1;
    do {
      if ((&DAT_020b8e9f)[IP1] == '%') {
        FUN_005f46bc(&stack0xfffffffc,0x4b0ea0);
        FUN_005f34d1(puVar14,0x4b0eb6);
        FUN_005f46bc(puVar14,0x4b0ef3);
        puVar4 = puVar14;
        FUN_005f34d1(puVar14,0x4b0f09);
        *(undefined4 *)(puVar4 + -0x20c) = 0;
        break;
      }
      IP1 = IP1 + 1;
      local_218 = local_218 + -1;
    } while (0 < local_218);
    iVar7 = FUN_005f4660(0x20);
    if (iVar7 == 0) {
      *(undefined4 *)(puVar4 + -0x204) = 0;
      Var13 = extraout_ST0;
      goto LAB_004b0f4c;
    }
    DAT_01fbb8a4 = 0;
    DAT_01fbb8a0 = 0x12;
    FUN_005f33c9(puVar4,0x4b34da);
    Var13 = FUN_005f34d1(puVar4,0x4b34f5);
    ffree(Var13);
    Var13 = thunk_FUN_0041b68a();
    *(undefined4 *)(puVar4 + -0x200) = 0;
    goto LAB_004b350a;
  }
  puVar4 = &stack0xfffffffc;
  Var13 = FUN_005f34d1(&stack0xfffffffc,0x4b0465);
  if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
    DAT_0089f218 = VEC_N;
    ffree(Var13);
    Var13 = thunk_FUN_0041b011();
    ffree(Var13);
    Var13 = thunk_FUN_004a30bb(&DAT_0089f214,&DAT_007645c8);
    if (DAT_0089f214 != -2) {
      if (DAT_0089f214 == 0) {
        VEC_N = DAT_0089f218;
        *(undefined4 *)(puVar4 + -0x1f8) = 0;
      }
      goto LAB_004b0609;
    }
    *(undefined4 *)(puVar4 + -0x1fc) = 0;
  }
  else {
    ffree(Var13);
    Var13 = thunk_FUN_00518448();
    DAT_0089f218 = VEC_N;
    ffree(Var13);
    Var13 = thunk_FUN_0041aa88();
    ffree(Var13);
    Var13 = thunk_FUN_004a30bb(&DAT_0089f214,&DAT_007645c8);
    if (DAT_0089f214 != -2) {
      if (DAT_0089f214 == 0) {
        VEC_N = DAT_0089f218;
        *(undefined4 *)(puVar4 + -0x1f0) = 0;
      }
LAB_004b0609:
      DAT_01fbb8a0 = 0;
      DAT_01fbb8a4 = 0;
      FUN_005f33c9(puVar4,0x4b0637);
      FUN_005f34d1(puVar4,0x4b0652);
      Var13 = FUN_005f33c9(puVar4,0x4b0674);
      fVar1 = P1;
      *(undefined2 *)(puVar4 + -0x240) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
      *(int *)(puVar4 + -0x23c) = (int)ROUND(fVar1);
      fVar1 = P4;
      IP1 = *(int *)(puVar4 + -0x23c);
      *(undefined2 *)(puVar4 + -0x240) = *(undefined2 *)(puVar4 + -0x240);
      *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
      *(int *)(puVar4 + -0x23c) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0x240);
      DAT_0089f224 = *(int *)(puVar4 + -0x23c);
      ffree(Var13);
      Var13 = thunk_FUN_0058c2c9(&DAT_009c6648,0x2b,&DAT_00764588,&DAT_0076458c,"(1i3)",5,&IP1);
      ffree(Var13);
      Var13 = thunk_FUN_0058c2c9(&DAT_009c6648,0x2b,&DAT_00764580,&DAT_00764584,"(1i3)",5,
                                 &DAT_0089f224);
      ffree(Var13);
      Var13 = thunk_FUN_0058c248(&DAT_009c6648,0x2b,&DAT_00764570,&DAT_00764574,"(1f6.2)",7,&P2);
      ffree(Var13);
      thunk_FUN_0058c248(&DAT_009c6648,0x2b,&DAT_00764568,&DAT_0076456c,"(1f6.2)",7,&P3);
      FUN_005f33c9(puVar4,0x4b07fc);
      FUN_005f34d1(puVar4,0x4b0817);
      FUN_005f33c9(puVar4,0x4b0839);
      FUN_005f34d1(puVar4,0x4b0854);
      FUN_005f33c9(puVar4,0x4b0876);
      Var13 = FUN_005f34d1(puVar4,0x4b0891);
      puVar5 = &DAT_00764538;
      puVar8 = &DAT_009c6510;
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
      ffree(Var13);
      IP1 = thunk_FUN_0059c5d0(&DAT_0089f228);
      DAT_0078b4e0 = 0;
      DAT_0078b4e4 = 0;
      FUN_005f34d1(puVar4,0x4b08ef);
      Var13 = FUN_005f34d1(puVar4,0x4b0910);
      if (IP1 != 2) {
        FUN_005f34d1(puVar4,0x4b0949);
        FUN_005f33c9(puVar4,0x4b096b);
        FUN_005f34d1(puVar4,0x4b0986);
        DAT_0089f224 = 4;
        IP3 = 0x2e;
        FUN_005f46bc(puVar4,0x4b09da);
        FUN_005f34d1(puVar4,0x4b09f0);
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b029d(&DAT_009c6630,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b029d(&DAT_009c6618,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b029d(&DAT_009c6600,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b033d(&DAT_009c65e8,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b033d(&DAT_009c65d0,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b033d(&DAT_009c65b8,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b029d(&DAT_009c65a0,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b029d(&DAT_009c6588,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b029d(&DAT_009c6570,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b033d(&DAT_009c6558,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b033d(&DAT_009c6540,0x18,&DAT_0089f224,&IP3);
        }
        iVar7 = FUN_00601a30(0x20);
        if (iVar7 == 0) {
          FUN_004b033d(&DAT_009c6528,0x18,&DAT_0089f224,&IP3);
        }
        DAT_0089f224 = IP3;
        (&DAT_020b8e9f)[IP3] = 0x3b;
        FUN_004b023b(&DAT_009c6510,0x18,&IP3);
        DAT_0089f224 = DAT_0089f224 + 1;
        IP3 = IP3 + DAT_0089f224;
        FUN_005f46bc(puVar4,0x4b0dd6);
        Var13 = FUN_005f34d1(puVar4,0x4b0dec);
        ffree(Var13);
        Var13 = thunk_FUN_00518448();
LAB_004b0f4c:
        puVar5 = (undefined4 *)&DAT_020b90a0;
        puVar8 = &DAT_009ae2bc;
        for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar8 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar8 = puVar8 + 1;
        }
        ffree(Var13);
        Var13 = thunk_FUN_005725fa();
        puVar5 = &DAT_009ae2bc;
        puVar8 = (undefined4 *)&DAT_020b90a0;
        for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar8 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar8 = puVar8 + 1;
        }
        DAT_020527a0 = 0xffffffff;
        ffree(Var13);
        thunk_FUN_0054c8e5(&DAT_020b90a0,1,&DAT_0089f210);
        iVar7 = (4 - DAT_0089f210) / -1;
        *(int *)(puVar4 + -0x1e8) = iVar7;
        DAT_0089f20c = DAT_0089f210;
        while( true ) {
          if (iVar7 < 1) goto LAB_004b11f8;
          FUN_005f46bc(puVar4,0x4b1012);
          FUN_005f34d1(puVar4,0x4b1028);
          if ((DAT_0089f220 == 0x7a73) || (DAT_0089f220 == 0x5a53)) break;
          *(undefined4 *)(puVar4 + -0x1e4) = 0;
          if ((DAT_0089f220 == 0x7470) || (DAT_0089f220 == 0x5450)) {
            DAT_0089f220 = DAT_0076452c;
            goto LAB_004b10fb;
          }
          *(undefined4 *)(puVar4 + -0x1dc) = 0;
          *(undefined4 *)(puVar4 + -0x1d0) = 0;
          DAT_0089f20c = DAT_0089f20c + -1;
          *(int *)(puVar4 + -0x1e8) = *(int *)(puVar4 + -0x1e8) + -1;
          iVar7 = *(int *)(puVar4 + -0x1e8);
        }
        DAT_0089f220 = DAT_00764528;
        *(undefined4 *)(puVar4 + -0x1e0) = 0;
LAB_004b10fb:
        iVar7 = ((DAT_0089f20c - DAT_0089f210) + -1) / -1;
        *(int *)(puVar4 + -0x1d8) = iVar7;
        DAT_0089f208 = DAT_0089f210;
        while (0 < iVar7) {
          (&DAT_020b90a0)[DAT_0089f208] = (&DAT_020b909f)[DAT_0089f208];
          DAT_0089f208 = DAT_0089f208 + -1;
          *(int *)(puVar4 + -0x1d8) = *(int *)(puVar4 + -0x1d8) + -1;
          iVar7 = *(int *)(puVar4 + -0x1d8);
        }
        (&DAT_020b909e)[DAT_0089f20c] = 0x50;
        FUN_005f46bc(puVar4,0x4b11c5);
        FUN_005f34d1(puVar4,0x4b11db);
        DAT_0089f210 = DAT_0089f210 + 1;
        *(undefined4 *)(puVar4 + -0x1d4) = 0;
LAB_004b11f8:
        (&DAT_020b90a0)[DAT_0089f210] = 0;
        FUN_005f46bc(puVar4,0x4b1239);
        Var13 = FUN_005f34d1(puVar4,0x4b124f);
        IP10 = 0;
        DAT_020b9454 = 0;
        IP1 = 1;
        DAT_020b9448 = 0;
LAB_004b1276:
        cVar2 = (&DAT_020b909f)[IP1];
        P1 = (float)CONCAT31(P1._1_3_,cVar2);
        if (cVar2 == '\"') {
          ffree(Var13);
          Var13 = FUN_004b3fe8(&IP1);
          *(undefined4 *)(puVar4 + -0x1cc) = 0;
          goto LAB_004b352b;
        }
        if (cVar2 == '<') {
          if ((&DAT_020b90a0)[IP1] == '=') {
            (&DAT_020b909f)[IP1] = 0x7b;
            *(undefined4 *)(puVar4 + -0x1c4) = 0;
          }
          else {
            if ((&DAT_020b90a0)[IP1] != '>') {
              *(undefined4 *)(puVar4 + -0x1bc) = 0;
              goto LAB_004b1381;
            }
            (&DAT_020b909f)[IP1] = 0x7e;
            *(undefined4 *)(puVar4 + -0x1c0) = 0;
          }
LAB_004b1362:
          (&DAT_020b90a0)[IP1] = 0x20;
        }
        else {
          *(undefined4 *)(puVar4 + -0x1c8) = 0;
          if ((cVar2 == '>') && ((&DAT_020b90a0)[IP1] == '=')) {
            (&DAT_020b909f)[IP1] = 0x7d;
            goto LAB_004b1362;
          }
          *(undefined4 *)(puVar4 + -0x1b8) = 0;
        }
LAB_004b1381:
        if (((uint)P1 & 0xff) != 0x20) {
          iVar7 = DAT_020b9454 + 1;
          if (((uint)P1 & 0xff) == 0x3b) {
            DAT_020b9454 = iVar7;
            FUN_005f46bc(puVar4,0x4b13fc);
            Var13 = FUN_005f34d1(puVar4,0x4b1412);
            DAT_020b9454 = DAT_020b9454 + 3;
            *(undefined4 *)(puVar4 + -0x1b0) = 0;
            goto LAB_004b157c;
          }
          if (((uint)P1 & 0xff) == 0x5c) {
            DAT_020b9454 = iVar7;
            FUN_005f46bc(puVar4,0x4b1484);
            Var13 = FUN_005f34d1(puVar4,0x4b149a);
            DAT_020b9454 = DAT_020b9454 + 2;
            *(undefined4 *)(puVar4 + -0x1ac) = 0;
            goto LAB_004b157c;
          }
          puVar14 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_020b9454);
          DAT_020b9454 = iVar7;
          *puVar14 = (&DAT_020b909f)[IP1];
          if ((&DAT_020b8e9f)[DAT_020b9454] == '(') {
            DAT_020b9448 = DAT_020b9448 + 1;
          }
          if ((&DAT_020b8e9f)[DAT_020b9454] == ')') {
            DAT_020b9448 = DAT_020b9448 + -1;
          }
          bVar10 = false;
          bVar11 = DAT_020b9448 == 0;
          if (-1 < DAT_020b9448) {
            iVar7 = 1;
            pbVar6 = &DAT_020b8e9f + DAT_020b9454;
            pbVar9 = &DAT_0076451c;
            do {
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              bVar10 = *pbVar6 < *pbVar9;
              bVar11 = *pbVar6 == *pbVar9;
              pbVar6 = pbVar6 + 1;
              pbVar9 = pbVar9 + 1;
            } while (bVar11);
            if (!bVar10) {
              iVar7 = 1;
              pbVar6 = &DAT_020b8e9f + DAT_020b9454;
              pbVar9 = &DAT_00764518;
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar10 = *pbVar6 < *pbVar9;
                bVar11 = *pbVar6 == *pbVar9;
                pbVar6 = pbVar6 + 1;
                pbVar9 = pbVar9 + 1;
              } while (bVar11);
              if (bVar10 || bVar11) {
                (&DAT_020b8e9f)[DAT_020b9454] = (&DAT_020b8e9f)[DAT_020b9454] + -0x20;
              }
            }
            goto LAB_004b157c;
          }
          *(undefined4 *)(puVar4 + -0x1a8) = 0;
          goto LAB_004b1b62;
        }
        *(undefined4 *)(puVar4 + -0x1b4) = 0;
LAB_004b157c:
        IP1 = IP1 + 1;
        if (IP1 < 0xa1) {
          *(undefined4 *)(puVar4 + -0x1a4) = 0;
          goto LAB_004b1276;
        }
        IP2 = 2;
        while( true ) {
          IP2 = IP2 + 1;
          *(undefined4 *)(puVar4 + -0x23c) = 4;
          iVar7 = FUN_005f4660(0x20);
          if (iVar7 == 0) {
            *(undefined4 *)(puVar4 + -0x1a0) = 0;
          }
          else {
            (&DAT_020b8e9f)[IP2] = 0x40;
            IP9 = 3;
            IP3 = IP2 + 1;
            iVar7 = (DAT_020b9454 - IP3) + 1;
            *(int *)(puVar4 + -0x19c) = iVar7;
            while (0 < iVar7) {
              if ((&DAT_020b8e9f)[IP9 + IP3] == ')') {
                IP9 = 4;
              }
              (&DAT_020b8e9f)[IP3] = (&DAT_020b8e9f)[IP9 + IP3];
              if ((IP9 == 3) && ((&DAT_020b8e9f)[IP3] == ',')) {
                (&DAT_020b8e9f)[IP3] = 0x40;
              }
              IP3 = IP3 + 1;
              *(int *)(puVar4 + -0x19c) = *(int *)(puVar4 + -0x19c) + -1;
              iVar7 = *(int *)(puVar4 + -0x19c);
            }
            DAT_020b9454 = DAT_020b9454 + -4;
            IP2 = IP2 + 8;
          }
          if (DAT_020b9454 <= IP2) break;
          *(undefined4 *)(puVar4 + -0x198) = 0;
        }
        iVar7 = DAT_020b9454 + -5;
        *(int *)(puVar4 + -0x194) = iVar7;
        DAT_0089f224 = 6;
        Var13 = extraout_ST0_00;
        while (0 < iVar7) {
          iVar7 = FUN_005f4660(0x20);
          if ((iVar7 != 0) || (iVar7 = FUN_005f4660(0x20), iVar7 != 0)) {
            *(undefined4 *)(puVar4 + -400) = 0;
            FUN_005f46bc(puVar4,0x4b1ac1);
            FUN_005f34d1(puVar4,0x4b1ad7);
            DAT_020b9454 = DAT_020b9454 + 1;
            FUN_005f46bc(puVar4,0x4b1b27);
            Var13 = FUN_005f34d1(puVar4,0x4b1b3d);
            goto LAB_004b1b4d;
          }
          iVar7 = FUN_005f4660(0x20);
          if (iVar7 != 0) {
            *(undefined4 *)(puVar4 + -0x18c) = 0;
            DAT_0089f21c = 1;
            DAT_020b9454 = DAT_020b9454 + 4;
            if (*(char *)((int)&DAT_020b8ea0 + DAT_0089f224 + 1) == 'N') {
              FUN_005f46bc(puVar4,0x4b1956);
              Var13 = FUN_005f34d1(puVar4,0x4b196c);
              *(undefined4 *)(puVar4 + -0x180) = 0;
            }
            else {
              FUN_005f46bc(puVar4,0x4b19bc);
              Var13 = FUN_005f34d1(puVar4,0x4b19d2);
              *(undefined4 *)(puVar4 + -0x17c) = 0;
            }
            goto LAB_004b1b4d;
          }
          iVar7 = FUN_005f4660(0x20);
          if (iVar7 != 0) {
            *(undefined4 *)(puVar4 + -0x188) = 0;
            FUN_005f46bc(puVar4,0x4b1a2c);
            Var13 = FUN_005f34d1(puVar4,0x4b1a42);
            DAT_020b9454 = DAT_020b9454 + 2;
            *(undefined4 *)(puVar4 + -0x178) = 0;
            goto LAB_004b1b4d;
          }
          DAT_0089f224 = DAT_0089f224 + 1;
          *(int *)(puVar4 + -0x194) = *(int *)(puVar4 + -0x194) + -1;
          Var13 = extraout_ST0_01;
          iVar7 = *(int *)(puVar4 + -0x194);
        }
        *(undefined4 *)(puVar4 + -0x184) = 0;
LAB_004b1b4d:
        *(undefined1 *)((int)&DAT_020b8ea0 + DAT_020b9454) = 0x20;
LAB_004b1b62:
        if (DAT_020b9448 != 0) {
          *(undefined4 *)(puVar4 + -0x170) = 0;
          goto LAB_004b352b;
        }
        *(undefined4 *)(puVar4 + -0x174) = 0;
        IP2 = 0;
        IP3 = 4;
LAB_004b1b8c:
        while ((&DAT_020b8e9e)[IP3] == '(') {
          IP2 = IP2 + 1;
          *(undefined4 *)(&DAT_020b909c + IP2 * 4) = 0xd;
          IP3 = IP3 + 1;
          *(undefined4 *)(puVar4 + -0x168) = 0;
        }
        *(undefined4 *)(puVar4 + -0x16c) = 0;
        if ((&DAT_020b8e9e)[IP3] == '@') {
          IP3 = IP3 + 1;
        }
        else {
          *(undefined4 *)(puVar4 + -0x164) = 0;
        }
        while( true ) {
          IP2 = IP2 + 1;
          if (DAT_020b9454 < IP3) {
            *(undefined4 *)(puVar4 + -0x160) = 0;
            goto LAB_004b352b;
          }
          ffree(Var13);
          Var13 = FUN_004b362c(&IP3,&P0 + IP2 * 4);
          if (IP3 < 1) {
            *(undefined4 *)(puVar4 + -0x158) = 0;
            goto LAB_004b350a;
          }
          *(undefined4 *)(puVar4 + -0x15c) = 0;
          *(undefined4 *)(&DAT_020b90a0 + IP2 * 4) = 0;
          if (((&DAT_020b8e9f)[IP3] == 'D') || ((&DAT_020b8e9f)[IP3] == 'C')) break;
          if (DAT_020b9454 <= IP3) {
            *(undefined4 *)(puVar4 + -0x150) = 0;
            goto LAB_004b1e6e;
          }
          while( true ) {
            ffree(Var13);
            Var13 = FUN_004b3907(&IP3,&DAT_020b9454,&DAT_020b909c + IP2 * 4);
            if ((IP3 < 0x201) && ((&DAT_020b8e9e)[IP3] == '(')) {
              IP2 = IP2 + 1;
              IP3 = IP3 + 1;
              *(undefined4 *)(&DAT_020b909c + IP2 * 4) = 0xd;
              *(undefined4 *)(puVar4 + -0x148) = 0;
              goto LAB_004b1b8c;
            }
            *(undefined4 *)(puVar4 + -0x14c) = 0;
            if ((*(int *)(&DAT_020b909c + IP2 * 4) != 0xd) &&
               (*(int *)(&DAT_020b909c + IP2 * 4) != 0xe)) break;
            IP2 = IP2 + 1;
            IP3 = IP3 + 1;
            *(undefined4 *)(puVar4 + -0x140) = 0;
          }
          *(undefined4 *)(puVar4 + -0x144) = 0;
          if (IP1 == 0) {
            ffree(Var13);
            Var13 = thunk_FUN_0054d831(&DAT_007644d8,0xf);
          }
          if (DAT_020b9454 < IP3) {
            if (IP3 < 0x270e) {
              *(undefined4 *)(puVar4 + -0x138) = 0;
            }
            else {
              IP2 = IP2 + 1;
              IP7 = 0x271a - IP3;
              *(int *)(&DAT_020b909c + IP2 * 4) = IP7;
              *(int *)(&DAT_020b90a0 + IP2 * 4) = IP7;
            }
            goto LAB_004b1e6e;
          }
          *(undefined4 *)(puVar4 + -0x13c) = 0;
        }
        *(undefined4 *)(puVar4 + -0x154) = 0;
LAB_004b1e6e:
        *(undefined4 *)(puVar4 + -0x134) = 0;
        *(int *)(puVar4 + -0x130) = IP2;
        IP1 = 1;
        iVar7 = IP2;
        while( true ) {
          if (iVar7 < 1) {
            *(undefined4 *)(puVar4 + -0x128) = 0;
            goto LAB_004b350a;
          }
          if (((*(int *)(&DAT_020b909c + IP1 * 4) == 0xc) ||
              (*(int *)(&DAT_020b909c + IP1 * 4) == 9)) ||
             (*(int *)(&DAT_020b909c + IP1 * 4) == 0xb)) break;
          IP1 = IP1 + 1;
          *(int *)(puVar4 + -0x130) = *(int *)(puVar4 + -0x130) + -1;
          iVar7 = *(int *)(puVar4 + -0x130);
        }
        *(undefined4 *)(puVar4 + -300) = 0;
        DAT_0089f204 = 1;
LAB_004b1f09:
        IP1 = 1;
        IP8 = (&ITEM_PTR0)[DAT_0089f204];
        fVar1 = (float)(&ITEM_LEN)[IP8];
        *(undefined2 *)(puVar4 + -0x240) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
        *(int *)(puVar4 + -0x23c) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0x240);
        IP9 = *(int *)(puVar4 + -0x23c);
        IP14 = 0;
LAB_004b1f75:
        while ((DAT_020b9448 = *(int *)(&DAT_020b909c + IP1 * 4), 6 < DAT_020b9448 &&
               (DAT_020b9448 < 0xf))) {
          if (DAT_020b9448 == 0xd) {
            IP14 = 1;
          }
          if (DAT_020b9448 == 0xe) {
            IP14 = 0;
          }
          IP1 = IP1 + 1;
          *(undefined4 *)(puVar4 + -0x120) = 0;
        }
        *(undefined4 *)(puVar4 + -0x124) = 0;
        ffree(Var13);
        Var13 = FUN_004b3b4d(&DAT_0089f200);
        DAT_020b9448 = IP3;
        IP1 = IP1 + 1;
        ffree(Var13);
        Var13 = FUN_004b3b4d(&DAT_020b9444);
        switch(DAT_020b9448) {
        case 1:
          if (DAT_020b9444 != DAT_0089f200) {
            *(undefined4 *)(puVar4 + -0x114) = 0;
LAB_004b2266:
            while( true ) {
              if ((IP3 == 9) || (IP2 <= IP1)) {
                *(undefined4 *)(puVar4 + -0xec) = 0;
                goto LAB_004b2cf9;
              }
              if (IP14 == 0) goto LAB_004b2306;
              *(undefined4 *)(puVar4 + -0xe8) = 0;
              if (IP3 == 0xd) {
                IP14 = 1;
              }
              if (IP3 == 0xe) {
                IP14 = 0;
              }
              if (IP3 == 8) break;
              IP1 = IP1 + 1;
              IP3 = *(int *)(&DAT_020b909c + IP1 * 4);
              *(undefined4 *)(puVar4 + -0xd4) = 0;
            }
            *(undefined4 *)(puVar4 + -0xd8) = 0;
            goto LAB_004b1f75;
          }
          *(undefined4 *)(puVar4 + -0x118) = 0;
          break;
        case 2:
          if (DAT_020b9444 == DAT_0089f200) {
            *(undefined4 *)(puVar4 + -0x10c) = 0;
            goto LAB_004b2266;
          }
          *(undefined4 *)(puVar4 + -0x110) = 0;
          break;
        case 3:
          if (DAT_020b9444 <= DAT_0089f200) {
            *(undefined4 *)(puVar4 + -0x104) = 0;
            goto LAB_004b2266;
          }
          *(undefined4 *)(puVar4 + -0x108) = 0;
          break;
        case 4:
          if (DAT_0089f200 < DAT_020b9444) {
            *(undefined4 *)(puVar4 + -0xfc) = 0;
            goto LAB_004b2266;
          }
          *(undefined4 *)(puVar4 + -0x100) = 0;
          break;
        case 5:
          if (DAT_020b9444 <= DAT_0089f200) {
            *(undefined4 *)(puVar4 + -0xf4) = 0;
            goto LAB_004b2266;
          }
          *(undefined4 *)(puVar4 + -0xf8) = 0;
          break;
        case 6:
          if (DAT_0089f200 < DAT_020b9444) goto LAB_004b2266;
          *(undefined4 *)(puVar4 + -0xf0) = 0;
          break;
        default:
          goto LAB_004b2d02;
        }
        while( true ) {
          if (IP3 == 9) {
            *(undefined4 *)(puVar4 + -0xd0) = 0;
            goto LAB_004b239d;
          }
          if (IP14 == 0) goto LAB_004b21e5;
          *(undefined4 *)(puVar4 + -0xcc) = 0;
          if (IP3 == 0xd) {
            IP14 = 1;
          }
          if (IP3 == 0xe) {
            IP14 = 0;
          }
          if (IP3 == 7) break;
          IP1 = IP1 + 1;
          IP3 = *(int *)(&DAT_020b909c + IP1 * 4);
          *(undefined4 *)(puVar4 + -0xb8) = 0;
        }
        *(undefined4 *)(puVar4 + -0xbc) = 0;
        goto LAB_004b1f75;
      }
      *(undefined4 *)(puVar4 + -0x1ec) = 0;
      goto LAB_004b350a;
    }
    *(undefined4 *)(puVar4 + -500) = 0;
  }
  *DAT_01fbb7c0 = DAT_0089f218 + -1;
  *(int *)(puVar4 + -0x23c) = VEC_BASE;
  *(int *)(puVar4 + -0x240) = VEC_STRIDE;
  *(undefined4 *)(puVar4 + -0x244) = 0x10;
  *(int *)(puVar4 + -0x248) = VEC_STRIDE * VEC_LBOUND;
  iVar7 = DAT_0089f218;
  for (iVar3 = 1; iVar3 <= *(int *)(puVar4 + -0x244); iVar3 = iVar3 + 1) {
    *(undefined4 *)
     ((*(int *)(puVar4 + -0x23c) - *(int *)(puVar4 + -0x248)) + *(int *)(puVar4 + -0x240) * iVar7) =
         0;
    iVar7 = iVar7 + 1;
  }
  ffree(Var13);
  Var13 = thunk_FUN_0058c344();
  ffree(Var13);
  Var13 = thunk_FUN_00549422();
  DAT_01fbb8a0 = 0;
LAB_004b2da9:
  P2 = f_0;
  P3 = f_0;
  P4 = f_0;
  DAT_0078b4e0 = 1;
  ffree(Var13);
  Var13 = thunk_FUN_0058c344();
LAB_004b350a:
  if (DAT_0089f21c == 0) {
    *(undefined4 *)(puVar4 + -4) = 0;
  }
  else {
    ffree(Var13);
    Var13 = FUN_004b47b5();
    DAT_0205274c = 0;
  }
LAB_004b352b:
  ffree(Var13);
  return;
LAB_004b2d02:
  *(undefined4 *)(puVar4 + -0x11c) = 0;
LAB_004b2d0c:
  DAT_0089f204 = DAT_0089f204 + 1;
LAB_004b2d1b:
  if (ITEM_I < DAT_0089f204) {
    if (IP10 != 0) {
      DAT_020b9448 = 999;
      DAT_020b944c = 0;
      P3 = (float)-(float10)f_9999;
      *(int *)(puVar4 + -0x28) = IP10;
      IP1 = 1;
      P2 = f_9999;
      iVar7 = IP10;
      while (0 < iVar7) {
        _DAT_020b8eac = (float)(&ITEM_P3)[(&ITEM_PTR0)[(&DAT_020492a4)[IP1]]];
        DAT_020b8ea8 = (float)(&ITEM_P2)[(&ITEM_PTR0)[(&DAT_020492a4)[IP1]]];
        if (_DAT_020b8eac < P2) {
          P2 = _DAT_020b8eac;
        }
        if (P3 < _DAT_020b8eac) {
          P3 = _DAT_020b8eac;
        }
        *(undefined2 *)(puVar4 + -0x240) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
        *(int *)(puVar4 + -0x23c) = (int)ROUND(DAT_020b8ea8);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0x240);
        DAT_0089f1fc = *(int *)(puVar4 + -0x23c);
        if (DAT_0089f1fc < DAT_020b9448) {
          DAT_020b9448 = DAT_0089f1fc;
        }
        if (DAT_020b944c < DAT_0089f1fc) {
          DAT_020b944c = DAT_0089f1fc;
        }
        IP1 = IP1 + 1;
        *(int *)(puVar4 + -0x28) = *(int *)(puVar4 + -0x28) + -1;
        iVar7 = *(int *)(puVar4 + -0x28);
      }
      IP3 = 0x15;
      *(undefined4 *)(puVar4 + -0x238) = 0;
      *(undefined4 *)(puVar4 + -0x250) = 0x12;
      *(undefined **)(puVar4 + -0x24c) = &DAT_007924d0;
      *(undefined4 *)(puVar4 + -0x248) = 6;
      *(char **)(puVar4 + -0x244) = "binary";
      *(undefined4 *)(puVar4 + -0x240) = 2;
      *(undefined4 *)(puVar4 + -0x23c) = 4;
      ffree((float10)f_9999);
      Var13 = FUN_005f6540(puVar4 + -0x238,0x15,0x784ff00,&DAT_0076449c,puVar4 + -0x250);
      *(undefined2 *)(puVar4 + -0x240) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
      *(int *)(puVar4 + -0x23c) = (int)ROUND(P2 * f_150 - f_100);
      DAT_0089f224 = *(int *)(puVar4 + -0x23c);
      *(undefined2 *)(puVar4 + -0x240) = *(undefined2 *)(puVar4 + -0x240);
      *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
      *(int *)(puVar4 + -0x23c) = (int)ROUND(P3 * f_150 + f_100);
      uVar12 = *(undefined2 *)(puVar4 + -0x240);
      IP1 = *(int *)(puVar4 + -0x23c);
      *(undefined4 *)(puVar4 + -0x238) = 0;
      *(int **)(puVar4 + -0x240) = &IP10;
      ffree(Var13);
      Var13 = FUN_005fa4d0(puVar4 + -0x238,IP3,0x784ff00,&DAT_00764490,puVar4 + -0x240);
      *(int **)(puVar4 + -0x240) = &DAT_020b9448;
      ffree(Var13);
      Var13 = FUN_005fa9f0(puVar4 + -0x238,&DAT_00764490,puVar4 + -0x240);
      *(float **)(puVar4 + -0x240) = &P2;
      ffree(Var13);
      Var13 = FUN_005fa9f0(puVar4 + -0x238,&DAT_0076448c,puVar4 + -0x240);
      *(float **)(puVar4 + -0x240) = &P3;
      ffree(Var13);
      Var13 = FUN_005fa9f0(puVar4 + -0x238,&DAT_0076448c,puVar4 + -0x240);
      *(int **)(puVar4 + -0x240) = &DAT_020b944c;
      ffree(Var13);
      Var13 = FUN_005fa9f0(puVar4 + -0x238,&DAT_00764490,puVar4 + -0x240);
      *(int **)(puVar4 + -0x240) = &DAT_0089f224;
      ffree(Var13);
      Var13 = FUN_005fa9f0(puVar4 + -0x238,&DAT_00764490,puVar4 + -0x240);
      *(int **)(puVar4 + -0x240) = &IP1;
      ffree(Var13);
      Var13 = FUN_005fa9f0(puVar4 + -0x238,&DAT_00764488,puVar4 + -0x240);
      *(int *)(puVar4 + -0x1c) = IP10;
      DAT_0089f224 = 1;
      iVar7 = IP10;
      while (0 < iVar7) {
        IP1 = (&ITEM_PTR0)[(&DAT_020492a4)[DAT_0089f224]];
        fVar1 = (float)(&ITEM_LEN)[IP1];
        *(undefined2 *)(puVar4 + -0x240) = uVar12;
        *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
        *(int *)(puVar4 + -0x23c) = (int)ROUND(fVar1);
        uVar12 = *(undefined2 *)(puVar4 + -0x240);
        IP7 = *(int *)(puVar4 + -0x23c);
        *(undefined4 *)(puVar4 + -0x238) = 0;
        *(int **)(puVar4 + -0x240) = &IP7;
        ffree(Var13);
        Var13 = FUN_005fa4d0(puVar4 + -0x238,IP3,0x784ff00,&DAT_00764490,puVar4 + -0x240);
        iVar7 = IP7 + 1;
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        DAT_0089f1e8 = IP1 + iVar7;
        *(undefined4 *)(puVar4 + -0x250) = 1;
        *(undefined4 **)(puVar4 + -0x24c) = &ITEM_LEN + IP1;
        *(undefined4 *)(puVar4 + -0x248) = 1;
        *(int *)(puVar4 + -0x244) = iVar7;
        *(undefined4 *)(puVar4 + -0x240) = 4;
        ffree(Var13);
        Var13 = FUN_005fa9f0(puVar4 + -0x238,&DAT_00764484,puVar4 + -0x250);
        DAT_0089f224 = DAT_0089f224 + 1;
        *(int *)(puVar4 + -0x1c) = *(int *)(puVar4 + -0x1c) + -1;
        iVar7 = *(int *)(puVar4 + -0x1c);
      }
      *(undefined4 *)(puVar4 + -0x238) = 0;
      ffree(Var13);
      FUN_005f7950(puVar4 + -0x238,IP3,0x784ff00,&DAT_007643ac,0);
      FUN_005f33c9(puVar4,0x4b336f);
      Var13 = FUN_005f34d1(puVar4,0x4b338a);
      ffree(Var13);
      Var13 = thunk_FUN_0058c2c9(&DAT_009ae2bc,0x200,&DAT_00764580,&DAT_00764584,"(1i3)",5,
                                 &DAT_020b9448);
      ffree(Var13);
      Var13 = thunk_FUN_0058c2c9(&DAT_009ae2bc,0x200,&DAT_00764458,&DAT_00764568,"(1i3)",5,
                                 &DAT_020b944c);
      ffree(Var13);
      Var13 = thunk_FUN_0058c248(&DAT_009ae2bc,0x200,&DAT_0076444c,&DAT_00764570,"(1f5.1)",7,&P2);
      ffree(Var13);
      Var13 = thunk_FUN_0058c248(&DAT_009ae2bc,0x200,&DAT_00764444,&DAT_00764448,"(1f5.1)",7,&P3);
      *(undefined4 *)(puVar4 + -0x10) = 0;
      goto LAB_004b352b;
    }
    *(undefined4 *)(puVar4 + -0x2c) = 0;
    DAT_0078b4e4 = 0;
    if (((f_0 <= P4) || (P2 != f_6)) || (P3 != f_1000008)) {
      *(undefined4 *)(puVar4 + -0xc) = 0;
      goto LAB_004b2da9;
    }
    *(undefined4 *)(puVar4 + -8) = 0;
    goto LAB_004b350a;
  }
  *(undefined4 *)(puVar4 + -0x30) = 0;
  goto LAB_004b1f09;
LAB_004b2306:
  if ((IP3 == 8) && (IP14 == 0)) goto LAB_004b2378;
  if (IP3 == 0xe) {
    IP14 = 0;
  }
  if (IP3 == 0xd) {
    IP14 = 1;
  }
  if (IP3 == 9) {
    *(undefined4 *)(puVar4 + -0xe0) = 0;
    goto LAB_004b2cf9;
  }
  IP1 = IP1 + 1;
  IP3 = *(int *)(&DAT_020b909c + IP1 * 4);
  *(undefined4 *)(puVar4 + -0xdc) = 0;
  goto LAB_004b2306;
LAB_004b2378:
  *(undefined4 *)(puVar4 + -0xe4) = 0;
  goto LAB_004b1f75;
LAB_004b21e5:
  if ((IP3 == 7) && (IP14 == 0)) goto LAB_004b2257;
  if (IP3 == 0xe) {
    IP14 = 0;
  }
  if (IP3 == 0xd) {
    IP14 = 1;
  }
  if (IP3 != 9) goto code_r0x004b2229;
  *(undefined4 *)(puVar4 + -0xc4) = 0;
LAB_004b239d:
  DAT_020b9450 = IP1;
  if ((IP10 == 0) && (*(int *)(&DAT_020b90a0 + IP1 * 4) == 0xc)) {
    IP5 = 0x15;
  }
  else {
    *(undefined4 *)(puVar4 + -0xb4) = 0;
  }
  goto LAB_004b23d9;
LAB_004b2257:
  *(undefined4 *)(puVar4 + -200) = 0;
  goto LAB_004b1f75;
code_r0x004b2229:
  IP1 = IP1 + 1;
  IP3 = *(int *)(&DAT_020b909c + IP1 * 4);
  *(undefined4 *)(puVar4 + -0xc0) = 0;
  goto LAB_004b21e5;
LAB_004b23d9:
  if (IP2 < DAT_020b9450) {
    *(undefined4 *)(puVar4 + -0xb0) = 0;
LAB_004b2cf9:
    *(undefined4 *)(puVar4 + -0x34) = 0;
    goto LAB_004b2d0c;
  }
  DAT_020b9450 = DAT_020b9450 + 1;
  if (*(int *)(&DAT_020b909c + DAT_020b9450 * 4) == 0xb) {
    DAT_0089f200 = P2;
    ffree(Var13);
    Var13 = thunk_FUN_0045deb2(&DAT_0089f204);
    P2 = DAT_0089f200;
    *(undefined4 *)(puVar4 + -0xa8) = 0;
    goto LAB_004b2d1b;
  }
  *(undefined4 *)(puVar4 + -0xac) = 0;
  if (*(int *)(&DAT_020b909c + DAT_020b9450 * 4) == 0xc) {
    IP10 = IP10 + 1;
    (&DAT_020492a4)[IP10] = DAT_0089f204;
    *(undefined4 *)(puVar4 + -0xa0) = 0;
    goto LAB_004b2cf9;
  }
  *(undefined4 *)(puVar4 + -0xa4) = 0;
  *(undefined4 *)(puVar4 + -0x9c) = 0;
  *(undefined4 *)(puVar4 + -0x98) = 0;
  fVar1 = *(float *)(&P0 + DAT_020b9450 * 4);
  *(undefined2 *)(puVar4 + -0x240) = in_FPUControlWord;
  *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
  *(int *)(puVar4 + -0x23c) = (int)ROUND(fVar1 - f_1000000);
  in_FPUControlWord = *(undefined2 *)(puVar4 + -0x240);
  DAT_0089f1fc = *(int *)(puVar4 + -0x23c);
  if (DAT_0089f1fc < 0x28) {
    *(undefined4 *)(puVar4 + -0x94) = 0;
    _DAT_0089f1f8 = (float)DAT_0089f1fc;
    if ((IP9 < DAT_0089f1fc) && ((float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_0089f204]] != f_16)) {
      ffree(Var13);
      Var13 = thunk_FUN_005239c9(&DAT_0089f204,&DAT_0089f1f8);
      IP9 = DAT_0089f1fc;
    }
  }
  else {
    ffree(Var13);
    Var13 = FUN_004b3534(&DAT_0089f1fc,&DAT_0089f204,&P1 + DAT_020b9450);
    *(undefined4 *)(puVar4 + -0x90) = 0;
  }
  DAT_020b9450 = DAT_020b9450 + 1;
  IP6 = *(int *)(&P0 + DAT_020b9450 * 4);
  if (f_1000000 < (float)IP6) {
    *(undefined2 *)(puVar4 + -0x240) = in_FPUControlWord;
    *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
    *(int *)(puVar4 + -0x23c) = (int)ROUND((float)IP6 - f_1000000);
    in_FPUControlWord = *(undefined2 *)(puVar4 + -0x240);
    IP6 = (&ITEM_LEN)[*(int *)(puVar4 + -0x23c) + IP8];
  }
  while ((DAT_0089f1f4 = *(int *)(&DAT_020b909c + DAT_020b9450 * 4), DAT_0089f1f4 == 0xd ||
         (DAT_0089f1f4 == 0xe))) {
    DAT_020b9450 = DAT_020b9450 + 1;
    *(undefined4 *)(puVar4 + -0x88) = 0;
  }
  *(undefined4 *)(puVar4 + -0x8c) = 0;
  if (0xe < DAT_0089f1f4) goto LAB_004b2625;
  *(undefined4 *)(puVar4 + -0x84) = 0;
  while( true ) {
    *(undefined4 *)(puVar4 + -0x80) = 0;
    DAT_0089f1f4 = *(int *)(&DAT_020b909c + DAT_020b9450 * 4);
    if (DAT_0089f1f4 < 0xf) break;
    *(undefined4 *)(puVar4 + -0x7c) = 0;
LAB_004b2625:
    DAT_020b9450 = DAT_020b9450 + 1;
    DAT_020b9440 = *(float *)(&P0 + DAT_020b9450 * 4);
    if (f_1000000 < DAT_020b9440) {
      *(undefined2 *)(puVar4 + -0x240) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x23e) = (ushort)*(undefined4 *)(puVar4 + -0x240) | 0xc00;
      *(int *)(puVar4 + -0x23c) = (int)ROUND(DAT_020b9440 - f_1000000);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0x240);
      DAT_020b9440 = (float)(&ITEM_LEN)[*(int *)(puVar4 + -0x23c) + IP8];
    }
    if (DAT_0089f1f4 == 0xf) {
      IP6 = (int)(DAT_020b9440 + (float)IP6);
    }
    if (DAT_0089f1f4 == 0x10) {
      IP6 = (int)((float)IP6 - DAT_020b9440);
    }
    if ((DAT_0089f1f4 == 0x11) && (DAT_020b9440 != f_0)) {
      IP6 = (int)((float)IP6 / DAT_020b9440);
    }
    if (DAT_0089f1f4 == 0x12) {
      IP6 = (int)(DAT_020b9440 * (float)IP6);
    }
  }
  if ((float)(&ITEM_P1)[IP8] == f_16) {
    if (DAT_0089f1fc == 0x1a) {
      if ((float)IP6 != f_0) {
        *(undefined4 *)(puVar4 + -0x70) = 0;
        DAT_0089f1fc = 0x10;
        if (*(float *)(&ITEM_P14 + IP8 * 4) == f_m1) {
          *(undefined4 *)(puVar4 + -0x60) = 0;
        }
        else {
          iVar7 = ((IP8 - ITEM_WORDS) + 0xd) / -1;
          *(int *)(puVar4 + -0x5c) = iVar7;
          IP1 = ITEM_WORDS;
          while (0 < iVar7) {
            (&ITEM_P3)[IP1] = (&ITEM_LEN)[IP1];
            IP1 = IP1 + -1;
            *(int *)(puVar4 + -0x5c) = *(int *)(puVar4 + -0x5c) + -1;
            iVar7 = *(int *)(puVar4 + -0x5c);
          }
          ITEM_WORDS = ITEM_WORDS + 3;
          (&ITEM_LEN)[IP8] = (float)(&ITEM_LEN)[IP8] + f_3;
          *(float *)(&ITEM_P14 + IP8 * 4) = f_m1;
          *(float *)(&ITEM_P15 + IP8 * 4) = f_0;
          ffree(Var13);
          Var13 = index_items();
          *(undefined4 *)(puVar4 + -0x58) = 0;
        }
        goto LAB_004b2ab4;
      }
      if (*(float *)(&ITEM_P14 + IP8 * 4) == f_m1) {
        IP1 = IP8 + 0xe;
        iVar7 = (ITEM_WORDS - IP1) + 1;
        *(int *)(puVar4 + -0x68) = iVar7;
        while (0 < iVar7) {
          (&ITEM_LEN)[IP1] = (&ITEM_P3)[IP1];
          IP1 = IP1 + 1;
          *(int *)(puVar4 + -0x68) = *(int *)(puVar4 + -0x68) + -1;
          iVar7 = *(int *)(puVar4 + -0x68);
        }
        ITEM_WORDS = ITEM_WORDS + -3;
        (&ITEM_LEN)[IP8] = (float)(&ITEM_LEN)[IP8] - f_3;
        ffree(Var13);
        Var13 = index_items();
        *(undefined4 *)(puVar4 + -100) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -0x6c) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar4 + -0x74) = 0;
      DAT_0089f1f0 = 0xd;
      if (*(float *)(&ITEM_P14 + IP8 * 4) == f_m1) {
        DAT_0089f1f0 = 0x10;
      }
      if ((((float)IP6 != f_0) || (DAT_0089f1fc != 0xe)) || (DAT_0089f1f0 != 0x10)) {
        if ((DAT_0089f1fc == 0xe) && (DAT_0089f1f0 != 0x10)) {
          iVar7 = ((IP8 - ITEM_WORDS) + 0xd) / -1;
          *(int *)(puVar4 + -0x50) = iVar7;
          DAT_0089f1ec = ITEM_WORDS;
          while (0 < iVar7) {
            (&ITEM_P3)[DAT_0089f1ec] = (&ITEM_LEN)[DAT_0089f1ec];
            DAT_0089f1ec = DAT_0089f1ec + -1;
            *(int *)(puVar4 + -0x50) = *(int *)(puVar4 + -0x50) + -1;
            iVar7 = *(int *)(puVar4 + -0x50);
          }
          ITEM_WORDS = ITEM_WORDS + 3;
          (&ITEM_LEN)[IP8] = (float)(&ITEM_LEN)[IP8] + f_3;
          ffree(Var13);
          Var13 = index_items();
          IP9 = IP9 + 3;
          IP6 = (int)f_m1;
          *(undefined4 *)(puVar4 + -0x4c) = 0;
        }
        else {
          if ((DAT_0089f1fc == 0xe && (float)IP6 != f_m1) ||
             ((0xe < DAT_0089f1fc && DAT_0089f1fc < 0x5a) && *(float *)(&ITEM_P14 + IP8 * 4) != f_m1
             )) {
            *(undefined4 *)(puVar4 + -0x48) = 0;
            goto LAB_004b352b;
          }
          if ((DAT_0089f1fc < 0xe) || (DAT_0089f1f0 == 0xd)) {
            *(undefined4 *)(puVar4 + -0x44) = 0;
          }
          else {
            if ((DAT_0089f1fc == 0xe) && ((float)IP6 != f_m1)) goto LAB_004b2b2f;
            if (DAT_0089f1f0 < DAT_0089f1fc) {
              *(undefined4 *)(puVar4 + -0x3c) = 0;
              goto LAB_004b2cf9;
            }
          }
        }
        goto LAB_004b2ab4;
      }
      *(undefined4 *)(puVar4 + -0x54) = 0;
LAB_004b2b2f:
      ffree(Var13);
      Var13 = thunk_FUN_0054c590(&ITEM_P17 + IP8 * 4,&ITEM_P14 + IP8 * 4,&ITEM_WORDS);
      ITEM_WORDS = ITEM_WORDS + -3;
      (&ITEM_LEN)[IP8] = (float)(&ITEM_LEN)[IP8] - f_3;
      ffree(Var13);
      Var13 = index_items();
      IP9 = IP9 + -3;
      *(undefined4 *)(puVar4 + -0x40) = 0;
    }
    goto LAB_004b2cf9;
  }
  *(undefined4 *)(puVar4 + -0x78) = 0;
LAB_004b2ab4:
  if (*(float *)(&DAT_020b9358 + DAT_020b9450 * 4) < f_1000040) {
    (&ITEM_LEN)[DAT_0089f1fc + IP8] = IP6;
  }
  if ((*(int *)(&DAT_020b909c + DAT_020b9450 * 4) != 10) &&
     (*(int *)(&DAT_020b909c + DAT_020b9450 * 4) != 7)) goto LAB_004b2cf9;
  *(undefined4 *)(puVar4 + -0x38) = 0;
  goto LAB_004b23d9;
}


