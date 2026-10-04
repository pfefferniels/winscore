// FUN_00510430 @ 00510430 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00510430(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined2 in_FPUControlWord;
  
  puVar2 = &stack0xfffffffc;
  if (DAT_01fbb8a0 == 600) {
    puVar2 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x51046d);
    if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
      DAT_01fbb7e0 = VEC_N;
      thunk_FUN_0041b011();
      thunk_FUN_004a30bb(&DAT_00941928,&DAT_00767504);
      if (DAT_00941928 != -2) {
        if (DAT_00941928 != 0) goto LAB_0051055c;
        VEC_N = DAT_01fbb7e0;
        *(undefined4 *)(puVar2 + -0x34) = 0;
        goto LAB_005109c3;
      }
      *(undefined4 *)(puVar2 + -0x38) = 0;
    }
    else {
      P10 = P2;
      thunk_FUN_00518448();
      DAT_01fbb7e0 = VEC_N;
      thunk_FUN_0041aa88();
      thunk_FUN_004a30bb(&DAT_00941928,&DAT_00767504);
      if (DAT_00941928 == -2) {
        *(undefined4 *)(puVar2 + -0x30) = 0;
      }
      else {
        if (DAT_00941928 == 0) {
          VEC_N = DAT_01fbb7e0;
          *(undefined4 *)(puVar2 + -0x2c) = 0;
          goto LAB_005109c3;
        }
LAB_0051055c:
        *(undefined2 *)(puVar2 + -0x6c) = in_FPUControlWord;
        *(ushort *)(puVar2 + -0x6a) = (ushort)*(undefined4 *)(puVar2 + -0x6c) | 0xc00;
        *(int *)(puVar2 + -0x68) = (int)ROUND(P1);
        DAT_00941924 = *(int *)(puVar2 + -0x68);
        DAT_00941920 = P2;
        _DAT_0094191c = P3;
        _DAT_00941918 = ITEM_I;
        _DAT_00941914 = f_0;
        if (MAX_STAFF < DAT_00941924) {
          DAT_00941924 = DAT_01fbb860;
        }
        if ((P2 == f_0) && (P3 == f_0)) {
          DAT_00941920 = DAT_01fbb868;
          _DAT_0094191c = DAT_01fbb86c;
        }
        else {
          *(undefined4 *)(puVar2 + -0x28) = 0;
        }
        *(undefined4 *)(puVar2 + -0x24) = 0;
        if ((_DAT_0094191c == f_0) && (DAT_00941920 != f_0)) {
          _DAT_00941914 = DAT_00941920;
          *(undefined4 *)(puVar2 + -0x1c) = 0;
LAB_00510775:
          DAT_00941910 = 2;
          if (DAT_00941924 == DAT_01fbb860) {
            DAT_00941910 = 0;
          }
          *(undefined4 *)(puVar2 + -0xc) = 0;
        }
        else {
          *(undefined4 *)(puVar2 + -0x20) = 0;
          if (_DAT_0094191c == f_0) {
            _DAT_0094191c = DAT_01fbb86c;
          }
          if ((DAT_00941920 == DAT_01fbb868) && (_DAT_0094191c == DAT_01fbb86c)) {
            DAT_00941910 = 1;
            *(undefined4 *)(puVar2 + -0x14) = 0;
          }
          else {
            *(undefined4 *)(puVar2 + -0x18) = 0;
            _DAT_0094190c = DAT_01fbb86c - DAT_01fbb868;
            DAT_00941908 = _DAT_0094191c - DAT_00941920;
            if (_DAT_0094190c == f_0) {
              _DAT_0094190c = DAT_00941908;
            }
            if (ABS(_DAT_0094190c - DAT_00941908) <= f_0_001) {
              _DAT_00941914 = DAT_00941920 - DAT_01fbb868;
              goto LAB_00510775;
            }
            *(undefined4 *)(puVar2 + -0x10) = 0;
            _DAT_00941914 = DAT_00941908 / _DAT_0094190c;
            DAT_00941910 = 0xffffffff;
            if (DAT_00941924 != DAT_01fbb860) {
              DAT_00941910 = 3;
            }
          }
        }
        DAT_01fbb874 = DAT_00941910;
        DAT_01fbb87c = ITEM_I;
        *(int *)(puVar2 + -0x68) = DAT_00941924 - DAT_01fbb860;
        P1 = (float)*(int *)(puVar2 + -0x68);
        thunk_FUN_004e7eea();
        if (_DAT_00941914 != f_0) {
          thunk_FUN_0049bb13(&DAT_00941910,&DAT_01fbb868,&DAT_00941920,&DAT_00941914);
        }
        DAT_01fbb8a0 = 0;
        if (DAT_020492a0 < 1) {
          *(undefined4 *)(puVar2 + -8) = 0;
          return;
        }
        DAT_0078b4f0 = 1;
        thunk_FUN_00495d4f(&DAT_0078b510,0x80);
        draw_items();
        thunk_FUN_00549422();
        DAT_020527e8 = ITEM_I;
        DAT_0078b4ec = 0;
        DAT_0078b4f0 = 1;
        DAT_0078b4e0 = 0;
        thunk_FUN_00597b60(0xffffffff);
        DAT_01fbb8a4 = 0;
      }
    }
    iVar1 = DAT_020527a0;
    DAT_01fbb8a0 = 0;
    if (DAT_00941928 == -2) {
      ITEM_WORDS = DAT_020527a0;
      DAT_020527a0 = 0;
      if (iVar1 < 1) {
        ITEM_WORDS = 1;
      }
      ITEM_I = IP18;
      draw_items();
    }
    if (DAT_00941904 == 0) {
      thunk_FUN_00597b60(0xffffffff);
      DAT_00941904 = -1;
    }
    else {
      *(undefined4 *)(puVar2 + -4) = 0;
    }
  }
  else {
    if (DAT_02052740 != 0) {
      thunk_FUN_00518448();
      if (P1 == f_0) {
        return;
      }
      DAT_01fbb860 = (int)ROUND(P1);
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      DAT_01fbb864 = (int)ROUND(P4);
      DAT_01c58560 = P5;
    }
    DAT_01fbb8a4 = 0;
    DAT_01fbb8a0 = 600;
LAB_005109c3:
    FUN_005f33c9(puVar2,0x5109e1);
    FUN_005f34d1(puVar2,0x5109fc);
    thunk_FUN_0041b68a();
    *(undefined4 *)(puVar2 + -0x3c) = 0;
  }
  return;
}


