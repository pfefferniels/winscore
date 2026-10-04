// FUN_00443b70 @ 00443b70 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0044429f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00443b70(void)

{
  undefined1 uVar5;
  int iVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined2 in_FPUControlWord;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iStack_18;
  
  puVar9 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  iVar1 = FUN_005f4660(0x20);
  if (iVar1 != 0) {
    uVar3 = thunk_FUN_0040db50();
    return uVar3;
  }
  DAT_007f7fc8 = DAT_0078b4e4;
  if (DAT_01fbb8a0 < 0) {
LAB_00443f1a:
    DAT_01fbb860 = (uint)ROUND(P1);
    if ((int)DAT_01fbb860 < 1) {
      DAT_01fbb860 = 1;
    }
    DAT_007f7fc8 = DAT_01fbb860;
    DAT_01fbb868 = P2;
    DAT_01fbb86c = P3;
    if (P3 == f_0) {
      DAT_01fbb86c = f_220;
    }
    DAT_01c58560 = P5;
    DAT_01fbb864 = (int)ROUND(P4);
    if (MAX_STAFF < (int)DAT_01fbb860) {
      DAT_01fbb860 = 1;
      DAT_01fbb864 = MAX_STAFF;
    }
    if (DAT_01fbb864 < (int)DAT_01fbb860) {
      DAT_01fbb864 = DAT_01fbb860;
    }
    uVar3 = thunk_FUN_00441fb8();
    DAT_01fbb8a0 = 0;
    if (DAT_020492a0 < 1) {
      DAT_01fbb8a0 = 0;
      return uVar3;
    }
    FUN_005f33c9(&stack0xfffffffc,0x444083);
    FUN_005f34d1(puVar9,0x44409e);
    uVar3 = draw_items();
LAB_004440a7:
    P1 = f_9;
    P2 = f_m1;
LAB_004445cc:
    DAT_0078b4ec = 0;
    DAT_0078b4f0 = 1;
  }
  else {
    uVar3 = 0;
    switch(DAT_0078b4e4) {
    case 0x4c:
      uVar3 = (uint)DAT_020b8ea2;
      if ((uVar3 != 0x47) && (DAT_020b8ea2 != 0x57)) {
        uVar3 = (uint)DAT_020b8ea2;
      }
    case 0x4e:
    case 0x51:
      break;
    case 0x4d:
LAB_00444158:
      DAT_01fbb860 = (int)ROUND(P2);
      if (DAT_020b8ea2 == 0x41) {
        DAT_01fbb860 = 999;
      }
      if (DAT_01fbb860 == 0) {
        DAT_007f7fc8 = DAT_0078b4e4;
        return (int)ROUND(P2);
      }
      DAT_01fbb864 = (int)ROUND(P3);
      P3 = f_0;
      DAT_01fbb868 = f_0;
      DAT_01fbb86c = f_220;
      DAT_01c58560 = f_2;
      if (DAT_0078b4e4 == 0x4d) {
        DAT_01c58560 = f_18;
      }
      if (MAX_STAFF < (int)DAT_01fbb860) {
        DAT_01fbb860 = 1;
        DAT_01fbb864 = MAX_STAFF;
      }
      DAT_01fbb874 = 0x44;
      DAT_01fbb878 = 1;
      DAT_01fbb87c = ITEM_I;
      uVar3 = thunk_FUN_0049b1d8();
      if (DAT_020492a0 == 0) {
        return uVar3;
      }
      DAT_007f7fc8 = 1;
      for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_007f7fbc = (&ITEM_PTR0)[(&DAT_020492a4)[DAT_007f7fc8]];
        DAT_007f7fb8 = (int)ROUND((float)(&ITEM_LEN)[DAT_007f7fbc]);
        if (DAT_007f7fb8 < 9) {
          DAT_007f7fb4 = 9 - DAT_007f7fb8;
          DAT_007f7fb0 = (&DAT_02091d20)[(&DAT_020492a4)[DAT_007f7fc8]];
          DAT_007f7fac = ITEM_WORDS;
          for (iVar4 = ((DAT_007f7fb0 - ITEM_WORDS) + -1) / -1; 0 < iVar4; iVar4 = iVar4 + -1) {
            (&ITEM_LEN)[DAT_007f7fb4 + DAT_007f7fac] = (&ITEM_LEN)[DAT_007f7fac];
            DAT_007f7fac = DAT_007f7fac + -1;
          }
          ITEM_WORDS = DAT_007f7fb4 + ITEM_WORDS;
          if ((float)(&ITEM_LEN)[DAT_007f7fbc] < f_8) {
            *(float *)(&ITEM_P8 + DAT_007f7fbc * 4) = f_0;
          }
          (&ITEM_LEN)[DAT_007f7fbc] = f_9;
          *(float *)(&ITEM_P9 + DAT_007f7fbc * 4) = f_m1;
          DAT_007f7fac = (&DAT_020492a4)[DAT_007f7fc8] + 1;
          for (iVar4 = (ITEM_I - DAT_007f7fac) + 2; 0 < iVar4; iVar4 = iVar4 + -1) {
            (&ITEM_PTR0)[DAT_007f7fac] = (&ITEM_PTR0)[DAT_007f7fac] + DAT_007f7fb4;
            DAT_007f7fac = DAT_007f7fac + 1;
          }
        }
        else {
          *(float *)(&ITEM_P9 + DAT_007f7fbc * 4) = f_m1;
        }
        DAT_007f7fc8 = DAT_007f7fc8 + 1;
      }
      DAT_0078b4f0 = 1;
      uVar3 = draw_items();
      return uVar3;
    case 0x4f:
      if (DAT_020b8ea2 == 0x4d) {
        uVar3 = FUN_00444745();
        return uVar3;
      }
      if (DAT_020b8ea2 != 0x4c) {
        DAT_007f7fc8 = DAT_0078b4e4;
        return (uint)DAT_020b8ea2;
      }
      if ((P2 != f_0) || (fVar2 = 0.0, P3 != f_0)) {
        P1 = P2;
        P2 = P3;
        P3 = P4;
        P4 = P5;
        fVar2 = P5;
      }
      uVar5 = (undefined1)((ushort)((ushort)(P3 == P2) << 0xe) >> 8);
      if (((P3 == P2) == 0) &&
         (uVar5 = (undefined1)((ushort)((ushort)(P2 == P1) << 0xe) >> 8), (P2 == P1) == 0)) {
        DAT_0078dc78 = (int)ROUND(P3);
        if ((P2 == P4) != 0) {
          DAT_0078dc70 = (int)ROUND(P1);
          _DAT_0078dc74 = (int)ROUND(P2);
          DAT_007f7fc8 = DAT_0078b4e4;
          return (uint)CONCAT21((short)((uint)DAT_0078dc78 >> 0x10),
                                (char)((ushort)((ushort)(P2 == P4) << 0xe) >> 8)) << 8;
        }
        DAT_0078dc70 = (int)ROUND(P1);
        _DAT_0078dc74 = (int)ROUND(P2);
        _DAT_0078dca0 = (int)ROUND(P4);
        DAT_007f7fc8 = DAT_0078b4e4;
        return (int)ROUND(P4);
      }
      DAT_007f7fc8 = DAT_0078b4e4;
      return (uint)CONCAT21((short)((uint)fVar2 >> 0x10),uVar5) << 8;
    case 0x50:
    case 0x53:
    case 0x54:
LAB_00444627:
      puVar7 = (undefined4 *)&DAT_020b8ea0;
      puVar8 = (undefined4 *)&DAT_020b90a0;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      if (DAT_020b8ea0._1_1_ == 0x54) {
        FUN_005f33c9(&stack0xfffffffc,0x44467a);
        puVar6 = puVar10;
        FUN_005f33c9(puVar10,0x444696);
        fVar2 = P2;
        *(undefined2 *)(puVar6 + -0xe8) = in_FPUControlWord;
        *(ushort *)(puVar6 + -0xe6) = (ushort)*(undefined4 *)(puVar6 + -0xe8) | 0xc00;
        *(int *)(puVar6 + -0xe4) = (int)ROUND(fVar2);
        _DAT_007f7fc4 = *(undefined4 *)(puVar6 + -0xe4);
        thunk_FUN_0058c2c9(&DAT_007924d0,0x12,&DAT_00760844,&DAT_00760844,"(1i1)",5,&DAT_007f7fc4);
      }
      uVar3 = thunk_FUN_004a1240(&DAT_00760840);
      *(undefined4 *)(puVar6 + -0xac) = 0;
      return uVar3;
    case 0x52:
      uVar3 = (uint)DAT_020b8ea2;
      if (uVar3 == 0x56) {
        if (DAT_02052740 == 0) {
          if (P2 == f_0) {
            uVar3 = thunk_FUN_00494302();
            return uVar3;
          }
          iStack_18 = 4;
          DAT_007f7fc8 = 1;
          do {
            *(float *)(&P0 + DAT_007f7fc8 * 4) = (&P1)[DAT_007f7fc8];
            DAT_007f7fc8 = DAT_007f7fc8 + 1;
            iStack_18 = iStack_18 + -1;
          } while (0 < iStack_18);
          thunk_FUN_005725fa();
          P5 = f_0;
        }
        else {
          thunk_FUN_00518448();
        }
        goto LAB_00443f1a;
      }
      goto LAB_004440a7;
    default:
      if (DAT_020b8ea0._1_1_ == 0x20) goto LAB_00444627;
      if (DAT_020b8ea0._1_1_ != 0x44) {
        if (DAT_020b8ea0._1_1_ == 0x58) {
          uVar3 = FUN_00445143();
          return uVar3;
        }
        if (DAT_020b8ea0._1_1_ == 0x56) {
          uVar3 = FUN_0044658c();
          return uVar3;
        }
        if (DAT_020b8ea0._1_1_ != 0x57) {
          DAT_007f7fc8 = DAT_0078b4e4;
          return (uint)DAT_020b8ea0._1_1_;
        }
        goto LAB_00444158;
      }
      DAT_007f7fc8 = 3;
      if (DAT_020b90a3 == 0x5c) {
LAB_00444603:
        DAT_007f7fc8 = 2;
LAB_0044460e:
        return (uint)DAT_020b90a3;
      }
      if (DAT_020b8ea2 == 0x41) {
        P2 = f_999;
      }
      if (P2 == f_0) {
        if (DAT_020b90a3 == 0x20) goto LAB_0044460e;
        goto LAB_00444603;
      }
      uVar3 = thunk_FUN_0042c1ed();
      goto LAB_004445cc;
    }
  }
  return uVar3;
}


