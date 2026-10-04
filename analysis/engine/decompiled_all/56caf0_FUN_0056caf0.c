// FUN_0056caf0 @ 0056caf0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0056cd6e) */
/* WARNING: Removing unreachable block (ram,0x0056cce5) */
/* WARNING: Removing unreachable block (ram,0x0056cbb3) */
/* WARNING: Removing unreachable block (ram,0x0056cca6) */
/* WARNING: Removing unreachable block (ram,0x0056cd2f) */
/* WARNING: Removing unreachable block (ram,0x0056cf8d) */
/* WARNING: Removing unreachable block (ram,0x0056cbf2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056caf0(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  unkbyte10 extraout_ST0_02;
  unkbyte10 Var9;
  float10 fVar10;
  
  puVar5 = &stack0xfffffffc;
  if (DAT_01cadcfc == 0) {
    puVar5 = &stack0xfffffffc;
    in_ST0 = FUN_005f34d1(&stack0xfffffffc,0x56cb1f);
  }
  ffree(in_ST0);
  thunk_FUN_0056b706(&DAT_009a8168,5);
  FUN_005f33c9(puVar5,0x56cb5b);
  DAT_009a8118 = 0;
  *(undefined4 *)(puVar5 + -0x48) = 0x1e;
  DAT_009a80e8 = 0x1e;
  do {
    if ((DAT_009a8118 == 0) && (' ' < *(char *)(DAT_009a80e8 + 0x9a8127))) {
      DAT_009a8118 = DAT_009a80e8;
    }
    iVar4 = FUN_00608e50(0x20);
    Var9 = extraout_ST0;
    if ((iVar4 == 0) && (iVar4 = FUN_00601a30(0x20), Var9 = extraout_ST0_00, iVar4 != 0)) {
      *(char *)(DAT_009a80e8 + 0x9a8127) = *(char *)(DAT_009a80e8 + 0x9a8127) + -0x20;
    }
    DAT_009a80e8 = DAT_009a80e8 + -1;
    *(int *)(puVar5 + -0x48) = *(int *)(puVar5 + -0x48) + -1;
  } while (0 < *(int *)(puVar5 + -0x48));
  DAT_009a8114 = 400;
  DAT_009a8110 = 0;
  iVar4 = DAT_009a8118 + -4;
  *(int *)(puVar5 + -0x44) = iVar4;
  DAT_009a810c = 5;
  while (0 < iVar4) {
    iVar4 = FUN_005f4660(0x20);
    if ((iVar4 != 0) || (iVar4 = FUN_005f4660(0x20), iVar4 != 0)) {
      DAT_009a8110 = -1;
    }
    iVar4 = FUN_005f4660(0x20);
    Var9 = extraout_ST0_01;
    if ((iVar4 != 0) || (iVar4 = FUN_005f4660(0x20), Var9 = extraout_ST0_02, iVar4 != 0)) {
      DAT_009a8114 = 700;
    }
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x44) = *(int *)(puVar5 + -0x44) + -1;
    iVar4 = *(int *)(puVar5 + -0x44);
  }
  if ((DAT_0078df00 == 0) || (OUTPUT_MODE < 0)) {
    if ((IP8 < 2000) || (OUTPUT_MODE < 0)) {
      *(undefined4 *)(puVar5 + -0x3c) = 0;
      goto LAB_0056cef6;
    }
  }
  else {
    *(undefined4 *)(puVar5 + -0x40) = 0;
  }
  FUN_005f33c9(puVar5,0x56ce1a);
  Var9 = FUN_005f34d1(puVar5,0x56ce35);
  puVar6 = &DAT_009a8128;
  puVar7 = (undefined4 *)&DAT_01a1ace0;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  if (DAT_009a8114 == 700) {
    FUN_005f33c9(puVar5,0x56ce76);
    Var9 = FUN_005f34d1(puVar5,0x56ce91);
    if (DAT_009a8110 == -1) {
      Var9 = FUN_005f33c9(puVar5,0x56cebc);
    }
  }
  else if (DAT_009a8110 == -1) {
    Var9 = FUN_005f33c9(puVar5,0x56cee9);
  }
LAB_0056cef6:
  ffree(Var9);
  fVar10 = (float10)thunk_FUN_0054cb15(&DAT_01a1ace0,0x1c,&DAT_009a8118,&DAT_0076a2c8);
  *(int *)(puVar5 + -0x38) = DAT_009a8118;
  DAT_009a80e8 = 1;
  iVar4 = DAT_009a8118;
  while (0 < iVar4) {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a80e8 + 0x1a1acdf);
    DAT_009a80e8 = DAT_009a80e8 + 1;
    *(int *)(puVar5 + -0x38) = *(int *)(puVar5 + -0x38) + -1;
    iVar4 = *(int *)(puVar5 + -0x38);
  }
  *DAT_01fbb844 = *DAT_01fbb844 + 1;
  *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) = 0;
  *(undefined4 *)(puVar5 + -0x34) = 4;
  DAT_009a810c = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a810c + 0x9a80ef);
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x34) = *(int *)(puVar5 + -0x34) + -1;
  } while (0 < *(int *)(puVar5 + -0x34));
  if (OUTPUT_MODE == 1) {
    DAT_01a9f308 = DAT_01a9f308 * f_0_825;
  }
  *(undefined4 *)(puVar5 + -0x30) = 4;
  DAT_009a810c = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a810c + 0x9a80ef);
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x30) = *(int *)(puVar5 + -0x30) + -1;
  } while (0 < *(int *)(puVar5 + -0x30));
  *(undefined2 *)(puVar5 + -0x70) = in_FPUControlWord;
  *(ushort *)(puVar5 + -0x6e) = (ushort)*(undefined4 *)(puVar5 + -0x70) | 0xc00;
  *(int *)(puVar5 + -0x6c) = (int)ROUND(P9 * f_10);
  uVar1 = *(undefined2 *)(puVar5 + -0x70);
  DAT_009a8108 = *(undefined4 *)(puVar5 + -0x6c);
  *(undefined4 *)(puVar5 + -0x2c) = 4;
  DAT_009a810c = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a810c + 0x9a80ef);
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x2c) = *(int *)(puVar5 + -0x2c) + -1;
  } while (0 < *(int *)(puVar5 + -0x2c));
  DAT_009a80e8 = 0;
  if (EDIT_ITEM != 0) {
    DAT_009a80e8 = 0xff;
  }
  if ((DAT_01b11790 == 0) || (EDIT_ITEM != 0)) {
    if (P14 == f_m1) {
      if (P16 == f_1) {
        P16 = f_0_92;
      }
      if (P16 < f_1) {
        fVar10 = (float10)P16 * (float10)f_10000 + (float10)P16 * (float10)f_100;
        P16 = (float)((float10)P16 * (float10)f_1000000 + fVar10);
      }
      *(undefined2 *)(puVar5 + -0x70) = uVar1;
      *(ushort *)(puVar5 + -0x6e) = (ushort)*(undefined4 *)(puVar5 + -0x70) | 0xc00;
      *(int *)(puVar5 + -0x6c) = (int)ROUND(P16);
      DAT_009a8104 = *(int *)(puVar5 + -0x6c);
      *(int *)(puVar5 + -0x6c) = DAT_009a8104 / 10000;
      *(undefined2 *)(puVar5 + -0x70) = *(undefined2 *)(puVar5 + -0x70);
      *(ushort *)(puVar5 + -0x6e) = (ushort)*(undefined4 *)(puVar5 + -0x70) | 0xc00;
      *(int *)(puVar5 + -0x6c) = (int)ROUND((float)*(int *)(puVar5 + -0x6c) * f_2_56);
      uVar2 = *(undefined4 *)(puVar5 + -0x6c);
      *(int *)(puVar5 + -0x6c) = (DAT_009a8104 % 10000) / 100;
      *(undefined2 *)(puVar5 + -0x70) = *(undefined2 *)(puVar5 + -0x70);
      *(ushort *)(puVar5 + -0x6e) = (ushort)*(undefined4 *)(puVar5 + -0x70) | 0xc00;
      *(int *)(puVar5 + -0x6c) = (int)ROUND((float)*(int *)(puVar5 + -0x6c) * f_2_56);
      uVar3 = *(undefined4 *)(puVar5 + -0x6c);
      *(int *)(puVar5 + -0x6c) = DAT_009a8104 % 100;
      *(undefined2 *)(puVar5 + -0x70) = *(undefined2 *)(puVar5 + -0x70);
      *(ushort *)(puVar5 + -0x6e) = (ushort)*(undefined4 *)(puVar5 + -0x70) | 0xc00;
      *(int *)(puVar5 + -0x6c) = (int)ROUND((float)*(int *)(puVar5 + -0x6c) * f_2_56);
      DAT_009a80e8 = (uint)CONCAT12((char)*(undefined4 *)(puVar5 + -0x6c),
                                    CONCAT11((char)uVar3,(char)uVar2));
      DAT_01b11790 = 1;
      DAT_01b11794 = DAT_009a80e8;
    }
    if (ITEM_I == DAT_020527ec) {
      DAT_009a80e8 = 0xff;
    }
  }
  else {
    DAT_009a80e8 = DAT_01b11794;
    *(undefined4 *)(puVar5 + -0x28) = 0;
  }
  *(undefined4 *)(puVar5 + -0x24) = 4;
  DAT_009a810c = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a810c + 0x9a80ef);
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x24) = *(int *)(puVar5 + -0x24) + -1;
  } while (0 < *(int *)(puVar5 + -0x24));
  *(undefined4 *)(puVar5 + -0x20) = 4;
  DAT_009a810c = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a810c + 0x9a80ef);
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x20) = *(int *)(puVar5 + -0x20) + -1;
  } while (0 < *(int *)(puVar5 + -0x20));
  *(undefined4 *)(puVar5 + -0x1c) = 4;
  DAT_009a810c = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a810c + 0x9a80ef);
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x1c) = *(int *)(puVar5 + -0x1c) + -1;
  } while (0 < *(int *)(puVar5 + -0x1c));
  *(undefined4 *)(puVar5 + -0x18) = 4;
  DAT_009a810c = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_009a810c + 0x9a80ef);
    DAT_009a810c = DAT_009a810c + 1;
    *(int *)(puVar5 + -0x18) = *(int *)(puVar5 + -0x18) + -1;
  } while (0 < *(int *)(puVar5 + -0x18));
  DAT_009a8100 = 0;
  iVar4 = (DAT_01cb1068 - DAT_01cadce0) + 1;
  *(int *)(puVar5 + -0x14) = iVar4;
  _DAT_009a80f0 = DAT_009a8100;
  iVar8 = DAT_01cadce0;
  do {
    DAT_009a8100 = _DAT_009a80f0;
    if (iVar4 < 1) {
LAB_0056d6d9:
      DAT_01a9f304 = DAT_009a80f8 + _DAT_009a80fc + -1;
      *(undefined4 *)(puVar5 + -4) = 4;
      DAT_009a810c = 1;
      do {
        *DAT_01fbb844 = *DAT_01fbb844 + 1;
        *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c)
             = *(undefined1 *)(DAT_009a810c + 0x9a80ef);
        DAT_009a810c = DAT_009a810c + 1;
        *(int *)(puVar5 + -4) = *(int *)(puVar5 + -4) + -1;
      } while (0 < *(int *)(puVar5 + -4));
      ffree(fVar10);
      return;
    }
    iVar4 = (&DAT_01caea3c)[iVar8];
    if ((999 < iVar4) && (DAT_01cadce0 < iVar8)) {
      *(undefined4 *)(puVar5 + -0x10) = 0;
      goto LAB_0056d6d9;
    }
    if ((iVar4 == 0x7e) || (0xa1 < iVar4 && iVar4 != 0xa7)) {
      *(undefined4 *)(puVar5 + -0xc) = 0;
    }
    else if ((iVar4 < 0x50) || (0x5e < iVar4)) {
      DAT_009a8100 = _DAT_009a80f0 + 1;
    }
    *(undefined4 *)(puVar5 + -8) = 0;
    iVar8 = iVar8 + 1;
    *(int *)(puVar5 + -0x14) = *(int *)(puVar5 + -0x14) + -1;
    iVar4 = *(int *)(puVar5 + -0x14);
    _DAT_009a80f0 = DAT_009a8100;
  } while( true );
}


