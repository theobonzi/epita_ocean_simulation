#include <iostream>
#include "math/Vector3.h"
#include "render/Image.h"
#include "render/Color.h"
#include "render/Ray.h"
#include "object/Object.h"
#include "object/Light.h"
#include "math/HeightFields.h"

int MAX_DEPTH = 10;

Color raytrace(std::vector<Sphere> listObj, Ray ray, std::vector<Point_Light> listLight, int depth)
{
    Color color;
    bool touch = false;
    if (depth > 0)
    {
        for (auto obj : listObj)
        {
            auto t = obj.intersect(ray);
            if (t > 1.0e-5)
            {
                touch = true;
                const Vector3 pi = ray.origin + ray.direction * t;
                const Vector3 N = obj.getNormal(pi);

                for (auto light : listLight)
                {
                    const Vector3 L = light.point - pi;
                    float dt = (L.normalize()).dot((N.normalize()));
                    // Diffuse
                    color = color + obj.color * (light.color * dt);

                    // Specular
                    Color specular_color;
                    const Vector3 S =
                        -ray.direction + N.normalize() * (ray.direction.normalize().dot(N.normalize())) * 2;
                    if ((S.dot(L)) / (S.norme() * L.norme()) < 0)
                    {
                        float specular = pow(S.normalize().dot(L.normalize()), 100);
                        color = color + light.color * specular;
                    }

                    // // Reflexion
                    // const Ray reflexionRay(pi, S);
                    // color = color + (raytrace(listObj, reflexionRay, listLight, depth - 1) * 0.2);
                }
            }
        }
    }
    if (!touch)
    {
        Vector3 unit_direction = ray.direction.normalize();
        auto t = 0.5 * (unit_direction.y + 1);
        color = Color(0.96, 0.69, 0.32) * t + Color(0.48, 0.61, 0.85) * (1.0 - t);
    }

    return color;
}
/*
double hit_sphere(const Point3 &center, double radius, Ray &r)
{
    Vector3 oc = r.origin - center;
    auto a = r.direction.norme();
    auto half_b = oc.dot(r.direction);
    auto c = oc.norme() - radius * radius;
    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return -1.0;
    else
        return (-half_b - sqrt(discriminant)) / a;
}

Color computeColor(Ray &ray)
{
    auto t = hit_sphere(Point3(0, 0, 0), 0.5, ray);
    if (t > 0.0)
        return Color(1, 0, 0);
    Vector3 unit_direction = ray.direction.normalize();
    t = 0.5 * (unit_direction.y + 1);
    return Color(0.96, 0.69, 0.32) * t + Color(0.48, 0.61, 0.85) * (1.0 - t);
}

int main()
{
    std::cout << "-Start-" << std::endl;

    int width = 400;
    Image image(width);

    Point3 origin(0, 0, 0);
    Vector3 horizontal(image.viewport_width, 0, 0);
    Vector3 vertical(0, image.viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vector3(0, 0, image.focal_length);

    Point_Light light(Point3(6, 2, 2), Color(1.0, 1.0, 1.0));
    // Point_Light light2(Point3(-6, -5, 2), Color(1.0, 1.0, 1.0));

    Sphere sphere(Point3(0.2, 0, -1), 0.4, Color(1, 0.24, 0.12));
    // Sphere sphere2(Point3(0, 0, -1), 0.35, Color(0.12, 0.8, 0.47));

    std::vector<Sphere> listObj;
    listObj.push_back(sphere);
    // listObj.push_back(sphere2);

    std::vector<Point_Light> listLight;
    listLight.push_back(light);
    // listLight.push_back(light2);

    for (int y = image.height - 1; y >= 0; --y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            Color color;
            auto u = double(x) / (image.width - 1);
            auto v = double(y) / (image.height - 1);

            // Ray ray(origin, lower_left_corner + horizontal * u + vertical * v - origin);
            Ray ray(origin, lower_left_corner + horizontal * u + vertical * v);

            // color = raytrace(&sphere, ray, Color(0, 0, 0), &light2);
            color = raytrace(listObj, ray, listLight, MAX_DEPTH);

            image.setPixel(x, y, color);
        }
    }

    image.savePPM("out.ppm");

    std::cout << "-End-" << std::endl;

    return 0;
} */

int main()
{
    Image image(RESOLUTION, RESOLUTION);

    GenerateSpectra();
    // UpdateHeights(0);
    for (int x = 0; x < RESOLUTION; x++)
    {
        for (int y = 0; y < RESOLUTION; y++)
        {
            float grey = spectrum0[x + RESOLUTION * y].real * 0.05f + 0.01f;
            std::cout << grey << '\t';
            image.setPixel(x, y, Color(grey, grey, grey));
        }
    }

    image.savePPM("heights.ppm");
}