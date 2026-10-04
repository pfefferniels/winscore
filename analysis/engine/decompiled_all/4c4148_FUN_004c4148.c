// FUN_004c4148 @ 004c4148 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004c42e6) */
/* WARNING: Removing unreachable block (ram,0x004c43e7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c4148(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  float10 in_ST0;
  unkbyte10 Var7;
  float10 extraout_ST0;
  undefined1 *puVar8;
  int local_94;
  
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  DAT_0089fb70 = 1;
  DAT_0089fb6c = 0;
  _DAT_0089fb68 = 0;
  DAT_0089fb64 = 0;
  local_94 = 0xc;
  DAT_0089fb60 = 1;
  while (*(char *)((int)&DAT_01e62c80 + DAT_0089fb60 + 3) != 'X') {
    DAT_0089fb60 = DAT_0089fb60 + 1;
    local_94 = local_94 + -1;
    if (local_94 < 1) goto LAB_004c4246;
  }
  DAT_0089fb5c = DAT_0089fb60;
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_004c2458(&DAT_01e62c84,1,&DAT_0089fb64,&DAT_0089fb5c);
  if (DAT_0089fb64 != 0) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_004c2458(&DAT_01e62c84,1,&DAT_0089fb58,&DAT_0089fb5c);
  }
  if (DAT_0089fb58 == 0) goto LAB_004c4246;
  DAT_0089fb54 = *param_1 + -1;
  iVar2 = -DAT_0089fb54 / -1;
  for (; (0 < iVar2 && ((&DAT_020b8e9f)[DAT_0089fb54] != '/')); DAT_0089fb54 = DAT_0089fb54 + -1) {
    iVar2 = iVar2 + -1;
  }
  DAT_0089fb50 = 0;
  DAT_0089fb4c = DAT_0089fb54 + -1;
  for (iVar2 = -DAT_0089fb4c / -1; 0 < iVar2; iVar2 = iVar2 + -1) {
    if ((&DAT_020b8e9f)[DAT_0089fb4c] == '/') {
      DAT_0089fb50 = DAT_0089fb50 + 1;
    }
    if (DAT_0089fb64 == DAT_0089fb50) goto LAB_004c4dfc;
    DAT_0089fb4c = DAT_0089fb4c + -1;
  }
  DAT_0089fb4c = 0;
LAB_004c4dfc:
  DAT_0089fb4c = DAT_0089fb4c + 1;
  DAT_0089fb48 = DAT_0089fb54 - DAT_0089fb4c;
  DAT_0089fb44 = DAT_0089fb54 + 1;
  puVar4 = (undefined4 *)&DAT_020b8ea0;
  puVar5 = &DAT_009ae2bc;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  DAT_0089fb40 = 1;
  iVar2 = DAT_0089fb58;
  while (iVar2 = iVar2 + -1, 0 < iVar2) {
    DAT_0089fb3c = DAT_0089fb4c;
    DAT_0089fb38 = DAT_0089fb44;
    for (iVar6 = DAT_0089fb48 + 1; 0 < iVar6; iVar6 = iVar6 + -1) {
      (&DAT_020b8e9f)[DAT_0089fb38] = (&DAT_020b8e9f)[DAT_0089fb3c];
      DAT_0089fb3c = DAT_0089fb3c + 1;
      if ((&DAT_020b8e9f)[DAT_0089fb38] == '/') {
        (&DAT_020b8e9f)[DAT_0089fb38] = 0x22;
      }
      DAT_0089fb38 = DAT_0089fb38 + 1;
    }
    DAT_0089fb44 = DAT_0089fb48 + DAT_0089fb44 + 1;
    DAT_0089fb40 = DAT_0089fb40 + 1;
  }
  (&DAT_020b8e9e)[DAT_0089fb44] = 0x3f;
  DAT_01fb8c90 = 1;
  goto LAB_004c4f67;
LAB_004c4c4b:
  DAT_0089fb30 = DAT_0089fb20;
  goto LAB_004c4c57;
LAB_004c4246:
  if ((((DAT_020b90a0 == '/') || (DAT_020b90a0 == ';')) && (DAT_01fbb700 != 2)) &&
     (puVar1 = &stack0xfffffffc, (&DAT_020b8e9e)[*param_1] == '/')) goto LAB_004c4946;
  DAT_01ade7c4 = *(char *)((int)&DAT_01e62c80 + DAT_0089fb70 + 3);
  if (DAT_01ade7c4 == '/') {
    DAT_0089fb6c = *param_1;
    do {
      do {
        iVar2 = DAT_0089fb6c;
        DAT_0089fb6c = iVar2 + -1;
      } while ((&DAT_020b8e9e)[iVar2] == '/');
      if (((&DAT_020b8e9e)[iVar2] != ' ') &&
         (DAT_01ade7c4 = (&DAT_020b8e9e)[iVar2], DAT_01ade7c4 != ' ')) goto LAB_004c4923;
    } while( true );
  }
  FUN_005f46bc(&stack0xfffffffc,0x4c430a);
  puVar3 = puVar8;
  Var7 = FUN_005f34d1(puVar8,0x4c4320);
  DAT_0089fb78 = (&DAT_01e62c84)[DAT_0089fb70];
  DAT_0089fb34 = f_0;
  DAT_0089fb30 = f_0;
  DAT_0089fb2c = f_0;
  DAT_0089fb28 = f_0;
  DAT_0089fb6c = DAT_0089fb70 + 1;
  iVar2 = 0xd - DAT_0089fb6c;
  *(int *)(puVar3 + -0x40) = iVar2;
  while (0 < iVar2) {
    if (*(char *)((int)&DAT_01e62c80 + DAT_0089fb6c + 3) == '.') {
      DAT_0089fb34 = DAT_0089fb34 + f_10;
    }
    DAT_0089fb6c = DAT_0089fb6c + 1;
    *(int *)(puVar3 + -0x40) = *(int *)(puVar3 + -0x40) + -1;
    iVar2 = *(int *)(puVar3 + -0x40);
  }
  ffree(Var7);
  DAT_01ade7ec = FUN_004c54f6(DAT_0089fb70 + 0x1e62c83,3);
  in_ST0 = extraout_ST0;
  if (DAT_0079483c == f_0) {
    *(undefined4 *)(puVar3 + -0x3c) = 0;
  }
  else {
    if (DAT_01ade7ec == 0) {
      if (DAT_01ade7c4 == 'G') {
        *(undefined4 *)(puVar3 + -0x34) = 0;
        goto LAB_004c458e;
      }
      if (DAT_01ade7c4 == 'S') {
        DAT_01ade7ec = 0x10;
      }
      if (DAT_01ade7c4 == 'E') {
        DAT_01ade7ec = 8;
      }
      if (DAT_01ade7c4 == 'Q') {
        DAT_01ade7ec = 4;
      }
      if (DAT_01ade7c4 == 'H') {
        DAT_01ade7ec = 2;
      }
      if (DAT_01ade7c4 == 'W') {
        DAT_01ade7ec = 1;
      }
      if (DAT_01ade7c4 == 'T') {
        DAT_01ade7ec = 0xc;
      }
      if (DAT_0089fb74 == 0x5354) {
        DAT_01ade7ec = 0x18;
      }
      if (DAT_0089fb74 == 0x5154) {
        DAT_01ade7ec = 6;
      }
      if (DAT_0089fb74 == 0x4854) {
        DAT_01ade7ec = 3;
      }
      if (DAT_0089fb74 == 0x5454) {
        DAT_01ade7ec = 0x30;
      }
      in_ST0 = (float10)FUN_005f34d1(puVar3,0x4c4583);
    }
    else {
      *(undefined4 *)(puVar3 + -0x38) = 0;
    }
    *(undefined4 *)(puVar3 + -0x30) = 0;
  }
LAB_004c458e:
  if ((DAT_01ade7ec == 0x10) || (DAT_01ade7c4 == 'S')) {
    DAT_0089fb30 = f_2;
  }
  if ((DAT_01ade7ec == 8) || (DAT_01ade7c4 == 'E')) {
    DAT_0089fb30 = f_1;
  }
  if ((DAT_01ade7ec == 2) || (DAT_01ade7c4 == 'H')) {
    DAT_0089fb2c = f_1;
  }
  if ((DAT_01ade7ec == 1) || (DAT_01ade7c4 == 'W')) {
    DAT_0089fb2c = f_2;
  }
  if ((DAT_01ade7c4 == 'D') || (DAT_0089fb74 == 0x352e)) {
    DAT_0089fb2c = f_3;
  }
  if (DAT_01ade7ec == 0x20) {
    DAT_0089fb30 = f_3;
  }
  if (DAT_01ade7ec == 0x40) {
    DAT_0089fb30 = f_4;
  }
  if ((DAT_0089fb74 != 0x5154) && (DAT_01ade7c4 == 'T' || DAT_01ade7ec == 0xc)) {
    DAT_0089fb30 = f_1;
  }
  if ((DAT_01ade7ec == 3) || (DAT_0089fb74 == 0x4854)) {
    DAT_0089fb2c = f_1;
    DAT_0089fb30 = f_0;
  }
  if ((DAT_01ade7ec == 0x18) || (DAT_0089fb74 == 0x5354)) {
    DAT_0089fb30 = f_2;
  }
  if ((DAT_01ade7ec == 0x30) || (DAT_0089fb74 == 0x5454)) {
    DAT_0089fb30 = f_3;
  }
  if (7 < DAT_01ade7ec) {
    DAT_0089fb30 = f_1;
  }
  if (0xf < DAT_01ade7ec) {
    DAT_0089fb30 = f_2;
  }
  if (0x1f < DAT_01ade7ec) {
    DAT_0089fb30 = f_3;
  }
  if (0x3f < DAT_01ade7ec) {
    DAT_0089fb30 = f_4;
  }
  if (0x7f < DAT_01ade7ec) {
    DAT_0089fb30 = f_5;
  }
  if (DAT_01ade7c4 == 'G') {
    DAT_0089fb30 = f_1;
    DAT_0089fb28 = f_1;
  }
  if (DAT_0089fb74 != 0x4f44) {
    DAT_0089fb24 = DAT_0089fb30;
    goto LAB_004c4923;
  }
  DAT_0089fb6c = DAT_0089fb7c;
  DAT_0089fb5c = DAT_00794834;
  while (*(float *)(&ITEM_P9 + DAT_0089fb6c * 4) = *(float *)(&ITEM_P9 + DAT_0089fb6c * 4) + f_10,
        (float)(&ITEM_P3)[DAT_0089fb6c] == (float)(&ITEM_P3)[(&DAT_02091d18)[DAT_0089fb5c]]) {
    DAT_0089fb5c = DAT_0089fb5c + -1;
    DAT_0089fb6c = (&ITEM_PTR0)[DAT_0089fb5c];
    *(undefined4 *)(puVar3 + -0x28) = 0;
  }
  *(undefined4 *)(puVar3 + -0x2c) = 0;
LAB_004c4c57:
  puVar4 = (undefined4 *)&DAT_020b8ea0;
  puVar5 = (undefined4 *)&DAT_020b90a0;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  _DAT_0089fb1c = 1;
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_004ddb6e(&DAT_0089fb5c);
  puVar4 = (undefined4 *)&DAT_020b90a0;
  puVar5 = (undefined4 *)&DAT_020b8ea0;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (1 < DAT_0089fb64) {
    if (DAT_0089fb58 == 0) {
      DAT_0089fb64 = DAT_0089fb64 + -1;
      DAT_00794830 = DAT_00794830 + 1;
      *(undefined4 *)(puVar3 + -8) = 0;
LAB_004c4923:
      DAT_0089fb6c = 0;
      DAT_0089fb5c = DAT_00794834 + 1;
      DAT_0089fb30 = DAT_0089fb24;
      puVar1 = puVar3;
    }
    else {
      *(undefined4 *)(puVar3 + -0xc) = 0;
      puVar1 = puVar3;
    }
LAB_004c4946:
    do {
      while( true ) {
        puVar3 = puVar1;
        DAT_00794834 = DAT_00794834 + 1;
        DAT_0089fb7c = (&ITEM_PTR0)[DAT_00794834];
        puVar1 = puVar3;
        if ((float)(&ITEM_P1)[DAT_0089fb7c] <= f_2) break;
        *(undefined4 *)(puVar3 + -0x24) = 0;
      }
      if ((float)(&ITEM_P3)[DAT_0089fb7c] != (float)(&ITEM_P3)[(&DAT_02091d18)[DAT_00794834]]) {
        *(int *)(&DAT_007cbbac + DAT_00794830 * 4) = DAT_00794834;
      }
      if ((float)(&ITEM_P1)[DAT_0089fb7c] == f_1) {
        if (DAT_0089fb74 == 0x5754) {
          DAT_0089fb30 = f_0;
          DAT_0089fb2c = f_2;
        }
        *(float *)(&ITEM_P9 + DAT_0089fb7c * 4) = DAT_0089fb34 + DAT_0089fb30;
        (&ITEM_P6)[DAT_0089fb7c] = DAT_0089fb2c;
        if (DAT_0089fb28 == f_0) goto LAB_004c4b6a;
        DAT_0079483c = f_100;
        if ((float)(&ITEM_P4)[DAT_0089fb7c] < f_0) {
          in_ST0 = (float10)f_100;
          DAT_0079483c = (float)-in_ST0;
        }
        (&ITEM_P4)[DAT_0089fb7c] = DAT_0079483c + (float)(&ITEM_P4)[DAT_0089fb7c];
        if (DAT_0089fb6c != 0) {
          in_ST0 = (float10)(float)(&ITEM_P1)[DAT_0089fb7c];
          (&ITEM_P1)[DAT_0089fb7c] = (float)-in_ST0;
        }
        if (DAT_0089fb6c == 0) {
          if (f_20 <= (float)(&ITEM_P5)[DAT_0089fb7c]) {
            (&ITEM_P5)[DAT_0089fb7c] = (float)(&ITEM_P5)[DAT_0089fb7c] - f_10;
          }
          *(float *)(&ITEM_P8 + DAT_0089fb7c * 4) = f_101;
          goto LAB_004c4b6a;
        }
        *(undefined4 *)(puVar3 + -0x20) = 0;
      }
      else {
        (&ITEM_P5)[DAT_0089fb7c] = DAT_0089fb30 - DAT_0089fb2c;
        (&ITEM_P6)[DAT_0089fb7c] = DAT_0089fb34 / f_10;
LAB_004c4b6a:
        in_ST0 = (float10)(float)(&ITEM_P1)[DAT_0089fb7c];
        (&ITEM_P1)[DAT_0089fb7c] = (float)-in_ST0;
        DAT_0089fb6c = 1;
        if (DAT_0089fb5c == DAT_00794834) {
          *(float *)(&DAT_01ade10c + DAT_00794830 * 4) = DAT_0089fb28;
          *(float *)(&DAT_01add2fc + DAT_00794830 * 4) = DAT_0089fb30;
          *(float *)(&DAT_01add7ac + DAT_00794830 * 4) = DAT_0089fb2c;
          *(float *)(&DAT_01addc5c + DAT_00794830 * 4) = DAT_0089fb34;
          DAT_0089fb20 = DAT_0089fb30;
        }
        else {
          *(undefined4 *)(puVar3 + -0x1c) = 0;
        }
        *(undefined4 *)(puVar3 + -0x18) = 0;
      }
      if ((float)(&ITEM_P3)[DAT_0089fb7c] != (float)(&ITEM_P3)[(&DAT_02091d20)[DAT_00794834]])
      goto LAB_004c4c4b;
      DAT_0089fb30 = f_0;
      *(undefined4 *)(puVar3 + -0x14) = 0;
    } while( true );
  }
  *(undefined4 *)(puVar3 + -0x10) = 0;
LAB_004c4f67:
  ffree(in_ST0);
  return;
}


