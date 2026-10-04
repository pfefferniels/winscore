// FUN_0058c344 @ 0058c344 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058c344(void)

{
  undefined2 in_FPUControlWord;
  undefined1 *puVar1;
  undefined4 local_4c;
  undefined4 local_48;
  int *local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38 [9];
  undefined4 local_14;
  
  puVar1 = &stack0xfffffffc;
  if (ITEM_I != 0) {
    if (DAT_020b8ea0._1_1_ == 'J') {
      _DAT_009a93a4 = DAT_020527e8;
      if (P2 == f_0) {
        local_14 = 0;
      }
      else {
        local_40 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        VIEW_DY = (int)ROUND(P2);
        local_3c = VIEW_DY;
      }
      DAT_009a93b0 = f_12691_822;
      DAT_009a93b4 = i_538983769;
      DAT_009a93b8 = i_538976288;
      local_38[0] = 0;
      local_4c = 6;
      local_48 = 0x9a93b6;
      local_44 = &VIEW_DY;
      FUN_005f34f0(local_38,0x784ff00,&DAT_0076aee0,&local_4c,&DAT_007a0680);
      draw_items();
      FUN_005f33c9(&stack0xfffffffc,0x58c44f);
      FUN_005f34d1(puVar1,0x58c46a);
      *(undefined4 *)(puVar1 + -8) = 0;
    }
    else {
      DAT_009a9498 = DAT_009c66cc;
      if (DAT_020b8ea0._1_1_ == '$') {
        if (DAT_009c66cc < 0x40) {
          DAT_009a9498 = 0x40;
          P2 = f_1;
        }
        else if (DAT_009c66cc < 0x80) {
          DAT_009a9498 = 0x80;
          P2 = f_2;
        }
        else if (DAT_009c66cc < 0xc0) {
          DAT_009a9498 = 0xc0;
          P2 = f_3;
        }
        else if (DAT_009c66cc < 0x100) {
          DAT_009a9498 = 0x100;
          P2 = f_4;
        }
        else if (DAT_009c66cc < 0x140) {
          DAT_009a9498 = 0x140;
          P2 = f_5;
        }
        else if (0x13f < DAT_009c66cc) {
          DAT_009a9498 = 0x40;
          P2 = f_1;
        }
      }
      else {
        if ((char)DAT_020b8ea0 != 'Z') {
          P2 = (float)DAT_009c66cc / f_64;
        }
        if (P2 == f_0) {
          P2 = DAT_007a0698;
        }
        if (P2 == f_0) {
          if (DAT_009c66cc == 0x40) {
            DAT_009a9498 = 0x80;
            P2 = f_2;
          }
          else {
            DAT_009a9498 = 0x40;
            P2 = f_1;
          }
        }
        else {
          DAT_009a9498 = (int)ROUND(P2 * f_64 + f_0_5);
        }
      }
      DAT_009c66cc = DAT_009a9498;
      local_40 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      DAT_009a93a0 = (int)ROUND(P2 * f_100 + f_0_5);
      local_3c = DAT_009a93a0;
      if (EDIT_ITEM == 0) {
        VIEW_DY = 0;
        fit_view(&DAT_0076aeec,&DAT_009a939c,&DAT_009a9398,&DAT_009a9394,&DAT_009a9390);
      }
      DAT_009c66cc = DAT_009a9498;
      if (300 < DAT_009a93a0) {
        DAT_009a93a0 = 300;
      }
      _DAT_009a938c = thunk_FUN_0059d240(DAT_009a93a0);
      if (EDIT_ITEM == 0) {
        VIEW_DX = 0x960;
        IP1 = -0x960;
        IP2 = 0;
        thunk_FUN_00579770(&DAT_0076aee8,1,&IP1);
        thunk_FUN_0054e546(&DAT_009a9388,&DAT_009a9384);
        if ((DAT_020b9444 <= _DAT_009a9384) && (_DAT_009a9384 != _DAT_009a9388)) {
          VIEW_DY = VIEW_DY + -3000;
        }
        if (_DAT_009a9388 <= DAT_020b9444) {
          VIEW_DY = VIEW_DY + 3000;
        }
        draw_items();
        DAT_00791470 = 0;
      }
    }
  }
  return;
}


