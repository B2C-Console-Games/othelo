1000	REM********		OTHELLO          BYTE VOL. 2, NUMBER 10 (OCT. 1977)
1010	REM********		PLAYS THE GAME OTHELLO WITH TWO STRATEGIES
1020	REM********		1. TAKE THE MAX. NUMBER OF PIECES
1030	REM********		2. ADD A BONUS FOR OUTSIDE POSITION
1040	REM********		BOARD IS THE ARRAY A, BOUNDED BY 0'S (BLANKS)
1050	REM********		A = 0 FOR EMPTY SQUARE
1060	REM********		A = B FOR BLACK SQUARE
1070	REM********		A = W FOR WHITE SQUARE
1080	REM********		I AND J ARE ALWAYS USED FOR ROW/COLUMN INDICES
1090	REM********		I1 AND J4 STORE INCREMENTS TO THE 8 NEIGHBOURS
1100	REM********		C$ AND D$ STORE CHARACTERS A-H,X,...,O FOR OUTPUT
1110	DIM A(9,9),I4(8),J4(8),C$(8),D$(2)
1120	REM********		
1130	PRINT "GREETINGS FROM OTHELLO!"
1140	PRINT "DO YOU WANT INSTRUCTIONS (Y OR N)";
1150	INPUT X$
1160	IF X$ = "N" THEN 1380
1170	IF X$ <> "Y" THEN 1150
1180	PRINT
1190	PRINT "OTHELLO IS PLAYED ON AN 8X8 CHECKER BOARD"
1200	PRINT "ROWS ARE NUMBERED FROM 1 TO 8 AND COLUMNS FROM A TO H"
1210	PRINT" THE INITIAL CONFIGURATION IS ALL BLANK EXCEPT FOR"
1220	PRINT "THE CENTER FOUR SQUARES, WHICH FORM THE PATTERN:"
1230	PRINT "               O X"
1240	PRINT "               X O"
1250	PRINT
1260	PRINT "TRY TO PLACE YOUR PIECE SO THAT IT WILL 'OUTFLANK' MINE"
1270	PRINT "THEREBY CREATING A HORIZONTAL, VERTICAL, OR DIAGONAL "
1280	PRINT "RUN OF MY PIECES BOUNDED AT EACH END BY AT LEAST ONE "
1290	PRINT "OF YOURS.  THIS WILL 'FLIP' MY PIECES, TURNING THEM INTO"
1300	PRINT "YOURS."
1310	PRINT"     NOTE: YOU MUST CAPTURE AT LEAST ONE OF MY PIECES"
1320	PRINT "IN THIS WAY IF IT IS AT ALL POSSIBLE.  IF IT IS NOT"
1330	PRINT "POSSIBLE, YOU FORFEIT YOUR TURN BY ENTERING"
1340	PRINT "     0,0   FOR YOUR ROW,COLUMN MOVE"
1350	PRINT " GOOD LUCK!"
1360	PRINT
1370	REM********		
1380	PRINT "SHOULD I WAIT BEFORE MAKING MY MOVES (Y OR N)";
1390	F2 = 0
1400	F9 = 1
1410	INPUT X$
1420	IF X$ = "N" THEN 1460
1430	IF X$ <> "Y" THEN  1410
1440	F2 = 1
1450	        PRINT "OK.  TYPING ANY CHARACTER WILL LET ME GO"
1460	PRINT "SHOULD I PLAY MY BEST STRATEGY (Y OR N)";
1470	S2 = 0
1480	INPUT X$
1490	IF X$ = "N" THEN 1520
1500	IF X$ <> "Y" THEN 1480
1510	S2 = 2
1520	B = -1
1530	W = +1
1540	D$(B +1) ="X"
1550	D$(0 +1) = "."
1560	D$(W + 1) ="O"
1570	FOR K = 1 TO 8
1580	    READ I4(K)
1590	NEXT K
1600	DATA 0,-1,-1,-1,0,1,1,1
1610	FOR K=1 TO 8
1620	    READ J4(K)
1630	NEXT K
1640	DATA 1,1,0,-1,-1,-1,0,1
1650	FOR K = 1 TO 8
1660	    READ C$(K)
1670	NEXT K
1680	DATA A,B,C,D,E,F,G,H
1690	REM********		SET UP A NEW GAME
1700	FOR I = 0 TO 9
1710	    FOR J = 0 TO 9
1720		A(I,J)=0
1730	    NEXT J
1740	NEXT I
1750	A(4,4) = W
1760	A(5,5) = W
1770	A(4,5) = B
1780	A(5,4) = B
1790	C1 = 2
1800	H1 = 2
1810	N1 = 4
1820	Z =0
1830	REM********		HUMAN'S CHOICES
1840	PRINT "DO YOU WANT TO HAVE X OR O";
1850	C = W
1860	H = B
1870	INPUT X$
1880	IF X$ = "X" THEN 1920
1890	IF X$ <> "O" THEN 1870
1900	C = B
1910	H = W
1920	PRINT "DO YOU WANT TO GO FIRST (Y OR N)";
1930	INPUT X$
1940	PRINT CHR$(26)
1950	IF X$ = "N" THEN 2030
1960	IF X$ <> "Y" THEN 1930
1970	REM********		PRINT INITIAL BOARD
1980	GOSUB 4320
1990	GO TO 2760
2000	REM********		COMPUTER'S MOVE
2010	IF F2 = 0 THEN 2030
2020	INPUT X$
2030	B1 = -1
2040	I3 = J3 = 0
2050	T1 = C
2060	T2 = H
2070	REM********		SCAN FOR BLANK SQUARE
2080	FOR I = 1 TO 8
2090	    FOR J = 1 TO 8
2100		IF A(I,J) <> 0 THEN 2390
2110		REM********		FOUND A BLANK SQUARE
2120		REM********		DOES IT HAVE AN OPPONENT AS A NEIGHBOUR
2130		GOSUB 3840
2140		IF F1 = 0 THEN 2390
2150		REM********		FOUND OPPONENT AS NEIGHBOUR
2160		REM********		HOW MANY OF HIS PIECES CAN WE FLIP?
2170		REM********		DON'T DO IT NOW
2180		U = -1
2190		GOSUB 4040
2200		REM********		EXTRA POINTS FOR BOUNDARY POSITION
2210		IF S1 = 0 THEN 2390
2220		IF (I-1) * (I-8) <> 0 THEN 2240
2230		S1 = S1 + S2
2240		IF (J-1) * (J-8) <> 0 THEN 2270
2250		S1 = S1 +S2
2260		REM********		IS THIS BETTER THAN THE BEST FOUND SO FAR
2270		IF S1 < B1 THEN 2390
2280		IF S1 > B1 THEN 2350
2290		REM********		A TIE; RANDOM DECISION
2300		REM********		THE NEXT TWO EXECUTABLE STATEMENTS ARE FOR
2310		REM********		BASIC WITH RANDOM NUMBERS
2320		R = RND(1)
2330		IF R > .5 THEN 2390
2340		REM********		YES
2350		B1 = S1
2360		I3 = I
2370		J3 = J
2380		REM********		END OF SCAN LOOP
2390	    NEXT J
2400	NEXT I
2410	REM********		COULD WE DO ANYTHING?
2420	IF B1 > 0 THEN 2510
2430	REM********		NO
2440	LET L = 18
2450	GOSUB 4490
2460	PRINT "DAMN! HAVE TO FORFEIT MY MOVE!"
2470	IF Z = 1 THEN 3370
2480	Z = 1
2490	GO TO 2760
2500	REM********		MAKE THE MOVE
2510	Z = 0
2520	LET L=15
2530	GOSUB 4490
2540	PRINT "I WILL MOVE TO ";
2550	PRINT I3;
2560	PRINT " , ";
2570	PRINT C$(J3)
2580	I= I3
2590	J= J3
2600	U= 1
2610	GOSUB 4040
2620	C1 = C1 + S1 + 1
2630	H1 = H1 - S1
2640	N1 = N1 + 1
2650	LET L=16
2660	GOSUB 4490
2670	PRINT " THAT GIVES ME : ";
2680	PRINT S1;
2690	PRINT " OF YOUR PIECES"
2700	REM********		PRINT OUT BOARD
2710	GOSUB 4320
2720	REM********		TEST FOR END OF GAME
2730	IF H1 = 0 THEN 3370
2740	IF N1 = 64 THEN 3370
2750	REM********		HUMANS MOVE
2760	T1 = H
2770	T2 = C
2780	LET L = 12
2790	GOSUB 4490
2800	PRINT " YOUR MOVE";
2810	INPUT I, X$
2820	IF I < 0 THEN 2810
2830	IF I > 8 THEN 2810
2840	IF I <> 0 THEN 2930
2850	LET L = 18
2860	GOSUB 4490
2870	PRINT "ARE YOU FORFEITING YOUR TURN Y OR N"
2880	INPUT X$
2890	IF X$ <> "Y" THEN 2800
2900	IF Z = 1 THEN 3370
2910	Z = 1
2920	GO TO 2010
2930	FOR J = 1 TO 8
2940	    IF C$(J) =X$ THEN 2980
2950	NEXT J
2960	GO TO 2810
2970	REM********		CHECK FOR BLANK
2980	IF A(I,J) = 0 THEN 3040
2990	LET L = 18
3000	GOSUB 4490
3010	PRINT "SORRY, THAT SQUARE IS OCCUPIED, TRY AGAIN"
3020	GO TO 2810
3030	REM********		CHECK FOR LEGAL NEIGHBOUR
3040	GOSUB 3840
3050	IF F1 = 1 THEN 3110
3060	LET L = 18
3070	GOSUB 4490
3080	PRINT "SORRY, YOU ARE NOT NEXT TO ONE OF MY PIECES. TRY AGAIN.";
3090	GO TO 2810
3100	REM********		CHECK IF LEGAL RUN
3110	U = -1
3120	GOSUB 4040
3130	IF S1 > 0 THEN 3190
3140	LET L = 18
3150	GOSUB 4490
3160	PRINT "SORRY, THAT DOESN'T FLANK A ROW, TRY AGAIN"
3170	GO TO 2810
3180	REM********		EVERYTHING LEGAL; MAKE HUMANS MOVE
3190	Z = 0
3200	LET L = 13
3210	GOSUB 4490
3220	PRINT "THAT GIVES YOU";
3230	PRINT S1;
3240	PRINT " OF MY PIECES"
3250	U = 1
3260	GOSUB 4040
3270	H1 = H1 + S1 + 1
3280	C1 = C1 -S1
3290	N1 = N1 + 1
3300	REM********		PRINT OUT BOARD
3310	GOSUB 4320
3320	REM********		TEST FOR END OF GAME
3330	IF C1 = 0 THEN 3370
3340	IF N1 = 64 THEN 3370
3350	GO TO 2010
3360	REM********		END OF GAME ; WRAPUP
3370	LET L = 18
3380	GOSUB 4490
3390	PRINT "FOR RESULTS ON GAME TYPE RETURN!!"
3400	INPUT X$
3410	PRINT CHR$(30),CHR$(26)
3420	PRINT "YOU HAVE ";
3430	PRINT H1;
3440	PRINT " PIECES, AND I HAVE ";
3450	PRINT C1;
3460	PRINT " PIECES--- "
3470	IF H1 = C1 THEN 3510
3480	IF H1 > C1 THEN 3530
3490	PRINT "SORRY, I WON THAT ONE."
3500	GO TO 3540
3510	PRINT " A TIE!!!!!"
3520	GO TO 3720
3530	PRINT "YOU WON!!!"
3540	C1 = C1 - H1
3550	IF C1 > 0 THEN 3570
3560	C1 = -C1
3570	C1 = (64 * C1)/ N1
3580	PRINT "THAT WAS A ";
3590	IF C1 < 11 THEN 3710
3600	IF C1 < 25 THEN 3690
3610	IF C1 < 39 THEN 3670
3620	IF C1 < 53 THEN 3650
3630	PRINT " A PERFECT GAME!"
3640	GO TO 3720
3650	PRINT "WALKAWAY!"
3660	GO TO 3720
3670	PRINT "FIGHT!"
3680	GO TO 3720
3690	PRINT "HOT GAME!"
3700	GO TO 3720
3710	PRINT "SQUEAKER!"
3720	PRINT
3730	PRINT"DO YOU WANT TO PLAY AGAIN";
3740	INPUT X$
3750	IF X$ = "Y" THEN 1700
3760	IF X$ <> "N" THEN 3740
3770	PRINT "THANKS FOR PLAYING."
3780	STOP
3790	REM********		
3800	REM********		SUBROUTINE: TEST FOR PROPER NEIGHBOUR
3810	REM********		ASSUMES:
3820	REM********		I,J LOCATES A BLANK SQUARE
3830	REM********		YOU HOPE TO SEE AN ADJACENT  T2 (= -T1)
3840	FOR I1 =  -1 TO 1
3850	    FOR J1 = -1 TO 1
3860		IF  A(I+I1,J+J1) = T2 THEN 3930
3870	    NEXT J1
3880	NEXT I1
3890	REM********		NO T2 FOUND
3900	F1 = 0
3910	RETURN
3920	REM********		SUCCESS
3930	F1 = 1
3940	RETURN
3950	REM********		SUBROUTINE SCORE AND UPDATE
3960	REM********		ASSUMES;
3970	REM********		(I,J) IS A TENTATIVE PLACE FOR A PIECE T1.
3980	REM********		WANT RUNS OF T2 = -T1, TERMINATED BY A T1.
3990	REM********		IF U IS TRUE (1), MARK THOSE RUNS AS T1'S.
4000	REM********		RETURN SUM OF ALL RUNS (T2'S ONLY) IN S1.
4010	REM********		MAIN PROGRAM CONTAINS THE FOLLOWING ARRAYS:
4020	REM********		I4:  0 -1 -1 -1  0  1  1  1
4030	REM********		J4:  1  1  0 -1 -1 -1  0  1
4040	S1 = 0
4050	FOR K = 1 TO 8
4060	    I5 = I4(K)
4070	    J5 = J4(K)
4080	    I6 = I + I5
4090	    J6 = J + J5
4100	    S3 = 0
4110	    IF A(I6,J6) <> T2 THEN 4290
4120	    REM			LOOP THROUGH THE RUN
4130	    S3 = S3 + 1
4140	    I6 = I6 + I5
4150	    J6 = J6 + J5
4160	    IF A (I6,J6) = T1 THEN 4190
4170	    IF A(I6,J6) = 0 THEN 4290
4180	    GO TO 4130
4190	    S1 = S1 + S3
4200	    IF U <> 1 THEN 4290
4210	    REM			UPDATE BOARD
4220	    I6 = I
4230	    J6 = J
4240	    FOR K1 = 0 TO S3
4250		A(I6,J6) = T1
4260		I6 = I6 + I5
4270		J6 = J6 + J5
4280	    NEXT K1
4290	NEXT K
4300	RETURN
4310	REM********		SUBROUTINE TO PRINT BOARD
4320	PRINT CHR$(30)
4330	LET L = 18
4340	IF F9 = 1 GO TO 4370
4350	GOSUB 4570
4360	LET F9 = 1
4370	PRINT CHR$(30)
4380	PRINT "    A B C D E F G H"
4390	FOR I = 1 TO 8
4400	    PRINT I;
4410	    FOR J = 1 TO 8
4420		PRINT " ";
4430		PRINT D$(A(I,J)+1);
4440	    NEXT J
4450	    PRINT
4460	NEXT I
4470	PRINT
4480	RETURN
4490	REM********		***	SPACE		***
4500	PRINT CHR$(30)
4510	FOR I9 = 1 TO L
4520	    PRINT
4530	NEXT I9
4540	IF L <> 18 GO TO 4560
4550	F9 = 0
4560	RETURN
4570	REM********		***	BLANK OUT	***
4580	GOSUB 4490
4590	PRINT TAB(60);" "
4600	PRINT TAB(60);" "
4610	RETURN
4620	END
