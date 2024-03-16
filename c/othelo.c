/*
 * Title: The annotated BASIC Listing
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/othelo/basic/othelo.bas: 
 *
                   +----+---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   |    | +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    |    | |
        Address    v    v v Original BASIC statement
    -------------- ------ - ------------------------------------------------------------------------------
    0x55bc7eab5d30 ---------A   01000 REM********		OTHELLO          BYTE VOL. 2, NUMBER 10 (OCT. 1977)
    0x55bc7eab5e20 ---------A   01010 REM********		PLAYS THE GAME OTHELLO WITH TWO STRATEGIES
    0x55bc7eab5f00 ---------A   01020 REM********		1. TAKE THE MAX. NUMBER OF PIECES
    0x55bc7eab5ff0 ---------A   01030 REM********		2. ADD A BONUS FOR OUTSIDE POSITION
    0x55bc7eab60d0 ---------A   01040 REM********		BOARD IS THE ARRAY A, BOUNDED BY 0'S (BLANKS)
    0x55bc7eab61a0 ---------A   01050 REM********		A = 0 FOR EMPTY SQUARE
    0x55bc7eab6250 ---------A   01060 REM********		A = B FOR BLACK SQUARE
    0x55bc7eab6300 ---------A   01070 REM********		A = W FOR WHITE SQUARE
    0x55bc7eab63e0 ---------A   01080 REM********		I AND J ARE ALWAYS USED FOR ROW/COLUMN INDICES
    0x55bc7eab6500 ---------A   01090 REM********		I1 AND J4 STORE INCREMENTS TO THE 8 NEIGHBOURS
    0x55bc7eab65e0 ---------A   01100 REM********		C$ AND D$ STORE CHARACTERS A-H,X,...,O FOR OUTPUT
    0x55bc7eabb0a0 ---------A   01110 DIM A(9,9),I4(8),J4(8),C$(8),D$(2)
    0x55bc7eabb100 ---------A   01120 REM********		
    0x55bc7eabb280 ---------A   01130 PRINT "GREETINGS FROM OTHELLO!"
    0x55bc7eabb3e0 ---------A   01140 PRINT "DO YOU WANT INSTRUCTIONS (Y OR N)";
    0x55bc7eabb540 ---------A T 01150 INPUT X$
    0x55bc7eabb730 ---------A   01160 IF X$ = "N" THEN 1380
    0x55bc7eabba20 ---------A   01170 IF X$ <> "Y" THEN 1150
    0x55bc7eabbac0 ---------A   01180 PRINT
    0x55bc7eabbc40 ---------A   01190 PRINT "OTHELLO IS PLAYED ON AN 8X8 CHECKER BOARD"
    0x55bc7eabbdc0 ---------A   01200 PRINT "ROWS ARE NUMBERED FROM 1 TO 8 AND COLUMNS FROM A TO H"
    0x55bc7eabbf40 ---------A   01210 PRINT" THE INITIAL CONFIGURATION IS ALL BLANK EXCEPT FOR"
    0x55bc7eabc0a0 ---------A   01220 PRINT "THE CENTER FOUR SQUARES, WHICH FORM THE PATTERN:"
    0x55bc7eabc1e0 ---------A   01230 PRINT "               O X"
    0x55bc7eabc310 ---------A   01240 PRINT "               X O"
    0x55bc7eabc3b0 ---------A   01250 PRINT
    0x55bc7eabc540 ---------A   01260 PRINT "TRY TO PLACE YOUR PIECE SO THAT IT WILL 'OUTFLANK' MINE"
    0x55bc7eabc6c0 ---------A   01270 PRINT "THEREBY CREATING A HORIZONTAL, VERTICAL, OR DIAGONAL "
    0x55bc7eabc840 ---------A   01280 PRINT "RUN OF MY PIECES BOUNDED AT EACH END BY AT LEAST ONE "
    0x55bc7eabc9a0 ---------A   01290 PRINT "OF YOURS.  THIS WILL 'FLIP' MY PIECES, TURNING THEM INTO"
    0x55bc7eabcb00 ---------A   01300 PRINT "YOURS."
    0x55bc7eabcc80 ---------A   01310 PRINT"     NOTE: YOU MUST CAPTURE AT LEAST ONE OF MY PIECES"
    0x55bc7eabce00 ---------A   01320 PRINT "IN THIS WAY IF IT IS AT ALL POSSIBLE.  IF IT IS NOT"
    0x55bc7eabd180 ---------A   01330 PRINT "POSSIBLE, YOU FORFEIT YOUR TURN BY ENTERING"
    0x55bc7eabd2d0 ---------A   01340 PRINT "     0,0   FOR YOUR ROW,COLUMN MOVE"
    0x55bc7eabd400 ---------A   01350 PRINT " GOOD LUCK!"
    0x55bc7eabd470 ---------A   01360 PRINT
    0x55bc7eabd4e0 ---------A   01370 REM********		
    0x55bc7eabd690 ---------A T 01380 PRINT "SHOULD I WAIT BEFORE MAKING MY MOVES (Y OR N)";
    0x55bc7eabd880 ---------A   01390 F2 = 0
    0x55bc7eabda70 ---------A   01400 F9 = 1
    0x55bc7eabdb50 ---------A T 01410 INPUT X$
    0x55bc7eabdd40 ---------A   01420 IF X$ = "N" THEN 1460
    0x55bc7eabdf20 ---------A   01430 IF X$ <> "Y" THEN  1410
    0x55bc7eabe0d0 ---------A   01440 F2 = 1
    0x55bc7eabe240 ---------A   01450         PRINT "OK.  TYPING ANY CHARACTER WILL LET ME GO"
    0x55bc7eabe3b0 ---------A T 01460 PRINT "SHOULD I PLAY MY BEST STRATEGY (Y OR N)";
    0x55bc7eabe5a0 ---------A   01470 S2 = 0
    0x55bc7eabe680 ---------A T 01480 INPUT X$
    0x55bc7eabe870 ---------A   01490 IF X$ = "N" THEN 1520
    0x55bc7eabea50 ---------A   01500 IF X$ <> "Y" THEN 1480
    0x55bc7eabebd0 ---------A   01510 S2 = 2
    0x55bc7eabedc0 ---------A T 01520 B = -1
    0x55bc7eabefb0 ---------A   01530 W = +1
    0x55bc7eabf280 ---------A   01540 D$(B +1) ="X"
    0x55bc7eabf590 ---------A   01550 D$(0 +1) = "."
    0x55bc7eabf860 ---------A   01560 D$(W + 1) ="O"
    0x55bc7eabfaf0 ---------A   01570 FOR K = 1 TO 8
    0x55bc7eabfc30 ---------A   01580     READ I4(K)
    0x55bc7eabfcd0 ---------A   01590 NEXT K
    0x55bc7eac0360 ---------A   01600 DATA 0,-1,-1,-1,0,1,1,1
    0x55bc7eac0570 ---------A   01610 FOR K=1 TO 8
    0x55bc7eac06b0 ---------A   01620     READ J4(K)
    0x55bc7eac0750 ---------A   01630 NEXT K
    0x55bc7eac0de0 ---------A   01640 DATA 1,1,0,-1,-1,-1,0,1
    0x55bc7eac1400 ---------A   01650 FOR K = 1 TO 8
    0x55bc7eac1540 ---------A   01660     READ C$(K)
    0x55bc7eac15e0 ---------A   01670 NEXT K
    0x55bc7eac1c80 ---------A   01680 DATA A,B,C,D,E,F,G,H
    0x55bc7eac1d00 ---------A   01690 REM********		SET UP A NEW GAME
    0x55bc7eac1fa0 ---------A T 01700 FOR I = 0 TO 9
    0x55bc7eac2240 ---------A   01710     FOR J = 0 TO 9
    0x55bc7eac2480 ---------A   01720 	A(I,J)=0
    0x55bc7eac2530 ---------A   01730     NEXT J
    0x55bc7eac25f0 ---------A   01740 NEXT I
    0x55bc7eac2870 ---------A   01750 A(4,4) = W
    0x55bc7eac2ae0 ---------A   01760 A(5,5) = W
    0x55bc7eac2d50 ---------A   01770 A(4,5) = B
    0x55bc7eac2fc0 ---------A   01780 A(5,4) = B
    0x55bc7eac31b0 ---------A   01790 C1 = 2
    0x55bc7eac33a0 ---------A   01800 H1 = 2
    0x55bc7eac3590 ---------A   01810 N1 = 4
    0x55bc7eac3790 ---------A   01820 Z =0
    0x55bc7eac3810 ---------A   01830 REM********		HUMAN'S CHOICES
    0x55bc7eac39a0 ---------A   01840 PRINT "DO YOU WANT TO HAVE X OR O";
    0x55bc7eac3b50 ---------A   01850 C = W
    0x55bc7eac3d00 ---------A   01860 H = B
    0x55bc7eac3de0 ---------A T 01870 INPUT X$
    0x55bc7eac3fd0 ---------A   01880 IF X$ = "X" THEN 1920
    0x55bc7eac41b0 ---------A   01890 IF X$ <> "O" THEN 1870
    0x55bc7eac42f0 ---------A   01900 C = B
    0x55bc7eac4440 ---------A   01910 H = W
    0x55bc7eac45a0 ---------A T 01920 PRINT "DO YOU WANT TO GO FIRST (Y OR N)";
    0x55bc7eac4670 ---------A T 01930 INPUT X$
    0x55bc7eac4880 ---------A   01940 PRINT CHR$(26)
    0x55bc7eac4a60 ---------A   01950 IF X$ = "N" THEN 2030
    0x55bc7eac4c50 ---------A   01960 IF X$ <> "Y" THEN 1930
    0x55bc7eac4ce0 ---------A   01970 REM********		PRINT INITIAL BOARD
    0x55bc7eac4d60 ---------A   01980 GOSUB 4320
    0x55bc7eac4dd0 ---------A   01990 GO TO 2760
    0x55bc7eac4e40 ---------A   02000 REM********		COMPUTER'S MOVE
    0x55bc7eac5010 ---------A T 02010 IF F2 = 0 THEN 2030
    0x55bc7eac50f0 ---------A   02020 INPUT X$
    0x55bc7eac52f0 ---------A T 02030 B1 = -1
    0x55bc7eac55c0 ---------A   02040 I3 = J3 = 0
    0x55bc7eac5770 ---------A   02050 T1 = C
    0x55bc7eac5930 ---------A   02060 T2 = H
    0x55bc7eac59b0 ---------A   02070 REM********		SCAN FOR BLANK SQUARE
    0x55bc7eac5bd0 ---------A   02080 FOR I = 1 TO 8
    0x55bc7eac5e00 ---------A   02090     FOR J = 1 TO 8
    0x55bc7eac6090 ---------A   02100 	IF A(I,J) <> 0 THEN 2390
    0x55bc7eac6120 ---------A   02110 	REM********		FOUND A BLANK SQUARE
    0x55bc7eac61f0 ---------A   02120 	REM********		DOES IT HAVE AN OPPONENT AS A NEIGHBOUR
    0x55bc7eac6280 ---------A   02130 	GOSUB 3840
    0x55bc7eac64c0 ---------A   02140 	IF F1 = 0 THEN 2390
    0x55bc7eac6560 ---------A   02150 	REM********		FOUND OPPONENT AS NEIGHBOUR
    0x55bc7eac6620 ---------A   02160 	REM********		HOW MANY OF HIS PIECES CAN WE FLIP?
    0x55bc7eac66c0 ---------A   02170 	REM********		DON'T DO IT NOW
    0x55bc7eac68c0 ---------A   02180 	U = -1
    0x55bc7eac6950 ---------A   02190 	GOSUB 4040
    0x55bc7eac69d0 ---------A   02200 	REM********		EXTRA POINTS FOR BOUNDARY POSITION
    0x55bc7eac6c30 ---------A   02210 	IF S1 = 0 THEN 2390
    0x55bc7eac70d0 ---------A   02220 	IF (I-1) * (I-8) <> 0 THEN 2240
    0x55bc7eac72c0 ---------A   02230 	S1 = S1 + S2
    0x55bc7eac7750 ---------A T 02240 	IF (J-1) * (J-8) <> 0 THEN 2270
    0x55bc7eac7960 ---------A   02250 	S1 = S1 +S2
    0x55bc7eac79f0 ---------A   02260 	REM********		IS THIS BETTER THAN THE BEST FOUND SO FAR
    0x55bc7eac7b90 ---------A T 02270 	IF S1 < B1 THEN 2390
    0x55bc7eac7d30 ---------A   02280 	IF S1 > B1 THEN 2350
    0x55bc7eac85d0 ---------A   02290 	REM********		A TIE; RANDOM DECISION
    0x55bc7eac86a0 ---------A   02300 	REM********		THE NEXT TWO EXECUTABLE STATEMENTS ARE FOR
    0x55bc7eac8750 ---------A   02310 	REM********		BASIC WITH RANDOM NUMBERS
    0x55bc7eac8a40 ---------A   02320 	R = RND(1)
    0x55bc7eac8bf0 ---------A   02330 	IF R > .5 THEN 2390
    0x55bc7eac8c70 ---------A   02340 	REM********		YES
    0x55bc7eac8db0 ---------A T 02350 	B1 = S1
    0x55bc7eac8ee0 ---------A   02360 	I3 = I
    0x55bc7eac9020 ---------A   02370 	J3 = J
    0x55bc7eac90a0 ---------A   02380 	REM********		END OF SCAN LOOP
    0x55bc7eac9160 ---------A T 02390     NEXT J
    0x55bc7eac9220 ---------A   02400 NEXT I
    0x55bc7eac92c0 ---------A   02410 REM********		COULD WE DO ANYTHING?
    0x55bc7eac9490 ---------A   02420 IF B1 > 0 THEN 2510
    0x55bc7eac9510 ---------A   02430 REM********		NO
    0x55bc7eac9710 ---------A   02440 LET L = 18
    0x55bc7eac97a0 ---------A   02450 GOSUB 4490
    0x55bc7eac98d0 ---------A   02460 PRINT "DAMN! HAVE TO FORFEIT MY MOVE!"
    0x55bc7eac9a80 ---------A   02470 IF Z = 1 THEN 3370
    0x55bc7eac9c00 ---------A   02480 Z = 1
    0x55bc7eac9c80 ---------A   02490 GO TO 2760
    0x55bc7eac9cf0 ---------A   02500 REM********		MAKE THE MOVE
    0x55bc7eac9e70 ---------A T 02510 Z = 0
    0x55bc7eac9fe0 ---------A   02520 LET L=15
    0x55bc7eaca060 ---------A   02530 GOSUB 4490
    0x55bc7eaca1a0 ---------A   02540 PRINT "I WILL MOVE TO ";
    0x55bc7eaca290 ---------A   02550 PRINT I3;
    0x55bc7eaca3e0 ---------A   02560 PRINT " , ";
    0x55bc7eaca510 ---------A   02570 PRINT C$(J3)
    0x55bc7eaca640 ---------A   02580 I= I3
    0x55bc7eaca770 ---------A   02590 J= J3
    0x55bc7eaca8e0 ---------A   02600 U= 1
    0x55bc7eaca950 ---------A   02610 GOSUB 4040
    0x55bc7eacabf0 ---------A   02620 C1 = C1 + S1 + 1
    0x55bc7eacadc0 ---------A   02630 H1 = H1 - S1
    0x55bc7eacafd0 ---------A   02640 N1 = N1 + 1
    0x55bc7eacb140 ---------A   02650 LET L=16
    0x55bc7eacb1c0 ---------A   02660 GOSUB 4490
    0x55bc7eacb300 ---------A   02670 PRINT " THAT GIVES ME : ";
    0x55bc7eacb400 ---------A   02680 PRINT S1;
    0x55bc7eacb540 ---------A   02690 PRINT " OF YOUR PIECES"
    0x55bc7eacb5c0 ---------A   02700 REM********		PRINT OUT BOARD
    0x55bc7eacb650 ---------A   02710 GOSUB 4320
    0x55bc7eacb6c0 ---------A   02720 REM********		TEST FOR END OF GAME
    0x55bc7eacb8a0 ---------A   02730 IF H1 = 0 THEN 3370
    0x55bc7eacba70 ---------A   02740 IF N1 = 64 THEN 3370
    0x55bc7eacbb00 ---------A   02750 REM********		HUMANS MOVE
    0x55bc7eacbc40 ---------A T 02760 T1 = H
    0x55bc7eacbd70 ---------A   02770 T2 = C
    0x55bc7eacbee0 ---------A   02780 LET L = 12
    0x55bc7eacbf60 ---------A   02790 GOSUB 4490
    0x55bc7eacc0a0 ---------A T 02800 PRINT " YOUR MOVE";
    0x55bc7eacc1d0 ---------A T 02810 INPUT I, X$
    0x55bc7eacc390 ---------A   02820 IF I < 0 THEN 2810
    0x55bc7eacc560 ---------A   02830 IF I > 8 THEN 2810
    0x55bc7eacc720 ---------A   02840 IF I <> 0 THEN 2930
    0x55bc7eacc8a0 ---------A   02850 LET L = 18
    0x55bc7eacc930 ---------A   02860 GOSUB 4490
    0x55bc7eacca60 ---------A   02870 PRINT "ARE YOU FORFEITING YOUR TURN Y OR N"
    0x55bc7eaccb40 ---------A   02880 INPUT X$
    0x55bc7eaccd20 ---------A   02890 IF X$ <> "Y" THEN 2800
    0x55bc7eaccee0 ---------A   02900 IF Z = 1 THEN 3370
    0x55bc7eacd060 ---------A   02910 Z = 1
    0x55bc7eacd0d0 ---------A   02920 GO TO 2010
    0x55bc7eacd2e0 ---------A T 02930 FOR J = 1 TO 8
    0x55bc7eacd4c0 ---------A   02940     IF C$(J) =X$ THEN 2980
    0x55bc7eacd580 ---------A   02950 NEXT J
    0x55bc7eacd610 ---------A   02960 GO TO 2810
    0x55bc7eacd680 ---------A   02970 REM********		CHECK FOR BLANK
    0x55bc7eacd910 ---------A T 02980 IF A(I,J) = 0 THEN 3040
    0x55bc7eacda90 ---------A   02990 LET L = 18
    0x55bc7eacdb20 ---------A   03000 GOSUB 4490
    0x55bc7eacdc60 ---------A   03010 PRINT "SORRY, THAT SQUARE IS OCCUPIED, TRY AGAIN"
    0x55bc7eacdcf0 ---------A   03020 GO TO 2810
    0x55bc7eacdd60 ---------A   03030 REM********		CHECK FOR LEGAL NEIGHBOUR
    0x55bc7eacddf0 ---------A T 03040 GOSUB 3840
    0x55bc7eacdf90 ---------A   03050 IF F1 = 1 THEN 3110
    0x55bc7eace110 ---------A   03060 LET L = 18
    0x55bc7eace1b0 ---------A   03070 GOSUB 4490
    0x55bc7eace320 ---------A   03080 PRINT "SORRY, YOU ARE NOT NEXT TO ONE OF MY PIECES. TRY AGAIN.";
    0x55bc7eace3a0 ---------A   03090 GO TO 2810
    0x55bc7eace410 ---------A   03100 REM********		CHECK IF LEGAL RUN
    0x55bc7eace590 ---------A T 03110 U = -1
    0x55bc7eace610 ---------A   03120 GOSUB 4040
    0x55bc7eace7b0 ---------A   03130 IF S1 > 0 THEN 3190
    0x55bc7eace930 ---------A   03140 LET L = 18
    0x55bc7eace9c0 ---------A   03150 GOSUB 4490
    0x55bc7eaceb00 ---------A   03160 PRINT "SORRY, THAT DOESN'T FLANK A ROW, TRY AGAIN"
    0x55bc7eaceb90 ---------A   03170 GO TO 2810
    0x55bc7eacec10 ---------A   03180 REM********		EVERYTHING LEGAL; MAKE HUMANS MOVE
    0x55bc7eaced90 ---------A T 03190 Z = 0
    0x55bc7eacef00 ---------A   03200 LET L = 13
    0x55bc7eacef80 ---------A   03210 GOSUB 4490
    0x55bc7eacf0c0 ---------A   03220 PRINT "THAT GIVES YOU";
    0x55bc7eacf1c0 ---------A   03230 PRINT S1;
    0x55bc7eacf2f0 ---------A   03240 PRINT " OF MY PIECES"
    0x55bc7eacf460 ---------A   03250 U = 1
    0x55bc7eacf4d0 ---------A   03260 GOSUB 4040
    0x55bc7eacf770 ---------A   03270 H1 = H1 + S1 + 1
    0x55bc7eacf940 ---------A   03280 C1 = C1 -S1
    0x55bc7eacfb60 ---------A   03290 N1 = N1 + 1
    0x55bc7eacfbe0 ---------A   03300 REM********		PRINT OUT BOARD
    0x55bc7eacfc70 ---------A   03310 GOSUB 4320
    0x55bc7eacfce0 ---------A   03320 REM********		TEST FOR END OF GAME
    0x55bc7eacfec0 ---------A   03330 IF C1 = 0 THEN 3370
    0x55bc7ead0080 ---------A   03340 IF N1 = 64 THEN 3370
    0x55bc7ead0110 ---------A   03350 GO TO 2010
    0x55bc7ead0180 ---------A   03360 REM********		END OF GAME ; WRAPUP
    0x55bc7ead0300 ---------A T 03370 LET L = 18
    0x55bc7ead0390 ---------A   03380 GOSUB 4490
    0x55bc7ead04c0 ---------A   03390 PRINT "FOR RESULTS ON GAME TYPE RETURN!!"
    0x55bc7ead05a0 ---------A   03400 INPUT X$
    0x55bc7ead0840 ---------A   03410 PRINT CHR$(30),CHR$(26)
    0x55bc7ead0990 ---------A   03420 PRINT "YOU HAVE ";
    0x55bc7ead0a90 ---------A   03430 PRINT H1;
    0x55bc7ead0be0 ---------A   03440 PRINT " PIECES, AND I HAVE ";
    0x55bc7ead0ce0 ---------A   03450 PRINT C1;
    0x55bc7ead0e20 ---------A   03460 PRINT " PIECES--- "
    0x55bc7ead0fa0 ---------A   03470 IF H1 = C1 THEN 3510
    0x55bc7ead1130 ---------A   03480 IF H1 > C1 THEN 3530
    0x55bc7ead1280 ---------A   03490 PRINT "SORRY, I WON THAT ONE."
    0x55bc7ead1300 ---------A   03500 GO TO 3540
    0x55bc7ead1420 ---------A T 03510 PRINT " A TIE!!!!!"
    0x55bc7ead1490 ---------A   03520 GO TO 3720
    0x55bc7ead15b0 ---------A T 03530 PRINT "YOU WON!!!"
    0x55bc7ead1790 ---------A T 03540 C1 = C1 - H1
    0x55bc7ead1940 ---------A   03550 IF C1 > 0 THEN 3570
    0x55bc7ead1a80 ---------A   03560 C1 = -C1
    0x55bc7eac8040 ---------A T 03570 C1 = (64 * C1)/ N1
    0x55bc7eac81a0 ---------A   03580 PRINT "THAT WAS A ";
    0x55bc7eac8360 ---------A   03590 IF C1 < 11 THEN 3710
    0x55bc7eac8530 ---------A   03600 IF C1 < 25 THEN 3690
    0x55bc7ead2c50 ---------A   03610 IF C1 < 39 THEN 3670
    0x55bc7ead2e20 ---------A   03620 IF C1 < 53 THEN 3650
    0x55bc7ead2f60 ---------A   03630 PRINT " A PERFECT GAME!"
    0x55bc7ead2fd0 ---------A   03640 GO TO 3720
    0x55bc7ead30f0 ---------A T 03650 PRINT "WALKAWAY!"
    0x55bc7ead3160 ---------A   03660 GO TO 3720
    0x55bc7ead3280 ---------A T 03670 PRINT "FIGHT!"
    0x55bc7ead32f0 ---------A   03680 GO TO 3720
    0x55bc7ead3410 ---------A T 03690 PRINT "HOT GAME!"
    0x55bc7ead3480 ---------A   03700 GO TO 3720
    0x55bc7ead35a0 ---------A T 03710 PRINT "SQUEAKER!"
    0x55bc7ead3620 ---------A T 03720 PRINT
    0x55bc7ead3780 ---------A   03730 PRINT"DO YOU WANT TO PLAY AGAIN";
    0x55bc7ead3860 ---------A T 03740 INPUT X$
    0x55bc7ead3a50 ---------A   03750 IF X$ = "Y" THEN 1700
    0x55bc7ead3c40 ---------A   03760 IF X$ <> "N" THEN 3740
    0x55bc7ead3d80 ---------A   03770 PRINT "THANKS FOR PLAYING."
    0x55bc7ead3dd0 ---------A   03780 STOP
    0x55bc7ead3e50 ---------B   03790 REM********		
    0x55bc7ead3f10 ---------B   03800 REM********		SUBROUTINE: TEST FOR PROPER NEIGHBOUR
    0x55bc7ead3fa0 ---------B   03810 REM********		ASSUMES:
    0x55bc7ead4050 ---------B   03820 REM********		I,J LOCATES A BLANK SQUARE
    0x55bc7ead4120 ---------B   03830 REM********		YOU HOPE TO SEE AN ADJACENT  T2 (= -T1)
    0x55bc7ead43d0 ---------B G 03840 FOR I1 =  -1 TO 1
    0x55bc7ead4680 ---------B   03850     FOR J1 = -1 TO 1
    0x55bc7ead4a00 ---------B   03860 	IF  A(I+I1,J+J1) = T2 THEN 3930
    0x55bc7ead4ac0 ---------B   03870     NEXT J1
    0x55bc7ead4b80 ---------B   03880 NEXT I1
    0x55bc7ead4c20 ---------B   03890 REM********		NO T2 FOUND
    0x55bc7ead4da0 ---------B   03900 F1 = 0
    0x55bc7ead4df0 ---------B   03910 RETURN
    0x55bc7ead4e80 ---------B   03920 REM********		SUCCESS
    0x55bc7ead5000 ---------B T 03930 F1 = 1
    0x55bc7ead5050 ---------B   03940 RETURN
    0x55bc7ead5110 ---------C   03950 REM********		SUBROUTINE SCORE AND UPDATE
    0x55bc7ead51a0 ---------C   03960 REM********		ASSUMES;
    0x55bc7ead5270 ---------C   03970 REM********		(I,J) IS A TENTATIVE PLACE FOR A PIECE T1.
    0x55bc7ead5340 ---------C   03980 REM********		WANT RUNS OF T2 = -T1, TERMINATED BY A T1.
    0x55bc7ead5410 ---------C   03990 REM********		IF U IS TRUE (1), MARK THOSE RUNS AS T1'S.
    0x55bc7ead54e0 ---------C   04000 REM********		RETURN SUM OF ALL RUNS (T2'S ONLY) IN S1.
    0x55bc7ead55c0 ---------C   04010 REM********		MAIN PROGRAM CONTAINS THE FOLLOWING ARRAYS:
    0x55bc7ead5680 ---------C   04020 REM********		I4:  0 -1 -1 -1  0  1  1  1
    0x55bc7ead5740 ---------C   04030 REM********		J4:  1  1  0 -1 -1 -1  0  1
    0x55bc7ead58c0 ---------C G 04040 S1 = 0
    0x55bc7ead5ad0 ---------C   04050 FOR K = 1 TO 8
    0x55bc7ead5cf0 ---------C   04060     I5 = I4(K)
    0x55bc7ead5f00 ---------C   04070     J5 = J4(K)
    0x55bc7ead6150 ---------C   04080     I6 = I + I5
    0x55bc7ead63a0 ---------C   04090     J6 = J + J5
    0x55bc7ead65a0 ---------C   04100     S3 = 0
    0x55bc7ead67e0 ---------C   04110     IF A(I6,J6) <> T2 THEN 4290
    0x55bc7ead6870 ---------C   04120     REM			LOOP THROUGH THE RUN
    0x55bc7ead6a90 ---------C T 04130     S3 = S3 + 1
    0x55bc7ead6c60 ---------C   04140     I6 = I6 + I5
    0x55bc7ead6e40 ---------C   04150     J6 = J6 + J5
    0x55bc7ead7080 ---------C   04160     IF A (I6,J6) = T1 THEN 4190
    0x55bc7ead7300 ---------C   04170     IF A(I6,J6) = 0 THEN 4290
    0x55bc7ead7380 ---------C   04180     GO TO 4130
    0x55bc7ead7550 ---------C T 04190     S1 = S1 + S3
    0x55bc7ead7710 ---------C   04200     IF U <> 1 THEN 4290
    0x55bc7ead7790 ---------C   04210     REM			UPDATE BOARD
    0x55bc7ead78d0 ---------C   04220     I6 = I
    0x55bc7ead7a10 ---------C   04230     J6 = J
    0x55bc7ead7c60 ---------C   04240     FOR K1 = 0 TO S3
    0x55bc7ead7e60 ---------C   04250 	A(I6,J6) = T1
    0x55bc7ead8030 ---------C   04260 	I6 = I6 + I5
    0x55bc7ead8200 ---------C   04270 	J6 = J6 + J5
    0x55bc7ead82b0 ---------C   04280     NEXT K1
    0x55bc7ead8370 ---------C T 04290 NEXT K
    0x55bc7ead83d0 ---------C   04300 RETURN
    0x55bc7ead8480 ---------D   04310 REM********		SUBROUTINE TO PRINT BOARD
    0x55bc7ead8600 ---------D G 04320 PRINT CHR$(30)
    0x55bc7ead8780 ---------D   04330 LET L = 18
    0x55bc7ead8910 ---------D   04340 IF F9 = 1 GO TO 4370
    0x55bc7ead89b0 ---------D   04350 GOSUB 4570
    0x55bc7ead8b10 ---------D   04360 LET F9 = 1
    0x55bc7ead8c90 ---------D T 04370 PRINT CHR$(30)
    0x55bc7ead8dc0 ---------D   04380 PRINT "    A B C D E F G H"
    0x55bc7ead8fd0 ---------D   04390 FOR I = 1 TO 8
    0x55bc7ead90d0 ---------D   04400     PRINT I;
    0x55bc7ead92e0 ---------D   04410     FOR J = 1 TO 8
    0x55bc7ead9450 ---------D   04420 	PRINT " ";
    0x55bc7ead9740 ---------D   04430 	PRINT D$(A(I,J)+1);
    0x55bc7ead97f0 ---------D   04440     NEXT J
    0x55bc7ead9870 ---------D   04450     PRINT
    0x55bc7ead9920 ---------D   04460 NEXT I
    0x55bc7ead99a0 ---------D   04470 PRINT
    0x55bc7ead99f0 ---------D   04480 RETURN
    0x55bc7ead9a90 ---------E G 04490 REM********		***	SPACE		***
    0x55bc7ead9c10 ---------E   04500 PRINT CHR$(30)
    0x55bc7ead9e60 ---------E   04510 FOR I9 = 1 TO L
    0x55bc7ead9ee0 ---------E   04520     PRINT
    0x55bc7ead9f90 ---------E   04530 NEXT I9
    0x55bc7eada140 ---------E   04540 IF L <> 18 GO TO 4560
    0x55bc7eada2e0 ---------E   04550 F9 = 0
    0x55bc7eada330 ---------E T 04560 RETURN
    0x55bc7eada3d0 ---------F G 04570 REM********		***	BLANK OUT	***
    0x55bc7eada450 ---------F   04580 GOSUB 4490
    0x55bc7eada710 ---------F   04590 PRINT TAB(60);" "
    0x55bc7eada960 ---------F   04600 PRINT TAB(60);" "
    0x55bc7eada9b0 ---------F   04610 RETURN
    0x55bc7eadaa10 ---------A   04620 END
 */

