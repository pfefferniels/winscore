// FUN_00504835 @ 00504835 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00504835(void)

{
  int iVar1;
  undefined1 *puVar2;
  float10 fVar3;
  
  puVar2 = &stack0xfffffffc;
  _DAT_009040b4 = 0;
  DAT_009040b0 = 0;
  iVar1 = -DAT_01b34584 / -1;
  DAT_009040ac = DAT_01b34584;
  while (0 < iVar1) {
    if (*(char *)((int)&DAT_01b34588 + DAT_009040ac + 3) == '\x05') {
      DAT_009040b0 = DAT_009040b0 + 1;
      *(int *)(DAT_009040b0 * 4 + 0x907f48) = DAT_009040ac;
      iVar1 = DAT_009040ac * 4;
      fVar3 = (float10)anint(puVar2,0x5048d2);
      *(int *)(puVar2 + -0x8c) = (int)ROUND(fVar3);
      *(undefined4 *)(&DAT_009040c8 + iVar1) = *(undefined4 *)(puVar2 + -0x8c);
    }
    else {
      *(undefined4 *)(puVar2 + -100) = 0;
    }
    *(undefined4 *)(puVar2 + -0x60) = 0;
    DAT_009040ac = DAT_009040ac + -1;
    *(int *)(puVar2 + -0x68) = *(int *)(puVar2 + -0x68) + -1;
    iVar1 = *(int *)(puVar2 + -0x68);
  }
  if (DAT_009040b0 == 0) {
    *(undefined4 *)(puVar2 + -0x5c) = 0;
  }
  else {
    thunk_FUN_0054c419(&DAT_0090600c,&DAT_00766ec4);
    *(int *)(puVar2 + -0x58) = DAT_009040b0;
    DAT_009040ac = 1;
    iVar1 = DAT_009040b0;
    while (0 < iVar1) {
      LOAD_W = *(int *)(DAT_009040ac * 4 + 0x907f48);
      FUN_00504dfc(&DAT_01b36c98 + LOAD_W * 4,&DAT_01b36c98 + LOAD_W * 4,&DAT_009040c8 + LOAD_W * 4,
                   &DAT_00766ec0);
      FUN_00504dfc(&DAT_009040c8 + LOAD_W * 4,&DAT_01b36c98 + LOAD_W * 4,&DAT_009040c8 + LOAD_W * 4,
                   &DAT_00766ebc);
      DAT_009040a8 = *(int *)(&DAT_01b36c98 + LOAD_W * 4);
      DAT_009040a4 = *(int *)(&DAT_009040c8 + LOAD_W * 4);
      DAT_009040c4 = *(char *)((int)&DAT_01b408d8 + LOAD_W + 3);
      if (DAT_009040c4 == (&DAT_01b42feb)[LOAD_W]) {
        DAT_009040c0 = 'c';
        *(int *)(puVar2 + -0x50) = DAT_01b34584;
        DAT_009040a0 = 1;
        iVar1 = DAT_01b34584;
        while (0 < iVar1) {
          if (DAT_009040a8 < *(int *)(&DAT_01b36c98 + DAT_009040a0 * 4)) {
            *(undefined4 *)(puVar2 + -0x4c) = 0;
            break;
          }
          if (((*(int *)(&DAT_00906008 + DAT_009040a0 * 4) == 0) &&
              (*(char *)((int)&DAT_01b34588 + DAT_009040a0 + 3) == '\x01')) &&
             (DAT_009040a8 == *(int *)(&DAT_01b36c98 + DAT_009040a0 * 4))) {
            DAT_009040b8 = *(char *)((int)&DAT_01b408d8 + DAT_009040a0 + 3) - DAT_009040c4;
            if (DAT_009040b8 < '\0') {
              DAT_009040b8 = -DAT_009040b8;
            }
            if (DAT_009040b8 < DAT_009040c0) {
              DAT_00904098 = (int)*(char *)((int)&DAT_01b408d8 + DAT_009040a0 + 3);
              DAT_009040bc = (&DAT_01b42feb)[DAT_009040a0];
              DAT_0090409c = DAT_009040a0;
              DAT_009040c0 = DAT_009040b8;
            }
            else {
              *(undefined4 *)(puVar2 + -0x44) = 0;
            }
          }
          else {
            *(undefined4 *)(puVar2 + -0x48) = 0;
          }
          *(undefined4 *)(puVar2 + -0x40) = 0;
          DAT_009040a0 = DAT_009040a0 + 1;
          *(int *)(puVar2 + -0x50) = *(int *)(puVar2 + -0x50) + -1;
          iVar1 = *(int *)(puVar2 + -0x50);
        }
        if (DAT_009040c0 == 'c') {
          *(undefined4 *)(puVar2 + -0x3c) = 0;
        }
        else {
          *(int *)(puVar2 + -0x38) = DAT_01b9d5c0;
          DAT_00904094 = 1;
          iVar1 = DAT_01b9d5c0;
joined_r0x00504b87:
          if (0 < iVar1) {
            if (DAT_009040a8 != *(int *)(&DAT_01b78b48 + DAT_00904094 * 4)) goto code_r0x00504ba2;
            *(undefined4 *)(puVar2 + -0x34) = 0;
            while( true ) {
              _DAT_00904090 =
                   *(float *)(&DAT_01b456f8 + DAT_0090409c * 4) +
                   *(float *)(DAT_00904094 * 4 + 0x1b82788);
              DAT_0090408c = 1;
              iVar1 = DAT_01b9d5c0;
              while( true ) {
                if (iVar1 < 1) {
                  *(undefined4 *)(puVar2 + -0x28) = 0;
                  goto LAB_00504db2;
                }
                if (ABS(*(float *)(DAT_0090408c * 4 + 0x1b82788) - _DAT_00904090) < f_0_01) break;
                DAT_0090408c = DAT_0090408c + 1;
                iVar1 = iVar1 + -1;
              }
              *(undefined4 *)(puVar2 + -0x2c) = 0;
              if (DAT_009040a4 == *(int *)(&DAT_01b78b48 + DAT_0090408c * 4)) break;
              DAT_0090409c = DAT_0090409c + 1;
              *(undefined4 *)(puVar2 + -0x20) = 0;
            }
            *(undefined4 *)(puVar2 + -0x24) = 0;
            DAT_0090408c = DAT_0090409c + 1;
            iVar1 = (DAT_01b34584 - DAT_0090408c) + 1;
            *(int *)(puVar2 + -0x1c) = iVar1;
            while( true ) {
              if (iVar1 < 1) goto LAB_00504db2;
              if (*(char *)((int)&DAT_01b34588 + DAT_0090408c + 3) == '\x01') break;
              *(undefined4 *)(puVar2 + -0x18) = 0;
LAB_00504cfd:
              *(undefined4 *)(puVar2 + -8) = 0;
              DAT_0090408c = DAT_0090408c + 1;
              *(int *)(puVar2 + -0x1c) = *(int *)(puVar2 + -0x1c) + -1;
              iVar1 = *(int *)(puVar2 + -0x1c);
            }
            if ((DAT_009040a4 != *(int *)(&DAT_01b36c98 + DAT_0090408c * 4)) ||
               (*(char *)((int)&DAT_01b408d8 + DAT_0090408c + 3) != DAT_00904098)) {
              *(undefined4 *)(puVar2 + -0x14) = 0;
              goto LAB_00504cfd;
            }
            if (((&DAT_01b42feb)[DAT_0090408c] != '\0') &&
               (DAT_009040bc != (&DAT_01b42feb)[DAT_0090408c])) {
              *(undefined4 *)(puVar2 + -0x10) = 0;
              goto LAB_00504db2;
            }
            *(float *)(&DAT_01b456f8 + DAT_0090409c * 4) =
                 *(float *)(&DAT_01b456f8 + DAT_0090409c * 4) +
                 *(float *)(&DAT_01b456f8 + DAT_0090408c * 4);
            *(undefined1 *)((int)&DAT_01b34588 + DAT_0090408c + 3) = 99;
            *(undefined4 *)(&DAT_00906008 + DAT_0090409c * 4) = 1;
            *(undefined4 *)(puVar2 + -0xc) = 0;
            goto LAB_00504dcc;
          }
          *(undefined4 *)(puVar2 + -0x30) = 0;
        }
      }
      else {
        *(undefined4 *)(puVar2 + -0x54) = 0;
      }
LAB_00504db2:
      *(undefined1 *)((int)&DAT_01b34588 + LOAD_W + 3) = 7;
      (&DAT_01b42feb)[LOAD_W] = 0;
LAB_00504dcc:
      *(undefined4 *)(puVar2 + -4) = 0;
      DAT_009040ac = DAT_009040ac + 1;
      *(int *)(puVar2 + -0x58) = *(int *)(puVar2 + -0x58) + -1;
      iVar1 = *(int *)(puVar2 + -0x58);
    }
  }
  return;
code_r0x00504ba2:
  DAT_00904094 = DAT_00904094 + 1;
  *(int *)(puVar2 + -0x38) = *(int *)(puVar2 + -0x38) + -1;
  iVar1 = *(int *)(puVar2 + -0x38);
  goto joined_r0x00504b87;
}


