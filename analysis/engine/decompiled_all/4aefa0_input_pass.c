// input_pass @ 004aefa0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void input_pass(int *param_1,int *param_2)

{
  int iVar1;
  int local_68;
  int local_60;
  
  _DAT_02052754 = 0;
  if (*param_1 == 1) {
    DAT_01fb8cc0 = 0;
    DAT_01fb8c90 = 0;
  }
  *param_1 = 0;
  if (2 < DAT_01fbb700) {
    iVar1 = *param_2;
    DAT_0089f108 = 1;
    for (; 0 < iVar1; iVar1 = iVar1 + -1) {
      if ((&DAT_020b8e9f)[DAT_0089f108] == '@') {
        thunk_FUN_004e620c(param_2,&DAT_0089f108);
        break;
      }
      DAT_0089f108 = DAT_0089f108 + 1;
    }
  }
  if (3 < DAT_01fbb700) {
    thunk_FUN_004e4d40(param_2);
  }
  DAT_01fbb718 = 0;
  local_68 = 0x180;
  *param_2 = 1;
  do {
    if ((DAT_01fbb700 == 2) && ((&DAT_020b8e9f)[*param_2] == 'T')) {
      local_60 = 5;
      DAT_0089f108 = 1;
      do {
        if (*(char *)(DAT_0089f108 + 0x792483) == *(char *)((int)&DAT_020b8ea0 + *param_2)) {
          switch(DAT_0089f108) {
          case 1:
            *(undefined1 *)((int)&DAT_020b8ea0 + *param_2) = 0x53;
            *(undefined1 *)((int)&DAT_020b8ea0 + *param_2 + 1) = 0x20;
            goto LAB_004af1c2;
          case 2:
            *(undefined1 *)((int)&DAT_020b8ea0 + *param_2) = 0x48;
            goto LAB_004af1c2;
          case 3:
            *(undefined1 *)((int)&DAT_020b8ea0 + *param_2) = 0x54;
            *(undefined1 *)((int)&DAT_020b8ea0 + *param_2 + 1) = 0x20;
            goto LAB_004af1c2;
          case 4:
            *(undefined1 *)((int)&DAT_020b8ea0 + *param_2) = 0x51;
            goto LAB_004af1c2;
          case 5:
            *(undefined1 *)((int)&DAT_020b8ea0 + *param_2) = 0x45;
            goto LAB_004af1c2;
          }
        }
        DAT_0089f108 = DAT_0089f108 + 1;
        local_60 = local_60 + -1;
      } while (0 < local_60);
    }
LAB_004af1c2:
    if ((&DAT_020b8e9f)[*param_2] == ';') goto LAB_004af26b;
    *param_2 = *param_2 + 1;
    local_68 = local_68 + -1;
  } while (0 < local_68);
  DAT_0089f108 = *param_2;
  iVar1 = -DAT_0089f108 / -1;
  for (; (0 < iVar1 && ((&DAT_020b8e9f)[DAT_0089f108] != '/')); DAT_0089f108 = DAT_0089f108 + -1) {
    iVar1 = iVar1 + -1;
  }
  *param_2 = DAT_0089f108;
  (&DAT_020b8e9f)[DAT_0089f108] = 0x3b;
LAB_004af26b:
  DAT_0078dd64 = *param_2;
  _DAT_0089f104 = 1;
  if ((char)DAT_020b8ea0 == '/') {
    _DAT_0089f104 = 2;
  }
  FUN_004af456(param_1,param_2,&DAT_0089f104);
  if (*param_1 == 0) {
    _DAT_0089f100 = 1;
  }
  else if ((DAT_01fbb700 == 1) &&
          (*(undefined4 *)(&DAT_01e67504 + (int)ROUND(DAT_01fb8c60) * 4) = DAT_01e6790c,
          200 < DAT_01fb8cc0)) {
    thunk_FUN_0052e08d();
    ITEM_I = DAT_020b8e58;
    ITEM_WORDS = DAT_020b8e54;
    _DAT_0089f0fc = DAT_020b8e5c;
    _DAT_0089f0f8 = 0;
    _DAT_02052754 = -3;
  }
  else {
    switch(DAT_01fbb700) {
    default:
      input_pitches();
      break;
    case 2:
      input_rhythm_spacing();
      break;
    case 3:
      thunk_FUN_004d8460();
      break;
    case 4:
      thunk_FUN_00413ca8();
      break;
    case 5:
      thunk_FUN_0053d1e0();
    }
    if (DAT_01fb8cc0 == 0) {
      _DAT_02052754 = -3 - DAT_01fbb700;
    }
    else {
      DAT_0078b378 = DAT_0078b378 + 1;
      _DAT_0089f100 = 0;
      DAT_01fb8cc0 = 0;
      DAT_01fb8c90 = 0;
    }
  }
  return;
}


