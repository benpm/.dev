from math import *
def point_sphere(x,y,z):
	return atan2(y, sqrt(x**2 + z**2)), atan2(x, z)

print(point_sphere(1,0,0))
print(point_sphere(0,1,0))
print(point_sphere(0,0,1))
print(point_sphere(-1,0,0))
print(point_sphere(0,-1,0))
print(point_sphere(0,0,-1))