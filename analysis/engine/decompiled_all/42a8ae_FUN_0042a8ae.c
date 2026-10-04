// FUN_0042a8ae @ 0042a8ae (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042a8ae(int *param_1,int *param_2)

{
  int iVar1;
  
  DAT_007ec314 = *param_1;
  DAT_007ec310 = NPT;
  DAT_007ec30c = NPT + -1;
  if (DAT_007ec314 < 1) {
    if (OUTPUT_MODE != 0) {
      DAT_007ec308 = *param_2;
      for (iVar1 = (DAT_007ec30c - DAT_007ec308) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        if (1 < *(short *)((int)&DAT_01fbb8dc + DAT_007ec308 * 2 + 2)) {
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007ec308 * 2 + 2) = 1;
        }
        DAT_007ec308 = DAT_007ec308 + 1;
      }
    }
  }
  else {
    DAT_007ec304 = DAT_007ec314 % 100;
    DAT_007ec314 = DAT_007ec314 / 100;
    DAT_007ec300 = 0xe;
    if (OUTPUT_MODE != 0) {
      DAT_007ec314 = DAT_007ec314 * 2;
      DAT_007ec304 = DAT_007ec304 * 2;
    }
    if (DAT_007ec314 != 0) {
      DAT_007ec2fc = 0xe;
      while( true ) {
        DAT_007ec308 = *param_2;
        for (iVar1 = (DAT_007ec30c - DAT_007ec308) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          (&PT_X0)[DAT_007ec310] = (&PT_X0)[DAT_007ec308];
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007ec310 * 2 + 2) =
               *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007ec308 * 2 + 2);
          (&PT_Y0)[DAT_007ec310] = (&PT_Y0)[DAT_007ec308] + DAT_007ec2fc;
          DAT_007ec310 = DAT_007ec310 + 1;
          DAT_007ec308 = DAT_007ec308 + 1;
        }
        DAT_007ec314 = DAT_007ec314 + -1;
        if (DAT_007ec314 == 0) break;
        if (DAT_007ec2fc < 0) {
          DAT_007ec2fc = DAT_007ec2fc - DAT_007ec300;
        }
        DAT_007ec2fc = -DAT_007ec2fc;
      }
      DAT_007ec314 = 0;
    }
    if (DAT_007ec304 != 0) {
      DAT_007ec2fc = DAT_007ec300;
      while( true ) {
        DAT_007ec308 = *param_2;
        for (iVar1 = (DAT_007ec30c - DAT_007ec308) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          (&PT_Y0)[DAT_007ec310] = (&PT_Y0)[DAT_007ec308];
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007ec310 * 2 + 2) =
               *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007ec308 * 2 + 2);
          DAT_007ec2f8 = (&PT_X0)[DAT_007ec308];
          if (-0x2f059 < DAT_007ec2f8) {
            DAT_007ec2f8 = DAT_007ec2fc + DAT_007ec2f8;
          }
          (&PT_X0)[DAT_007ec310] = DAT_007ec2f8;
          DAT_007ec310 = DAT_007ec310 + 1;
          DAT_007ec308 = DAT_007ec308 + 1;
        }
        DAT_007ec304 = DAT_007ec304 + -1;
        if (DAT_007ec304 == 0) break;
        if (DAT_007ec2fc < 0) {
          DAT_007ec2fc = DAT_007ec2fc - DAT_007ec300;
        }
        DAT_007ec2fc = -DAT_007ec2fc;
      }
      DAT_007ec304 = 0;
    }
    NPT = DAT_007ec310;
  }
  return;
}


