// FUN_00535d00 @ 00535d00 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00535d00(int *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  if (*param_1 == 99) {
    return;
  }
  DAT_0099a828 = ITEM_I;
  if (*param_1 < 9) {
    draw_items();
    _DAT_0099a824 = 0x42;
    fit_view(&DAT_0099a824,&DAT_01c25e80,&DAT_01c25e84,&DAT_01c25e88,&DAT_01c25e8c);
    draw_items();
    if (DAT_01c25e80 < 60000) {
      DAT_01c25e80 = 60000;
    }
    if (-31000 < DAT_01c25e84) {
      DAT_01c25e84 = -31000;
    }
    _DAT_0099a820 = DAT_01c25e80 - DAT_01c25e84;
    _DAT_0099a81c = DAT_01c25e8c - _DAT_01c25e88;
    thunk_FUN_00579770(&DAT_00768974,1,&IP1);
    _DAT_01c25e90 = IP1;
    _DAT_01c25e94 = IP2;
    thunk_FUN_00579770(&DAT_00768970,1,&IP1);
    DAT_0099a818 = IP1;
    DAT_0099a814 = IP2;
    IP1 = 500000;
    IP2 = -500000;
    thunk_FUN_00579770(&DAT_00768990,1,&IP1);
    thunk_FUN_00579770(&DAT_00768970,1,&IP1);
    DAT_01c25e9c = IP2;
    _DAT_0099a830 = -IP2;
    DAT_0099a82c = (int)ROUND((float)IP1 + f_2400);
    DAT_01c25e98 = IP1;
    if (_DAT_0078cad0 == f_99) {
      switch(*param_1) {
      case 0:
        IP1 = 0;
        break;
      case 1:
        IP2 = 0;
        IP1 = -0x960;
        break;
      case 2:
        IP2 = IP2 / 2;
        IP1 = 0;
        break;
      case 3:
        break;
      case 4:
        IP2 = 0;
        break;
      case 5:
        IP2 = IP2 / 2;
        break;
      case 6:
        IP1 = IP1 / 2;
        break;
      case 7:
        IP2 = 0;
        IP1 = IP1 / 2;
        break;
      case 8:
        IP2 = IP2 / 2;
        IP1 = IP1 / 2;
        break;
      default:
        return;
      }
    }
    else {
      _DAT_0099a810 = (float)IP2;
      IP2 = (int)ROUND(_DAT_0099a810 * _DAT_0078cad0);
      IP1 = 0;
    }
LAB_005364e9:
    thunk_FUN_00579770(&DAT_00768990,1,&IP1);
    if (PAPER != 0) {
      draw_items();
    }
    if (DAT_0099a828 < 2) {
      return;
    }
    if (DAT_0078b4e4 == 0x4d) {
      return;
    }
    ITEM_I = DAT_0099a828;
    return;
  }
  if (8 < *param_1 - 9U) {
    return;
  }
  iVar1 = *param_1 + -9;
  bVar4 = iVar1 == 0;
  switch(iVar1) {
  case 0:
    IP1 = 2000;
    break;
  case 1:
    IP1 = -4000;
    break;
  case 2:
    IP1 = -2000;
    break;
  case 3:
    IP1 = 4000;
    break;
  case 4:
    IP1 = -2000;
    goto LAB_00535e07;
  case 5:
    IP1 = -4000;
    goto LAB_00535e07;
  case 6:
    IP1 = 2000;
    goto LAB_00535e07;
  case 7:
    IP1 = 4000;
LAB_00535e07:
    VIEW_DX = IP1 + VIEW_DX;
    goto LAB_00535e20;
  case 8:
    iVar1 = 5;
    pcVar2 = (char *)&DAT_020b8ea0;
    pcVar3 = "~~999";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      IP1 = 0;
      IP2 = 0x2a3;
      P1 = (float)i_0;
      P2 = f_38000;
      thunk_FUN_00579770(&DAT_00768994,1,&IP1);
      IP1 = 0;
      IP2 = 0x366;
      thunk_FUN_00579770(&DAT_00768990,1,&IP1);
      VIEW_DX = (int)ROUND(f_14500 - ((float)DAT_01a14950 + f_2338) * f_2);
      _DAT_0099a810 = (float)DAT_01a1494c;
      _DAT_0099a80c = (_DAT_0099a810 - f_266) * f_2;
      VIEW_DY = (int)ROUND(_DAT_0099a80c);
    }
    else {
      iVar1 = 5;
      pcVar2 = (char *)&DAT_020b8ea0;
      pcVar3 = "~~998";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        P2 = f_38000;
        thunk_FUN_00579770(&DAT_00768994,1,&IP1);
        IP2 = 0;
        thunk_FUN_00579770(&DAT_00768990,1,&IP1);
        VIEW_DX = 0x960;
      }
    }
    if (IP1 < DAT_0099a818) {
      VIEW_DX = VIEW_DX + 2000;
      draw_items();
      IP1 = -0x960;
      IP2 = DAT_0099a814;
    }
    else if (DAT_0099a82c + -0x960 < IP1) {
      VIEW_DX = VIEW_DX + -2000;
      draw_items();
      IP1 = DAT_0099a82c + -0x960;
      IP2 = DAT_0099a814;
    }
    else if (IP2 < DAT_01c25e9c) {
      VIEW_DY = VIEW_DY + -4000;
      draw_items();
      IP2 = DAT_01c25e9c;
      IP1 = DAT_0099a818;
    }
    else if (0 < IP2) {
      VIEW_DY = VIEW_DY + 4000;
      draw_items();
      IP2 = 0;
      IP1 = DAT_0099a818;
    }
    goto LAB_005364e9;
  }
  VIEW_DY = VIEW_DY - IP1;
LAB_00535e20:
  draw_items();
  return;
}


