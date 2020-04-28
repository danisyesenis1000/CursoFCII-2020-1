
#include "clases.h"
#include <math.h>
using namespace std;

Circular::Circular(float _R,float _w,float _dt,float _t_total,float _n,float _alf){
    R=_R;
    w=_w;
    dt=_dt;
    t_total=_t_total;
    n=_n;
    alf=_alf;
   }

Circular::~Circular(){} 

float Circular::xpos(float t){
    return R*cos(w*t + alf);
}

float Circular::ypos(float t){
    return R*sin(w*t + alf);
}




Expiral::Expiral(float _z0, float _vz,float _R,float _w,
        float _dt,float _t_total,float _n,float _alf): Circular(_R,_w,_dt,_t_total,_n,_alf){
        z0=_z0;
        vz=_vz;
    }
Expiral::~Expiral(){}

float Expiral::zpos(float t){
    return z0+vz*t;
}




