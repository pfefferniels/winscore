// FUN_00529628 @ 00529628 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0052aa93) */
/* WARNING: Removing unreachable block (ram,0x00529768) */
/* WARNING: Removing unreachable block (ram,0x005297dc) */
/* WARNING: Removing unreachable block (ram,0x0052afa0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00529628(void)

{
  undefined2 uVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  bool bVar11;
  undefined2 in_FPUControlWord;
  undefined4 *in_stack_00000014;
  int local_11c;
  
  puVar5 = &stack0xfffffffc;
  DAT_0094eca8 = 0;
  DAT_0078b4e0 = 0;
  DAT_0078b4ec = 0;
  DAT_020b8e44 = ITEM_WORDS;
  DAT_0094eca4 = 0;
  if ((DAT_020b8ea2 != 'A') &&
     ((DAT_020b8ea0._1_1_ == 'M' || DAT_020b8ea0._1_1_ == 'X') || DAT_020b8ea0._1_1_ == 'B')) {
    DAT_0094eca4 = 1;
  }
  puVar7 = &DAT_0078b510;
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *in_stack_00000014;
    in_stack_00000014 = in_stack_00000014 + 1;
    puVar7 = puVar7 + 1;
  }
  if ((DAT_009ae2bc & 0xffffff) == 0x577e7e) {
    puVar7 = (undefined4 *)&DAT_007a0b7c;
    puVar9 = &DAT_0078b510;
    for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  DAT_0094eca0 = 0x80;
  thunk_FUN_0054c6b5(&DAT_0078b510,0x80,&DAT_0094eca0,&DAT_0094ec9c,&DAT_0094ec98);
  local_11c = 0x80;
  DAT_0094eca0 = 0x80;
  do {
    iVar4 = FUN_00601a30(0x20);
    if (iVar4 == 0) break;
    DAT_0094eca0 = DAT_0094eca0 + -1;
    local_11c = local_11c + -1;
  } while (0 < local_11c);
  FUN_005f46bc(&stack0xfffffffc,0x5297fe);
  FUN_005f34d1(puVar5,0x529814);
  if ((DAT_009ae2bc & 0xffffff) != 0x527e7e) {
    *(undefined4 *)(puVar5 + -0x110) = 0;
    goto LAB_0052a417;
  }
  if (1 < ITEM_WORDS) {
    DAT_0094ec94 = 1;
    while (f_200 <= (float)(&ITEM_P2)[DAT_0094ec94]) {
      *(int *)(puVar5 + -0x13c) = DAT_0094ec94 + 1;
      fVar2 = (float)(&ITEM_LEN)[DAT_0094ec94];
      *(undefined2 *)(puVar5 + -0x140) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
      *(int *)(puVar5 + -0x13c) = (int)ROUND((float)*(int *)(puVar5 + -0x13c) + fVar2);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x140);
      DAT_0094ec94 = *(int *)(puVar5 + -0x13c);
      if (ITEM_WORDS <= DAT_0094ec94) {
        DAT_0094ec90 = thunk_FUN_00595f30(&DAT_00768040,1);
        if (DAT_0094ec90 < 0) {
          *(undefined4 *)(puVar5 + -0x104) = 0;
          goto LAB_0052994b;
        }
        thunk_FUN_0054c590(&ITEM_P1,*(undefined4 *)(puVar5 + 0x10),&ITEM_WORDS);
        *(undefined4 *)(puVar5 + -0x100) = 0;
        goto LAB_00529955;
      }
      *(undefined4 *)(puVar5 + -0x108) = 0;
    }
    *(undefined4 *)(puVar5 + -0x10c) = 0;
  }
LAB_0052994b:
  thunk_FUN_004a6baa();
  thunk_FUN_0054c3ec();
LAB_00529955:
  DAT_01be6cd8 = 0;
  DAT_0094ec8c = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE);
  thunk_FUN_0054c4c6((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 2,&DAT_0094ecb0,
                     &DAT_0094ec8c);
  iVar4 = VEC_STRIDE;
  if ((_DAT_0094ecb0 < f_4) || (*(float *)(&DAT_0094ecac + DAT_0094ec8c * 2) != f_m9999)) {
    iVar6 = VEC_BASE - VEC_STRIDE * VEC_LBOUND;
    *(int *)(puVar5 + -0x140) = DAT_0094ec8c + 1;
    thunk_FUN_0054c4c6(iVar6 + iVar4,&DAT_0094ecb0,puVar5 + -0x140);
    iVar4 = DAT_0094ec8c * 4;
    *(int *)(puVar5 + -0xfc) = iVar4;
    DAT_0094eca0 = 1;
    while (0 < iVar4) {
      *(undefined1 *)(DAT_0094eca0 + 0x94ecaf) = (&DAT_0094ecb1)[DAT_0094eca0];
      DAT_0094eca0 = DAT_0094eca0 + 1;
      *(int *)(puVar5 + -0xfc) = *(int *)(puVar5 + -0xfc) + -1;
      iVar4 = *(int *)(puVar5 + -0xfc);
    }
  }
  DAT_0094ec94 = ITEM_WORDS;
  thunk_FUN_0054c590(&DAT_0094ecb0,ITEM_WORDS * 4 + *(int *)(puVar5 + 0x10) + -4,&DAT_0094ec8c);
  DAT_0094ec8c = ITEM_WORDS + DAT_0094ec8c + -1;
  if ((f_2 < _DAT_0094ecb0) &&
     (*(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec8c * 4) == f_m9999)) {
    *(undefined4 *)(puVar5 + -0xf8) = 0;
LAB_00529b14:
    DAT_0078b4e8 = 0;
    DAT_0094ec78 = DAT_0094ec8c + -5;
    DAT_0094eca0 = 1;
    while( true ) {
      fVar2 = *(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094eca0 * 4);
      *(undefined2 *)(puVar5 + -0x140) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
      *(int *)(puVar5 + -0x13c) = (int)ROUND(fVar2);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x140);
      DAT_0094ec74 = *(int *)(puVar5 + -0x13c);
      if (DAT_0094ec78 <= DAT_0094eca0) break;
      if (DAT_0094ec74 < 2) {
        FUN_005f34d1(puVar5,0x529fc9);
        FUN_005f33c9(puVar5,0x529feb);
        FUN_005f34d1(puVar5,0x52a006);
        FUN_005f33c9(puVar5,0x52a025);
        thunk_FUN_0054d831(&DAT_020b8ea0,0x4b);
        *(undefined4 *)(puVar5 + -0x138) = 0;
        FUN_005f7950(puVar5 + -0x138,**(undefined4 **)(puVar5 + 8),0x784ff00,&DAT_00767ff4,0);
        DAT_0094ec80 = DAT_0094ec8c + -6;
        *(undefined4 *)(puVar5 + -0xa4) = 6;
        DAT_0094ec94 = DAT_0094eca0;
        iVar4 = DAT_0094ec94;
        do {
          DAT_0094ec94 = iVar4;
          DAT_0094ec80 = DAT_0094ec80 + 1;
          *(undefined4 *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec94 * 4) =
               *(undefined4 *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec80 * 4);
          *(int *)(puVar5 + -0xa4) = *(int *)(puVar5 + -0xa4) + -1;
          iVar4 = DAT_0094ec94 + 1;
        } while (0 < *(int *)(puVar5 + -0xa4));
        DAT_0094ec8c = DAT_0094ec94;
        *(undefined4 *)(puVar5 + -0xa0) = 0;
        DAT_0094ec94 = DAT_0094ec94 + 1;
        goto LAB_0052a110;
      }
      if ((DAT_0094ec74 < 0x2e) || (*(float *)(*(int *)(puVar5 + 0x10) + DAT_0094eca0 * 4) == f_16))
      {
        fVar2 = *(float *)(*(int *)(puVar5 + 0x10) + DAT_0094eca0 * 4);
        *(undefined2 *)(puVar5 + -0x140) = in_FPUControlWord;
        *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
        *(int *)(puVar5 + -0x13c) = (int)ROUND(fVar2);
        uVar1 = *(undefined2 *)(puVar5 + -0x140);
        _DAT_0094ec6c = *(undefined4 *)(puVar5 + -0x13c);
        if (DAT_0094ec74 < 3) {
          *(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094eca0 * 4) = f_3;
          DAT_0094ec94 = 3 - DAT_0094ec74;
          iVar4 = (((DAT_0094ec74 + DAT_0094eca0) - DAT_0094ec8c) + -1) / -1;
          *(int *)(puVar5 + -0x8c) = iVar4;
          DAT_0094ec80 = DAT_0094ec8c;
          while (0 < iVar4) {
            *(undefined4 *)(*(int *)(puVar5 + 0x10) + -4 + (DAT_0094ec94 + DAT_0094ec80) * 4) =
                 *(undefined4 *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec80 * 4);
            DAT_0094ec80 = DAT_0094ec80 + -1;
            *(int *)(puVar5 + -0x8c) = *(int *)(puVar5 + -0x8c) + -1;
            iVar4 = *(int *)(puVar5 + -0x8c);
          }
          DAT_0094ec8c = DAT_0094ec94 + DAT_0094ec8c;
          DAT_0094ec78 = DAT_0094ec94 + DAT_0094ec78;
          *(float *)(*(int *)(puVar5 + 0x10) + 8 + DAT_0094eca0 * 4) = f_0;
        }
        else {
          *(undefined4 *)(puVar5 + -0x90) = 0;
        }
        if (((f_19 <= *(float *)(*(int *)(puVar5 + 0x10) + DAT_0094eca0 * 4)) ||
            (*(float *)(*(int *)(puVar5 + 0x10) + DAT_0094eca0 * 4) == f_13)) ||
           (*(float *)(*(int *)(puVar5 + 0x10) + DAT_0094eca0 * 4) < f_1)) {
          fVar2 = *(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094eca0 * 4);
          *(undefined2 *)(puVar5 + -0x140) = uVar1;
          *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
          *(int *)(puVar5 + -0x13c) = (int)ROUND(fVar2 + f_1);
          in_FPUControlWord = *(undefined2 *)(puVar5 + -0x140);
          DAT_0094ec80 = *(int *)(puVar5 + -0x13c);
          goto LAB_00529efc;
        }
        *(undefined4 *)(puVar5 + -0x88) = 0;
        fVar2 = *(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094eca0 * 4);
        *(undefined2 *)(puVar5 + -0x140) = uVar1;
        *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
        *(int *)(puVar5 + -0x13c) = (int)ROUND((float)DAT_0094eca0 + fVar2 + f_1);
        in_FPUControlWord = *(undefined2 *)(puVar5 + -0x140);
        DAT_0094eca0 = *(int *)(puVar5 + -0x13c);
        if (DAT_0094ec78 <= DAT_0094eca0) goto LAB_0052a110;
        *(undefined4 *)(puVar5 + -0x7c) = 0;
      }
      else {
        DAT_0094ec80 = DAT_0094eca0 + 0x2d;
        iVar4 = ((DAT_0094eca0 - DAT_0094ec80) + -1) / -1;
        *(int *)(puVar5 + -0x9c) = iVar4;
        while (0 < iVar4) {
          if (*(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec80 * 4) != f_0) {
            *(undefined4 *)(puVar5 + -0x98) = 0;
            break;
          }
          DAT_0094ec80 = DAT_0094ec80 + -1;
          *(int *)(puVar5 + -0x9c) = *(int *)(puVar5 + -0x9c) + -1;
          iVar4 = *(int *)(puVar5 + -0x9c);
        }
        DAT_0094ec70 = DAT_0094ec80 - DAT_0094eca0;
        *(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094eca0 * 4) = (float)DAT_0094ec70;
        DAT_0094eca0 = DAT_0094ec80 + 1;
        DAT_0094ec80 = DAT_0094ec74 - DAT_0094ec70;
        *(undefined4 *)(puVar5 + -0x94) = 0;
LAB_00529efc:
        iVar4 = (DAT_0094ec8c - DAT_0094eca0) + 1;
        *(int *)(puVar5 + -0x84) = iVar4;
        DAT_0094ec74 = DAT_0094eca0;
        while (0 < iVar4) {
          *(undefined4 *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec74 * 4) =
               *(undefined4 *)(*(int *)(puVar5 + 0x10) + -4 + (DAT_0094ec80 + DAT_0094ec74) * 4);
          DAT_0094ec74 = DAT_0094ec74 + 1;
          *(int *)(puVar5 + -0x84) = *(int *)(puVar5 + -0x84) + -1;
          iVar4 = *(int *)(puVar5 + -0x84);
        }
        DAT_0094ec8c = DAT_0094ec8c - DAT_0094ec80;
        DAT_0094ec78 = DAT_0094ec78 - DAT_0094ec80;
        *(undefined4 *)(puVar5 + -0x80) = 0;
      }
    }
    *(undefined4 *)(puVar5 + -0xac) = 0;
LAB_0052a110:
    if (*(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec8c * 4) == f_m9999) {
      fVar2 = *(float *)(*(int *)(puVar5 + 0x10) + -8 + DAT_0094ec8c * 4);
      *(undefined2 *)(puVar5 + -0x140) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
      *(int *)(puVar5 + -0x13c) = (int)ROUND(fVar2);
      DAT_0094ec70 = *(int *)(puVar5 + -0x13c);
      fVar2 = *(float *)(*(int *)(puVar5 + 0x10) + -0xc + DAT_0094ec8c * 4);
      *(undefined2 *)(puVar5 + -0x140) = *(undefined2 *)(puVar5 + -0x140);
      *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
      *(int *)(puVar5 + -0x13c) = (int)ROUND(fVar2);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x140);
      DAT_0078b4e8 = *(int *)(puVar5 + -0x13c);
      if (3 < DAT_0094ec70) {
        fVar2 = *(float *)(*(int *)(puVar5 + 0x10) + -0x10 + DAT_0094ec8c * 4);
        *(undefined2 *)(puVar5 + -0x140) = in_FPUControlWord;
        *(ushort *)(puVar5 + -0x13e) = (ushort)*(undefined4 *)(puVar5 + -0x140) | 0xc00;
        *(int *)(puVar5 + -0x13c) = (int)ROUND(fVar2);
        in_FPUControlWord = *(undefined2 *)(puVar5 + -0x140);
        **(undefined4 **)(puVar5 + 0x14) = *(undefined4 *)(puVar5 + -0x13c);
      }
      DAT_0078dc90 = 0;
      if (4 < DAT_0094ec70) {
        DAT_0078dc90 = *(undefined4 *)(*(int *)(puVar5 + 0x10) + -0x14 + DAT_0094ec8c * 4);
      }
      DAT_0078dc88 = DAT_0078dc90;
      DAT_0094ec8c = DAT_0094ec8c - DAT_0094ec70;
      DAT_0079144c = 0x20202020;
      DAT_00791450 = 0x20202020;
      **(int **)(puVar5 + 0xc) = DAT_0094ec8c;
      _DAT_0094ec68 = 0;
      *(undefined4 *)(puVar5 + -0x74) = 0;
      goto LAB_0052a287;
    }
    *(undefined4 *)(puVar5 + -0x78) = 0;
    do {
      FUN_005f33c9(puVar5,0x52ae28);
      FUN_005f33c9(puVar5,0x52ae44);
      FUN_005f34d1(puVar5,0x52ae5f);
      *(undefined4 *)(puVar5 + -0x70) = 0;
LAB_0052a34c:
      *(undefined4 *)(puVar5 + -0x138) = 0;
      FUN_005f7950(puVar5 + -0x138,**(undefined4 **)(puVar5 + 8),0x784ff00,&DAT_00767ff4,0);
      bVar11 = &stack0x00000000 == (undefined1 *)0x164;
      iVar4 = 1;
      piVar8 = (int *)(s____Error_writing_file__00796ddc + 10);
      piVar10 = &i_1953067639;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar11 = *piVar8 == *piVar10;
        piVar8 = piVar8 + 1;
        piVar10 = piVar10 + 1;
      } while (bVar11);
      if (bVar11) {
        *(undefined4 *)(puVar5 + -0x60) = 0;
        return;
      }
      P2 = f_0;
      _DAT_0094ec50 = 99;
      thunk_FUN_004f5268(&DAT_0094ec50);
      FUN_005f33c9(puVar5,0x52a3e4);
      FUN_005f34d1(puVar5,0x52a3ff);
      thunk_FUN_004a5309(*(undefined4 *)(puVar5 + 0x18),0x80);
      *(undefined4 *)(puVar5 + -0x5c) = 0;
LAB_0052a417:
      DAT_0094ec88 = **(int **)(puVar5 + 8);
      *(undefined4 *)(puVar5 + -0x138) = 0;
      FUN_005f7950(puVar5 + -0x138,3,0x784ff00,&DAT_00767ff4,0);
      *(undefined4 *)(puVar5 + -0x138) = 0;
      FUN_005f7950(puVar5 + -0x138,DAT_0094ec88,0x784ff00,&DAT_00767ff4,0);
      thunk_FUN_00498826(&DAT_0078b510,0x80,&DAT_0094ec88,&DAT_00767fe4,&DAT_00767fe8);
      if (DAT_0094ec88 < 0) {
        *(undefined4 *)(puVar5 + -0xe4) = 0;
        if (**(int **)(puVar5 + 8) != 3) {
          FUN_00608ca0(&DAT_0094ec64,&DAT_0094ec60,&DAT_0094ec5c,&DAT_0094ec58,&DAT_0094ec54);
          goto LAB_0052a2f8;
        }
        *(undefined4 *)(puVar5 + -0x6c) = 0;
        FUN_005f33c9(puVar5,0x52a4f3);
        FUN_005f33c9(puVar5,0x52a50f);
        FUN_005f34d1(puVar5,0x52a52a);
        goto LAB_0052a34c;
      }
      if (DAT_0094ec88 != 3) {
        *(undefined4 *)(puVar5 + -0xe0) = 0;
        DAT_0094ec70 = **(int **)(puVar5 + 0xc) + 5;
        *(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec70 * 4) = f_m9999;
        *(float *)(*(int *)(puVar5 + 0x10) + -8 + DAT_0094ec70 * 4) = f_5;
        *(float *)(*(int *)(puVar5 + 0x10) + -0xc + DAT_0094ec70 * 4) = (float)DAT_0078b4e8;
        *(float *)(*(int *)(puVar5 + 0x10) + -0x10 + DAT_0094ec70 * 4) =
             (float)**(int **)(puVar5 + 0x14);
        DAT_0078dc90 = DAT_0078dc84;
        *(undefined4 *)(*(int *)(puVar5 + 0x10) + -0x14 + DAT_0094ec70 * 4) = DAT_0078dc84;
        if (DAT_0094ec4c == 0) {
          *(undefined4 *)(puVar5 + -0x58) = 0;
        }
        else {
          if ((DAT_009ae2bc & 0xffffff) == 0x577e7e) {
            thunk_FUN_0054c590(*(undefined4 *)(puVar5 + 0x10),&DAT_0094ecb4,&DAT_0094ec70);
            DAT_01be6cd8 = 0xffffffff;
            _DAT_0094ecb0 = (float)DAT_0094ec70;
            if (DAT_0094ec70 < 0x3779) {
              DAT_01be6cd8 = 0;
              iVar4 = DAT_0094ec70 * 4 + 2;
              *(int *)(puVar5 + -0x4c) = iVar4;
              DAT_0094eca0 = 3;
              while (0 < iVar4) {
                *(undefined1 *)(DAT_0094eca0 + 0x94ecaf) = (&DAT_0094ecb1)[DAT_0094eca0];
                DAT_0094eca0 = DAT_0094eca0 + 1;
                *(int *)(puVar5 + -0x4c) = *(int *)(puVar5 + -0x4c) + -1;
                iVar4 = *(int *)(puVar5 + -0x4c);
              }
            }
            else {
              *(undefined4 *)(puVar5 + -0x50) = 0;
            }
            *(int *)(puVar5 + -0x140) = DAT_0094ec70 + 1;
            thunk_FUN_0054c4c6(&DAT_0094ecb0,(VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE,
                               puVar5 + -0x140);
            *(undefined4 *)(puVar5 + -0x48) = 0;
            return;
          }
          *(undefined4 *)(puVar5 + -0x54) = 0;
        }
        DAT_0078b4f0 = 0;
        if (DAT_0094ec70 < 0x3779) {
          DAT_0094ecac = (short)DAT_0094ec70;
          *(undefined4 *)(puVar5 + -0x138) = 0;
          *(short **)(puVar5 + -0x140) = &DAT_0094ecac;
          iVar4 = FUN_005fa4d0(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767fc0,puVar5 + -0x140)
          ;
          *(int *)(puVar5 + -0x40) = iVar4;
          if (iVar4 == 0) {
            iVar4 = (int)DAT_0094ecac;
            if (iVar4 < 0) {
              iVar4 = 0;
            }
            DAT_0094ec80 = iVar4 + 1;
            *(undefined4 *)(puVar5 + -0x150) = 1;
            *(undefined4 *)(puVar5 + -0x14c) = *(undefined4 *)(puVar5 + 0x10);
            *(undefined4 *)(puVar5 + -0x148) = 1;
            *(int *)(puVar5 + -0x144) = iVar4;
            *(undefined4 *)(puVar5 + -0x140) = 4;
            uVar3 = FUN_005fa9f0(puVar5 + -0x138,&DAT_00767fc4,puVar5 + -0x150);
            *(undefined4 *)(puVar5 + -0x40) = uVar3;
          }
          if (*(int *)(puVar5 + -0x40) == 0) {
            *(undefined4 *)(puVar5 + -0x3c) = 0;
            goto LAB_0052a287;
          }
        }
        else {
          *(undefined4 *)(puVar5 + -0x44) = 0;
          *(undefined4 *)(puVar5 + -0x138) = 0;
          *(int **)(puVar5 + -0x140) = &DAT_0094ec70;
          iVar4 = FUN_005fa4d0(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767fc8,puVar5 + -0x140)
          ;
          *(int *)(puVar5 + -0x38) = iVar4;
          if (iVar4 == 0) {
            iVar4 = DAT_0094ec70;
            if (DAT_0094ec70 < 0) {
              iVar4 = 0;
            }
            DAT_0094ec80 = iVar4 + 1;
            *(undefined4 *)(puVar5 + -0x150) = 1;
            *(undefined4 *)(puVar5 + -0x14c) = *(undefined4 *)(puVar5 + 0x10);
            *(undefined4 *)(puVar5 + -0x148) = 1;
            *(int *)(puVar5 + -0x144) = iVar4;
            *(undefined4 *)(puVar5 + -0x140) = 4;
            uVar3 = FUN_005fa9f0(puVar5 + -0x138,&DAT_00767fc4,puVar5 + -0x150);
            *(undefined4 *)(puVar5 + -0x38) = uVar3;
          }
          if (*(int *)(puVar5 + -0x38) == 0) {
LAB_0052a287:
            if (DAT_01c58610 == 2) {
              *(undefined4 *)(puVar5 + -0x138) = 0;
              *(undefined4 *)(puVar5 + -0x140) = 0x80;
              *(undefined4 **)(puVar5 + -0x13c) = &DAT_0098d530;
              uVar3 = FUN_005fa4d0(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767ff0,
                                   puVar5 + -0x140);
              *(undefined4 *)(puVar5 + -0x30) = uVar3;
              if (*(int *)(puVar5 + -0x30) != 0) goto LAB_0052a2f8;
            }
            else {
              *(undefined4 *)(puVar5 + -0x34) = 0;
            }
            *(undefined4 *)(puVar5 + -0x138) = 0;
            FUN_005f7950(puVar5 + -0x138,**(undefined4 **)(puVar5 + 8),0x784ff00,&DAT_00767ff4,0);
            DAT_00790c10 = 0;
            if (_DAT_020b90a0 == 0x4d47) {
              puVar7 = &DAT_0098d530;
              puVar9 = &DAT_0078b510;
              for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar9 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar9 = puVar9 + 1;
              }
              *(undefined4 *)(puVar5 + -0x28) = 0;
              goto LAB_0052b098;
            }
            if (DAT_01c58610 == 2) {
              puVar7 = &DAT_0098d530;
              puVar9 = &DAT_0078b510;
              for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar9 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar9 = puVar9 + 1;
              }
              *(undefined4 *)(puVar5 + -0x24) = 0;
              return;
            }
            iVar4 = FUN_005f4660(0x20);
            if (iVar4 != 0) {
              *(undefined4 *)(puVar5 + -0x20) = 0;
              bVar11 = false;
              goto LAB_0052b04d;
            }
            *(undefined4 *)(puVar5 + -0x1c) = 0x80;
            DAT_0094eca0 = 1;
            goto LAB_0052af8a;
          }
        }
LAB_0052a2f8:
        s____Error_writing_file__00796ddc[10] = (undefined1)i_1953067639;
        s____Error_writing_file__00796ddc[0xb] = i_1953067639._1_1_;
        s____Error_writing_file__00796ddc[0xc] = i_1953067639._2_1_;
        s____Error_writing_file__00796ddc[0xd] = i_1953067639._3_1_;
        FUN_005f33c9(puVar5,0x52a326);
        FUN_005f34d1(puVar5,0x52a341);
        *(undefined4 *)(puVar5 + -0x68) = 0;
        goto LAB_0052a34c;
      }
      if ((DAT_01c58600 == 0) && (_DAT_020b90a0 != 0x4d47)) {
        DAT_0094ec84 = DAT_02052740;
        thunk_FUN_004a6baa();
        thunk_FUN_0054c3ec();
        if (0 < DAT_01c26194) {
          DAT_01c26194 = -DAT_01c26194;
        }
        DAT_02052740 = DAT_0094ec84;
      }
      *(undefined4 *)(puVar5 + -0x138) = 0;
      *(short **)(puVar5 + -0x140) = &DAT_0094ecac;
      uVar3 = FUN_005f8240(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767fbc,puVar5 + -0x140);
      *(undefined4 *)(puVar5 + -0xdc) = uVar3;
      if (*(int *)(puVar5 + -0xdc) == 0) {
        iVar4 = (int)DAT_0094ecac;
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        DAT_0094ec80 = iVar4 + 1;
        *(undefined4 *)(puVar5 + -0x138) = 0;
        *(undefined4 *)(puVar5 + -0x150) = 1;
        *(undefined4 *)(puVar5 + -0x14c) = *(undefined4 *)(puVar5 + 0x10);
        *(undefined4 *)(puVar5 + -0x148) = 1;
        *(int *)(puVar5 + -0x144) = iVar4;
        *(undefined4 *)(puVar5 + -0x140) = 4;
        uVar3 = FUN_005f8240(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767fc4,puVar5 + -0x150);
        *(undefined4 *)(puVar5 + -0xd8) = uVar3;
        if (*(int *)(puVar5 + -0xd8) == 0) {
          iVar4 = FUN_005f4660(0x20);
          if (iVar4 == 0) {
            *(undefined4 *)(puVar5 + -0xd4) = 0;
          }
          else {
            *(undefined4 *)(puVar5 + -0x138) = 0;
            *(undefined4 *)(puVar5 + -0x140) = 0x80;
            *(undefined4 **)(puVar5 + -0x13c) = &DAT_0098d4b0;
            uVar3 = FUN_005f8240(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767ff0,
                                 puVar5 + -0x140);
            *(undefined4 *)(puVar5 + -0xd0) = uVar3;
            if (*(int *)(puVar5 + -0xd0) == 0) {
              DAT_0094eca8 = 1;
              DAT_0078b4e0 = 0;
              FUN_005f33c9(puVar5,0x52ab5e);
              FUN_005f34d1(puVar5,0x52ab79);
              FUN_005f33c9(puVar5,0x52ab9b);
              FUN_005f34d1(puVar5,0x52abb6);
              DAT_0094ec7c = thunk_FUN_00595e70();
              if (0 < DAT_0094ec7c) {
                FUN_005f34d1(puVar5,0x52abeb);
                *(undefined4 *)(puVar5 + -0xcc) = 0;
                DAT_0078b4e0 = 0xffffff9d;
                return;
              }
              puVar7 = &DAT_0098d4b0;
              puVar9 = &DAT_0078b510;
              for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar9 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar9 = puVar9 + 1;
              }
            }
          }
        }
      }
      *(undefined4 *)(puVar5 + -0x138) = 0;
      FUN_005f7950(puVar5 + -0x138,DAT_0094ec88,0x784ff00,&DAT_00767ff4,0);
      DAT_0094ec8c = (int)DAT_0094ecac;
      if ((DAT_0078b4ec == 1) ||
         (*(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec8c * 4) == f_m9999)) {
        *(undefined4 *)(puVar5 + -0xc4) = 0;
        goto LAB_00529b14;
      }
      thunk_FUN_00498826(&DAT_0078b510,0x80,&DAT_0094ec88,&DAT_00767fe4,&DAT_00767fe8);
      *(undefined4 *)(puVar5 + -0x138) = 0;
      *(int **)(puVar5 + -0x140) = &DAT_0094ec8c;
      uVar3 = FUN_005f8240(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767f98,puVar5 + -0x140);
      *(undefined4 *)(puVar5 + -0xc0) = uVar3;
      if (*(int *)(puVar5 + -0xc0) != 0) goto LAB_0052ae6f;
      if ((2 < DAT_0094ec8c) && (DAT_0094ec8c <= DAT_020b8e20)) goto code_r0x0052ad28;
      *(undefined4 *)(puVar5 + -0xbc) = 0;
    } while( true );
  }
LAB_0052b1e6:
  FUN_005f34d1(puVar5,0x52b203);
  FUN_005f33c9(puVar5,0x52b225);
  FUN_005f34d1(puVar5,0x52b240);
  FUN_005f33c9(puVar5,0x52b25f);
  thunk_FUN_0054d831(&DAT_020b8ea0,0x4b);
  FUN_005f34d1(puVar5,0x52b291);
  FUN_005f34d1(puVar5,0x52b2b2);
  FUN_005f34d1(puVar5,0x52b2d3);
  DAT_0078b4e0 = 0xffffff9d;
  *(undefined4 *)(puVar5 + -0x138) = 0;
  FUN_005f7950(puVar5 + -0x138,**(undefined4 **)(puVar5 + 8),0x784ff00,&DAT_00767ff4,0);
  *(undefined4 *)(puVar5 + -0xf0) = 0;
  return;
code_r0x0052ad28:
  iVar4 = DAT_0094ec8c;
  if (DAT_0094ec8c < 0) {
    iVar4 = 0;
  }
  DAT_0094ec80 = iVar4 + 1;
  *(undefined4 *)(puVar5 + -0x138) = 0;
  *(undefined4 *)(puVar5 + -0x150) = 1;
  *(undefined4 *)(puVar5 + -0x14c) = *(undefined4 *)(puVar5 + 0x10);
  *(undefined4 *)(puVar5 + -0x148) = 1;
  *(int *)(puVar5 + -0x144) = iVar4;
  *(undefined4 *)(puVar5 + -0x140) = 4;
  uVar3 = FUN_005f8240(puVar5 + -0x138,DAT_0094ec88,0x784ff01,&DAT_00767fc4,puVar5 + -0x150);
  *(undefined4 *)(puVar5 + -0xb8) = uVar3;
  if ((*(int *)(puVar5 + -0xb8) != 0) ||
     (*(float *)(*(int *)(puVar5 + 0x10) + -4 + DAT_0094ec8c * 4) == f_m9999)) {
LAB_0052ae6f:
    *(undefined4 *)(puVar5 + -0x138) = 0;
    FUN_005f7950(puVar5 + -0x138,DAT_0094ec88,0x784ff00,&DAT_00767ff4,0);
    goto LAB_00529b14;
  }
  *(undefined4 *)(puVar5 + -0xb4) = 0;
  goto LAB_0052b1e6;
  while( true ) {
    DAT_0094eca0 = DAT_0094eca0 + 1;
    *(int *)(puVar5 + -0x1c) = *(int *)(puVar5 + -0x1c) + -1;
    if (*(int *)(puVar5 + -0x1c) < 1) break;
LAB_0052af8a:
    iVar4 = FUN_005f4660(0x20);
    bVar11 = iVar4 == 0;
    if (!bVar11) {
      *(undefined4 *)(puVar5 + -0x18) = 0;
      goto LAB_0052b04d;
    }
  }
  if (DAT_0094eca8 == 0) {
    DAT_0094eca0 = 0x80;
    thunk_FUN_0054c6b5(&DAT_0078b510,0x80,&DAT_0094eca0,&DAT_0094ec9c,&DAT_0094ec98);
    FUN_0052b61a(&DAT_00767f78);
    bVar11 = &stack0x00000000 == (undefined1 *)0x164;
  }
  else {
    *(undefined4 *)(puVar5 + -0x14) = 0;
    bVar11 = false;
  }
LAB_0052b04d:
  iVar4 = 0x20;
  piVar8 = &DAT_0078b510;
  piVar10 = &DAT_0098d530;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar11 = *piVar8 == *piVar10;
    piVar8 = piVar8 + 1;
    piVar10 = piVar10 + 1;
  } while (bVar11);
  if (!bVar11) {
    puVar7 = &DAT_0098d530;
    puVar9 = &DAT_0078b590;
    for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  puVar7 = &DAT_0078b510;
  puVar9 = &DAT_0098d530;
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar7 = &DAT_0078b510;
  puVar9 = *(undefined4 **)(puVar5 + 0x18);
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
LAB_0052b098:
  if (DAT_0078b4e4 != 0x4d) {
    DAT_020b8e38 = 0;
  }
  if ((DAT_0094eca4 == 0) && (DAT_01c58610 == 0)) {
    thunk_FUN_0054cd71(&DAT_0078b510,0x80,&DAT_00767f74,&DAT_0094ec50);
    _DAT_0094ec50 = 0xffffffff;
    thunk_FUN_004f5268(&DAT_0094ec50);
    FUN_005f33c9(puVar5,0x52b11d);
    FUN_005f34d1(puVar5,0x52b138);
    *(undefined4 *)(puVar5 + -0xc) = 0x80;
    DAT_0094eca0 = 0x80;
    do {
      if ((&DAT_020b909f)[DAT_0094eca0] == '\\') {
        *(undefined4 *)(puVar5 + -8) = 0;
        (&DAT_020b909f)[DAT_0094eca0] = 0;
        iVar4 = DAT_0094eca0;
        if (DAT_0094eca0 < 0) {
          iVar4 = 0;
        }
        DAT_0094ec88 = FUN_00601c70(&DAT_020b90a0,iVar4);
        return;
      }
      (&DAT_020b909f)[DAT_0094eca0] = 0x20;
      DAT_0094eca0 = DAT_0094eca0 + -1;
      *(int *)(puVar5 + -0xc) = *(int *)(puVar5 + -0xc) + -1;
    } while (0 < *(int *)(puVar5 + -0xc));
    *(undefined4 *)(puVar5 + -4) = 0;
    return;
  }
  *(undefined4 *)(puVar5 + -0x10) = 0;
  return;
}


