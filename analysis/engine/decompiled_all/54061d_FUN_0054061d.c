// FUN_0054061d @ 0054061d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054061d(void)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  float10 fVar6;
  undefined1 *puVar7;
  float local_d4;
  uint local_d0;
  float local_cc;
  undefined4 local_a4;
  int local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  
  puVar7 = &stack0xfffffffc;
  push_words(&DAT_00768e04,&P1);
  if (DAT_020b8ea3 != 'X') {
    thunk_FUN_005725fa();
    DAT_020527a0 = -2;
  }
  DAT_0078b4e4 = 0x53;
  thunk_FUN_004f7808();
  pop_words(&DAT_00768e04,&P1);
  thunk_FUN_0054e546(&DAT_0099d244,&DAT_0099d240);
  if (((int)DAT_007974f4 < 1) || (2 < (int)DAT_007974f4)) {
    DAT_007974f4 = 1.4013e-45;
  }
  if (P2 == f_0) {
    FUN_00541619(&DAT_0099d23c,&DAT_007974f4);
    if (DAT_0099d23c == 2) {
      return;
    }
    local_a4 = 0;
  }
  else {
    for (iVar2 = 1; iVar2 < 0x21; iVar2 = iVar2 + 1) {
      *(undefined4 *)(iVar2 * 4 + 0x99dd94) = 0;
    }
    DAT_01fbb860 = (float)(int)ROUND(P3);
    DAT_01fbb864 = (float)(int)ROUND(P6);
    DAT_01e67910 = P4;
    DAT_01e67914 = P5;
    if (f_2 < P2) {
      P2 = f_1;
    }
    local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_007974f4 = (float)(int)ROUND(P2);
    local_cc = DAT_007974f4;
  }
  if (DAT_01e67914 == f_0) {
    DAT_01e67914 = DAT_01fbb8b8;
  }
  if ((DAT_01fbb860 == 0.0) && (DAT_01fbb864 == 0.0)) {
    if (f_199 < _DAT_0099d244) {
      _DAT_0099d244 = f_199;
    }
    DAT_01fbb860 = (float)(int)ROUND(_DAT_0099d240);
    local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_01fbb864 = (float)(int)ROUND(_DAT_0099d244);
    local_cc = DAT_01fbb864;
  }
  else if (DAT_01fbb864 == 0.0) {
    DAT_01fbb864 = DAT_01fbb860;
  }
