// FUN_00524c4a @ 00524c4a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524c4a(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar2 = &stack0xfffffffc;
  DAT_01fbb710 = 0;
  DAT_01fbb708 = 0;
  if ((&DAT_020b8e9f)[*param_1] == ' ') {
    FUN_00526ec4(&DAT_0094e6dc,param_1,&DAT_01fbb704);
  }
  DAT_01fbb714 = 0;
  DAT_01fbb70c = 1;
LAB_00524cae:
  DAT_01fbb704 = **(int **)(puVar2 + 8);
  iVar1 = (DAT_0078dd64 - DAT_01fbb704) + 1;
  *(int *)(puVar2 + -0x8c) = iVar1;
  DAT_0094e6d8 = DAT_01fbb704;
  do {
    if (iVar1 < 1) {
LAB_005253c4:
      FUN_005259e5(*(undefined4 *)(puVar2 + 8));
      *(undefined4 *)(puVar2 + -0x1c) = 0;
      return;
    }
    DAT_0094e6e0 = (&DAT_020b8e9f)[DAT_01fbb704];
    if (DAT_0094e6e0 == ',') {
      (&DAT_020b8e9f)[DAT_01fbb704] = 0x2f;
      *(undefined4 *)(puVar2 + -0x84) = 0;
LAB_005252e3:
      if (0 < DAT_01fbb718) {
        DAT_01fbb718 = 2;
      }
      if (DAT_01fbb710 == -999) {
        *(undefined4 *)(puVar2 + -0x14) = 0;
        return;
      }
LAB_0052530f:
      DAT_0094e6dc = (uint)(byte)(&DAT_020b8e9f)[**(int **)(puVar2 + 8)];
      if ((DAT_0094e6dc != 0x2f) && (DAT_0094e6dc != 0x3b)) {
        if (DAT_01fbb700 < 4) {
          if (DAT_01fbb700 == 1) {
            thunk_FUN_004e2cc8(*(undefined4 *)(puVar2 + 8),&DAT_0094e6dc);
            *(undefined4 *)(puVar2 + -0xc) = 0;
            return;
          }
          if (DAT_01fbb700 == 2) {
            thunk_FUN_004d9ea0(*(undefined4 *)(puVar2 + 8),&DAT_0094e6dc);
            *(undefined4 *)(puVar2 + -8) = 0;
            return;
          }
          if (DAT_01fbb700 == 3) {
            thunk_FUN_004daeb2(*(undefined4 *)(puVar2 + 8),&DAT_0094e6dc);
            *(undefined4 *)(puVar2 + -4) = 0;
            return;
          }
        }
        else if (DAT_01fbb700 < 6) {
          thunk_FUN_004da9c3(*(undefined4 *)(puVar2 + 8));
          return;
        }
      }
      *(undefined4 *)(puVar2 + -0x10) = 0;
      DAT_01fbb710 = 0xfffffffe;
      return;
    }
    *(undefined4 *)(puVar2 + -0x88) = 0;
    if (DAT_0094e6e0 == '/') {
      *(undefined4 *)(puVar2 + -0x80) = 0;
      goto LAB_005252e3;
    }
    if (DAT_0094e6e0 == ';') {
      *(undefined4 *)(puVar2 + -0x7c) = 0;
      if ((DAT_0078d888 == 0) || (DAT_01fbb714 == 1)) {
        *(undefined4 *)(puVar2 + -0x18) = 0;
      }
      else {
        DAT_01fbb714 = 1;
      }
      **(undefined4 **)(puVar2 + 0xc) = 1;
      goto LAB_005252e3;
    }
    if (DAT_0094e6e0 == '[') break;
    *(undefined4 *)(puVar2 + -0x78) = 0;
    if (DAT_0094e6e0 == ']') {
      (&DAT_020b8e9f)[DAT_01fbb704] = 0x20;
      if (DAT_01fbb704 == **(int **)(puVar2 + 8)) {
        **(int **)(puVar2 + 8) = **(int **)(puVar2 + 8) + 1;
      }
      *(undefined4 *)(puVar2 + -0x6c) = 0;
    }
    else {
      *(undefined4 *)(puVar2 + -0x70) = 0;
      if (DAT_0094e6e0 == '@') {
        push_words(&DAT_00767d80,&DAT_020b8ea0);
        *(int *)(puVar2 + -0xb8) = DAT_01fbb704 + 4;
        thunk_FUN_00420e60(&DAT_020b8ea0,0x200,&DAT_020b90a0,0x200,puVar2 + -0xb8,&DAT_01fbb704);
        pop_words(&DAT_00767d80,&DAT_020b8ea0);
        if (*(char *)((int)&DAT_020b8ea0 + DAT_01fbb704) == '-') {
          FUN_00526f23(&DAT_01fbb704);
        }
        if (*(char *)((int)&DAT_020b8ea0 + DAT_01fbb704) == '$') {
          FUN_00527276(&DAT_01fbb704);
        }
        if (P2 == f_0) {
          *(undefined4 *)(puVar2 + -100) = 0;
        }
        else if (DAT_01fbb700 < 3) {
          *(undefined4 *)(puVar2 + -0x60) = 0;
          FUN_0052789c();
        }
        else {
          thunk_FUN_004e5ea6();
          *(undefined4 *)(puVar2 + -0x5c) = 0;
        }
        thunk_FUN_0054cb15(&DAT_007cb2d0,0x100,&DAT_0094e6d4,&DAT_00767d7c);
        if (*(char *)((int)&DAT_007cb2cc + DAT_0094e6d4 + 3) == ']') {
          *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094e6d4 + 3) = 0x2f;
        }
        DAT_0094e6d0 = 0;
        iVar1 = (DAT_0078dd64 - DAT_01fbb704) + 1;
        *(int *)(puVar2 + -0x58) = iVar1;
        DAT_0094e6cc = DAT_01fbb704;
        goto joined_r0x00525076;
      }
      *(undefined4 *)(puVar2 + -0x68) = 0;
      if ((DAT_0094e6e0 == 'X') || (DAT_0094e6e0 == 'Z')) {
        if ((DAT_01fbb710 != -999) && (DAT_01fbb700 != 3)) {
          DAT_0094e6bc = (uint)*(byte *)((int)&DAT_020b8ea0 + DAT_01fbb704);
          if ((DAT_0094e6bc != 0x5b) && (0x39 < DAT_0094e6bc || DAT_0094e6bc < 0x31)) {
            *(undefined4 *)(puVar2 + -0x30) = 0;
            goto LAB_005253c4;
          }
          *(undefined4 *)(puVar2 + -0x34) = 0;
          goto LAB_00524ee3;
        }
        *(undefined4 *)(puVar2 + -0x38) = 0;
      }
      else {
        *(undefined4 *)(puVar2 + -0x3c) = 0;
      }
      if ((2 < DAT_01fbb700) && (DAT_0094e6e0 == '=')) {
        (&DAT_020b8e9f)[DAT_01fbb704] = 0x2b;
      }
      if (DAT_01fbb700 == 1) {
        if ((DAT_0094e6e0 == ':') || (DAT_00796d2c == DAT_0094e6e0)) {
          if (DAT_01fbb718 == 0) {
            DAT_01fbb718 = -1;
          }
          *(undefined4 *)(puVar2 + -0x24) = 0;
          goto LAB_0052530f;
        }
        *(undefined4 *)(puVar2 + -0x28) = 0;
      }
      else {
        *(undefined4 *)(puVar2 + -0x2c) = 0;
      }
    }
