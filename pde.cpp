#include "pde.hpp"

namespace dauphine
{
    
    pde::pde()
    {
        std::cout<<"PDE constructor"<<std::endl;
    }

    pde::~pde()
    {
        std::cout<<"PDE destructor"<<std::endl;
    }

    bs_pde::bs_pde(volatility* vol, rate* r)
    : m_vol(vol), m_rate(r)
    {
        std::cout<<"BS PDE constructor"<<std::endl;
    }


    bs_pde::~bs_pde()
    {
        m_vol = nullptr;
	m_rate = nullptr;
        std::cout<<"BS PDE destructor"<<std::endl;
    }

    double bs_pde::first_coeff() const
    {
        return 1.;
    }

    double bs_pde::diff_coeff(double s, double t) const
    {
          double sigma = m_vol->get_sigma(s, t);
          return -0.5*sigma*sigma;
    }

    double bs_pde::conv_coeff(double s, double t) const
    {
        double sigma = m_vol->get_sigma(s, t);
        double rate = m_rate->get_rate(s,t);

        return 0.5*sigma*sigma-rate;
    }

    double bs_pde::zero_coeff(double s, double t) const
    {
        return m_rate->get_rate(s,t);
    }

    double bs_pde::source_coeff() const
    {
        return 0.;
    }
    
    volatility* bs_pde::get_volatility() const{
        return m_vol;
    }
    rate* bs_pde::get_rate() const{
        return m_rate;
    }

}
