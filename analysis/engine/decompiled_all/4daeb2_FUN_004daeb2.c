// FUN_004daeb2 @ 004daeb2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004daeb2(int *param_1,uint *param_2)

{
  char *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  if (*param_1 == 1) {
    iVar4 = 0xa0;
    DAT_01aad7d8 = 0xa0;
    do {
      if ((char)(&DAT_020b8e9f)[DAT_01aad7d8] < '!') break;
      DAT_01aad7d8 = DAT_01aad7d8 - 1;
      iVar4 = iVar4 + -1;
    } while (0 < iVar4);
    DAT_01aad7d4 = 1;
    do {
      DAT_01aad7d0 = (int)(char)(&DAT_020b8e9f)[DAT_01aad7d4];
      iVar4 = DAT_01aad7d4;
      if (DAT_01aad7d0 == 0x38) {
        iVar4 = DAT_01aad7d4 + 1;
        DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
        if (DAT_01aad7d0 != 0x56) {
          if (DAT_01aad7d0 != 0x42) goto LAB_004dafcf;
          puVar2 = &DAT_020b8e9f + DAT_01aad7d4;
          DAT_01aad7d4 = iVar4;
          *puVar2 = 0x4f;
          *param_2 = 0x4f;
          iVar4 = DAT_01aad7d4;
          goto LAB_004db74f;
        }
        puVar2 = &DAT_020b8e9f + DAT_01aad7d4;
        DAT_01aad7d4 = iVar4;
        *puVar2 = 0x4f;
        *param_2 = 0x4f;
        iVar4 = DAT_01aad7d4;
        goto LAB_004db6f8;
      }
LAB_004dafcf:
      DAT_01aad7d4 = iVar4;
      iVar3 = DAT_01aad7d4;
      iVar4 = DAT_01aad7d4;
      if (0x40 < DAT_01aad7d0) {
        if (DAT_01aad7d0 == 0x41) {
          iVar4 = DAT_01aad7d4 + 1;
          if (((*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4) != 'S') &&
              (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4) != 'O')) &&
             (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1) != 'T')) {
            if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4) == 'C') {
              iVar4 = DAT_01aad7d4 + 2;
              if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1) == ' ') goto LAB_004db7c3;
              if ((&DAT_020b8ea2)[DAT_01aad7d4] == 'S') {
                puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                DAT_01aad7d4 = iVar4;
                *puVar2 = 0x53;
                iVar4 = DAT_01aad7d4;
                goto LAB_004db6f8;
              }
              if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1) != 'L') goto LAB_004db71a;
              goto LAB_004db8c5;
            }
            if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4) == 'R') {
              puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
              DAT_01aad7d4 = iVar4;
              *puVar2 = 0x4f;
              iVar4 = DAT_01aad7d4;
              goto LAB_004db74f;
            }
          }
LAB_004db799:
          do {
            DAT_01aad7d4 = iVar4;
            iVar4 = DAT_01aad7d4 + 1;
          } while ('@' < *(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4));
        }
        else if (DAT_01aad7d0 == 0x43) {
          iVar4 = DAT_01aad7d4 + 1;
          if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4) == 'R') {
            iVar4 = DAT_01aad7d4 + 2;
            if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1) != 'S') {
              if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1) != 'H') goto LAB_004db799;
