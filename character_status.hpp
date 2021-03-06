#pragma once

namespace elona
{

void modcorrupt(int = 0);
void modify_potential(int, int, int);
void modify_karma(int, int);
void modheight(int = 0, int = 0);
void modweight(int, int, bool = false);
void refreshspeed(int = 0);
void refresh_speed_correction_value(int);
void gain_new_body_part(int);
void gain_level(int);
void grow_primary_skills(int);
void update_required_experience(int);

} // namespace elona
