// FUN_004156ec @ 004156ec (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004156ec(void)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  
  iVar1 = (DAT_01f95c8c - DAT_01f95c88) + 1;
  DAT_01f95c84 = DAT_01f95c88;
  while( true ) {
    if (iVar1 < 1) {
      ffree(in_ST0);
      return;
    }
    DAT_01f95c9c = *(int *)(&DAT_01f995bc + DAT_01f95c84 * 4);
    DAT_0078cd44 = *(int *)(&DAT_01f9929c + DAT_01f95c84 * 4);
    if (-1 < DAT_0078cd44) {
      if ((DAT_0078cd44 == 0) &&
         (DAT_0078cd44 = DAT_0078deb0,
         (int)ROUND(*(float *)(&DAT_01f95d70 + DAT_01f95c9c * 0x3c)) != 0)) {
        DAT_0078cd44 = (int)ROUND(*(float *)(&DAT_01f95d70 + DAT_01f95c9c * 0x3c)) * -10 + 0x1e;
      }
      _DAT_007d13e8 = (float)(&DAT_01f95d54)[DAT_01f95c9c * 0xf];
      DAT_01f95c98 = (int)ROUND(_DAT_007d13e8);
      if (DAT_01f95c98 % 100 < 0x14) {
        if (0x13 < DAT_0078cd44) {
          (&DAT_01f95d54)[DAT_01f95c9c * 0xf] = _DAT_007d13e8 + f_10;
        }
      }
      else if (DAT_0078cd44 < 0x14) {
        (&DAT_01f95d54)[DAT_01f95c9c * 0xf] = _DAT_007d13e8 - f_10;
      }
    }
    if (DAT_01fb8c6c != 0) break;
LAB_004159dd:
    DAT_01f95c84 = DAT_01f95c84 + 1;
    iVar1 = iVar1 + -1;
  }
  DAT_0078deb4 = (float)(&DAT_01f95d4c)[DAT_01f95c9c * 0xf];
  DAT_01f95c98 = DAT_01fb8c6c;
LAB_004158aa:
  DAT_01f95c98 = DAT_01f95c98 + 1;
  if (((float)(&DAT_01f95d44)[DAT_01f95c98 * 0xf] != f_6) ||
     (DAT_0078deb4 != (float)(&DAT_01f95d4c)[DAT_01f95c98 * 0xf])) goto LAB_004158ff;
  *(float *)(&DAT_01f95d5c + DAT_01f95c98 * 0x3c) = (float)-DAT_0078deb0;
  in_ST0 = (float10)*(float *)(&DAT_01f95d68 + DAT_01f95c98 * 0x3c) - (float10)f_10;
  *(float *)(&DAT_01f95d68 + DAT_01f95c98 * 0x3c) =
       (float)((float10)*(float *)(&DAT_01f95d74 + DAT_01f95c9c * 0x3c) * (float10)f_10 + in_ST0);
  *(float *)(&DAT_01f95d6c + DAT_01f95c98 * 0x3c) = DAT_0078deb4;
  iVar2 = 4;
  DAT_01f95c9c = 3;
  do {
    (&DAT_01f95d40)[DAT_01f95c9c + DAT_01f95c98 * 0xf] =
         (&DAT_01f95d40)[DAT_01f95c9c + DAT_01fb8c80 * 0xf];
    DAT_01f95c9c = DAT_01f95c9c + 1;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  goto LAB_004159dd;
LAB_004158ff:
  if (DAT_0078deb8 <= DAT_01f95c98) goto LAB_004159dd;
  goto LAB_004158aa;
}


