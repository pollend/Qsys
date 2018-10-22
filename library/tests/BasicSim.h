#include <iostream>
#include <eigen3/Eigen/Dense>
#include <complex>


#ifndef BASICSIM_H
#define BASICSIM_H

using namespace std;
using namespace Eigen;

class BasicSim {
  private:
    MatrixXcd hamiltonian;
    MatrixXcd propagator;
    VectorXcd psi0;
    float dt;

  public:
    BasicSim(MatrixXcd hamiltonian, VectorXcd psi0, float dt) {
      this->hamiltonian = hamiltonian;
      this->dt = dt;
      this->propagator = (-1*dt*this->hamiltonian).array().exp().matrix();
      this->psi0 = psi0;
    }

    ~BasicSim(){}

    vector<Vector3cd> runSim(int final_time) {
        vector<Vector3cd> results(final_time*dt);
        VectorXcd psi = psi0;
        for (float i = 0; i < final_time*dt; i+=dt) {
          results[i] = psi;
          psi = propagator * psi;
          cin.get();
        }

        return results;
    }
};




#endif