/*
 * Line reference table:
 *

    Target
   Line Num.    Referencing line number (Reference is T-GOTO or G-GOSUB).
   ---------    -------------------------------------------------------------------
     01150      01170T
     01380      01160T
     01410      01430T
     01460      01420T
     01480      01500T
     01520      01490T
     01700      03750T
     01870      01890T
     01920      01880T
     01930      01960T
     02010      02920T, 03350T
     02030      01950T, 02010T
     02240      02220T
     02270      02240T
     02350      02280T
     02390      02100T, 02140T, 02210T, 02270T, 02330T
     02510      02420T
     02760      01990T, 02490T
     02800      02890T
     02810      02820T, 02830T, 02960T, 03020T, 03090T, 03170T
     02930      02840T
     02980      02940T
     03040      02980T
     03110      03050T
     03190      03130T
     03370      02470T, 02730T, 02740T, 02900T, 03330T, 03340T
     03510      03470T
     03530      03480T
     03540      03500T
     03570      03550T
     03650      03620T
     03670      03610T
     03690      03600T
     03710      03590T
     03720      03520T, 03640T, 03660T, 03680T, 03700T
     03740      03760T
     03840      02130G, 03040G
     03930      03860T
     04040      02190G, 02610G, 03120G, 03260G
     04130      04180T
     04190      04160T
     04290      04110T, 04170T, 04200T
     04320      01980G, 02710G, 03310G
     04370      04340T
     04490      02450G, 02530G, 02660G, 02790G, 02860G, 03000G, 03070G, 03150G, 
                03210G, 03380G, 04580G
     04560      04540T
     04570      04350G

 */

