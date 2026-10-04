// FUN_004e2cc8 @ 004e2cc8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e2cc8(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  float10 fVar8;
  int local_12c;
  int iStack_d0;
  int iStack_10;
  
  _DAT_008d08c0 = 0;
  DAT_01f93ef8 = 0;
  DAT_01f93ef0 = *param_2;
  do {
    if ((0x40 < (int)DAT_01f93ef0) && ((int)DAT_01f93ef0 < 0x48)) {
      DAT_01f93ef4 = (uint)*(byte *)((int)&DAT_020b8ea0 + *param_1);
      if ((DAT_01f93ef0 == 0x42) && (DAT_01f93ef4 == 0x41)) {
        DAT_01f93ee8 = 1;
        goto LAB_004e3c4c;
      }
      if ((DAT_01f93ef0 == 0x41) && (DAT_01f93ef4 == 0x4c)) {
        DAT_01f93ee8 = 2;
        goto LAB_004e3c4c;
      }
      if ((DAT_01f93ef0 == 0x43) && (DAT_01f93ef4 != 0x2f)) {
        DAT_01f93ef4 = (uint)*(byte *)((int)&DAT_020b8ea0 + *param_1 + 1);
        if (DAT_01f93ef4 == 0x4d) {
          DAT_01f93ee0 = 0x74cd;
          DAT_0078d918 = 99;
          DAT_0078d91c = 1;
          goto LAB_004e43f8;
        }
        if (DAT_01f93ef4 == 0x54) {
          DAT_01f93ee0 = 0x7469;
          DAT_0078d918 = 0x62;
          DAT_0078d91c = 1;
          goto LAB_004e43f8;
        }
      }
      DAT_01f93ef4 = DAT_01f93ef0;
      DAT_0078dec8 = DAT_01f93ef0 - 0x42;
      if (DAT_0078dec8 < 1) {
        DAT_0078dec8 = DAT_01f93ef0 - 0x3b;
      }
      DAT_01f93ee4 = 0;
      break;
    }
    DAT_01f93efc = (&DAT_020b8e9f)[*param_1];
    local_12c = 0xd;
    DAT_01f93ef4 = 1;
    while (*(char *)(DAT_01f93ef4 + 0x79490b) != DAT_01f93efc) {
LAB_004e2d61:
      DAT_01f93ef4 = DAT_01f93ef4 + 1;
      local_12c = local_12c + -1;
      bVar6 = false;
      bVar7 = local_12c == 0;
      if (local_12c < 1) {
        iVar2 = 1;
        pbVar4 = (byte *)&DAT_01f93efc;
        pbVar5 = &DAT_00765ed4;
        goto code_r0x004e42a7;
      }
    }
    switch(DAT_01f93ef4) {
    case 1:
      DAT_01f93ef4 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
      DAT_01f93eec = 0;
      if (((int)DAT_01f93ef0 < 0x30) || (0x39 < (int)DAT_01f93ef0)) {
        FUN_004e4432(&DAT_00765ed8);
        DAT_01f93ee8 = DAT_01b12c90;
      }
      else {
        fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
        DAT_01f93ee8 = (uint)ROUND(fVar8);
        *param_1 = *param_1 + -1;
        DAT_01f93ef4 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
        if (DAT_01f93ef0 == 0x46) {
          DAT_01f93ee8 = -DAT_01f93ee8;
        }
        else if (DAT_01f93ef0 != 0x53) goto LAB_004e4411;
        iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
        if (iVar2 == 0) {
          if (DAT_01f93ef0 != 0x4e) goto LAB_004e4411;
          DAT_01f93eec = 100;
        }
      }
      DAT_01f93eec = DAT_01f93eec + 17000;
      if ((int)DAT_01f93ee8 < 0) {
        DAT_01f93eec = -DAT_01f93eec;
      }
      DAT_01f93ee0 = DAT_01f93eec + DAT_01f93ee8;
      goto LAB_004e43f8;
    case 2:
      DAT_01f93ee8 = DAT_0078dd60;
      DAT_01f93eec = 0;
      goto LAB_004e3da9;
    case 3:
      DAT_0078dec4 = -1;
      break;
    case 4:
      if (*(char *)((int)&DAT_020b8ea0 + *param_1) == 'R') goto code_r0x004e37a5;
      DAT_0078dec4 = DAT_0078dec8;
      break;
    case 5:
      if ((*(char *)((int)&DAT_020b8ea0 + *param_1 + 1) == 'P') &&
         (*(char *)((int)&DAT_020b8ea0 + *param_1) == 'E')) {
        *param_1 = *param_1 + 2;
        goto LAB_004e3abe;
      }
      DAT_01f93ee8 = 0;
      iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
      if (iVar2 != 0) goto LAB_004e3a86;
      if ((int)DAT_01f93ef0 < 0x41) {
        fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
        DAT_01ade8e0 = (float)((float10)f_m2000 - fVar8);
        goto LAB_004e4404;
      }
      iStack_d0 = 6;
      DAT_01f93ef4 = 1;
      goto LAB_004e38af;
    case 6:
    case 0xc:
      iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
      if (iVar2 != 0) goto LAB_004e4411;
      if (DAT_01f93ef4 == 0xc) {
        DAT_01f93ee0 = 8000;
        if (DAT_01f93ef0 == 0x2b) {
          DAT_01f93ee0 = 0x1f41;
        }
        goto LAB_004e43f8;
      }
      iStack_10 = 6;
      DAT_01f93ef4 = 1;
      goto LAB_004e41e4;
    case 7:
      goto LAB_004e3bdb;
    case 8:
    case 9:
LAB_004e3abe:
      DAT_01f93efe = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
      fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
      DAT_01fbb70c = (int)ROUND(fVar8);
      DAT_01f93efe = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
      fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
      DAT_01fbb710 = (int)ROUND(-fVar8);
      if (DAT_01f93ef4 == 9) {
        DAT_01fbb70c = DAT_01fbb70c + 100;
      }
      goto LAB_004e43f8;
    case 10:
      DAT_01f93ef0 = (uint)*(byte *)((int)&DAT_020b8ea0 + *param_1);
      DAT_01f93ee8 = (uint)(DAT_01f93ef0 == 0x42);
      if (DAT_01f93ef0 == 0x41) {
        DAT_01f93ee8 = 2;
      }
      if ((DAT_01f93ef0 == 0x54) && (*(char *)((int)&DAT_020b8ea0 + *param_1 + 1) == 'E')) {
        DAT_01f93ee8 = 3;
      }
      DAT_01f93ee0 = -3000 - DAT_01f93ee8;
      goto LAB_004e43f8;
    case 0xb:
    case 0xd:
      DAT_01f93ef4 = 0xb;
      if (DAT_01f93efc == *(char *)((int)&DAT_020b8ea0 + *param_1)) {
        *param_1 = *param_1 + 1;
        DAT_01f93ef4 = 0;
      }
      DAT_01f93efe = DAT_01fb8cc0 + 1;
      DAT_01f93f06 = 0xffffffff;
      goto LAB_004e355f;
    default:
      goto LAB_004e2d61;
    }
    thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
  } while( true );