LAB_004db71a:
              DAT_01aad7d4 = DAT_01aad7d4 + 2;
              *(undefined1 *)((int)&DAT_020b8ea0 + iVar3) = 0x20;
              iVar4 = DAT_01aad7d4;
            }
            goto LAB_004db76a;
          }
        }
        else {
          if (DAT_01aad7d0 == 0x44) {
            iVar4 = DAT_01aad7d4 + 1;
            DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
            if (DAT_01aad7d0 == 0x4e) goto LAB_004db6f8;
            if (DAT_01aad7d0 != 0x49) {
              if (DAT_01aad7d0 != 0x43) goto LAB_004db799;
              puVar2 = &DAT_020b8e9f + DAT_01aad7d4;
              DAT_01aad7d4 = iVar4;
              *puVar2 = 0x43;
              *param_2 = 0x43;
              if ((&DAT_020b8e9d)[DAT_01aad7d4] == '-') {
                *param_2 = 0x2d;
              }
              (&DAT_020b8e9f)[DAT_01aad7d4] = 0x2d;
              iVar4 = DAT_01aad7d4;
            }
LAB_004db74f:
            DAT_01aad7d4 = iVar4;
            iVar4 = DAT_01aad7d4 + 1;
          }
          else if (DAT_01aad7d0 == 0x46) {
            iVar4 = DAT_01aad7d4 + 2;
            if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1) != 'R') goto LAB_004db799;
          }
          else {
            if (DAT_01aad7d0 == 0x48) {
              iVar4 = DAT_01aad7d4 + 1;
              DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
              if (DAT_01aad7d0 == 0x41) goto LAB_004db6f8;
              if (DAT_01aad7d0 == 0x56) {
                puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                DAT_01aad7d4 = iVar4;
                *puVar2 = 0x57;
                iVar4 = DAT_01aad7d4;
                goto LAB_004db74f;
              }
            }
            DAT_01aad7d4 = iVar4;
            if (DAT_01aad7d0 == 0x50) {
              iVar4 = DAT_01aad7d4 + 1;
              DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
              if ((DAT_01aad7d0 != 0x49) && (DAT_01aad7d0 != 0x5a)) goto LAB_004db799;
              if (DAT_01aad7d0 == 0x49) {
                puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                DAT_01aad7d4 = iVar4;
                *puVar2 = 0x5a;
                iVar4 = DAT_01aad7d4;
              }
              goto LAB_004db74f;
            }
            if (DAT_01aad7d0 == 0x52) {
              DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1);
              iVar4 = DAT_01aad7d4 + 2;
              if (DAT_01aad7d0 != 0x54) goto LAB_004db7c3;
            }
            else {
              if (DAT_01aad7d0 == 0x53) {
                iVar4 = DAT_01aad7d4 + 1;
                DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                if (DAT_01aad7d0 != 0x54) goto LAB_004db799;
                if ((&DAT_020b8ea2)[DAT_01aad7d4] == 'C') {
                  puVar2 = &DAT_020b8ea2 + DAT_01aad7d4;
                  DAT_01aad7d4 = iVar4;
                  *puVar2 = 0x20;
                  iVar4 = DAT_01aad7d4;
                }
              }
              else if (DAT_01aad7d0 == 0x54) {
                iVar4 = DAT_01aad7d4 + 1;
                DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                if (DAT_01aad7d0 != 0x45) {
                  if (DAT_01aad7d0 == 0x52) {
                    iVar4 = DAT_01aad7d4 + 2;
                    DAT_01aad7d0 = (int)*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1);
                    if (DAT_01aad7d0 == 0x45) {
                      puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                      DAT_01aad7d4 = iVar4;
                      *puVar2 = 0x4d;
                      (&DAT_020b8e9f)[DAT_01aad7d4] = 0x20;
                      iVar4 = DAT_01aad7d4;
                      if ((*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4) == 'M') &&
                         (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1) != ' ')) {
                        (&DAT_020b8e9f)[DAT_01aad7d4] =
                             *(undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4 + 1);
                        iVar4 = DAT_01aad7d4 + 1;
                      }
                      goto LAB_004db6f8;
                    }
                    if (DAT_01aad7d0 == 0x49) {
                      iVar3 = DAT_01aad7d4 + 1;
                      DAT_01aad7d4 = iVar4;
                      *(undefined1 *)((int)&DAT_020b8ea0 + iVar3) = 0x20;
                      DAT_01aad7d0 = DAT_01aad7d4;
                      while( true ) {
                        pcVar1 = (char *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                        DAT_01aad7cc = (int)*pcVar1;
                        if (DAT_01aad7cc != 0x4c) break;
                        puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                        DAT_01aad7d4 = DAT_01aad7d4 + 1;
                        *puVar2 = 0x20;
                      }
                      DAT_01aad7d4 = DAT_01aad7d4 + 1;
                      (&DAT_020b8e9f)[DAT_01aad7d0] = *pcVar1;
                      iVar4 = DAT_01aad7d4;
                      goto LAB_004db76a;
                    }
                  }
                  goto LAB_004db7c3;
                }
                if ((&DAT_020b8ea2)[DAT_01aad7d4] == 'U') {
                  puVar2 = &DAT_020b8ea2 + DAT_01aad7d4;
                  DAT_01aad7d4 = iVar4;
                  *puVar2 = 0x20;
                  iVar4 = DAT_01aad7d4;
                }
                else {
                  if ((&DAT_020b8ea2)[DAT_01aad7d4] != 'S') goto LAB_004db7c3;
                  puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                  DAT_01aad7d4 = iVar4;
                  *puVar2 = 0x53;
                  iVar4 = DAT_01aad7d4 + 1;
                }
              }
              else if ((DAT_01aad7d0 != 0x55) ||
                      (pcVar1 = (char *)((int)&DAT_020b8ea0 + DAT_01aad7d4),
                      iVar4 = DAT_01aad7d4 + 1, DAT_01aad7d4 = DAT_01aad7d4 + 1, *pcVar1 == ' ')) {
                iVar4 = DAT_01aad7d4;
                if ((DAT_01aad7d0 != 0x57) ||
                   (iVar4 = DAT_01aad7d4 + 1, *(char *)((int)&DAT_020b8ea0 + DAT_01aad7d4) != 'E'))
                goto LAB_004db7c3;
                if ((&DAT_020b8ea2)[DAT_01aad7d4] != ' ') {
                  puVar2 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4);
                  DAT_01aad7d4 = iVar4;
                  *puVar2 = 0x53;
                  iVar4 = DAT_01aad7d4 + 1;
                }
              }