/* 
 * Routine Start, Target, Return and End Program Addresses 
 * 

  Rtn      Start           Target           Return             End    
  --- --------------   --------------   --------------   -------------- 
   A) 0x55bc7eab5d30   0x55bc7eab5d30   0x55bc7eadaa10   0x55bc7eadaa10 
   B) 0x55bc7ead3e50   0x55bc7ead43d0   0x55bc7ead4df0   0x55bc7ead5050 
   C) 0x55bc7ead5110   0x55bc7ead58c0   0x55bc7ead83d0   0x55bc7ead83d0 
   D) 0x55bc7ead8480   0x55bc7ead8600   0x55bc7ead99f0   0x55bc7ead99f0 
   E) 0x55bc7ead9a90   0x55bc7ead9a90   0x55bc7eada330   0x55bc7eada330 
   F) 0x55bc7eada3d0   0x55bc7eada3d0   0x55bc7eada9b0   0x55bc7eada9b0 

    NOTE: Routine B overlaps, or is tangled with, routine A!
    NOTE: Routine C overlaps, or is tangled with, routine A!
    NOTE: Routine D overlaps, or is tangled with, routine A!
    NOTE: Routine E overlaps, or is tangled with, routine A!
    NOTE: Routine F overlaps, or is tangled with, routine A!

 */



/*
 * Free line number map.
 *
     Start    End    # Lines in Gap
     -----   -----   ------------------
     00000 - 00990     100 
     04680 - 10000    5330 

 */



/*
 *  Symbol Table Listing for '/home/alan/dev/BasicGames/source/base/othelo/basic/othelo.bas'
 *
    A     Array    Integer     {0,10} {0,10} 
    B              Integer 
    B1             Integer 
    C              Integer 
    C$    Array    String      {0,9} 
    C1             Integer 
    CHR$  Function String      args=1, int   
    D$    Array    String      {0,3} 
    F1             Integer 
    F2             Integer 
    F9             Integer 
    H              Integer 
    H1             Integer 
    I              Integer 
    I1             Integer 
    I3             Integer 
    I4    Array    Integer     {0,9} 
    I5             Integer 
    I6             Integer 
    I9             Integer 
    J              Integer 
    J1             Integer 
    J3             Integer 
    J4    Array    Integer     {0,9} 
    J5             Integer 
    J6             Integer 
    K              Integer 
    K1             Integer 
    L              Integer 
    N1             Integer 
    R              Integer 
    RND   Function Integer     args=1, int   
    S1             Integer 
    S2             Integer 
    S3             Integer 
    T1             Integer 
    T2             Integer 
    TAB   Function String      args=1, 
    U              Integer 
    W              Integer 
    X$             String  
    Z              Integer 

 */


