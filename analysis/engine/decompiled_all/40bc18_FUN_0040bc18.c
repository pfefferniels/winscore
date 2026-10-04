// FUN_0040bc18 @ 0040bc18 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040bc18(void)

{
  float fVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  undefined2 uVar3;
  unkbyte10 Var4;
  float10 fVar5;
  float10 fVar6;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined1 *puVar7;
  
  puVar7 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x40bc3f);
  Var4 = FUN_005f34d1(puVar7,0x40bc5a);
  ffree(Var4);
  Var4 = thunk_FUN_0054c590(&DAT_020b9440,&DAT_020b964c,&DAT_0075f050);
  if ((DAT_020b964c == f_1) && (P2 != f_0)) {
    _DAT_020b9650 = P2;
  }
  DAT_020b8ea0._0_1_ = DAT_0075f044;
  if (DAT_020b8ea2 == 'X') {
    DAT_020b8ea3 = 'X';
  }
  ffree(Var4);
  fVar5 = (float10)amod(&DAT_020b965c,&f_100);
  fVar6 = (float10)f_10;
  *(undefined2 *)(puVar7 + -0x4c) = in_FPUControlWord;
  *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
  *(int *)(puVar7 + -0x48) = (int)ROUND(fVar5 / fVar6);
  iVar2 = ITEM_I;
  uVar3 = *(undefined2 *)(puVar7 + -0x4c);
  DAT_020b8e60 = *(int *)(puVar7 + -0x48);
  fVar6 = extraout_ST1;
  if ((DAT_020b8e60 == 0) || (_DAT_020b9660 == f_1)) {
    *(undefined4 *)(puVar7 + -0x24) = 0;
  }
  else {
    _DAT_020b8e74 = f_m999;
    *(int *)(puVar7 + -0x20) = ITEM_I;
    DAT_007aba88 = 1;
    fVar1 = _DAT_020b9650;
    while (_DAT_020b9650 = fVar1, 0 < iVar2) {
      IP7 = (&ITEM_PTR0)[DAT_007aba88];
      if (((float)(&ITEM_P1)[IP7] == f_6) && (fVar1 == (float)(&ITEM_P2)[IP7])) {
        if ((_DAT_020b9654 < (float)(&ITEM_P3)[IP7] - f_0_1) ||
           ((float)(&ITEM_P6)[IP7] + f_0_1 < _DAT_020b9654)) {
          *(undefined4 *)(puVar7 + -0x18) = 0;
        }
        else {
          fVar1 = _DAT_020b9658 / f_100;
          *(undefined2 *)(puVar7 + -0x4c) = uVar3;
          *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
          *(int *)(puVar7 + -0x48) = (int)ROUND(fVar1);
          IP4 = *(int *)(puVar7 + -0x48);
          if (IP4 < 0) {
            IP4 = -IP4;
          }
          fVar1 = (float)(&ITEM_P1)[IP7] / f_100;
          *(undefined2 *)(puVar7 + -0x4c) = *(undefined2 *)(puVar7 + -0x4c);
          *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
          *(int *)(puVar7 + -0x48) = (int)ROUND(fVar1);
          uVar3 = *(undefined2 *)(puVar7 + -0x4c);
          DAT_007aba84 = *(int *)(puVar7 + -0x48);
          iVar2 = DAT_007aba84;
          if (DAT_007aba84 < 0) {
            iVar2 = -DAT_007aba84;
          }
          if (iVar2 == IP4) {
            ffree(fVar6);
            Var4 = thunk_FUN_0054c419(&DAT_020b95e0,&DAT_0075f050);
            fVar1 = (float)(&ITEM_LEN)[IP7];
            *(undefined2 *)(puVar7 + -0x4c) = uVar3;
            *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
            *(int *)(puVar7 + -0x48) = (int)ROUND(fVar1);
            uVar3 = *(undefined2 *)(puVar7 + -0x4c);
            IP6 = *(int *)(puVar7 + -0x48);
            ffree(Var4);
            fVar6 = (float10)thunk_FUN_0054c590(&ITEM_P1 + IP7,&DAT_020b95e0,&IP6);
            fVar1 = _DAT_020b95f8;
            *(undefined2 *)(puVar7 + -0x4c) = uVar3;
            *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
            *(int *)(puVar7 + -0x48) = (int)ROUND(fVar1);
            uVar3 = *(undefined2 *)(puVar7 + -0x4c);
            IP7 = *(int *)(puVar7 + -0x48);
            if (IP7 < 1) {
              *(undefined4 *)(puVar7 + -0x10) = 0;
            }
            else {
              IP8 = IP7 / 10;
              if (((DAT_020b9444 == _DAT_020b9650) && (IP8 != DAT_020b8e60)) &&
                 (DAT_020b8ea3 != 'X')) {
                *(undefined4 *)(puVar7 + -0xc) = 0;
              }
              else {
                ffree(fVar6);
                Var4 = push_words(&DAT_0075f050,&DAT_020b964c);
                DAT_020b9634 = f_m999;
                ffree(Var4);
                Var4 = FUN_0040c1c0(&DAT_020b8e60);
                if (_DAT_020b8e74 < DAT_020b9634) {
                  _DAT_020b8e74 = DAT_020b9634;
                }
                ffree(Var4);
                fVar6 = (float10)pop_words(&DAT_0075f050,&DAT_020b964c);
              }
            }
          }
          else {
            *(undefined4 *)(puVar7 + -0x14) = 0;
          }
        }
      }
      else {
        *(undefined4 *)(puVar7 + -0x1c) = 0;
      }
      *(undefined4 *)(puVar7 + -8) = 0;
      DAT_007aba88 = DAT_007aba88 + 1;
      *(int *)(puVar7 + -0x20) = *(int *)(puVar7 + -0x20) + -1;
      fVar1 = _DAT_020b9650;
      iVar2 = *(int *)(puVar7 + -0x20);
    }
    if (_DAT_020b8e74 == f_m999) {
      P1 = f_0;
      *(undefined4 *)(puVar7 + -4) = 0;
    }
    else {
      P1 = f_8;
      if (fVar1 != DAT_020b9444) {
        *(undefined2 *)(puVar7 + -0x4c) = uVar3;
        *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
        *(int *)(puVar7 + -0x48) = (int)ROUND(fVar1);
        fVar1 = DAT_020b9444;
        iVar2 = (&STAFF_Y0)[*(int *)(puVar7 + -0x48)];
        *(undefined2 *)(puVar7 + -0x4c) = *(undefined2 *)(puVar7 + -0x4c);
        *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
        *(int *)(puVar7 + -0x48) = (int)ROUND(fVar1);
        uVar3 = *(undefined2 *)(puVar7 + -0x4c);
        *(int *)(puVar7 + -0x48) = iVar2 - (&STAFF_Y0)[*(int *)(puVar7 + -0x48)];
        fVar6 = (float10)*(int *)(puVar7 + -0x48);
        DAT_020b8e68 = (float)(fVar6 / ((float10)STEP * (float10)f_7));
        if (f_20 <= DAT_020b9450) {
          fVar6 = (float10)DAT_020b8e68;
          DAT_020b8e68 = (float)-fVar6;
        }
      }
      P2 = DAT_020b8e68 + _DAT_020b8e74;
      if (DAT_020b9478 != f_0) {
        P2 = P2 / DAT_020b9478;
      }
      ffree(fVar6);
      fVar6 = (float10)amod(&DAT_020b966c,&f_10);
      *(undefined2 *)(puVar7 + -0x4c) = uVar3;
      *(ushort *)(puVar7 + -0x4a) = (ushort)*(undefined4 *)(puVar7 + -0x4c) | 0xc00;
      *(int *)(puVar7 + -0x48) = (int)ROUND(fVar6);
      IP5 = *(int *)(puVar7 + -0x48);
      P3 = f_900;
      *(int *)(puVar7 + -0x48) = -IP5;
      P4 = (float)*(int *)(puVar7 + -0x48);
      fVar6 = extraout_ST1_00;
    }
  }
  ffree(fVar6);
  return;
}