LAB_004db6f8:
              DAT_01aad7d4 = iVar4;
              *(undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7d4) = 0x20;
              iVar4 = DAT_01aad7d4;
            }
          }
LAB_004db76a:
          DAT_01aad7d4 = iVar4;
          (&DAT_020b8e9f)[DAT_01aad7d4] = 0x20;
          iVar4 = DAT_01aad7d4;
        }
      }
LAB_004db7c3:
      DAT_01aad7d4 = iVar4;
      DAT_01aad7d4 = DAT_01aad7d4 + 1;
    } while (DAT_01aad7d4 < (int)DAT_01aad7d8);
  }
  DAT_01aad7c8 = DAT_01fb8cc0;
  DAT_01aad7c0 = *param_1;
  DAT_01aad7cc = 0;
  DAT_01aad7dc = *param_2;
  if ((DAT_01aad7dc == 0x2d) || (DAT_01aad7dc == 0x2b)) {
    DAT_01aad7cc = 1;
    DAT_01aad7dc = (uint)*(byte *)((int)&DAT_020b8ea0 + DAT_01aad7c0);
    DAT_01aad7c0 = DAT_01aad7c0 + 1;
  }
  DAT_01aad7d4 = DAT_01aad7c0 + 1;
  DAT_01aad7d0 = thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
  iVar4 = DAT_01aad7d4;
  switch(DAT_01aad7dc) {
  case 0x41:
LAB_004db8c5:
    DAT_01aad7d4 = iVar4;
    DAT_01aad7d8 = 5;
    if (DAT_01aad7c4 == 0x43) {
      DAT_01aad7d8 = 0x44;
      thunk_FUN_00526ec4(&DAT_01aad7dc,&DAT_01aad7c0,&DAT_01fbb704);
      if (DAT_01aad7dc == 0x54) {
        DAT_01aad7d8 = 0x19;
        goto LAB_004dc1d7;
      }
    }
    if (DAT_01aad7c4 == 0x52) {
      DAT_01aad7d8 = 0xf;
    }
    if (DAT_01aad7c4 == 0x53) {
      DAT_01aad7d8 = 9;
    }
    if (DAT_01aad7c4 == 0x4f) {
      DAT_01aad7d8 = 0x43;
    }
    if (DAT_01aad7c0 == DAT_01aad7d4) goto LAB_004dc1d7;
    break;
  default:
LAB_004dc484:
    thunk_FUN_005259e5(&DAT_01aad7c0);
LAB_004dc4a0:
    *param_1 = DAT_01aad7c0;
    DAT_01fb8cc0 = DAT_01aad7c8;
    return;
  case 0x43:
    DAT_01aad7d8 = 0x61;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      if (DAT_01aad7c4 == 0x52) {
        DAT_01aad7d8 = 0x3f;
      }
      if (DAT_01aad7c4 == 0x2d) {
        DAT_01aad7d8 = 0x62;
      }
      goto LAB_004dc1d7;
    }
    break;
  case 0x44:
    DAT_01aad7d8 = 0xb;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      if (DAT_01aad7c4 == 0x49) {
        DAT_01aad7d8 = 0x40;
      }
      goto LAB_004dc1d7;
    }
    break;
  case 0x46:
    DAT_01aad7d8 = 0x38;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      if (DAT_01aad7c4 == 0x50) {
        DAT_01aad7d8 = 0x3c;
        goto LAB_004dc1d7;
      }
      if (DAT_01aad7c4 != 0x46) {
        if (DAT_01aad7c4 == 0x45) {
          DAT_01aad7d8 = 0xe;
        }
        else if (DAT_01aad7c4 == 0x49) {
          DAT_01aad7d4 = DAT_01aad7c0 + 1;
          thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
          DAT_01aad7d8 = 1;
          if (DAT_01aad7c4 == 0x53) {
            DAT_01aad7d8 = 2;
          }
          if (DAT_01aad7c4 == 0x4e) {
            DAT_01aad7d8 = 3;
          }
        }
        else {
          if ((DAT_01aad7c4 < 0x30) || (0x39 < DAT_01aad7c4)) goto LAB_004dc484;
          DAT_01aad7d8 = DAT_01aad7c4 - 0x12;
        }
        goto LAB_004dc1d7;
      }
      DAT_01aad7d8 = 0x39;
      DAT_01aad7d4 = DAT_01aad7c0 + 1;
      DAT_01aad7d0 = thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
      if (DAT_01aad7c0 == DAT_01aad7d4) {
        if (DAT_01aad7c4 != 0x46) goto LAB_004dc484;
        DAT_01aad7d8 = 0x3a;
        goto LAB_004dc1d7;
      }
    }
    break;
  case 0x48:
    DAT_01aad7d8 = 0xd;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      DAT_01aad7d8 = 0x13;
      goto LAB_004dc1d7;
    }
    break;
  case 0x49:
    DAT_01aad7d8 = 0x12;
    goto joined_r0x004dbead;
  case 0x4d:
    DAT_01aad7d8 = 0x11;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      if (DAT_01aad7c4 == 0x46) {
        DAT_01aad7d8 = 0x37;
      }
      if (DAT_01aad7c4 == 0x50) {
        DAT_01aad7d8 = 0x36;
      }
      goto LAB_004dc1d7;
    }
    break;
  case 0x4e:
    fVar5 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
    DAT_01aad7d8 = (uint)ROUND(-fVar5);
    goto LAB_004dc1d7;
  case 0x4f:
    DAT_01aad7d8 = 0x60;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      if (DAT_01aad7c4 == 0x42) {
        DAT_01aad7d8 = 0x5f;
      }
      goto LAB_004dc1d7;
    }
    break;
  case 0x50:
    DAT_01aad7d8 = 0x35;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      if (DAT_01aad7c4 != 0x50) {
        DAT_01aad7d8 = 0x18;
        if (DAT_01aad7c4 == 0x5a) {
          DAT_01aad7d8 = 0x42;
        }
        goto LAB_004dc1d7;
      }
      DAT_01aad7d8 = 0x34;
      DAT_01aad7d4 = DAT_01aad7c0 + 1;
      thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
      if (DAT_01aad7c0 == DAT_01aad7d4) {
        DAT_01aad7d8 = 0x33;
        goto LAB_004dc1d7;
      }
    }
    break;
  case 0x52:
    DAT_01aad7d8 = 0x41;
