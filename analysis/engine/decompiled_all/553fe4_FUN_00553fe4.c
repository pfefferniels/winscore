// FUN_00553fe4 @ 00553fe4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00553fe4(void)

{
  if ((DAT_0078b378 == 0) || (DAT_0078b378 == 0x3e9)) {
    DAT_009a38c8 = DAT_01be6c40;
    DAT_009a38c4 = DAT_01be6c44;
    DAT_009a38c0 = DAT_01be6c48;
    DAT_009a38bc = DAT_01be6c4c;
    DAT_009a38b8 = DAT_01be6c50;
    DAT_009a38b4 = DAT_01be6c54;
    P2 = f_0_52;
    P4 = f_90;
    P3 = f_50;
    _DAT_009a38b0 = 0x20;
    _DAT_0079ebd4 = 0xd;
    while( true ) {
      DAT_009a38ac = DAT_009a38a8 - DAT_009a38c8;
      DAT_009a38a4 = DAT_009a38a0 - DAT_009a38c8;
      DAT_009a389c = DAT_009a38c4 - _DAT_009a3898;
      DAT_009a3894 = DAT_009a38c4 - _DAT_009a3890;
      DAT_009a388c = (int)(0x2f0f8 / (longlong)DAT_01be6c48);
      DAT_009a3888 = (int)(0x2f0f8 / (longlong)DAT_01be6c4c);
      if (DAT_009a38ac < -DAT_009a388c) {
        DAT_009a38ac = -DAT_009a388c;
      }
      if (DAT_009a388c < DAT_009a38a4) {
        DAT_009a38a4 = DAT_009a388c;
      }
      if (DAT_009a3894 < -DAT_009a3888) {
        DAT_009a3894 = -DAT_009a3888;
      }
      if (DAT_009a3888 < DAT_009a389c) {
        DAT_009a389c = DAT_009a3888;
      }
      if (DAT_009a38a4 < -DAT_009a388c) {
        DAT_009a38a4 = -DAT_009a388c;
      }
      if (DAT_009a388c < DAT_009a38ac) {
        DAT_009a38ac = DAT_009a388c;
      }
      if (DAT_009a389c < -DAT_009a3888) {
        DAT_009a389c = -DAT_009a3888;
      }
      if (DAT_009a3888 < DAT_009a3894) {
        DAT_009a3894 = DAT_009a3888;
      }
      _DAT_0079ebf4 = DAT_01be6c48 * DAT_009a38ac;
      _DAT_0079ebfc = DAT_01be6c48 * DAT_009a38a4;
      _DAT_0079ebc0 = DAT_01be6c4c * DAT_009a389c;
      _DAT_0079ebc4 = DAT_01be6c4c * DAT_009a3894;
      if (DAT_01fbb7e4 != 0) break;
      if (DAT_01fbb7f8 == 0xf) {
        if (DAT_01fbb7fc == 9) {
LAB_0055432a:
          DAT_009a38c8 = DAT_009a38c8 + -0x32;
        }
        else {
LAB_0055430d:
          DAT_009a38c8 = DAT_009a38c8 + 0x32;
        }
      }
      else {
        switch(DAT_01fbb7f8) {
        case 0x43:
          goto LAB_0055430d;
        case 0x44:
          goto LAB_0055432a;
        default:
          goto LAB_005543fa;
        case 0x48:
          DAT_009a38c4 = DAT_009a38c4 + 5;
          break;
        case 0x49:
          DAT_009a38c4 = DAT_009a38c4 + 100;
          break;
        case 0x4b:
          DAT_009a38c8 = DAT_009a38c8 + 5;
          break;
        case 0x4d:
          DAT_009a38c8 = DAT_009a38c8 + -5;
          break;
        case 0x50:
          DAT_009a38c4 = DAT_009a38c4 + -5;
          break;
        case 0x51:
          DAT_009a38c4 = DAT_009a38c4 + -100;
        }
      }
    }
LAB_005543fa:
    DAT_01be6c40 = DAT_009a38c8;
    _DAT_01ae2850 = DAT_009a38c8;
    DAT_01be6c44 = DAT_009a38c4;
    _DAT_01ae2854 = DAT_009a38c4;
    _DAT_01ae2858 = DAT_01be6c48;
    _DAT_01ae285c = DAT_01be6c4c;
    _DAT_0079ebc8 = _DAT_0079ebc4;
    _DAT_0079ebcc = _DAT_0079ebc0;
    _DAT_0079ebd0 = _DAT_0079ebc0;
    _DAT_0079ebf8 = _DAT_0079ebf4;
    _DAT_0079ec00 = _DAT_0079ebfc;
    _DAT_0079ec04 = _DAT_0079ebf4;
    DAT_01ae2840 = _DAT_0079ebf4;
    DAT_01ae2844 = _DAT_0079ebc0;
    DAT_01ae2848 = _DAT_0079ebfc;
    DAT_01ae284c = _DAT_0079ebc4;
  }
  return;
}


