// FUN_004d4930 @ 004d4930 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d4930(int *param_1)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  undefined4 *local_54;
  int local_50;
  undefined4 local_4c [8];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  DAT_01aae2e4 = 0x2f0ee;
  DAT_01aae2e0 = 0x2f0ee;
  DAT_01aae2ec = -0x2f0ee;
  DAT_01aae2e8 = -0x2f0bc;
  DAT_01aae2f8 = -0x2f0ee;
  DAT_008a034c = 0;
  ITEM_I = 0;
  _DAT_008a0348 = OUTPUT_MODE;
  DAT_008a0344 = 1;
  _DAT_008a0340 = 1;
  DAT_01b11770 = 1;
  while( true ) {
    DAT_008a033c = DAT_01b11770;
    local_54 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
    local_50 = (int)ROUND((float)(&ITEM_LEN)[DAT_01b11770]);
    DAT_008a0338 = local_50;
    if (((float)(&ITEM_P1)[DAT_01b11770] == f_16) &&
       (f_1 < *(float *)(&ITEM_P12 + DAT_01b11770 * 4))) {
      DAT_008a0338 = 0xc;
    }
    iVar1 = 0x13;
    DAT_008a0334 = 1;
    DAT_01b11770 = DAT_01b11770 + local_50 + 1;
    do {
      if (DAT_008a0338 < DAT_008a0334) {
        *(float *)(&P0 + DAT_008a0334 * 4) = f_0;
        local_28 = 0;
      }
      else {
        local_2c = 0;
        DAT_008a033c = DAT_008a033c + 1;
        *(undefined4 *)(&P0 + DAT_008a0334 * 4) = (&ITEM_LEN)[DAT_008a033c];
      }
      local_24 = 0;
      DAT_008a0334 = DAT_008a0334 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
    if (P1 == f_8) {
      P12 = f_1;
      if (P2 == f_1) {
        if (P8 == f_0) {
          local_18 = 0;
        }
        else {
          DAT_0078d8a4 = 1;
          _DAT_008a0330 = f_4000;
          if (DAT_0078b4e8 == 1) {
            _DAT_008a0330 = f_1574_8031;
          }
          local_54 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
          DAT_008a034c = (int)ROUND(_DAT_008a0330 * P8);
          _DAT_008a032c = 0;
          local_50 = DAT_008a034c;
        }
      }
      else {
        local_1c = 0;
      }
    }
    else {
      local_20 = 0;
    }
    NPT = 1;
    if (P1 == f_16) {
      local_14 = 0;
    }
    else {
      draw_item();
      DAT_008a0334 = 1;
      iVar1 = NPT;
      while (iVar1 = iVar1 + -1, 0 < iVar1) {
        DAT_008a0328 = (&PT_X0)[DAT_008a0334];
        DAT_008a0338 = (&PT_Y0)[DAT_008a0334];
        if (DAT_008a0338 < DAT_01aae2e4) {
          DAT_01aae2e4 = DAT_008a0338;
        }
        if (DAT_01aae2f8 < DAT_008a0338) {
          DAT_01aae2f8 = DAT_008a0338;
        }
        if ((DAT_01c4ef40 < 2) || (P1 != f_14)) {
          DAT_01aae2ec = DAT_01aae2f8;
        }
        if (DAT_008a0328 < DAT_01aae2e0) {
          DAT_01aae2e0 = DAT_008a0328;
        }
        if (DAT_01aae2e8 < DAT_008a0328) {
          DAT_01aae2e8 = DAT_008a0328;
        }
        local_10 = 0;
        DAT_008a0334 = DAT_008a0334 + 1;
      }
      ITEM_I = DAT_008a0344;
      DAT_008a0344 = DAT_008a0344 + 1;
    }
    if (*param_1 <= DAT_01b11770) break;
    local_c = 0;
  }
  DAT_008a0324 = DAT_01aae2e4 + 24000;
  _DAT_008a0320 = -((float)DAT_008a0324 / f_4000);
  DAT_01be6ca8 = DAT_01aae2e4;
  DAT_008a031c = DAT_01aae2ec - DAT_01aae2e4;
  DAT_008a0318 = DAT_008a0324 + DAT_008a031c;
  if (DAT_01aae214 == 0) {
    DAT_0078cafc = -24000 - DAT_01aae2e4;
    DAT_01be6ca4 = DAT_01aae2e0;
    DAT_01be6cac = DAT_01aae2e8;
    _DAT_008a0310 = 0;
    _DAT_008a0314 = DAT_008a0324;
    DAT_01be6cb4 = DAT_008a031c;
  }
  else {
    if (DAT_01aae2e0 < DAT_01be6ca4) {
      DAT_01be6ca4 = DAT_01aae2e0;
    }
    if (DAT_01be6cac < DAT_01aae2e8) {
      DAT_01be6cac = DAT_01aae2e8;
    }
    if (DAT_008a030c != 0) {
      DAT_008a0324 = 0;
    }
    DAT_008a0308 = DAT_008a0308 - DAT_008a0324;
    _DAT_008a0310 = DAT_008a0308 + _DAT_008a0310;
    DAT_01be6cb4 = (DAT_008a0318 + _DAT_008a0310) - _DAT_008a0314;
    if (-1 < DAT_01be6c0c) {
      local_4c[0] = 0;
      local_54 = &DAT_008a0308;
      FUN_005fc330(local_4c,0x18,0x784ff00,&DAT_00765514,&local_54,&DAT_00793c28);
    }
  }
  DAT_008a030c = DAT_008a034c;
  DAT_008a0308 = DAT_008a034c;
  if (DAT_008a034c == 0) {
    DAT_008a0308 = DAT_008a0318 + 1000;
  }
  DAT_01be6cb0 = DAT_01be6cb4 + DAT_01be6ca8;
  return;
}


