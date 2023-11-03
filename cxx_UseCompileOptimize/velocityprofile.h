//
// Created by wjh on 11/3/23.
//

#ifndef CXX_VELOCITYPROFILE_H
#define CXX_VELOCITYPROFILE_H
#include<vector>
#include<math.h>
namespace chassis {
    class velocityprofile {
        enum ProfileType {
            Linear,
            SPlan,
        };
    public:

        double get_tlength() {
            return t_length;
        }

        std::vector<double> profile(double vel, double acc)
        {
            if(iszero(acc)|| isfinite(acc)|| isnan(vel)) {

            }

            int n = floor(vel/acc);

            return std::vector<double>();
        }
        std::vector<std::vector<double>> profile_vec(std::vector<double> vel,std::vector<double> acc){

        }
    private:
        double t_length;
        std::vector<double> velocity_result;
    };
}

#endif //CXX_VELOCITYPROFILE_H
