#ifndef HEIGHTFIELDS_H
#define HEIGHTFIELDS_H
#include "Constants.h"
#include "Numbers.h"
#include "Complex.h"
#include "Fourier.h"

Complex *spectrum0 = new Complex[RESOLUTION * RESOLUTION];
Complex *spectrum = new Complex[RESOLUTION * RESOLUTION];

float *heights = new float[RESOLUTION * RESOLUTION];

float PhillipsSpectrumCoefs(const Vector2 &k)
{
    float L = WIND_SPEED * WIND_SPEED / GRAVITY;
    float l = L / 300.0f;

    float kDotw = k.dot(WIND_DIRECTION);

    float k2 = k.dot(k);
    if (k2 < 0.000001f)
        return 0;

    float phillips = expf(-1.f / (k2 * L * L)) / (k2 * k2 * k2) * (kDotw * kDotw);
    if (kDotw < 0)
        phillips *= 0.01f;

    return phillips * expf(-k2 * l * l);
}

void GenerateSpectra()
{
    for (int i = 0; i < RESOLUTION; i++)
        for (int j = 0; j < RESOLUTION; j++)
        {
            Vector2 k = Vector2(RESOLUTION - 2 * i, RESOLUTION - 2 * j) * M_PI / PATCH_SIZE;
            float p = sqrtf(PhillipsSpectrumCoefs(k) / 2);

            int index = i * RESOLUTION + j;
            // std::cout << p << '\t';
            //  std::cout << RandomGaussian() << '\t';
            spectrum0[index] = Complex(RandomGaussian() * p * 10000, RandomGaussian() * p);
        }
}

void generateSin()
{
    spectrum = sin(RandomGaussian());
}

void UpdateHeights(float t)
{
    for (int i = 0; i < RESOLUTION * RESOLUTION; i++)
    {
        spectrum[i] = spectrum0[i];
    }

    InverseFourierTransform(RESOLUTION, spectrum);

    for (int i = 0; i < RESOLUTION; i++)
    {
        for (int j = 0; j < RESOLUTION; j++)
        {
            float sign = ((i + j) % 2) ? -1 : 1;
            int index = i * RESOLUTION + j;
            heights[index] = sign * spectrum[index].real;
        }
    }
}

#endif /* HEIGHTFIELDS_H */