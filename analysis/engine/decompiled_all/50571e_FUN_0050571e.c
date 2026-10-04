// FUN_0050571e @ 0050571e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00505d41) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050571e(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  float10 fVar7;
  
  puVar6 = &stack0xfffffffc;
  uVar1 = (uint)DAT_00909f04 >> 8;
  _DAT_00909efc = 1;
  _DAT_00909f08 = 1;
  _DAT_00909f10 = 1;
  _DAT_00909f14 = 1;
  _DAT_00909f0c = 40000;
  _DAT_00909ef8 = &DAT_0092c1f8;
  _DAT_00909f00 = 0xffffffff;
  DAT_00909f04 = CONCAT31(((uint3)uVar1 | 0xff0000) ^ 0xfe0000,1);
  iVar4 = 1;
  for (iVar2 = 1; iVar2 < 0x9c41; iVar2 = iVar2 + 1) {
    *(undefined1 *)(iVar4 + 0x92c1f7) = 0;
    iVar4 = iVar4 + 1;
  }
  DAT_00909ee8 = 0x41;
  DAT_00909ee4 = 1;
  DAT_01b34580 = 1;
  do {
    if (*(int *)(&DAT_01f93940 + DAT_01b34580 * 0x40) == 0) {
      *(undefined4 *)(puVar6 + -0x2c) = 0;
    }
    else {
      if (*(int *)(DAT_01b34580 * 4 + 0x1b12e1c) != 0) {
        DAT_00909ef0 = 1;
        DAT_00909ef4 = *(int *)(DAT_01b34580 * 4 + 0x1b12e1c);
        iVar2 = (*(int *)(DAT_01b34580 * 4 + 0x1b12e5c) - DAT_00909ef4) + 1;
        *(int *)(puVar6 + -0x24) = iVar2;
        while (0 < iVar2) {
          *(char *)(DAT_00909ef0 + 0x913b57) =
               (char)*(undefined4 *)(DAT_01b34580 * 4 + 0x1b12edc) + (&DAT_01b58f7b)[DAT_00909ef4];
          *(undefined1 *)(DAT_00909ef0 + 0x916267) = *(undefined1 *)(DAT_01b34580 * 4 + 0x1b12f1c);
          (&DAT_00916268)[DAT_00909ef0] = *(undefined1 *)(DAT_01b34580 * 4 + 0x1b12f1c);
          *(undefined4 *)(&DAT_00909f14 + DAT_00909ef0 * 4) =
               *(undefined4 *)(&DAT_01b5b688 + DAT_00909ef4 * 4);
          *(undefined4 *)(DAT_00909ef0 * 4 + 0x918974) =
               *(undefined4 *)(&DAT_01b652c8 + DAT_00909ef4 * 4);
          *(undefined4 *)(DAT_00909ef0 * 4 + 0x9225b4) =
               *(undefined4 *)(&DAT_01b6ef08 + DAT_00909ef4 * 4);
          DAT_00909ef0 = DAT_00909ef0 + 2;
          DAT_00909ef4 = DAT_00909ef4 + 1;
          *(int *)(puVar6 + -0x24) = *(int *)(puVar6 + -0x24) + -1;
          iVar2 = *(int *)(puVar6 + -0x24);
        }
        DAT_00909ef0 = DAT_00909ef0 + -1;
        DAT_00909ef4 = 2;
        while( true ) {
          *(undefined1 *)(DAT_00909ef4 + 0x916267) = 0;
          *(undefined1 *)(DAT_00909ef4 + 0x913b57) = *(undefined1 *)(DAT_00909ef4 + 0x913b56);
          *(undefined4 *)(&DAT_00909f14 + DAT_00909ef4 * 4) =
               *(undefined4 *)(DAT_00909ef4 * 4 + 0x918970);
          DAT_00909ef4 = DAT_00909ef4 + 2;
          if (DAT_00909ef0 < DAT_00909ef4) break;
          *(undefined4 *)(puVar6 + -0x20) = 0;
        }
        _DAT_00909ee0 = f_1;
        (&DAT_00909f18)[DAT_00909ef0] = f_90999;
        do {
          DAT_00909ef4 = 1;
LAB_005059e2:
          if (*(float *)(&DAT_00909f14 + DAT_00909ef4 * 4) <= (float)(&DAT_00909f18)[DAT_00909ef4])
          {
            *(undefined4 *)(puVar6 + -0x1c) = 0;
            DAT_00909ef4 = DAT_00909ef4 + 1;
            if (DAT_00909ef4 <= DAT_00909ef0) goto code_r0x00505a27;
            DAT_00909ef4 = DAT_00909ef0 + 1;
            iVar2 = (1 - DAT_00909ef4) / -1;
            *(int *)(puVar6 + -0x10) = iVar2;
            DAT_00909ef0 = DAT_00909ef4;
            while (0 < iVar2) {
              *(float *)(&DAT_00909f14 + DAT_00909ef4 * 4) =
                   *(float *)(&DAT_00909f14 + DAT_00909ef4 * 4) -
                   *(float *)(&DAT_00909f10 + DAT_00909ef4 * 4);
              iVar2 = DAT_00909ef4 * 4;
              fVar7 = (float10)anint(puVar6,0x505b29);
              *(int *)(puVar6 + -0x54) = (int)ROUND(fVar7);
              *(undefined4 *)(&DAT_00909f14 + iVar2) = *(undefined4 *)(puVar6 + -0x54);
              DAT_00909ef4 = DAT_00909ef4 + -1;
              *(int *)(puVar6 + -0x10) = *(int *)(puVar6 + -0x10) + -1;
              iVar2 = *(int *)(puVar6 + -0x10);
            }
            fVar7 = (float10)anint(puVar6,0x505b77);
            *(int *)(puVar6 + -0x54) = (int)ROUND(fVar7);
            DAT_00909f18 = *(undefined4 *)(puVar6 + -0x54);
            *(undefined1 *)(DAT_00909ee8 + 0x92c1f7) = *(undefined1 *)(DAT_01b34580 * 4 + 0x1b12e9c)
            ;
            (&DAT_0092c1f8)[DAT_00909ee8] = 1;
            (&DAT_0092c1f9)[DAT_00909ee8] = 0x21;
            *(undefined1 *)(DAT_00909ee8 + 0x92c1fa) = 0xff;
            DAT_00909edc = 1;
            *(int *)(puVar6 + -0xc) = DAT_00909ef0;
            DAT_00909ef4 = 1;
            _DAT_00909ed0 = DAT_00909edc;
            iVar4 = DAT_00909ee4;
            iVar3 = DAT_00909ee8;
            iVar2 = DAT_00909ef0;
            while (DAT_00909ee8 = iVar3 + 8, DAT_00909edc = _DAT_00909ed0, DAT_00909ee4 = iVar4,
                  0 < iVar2) {
              *(undefined1 *)(iVar3 + 0x92c1ff) = *(undefined1 *)(DAT_00909ef4 + 0x916267);
              (&DAT_0092c1f8)[DAT_00909ee8] = *(undefined1 *)(DAT_00909ef4 + 0x913b57);
              (&DAT_0092c1f9)[DAT_00909ee8] = 0;
              *(undefined1 *)(DAT_00909ee8 + 0x92c1fa) = 0x81;
              if (*(char *)(DAT_00909ef4 + 0x916267) == '\0') {
                *(undefined1 *)(DAT_00909ee8 + 0x92c1fa) = 0x80;
              }
              iVar2 = DAT_00909ee8 + 4;
              iVar4 = (DAT_00909ee8 - iVar2) + 8;
              if (iVar4 < 0) {
                iVar4 = 0;
              }
              iVar5 = 1;
              for (iVar3 = 1; iVar3 <= iVar4; iVar3 = iVar3 + 1) {
                *(undefined1 *)(iVar2 + 0x92c1f7) = *(undefined1 *)(iVar5 + 0x909ecf);
                iVar5 = iVar5 + 1;
                iVar2 = iVar2 + 1;
              }
              _DAT_00909ed0 = DAT_00909edc + 1;
              *(undefined4 *)(puVar6 + -8) = 0;
              DAT_00909ef4 = DAT_00909ef4 + 1;
              *(int *)(puVar6 + -0xc) = *(int *)(puVar6 + -0xc) + -1;
              iVar4 = DAT_00909ee4;
              iVar3 = DAT_00909ee8;
              iVar2 = *(int *)(puVar6 + -0xc);
            }
            _DAT_00909ed8 = _DAT_00909ed0 * 2 + 0x10;
            iVar3 = 1;
            for (iVar2 = 1; iVar2 < 5; iVar2 = iVar2 + 1) {
              *(undefined1 *)(iVar4 + 0x92c1f7) = *(undefined1 *)(iVar3 + 0x909ecf);
              iVar3 = iVar3 + 1;
              iVar4 = iVar4 + 1;
            }
            DAT_00909ee4 = DAT_00909ee4 + 4;
            goto LAB_00505d89;
          }
          FUN_00505dcf(&DAT_00909f18,&DAT_00909ef4);
          FUN_00505dcf(&DAT_009225b8,&DAT_00909ef4);
          FUN_00505e0d(&DAT_00916268,&DAT_00909ef4);
          FUN_00505e0d(&DAT_00913b58,&DAT_00909ef4);
          FUN_00505e0d(&DAT_01b9ae2c,&DAT_00909ef4);
          *(undefined4 *)(puVar6 + -0x18) = 0;
        } while( true );
      }
      *(undefined4 *)(puVar6 + -0x28) = 0;
    }
LAB_00505d89:
    *(undefined4 *)(puVar6 + -4) = 0;
    DAT_01b34580 = DAT_01b34580 + 1;
    *(int *)(puVar6 + -0x30) = *(int *)(puVar6 + -0x30) + -1;
    if (*(int *)(puVar6 + -0x30) < 1) {
      thunk_FUN_005c69a0(&DAT_00909ed8,&DAT_0092c1f8);
      return;
    }
  } while( true );
code_r0x00505a27:
  *(undefined4 *)(puVar6 + -0x14) = 0;
  goto LAB_005059e2;
}