/*
 * Title: Display of final 'clean' BASIC listing.
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/othelo/basic/othelo.bas: 
 *
                   +----+---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   |    | +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    |    | |
        Address    v    v v Original BASIC statement
    -------------- ------ - ------------------------------------------------------------------------------
    0x55bc7eab5d30 ---------A   01000 REM********		OTHELLO          BYTE VOL. 2, NUMBER 10 (OCT. 1977)
    0x55bc7eab5e20 ---------A   01010 REM********		PLAYS THE GAME OTHELLO WITH TWO STRATEGIES
    0x55bc7eab5f00 ---------A   01020 REM********		1. TAKE THE MAX. NUMBER OF PIECES
    0x55bc7eab5ff0 ---------A   01030 REM********		2. ADD A BONUS FOR OUTSIDE POSITION
    0x55bc7eab60d0 ---------A   01040 REM********		BOARD IS THE ARRAY A, BOUNDED BY 0'S (BLANKS)
    0x55bc7eab61a0 ---------A   01050 REM********		A = 0 FOR EMPTY SQUARE
    0x55bc7eab6250 ---------A   01060 REM********		A = B FOR BLACK SQUARE
    0x55bc7eab6300 ---------A   01070 REM********		A = W FOR WHITE SQUARE
    0x55bc7eab63e0 ---------A   01080 REM********		I AND J ARE ALWAYS USED FOR ROW/COLUMN INDICES
    0x55bc7eab6500 ---------A   01090 REM********		I1 AND J4 STORE INCREMENTS TO THE 8 NEIGHBOURS
    0x55bc7eab65e0 ---------A   01100 REM********		C$ AND D$ STORE CHARACTERS A-H,X,...,O FOR OUTPUT
    0x55bc7eabb0a0 ---------A   01110 DIM A(9,9),I4(8),J4(8),C$(8),D$(2)
    0x55bc7eabb100 ---------A   01120 REM********		
    0x55bc7eabb280 ---------A   01130 PRINT "GREETINGS FROM OTHELLO!"
    0x55bc7eabb3e0 ---------A   01140 PRINT "DO YOU WANT INSTRUCTIONS (Y OR N)";
    0x55bc7eabb540 ---------A T 01150 INPUT X$
    0x55bc7eabb730 ---------A   01160 IF X$ = "N" THEN 1380
    0x55bc7eabba20 ---------A   01170 IF X$ <> "Y" THEN 1150
    0x55bc7eabbac0 ---------A   01180 PRINT
    0x55bc7eabbc40 ---------A   01190 PRINT "OTHELLO IS PLAYED ON AN 8X8 CHECKER BOARD"
    0x55bc7eabbdc0 ---------A   01200 PRINT "ROWS ARE NUMBERED FROM 1 TO 8 AND COLUMNS FROM A TO H"
    0x55bc7eabbf40 ---------A   01210 PRINT" THE INITIAL CONFIGURATION IS ALL BLANK EXCEPT FOR"
    0x55bc7eabc0a0 ---------A   01220 PRINT "THE CENTER FOUR SQUARES, WHICH FORM THE PATTERN:"
    0x55bc7eabc1e0 ---------A   01230 PRINT "               O X"
    0x55bc7eabc310 ---------A   01240 PRINT "               X O"
    0x55bc7eabc3b0 ---------A   01250 PRINT
    0x55bc7eabc540 ---------A   01260 PRINT "TRY TO PLACE YOUR PIECE SO THAT IT WILL 'OUTFLANK' MINE"
    0x55bc7eabc6c0 ---------A   01270 PRINT "THEREBY CREATING A HORIZONTAL, VERTICAL, OR DIAGONAL "
    0x55bc7eabc840 ---------A   01280 PRINT "RUN OF MY PIECES BOUNDED AT EACH END BY AT LEAST ONE "
    0x55bc7eabc9a0 ---------A   01290 PRINT "OF YOURS.  THIS WILL 'FLIP' MY PIECES, TURNING THEM INTO"
    0x55bc7eabcb00 ---------A   01300 PRINT "YOURS."
    0x55bc7eabcc80 ---------A   01310 PRINT"     NOTE: YOU MUST CAPTURE AT LEAST ONE OF MY PIECES"
    0x55bc7eabce00 ---------A   01320 PRINT "IN THIS WAY IF IT IS AT ALL POSSIBLE.  IF IT IS NOT"
    0x55bc7eabd180 ---------A   01330 PRINT "POSSIBLE, YOU FORFEIT YOUR TURN BY ENTERING"
    0x55bc7eabd2d0 ---------A   01340 PRINT "     0,0   FOR YOUR ROW,COLUMN MOVE"
    0x55bc7eabd400 ---------A   01350 PRINT " GOOD LUCK!"
    0x55bc7eabd470 ---------A   01360 PRINT
    0x55bc7eabd4e0 ---------A   01370 REM********		
    0x55bc7eabd690 ---------A T 01380 PRINT "SHOULD I WAIT BEFORE MAKING MY MOVES (Y OR N)";
    0x55bc7eabd880 ---------A   01390 F2 = 0
    0x55bc7eabda70 ---------A   01400 F9 = 1
    0x55bc7eabdb50 ---------A T 01410 INPUT X$
    0x55bc7eabdd40 ---------A   01420 IF X$ = "N" THEN 1460
    0x55bc7eabdf20 ---------A   01430 IF X$ <> "Y" THEN  1410
    0x55bc7eabe0d0 ---------A   01440 F2 = 1
    0x55bc7eabe240 ---------A   01450         PRINT "OK.  TYPING ANY CHARACTER WILL LET ME GO"
    0x55bc7eabe3b0 ---------A T 01460 PRINT "SHOULD I PLAY MY BEST STRATEGY (Y OR N)";
    0x55bc7eabe5a0 ---------A   01470 S2 = 0
    0x55bc7eabe680 ---------A T 01480 INPUT X$
    0x55bc7eabe870 ---------A   01490 IF X$ = "N" THEN 1520
    0x55bc7eabea50 ---------A   01500 IF X$ <> "Y" THEN 1480
    0x55bc7eabebd0 ---------A   01510 S2 = 2
    0x55bc7eabedc0 ---------A T 01520 B = -1
    0x55bc7eabefb0 ---------A   01530 W = +1
    0x55bc7eabf280 ---------A   01540 D$(B +1) ="X"
    0x55bc7eabf590 ---------A   01550 D$(0 +1) = "."
    0x55bc7eabf860 ---------A   01560 D$(W + 1) ="O"
    0x55bc7eabfaf0 ---------A   01570 FOR K = 1 TO 8
    0x55bc7eabfc30 ---------A   01580     READ I4(K)
    0x55bc7eabfcd0 ---------A   01590 NEXT K
    0x55bc7eac0360 ---------A   01600 DATA 0,-1,-1,-1,0,1,1,1
    0x55bc7eac0570 ---------A   01610 FOR K=1 TO 8
    0x55bc7eac06b0 ---------A   01620     READ J4(K)
    0x55bc7eac0750 ---------A   01630 NEXT K
    0x55bc7eac0de0 ---------A   01640 DATA 1,1,0,-1,-1,-1,0,1
    0x55bc7eac1400 ---------A   01650 FOR K = 1 TO 8
    0x55bc7eac1540 ---------A   01660     READ C$(K)
    0x55bc7eac15e0 ---------A   01670 NEXT K
    0x55bc7eac1c80 ---------A   01680 DATA A,B,C,D,E,F,G,H
    0x55bc7eac1d00 ---------A   01690 REM********		SET UP A NEW GAME
    0x55bc7eac1fa0 ---------A T 01700 FOR I = 0 TO 9
    0x55bc7eac2240 ---------A   01710     FOR J = 0 TO 9
    0x55bc7eac2480 ---------A   01720 	A(I,J)=0
    0x55bc7eac2530 ---------A   01730     NEXT J
    0x55bc7eac25f0 ---------A   01740 NEXT I
    0x55bc7eac2870 ---------A   01750 A(4,4) = W
    0x55bc7eac2ae0 ---------A   01760 A(5,5) = W
    0x55bc7eac2d50 ---------A   01770 A(4,5) = B
    0x55bc7eac2fc0 ---------A   01780 A(5,4) = B
    0x55bc7eac31b0 ---------A   01790 C1 = 2
    0x55bc7eac33a0 ---------A   01800 H1 = 2
    0x55bc7eac3590 ---------A   01810 N1 = 4
    0x55bc7eac3790 ---------A   01820 Z =0
    0x55bc7eac3810 ---------A   01830 REM********		HUMAN'S CHOICES
    0x55bc7eac39a0 ---------A   01840 PRINT "DO YOU WANT TO HAVE X OR O";
    0x55bc7eac3b50 ---------A   01850 C = W
    0x55bc7eac3d00 ---------A   01860 H = B
    0x55bc7eac3de0 ---------A T 01870 INPUT X$
    0x55bc7eac3fd0 ---------A   01880 IF X$ = "X" THEN 1920
    0x55bc7eac41b0 ---------A   01890 IF X$ <> "O" THEN 1870
    0x55bc7eac42f0 ---------A   01900 C = B
    0x55bc7eac4440 ---------A   01910 H = W
    0x55bc7eac45a0 ---------A T 01920 PRINT "DO YOU WANT TO GO FIRST (Y OR N)";
    0x55bc7eac4670 ---------A T 01930 INPUT X$
    0x55bc7eac4880 ---------A   01940 PRINT CHR$(26)
    0x55bc7eac4a60 ---------A   01950 IF X$ = "N" THEN 2030
    0x55bc7eac4c50 ---------A   01960 IF X$ <> "Y" THEN 1930
    0x55bc7eac4ce0 ---------A   01970 REM********		PRINT INITIAL BOARD
    0x55bc7eac4d60 ---------A   01980 GOSUB 4340
    0x55bc7eac4dd0 ---------A   01990 GO TO 2760
    0x55bc7eac4e40 ---------A   02000 REM********		COMPUTER'S MOVE
    0x55bc7eac5010 ---------A T 02010 IF F2 = 0 THEN 2030
    0x55bc7eac50f0 ---------A   02020 INPUT X$
    0x55bc7eac52f0 ---------A T 02030 B1 = -1
    0x55bc7eac55c0 ---------A   02040 I3 = J3 = 0
    0x55bc7eac5770 ---------A   02050 T1 = C
    0x55bc7eac5930 ---------A   02060 T2 = H
    0x55bc7eac59b0 ---------A   02070 REM********		SCAN FOR BLANK SQUARE
    0x55bc7eac5bd0 ---------A   02080 FOR I = 1 TO 8
    0x55bc7eac5e00 ---------A   02090     FOR J = 1 TO 8
    0x55bc7eac6090 ---------A   02100 	IF A(I,J) <> 0 THEN 2390
    0x55bc7eac6120 ---------A   02110 	REM********		FOUND A BLANK SQUARE
    0x55bc7eac61f0 ---------A   02120 	REM********		DOES IT HAVE AN OPPONENT AS A NEIGHBOUR
    0x55bc7eac6280 ---------A   02130 	GOSUB 3800
    0x55bc7eac64c0 ---------A   02140 	IF F1 = 0 THEN 2390
    0x55bc7eac6560 ---------A   02150 	REM********		FOUND OPPONENT AS NEIGHBOUR
    0x55bc7eac6620 ---------A   02160 	REM********		HOW MANY OF HIS PIECES CAN WE FLIP?
    0x55bc7eac66c0 ---------A   02170 	REM********		DON'T DO IT NOW
    0x55bc7eac68c0 ---------A   02180 	U = -1
    0x55bc7eac6950 ---------A   02190 	GOSUB 3970
    0x55bc7eac69d0 ---------A   02200 	REM********		EXTRA POINTS FOR BOUNDARY POSITION
    0x55bc7eac6c30 ---------A   02210 	IF S1 = 0 THEN 2390
    0x55bc7eac70d0 ---------A   02220 	IF (I-1) * (I-8) <> 0 THEN 2240
    0x55bc7eac72c0 ---------A   02230 	S1 = S1 + S2
    0x55bc7eac7750 ---------A T 02240 	IF (J-1) * (J-8) <> 0 THEN 2270
    0x55bc7eac7960 ---------A   02250 	S1 = S1 +S2
    0x55bc7eac79f0 ---------A   02260 	REM********		IS THIS BETTER THAN THE BEST FOUND SO FAR
    0x55bc7eac7b90 ---------A T 02270 	IF S1 < B1 THEN 2390
    0x55bc7eac7d30 ---------A   02280 	IF S1 > B1 THEN 2350
    0x55bc7eac85d0 ---------A   02290 	REM********		A TIE; RANDOM DECISION
    0x55bc7eac86a0 ---------A   02300 	REM********		THE NEXT TWO EXECUTABLE STATEMENTS ARE FOR
    0x55bc7eac8750 ---------A   02310 	REM********		BASIC WITH RANDOM NUMBERS
    0x55bc7eac8a40 ---------A   02320 	R = RND(1)
    0x55bc7eac8bf0 ---------A   02330 	IF R > .5 THEN 2390
    0x55bc7eac8c70 ---------A   02340 	REM********		YES
    0x55bc7eac8db0 ---------A T 02350 	B1 = S1
    0x55bc7eac8ee0 ---------A   02360 	I3 = I
    0x55bc7eac9020 ---------A   02370 	J3 = J
    0x55bc7eac90a0 ---------A   02380 	REM********		END OF SCAN LOOP
    0x55bc7eac9160 ---------A T 02390     NEXT J
    0x55bc7eac9220 ---------A   02400 NEXT I
    0x55bc7eac92c0 ---------A   02410 REM********		COULD WE DO ANYTHING?
    0x55bc7eac9490 ---------A   02420 IF B1 > 0 THEN 2510
    0x55bc7eac9510 ---------A   02430 REM********		NO
    0x55bc7eac9710 ---------A   02440 LET L = 18
    0x55bc7eac97a0 ---------A   02450 GOSUB 4530
    0x55bc7eac98d0 ---------A   02460 PRINT "DAMN! HAVE TO FORFEIT MY MOVE!"
    0x55bc7eac9a80 ---------A   02470 IF Z = 1 THEN 3370
    0x55bc7eac9c00 ---------A   02480 Z = 1
    0x55bc7eac9c80 ---------A   02490 GO TO 2760
    0x55bc7eac9cf0 ---------A   02500 REM********		MAKE THE MOVE
    0x55bc7eac9e70 ---------A T 02510 Z = 0
    0x55bc7eac9fe0 ---------A   02520 LET L=15
    0x55bc7eaca060 ---------A   02530 GOSUB 4530
    0x55bc7eaca1a0 ---------A   02540 PRINT "I WILL MOVE TO ";
    0x55bc7eaca290 ---------A   02550 PRINT I3;
    0x55bc7eaca3e0 ---------A   02560 PRINT " , ";
    0x55bc7eaca510 ---------A   02570 PRINT C$(J3)
    0x55bc7eaca640 ---------A   02580 I= I3
    0x55bc7eaca770 ---------A   02590 J= J3
    0x55bc7eaca8e0 ---------A   02600 U= 1
    0x55bc7eaca950 ---------A   02610 GOSUB 3970
    0x55bc7eacabf0 ---------A   02620 C1 = C1 + S1 + 1
    0x55bc7eacadc0 ---------A   02630 H1 = H1 - S1
    0x55bc7eacafd0 ---------A   02640 N1 = N1 + 1
    0x55bc7eacb140 ---------A   02650 LET L=16
    0x55bc7eacb1c0 ---------A   02660 GOSUB 4530
    0x55bc7eacb300 ---------A   02670 PRINT " THAT GIVES ME : ";
    0x55bc7eacb400 ---------A   02680 PRINT S1;
    0x55bc7eacb540 ---------A   02690 PRINT " OF YOUR PIECES"
    0x55bc7eacb5c0 ---------A   02700 REM********		PRINT OUT BOARD
    0x55bc7eacb650 ---------A   02710 GOSUB 4340
    0x55bc7eacb6c0 ---------A   02720 REM********		TEST FOR END OF GAME
    0x55bc7eacb8a0 ---------A   02730 IF H1 = 0 THEN 3370
    0x55bc7eacba70 ---------A   02740 IF N1 = 64 THEN 3370
    0x55bc7eacbb00 ---------A   02750 REM********		HUMANS MOVE
    0x55bc7eacbc40 ---------A T 02760 T1 = H
    0x55bc7eacbd70 ---------A   02770 T2 = C
    0x55bc7eacbee0 ---------A   02780 LET L = 12
    0x55bc7eacbf60 ---------A   02790 GOSUB 4530
    0x55bc7eacc0a0 ---------A T 02800 PRINT " YOUR MOVE";
    0x55bc7eacc1d0 ---------A T 02810 INPUT I, X$
    0x55bc7eacc390 ---------A   02820 IF I < 0 THEN 2810
    0x55bc7eacc560 ---------A   02830 IF I > 8 THEN 2810
    0x55bc7eacc720 ---------A   02840 IF I <> 0 THEN 2930
    0x55bc7eacc8a0 ---------A   02850 LET L = 18
    0x55bc7eacc930 ---------A   02860 GOSUB 4530
    0x55bc7eacca60 ---------A   02870 PRINT "ARE YOU FORFEITING YOUR TURN Y OR N"
    0x55bc7eaccb40 ---------A   02880 INPUT X$
    0x55bc7eaccd20 ---------A   02890 IF X$ <> "Y" THEN 2800
    0x55bc7eaccee0 ---------A   02900 IF Z = 1 THEN 3370
    0x55bc7eacd060 ---------A   02910 Z = 1
    0x55bc7eacd0d0 ---------A   02920 GO TO 2010
    0x55bc7eacd2e0 ---------A T 02930 FOR J = 1 TO 8
    0x55bc7eacd4c0 ---------A   02940     IF C$(J) =X$ THEN 2980
    0x55bc7eacd580 ---------A   02950 NEXT J
    0x55bc7eacd610 ---------A   02960 GO TO 2810
    0x55bc7eacd680 ---------A   02970 REM********		CHECK FOR BLANK
    0x55bc7eacd910 ---------A T 02980 IF A(I,J) = 0 THEN 3040
    0x55bc7eacda90 ---------A   02990 LET L = 18
    0x55bc7eacdb20 ---------A   03000 GOSUB 4530
    0x55bc7eacdc60 ---------A   03010 PRINT "SORRY, THAT SQUARE IS OCCUPIED, TRY AGAIN"
    0x55bc7eacdcf0 ---------A   03020 GO TO 2810
    0x55bc7eacdd60 ---------A   03030 REM********		CHECK FOR LEGAL NEIGHBOUR
    0x55bc7eacddf0 ---------A T 03040 GOSUB 3800
    0x55bc7eacdf90 ---------A   03050 IF F1 = 1 THEN 3110
    0x55bc7eace110 ---------A   03060 LET L = 18
    0x55bc7eace1b0 ---------A   03070 GOSUB 4530
    0x55bc7eace320 ---------A   03080 PRINT "SORRY, YOU ARE NOT NEXT TO ONE OF MY PIECES. TRY AGAIN.";
    0x55bc7eace3a0 ---------A   03090 GO TO 2810
    0x55bc7eace410 ---------A   03100 REM********		CHECK IF LEGAL RUN
    0x55bc7eace590 ---------A T 03110 U = -1
    0x55bc7eace610 ---------A   03120 GOSUB 3970
    0x55bc7eace7b0 ---------A   03130 IF S1 > 0 THEN 3190
    0x55bc7eace930 ---------A   03140 LET L = 18
    0x55bc7eace9c0 ---------A   03150 GOSUB 4530
    0x55bc7eaceb00 ---------A   03160 PRINT "SORRY, THAT DOESN'T FLANK A ROW, TRY AGAIN"
    0x55bc7eaceb90 ---------A   03170 GO TO 2810
    0x55bc7eacec10 ---------A   03180 REM********		EVERYTHING LEGAL; MAKE HUMANS MOVE
    0x55bc7eaced90 ---------A T 03190 Z = 0
    0x55bc7eacef00 ---------A   03200 LET L = 13
    0x55bc7eacef80 ---------A   03210 GOSUB 4530
    0x55bc7eacf0c0 ---------A   03220 PRINT "THAT GIVES YOU";
    0x55bc7eacf1c0 ---------A   03230 PRINT S1;
    0x55bc7eacf2f0 ---------A   03240 PRINT " OF MY PIECES"
    0x55bc7eacf460 ---------A   03250 U = 1
    0x55bc7eacf4d0 ---------A   03260 GOSUB 3970
    0x55bc7eacf770 ---------A   03270 H1 = H1 + S1 + 1
    0x55bc7eacf940 ---------A   03280 C1 = C1 -S1
    0x55bc7eacfb60 ---------A   03290 N1 = N1 + 1
    0x55bc7eacfbe0 ---------A   03300 REM********		PRINT OUT BOARD
    0x55bc7eacfc70 ---------A   03310 GOSUB 4340
    0x55bc7eacfce0 ---------A   03320 REM********		TEST FOR END OF GAME
    0x55bc7eacfec0 ---------A   03330 IF C1 = 0 THEN 3370
    0x55bc7ead0080 ---------A   03340 IF N1 = 64 THEN 3370
    0x55bc7ead0110 ---------A   03350 GO TO 2010
    0x55bc7ead0180 ---------A   03360 REM********		END OF GAME ; WRAPUP
    0x55bc7ead0300 ---------A T 03370 LET L = 18
    0x55bc7ead0390 ---------A   03380 GOSUB 4530
    0x55bc7ead04c0 ---------A   03390 PRINT "FOR RESULTS ON GAME TYPE RETURN!!"
    0x55bc7ead05a0 ---------A   03400 INPUT X$
    0x55bc7ead0840 ---------A   03410 PRINT CHR$(30),CHR$(26)
    0x55bc7ead0990 ---------A   03420 PRINT "YOU HAVE ";
    0x55bc7ead0a90 ---------A   03430 PRINT H1;
    0x55bc7ead0be0 ---------A   03440 PRINT " PIECES, AND I HAVE ";
    0x55bc7ead0ce0 ---------A   03450 PRINT C1;
    0x55bc7ead0e20 ---------A   03460 PRINT " PIECES--- "
    0x55bc7ead0fa0 ---------A   03470 IF H1 = C1 THEN 3510
    0x55bc7ead1130 ---------A   03480 IF H1 > C1 THEN 3530
    0x55bc7ead1280 ---------A   03490 PRINT "SORRY, I WON THAT ONE."
    0x55bc7ead1300 ---------A   03500 GO TO 3540
    0x55bc7ead1420 ---------A T 03510 PRINT " A TIE!!!!!"
    0x55bc7ead1490 ---------A   03520 GO TO 3720
    0x55bc7ead15b0 ---------A T 03530 PRINT "YOU WON!!!"
    0x55bc7ead1790 ---------A T 03540 C1 = C1 - H1
    0x55bc7ead1940 ---------A   03550 IF C1 > 0 THEN 3570
    0x55bc7ead1a80 ---------A   03560 C1 = -C1
    0x55bc7eac8040 ---------A T 03570 C1 = (64 * C1)/ N1
    0x55bc7eac81a0 ---------A   03580 PRINT "THAT WAS A ";
    0x55bc7eac8360 ---------A   03590 IF C1 < 11 THEN 3710
    0x55bc7eac8530 ---------A   03600 IF C1 < 25 THEN 3690
    0x55bc7ead2c50 ---------A   03610 IF C1 < 39 THEN 3670
    0x55bc7ead2e20 ---------A   03620 IF C1 < 53 THEN 3650
    0x55bc7ead2f60 ---------A   03630 PRINT " A PERFECT GAME!"
    0x55bc7ead2fd0 ---------A   03640 GO TO 3720
    0x55bc7ead30f0 ---------A T 03650 PRINT "WALKAWAY!"
    0x55bc7ead3160 ---------A   03660 GO TO 3720
    0x55bc7ead3280 ---------A T 03670 PRINT "FIGHT!"
    0x55bc7ead32f0 ---------A   03680 GO TO 3720
    0x55bc7ead3410 ---------A T 03690 PRINT "HOT GAME!"
    0x55bc7ead3480 ---------A   03700 GO TO 3720
    0x55bc7ead35a0 ---------A T 03710 PRINT "SQUEAKER!"
    0x55bc7ead3620 ---------A T 03720 PRINT
    0x55bc7ead3780 ---------A   03730 PRINT"DO YOU WANT TO PLAY AGAIN";
    0x55bc7ead3860 ---------A T 03740 INPUT X$
    0x55bc7ead3a50 ---------A   03750 IF X$ = "Y" THEN 1700
    0x55bc7ead3c40 ---------A   03760 IF X$ <> "N" THEN 3740
    0x55bc7ead3d80 ---------A   03770 PRINT "THANKS FOR PLAYING."
    0x55bc7ead3dd0 ---------A   03780 STOP
    0x55bc7eadaa10 ---------A   03790 END
    0x55bc7eae32b0 ---------B G 03800 GOTO 3860 (Pseudo Goto)
    0x55bc7ead3e50 ---------B   03810 REM********		
    0x55bc7ead3f10 ---------B   03820 REM********		SUBROUTINE: TEST FOR PROPER NEIGHBOUR
    0x55bc7ead3fa0 ---------B   03830 REM********		ASSUMES:
    0x55bc7ead4050 ---------B   03840 REM********		I,J LOCATES A BLANK SQUARE
    0x55bc7ead4120 ---------B   03850 REM********		YOU HOPE TO SEE AN ADJACENT  T2 (= -T1)
    0x55bc7ead43d0 ---------B T 03860 FOR I1 =  -1 TO 1
    0x55bc7ead4680 ---------B   03870     FOR J1 = -1 TO 1
    0x55bc7ead4a00 ---------B   03880 	IF  A(I+I1,J+J1) = T2 THEN 3950
    0x55bc7ead4ac0 ---------B   03890     NEXT J1
    0x55bc7ead4b80 ---------B   03900 NEXT I1
    0x55bc7ead4c20 ---------B   03910 REM********		NO T2 FOUND
    0x55bc7ead4da0 ---------B   03920 F1 = 0
    0x55bc7eae3390 ---------B   03930 GOTO 3960 (Pseudo Goto)
    0x55bc7ead4e80 ---------B   03940 REM********		SUCCESS
    0x55bc7ead5000 ---------B T 03950 F1 = 1
    0x55bc7ead5050 ---------B T 03960 RETURN
    0x55bc7eae3420 ---------C G 03970 GOTO 4070 (Pseudo Goto)
    0x55bc7ead5110 ---------C   03980 REM********		SUBROUTINE SCORE AND UPDATE
    0x55bc7ead51a0 ---------C   03990 REM********		ASSUMES;
    0x55bc7ead5270 ---------C   04000 REM********		(I,J) IS A TENTATIVE PLACE FOR A PIECE T1.
    0x55bc7ead5340 ---------C   04010 REM********		WANT RUNS OF T2 = -T1, TERMINATED BY A T1.
    0x55bc7ead5410 ---------C   04020 REM********		IF U IS TRUE (1), MARK THOSE RUNS AS T1'S.
    0x55bc7ead54e0 ---------C   04030 REM********		RETURN SUM OF ALL RUNS (T2'S ONLY) IN S1.
    0x55bc7ead55c0 ---------C   04040 REM********		MAIN PROGRAM CONTAINS THE FOLLOWING ARRAYS:
    0x55bc7ead5680 ---------C   04050 REM********		I4:  0 -1 -1 -1  0  1  1  1
    0x55bc7ead5740 ---------C   04060 REM********		J4:  1  1  0 -1 -1 -1  0  1
    0x55bc7ead58c0 ---------C T 04070 S1 = 0
    0x55bc7ead5ad0 ---------C   04080 FOR K = 1 TO 8
    0x55bc7ead5cf0 ---------C   04090     I5 = I4(K)
    0x55bc7ead5f00 ---------C   04100     J5 = J4(K)
    0x55bc7ead6150 ---------C   04110     I6 = I + I5
    0x55bc7ead63a0 ---------C   04120     J6 = J + J5
    0x55bc7ead65a0 ---------C   04130     S3 = 0
    0x55bc7ead67e0 ---------C   04140     IF A(I6,J6) <> T2 THEN 4320
    0x55bc7ead6870 ---------C   04150     REM			LOOP THROUGH THE RUN
    0x55bc7ead6a90 ---------C T 04160     S3 = S3 + 1
    0x55bc7ead6c60 ---------C   04170     I6 = I6 + I5
    0x55bc7ead6e40 ---------C   04180     J6 = J6 + J5
    0x55bc7ead7080 ---------C   04190     IF A (I6,J6) = T1 THEN 4220
    0x55bc7ead7300 ---------C   04200     IF A(I6,J6) = 0 THEN 4320
    0x55bc7ead7380 ---------C   04210     GO TO 4160
    0x55bc7ead7550 ---------C T 04220     S1 = S1 + S3
    0x55bc7ead7710 ---------C   04230     IF U <> 1 THEN 4320
    0x55bc7ead7790 ---------C   04240     REM			UPDATE BOARD
    0x55bc7ead78d0 ---------C   04250     I6 = I
    0x55bc7ead7a10 ---------C   04260     J6 = J
    0x55bc7ead7c60 ---------C   04270     FOR K1 = 0 TO S3
    0x55bc7ead7e60 ---------C   04280 	A(I6,J6) = T1
    0x55bc7ead8030 ---------C   04290 	I6 = I6 + I5
    0x55bc7ead8200 ---------C   04300 	J6 = J6 + J5
    0x55bc7ead82b0 ---------C   04310     NEXT K1
    0x55bc7ead8370 ---------C T 04320 NEXT K
    0x55bc7ead83d0 ---------C   04330 RETURN
    0x55bc7eae3500 ---------D G 04340 GOTO 4360 (Pseudo Goto)
    0x55bc7ead8480 ---------D   04350 REM********		SUBROUTINE TO PRINT BOARD
    0x55bc7ead8600 ---------D T 04360 PRINT CHR$(30)
    0x55bc7ead8780 ---------D   04370 LET L = 18
    0x55bc7ead8910 ---------D   04380 IF F9 = 1 GO TO 4410
    0x55bc7ead89b0 ---------D   04390 GOSUB 4620
    0x55bc7ead8b10 ---------D   04400 LET F9 = 1
    0x55bc7ead8c90 ---------D T 04410 PRINT CHR$(30)
    0x55bc7ead8dc0 ---------D   04420 PRINT "    A B C D E F G H"
    0x55bc7ead8fd0 ---------D   04430 FOR I = 1 TO 8
    0x55bc7ead90d0 ---------D   04440     PRINT I;
    0x55bc7ead92e0 ---------D   04450     FOR J = 1 TO 8
    0x55bc7ead9450 ---------D   04460 	PRINT " ";
    0x55bc7ead9740 ---------D   04470 	PRINT D$(A(I,J)+1);
    0x55bc7ead97f0 ---------D   04480     NEXT J
    0x55bc7ead9870 ---------D   04490     PRINT
    0x55bc7ead9920 ---------D   04500 NEXT I
    0x55bc7ead99a0 ---------D   04510 PRINT
    0x55bc7ead99f0 ---------D   04520 RETURN
    0x55bc7eae35e0 ---------E G 04530 GOTO 4550 (Pseudo Goto)
    0x55bc7ead9a90 ---------E   04540 REM********		***	SPACE		***
    0x55bc7ead9c10 ---------E T 04550 PRINT CHR$(30)
    0x55bc7ead9e60 ---------E   04560 FOR I9 = 1 TO L
    0x55bc7ead9ee0 ---------E   04570     PRINT
    0x55bc7ead9f90 ---------E   04580 NEXT I9
    0x55bc7eada140 ---------E   04590 IF L <> 18 GO TO 4610
    0x55bc7eada2e0 ---------E   04600 F9 = 0
    0x55bc7eada330 ---------E T 04610 RETURN
    0x55bc7eae36c0 ---------F G 04620 GOTO 4640 (Pseudo Goto)
    0x55bc7eada3d0 ---------F   04630 REM********		***	BLANK OUT	***
    0x55bc7eada450 ---------F T 04640 GOSUB 4530
    0x55bc7eada710 ---------F   04650 PRINT TAB(60);" "
    0x55bc7eada960 ---------F   04660 PRINT TAB(60);" "
    0x55bc7eada9b0 ---------F   04670 RETURN
 */

