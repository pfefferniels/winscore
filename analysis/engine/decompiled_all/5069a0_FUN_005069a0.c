// FUN_005069a0 @ 005069a0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005069a0(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  if (DAT_00795780 == 0) {
    FUN_005f33c9(&stack0xfffffffc,0x5069dc);
    FUN_005f34d1(puVar5,0x5069f7);
    DAT_00795780 = 1;
    DAT_019c66f0 = 0x78;
    **(undefined4 **)(puVar5 + 0xc) = 0;
    for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
      for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
        *(undefined4 *)(iVar3 * 4 + iVar2 * 0x40 + 0x1f9393c) = 0;
      }
    }
    for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
      for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
        *(undefined4 *)(iVar3 * 4 + iVar2 * 0x40 + 0x1a7295c) = 0;
      }
    }
    for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
      for (iVar3 = 1; iVar3 < 5; iVar3 = iVar3 + 1) {
        *(undefined4 *)(iVar3 * 4 + iVar2 * 0x10 + 0x1a7288c) = 0;
      }
    }
    DAT_0078b4e4 = 0x50;
    DAT_0078b4e0 = 0xffffffff;
    DAT_01b34574 = DAT_0078b4f0;
    thunk_FUN_004f7808();
    DAT_0078b4e0 = 0;
    FUN_005f34d1(puVar5,0x506b0c);
    DAT_0078b4f0 = DAT_01b34574;
    DAT_01b34574 = 0;
    puVar1 = puVar5;
    FUN_005f34d1(puVar5,0x506b41);
    if (DAT_01a728a0 == 0) {
      iVar2 = 1;
      for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
        *(undefined4 *)(iVar2 * 0x10 + 0x1a72890) = 1;
        iVar2 = iVar2 + 1;
      }
    }
    if (DAT_01a728a4 == 0) {
      iVar2 = 1;
      for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
        *(undefined4 *)(iVar2 * 0x10 + 0x1a72894) = 1;
        iVar2 = iVar2 + 1;
      }
    }
    if (DAT_01a728a8 == 0) {
      iVar2 = 1;
      for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
        *(undefined4 *)(iVar2 * 0x10 + 0x1a72898) = 0x40;
        iVar2 = iVar2 + 1;
      }
    }
    for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
      for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
        *(undefined4 *)(iVar3 * 4 + iVar2 * 0x40 + 0x1f9393c) = 0;
      }
    }
    DAT_01b34574 = 0;
    DAT_01b9d5c0 = 0;
    thunk_FUN_00505e84();
    if (DAT_01f93980 != 0) {
      *(undefined4 *)(puVar1 + -0x54) = 0;
      *(undefined4 *)(puVar1 + -0x7c) = 1;
      do {
        if (0x10 < *(int *)(puVar1 + -0x7c)) goto LAB_00506c8f;
        iVar2 = *(int *)(puVar1 + -0x7c);
        iVar3 = *(int *)(puVar1 + -0x7c);
        for (iVar4 = 1; iVar4 < 0x11; iVar4 = iVar4 + 1) {
          *(undefined4 *)(iVar4 * 4 + iVar3 * 0x40 + 0x1a7295c) =
               *(undefined4 *)(iVar4 * 4 + iVar2 * 0x40 + 0x1f9393c);
        }
        *(int *)(puVar1 + -0x7c) = *(int *)(puVar1 + -0x7c) + 1;
      } while( true );
    }
