// FUN_00572c60 @ 00572c60 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00572c60(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int local_68;
  
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  if (((_DAT_020b8ea0 & 0xff) == 0x3a) || ((_DAT_020b8ea0 & 0xff) == 0x27)) {
    DAT_01e67950 = 2;
    if (*param_1 < 2) {
LAB_005734b7:
      _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_0076a5d0);
      return;
    }
    while( true ) {
      DAT_01e67940 = 1;
      while( true ) {
        cVar1 = (&DAT_020b8e9f)[DAT_01e67950];
        _DAT_009a8890 = CONCAT31(DAT_009a8890_1,cVar1);
        if ((cVar1 != ':') && (cVar1 != '\'')) break;
        DAT_01e67940 = DAT_01e67940 + 1;
        DAT_01e67950 = DAT_01e67950 + 1;
      }
      DAT_01e67944 = 0;
      DAT_01e67954 = DAT_01e67940;
      if (3 < DAT_01e67940) break;
      local_68 = 0x50;
      DAT_01e67948 = 1;
      do {
        *(undefined1 *)(DAT_01e67948 * 3 + DAT_01e67940 + 0x1a1af3c) = 0x20;
        DAT_01e67948 = DAT_01e67948 + 1;
        local_68 = local_68 + -1;
      } while (0 < local_68);
      iVar2 = (*param_1 - DAT_01e67950) + 1;
      DAT_01e67948 = DAT_01e67950;
      while( true ) {
        if (iVar2 < 1) {
          if (DAT_01e67944 != 0) {
            return;
          }
          goto LAB_005734b7;
        }
        cVar1 = (&DAT_020b8e9f)[DAT_01e67948];
        DAT_009a8890_1 = (undefined3)((uint)_DAT_009a8890 >> 8);
        _DAT_009a8890 = CONCAT31(DAT_009a8890_1,cVar1);
        if ((cVar1 == ':') || (cVar1 == '\'')) break;
        DAT_009a888c = DAT_01e67948 - DAT_01e67954;
        (&DAT_020b8e9f)[DAT_009a888c] = cVar1;
        (&DAT_020b909f)[DAT_009a888c] = (char)_DAT_009a8890;
        if (DAT_009a888c < 0x11) {
          *(char *)((int)&DAT_020b8e5c + DAT_009a888c + 3) = (char)_DAT_009a8890;
        }
        (&DAT_020b8e9f)[DAT_01e67948] = 0x20;
        (&DAT_020b909f)[DAT_01e67948] = 0x20;
        DAT_01e67944 = DAT_01e67944 + 1;
        *(char *)(DAT_01e67944 * 3 + DAT_01e67940 + 0x1a1af3c) = (char)_DAT_009a8890;
        DAT_01e67948 = DAT_01e67948 + 1;
        iVar2 = iVar2 + -1;
      }
      DAT_01e67950 = DAT_01e67948 + 1;
    }
  }
  else {
    DAT_01e67948 = 0;
    DAT_009a8888 = (uint)((_DAT_020b8ea0 & 0xff) == 0x60);
    DAT_01a1b030 = 0;
    DAT_01a1b034 = 0;
    _DAT_01a1b038 = 0;
    while( true ) {
      DAT_01e67950 = 0;
      do {
        iVar2 = DAT_01e67948 + 1;
        if (*param_1 < iVar2) {
          DAT_01e67948 = iVar2;
          *param_1 = 0;
          FUN_005f34d1(&stack0xfffffffc,0x572dca);
          FUN_005f34d1(puVar5,0x572deb);
          *(undefined4 *)(puVar5 + -0x34) = 3;
          DAT_01e67948 = 1;
          do {
            if (*(int *)(DAT_01e67948 * 4 + 0x1a1b02c) == 0) {
              *(undefined4 *)(puVar5 + -0x30) = 0;
            }
            else {
              DAT_009a8884 = DAT_01e67948;
              *(undefined4 *)(puVar5 + -0x2c) = 0x50;
              DAT_01e67944 = 1;
              do {
                **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
                if (**(int **)(puVar5 + 8) < 0x11) {
                  *(undefined1 *)((int)&DAT_020b8e5c + **(int **)(puVar5 + 8) + 3) =
                       *(undefined1 *)(DAT_01e67944 * 3 + DAT_01e67948 + 0x1a1af3c);
                }
                (&DAT_020b909f)[**(int **)(puVar5 + 8)] =
                     *(undefined1 *)(DAT_01e67944 * 3 + DAT_01e67948 + 0x1a1af3c);
                (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] =
                     *(undefined1 *)(DAT_01e67944 * 3 + DAT_01e67948 + 0x1a1af3c);
                DAT_01e67944 = DAT_01e67944 + 1;
                *(int *)(puVar5 + -0x2c) = *(int *)(puVar5 + -0x2c) + -1;
              } while (0 < *(int *)(puVar5 + -0x2c));
            }
            *(undefined4 *)(puVar5 + -0x28) = 0;
            DAT_01e67948 = DAT_01e67948 + 1;
            *(int *)(puVar5 + -0x34) = *(int *)(puVar5 + -0x34) + -1;
          } while (0 < *(int *)(puVar5 + -0x34));
          if (DAT_009a8888 == 0) {
            *(undefined4 *)(puVar5 + -0x24) = 0;
            return;
          }
          puVar3 = (undefined4 *)&DAT_020b8ea0;
          puVar4 = (undefined4 *)(puVar5 + -0x2a0);
          for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          DAT_009a8880 = FUN_005ff950(puVar5 + -0x2a0,0x200);
          *(undefined1 *)((int)&DAT_020b8ea0 + DAT_009a8880) = 0;
          FUN_005f33c9(puVar5,0x572f6a);
          FUN_005f34d1(puVar5,0x572f85);
          (&DAT_020b90b0)[DAT_009a8884] = 0;
          puVar3 = (undefined4 *)&DAT_020b8ea0;
          puVar4 = &DAT_009ae2bc;
          for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          thunk_FUN_00571f5d(&DAT_020b90a0,0x200);
          if ((char)DAT_020b8ea0 == '\x02') {
            *(undefined4 *)(puVar5 + -0x20) = 0;
            return;
          }
          thunk_FUN_0054c78b(&DAT_009a887c);
          *(undefined4 *)(puVar5 + -0x1c) = 0x50;
          DAT_009a8878 = 1;
          do {
            if ((char)(&DAT_020b8e9f)[DAT_009a8878] < ' ') {
              (&DAT_020b8e9f)[DAT_009a8878] = 0x20;
            }
            *(undefined1 *)(DAT_009a8878 * 3 + DAT_009a8884 + 0x1a1af3c) =
                 (&DAT_020b8e9f)[DAT_009a8878];
            DAT_009a8878 = DAT_009a8878 + 1;
            *(int *)(puVar5 + -0x1c) = *(int *)(puVar5 + -0x1c) + -1;
          } while (0 < *(int *)(puVar5 + -0x1c));
          puVar3 = (undefined4 *)&DAT_020b8ea0;
          puVar4 = (undefined4 *)&DAT_020b90a0;
          for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          *(undefined4 *)(puVar5 + -0x18) = 0;
          return;
        }
      } while ((((*(char *)((int)&DAT_020b8ea0 + DAT_01e67948) == ';') ||
                (*(char *)((int)&DAT_020b8ea0 + DAT_01e67948) == '`')) &&
               (DAT_01e67950 = DAT_01e67950 + 1, DAT_01e67948 = iVar2, iVar2 < *param_1)) ||
              (DAT_01e67948 = iVar2, DAT_01e67950 == 0));
      if (3 < DAT_01e67950) break;
      *(undefined4 *)(DAT_01e67950 * 4 + 0x1a1b02c) = 1;
    }
  }
  FUN_005f33c9(&stack0xfffffffc,0x5732ff);
  FUN_005f34d1(puVar6,0x57331a);
  *(undefined4 *)(puVar6 + -0x10) = 0x4a;
  DAT_01e67948 = 1;
  do {
    (&DAT_020b90a3)[DAT_01e67948] = *(undefined1 *)(DAT_01e67948 * 3 + 0x1a1af3d);
    DAT_01e67948 = DAT_01e67948 + 1;
    *(int *)(puVar6 + -0x10) = *(int *)(puVar6 + -0x10) + -1;
  } while (0 < *(int *)(puVar6 + -0x10));
  DAT_020b90f0 = 0xd;
  DAT_020b90f1 = 10;
  DAT_020b90f2 = i_538983227;
  *(undefined4 *)(puVar6 + -0xc) = 0x4a;
  DAT_01e67948 = 1;
  do {
    *(undefined1 *)((int)&DAT_020b90f2 + DAT_01e67948 + 3) =
         *(undefined1 *)(DAT_01e67948 * 3 + 0x1a1af3e);
    DAT_01e67948 = DAT_01e67948 + 1;
    *(int *)(puVar6 + -0xc) = *(int *)(puVar6 + -0xc) + -1;
  } while (0 < *(int *)(puVar6 + -0xc));
  DAT_020b9141 = 0xd;
  DAT_020b9142 = 10;
  DAT_020b9143 = i_540752699;
  *(undefined4 *)(puVar6 + -8) = 0x4a;
  DAT_01e67948 = 1;
  do {
    *(undefined1 *)(DAT_01e67948 + 0x20b9147) = *(undefined1 *)(DAT_01e67948 * 3 + 0x1a1af3f);
    DAT_01e67948 = DAT_01e67948 + 1;
    *(int *)(puVar6 + -8) = *(int *)(puVar6 + -8) + -1;
  } while (0 < *(int *)(puVar6 + -8));
  DAT_020b9191 = 0;
  thunk_FUN_0054d831(&DAT_020b90a0,0x200);
  _DAT_020b8ea0 = i_538976288;
  _DAT_020b8ea4 = DAT_0076a5e0;
  if (DAT_009a8874 == 0) {
    *(undefined4 *)(puVar6 + -4) = 0;
  }
  else {
    _DAT_020b8ea0 = i_808464434;
    _DAT_020b8ea4 = DAT_0076a5d8;
  }
  return;
}