//---------------------------------------------------------------------------
// $Header$ 
//
// NOTE: This program has been automatically tranlated by b2c
//
// $Log$ 
// 
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//---------------------------------------------------------------------------
// Global data area.
//---------------------------------------------------------------------------
char* data_01600s[]={"0","-1","-1","-1","0","1","1","1"};
char* data_01640s[]={"1","1","0","-1","-1","-1","0","1"};
char* data_01680s[]={"A","B","C","D","E","F","G","H"};
//---------------------------------------------------------------------------




typedef enum {TYPE_None,TYPE_Integer,TYPE_Float,TYPE_String}t_type;
typedef struct{
    int    LineNum;
    int    Size;
    char** SData;
}t_data;
t_data ProgramData[] = {
    { 1600,  8,data_01600s},
    { 1640,  8,data_01640s},
    { 1680,  8,data_01680s},
    {    0,  0,nullptr       }
};

#include "intrinsics.h"


//---------------------------------------------------------------------------
// Global variable area.
//
// NOTE: Variable names are long to allow for easy editing.
//---------------------------------------------------------------------------
int   A_int_arr[10][10];// Comments?
int   B_int;        // Comments?
int   B1_int;       // Comments?
int   C_int;        // Comments?
char* C_str_arr[9]; // Comments?
int   C1_int;       // Comments?
char* D_str_arr[3]; // Comments?
int   F1_int;       // Comments?
int   F2_int;       // Comments?
int   F9_int;       // Comments?
int   H_int;        // Comments?
int   H1_int;       // Comments?
int   I_int;        // Comments?
int   I1_int;       // Comments?
int   I3_int;       // Comments?
int   I4_int_arr[9];// Comments?
int   I5_int;       // Comments?
int   I6_int;       // Comments?
int   I9_int;       // Comments?
int   J_int;        // Comments?
int   J1_int;       // Comments?
int   J3_int;       // Comments?
int   J4_int_arr[9];// Comments?
int   J5_int;       // Comments?
int   J6_int;       // Comments?
int   K_int;        // Comments?
int   K1_int;       // Comments?
int   L_int;        // Comments?
int   N1_int;       // Comments?
int   R_int;        // Comments?
int   S1_int;       // Comments?
int   S2_int;       // Comments?
int   S3_int;       // Comments?
int   T1_int;       // Comments?
int   T2_int;       // Comments?
int   U_int;        // Comments?
int   W_int;        // Comments?
char* X_str;        // Comments?
int   Z_int;        // Comments?
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char* GLBpStr=nullptr;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Subroutine Prototypes.
//---------------------------------------------------------------------------
void Routine_03800();
void Routine_03970();
void Routine_04340();
void Routine_04530();
void Routine_04620();

