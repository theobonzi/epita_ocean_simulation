#ifndef NUMBERS_H
#define NUMBERS_H

float Random()
{
    static unsigned int randoState = 0x36dc64af;
    randoState = randoState ^ (randoState << 13u);
    randoState = randoState ^ (randoState >> 17u);
    randoState = randoState ^ (randoState << 5u);
    randoState *= 1685821657u;

    unsigned int intermediate = ((randoState & 0x007FFFFFu) | 0x3F800000u);
    return *((float *)(&intermediate)) - 1.0f;
}

float RandomGaussian()
{
    float a = 0.f;
    for (int i = 0; i < 12; i++)
    {
        a += Random();
    }
    return a - 6.f;
}

#endif /* NUMBERS_H */