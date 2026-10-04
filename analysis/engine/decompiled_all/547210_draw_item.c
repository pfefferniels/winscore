// draw_item @ 00547210 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_item(void)

{
  undefined1 *puVar1;
  undefined2 in_FPUControlWord;
  undefined1 *puVar2;
  int local_6c;
  int local_64;
  
  puVar2 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  local_6c = 0x2d;
  DAT_0099f8a4 = 0x2d;
  do {
    if (*(float *)(&P0 + DAT_0099f8a4 * 4) != f_0) break;
    DAT_0099f8a4 = DAT_0099f8a4 + -1;
    local_6c = local_6c + -1;
  } while (0 < local_6c);
  if (DAT_0099f8a4 < 3) {
    DAT_0099f8a4 = 3;
  }
  local_64 = 0x2d;
  DAT_0099f8a0 = 1;
  do {
    *(int *)(&IP0 + DAT_0099f8a0 * 4) = (int)ROUND(*(float *)(&P0 + DAT_0099f8a0 * 4));
    DAT_0099f8a0 = DAT_0099f8a0 + 1;
    local_64 = local_64 + -1;
  } while (0 < local_64);
  if (IP1 < 1) {
    return;
  }
  if (0x14 < IP1) {
    return;
  }
  if (IP2 < 0) {
    return;
  }
  if (MAX_STAFF < IP2) {
    return;
  }
  DAT_0078b4ec = 0;
  CUR_STAFF = IP2;
  item_position();
  DAT_0078b6a0 = DAT_00791444;
  switch(IP1) {
  case 1:
    draw_note();
    puVar1 = &stack0xfffffffc;
    break;
  case 2:
    draw_rest();
    puVar1 = &stack0xfffffffc;
    break;
  default:
    if (P15 != f_0) {
      X_POS = P15 * f_150 + X_POS;
    }
    switch(IP1) {
    case 3:
      draw_clef(&X_POS,&Y_POS,&IP5,&P6,&P7);
      puVar1 = &stack0xfffffffc;
      break;
    case 4:
      goto LAB_00547421;
    case 5:
      goto LAB_00547432;
    case 6:
      goto LAB_00547443;
    case 7:
      draw_code7();
      DAT_020b8ea0._0_1_ = DAT_0076905c;
      puVar1 = &stack0xfffffffc;
      break;
    case 8:
      goto LAB_00547475;
    case 9:
LAB_0054756a:
      push_words(&DAT_00769054,&P3);
      draw_symbol(&X_POS,&Y_POS,&IP5,&P6,&P7,&IP8,&P9,&IP9);
      goto LAB_00547607;
    case 10:
      draw_number(&IP5);
      puVar1 = &stack0xfffffffc;
      break;
    case 0xb:
      goto LAB_005474a4;
    case 0xc:
      if (IP5 == 10) {
        draw_box_grid();
        puVar1 = &stack0xfffffffc;
      }
      else if (IP5 < 0) {
        draw_box_negative();
        puVar1 = &stack0xfffffffc;
      }
      else if ((IP5 < 2) || (IP5 == 3)) {
        draw_box();
      }
      else {
        draw_box_other();
        puVar1 = &stack0xfffffffc;
      }
      break;
    case 0xd:
      goto LAB_00547563;
    case 0xe:
      push_words(&DAT_00769054,&P3);
      if ((IP4 == 0) && ((_DAT_020b90a0 & 0xffffff) == 0x564e49)) {
        DAT_020b944c = f_m1;
      }
      draw_barline();
LAB_00547607:
      pop_words(&DAT_00769054,&P3);
      puVar1 = &stack0xfffffffc;
      break;
    case 0xf:
      goto LAB_00547626;
    case 0x10:
      goto LAB_0054763f;
    case 0x11:
      draw_keysig();
      puVar1 = &stack0xfffffffc;
      break;
    case 0x12:
      draw_meter();
      puVar1 = &stack0xfffffffc;
      break;
    default:
      goto LAB_00547792;
    }
    break;
  case 4:
LAB_00547421:
    draw_line();
    puVar1 = &stack0xfffffffc;
    break;
  case 5:
LAB_00547432:
    draw_slur();
    puVar1 = &stack0xfffffffc;
    break;
  case 6:
LAB_00547443:
    draw_beam();
    puVar1 = &stack0xfffffffc;
    break;
  case 8:
LAB_00547475:
    draw_staff();
    return;
  case 0xb:
LAB_005474a4:
    draw_symbol(&X_POS,&Y_POS,&IP5,&P6,&P7,&IP8,&P9,&IP9);
    DAT_0099f8a4 = 0x19;
    FUN_005f34d1(&stack0xfffffffc,&LAB_00547509);
    *(undefined4 *)(puVar2 + -0x20) = 0;
    puVar1 = puVar2;
    break;
  case 0xd:
LAB_00547563:
    goto LAB_0054756a;
  case 0xf:
LAB_00547626:
    draw_eps();
    DAT_0099f8a4 = 0x19;
    puVar1 = &stack0xfffffffc;
    break;
  case 0x10:
LAB_0054763f:
    if ((P12 == f_0) || (P13 == f_0)) {
      _DAT_0099f894 = 0;
    }
    draw_text();
    puVar1 = &stack0xfffffffc;
    if (EDIT_ITEM == 0) {
      DAT_020b9470 = f_0;
      puVar1 = &stack0xfffffffc;
    }
  }
  if (((((_DAT_020b90a0 & 0xff) == 99) || ((_DAT_020b90a0 & 0xff) == 0x43)) || (EDIT_ITEM < 1)) ||
     (DAT_00791480 < 0)) {
    *(undefined4 *)(puVar1 + -0x30) = 0;
  }
  else {
    if (P2 != (float)(&ITEM_P2)[(&ITEM_PTR0)[EDIT_ITEM]]) {
      *(undefined2 *)(puVar1 + -0x90) = in_FPUControlWord;
      *(ushort *)(puVar1 + -0x8e) = (ushort)*(undefined4 *)(puVar1 + -0x90) | 0xc00;
      *(int *)(puVar1 + -0x8c) = (int)ROUND(DAT_020b9470);
      _DAT_0099f89c = *(int *)(puVar1 + -0x8c);
      _DAT_0099f898 = 0;
      thunk_FUN_00585d20();
      DAT_020b9470 = (float)_DAT_0099f89c;
    }
    *(undefined4 *)(puVar1 + -0x2c) = 0;
  }
LAB_00547792:
  return;
}


