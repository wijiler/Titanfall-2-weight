#pragma once
float ppk(unsigned int kills)
{
    float points;
    if (kills > 1000)
    {
        points = (kills / 1000) * 10;
    }
    else
    {
        points = 10;
    }
    if (points < 2)
    {
        points = 2;
    }
    return points;
}
float weaponweightcalc(unsigned int weaponkills, unsigned int weapondeaths)
{
    float weight = 0;
    float weaponkd = weaponkills / weapondeaths;
    float p = ppk(weaponkills);
    int killweight = (weaponkills * p) / (weapondeaths / 5);
    float kdweight;
    if (weaponkd < 1)
    {
        kdweight = killweight * weaponkd;
    }
    else
    {
        kdweight = (weaponkd + killweight) * 10;
    }
    weight = (kdweight + killweight) / 2;
    return weight;
}
float overallweightcalc(unsigned int kills, unsigned int deaths)
{
    float weight = 0;
    float kd = kills/deaths;
    float p = ppk(kills);
    int killweight = (kills * p) / (deaths / 5);
    float kdweight;
    if (kd < 1)
    {
        kdweight = killweight * kd;
    }
    else
    {
        kdweight = (kd + killweight) * 10;
    }
    weight = (kdweight + killweight) / 2;
    return weight;
}
