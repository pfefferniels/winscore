// FUN_0040f003 @ 0040f003 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0040fdc2) */
/* WARNING: Removing unreachable block (ram,0x0040ffae) */
/* WARNING: Removing unreachable block (ram,0x0040fd2f) */
/* WARNING: Removing unreachable block (ram,0x00410153) */
/* WARNING: Removing unreachable block (ram,0x0040fe28) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040f003(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 in_FPUControlWord;
  undefined2 uVar7;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if ((_DAT_020b8ea0 & 0xffffff) == 0x4f4441) {
    DAT_0078df00 = (int)ROUND(P2);
    FUN_005f34d1(&stack0xfffffffc,0x40f086);
    DAT_00791444 = 0xffffffff;
    draw_items();
    *(undefined4 *)(puVar8 + -0xc0) = 0;
    return;
  }
  if ((_DAT_020b8ea0 & 0xffff) == 0x4141) {
    return;
  }
  if ((_DAT_020b8ea0 & 0xffffff) == 0x444441) {
    if (P2 == f_0) {
      thunk_FUN_0054d7d4("ADD 0",5);
      return;
    }
    if (P3 == f_0) {
      P3 = f_4;
    }
    if (P4 == f_0) {
      P4 = f_4;
    }
    if (P6 == f_0) {
      P6 = f_1;
    }
    DAT_007caaa4 = 0;
    DAT_007caaa0 = (int)ROUND(P2);
    _DAT_007caa9c = (P3 * f_4) / P4;
    _DAT_007caa98 = P5;
    DAT_007caa94 = P6;
    thunk_FUN_004f7808();
    DAT_01fbb8c4 = 1;
    iVar4 = ITEM_I;
    while( true ) {
      if (iVar4 < 1) {
        DAT_01fbb8c4 = 0;
        thunk_FUN_005725fa();
        if (_DAT_007caa98 != f_0) {
          DAT_01fbb8c4 = (int)ROUND(_DAT_007caa98);
          (&ITEM_LEN)[ITEM_WORDS] = f_4;
          (&ITEM_P1)[ITEM_WORDS] = f_14;
          (&ITEM_P2)[ITEM_WORDS] = (float)DAT_007caaa0;
          (&ITEM_P3)[ITEM_WORDS] =
               ((float)(&DAT_007caaa8)[DAT_01fbb8c4] - (float)(&DAT_007caaa4)[DAT_01fbb8c4]) / f_2 +
               (float)(&DAT_007caaa4)[DAT_01fbb8c4];
          (&ITEM_P4)[ITEM_WORDS] = DAT_007caa94;
          ITEM_WORDS = ITEM_WORDS + 5;
        }
        DAT_01fbb8c4 = DAT_01fbb8c4 + 1;
        do {
          _DAT_007caa90 = f_0;
          while (_DAT_007caa90 = _DAT_007caa90 + *(float *)(&DAT_007caca4 + DAT_01fbb8c4 * 4),
                _DAT_007caa90 < _DAT_007caa9c) {
            DAT_01fbb8c4 = DAT_01fbb8c4 + 1;
          }
          (&ITEM_LEN)[ITEM_WORDS] = f_4;
          (&ITEM_P1)[ITEM_WORDS] = f_14;
          (&ITEM_P2)[ITEM_WORDS] = (float)DAT_007caaa0;
          (&ITEM_P3)[ITEM_WORDS] =
               ((float)(&DAT_007caaa8)[DAT_01fbb8c4] - (float)(&DAT_007caaa4)[DAT_01fbb8c4]) / f_2 +
               (float)(&DAT_007caaa4)[DAT_01fbb8c4];
          if (DAT_007caaa4 == DAT_01fbb8c4) {
            (&ITEM_P3)[ITEM_WORDS] = DAT_01fbb8b8;
          }
          (&ITEM_P4)[ITEM_WORDS] = DAT_007caa94;
          DAT_01fbb8c4 = DAT_01fbb8c4 + 1;
          ITEM_WORDS = ITEM_WORDS + 5;
        } while (DAT_01fbb8c4 <= DAT_007caaa4);
        draw_items();
        return;
      }
      LOAD_I = DAT_01fbb8c4;
      load_item_header();
      if ((LOAD_CODE == 0xe) && (DAT_007caaa0 == LOAD_STAFF)) break;
      if ((((LOAD_CODE < 3) && (DAT_007caaa0 == LOAD_STAFF)) &&
          (*(float *)(&ITEM_P7 + LOAD_W * 4) <= f_60)) &&
         (LOAD_P3 != (float)(&DAT_007caaa4)[DAT_007caaa4])) {
        DAT_007caaa4 = DAT_007caaa4 + 1;
        *(undefined4 *)(&DAT_007caca4 + DAT_007caaa4 * 4) = *(undefined4 *)(&ITEM_P7 + LOAD_W * 4);
        (&DAT_007caaa4)[DAT_007caaa4] = (int)LOAD_P3;
      }
      DAT_01fbb8c4 = DAT_01fbb8c4 + 1;
      iVar4 = iVar4 + -1;
    }
    thunk_FUN_0054d831(&DAT_0075f2cc,0x1a);
    return;
  }
  if (DAT_01fbb8a0 == 0) {
LAB_0040f5d4:
    if (DAT_0078b4e4 == 0x44) {
      if (P4 == f_0) {
        P4 = DAT_01fbb8b8;
      }
      if ((P2 == f_0) || (f_256 < P2)) {
        P2 = f_1;
        P3 = f_0;
        P5 = f_199;
      }
      thunk_FUN_0040cde4(&DAT_0075f1e0);
      return;
    }
    if (DAT_0078b4e4 != 0x20) {
      return;
    }
    _DAT_01fbb8c0 = 0;
    if (DAT_02052748 == DAT_02052740) {
      _DAT_007caa8c = NPT;
      IP11 = 1;
      DAT_01fbb8a0 = 0x32;
      goto LAB_00410288;
    }
LAB_0040f627:
    puVar3 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x40f644);
    if (((_DAT_020b8ea0 & 0xff) != 0x7c) && ((_DAT_020b8ea0 & 0xff) != 0x7e)) {
      thunk_FUN_00518448();
      DAT_01fbb870 = P5;
      if (DAT_02052748 == DAT_02052740) {
        DAT_01fbb7e0 = VEC_N;
        thunk_FUN_0041aa88();
        thunk_FUN_004a30bb(&DAT_01fbb8d4,&DAT_0075f2c0);
        if (DAT_01fbb8d4 == -2) {
          *(undefined4 *)(puVar3 + -0x70) = 0;
          goto LAB_00410114;
        }
        if (DAT_01fbb8d4 == 0) {
          VEC_N = DAT_01fbb7e0;
          *(undefined4 *)(puVar3 + -0x6c) = 0;
          goto LAB_00410288;
        }
      }
      else {
        *(undefined4 *)(puVar3 + -0x74) = 0;
      }
LAB_0040f761:
      fVar1 = P1;
      *(undefined2 *)(puVar3 + -0xe8) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xe6) = (ushort)*(undefined4 *)(puVar3 + -0xe8) | 0xc00;
      *(int *)(puVar3 + -0xe4) = (int)ROUND(fVar1);
      fVar1 = P4;
      DAT_01fbb860 = *(int *)(puVar3 + -0xe4);
      *(undefined2 *)(puVar3 + -0xe8) = *(undefined2 *)(puVar3 + -0xe8);
      *(ushort *)(puVar3 + -0xe6) = (ushort)*(undefined4 *)(puVar3 + -0xe8) | 0xc00;
      *(int *)(puVar3 + -0xe4) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xe8);
      DAT_01fbb864 = *(int *)(puVar3 + -0xe4);
      if (DAT_01fbb860 < 1) {
        DAT_01fbb860 = 1;
      }
      if (DAT_01fbb864 == 0) {
        DAT_01fbb864 = DAT_01fbb860;
      }
      if (DAT_01fbb864 < DAT_01fbb860) {
        thunk_FUN_0054c68f(&DAT_01fbb860,&DAT_01fbb864);
      }
      DAT_01fbb8c4 = DAT_01fbb860;
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      if (P3 == f_0) {
        DAT_01fbb86c = f_220;
      }
      if (MAX_STAFF < DAT_01fbb860) {
        DAT_01fbb860 = 1;
        DAT_01fbb864 = MAX_STAFF;
      }
      else {
        *(undefined4 *)(puVar3 + -0x68) = 0;
      }
      if (DAT_01fbb864 < DAT_01fbb860) {
        DAT_01fbb864 = DAT_01fbb860;
      }
      if (DAT_01fbb870 != f_0) {
        *(undefined4 *)(puVar3 + -100) = 0;
LAB_0040f937:
        if (DAT_02052748 == DAT_02052740) {
          FUN_005f33c9(puVar3,0x40f992);
          FUN_005f34d1(puVar3,0x40f9ad);
          *(undefined4 *)(puVar3 + -0x48) = 0;
          DAT_01fbb8a0 = 0x34;
          return;
        }
        *(undefined4 *)(puVar3 + -0x4c) = 0;
        puVar8 = puVar3;
        goto LAB_0040f94c;
      }
      if (DAT_02052748 == DAT_02052740) {
        FUN_005f33c9(puVar3,0x410230);
        FUN_005f34d1(puVar3,0x41024b);
        DAT_01fbb8a0 = 0x33;
        *(undefined4 *)(puVar3 + -0x5c) = 0;
        return;
      }
      *(undefined4 *)(puVar3 + -0x60) = 0;
      puVar8 = puVar3;
LAB_0040f8e9:
      puVar3 = puVar8;
      thunk_FUN_00518448();
      if (P1 == f_0) {
        *(undefined4 *)(puVar3 + -0x58) = 0;
        goto LAB_00410114;
      }
      DAT_01fbb870 = P1;
      if (P2 == f_0) {
        *(undefined4 *)(puVar3 + -0x54) = 0;
        goto LAB_0040f937;
      }
      thunk_FUN_0054c590(&P2,&P1,&DAT_0075f288);
      *(undefined4 *)(puVar3 + -0x50) = 0;
      goto LAB_0040f9ef;
    }
    DAT_01fbb870 = f_0;
    DAT_01fbb7e0 = VEC_N;
    thunk_FUN_0041b011();
    thunk_FUN_004a30bb(&DAT_01fbb8d4,&DAT_0075f2c0);
    if (DAT_01fbb8d4 != -2) {
      if (DAT_01fbb8d4 == 0) {
        VEC_N = DAT_01fbb7e0;
        *(undefined4 *)(puVar3 + -0x78) = 0;
LAB_00410288:
        FUN_005f33c9(puVar3,0x4102a6);
        FUN_005f34d1(puVar3,0x4102c1);
        thunk_FUN_0041b68a();
        *(undefined4 *)(puVar3 + -0x80) = 0;
        return;
      }
      goto LAB_0040f761;
    }
    *(undefined4 *)(puVar3 + -0x7c) = 0;
  }
  else {
    if (DAT_01fbb8a0 == 0x32) goto LAB_0040f627;
    puVar8 = &stack0xfffffffc;
    if (DAT_01fbb8a0 == 0x33) goto LAB_0040f8e9;
    puVar8 = &stack0xfffffffc;
    if (DAT_01fbb8a0 != 0x34) goto LAB_0040f5d4;
LAB_0040f94c:
    puVar3 = puVar8;
    thunk_FUN_00518448();
    if (P1 == f_0) {
      *(undefined4 *)(puVar3 + -0x44) = 0;
    }
    else {
LAB_0040f9ef:
      FUN_005f33c9(puVar3,0x40fa0d);
      FUN_005f34d1(puVar3,0x40fa28);
      *(undefined4 *)(puVar3 + -0xe0) = 0;
      *(undefined4 *)(puVar3 + -0xf0) = 3;
      *(undefined4 *)(puVar3 + -0xec) = 0x20b90a7;
      *(int **)(puVar3 + -0xe8) = &DAT_01fbb860;
      FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f1c0,puVar3 + -0xf0,&DAT_0078b02c);
      *(undefined4 *)(puVar3 + -0xe0) = 0;
      *(undefined4 *)(puVar3 + -0xf0) = 3;
      *(undefined4 **)(puVar3 + -0xec) = &DAT_020b90b3;
      *(int **)(puVar3 + -0xe8) = &DAT_01fbb864;
      FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f1c0,puVar3 + -0xf0,&DAT_0078b040);
      *(undefined4 *)(puVar3 + -0xe0) = 0;
      *(undefined4 *)(puVar3 + -0xf0) = 8;
      *(undefined4 *)(puVar3 + -0xec) = 0x20b90bf;
      *(float **)(puVar3 + -0xe8) = &DAT_01fbb868;
      FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f280,puVar3 + -0xf0,&DAT_0078b054);
      *(undefined4 *)(puVar3 + -0xe0) = 0;
      *(undefined4 *)(puVar3 + -0xf0) = 8;
      *(undefined **)(puVar3 + -0xec) = &DAT_020b90d0;
      *(float **)(puVar3 + -0xe8) = &DAT_01fbb86c;
      FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f280,puVar3 + -0xf0,&DAT_0078b068);
      *(undefined2 *)(puVar3 + -0xe8) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xe6) = (ushort)*(undefined4 *)(puVar3 + -0xe8) | 0xc00;
      *(int *)(puVar3 + -0xe4) = (int)ROUND(DAT_01fbb870);
      uVar7 = *(undefined2 *)(puVar3 + -0xe8);
      *(undefined4 *)(puVar3 + -0xe0) = 0;
      *(undefined4 *)(puVar3 + -0xf8) = 2;
      *(undefined4 *)(puVar3 + -0xf4) = 0x20b90e0;
      *(undefined4 *)(puVar3 + -0xf0) = *(undefined4 *)(puVar3 + -0xe4);
      FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f278,puVar3 + -0xf8,&DAT_0078b07c);
      DAT_01fbb8c4 = 1;
      DAT_007caa88 = 0x4a;
      while( true ) {
        fVar1 = *(float *)(&P0 + DAT_01fbb8c4 * 4);
        *(undefined2 *)(puVar3 + -0xe8) = uVar7;
        *(ushort *)(puVar3 + -0xe6) = (ushort)*(undefined4 *)(puVar3 + -0xe8) | 0xc00;
        *(int *)(puVar3 + -0xe4) = (int)ROUND(fVar1);
        uVar7 = *(undefined2 *)(puVar3 + -0xe8);
        IP1 = *(int *)(puVar3 + -0xe4);
        IP2 = 0;
        if (IP1 < 1000) {
          *(undefined4 *)(puVar3 + -0x2c) = 0;
          if (IP1 < 100) {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
            iVar4 = IP1;
          }
          else {
            iVar4 = IP1 / 100;
            IP2 = IP1;
          }
          IP1 = iVar4;
          *(undefined4 *)(puVar3 + -0xe0) = 0;
          *(undefined4 *)(puVar3 + -0xf0) = 2;
          *(char **)(puVar3 + -0xec) = s_p__p__if_p2>__and_p2<__and_p3>__a_0078b160 + 5;
          *(int **)(puVar3 + -0xe8) = &IP1;
          FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f1c0,puVar3 + -0xf0,&DAT_0078b0b8);
          FUN_005f46bc(puVar3,0x40fd53);
          FUN_005f34d1(puVar3,0x40fd69);
          DAT_007caa88 = DAT_007caa88 + 4;
          if (IP2 == 0) {
            *(undefined4 *)(puVar3 + -0x14) = 0;
          }
          else {
            s_p__p__if_p2>__and_p2<__and_p3>__a_0078b160[1] =
                 s_p__p__if_p2>__and_p2<__and_p3>__a_0078b160[5];
            s_p__p__if_p2>__and_p2<__and_p3>__a_0078b160[2] =
                 s_p__p__if_p2>__and_p2<__and_p3>__a_0078b160[6];
            FUN_005f46bc(puVar3,0x40fde6);
            FUN_005f34d1(puVar3,0x40fdfc);
            DAT_007caa88 = DAT_007caa88 + 4;
          }
          *(undefined4 *)(puVar3 + -0xe0) = 0;
          *(undefined4 *)(puVar3 + -0xf0) = 0xd;
          *(undefined1 **)(puVar3 + -0xec) = &DAT_020b909f + DAT_007caa88;
          *(undefined4 *)(puVar3 + -0xe8) = 4;
          *(float **)(puVar3 + -0xe4) = &P1 + DAT_01fbb8c4;
          FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f270,puVar3 + -0xf0,&DAT_0078b0cc);
        }
        else {
          IP2 = IP1 / 1000;
          *(undefined4 *)(puVar3 + -0xe0) = 0;
          *(undefined4 *)(puVar3 + -0xf0) = 2;
          *(undefined **)(puVar3 + -0xec) = &DAT_0078b159;
          *(int **)(puVar3 + -0xe8) = &IP2;
          FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f1c0,puVar3 + -0xf0,&DAT_0078b090);
          fVar1 = (&P1)[DAT_01fbb8c4];
          *(undefined2 *)(puVar3 + -0xe8) = uVar7;
          *(ushort *)(puVar3 + -0xe6) = (ushort)*(undefined4 *)(puVar3 + -0xe8) | 0xc00;
          *(int *)(puVar3 + -0xe4) = (int)ROUND(fVar1);
          uVar7 = *(undefined2 *)(puVar3 + -0xe8);
          *(undefined4 *)(puVar3 + -0xe0) = 0;
          *(undefined4 *)(puVar3 + -0xf8) = 2;
          *(undefined **)(puVar3 + -0xf4) = &DAT_0078b15d;
          *(undefined4 *)(puVar3 + -0xf0) = *(undefined4 *)(puVar3 + -0xe4);
          FUN_005f34f0(puVar3 + -0xe0,0x784ff00,&DAT_0075f278,puVar3 + -0xf8,&DAT_0078b0a4);
          FUN_005f46bc(puVar3,0x40ffd2);
          FUN_005f34d1(puVar3,0x40ffe8);
          DAT_007caa88 = DAT_007caa88 + 7;
          *(undefined4 *)(puVar3 + -0x20) = 0;
        }
        DAT_01fbb8c4 = DAT_01fbb8c4 + 2;
        if (*(float *)(&P0 + DAT_01fbb8c4 * 4) == f_0) break;
        DAT_007caa88 = DAT_007caa88 + 0xc;
        FUN_005f46bc(puVar3,0x410078);
        FUN_005f34d1(puVar3,0x41008e);
        DAT_007caa88 = DAT_007caa88 + 1;
        *(undefined4 *)(puVar3 + -8) = 0;
      }
      *(undefined4 *)(puVar3 + -0xc) = 0;
      puVar5 = (undefined4 *)&DAT_020b90a0;
      puVar6 = &DAT_009ae2bc;
      for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      thunk_FUN_005725fa();
      puVar5 = &DAT_009ae2bc;
      puVar6 = (undefined4 *)&DAT_020b90a0;
      for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      DAT_020527a0 = 0xfffffffe;
      thunk_FUN_004b041d();
      DAT_0078b4f0 = 1;
      if (DAT_02052748 != DAT_02052740) {
        *(undefined4 *)(puVar3 + -4) = 0;
        goto LAB_004101a9;
      }
    }
  }
LAB_00410114:
  *DAT_01fbb7c0 = DAT_01fbb7e0 + -1;
  *(int *)(puVar3 + -0xe4) = VEC_BASE;
  *(int *)(puVar3 + -0xe8) = VEC_STRIDE;
  *(undefined4 *)(puVar3 + -0xec) = 0x10;
  *(int *)(puVar3 + -0xf0) = VEC_STRIDE * VEC_LBOUND;
  iVar4 = DAT_01fbb7e0;
  for (iVar2 = 1; iVar2 <= *(int *)(puVar3 + -0xec); iVar2 = iVar2 + 1) {
    *(undefined4 *)
     ((*(int *)(puVar3 + -0xe4) - *(int *)(puVar3 + -0xf0)) + *(int *)(puVar3 + -0xe8) * iVar4) = 0;
    iVar4 = iVar4 + 1;
  }
LAB_004101a9:
  draw_items();
  DAT_01fbb8a4 = 0;
  thunk_FUN_00468df8(&DAT_0075f268);
  DAT_01fbb8a0 = 0;
  FUN_005f33c9(puVar3,0x4101ee);
  FUN_005f34d1(puVar3,0x410209);
  return;
}


