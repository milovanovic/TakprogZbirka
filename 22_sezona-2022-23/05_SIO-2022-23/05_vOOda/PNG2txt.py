import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

PNGprefix = "PNG-testcases/";
txtprefix = "testcases/";

c = ['.', '#']; # Karakteri koji oznacavaju blokirana i slobodna polja

T = 5; # Broj test primera

for t in range(1,T+1):
    if(t<10):
        imagePath = PNGprefix + "0" + str(t) + ".png";
        txtPath = txtprefix + "0" + str(t) + ".in";
    else:
        imagePath = PNGprefix + str(t) + ".png";
        txtPath = txtprefix + str(t) + ".in";
    
    image = mpimg.imread(imagePath);

    txtfile = open(txtPath,"w");

    N, M, C = np.shape(image);
    
    txtfile.write(str(N)+" "+str(M)+"\n");

    for i in range(N):
        for j in range(M):
            if((image[i][j]==np.ones(C)).all()):
                txtfile.write(c[0]);
            else:
                txtfile.write(c[1]);
        txtfile.write("\n");

    txtfile.close();
    
    