joined_r0x004dbead:
    if (DAT_01aad7c0 == DAT_01aad7d4) goto LAB_004dc1d7;
    break;
  case 0x53:
    DAT_01aad7d8 = 7;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      DAT_01aad7d8 = 0x3d;
      if ((0x31 < DAT_01aad7c4) && (DAT_01aad7c4 < 0x35)) {
        DAT_01aad7d8 = DAT_01aad7c4 - 0x18;
      }
      DAT_01aad7d4 = DAT_01aad7c0 + 1;
      thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
      if (DAT_01aad7c0 == DAT_01aad7d4) {
        DAT_01aad7d8 = 0x3e;
        goto LAB_004dc1d7;
      }
    }
    break;
  case 0x54:
    DAT_01aad7d8 = 6;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      if (DAT_01aad7c4 == 0x53) {
        DAT_01aad7d8 = 10;
        goto LAB_004dc1d7;
      }
      if (DAT_01aad7c4 == 0x48) {
        DAT_01aad7d8 = 0x10;
        goto LAB_004dc1d7;
      }
      if (DAT_01aad7c4 == 0x52) {
        DAT_01aad7d8 = 0x14;
        while( true ) {
          DAT_01aad7d4 = DAT_01aad7c0 + 1;
          DAT_01aad7d0 = thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
          if (DAT_01aad7c0 != DAT_01aad7d4) break;
          if (DAT_01aad7c4 == 0x57) {
            DAT_01aad7d8 = DAT_01aad7d8 + 100;
            goto LAB_004dc1d7;
          }
          DAT_01aad7d8 = 0x15;
          if (DAT_01aad7c4 == 0x53) {
            DAT_01aad7d8 = 0x16;
          }
          if (DAT_01aad7c4 == 0x4e) {
            DAT_01aad7d8 = 0x17;
          }
        }
      }
      else {
        DAT_01aad7d8 = 0x5d;
        DAT_01aad7d4 = DAT_01aad7c0 + 1;
        thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
        if (DAT_01aad7c0 == DAT_01aad7d4) {
          if (DAT_01aad7c4 == 0x45) {
            DAT_01aad7d8 = 0x5b;
          }
          if (DAT_01aad7c4 == 0x53) {
            DAT_01aad7d8 = 0x5c;
          }
          if ((DAT_01aad7c4 < 0x35) && (0x30 < DAT_01aad7c4)) {
            DAT_01aad7d8 = DAT_01aad7c4 + 0x2a;
          }
          goto LAB_004dc1d7;
        }
      }
    }
    break;
  case 0x55:
    DAT_01aad7d8 = 0xc;
    break;
  case 0x57:
    DAT_01aad7d8 = 4;
    if (DAT_01aad7c0 == DAT_01aad7d4) {
      DAT_01aad7d8 = 8;
      goto LAB_004dc1d7;
    }
  }
  DAT_01aad7c0 = DAT_01aad7c0 + -1;