LAB_004e2f76:
  iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
  if (iVar2 != 0) {
LAB_004e33a4:
    DAT_0078decc = DAT_0078dec8;
    if ((DAT_01f93ef8 == 0) && (-1 < DAT_0078dec4)) {
      DAT_008d08bc = (DAT_0078dec4 - DAT_0078dec8) - DAT_0078dec0;
      if ((0 < DAT_008d08bc) && (3 < DAT_008d08bc)) {
        DAT_0078dec0 = DAT_0078dec0 + 7;
      }
      if ((DAT_008d08bc < 0) && (DAT_008d08bc < -3)) {
        DAT_0078dec0 = DAT_0078dec0 + -7;
      }
    }
    DAT_0078dec8 = DAT_0078dec0 + DAT_0078dec8;
    DAT_01f93ee4 = DAT_0078dec8 + DAT_01f93ee4 + _DAT_008d08c0 + 1000;
    if (0 < DAT_01fbb718) {
      DAT_01f93ee4 = -DAT_01f93ee4;
    }
    if (-1 < DAT_0078dec4) {
      DAT_0078dec4 = DAT_0078dec8;
    }
    if (DAT_01fbb718 < 0) {
      DAT_01fbb718 = 1;
    }
    if (DAT_01fbb718 == 2) {
      DAT_01fbb718 = 0;
    }
    DAT_01ade8e0 = (float)DAT_01f93ee4;
    return;
  }
  if (DAT_01f93ef0 != DAT_01f93ef4) {
    if (DAT_01f93ef0 == 0x28) {
      _DAT_008d08c0 = 6000;
    }
    else {
      if (DAT_01f93ef0 == 0x46) {
        DAT_01f93ee4 = 100;
LAB_004e304f:
        DAT_01f93ef4 = DAT_01f93ef0;
        iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
        if (iVar2 != 0) goto LAB_004e33a4;
        if (DAT_01f93ef0 == DAT_01f93ef4) {
          DAT_01f93ee4 = DAT_01f93ee4 + 300;
          iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
          if (iVar2 != 0) goto LAB_004e33a4;
        }
      }
      else {
        if (DAT_01f93ef0 == 0x53) {
          DAT_01f93ee4 = 200;
          goto LAB_004e304f;
        }
        if (DAT_01f93ef0 == 0x4e) {
          DAT_01f93ee4 = 300;
          goto LAB_004e304f;
        }
      }
      if ((0x2f < (int)DAT_01f93ef0) && ((int)DAT_01f93ef0 < 0x3a)) {
        DAT_0078dec0 = DAT_01f93ef0 * 7 + -0x150;
        if (-1 < DAT_0078dec4) {
          DAT_0078dec4 = DAT_0078dec0 + DAT_0078dec8;
        }
        iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
        if (iVar2 != 0) goto LAB_004e33a4;
      }
      if ((DAT_01f93ef0 == 0x2b) || (DAT_01f93ef0 == 0x2d)) {
        DAT_01fbb708 = DAT_01f93ef0;
        iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
        if (iVar2 != 0) goto LAB_004e33a4;
      }
      if ((DAT_01f93ef0 == 0x58) || (DAT_01f93ef0 == 0x5a)) {
        DAT_01f93efe = DAT_01f93ef0;
        DAT_01f93ef4 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
        fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
        DAT_01fbb710 = (int)ROUND(fVar8);
        if (DAT_01f93efe == 0x5a) {
          DAT_01fbb710 = DAT_01fbb710 + 100;
        }
        *param_1 = DAT_01fbb704;
        goto LAB_004e33a4;
      }
      if (DAT_01f93ef0 == 0x55) {
        if (DAT_0078dec8 <= DAT_0078decc) {
          DAT_0078dec0 = DAT_0078dec0 + 7;
        }
      }
      else {
        if (DAT_01f93ef0 != 0x4a) goto LAB_004e4411;
        if (DAT_0078decc <= DAT_0078dec8) {
          DAT_0078dec0 = DAT_0078dec0 + -7;
        }
      }
      DAT_01f93ef8 = 1;
    }
    goto LAB_004e2f76;
  }
  DAT_01f93ee4 = DAT_01f93ee4 + 100;
  goto LAB_004e2f76;
  while( true ) {
    iVar2 = iVar2 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
    if (!bVar7) break;
code_r0x004e42a7:
    if (iVar2 == 0) break;
  }
  if (!bVar6) {
    iVar2 = 1;
    pbVar4 = (byte *)&DAT_01f93efc;
    pbVar5 = &DAT_00765ed0;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pbVar4 < *pbVar5;
      bVar7 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (bVar6 || bVar7) {
LAB_004e42d2:
      fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
      DAT_01f93ee8 = (uint)ROUND(fVar8);
      DAT_01f93ef4 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
      fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
      DAT_01f93eec = (int)ROUND(fVar8);
      if (DAT_01f93eec == 0) {
        thunk_FUN_0054c68f(&DAT_01f93ee8,&DAT_01f93eec);
      }
LAB_004e43d8:
      DAT_01f93ee0 = DAT_01f93ee8 * 100 + DAT_01f93eec + 20000;
      DAT_0078d918 = DAT_01f93ee8;
      DAT_0078d91c = DAT_01f93eec;
      goto LAB_004e43f8;
    }
  }
  goto LAB_004e4411;
