totalline=1143
trials=(line-2)/7=1142/7=163
when I try about 160 times, it runs error for there was no change when I type [hjkl]
I doubt that was about memory leakage or I could not understand the rule about this game engine well.So I will try review the code later.
===========================================================================
[edony@edony c2048]$ ./2048 --human
0 4 16
0 0 4 0 
0 0 0 0 
2 0 0 0 
0 0 0 0 
Score: 6

[hjkl] k
2 0 4 0 
0 0 0 0 
0 0 0 0 
0 0 0 2 
Score: 8

[hjkl] h
2 4 0 0 
0 2 0 0 
0 0 0 0 
2 0 0 0 
Score: 10

[hjkl] h
2 4 0 0 
2 0 0 0 
0 0 0 0 
2 2 0 0 
Score: 12

[hjkl] k
2 4 0 0 
4 2 2 0 
0 0 0 0 
0 0 0 0 
Score: 16

[hjkl] h
2 4 0 0 
4 4 0 2 
0 0 0 0 
0 0 0 0 
Score: 20

[hjkl] k
2 8 0 2 
4 0 0 0 
0 0 0 2 
0 0 0 0 
Score: 27

[hjkl] k
2 8 0 4 
4 0 0 0 
0 0 0 0 
0 2 0 0 
Score: 31

[hjkl] h
2 8 4 0 
4 0 0 0 
0 0 0 0 
2 2 0 0 
Score: 33

[hjkl] h
2 8 4 0 
4 0 0 2 
0 0 0 0 
4 0 0 0 
Score: 37

[hjkl] k
2 8 4 2 
8 0 2 0 
0 0 0 0 
0 0 0 0 
Score: 44

[hjkl] l
2 8 4 2 
0 8 0 2 
0 0 2 0 
0 0 0 0 
Score: 46

[hjkl] k
2 16 4 4 
0 0 2 2 
0 0 0 0 
0 0 0 0 
Score: 60

[hjkl] h
2 16 8 0 
0 0 4 0 
2 0 0 0 
0 0 0 0 
Score: 69

[hjkl] k
4 16 8 0 
0 0 4 0 
0 0 0 0 
2 0 0 0 
Score: 73

[hjkl] h
4 16 8 0 
4 0 0 0 
0 0 2 0 
2 0 0 0 
Score: 75

[hjkl] k
8 16 8 0 
0 0 2 0 
2 0 2 0 
0 0 0 0 
Score: 82

[hjkl] h
8 16 8 0 
2 0 0 0 
4 0 2 0 
0 0 0 0 
Score: 86

[hjkl] k
8 16 8 2 
2 0 2 0 
4 0 0 0 
0 0 0 0 
Score: 88

[hjkl] h
8 16 8 2 
4 2 0 0 
4 0 0 0 
0 0 0 0 
Score: 92

[hjkl] k
8 16 8 2 
8 2 0 0 
0 0 2 0 
0 0 0 0 
Score: 99

[hjkl] k
16 16 8 2 
0 2 2 0 
0 0 0 0 
0 0 0 2 
Score: 111

[hjkl] h
32 0 8 2 
0 4 0 0 
2 0 0 0 
2 0 0 0 
Score: 140

[hjkl] k
32 4 8 2 
0 0 0 0 
4 0 0 0 
0 2 0 0 
Score: 144

[hjkl] k
32 4 8 2 
4 2 0 0 
0 0 0 0 
0 0 0 2 
Score: 146

[hjkl] k
32 4 8 4 
4 2 0 0 
0 2 0 0 
0 0 0 0 
Score: 150

[hjkl] k
32 4 8 4 
4 4 0 0 
0 0 0 0 
0 0 0 2 
Score: 154

[hjkl] k
32 8 8 4 
4 0 0 2 
0 0 0 0 
0 0 2 0 
Score: 161

[hjkl] h
32 16 0 4 
4 2 0 0 
0 0 0 0 
2 0 2 0 
Score: 173

[hjkl] k
32 16 2 4 
4 2 0 0 
2 0 0 0 
0 2 0 0 
Score: 175

[hjkl] k
32 16 2 4 
4 4 0 0 
2 0 0 0 
0 0 0 2 
Score: 179

