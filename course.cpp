#include "course.h"

player::player (std::string p_name, float p_hcp, int p_age, int p_golfid)
{
    hcp=p_hcp;
    age=p_age;
    name = p_name;
    golfid = p_golfid;
}

tee::tee (float tCR, int tslope_value, float tbogey_value, float tscratch_value)
{
    CR=tCR;
    slope_value = tslope_value;
    bogey_value = tbogey_value;
    scratch_value = tscratch_value;

}
