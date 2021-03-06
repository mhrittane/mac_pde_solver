#ifndef volatility_hpp
#define volatility_hpp

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>
#include <functional>
#include <stdio.h>

#include "pde_boundary_conditions.hpp"
#include "global.hpp"
#include <cmath>

namespace dauphine
{
    class volatility
     {
     public:
         explicit volatility(Space_boundaries* sb,
                             Time_boundaries* tb);
         virtual ~volatility();
         virtual double get_sigma(double s, double t) const;
         virtual double get_sigma_by_index(int row, int column) const;
         virtual void vol_build(double eps=0) = 0;  //allows the user to define the incremental change of the volatility as needed for the vega calculation
         Space_boundaries* get_sboundaries(); 
         Time_boundaries* get_tboundaries();
         
         
     protected:
         std::vector<double> m_volatility;
         int nb_rows;
         int nb_cols;
         Space_boundaries* s_boundaries;
         Time_boundaries* t_boundaries;
     };


     class vol_cst: public volatility
     {
     public:
         vol_cst(Space_boundaries* sb,
                 Time_boundaries* tb);
         ~vol_cst();
         void vol_build(double eps=0) override;
     };
}

#endif
