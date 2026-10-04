// FUN_004fb0b8 @ 004fb0b8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004fb307) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fb0b8(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 local_64;
  int local_60;
  int *local_5c;
  undefined4 local_50 [8];
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  
  local_30 = 0x2d;
  DAT_00901cac = 1;
  do {
    *(undefined4 *)(&IP0 + DAT_00901cac * 4) = 0;
    DAT_00901cac = DAT_00901cac + 1;
    local_30 = local_30 + -1;
  } while (0 < local_30);
  thunk_FUN_0054c6b5(&DAT_020b8ea0,1,&DAT_00901ca8,&DAT_0078b4e0,&DAT_0078b4e4);
  _DAT_00901ca4 = 0;
  *param_1 = 0;
  local_2c = 0x80;
  DAT_00901cac = 1;
  do {
    cVar1 = (&DAT_020b8e9f)[DAT_00901cac];
    _DAT_00901cb0 = CONCAT31(DAT_00901cb0_1,cVar1);
    if (cVar1 == ' ') {
      local_28 = 0;
      break;
    }
    if (cVar1 == '.') {
      *param_1 = DAT_00901cac + -1;
    }
    (&DAT_01c4eec3)[DAT_01c4ef40 * 0x80 + DAT_00901cac] = (char)_DAT_00901cb0;
    DAT_00901cac = DAT_00901cac + 1;
    local_2c = local_2c + -1;
  } while (0 < local_2c);
  if (*param_1 == 0) {
    (&DAT_01c4eec3)[DAT_01c4ef40 * 0x80 + DAT_00901cac] = 0x2e;
    (&DAT_01c4eec4)[DAT_01c4ef40 * 0x80 + DAT_00901cac] = 0x4d;
    (&DAT_01c4eec5)[DAT_01c4ef40 * 0x80 + DAT_00901cac] = 0x55;
    (&DAT_01c4eec6)[DAT_01c4ef40 * 0x80 + DAT_00901cac] = 0x53;
    *param_1 = DAT_00901cac + -1;
  }
  else {
    local_24 = 0;
  }
  *param_2 = 0;
  _DAT_00901ca0 = 0;
  DAT_00901c9c = DAT_00901cac;
  while( true ) {
    iVar2 = DAT_00901c9c + 1;
    cVar1 = *(char *)((int)&DAT_020b8ea0 + DAT_00901c9c);
    _DAT_00901cb0 = CONCAT31(DAT_00901cb0_1,cVar1);
    if ((cVar1 != ' ') && (cVar1 != ',')) break;
    local_20 = 0;
    DAT_00901c9c = iVar2;
    if (DAT_00901ca8 <= iVar2) goto LAB_004fb35b;
    local_c = 0;
  }
  local_64 = 3;
  local_60 = (int)&DAT_020b8ea0 + DAT_00901c9c;
  local_50[0] = 0;
  local_5c = param_2;
  DAT_00901c9c = iVar2;
  iVar2 = FUN_005f9240(local_50,0x784ff01,&DAT_007669d8,&local_64,&DAT_00795160);
  if (iVar2 != 0) {
    return;
  }
LAB_004fb35b:
  if (*param_2 == 0) {
    *param_2 = 1;
    IP1 = 1;
  }
  return;
}


