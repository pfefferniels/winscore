// FUN_004a217d @ 004a217d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004a2aee) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a217d(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined2 in_FPUControlWord;
  int local_40;
  
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  iVar2 = FUN_005f4660(0x20);
  if (iVar2 == 0) {
    if (DAT_01fbb8a0 == 0x11) {
LAB_004a257b:
      DAT_01fbb8a4 = 0x42;
      for (iVar2 = 1; iVar2 < 0x21; iVar2 = iVar2 + 1) {
        (&DAT_00838ab8)[iVar2] = 0;
      }
      if (P5 == f_0) {
        FUN_005f33c9(puVar4,0x4a2612);
        FUN_005f34d1(puVar4,0x4a262d);
        DAT_00838ab4 = thunk_FUN_0059b4e0(&DAT_00838abc);
        if (DAT_00838ab4 == 2) {
          *(undefined4 *)(puVar4 + -0x48) = 0;
          goto LAB_004a2aaf;
        }
        *(undefined4 *)(puVar4 + -0x44) = 0x12;
        DAT_00838ab0 = 1;
        do {
          *(float *)(DAT_00838ab0 * 4 + 0x1c5855c) = (float)(&DAT_00838ab8)[DAT_00838ab0];
          DAT_00838ab0 = DAT_00838ab0 + 1;
          *(int *)(puVar4 + -0x44) = *(int *)(puVar4 + -0x44) + -1;
        } while (0 < *(int *)(puVar4 + -0x44));
        *(undefined4 *)(puVar4 + -0x40) = 0;
        puVar3 = puVar4;
      }
      else {
        iVar2 = 5;
        for (iVar7 = 1; iVar7 < 0x13; iVar7 = iVar7 + 1) {
          *(undefined4 *)(iVar7 * 4 + 0x1c5855c) = *(undefined4 *)(&P0 + iVar2 * 4);
          iVar2 = iVar2 + 1;
        }
        *(undefined4 *)(puVar4 + -0x4c) = 0;
        puVar3 = puVar4;
      }
      goto LAB_004a27f6;
    }
    if (DAT_01fbb8a0 == 0) {
      if (DAT_02052740 == 0) {
        DAT_01fbb8a4 = 0;
        DAT_01fbb8a0 = 6;
        goto LAB_004a2c31;
      }
      thunk_FUN_00518448();
      if (P1 == f_0) {
        return;
      }
      DAT_01fbb860 = (int)ROUND(P1);
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      DAT_01fbb864 = (int)ROUND(P4);
      iVar2 = 5;
      for (iVar7 = 1; iVar7 < 0x13; iVar7 = iVar7 + 1) {
        *(undefined4 *)(iVar7 * 4 + 0x1c5855c) = *(undefined4 *)(&P0 + iVar2 * 4);
        iVar2 = iVar2 + 1;
      }
      goto LAB_004a27f6;
    }
    if (DAT_01fbb8a4 != 0) {
      thunk_FUN_00518448();
      local_40 = 0x12;
      DAT_00838ab0 = 1;
      do {
        *(undefined4 *)(DAT_00838ab0 * 4 + 0x1c5855c) = *(undefined4 *)(&P0 + DAT_00838ab0 * 4);
        DAT_00838ab0 = DAT_00838ab0 + 1;
        local_40 = local_40 + -1;
      } while (0 < local_40);
      puVar3 = &stack0xfffffffc;
      if (DAT_02052760 != 0) {
        DAT_02052760 = (int)ROUND(DAT_01c58560);
        puVar3 = &stack0xfffffffc;
      }
      goto LAB_004a27f6;
    }
    puVar4 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x4a22f0);
    _DAT_007a0b7c = CONCAT12(DAT_020b90a2,_DAT_020b90a0);
    puVar5 = puVar4;
    if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
      DAT_01fbb7e0 = VEC_N;
      thunk_FUN_0041b011();
      FUN_004a30bb(&DAT_00838ab8,&DAT_0076382c);
      if (DAT_00838ab8 == -2) {
        *(undefined4 *)(puVar4 + -0x70) = 0;
        goto LAB_004a2aaf;
      }
      if (DAT_00838ab8 == 0) {
        VEC_N = DAT_01fbb7e0;
        *(undefined4 *)(puVar4 + -0x6c) = 0;
LAB_004a2c31:
        FUN_005f33c9(puVar5,0x4a2c4f);
        FUN_005f34d1(puVar5,0x4a2c6a);
        thunk_FUN_0041b68a();
        *(undefined4 *)(puVar5 + -0x78) = 0;
        return;
      }
