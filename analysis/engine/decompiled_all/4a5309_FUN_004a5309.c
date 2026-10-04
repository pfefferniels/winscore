// FUN_004a5309 @ 004a5309 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004a535b) */
/* WARNING: Removing unreachable block (ram,0x004a539b) */

void FUN_004a5309(char *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  bool bVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined4 uStack_c8;
  undefined4 local_b4 [41];
  int local_10;
  undefined4 local_c;
  
  puVar10 = &stack0xfffffffc;
  puVar11 = &stack0xfffffffc;
  bVar9 = &stack0x00000000 == (undefined1 *)0xb8;
  iVar3 = 7;
  pcVar4 = (char *)&DAT_0078b464;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar9 = *pcVar4 == *param_1;
    pcVar4 = pcVar4 + 1;
    param_1 = param_1 + 1;
  } while (bVar9);
  if (!bVar9) {
    local_10 = 0x80;
    DAT_00838f68 = 0x80;
    do {
      uStack_c8 = 0x20;
      iVar3 = FUN_005f4660();
      if (iVar3 != 0) {
LAB_004a54ab:
        local_c = 0;
        uStack_c8 = 0x4a54e0;
        FUN_005f46bc(&stack0xfffffffc);
        uStack_c8 = 0x4a54f6;
        FUN_005f34d1(puVar11);
        DAT_01b12d40 = DAT_00838f68;
        return;
      }
      uStack_c8 = 0x20;
      iVar3 = FUN_005f4660();
      if (iVar3 != 0) goto LAB_004a54ab;
      DAT_00838f68 = DAT_00838f68 + -1;
      local_10 = local_10 + -1;
    } while (0 < local_10);
    puVar6 = &DAT_01ae2880;
    puVar8 = local_b4;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    uStack_c8 = 0x80;
    DAT_00838f64 = FUN_005ff950(local_b4);
    uStack_c8 = 0x4a5444;
    FUN_005f46bc();
    uStack_c8 = 0x4a5460;
    FUN_005f46bc();
    uStack_c8 = 0x4a5479;
    FUN_005f46bc();
    bVar9 = (undefined1 *)0xfffffffb < &uStack_c8;
    iVar3 = 1;
    pbVar5 = (byte *)&DAT_01b12cc0;
    pbVar7 = &DAT_00763964;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar2 = *pbVar7;
      bVar1 = *pbVar5;
      bVar9 = bVar1 < bVar2;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar1 == bVar2);
    if (!bVar9) {
      puVar6 = &DAT_01b12cc0;
      puVar8 = *(undefined4 **)(puVar10 + 8);
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    *(undefined4 *)(puVar10 + -4) = 0;
  }
  return;
}


