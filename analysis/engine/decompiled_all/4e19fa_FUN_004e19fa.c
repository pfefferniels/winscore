// FUN_004e19fa @ 004e19fa (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004e19fa(void)

{
  int iVar1;
  int iVar2;
  
  thunk_FUN_0054c419(&DAT_01cadd40,&DAT_00765dc8);
  iVar1 = 7;
  DAT_008c884c = 1;
  do {
    DAT_008c8848 = *(int *)(DAT_01b12c90 * 0x1c + DAT_008c884c * 4 + 0x78db40);
    if (DAT_008c8848 != 0) {
      if (DAT_008c8848 < 1) {
        DAT_008c8848 = 1;
      }
      else {
        DAT_008c8848 = 2;
      }
    }
    *(int *)(DAT_008c884c * 4 + 0x1aad49c) = DAT_008c8848;
    DAT_008c884c = DAT_008c884c + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  iVar1 = 10;
  DAT_008c884c = 1;
  do {
    iVar2 = 7;
    DAT_008c8848 = 1;
    do {
      *(undefined4 *)(&DAT_01cadd20 + DAT_008c884c * 0x1c + DAT_008c8848 * 4) =
           *(undefined4 *)(DAT_008c8848 * 4 + 0x1aad49c);
      DAT_008c8848 = DAT_008c8848 + 1;
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
    DAT_008c884c = DAT_008c884c + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  FUN_004e1b2a();
  return;
}