[hjkl] h
32 16 2 4 
8 0 0 0 
2 0 0 2 
2 0 0 0 
Score: 186

[hjkl] k
32 16 2 4 
8 0 0 2 
4 0 0 0 
0 0 0 2 
Score: 190

[hjkl] k
32 16 2 4 
8 0 0 4 
4 0 0 0 
0 0 2 0 
Score: 194

[hjkl] h
32 16 2 4 
8 4 0 0 
4 0 0 0 
2 0 2 0 
Score: 196

[hjkl] l
32 16 2 4 
8 0 0 4 
0 2 0 4 
0 0 4 0 
Score: 200

[hjkl] k
32 16 2 4 
8 2 4 8 
0 0 2 0 
0 0 0 0 
Score: 207

[hjkl] h
32 16 2 4 
8 2 4 8 
2 0 0 0 
2 0 0 0 
Score: 209

[hjkl] k
32 16 2 4 
8 2 4 8 
4 0 0 0 
2 0 0 0 
Score: 213

[hjkl] l
32 16 2 4 
8 2 4 8 
0 2 0 4 
0 0 0 2 
Score: 215

[hjkl] k
32 16 2 4 
8 4 4 8 
0 2 0 4 
0 0 0 2 
Score: 219

[hjkl] h
32 16 2 4 
8 8 2 8 
2 0 4 0 
2 0 0 0 
Score: 226

[hjkl] l
32 16 2 4 
0 16 2 8 
0 2 4 4 
0 0 0 2 
Score: 240

[hjkl] k
32 32 4 4 
0 0 0 8 
0 2 4 4 
2 0 0 2 
Score: 269

[hjkl] h
64 0 8 0 
8 0 0 0 
2 0 8 2 
4 0 0 0 
Score: 333

[hjkl] k
64 0 16 2 
8 0 0 0 
2 0 0 0 
4 0 0 2 
Score: 345

[hjkl] h
64 16 0 2 
8 0 0 2 
2 0 0 0 
4 2 0 0 
Score: 347

[hjkl] k
64 16 0 4 
8 2 0 0 
2 0 4 0 
4 0 0 0 
Score: 353

[hjkl] h
64 16 4 0 
8 2 0 0 
2 4 0 4 
4 0 0 0 
Score: 357

[hjkl] k
64 16 4 4 
8 2 0 0 
2 4 0 2 
4 0 0 0 
Score: 359

[hjkl] h
64 16 8 0 
8 2 0 0 
2 4 2 0 
4 0 0 2 
Score: 366

[hjkl] k
64 16 8 2 
8 2 2 0 
2 4 0 0 
4 2 0 0 
Score: 368

[hjkl] h
64 16 8 2 
8 4 0 0 
2 4 0 2 
4 2 0 0 
Score: 372

[hjkl] k
64 16 8 4 
8 8 0 0 
2 0 0 2 
4 2 0 0 
Score: 381

[hjkl] h
64 16 8 4 
16 0 0 0 
4 4 0 0 
4 2 0 0 
Score: 397

[hjkl] h
64 16 8 4 
16 0 0 0 
8 0 0 0 
4 2 2 0 
Score: 404

[hjkl] h
64 16 8 4 
16 0 0 0 
8 0 0 2 
4 4 0 0 
Score: 408

[hjkl] h
64 16 8 4 
16 0 0 2 
8 2 0 0 
8 0 0 0 
Score: 415

[hjkl] k
64 16 8 4 
16 2 0 2 
16 0 0 2 
0 0 0 0 
Score: 427

[hjkl] k
64 16 8 4 
32 2 0 4 
0 0 0 4 
0 0 0 0 
Score: 458

[hjkl] k
64 16 8 4 
32 2 0 8 
0 0 0 0 
4 0 0 0 
Score: 467

[hjkl] h
64 16 8 4 
32 2 8 0 
0 0 0 0 
4 2 0 0 
Score: 469

[hjkl] k
64 16 16 4 
32 4 0 0 
4 0 0 2 
0 0 0 0 
Score: 483

[hjkl] h
64 32 0 4 
32 4 0 0 
4 2 0 2 
0 0 0 0 
Score: 510

