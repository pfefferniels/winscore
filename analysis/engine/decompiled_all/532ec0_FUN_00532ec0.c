// FUN_00532ec0 @ 00532ec0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00532ec0(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  if (DAT_01cadcfc == 0) {
    puVar2 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x532eef);
  }
  DAT_01cadcfc = 1;
  if ((DAT_01cadce4 == 0x7e) || (0x52 < DAT_01cadce4 && DAT_01cadce4 < 0x58)) {
    DAT_01cadce0 = DAT_01cadce0 + 1;
    uVar1 = thunk_FUN_0056f324(&DAT_01caea3c + DAT_01cadce0);
    puVar2[-0x79] = uVar1;
    DAT_0099a710 = puVar2[-0x79];
    if (DAT_01cadce4 == 0x7e) {
      *(undefined4 *)(puVar2 + -0x54) = 0;
      if (DAT_0099a710 == 'A') {
        DAT_0099a710 = -0x3d;
      }
      if (DAT_0099a710 == 'a') {
        DAT_0099a710 = -0x1d;
      }
      if (DAT_0099a710 == 'o') {
        DAT_0099a710 = -0xb;
      }
      if (DAT_0099a710 == 'O') {
        DAT_0099a710 = -0x2b;
      }
      if (DAT_0099a710 == 'n') {
        DAT_0099a710 = -0xf;
      }
      if (DAT_0099a710 == 'N') {
        DAT_0099a710 = -0x2f;
      }
      *(undefined4 *)(puVar2 + -0x3c) = 0;
    }
    else {
      switch(DAT_01cadce4) {
      default:
        if (DAT_0099a710 == 'A') {
          DAT_0099a710 = -0x3f;
        }
        if (DAT_0099a710 == 'a') {
          DAT_0099a710 = -0x1f;
        }
        if (DAT_0099a710 == 'E') {
          DAT_0099a710 = -0x37;
        }
        if (DAT_0099a710 == 'e') {
          DAT_0099a710 = -0x17;
        }
        if (DAT_0099a710 == 'I') {
          DAT_0099a710 = -0x33;
        }
        if (DAT_0099a710 == 'i') {
          DAT_0099a710 = -0x13;
        }
        if (DAT_0099a710 == 'O') {
          DAT_0099a710 = -0x2d;
        }
        if (DAT_0099a710 == 'o') {
          DAT_0099a710 = -0xd;
        }
        if (DAT_0099a710 == 'U') {
          DAT_0099a710 = -0x26;
        }
        if (DAT_0099a710 == 'u') {
          DAT_0099a710 = -6;
        }
        if (DAT_0099a710 == 'Y') {
          DAT_0099a710 = -0x23;
        }
        if (DAT_0099a710 == 'y') {
          DAT_0099a710 = -3;
        }
        *(undefined4 *)(puVar2 + -0x50) = 0;
        break;
      case 0x54:
        if (DAT_0099a710 == 'A') {
          DAT_0099a710 = -0x40;
        }
        if (DAT_0099a710 == 'a') {
          DAT_0099a710 = -0x20;
        }
        if (DAT_0099a710 == 'E') {
          DAT_0099a710 = -0x38;
        }
        if (DAT_0099a710 == 'e') {
          DAT_0099a710 = -0x18;
        }
        if (DAT_0099a710 == 'I') {
          DAT_0099a710 = -0x34;
        }
        if (DAT_0099a710 == 'i') {
          DAT_0099a710 = -0x14;
        }
        if (DAT_0099a710 == 'O') {
          DAT_0099a710 = -0x2e;
        }
        if (DAT_0099a710 == 'o') {
          DAT_0099a710 = -0xe;
        }
        if (DAT_0099a710 == 'U') {
          DAT_0099a710 = -0x27;
        }
        if (DAT_0099a710 == 'u') {
          DAT_0099a710 = -7;
        }
        *(undefined4 *)(puVar2 + -0x4c) = 0;
        break;
      case 0x55:
        if (DAT_0099a710 == 'A') {
          DAT_0099a710 = -0x3e;
        }
        if (DAT_0099a710 == 'a') {
          DAT_0099a710 = -0x1e;
        }
        if (DAT_0099a710 == 'E') {
          DAT_0099a710 = -0x36;
        }
        if (DAT_0099a710 == 'e') {
          DAT_0099a710 = -0x16;
        }
        if (DAT_0099a710 == 'I') {
          DAT_0099a710 = -0x32;
        }
        if (DAT_0099a710 == 'i') {
          DAT_0099a710 = -0x12;
        }
        if (DAT_0099a710 == 'O') {
          DAT_0099a710 = -0x2c;
        }
        if (DAT_0099a710 == 'o') {
          DAT_0099a710 = -0xc;
        }
        if (DAT_0099a710 == 'U') {
          DAT_0099a710 = -0x25;
        }
        if (DAT_0099a710 == 'u') {
          DAT_0099a710 = -5;
        }
        *(undefined4 *)(puVar2 + -0x48) = 0;
        break;
      case 0x56:
        if (DAT_0099a710 == 'A') {
          DAT_0099a710 = -0x3c;
        }
        if (DAT_0099a710 == 'a') {
          DAT_0099a710 = -0x1c;
        }
        if (DAT_0099a710 == 'E') {
          DAT_0099a710 = -0x35;
        }
        if (DAT_0099a710 == 'e') {
          DAT_0099a710 = -0x15;
        }
        if (DAT_0099a710 == 'I') {
          DAT_0099a710 = -0x31;
        }
        if (DAT_0099a710 == 'i') {
          DAT_0099a710 = -0x11;
        }
        if (DAT_0099a710 == 'O') {
          DAT_0099a710 = -0x2a;
        }
        if (DAT_0099a710 == 'o') {
          DAT_0099a710 = -10;
        }
        if (DAT_0099a710 == 'U') {
          DAT_0099a710 = -0x24;
        }
        if (DAT_0099a710 == 'u') {
          DAT_0099a710 = -4;
        }
        if (DAT_0099a710 == 'y') {
          DAT_0099a710 = -1;
        }
        *(undefined4 *)(puVar2 + -0x44) = 0;
        break;
      case 0x57:
        if (DAT_0099a710 == 'C') {
          DAT_0099a710 = -0x39;
        }
        if (DAT_0099a710 == 'c') {
          DAT_0099a710 = -0x19;
        }
        *(undefined4 *)(puVar2 + -0x40) = 0;
      }
    }
    goto LAB_0053361a;
  }
  *(undefined4 *)(puVar2 + -0x58) = 0;
  if ((0x4f < DAT_01cadce4) && (DAT_01cadce4 < 0x5d)) {
    *(undefined4 *)(puVar2 + -0x38) = 0;
    goto LAB_0053361a;
  }
  if (DAT_01cadce4 < 0) {
    *(undefined4 *)(puVar2 + -0x34) = 0x3b;
    DAT_0099a724 = 1;
    do {
      if (-*(int *)(DAT_0099a724 * 4 + 0x7970a4) == DAT_01cadce4) {
        DAT_0099a710 = *(char *)(DAT_0099a724 + 0x79706b);
        *(undefined4 *)(puVar2 + -0x2c) = 0;
        goto LAB_0053361a;
      }
      *(undefined4 *)(puVar2 + -0x30) = 0;
      *(undefined4 *)(puVar2 + -0x28) = 0;
      DAT_0099a724 = DAT_0099a724 + 1;
      *(int *)(puVar2 + -0x34) = *(int *)(puVar2 + -0x34) + -1;
    } while (0 < *(int *)(puVar2 + -0x34));
  }
  *(undefined4 *)(puVar2 + -0x24) = 0;
  if ((DAT_01cadce4 < -0xa1) && (DAT_01cadce4 != -800)) {
    *(undefined4 *)(puVar2 + -0x20) = 0;
    goto LAB_0053361a;
  }
  uVar1 = thunk_FUN_0056f324(&DAT_01cadce4);
  puVar2[-0x79] = uVar1;
  DAT_0099a710 = puVar2[-0x79];
  if ((DAT_01cadce4 < 0x84) || (0x8c < DAT_01cadce4)) {
    *(undefined4 *)(puVar2 + -0x1c) = 0;
LAB_0053307c:
    if ((DAT_01cadce4 == 0x91) || (DAT_01cadce4 == 0x93)) {
      DAT_01cadce4 = (DAT_01cadce4 + -0x91) / 2 + 0x54;
    }
    else {
      *(undefined4 *)(puVar2 + -0x14) = 0;
    }
  }
  else {
    if ((DAT_01cadce4 != 0x88) && (DAT_01cadce4 != 0x89)) {
      DAT_01cadce4 = DAT_01cadce4 + -0x34;
      goto LAB_0053307c;
    }
    *(undefined4 *)(puVar2 + -0x18) = 0;
  }
  *(undefined4 *)(puVar2 + -0x10) = 0;
