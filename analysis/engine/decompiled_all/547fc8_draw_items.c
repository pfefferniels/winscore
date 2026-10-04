// draw_items @ 00547fc8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_items(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 in_FPUControlWord;
  undefined2 uVar4;
  
  puVar3 = &stack0xfffffffc;
  if (ITEM_I != 0) {
    if ((DAT_02052740 < 1) || (DAT_0078b378 != 0)) {
      COLOR = 0;
      _DAT_0099f94c = 0;
      _DAT_0099f948 = f_0;
      VEC_LAST_PEN = 0;
      VEC_N = 1;
      draw_page_frame();
      DAT_00791474 = 0;
      if (DAT_00795448 == 0) {
        *DAT_01fbb844 = 0;
      }
      DAT_0078b6a0 = DAT_00791444;
      _DAT_01b11774 = DAT_0099f944;
      _DAT_0099f940 = OUTPUT_MODE;
      do {
        index_items();
        ITEM_COUNT_SAVE = ITEM_I;
        ITEM_I = 1;
        while( true ) {
          NPT = 1;
          *(undefined4 *)(puVar3 + -100) = 0;
          DAT_0099f93c = (&ITEM_PTR0)[ITEM_I];
          DAT_01b11790 = 0;
          _DAT_01b11798 = f_0;
          fVar1 = (float)(&ITEM_LEN)[DAT_0099f93c];
          *(undefined2 *)(puVar3 + -0x94) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x92) = (ushort)*(undefined4 *)(puVar3 + -0x94) | 0xc00;
          *(int *)(puVar3 + -0x90) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x94);
          DAT_0099f938 = *(int *)(puVar3 + -0x90);
          if ((float)(&ITEM_P1)[DAT_0099f93c] == f_0) {
            (&ITEM_P1)[DAT_0099f93c] = f_3;
          }
          if (((float)(&ITEM_P1)[DAT_0099f93c] == f_16) &&
             (DAT_0099f938 = 0xc, *(float *)(&ITEM_P14 + DAT_0099f93c * 4) == f_m1)) {
            DAT_0099f938 = 0x12;
          }
          for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
            *(float *)(&P0 + iVar2 * 4) = f_0;
          }
          *(undefined4 *)(puVar3 + -0x60) = 0x32;
          DAT_0099f934 = 1;
          do {
            if (DAT_0099f938 < DAT_0099f934) {
              *(undefined4 *)(puVar3 + -0x58) = 0;
            }
            else {
              *(undefined4 *)(puVar3 + -0x5c) = 0;
              DAT_0099f93c = DAT_0099f93c + 1;
              *(undefined4 *)(&P0 + DAT_0099f934 * 4) = (&ITEM_LEN)[DAT_0099f93c];
            }
            *(undefined4 *)(puVar3 + -0x54) = 0;
            DAT_0099f934 = DAT_0099f934 + 1;
            *(int *)(puVar3 + -0x60) = *(int *)(puVar3 + -0x60) + -1;
          } while (0 < *(int *)(puVar3 + -0x60));
          if (f_19 <= P1) break;
          *(undefined4 *)(puVar3 + -0x50) = 0;
          if (OUTPUT_MODE == -1) {
            if (f_0 <= P26) {
              DAT_0099f934 = 0;
              if ((P1 == f_16) && (P14 == f_m1)) {
                DAT_0099f934 = 0x10;
              }
              if (f_0 < P26) {
                DAT_0099f934 = 0x1a;
              }
              if (DAT_0099f934 == 0) {
                *(undefined4 *)(puVar3 + -0x28) = 0;
                _DAT_0099f948 = f_0;
              }
              else {
                DAT_01b1179c = *(float *)(&P0 + DAT_0099f934 * 4);
                if (_DAT_0099f948 == DAT_01b1179c) {
                  *(undefined4 *)(puVar3 + -0x24) = 0;
                }
                else {
                  _DAT_0099f948 = DAT_01b1179c;
                  thunk_FUN_004d4f89(&DAT_0099f94c);
                  *(undefined4 *)(puVar3 + -0x20) = 0;
                }
              }
              goto LAB_0054834e;
            }
            *(undefined4 *)(puVar3 + -0x2c) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x30) = 0;
LAB_0054834e:
            (&DAT_020a55a0)[ITEM_I] = *(undefined4 *)(&DAT_020a559c + ITEM_I * 4);
            draw_item();
            if (OUTPUT_MODE == -1) {
              thunk_FUN_004d3e78();
              if (IP1 == 1) {
                DAT_0099f938 = IP6;
                if (IP6 < 0) {
                  DAT_0099f938 = -IP6;
                }
                if ((DAT_0099f938 < 0x14) || (0x17 < DAT_0099f938)) {
                  *(undefined4 *)(puVar3 + -0x18) = 0;
                }
                else {
                  DAT_0099f928 = P26;
                  if (IP6 < 0) {
                    *(undefined4 *)(puVar3 + -0x14) = 0;
                  }
                  else {
                    P26 = f_1;
                    DAT_01b1179c = f_1;
                    thunk_FUN_004d4f89(&DAT_0099f94c);
                  }
                  _DAT_0099f924 = P15;
                  if (P15 == f_0) {
                    _DAT_0099f924 = f_1;
                  }
                  thunk_FUN_004f1d5e(&DAT_0099f924);
                  _DAT_0099f948 = DAT_0099f928;
                  if (0 < IP6) {
                    *(undefined4 *)(puVar3 + -0x8c) = 0;
                    FUN_005fc330(puVar3 + -0x8c,0x18,0x784ff00,&DAT_007691c0,0,&DAT_007975b8);
                  }
                }
              }
              else {
                *(undefined4 *)(puVar3 + -0x1c) = 0;
              }
              if (_DAT_0099f948 == f_0) {
                *(undefined4 *)(puVar3 + -0xc) = 0;
                goto LAB_005485d9;
              }
              DAT_0099f920 = (&DAT_02091d20)[ITEM_I];
              _DAT_0099f91c = f_0;
              if (f_26 <= (float)(&ITEM_LEN)[DAT_0099f920]) {
                _DAT_0099f91c = *(float *)(&ITEM_P26 + DAT_0099f920 * 4);
              }
              if (((float)(&ITEM_P1)[DAT_0099f920] == f_16) &&
                 (*(float *)(&ITEM_P14 + DAT_0099f920 * 4) == f_m1)) {
                _DAT_0099f91c = *(float *)(&ITEM_P16 + DAT_0099f920 * 4);
              }
              if (_DAT_0099f948 != _DAT_0099f91c) {
                *(undefined4 *)(puVar3 + -0x8c) = 0;
                FUN_005fc330(puVar3 + -0x8c,0x18,0x784ff00,&DAT_007691c0,0,&DAT_007975c8);
              }
            }
            else {
              if (1 < NPT) {
                flush_points();
              }
              *(int *)(ITEM_I * 4 + 0x7978fc) = VEC_N + 1;
            }
            DAT_01b11790 = 0;
          }
