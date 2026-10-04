// FUN_00559733 @ 00559733 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00559733(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  uint local_44;
  undefined4 *local_40;
  undefined4 local_3c [8];
  undefined4 local_1c;
  int local_10;
  
  puVar2 = (undefined4 *)&DAT_020b8ea0;
  puVar3 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_009a3c7c = X_POS;
  ffree(in_ST0);
  Var4 = push_words(&DAT_00769b1c,&P1);
  ffree(Var4);
  Var4 = push_words(&DAT_00769b1c,&IP1);
  local_44 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  local_40 = (undefined4 *)(int)ROUND(P4 + f_1);
  P4 = (float)(int)local_40;
  ffree(Var4);
  fVar5 = (float10)staff_level_y(&P4);
  Y_POS = (float)fVar5;
  P6 = f_2_2;
  if (9 < IP9) {
    P6 = f_3_35;
  }
  if (IP9 == -1) {
    P6 = f_2_3;
  }
  if (f_100 <= P12) {
    P3 = P3 + f_0_25;
    P6 = P6 + f_0_16;
    if (IP9 == -1) {
      P3 = P3 + f_0_2;
    }
  }
  else {
    local_1c = 0;
  }
  X_POS = (float)(((float10)(float)(&STAFF_STEP0)[CUR_STAFF] / (float10)f_35) * (float10)f_160 +
                 (float10)P3 * (float10)f_150);
  P7 = f_1;
  IP5 = 0;
  IP8 = 0;
  IP9 = 0;
  IP10 = 0;
  P13 = f_1;
  ffree((float10)P3 * (float10)f_150);
  Var4 = draw_box();
  if (OUTPUT_MODE == -1) {
    local_3c[0] = 0;
    ffree(Var4);
    Var4 = FUN_005fc330(local_3c,0x18,0x784ff00,&DAT_00769afc,0,&DAT_0079ed58);
    DAT_009a3c78 = 0;
    if (200 < IP2) {
      DAT_009a3c78 = 0x8502;
    }
    local_44 = DAT_009a3c78 + DAT_01fd3f84;
    local_3c[0] = 0;
    ffree(Var4);
    Var4 = FUN_005fc330(local_3c,0x18,0x784ff00,&DAT_00769af8,&local_44,&DAT_0079ed74);
    local_44 = 4;
    local_40 = &DAT_02004cc4;
    ffree(Var4);
    Var4 = FUN_005fc980(local_3c,&DAT_00769af4,&local_44);
    local_10 = 4;
    DAT_009a3c74 = 3;
    do {
      local_44 = (&PT_X0)[DAT_009a3c74] + DAT_009a3c78;
      local_3c[0] = 0;
      ffree(Var4);
      Var4 = FUN_005fc330(local_3c,0x18,0x784ff00,&DAT_00769af8,&local_44,&DAT_0079ed90);
      local_40 = &PT_Y0 + DAT_009a3c74;
      local_44 = 4;
      ffree(Var4);
      Var4 = FUN_005fc980(local_3c,&DAT_00769af4,&local_44);
      DAT_009a3c74 = DAT_009a3c74 + 1;
      local_10 = local_10 + -1;
    } while (0 < local_10);
    local_3c[0] = 0;
    ffree(Var4);
    Var4 = FUN_005fc330(local_3c,0x18,0x784ff00,&DAT_00769afc,0,&DAT_0079edac);
    NPT = 1;
  }
  else {
    COLOR = (int)&DAT_00fdfdfd;
    DAT_009a3c78 = EDIT_ITEM;
    EDIT_ITEM = -1;
    ffree(Var4);
    Var4 = emit_points();
    EDIT_ITEM = DAT_009a3c78;
  }
  ffree(Var4);
  Var4 = pop_words(&DAT_00769b1c,&IP1);
  ffree(Var4);
  Var4 = pop_words(&DAT_00769b1c,&P1);
  puVar2 = (undefined4 *)&DAT_020b90a0;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  X_POS = DAT_009a3c7c;
  ffree(Var4);
  return;
}


