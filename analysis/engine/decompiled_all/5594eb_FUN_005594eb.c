// FUN_005594eb @ 005594eb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005594eb(int *param_1)

{
  if (IP3 < 0x21) {
    if (0x14 < IP3) {
      IP3 = 0x14 - IP3;
    }
    *param_1 = IP3 + *param_1;
  }
  else {
    *param_1 = IP3;
  }
  return;
}


