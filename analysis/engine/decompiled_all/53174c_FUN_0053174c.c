// FUN_0053174c @ 0053174c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053174c(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar4 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x531775);
  if (-1 < DAT_01fbb700) {
    *(undefined4 *)(puVar4 + -0xd0) = 0;
    if (0 < DAT_02052740) goto LAB_00531b47;
    *(undefined4 *)(puVar4 + -0xbc) = 0;
    goto LAB_00531ce9;
  }
  FUN_005f33c9(puVar4,0x5317c6);
  FUN_005f34d1(puVar4,0x5317e1);
  FUN_005f33c9(puVar4,0x531803);
  FUN_005f34d1(puVar4,0x53181e);
  puVar5 = (undefined4 *)&DAT_020b90a0;
  puVar7 = (undefined4 *)&DAT_007a0b7c;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  thunk_FUN_00468df8(&DAT_00768748);
  thunk_FUN_0054cb15(&DAT_020b8ea0,1,*(undefined4 *)(puVar4 + 0xc),&DAT_00768744);
  *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar4 + 0xc)) = 0;
  puVar5 = (undefined4 *)&DAT_020b8ea0;
  puVar7 = &DAT_009ae2bc;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  if (DAT_02052740 == -2) {
    *(undefined4 *)(puVar4 + -0xcc) = 0;
  }
  else {
    iVar2 = thunk_FUN_0059c140();
    if (iVar2 == 2) {
      _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_0076873c);
      *(undefined4 *)(puVar4 + -0xc4) = 0;
LAB_0053194d:
      do {
        if (_DAT_020b90a0 != 0x4944494d) {
          if ((_DAT_020b90a0 & 0xff) == 0x5e) {
            *(undefined4 *)(puVar4 + -0x68) = 0;
            return;
          }
          puVar5 = (undefined4 *)&DAT_020b8ea0;
          puVar7 = (undefined4 *)&DAT_020b90a0;
          for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          DAT_0171b230 = 0;
          **(undefined4 **)(puVar4 + 8) = 0;
          *(undefined4 *)(puVar4 + -100) = 0;
LAB_00531a30:
          do {
            if ((_DAT_020b8ea0 & 0xff) == 0x25) {
              thunk_FUN_005253e2();
              if (DAT_02052740 < 0) goto LAB_00532019;
              if (DAT_02052740 == 0) goto LAB_00532234;
            }
            else {
              if ((_DAT_020b8ea0 & 0xff) != 0x20) {
                *(undefined4 *)(puVar4 + -0x58) = 0;
                goto LAB_005324fb;
              }
              if (DAT_01fbb700 == 0) {
                _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007685e4);
                *(undefined4 *)(puVar4 + -0x50) = 0;
                goto LAB_005324fb;
              }
              *(undefined4 *)(puVar4 + -0x54) = 0;
              *(undefined4 *)(puVar4 + -0x4c) = 0x17f;
              DAT_0078b4e0 = 2;
              do {
                if ((&DAT_020b8e9f)[DAT_0078b4e0] != ' ') {
                  *(undefined4 *)(puVar4 + -0x48) = 0;
                  while (thunk_FUN_0054c5f8(0x20b8ea1,1,&DAT_020b8ea0,1,&DAT_00768724),
                        (_DAT_020b8ea0 & 0xff) == 0x20) {
                    *(undefined4 *)(puVar4 + -0x3c) = 0;
                  }
                  goto LAB_005324fb;
                }
                DAT_0078b4e0 = DAT_0078b4e0 + 1;
                *(int *)(puVar4 + -0x4c) = *(int *)(puVar4 + -0x4c) + -1;
              } while (0 < *(int *)(puVar4 + -0x4c));
              if (DAT_02052740 < 1) {
                *(undefined4 *)(puVar4 + -0x44) = 0;
                goto LAB_00532234;
              }
              thunk_FUN_00549422();
              *(undefined4 *)(puVar4 + -0x40) = 0;
            }
LAB_00531b47:
            *(undefined4 *)(puVar4 + -0xf0) = 0;
            iVar2 = FUN_005fdbd0(puVar4 + -0xf0,DAT_02052740,0x784ff02,&DAT_00768720,0,&DAT_00797020
                                );
            *(int *)(puVar4 + -0xb8) = iVar2;
            if (iVar2 == 0) {
              *(undefined4 *)(puVar4 + -0xf4) = 0x180;
              DAT_0099a6ac = 1;
              do {
                *(undefined4 *)(puVar4 + -0x108) = 1;
                *(undefined1 **)(puVar4 + -0x104) = &DAT_020b8e9f + DAT_0099a6ac;
                *(undefined4 *)(puVar4 + -0x100) = 1;
                iVar2 = FUN_005fe110(puVar4 + -0xf0,&DAT_0076871c,puVar4 + -0x108);
                *(int *)(puVar4 + -0xb8) = iVar2;
                if (iVar2 != 0) goto LAB_00531c4b;
                DAT_0099a6ac = DAT_0099a6ac + 1;
                *(int *)(puVar4 + -0xf4) = *(int *)(puVar4 + -0xf4) + -1;
              } while (0 < *(int *)(puVar4 + -0xf4));
              uVar3 = FUN_005fe110(puVar4 + -0xf0,&DAT_00768718,0);
              *(undefined4 *)(puVar4 + -0xb8) = uVar3;
            }
LAB_00531c4b:
            if (*(int *)(puVar4 + -0xb8) == -1) goto LAB_00531c63;
            *(undefined4 *)(puVar4 + -0xb4) = 0;
          } while( true );
        }
        *(undefined4 *)(puVar4 + -0x6c) = 0;
        if (DAT_019c7e48 != 0) {
          thunk_FUN_0054d831("No MIDI for input.",0x13);
          *(undefined4 *)(puVar4 + -0x60) = 0;
          goto LAB_00531ce9;
        }
        DAT_0099a6a8 = ITEM_WORDS;
        DAT_01fb8c90 = ITEM_I;
        if ((&DAT_020b8e9f)[DAT_0078d938] == ';') goto LAB_00531a30;
        thunk_FUN_0041c3b8(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
        *(undefined4 *)(puVar4 + -0x5c) = 0;
      } while( true );
    }
    *(undefined4 *)(puVar4 + -200) = 0;
  }
  puVar5 = &DAT_009ae2bc;
  puVar7 = (undefined4 *)&DAT_020b8ea0;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  FUN_005f34d1(puVar4,0x5318e8);
  DAT_01a1f480 = 0;
  puVar5 = (undefined4 *)&DAT_020b8ea0;
  puVar7 = &DAT_01a1f484;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  thunk_FUN_00518b3f(&DAT_00768740);
  DAT_0099a6b0 = 2;
  *(undefined4 *)(puVar4 + -0xc0) = 0;
  return;
