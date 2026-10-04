// FUN_00430ec0 @ 00430ec0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00430ec0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  do {
    *(undefined4 *)(puVar3 + -0xa8) = 0;
    *(undefined4 *)(puVar3 + -0xb8) = 0x80;
    *(char **)(puVar3 + -0xb4) = &DAT_01c5b1e4;
    *(uint **)(puVar3 + -0xb0) = &DAT_007f1480;
    FUN_005f47c0(puVar3 + -0xa8,0xffffffff,0x784ff00,&DAT_0075ffbc,puVar3 + -0xb8);
    if ((DAT_007f1480 & 1) == 0) {
      *(undefined4 *)(puVar3 + -0x84) = 0;
    }
    else {
      IP2 = 0;
      IP4 = 8;
      *(undefined4 *)(puVar3 + -0xa8) = 0;
      *(undefined4 *)(puVar3 + -0xb8) = 0x80;
      *(char **)(puVar3 + -0xb4) = &DAT_01c5b1e4;
      *(undefined4 *)(puVar3 + -0xb0) = 2;
      *(undefined4 *)(puVar3 + -0xac) = 4;
      FUN_005f6540(puVar3 + -0xa8,8,0x784ff00,&DAT_0075ffac,puVar3 + -0xb8);
      if (0 < IP4) {
        *(undefined4 *)(puVar3 + -0x7c) = 0;
LAB_00430fcb:
        do {
          *(undefined4 *)(puVar3 + -0xa8) = 0;
          iVar1 = FUN_005fdbd0(puVar3 + -0xa8,8,0x784ff03,&DAT_0075ffa8,0,&DAT_0078f2e8);
          *(int *)(puVar3 + -0x68) = iVar1;
          if (iVar1 == 0) {
            *(undefined4 *)(puVar3 + -0xac) = 0xa0;
            IP4 = 1;
            do {
              *(undefined4 *)(puVar3 + -0xc0) = 1;
              *(undefined1 **)(puVar3 + -0xbc) = &DAT_020b8e9f + IP4;
              *(undefined4 *)(puVar3 + -0xb8) = 1;
              iVar1 = FUN_005fe110(puVar3 + -0xa8,&DAT_0075ffa4,puVar3 + -0xc0);
              *(int *)(puVar3 + -0x68) = iVar1;
              if (iVar1 != 0) goto LAB_004310c1;
              IP4 = IP4 + 1;
              *(int *)(puVar3 + -0xac) = *(int *)(puVar3 + -0xac) + -1;
            } while (0 < *(int *)(puVar3 + -0xac));
            uVar2 = FUN_005fe110(puVar3 + -0xa8,&DAT_0075ffa0,0);
            *(undefined4 *)(puVar3 + -0x68) = uVar2;
          }
LAB_004310c1:
          if ((*(int *)(puVar3 + -0x68) == -1) || (*(int *)(puVar3 + -0x68) != 0)) {
LAB_004317b3:
            DAT_01c5b1e0 = 1;
            goto LAB_004317cf;
          }
          if ((char)DAT_020b8ea0 == ' ') {
            *(undefined4 *)(puVar3 + -100) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x60) = 0xa0;
            IP1 = 0xa0;
            while ((&DAT_020b8e9f)[IP1] != ';') {
              IP1 = IP1 + -1;
              *(int *)(puVar3 + -0x60) = *(int *)(puVar3 + -0x60) + -1;
              if (*(int *)(puVar3 + -0x60) < 1) {
                *(undefined4 *)(puVar3 + -0x58) = 0;
                goto LAB_00431763;
              }
            }
            *(undefined4 *)(puVar3 + -0x5c) = 0;
            (&DAT_020b8e9f)[IP1] = 0x20;
            *(undefined4 *)(puVar3 + -0x54) = 0xa0;
            IP4 = 1;
            do {
              if (IP1 == IP4) {
                *(undefined4 *)(puVar3 + -0x50) = 0;
                goto LAB_00431763;
              }
              if ((&DAT_020b8e9f)[IP4] == ';') {
                *(undefined4 *)(puVar3 + -0x4c) = 0;
                break;
              }
              IP4 = IP4 + 1;
              *(int *)(puVar3 + -0x54) = *(int *)(puVar3 + -0x54) + -1;
            } while (0 < *(int *)(puVar3 + -0x54));
            DAT_007f1464 = IP4 + -1;
            IP2 = 0;
            IP3 = 0;
            DAT_007f1460 = IP4 + 1;
            FUN_00431806(&DAT_007f1460,&IP4);
            if (1 < IP4 - DAT_007f1460) {
              *(undefined4 *)(puVar3 + -0x48) = 0;
              goto LAB_004317b3;
            }
            DAT_007f145c = (byte)(&DAT_020b8e9f)[DAT_007f1460] - 0x30;
            if (DAT_007f1460 < IP4) {
              DAT_007f145c = (uint)(byte)(&DAT_020b8e9f)[IP4] + DAT_007f145c * 10 + -0x30;
            }
            if (0x14 < DAT_007f145c) {
              *(undefined4 *)(puVar3 + -0x44) = 0;
              goto LAB_004317b3;
            }
            IP8 = 1;
            if ((char)DAT_020b8ea0 == '_') {
              IP8 = 4;
            }
            DAT_007f1458 = (byte)(&DAT_020b8e9f)[IP8] - 0x42;
            if (DAT_007f1458 < 1) {
              DAT_007f1458 = (byte)(&DAT_020b8e9f)[IP8] - 0x3b;
            }
            DAT_007f1454 = DAT_007f1458 * 2 + -2;
            if (DAT_007f1458 < 4) {
              DAT_007f1454 = DAT_007f1458 * 2 + -1;
            }
            if (*(char *)((int)&DAT_020b8ea0 + IP8) == '?') {
              DAT_007f1448 = *(char *)((int)&DAT_020b8ea0 + IP8 + 1);
              if (DAT_007f1448 == '1') {
                DAT_007f1454 = DAT_007f1454 + -1;
              }
              if (DAT_007f1448 == '2') {
                DAT_007f1454 = DAT_007f1454 + 1;
              }
            }
            else {
              *(undefined4 *)(puVar3 + -0x40) = 0;
            }
            if (0xc < DAT_007f1454) {
              DAT_007f1454 = 1;
            }
            if (DAT_007f1454 == 0) {
              DAT_007f1454 = 0xc;
            }
            FUN_005f46bc(puVar3,0x4313b1);
            FUN_005f34d1(puVar3,0x4313c7);
            DAT_007f1450 = 0;
            while (IP4 < IP1) {
              DAT_007f1460 = IP4 + 1;
              FUN_00431806(&DAT_007f1460,&IP4);
              DAT_007f1448 = (&DAT_020b8e9f)[DAT_007f1460];
              if (DAT_007f1448 == ' ') {
                *(undefined4 *)(puVar3 + -0x38) = 0;
                goto LAB_00430fcb;
              }
              DAT_007f1468 = 0;
              DAT_007f147c = 0;
              iVar1 = ((DAT_007f1460 - IP4) + -1) / -1;
              *(int *)(puVar3 + -0x34) = iVar1;
              DAT_007f1458 = IP4;
              while (0 < iVar1) {
                DAT_007f146c = (&DAT_020b8e9f)[DAT_007f1458];
                if (DAT_007f146c == 'x') {
                  DAT_007f146c = '9';
                }
                if (DAT_007f146c == 'o') {
                  DAT_007f146c = '8';
                }
                DAT_007f1474 = (int)DAT_007f146c;
                DAT_007f1478 = DAT_007f1474 + -0x30;
                DAT_007f1470 = FUN_005ff9b0(10,DAT_007f1468);
                DAT_007f147c = DAT_007f1470 * DAT_007f1478 + DAT_007f147c;
                DAT_007f1468 = DAT_007f1468 + 1;
                *(undefined4 *)(puVar3 + -0x30) = 0;
                DAT_007f1458 = DAT_007f1458 + -1;
                *(int *)(puVar3 + -0x34) = *(int *)(puVar3 + -0x34) + -1;
                iVar1 = *(int *)(puVar3 + -0x34);
              }
              if (IP3 == IP2) {
                if (IP2 == 5) {
                  *(undefined4 *)(puVar3 + -0x28) = 0;
                  goto LAB_004317b3;
                }
                IP2 = IP2 + 1;
                *(float *)(&DAT_01c5c37c + DAT_007f145c * 0x14 + DAT_007f1454 * 400 + IP2 * 4) =
                     (float)DAT_007f147c;
                *(undefined4 *)(puVar3 + -0x24) = 0;
              }
              else {
                *(undefined4 *)(puVar3 + -0x2c) = 0;
                if (DAT_007f1450 < 1) {
                  *(int *)(&DAT_01c5d63c + IP2 * 4 + DAT_007f1454 * 400 + DAT_007f145c * 0x14) =
                       DAT_007f147c;
                  DAT_007f1450 = DAT_007f1450 + 1;
                  *(undefined4 *)(puVar3 + -0x1c) = 0;
                }
                else {
                  *(undefined4 *)(puVar3 + -0x20) = 0;
                  *(int *)(&DAT_01c5e8fc + DAT_007f1454 * 400 + DAT_007f145c * 0x14 + IP2 * 4) =
                       DAT_007f147c;
                  DAT_007f1450 = 0;
                  if ((&DAT_020b8e9f)[IP4] == ';') {
                    *(undefined4 *)(puVar3 + -0x18) = 0;
                    goto LAB_0043167c;
                  }
                  IP3 = IP2;
                  if (IP2 == 5) goto LAB_0043167c;
                  *(undefined4 *)(puVar3 + -0x14) = 0;
                }
              }
            }
            *(undefined4 *)(puVar3 + -0x3c) = 0;
LAB_0043167c:
            if (IP2 == 5) {
              *(undefined4 *)(puVar3 + -0x10) = 0;
            }
            else {
              IP4 = IP2 + 1;
              iVar1 = 6 - IP4;
              *(int *)(puVar3 + -0xc) = iVar1;
              while (0 < iVar1) {
                *(int *)(&DAT_01c5c37c + DAT_007f145c * 0x14 + DAT_007f1454 * 400 + IP4 * 4) = i_0;
                *(undefined4 *)(&DAT_01c5e8fc + DAT_007f1454 * 400 + DAT_007f145c * 0x14 + IP4 * 4)
                     = 0;
                *(undefined4 *)(&DAT_01c5d63c + DAT_007f1454 * 400 + DAT_007f145c * 0x14 + IP4 * 4)
                     = 0;
                IP4 = IP4 + 1;
                *(int *)(puVar3 + -0xc) = *(int *)(puVar3 + -0xc) + -1;
                iVar1 = *(int *)(puVar3 + -0xc);
              }
              *(undefined4 *)(puVar3 + -8) = 0;
            }
          }
        } while( true );
      }
LAB_00431763:
      *(undefined4 *)(puVar3 + -0x78) = 0;
    }
    *(undefined4 *)(puVar3 + -0x74) = 0;
    DAT_01c5b1e4 = DAT_01c5b1e4 + '\x01';
    if ('z' < DAT_01c5b1e4) {
      IP7 = 0;
      *(undefined4 *)(puVar3 + -0x6c) = 0;
LAB_004317cf:
      *(undefined4 *)(puVar3 + -0xa8) = 0;
      FUN_005f7950(puVar3 + -0xa8,8,0x784ff00,&DAT_0075ff98,0);
      return;
    }
    *(undefined4 *)(puVar3 + -0x70) = 0;
  } while( true );
}


