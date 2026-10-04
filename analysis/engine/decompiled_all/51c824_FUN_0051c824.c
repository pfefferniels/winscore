// FUN_0051c824 @ 0051c824 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0051c824(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  DAT_01be6c60 = *param_2 + -1;
  DAT_01be6c68 = *param_1;
  do {
    if (((float)(&DAT_01f95d44)[DAT_01be6c68 * 0xf] == f_1) &&
       (f_10 <= *(float *)(&DAT_01f95d64 + DAT_01be6c68 * 0x3c))) {
      DAT_01be6c64 = DAT_01be6c68;
      do {
        iVar1 = DAT_01be6c64 + 1;
        if (((float)(&DAT_01f95d44)[iVar1 * 0xf] != f_1) ||
           (f_10 <= (float)(&DAT_01f95d54)[iVar1 * 0xf])) break;
        DAT_01be6c64 = iVar1;
      } while (iVar1 < *param_2);
      if (DAT_01be6c68 != DAT_01be6c64) {
        iVar2 = DAT_01be6c68;
        for (iVar1 = (DAT_01be6c64 - DAT_01be6c68) + 1; DAT_01be6c6c = iVar2, 0 < iVar1;
            iVar1 = iVar1 + -1) {
          if (*(float *)(&DAT_01f95d68 + iVar2 * 0x3c) != f_0) {
            DAT_01be6c7c = 0;
            if (f_20 <= (float)(&DAT_01f95d54)[DAT_01be6c68 * 0xf]) {
              fVar3 = (float10)amod(&DAT_01f95d28 + iVar2 * 0xf,&f_100);
              (&DAT_01f95d28)[iVar2 * 0xf] = (float)fVar3;
              DAT_01be6c74 = DAT_01be6c68;
              DAT_01be6c70 = DAT_01be6c64;
              DAT_01be6c78 = 1;
            }
            else {
              DAT_01be6c74 = DAT_01be6c64;
              DAT_01be6c70 = DAT_01be6c68;
              DAT_01be6c78 = -1;
            }
            iVar2 = DAT_01be6c78;
            iVar1 = ((DAT_01be6c70 - DAT_01be6c74) + DAT_01be6c78) / DAT_01be6c78;
            DAT_01be6c6c = DAT_01be6c74;
            goto joined_r0x0051ca75;
          }
          iVar2 = iVar2 + 1;
        }
LAB_0051cc90:
        DAT_01be6c68 = DAT_01be6c64;
      }
    }
    if (DAT_01be6c60 <= DAT_01be6c68) {
      return;
    }
    DAT_01be6c68 = DAT_01be6c68 + 1;
  } while( true );
joined_r0x0051ca75:
  if (iVar1 < 1) goto LAB_0051cc90;
  DAT_01be6c80 = f_0;
  DAT_01be6c84 = f_0;
  if (DAT_01be6c78 < 0) {
    if (*(float *)(&DAT_01f95d68 + DAT_01be6c6c * 0x3c) == f_0) {
      DAT_01be6c84 = f_1000;
      if (DAT_01be6c74 != DAT_01be6c6c) {
        if ((float)(&DAT_01f95d8c)[DAT_01be6c6c * 0xf] - (float)(&DAT_01f95d50)[DAT_01be6c6c * 0xf]
            <= f_2) {
          if (DAT_01be6c7c != 0) goto LAB_0051cbfe;
        }
        else {
LAB_0051cbd4:
          DAT_01be6c7c = 0;
        }
      }
LAB_0051cc15:
      if (f_100 <= *(float *)(&DAT_01f95d64 + DAT_01be6c6c * 0x3c)) {
        DAT_01be6c80 = f_0;
      }
      *(float *)(&DAT_01f95d64 + DAT_01be6c6c * 0x3c) =
           DAT_01be6c80 + *(float *)(&DAT_01f95d64 + DAT_01be6c6c * 0x3c) + DAT_01be6c84;
    }
    else {
      DAT_01be6c7c = 1;
    }
  }
  else if (DAT_01be6c74 != DAT_01be6c6c) {
    DAT_01be6c84 = f_1000;
    if (*(float *)(&DAT_01f95d68 + DAT_01be6c6c * 0x3c) == f_0) {
      DAT_01be6c84 = f_0;
      if (f_2 < *(float *)(&DAT_01f95d14 + DAT_01be6c6c * 0x3c) -
                (float)(&DAT_01f95d50)[DAT_01be6c6c * 0xf]) goto LAB_0051cbd4;
      if (DAT_01be6c7c == 0) goto LAB_0051cc61;
    }
LAB_0051cbfe:
    DAT_01be6c7c = 1;
    DAT_01be6c80 = f_100;
    goto LAB_0051cc15;
  }
LAB_0051cc61:
  DAT_01be6c6c = iVar2 + DAT_01be6c6c;
  iVar1 = iVar1 + -1;
  goto joined_r0x0051ca75;
}