LAB_00531c63:
  *(undefined4 *)(puVar4 + -0xf0) = 0;
  FUN_005f7950(puVar4 + -0xf0,DAT_02052740,0x784ff00,&DAT_00768714,0);
  DAT_02052740 = 0;
  DAT_01fbb700 = DAT_01fbb700 + -1;
  if (0 < DAT_01fbb700) {
    input_store_items();
  }
  DAT_01fbb700 = DAT_01fbb700 + 1;
  FUN_005f34d1(puVar4,0x531ce5);
LAB_00531ce9:
  if (DAT_01fbb700 == 0) {
    FUN_005f33c9(puVar4,0x531d10);
    FUN_005f34d1(puVar4,0x531d2b);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_007685d8);
    }
  }
  else if (DAT_01fbb700 == 1) {
    FUN_005f33c9(puVar4,0x531d7a);
    FUN_005f34d1(puVar4,0x531d95);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_007686b4);
    }
  }
  else if (DAT_01fbb700 == 2) {
    if (DAT_01fb8c88 == 0) {
      thunk_FUN_0054d831("*** No notes/rests given. ***",0x1e);
      _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_0076873c);
      *(undefined4 *)(puVar4 + -0xac) = 0;
      return;
    }
    FUN_005f33c9(puVar4,0x531e21);
    FUN_005f34d1(puVar4,0x531e3c);
    *(undefined4 *)(puVar4 + -0xf0) = 0;
    *(undefined4 *)(puVar4 + -0x108) = 3;
    *(undefined4 *)(puVar4 + -0x104) = 0x20b90a6;
    *(int **)(puVar4 + -0x100) = &DAT_01fb8c88;
    FUN_005f34f0(puVar4 + -0xf0,0x784ff00,&DAT_00768674,puVar4 + -0x108,&DAT_00797034);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_00768670);
    }
  }
  else if (DAT_01fbb700 == 3) {
    if (f_256 < _DAT_01fb8c64) {
      thunk_FUN_00524678();
    }
    FUN_005f33c9(puVar4,0x531efa);
    FUN_005f34d1(puVar4,0x531f15);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_00768638);
    }
  }
  else if (DAT_01fbb700 == 4) {
    FUN_005f33c9(puVar4,0x531f64);
    FUN_005f34d1(puVar4,0x531f7f);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_00768610);
    }
  }
  else if (DAT_01fbb700 == 5) {
    FUN_005f33c9(puVar4,0x531fc7);
    FUN_005f34d1(puVar4,0x531fe2);
    if (-1 < DAT_02052740) {
      thunk_FUN_00468df8(&DAT_007685e8);
    }
  }
  if (DAT_02052740 < 0) {
LAB_00532019:
    do {
      switch(DAT_01fbb700) {
      default:
        FUN_005f33c9(puVar4,0x53217e);
        FUN_005f34d1(puVar4,0x532199);
        *(undefined4 *)(puVar4 + -0xa0) = 0;
        break;
      case 1:
        iVar6 = 1;
        for (iVar2 = 1; iVar2 < 0x181; iVar2 = iVar2 + 1) {
          (&DAT_020b8e9f)[iVar6] = *(undefined1 *)((int)&DAT_01a1f4d0 + iVar2 + 3);
          iVar6 = iVar6 + 1;
        }
        *(undefined4 *)(puVar4 + -0x9c) = 0;
        break;
      case 2:
        iVar6 = 1;
        for (iVar2 = 1; iVar2 < 0x181; iVar2 = iVar2 + 1) {
          (&DAT_020b8e9f)[iVar6] = (&DAT_01a1f653)[iVar2];
          iVar6 = iVar6 + 1;
        }
        *(undefined4 *)(puVar4 + -0x98) = 0;
        break;
      case 3:
        iVar2 = 1;
        for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
          (&DAT_020b8e9f)[iVar2] = (&DAT_01a1f7d3)[iVar6];
          iVar2 = iVar2 + 1;
        }
        *(undefined4 *)(puVar4 + -0x94) = 0;
        break;
      case 4:
        iVar6 = 1;
        for (iVar2 = 1; iVar2 < 0x181; iVar2 = iVar2 + 1) {
          (&DAT_020b8e9f)[iVar6] = *(undefined1 *)(iVar2 + 0x1a1f953);
          iVar6 = iVar6 + 1;
        }
        *(undefined4 *)(puVar4 + -0x90) = 0;
        break;
      case 5:
        iVar2 = 1;
        for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
          (&DAT_020b8e9f)[iVar2] = *(undefined1 *)(iVar6 + 0x1a1fad3);
          iVar2 = iVar2 + 1;
        }
      }
      DAT_0099a6b0 = DAT_0099a6b0 + 1;
      if ((char)DAT_020b8ea0 == '\0') {
        FUN_005f34d1(puVar4,0x53221e);
        DAT_02052740 = 0;
        *(undefined4 *)(puVar4 + -0x8c) = 0;
        goto LAB_00532234;
      }
      if ((_DAT_020b8ea0 & 0xff) != 0x25) goto LAB_0053240e;
      thunk_FUN_0054943a();
      thunk_FUN_0054991a(&DAT_020b90a0,0x200);
      thunk_FUN_005253e2();
      *(undefined4 *)(puVar4 + -0x88) = 0;
    } while( true );
  }
  *(undefined4 *)(puVar4 + -0xa4) = 0;
