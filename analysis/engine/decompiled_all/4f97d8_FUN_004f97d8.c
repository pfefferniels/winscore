// FUN_004f97d8 @ 004f97d8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004f97d8(void)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  int *piVar7;
  byte *pbVar8;
  int *piVar9;
  bool bVar10;
  undefined1 uVar11;
  undefined2 in_FPUControlWord;
  undefined4 uStack_78;
  
  puVar5 = &stack0xfffffffc;
  thunk_FUN_0054c78b(&DAT_009011e8);
  DAT_009011e4 = 1;
  DAT_009011e0 = 0;
  DAT_009011dc = 1;
LAB_004f9811:
  iVar4 = DAT_009011e4 + 1;
  if ((*(char *)((int)&DAT_020b8ea0 + DAT_009011e4) == '\r') &&
     (*(char *)((int)&DAT_020b8ea0 + DAT_009011e4 + 1) == '\n')) {
    DAT_009011e0 = DAT_009011e0 + 1;
    uStack_78 = 0x4f989e;
    DAT_009011e4 = iVar4;
    FUN_005f46bc();
    uStack_78 = 0x4f98b4;
    FUN_005f34d1();
    DAT_009011dc = DAT_009011e4 + 2;
    DAT_009011e4 = DAT_009011e4 + 1;
    uStack_78 = 3;
    thunk_FUN_00571b78(&DAT_01c4eec4 + DAT_009011e0 * 0x80,0x80,&DAT_00766928);
    *(undefined4 *)(puVar5 + -0x38) = 0;
LAB_004f9b7a:
    if (0x200 < DAT_009011e4) goto LAB_004f9c5f;
    *(undefined4 *)(puVar5 + -0x24) = 0;
    goto LAB_004f9811;
  }
  if (*(char *)((int)&DAT_020b8ea0 + DAT_009011e4) == '\0') {
    if ((char)(&DAT_020b8e9f)[DAT_009011e4] < ' ') {
      *(undefined4 *)(puVar5 + -0x34) = 0;
      DAT_009011e4 = iVar4;
    }
    else {
      DAT_009011e0 = DAT_009011e0 + 1;
      uStack_78 = 0x4f9c0b;
      DAT_009011e4 = iVar4;
      FUN_005f46bc();
      uStack_78 = 0x4f9c21;
      FUN_005f34d1();
      uStack_78 = 3;
      thunk_FUN_00571b78(&DAT_01c4eec4 + DAT_009011e0 * 0x80,0x80,&DAT_00766928);
      *(undefined4 *)(puVar5 + -0x30) = 0;
    }
LAB_004f9e6b:
    DAT_01c4ef40 = DAT_009011e0;
  }
  else {
    if (*(char *)((int)&DAT_020b8ea0 + DAT_009011e4) != ':') {
      pcVar1 = (char *)((int)&DAT_020b8ea0 + DAT_009011e4);
      DAT_009011e4 = iVar4;
      if (*pcVar1 == ' ') {
        *(undefined4 *)(puVar5 + -0x28) = 0;
        DAT_009011e0 = DAT_009011e0 + 1;
        uStack_78 = 0x4f99ab;
        FUN_005f46bc();
        uStack_78 = 0x4f99c1;
        FUN_005f34d1();
        uStack_78 = 3;
        thunk_FUN_00571b78(&DAT_01c4eec4 + DAT_009011e0 * 0x80,0x80,&DAT_00766928);
        thunk_FUN_0054c5f8((int)&DAT_020b8ea0 + DAT_009011e4,1,&DAT_020b8ea0,1,&DAT_00766924);
        uStack_78 = 0x4f9a21;
        thunk_FUN_00518448();
        *(undefined2 *)(puVar5 + -0x60) = in_FPUControlWord;
        *(ushort *)(puVar5 + -0x5e) = (ushort)*(undefined4 *)(puVar5 + -0x60) | 0xc00;
        *(int *)(puVar5 + -0x5c) = (int)ROUND(P1 - f_1);
        in_FPUControlWord = *(undefined2 *)(puVar5 + -0x60);
        iVar4 = *(int *)(puVar5 + -0x5c);
        *(int *)(puVar5 + -8) = iVar4;
        DAT_009011d4 = 1;
        while (0 < iVar4) {
          DAT_009011e0 = DAT_009011e0 + 1;
          uStack_78 = 0x4f9aa5;
          FUN_005f33c9();
          uStack_78 = 0x80;
          thunk_FUN_004cfb85(&DAT_01c4eec4 + DAT_009011e0 * 0x80);
          DAT_009011d4 = DAT_009011d4 + 1;
          *(int *)(puVar5 + -8) = *(int *)(puVar5 + -8) + -1;
          iVar4 = *(int *)(puVar5 + -8);
        }
        DAT_009011dc = 1;
        DAT_009011e4 = 1;
        DAT_009011d4 = 4;
        if (f_9 < P1) {
          DAT_009011d4 = 5;
        }
        thunk_FUN_0054c5f8(&DAT_020b909f + DAT_009011d4,1,&DAT_020b8ea0,1,&DAT_00766924);
        bVar10 = (undefined1 *)0xfffffffb < &uStack_78;
        iVar4 = 1;
        pbVar6 = (byte *)&DAT_020b8ea0;
        pbVar8 = &DAT_00766918;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar3 = *pbVar8;
          bVar2 = *pbVar6;
          bVar10 = bVar2 < bVar3;
          pbVar6 = pbVar6 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar2 == bVar3);
        if (bVar10) goto LAB_004f9e6b;
        *(undefined4 *)(puVar5 + -4) = 0;
        goto LAB_004f9811;
      }
      goto LAB_004f9b7a;
    }
    *(undefined4 *)(puVar5 + -0x2c) = 0;
    DAT_009011e4 = iVar4;