LAB_004a244c:
      fVar1 = P1;
      *(undefined2 *)(puVar4 + -0xb4) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0xb2) = (ushort)*(undefined4 *)(puVar4 + -0xb4) | 0xc00;
      *(int *)(puVar4 + -0xb0) = (int)ROUND(fVar1);
      fVar1 = P4;
      DAT_01fbb860 = *(int *)(puVar4 + -0xb0);
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      *(undefined2 *)(puVar4 + -0xb4) = *(undefined2 *)(puVar4 + -0xb4);
      *(ushort *)(puVar4 + -0xb2) = (ushort)*(undefined4 *)(puVar4 + -0xb4) | 0xc00;
      *(int *)(puVar4 + -0xb0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb4);
      DAT_01fbb864 = *(int *)(puVar4 + -0xb0);
      if ((((_DAT_007a0b7c & 0xffff) != 0x584d) && (_DAT_020b90a0 != 0x584d)) &&
         ((short)DAT_009ae2bc != 0x584d)) {
        if ((_DAT_007a0b7c & 0xffffff) == 0x455543) {
          thunk_FUN_0044695d();
          *(undefined4 *)(puVar4 + -0x58) = 0;
          return;
        }
        *(undefined4 *)(puVar4 + -0x5c) = 0;
        iVar2 = FUN_005f4660(0x20);
        if (iVar2 != 0) {
          thunk_FUN_0054061d();
          DAT_01fbb8a0 = 0;
          *(undefined4 *)(puVar4 + -0x50) = 0;
          return;
        }
        *(undefined4 *)(puVar4 + -0x54) = 0;
        goto LAB_004a257b;
      }
      DAT_01fbb8a0 = 5;
      *(undefined4 *)(puVar4 + -0x60) = 0;
      goto LAB_004a2865;
    }
    if (_DAT_020b90a0 == 0x584d) {
      puVar6 = (undefined4 *)&DAT_020b90a0;
      puVar8 = &DAT_009ae2bc;
      for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      _DAT_007a0b7c = CONCAT22(_DAT_007a0b7e,DAT_0076387c);
    }
    thunk_FUN_00518448();
    DAT_01fbb7e0 = VEC_N;
    thunk_FUN_0041aa88();
    push_words(&DAT_00763878,&P1);
    FUN_004a30bb(&DAT_00838ab8,&DAT_0076382c);
    pop_words(&DAT_00763878,&P1);
    if (DAT_00838ab8 != -2) {
      if (DAT_00838ab8 == 0) {
        VEC_N = DAT_01fbb7e0;
        *(undefined4 *)(puVar4 + -100) = 0;
        goto LAB_004a2c31;
      }
      goto LAB_004a244c;
    }
    *(undefined4 *)(puVar4 + -0x68) = 0;
  }
  else {
    DAT_01fbb860 = 0xc9;
    DAT_01fbb868 = f_m10;
    DAT_01fbb86c = f_210;
    DAT_01fbb864 = 0x100;
    puVar3 = &stack0xfffffffc;
LAB_004a27f6:
    DAT_01fbb8a4 = 0;
    DAT_01fbb8a0 = 0;
    FUN_005f33c9(puVar3,0x4a2824);
    puVar4 = puVar3;
    FUN_005f34d1(puVar3,0x4a283f);
    DAT_020492a4 = 0;
    if (DAT_01fbb868 == f_m99) {
      DAT_020492a4 = -99;
      *(undefined4 *)(puVar4 + -0x34) = 0;
    }
    else {
      *(undefined4 *)(puVar4 + -0x38) = 0;
LAB_004a2865:
      DAT_01fbb874 = 0x44;
      DAT_01fbb878 = 1;
      DAT_01fbb87c = ITEM_I;
      thunk_FUN_0049b1d8();
      if (DAT_020492a0 == 0) {
        thunk_FUN_0054d831("Nothing to do.",0xf);
        *(undefined4 *)(puVar4 + -0x2c) = 0;
        goto LAB_004a2aaf;
      }
      *(undefined4 *)(puVar4 + -0x30) = 0;
    }
    DAT_0078b4ec = 0;
    DAT_0078b4f0 = 1;
    if (DAT_020492a4 == 0) {
      *(undefined4 *)(puVar4 + -0x28) = 0;
    }
    else {
      if (DAT_020492a4 == -99) {
        DAT_020492a4 = 1;
        while( true ) {
          fVar1 = (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_020492a4]];
          *(undefined2 *)(puVar4 + -0xb4) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0xb2) = (ushort)*(undefined4 *)(puVar4 + -0xb4) | 0xc00;
          *(int *)(puVar4 + -0xb0) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb4);
          if (*(int *)(puVar4 + -0xb0) == DAT_01fbb860) {
            *(undefined4 *)(puVar4 + -0x20) = 0;
            DAT_020492a4 = DAT_020492a4 + 1;
          }
          else {
            thunk_FUN_005725fa();
            thunk_FUN_0045deb2(&DAT_020492a4);
            *(undefined4 *)(puVar4 + -0x1c) = 0;
          }
          if (ITEM_I < DAT_020492a4) break;
          *(undefined4 *)(puVar4 + -0x18) = 0;
        }
        *(undefined4 *)(puVar4 + -0x14) = 0;
        goto LAB_004a2c0a;
      }
      *(undefined4 *)(puVar4 + -0x24) = 0;
      thunk_FUN_005725fa();
      DAT_020527a0 = 0xffffffff;
      if (DAT_01fbb8a0 == 5) {
        *(undefined4 *)(puVar4 + -0x10) = 0;
        DAT_020527a0 = 0xffffffff;
        return;
      }
      thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&ITEM_WORDS);
      *(int *)(puVar4 + -0xc) = DAT_020492a4;
      DAT_00838ab0 = 1;
      iVar2 = DAT_020492a4;
      while (0 < iVar2) {
        DAT_00838aac = (&ITEM_PTR0)[(&DAT_020492a4)[DAT_00838ab0]];
        (&DAT_01e99980)[DAT_00838aac] = f_m1;
        DAT_00838ab0 = DAT_00838ab0 + 1;
        *(int *)(puVar4 + -0xc) = *(int *)(puVar4 + -0xc) + -1;
        iVar2 = *(int *)(puVar4 + -0xc);
      }
      DAT_00838aa8 = 1;
      DAT_00838ab0 = 1;
      while( true ) {
        fVar1 = (float)(&DAT_01e9997c)[DAT_00838ab0];
        *(undefined2 *)(puVar4 + -0xb4) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0xb2) = (ushort)*(undefined4 *)(puVar4 + -0xb4) | 0xc00;
        *(int *)(puVar4 + -0xb0) = (int)ROUND(fVar1 + f_1);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb4);
        DAT_00838aa4 = *(int *)(puVar4 + -0xb0);
        if ((float)(&DAT_01e99980)[DAT_00838ab0] == f_m1) {
          *(undefined4 *)(puVar4 + -8) = 0;
        }
        else {
          thunk_FUN_0054c590(&DAT_01e9997c + DAT_00838ab0,&ITEM_LEN + DAT_00838aa8,&DAT_00838aa4);
          DAT_00838aa8 = DAT_00838aa4 + DAT_00838aa8;
        }
        DAT_00838ab0 = DAT_00838aa4 + DAT_00838ab0;
        if (ITEM_WORDS <= DAT_00838ab0) break;
        *(undefined4 *)(puVar4 + -4) = 0;
      }
      ITEM_WORDS = DAT_00838aa8;
    }
  }
LAB_004a2aaf:
  *DAT_01fbb7c0 = DAT_01fbb7e0 + -1;
  *(int *)(puVar4 + -0xb0) = VEC_BASE;
  *(int *)(puVar4 + -0xb4) = VEC_STRIDE;
  *(undefined4 *)(puVar4 + -0xb8) = 0x10;
  *(int *)(puVar4 + -0xbc) = VEC_STRIDE * VEC_LBOUND;
  iVar2 = DAT_01fbb7e0;
  for (iVar7 = 1; iVar7 <= *(int *)(puVar4 + -0xb8); iVar7 = iVar7 + 1) {
    *(undefined4 *)
     ((*(int *)(puVar4 + -0xb0) - *(int *)(puVar4 + -0xbc)) + *(int *)(puVar4 + -0xb4) * iVar2) = 0;
    iVar2 = iVar2 + 1;
  }
  draw_items();
  thunk_FUN_00549422();
  DAT_01fbb8a0 = 0;
LAB_004a2c0a:
  thunk_FUN_00468df8(&DAT_00763658);
  return;
}