//---------------------------------------------------------------------------
// Program Functions.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Program Subroutines.
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Routine B
//---------------------------------------------------------------------------

void Routine_03800(){
    // 03800 GOTO 3860 (Pseudo Goto)
    goto Lbl_03860;
    // 03810 REM********		
    // 03820 REM********		SUBROUTINE: TEST FOR PROPER NEIGHBOUR
    // 03830 REM********		ASSUMES:
    // 03840 REM********		I,J LOCATES A BLANK SQUARE
    // 03850 REM********		YOU HOPE TO SEE AN ADJACENT  T2 (= -T1)

  Lbl_03860:
    // 03860 FOR I1 =  -1 TO 1
    for(I1_int=-1;I1_int<=1;I1_int++){
        // 03870     FOR J1 = -1 TO 1
        for(J1_int=-1;J1_int<=1;J1_int++){
            // 03880 	IF  A(I+I1,J+J1) = T2 THEN 3950
            if(A_int_arr[(int)I_int+I1_int][(int)J_int+J1_int]==T2_int)goto Lbl_03950;
            // 03890     NEXT J1
            int dummy_3890=0; // Ignore this line.
        }; // End-For(J1_int)
        // 03900 NEXT I1
        int dummy_3900=0; // Ignore this line.
    }; // End-For(I1_int)
    // 03910 REM********		NO T2 FOUND
    // 03920 F1 = 0
    F1_int = 0;
    // 03930 GOTO 3960 (Pseudo Goto)
    goto Lbl_03960;
    // 03940 REM********		SUCCESS

  Lbl_03950:
    // 03950 F1 = 1
    F1_int = 1;

  Lbl_03960:
    // 03960 RETURN
    return;
};


//---------------------------------------------------------------------------
// Routine C
//---------------------------------------------------------------------------

void Routine_03970(){
    // 03970 GOTO 4070 (Pseudo Goto)
    goto Lbl_04070;
    // 03980 REM********		SUBROUTINE SCORE AND UPDATE
    // 03990 REM********		ASSUMES;
    // 04000 REM********		(I,J) IS A TENTATIVE PLACE FOR A PIECE T1.
    // 04010 REM********		WANT RUNS OF T2 = -T1, TERMINATED BY A T1.
    // 04020 REM********		IF U IS TRUE (1), MARK THOSE RUNS AS T1'S.
    // 04030 REM********		RETURN SUM OF ALL RUNS (T2'S ONLY) IN S1.
    // 04040 REM********		MAIN PROGRAM CONTAINS THE FOLLOWING ARRAYS:
    // 04050 REM********		I4:  0 -1 -1 -1  0  1  1  1
    // 04060 REM********		J4:  1  1  0 -1 -1 -1  0  1

  Lbl_04070:
    // 04070 S1 = 0
    S1_int = 0;
    // 04080 FOR K = 1 TO 8
    for(K_int=1;K_int<=8;K_int++){
        // 04090     I5 = I4(K)
        I5_int = I4_int_arr[(int)K_int];
        // 04100     J5 = J4(K)
        J5_int = J4_int_arr[(int)K_int];
        // 04110     I6 = I + I5
        I6_int = I_int+I5_int;
        // 04120     J6 = J + J5
        J6_int = J_int+J5_int;
        // 04130     S3 = 0
        S3_int = 0;
        // 04140     IF A(I6,J6) <> T2 THEN 4320
        if(A_int_arr[(int)I6_int][(int)J6_int]!=T2_int)goto Lbl_04320;
        // 04150     REM			LOOP THROUGH THE RUN

  Lbl_04160:
        // 04160     S3 = S3 + 1
        S3_int = S3_int+1;
        // 04170     I6 = I6 + I5
        I6_int = I6_int+I5_int;
        // 04180     J6 = J6 + J5
        J6_int = J6_int+J5_int;
        // 04190     IF A (I6,J6) = T1 THEN 4220
        if(A_int_arr[(int)I6_int][(int)J6_int]==T1_int)goto Lbl_04220;
        // 04200     IF A(I6,J6) = 0 THEN 4320
        if(A_int_arr[(int)I6_int][(int)J6_int]==0)goto Lbl_04320;
        // 04210     GO TO 4160
        goto Lbl_04160;

  Lbl_04220:
        // 04220     S1 = S1 + S3
        S1_int = S1_int+S3_int;
        // 04230     IF U <> 1 THEN 4320
        if(U_int!=1)goto Lbl_04320;
        // 04240     REM			UPDATE BOARD
        // 04250     I6 = I
        I6_int = I_int;
        // 04260     J6 = J
        J6_int = J_int;
        // 04270     FOR K1 = 0 TO S3
        for(K1_int=0;K1_int<=S3_int;K1_int++){
            // 04280 	A(I6,J6) = T1
            A_int_arr[(int)I6_int][(int)J6_int] = T1_int;
            // 04290 	I6 = I6 + I5
            I6_int = I6_int+I5_int;
            // 04300 	J6 = J6 + J5
            J6_int = J6_int+J5_int;
            // 04310     NEXT K1
            int dummy_4310=0; // Ignore this line.
        }; // End-For(K1_int)

  Lbl_04320:
        // 04320 NEXT K
        int dummy_4320=0; // Ignore this line.
    }; // End-For(K_int)
    // 04330 RETURN
    return;
};


//---------------------------------------------------------------------------
// Routine D
//---------------------------------------------------------------------------

void Routine_04340(){
    // 04340 GOTO 4360 (Pseudo Goto)
    goto Lbl_04360;
    // 04350 REM********		SUBROUTINE TO PRINT BOARD

  Lbl_04360:
    // 04360 PRINT CHR$(30)
    b2c_fprintf(stdout,"%s",CHR(30)); b2c_fprintf(stdout,"\n");
    // 04370 LET L = 18
    L_int = 18;
    // 04380 IF F9 = 1 GO TO 4410
    if(F9_int==1)goto Lbl_04410;
    // 04390 GOSUB 4620
    Routine_04620();
    // 04400 LET F9 = 1
    F9_int = 1;

  Lbl_04410:
    // 04410 PRINT CHR$(30)
    b2c_fprintf(stdout,"%s",CHR(30)); b2c_fprintf(stdout,"\n");
    // 04420 PRINT "    A B C D E F G H"
    b2c_fprintf(stdout,"    A B C D E F G H"); b2c_fprintf(stdout,"\n");
    // 04430 FOR I = 1 TO 8
    for(I_int=1;I_int<=8;I_int++){
        // 04440     PRINT I;
        b2c_fprintf(stdout," %d ",I_int); 
        // 04450     FOR J = 1 TO 8
        for(J_int=1;J_int<=8;J_int++){
            // 04460 	PRINT " ";
            b2c_fprintf(stdout," "); 
            // 04470 	PRINT D$(A(I,J)+1);
            b2c_fprintf(stdout,"%s",D_str_arr[(int)A_int_arr[(int)I_int][(int)J_int]+1]); 
            // 04480     NEXT J
            int dummy_4480=0; // Ignore this line.
        }; // End-For(J_int)
        // 04490     PRINT
        b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
        // 04500 NEXT I
        int dummy_4500=0; // Ignore this line.
    }; // End-For(I_int)
    // 04510 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 04520 RETURN
    return;
};


//---------------------------------------------------------------------------
// Routine E
//---------------------------------------------------------------------------

void Routine_04530(){
    // 04530 GOTO 4550 (Pseudo Goto)
    goto Lbl_04550;
    // 04540 REM********		***	SPACE		***

  Lbl_04550:
    // 04550 PRINT CHR$(30)
    b2c_fprintf(stdout,"%s",CHR(30)); b2c_fprintf(stdout,"\n");
    // 04560 FOR I9 = 1 TO L
    for(I9_int=1;I9_int<=L_int;I9_int++){
        // 04570     PRINT
        b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
        // 04580 NEXT I9
        int dummy_4580=0; // Ignore this line.
    }; // End-For(I9_int)
    // 04590 IF L <> 18 GO TO 4610
    if(L_int!=18)goto Lbl_04610;
    // 04600 F9 = 0
    F9_int = 0;

  Lbl_04610:
    // 04610 RETURN
    return;
};


//---------------------------------------------------------------------------
// Routine F
//---------------------------------------------------------------------------

void Routine_04620(){
    // 04620 GOTO 4640 (Pseudo Goto)
    goto Lbl_04640;
    // 04630 REM********		***	BLANK OUT	***

  Lbl_04640:
    // 04640 GOSUB 4530
    Routine_04530();
    // 04650 PRINT TAB(60);" "
    b2c_fprintf(stdout,"%s ",TAB(60)); b2c_fprintf(stdout,"\n");
    // 04660 PRINT TAB(60);" "
    b2c_fprintf(stdout,"%s ",TAB(60)); b2c_fprintf(stdout,"\n");
    // 04670 RETURN
    return;
};

