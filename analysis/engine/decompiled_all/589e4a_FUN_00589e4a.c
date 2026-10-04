// FUN_00589e4a @ 00589e4a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00589e4a(void)

{
  char local_7c [11];
  char local_71;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_01a9f328 == DAT_01a9f324) {
    local_50 = 0;
    DAT_01a9f320 = DAT_01a9f320 + -1;
  }
  else {
    DAT_01a9f328 = DAT_01a9f324;
    if (DAT_01a9f324 < 1) {
      FUN_0058a182(&DAT_0076adc0,1);
      DAT_01a9f324 = -DAT_01a9f324;
    }
    else {
      local_4c = 0;
    }
    if (DAT_01a9f324 < 0x14) {
      local_48 = 0;
      DAT_009a92ec = (&DAT_007a05f3)[DAT_01a9f324];
      if (DAT_01a9f324 < 4) {
        DAT_009a92ec = s_FSNWATSWATDUHFATMIH_007a05f4[0];
      }
    }
    else {
      DAT_009a92ec = s_FSNWATSWATDUHFATMIH_007a05f4[0];
      if (DAT_01a9f324 < 0x1e) {
        DAT_009a92ec = s_FSNWATSWATDUHFATMIH_007a05f4[5];
        if (DAT_01a9f324 == 0x18) {
          DAT_009a92ec = DAT_0076ae7c;
        }
        if (DAT_01a9f324 == 0x19) {
          DAT_009a92ec = s_FSNWATSWATDUHFATMIH_007a05f4[4];
        }
        local_40 = 0;
      }
      else {
        local_44 = 0;
      }
    }
    FUN_0058a182(&DAT_009a92ec,1);
    if ((DAT_01a9f324 < 4) || (7 < DAT_01a9f324)) {
      if (DAT_01a9f324 < 5) {
        FUN_0058a182(&DAT_0076ae74,1);
      }
      else {
        local_38 = 0;
        if (DAT_01a9f324 < 0xb) {
          FUN_0058a182(s_FSNWATSWATDUHFATMIH_007a05f4 + 1,1);
          local_2c = 0;
          goto LAB_0058a14b;
        }
        local_30 = 0;
        if (DAT_01a9f324 < 0xe) {
          local_28 = 0;
          goto LAB_0058a14b;
        }
        if (DAT_01a9f324 < 0x14) {
          FUN_0058a182(&DAT_007a05de + DAT_01a9f324,1);
          local_20 = 0;
          goto LAB_0058a14b;
        }
        local_24 = 0;
        if (0x17 < DAT_01a9f324) {
          local_1c = 0;
          if (DAT_01a9f324 < 0x1e) {
            DAT_009a92ec = DAT_0076ae78;
            if (DAT_01a9f324 == 0x19) {
              DAT_009a92ec = DAT_0076ae08;
            }
            FUN_0058a182(&DAT_009a92ec,1);
            if (DAT_01a9f324 == 0x19) {
              FUN_0058a182(s_FSNWATSWATDUHFATMIH_007a05f4 + 5,1);
            }
            local_c = 0;
          }
          else {
            local_10 = 0;
            local_7c[0] = (char)DAT_01a9f324 + '\x12';
            local_71 = local_7c[0];
            FUN_0058a182(local_7c,1);
            local_8 = 0;
          }
          goto LAB_0058a14b;
        }
        FUN_0058a182(s_RHOMW_007a05ed,1);
        if (DAT_01a9f324 == 0x14) {
          local_18 = 0;
          goto LAB_0058a14b;
        }
        DAT_01a9f324 = DAT_01a9f324 + -0x14;
        local_14 = 0;
      }
      FUN_0058a182(&DAT_007a05f3 + DAT_01a9f324,1);
      local_34 = 0;
    }
    else {
      local_3c = 0;
    }
  }
LAB_0058a14b:
  FUN_0058a1b1(&DAT_01a9f320,&DAT_01a1f7d4,1,&DAT_01a9f30c);
  FUN_0058a182(&DAT_0076adf8,1);
  return;
}