LAB_004e355f:
  DAT_01f93efe = DAT_01f93efe - 1;
  if (0 < (int)DAT_01f93efe) {
    DAT_01f93f0a = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_01f93efe]);
    iVar2 = DAT_01f93f0a;
    if (DAT_01f93f0a < 0) {
      iVar2 = -DAT_01f93f0a;
    }
    DAT_01f93f02 = iVar2 / 1000;
    if ((DAT_01f93f02 == 1) || (DAT_01f93f02 == 7)) goto LAB_004e35fc;
    goto LAB_004e363c;
  }
  goto LAB_004e4411;
LAB_004e35fc:
  if (DAT_01f93f06 == 0) {
    DAT_01f93f06 = DAT_01f93efe;
  }
  if (DAT_01f93f0a < 0) goto LAB_004e355f;
  if ((int)DAT_01f93f06 < 0) {
LAB_004e363c:
    DAT_01f93f06 = 0;
    goto LAB_004e355f;
  }
  DAT_01f93f02 = DAT_01f93efe;
  DAT_01f93ee0 = DAT_01f93f0a;
  for (iVar2 = (DAT_01f93f06 - DAT_01f93efe) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
    DAT_01fb8cc0 = DAT_01fb8cc0 + 1;
    iVar1 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_01f93f02]);
    DAT_01f93f0a = iVar1;
    if (DAT_01f93ef4 == 0xb) {
      iVar3 = iVar1;
      if (iVar1 < 0) {
        iVar3 = -iVar1;
      }
      DAT_01f93f0a = iVar3 % 100 + 1000;
      DAT_008d08bc = iVar1;
      if (iVar1 < 0) {
        DAT_01f93f0a = -DAT_01f93f0a;
      }
    }
    (&DAT_01fb8cc0)[DAT_01fb8cc0] = (int)(float)DAT_01f93f0a;
    DAT_01f93f02 = DAT_01f93f02 + 1;
    DAT_01f93ee0 = DAT_01f93f0a;
  }
  DAT_01fb8cc0 = DAT_01fb8cc0 + -1;
  DAT_01f93f0a = DAT_01f93ee0;
  goto LAB_004e43f8;