LAB_005073d0:
    *(undefined4 *)(puVar1 + -0x50) = 0;
    DAT_01b9d5c0 = 0xfffffc19;
    return;
  }
  while( true ) {
    if (**(int **)(puVar1 + 0xc) != 0) {
      if (**(int **)(puVar1 + 0xc) == -6) {
        **(int **)(puVar1 + 0xc) = DAT_019c66f0 + -6;
      }
      if (**(int **)(puVar1 + 0xc) == -0xc) {
        **(int **)(puVar1 + 0xc) = DAT_019c66f0 + 0xc;
      }
      DAT_019c66f0 = **(int **)(puVar1 + 0xc);
    }
    if (**(int **)(puVar1 + 8) == 0) {
      DAT_0093fe1c = thunk_FUN_0059cdf0(&DAT_01a728a0,&DAT_01a729a0);
    }
    **(undefined4 **)(puVar1 + 0xc) = 0;
    thunk_FUN_00468df8(&DAT_00766ef4);
    if (DAT_0093fe1c == 2) {
      *(undefined4 *)(puVar1 + -0x3c) = 0;
      goto LAB_005073d0;
    }
    if (DAT_019c66ec == 0) break;
    DAT_019c66ec = 0;
    *(undefined4 *)(puVar1 + -0x38) = 0;
LAB_00506c8f:
    thunk_FUN_00468df8(&DAT_00766efc);
    DAT_0093fe28 = 0;
    *(int *)(puVar1 + -0x4c) = ITEM_I;
    DAT_0093fe24 = 1;
    iVar2 = ITEM_I;
    while (0 < iVar2) {
      LOAD_I = DAT_0093fe24;
      load_item_header();
      if ((LOAD_CODE == 8) && (0xc < LOAD_LEN)) {
        DAT_0093fe20 = (float)(&ITEM_P13)[LOAD_W];
        if (DAT_0093fe20 == f_0) {
          *(undefined4 *)(puVar1 + -0x44) = 0;
        }
        else {
          if (DAT_0093fe28 == 0) {
            DAT_0093fe28 = 1;
            thunk_FUN_0054c590(&ITEM_P1,&DAT_01a27780,&ITEM_WORDS);
          }
          for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
            *(float *)(&P0 + iVar2 * 4) = f_0;
          }
          P2 = DAT_0093fe20;
          P3 = (float)LOAD_STAFF;
          thunk_FUN_0055b1f8();
          draw_items();
        }
      }
      else {
        *(undefined4 *)(puVar1 + -0x48) = 0;
      }
      *(undefined4 *)(puVar1 + -0x40) = 0;
      DAT_0093fe24 = DAT_0093fe24 + 1;
      *(int *)(puVar1 + -0x4c) = *(int *)(puVar1 + -0x4c) + -1;
      iVar2 = *(int *)(puVar1 + -0x4c);
    }
  }
  if (DAT_019c66f0 == 0) {
    DAT_019c66f0 = 0x78;
  }
  DAT_01f93d80 = (float)DAT_019c66f0;
  if (DAT_01a729a0 == 0 && DAT_01a729e0 == 0) {
    DAT_01b9d5c0 = 0xfffffc19;
    *(undefined4 *)(puVar1 + -0x34) = 0;
  }
  else {
    DAT_01b34574 = 0;
    *(undefined4 *)(puVar1 + -0x30) = 0x10;
    DAT_0093fe1c = 1;
    do {
      *(undefined4 *)(puVar1 + -0x2c) = 0x10;
      DAT_0093fe3c = 1;
      do {
        *(undefined4 *)(DAT_0093fe3c * 4 + DAT_0093fe1c * 0x40 + 0x1f9393c) =
             *(undefined4 *)(DAT_0093fe1c * 0x40 + DAT_0093fe3c * 4 + 0x1a7295c);
        DAT_0093fe3c = DAT_0093fe3c + 1;
        *(int *)(puVar1 + -0x2c) = *(int *)(puVar1 + -0x2c) + -1;
      } while (0 < *(int *)(puVar1 + -0x2c));
      *(undefined4 *)(puVar1 + -0x28) = 0;
      DAT_0093fe1c = DAT_0093fe1c + 1;
      *(int *)(puVar1 + -0x30) = *(int *)(puVar1 + -0x30) + -1;
    } while (0 < *(int *)(puVar1 + -0x30));
    if (DAT_01b34574 == 0) {
      *(undefined4 *)(puVar1 + -0x24) = 0x10;
      DAT_0093fe3c = 1;
      do {
        *(int *)(DAT_0093fe3c * 4 + 0x1b12e1c) = DAT_0093fe3c;
        *(undefined4 *)(DAT_0093fe3c * 4 + 0x1b12e5c) =
             *(undefined4 *)(DAT_0093fe3c * 0x10 + 0x1a72890);
        *(undefined4 *)(DAT_0093fe3c * 4 + 0x1b12e9c) =
             *(undefined4 *)(DAT_0093fe3c * 0x10 + 0x1a72894);
        *(undefined4 *)(DAT_0093fe3c * 4 + 0x1b12f1c) =
             *(undefined4 *)(DAT_0093fe3c * 0x10 + 0x1a72898);
        *(undefined4 *)(DAT_0093fe3c * 4 + 0x1b12edc) =
             *(undefined4 *)(DAT_0093fe3c * 0x10 + 0x1a7289c);
        DAT_0093fe3c = DAT_0093fe3c + 1;
        *(int *)(puVar1 + -0x24) = *(int *)(puVar1 + -0x24) + -1;
      } while (0 < *(int *)(puVar1 + -0x24));
    }
    DAT_01b34574 = 0;
    DAT_01f93d80 = f_11520 / DAT_01f93d80;
    while ((DAT_01f93980 == 0 && (DAT_01f939c0 == 0))) {
      for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
        for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
          *(undefined4 *)(iVar3 * 4 + iVar2 * 0x40 + 0x1f9393c) = 0;
        }
      }
      DAT_01b34574 = 0;
      thunk_FUN_00505e84();
      *(undefined4 *)(puVar1 + -0x1c) = 0;
    }
    *(undefined4 *)(puVar1 + -0x20) = 0;
    if (DAT_01b34574 == 0) {
      DAT_0078b4e4 = 0x53;
      DAT_0078b4e0 = 0xffffffff;
      DAT_01b34574 = DAT_0078b4f0;
      thunk_FUN_004f7808();
      DAT_0078b4e0 = 0;
      FUN_005f34d1(puVar1,0x507118);
      DAT_0078b4f0 = DAT_01b34574;
      DAT_01b34574 = 0;
      *(undefined4 *)(puVar1 + -0x7c) = 1;
      while (*(int *)(puVar1 + -0x7c) < 0x11) {
        iVar2 = *(int *)(puVar1 + -0x7c);
        iVar3 = *(int *)(puVar1 + -0x7c);
        for (iVar4 = 1; iVar4 < 0x11; iVar4 = iVar4 + 1) {
          *(undefined4 *)(iVar4 * 4 + iVar3 * 0x40 + 0x93fefc) =
               *(undefined4 *)(iVar4 * 4 + iVar2 * 0x40 + 0x1f9393c);
        }
        *(int *)(puVar1 + -0x7c) = *(int *)(puVar1 + -0x7c) + 1;
      }
      for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
        *(undefined4 *)(iVar2 * 4 + 0x93fefc) = *(undefined4 *)(iVar2 * 4 + 0x1b12e1c);
      }
      for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
        *(undefined4 *)(iVar2 * 4 + 0x93febc) = *(undefined4 *)(iVar2 * 4 + 0x1b12e5c);
      }
      for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
        *(undefined4 *)(iVar2 * 4 + 0x93fe7c) = *(undefined4 *)(iVar2 * 4 + 0x1b12e9c);
      }
      for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
        (&DAT_0093fe3c)[iVar2] = *(undefined4 *)(iVar2 * 4 + 0x1b12edc);
      }
      _DAT_0093fe18 = DAT_01f93d80;
      *(undefined4 *)(puVar1 + -0x14) = 0x10;
      DAT_01b34580 = 1;
      do {
        if (*(int *)(&DAT_01f93940 + DAT_01b34580 * 0x40) == 0) {
          *(undefined4 *)(puVar1 + -0x10) = 0;
        }
        else {
          DAT_01b34588 = f_0_3;
          DAT_0093fe14 = DAT_01b34574 + 1;
          *(int *)(DAT_01b34580 * 4 + 0x1b12e1c) = DAT_0093fe14;
          FUN_005073eb();
          FUN_005077a2();
          DAT_01b2a160 = 0xffffffff;
          thunk_FUN_00504468(&DAT_01b9d5c0);
          FUN_005086df();
          thunk_FUN_00504835();
          FUN_00508997();
          thunk_FUN_00504fcb();
          *(int *)(DAT_01b34580 * 4 + 0x1b12e5c) = DAT_01b34574;
        }
        *(undefined4 *)(puVar1 + -0xc) = 0;
        DAT_01b34580 = DAT_01b34580 + 1;
        *(int *)(puVar1 + -0x14) = *(int *)(puVar1 + -0x14) + -1;
      } while (0 < *(int *)(puVar1 + -0x14));
      if (DAT_01b34574 == 0) {
        thunk_FUN_0054d831("No Notes Found.",0xf);
        FUN_005f33c9(puVar1,0x507325);
        FUN_005f34d1(puVar1,0x507340);
        *(undefined4 *)(puVar1 + -8) = 0;
        goto LAB_00507387;
      }
    }
    else {
      *(undefined4 *)(puVar1 + -0x18) = 0;
    }
    thunk_FUN_0050571e();
    FUN_005f34d1(puVar1,0x50736f);
  }
LAB_00507387:
  if (DAT_0093fe28 == 0) {
    *(undefined4 *)(puVar1 + -4) = 0;
  }
  else {
    DAT_0093fe28 = 0;
    thunk_FUN_0054c590(&DAT_01a27780,&ITEM_P1,&ITEM_WORDS);
    DAT_0078b4f0 = 0;
    draw_items();
  }
  return;
}


