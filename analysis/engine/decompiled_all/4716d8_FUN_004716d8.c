// FUN_004716d8 @ 004716d8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004716d8(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined2 in_FPUControlWord;
  int local_84;
  uint local_80;
  int local_7c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  DAT_01caea44 = (int)ROUND(P2);
  if (DAT_01caea44 == 0) {
    DAT_01caea44 = 1;
  }
  DAT_01c585cc = (&ITEM_PTR0)[EDIT_ITEM];
  local_80 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_01c585c8 = (int)ROUND(*(float *)(&ITEM_P12 + DAT_01c585cc * 4));
  DAT_00824f8c = 0xd;
  if (*(float *)(&ITEM_P14 + DAT_01c585cc * 4) == f_m1) {
    DAT_00824f8c = 0x10;
  }
  DAT_01c585d4 = (DAT_00824f8c + DAT_01c585cc) * 4 + 1;
  DAT_00824f88 = 0;
  if (EDIT_ITEM < ITEM_I) {
    DAT_00824f88 = (&DAT_02091d20)[EDIT_ITEM];
  }
  DAT_00824f84 = 0;
  if (1 < EDIT_ITEM) {
    DAT_00824f84 = (&DAT_02091d18)[EDIT_ITEM];
  }
  DAT_01c585c4 = 0;
  local_7c = DAT_01c585c8;
  if (DAT_01caea44 < 1) {
    DAT_01caea48 = 1;
    DAT_00824f80 = DAT_01c585d4;
    for (local_54 = DAT_01c585c8; 0 < local_54; local_54 = local_54 + -1) {
      if (*(char *)((int)&ITEM_LEN + DAT_00824f80 + 3) == ' ') {
        DAT_01c585c4 = DAT_01c585c4 + 1;
        if (-DAT_01c585c4 == DAT_01caea44) {
          local_4c = 0;
          goto LAB_00471eec;
        }
      }
      else {
        local_50 = 0;
      }
      DAT_01caea48 = DAT_01caea48 + 1;
      DAT_00824f80 = DAT_00824f80 + 1;
    }
    thunk_FUN_0054d831(&DAT_007620f0,0x24);
LAB_00471eec:
    DAT_01fb8cf8._0_1_ = DAT_007620e8;
    iVar4 = DAT_01caea48 + -1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iVar2 = 2;
    iVar5 = DAT_01c585d4;
    for (iVar6 = 1; iVar6 <= iVar4; iVar6 = iVar6 + 1) {
      (&DAT_01fb8cf7)[iVar2] = *(undefined1 *)((int)&ITEM_LEN + iVar5 + 3);
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 1;
    }
    DAT_00824f7c = DAT_01c585c8 - DAT_01caea48;
    DAT_00824f78 = DAT_01caea48;
    local_84 = DAT_00824f8c + DAT_01c585cc + 1;
    thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&local_84);
    if (EDIT_ITEM == 1) {
      local_48 = 0;
    }
    else if (((DAT_020b8ea3 != 'X') && ((float)(&ITEM_P1)[DAT_00824f84] == f_16)) &&
            ((float)(&ITEM_P2)[DAT_01c585cc] == (float)(&ITEM_P2)[DAT_00824f84])) {
      local_44 = 0;
      iVar4 = (DAT_00824f8c + DAT_00824f84) * 4 + 1;
      local_80 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      DAT_0078d85c = (int)ROUND(*(float *)(&ITEM_P12 + DAT_00824f84 * 4));
      local_7c = DAT_0078d85c;
      if (DAT_0078d85c < 0) {
        local_7c = 0;
      }
      iVar5 = 1;
      DAT_00824f74 = iVar4;
      for (iVar2 = 1; iVar2 <= local_7c; iVar2 = iVar2 + 1) {
        (&DAT_01fb8daf)[iVar5] = *(undefined1 *)((int)&ITEM_LEN + iVar4 + 3);
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 1;
      }
      iVar4 = DAT_0078d85c + 1;
      iVar5 = ((DAT_00824f78 + DAT_0078d85c) - iVar4) + 1;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      iVar2 = 1;
      for (iVar6 = 1; iVar6 <= iVar5; iVar6 = iVar6 + 1) {
        (&DAT_01fb8daf)[iVar4] = (&DAT_01fb8cf7)[iVar2];
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 1;
      }
      DAT_00824f78 = DAT_0078d85c + DAT_00824f78;
      if (DAT_00824f7c < 1) {
        local_3c = 0;
      }
      else {
        while (*(char *)((int)&ITEM_LEN + DAT_01caea48 + DAT_01c585d4 + 3) == ' ') {
          DAT_01caea48 = DAT_01caea48 + 1;
          local_34 = 0;
        }
        local_38 = 0;
        DAT_00824f7c = DAT_01c585c8 - DAT_01caea48;
        local_7c = DAT_00824f7c;
        if (DAT_00824f7c < 0) {
          local_7c = 0;
        }
        iVar5 = DAT_01caea48 + DAT_01c585d4;
        iVar4 = 1;
        for (iVar2 = 1; iVar2 <= local_7c; iVar2 = iVar2 + 1) {
          (&DAT_01fb8cf7)[iVar4] = *(undefined1 *)((int)&ITEM_LEN + iVar5 + 3);
          iVar5 = iVar5 + 1;
          iVar4 = iVar4 + 1;
        }
        if ((char)DAT_01fb8cf8 == '_') {
          local_30 = 0;
        }
        else {
          iVar2 = 1;
          iVar4 = DAT_01c585d4;
          for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
            (&DAT_01fb8cf7)[iVar2] = *(undefined1 *)((int)&ITEM_LEN + iVar4 + 3);
            iVar4 = iVar4 + 1;
            iVar2 = iVar2 + 1;
          }
          iVar4 = DAT_00824f7c;
          if (DAT_00824f7c < 0) {
            iVar4 = 0;
          }
          iVar5 = DAT_01caea48 + DAT_01c585d4;
          iVar2 = 4;
          for (iVar6 = 1; iVar6 <= iVar4; iVar6 = iVar6 + 1) {
            (&DAT_01fb8cf7)[iVar2] = *(undefined1 *)((int)&ITEM_LEN + iVar5 + 3);
            iVar5 = iVar5 + 1;
            iVar2 = iVar2 + 1;
          }
          DAT_00824f7c = DAT_00824f7c + 3;
        }
      }
      FUN_004727bc(&DAT_01c585cc,&DAT_00824f84,&DAT_00824f78,&DAT_00824f70,&DAT_01fb8db0,1,
                   &DAT_00824f8c);
      if (DAT_00824f7c < 1) {
        local_84 = (ITEM_WORDS - DAT_00824f88) + 1;
        thunk_FUN_0054c590(&ITEM_LEN + DAT_00824f88,&DAT_01e9997c + DAT_00824f70,&local_84);
        ITEM_WORDS = ((ITEM_WORDS + DAT_00824f70) - DAT_00824f88) + 1;
        if (1 < EDIT_ITEM) {
          EDIT_ITEM = EDIT_ITEM + -1;
        }
        local_2c = 0;
      }
      else {
        local_84 = DAT_00824f8c + 2;
        thunk_FUN_0054c590(&ITEM_LEN + DAT_01c585cc,&DAT_01e9997c + DAT_00824f70,&local_84);
        FUN_004727bc(&DAT_01c585cc,&DAT_00824f70,&DAT_00824f7c,&DAT_00824f80,&DAT_01fb8cf8,1,
                     &DAT_00824f8c);
        local_84 = ITEM_WORDS - DAT_00824f88;
        thunk_FUN_0054c590(&ITEM_LEN + DAT_00824f88,&DAT_01e9997c + DAT_00824f80,&local_84);
        ITEM_WORDS = (ITEM_WORDS + DAT_00824f80) - DAT_00824f88;
        local_28 = 0;
      }
      goto LAB_00472692;
    }
    DAT_00824f78 = DAT_00824f78 + -1;
    iVar4 = DAT_00824f78;
    if (DAT_00824f78 < 0) {
      iVar4 = 0;
    }
    puVar7 = &stack0xffffff6c;
    for (uVar3 = iVar4 + 7U & 0xfffffff8; 0x1000 < (int)uVar3; uVar3 = uVar3 - 0x1000) {
      puVar7 = puVar7 + -0x1000;
    }
    local_7c = (int)puVar7 - uVar3;
    local_80 = 2;
    for (iVar5 = 1; iVar5 <= iVar4; iVar5 = iVar5 + 1) {
      *(undefined *)(local_7c + -1 + iVar5) = (&DAT_01fb8cf7)[local_80];
      local_80 = local_80 + 1;
    }
    local_84 = 1;
    DAT_01caea48 = DAT_00824f78;
    for (iVar5 = 1; iVar5 <= iVar4; iVar5 = iVar5 + 1) {
      (&DAT_01fb8cf7)[local_84] = *(undefined1 *)(local_7c + -1 + iVar5);
      local_84 = local_84 + 1;
    }
    FUN_004727bc(&DAT_01c585cc,&DAT_01c585cc,&DAT_00824f78,&DAT_01c585c4,&DAT_01fb8cf8,1,
                 &DAT_00824f8c);
    (&DAT_01e9998c)[DAT_01c585cc] = (float)(&DAT_01e9998c)[DAT_01c585cc] + f_5;
    local_84 = DAT_00824f8c + 2;
    thunk_FUN_0054c590(&ITEM_LEN + DAT_01c585cc,&DAT_01e9997c + DAT_01c585c4,&local_84);
    iVar5 = DAT_00824f78 + DAT_01c585d4 + 1;
    iVar4 = DAT_00824f7c;
    if (DAT_00824f7c < 0) {
      iVar4 = 0;
    }
    iVar6 = 1;
    DAT_00824f80 = iVar5;
    for (iVar2 = 1; iVar2 <= iVar4; iVar2 = iVar2 + 1) {
      (&DAT_01fb8cf7)[iVar6] = *(undefined1 *)((int)&ITEM_LEN + iVar5 + 3);
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 1;
    }
    FUN_004727bc(&DAT_01c585cc,&DAT_01c585c4,&DAT_00824f7c,&DAT_01c585c4,&DAT_01fb8cf8,1,
                 &DAT_00824f8c);
    local_84 = (ITEM_WORDS - DAT_00824f88) + 1;
    thunk_FUN_0054c590(&ITEM_LEN + DAT_00824f88,&DAT_01e9997c + DAT_01c585c4,&local_84);
    ITEM_WORDS = ((ITEM_WORDS + DAT_01c585c4) - DAT_00824f88) + 1;
    local_40 = 0;
  }
  else {
    local_58 = 0;
    DAT_00824f6c = 0;
    if (EDIT_ITEM < ITEM_I + -1) {
      DAT_00824f6c = (&DAT_02091d24)[EDIT_ITEM];
    }
    DAT_01caea48 = 0;
    DAT_00824f80 = DAT_01c585c8 + DAT_01c585d4 + -1;
    for (local_24 = ((DAT_01c585d4 - DAT_00824f80) + -1) / -1; 0 < local_24;
        local_24 = local_24 + -1) {
      if (*(char *)((int)&ITEM_LEN + DAT_00824f80 + 3) == ' ') {
        DAT_01c585c4 = DAT_01c585c4 + 1;
        if (DAT_01caea44 == DAT_01c585c4) {
          local_1c = 0;
          goto LAB_00471902;
        }
      }
      else {
        local_20 = 0;
      }
      DAT_01caea48 = DAT_01caea48 + 1;
      DAT_00824f80 = DAT_00824f80 + -1;
    }
    thunk_FUN_0054d831(&DAT_007620f0,0x24);
LAB_00471902:
    iVar4 = DAT_01caea48;
    if (DAT_01caea48 < 0) {
      iVar4 = 0;
    }
    iVar6 = 1;
    iVar5 = DAT_00824f80;
    for (iVar2 = 1; iVar2 <= iVar4; iVar2 = iVar2 + 1) {
      (&DAT_01fb8daf)[iVar6] = *(undefined1 *)((int)&ITEM_P1 + iVar5);
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 1;
    }
    DAT_00824f7c = (DAT_01c585c8 - DAT_01caea48) + -1;
    iVar4 = DAT_00824f7c;
    if (DAT_00824f7c < 0) {
      iVar4 = 0;
    }
    iVar2 = 1;
    iVar5 = DAT_01c585d4;
    for (iVar6 = 1; iVar6 <= iVar4; iVar6 = iVar6 + 1) {
      (&DAT_01fb8cf7)[iVar2] = *(undefined1 *)((int)&ITEM_LEN + iVar5 + 3);
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 1;
    }
    DAT_00824f78 = DAT_01caea48;
    if (DAT_01fb8db0 == '_') {
      local_18 = 0;
    }
    else {
      local_14 = ((DAT_01c585d4 - DAT_00824f80) + -1) / -1;
      DAT_01caea64 = DAT_00824f80;
      if (0 < local_14) {
LAB_00471a0a:
        if (*(char *)((int)&ITEM_LEN + DAT_01caea64 + 3) != '_') goto code_r0x00471a1c;
        local_10 = 0;
        DAT_0078d85c = DAT_01caea48;
        iVar4 = DAT_01caea64;
        for (local_8 = -DAT_01caea48 / -1; DAT_01caea64 = iVar4, 0 < local_8; local_8 = local_8 + -1
            ) {
          (&DAT_01fb8db2)[DAT_0078d85c] = (&DAT_01fb8daf)[DAT_0078d85c];
          DAT_0078d85c = DAT_0078d85c + -1;
          iVar4 = DAT_01caea64;
        }
        iVar5 = 1;
        for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
          (&DAT_01fb8daf)[iVar5] = *(undefined1 *)((int)&ITEM_LEN + iVar4 + 3);
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 1;
        }
        DAT_00824f78 = DAT_01caea48 + 3;
        goto LAB_00471afc;
      }
LAB_00471af5:
      local_c = 0;
    }
