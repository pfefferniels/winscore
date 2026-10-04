/makeoutlinedict 7 dict def
/MakeOutlineFont
  {makeoutlinedict begin
    /uniqueid exch def
    /strokewidth exch def
    /newfontname exch def
    /basefontname exch def
  /basefontdict basefontname findfont def
  /numentries basefontdict maxlength 1 add def
 
  basefontdict /UniqueID known not
    {/numentries numentries 1 add def} if
      /outfontdict numentries dict def
      basefontdict
        {exch dup /FID ne
          {exch outfontdict 3 1 roll put }
          {pop pop} 
          ifelse 
      } forall 
 
   outfontdict /FontName newfontname put
   outfontdict /PaintType 2 put
   outfontdict /StrokeWidth strokewidth put
   outfontdict /UniqueID uniqueid put
     newfontname outfontdict definefont pop
     end }  def 
 

/rncsmdict 12 dict def /ReE
{ rncsmdict begin  /newcdnm exch def /nfnm exch def
/bfn exch def /bfdict bfn findfont def
/nfn bfdict maxlength dict def   bfdict { exch dup /FID ne
{ dup /Encoding eq { exch dup length array copy
nfn 3 1 roll put } { exch nfn 3 1 roll put }
ifelse }  { pop pop } ifelse } forall
nfn /FontName nfnm put newcdnm aload pop
newcdnm length 2 idiv  { nfn /Encoding get 3 1 roll put } repeat
nfnm nfn definefont pop end} def
/acc [ 0/aacute 1/agrave 2/acircumflex 3/adieresis
4/ccedilla 5/atilde 6/minus 7/aring 8/eacute 9/egrave
10/ecircumflex 11/edieresis 12/iacute 13/igrave 14/icircumflex
15/idieresis 16/oacute 17/ograve 18/ocircumflex 19/odieresis
20/otilde 21/uacute 22/ugrave 23/ucircumflex 24/udieresis
25/ydieresis 26/ntilde 27/scaron 28/zcaron 29/copyright
128/Aacute 129/Agrave 130/Acircumflex 131/Adieresis 132/Ccedilla
133/Atilde 134/registered 135/Aring 136/Eacute 137/Egrave
138/Ecircumflex 139/Edieresis 140/Iacute 141/Igrave 142/Icircumflex
143/Idieresis 144/Oacute 145/Ograve 146/Ocircumflex 147/Odieresis
148/Otilde 149/Uacute 150/Ugrave 151/Ucircumflex 152/Udieresis
153/Ydieresis 154/Ntilde 155/Scaron 156/Zcaron 157/trademark  
8#362/onequarter  243/onehalf 244/threequarters  252/underscore
245/onesuperior  246/twosuperior 247/threesuperior  ] def
% this must be here to end the file