LAB_00532234:
  DAT_0171b230 = 1;
  if (DAT_01fbb700 == 1) {
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    FUN_005f34d1(puVar4,0x532276);
    FUN_005f34d1(puVar4,0x532297);
    thunk_FUN_00596140();
    thunk_FUN_0041c3b8(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
  }
  else if (DAT_01fbb700 == 2) {
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    thunk_FUN_00596140();
    FUN_005f34d1(puVar4,0x5322ec);
    FUN_005f34d1(puVar4,0x53230d);
    thunk_FUN_00422d98(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
  }
  else if (DAT_01fbb700 == 3) {
    FUN_005f34d1(puVar4,0x532347);
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    thunk_FUN_00596140();
    thunk_FUN_00426950(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
  }
  else if (DAT_01fbb700 < 4) {
    FUN_005f34d1(puVar4,0x5323de);
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    thunk_FUN_00596140();
    thunk_FUN_0054991a(&DAT_020b90a0,1);
  }
  else {
    FUN_005f34d1(puVar4,0x532397);
    thunk_FUN_0054946a(&DAT_020b90a0,1);
    thunk_FUN_00596140();
    thunk_FUN_00427c68(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
  }
  goto LAB_0053194d;
LAB_0053240e:
  puVar5 = (undefined4 *)&DAT_020b90a0;
  puVar7 = (undefined4 *)&DAT_007a0b7c;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  thunk_FUN_0054cb15(&DAT_020b8ea0,1,*(undefined4 *)(puVar4 + 0xc),&DAT_00768744);
  *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar4 + 0xc)) = 0;
  puVar5 = (undefined4 *)&DAT_020b8ea0;
  puVar7 = &DAT_009ae2bc;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  if (DAT_02052740 == -2) {
    *(undefined4 *)(puVar4 + -0x84) = 0;
    goto LAB_0053248b;
  }
  iVar2 = thunk_FUN_0059c140();
  if (iVar2 != 2) {
    *(undefined4 *)(puVar4 + -0x80) = 0;
LAB_0053248b:
    puVar5 = &DAT_009ae2bc;
    puVar7 = (undefined4 *)&DAT_020b8ea0;
    for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_005f34d1(puVar4,0x5324bb);
    *(undefined4 *)(puVar4 + -0x78) = 0;
LAB_005324fb:
    thunk_FUN_0054c6b5(&DAT_020b8ea0,0x200,*(undefined4 *)(puVar4 + 0xc),&DAT_0078b4e0,&DAT_0078b4e4
                      );
    if (DAT_01fbb700 < 1) {
      *(undefined4 *)(puVar4 + -0x38) = 0;
      iVar6 = DAT_007cb2c4;
    }
    else {
      if (((&DAT_020b8e9f)[**(int **)(puVar4 + 0xc)] == ';') ||
         ((&DAT_020b8e9f)[**(int **)(puVar4 + 0xc)] == '/')) {
        *(undefined4 *)(puVar4 + -0x34) = 0;
      }
      else {
        **(int **)(puVar4 + 0xc) = **(int **)(puVar4 + 0xc) + 1;
        (&DAT_020b8e9f)[**(int **)(puVar4 + 0xc)] = 0x3b;
      }
      iVar2 = **(int **)(puVar4 + 0xc);
      *(int *)(puVar4 + -0x30) = iVar2;
      DAT_0099a6a4 = 1;
      while (0 < iVar2) {
        if ((&DAT_020b8e9f)[DAT_0099a6a4] == '\'') {
          (&DAT_020b8e9f)[DAT_0099a6a4] = 0x3a;
        }
        DAT_0099a6a4 = DAT_0099a6a4 + 1;
        *(int *)(puVar4 + -0x30) = *(int *)(puVar4 + -0x30) + -1;
        iVar2 = *(int *)(puVar4 + -0x30);
      }
      iVar2 = **(int **)(puVar4 + 0xc);
      *(int *)(puVar4 + -0x2c) = iVar2;
      DAT_0099a6a4 = 1;
      iVar1 = DAT_0099a6a4;
      iVar6 = DAT_007cb2c4;
      while (DAT_007cb2c4 = iVar1, DAT_0099a6a4 = DAT_007cb2c4, 0 < iVar2) {
        if ((&DAT_020b8e9f)[DAT_007cb2c4] == '[') {
          DAT_007cb2c0 = DAT_007cb2c4 + -1;
        }
        if ((&DAT_020b8e9f)[DAT_007cb2c4] == ']') {
          thunk_FUN_0041fab5(*(undefined4 *)(puVar4 + 0xc),&DAT_0099a6a0);
          iVar6 = DAT_007cb2c4;
        }
        else {
          *(undefined4 *)(puVar4 + -0x28) = 0;
        }
        DAT_007cb2c4 = iVar6;
        *(undefined4 *)(puVar4 + -0x24) = 0;
        *(int *)(puVar4 + -0x2c) = *(int *)(puVar4 + -0x2c) + -1;
        iVar1 = DAT_0099a6a4 + 1;
        iVar6 = DAT_007cb2c4;
        iVar2 = *(int *)(puVar4 + -0x2c);
      }
    }
    DAT_007cb2c4 = iVar6;
    if ((_DAT_020b8ea0 & 0xffff) == 0x4353) {
      *(undefined4 *)(puVar4 + -0x20) = 0;
    }
    else {
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
        break;
      case 1:
        iVar6 = 1;
        for (iVar2 = 1; iVar2 < 0x181; iVar2 = iVar2 + 1) {
          *(undefined1 *)((int)&DAT_01a1f4d0 + iVar2 + 3) = (&DAT_020b8e9f)[iVar6];
          iVar6 = iVar6 + 1;
        }
        *(undefined4 *)(puVar4 + -0x14) = 0;
        break;
      case 2:
        iVar6 = 1;
        for (iVar2 = 1; iVar2 < 0x181; iVar2 = iVar2 + 1) {
          (&DAT_01a1f653)[iVar2] = (&DAT_020b8e9f)[iVar6];
          iVar6 = iVar6 + 1;
        }
        *(undefined4 *)(puVar4 + -0x10) = 0;
        break;
      case 3:
        iVar2 = 1;
        for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
          (&DAT_01a1f7d3)[iVar6] = (&DAT_020b8e9f)[iVar2];
          iVar2 = iVar2 + 1;
        }
        *(undefined4 *)(puVar4 + -0xc) = 0;
        break;
      case 4:
        iVar2 = 1;
        for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
          *(undefined1 *)(iVar6 + 0x1a1f953) = (&DAT_020b8e9f)[iVar2];
          iVar2 = iVar2 + 1;
        }
        *(undefined4 *)(puVar4 + -8) = 0;
        break;
      case 5:
        iVar2 = 1;
        for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
          *(undefined1 *)(iVar6 + 0x1a1fad3) = (&DAT_020b8e9f)[iVar2];
          iVar2 = iVar2 + 1;
        }
        *(undefined4 *)(puVar4 + -4) = 0;
      }
    }
    return;
  }
  _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_0076873c);
  *(undefined4 *)(puVar4 + -0x7c) = 0;
  goto LAB_0053194d;
}