LAB_004dc1d7:
  DAT_01aad7c8 = DAT_01aad7c8 + 1;
  DAT_01aad7e8 = DAT_01aad7d8;
  DAT_01aad7d0 = DAT_01aad7cc;
  if ((int)DAT_01aad7d8 < 0) {
    DAT_01aad7d0 = -DAT_01aad7cc;
  }
  *(int *)(&DAT_01aada3c + DAT_01aad7c8 * 4) = DAT_01aad7d0;
  (&DAT_01fb8cc0)[DAT_01aad7c8] = (int)(float)(int)(DAT_01aad7e8 * 10000);
  do {
    DAT_01aad7d0 = thunk_FUN_00526ec4(&DAT_01aad7dc,&DAT_01aad7c0,&DAT_01fbb704);
    while ((DAT_01aad7d8 = (uint)(byte)(&DAT_020b8e9f)[DAT_01aad7c0], DAT_01aad7d8 != 0x55 ||
           (DAT_01aad7e8 != 0x18))) {
      if ((DAT_01aad7d8 == 0x2d) || (DAT_01aad7d8 == 0x2b)) {
        DAT_01aad7d8 = (uint)*(byte *)((int)&DAT_020b8ea0 + DAT_01aad7c0);
      }
      if (((DAT_01aad7d8 != 0x20) && (DAT_01aad7d8 < 0x2e || 0x39 < DAT_01aad7d8)) ||
         (DAT_01aad7d8 == 0x2f)) goto LAB_004dc484;
      fVar5 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
      DAT_01aad7ec = (float)fVar5;
      DAT_01aad7c0 = DAT_01aad7c0 + -1;
      iVar4 = thunk_FUN_00526ec4(&DAT_01aad7dc,&DAT_01aad7c0,&DAT_01fbb704);
      if (iVar4 != 0) {
        DAT_01ade8e0 = DAT_01aad7ec;
        goto LAB_004dc4a0;
      }
      DAT_01aad7c8 = DAT_01aad7c8 + 1;
      if ((DAT_01aad7dc == 0x3a) || (DAT_01aad7dc == 0x27)) {
        if (((int)DAT_01aad7e8 < 0x5f) || (0x62 < (int)DAT_01aad7e8)) {
          DAT_01aad7ec = DAT_01aad7ec + f_1000;
        }
        (&DAT_01fb8cc0)[DAT_01aad7c8] = (int)DAT_01aad7ec;
        DAT_01aad7d0 = thunk_FUN_00526ec4(&DAT_01aad7dc,&DAT_01aad7c0,&DAT_01fbb704);
      }
      else {
        (&DAT_01fb8cc0)[DAT_01aad7c8] = (int)DAT_01aad7ec;
      }
    }
    DAT_01aad7c0 = DAT_01aad7c0 + 1;
    DAT_01aad7d8 = 0x55;
  } while( true );
}