LAB_005485d9:
          ITEM_I = ITEM_I + 1;
          *(int *)(&DAT_020359fc + ITEM_I * 4) = VEC_N;
          NPT = 1;
          if (ITEM_COUNT_SAVE < ITEM_I) {
            ITEM_I = ITEM_COUNT_SAVE;
            DAT_020b8ea0._0_1_ = DAT_00769150;
            *DAT_01fbb7c0 = VEC_N + -1;
            return;
          }
          *(undefined4 *)(puVar3 + -4) = 0;
        }
        if (P1 == f_999) {
          *(undefined4 *)(puVar3 + -0x4c) = 0;
        }
        else {
          FUN_005f33c9(puVar3,0x548661);
          FUN_005f34d1(puVar3,0x54867c);
          *(undefined4 *)(puVar3 + -0x8c) = 0;
          *(undefined4 *)(puVar3 + -0xa0) = 4;
          *(undefined1 **)(puVar3 + -0x9c) = &DAT_020b8ea5;
          *(int **)(puVar3 + -0x98) = &ITEM_I;
          FUN_005f34f0(puVar3 + -0x8c,0x784ff00,&DAT_0076915c,puVar3 + -0xa0,&DAT_00797568);
          *(undefined2 *)(puVar3 + -0x94) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x92) = (ushort)*(undefined4 *)(puVar3 + -0x94) | 0xc00;
          *(int *)(puVar3 + -0x90) = (int)ROUND(P1);
          uVar4 = *(undefined2 *)(puVar3 + -0x94);
          DAT_0099f938 = *(int *)(puVar3 + -0x90);
          *(undefined4 *)(puVar3 + -0x8c) = 0;
          *(undefined4 *)(puVar3 + -0xa0) = 2;
          *(undefined **)(puVar3 + -0x9c) = &DAT_020b8edf;
          *(int **)(puVar3 + -0x98) = &DAT_0099f938;
          FUN_005f34f0(puVar3 + -0x8c,0x784ff00,&DAT_0076915c,puVar3 + -0xa0,&DAT_0079757c);
          *(undefined2 *)(puVar3 + -0x94) = uVar4;
          *(ushort *)(puVar3 + -0x92) = (ushort)*(undefined4 *)(puVar3 + -0x94) | 0xc00;
          *(int *)(puVar3 + -0x90) = (int)ROUND(P2);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x94);
          DAT_0099f938 = *(int *)(puVar3 + -0x90);
          *(undefined4 *)(puVar3 + -0x8c) = 0;
          *(undefined4 *)(puVar3 + -0xa0) = 3;
          *(undefined **)(puVar3 + -0x9c) = &DAT_020b8ee6;
          *(int **)(puVar3 + -0x98) = &DAT_0099f938;
          FUN_005f34f0(puVar3 + -0x8c,0x784ff00,&DAT_0076915c,puVar3 + -0xa0,&DAT_00797590);
          *(undefined4 *)(puVar3 + -0x8c) = 0;
          *(undefined4 *)(puVar3 + -0xa0) = 5;
          *(undefined **)(puVar3 + -0x9c) = &DAT_020b8eee;
          *(float **)(puVar3 + -0x98) = &P3;
          FUN_005f34f0(puVar3 + -0x8c,0x784ff00,&DAT_00769154,puVar3 + -0xa0,&DAT_007975a4);
          FUN_0054d831(&DAT_020b8ea0,0x200);
        }
        DAT_0099f934 = (&ITEM_PTR0)[ITEM_I];
        fVar1 = (float)(&ITEM_LEN)[DAT_0099f934];
        *(undefined2 *)(puVar3 + -0x94) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x92) = (ushort)*(undefined4 *)(puVar3 + -0x94) | 0xc00;
        *(int *)(puVar3 + -0x90) = (int)ROUND(fVar1 + f_1);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x94);
        DAT_0099f92c = *(int *)(puVar3 + -0x90);
        iVar2 = (ITEM_WORDS - DAT_0099f934) + 1;
        *(int *)(puVar3 + -0x38) = iVar2;
        DAT_0099f930 = DAT_0099f934;
        while (0 < iVar2) {
          (&ITEM_LEN)[DAT_0099f934] = (&ITEM_LEN)[DAT_0099f92c + DAT_0099f934];
          DAT_0099f934 = DAT_0099f934 + 1;
          *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
          iVar2 = *(int *)(puVar3 + -0x38);
        }
        ITEM_WORDS = ITEM_WORDS - DAT_0099f92c;
        *(undefined4 *)(puVar3 + -0x34) = 0;
      } while( true );
    }
    index_items();
  }
  return;
}