LAB_004e3bdb:
  DAT_01f93ee8 = 0;
  DAT_01f93ef0 = (uint)*(byte *)((int)&DAT_020b8ea0 + *param_1);
  if (DAT_01f93ef0 == 0x52) goto LAB_004e3c4c;
  if (DAT_01f93ef0 == 0x45) {
    DAT_01f93ee8 = 3;
    goto LAB_004e3c4c;
  }
  if (DAT_01f93ef0 != 0x20) {
    if ((0x2f < DAT_01f93ef0) && (DAT_01f93ef0 < 0x3a)) {
      *param_1 = *param_1 + 1;
      goto LAB_004e42d2;
    }
    DAT_01f93ef4 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
    if ((0x2f < (int)DAT_01f93ef0) && ((int)DAT_01f93ef0 < 0x3a)) goto LAB_004e42d2;
    DAT_01f93ee8 = DAT_0078d918;
    DAT_01f93eec = DAT_0078d91c;
    goto LAB_004e43d8;
  }
  *param_1 = *param_1 + 1;
  goto LAB_004e3bdb;
  while( true ) {
    DAT_01f93ef4 = DAT_01f93ef4 + 1;
    iStack_d0 = iStack_d0 + -1;
    if (iStack_d0 < 1) break;
LAB_004e38af:
    if (DAT_01f93ef0 == *(uint *)(DAT_01f93ef4 * 4 + 0x7948c0)) {
      DAT_01f93ee8 = DAT_01f93ef4;
      if ((DAT_01f93ef4 == 2) || (DAT_01f93ef4 == 6)) {
        DAT_01f93efc = *(char *)((int)&DAT_020b8ea0 + *param_1);
        if (DAT_01f93efc == 'D') {
          DAT_01f93ee8 = 8;
          if (DAT_01f93ef4 == 6) {
            DAT_01f93ee8 = 7000;
          }
        }
        else {
          if (DAT_01f93efc != 'U') goto LAB_004e39b0;
          DAT_01f93ee8 = 9;
          if (DAT_01f93ef4 == 6) {
            DAT_01f93ee8 = 0x1b59;
          }
        }
        *param_1 = *param_1 + 1;
      }
LAB_004e39b0:
      iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
      if (iVar2 != 0) goto LAB_004e3a86;
      break;
    }
  }
  if (DAT_01f93ef0 != 0x58) goto LAB_004e4411;
  DAT_01f93ef4 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
  fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
  DAT_01fbb710 = (int)ROUND(fVar8);
