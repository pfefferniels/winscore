// FUN_00536c75 @ 00536c75 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00536c75(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  if (DAT_0099a8bc == 99) {
    return;
  }
  if (DAT_0099a8bc < 9) {
    _DAT_0099a8b8 = DAT_01c25e80 - DAT_01c25e84;
    _DAT_0099a8b4 = DAT_01c25e8c - _DAT_01c25e88;
    thunk_FUN_00579770(&DAT_00768974,1,&IP1);
    _DAT_01c25e90 = IP1;
    _DAT_01c25e94 = IP2;
    thunk_FUN_00579770(&DAT_00768970,1,&IP1);
    DAT_0099a8b0 = IP1;
    DAT_0099a8ac = IP2;
    IP1 = 500000;
    IP2 = -500000;
    thunk_FUN_00579770(&DAT_00768990,1,&IP1);
    thunk_FUN_00579770(&DAT_00768970,1,&IP1);
    DAT_01c25e9c = IP2;
    _DAT_0099a8c4 = -IP2;
    DAT_0099a8c0 = (int)ROUND((float)IP1 + f_2400);
    DAT_01c25e98 = IP1;
    switch(DAT_0099a8bc) {
    case 0:
      IP2 = -500000;
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
LAB_0053734d:
    thunk_FUN_00579770(&DAT_00768990,1,&IP1);
    if (PAPER == 0) {
      return;
    }
    draw_items();
    return;
  }
  if (8 < DAT_0099a8bc - 9U) {
    return;
  }
  bVar4 = DAT_0099a8bc + -9 == 0;
  switch(DAT_0099a8bc + -9) {
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
    goto LAB_00536d75;
  case 5:
    IP1 = -4000;
    goto LAB_00536d75;
  case 6:
    IP1 = 2000;
    goto LAB_00536d75;
  case 7:
    IP1 = 4000;
LAB_00536d75:
    VIEW_DX = IP1 + VIEW_DX;
    goto LAB_00536d8e;
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
      _DAT_0099a8a8 = (float)DAT_01a1494c;
      _DAT_0099a8a4 = (_DAT_0099a8a8 - f_266) * f_2;
      VIEW_DY = (int)ROUND(_DAT_0099a8a4);
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
    if (IP1 < DAT_0099a8b0) {
      VIEW_DX = VIEW_DX + 2000;
      draw_items();
      IP1 = -0x960;
      IP2 = DAT_0099a8ac;
    }
    else if (DAT_0099a8c0 + -0x960 < IP1) {
      VIEW_DX = VIEW_DX + -2000;
      draw_items();
      IP1 = DAT_0099a8c0 + -0x960;
      IP2 = DAT_0099a8ac;
    }
    else if (IP2 < DAT_01c25e9c) {
      VIEW_DY = VIEW_DY + -4000;
      draw_items();
      IP2 = DAT_01c25e9c;
      IP1 = DAT_0099a8b0;
    }
    else if (0 < IP2) {
      VIEW_DY = VIEW_DY + 4000;
      draw_items();
      IP2 = 0;
      IP1 = DAT_0099a8b0;
    }
    goto LAB_0053734d;
  }
  VIEW_DY = VIEW_DY - IP1;
LAB_00536d8e:
  draw_items();
  return;
}