LAB_00524ee3:
    *(undefined4 *)(puVar2 + -0x20) = 0;
    DAT_01fbb704 = DAT_01fbb704 + 1;
    *(int *)(puVar2 + -0x8c) = *(int *)(puVar2 + -0x8c) + -1;
    iVar1 = *(int *)(puVar2 + -0x8c);
  } while( true );
  DAT_007cb2c0 = DAT_01fbb704 + -1;
  **(int **)(puVar2 + 8) = DAT_01fbb704 + 1;
  *(undefined4 *)(puVar2 + -0x74) = 0;
  goto LAB_00524cae;
joined_r0x00525076:
  if (iVar1 < 1) goto LAB_005250d4;
  DAT_0094e6d0 = DAT_0094e6d0 + 1;
  if (((&DAT_020b8e9f)[DAT_0094e6cc] == '/') || ((&DAT_020b8e9f)[DAT_0094e6cc] == ';')) {
    *(undefined4 *)(puVar2 + -0x54) = 0;
    goto LAB_005250d4;
  }
  DAT_0094e6cc = DAT_0094e6cc + 1;
  *(int *)(puVar2 + -0x58) = *(int *)(puVar2 + -0x58) + -1;
  iVar1 = *(int *)(puVar2 + -0x58);
  goto joined_r0x00525076;
LAB_005250d4:
  DAT_0094e6c8 = (DAT_0094e6d4 - DAT_0094e6d0) + -3;
  iVar1 = ((DAT_0094e6cc - DAT_0078dd64) + -1) / -1;
  *(int *)(puVar2 + -0x50) = iVar1;
  DAT_0094e6c4 = DAT_0078dd64;
  while (0 < iVar1) {
    (&DAT_020b8e9f)[DAT_0094e6c8 + DAT_0094e6c4] = (&DAT_020b8e9f)[DAT_0094e6c4];
    _DAT_0094e6c0 = (float)DAT_0094e6c4;
    *(undefined4 *)(puVar2 + -0x4c) = 0;
    DAT_0094e6c4 = DAT_0094e6c4 + -1;
    *(int *)(puVar2 + -0x50) = *(int *)(puVar2 + -0x50) + -1;
    iVar1 = *(int *)(puVar2 + -0x50);
  }
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  puVar4 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar1 = DAT_0094e6d4 + -4;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(puVar2 + -0xb0) = iVar1;
  *(undefined4 *)(puVar2 + -0xb4) = 2;
  FUN_005f46bc(puVar2,0x5251ea);
  FUN_005f34d1(puVar2,0x525200);
  DAT_0078dd64 = DAT_0094e6c8 + DAT_0078dd64;
  **(int **)(puVar2 + 8) = DAT_01fbb704;
  *(undefined4 *)(puVar2 + -0x48) = 0;
  goto LAB_00524cae;
}


