// FUN_004f4889 @ 004f4889 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004f4889(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined1 *puVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  if (*param_3 == 0) {
    *param_3 = 1;
  }
  thunk_FUN_0054c6b5(param_1,param_2,&DAT_008d1b70,&DAT_008d1b6c,&DAT_008d1b68);
  iVar4 = FUN_005f4660(0x20);
  if (iVar4 != 0) {
    thunk_FUN_0054d831("** NAME is blank. ***",0x15);
    return;
  }
  do {
    FUN_005f46bc(puVar5,0x4f4931);
    FUN_005f34d1(puVar5,0x4f4947);
    iVar4 = FUN_00606850(puVar5,0x4f4969);
    DAT_008d1b64 = iVar4 + 1;
    if (DAT_008d1b64 == 0) {
      DAT_008d1b64 = DAT_008d1b70 + 1;
    }
    while( true ) {
      while( true ) {
        while( true ) {
          iVar4 = DAT_008d1b64 + -1;
          if (iVar4 < 1) {
            *(undefined4 *)(puVar5 + -0x2c) = 0;
            DAT_008d1b64 = iVar4;
            return;
          }
          if (0 < **(int **)(puVar5 + 0x10)) break;
          if ((&DAT_020b909e)[DAT_008d1b64] == 'A') {
            puVar1 = &DAT_020b909e + DAT_008d1b64;
            DAT_008d1b64 = iVar4;
            *puVar1 = 0x5a;
            *(undefined4 *)(puVar5 + -0x1c) = 0;
          }
          else {
            if ((&DAT_020b909e)[DAT_008d1b64] != '0') goto LAB_004f4a84;
            puVar1 = &DAT_020b909e + DAT_008d1b64;
            DAT_008d1b64 = iVar4;
            *puVar1 = 0x39;
            *(undefined4 *)(puVar5 + -0x18) = 0;
          }
        }
        if ((&DAT_020b909e)[DAT_008d1b64] != 'Z') break;
        puVar1 = &DAT_020b909e + DAT_008d1b64;
        DAT_008d1b64 = iVar4;
        *puVar1 = 0x41;
        *(undefined4 *)(puVar5 + -0x28) = 0;
      }
      if ((&DAT_020b909e)[DAT_008d1b64] != '9') break;
      puVar1 = &DAT_020b909e + DAT_008d1b64;
      DAT_008d1b64 = iVar4;
      *puVar1 = 0x30;
      *(undefined4 *)(puVar5 + -0x24) = 0;
    }
    *(undefined4 *)(puVar5 + -0x20) = 0;
LAB_004f4a84:
    pcVar2 = &DAT_020b909e + DAT_008d1b64;
    pcVar3 = &DAT_020b909e + DAT_008d1b64;
    DAT_008d1b64 = iVar4;
    *pcVar3 = (char)**(undefined4 **)(puVar5 + 0x10) + *pcVar2;
    FUN_005f33c9(puVar5,0x4f4ac6);
    if ((DAT_020b8ea0 == 0x5853) || (DAT_020b8ea0 == 0x4253)) {
      *(undefined4 *)(puVar5 + -0x14) = 0;
      return;
    }
    *(undefined4 *)(puVar5 + -0x50) = 0;
    *(undefined4 *)(puVar5 + -0x60) = 0x7e;
    *(int *)(puVar5 + -0x5c) = *(int *)(puVar5 + 8) + 2;
    *(uint **)(puVar5 + -0x58) = &DAT_008d1b74;
    FUN_005f47c0(puVar5 + -0x50,0xffffffff,0x784ff00,&DAT_0076665c,puVar5 + -0x60);
    if ((DAT_008d1b74 & 1) != 0) {
      *(undefined4 *)(puVar5 + -0xc) = 0;
      return;
    }
    FUN_005f46bc(puVar5,0x4f4b68);
    FUN_005f34d1(puVar5,0x4f4b7e);
    *(undefined4 *)(puVar5 + -8) = 0;
  } while( true );
}