[hjkl] h
64 32 4 0 
32 4 0 0 
4 4 0 2 
0 0 0 0 
Score: 514

[hjkl] k
64 32 4 2 
32 8 0 0 
4 0 0 0 
0 2 0 0 
Score: 521

[hjkl] k
64 32 4 2 
32 8 0 2 
4 2 0 0 
0 0 0 0 
Score: 523

[hjkl] l
64 32 4 2 
32 0 8 2 
4 0 2 2 
0 0 0 0 
Score: 525

[hjkl] k
64 32 4 2 
32 0 8 4 
4 0 2 0 
0 2 0 0 
Score: 529

[hjkl] h
64 32 4 2 
32 8 0 4 
4 2 2 0 
2 0 0 0 
Score: 531

[hjkl] h
64 32 4 2 
32 8 4 0 
4 4 4 0 
2 0 0 0 
Score: 537

[hjkl] k
64 32 4 2 
32 8 8 0 
4 4 0 4 
2 0 0 0 
Score: 546

[hjkl] h
64 32 4 2 
32 16 0 2 
4 8 0 0 
2 0 0 0 
Score: 563

[hjkl] k
64 32 4 4 
32 16 0 0 
4 8 0 0 
2 0 0 2 
Score: 567

[hjkl] h
64 32 8 0 
32 16 2 0 
4 8 0 0 
4 0 0 0 
Score: 576

[hjkl] k
64 32 8 0 
32 16 2 4 
8 8 0 0 
0 0 0 0 
Score: 585

[hjkl] k
64 32 8 4 
32 16 2 0 
8 8 0 0 
4 0 0 0 
Score: 589

[hjkl] l
64 32 8 4 
32 16 0 2 
4 16 0 0 
0 0 0 4 
Score: 603

[hjkl] l
64 32 8 4 
32 0 16 2 
4 0 2 16 
0 0 0 4 
Score: 605

[hjkl] l
64 32 8 4 
0 32 16 2 
0 4 2 16 
0 0 2 4 
Score: 607

[hjkl] k
64 64 8 4 
0 0 16 2 
2 4 4 16 
0 0 0 4 
Score: 661

[hjkl] h
128 0 8 4 
16 0 2 2 
2 8 0 16 
4 0 0 0 
Score: 793

[hjkl] k
128 8 8 4 
16 0 2 2 
2 0 0 16 
4 2 0 0 
Score: 795

[hjkl] h
128 16 0 4 
16 0 4 0 
2 16 2 0 
4 2 0 0 
Score: 809

[hjkl] k
128 32 4 4 
16 0 2 0 
2 0 2 0 
4 2 0 0 
Score: 836

[hjkl] h
128 32 8 0 
16 2 0 0 
4 0 0 0 
4 2 0 2 
Score: 845

[hjkl] k
128 32 8 2 
16 4 2 0 
8 0 0 0 
0 0 0 0 
Score: 854

[hjkl] l
128 32 8 2 
16 4 2 2 
0 0 0 8 
0 0 0 0 
Score: 856

[hjkl] k 
128 32 8 4 
16 4 2 0 
0 0 0 8 
0 0 2 0 
Score: 860

[hjkl] k
128 32 8 4 
16 4 4 8 
2 0 0 0 
0 0 0 0 
Score: 864

[hjkl] h
128 32 8 4 
16 8 0 8 
2 0 0 0 
2 0 0 0 
Score: 871

[hjkl] l
128 32 8 4 
16 0 0 16 
2 0 0 2 
0 0 0 2 
Score: 883

[hjkl] h
128 32 8 4 
32 0 0 0 
4 0 0 0 
2 0 2 0 
Score: 912

[hjkl] l
128 32 8 4 
0 0 0 32 
0 0 0 4 
4 0 4 0 
Score: 918

[hjkl] k
128 32 8 4 
4 0 4 32 
0 0 0 4 
0 0 2 0 
Score: 920

[hjkl] h
128 32 8 4 
8 0 0 32 
4 0 0 0 
2 2 0 0 
Score: 927

[hjkl] h
128 32 8 4 
8 32 0 0 
4 0 0 0 
4 0 2 0 
Score: 931

[hjkl] k
128 64 8 4 
8 0 2 0 
8 0 0 0 
0 2 0 0 
Score: 988

