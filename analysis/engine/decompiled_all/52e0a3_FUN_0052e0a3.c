// FUN_0052e0a3 @ 0052e0a3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052e0a3(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar4 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x52e0cc);
  if (0 < DAT_02052740) goto LAB_0052e0e8;
  *(undefined4 *)(puVar4 + -0xf8) = 0;
LAB_0052e679:
  if (2 < DAT_01fbb700) {
    thunk_FUN_00523c07(&DAT_007682a0);
  }
  if (-1 < DAT_02052740) {
    thunk_FUN_00549422();
  }
  if ((((_DAT_020b90a0 & 0xff) != 0x21) && (DAT_01fbb700 == 3)) && (f_256 < _DAT_01fb8c64)) {
    thunk_FUN_00524678();
  }
  if ((_DAT_020b8ea0 & 0xff) == 0x21) {
    *(undefined4 *)(puVar4 + -0xac) = 0;
    return;
  }
  if (DAT_01fbb700 == 0) {
    FUN_005f33c9(puVar4,0x52e71f);
    FUN_005f34d1(puVar4,0x52e73a);
  }
  else if (DAT_01fbb700 == 1) {
    FUN_005f33c9(puVar4,0x52e76a);
    FUN_005f34d1(puVar4,0x52e785);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_00768384);
    }
  }
  else if (DAT_01fbb700 == 2) {
    if (DAT_01fb8c88 == 0) {
      thunk_FUN_0054d831("*** No notes/rests given. ***",0x1e);
      _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_00768198);
      *(undefined4 *)(puVar4 + -0xa8) = 0;
      return;
    }
    FUN_005f33c9(puVar4,0x52e811);
    FUN_005f34d1(puVar4,0x52e82c);
    *(undefined4 *)(puVar4 + -0x118) = 0;
    *(undefined4 *)(puVar4 + -0x130) = 3;
    *(undefined4 *)(puVar4 + -300) = 0x20b90a6;
    *(int **)(puVar4 + -0x128) = &DAT_01fb8c88;
    FUN_005f34f0(puVar4 + -0x118,0x784ff00,&DAT_00768284,puVar4 + -0x130,&DAT_00796f94);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_00768348);
    }
  }
  else if (DAT_01fbb700 == 3) {
    FUN_005f33c9(puVar4,0x52e8d2);
    FUN_005f34d1(puVar4,0x52e8ed);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_00768314);
    }
  }
  else if (DAT_01fbb700 == 4) {
    FUN_005f33c9(puVar4,0x52e93c);
    FUN_005f34d1(puVar4,0x52e957);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_007682ec);
    }
  }
  else if (DAT_01fbb700 == 5) {
    FUN_005f33c9(puVar4,0x52e99f);
    FUN_005f34d1(puVar4,0x52e9ba);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_007682c4);
    }
  }
  if (DAT_02052740 < 0) goto LAB_0052e9f1;
  *(undefined4 *)(puVar4 + -0xa0) = 0;
