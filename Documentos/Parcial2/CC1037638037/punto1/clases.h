class Circular{
   public:
   float R,w,dt,t_total,n,alf;
   Circular(float _R,float _w,float _dt,float _t_total,float _n,float _alf);
   ~Circular();
   float xpos(float t);
   float ypos(float t);
             
};

class Expiral: public Circular{
   public:
    float z0,vz;
    Expiral(float _z0, float _vz,float _R,float _w,float _dt,float _t_total,float _n,float _alf);
    ~Expiral();
    float zpos(float t);

};