// FUN_00530dd8 @ 00530dd8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00530dd8(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x530e01);
  DAT_009ae4bc = 1;
  DAT_01fb8cc0 = 0;
  DAT_01a1f480 = 0;
  DAT_00791448 = ITEM_I + 1;
  DAT_01a14954 = 0x20202020;
  DAT_0078dec4 = 0xffffffff;
  if (-1 < DAT_02052740) {
    puVar4 = (undefined4 *)&DAT_020b90a0;
    puVar5 = (undefined4 *)&DAT_020b8ea0;
    for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    if (DAT_020b8ea0 != 0x5053) {
      puVar4 = (undefined4 *)&DAT_020b8ea0;
      puVar5 = &DAT_01a1f484;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    fVar1 = P2;
    DAT_0078dd60 = 1;
    *(undefined2 *)(puVar3 + -0xcc) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0xca) = (ushort)*(undefined4 *)(puVar3 + -0xcc) | 0xc00;
    *(int *)(puVar3 + -200) = (int)ROUND(fVar1);
    in_FPUControlWord = *(undefined2 *)(puVar3 + -0xcc);
    CUR_STAFF = *(int *)(puVar3 + -200);
    _DAT_0099a564 = -(uint)(DAT_0078d894 < _DAT_01fb8c64);
    goto LAB_00530f14;
  }
  DAT_0171b230 = 1;
  _DAT_0099a564 = -1;
  *(undefined4 *)(puVar3 + -0xa4) = 0;
LAB_0053106f:
  _DAT_0099a558 = 1;
  DAT_0099a554 = DAT_020b8e58;
  DAT_01a1fe18 = 1;
  if ((DAT_02052740 < 1) && (2 < DAT_01fbb700)) {
    thunk_FUN_00523c07(&DAT_007685d0);
  }
  if (DAT_01fb8c74 == 0) goto LAB_005310d3;
  if (DAT_01fbb700 != 0) goto LAB_005310d3;
  *(undefined4 *)(puVar3 + -0x84) = 0;
LAB_00531124:
  if (DAT_01fbb700 == 0) {
    if ((char)DAT_020b8ea0 != 'X') {
      if (DAT_020b8ea0 == 0x4353) {
        thunk_FUN_0053ec10();
        thunk_FUN_00549422();
        *(undefined4 *)(puVar3 + -0x78) = 0;
        goto LAB_005310d3;
      }
      if (P1 == f_999) {
        P1 = DAT_00796fd0;
        P2 = DAT_00796fd4;
      }
      DAT_00794850 = P1 - f_5;
      DAT_00796fd0 = P1;
      DAT_00796fd4 = P2;
      goto LAB_005311c9;
    }
    *(undefined4 *)(puVar3 + -0x7c) = 0;
    goto LAB_005316d5;
  }
LAB_005311c9:
  if (DAT_01fbb700 < 0) {
    *(undefined4 *)(puVar3 + -0x74) = 0;
LAB_00530f14:
    if (P2 <= f_0) {
      thunk_FUN_0052f485();
    }
    *(undefined2 *)(puVar3 + -0xcc) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0xca) = (ushort)*(undefined4 *)(puVar3 + -0xcc) | 0xc00;
    *(int *)(puVar3 + -200) = (int)ROUND(P2);
    in_FPUControlWord = *(undefined2 *)(puVar3 + -0xcc);
    DAT_0099a55c = *(int *)(puVar3 + -200);
    DAT_01fb8c60 = P2;
    if (MAX_STAFF < DAT_0099a55c) {
      *(undefined4 *)(puVar3 + -0xa0) = 0;
      goto LAB_00531705;
    }
    DAT_01f9a6f4 = 1;
    if (_DAT_01fb8c64 == f_0) {
      thunk_FUN_00468df8(&DAT_007685d8);
    }
    DAT_01e6790c = *(undefined4 *)(&DAT_01e67504 + DAT_0099a55c * 4);
    thunk_FUN_00525ae4();
    DAT_020b8e54 = ITEM_WORDS;
    DAT_01fbb700 = 0;
    DAT_020b8e58 = ITEM_I;
    DAT_01fb8c74 = 0;
    _DAT_01fb8c64 = f_999;
    *(undefined4 *)(puVar3 + -0x9c) = 0;
