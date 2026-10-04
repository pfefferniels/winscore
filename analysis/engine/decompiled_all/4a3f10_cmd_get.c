// cmd_get @ 004a3f10 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004a424b) */
/* WARNING: Removing unreachable block (ram,0x004a41cb) */
/* WARNING: Removing unreachable block (ram,0x004a4293) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cmd_get(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  puVar2 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  DAT_0078de00 = 0;
  if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x48) {
    thunk_FUN_00518b3f(&DAT_007639b4);
    if (P2 == f_0) {
      P2 = f_1;
    }
    DAT_00838c1c = (int)ROUND(P2);
    FUN_005f33c9(&stack0xfffffffc,0x4a3fba);
    FUN_005f33c9(puVar2,0x4a3fd6);
    FUN_005f34d1(puVar2,0x4a3ff1);
    *(undefined4 *)(puVar2 + -0x58) = 0;
  }
  else {
    puVar2 = &stack0xfffffffc;
    if ((DAT_009ae2bc & 0xffffff) != 0x527e7e) {
      DAT_00838c18 = DAT_0078b4e4;
      if (DAT_0078b4e4 != 0x4d) {
        if ((_DAT_020b8ea0 & 0xffffff) == 0x565347) {
          FUN_005f33c9(&stack0xfffffffc,0x4a407a);
          FUN_005f34d1(puVar6,0x4a4095);
          DAT_020527e8 = ITEM_I;
          DAT_020527a0 = ITEM_WORDS;
          *(undefined4 *)(puVar6 + -0x4c) = 0;
          puVar2 = puVar6;
          goto LAB_004a40fe;
        }
        iVar1 = thunk_FUN_00579410(&DAT_00763990);
        if (iVar1 != -1) {
          puVar4 = &DAT_01c4cb60;
          puVar5 = &DAT_0078b510;
          for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          FUN_005f34d1(&stack0xfffffffc,0x4a4799);
          draw_items();
          *(undefined4 *)(puVar7 + -0x44) = 0;
          return;
        }
      }
      puVar2 = &stack0xfffffffc;
      DAT_0078b4e4 = DAT_00838c18;
      if (DAT_00838c18 == 0x50) {
        puVar4 = &DAT_0078b590;
        puVar5 = &DAT_01c4cb60;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        puVar4 = &DAT_0078b510;
        puVar5 = &DAT_0078b590;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        goto LAB_004a46a4;
      }
    }
LAB_004a40fe:
    puVar4 = &DAT_009ae2bc;
    puVar5 = &DAT_00838c28;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_005f33c9(puVar2,0x4a412f);
    FUN_005f34d1(puVar2,0x4a414a);
    if ((char)DAT_00838c28 == '~') {
      thunk_FUN_0054c83c(&DAT_00838c28,0x200,&DAT_0076398c);
      *(undefined4 *)(puVar2 + -0x34) = 0x200;
      DAT_00838c1c = 0x200;
LAB_004a4199:
      if (*(char *)(DAT_00838c1c + 0x838c27) < ' ') {
        *(undefined1 *)(DAT_00838c1c + 0x838c27) = 0x20;
      }
      iVar1 = FUN_005f4660(0x20);
      if (iVar1 == 0) goto code_r0x004a41f2;
      iVar1 = FUN_005f4660(0x20);
      if ((iVar1 == 0) && (iVar1 = FUN_005f4660(0x20), iVar1 == 0)) {
        *(undefined4 *)(puVar2 + -0x2c) = 0;
        puVar4 = &DAT_00838c28;
        puVar5 = &DAT_009ae2bc;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        goto LAB_004a42da;
      }
      goto LAB_004a459e;
    }
    *(undefined4 *)(puVar2 + -0x38) = 0;
LAB_004a42da:
    thunk_FUN_0054c83c(&DAT_020b90a0,1,&DAT_0076398c);
    if ((_DAT_020b8ea0 & 0xffff) == 0x4d47) {
      puVar4 = (undefined4 *)&DAT_020b90a0;
      puVar5 = &DAT_009ae2bc;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = (undefined4 *)&DAT_020b8ea0;
      puVar5 = &DAT_00838c28;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      thunk_FUN_005725fa();
      puVar4 = &DAT_009ae2bc;
      puVar5 = (undefined4 *)&DAT_020b90a0;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_005f34d1(puVar2,0x4a4371);
      puVar4 = &DAT_00838c28;
      puVar5 = (undefined4 *)&DAT_020b8ea0;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_005f34d1(puVar2,0x4a43a5);
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4e) {
        DAT_00838c1c = 0;
        thunk_FUN_004f5268(&DAT_00838c1c);
        _DAT_020b8ea0 = CONCAT12(DAT_00763978,DAT_020b8ea0);
        FUN_005f33c9(puVar2,0x4a4400);
        _DAT_020b90a0 = i_542264647;
      }
      else if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x42) {
        DAT_00838c1c = 1;
        thunk_FUN_004f5268(&DAT_00838c1c);
        _DAT_020b8ea0 = CONCAT12(DAT_00763970,DAT_020b8ea0);
        FUN_005f33c9(puVar2,0x4a4477);
        _DAT_020b90a0 = i_541871431;
        FUN_004a47b0(&DAT_00763968,&DAT_00838c18);
        DAT_0078de00 = DAT_00838c18 + 1;
      }
    }
    else {
      *(undefined4 *)(puVar2 + -0x18) = 0;
    }
  }
  if ((_DAT_020b90a0 >> 0x10 & 0xff) == 0x49) {
    _DAT_020b90a0 = CONCAT12(DAT_00763964,_DAT_020b90a0);
  }
  FUN_004a4ae3(&DAT_01c4cb60,0x80);
  if (DAT_0078b4e4 == 0) {
    *(undefined4 *)(puVar2 + -0x14) = 0;
    return;
  }
  puVar3 = puVar2;
  FUN_005f34d1(puVar2,0x4a4513);
  if ((_DAT_020b8ea0 & 0xffff) == 0x4d47) {
    puVar4 = &DAT_0078b510;
    puVar5 = &DAT_01b12ae0;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_01c4cb60;
    puVar5 = &DAT_01b12b60;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    thunk_FUN_0054cd71(&DAT_01b12ae0,1,&DAT_00763960,&DAT_00838c1c);
    thunk_FUN_0054cd71(&DAT_01b12b60,1,&DAT_00763960,&DAT_00838c1c);
  }
  else {
    *(undefined4 *)(puVar3 + -0x10) = 0;
  }
LAB_004a46a4:
  DAT_01c4ef44 = ITEM_I;
  DAT_01c4ef48 = DAT_0078b4e4;
  load_score();
  if (DAT_0078b4e0 == -99) {
    ITEM_I = DAT_020527e8;
    ITEM_WORDS = DAT_020527a0;
    if (DAT_020527a0 < 1) {
      ITEM_WORDS = 1;
    }
    *(undefined4 *)(puVar3 + -0xc) = 0;
  }
  else {
    redraw(&DAT_0078df04);
    if (DAT_0078b4e4 == 0) {
      *(undefined4 *)(puVar3 + -8) = 0;
    }
    else {
      _DAT_020527f8 = 0;
      if (DAT_01c4ef48 == 0x4d) {
        DAT_01c4ef48 = ITEM_I;
        _DAT_01c4ef54 = ITEM_WORDS;
        _DAT_01c4ef50 = NPT;
      }
      else {
        *(undefined4 *)(puVar3 + -4) = 0;
      }
    }
  }
  return;
code_r0x004a41f2:
  *(undefined4 *)(puVar2 + -0x30) = 0;
  *(undefined4 *)(puVar2 + -0x20) = 0;
  DAT_00838c1c = DAT_00838c1c + -1;
  *(int *)(puVar2 + -0x34) = *(int *)(puVar2 + -0x34) + -1;
  if (*(int *)(puVar2 + -0x34) < 1) {
    *(undefined4 *)(puVar2 + -0x1c) = 0;
LAB_004a459e:
    FUN_005f34d1(puVar2,0x4a45bb);
    FUN_005f33c9(puVar2,0x4a45dd);
    FUN_005f33c9(puVar2,0x4a45f9);
    FUN_005f34d1(puVar2,0x4a4614);
    *(undefined4 *)(puVar2 + -0x28) = 0x200;
    DAT_00838c14 = 1;
    do {
      if ((char)(&DAT_020b909f)[DAT_00838c14] < ' ') {
        (&DAT_020b909f)[DAT_00838c14] = 0x20;
      }
      DAT_00838c14 = DAT_00838c14 + 1;
      *(int *)(puVar2 + -0x28) = *(int *)(puVar2 + -0x28) + -1;
    } while (0 < *(int *)(puVar2 + -0x28));
    thunk_FUN_00567e5b();
    *(undefined4 *)(puVar2 + -0x24) = 0;
    return;
  }
  goto LAB_004a4199;
}