[hjkl] k
128 64 8 4 
16 2 2 0 
0 0 0 0 
0 2 0 0 
Score: 1000

[hjkl] h
128 64 8 4 
16 4 0 0 
0 0 0 0 
2 2 0 0 
Score: 1004

[hjkl] l
128 64 8 4 
16 0 0 4 
0 2 0 0 
0 4 0 0 
Score: 1008

[hjkl] k
128 64 8 8 
16 2 0 0 
2 0 0 0 
0 4 0 0 
Score: 1015

[hjkl] h
128 64 16 2 
16 2 0 0 
2 0 0 0 
4 0 0 0 
Score: 1027

[hjkl] l
128 64 16 2 
16 0 2 2 
0 0 0 2 
0 0 0 4 
Score: 1029

[hjkl] k
128 64 16 2 
16 0 2 4 
0 0 0 0 
0 0 4 4 
Score: 1035

[hjkl] k
128 64 16 2 
16 0 2 8 
0 0 4 0 
2 0 0 0 
Score: 1042

[hjkl] k
128 64 16 2 
16 0 2 8 
2 0 4 0 
0 0 0 4 
Score: 1046

[hjkl] l
128 64 16 2 
0 16 2 8 
0 2 2 4 
0 0 0 4 
Score: 1048

[hjkl] k
128 64 16 2 
0 16 4 8 
0 2 0 8 
0 2 0 0 
Score: 1057

[hjkl] k
128 64 16 2 
0 16 4 16 
0 4 0 0 
0 0 2 0 
Score: 1071

[hjkl] k
128 64 16 2 
0 16 4 16 
0 4 2 2 
0 0 0 0 
Score: 1073

[hjkl] l
128 64 16 2 
0 16 4 16 
2 4 0 4 
0 0 0 0 
Score: 1077

[hjkl] h
128 64 16 2 
16 2 4 16 
2 8 0 0 
0 0 0 0 
Score: 1084

[hjkl] l
128 64 16 2 
16 2 4 16 
2 0 2 8 
0 0 0 0 
Score: 1086

[hjkl] l
128 64 16 2 
16 2 4 16 
0 0 4 8 
2 0 0 0 
Score: 1090

[hjkl] k
128 64 16 2 
16 2 8 16 
2 0 0 8 
0 0 4 0 
Score: 1099

[hjkl] l
128 64 16 2 
16 2 8 16 
0 2 2 8 
0 0 0 4 
Score: 1101

[hjkl] h
128 64 16 2 
16 2 8 16 
0 4 0 8 
4 0 0 2 
Score: 1105

[hjkl] h
128 64 16 2 
16 2 8 16 
4 0 8 2 
4 2 0 0 
Score: 1107

[hjkl] k
128 64 16 2 
16 4 16 16 
8 0 0 2 
0 2 0 0 
Score: 1126

[hjkl] k
128 64 32 2 
16 4 0 16 
8 2 0 2 
0 0 2 0 
Score: 1153

[hjkl] k
128 64 32 2 
16 4 2 16 
8 2 2 2 
0 0 0 0 
Score: 1155

[hjkl] k
128 64 32 2 
16 4 4 16 
8 2 0 2 
0 0 0 4 
Score: 1161

[hjkl] h
128 64 32 2 
16 8 0 16 
8 4 0 0 
4 2 0 0 
Score: 1170

[hjkl] l
128 64 32 2 
16 2 8 16 
8 0 0 4 
4 0 0 2 
Score: 1172

[hjkl] h
128 64 32 2 
16 2 8 16 
8 4 0 0 
4 2 2 0 
Score: 1174

[hjkl] h
128 64 32 2 
16 2 8 16 
8 4 0 0 
4 4 0 2 
Score: 1178

[hjkl] k
128 64 32 2 
16 2 8 16 
8 8 0 2 
4 0 0 2 
Score: 1185

[hjkl] k
128 64 32 2 
16 2 8 16 
8 8 4 4 
4 0 0 0 
Score: 1191

[hjkl] l
128 64 32 2 
16 2 8 16 
0 16 2 8 
0 0 0 4 
Score: 1208