LAB_00471afc:
    puVar7 = &DAT_01fb8db0 + DAT_00824f78;
    DAT_00824f78 = DAT_00824f78 + 1;
    *puVar7 = 0x20;
    thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&DAT_00824f88);
    DAT_00824f70 = DAT_00824f88;
    if (DAT_00824f7c < 1) {
      DAT_00824f70 = DAT_01c585cc;
    }
    else {
      FUN_004727bc(&DAT_01c585cc,&DAT_01c585cc,&DAT_00824f7c,&DAT_00824f70,&DAT_01fb8cf8,1,
                   &DAT_00824f8c);
    }
    if (((DAT_020b8ea3 == 'X') || (ITEM_I == EDIT_ITEM)) ||
       (((float)(&ITEM_P1)[DAT_00824f88] != f_16 ||
        ((float)(&ITEM_P2)[DAT_01c585cc] != (float)(&ITEM_P2)[DAT_00824f88])))) {
      DAT_00824f78 = DAT_00824f78 + -1;
      (&ITEM_P4)[DAT_01c585cc] = (float)(&ITEM_P4)[DAT_01c585cc] - f_5;
      local_84 = DAT_00824f8c + 2;
      thunk_FUN_0054c590(&ITEM_LEN + DAT_01c585cc,&DAT_01e9997c + DAT_00824f70,&local_84);
      DAT_00824f6c = DAT_00824f88;
      DAT_00824f88 = DAT_01c585cc;
    }
    else {
      iVar4 = (DAT_00824f8c + DAT_00824f88) * 4 + 1;
      local_80 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      DAT_00824f80 = (int)ROUND(*(float *)(&ITEM_P12 + DAT_00824f88 * 4));
      iVar5 = DAT_00824f78 + 1;
      iVar2 = ((DAT_00824f80 + DAT_00824f78) - iVar5) + 1;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      DAT_00824f74 = iVar4;
      for (local_7c = 1; local_7c <= iVar2; local_7c = local_7c + 1) {
        bVar1 = *(byte *)((int)&ITEM_LEN + iVar4 + 3);
        local_80 = (uint)bVar1;
        (&DAT_01fb8daf)[iVar5] = bVar1;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 1;
      }
      DAT_00824f78 = DAT_00824f80 + DAT_00824f78;
    }
    local_84 = DAT_00824f8c + 2;
    thunk_FUN_0054c590(&ITEM_LEN + DAT_00824f88,&DAT_01e9997c + DAT_00824f70,&local_84);
    FUN_004727bc(&DAT_01c585cc,&DAT_00824f70,&DAT_00824f78,&DAT_01c585c4,&DAT_01fb8db0,1,
                 &DAT_00824f8c);
    DAT_01c585c8 = DAT_01c585c4;
    if (DAT_00824f6c != 0) {
      local_84 = (ITEM_WORDS - DAT_00824f6c) + 1;
      thunk_FUN_0054c590(&ITEM_LEN + DAT_00824f6c,&DAT_01e9997c + DAT_01c585c4,&local_84);
      DAT_01c585c8 = (ITEM_WORDS + DAT_01c585c8) - DAT_00824f6c;
    }
    ITEM_WORDS = DAT_01c585c8;
  }