LAB_004f9c5f:
    (&DAT_020b8e9f)[DAT_009011e4] = 0x20;
    DAT_009011d8 = DAT_009011e4 + 1;
    iVar4 = 0x81 - DAT_009011d8;
    *(int *)(puVar5 + -0x20) = iVar4;
    while (0 < iVar4) {
      if ((&DAT_020b8e9f)[DAT_009011d8] == ' ') {
        *(undefined4 *)(puVar5 + -0x1c) = 0;
      }
      else {
        uStack_78 = 0x4f9cea;
        FUN_005f46bc();
        uStack_78 = 0x4f9d00;
        FUN_005f34d1();
        uStack_78 = 3;
        thunk_FUN_00571b78(&DAT_01c4ef44,0x80,&DAT_00766928);
        uStack_78 = 0x4f9d5c;
        FUN_005f46bc();
        uStack_78 = 0x4f9d72;
        FUN_005f34d1();
        uStack_78 = 3;
        thunk_FUN_00571b78(&DAT_01c4cb60,0x80,&DAT_00766928);
        *(undefined4 *)(puVar5 + -0x18) = 299;
        DAT_009011e0 = 2;
        do {
          uStack_78 = 0x4f9dd7;
          FUN_005f33c9();
          uVar11 = &stack0x00000000 == (undefined1 *)0x74;
          uStack_78 = 0x80;
          thunk_FUN_004cfb85(&DAT_01c4eec4 + DAT_009011e0 * 0x80);
          iVar4 = 0x20;
          piVar7 = &DAT_01c4cb60;
          piVar9 = (int *)(&DAT_01c4eec4 + DAT_009011e0 * 0x80);
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            uVar11 = *piVar7 == *piVar9;
            piVar7 = piVar7 + 1;
            piVar9 = piVar9 + 1;
          } while ((bool)uVar11);
          if ((bool)uVar11) {
            *(undefined4 *)(puVar5 + -0x14) = 0;
            goto LAB_004f9e6b;
          }
          DAT_009011e0 = DAT_009011e0 + 1;
          *(int *)(puVar5 + -0x18) = *(int *)(puVar5 + -0x18) + -1;
        } while (0 < *(int *)(puVar5 + -0x18));
      }
      *(undefined4 *)(puVar5 + -0x10) = 0;
      DAT_009011d8 = DAT_009011d8 + 1;
      *(int *)(puVar5 + -0x20) = *(int *)(puVar5 + -0x20) + -1;
      iVar4 = *(int *)(puVar5 + -0x20);
    }
    DAT_009011e0 = -999;
    *(undefined4 *)(puVar5 + -0xc) = 0;
  }
  return;
}


