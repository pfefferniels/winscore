// box_outline @ 004a060d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void box_outline(void)

{
  add_point(&DAT_01f93e60,&DAT_01f93e64,&DAT_01f93e80);
  add_point(&DAT_01f93e68,&DAT_01f93e6c,&DAT_00763570);
  add_point(&DAT_01f93e70,&DAT_01f93e74,&DAT_00763570);
  add_point(&DAT_01f93e78,&DAT_01f93e7c,&DAT_00763570);
  add_point(&DAT_01f93e60,&DAT_01f93e64,&DAT_00763570);
  DAT_01f93e80 = 0;
  if (OUTPUT_MODE == -1) {
    add_point(&DAT_01f93e68,&DAT_01f93e6c,&DAT_01f93e80);
  }
  return;
}


