// FUN_004cf214 @ 004cf214 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cf214(void)

{
  undefined1 *puVar1;
  int iVar2;
  int local_1c;
  int local_c;
  
  DAT_01ade7da = DAT_007651a0;
  DAT_01ade7db = 0x20;
  DAT_01caea44 = 0;
  local_1c = 0x1a;
  DAT_01caea64 = 1;
  do {
    if (*(char *)(DAT_01caea64 + 0x78b50f) == '\\') {
      puVar1 = (undefined1 *)((int)&DAT_01ade7c0 + DAT_01caea44);
      DAT_01caea44 = DAT_01caea44 + 1;
      *puVar1 = 0x5c;
    }
    puVar1 = (undefined1 *)((int)&DAT_01ade7c0 + DAT_01caea44);
    DAT_01caea44 = DAT_01caea44 + 1;
    *puVar1 = *(undefined1 *)(DAT_01caea64 + 0x78b50f);
    if (DAT_01caea44 == 0x1c) break;
    DAT_01caea64 = DAT_01caea64 + 1;
    local_1c = local_1c + -1;
  } while (0 < local_1c);
  thunk_FUN_004d1958();
  if (DAT_0078cba6 != 2) {
    DAT_01aae2cc = 0;
    if (DAT_0078cbaa == 2) {
      DAT_01aae2cc = 0xd8;
    }
    if (DAT_0078cbaa == 3) {
      DAT_01aae2cc = 0x1b0;
    }
    _DAT_01aae2c4 = DAT_01aae2cc + DAT_01aae2d0 + -9;
    DAT_01aae2c8 = DAT_01aae2cc + DAT_01aae2d0;
    DAT_01aae2cc = DAT_01aae2cc + DAT_01aae2d0 + -0xb;
    local_c = 4;
    DAT_01aae2c0 = 2;
    do {
      *(int *)(DAT_01aae2c0 * 4 + 0x793364) = DAT_01aae2c8;
      (&DAT_0079336c)[DAT_01aae2c0] = DAT_01aae2cc;
      DAT_01aae2c0 = DAT_01aae2c0 + 4;
      local_c = local_c + -1;
    } while (0 < local_c);
    FUN_004cf490(&DAT_00793368);
    if (DAT_0078cba6 == 1) {
      return;
    }
  }
  _DAT_01aae2c4 = DAT_01aae2d4 + -9;
  DAT_01aae2c8 = DAT_01aae2d4;
  DAT_01aae2cc = DAT_01aae2d4 + -0xb;
  iVar2 = 4;
  DAT_01aae2c0 = 2;
  do {
    *(int *)(DAT_01aae2c0 * 4 + 0x7933a4) = DAT_01aae2d4;
    (&DAT_007933ac)[DAT_01aae2c0] = DAT_01aae2cc;
    DAT_01aae2c0 = DAT_01aae2c0 + 4;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  FUN_004cf490(&DAT_007933a8);
  return;
}