LAB_004e3a86:
  DAT_01f93ee0 = DAT_01f93ee8 + 2000;
  goto LAB_004e43f8;
code_r0x004e37a5:
  DAT_01f93ee8 = 4;
LAB_004e3c4c:
  DAT_01f93ee0 = DAT_01f93ee8 + 3000;
  goto LAB_004e43f8;
  while( true ) {
    DAT_01f93ef4 = DAT_01f93ef4 + 1;
    iStack_10 = iStack_10 + -1;
    if (iStack_10 < 1) break;
LAB_004e41e4:
    if (DAT_01f93ef0 == *(uint *)(DAT_01f93ef4 * 4 + 0x7948f0)) {
      DAT_01f93ee8 = 5000;
      if ((int)DAT_01f93ef0 < 0x41) {
        DAT_01f93ee8 = 6000;
      }
      DAT_01f93ee0 = *(int *)(DAT_01f93ef4 * 4 + 0x7948d8) + DAT_01f93ee8;
      goto LAB_004e43f8;
    }
  }
LAB_004e4411:
  thunk_FUN_005259e5(param_1);
  return;
LAB_004e3da9:
  iVar2 = thunk_FUN_00526ec4(&DAT_01f93ef0,param_1,&DAT_01fbb704);
  if (iVar2 == 0) {
    if ((DAT_01f93ef0 == 0x44) || (DAT_01f93ef0 == 0x4d)) {
      if (DAT_01f93eec == 100) goto LAB_004e3ebe;
      if (DAT_01f93eec != 0) {
        DAT_01f93eec = 500;
      }
      if (DAT_01f93eec == 0) {
        DAT_01f93eec = 100;
      }
    }
    else if (DAT_01f93ef0 == 0x48) {
LAB_004e3ebe:
      DAT_01f93eec = 200;
    }
    else if (DAT_01f93ef0 == 0x49) {
      DAT_01f93eec = 900;
    }
    else if (DAT_01f93ef0 == 0x52) {
      DAT_01f93eec = 400;
    }
    else if (DAT_01f93ef0 == 0x4c) {
      DAT_01f93eec = 300;
    }
    else {
      if (DAT_01f93ef0 != 0x53) {
        if (((int)DAT_01f93ef0 < 0x30) || (0x39 < (int)DAT_01f93ef0)) goto LAB_004e4411;
        fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + *param_1,1,param_1);
        DAT_01f93ee8 = (uint)ROUND(fVar8);
        goto LAB_004e3f84;
      }
      DAT_01f93eec = 700;
    }
    goto LAB_004e3da9;
  }
LAB_004e3f84:
  DAT_01f93ee0 = DAT_01f93ee8 + DAT_01f93eec + 4000;
  DAT_0078dd60 = DAT_01f93ee8;
LAB_004e43f8:
  DAT_01ade8e0 = (float)DAT_01f93ee0;
LAB_004e4404:
  *param_1 = DAT_01fbb704;
  return;
}