[hjkl] h
128 64 32 2 
16 2 8 16 
16 0 2 8 
4 0 0 2 
Score: 1210

[hjkl] h
128 64 32 2 
16 2 8 16 
16 2 0 8 
4 2 2 0 
Score: 1212

[hjkl] k
128 64 32 2 
32 2 8 16 
0 4 2 8 
4 0 0 2 
Score: 1241

[hjkl] h
128 64 32 2 
32 2 8 16 
4 0 2 8 
4 2 4 0 
Score: 1245

[hjkl] h
128 64 32 2 
32 2 8 16 
4 2 2 8 
4 2 4 0 
Score: 1247

[hjkl] k
128 64 32 2 
32 2 8 16 
8 4 2 8 
0 0 4 2 
Score: 1256

[hjkl] h
128 64 32 2 
32 2 8 16 
8 4 2 8 
4 0 2 2 
Score: 1258

[hjkl] k
128 64 32 2 
32 2 8 16 
8 4 4 8 
4 0 2 2 
Score: 1262

[hjkl] l
128 64 32 2 
32 2 8 16 
8 0 8 8 
0 4 2 4 
Score: 1271

[hjkl] k
128 64 32 2 
32 2 16 16 
8 4 0 8 
4 0 2 4 
Score: 1285

[hjkl] h
128 64 32 2 
32 2 32 0 
8 4 8 2 
4 2 0 4 
Score: 1312

[hjkl] k
128 64 64 4 
32 2 0 0 
8 4 8 0 
4 2 2 4 
Score: 1366

[hjkl] h
128 128 0 4 
32 2 2 0 
8 4 8 0 
4 4 0 4 
Score: 1495

[hjkl] h
256 0 4 0 
32 4 0 0 
8 4 8 2 
4 8 0 0 
Score: 1754

[hjkl] k
256 0 4 2 
32 8 8 0 
8 0 0 0 
4 8 2 0 
Score: 1761

[hjkl] h
256 4 0 2 
32 16 0 0 
8 0 0 0 
4 8 2 2 
Score: 1773

[hjkl] k
256 4 2 4 
32 16 4 0 
8 8 0 0 
4 0 0 0 
Score: 1779

[hjkl] h
256 4 2 4 
32 16 4 0 
16 0 0 2 
4 0 0 0 
Score: 1791

[hjkl] l
256 4 2 4 
32 16 0 4 
0 0 16 2 
0 2 0 4 
Score: 1793

[hjkl] k
256 4 2 8 
32 16 16 0 
0 2 0 2 
2 0 0 4 
Score: 1800

[hjkl] h
256 4 2 8 
32 32 2 0 
0 4 0 0 
2 4 0 0 
Score: 1829

[hjkl] h
256 4 2 8 
64 0 2 0 
4 0 0 0 
2 4 2 0 
Score: 1881

[hjkl] k
256 8 2 8 
64 0 4 0 
4 0 0 0 
2 0 0 2 
Score: 1890

[hjkl] k
256 8 2 8 
64 0 4 2 
4 2 0 0 
2 0 0 0 
Score: 1892

[hjkl] h
256 8 2 8 
64 4 2 2 
4 2 0 0 
2 0 0 0 
Score: 1894

[hjkl] h
256 8 2 8 
64 4 4 2 
4 2 0 0 
2 0 0 0 
Score: 1898

[hjkl] h
256 8 2 8 
64 8 0 2 
4 2 0 2 
2 0 0 0 
Score: 1905

[hjkl] k
256 16 2 8 
64 0 0 4 
4 2 0 0 
2 0 2 0 
Score: 1919

[hjkl] kh
256 16 4 8 
64 2 0 4 
4 0 0 0 
2 0 2 0 
Score: 1923

[hjkl] k
256 16 4 8 
64 2 0 4 
4 0 0 0 
2 0 2 0 
Score: 1923

[hjkl] k 
256 16 4 8 
64 2 0 4 
4 0 0 0 
2 0 2 0 
Score: 1923

[hjkl] k
256 16 4 8 
64 2 0 4 
4 0 0 0 
2 0 2 0 
Score: 1923

[hjkl] h
256 16 4 8 
64 2 0 4 
4 0 0 0 
2 0 2 0 
Score: 1923

[hjkl] 