code_r0x0053101a:
    if (DAT_02052740 < 1) {
      if ((DAT_02052740 < 0) && (DAT_01fbb700 < 2)) {
        *(undefined4 *)(puVar3 + -0x8c) = 0;
      }
      else {
        draw_items();
        thunk_FUN_00549422();
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x90) = 0;
    }
    if (DAT_01fbb700 == 6) {
      *(undefined4 *)(puVar3 + -0x88) = 0;
LAB_00531297:
      if (DAT_02052740 <= DAT_02052748) {
        *(undefined4 *)(puVar3 + -0x3c) = 0;
        do {
          if (DAT_02052740 == -2) {
            *(undefined4 *)(puVar3 + -0x34) = 0;
            FUN_005f33c9(puVar3,0x53144d);
            FUN_005f34d1(puVar3,0x531468);
            *(undefined4 *)(puVar3 + -0x1c) = 0;
LAB_0053150b:
            DAT_0078b4e0 = 0x4c;
            DAT_0078b4e4 = 0x4a;
            thunk_FUN_004b80b7(&IP2,&IP2,&f_0,&DAT_00768554);
            *(undefined4 *)(puVar3 + -0x14) = 0;
            goto LAB_005316bb;
          }
          FUN_005f33c9(puVar3,0x5312db);
          FUN_005f34d1(puVar3,0x5312f6);
          thunk_FUN_00596140();
          thunk_FUN_0054946a(&DAT_020b90a0,0x200);
          thunk_FUN_00468df8(&DAT_00768560);
          DAT_0171b230 = 1;
          thunk_FUN_00549afb();
          DAT_020b8ea0 = CONCAT11(DAT_020b8ea0._1_1_,DAT_020b90a0);
          thunk_FUN_0054c768(&DAT_020b8ea0);
          DAT_0171b230 = 0;
          thunk_FUN_0054da52(&DAT_020b90a0,1);
          if ((char)DAT_020b8ea0 == 'A') {
            *(undefined4 *)(puVar3 + -0x30) = 0;
            goto LAB_0053147f;
          }
          if ((char)DAT_020b8ea0 == 'E') goto LAB_00531496;
          if ((char)DAT_020b8ea0 == 'L') {
            DAT_020b8ea0 = 0x4a4c;
          }
          if (((char)DAT_020b8ea0 == 'S') || ((char)DAT_020b8ea0 == 'L')) {
            *(undefined4 *)(puVar3 + -0x28) = 0;
LAB_005314e7:
            thunk_FUN_00526451();
            if (DAT_020b8ea0._1_1_ == 'J') goto LAB_0053150b;
            *(undefined4 *)(puVar3 + -0x18) = 0;
            goto LAB_005316bb;
          }
          if ((char)DAT_020b8ea0 == '\r') {
            DAT_020b8ea0 = CONCAT11(DAT_020b8ea0._1_1_,DAT_0076855c);
          }
          if (((char)DAT_020b8ea0 == 'X') || ((char)DAT_020b8ea0 == ';')) {
            *(undefined4 *)(puVar3 + -0x24) = 0;
            goto LAB_005314e7;
          }
          *(undefined4 *)(puVar3 + -0x20) = 0;
        } while( true );
      }
      input_store_items();
      thunk_FUN_00549422();
      *(undefined4 *)(puVar3 + -0x38) = 0;
      goto LAB_005316bb;
    }
    goto LAB_0053106f;
  }
  if ((2 < DAT_01fbb700) && ((char)DAT_020b8ea0 == 'G')) {
    *(undefined4 *)(puVar3 + -0x70) = 0;
    goto LAB_00531297;
  }
  if ((char)DAT_020b8ea0 == '^') {
    *(undefined4 *)(puVar3 + -0x6c) = 0;
    goto LAB_0053149d;
  }
  if ((char)DAT_020b8ea0 == '!') {
    ITEM_WORDS = DAT_020b8e54;
    ITEM_I = DAT_020b8e58;
    *(undefined4 *)(puVar3 + -0x68) = 0;
    goto LAB_005316bb;
  }
  if (2 < DAT_01fbb700) {
    if ((char)DAT_020b8ea0 == ';') {
      DAT_01fbb700 = DAT_01fbb700 + 1;
      if (DAT_01fbb700 != 6) {
        *(undefined4 *)(puVar3 + -0x60) = 0;
        goto LAB_005310d3;
      }
      *(undefined4 *)(puVar3 + -100) = 0;
      goto LAB_00531297;
    }
    if ((char)DAT_020b8ea0 == 'G') {
      DAT_01fbb700 = 6;
    }
  }
  switch(DAT_01fbb700) {
  case 1:
  case 5:
    break;
  case 2:
    ITEM_WORDS = DAT_020b8e54;
    ITEM_I = DAT_020b8e58;
    *(undefined4 *)(puVar3 + -0x48) = 0;
    break;
  case 3:
    uRam0099a548 = DAT_01fb8c80;
    *(undefined4 *)(puVar3 + -0x44) = 0;
    break;
  case 4:
    uRam0099a544 = DAT_01fb8c80;
    *(undefined4 *)(puVar3 + -0x40) = 0;
    break;
  default:
    thunk_FUN_00526042(&DAT_0099a564);
    if (DAT_01fbb700 == 899) {
      *(undefined4 *)(puVar3 + -0x5c) = 0;
      goto LAB_0053169b;
    }
    DAT_01fbb700 = 1;
    *(undefined4 *)(puVar3 + -0x58) = 0;
    goto LAB_0053106f;
  }
  func_0x004050dd(&DAT_0099a558,&DAT_0099a54c);
  if (_DAT_02052754 != 0) {
    *(undefined4 *)(puVar3 + -0x54) = 0;
    *(undefined4 *)(puVar3 + -0x10) = 0;
    *(undefined4 *)(puVar3 + -0xc) = 0;
    goto LAB_00531705;
  }
  if (DAT_02052740 <= DAT_02052748) {
    input_store_items();
  }
  DAT_01fbb700 = DAT_01fbb700 + 1;
  if (DAT_01fbb700 == **(int **)(puVar3 + 8)) {
    *(undefined4 *)(puVar3 + -0x50) = 0;
    return;
  }
  *(undefined4 *)(puVar3 + -0x4c) = 0;
  goto code_r0x0053101a;
