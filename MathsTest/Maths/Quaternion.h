#pragma once

#include "math.h"
#include "Vec3.h"
#include "Mat4.h"

/**
@brief The namespace for all maths code.
*/
namespace Maths
{

	/**
	@brief Contains the Quaternion structure with functions and overloaded operators.
	*/
	struct Quaternion
	{
		float w;
		float x;
		float y;
		float z;

		/**
		@brief Constructs the Quaternion setting the values to 1,0,0,0.
		*/
		Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) {}

		/**
		@brief Constructs the Quaternion setting the values to the input coordinates.
		@param w The inputed w position.
		@param x The inputed x position.
		@param y The inputed y position.
		@param z The inputed z position.
		*/
		Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

		/**
		@brief Constructs the Quaternion setting the values to the input coordinates.
		@param w The inputed w position.
		@param x The inputed x position.
		@param y The inputed y position.
		@param z The inputed z position.
		*/
		Quaternion(int w, int x, int y, int z) : w((float)w), x((float)x), y((float)y), z((float)z) {}

		/**
		@brief Returns the length of the Vec4.
		@returns The length of the Vec4.
		*/
		float getLength()
		{
			return (float)sqrt((w*w) + (x*x) + (y*y) + (z*z));
		}

		float getDotProduct(Quaternion Qa, Quaternion Qb)
		{
			float dp = Qa.x*Qb.x + Qa.y*Qb.y + Qa.z*Qb.z + Qa.w * Qb.w;
			return dp;
		}

		Quaternion getNormalised()
		{
			Quaternion normalised;
			float length = getLength();
			normalised.w = w / length;
			normalised.x = x / length;
			normalised.y = y / length;
			normalised.z = z / length;
			return normalised;
		}

		void rotate(Quaternion &quat, Maths::Vec3 axis, float angle);
		
		Mat4 getMatrix();
	};

	/**
	@brief Overloads the * operator allowing a Quaternion to be multiplied by another Quaternion.
	IMPORTANT: (Quaternion1 * Quaternion2) != (Quaternion2 * Quaternion1)
	@param q1 One of the input Quaternion's.
	@param q2 One of the input Quaternion's.
	@returns The new Quaternion.
	*/
	inline Quaternion operator * (Quaternion q1, Quaternion q2)
	{
		Quaternion q3;
		q3.w = (q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z);
		q3.x = (q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y);
		q3.y = (q1.w * q2.y) - (q1.x * q2.z) + (q1.y * q2.w) + (q1.z * q2.x);
		q3.z = (q1.w * q2.z) + (q1.x * q2.y) - (q1.y * q2.x) + (q1.z * q2.w);
		return q3;
	}

}// End of Maths namespace