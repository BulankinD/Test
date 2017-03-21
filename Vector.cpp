#include "Vector.h"
#include <iostream>
#include <cmath>

using namespace std;

vector::vector (int n){
    this->n = n;
    comp = new float[n];
}
vector::vector(const vector& that){
    this->n = that.n;
    for (int i = 0; i < this->n; i++)
        this->comp[i] = that.comp[i];
}
vector::~vector(){
    delete [] comp;
}


vector vector::operator + (const vector& that){
    vector ans(this->n);
    for (int i = 0; i < this->n; i++){
        ans.comp[i] = this->comp[i] + that.comp[i];
    }
    return ans;
}
vector vector::operator - (const vector& that){
    return this + (that * -1);
}
vector vector::operator ^(const vector& that){
    if (this->n != 3){
        cout << "UNDEFINED";
		return 0;
    } 
	else{
        vector ans(this->n);
        ans.comp[0] = this->comp[1] * that.comp[2] - this->comp[2] * that.comp[1];
        ans.comp[1] = this->comp[2] * that.comp[0] - this->comp[0] * that.comp[2];
        ans.comp[2] = this->comp[0] * that.comp[1] - this->comp[1] * that.comp[0];
        return ans;
    }
}
void vector::set(int i, float x){
    this->comp[i] = x;
}
float vector::operator [](int i){
    return this->comp[i];
}
float modul(vector &a){
    float ans = 0;
    for (int  i = 0; i < a.n; i++){
        ans += (a.comp[i] * a.comp[i]);
    }
    return sqrt(ans);
}
float vector::operator *(const vector& that){
    float ans = 0;
    for (int i = 0; i < this->n; i++){
        ans += this->comp[i] * that.comp[i];
    }
    return ans;
}
vector vector::operator *(float a){
    vector ans(this->n);
    for (int i = 0; i < this->n; i++){
        ans.comp[i] = this->comp[i] * a;
    }
    return ans;
}
void vector:: printvec(){
    for (int i = 0; i < this->n; i++){
        cout << this->comp[i] << " ";
    }
    cout << endl;
}