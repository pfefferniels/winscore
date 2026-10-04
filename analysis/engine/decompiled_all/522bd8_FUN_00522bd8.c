// FUN_00522bd8 @ 00522bd8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0052319e) */
/* WARNING: Removing unreachable block (ram,0x00523089) */
/* WARNING: Removing unreachable block (ram,0x00523557) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00522bd8(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int *piVar12;
  bool bVar13;
  undefined2 in_FPUControlWord;
  undefined1 *puVar14;
  undefined1 *puVar15;
  
  puVar14 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar15 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  if (DAT_0078b4e4 == 0x53) {
    if ((DAT_0078b4f0 != 0) && (iVar3 = thunk_FUN_00579410(&DAT_00767bfc), iVar3 != -1)) {
      DAT_0078b4e0 = 0;
      return;
    }
    bVar13 = _DAT_020b90a0 >> 0x18 == 0x20;
    if (bVar13) {
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x4d) {
        DAT_0078b4e0 = 0;
        VEC_N = 0;
        *DAT_01fbb844 = 0;
        *DAT_01fbb7c0 = 0;
        DAT_00791448 = 0;
        ITEM_I = 0;
        ITEM_WORDS = 1;
        return;
      }
      puVar8 = &DAT_0078b510;
      puVar11 = (undefined4 *)&DAT_020b90a3;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
    }
    else {
      _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00767bf8);
      iVar3 = 1;
      piVar9 = (int *)&DAT_020b90a3;
      piVar12 = &DAT_00767bf4;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar13 = *piVar9 == *piVar12;
        piVar9 = piVar9 + 1;
        piVar12 = piVar12 + 1;
      } while (bVar13);
      if (bVar13) {
        DAT_0094e510 = 1;
        if (DAT_0078b460 == 0x19) {
          DAT_0094e510 = 2;
        }
        if (DAT_0078b460 == 0x1f) {
          DAT_0094e510 = 3;
        }
        FUN_005f33c9(&stack0xfffffffc,0x52392b);
        FUN_005f33c9(puVar15,0x523947);
        FUN_005f33c9(puVar15,0x523963);
        puVar5 = puVar15;
        FUN_005f34d1(puVar15,0x52397e);
      }
      thunk_FUN_004a6adc();
      puVar6 = puVar5;
    }
    DAT_0078b4e4 = 1;
    DAT_0078b4f0 = 0;
    cmd_get();
    thunk_FUN_0048ecfb();
    *(undefined4 *)(puVar6 + -0x98) = 0;
    return;
  }
  if (DAT_0078b4e4 == 0x49) {
    DAT_0094e50c = _DAT_020b8ea0 >> 0x10 & 0xff;
    if (DAT_0094e50c == 0x50) {
      thunk_FUN_0051ffc0();
    }
    thunk_FUN_00468df8(&DAT_00767c00);
    return;
  }
  DAT_01fbb798 = 0;
  bVar13 = DAT_0078b4e4 == 0x44;
  if (bVar13) {
    DAT_01fbb798 = 1;
  }
  else {
    iVar3 = 5;
    pcVar7 = (char *)&DAT_020b8ea0;
    pcVar10 = "RESTO";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar13 = *pcVar7 == *pcVar10;
      pcVar7 = pcVar7 + 1;
      pcVar10 = pcVar10 + 1;
    } while (bVar13);
    if (bVar13) {
      thunk_FUN_0047330a();
      return;
    }
    if (DAT_0078b4e4 != 0x45) {
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x55) {
        thunk_FUN_0058adc1(&DAT_00767cc8);
        return;
      }
      if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x55) {
        DAT_0094e4f8 = P2;
        thunk_FUN_0054cd13(&P1,&DAT_00767ce8);
        P2 = DAT_0094e4f8;
        if (DAT_0094e4f8 == f_0) {
          thunk_FUN_0054e546(&P2,&DAT_0094e4f4);
        }
        P5 = f_1301;
        if (_DAT_020b8ea0 >> 0x18 == 0x43) {
          P5 = f_1302;
        }
        if (DAT_020b8ea4 != 'V') {
          P1 = f_9;
          P11 = f_1;
          return;
        }
        P1 = f_9;
        P3 = f_16;
        P9 = f_m90;
        P11 = f_1;
        return;
      }
      goto LAB_00522fa4;
    }
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x44) {
      if (-1 < DAT_020b8e38) {
        thunk_FUN_0054d831("*** Nothing to REDO.",0x15);
        return;
      }
      puVar8 = &DAT_0078b510;
      puVar11 = (undefined4 *)&DAT_007a0b7c;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      DAT_01c58610 = 2;
      FUN_005f33c9(&stack0xfffffffc,0x522e00);
      FUN_005f33c9(puVar14,0x522e1c);
      FUN_005f33c9(puVar14,0x522e38);
      FUN_005f34d1(puVar14,0x522e53);
      puVar8 = (undefined4 *)&DAT_020b8ea0;
      puVar11 = (undefined4 *)&DAT_020b90a0;
      for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      DAT_0078b4f0 = 1;
      cmd_get();
      DAT_020b8e38 = 1;
      DAT_020527a0 = 0xffffffff;
      puVar8 = (undefined4 *)&DAT_007a0b7c;
      puVar11 = &DAT_0078b510;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      FUN_005f34d1(puVar14,0x522ec0);
      DAT_01c58610 = 0;
      DAT_0078b4f0 = 1;
      thunk_FUN_00495d4f(&DAT_0078b510,0x80);
      *(undefined4 *)(puVar14 + -0x34) = 0;
      return;
    }
    _DAT_0094e508 = 0;
    DAT_0094e50c = 4;
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x53) {
      DAT_01fbb798 = 2;
      DAT_0094e50c = 5;
    }
  }
  if ((_DAT_020b8ea0 & 0xffffff) == 0x504552) {
    if (DAT_02052740 == 0) {
      puVar8 = (undefined4 *)&DAT_020b8ea0;
      puVar11 = (undefined4 *)&DAT_020b90a0;
      for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
LAB_00522fa4:
      thunk_FUN_0054d7d4(&DAT_020b90a0,0x200);
      return;
    }
    puVar4 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x522fd7);
    fVar1 = P2;
    if (DAT_00794fd0 == 0) {
      *(undefined2 *)(puVar4 + -0xd4) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0xd2) = (ushort)*(undefined4 *)(puVar4 + -0xd4) | 0xc00;
      *(int *)(puVar4 + -0xd0) = (int)ROUND(fVar1);
      DAT_00794fd0 = *(int *)(puVar4 + -0xd0);
    }
    else {
      *(undefined4 *)(puVar4 + -0x5c) = 0;
    }
  }
  DAT_0094e504 = 4;
  if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x41) {
    DAT_0094e504 = 5;
  }
  if (_DAT_020b90a0 == 0x44414552) {
    DAT_0094e504 = 6;
  }
  FUN_005f46bc(puVar4,0x5230ad);
  FUN_005f34d1(puVar4,0x5230c3);
  if ((DAT_01a1fe80 & 0xffffff) == 0x525454) {
    puVar8 = &DAT_0078b610;
    puVar11 = &DAT_0094e518;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar11 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  FUN_005f34d1(puVar4,0x52310e);
  iVar3 = FUN_005f4660(0x20);
  if (iVar3 == 0) {
LAB_00523368:
    *(undefined4 *)(puVar4 + -0xcc) = 0;
    *(undefined4 *)(puVar4 + -0xe0) = 0x80;
    *(undefined4 **)(puVar4 + -0xdc) = &DAT_0094e518;
    *(uint **)(puVar4 + -0xd8) = &DAT_0094e514;
    FUN_005f47c0(puVar4 + -0xcc,0xffffffff,0x784ff00,&DAT_00767c40,puVar4 + -0xe0);
    if ((DAT_0094e514 & 1) != 0) {
      *(undefined4 *)(puVar4 + -0x40) = 0;
      DAT_02052740 = DAT_02052744;
      FUN_005f33c9(puVar4,0x523406);
      FUN_005f34d1(puVar4,0x523421);
      FUN_005f33c9(puVar4,0x523443);
      DAT_020b8ec0._2_1_ = DAT_00767c68;
      puVar8 = (undefined4 *)&DAT_020b8ea0;
      puVar11 = &DAT_009ae2bc;
      for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      _DAT_0094e4fc = ITEM_I;
      *(undefined4 *)(puVar4 + -0xcc) = 0;
      FUN_005f7950(puVar4 + -0xcc,DAT_02052740,0x784ff00,&DAT_00767c14,0);
      *(undefined4 *)(puVar4 + -0xcc) = 0;
      *(undefined4 *)(puVar4 + -0xe0) = 0x80;
      *(undefined4 **)(puVar4 + -0xdc) = &DAT_0094e518;
      *(undefined4 *)(puVar4 + -0xd8) = 2;
      *(undefined4 *)(puVar4 + -0xd4) = 4;
      FUN_005f6540(puVar4 + -0xcc,DAT_02052740,0x784ff00,&DAT_00767c04,puVar4 + -0xe0);
      if (DAT_02052740 < 0) {
        DAT_02052740 = DAT_02052748;
      }
      puVar8 = &DAT_0094e518;
      puVar11 = &DAT_0078b610;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      *(undefined4 *)(puVar4 + -0x28) = 0x40;
      DAT_0094e500 = 0x40;
      do {
        iVar3 = FUN_005f4660(0x20);
        if (iVar3 != 0) {
          *(undefined4 *)(puVar4 + -0x24) = 0;
          break;
        }
        DAT_0094e500 = DAT_0094e500 + -1;
        *(int *)(puVar4 + -0x28) = *(int *)(puVar4 + -0x28) + -1;
      } while (0 < *(int *)(puVar4 + -0x28));
      DAT_0078b460 = DAT_0094e500 + -1;
      FUN_005f46bc(puVar4,0x5235e7);
      FUN_005f46bc(puVar4,0x523603);
      FUN_005f46bc(puVar4,0x52361f);
      FUN_005f34d1(puVar4,0x523635);
      *(undefined4 *)(puVar4 + -0xcc) = 0;
      *(undefined4 *)(puVar4 + -0xe8) = 0x80;
      *(undefined4 **)(puVar4 + -0xe4) = &DAT_0094e518;
      *(undefined4 *)(puVar4 + -0xe0) = 7;
      *(char **)(puVar4 + -0xdc) = "unknown";
      *(undefined4 *)(puVar4 + -0xd8) = 2;
      uVar2 = FUN_005f6540(puVar4 + -0xcc,7,0x784ff01,&DAT_00767c50,puVar4 + -0xe8);
      *(undefined4 *)(puVar4 + -0x20) = uVar2;
      if (*(int *)(puVar4 + -0x20) == 0) {
        *(undefined4 *)(puVar4 + -0xcc) = 0;
        *(undefined4 *)(puVar4 + -0xd8) = 0x80;
        *(undefined4 **)(puVar4 + -0xd4) = &DAT_0078b610;
        uVar2 = FUN_005fc330(puVar4 + -0xcc,7,0x784ff01,&DAT_00767c4c,puVar4 + -0xd8,&DAT_00796bac);
        *(undefined4 *)(puVar4 + -0x1c) = uVar2;
        if (*(int *)(puVar4 + -0x1c) == 0) {
          *(undefined4 *)(puVar4 + -0xcc) = 0;
          FUN_005f7950(puVar4 + -0xcc,7,0x784ff00,&DAT_00767c14,0);
          _DAT_020b8e40 = 0;
          thunk_FUN_005725fa();
          *(undefined4 *)(puVar4 + -0x14) = 0;
          return;
        }
      }
    }
  }
  else {
    if ((DAT_02052740 != 0) && (DAT_00794fd0 == 0)) {
      thunk_FUN_0054d831("No file name given after \"RE\"",0x1e);
      DAT_02052740 = 0;
      *(undefined4 *)(puVar4 + -0x58) = 0;
      goto LAB_0052376b;
    }
    *(undefined4 *)(puVar4 + -0x54) = 0x40;
    DAT_0094e500 = 0x40;
    do {
      *(undefined4 *)(puVar4 + -0xd0) = 1;
      iVar3 = FUN_005f4660(0x20);
      if (iVar3 != 0) {
        *(undefined4 *)(puVar4 + -0x50) = 0;
        break;
      }
      DAT_0094e500 = DAT_0094e500 + -1;
      *(int *)(puVar4 + -0x54) = *(int *)(puVar4 + -0x54) + -1;
    } while (0 < *(int *)(puVar4 + -0x54));
    DAT_0078b460 = DAT_0094e500 + -1;
    FUN_005f46bc(puVar4,0x52323a);
    FUN_005f46bc(puVar4,0x523256);
    FUN_005f46bc(puVar4,0x523272);
    FUN_005f34d1(puVar4,0x523288);
    *(undefined4 *)(puVar4 + -0xcc) = 0;
    *(undefined4 *)(puVar4 + -0xe8) = 0x80;
    *(undefined4 **)(puVar4 + -0xe4) = &DAT_0094e518;
    *(undefined4 *)(puVar4 + -0xe0) = 7;
    *(char **)(puVar4 + -0xdc) = "unknown";
    *(undefined4 *)(puVar4 + -0xd8) = 2;
    uVar2 = FUN_005f6540(puVar4 + -0xcc,7,0x784ff01,&DAT_00767c50,puVar4 + -0xe8);
    *(undefined4 *)(puVar4 + -0x4c) = uVar2;
    if (*(int *)(puVar4 + -0x4c) == 0) {
      *(undefined4 *)(puVar4 + -0xcc) = 0;
      *(undefined4 *)(puVar4 + -0xd8) = 0x80;
      *(undefined4 **)(puVar4 + -0xd4) = &DAT_0094e518;
      uVar2 = FUN_005fdbd0(puVar4 + -0xcc,7,0x784ff01,&DAT_00767c4c,puVar4 + -0xd8,&DAT_00796b98);
      *(undefined4 *)(puVar4 + -0x48) = uVar2;
      if (*(int *)(puVar4 + -0x48) == 0) goto LAB_00523368;
    }
  }
  thunk_FUN_0042ac4e(&DAT_0094e518,0x80);
LAB_0052376b:
  *(undefined4 *)(puVar4 + -0x3c) = 0;
  DAT_00794fd0 = 0;
  DAT_0078b4e0 = 0xffffffff;
  return;
}


