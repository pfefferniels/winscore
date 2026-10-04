// FUN_004479a8 @ 004479a8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004479a8(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_68;
  
  puVar5 = &stack0xfffffffc;
  if (1 < ITEM_WORDS) {
    _DAT_007fcf58 = 1;
    DAT_0078b4e4 = 0x53;
    thunk_FUN_004f7808();
    puVar7 = &DAT_0078b510;
    puVar8 = &DAT_020492a0;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_00448235(&DAT_00760b00);
    if (f_0 < P1) {
      puVar6 = &stack0xfffffffc;
      if (((_DAT_020b8ea0 & 0xff) != 0x20) &&
         (puVar6 = &stack0xfffffffc, (_DAT_020b8ea0 & 0xff) != 0x2d)) {
        local_68 = 0x80;
        DAT_01c585d0 = 1;
        do {
          thunk_FUN_0054c768(&DAT_020b8e9f + DAT_01c585d0);
          DAT_01c585d0 = DAT_01c585d0 + 1;
          local_68 = local_68 + -1;
        } while (0 < local_68);
        puVar7 = (undefined4 *)&DAT_020b8ea0;
        puVar8 = &DAT_0078b510;
        for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        thunk_FUN_00571b78(&DAT_0078b510,0x80,0x78b691,3);
        puVar7 = &DAT_0078b510;
        puVar8 = &DAT_01c4cb60;
        for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        DAT_01caecac = ITEM_WORDS;
        thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&DAT_01caecac);
        DAT_01caea40 = DAT_01caea40 + -1;
        DAT_01caecb0 = ITEM_I;
LAB_00447b20:
        _DAT_01caecb8 = (float)*(int *)(&DAT_01caea60 + DAT_01caea40 * 4);
        iVar3 = -DAT_01caecb0 / -1;
        *(int *)(puVar5 + -0x60) = iVar3;
        iVar4 = DAT_01caecb0;
        while (0 < iVar3) {
          DAT_01caea48 = (&ITEM_PTR0)[iVar4];
          if (_DAT_01caecb8 == (float)(&ITEM_P2)[DAT_01caea48]) {
            *(undefined4 *)(puVar5 + -0x5c) = 0;
            break;
          }
          iVar4 = iVar4 + -1;
          *(int *)(puVar5 + -0x60) = *(int *)(puVar5 + -0x60) + -1;
          iVar3 = *(int *)(puVar5 + -0x60);
        }
        LOAD_I = iVar4 + 1;
        DAT_01caecb4 = 0;
        iVar3 = (DAT_01caecb0 - LOAD_I) + 1;
        *(int *)(puVar5 + -0x58) = iVar3;
        DAT_01c585d0 = LOAD_I;
        while (0 < iVar3) {
          load_item_header();
          (&ITEM_P2)[LOAD_W] = (float)(&ITEM_P2)[LOAD_W] - _DAT_01caecb8;
          if (LOAD_CODE == 8) {
            DAT_01c585d4 = LOAD_W + 4;
            LOAD_P3 = f_1;
            if (4 < LOAD_LEN) {
              LOAD_P3 = (float)(&ITEM_P1)[DAT_01c585d4];
            }
            if (LOAD_P3 == f_0) {
              LOAD_P3 = f_1;
            }
            if (DAT_01caecb4 == 0) {
              _DAT_01caecbc = f_0;
              if (LOAD_LEN < 4) {
                *(undefined4 *)(puVar5 + -0x4c) = 0;
              }
              else {
                _DAT_01caecbc = LOAD_P3 * (float)(&ITEM_LEN)[DAT_01c585d4];
                (&ITEM_LEN)[DAT_01c585d4] = f_0;
              }
              DAT_01caecb4 = 1;
              *(undefined4 *)(puVar5 + -0x48) = 0;
            }
            else {
              *(undefined4 *)(puVar5 + -0x50) = 0;
              if (LOAD_LEN < 4) {
                thunk_FUN_005239c9(&LOAD_I,&DAT_00760af4);
              }
              (&ITEM_LEN)[DAT_01c585d4] = (float)(&ITEM_LEN)[DAT_01c585d4] - _DAT_01caecbc / LOAD_P3
              ;
            }
          }
          else {
            *(undefined4 *)(puVar5 + -0x54) = 0;
          }
          *(undefined4 *)(puVar5 + -0x44) = 0;
          LOAD_I = LOAD_I + 1;
          *(int *)(puVar5 + -0x58) = *(int *)(puVar5 + -0x58) + -1;
          iVar3 = *(int *)(puVar5 + -0x58);
        }
        do {
          *(undefined4 *)(puVar5 + -0x90) = 0;
          *(undefined4 *)(puVar5 + -0xa0) = 0x80;
          *(undefined4 **)(puVar5 + -0x9c) = &DAT_0078b510;
          *(uint **)(puVar5 + -0x98) = &DAT_007fcf60;
          FUN_005f47c0(puVar5 + -0x90,0xffffffff,0x784ff00,&DAT_00760ae8,puVar5 + -0xa0);
          if ((DAT_007fcf60 & 1) != 0) {
            FUN_005f33c9(puVar5,0x447de5);
            FUN_005f34d1(puVar5,0x447e00);
            iVar3 = thunk_FUN_00579410(&DAT_00760ae4);
            if (iVar3 != 0) {
              *(undefined4 *)(puVar5 + -0x34) = 0;
              goto LAB_00447e28;
            }
            *(undefined4 *)(puVar5 + -0x38) = 0;
LAB_00448090:
            thunk_FUN_0054c590(&DAT_01e99980,&ITEM_P1,&DAT_01caecac);
            ITEM_WORDS = DAT_01caecac;
            puVar6 = puVar5;
            break;
          }
          *(undefined4 *)(puVar5 + -0x3c) = 0;
          *(undefined4 *)(puVar5 + -0x30) = 0;
LAB_00447e28:
          DAT_01caecb4 = (&ITEM_PTR0)[DAT_01c585d0];
          DAT_01caea48 = (ITEM_WORDS - DAT_01caecb4) + 1;
          ITEM_WORDS = DAT_01caecb4;
          thunk_FUN_00529628(&DAT_00760adc,&DAT_01caea48,&ITEM_LEN + DAT_01caecb4,&DAT_00760ae0,
                             &DAT_0078b510,0x80);
          if (DAT_0078b4e0 < 0) {
            *(undefined4 *)(puVar5 + -0x2c) = 0;
LAB_00448022:
            *(undefined4 *)(puVar5 + -4) = 0;
            FUN_005f33c9(puVar5,0x448047);
            FUN_005f34d1(puVar5,0x448062);
            _DAT_009ae2d0 = _DAT_020b8ea0;
            ram0x009ae2d4 = _DAT_020b8ea4;
            DAT_009ae2d8 = DAT_020b8ea8;
            DAT_009ae2dc = DAT_020b8eac;
            DAT_009ae2de = DAT_020b8eae;
            goto LAB_00448090;
          }
          DAT_01caea40 = DAT_01caea40 + -1;
          if (DAT_01caea40 < 0) {
            *(undefined4 *)(puVar5 + -0x28) = 0;
            goto LAB_00448022;
          }
          puVar7 = &DAT_0078b510;
          puVar8 = (undefined4 *)&DAT_020b8ea0;
          for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          for (DAT_007fcf54 = 2; (&DAT_020b8e9f)[DAT_007fcf54] != '.';
              DAT_007fcf54 = DAT_007fcf54 + 1) {
          }
          DAT_01c585d4 = DAT_007fcf54;
          while( true ) {
            while (iVar3 = DAT_007fcf54 + -1, (&DAT_020b8e9e)[DAT_007fcf54] == 'Z') {
              *(undefined4 *)(puVar5 + -0x24) = 0;
              puVar6 = &DAT_020b8e9e + DAT_007fcf54;
              DAT_007fcf54 = iVar3;
              *puVar6 = 0x41;
              *(undefined4 *)(puVar5 + -0x18) = 0;
            }
            if ((&DAT_020b8e9e)[DAT_007fcf54] != '9') break;
            *(undefined4 *)(puVar5 + -0x20) = 0;
            puVar6 = &DAT_020b8e9e + DAT_007fcf54;
            DAT_007fcf54 = iVar3;
            *puVar6 = 0x30;
            *(undefined4 *)(puVar5 + -0x14) = 0;
          }
          pcVar1 = &DAT_020b8e9e + DAT_007fcf54;
          pcVar2 = &DAT_020b8e9e + DAT_007fcf54;
          DAT_007fcf54 = iVar3;
          *pcVar2 = *pcVar1 + '\x01';
          *(undefined4 *)(puVar5 + -0x1c) = 0;
          puVar7 = (undefined4 *)&DAT_020b8ea0;
          puVar8 = &DAT_0078b510;
          for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          if (DAT_01caea40 != 0) goto LAB_00447fe2;
          DAT_01c585d0 = 1;
          *(undefined4 *)(puVar5 + -0xc) = 0;
        } while( true );
      }
      puVar7 = &DAT_020492a0;
      puVar8 = &DAT_0078b510;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      DAT_0078b4e0 = 0x20;
      FUN_005f34d1(puVar6,0x448100);
      DAT_0078b4e4 = 0x53;
      FUN_005f33c9(puVar6,0x44812d);
      FUN_005f33c9(puVar6,0x448149);
      FUN_005f34d1(puVar6,0x448164);
      thunk_FUN_00522bd8();
      thunk_FUN_00549422();
    }
  }
  return;
LAB_00447fe2:
  *(undefined4 *)(puVar5 + -0x10) = 0;
  DAT_01caecb0 = DAT_01c585d0 + -1;
  *(undefined4 *)(puVar5 + -8) = 0;
  goto LAB_00447b20;
}


