#include "VectorArray.h"
#include <iostream>
#include "Vector.h"
using namespace std;

VectorArray::VectorArray()
{
    tam = 0;
    ArrayVec = new Vector[0];
}

VectorArray::VectorArray(const Vector vec[], int len){
    ArrayVec=new Vector[len];
    for(int i=0; i<len;i++){
        ArrayVec[i]=vec[i];
    }
    tam=len;
}

VectorArray::VectorArray(const VectorArray& vec){
    tam=vec.tam;
    ArrayVec=new Vector[tam];
    for(int i=0; i<tam;i++)
        ArrayVec[i]=vec.ArrayVec[i];
    tam=vec.tam;

}

void VectorArray::resize(int tmn)
{
    Vector *v = new Vector[tmn];
    tam = tmn;
    for(int i=0;i<tmn;i++)
        v[i]=ArrayVec[i];
    delete[] ArrayVec;
    ArrayVec = v;
}

void VectorArray::pushback(Punto &vc){
    tam++;
    resize(tam+1);
    ArrayVec[tam]=vc;
}
void VectorArray::insertar(const int position, const Vector &vec)
{
    resize(tam+1);
    for(int i=tam;i>position;i--)
        ArrayVec[i]=ArrayVec[i--];
    ArrayVec[position]=vec;
}

void VectorArray::borrar(const int position){
    for(int i=position; i<tam-1; i++)
        ArrayVec[i]=ArrayVec[i+1];
    resize(tam-1);
}

void ArrayPunto::printArray(){
    for(int i=0;i<tam;i++)
        ArrayVec[i].PrintVector();
}

const int ArrayPunto::getSize() const{
    return tam;
}

VectorArray::~VectorArray()
{
    delete []ArrayVec;
}
