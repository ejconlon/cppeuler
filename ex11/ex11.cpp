
/*
 * In the 2020 grid below, four numbers along a diagonal line have been marked in red.
 *
 * 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
 * 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
 * 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
 * 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
 * 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
 * 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
 * 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
 * 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
 * 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
 * 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
 * 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
 * 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
 * 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
 * 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
 * 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
 * 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
 * 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
 * 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
 * 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
 * 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
 * The product of these numbers is 26  63  78  14 = 1788696.
 *
 * What is the greatest product of four adjacent numbers in any direction (up, down, left, right, or diagonally) in the 2020 grid?
 *
 *
 * Answer:
 * 70600674
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

#define STRARRAY {\
"08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08",\
"49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00",\
"81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65",\
"52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91",\
"22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80",\
"24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50",\
"32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70",\
"67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21",\
"24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72",\
"21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95",\
"78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92",\
"16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57",\
"86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58",\
"19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40",\
"04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66",\
"88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69",\
"04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36",\
"20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16",\
"20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54",\
"01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"\
}

template <typename T>
class Iterator {
    public:
        virtual ~Iterator() {}
        virtual void advance() = 0;
        virtual T getValue() = 0;
        virtual bool equals(Iterator<T>* other) = 0;
};

template <typename T>
class Iterable {
    public:
        virtual ~Iterable() {}
        virtual Iterator<T>* begin() = 0;
        virtual Iterator<T>* end() = 0;
};

template <typename T>
class SubArrayIterator : public Iterator<T> {
    T* array; 
    int pos;
    public:
        SubArrayIterator(T* array, int pos) :
            array(array),
            pos(pos) {}
        
        virtual void advance() {
            pos++;
        }
        virtual T getValue() {
            return array[pos];    
        }
        bool operator==(SubArrayIterator<T>& other) { 
            return array == other.array && pos == other.pos; 
        }
        bool operator!=(SubArrayIterator<T>& other) { 
            return !(operator==(other));
        }
        virtual bool equals(Iterator<T>* other){
            SubArrayIterator<T>* o2 = dynamic_cast <SubArrayIterator<T>*> (other);    
            if (o2 != NULL) {
                return array == o2->array && pos == o2->pos; 
            } else {
                return false;
            }
        }
};

template <typename T>
class SubArray : public Iterable<T> {
    T* array; 
    int startPos;
    int endPos;
    public:
        SubArray(T* array, int startPos, int endPos) :
            array(array),
            startPos(startPos),
            endPos(endPos) {}

        virtual SubArrayIterator<T>* begin() {
            return new SubArrayIterator<T>(array, startPos);
        }
        virtual SubArrayIterator<T>* end() {
            return new SubArrayIterator<T>(array, endPos);
        }
};

int test() {

    int array[6] = {1,2,3,4,5,6};
    int len = sizeof(array)/sizeof(int);
    assert(len == 6);

    SubArray<int> s(array, 1, 3);
    SubArrayIterator<int>* begin = s.begin();
    SubArrayIterator<int>* end = s.end();
    
    for (; *begin != *end; begin->advance()) {
        std::cout << begin->getValue() << std::endl;
    }

    delete begin;
    delete end;

    return 0;
}   

long prod(Iterable<long>& ib) {
    long p = 1;
    
    Iterator<long>* begin = ib.begin();
    Iterator<long>* end = ib.end();
   
    for (; !begin->equals(end); begin->advance()) {
        p *= begin->getValue();
    }

    delete begin;
    delete end;

    return p;
}

int main() {
    int foo = test(); if (foo != 0) return foo;

    std::string strarray[] = STRARRAY;
    int zlen = 3;
    int height =  sizeof(strarray)/sizeof(std::string);

    if (height == 0) return -1;
    std::string first = strarray[0];
    int width = (first.length()+1)/zlen; 

    std::cout << "height "<<height <<" width "<< width << std::endl;

    long array[height][width];

    for (int h = 0; h < height; h++) {
        std::string row = strarray[h];
        int w = 0;
        for (size_t found = 0; found != std::string::npos; found = row.find(" ", found+1)) {
            if (found == 0) found -= 1;
            std::string entry = row.substr(found+1, 2);
            if (entry.at(0) == '0') {
                entry = entry.replace(0, 1, " ");
            }
            array[h][w] = atol(entry.c_str());   
            w++;
        }
    }

    for (int h = 0; h < height; h++) {
        std::cout << "Row " << h <<  std::endl;
        for (int w = 0; w < width; w++) {
            std::cout << array[h][w] << std::endl;
        }
    }

    long maxprod = 0;
    int nelems = 4;

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width-nelems; w++) {
            SubArray<long> s(array[h], w, w+nelems);
            long p = prod(s); 
            if (p > maxprod) maxprod = p;
        }
    }
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height-nelems; h++) {
            long a2[nelems];
            for (int i = 0; i < nelems; i++) {
                a2[i] = array[h+i][w];
            }
            SubArray<long> s(a2, 0, nelems);
            long p = prod(s); 
            if (p > maxprod) maxprod = p;
        }
    }
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            long a2[nelems];
            for (int i = 0; i < nelems; i++) {
                int hi = h+i;
                int wi = w+i;
                if (hi >= height || wi >= width) a2[i] = 0;
                else a2[i] = array[hi][wi];
            }
            SubArray<long> s(a2, 0, nelems);
            long p = prod(s); 
            if (p > maxprod) maxprod = p;
        }
    }
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            long a2[nelems];
            for (int i = 0; i < nelems; i++) {
                int hi = h+i;
                int wi = w-i;
                if (hi >= height|| wi < 0) a2[i] = 0;
                else a2[i] = array[hi][wi];
            }
            SubArray<long> s(a2, 0, nelems);
            long p = prod(s); 
            if (p > maxprod) maxprod = p;
        }
    }

    std::cout << "MAX PROD: " << maxprod << std::endl;

    return 0;
}
