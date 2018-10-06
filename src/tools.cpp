#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
    VectorXd rmse = VectorXd(4);
    rmse << 0,0,0,0;
    if (    estimations.size() == 0 ||
            estimations.size() != ground_truth.size())
    {
        cerr << "Some error in estimations vector" << endl;
    }
    else
    {
        for(size_t i=0;i<estimations.size();i++)
        {
            VectorXd error = estimations[i] - ground_truth[i];
            error = error.array() * error.array();
            rmse += error;
        }
        rmse /= estimations.size();
        rmse = rmse.array().sqrt();
    }

    return rmse;
}
