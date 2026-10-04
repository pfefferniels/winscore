// FUN_004f1f69 @ 004f1f69 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004f1f69(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_44;
  undefined4 *local_40;
  undefined4 local_38 [10];
  int local_10;
  
  puVar2 = (undefined4 *)&DAT_020b8ea0;
  puVar3 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_008d19e8 = X_POS;
  push_words(&DAT_00766564,&P1);
  push_words(&DAT_00766564,&IP1);
  P6 = f_2_4;
  X_POS = ((float)(&STAFF_STEP0)[CUR_STAFF] / f_25) * f_210 + X_POS;
  P7 = f_0_35;
  IP5 = 0;
  IP8 = 0;
  IP9 = 0;
  IP10 = 0;
  P13 = f_1;
  draw_box();
  if (OUTPUT_MODE == -1) {
    local_38[0] = 0;
    FUN_005fc330(local_38,0x18,0x784ff00,&DAT_007664a0,0,&DAT_00794e3c);
    DAT_008d19e4 = 0;
    if (200 < IP2) {
      DAT_008d19e4 = 0x8502;
    }
    local_44 = DAT_008d19e4 + DAT_01fd3f84;
    local_38[0] = 0;
    FUN_005fc330(local_38,0x18,0x784ff00,&DAT_00766554,&local_44,&DAT_00794e58);
    local_44 = 4;
    local_40 = &DAT_02004cc4;
    FUN_005fc980(local_38,&DAT_00766550,&local_44);
    local_10 = 4;
    DAT_008d19e0 = 3;
    do {
      local_44 = (&PT_X0)[DAT_008d19e0] + DAT_008d19e4;
      local_38[0] = 0;
      FUN_005fc330(local_38,0x18,0x784ff00,&DAT_00766554,&local_44,&DAT_00794e74);
      local_40 = &PT_Y0 + DAT_008d19e0;
      local_44 = 4;
      FUN_005fc980(local_38,&DAT_00766550,&local_44);
      DAT_008d19e0 = DAT_008d19e0 + 1;
      local_10 = local_10 + -1;
    } while (0 < local_10);
    local_38[0] = 0;
    FUN_005fc330(local_38,0x18,0x784ff00,&DAT_007664a0,0,&DAT_00794e90);
    NPT = 1;
  }
  else {
    DAT_008d19dc = COLOR;
    COLOR = (int)&DAT_00fdfdfd;
    DAT_008d19e4 = IP26;
    IP26 = 1;
    P26 = f_1;
    emit_points();
    IP26 = DAT_008d19e4;
    COLOR = DAT_008d19dc;
    P26 = (float)DAT_008d19e4;
  }
  pop_words(&DAT_00766564,&IP1);
  pop_words(&DAT_00766564,&P1);
  puVar2 = (undefined4 *)&DAT_020b90a0;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  X_POS = DAT_008d19e8;
  return;
}


