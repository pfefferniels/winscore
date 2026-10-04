// FUN_0052b61a @ 0052b61a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0052b7f1) */
/* WARNING: Removing unreachable block (ram,0x0052b664) */
/* WARNING: Removing unreachable block (ram,0x0052b6a9) */
/* WARNING: Removing unreachable block (ram,0x0052b834) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052b61a(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 local_104 [45];
  int local_50;
  undefined4 local_4c;
  undefined4 local_44;
  
  puVar7 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if (*param_1 == 0) {
    local_50 = 0x80;
    DAT_0098d68c = 1;
    do {
      iVar1 = FUN_005f4660(0x20);
      if ((iVar1 != 0) || (iVar1 = FUN_005f4660(0x20), iVar1 != 0)) {
        local_4c = 0;
        iVar1 = FUN_005f4660(0x20);
        if ((iVar1 == 0) && (iVar1 = FUN_005f4660(0x20), iVar1 == 0)) {
          _DAT_0098d688 = FUN_00601b80(&DAT_01b12cc0,0x80);
          FUN_005f33c9(&stack0xfffffffc,0x52b892);
          FUN_005f33c9(puVar8,0x52b8ae);
          puVar3 = puVar8;
          FUN_005f33c9(puVar8,0x52b8d0);
        }
        else {
          local_44 = 0;
        }
        goto LAB_0052b8dd;
      }
      DAT_0098d68c = DAT_0098d68c + 1;
      local_50 = local_50 + -1;
    } while (0 < local_50);
    _DAT_0098d688 = FUN_00601b80(&DAT_01b12cc0,0x80);
    puVar4 = &DAT_01b12cc0;
    puVar5 = local_104;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    DAT_0098d684 = FUN_005ff950(local_104,0x80);
    FUN_005f46bc(&stack0xfffffffc,0x52b76a);
    FUN_005f46bc(puVar7,0x52b786);
    FUN_005f46bc(puVar7,0x52b7a2);
    puVar3 = puVar7;
    FUN_005f33c9(puVar7,0x52b7c4);
    *(undefined4 *)(puVar3 + -0x44) = 0;
LAB_0052b8dd:
    *(undefined4 *)(puVar3 + -0x70) = 0;
    *(undefined4 *)(puVar3 + -0x80) = 0x14;
    *(char **)(puVar3 + -0x7c) = "C:\\!tmp\\!history.tmp:";
    *(undefined4 *)(puVar3 + -0x78) = 2;
    *(undefined4 *)(puVar3 + -0x74) = 4;
    uVar2 = FUN_005f6540(puVar3 + -0x70,0x11,0x784ff01,&DAT_00768084,puVar3 + -0x80);
    *(undefined4 *)(puVar3 + -0x3c) = uVar2;
    if (*(int *)(puVar3 + -0x3c) == 0) {
      DAT_0098d690 = DAT_00768080;
      *(undefined4 *)(puVar3 + -0x38) = 0x28;
      DAT_0098d68c = 1;
      do {
        *(undefined4 *)(puVar3 + -0x70) = 0;
        *(undefined4 *)(puVar3 + -0x80) = 0x80;
        *(undefined **)(puVar3 + -0x7c) = &DAT_0078b650 + DAT_0098d68c * 0x80;
        *(undefined4 *)(puVar3 + -0x78) = 0x80;
        uVar2 = FUN_005fdbd0(puVar3 + -0x70,0x11,0x784ff01,&DAT_0076807c,puVar3 + -0x80,
                             &DAT_00796db0);
        *(undefined4 *)(puVar3 + -0x34) = uVar2;
        if (*(int *)(puVar3 + -0x34) != 0) goto LAB_0052bbcc;
        DAT_0098d68c = DAT_0098d68c + 1;
        *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
      } while (0 < *(int *)(puVar3 + -0x38));
      *(undefined4 *)(puVar3 + -0x70) = 0;
      FUN_005f7950(puVar3 + -0x70,0x11,0x784ff00,&DAT_00767ff4,0);
      thunk_FUN_0054c768(&DAT_0078b510);
      *(undefined4 *)(puVar3 + -0x2c) = 0x80;
      DAT_0098d680 = 0x80;
      do {
        if (' ' < *(char *)(DAT_0098d680 + 0x78b50f)) {
          *(undefined4 *)(puVar3 + -0x28) = 0;
          break;
        }
        DAT_0098d680 = DAT_0098d680 + -1;
        *(int *)(puVar3 + -0x2c) = *(int *)(puVar3 + -0x2c) + -1;
      } while (0 < *(int *)(puVar3 + -0x2c));
      *(undefined1 *)((int)&DAT_0078b510 + DAT_0098d680) = 0;
      *(undefined4 *)(puVar3 + -0x24) = 0x28;
      DAT_0098d68c = 1;
      do {
        puVar4 = (undefined4 *)(&DAT_0078b650 + DAT_0098d68c * 0x80);
        puVar5 = &DAT_0098d698;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        *(undefined4 *)(puVar3 + -0x20) = 0x80;
        DAT_0098d67c = 0x80;
        do {
          if (' ' < *(char *)(DAT_0098d67c + 0x98d697)) {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
            break;
          }
          DAT_0098d67c = DAT_0098d67c + -1;
          *(int *)(puVar3 + -0x20) = *(int *)(puVar3 + -0x20) + -1;
        } while (0 < *(int *)(puVar3 + -0x20));
        iVar1 = FUN_005f4660(0x20);
        if (iVar1 != 0) {
          *(undefined4 *)(puVar3 + -0x18) = 0;
          return;
        }
        DAT_0098d68c = DAT_0098d68c + 1;
        *(int *)(puVar3 + -0x24) = *(int *)(puVar3 + -0x24) + -1;
      } while (0 < *(int *)(puVar3 + -0x24));
      *(undefined4 *)(puVar3 + -0x14) = 0x27;
      DAT_0098d68c = 0x28;
      do {
        FUN_005f33c9(puVar3,0x52bbaa);
        DAT_0098d68c = DAT_0098d68c + -1;
        *(int *)(puVar3 + -0x14) = *(int *)(puVar3 + -0x14) + -1;
      } while (0 < *(int *)(puVar3 + -0x14));
    }
LAB_0052bbcc:
    puVar4 = &DAT_0078b510;
    pcVar6 = s___________________________________0078b6d0;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pcVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      pcVar6 = pcVar6 + 4;
    }
    *(undefined4 *)(puVar3 + -0x70) = 0;
    *(undefined4 *)(puVar3 + -0x80) = 0x14;
    *(char **)(puVar3 + -0x7c) = "C:\\!tmp\\!history.tmp:";
    *(undefined4 *)(puVar3 + -0x78) = 2;
    *(undefined4 *)(puVar3 + -0x74) = 4;
    uVar2 = FUN_005f6540(puVar3 + -0x70,0x11,0x784ff01,&DAT_00768084,puVar3 + -0x80);
    *(undefined4 *)(puVar3 + -0x10) = uVar2;
    if (*(int *)(puVar3 + -0x10) == 0) {
      *(undefined4 *)(puVar3 + -0xc) = 0x28;
      DAT_0098d68c = 1;
      do {
        *(undefined4 *)(puVar3 + -0x70) = 0;
        *(undefined4 *)(puVar3 + -0x80) = 0x80;
        *(undefined **)(puVar3 + -0x7c) = &DAT_0078b650 + DAT_0098d68c * 0x80;
        *(undefined4 *)(puVar3 + -0x78) = 0x80;
        FUN_005fc330(puVar3 + -0x70,0x11,0x784ff00,&DAT_0076807c,puVar3 + -0x80,&DAT_00796dc4);
        DAT_0098d68c = DAT_0098d68c + 1;
        *(int *)(puVar3 + -0xc) = *(int *)(puVar3 + -0xc) + -1;
      } while (0 < *(int *)(puVar3 + -0xc));
      *(undefined4 *)(puVar3 + -0x70) = 0;
      FUN_005f7950(puVar3 + -0x70,0x11,0x784ff00,&DAT_00767ff4,0);
    }
  }
  return;
}