LAB_0052ef77:
  DAT_0171b230 = 1;
  if (DAT_01fbb700 == 1) {
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    FUN_005f34d1(puVar4,0x52efb9);
    FUN_005f34d1(puVar4,0x52efda);
    thunk_FUN_00596140();
    FUN_0052f871(&DAT_01fb8c60);
    goto LAB_0052ed33;
  }
  if (DAT_01fbb700 == 2) {
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    thunk_FUN_00596140();
    FUN_005f34d1(puVar4,0x52f03a);
    FUN_005f34d1(puVar4,0x52f05b);
    thunk_FUN_00422d98(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
    if ((_DAT_020b90a0 & 0xff) == 0x5e) {
      *(undefined4 *)(puVar4 + -0x74) = 0;
      return;
    }
  }
  else if (DAT_01fbb700 == 3) {
    FUN_005f34d1(puVar4,0x52f0b3);
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    thunk_FUN_00596140();
    thunk_FUN_00426950(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
  }
  else if (DAT_01fbb700 < 4) {
    FUN_005f34d1(puVar4,0x52f14a);
    thunk_FUN_0054991a(&DAT_020b90a0,1);
  }
  else {
    FUN_005f34d1(puVar4,0x52f103);
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    thunk_FUN_00596140();
    thunk_FUN_00427c68(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
  }
LAB_0052ed5d:
  do {
    if (_DAT_020b90a0 != 0x4944494d) {
      if ((_DAT_020b90a0 & 0xff) == 0x5e) {
        *(undefined4 *)(puVar4 + -0x6c) = 0;
        return;
      }
      puVar5 = (undefined4 *)&DAT_020b8ea0;
      puVar6 = (undefined4 *)&DAT_020b90a0;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      **(undefined4 **)(puVar4 + 8) = 0;
      *(undefined4 *)(puVar4 + -0x68) = 0;
LAB_0052ee6d:
      if ((_DAT_020b8ea0 & 0xff) != 0x25) {
        if ((_DAT_020b8ea0 & 0xff) == 0x20) {
          if (DAT_01fbb700 != 0) {
            *(undefined4 *)(puVar4 + -0x54) = 0;
            *(undefined4 *)(puVar4 + -0x4c) = 0x17f;
            DAT_0078b4e0 = 2;
LAB_0052eede:
            if ((&DAT_020b8e9f)[DAT_0078b4e0] == ' ') break;
            *(undefined4 *)(puVar4 + -0x48) = 0;
            while (thunk_FUN_0054c5f8(0x20b8ea1,1,&DAT_020b8ea0,1,&DAT_007682a8),
                  (_DAT_020b8ea0 & 0xff) == 0x20) {
              *(undefined4 *)(puVar4 + -0x3c) = 0;
            }
            goto LAB_0052ecf7;
          }
          _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007682a4);
          *(undefined4 *)(puVar4 + -0x50) = 0;
        }
        else {
          *(undefined4 *)(puVar4 + -0x58) = 0;
        }
        goto LAB_0052ecf7;
      }
      thunk_FUN_005253e2();
      if (-1 < DAT_02052740) {
        if (0 < DAT_02052740) goto LAB_0052e0e8;
        goto LAB_0052ef77;
      }
      goto LAB_0052e9f1;
    }
    *(undefined4 *)(puVar4 + -0x70) = 0;
    if (DAT_019c7e48 != 0) {
      thunk_FUN_0054d831("No MIDI for input.",0x13);
      *(undefined4 *)(puVar4 + -100) = 0;
      goto LAB_0052e679;
    }
    DAT_0099a0d0 = ITEM_WORDS;
    DAT_01fb8c90 = ITEM_I;
    thunk_FUN_004de270();
    if (((_DAT_020b8ea0 & 0xff) == 0x21) || ((_DAT_020b8ea0 & 0xff) == 0x24)) {
      *(undefined4 *)(puVar4 + -0x60) = 0;
      return;
    }
    if ((&DAT_020b8e9f)[DAT_0078d938] == ';') {
      ITEM_WORDS = DAT_0099a0d0;
      ITEM_I = DAT_01fb8c90;
      goto LAB_0052ee6d;
    }
    thunk_FUN_0041c3b8(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
    *(undefined4 *)(puVar4 + -0x5c) = 0;
  } while( true );
  DAT_0078b4e0 = DAT_0078b4e0 + 1;
  *(int *)(puVar4 + -0x4c) = *(int *)(puVar4 + -0x4c) + -1;
  if (*(int *)(puVar4 + -0x4c) < 1) goto LAB_0052ef63;
  goto LAB_0052eede;
LAB_0052ef63:
  if (0 < DAT_02052740) {
    thunk_FUN_00549422();
    *(undefined4 *)(puVar4 + -0x40) = 0;
LAB_0052e0e8:
    *(undefined4 *)(puVar4 + -0x118) = 0;
    iVar1 = FUN_005fdbd0(puVar4 + -0x118,DAT_02052740,0x784ff02,&DAT_007683f4,0,&DAT_00796f58);
    *(int *)(puVar4 + -0xf4) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(puVar4 + -0x11c) = 0x180;
      DAT_0099a0e8 = 1;
      do {
        *(undefined4 *)(puVar4 + -0x130) = 1;
        *(undefined1 **)(puVar4 + -300) = &DAT_020b8e9f + DAT_0099a0e8;
        *(undefined4 *)(puVar4 + -0x128) = 1;
        iVar1 = FUN_005fe110(puVar4 + -0x118,&DAT_007683f0,puVar4 + -0x130);
        *(int *)(puVar4 + -0xf4) = iVar1;
        if (iVar1 != 0) goto LAB_0052e1ec;
        DAT_0099a0e8 = DAT_0099a0e8 + 1;
        *(int *)(puVar4 + -0x11c) = *(int *)(puVar4 + -0x11c) + -1;
      } while (0 < *(int *)(puVar4 + -0x11c));
      uVar2 = FUN_005fe110(puVar4 + -0x118,&DAT_007683ec,0);
      *(undefined4 *)(puVar4 + -0xf4) = uVar2;
    }
LAB_0052e1ec:
    if (*(int *)(puVar4 + -0xf4) == -1) goto LAB_0052e5f3;
    if ((char)DAT_020b8ea0 == '\0') {
      *(undefined4 *)(puVar4 + -0xf0) = 0;
      goto LAB_0052e5f3;
    }
    if ((_DAT_020b8ea0 & 0xff) == 0x25) {
      if ((_DAT_020b8ea0 & 0xff) == (_DAT_020b8ea0 >> 8 & 0xff)) {
        do {
          for (iVar1 = 1; iVar1 < 0x201; iVar1 = iVar1 + 1) {
            (&DAT_020b8e9f)[iVar1] = 0x20;
          }
          *(undefined4 *)(puVar4 + -0x118) = 0;
          iVar1 = FUN_005fdbd0(puVar4 + -0x118,DAT_02052740,0x784ff02,&DAT_007683f4,0,&DAT_00796f6c)
          ;
          *(int *)(puVar4 + -0xe4) = iVar1;
          if (iVar1 == 0) {
            iVar1 = 0x180;
            DAT_0099a0e8 = 1;
            do {
              *(undefined4 *)(puVar4 + -0x130) = 1;
              *(undefined1 **)(puVar4 + -300) = &DAT_020b8e9f + DAT_0099a0e8;
              *(undefined4 *)(puVar4 + -0x128) = 1;
              iVar3 = FUN_005fe110(puVar4 + -0x118,&DAT_007683f0,puVar4 + -0x130);
              *(int *)(puVar4 + -0xe4) = iVar3;
              if (iVar3 != 0) goto LAB_0052e35b;
              DAT_0099a0e8 = DAT_0099a0e8 + 1;
              iVar1 = iVar1 + -1;
            } while (0 < iVar1);
            uVar2 = FUN_005fe110(puVar4 + -0x118,&DAT_007683ec,0);
            *(undefined4 *)(puVar4 + -0xe4) = uVar2;
          }
LAB_0052e35b:
          if (*(int *)(puVar4 + -0xe4) == -1) goto LAB_0052e5f3;
          if ((_DAT_020b8ea0 & 0xffff) == 0x2525) goto LAB_0052e389;
          *(undefined4 *)(puVar4 + -0xe0) = 0;
        } while( true );
      }
      *(undefined4 *)(puVar4 + -0xe8) = 0;
      goto LAB_0052e0e8;
    }
    *(undefined4 *)(puVar4 + -0xec) = 0;
    do {
      DAT_0099a0e4 = 0x180;
      *(undefined4 *)(puVar4 + -0xd8) = 0x180;
      DAT_0099a0e0 = 1;
      do {
        if ((&DAT_020b8e9f)[DAT_0099a0e0] == '%') {
          DAT_0099a0e4 = DAT_0099a0e0;
          *(undefined4 *)(puVar4 + -0xd0) = 0;
          break;
        }
        *(undefined4 *)(puVar4 + -0xd4) = 0;
        *(undefined4 *)(puVar4 + -0xcc) = 0;
        DAT_0099a0e0 = DAT_0099a0e0 + 1;
        *(int *)(puVar4 + -0xd8) = *(int *)(puVar4 + -0xd8) + -1;
      } while (0 < *(int *)(puVar4 + -0xd8));
      iVar1 = -DAT_0099a0e4 / -1;
      *(int *)(puVar4 + -200) = iVar1;
      DAT_0099a0dc = DAT_0099a0e4;
      while (0 < iVar1) {
        if ((&DAT_020b8e9f)[DAT_0099a0dc] == ';') {
          _DAT_0099a0d8 = 0;
          *(undefined4 *)(puVar4 + -0xc0) = 0;
          goto LAB_0052ee6d;
        }
        *(undefined4 *)(puVar4 + -0xc4) = 0;
        if ((&DAT_020b8e9f)[DAT_0099a0dc] == '/') {
          *(undefined4 *)(puVar4 + -0xbc) = 0;
          break;
        }
        DAT_0099a0dc = DAT_0099a0dc + -1;
        *(int *)(puVar4 + -200) = *(int *)(puVar4 + -200) + -1;
        iVar1 = *(int *)(puVar4 + -200);
      }
      *(undefined4 *)(puVar4 + -0x118) = 0;
      iVar1 = FUN_005fdbd0(puVar4 + -0x118,DAT_02052740,0x784ff02,&DAT_007683f4,0,&DAT_00796f80);
      *(int *)(puVar4 + -0xb8) = iVar1;
      if (iVar1 == 0) {
        DAT_0099a0e8 = DAT_0099a0dc + 1;
        for (iVar1 = 0x181 - DAT_0099a0e8; 0 < iVar1; iVar1 = iVar1 + -1) {
          *(undefined4 *)(puVar4 + -0x130) = 1;
          *(undefined1 **)(puVar4 + -300) = &DAT_020b8e9f + DAT_0099a0e8;
          *(undefined4 *)(puVar4 + -0x128) = 1;
          iVar3 = FUN_005fe110(puVar4 + -0x118,&DAT_007683f0,puVar4 + -0x130);
          *(int *)(puVar4 + -0xb8) = iVar3;
          if (iVar3 != 0) goto LAB_0052e5c4;
          DAT_0099a0e8 = DAT_0099a0e8 + 1;
        }
        uVar2 = FUN_005fe110(puVar4 + -0x118,&DAT_007683ec,0);
        *(undefined4 *)(puVar4 + -0xb8) = uVar2;
      }
LAB_0052e5c4:
      if (*(int *)(puVar4 + -0xb8) == -1) goto LAB_0052e5f3;
      *(undefined4 *)(puVar4 + -0xb4) = 0;
    } while( true );
  }
  *(undefined4 *)(puVar4 + -0x44) = 0;
  goto LAB_0052ef77;
LAB_0052e389:
  *(undefined4 *)(puVar4 + -0xdc) = 0;
  goto LAB_0052e0e8;
LAB_0052e5f3:
  *(undefined4 *)(puVar4 + -0x118) = 0;
  FUN_005f7950(puVar4 + -0x118,DAT_02052740,0x784ff00,&DAT_007683e8,0);
  DAT_02052740 = 0;
  DAT_01fbb700 = DAT_01fbb700 + -1;
  if (0 < DAT_01fbb700) {
    input_store_items();
  }
  DAT_01fbb700 = DAT_01fbb700 + 1;
  FUN_005f34d1(puVar4,0x52e675);
  goto LAB_0052e679;
LAB_0052e9f1:
  switch(DAT_01fbb700) {
  default:
    FUN_005f33c9(puVar4,0x52eb56);
    FUN_005f34d1(puVar4,0x52eb71);
    *(undefined4 *)(puVar4 + -0x9c) = 0;
    break;
  case 1:
    iVar3 = 1;
    for (iVar1 = 1; iVar1 < 0x181; iVar1 = iVar1 + 1) {
      (&DAT_020b8e9f)[iVar3] = *(undefined1 *)((int)&DAT_01a1f4d0 + iVar1 + 3);
      iVar3 = iVar3 + 1;
    }
    *(undefined4 *)(puVar4 + -0x98) = 0;
    break;
  case 2:
    iVar3 = 1;
    for (iVar1 = 1; iVar1 < 0x181; iVar1 = iVar1 + 1) {
      (&DAT_020b8e9f)[iVar3] = (&DAT_01a1f653)[iVar1];
      iVar3 = iVar3 + 1;
    }
    *(undefined4 *)(puVar4 + -0x94) = 0;
    break;
  case 3:
    iVar1 = 1;
    for (iVar3 = 1; iVar3 < 0x181; iVar3 = iVar3 + 1) {
      (&DAT_020b8e9f)[iVar1] = (&DAT_01a1f7d3)[iVar3];
      iVar1 = iVar1 + 1;
    }
    *(undefined4 *)(puVar4 + -0x90) = 0;
    break;
  case 4:
    iVar3 = 1;
    for (iVar1 = 1; iVar1 < 0x181; iVar1 = iVar1 + 1) {
      (&DAT_020b8e9f)[iVar3] = *(undefined1 *)(iVar1 + 0x1a1f953);
      iVar3 = iVar3 + 1;
    }
    *(undefined4 *)(puVar4 + -0x8c) = 0;
    break;
  case 5:
    iVar1 = 1;
    for (iVar3 = 1; iVar3 < 0x181; iVar3 = iVar3 + 1) {
      (&DAT_020b8e9f)[iVar1] = *(undefined1 *)(iVar3 + 0x1a1fad3);
      iVar1 = iVar1 + 1;
    }
  }
  DAT_0099a0d4 = DAT_0099a0d4 + 1;
  if ((char)DAT_020b8ea0 == '\0') {
    FUN_005f34d1(puVar4,0x52ebf2);
    DAT_02052740 = 0;
    *(undefined4 *)(puVar4 + -0x88) = 0;
    goto LAB_0052ef77;
  }
  if ((_DAT_020b8ea0 & 0xff) != 0x25) goto LAB_0052ec0d;
  thunk_FUN_0054943a();
  thunk_FUN_0054991a(&DAT_020b90a0,0x200);
  thunk_FUN_005253e2();
  *(undefined4 *)(puVar4 + -0x84) = 0;
  goto LAB_0052e9f1;
LAB_0052ec0d:
  puVar5 = (undefined4 *)&DAT_020b90a0;
  puVar6 = (undefined4 *)&DAT_007a0b7c;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  thunk_FUN_0054cb15(&DAT_020b8ea0,1,*(undefined4 *)(puVar4 + 0xc),&DAT_007682c0);
  *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar4 + 0xc)) = 0;
  puVar5 = (undefined4 *)&DAT_020b8ea0;
  puVar6 = &DAT_009ae2bc;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar1 = thunk_FUN_0059c140();
  if (iVar1 == 2) {
    *(undefined4 *)(puVar4 + -0x80) = 0;
    _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_00768198);
    FUN_005f34d1(puVar4,0x52eca2);
    *(undefined4 *)(puVar4 + -0x18) = 0;
    **(undefined4 **)(puVar4 + 8) = 1;
    return;
  }
  puVar5 = &DAT_009ae2bc;
  puVar6 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  FUN_005f34d1(puVar4,0x52ecec);
  *(undefined4 *)(puVar4 + -0x7c) = 0;
