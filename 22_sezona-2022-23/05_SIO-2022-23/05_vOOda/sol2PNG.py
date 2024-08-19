import png

inputprefix = "testcases/";
solutionprefix = "sols-gridi/";
PNGdestination = "sols-gridi/"

c = ['.', '#']; # Karakteri koji oznacavaju blokirana i slobodna polja

T = 8; # Broj test primera

for t in range(1,T+1):
    if(t<10):
        imagePath = PNGdestination + "0" + str(t) + ".png";
        inPath = inputprefix + "0" + str(t) + ".in";
        solPath = solutionprefix + "0" + str(t) + ".out";
    else:
        imagePath = PNGprefix + str(t) + ".png";
        inPath = inputprefix + str(t) + ".in";
        solPath = solutionprefix + str(t) + ".out";

    infile = open(inPath,"r");
    N,M = map(int, infile.readline().split());

    s = [];

    for i in range(N):
        s.append(list(infile.readline()[:-1]));

    infile.close();

    if(solutionprefix!=""):
        solfile = open(solPath,"r");
        ans = int(solfile.readline());

        for i in range(ans):
            x,y = map(int, solfile.readline().split());
            s[x-1][y-1]='V';

        solfile.close();

    img = [];
    for i in range(N):
        row = ();
        for j in range(M):
            if(s[i][j]=='.'):
                row = row + (255, 255, 255, 255);
            if(s[i][j]=='#'):
                row = row + (0, 0, 0, 255);
            if(s[i][j]=='V'):
                row = row + (0, 0, 255, 255);
                
        img.append(row)
    
    with open(imagePath, 'wb') as f:
        w = png.Writer(M, N, greyscale=False, alpha=True);
        w.write(f, img);
    