LAB_00472692:
  thunk_FUN_0054c590(&DAT_01e99980,&ITEM_P1,&ITEM_WORDS);
  thunk_FUN_00448179();
  iVar4 = (&ITEM_PTR0)[EDIT_ITEM];
  iVar5 = DAT_00824f8c;
  if (DAT_00824f8c < 0) {
    iVar5 = 0;
  }
  iVar2 = 1;
  DAT_01c585cc = iVar4;
  for (iVar6 = 1; iVar4 = iVar4 + 1, iVar6 <= iVar5; iVar6 = iVar6 + 1) {
    *(undefined4 *)(&DAT_020b943c + iVar2 * 4) = (&ITEM_LEN)[iVar4];
    iVar2 = iVar2 + 1;
  }
  DAT_01c585c8 = (int)ROUND(*(float *)(&ITEM_P12 + DAT_01c585cc * 4));
  iVar5 = (DAT_00824f8c + DAT_01c585cc) * 4 + 1;
  iVar4 = DAT_01c585c8;
  if (DAT_01c585c8 < 0) {
    iVar4 = 0;
  }
  iVar6 = 1;
  DAT_01c585c4 = iVar5;
  for (iVar2 = 1; iVar2 <= iVar4; iVar2 = iVar2 + 1) {
    (&DAT_01fb8cf7)[iVar6] = *(undefined1 *)((int)&ITEM_LEN + iVar5 + 3);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 1;
  }
  return;
code_r0x00471a1c:
  DAT_01caea64 = DAT_01caea64 + -1;
  local_14 = local_14 + -1;
  if (local_14 < 1) goto LAB_00471af5;
  goto LAB_00471a0a;
}


