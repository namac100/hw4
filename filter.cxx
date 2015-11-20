#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double *read(const string filename, int* N);
void filter(double *p, int* N);
void print(const double *p, int* N);
void save(const string savename, const double *p, int*N);

int main(){
  int N; 					//Hilfsvariable fuer Arraygroesse
  string filename = "noisy.txt";
  string savename = "filtered.txt";
  
  double* p = read(filename, &N);
  filter(p, &N);
  save(savename, p, &N);
  delete[] p;
  
  return 0;
}

double *read(const string filename, int* N){
  *N = 237;					//Eigentliche Arraygroesse
  double* p = new double[*N];
  ifstream in(filename.c_str());
  for(int i=0; i<(*N); i++){
    in >> p[i];
  }
  in.close();
  return p;
}

void filter(double *p, int* N){
  double ptemp, pprev;
  for(int i=0; i<(*N-1); i++){
    ptemp = p[i];
    p[i] = (pprev + p[i] + p[i+1])/3.0;
    pprev = ptemp;
  }
  p[(*N)-1] = p[0];				//Randbedingung
}

void print(const double *p, int* N){
  for(int i=0; i<(*N); i++){
    cout << p[i] << endl;
  }
}

void save(const string savename, const double *p, int*N){
  ofstream out(savename.c_str());
  for(int i=0; i<(*N); i++){
    out << p[i] << endl;
  }
  out.close();
}