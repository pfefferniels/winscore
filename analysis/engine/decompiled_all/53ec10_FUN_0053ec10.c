// FUN_0053ec10 @ 0053ec10 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053ec10(void)

{
  byte bVar1;
  byte bVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  undefined2 in_FPUControlWord;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  
  puVar9 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  puVar11 = &stack0xfffffffc;
  puVar12 = &stack0xfffffffc;
  puVar13 = &stack0xfffffffc;
  puVar14 = &stack0xfffffffc;
  puVar15 = &stack0xfffffffc;
  puVar16 = &stack0xfffffffc;
  puVar17 = &stack0xfffffffc;
  puVar18 = &stack0xfffffffc;
  puVar19 = &stack0xfffffffc;
  if (_DAT_020b8ea0 == 0x50535453) {
    thunk_FUN_00545f58();
    draw_items();
    return;
  }
  if (DAT_0078b4e4 == 0x43) {
    if (EDIT_ITEM != 0) {
      return;
    }
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x24) {
      if (DAT_007974f0 == 0) {
        _DAT_020b8ea0 = CONCAT12(DAT_00768d60,DAT_020b8ea0);
      }
      DAT_007974f0 = 1;
    }
    thunk_FUN_0054c768(&DAT_020b8ea2);
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58) {
      DAT_0078d890 = 0;
    }
    else {
      IP2 = (int)ROUND(P2);
      DAT_007974f0 = 0;
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4c) {
        bVar8 = false;
      }
      else {
        bVar8 = false;
        if ((DAT_0078d890 != 0) &&
           ((((_DAT_020b8ea0 & 0xffffff) == 0x2a4353 || (DAT_0078d890 < 0xdad)) ||
            (bVar8 = (_DAT_020b8ea0 & 0xffffff) < 0x204353, (_DAT_020b8ea0 & 0xffffff) == 0x204353))
           )) {
          bVar8 = (_DAT_020b8ea0 >> 0x10 & 0xff) < 0x56;
        }
      }
      iVar4 = 1;
      pbVar6 = (byte *)&DAT_020b8ea2;
      pbVar7 = &DAT_00768d5c;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar2 = *pbVar7;
        bVar1 = *pbVar6;
        bVar8 = bVar1 < bVar2;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar1 == bVar2);
      if (bVar8) {
        DAT_0078d890 = 1000;
      }
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x49) {
        DAT_0078d890 = 2000;
      }
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x43) {
        DAT_0078d890 = 3000;
      }
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x56) {
        DAT_0078d890 = 4000;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x43) {
        DAT_0078d890 = 5000;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x54) {
        PAPER = 1;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x47) {
        PAPER = 2;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x44) {
        PAPER = 3;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x50) {
        PAPER = 4;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x33) {
        PAPER = 5;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x34) {
        PAPER = 6;
      }
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x42) {
        PAPER = 7;
      }
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x55) {
        PAPER = 8;
      }
      if (DAT_0078d890 != 0) {
        if ((P2 == f_0) && (DAT_0078d890 < 4000)) {
          thunk_FUN_0054e546(&P2,&DAT_0099d0e8);
        }
        DAT_0078d890 = (int)ROUND((float)DAT_0078d890 + P2);
      }
      DAT_020b8ea0 = CONCAT11(0x20,DAT_00768d54);
    }
    if (EDIT_ITEM != 0) {
      DAT_01e67940 = ITEM_WORDS;
      ITEM_WORDS = DAT_020b8e44;
      draw_items();
      ITEM_WORDS = DAT_01e67940;
      return;
    }
    draw_items();
    switch(PAPER) {
    case 1:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f054);
      FUN_005f34d1(puVar9,&LAB_0053f06f);
      *(undefined4 *)(puVar9 + -0x88) = 0;
      return;
    case 2:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f0a0);
      FUN_005f34d1(puVar10,&LAB_0053f0bb);
      *(undefined4 *)(puVar10 + -0x84) = 0;
      return;
    case 3:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f0ec);
      FUN_005f34d1(puVar11,&LAB_0053f107);
      *(undefined4 *)(puVar11 + -0x80) = 0;
      return;
    case 4:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f135);
      FUN_005f34d1(puVar12,&LAB_0053f150);
      *(undefined4 *)(puVar12 + -0x7c) = 0;
      return;
    case 5:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f17e);
      FUN_005f34d1(puVar13,&LAB_0053f199);
      *(undefined4 *)(puVar13 + -0x78) = 0;
      return;
    case 6:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f1c7);
      FUN_005f34d1(puVar14,&LAB_0053f1e2);
      *(undefined4 *)(puVar14 + -0x74) = 0;
      return;
    case 7:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f210);
      FUN_005f34d1(puVar15,&LAB_0053f22b);
      *(undefined4 *)(puVar15 + -0x70) = 0;
      return;
    case 8:
      FUN_005f33c9(&stack0xfffffffc,&LAB_0053f259);
      FUN_005f34d1(puVar16,&LAB_0053f274);
      *(undefined4 *)(puVar16 + -0x10c) = 0;
      *(undefined4 *)(puVar16 + -0x120) = 5;
      *(undefined4 *)(puVar16 + -0x11c) = 0x9ae2ce;
      *(undefined4 **)(puVar16 + -0x118) = &DAT_00791630;
      FUN_005f34f0(puVar16 + -0x10c,0x784ff00,&DAT_00768c68,puVar16 + -0x120,&DAT_00797498);
      *(undefined4 *)(puVar16 + -0x10c) = 0;
      *(undefined4 *)(puVar16 + -0x120) = 5;
      *(undefined **)(puVar16 + -0x11c) = &DAT_009ae2d5;
      *(undefined4 **)(puVar16 + -0x118) = &DAT_00791634;
      FUN_005f34f0(puVar16 + -0x10c,0x784ff00,&DAT_00768c68,puVar16 + -0x120,&DAT_007974ac);
      *(undefined4 *)(puVar16 + -100) = 0;
      return;
    default:
      return;
    }
  }
  if (DAT_0078b4e4 == 0x48) {
    if (DAT_020b8ea2 == 'P') {
      thunk_FUN_00553fe4();
    }
    else if (DAT_020b8ea2 == 'M') {
      if (0 < DAT_0078d884) {
        DAT_01e67954 = 1;
        for (iVar4 = DAT_0078d884; 0 < iVar4; iVar4 = iVar4 + -1) {
          DAT_01e67940 = *(int *)((int)&DAT_0078d8a0 + DAT_01e67954 * 4 + 2);
          DAT_01e67944 = *(int *)((int)&DAT_0078d8a4 + DAT_01e67954 * 4 + 2) + -1;
          DAT_01e67954 = DAT_01e67954 + 1;
        }
      }
    }
    else {
      OUTPUT_MODE = 1;
      _DAT_0078b6ac = f_0;
      _DAT_0078b6b4 = f_0;
      _DAT_0078b6b8 = f_0;
      if (DAT_020b8ea2 == 'X') {
        OUTPUT_MODE = 0;
      }
    }
  }
  else if (DAT_0078b4e4 == 0x54) {
    if (0 < ITEM_I) {
      if ((DAT_020b8ea2 != 'M') && (DAT_020b8ea2 != 'U')) {
        return;
      }
      thunk_FUN_005770d8();
    }
  }
  else if (EDIT_ITEM == 0) {
    if (DAT_0078b4e4 == 0x50) {
      if (P2 == f_999) {
        _DAT_01fb8c64 = f_999;
        DAT_0078d960 = 0;
        DAT_01fb8c74 = 0;
        FUN_005f33c9(&stack0xfffffffc,0x53f55b);
        FUN_005f34d1(puVar17,0x53f576);
        *(undefined4 *)(puVar17 + -0x60) = 0;
      }
      else {
        _DAT_01fb8c64 = P2;
        FUN_005f33c9(&stack0xfffffffc,0x53f5b0);
        FUN_005f34d1(puVar18,0x53f5cb);
        *(undefined4 *)(puVar18 + -0x10c) = 0;
        *(undefined4 *)(puVar18 + -0x120) = 4;
        *(undefined4 *)(puVar18 + -0x11c) = 0x9ae2cb;
        *(undefined **)(puVar18 + -0x118) = &DAT_01fb8c64;
        FUN_005f34f0(puVar18 + -0x10c,0x784ff00,&DAT_00768c68,puVar18 + -0x120,&DAT_007974c0);
        fVar3 = _DAT_01fb8c64;
        DAT_009ae2cc._3_1_ = 0;
        *(undefined2 *)(puVar18 + -0x114) = in_FPUControlWord;
        *(ushort *)(puVar18 + -0x112) = (ushort)*(undefined4 *)(puVar18 + -0x114) | 0xc00;
        *(int *)(puVar18 + -0x110) = (int)ROUND(fVar3);
        DAT_0078d960 = *(int *)(puVar18 + -0x110);
        if (MAX_STAFF < DAT_0078d960) {
          DAT_0078d960 = 0;
        }
        if (DAT_0078d960 == 0) {
          _DAT_01fb8c64 = f_99;
        }
        *(undefined4 *)(puVar18 + -0x58) = 0;
      }
    }
    else {
      if ((DAT_0078b4e4 == 0x4d) || (DAT_0078b4e4 == 0x4e)) {
LAB_0053fc21:
        thunk_FUN_00496aee();
        return;
      }
      if (DAT_0078b4e4 == 0x49) {
        thunk_FUN_00575e58();
      }
      else if (DAT_0078b4e4 == 0x45) {
        if (DAT_020b8ea3 == 'Z') {
          thunk_FUN_005725fa();
          DAT_020527a0 = 0xfffffffe;
          FUN_00543b7e();
          thunk_FUN_00535d00(&DAT_00768bf8);
        }
        else if (DAT_020b8ea3 == 'X') {
          thunk_FUN_005725fa();
          DAT_020527a0 = 0xfffffffd;
          if (P2 == f_0) {
            FUN_00541619(&DAT_0099d0e4,&DAT_007974ec);
          }
          if (DAT_0099d0e4 == 2) {
            return;
          }
          DAT_01e67948 = (int)ROUND(P4);
          DAT_0099d0e4 = (int)ROUND(P3);
          if (DAT_01e67948 == 0) {
            DAT_01e67948 = DAT_0099d0e4 + 1;
          }
          if (DAT_0099d0e4 == 0) {
            DAT_0099d0e4 = DAT_01e67948 + 1;
          }
          DAT_0099d0e0 = 0;
          LOAD_I = 1;
          for (iVar4 = ITEM_I; 0 < iVar4; iVar4 = iVar4 + -1) {
            load_item_header();
            if ((LOAD_CODE != 0xe) && (DAT_01e67948 == LOAD_STAFF)) {
              if (LOAD_CODE != 8) {
                FUN_005f33c9(&stack0xfffffffc,0x53f8d4);
                FUN_005f34d1(puVar19,0x53f8ef);
                *(undefined4 *)(puVar19 + -0x10c) = 0;
                *(undefined4 *)(puVar19 + -0x120) = 3;
                *(undefined4 **)(puVar19 + -0x11c) = &DAT_020b8eb4;
                *(int **)(puVar19 + -0x118) = &DAT_01e67948;
                FUN_005f34f0(puVar19 + -0x10c,0x784ff00,&DAT_00768c04,puVar19 + -0x120,&DAT_007974d4
                            );
                thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
                *(undefined4 *)(puVar19 + -0x38) = 0;
                return;
              }
              DAT_0099d0e0 = 1;
            }
            LOAD_I = LOAD_I + 1;
          }
          LOAD_I = 1;
          DAT_01e67940 = ITEM_I;
          for (iVar4 = ITEM_I; 0 < iVar4; iVar4 = iVar4 + -1) {
            load_item_header();
            if ((DAT_0099d0e4 == LOAD_STAFF) && ((DAT_0099d0e0 == 0 || (LOAD_CODE != 8)))) {
              ITEM_I = ITEM_I + 1;
              DAT_01e67950 = LOAD_W;
              for (iVar5 = LOAD_LEN + 1; 0 < iVar5; iVar5 = iVar5 + -1) {
                (&ITEM_LEN)[ITEM_WORDS] = (&ITEM_LEN)[DAT_01e67950];
                if (LOAD_W + 2 == DAT_01e67950) {
                  (&ITEM_LEN)[ITEM_WORDS] = (float)DAT_01e67948;
                }
                ITEM_WORDS = ITEM_WORDS + 1;
                DAT_01e67950 = DAT_01e67950 + 1;
              }
            }
            LOAD_I = LOAD_I + 1;
          }
          _DAT_007974ec = (int)ROUND(P2);
          _DAT_0099d0dc = P2;
          index_items();
          _DAT_020b8ea0 = CONCAT13(0x58,_DAT_020b8ea0);
          P3 = (float)DAT_01e67948;
          FUN_0054061d();
          if (_DAT_0099d0dc == f_1) {
            P2 = f_2;
          }
          if (_DAT_0099d0dc == f_2) {
            P2 = f_1;
          }
          P3 = (float)DAT_0099d0e4;
          _DAT_020b8ea0 = CONCAT13(0x58,_DAT_020b8ea0);
          P5 = f_0;
          P4 = f_0;
          FUN_0054061d();
          DAT_020527a0 = 0xffffffff;
          thunk_FUN_00535d00(&DAT_00768bf8);
        }
        else {
          FUN_0054061d();
        }
      }
      else if (DAT_0078b4e4 == 0x41) goto LAB_0053fc21;
    }
  }
  DAT_0078b4e0 = 0;
  return;
}