LAB_0052ecf7:
  thunk_FUN_0054c6b5(&DAT_020b8ea0,0x200,*(undefined4 *)(puVar4 + 0xc),&DAT_0078b4e0,&DAT_0078b4e4);
  if (0 < DAT_01fbb700) {
    if (((&DAT_020b8e9f)[**(int **)(puVar4 + 0xc)] == ';') ||
       ((&DAT_020b8e9f)[**(int **)(puVar4 + 0xc)] == '/')) {
      *(undefined4 *)(puVar4 + -0x34) = 0;
    }
    else {
      **(int **)(puVar4 + 0xc) = **(int **)(puVar4 + 0xc) + 1;
      (&DAT_020b8e9f)[**(int **)(puVar4 + 0xc)] = 0x3b;
    }
    iVar1 = **(int **)(puVar4 + 0xc);
    *(int *)(puVar4 + -0x30) = iVar1;
    DAT_0099a0cc = 1;
    while (0 < iVar1) {
      if ((&DAT_020b8e9f)[DAT_0099a0cc] == '\'') {
        (&DAT_020b8e9f)[DAT_0099a0cc] = 0x3a;
      }
      DAT_0099a0cc = DAT_0099a0cc + 1;
      *(int *)(puVar4 + -0x30) = *(int *)(puVar4 + -0x30) + -1;
      iVar1 = *(int *)(puVar4 + -0x30);
    }
    iVar1 = **(int **)(puVar4 + 0xc);
    *(int *)(puVar4 + -0x2c) = iVar1;
    DAT_0099a0cc = 1;
    while (0 < iVar1) {
      if ((&DAT_020b8e9f)[DAT_0099a0cc] == '[') {
        DAT_007cb2c0 = DAT_0099a0cc + -1;
      }
      if ((&DAT_020b8e9f)[DAT_0099a0cc] == ']') {
        DAT_007cb2c4 = DAT_0099a0cc;
        thunk_FUN_0041fab5(*(undefined4 *)(puVar4 + 0xc),&DAT_0099a0c8);
      }
      else {
        *(undefined4 *)(puVar4 + -0x28) = 0;
      }
      *(undefined4 *)(puVar4 + -0x24) = 0;
      DAT_0099a0cc = DAT_0099a0cc + 1;
      *(int *)(puVar4 + -0x2c) = *(int *)(puVar4 + -0x2c) + -1;
      iVar1 = *(int *)(puVar4 + -0x2c);
    }
    if ((_DAT_020b8ea0 & 0xffff) != 0x4353) {
      switch(DAT_01fbb700) {
      default:
        _DAT_01a1f4c4 = _DAT_020b8ea0;
        DAT_01a1f4c8 = _DAT_020b8ea4;
        DAT_01a1f4cc = DAT_020b8ea8;
        DAT_01a1f4d0 = _DAT_020b8eac;
        if (DAT_01fbb700 == 0) {
          thunk_FUN_00518b3f(*(undefined4 *)(puVar4 + 0xc));
        }
        *(undefined4 *)(puVar4 + -0x1c) = 0;
        return;
      case 1:
        iVar3 = 1;
        for (iVar1 = 1; iVar1 < 0x181; iVar1 = iVar1 + 1) {
          *(undefined1 *)((int)&DAT_01a1f4d0 + iVar1 + 3) = (&DAT_020b8e9f)[iVar3];
          iVar3 = iVar3 + 1;
        }
        *(undefined4 *)(puVar4 + -0x14) = 0;
        return;
      case 2:
        iVar3 = 1;
        break;
      case 3:
        iVar1 = 1;
        for (iVar3 = 1; iVar3 < 0x181; iVar3 = iVar3 + 1) {
          (&DAT_01a1f7d3)[iVar3] = (&DAT_020b8e9f)[iVar1];
          iVar1 = iVar1 + 1;
        }
        *(undefined4 *)(puVar4 + -0xc) = 0;
        return;
      case 4:
        iVar1 = 1;
        for (iVar3 = 1; iVar3 < 0x181; iVar3 = iVar3 + 1) {
          *(undefined1 *)(iVar3 + 0x1a1f953) = (&DAT_020b8e9f)[iVar1];
          iVar1 = iVar1 + 1;
        }
        *(undefined4 *)(puVar4 + -8) = 0;
        return;
      case 5:
        iVar1 = 1;
        for (iVar3 = 1; iVar3 < 0x181; iVar3 = iVar3 + 1) {
          *(undefined1 *)(iVar3 + 0x1a1fad3) = (&DAT_020b8e9f)[iVar1];
          iVar1 = iVar1 + 1;
        }
        *(undefined4 *)(puVar4 + -4) = 0;
        return;
      }
      for (iVar1 = 1; iVar1 < 0x181; iVar1 = iVar1 + 1) {
        (&DAT_01a1f653)[iVar1] = (&DAT_020b8e9f)[iVar3];
        iVar3 = iVar3 + 1;
      }
      *(undefined4 *)(puVar4 + -0x10) = 0;
      return;
    }
    *(undefined4 *)(puVar4 + -0x20) = 0;
    return;
  }
  *(undefined4 *)(puVar4 + -0x38) = 0;
LAB_0052ed33:
  thunk_FUN_0041c3b8(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
  if ((_DAT_020b90a0 & 0xff) == 0x5e) {
    *(undefined4 *)(puVar4 + -0x78) = 0;
    return;
  }
  goto LAB_0052ed5d;
}


