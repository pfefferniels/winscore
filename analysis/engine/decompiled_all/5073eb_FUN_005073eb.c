// FUN_005073eb @ 005073eb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005073eb(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 in_FPUControlWord;
  float10 fVar4;
  
  puVar3 = &stack0xfffffffc;
  for (iVar2 = 1; iVar2 < 0x1f5; iVar2 = iVar2 + 1) {
    (&DAT_01b2a160)[iVar2] = 0;
  }
  DAT_01b2a160 = 0;
  DAT_00940350 = 0;
  DAT_0094034c = 1;
  do {
    DAT_01b9d5c4 = *(int *)(DAT_0094034c * 4 + DAT_01b34580 * 0x40 + 0x1f9393c);
    if (DAT_01b9d5c4 == 0) {
      *(undefined4 *)(puVar3 + -0x3c) = 0;
    }
    else {
      *(int *)(puVar3 + -0x38) = ITEM_I;
      LOAD_I = 1;
      iVar2 = ITEM_I;
      while (0 < iVar2) {
        load_item_header();
        if (DAT_01b9d5c4 < LOAD_STAFF) {
          *(undefined4 *)(puVar3 + -0x34) = 0;
          break;
        }
        if (LOAD_CODE == 0xe) {
          DAT_00940348 = 1;
          if (3 < LOAD_LEN) {
            fVar1 = (float)(&ITEM_P4)[LOAD_W];
            *(undefined2 *)(puVar3 + -0x68) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x66) = (ushort)*(undefined4 *)(puVar3 + -0x68) | 0xc00;
            *(int *)(puVar3 + -100) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x68);
            DAT_00940348 = *(int *)(puVar3 + -100);
          }
          if (DAT_00940348 == 0) {
            DAT_00940348 = 1;
          }
          if (DAT_01b9d5c4 - LOAD_STAFF < DAT_00940348) {
            iVar2 = DAT_01b2a160 + 1;
            DAT_01b2a160 = iVar2;
            fVar4 = (float10)anint(puVar3,0x507559);
            *(int *)(puVar3 + -100) = (int)ROUND(fVar4);
            (&DAT_01b2a160)[iVar2] = DAT_00940350 + *(int *)(puVar3 + -100);
          }
          else {
            *(undefined4 *)(puVar3 + -0x2c) = 0;
          }
        }
        else {
          *(undefined4 *)(puVar3 + -0x30) = 0;
        }
        *(undefined4 *)(puVar3 + -0x28) = 0;
        LOAD_I = LOAD_I + 1;
        *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
        iVar2 = *(int *)(puVar3 + -0x38);
      }
      DAT_00940350 = DAT_00940350 + 400;
    }
    *(undefined4 *)(puVar3 + -0x24) = 0;
    DAT_0094034c = DAT_0094034c + 1;
    *(int *)(puVar3 + -0x40) = *(int *)(puVar3 + -0x40) + -1;
    if (*(int *)(puVar3 + -0x40) < 1) {
      while( true ) {
        DAT_00940344 = 0;
        iVar2 = DAT_01b2a160 + -1;
        *(int *)(puVar3 + -0x20) = iVar2;
        DAT_0094034c = 2;
        while (0 < iVar2) {
          if ((&DAT_01b2a160)[DAT_0094034c] - *(int *)(DAT_0094034c * 4 + 0x1b2a15c) < -1) {
            thunk_FUN_0054c68f(&DAT_01b2a160 + DAT_0094034c,DAT_0094034c * 4 + 0x1b2a15c);
            DAT_00940344 = 1;
          }
          else {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
          }
          *(undefined4 *)(puVar3 + -0x18) = 0;
          DAT_0094034c = DAT_0094034c + 1;
          *(int *)(puVar3 + -0x20) = *(int *)(puVar3 + -0x20) + -1;
          iVar2 = *(int *)(puVar3 + -0x20);
        }
        if (DAT_00940344 == 0) break;
        *(undefined4 *)(puVar3 + -0x14) = 0;
      }
      DAT_00940344 = 2;
      do {
        iVar2 = (DAT_01b2a160 - DAT_00940344) + 1;
        *(int *)(puVar3 + -0x10) = iVar2;
        DAT_0094034c = DAT_00940344;
        while( true ) {
          if (iVar2 < 1) {
            return;
          }
          if ((&DAT_01b2a160)[DAT_0094034c] == *(int *)(DAT_0094034c * 4 + 0x1b2a15c)) break;
          *(undefined4 *)(puVar3 + -0xc) = 0;
          *(undefined4 *)(puVar3 + -4) = 0;
          DAT_0094034c = DAT_0094034c + 1;
          *(int *)(puVar3 + -0x10) = *(int *)(puVar3 + -0x10) + -1;
          iVar2 = *(int *)(puVar3 + -0x10);
        }
        DAT_01b2a160 = DAT_01b2a160 + -1;
        DAT_00940340 = DAT_0094034c;
        DAT_00940344 = DAT_0094034c;
        for (iVar2 = (DAT_01b2a160 - DAT_0094034c) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
          DAT_0094034c = DAT_00940344;
          (&DAT_01b2a160)[DAT_00940340] = (&DAT_01b2a164)[DAT_00940340];
          DAT_00940340 = DAT_00940340 + 1;
          DAT_00940344 = DAT_0094034c;
        }
        *(undefined4 *)(puVar3 + -8) = 0;
      } while( true );
    }
  } while( true );
}


