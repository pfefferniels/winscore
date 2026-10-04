// FUN_004cf490 @ 004cf490 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004cf490(undefined4 *param_1)

{
  int iVar1;
  float *local_4c;
  undefined4 *local_48;
  undefined4 local_40 [8];
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  
  DAT_01caea54 = DAT_01caea54 % 100;
  DAT_01caea50 = DAT_01caea50 % 100;
  local_40[0] = 0;
  local_4c = (float *)&DAT_01aae2c8;
  local_20 = FUN_005fc330(local_40,0x18,0x784ff01,&DAT_00765184,&local_4c,&DAT_00793280);
  if (local_20 == 0) {
    local_4c = (float *)&DAT_01aae2c8;
    local_20 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
    if (local_20 == 0) {
      local_4c = (float *)&DAT_01aae2cc;
      local_20 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
      if (local_20 == 0) {
        local_4c = (float *)&DAT_01aae2cc;
        local_20 = FUN_005fc980(local_40,&DAT_00765108,&local_4c);
      }
    }
  }
  if (local_20 == 0) {
    local_40[0] = 0;
    local_4c = (float *)0x40;
    local_48 = param_1;
    local_1c = FUN_005fc330(local_40,0x18,0x784ff01,&DAT_00765250,&local_4c,&DAT_0079323c);
    if (local_1c == 0) {
      local_40[0] = 0;
      local_4c = (float *)&DAT_01aae2c4;
      local_18 = FUN_005fc330(local_40,0x18,0x784ff01,&DAT_00765184,&local_4c,&DAT_00793134);
      if (local_18 == 0) {
        local_4c = (float *)&DAT_01aae2c4;
        local_18 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
        if (local_18 == 0) {
          local_4c = (float *)&DAT_01aae2c4;
          local_18 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
          if (local_18 == 0) {
            local_4c = (float *)&DAT_01aae2c4;
            local_18 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
            if (local_18 == 0) {
              local_4c = (float *)&DAT_01aae2c4;
              local_18 = FUN_005fc980(local_40,&DAT_00765108,&local_4c);
            }
          }
        }
      }
      if (local_18 == 0) {
        local_40[0] = 0;
        local_4c = (float *)&DAT_01aae2c4;
        iVar1 = FUN_005fc330(local_40,0x18,0x784ff01,&DAT_00765184,&local_4c,&DAT_00793000);
        if (iVar1 == 0) {
          local_4c = (float *)0x1c;
          local_48 = &DAT_01ade7c0;
          iVar1 = FUN_005fc980(local_40,&DAT_0076524c,&local_4c);
          if (iVar1 == 0) {
            local_4c = (float *)&DAT_01aae2c4;
            iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
            if (iVar1 == 0) {
              local_4c = (float *)0x12;
              local_48 = (undefined4 *)&DAT_0078cb10;
              iVar1 = FUN_005fc980(local_40,&DAT_0076524c,&local_4c);
              if (iVar1 == 0) {
                local_4c = (float *)&DAT_01aae2c4;
                iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
                if (iVar1 == 0) {
                  local_4c = (float *)&DAT_01caea5c;
                  iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
                  if (iVar1 == 0) {
                    local_4c = (float *)&DAT_01caea64;
                    iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
                    if (iVar1 == 0) {
                      local_4c = (float *)&DAT_01aae2c4;
                      iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
                      if (iVar1 == 0) {
                        local_4c = (float *)&DAT_01caea44;
                        iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
                        if (iVar1 == 0) {
                          local_4c = (float *)&DAT_01caea4c;
                          iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
                          if (iVar1 == 0) {
                            local_4c = (float *)&DAT_01caea54;
                            iVar1 = FUN_005fc980(local_40,&DAT_00765108,&local_4c);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (iVar1 == 0) {
          if (DAT_0078b4e8 == 0) {
            local_40[0] = 0;
            local_4c = (float *)&DAT_01aae2c4;
            FUN_005fc330(local_40,0x18,0x784ff00,&DAT_00765184,&local_4c,&DAT_007932f4);
            local_4c = (float *)&DAT_01c60cb2;
            FUN_005fc980(local_40,&DAT_007650e8,&local_4c);
            local_4c = &DAT_01c60caa;
            FUN_005fc980(local_40,&DAT_007650e8,&local_4c);
            local_4c = &DAT_01c60cae;
            FUN_005fc980(local_40,&DAT_007650e8,&local_4c);
            local_4c = (float *)&DAT_0078b47c;
            FUN_005fc980(local_40,&DAT_00765184,&local_4c);
            local_4c = (float *)&DAT_01c60ca6;
            FUN_005fc980(local_40,&DAT_00765108,&local_4c);
            return;
          }
          local_14 = 0;
          P1 = DAT_01c60caa * f_2_54;
          P2 = DAT_01c60cae * f_2_54;
          local_40[0] = 0;
          local_4c = (float *)&DAT_01aae2c4;
          iVar1 = FUN_005fc330(local_40,0x18,0x784ff01,&DAT_00765184,&local_4c,&DAT_00792f38);
          if (iVar1 == 0) {
            local_4c = (float *)&DAT_01c60cb2;
            iVar1 = FUN_005fc980(local_40,&DAT_007650e8,&local_4c);
            if (iVar1 == 0) {
              local_4c = &P1;
              iVar1 = FUN_005fc980(local_40,&DAT_007650e8,&local_4c);
              if (iVar1 == 0) {
                local_4c = &P2;
                iVar1 = FUN_005fc980(local_40,&DAT_007650e8,&local_4c);
                if (iVar1 == 0) {
                  local_4c = (float *)&DAT_0078b47c;
                  iVar1 = FUN_005fc980(local_40,&DAT_00765184,&local_4c);
                  if (iVar1 == 0) {
                    local_4c = (float *)&DAT_01c60ca6;
                    iVar1 = FUN_005fc980(local_40,&DAT_00765108,&local_4c);
                  }
                }
              }
            }
          }
          if (iVar1 == 0) {
            return;
          }
        }
      }
    }
  }
  FUN_004cf1c2();
  return;
}


