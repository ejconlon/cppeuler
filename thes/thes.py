#!/usr/bin/python
# An on-disk data structure for finding related words
# By Steve Hanov. This code and data file are released to the public domain.

import sys, mmap, struct

class FrozenThesaurus:
    def __init__(self, filename):
        self.f = file(filename, "rb")
        self.mmap = mmap.mmap( self.f.fileno(), 0, access=mmap.ACCESS_READ )

    def getDword( self, ptr ):
        # return the 32 bit number beginning at the given byte offset in the
        # file.
        return struct.unpack("<I", self.mmap[ptr:ptr+4])[0]

    def getString( self, ptr ):
        # return the null terminated string beginning at the given byte offset.
        result = []
        while self.mmap[ptr] != '\0':
            result.append(self.mmap[ptr])
            ptr += 1
        return "".join(result)

    def getWordCount(self):
        # Retrive the number of words in the file.
        return self.getDword(0)

    def getWord(self, index):
        # Retrive a word, given its index. The index must be less then the word
        # count.
        return self.getString( self.getDword(4 + index * 4) )

    def getIndexOf( self, word ):        
        # perform a binary search through the index for the given word.
        high = self.getWordCount()
        low = -1

        while (high - low > 1):
            probe = (high + low) / 2

            candidate = self.getWord(probe)

            if candidate == word:
                return probe
            elif candidate < word:    
                low = probe
            else:
                high = probe

        return None

    def getRelatedWords( self, word ):
        # Returns the list of related words to the given word.
        results = []

        index = self.getIndexOf( word )
        if index == None: return results

        ptr = self.getDword( 4 + index * 4 )

        # skip past the word text
        while self.mmap[ptr] != '\0': ptr += 1
        ptr += 1

        numRelated = self.getDword( ptr )
        for i in range(numRelated):
            ptr += 4
            results.append( self.getString( self.getDword( ptr ) ) )

        return results;            

data = FrozenThesaurus("thesaurus.dat")
print data.getRelatedWords(sys.argv[1])