//---------------------------------------------------------------------------
// Main Program.
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc,char *argv[])
{
    // 01000 REM********		OTHELLO          BYTE VOL. 2, NUMBER 10 (OCT. 1977)
    // 01010 REM********		PLAYS THE GAME OTHELLO WITH TWO STRATEGIES
    // 01020 REM********		1. TAKE THE MAX. NUMBER OF PIECES
    // 01030 REM********		2. ADD A BONUS FOR OUTSIDE POSITION
    // 01040 REM********		BOARD IS THE ARRAY A, BOUNDED BY 0'S (BLANKS)
    // 01050 REM********		A = 0 FOR EMPTY SQUARE
    // 01060 REM********		A = B FOR BLACK SQUARE
    // 01070 REM********		A = W FOR WHITE SQUARE
    // 01080 REM********		I AND J ARE ALWAYS USED FOR ROW/COLUMN INDICES
    // 01090 REM********		I1 AND J4 STORE INCREMENTS TO THE 8 NEIGHBOURS
    // 01100 REM********		C$ AND D$ STORE CHARACTERS A-H,X,...,O FOR OUTPUT
    // 01110 DIM A(9,9),I4(8),J4(8),C$(8),D$(2)
    // 01120 REM********		
    // 01130 PRINT "GREETINGS FROM OTHELLO!"
    b2c_fprintf(stdout,"GREETINGS FROM OTHELLO!"); b2c_fprintf(stdout,"\n");
    // 01140 PRINT "DO YOU WANT INSTRUCTIONS (Y OR N)";
    b2c_fprintf(stdout,"DO YOU WANT INSTRUCTIONS (Y OR N)"); 

  Lbl_01150:
    // 01150 INPUT X$
    // Start of Basic INPUT statement 01150
    printf(" ? ");
    char inpbuf_01150[100];
    if(fgets(inpbuf_01150,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01150=strtok(inpbuf_01150," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01150==nullptr){
            X_str = "";
        }else{
            X_str = ps_01150;
        };
    }; // End of Basic INPUT statement 01150
    // 01160 IF X$ = "N" THEN 1380
    if(strcmp(X_str,"N")==0)goto Lbl_01380;
    // 01170 IF X$ <> "Y" THEN 1150
    if(strcmp(X_str,"Y")!=0)goto Lbl_01150;
    // 01180 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01190 PRINT "OTHELLO IS PLAYED ON AN 8X8 CHECKER BOARD"
    b2c_fprintf(stdout,"OTHELLO IS PLAYED ON AN 8X8 CHECKER BOARD"); b2c_fprintf(stdout,"\n");
    // 01200 PRINT "ROWS ARE NUMBERED FROM 1 TO 8 AND COLUMNS FROM A TO H"
    b2c_fprintf(stdout,"ROWS ARE NUMBERED FROM 1 TO 8 AND COLUMNS FROM A TO H"); b2c_fprintf(stdout,"\n");
    // 01210 PRINT" THE INITIAL CONFIGURATION IS ALL BLANK EXCEPT FOR"
    b2c_fprintf(stdout," THE INITIAL CONFIGURATION IS ALL BLANK EXCEPT FOR"); b2c_fprintf(stdout,"\n");
    // 01220 PRINT "THE CENTER FOUR SQUARES, WHICH FORM THE PATTERN:"
    b2c_fprintf(stdout,"THE CENTER FOUR SQUARES, WHICH FORM THE PATTERN:"); b2c_fprintf(stdout,"\n");
    // 01230 PRINT "               O X"
    b2c_fprintf(stdout,"               O X"); b2c_fprintf(stdout,"\n");
    // 01240 PRINT "               X O"
    b2c_fprintf(stdout,"               X O"); b2c_fprintf(stdout,"\n");
    // 01250 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01260 PRINT "TRY TO PLACE YOUR PIECE SO THAT IT WILL 'OUTFLANK' MINE"
    b2c_fprintf(stdout,"TRY TO PLACE YOUR PIECE SO THAT IT WILL 'OUTFLANK' MINE"); b2c_fprintf(stdout,"\n");
    // 01270 PRINT "THEREBY CREATING A HORIZONTAL, VERTICAL, OR DIAGONAL "
    b2c_fprintf(stdout,"THEREBY CREATING A HORIZONTAL, VERTICAL, OR DIAGONAL "); b2c_fprintf(stdout,"\n");
    // 01280 PRINT "RUN OF MY PIECES BOUNDED AT EACH END BY AT LEAST ONE "
    b2c_fprintf(stdout,"RUN OF MY PIECES BOUNDED AT EACH END BY AT LEAST ONE "); b2c_fprintf(stdout,"\n");
    // 01290 PRINT "OF YOURS.  THIS WILL 'FLIP' MY PIECES, TURNING THEM INTO"
    b2c_fprintf(stdout,"OF YOURS.  THIS WILL 'FLIP' MY PIECES, TURNING THEM INTO"); b2c_fprintf(stdout,"\n");
    // 01300 PRINT "YOURS."
    b2c_fprintf(stdout,"YOURS."); b2c_fprintf(stdout,"\n");
    // 01310 PRINT"     NOTE: YOU MUST CAPTURE AT LEAST ONE OF MY PIECES"
    b2c_fprintf(stdout,"     NOTE: YOU MUST CAPTURE AT LEAST ONE OF MY PIECES"); b2c_fprintf(stdout,"\n");
    // 01320 PRINT "IN THIS WAY IF IT IS AT ALL POSSIBLE.  IF IT IS NOT"
    b2c_fprintf(stdout,"IN THIS WAY IF IT IS AT ALL POSSIBLE.  IF IT IS NOT"); b2c_fprintf(stdout,"\n");
    // 01330 PRINT "POSSIBLE, YOU FORFEIT YOUR TURN BY ENTERING"
    b2c_fprintf(stdout,"POSSIBLE, YOU FORFEIT YOUR TURN BY ENTERING"); b2c_fprintf(stdout,"\n");
    // 01340 PRINT "     0,0   FOR YOUR ROW,COLUMN MOVE"
    b2c_fprintf(stdout,"     0,0   FOR YOUR ROW,COLUMN MOVE"); b2c_fprintf(stdout,"\n");
    // 01350 PRINT " GOOD LUCK!"
    b2c_fprintf(stdout," GOOD LUCK!"); b2c_fprintf(stdout,"\n");
    // 01360 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01370 REM********		

  Lbl_01380:
    // 01380 PRINT "SHOULD I WAIT BEFORE MAKING MY MOVES (Y OR N)";
    b2c_fprintf(stdout,"SHOULD I WAIT BEFORE MAKING MY MOVES (Y OR N)"); 
    // 01390 F2 = 0
    F2_int = 0;
    // 01400 F9 = 1
    F9_int = 1;

  Lbl_01410:
    // 01410 INPUT X$
    // Start of Basic INPUT statement 01410
    printf(" ? ");
    char inpbuf_01410[100];
    if(fgets(inpbuf_01410,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01410=strtok(inpbuf_01410," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01410==nullptr){
            X_str = "";
        }else{
            X_str = ps_01410;
        };
    }; // End of Basic INPUT statement 01410
    // 01420 IF X$ = "N" THEN 1460
    if(strcmp(X_str,"N")==0)goto Lbl_01460;
    // 01430 IF X$ <> "Y" THEN  1410
    if(strcmp(X_str,"Y")!=0)goto Lbl_01410;
    // 01440 F2 = 1
    F2_int = 1;
    // 01450         PRINT "OK.  TYPING ANY CHARACTER WILL LET ME GO"
    b2c_fprintf(stdout,"OK.  TYPING ANY CHARACTER WILL LET ME GO"); b2c_fprintf(stdout,"\n");

  Lbl_01460:
    // 01460 PRINT "SHOULD I PLAY MY BEST STRATEGY (Y OR N)";
    b2c_fprintf(stdout,"SHOULD I PLAY MY BEST STRATEGY (Y OR N)"); 
    // 01470 S2 = 0
    S2_int = 0;

  Lbl_01480:
    // 01480 INPUT X$
    // Start of Basic INPUT statement 01480
    printf(" ? ");
    char inpbuf_01480[100];
    if(fgets(inpbuf_01480,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01480=strtok(inpbuf_01480," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01480==nullptr){
            X_str = "";
        }else{
            X_str = ps_01480;
        };
    }; // End of Basic INPUT statement 01480
    // 01490 IF X$ = "N" THEN 1520
    if(strcmp(X_str,"N")==0)goto Lbl_01520;
    // 01500 IF X$ <> "Y" THEN 1480
    if(strcmp(X_str,"Y")!=0)goto Lbl_01480;
    // 01510 S2 = 2
    S2_int = 2;

  Lbl_01520:
    // 01520 B = -1
    B_int = -1;
    // 01530 W = +1
    W_int = 1;
    // 01540 D$(B +1) ="X"
    GLBpStr="X";
    D_str_arr[(int)B_int+1] = (GLBpStr==GLB_StrCatBuf)?strdup(GLBpStr):GLBpStr;
    // 01550 D$(0 +1) = "."
    GLBpStr=".";
    D_str_arr[(int)0+1] = (GLBpStr==GLB_StrCatBuf)?strdup(GLBpStr):GLBpStr;
    // 01560 D$(W + 1) ="O"
    GLBpStr="O";
    D_str_arr[(int)W_int+1] = (GLBpStr==GLB_StrCatBuf)?strdup(GLBpStr):GLBpStr;
    // 01570 FOR K = 1 TO 8
    for(K_int=1;K_int<=8;K_int++){
        // 01580     READ I4(K)
        I4_int_arr[(int)K_int] = Get_Data_Int();
        // 01590 NEXT K
        int dummy_1590=0; // Ignore this line.
    }; // End-For(K_int)
    // 01600 DATA 0,-1,-1,-1,0,1,1,1
    // 01610 FOR K=1 TO 8
    for(K_int=1;K_int<=8;K_int++){
        // 01620     READ J4(K)
        J4_int_arr[(int)K_int] = Get_Data_Int();
        // 01630 NEXT K
        int dummy_1630=0; // Ignore this line.
    }; // End-For(K_int)
    // 01640 DATA 1,1,0,-1,-1,-1,0,1
    // 01650 FOR K = 1 TO 8
    for(K_int=1;K_int<=8;K_int++){
        // 01660     READ C$(K)
        C_str_arr[(int)K_int] = Get_Data_String();
        // 01670 NEXT K
        int dummy_1670=0; // Ignore this line.
    }; // End-For(K_int)
    // 01680 DATA A,B,C,D,E,F,G,H
    // 01690 REM********		SET UP A NEW GAME

  Lbl_01700:
    // 01700 FOR I = 0 TO 9
    for(I_int=0;I_int<=9;I_int++){
        // 01710     FOR J = 0 TO 9
        for(J_int=0;J_int<=9;J_int++){
            // 01720 	A(I,J)=0
            A_int_arr[(int)I_int][(int)J_int] = 0;
            // 01730     NEXT J
            int dummy_1730=0; // Ignore this line.
        }; // End-For(J_int)
        // 01740 NEXT I
        int dummy_1740=0; // Ignore this line.
    }; // End-For(I_int)
    // 01750 A(4,4) = W
    A_int_arr[(int)4][(int)4] = W_int;
    // 01760 A(5,5) = W
    A_int_arr[(int)5][(int)5] = W_int;
    // 01770 A(4,5) = B
    A_int_arr[(int)4][(int)5] = B_int;
    // 01780 A(5,4) = B
    A_int_arr[(int)5][(int)4] = B_int;
    // 01790 C1 = 2
    C1_int = 2;
    // 01800 H1 = 2
    H1_int = 2;
    // 01810 N1 = 4
    N1_int = 4;
    // 01820 Z =0
    Z_int = 0;
    // 01830 REM********		HUMAN'S CHOICES
    // 01840 PRINT "DO YOU WANT TO HAVE X OR O";
    b2c_fprintf(stdout,"DO YOU WANT TO HAVE X OR O"); 
    // 01850 C = W
    C_int = W_int;
    // 01860 H = B
    H_int = B_int;

  Lbl_01870:
    // 01870 INPUT X$
    // Start of Basic INPUT statement 01870
    printf(" ? ");
    char inpbuf_01870[100];
    if(fgets(inpbuf_01870,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01870=strtok(inpbuf_01870," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01870==nullptr){
            X_str = "";
        }else{
            X_str = ps_01870;
        };
    }; // End of Basic INPUT statement 01870
    // 01880 IF X$ = "X" THEN 1920
    if(strcmp(X_str,"X")==0)goto Lbl_01920;
    // 01890 IF X$ <> "O" THEN 1870
    if(strcmp(X_str,"O")!=0)goto Lbl_01870;
    // 01900 C = B
    C_int = B_int;
    // 01910 H = W
    H_int = W_int;

  Lbl_01920:
    // 01920 PRINT "DO YOU WANT TO GO FIRST (Y OR N)";
    b2c_fprintf(stdout,"DO YOU WANT TO GO FIRST (Y OR N)"); 

  Lbl_01930:
    // 01930 INPUT X$
    // Start of Basic INPUT statement 01930
    printf(" ? ");
    char inpbuf_01930[100];
    if(fgets(inpbuf_01930,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01930=strtok(inpbuf_01930," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01930==nullptr){
            X_str = "";
        }else{
            X_str = ps_01930;
        };
    }; // End of Basic INPUT statement 01930
    // 01940 PRINT CHR$(26)
    b2c_fprintf(stdout,"%s",CHR(26)); b2c_fprintf(stdout,"\n");
    // 01950 IF X$ = "N" THEN 2030
    if(strcmp(X_str,"N")==0)goto Lbl_02030;
    // 01960 IF X$ <> "Y" THEN 1930
    if(strcmp(X_str,"Y")!=0)goto Lbl_01930;
    // 01970 REM********		PRINT INITIAL BOARD
    // 01980 GOSUB 4340
    Routine_04340();
    // 01990 GO TO 2760
    goto Lbl_02760;
    // 02000 REM********		COMPUTER'S MOVE

  Lbl_02010:
    // 02010 IF F2 = 0 THEN 2030
    if(F2_int==0)goto Lbl_02030;
    // 02020 INPUT X$
    // Start of Basic INPUT statement 02020
    printf(" ? ");
    char inpbuf_02020[100];
    if(fgets(inpbuf_02020,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_02020=strtok(inpbuf_02020," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_02020==nullptr){
            X_str = "";
        }else{
            X_str = ps_02020;
        };
    }; // End of Basic INPUT statement 02020

  Lbl_02030:
    // 02030 B1 = -1
    B1_int = -1;
    // 02040 I3 = J3 = 0
    J3_int = I3_int = 0;
    // 02050 T1 = C
    T1_int = C_int;
    // 02060 T2 = H
    T2_int = H_int;
    // 02070 REM********		SCAN FOR BLANK SQUARE
    // 02080 FOR I = 1 TO 8
    for(I_int=1;I_int<=8;I_int++){
        // 02090     FOR J = 1 TO 8
        for(J_int=1;J_int<=8;J_int++){
            // 02100 	IF A(I,J) <> 0 THEN 2390
            if(A_int_arr[(int)I_int][(int)J_int]!=0)goto Lbl_02390;
            // 02110 	REM********		FOUND A BLANK SQUARE
            // 02120 	REM********		DOES IT HAVE AN OPPONENT AS A NEIGHBOUR
            // 02130 	GOSUB 3800
            Routine_03800();
            // 02140 	IF F1 = 0 THEN 2390
            if(F1_int==0)goto Lbl_02390;
            // 02150 	REM********		FOUND OPPONENT AS NEIGHBOUR
            // 02160 	REM********		HOW MANY OF HIS PIECES CAN WE FLIP?
            // 02170 	REM********		DON'T DO IT NOW
            // 02180 	U = -1
            U_int = -1;
            // 02190 	GOSUB 3970
            Routine_03970();
            // 02200 	REM********		EXTRA POINTS FOR BOUNDARY POSITION
            // 02210 	IF S1 = 0 THEN 2390
            if(S1_int==0)goto Lbl_02390;
            // 02220 	IF (I-1) * (I-8) <> 0 THEN 2240
            if((I_int-1)*(I_int-8)!=0)goto Lbl_02240;
            // 02230 	S1 = S1 + S2
            S1_int = S1_int+S2_int;

  Lbl_02240:
            // 02240 	IF (J-1) * (J-8) <> 0 THEN 2270
            if((J_int-1)*(J_int-8)!=0)goto Lbl_02270;
            // 02250 	S1 = S1 +S2
            S1_int = S1_int+S2_int;
            // 02260 	REM********		IS THIS BETTER THAN THE BEST FOUND SO FAR

  Lbl_02270:
            // 02270 	IF S1 < B1 THEN 2390
            if(S1_int<B1_int)goto Lbl_02390;
            // 02280 	IF S1 > B1 THEN 2350
            if(S1_int>B1_int)goto Lbl_02350;
            // 02290 	REM********		A TIE; RANDOM DECISION
            // 02300 	REM********		THE NEXT TWO EXECUTABLE STATEMENTS ARE FOR
            // 02310 	REM********		BASIC WITH RANDOM NUMBERS
            // 02320 	R = RND(1)
            R_int = RND(1);
            // 02330 	IF R > .5 THEN 2390
            if(R_int>0.5)goto Lbl_02390;
            // 02340 	REM********		YES

  Lbl_02350:
            // 02350 	B1 = S1
            B1_int = S1_int;
            // 02360 	I3 = I
            I3_int = I_int;
            // 02370 	J3 = J
            J3_int = J_int;
            // 02380 	REM********		END OF SCAN LOOP

  Lbl_02390:
            // 02390     NEXT J
            int dummy_2390=0; // Ignore this line.
        }; // End-For(J_int)
        // 02400 NEXT I
        int dummy_2400=0; // Ignore this line.
    }; // End-For(I_int)
    // 02410 REM********		COULD WE DO ANYTHING?
    // 02420 IF B1 > 0 THEN 2510
    if(B1_int>0)goto Lbl_02510;
    // 02430 REM********		NO
    // 02440 LET L = 18
    L_int = 18;
    // 02450 GOSUB 4530
    Routine_04530();
    // 02460 PRINT "DAMN! HAVE TO FORFEIT MY MOVE!"
    b2c_fprintf(stdout,"DAMN! HAVE TO FORFEIT MY MOVE!"); b2c_fprintf(stdout,"\n");
    // 02470 IF Z = 1 THEN 3370
    if(Z_int==1)goto Lbl_03370;
    // 02480 Z = 1
    Z_int = 1;
    // 02490 GO TO 2760
    goto Lbl_02760;
    // 02500 REM********		MAKE THE MOVE

  Lbl_02510:
    // 02510 Z = 0
    Z_int = 0;
    // 02520 LET L=15
    L_int = 15;
    // 02530 GOSUB 4530
    Routine_04530();
    // 02540 PRINT "I WILL MOVE TO ";
    b2c_fprintf(stdout,"I WILL MOVE TO "); 
    // 02550 PRINT I3;
    b2c_fprintf(stdout," %d ",I3_int); 
    // 02560 PRINT " , ";
    b2c_fprintf(stdout," , "); 
    // 02570 PRINT C$(J3)
    b2c_fprintf(stdout,"%s",C_str_arr[(int)J3_int]); b2c_fprintf(stdout,"\n");
    // 02580 I= I3
    I_int = I3_int;
    // 02590 J= J3
    J_int = J3_int;
    // 02600 U= 1
    U_int = 1;
    // 02610 GOSUB 3970
    Routine_03970();
    // 02620 C1 = C1 + S1 + 1
    C1_int = C1_int+S1_int+1;
    // 02630 H1 = H1 - S1
    H1_int = H1_int-S1_int;
    // 02640 N1 = N1 + 1
    N1_int = N1_int+1;
    // 02650 LET L=16
    L_int = 16;
    // 02660 GOSUB 4530
    Routine_04530();
    // 02670 PRINT " THAT GIVES ME : ";
    b2c_fprintf(stdout," THAT GIVES ME : "); 
    // 02680 PRINT S1;
    b2c_fprintf(stdout," %d ",S1_int); 
    // 02690 PRINT " OF YOUR PIECES"
    b2c_fprintf(stdout," OF YOUR PIECES"); b2c_fprintf(stdout,"\n");
    // 02700 REM********		PRINT OUT BOARD
    // 02710 GOSUB 4340
    Routine_04340();
    // 02720 REM********		TEST FOR END OF GAME
    // 02730 IF H1 = 0 THEN 3370
    if(H1_int==0)goto Lbl_03370;
    // 02740 IF N1 = 64 THEN 3370
    if(N1_int==64)goto Lbl_03370;
    // 02750 REM********		HUMANS MOVE

  Lbl_02760:
    // 02760 T1 = H
    T1_int = H_int;
    // 02770 T2 = C
    T2_int = C_int;
    // 02780 LET L = 12
    L_int = 12;
    // 02790 GOSUB 4530
    Routine_04530();

  Lbl_02800:
    // 02800 PRINT " YOUR MOVE";
    b2c_fprintf(stdout," YOUR MOVE"); 

  Lbl_02810:
    // 02810 INPUT I, X$
    // Start of Basic INPUT statement 02810
    printf(" ? ");
    char inpbuf_02810[100];
    if(fgets(inpbuf_02810,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_02810=strtok(inpbuf_02810," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_02810==nullptr){
            I_int = 0;
        }else{
            I_int = atof(ps_02810);
        };
        ps_02810=strtok(nullptr," ,\t\n");
        if(ps_02810==nullptr){
            X_str = "";
        }else{
            X_str = ps_02810;
        };
    }; // End of Basic INPUT statement 02810
    // 02820 IF I < 0 THEN 2810
    if(I_int<0)goto Lbl_02810;
    // 02830 IF I > 8 THEN 2810
    if(I_int>8)goto Lbl_02810;
    // 02840 IF I <> 0 THEN 2930
    if(I_int!=0)goto Lbl_02930;
    // 02850 LET L = 18
    L_int = 18;
    // 02860 GOSUB 4530
    Routine_04530();
    // 02870 PRINT "ARE YOU FORFEITING YOUR TURN Y OR N"
    b2c_fprintf(stdout,"ARE YOU FORFEITING YOUR TURN Y OR N"); b2c_fprintf(stdout,"\n");
    // 02880 INPUT X$
    // Start of Basic INPUT statement 02880
    printf(" ? ");
    char inpbuf_02880[100];
    if(fgets(inpbuf_02880,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_02880=strtok(inpbuf_02880," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_02880==nullptr){
            X_str = "";
        }else{
            X_str = ps_02880;
        };
    }; // End of Basic INPUT statement 02880
    // 02890 IF X$ <> "Y" THEN 2800
    if(strcmp(X_str,"Y")!=0)goto Lbl_02800;
    // 02900 IF Z = 1 THEN 3370
    if(Z_int==1)goto Lbl_03370;
    // 02910 Z = 1
    Z_int = 1;
    // 02920 GO TO 2010
    goto Lbl_02010;

  Lbl_02930:
    // 02930 FOR J = 1 TO 8
    for(J_int=1;J_int<=8;J_int++){
        // 02940     IF C$(J) =X$ THEN 2980
        if(strcmp(C_str_arr[(int)J_int],X_str)==0)goto Lbl_02980;
        // 02950 NEXT J
        int dummy_2950=0; // Ignore this line.
    }; // End-For(J_int)
    // 02960 GO TO 2810
    goto Lbl_02810;
    // 02970 REM********		CHECK FOR BLANK

  Lbl_02980:
    // 02980 IF A(I,J) = 0 THEN 3040
    if(A_int_arr[(int)I_int][(int)J_int]==0)goto Lbl_03040;
    // 02990 LET L = 18
    L_int = 18;
    // 03000 GOSUB 4530
    Routine_04530();
    // 03010 PRINT "SORRY, THAT SQUARE IS OCCUPIED, TRY AGAIN"
    b2c_fprintf(stdout,"SORRY, THAT SQUARE IS OCCUPIED, TRY AGAIN"); b2c_fprintf(stdout,"\n");
    // 03020 GO TO 2810
    goto Lbl_02810;
    // 03030 REM********		CHECK FOR LEGAL NEIGHBOUR

  Lbl_03040:
    // 03040 GOSUB 3800
    Routine_03800();
    // 03050 IF F1 = 1 THEN 3110
    if(F1_int==1)goto Lbl_03110;
    // 03060 LET L = 18
    L_int = 18;
    // 03070 GOSUB 4530
    Routine_04530();
    // 03080 PRINT "SORRY, YOU ARE NOT NEXT TO ONE OF MY PIECES. TRY AGAIN.";
    b2c_fprintf(stdout,"SORRY, YOU ARE NOT NEXT TO ONE OF MY PIECES. TRY AGAIN."); 
    // 03090 GO TO 2810
    goto Lbl_02810;
    // 03100 REM********		CHECK IF LEGAL RUN

  Lbl_03110:
    // 03110 U = -1
    U_int = -1;
    // 03120 GOSUB 3970
    Routine_03970();
    // 03130 IF S1 > 0 THEN 3190
    if(S1_int>0)goto Lbl_03190;
    // 03140 LET L = 18
    L_int = 18;
    // 03150 GOSUB 4530
    Routine_04530();
    // 03160 PRINT "SORRY, THAT DOESN'T FLANK A ROW, TRY AGAIN"
    b2c_fprintf(stdout,"SORRY, THAT DOESN'T FLANK A ROW, TRY AGAIN"); b2c_fprintf(stdout,"\n");
    // 03170 GO TO 2810
    goto Lbl_02810;
    // 03180 REM********		EVERYTHING LEGAL; MAKE HUMANS MOVE

  Lbl_03190:
    // 03190 Z = 0
    Z_int = 0;
    // 03200 LET L = 13
    L_int = 13;
    // 03210 GOSUB 4530
    Routine_04530();
    // 03220 PRINT "THAT GIVES YOU";
    b2c_fprintf(stdout,"THAT GIVES YOU"); 
    // 03230 PRINT S1;
    b2c_fprintf(stdout," %d ",S1_int); 
    // 03240 PRINT " OF MY PIECES"
    b2c_fprintf(stdout," OF MY PIECES"); b2c_fprintf(stdout,"\n");
    // 03250 U = 1
    U_int = 1;
    // 03260 GOSUB 3970
    Routine_03970();
    // 03270 H1 = H1 + S1 + 1
    H1_int = H1_int+S1_int+1;
    // 03280 C1 = C1 -S1
    C1_int = C1_int-S1_int;
    // 03290 N1 = N1 + 1
    N1_int = N1_int+1;
    // 03300 REM********		PRINT OUT BOARD
    // 03310 GOSUB 4340
    Routine_04340();
    // 03320 REM********		TEST FOR END OF GAME
    // 03330 IF C1 = 0 THEN 3370
    if(C1_int==0)goto Lbl_03370;
    // 03340 IF N1 = 64 THEN 3370
    if(N1_int==64)goto Lbl_03370;
    // 03350 GO TO 2010
    goto Lbl_02010;
    // 03360 REM********		END OF GAME ; WRAPUP

  Lbl_03370:
    // 03370 LET L = 18
    L_int = 18;
    // 03380 GOSUB 4530
    Routine_04530();
    // 03390 PRINT "FOR RESULTS ON GAME TYPE RETURN!!"
    b2c_fprintf(stdout,"FOR RESULTS ON GAME TYPE RETURN!!"); b2c_fprintf(stdout,"\n");
    // 03400 INPUT X$
    // Start of Basic INPUT statement 03400
    printf(" ? ");
    char inpbuf_03400[100];
    if(fgets(inpbuf_03400,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_03400=strtok(inpbuf_03400," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_03400==nullptr){
            X_str = "";
        }else{
            X_str = ps_03400;
        };
    }; // End of Basic INPUT statement 03400
    // 03410 PRINT CHR$(30),CHR$(26)
    b2c_fprintf(stdout,"%s@%s",CHR(30),CHR(26)); b2c_fprintf(stdout,"\n");
    // 03420 PRINT "YOU HAVE ";
    b2c_fprintf(stdout,"YOU HAVE "); 
    // 03430 PRINT H1;
    b2c_fprintf(stdout," %d ",H1_int); 
    // 03440 PRINT " PIECES, AND I HAVE ";
    b2c_fprintf(stdout," PIECES, AND I HAVE "); 
    // 03450 PRINT C1;
    b2c_fprintf(stdout," %d ",C1_int); 
    // 03460 PRINT " PIECES--- "
    b2c_fprintf(stdout," PIECES--- "); b2c_fprintf(stdout,"\n");
    // 03470 IF H1 = C1 THEN 3510
    if(H1_int==C1_int)goto Lbl_03510;
    // 03480 IF H1 > C1 THEN 3530
    if(H1_int>C1_int)goto Lbl_03530;
    // 03490 PRINT "SORRY, I WON THAT ONE."
    b2c_fprintf(stdout,"SORRY, I WON THAT ONE."); b2c_fprintf(stdout,"\n");
    // 03500 GO TO 3540
    goto Lbl_03540;

  Lbl_03510:
    // 03510 PRINT " A TIE!!!!!"
    b2c_fprintf(stdout," A TIE!!!!!"); b2c_fprintf(stdout,"\n");
    // 03520 GO TO 3720
    goto Lbl_03720;

  Lbl_03530:
    // 03530 PRINT "YOU WON!!!"
    b2c_fprintf(stdout,"YOU WON!!!"); b2c_fprintf(stdout,"\n");

  Lbl_03540:
    // 03540 C1 = C1 - H1
    C1_int = C1_int-H1_int;
    // 03550 IF C1 > 0 THEN 3570
    if(C1_int>0)goto Lbl_03570;
    // 03560 C1 = -C1
    C1_int = -C1_int;

  Lbl_03570:
    // 03570 C1 = (64 * C1)/ N1
    C1_int = (64*C1_int)/N1_int;
    // 03580 PRINT "THAT WAS A ";
    b2c_fprintf(stdout,"THAT WAS A "); 
    // 03590 IF C1 < 11 THEN 3710
    if(C1_int<11)goto Lbl_03710;
    // 03600 IF C1 < 25 THEN 3690
    if(C1_int<25)goto Lbl_03690;
    // 03610 IF C1 < 39 THEN 3670
    if(C1_int<39)goto Lbl_03670;
    // 03620 IF C1 < 53 THEN 3650
    if(C1_int<53)goto Lbl_03650;
    // 03630 PRINT " A PERFECT GAME!"
    b2c_fprintf(stdout," A PERFECT GAME!"); b2c_fprintf(stdout,"\n");
    // 03640 GO TO 3720
    goto Lbl_03720;

  Lbl_03650:
    // 03650 PRINT "WALKAWAY!"
    b2c_fprintf(stdout,"WALKAWAY!"); b2c_fprintf(stdout,"\n");
    // 03660 GO TO 3720
    goto Lbl_03720;

  Lbl_03670:
    // 03670 PRINT "FIGHT!"
    b2c_fprintf(stdout,"FIGHT!"); b2c_fprintf(stdout,"\n");
    // 03680 GO TO 3720
    goto Lbl_03720;

  Lbl_03690:
    // 03690 PRINT "HOT GAME!"
    b2c_fprintf(stdout,"HOT GAME!"); b2c_fprintf(stdout,"\n");
    // 03700 GO TO 3720
    goto Lbl_03720;

  Lbl_03710:
    // 03710 PRINT "SQUEAKER!"
    b2c_fprintf(stdout,"SQUEAKER!"); b2c_fprintf(stdout,"\n");

  Lbl_03720:
    // 03720 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 03730 PRINT"DO YOU WANT TO PLAY AGAIN";
    b2c_fprintf(stdout,"DO YOU WANT TO PLAY AGAIN"); 

  Lbl_03740:
    // 03740 INPUT X$
    // Start of Basic INPUT statement 03740
    printf(" ? ");
    char inpbuf_03740[100];
    if(fgets(inpbuf_03740,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_03740=strtok(inpbuf_03740," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_03740==nullptr){
            X_str = "";
        }else{
            X_str = ps_03740;
        };
    }; // End of Basic INPUT statement 03740
    // 03750 IF X$ = "Y" THEN 1700
    if(strcmp(X_str,"Y")==0)goto Lbl_01700;
    // 03760 IF X$ <> "N" THEN 3740
    if(strcmp(X_str,"N")!=0)goto Lbl_03740;
    // 03770 PRINT "THANKS FOR PLAYING."
    b2c_fprintf(stdout,"THANKS FOR PLAYING."); b2c_fprintf(stdout,"\n");
    // 03780 STOP
    exit(1);
    // 03790 END
   return(0);
};

//---------------------------------------------------------------------------
// End of $RCSfile$ 
//---------------------------------------------------------------------------
