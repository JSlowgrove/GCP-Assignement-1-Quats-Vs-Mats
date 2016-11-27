#include "Quaternion.h"

namespace Maths
{

	void Quaternion::rotate(Quaternion &quat, Maths::Vec3 axis, float angle)
	{
		Quaternion localQuat;
		localQuat.w = cosf(angle * 0.5f);
		localQuat.x = axis.x * sinf(angle * 0.5f);
		localQuat.y = axis.y * sinf(angle * 0.5f);
		localQuat.z = axis.z * sinf(angle * 0.5f);

		//flip the y to make it rotate the same way as rotating with a matrix
		localQuat.y = -localQuat.y;

		quat = localQuat;
	}

	Maths::Vec3 Quaternion::rotatePointAroundAxis(Maths::Vec3 initalPoint, Maths::Vec3 axis, float angle)
	{
		//Step 1) Convert the point P(x,y,z) to a quaternion p:
		//p = [0 + xi + yi + zk]

		Quaternion quatPoint = Quaternion(0.0f, initalPoint.x, initalPoint.y, initalPoint.z);

		//Step 2) Define the axis of rotation as a unit vector u:
		//u = [u.xi + u.yi + u.zk]

		//Vec3 unitAxis = axis.getNormalised(); THIS IS NOT NEEDED AS ROTATING AROUND X Y OR Z SO PASSING IN EITHER 1 OR 0

		//Step 3) Define the transforming quaternion q:
		//q = [cos(angle/2), sin(angle/2)u] or q = [cos(angle/2), sin(angle/2)x, sin(angle/2)y, sin(angle/2)z]

		Quaternion transformQuat;
		transformQuat.w = cosf(angle / 2.0f);
		transformQuat.x = sinf(angle / 2.0f);
		transformQuat.y = sinf(angle / 2.0f);
		transformQuat.z = sinf(angle / 2.0f);

		//Step 4) Define the inverse of the transforming quaternion qinv:
		//q_inv = [cos(angle/2), -sin(angle/2)u] or q_inv = [cos(angle/2), -sin(angle/2)x, -sin(angle/2)y, -sin(angle/2)z]

		Quaternion inverseQuat;
		inverseQuat.w = cosf(angle / 2.0f);
		inverseQuat.x = -sinf(angle / 2.0f);
		inverseQuat.y = -sinf(angle / 2.0f);
		inverseQuat.z = -sinf(angle / 2.0f);

		//Step 5) Compute p':
		//p' = qpq_inv
		Quaternion newQuat = quatPoint * transformQuat * inverseQuat;

		//Step 6) Unpack (x',y',z')
		//(x',y',z') p' = [0 + x'i + y'i + z'k]
		Maths::Vec3 newPoint;
		newPoint.x = newQuat.x;
		newPoint.y = newQuat.y;
		newPoint.z = newQuat.z;
		return newPoint;
	}

	Mat4 Quaternion::getMatrix()
	{
		Mat4 matrix;
		matrix.m[0] = (w*w) + (x*x) - (y*y) - (z*z);	matrix.m[1] = 2.0f * (x * y + w * z);			matrix.m[2] = 2.0f * (x * z - w * y);			matrix.m[3] = 0.0f;
		matrix.m[4] = 2.0f * (x * y - w * z);			matrix.m[5] = (w*w) - (x*x) + (y*y) - (z*z);	matrix.m[6] = 2.0f * (y * z + w * x);			matrix.m[7] = 0.0f;
		matrix.m[8] = 2.0f * (x * z + w * y);			matrix.m[9] = 2.0f * (y * z - w * x);			matrix.m[10] = (w*w) - (x*x) - (y*y) + (z*z);	matrix.m[11] = 0.0f;
		matrix.m[12] = 0.0f;							matrix.m[13] = 0.0f;							matrix.m[14] = 0.0f;							matrix.m[15] = 1.0f;
		return matrix;
	}
}