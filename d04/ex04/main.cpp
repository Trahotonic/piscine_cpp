//
// Created by Roman Kyslyy on 6/16/18.
//

#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "MiningBarge.hpp"
#include "KoalaSteroid.hpp"
#include "AsteroKreog.hpp"

int main(void)
{
    IMiningLaser    *deepLaser = new DeepCoreMiner();
    IMiningLaser    *stripLaser = new StripMiner();

    MiningBarge     *barge = new MiningBarge();

    IAsteroid       *bocalSteroid = new BocalSteroid();
    IAsteroid       *asteroBocal = new AsteroBocal();

    barge->equip(deepLaser);
    barge->equip(stripLaser);

    barge->mine(bocalSteroid);
    barge->mine(asteroBocal);

    return (0);
}