LAB_0053361a:
  _DAT_01a27700 = 1;
  DAT_0099a720 = DAT_01cadce0;
  if ((*(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) + VIEW_DX) - **(int **)(puVar2 + 8) < 20000) {
    *(undefined4 *)(puVar2 + -0xc) = 0;
  }
  else {
    _DAT_0099a71c = i_0;
  }
  *(undefined4 *)(puVar2 + -8) = 4;
  DAT_0099a718 = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_0099a718 + 0x99a707);
    DAT_0099a718 = DAT_0099a718 + 1;
    *(int *)(puVar2 + -8) = *(int *)(puVar2 + -8) + -1;
  } while (0 < *(int *)(puVar2 + -8));
  DAT_01aea640 = DAT_01aea640 + 1;
  *(int *)(&DAT_01afdec0 + DAT_01aea640 * 4) = *DAT_01fbb844;
  _DAT_0099a708 = (*(int *)(&DAT_01cb02bc + DAT_0099a720 * 4) - VIEW_DY) + -100;
  *(undefined4 *)(puVar2 + -4) = 4;
  DAT_0099a718 = 1;
  do {
    *DAT_01fbb844 = *DAT_01fbb844 + 1;
    *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
         *(undefined1 *)(DAT_0099a718 + 0x99a707);
    DAT_0099a718 = DAT_0099a718 + 1;
    *(int *)(puVar2 + -4) = *(int *)(puVar2 + -4) + -1;
  } while (0 < *(int *)(puVar2 + -4));
  *DAT_01fbb844 = *DAT_01fbb844 + 1;
  *(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) =
       DAT_0099a710;
  *DAT_01fbb844 = *DAT_01fbb844 + 1;
  *(undefined1 *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + *DAT_01fbb844 * DAT_01fbb83c) = 0;
  return;
}


