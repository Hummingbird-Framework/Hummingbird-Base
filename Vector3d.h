#ifndef HB_VECTOR_3D_H
#define HB_VECTOR_3D_H

namespace hb
{
	struct Vector3d
	{
		double x, y, z;
		Vector3d(): x(0), y(0), z(0){};
		Vector3d(double x, double y, double z): x(x), y(y), z(z){};
	};
	
}

hb::Vector3d operator -(const hb::Vector3d& right);
hb::Vector3d& operator +=(hb::Vector3d& left, const hb::Vector3d& right);
hb::Vector3d& operator -=(hb::Vector3d& left, const hb::Vector3d& right);
hb::Vector3d operator +(const hb::Vector3d& left, const hb::Vector3d& right);
hb::Vector3d operator -(const hb::Vector3d& left, const hb::Vector3d& right);
hb::Vector3d operator *(const hb::Vector3d& left, double right);
hb::Vector3d operator *(double left, const hb::Vector3d& right);
hb::Vector3d& operator *=(hb::Vector3d& left, double right);
hb::Vector3d operator /(const hb::Vector3d& left, double right);
hb::Vector3d& operator /=(hb::Vector3d& left, double right);
bool operator ==(const hb::Vector3d& left, const hb::Vector3d& right);
#endif
