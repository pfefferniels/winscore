// FUN_00496aee @ 00496aee (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00496e48) */
/* WARNING: Removing unreachable block (ram,0x00496f6d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496aee(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined1 *puVar9;
  
  puVar9 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if ((int)(DAT_0078b4e4 - 0x4d) < 0) {
LAB_00496b6a:
    thunk_FUN_004a4ae3(&DAT_01c4cb60,0x80);
    iVar1 = FUN_005f4660(0x20);
    puVar3 = &stack0xfffffffc;
    if ((iVar1 != 0) || (iVar1 = FUN_005f4660(0x20), puVar3 = &stack0xfffffffc, iVar1 != 0))
    goto LAB_00497113;
    iVar1 = 0x20;
    bVar8 = true;
    piVar4 = &DAT_01b12ae0;
    piVar6 = &DAT_01c4cb60;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar8 = *piVar4 == *piVar6;
      piVar4 = piVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (bVar8);
    puVar2 = &stack0xfffffffc;
    if (!bVar8) {
      iVar1 = 0x20;
      piVar4 = &DAT_01b12b60;
      piVar6 = &DAT_01c4cb60;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar8 = *piVar4 == *piVar6;
        piVar4 = piVar4 + 1;
        piVar6 = piVar6 + 1;
      } while (bVar8);
      puVar2 = &stack0xfffffffc;
      if (!bVar8) {
        puVar2 = &stack0xfffffffc;
        FUN_005f34d1(&stack0xfffffffc,0x496c1b);
      }
    }
    if ((DAT_009ae2bc & 0xffffff) == 0x577e7e) {
      *(undefined4 *)(puVar2 + -0x38) = 0;
    }
    else {
      FUN_0049731a(&DAT_01c4cb60,0x80,&DAT_0082a480);
      if (DAT_0082a480 != -1) {
        *(undefined4 *)(puVar2 + -0x30) = 0;
        puVar3 = puVar2;
        goto LAB_00497113;
      }
      *(undefined4 *)(puVar2 + -0x34) = 0;
    }
  }
  else {
    if (DAT_0078b4e4 != 0x4d) {
      DAT_0078b4e4 = (uint)DAT_020b8ea2;
      if ((DAT_0078b4e4 != 0x58) && (DAT_0078b4e4 != 0x42)) goto LAB_00497113;
      DAT_020b8ea0._1_1_ = DAT_020b8ea2;
      DAT_020b8ea2 = DAT_007631f4;
      thunk_FUN_004f41aa();
      goto LAB_00496b6a;
    }
    if (' ' < (char)DAT_01b12ae0) {
      puVar5 = &DAT_01b12ae0;
      puVar7 = (undefined4 *)&DAT_007a0b7c;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      FUN_005f34d1(&stack0xfffffffc,0x496cca);
      puVar5 = &DAT_01b12b60;
      puVar7 = &DAT_009af4bc;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar2 = puVar9;
      FUN_005f34d1(puVar9,0x496cfe);
      DAT_0082a47c = thunk_FUN_0059d400(&DAT_0082a484);
      if ((DAT_0082a47c == 2) || (DAT_0082a490 == 0)) {
        *(undefined4 *)(puVar2 + -0x24) = 0;
        return;
      }
      puVar5 = &DAT_01b12ae0;
      puVar7 = &DAT_0078b510;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      if (DAT_0082a488 != 0) {
        puVar5 = &DAT_01b12b60;
        puVar7 = &DAT_0078b510;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      if (DAT_0082a48c != 0) {
        iVar1 = FUN_005f4660(0x20);
        if (iVar1 != 0) {
          thunk_FUN_0054d831("No file name given.",0x14);
          *(undefined4 *)(puVar2 + -0x20) = 0;
          return;
        }
        puVar5 = &DAT_009ae2bc;
        puVar7 = &DAT_0078b510;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        FUN_00497193(&DAT_0078b510,0x80,&DAT_0078b690,4);
        if (DAT_0078b690 == 0x20202020) {
          FUN_00497193(&DAT_01b12ae0,0x80,&DAT_0078b690,4);
          *(undefined4 *)(puVar2 + -0x18) = 0x80;
          DAT_0082a478 = 0x80;
          do {
            iVar1 = FUN_005f4660(0x20);
            if (iVar1 == 0) {
              *(undefined4 *)(puVar2 + -0x14) = 0;
              break;
            }
            DAT_0082a478 = DAT_0082a478 + -1;
            *(int *)(puVar2 + -0x18) = *(int *)(puVar2 + -0x18) + -1;
          } while (0 < *(int *)(puVar2 + -0x18));
          if ((DAT_0078b690._1_1_ == '\0') || (DAT_0078b690 >> 8 == 0x202020)) {
            FUN_005f46bc(puVar2,0x496ef5);
            FUN_005f46bc(puVar2,0x496f11);
            FUN_005f34d1(puVar2,0x496f27);
            DAT_0082a474 = thunk_FUN_00595cd0(&DAT_020b8ea0);
            if (DAT_0082a474 == -1) {
              DAT_0078b690 = 0x53554d2e;
            }
          }
          FUN_005f46bc(puVar2,0x496f91);
          FUN_005f34d1(puVar2,0x496fa7);
        }
        else {
          *(undefined4 *)(puVar2 + -0x1c) = 0;
        }
      }
    }
    DAT_01b12ae0._0_1_ = '\0';
    puVar5 = &DAT_0078b510;
    puVar7 = &DAT_01c4cb60;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  _DAT_0082a470 = 6;
  thunk_FUN_00529628(&DAT_007631c0,&ITEM_WORDS,&ITEM_P1,&DAT_0082a470,&DAT_01c4cb60,0x80);
  if (DAT_0078b4e0 < 0) {
    *(undefined4 *)(puVar2 + -0x10) = 0;
    puVar3 = puVar2;
  }
  else {
    FUN_005f34d1(puVar2,0x49703d);
    FUN_005f33c9(puVar2,0x49705f);
    FUN_005f34d1(puVar2,0x49707a);
    _DAT_0082a46c = 0;
    thunk_FUN_00579770(&DAT_007631ac,1,&DAT_0082a468);
    FUN_00495d4f(&DAT_01c4cb60,0x80);
    thunk_FUN_0048f4eb(&DAT_01c4cb60,0x80,&DAT_007631a8);
    bVar8 = true;
    DAT_0078b4f0 = 0;
    iVar1 = 0x20;
    piVar4 = &DAT_01c4cb60;
    piVar6 = &DAT_0078b510;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar8 = *piVar4 == *piVar6;
      piVar4 = piVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (bVar8);
    if (bVar8) {
      *(undefined4 *)(puVar2 + -0xc) = 0;
    }
    else {
      puVar5 = &DAT_01c4cb60;
      puVar7 = &DAT_0078b510;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    *(undefined4 *)(puVar2 + -8) = 0;
    puVar3 = puVar2;
  }
LAB_00497113:
  *(undefined4 *)(puVar3 + -4) = 0;
  DAT_0078b4e0 = 0x20;
  return;
}