LAB_005408fe:
  DAT_0099d238 = 1;
  for (local_a0 = ITEM_I; 0 < local_a0; local_a0 = local_a0 + -1) {
    LOAD_I = DAT_0099d238;
    load_item_header();
    if ((LOAD_STAFF < (int)DAT_01fbb860) || ((int)DAT_01fbb864 < LOAD_STAFF)) {
      local_9c = 0;
    }
    else if (LOAD_CODE == 1) {
      DAT_0099d23c = DAT_0099d238 + 1;
      for (local_94 = (ITEM_I - DAT_0099d23c) + 1; 0 < local_94; local_94 = local_94 + -1) {
        DAT_0099d234 = (&ITEM_PTR0)[DAT_0099d23c];
        if (((float)(&ITEM_P1)[DAT_0099d234] == f_1) &&
           ((float)LOAD_STAFF == (float)(&ITEM_P2)[DAT_0099d234])) {
          if ((LOAD_P3 == (float)(&ITEM_P3)[DAT_0099d234]) &&
             ((float)(&ITEM_P4)[DAT_0099d234] == (float)(&ITEM_P4)[LOAD_W])) {
            DAT_0099d230 = (float)(&ITEM_P5)[LOAD_W];
            DAT_0099d22c = (float)(&ITEM_P5)[DAT_0099d234];
            local_cc = (float)(int)ROUND(DAT_0099d230 / f_10);
            if (local_cc == 0.0) {
              local_cc = (float)(int)ROUND(DAT_0099d22c / f_10);
            }
            local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
            DAT_0099d228 = local_cc;
            local_d4 = DAT_0099d230;
            fVar6 = (float10)FUN_005ff874(&local_d4,&f_10);
            iVar2 = LOAD_W;
            if (fVar6 == (float10)f_0) {
              local_cc = (float)((int)DAT_0099d228 * 10);
              local_d4 = DAT_0099d22c;
              fVar6 = (float10)FUN_005ff874(&local_d4,&f_10);
              (&ITEM_P5)[iVar2] = (float)(fVar6 + (float10)local_cc);
            }
            (&ITEM_P1)[DAT_0099d234] = f_99;
            if (((float)(&ITEM_LEN)[DAT_0099d234] < f_11) ||
               (*(float *)(&ITEM_P11 + DAT_0099d234 * 4) == f_0)) {
              local_88 = 0;
            }
            else {
              DAT_0099d224 = *(undefined4 *)(&ITEM_P11 + DAT_0099d234 * 4);
              if (LOAD_LEN < 0xb) {
                thunk_FUN_005239c9(&LOAD_I,&f_11);
                *(undefined4 *)(&ITEM_P11 + LOAD_W * 4) = DAT_0099d224;
                local_84 = 0;
                goto LAB_005408fe;
              }
              if (*(float *)(&ITEM_P11 + LOAD_W * 4) == f_0) {
                *(undefined4 *)(&ITEM_P11 + LOAD_W * 4) = DAT_0099d224;
              }
            }
          }
          else {
            local_8c = 0;
          }
        }
        else {
          local_90 = 0;
        }
        local_80 = 0;
        DAT_0099d23c = DAT_0099d23c + 1;
      }
    }
    else {
      local_98 = 0;
    }
    local_7c = 0;
    DAT_0099d238 = DAT_0099d238 + 1;
  }
  DAT_0099d238 = 1;
  for (local_78 = ITEM_I; 0 < local_78; local_78 = local_78 + -1) {
    LOAD_I = DAT_0099d238;
    load_item_header();
    if ((LOAD_STAFF < (int)DAT_01fbb860) || ((int)DAT_01fbb864 < LOAD_STAFF)) {
      local_74 = 0;
    }
    else {
      if (LOAD_CODE == 1) {
        local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_cc = (float)(int)ROUND((float)(&ITEM_P5)[LOAD_W] / f_10);
        if (local_cc != 0.0) {
          DAT_0099d23c = DAT_0099d238 + 1;
          iVar2 = LOAD_W;
          for (local_6c = (ITEM_I - DAT_0099d23c) + 1; LOAD_W = iVar2, 0 < local_6c;
              local_6c = local_6c + -1) {
            DAT_0099d234 = (&ITEM_PTR0)[DAT_0099d23c];
            if (((float)(&ITEM_P1)[DAT_0099d234] == f_1) &&
               ((float)LOAD_STAFF == (float)(&ITEM_P2)[DAT_0099d234])) {
              if (ABS((float)(&ITEM_P3)[DAT_0099d234] - LOAD_P3) <= f_0_1) {
                local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                local_cc = (float)(int)ROUND((float)(&ITEM_P5)[DAT_0099d234] / f_10);
                if (local_cc != 0.0) {
                  if (((float)(&ITEM_P5)[DAT_0099d234] < f_20 &&
                       (float)(&ITEM_P4)[DAT_0099d234] < (float)(&ITEM_P4)[iVar2]) ||
                     ((float)(&ITEM_P4)[iVar2] < (float)(&ITEM_P4)[DAT_0099d234] &&
                      f_20 <= (float)(&ITEM_P5)[DAT_0099d234])) {
                    local_d4 = (float)(&ITEM_P5)[iVar2];
                    fVar6 = (float10)FUN_005ff874(&local_d4,&f_10);
                    (&ITEM_P5)[iVar2] = (float)fVar6;
                  }
                  iVar2 = DAT_0099d234;
                  if ((f_20 <= (float)(&ITEM_P5)[DAT_0099d234] &&
                       (float)(&ITEM_P4)[DAT_0099d234] < (float)(&ITEM_P4)[LOAD_W]) ||
                     ((float)(&ITEM_P4)[LOAD_W] < (float)(&ITEM_P4)[DAT_0099d234] &&
                      (float)(&ITEM_P5)[DAT_0099d234] < f_20)) {
                    local_d4 = (float)(&ITEM_P5)[DAT_0099d234];
                    fVar6 = (float10)FUN_005ff874(&local_d4,&f_10);
                    (&ITEM_P5)[iVar2] = (float)fVar6;
                  }
                  goto LAB_00541017;
                }
              }
              local_64 = 0;
            }
            else {
              local_68 = 0;
            }
LAB_00541017:
            local_60 = 0;
            DAT_0099d23c = DAT_0099d23c + 1;
            iVar2 = LOAD_W;
          }
          goto LAB_00541054;
        }
      }
      local_70 = 0;
    }
LAB_00541054:
    local_5c = 0;
    DAT_0099d238 = DAT_0099d238 + 1;
  }
  _DAT_0099d220 = 0;
  LOAD_I = 1;
  local_58 = ITEM_I;
  do {
    puVar3 = &stack0xfffffffc;
    if (local_58 < 1) goto LAB_005411be;
    load_item_header();
    if (LOAD_STAFF < (int)DAT_01fbb860) {
      local_54 = 0;
    }
    else {
      if ((int)DAT_01fbb864 < LOAD_STAFF) {
        local_50 = 0;
        puVar3 = &stack0xfffffffc;
        goto LAB_005411be;
      }
      if (LOAD_CODE == 2) {
        if ((float)(&ITEM_P6)[LOAD_W] < f_0) {
          FUN_005f33c9(&stack0xfffffffc,0x541157);
          FUN_005f34d1(puVar7,0x541172);
          puVar4 = (undefined4 *)&DAT_020b8ea0;
          puVar5 = &DAT_0099d250;
          for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          DAT_0099d238 = thunk_FUN_00595f30(&DAT_0099d250,1);
          if (DAT_0099d238 < 0) {
            _DAT_0099d220 = 1;
          }
          *(undefined4 *)(puVar7 + -0x40) = 0;
          puVar3 = puVar7;
LAB_005411be:
          iVar2 = ((int)DAT_01fbb864 - (int)DAT_01fbb860) + 1;
          *(int *)(puVar3 + -0x38) = iVar2;
          DAT_0099d21c = DAT_01fbb860;
          do {
            if (iVar2 < 1) {
              if (DAT_007974f8 == 0) {
                FUN_00542cda();
              }
              draw_items();
              thunk_FUN_00549422();
              if (DAT_020527a0 == -3) {
                DAT_01fbb700 = 0;
                return;
              }
              DAT_01fbb700 = 0;
              DAT_020527a0 = 0xffffffff;
              return;
            }
            DAT_0099d238 = 0;
            DAT_0099d248 = 0;
            FUN_00541b97(&DAT_007974f4,&DAT_0099d21c,&DAT_0099d220,&DAT_007974f8);
            *(int *)(puVar3 + -0x34) = ITEM_I;
            LOAD_I = 1;
            iVar2 = ITEM_I;
            while (0 < iVar2) {
              load_item_header();
              if (((DAT_01e67914 < LOAD_P3) || (DAT_0099d21c != (float)LOAD_STAFF)) ||
                 (LOAD_P3 < DAT_01e67910)) {
                *(undefined4 *)(puVar3 + -0x30) = 0;
              }
              else {
                if (LOAD_CODE == 1) {
                  bVar1 = f_m2 < (float)(&ITEM_P6)[LOAD_W];
                  *(undefined4 *)(puVar3 + -0xd0) = (&ITEM_P5)[LOAD_W];
                  fVar6 = (float10)FUN_005ff874(puVar3 + -0xd0,&DAT_00768db8);
                  if (fVar6 < (float10)f_10 && bVar1) {
                    (&ITEM_P5)[LOAD_W] = (float)(&ITEM_P5)[LOAD_W] + f_10;
                  }
                }
                else {
                  *(undefined4 *)(puVar3 + -0x2c) = 0;
                }
                if ((LOAD_CODE == 2) && (DAT_0099d21c == (float)LOAD_STAFF)) {
                  (&ITEM_P4)[LOAD_W] = f_0;
                }
              }
              *(undefined4 *)(puVar3 + -0x28) = 0;
              LOAD_I = LOAD_I + 1;
              *(int *)(puVar3 + -0x34) = *(int *)(puVar3 + -0x34) + -1;
              iVar2 = *(int *)(puVar3 + -0x34);
            }
            DAT_01fbb8a0 = 0;
            DAT_01fb8c60 = (float)(int)DAT_0099d21c;
            DAT_0078b4e0 = 0x4c;
            DAT_0078b4e4 = 0x4a;
            P1 = (float)(int)DAT_0099d21c;
            _DAT_0099d214 = DAT_01fbb8b8;
            _DAT_0099d218 = f_0;
            DAT_01a1c760 = DAT_0099d21c;
            _DAT_01a1c764 = DAT_0099d21c;
            P2 = DAT_01e67910;
            P3 = DAT_01e67914;
            FUN_005f33c9(puVar3,0x54140a);
            FUN_005f34d1(puVar3,0x541425);
            thunk_FUN_0047c3e8(&DAT_00768db0);
            if (DAT_01a1c380 == 0) {
              *(undefined4 *)(puVar3 + -0x24) = 0;
            }
            else {
              DAT_0099d210 = 1;
              *(int *)(puVar3 + -0x20) = DAT_01a1c380;
              DAT_0099d248 = 1;
              iVar2 = DAT_01a1c380;
              while (0 < iVar2) {
                iVar2 = (ITEM_I - DAT_0099d210) + 1;
                *(int *)(puVar3 + -0x1c) = iVar2;
                LOAD_I = DAT_0099d210;
                while (0 < iVar2) {
                  load_item_header();
                  if ((int)DAT_0099d21c < LOAD_STAFF) {
                    *(undefined4 *)(puVar3 + -0x18) = 0;
                    goto LAB_005415b5;
                  }
                  if ((LOAD_CODE == 1) && (DAT_0099d21c == (float)LOAD_STAFF)) {
                    if (LOAD_P3 == (float)(&DAT_01a1c380)[DAT_0099d248]) {
                      if (LOAD_LEN < 0xb) {
                        thunk_FUN_005239c9(&LOAD_I,&f_11);
                      }
                      if (*(float *)(&ITEM_P11 + LOAD_W * 4) == f_0) {
                        *(float *)(&ITEM_P11 + LOAD_W * 4) =
                             (float)(int)(&DAT_01a1c510)[DAT_0099d248];
                      }
                      *(undefined4 *)(puVar3 + -0xc) = 0;
                      break;
                    }
                    *(undefined4 *)(puVar3 + -0x10) = 0;
                  }
                  else {
                    *(undefined4 *)(puVar3 + -0x14) = 0;
                  }
                  *(undefined4 *)(puVar3 + -8) = 0;
                  LOAD_I = LOAD_I + 1;
                  *(int *)(puVar3 + -0x1c) = *(int *)(puVar3 + -0x1c) + -1;
                  iVar2 = *(int *)(puVar3 + -0x1c);
                }
                DAT_0099d210 = LOAD_I + 1;
                DAT_0099d248 = DAT_0099d248 + 1;
                *(int *)(puVar3 + -0x20) = *(int *)(puVar3 + -0x20) + -1;
                iVar2 = *(int *)(puVar3 + -0x20);
              }
            }
LAB_005415b5:
            *(undefined4 *)(puVar3 + -4) = 0;
            DAT_0099d21c = (float)((int)DAT_0099d21c + 1);
            *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
            iVar2 = *(int *)(puVar3 + -0x38);
          } while( true );
        }
        local_48 = 0;
      }
      else {
        local_4c = 0;
      }
    }
    local_40 = 0;
    LOAD_I = LOAD_I + 1;
    local_58 = local_58 + -1;
  } while( true );
}