LAB_00531496:
  *(undefined4 *)(puVar3 + -0x2c) = 0;
LAB_0053149d:
  while( true ) {
    DAT_01fbb700 = -1;
    DAT_02052740 = -1;
    ITEM_WORDS = DAT_020b8e54;
    ITEM_I = DAT_020b8e58;
    *(undefined4 *)(puVar3 + -8) = 0;
LAB_005310d3:
    FUN_0053174c(&DAT_0099a550,&DAT_0099a54c);
    if (DAT_020b90a0 != '^') break;
    *(undefined4 *)(puVar3 + -0x80) = 0;
    DAT_0099a554 = thunk_FUN_005956b0();
    if (DAT_0099a554 == 0) goto LAB_0053147f;
    *(undefined4 *)(puVar3 + -4) = 0;
  }
  goto LAB_00531124;
LAB_0053147f:
  thunk_FUN_0052f62e(&DAT_007685d0);
LAB_0053169b:
  DAT_0078b378 = 0;
  DAT_0078b4ec = 0;
  DAT_01b12c70 = 0;
  DAT_0205274c = 0;
LAB_005316bb:
  DAT_01fbb700 = 0;
  DAT_0078d890 = 0;
  draw_items();
  thunk_FUN_00549422();
LAB_005316d5:
  thunk_FUN_00468df8(&DAT_00768550);
  thunk_FUN_0054943a();
  thunk_FUN_0054946a("*** Leaving input ***",0x16);
  DAT_0171b230 = 0;
LAB_00531705:
  DAT_009ae4bc = 0;
  DAT_01fbb700 = 0;
  DAT_01f9a6f4 = 0;
  **(undefined4 **)(puVar3 + 8) = 0;
  DAT_02052740 = 0;
  return;
}


