// FUN_004b3fe8 @ 004b3fe8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004b4075) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b3fe8(void)

{
  undefined1 *puVar1;
  float fVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  undefined2 in_FPUControlWord;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x4b400e);
  *(undefined4 *)(puVar3 + -0x4c) = 0x200;
  DAT_0089f3c8 = 0x200;
  do {
    if ((&DAT_020b909f)[DAT_0089f3c8] == '\"') {
      *(undefined4 *)(puVar3 + -0x48) = 0;
      break;
    }
    DAT_0089f3c8 = DAT_0089f3c8 + -1;
    *(int *)(puVar3 + -0x4c) = *(int *)(puVar3 + -0x4c) + -1;
  } while (0 < *(int *)(puVar3 + -0x4c));
  FUN_005f46bc(puVar3,0x4b4099);
  FUN_005f34d1(puVar3,0x4b40af);
  thunk_FUN_00518b3f(&DAT_0076466c);
  DAT_0089f3c4 = 0;
  FUN_005f34d1(puVar3,0x4b40ea);
  DAT_0089f3c8 = **(int **)(puVar3 + 8) + 1;
  iVar4 = 0x201 - DAT_0089f3c8;
  *(int *)(puVar3 + -0x44) = iVar4;
  while( true ) {
    if (iVar4 < 1) {
      thunk_FUN_0054d831("*** Closing \" missing. ***",0x1b);
      *(undefined4 *)(puVar3 + -0x3c) = 0;
      return;
    }
    if ((&DAT_020b909f)[DAT_0089f3c8] == '\"') break;
    puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_0089f3c4);
    DAT_0089f3c4 = DAT_0089f3c4 + 1;
    *puVar1 = (&DAT_020b909f)[DAT_0089f3c8];
    DAT_0089f3c8 = DAT_0089f3c8 + 1;
    *(int *)(puVar3 + -0x44) = *(int *)(puVar3 + -0x44) + -1;
    iVar4 = *(int *)(puVar3 + -0x44);
  }
  *(undefined4 *)(puVar3 + -0x40) = 0;
  DAT_0089f3c0 = 100;
  DAT_0089f3bc = DAT_0089f3c8 + 1;
  iVar4 = 0x201 - DAT_0089f3bc;
  *(int *)(puVar3 + -0x38) = iVar4;
  while( true ) {
    if (iVar4 < 1) {
      thunk_FUN_0054d831("*** Missing \" ***",0x12);
      *(undefined4 *)(puVar3 + -0x30) = 0;
      return;
    }
    if ((&DAT_020b909f)[DAT_0089f3bc] == '\"') break;
    DAT_0089f3bc = DAT_0089f3bc + 1;
    *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
    iVar4 = *(int *)(puVar3 + -0x38);
  }
  *(undefined4 *)(puVar3 + -0x34) = 0;
  DAT_0089f3b8 = DAT_0089f3bc + 1;
  iVar4 = 0x201 - DAT_0089f3b8;
  *(int *)(puVar3 + -0x2c) = iVar4;
  while( true ) {
    if (iVar4 < 1) {
      thunk_FUN_0054d831("*** Closing \" missing. ***",0x1b);
      *(undefined4 *)(puVar3 + -0x24) = 0;
      return;
    }
    if ((&DAT_020b909f)[DAT_0089f3b8] == '\"') break;
    puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_0089f3c0);
    DAT_0089f3c0 = DAT_0089f3c0 + 1;
    *puVar1 = (&DAT_020b909f)[DAT_0089f3b8];
    DAT_0089f3b8 = DAT_0089f3b8 + 1;
    *(int *)(puVar3 + -0x2c) = *(int *)(puVar3 + -0x2c) + -1;
    iVar4 = *(int *)(puVar3 + -0x2c);
  }
  *(undefined4 *)(puVar3 + -0x28) = 0;
  iVar4 = ITEM_I;
  if (P4 == f_0) {
    P4 = P1;
  }
  if (P3 == f_0) {
    P3 = DAT_01fbb8b8;
  }
  if (P1 == f_0) {
    P1 = f_1;
    P4 = f_256;
  }
  *(int *)(puVar3 + -0x20) = ITEM_I;
  LOAD_I = 1;
  while (0 < iVar4) {
    load_item_header();
    if ((((P3 < LOAD_P3) || (LOAD_P3 < P2)) || (P4 < (float)LOAD_STAFF)) ||
       ((LOAD_CODE != 0x10 || ((float)LOAD_STAFF < P1)))) {
      *(undefined4 *)(puVar3 + -0x1c) = 0;
    }
    else {
      DAT_0089f3b4 = DAT_0089f3c0 + -100;
      DAT_0089f3c8 = DAT_0089f3b4 - DAT_0089f3c4;
      DAT_0089f3ac = LOAD_W * 4 + 0x35;
      DAT_0089f3b8 = 1;
      DAT_0089f3b0 = DAT_0089f3ac;
      while( true ) {
        iVar4 = FUN_005f4660(0x20);
        if (iVar4 == 0) {
          *(undefined4 *)(puVar3 + -0x18) = 0;
        }
        else {
          if (DAT_0089f3c8 == 0) {
            *(undefined4 *)(puVar3 + -0x14) = 0;
          }
          else {
            fVar2 = *(float *)(&ITEM_P12 + LOAD_W * 4);
            *(undefined2 *)(puVar3 + -0x74) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x72) = (ushort)*(undefined4 *)(puVar3 + -0x74) | 0xc00;
            *(int *)(puVar3 + -0x70) = (int)ROUND(fVar2);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x74);
            DAT_0089f3a8 = *(int *)(puVar3 + -0x70);
            DAT_0089f3a4 = DAT_0089f3a8 + DAT_0089f3b0 + -1;
            *(float *)(&ITEM_P12 + LOAD_W * 4) =
                 (float)DAT_0089f3c8 + *(float *)(&ITEM_P12 + LOAD_W * 4);
            DAT_0089f3a0 = LOAD_LEN + -0xd;
            DAT_0089f39c = (DAT_0089f3c8 + DAT_0089f3a8) / 4;
            uVar5 = DAT_0089f3c8 + DAT_0089f3a8 & 3;
            if ((uVar5 != 0) && (DAT_0089f3c8 + DAT_0089f3a8 < 0)) {
              uVar5 = uVar5 - 4;
            }
            if (uVar5 != 0) {
              DAT_0089f39c = DAT_0089f39c + 1;
            }
            _DAT_0089f398 = (float)DAT_0089f39c + f_13;
            if (DAT_0089f3c8 < 1) {
              if (DAT_0089f3c8 < 0) {
                iVar4 = (DAT_0089f3a4 - DAT_0089f3ac) + 1;
                *(int *)(puVar3 + -0xc) = iVar4;
                DAT_0089f394 = DAT_0089f3ac;
                while (0 < iVar4) {
                  *(undefined1 *)((int)&ITEM_LEN + DAT_0089f394 + 3) =
                       *(undefined1 *)((int)&ITEM_LEN + (DAT_0089f394 - DAT_0089f3c8) + 3);
                  DAT_0089f394 = DAT_0089f394 + 1;
                  *(int *)(puVar3 + -0xc) = *(int *)(puVar3 + -0xc) + -1;
                  iVar4 = *(int *)(puVar3 + -0xc);
                }
                if (DAT_0089f3a0 != DAT_0089f39c) {
                  thunk_FUN_005239c9(&LOAD_I,&DAT_0089f398);
                }
              }
            }
            else {
              if (DAT_0089f3a0 != DAT_0089f39c) {
                thunk_FUN_005239c9(&LOAD_I,&DAT_0089f398);
              }
              iVar4 = ((DAT_0089f3ac - DAT_0089f3a4) + -1) / -1;
              *(int *)(puVar3 + -0x10) = iVar4;
              DAT_0089f394 = DAT_0089f3a4;
              while (0 < iVar4) {
                *(undefined1 *)((int)&ITEM_LEN + DAT_0089f3c8 + DAT_0089f394 + 3) =
                     *(undefined1 *)((int)&ITEM_LEN + DAT_0089f394 + 3);
                DAT_0089f394 = DAT_0089f394 + -1;
                *(int *)(puVar3 + -0x10) = *(int *)(puVar3 + -0x10) + -1;
                iVar4 = *(int *)(puVar3 + -0x10);
              }
            }
          }
          *(undefined4 *)(puVar3 + -0x70) = 100;
          FUN_005f46bc(puVar3,0x4b4687);
          FUN_005f34d1(puVar3,0x4b469d);
        }
        DAT_0089f3ac = DAT_0089f3ac + 1;
        DAT_0089f3b8 = DAT_0089f3b8 + 1;
        if (*(float *)(&ITEM_P12 + LOAD_W * 4) < (float)DAT_0089f3b8) break;
        *(undefined4 *)(puVar3 + -8) = 0;
      }
    }
    *(undefined4 *)(puVar3 + -4) = 0;
    LOAD_I = LOAD_I + 1;
    *(int *)(puVar3 + -0x20) = *(int *)(puVar3 + -0x20) + -1;
    iVar4 = *(int *)(puVar3 + -0x20);
  }
  FUN_005f34d1(puVar3,0x4b4732);
  **(undefined4 **)(puVar3 + 8) = DAT_02052740;
  DAT_02052740 = 0;
  draw_items();
  DAT_02052740 = **(undefined4 **)(puVar3 + 8);
  thunk_FUN_00549422();
  return;
}


