import heapq
import os
import numpy as np
import math
from collections import Counter

class entropyCoding:
    def __init__(self, path):
        self.path = path

    def entropy(self, data):
        text = open('sql.html','r').read()
        chars=list(data)
        length=len(chars)

        print ("Número de caracteres: %d"%(length))
        chars = str(chars)
        dec=[ord(c) for c in chars]
        decset=set(dec)

        freqdic={}
        for c in decset:
            freqdic[c]=dec.count(c)

        Entropy=0

        for c in decset:
            prop=freqdic[c]/(1*length)
            informationContent=np.log2(1.0/prop)
            Entropy+=prop*informationContent

        return (Entropy/2),2

    def openfile(self):
        name = self.path
        r = open(name,'rb').read()
        #print(r)
        data = np.array([t for t in r])
        entropia, freq = self.entropy(r)

        return (str(entropia))