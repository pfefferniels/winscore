// FUN_00533a88 @ 00533a88 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00533a88(void)

{
  int iVar1;
  int iVar2;
  
  if (-1 < DAT_0078dc68) {
    if (DAT_0078dc68 == 0) {
      DAT_0078dc68 = 2000;
    }
    DAT_0078dc64 = 0;
    DAT_0078b4e0 = 0;
    OUTPUT_MODE = -99;
    EDIT_ITEM = 0;
    DAT_01a1c814 = 0;
    DAT_01eae1b0 = 0;
    DAT_01aadd20 = 0;
    for (iVar1 = 1; iVar1 < 0x101; iVar1 = iVar1 + 1) {
      (&DAT_01aadd20)[iVar1] = 0;
    }
    LOAD_I = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      load_item_header();
      if ((((LOAD_CODE < 0x11) && (LOAD_CODE != 7)) && (3 < LOAD_CODE)) && (LOAD_CODE != 9))
      goto LAB_005341ce;
      iVar2 = 0x12;
      DAT_01a1c808 = 1;
      do {
        if (LOAD_LEN < DAT_01a1c808) {
          *(int *)(&P0 + DAT_01a1c808 * 4) = i_0;
          *(undefined4 *)(&IP0 + DAT_01a1c808 * 4) = 0;
        }
        else {
          DAT_01a1c810 = (float)(&ITEM_LEN)[LOAD_W + DAT_01a1c808];
          *(float *)(&P0 + DAT_01a1c808 * 4) = DAT_01a1c810;
          *(int *)(&IP0 + DAT_01a1c808 * 4) = (int)ROUND(DAT_01a1c810);
        }
        DAT_01a1c808 = DAT_01a1c808 + 1;
        iVar2 = iVar2 + -1;
      } while (0 < iVar2);
      DAT_01a1c80c = IP5;
      switch(LOAD_CODE) {
      default:
        iVar2 = IP5 % 10;
        if (iVar2 != 0) {
          DAT_01a1c80c = iVar2 + 5;
          if (10 < DAT_01a1c80c) {
            DAT_01a1c80c = iVar2 + 0x8b;
          }
          FUN_0053421b();
        }
        DAT_01a1c80c = IP6;
        if ((9 < IP6) && (IP6 < 0x14)) {
          DAT_01a1c80c = IP6 + -10;
        }
        if ((-1 < DAT_01a1c80c) && (DAT_01a1c80c != 7)) {
          if (DAT_01a1c80c < 7) {
            DAT_01a1c80c = DAT_01a1c80c + 0xb;
          }
          else {
            if (DAT_01a1c80c == 8) {
              DAT_01a1c80c = 0x5f;
            }
            if (DAT_01a1c80c == 9) {
              DAT_01a1c80c = 0x8b;
            }
          }
          FUN_0053421b();
        }
        DAT_01a1c80c = IP11;
        if (IP11 < 0) {
          DAT_01a1c80c = -IP11;
        }
        if (DAT_01a1c80c != 0) {
          iVar2 = DAT_01a1c80c;
          if (DAT_01a1c80c < 0) {
            iVar2 = -DAT_01a1c80c;
          }
          if (iVar2 < 0x1d) {
            if (DAT_01a1c80c < 4) {
              DAT_01a1c80c = DAT_01a1c80c + 5;
            }
            else {
              if (0x13 < DAT_01a1c80c) {
                if (DAT_01a1c80c < 0x18) {
                  if (DAT_01a1c80c != 0x14) {
                    DAT_01a1c80c = DAT_01a1c80c + -0xf;
                    goto LAB_005341b2;
                  }
                }
                else if (DAT_01a1c80c < 0x1d) {
                  if (0x19 < DAT_01a1c80c) {
                    DAT_01a1c80c = 0x18;
                  }
                  if (DAT_01a1c80c == 0x18) {
                    DAT_01a1c80c = 0x26;
                  }
                  if (DAT_01a1c80c == 0x19) {
                    DAT_01a1c80c = 0x77;
                  }
                  goto LAB_005341b2;
                }
                break;
              }
              DAT_01a1c80c = DAT_01a1c80c + 0x11;
            }
            goto LAB_005341b2;
          }
        }
        break;
      case 2:
        if (IP5 < 0) {
          if (IP5 != -4) break;
          DAT_01a1c80c = 0x27;
        }
        else {
          DAT_01a1c80c = IP5 + 0x2b;
          if (0x2c < DAT_01a1c80c) {
            DAT_01a1c80c = 0x2c;
          }
        }
        goto LAB_005341b2;
      case 3:
      case 4:
      case 5:
      case 6:
        if (IP5 == 3) {
          DAT_01a1c80c = 2;
        }
code_r0x00533eae:
        if (P7 == (float)i_0) {
          P7 = P6;
        }
        if (((IP8 == 0) && (IP9 == 0)) && (P7 == P6)) goto LAB_005341b2;
        break;
      case 7:
      case 8:
        iRam0099a78c = (int)ROUND(P7);
        if (iRam0099a78c == 0) {
          DAT_01a1c80c = 0x25;
          FUN_0053421b();
          if (P8 != (float)i_0) {
            DAT_01a1c80c = (int)ROUND(P8 + _UNK_00768850);
            goto LAB_005341b2;
          }
        }
        else if (iRam0099a78c == 0x14) {
          if (IP5 != 0) {
            DAT_01a1c80c = 0x31;
            FUN_0053421b();
          }
          DAT_01a1c80c = 0x30;
          goto LAB_005341b2;
        }
        break;
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
        iVar2 = 0x14;
        iRam0099a78c = 1;
        do {
          if (IP5 == *(int *)(iRam0099a78c * 4 + 0x1a1c77c)) goto LAB_005341ce;
          iRam0099a78c = iRam0099a78c + 1;
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
        if (IP5 < 3000) goto code_r0x00533eae;
        break;
      case 0x11:
        iRam0099a78c = 6;
        if (0 < IP5) {
          iRam0099a78c = 7;
        }
        iVar2 = IP5;
        if (IP5 < 0) {
          iVar2 = -IP5;
        }
        if (100 < iVar2) {
          iRam0099a78c = 8;
        }
        DAT_01a1c80c = iRam0099a78c;
LAB_005341b2:
        FUN_0053421b();
        if (DAT_0078dc68 < DAT_0078dc64) {
          OUTPUT_MODE = -1;
          return;
        }
        break;
      case 0x12:
        if (0x61 < IP5) {
          DAT_01a1c80c = 0x75 - IP5;
          goto LAB_005341b2;
        }
      }
LAB_005341ce:
      LOAD_I = LOAD_I + 1;
    }
  }
  OUTPUT_MODE = -1;
  return;
}


