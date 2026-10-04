// FUN_004f4bb0 @ 004f4bb0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004f4bb0(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  int local_40;
  
  puVar2 = param_1;
  puVar3 = &DAT_008d1b80;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *param_4 = 0;
  local_40 = 0x7f;
  DAT_008d1b7c = 2;
  do {
    if (*(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 3) == '.') break;
    DAT_008d1b7c = DAT_008d1b7c + 1;
    local_40 = local_40 + -1;
  } while (0 < local_40);
  DAT_008d1b78 = (int)*(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2);
  DAT_008d1b7c = DAT_008d1b7c + -1;
  fVar4 = (float10)FUN_004f4f54(&DAT_008d1b80,0x80,param_3,&DAT_008d1b7c);
  if (fVar4 != (float10)f_0) {
    *param_4 = 1;
    return;
  }
  if (*param_3 < 0) {
    if (DAT_008d1b78 == 0x30) {
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 3) = 0x39;
    }
    else {
      if (DAT_008d1b78 != 0x41) {
        *(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 3) = (char)DAT_008d1b78 + -1;
        goto LAB_004f4f3b;
      }
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 3) = 0x5a;
    }
    DAT_008d1b78 = (int)*(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2);
    if (DAT_008d1b78 == 0x30) {
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) = 0x39;
    }
    else {
      if (DAT_008d1b78 != 0x41) {
        if (1 < DAT_008d1b7c) {
          *(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) =
               *(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) + -1;
        }
        goto LAB_004f4f3b;
      }
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) = 0x5a;
    }
    if (1 < DAT_008d1b7c) {
      iVar1 = (int)*(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 1);
      if (iVar1 == 0x30) {
        DAT_008d1b78 = 0x39;
      }
      else if (iVar1 == 0x41) {
        DAT_008d1b78 = 0x5a;
      }
      else {
        DAT_008d1b78 = iVar1 + -1;
      }
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 1) = (undefined1)DAT_008d1b78;
    }
  }
  else {
    if (DAT_008d1b78 == 0x39) {
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 3) = 0x30;
    }
    else {
      if (DAT_008d1b78 != 0x5a) {
        *(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 3) = (char)DAT_008d1b78 + '\x01';
        goto LAB_004f4f3b;
      }
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 3) = 0x41;
    }
    DAT_008d1b78 = (int)*(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2);
    if (DAT_008d1b78 == 0x39) {
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) = 0x30;
    }
    else {
      if (DAT_008d1b78 != 0x5a) {
        if (1 < DAT_008d1b7c) {
          *(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) =
               *(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) + '\x01';
        }
        goto LAB_004f4f3b;
      }
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 2) = 0x41;
    }
    if (1 < DAT_008d1b7c) {
      iVar1 = (int)*(char *)((int)&DAT_008d1b7c + DAT_008d1b7c + 1);
      if (iVar1 == 0x39) {
        DAT_008d1b78 = 0x30;
      }
      else if (iVar1 == 0x5a) {
        DAT_008d1b78 = 0x41;
      }
      else {
        DAT_008d1b78 = iVar1 + 1;
      }
      *(undefined1 *)((int)&DAT_008d1b7c + DAT_008d1b7c + 1) = (undefined1)DAT_008d1b78;
    }
  }
LAB_004f4f3b:
  puVar2 = &DAT_008d1b80;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


